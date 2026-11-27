#!/usr/bin/env python3
"""Write the initialised data that tools/gendata.py generates for a source file into the file itself.

    python tools/inlinedata.py [--module M ...] [FILE ...] [--dry] [--print] [--check]

For every definition build/data_plan.json gives the file, the values are read from your Game.exe (the same
rendering and checks as tools/gendata.py) and written as source in place of the file's `#include "gen/data/..."`
lines: the definitions of the main include where that line was, a static's definition where its own include line
was. The data plan keeps every record (the build places each definition at its address by the plan's names); the
ones now in source are marked "sourced": true, and gendata.py no longer renders them. A file with nothing generated
left gets the state "sourced" and loses its include line.

How the values are written:

  typed definitions   with the plan's type: integers in decimal, in hexadecimal where the name of the global, its
                      type or the member says flags, masks, colours, CRC or hash tables, GUIDs, four-character codes,
                      and for values from 0x1000000 up; floats as the shortest literal that reads back the same
                      bits; enums as casts of their value
  char arrays         string literals (embedded NULs as \\0, other control and high bytes as \\x escapes), braced
                      character constants where the array has no terminating NUL; wchar_t arrays as L"..."
  pointers            &symbol, &array[i], function names, string literals, as the plan resolves each relocation;
                      casts only where the initialised type needs one
  anonymous blobs     gData_<VA> keeps its name; a blob without pointers becomes an unsigned char array (a char
                      string where it reads as text), a blob of string pointers a const char* array, a blob of other
                      pointers a const void* array; a blob that mixes bytes and pointers keeps its packed struct of
                      byte runs and pointers

Each definition keeps its `// 0x<VA>` marker on the line that names it (the first line of a definition that spans
lines, where the checker reads it). Definitions of the classes in EXCLUDED_* and the ranges of
build/identity_plan.json (the PKWARE library, link stamps, the signature) and the resources are never written into
source: they stay generated from your Game.exe, and the tool refuses to move them.

--module M   every file of Source/M that the plan holds (repeatable)
--dry        say what would move, write nothing
--print      print the new text of each file instead of writing it
--check      verify that every sourced record is defined in its file and no sourced file still includes gen/data
"""
import os, re, sys, json, collections

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from common import ROOT, settings, check_image, die, GEN_INCLUDE
import gendata as G

PLAN = os.path.join(ROOT, G.PLAN_PATH)

# Never written into source. Each entry says why. These stay generated from your own Game.exe at build time.
#
# Files whose whole data is key material or feeds a cryptographic routine.
EXCLUDED_FILES = (
    # Storm's archive signature check: RSA over SBig with the public key tables.
    ("Source/Storm/SOURCE/SSignature", "Storm archive signature verification (RSA public key and its tables)"),
    # Storm's big-number library: small primes, Fermat bases and the random seed of its key and primality routines.
    ("Source/Storm/SOURCE/SBig", "Storm big-number library tables (primality and key generation)"),
    # The SRP logon protocol: hash pads and group parameters.
    ("Source/SRP/", "SRP logon protocol"),
    # Battle.net logon: the SRP group (gabSrpData1/2 are g and N), the session key computation, CD-key hashing.
    ("Source/Bnclient/", "Battle.net logon (SRP group parameters, session key)"),
    # Warden: the built-in encrypted module, its RC4 keys and the RSA modulus and exponent of module signatures.
    ("Source/D2Client/WARDEN/", "Warden (encrypted module, RC4 keys, RSA modulus and exponent)"),
)

# Single definitions that are key material, found by their use: each is passed to a big-number, signature or
# CD-key decoding routine.
EXCLUDED_VAS = {
    0x006CEF78: "gabSignatureModulus: RSA modulus of Storm's archive signature (SFILE.CPP, passed to SBigFromBinary)",
    0x006CF078: "gabSignatureExponent: RSA public exponent of the same key",
    0x006CF07C: "gaSignatureKeys: the key table that points at the modulus and exponent",
    0x006DF238: "gacCDKeyMap: CD-key character decoding map (BnSend.cpp)",
    0x006DFF20: "gaSubstitutionBox: CD-key decoding substitution box (BnDownload.cpp)",
    0x006E0100: "gaCdKeyCharMap: CD-key character map (BnDownload.cpp)",
    0x006D59F0: "gabCdKeyMap: CD-key character decoding map (D2Multi ComCallback.cpp)",
    0x006D74B0: "gabBuiltinModule: Warden's built-in module, encrypted",
    0x006D8768: "gabBuiltinModuleKey: Warden module key",
    0x006D8778: "gabBuiltinModuleRc4Key: Warden RC4 key",
    0x006D8D14: "gabExponent: RSA exponent of Warden module signatures",
    0x006D8D18: "gabModulus: RSA modulus of Warden module signatures",
    0x00730164: "gabSrpData1: SRP generator",
    0x0073016C: "gabSrpData2: SRP modulus",
    0x006E03F0: "gabSha1Pad80: SRP hash padding",
}

# Any name that says key material is refused unless REVIEWED_NAMES clears it, so a key table nobody listed above
# cannot slip through under its own name.
KEY_NAME = re.compile(r"(?i)key|modul|expon|rc4|srp|signature|sbig|prime|secret|cipher|crypt|(?<![a-z])sbox(?![a-z])|substitution|warden")

# Names KEY_NAME matches that were checked and hold no key material (keyboard bindings, a level name, a monster).
REVIEWED_NAMES = re.compile(r"(?i)hotkey|keyconfig|keycapture|keytable|beltkey|^gKey_0070CD54$|act1crypt|primepoison|"
                            r"modulator|^gaszModuleTypes_|^gszModules$|^gpszModuleName$")

HEX_HINT = re.compile(r"(?i)flag|mask|colou?r|rgb|crc|hash|guid|iid|propertyset|fourcc|style|bits|magic|attrib")
WIDTH = 140


def char_arrays(recs, externs):
    """Names this file sees as char arrays: its string and char-array definitions, the char arrays its data externs
    declare. `(const char*)&gszX` is written `gszX` for them."""
    out = set()
    for r in recs:
        m = r.get("model") or {}
        if r["form"] == "string" or (m.get("k") == "arr" and (m.get("elem") or {}).get("name") == "char"):
            out.add(r.get("cname") or r["name"])
        elif r["form"] == "bytes" and not r["pointers"] and r.get("text"):
            out.add(r["cname"])
    for e in externs or ():
        m = re.match(r'^extern\s+(?:"C"\s+)?(?:const\s+)?char\s+(\w+)\s*\[[^\]]*\]\s*;', e)
        if m:
            out.add(m.group(1))
    return out


class Unreadable(Exception):
    pass


class Guard:
    """The ranges no definition may come from: identity_plan's (PKWARE, stamps, signature) and the resources."""

    def __init__(self, img):
        ip = json.load(open(os.path.join(ROOT, "build", "identity_plan.json")))
        self.ranges = []
        for it in ip.get("items", ()):
            if it.get("where") == "va":
                lo = int(it["at"], 16)
                why = {"library": "PKWARE DCL library", "stamp": "link stamp", "signature": "file signature"}.get(it["cls"], it["cls"])
                self.ranges.append((lo, lo + it["length"], "%s (%s)" % (why, it["name"])))
        B = img.pe.image_base
        for s in img.lay["sections"]:
            if s["name"] == ".rsrc":
                self.ranges.append((B + s["va"], B + s["va"] + s["vsize"], "resources (.rsrc)"))

    def refusal(self, r):
        va = int(r["va"], 16); n = r["size"]
        for lo, hi, why in self.ranges:
            if va < hi and lo < va + n:
                return why
        for pre, why in EXCLUDED_FILES:
            if r["file"].startswith(pre):
                return why
        if va in EXCLUDED_VAS:
            return EXCLUDED_VAS[va]
        for nm in {r.get("name"), r.get("cname")} - {None}:
            if KEY_NAME.search(nm) and not REVIEWED_NAMES.search(nm):
                return "named like key material (%s): review it and add it to REVIEWED_NAMES if it is not" % nm
        return None


# ---------------------------------------------------------------------------------------------------------------
# literals

def c_string(units, wide):
    """A string literal of the code units, the terminating NUL left to the compiler."""
    q = 'L"' if wide else '"'
    out = [q]; esc = None
    simple = {0x22: '\\"', 0x5C: "\\\\", 0x0A: "\\n", 0x0D: "\\r", 0x09: "\\t"}
    for c in units:
        nxt = None
        if c == 0:
            s = "\\0"; nxt = "oct"
        elif c in simple:
            s = simple[c]
        elif c == 0x3F and out[-1] in ("?", "\\?"):
            s = "\\?"
        elif 0x20 <= c < 0x7F:
            s = chr(c)
            if (esc == "hex" and s in "0123456789abcdefABCDEF") or (esc == "oct" and s in "01234567"):
                out.append('" ' + q)
        else:
            s = ("\\x%04X" if wide else "\\x%02X") % c; nxt = "hex"
        out.append(s); esc = nxt
    out.append('"')
    return "".join(out)


def char_const(v):
    """A character constant for a printable char value, else None."""
    if v == 0x27:
        return "'\\''"
    if v == 0x5C:
        return "'\\\\'"
    if 0x20 <= v < 0x7F:
        return "'%s'" % chr(v)
    return None


def int_text(v, size, kind, hexmode, pad):
    if kind in ("s", "c"):
        lim = 1 << (8 * size - 1)
        if v >= lim:
            v -= 1 << (8 * size)
    if v < 0 or kind == "s" and v < 0x1000000 and not hexmode:
        return G.int_lit(v & ((1 << (8 * size)) - 1), size, "s")
    big = v >= 0x1000000
    if hexmode or big:
        digits = "%0*X" % (2 * size, v) if pad else "%X" % v
        lit = "0x" + digits
    else:
        lit = "%d" % v
    if size == 8:
        lit += "ui64" if kind == "u" else "i64"
    return lit


def is_zero(t):
    return t in ("0", "0.0f", "0.0", "false", '""', 'L""', "{ 0 }") or re.fullmatch(r"0x0+(ui64|i64)?|\{ (0|0x0+)(, (0|0x0+))* \}", t) is not None


# ---------------------------------------------------------------------------------------------------------------
# layout: a value is a leaf (str) or a Brace of values

class Brace:
    def __init__(self, items, flat):
        self.items = items; self.flat = flat


def trim(items):
    k = len(items)
    while k and isinstance(items[k - 1], str) and is_zero(items[k - 1]):
        k -= 1
    if len(items) - k >= 8 or k == 0:
        items = items[:k] or ["0"]
    return items


def one(v):
    if isinstance(v, str):
        return v
    parts = [one(x) for x in v.items]
    if any(p is None or "\n" in p for p in parts):
        return None
    return "{ " + ", ".join(parts) + " }"


def lay(v, ind=0, lead=0):
    if isinstance(v, str):
        return v
    o = one(v)
    if o is not None and ind + lead + len(o) <= WIDTH:
        return o
    pad = " " * (ind + 4)
    if v.flat and not any(x.startswith(('"', 'L"')) for x in v.items):
        rows = []
        n = max(len(x) for x in v.items)
        per = 16 if n <= 6 else 8 if n <= 12 else 4
        for i in range(0, len(v.items), per):
            rows.append(", ".join(v.items[i:i + per]))
        if max(len(r) for r in rows) + len(pad) > WIDTH + 20:
            rows = list(v.items)
        return "{\n" + pad + (",\n" + pad).join(rows) + "\n" + " " * ind + "}"
    return "{\n" + pad + (",\n" + pad).join(lay(x, ind + 4) for x in v.items) + "\n" + " " * ind + "}"


# ---------------------------------------------------------------------------------------------------------------
# rendering, the same walk as gendata.render with readable leaves

def plain_pointer(e, spell, chars, arrays=None):
    """gendata's pointer expression without the casts the initialised type does not need: a string literal or a char
    array as a const char*, an object's address as a const void*, an element of an array this file defines as
    &array[i]."""
    sp = re.sub(r"\s+", "", spell or "")
    m = re.match(r"^\((.+?)\)(?:\(\(char ?\*\)&(\w+) \+ (\d+)\)|&(\w+))$", e)
    if m and arrays:
        x = m.group(2) or m.group(4); off = int(m.group(3) or 0); am = arrays.get(x)
        if am and sp.endswith("*") and sp[:-1] == re.sub(r"\s+", "", (am["elem"].get("name") or "")) \
                and off % am["elem"]["size"] == 0 and off < am["size"]:
            return "&%s[%d]" % (x, off // am["elem"]["size"])
    m = re.match(r'^\((?:const ?char ?\* ?(?:const)?|const ?void ?\* ?(?:const)?)\)(".*")$', e, re.S)
    if m and sp in ("constchar*", "charconst*", "constvoid*", "constchar*const", "constvoid*const"):
        return m.group(1)
    m = re.match(r"^\((?:const ?)?char ?\* ?(?:const)?\)&(\w+)$", e)
    if m and sp in ("constchar*", "charconst*", "constchar*const", "char*", "char*const") and m.group(1) in chars:
        return m.group(1)
    m = re.match(r"^\(const ?void ?\*\)(&\w+)$", e)
    if m and sp in ("constvoid*", "constvoid*const"):
        return m.group(1)
    return e


class Rd:

    def __init__(self, raw, relocs, sym, hexmode, chars=(), arrays=None):
        self.raw, self.relocs, self.sym, self.hexmode, self.chars, self.arrays = raw, relocs, sym, hexmode, chars, arrays

    def ptr(self, off, spell, fn):
        e = self.sym(self.relocs[off], spell, fn)
        return plain_pointer(e, spell, self.chars, self.arrays)

    def value(self, m, off, names, in_arr=False):
        raw = self.raw; k = m["k"]; n = m["size"]
        for r in self.relocs:
            if off <= r < off + n and k not in ("arr", "struct", "union") and not (r == off and n == 4 and k in ("ptr", "prim", "enum")):
                raise Unreadable("relocation_inside_" + k)
        hexm = self.hexmode or any(HEX_HINT.search(x) for x in names if x)
        if k == "prim":
            b = raw[off:off + n]
            if off in self.relocs:
                if m["kind"] == "f":
                    raise Unreadable("relocation_in_float")
                return plain_pointer(self.sym(self.relocs[off], m["name"], False), m["name"], self.chars, self.arrays)
            if m["kind"] == "f":
                return G.float_lit(b)
            v = int.from_bytes(b, "little")
            if m["kind"] == "b":
                if v > 1:
                    raise Unreadable("bool_not_0_or_1")
                return "true" if v else "false"
            if m["kind"] == "c" and in_arr:
                c = char_const(v)
                if c:
                    return c
            if v == 0 and not (in_arr and hexm):
                return "0"
            return int_text(v, n, m["kind"], hexm, in_arr and hexm)
        if k == "enum":
            if off in self.relocs:
                raise Unreadable("relocation_in_enum")
            v = int.from_bytes(raw[off:off + n], "little")
            return "(%s)%s" % (m["name"], G.int_lit(v, n, m["kind"]))
        if k == "ptr":
            if off in self.relocs:
                return self.ptr(off, m["spell"], m.get("fn"))
            v = int.from_bytes(raw[off:off + 4], "little")
            if v == 0:
                return "0"
            if not m.get("spell"):
                raise Unreadable("pointer_unspellable")
            return "(%s)0x%X" % (m["spell"], v)
        if k == "arr":
            em = m["elem"]; es = em["size"]
            if em["k"] == "prim" and not any(off <= r < off + n for r in self.relocs):
                if em["name"] == "char" and raw[off + n - 1] == 0:
                    t = raw[off:off + n].rstrip(b"\0")
                    return c_string(t, False)
                if em["name"] == "wchar_t" and raw[off + n - 2:off + n] == b"\0\0":
                    u = [int.from_bytes(raw[off + i:off + i + 2], "little") for i in range(0, n, 2)]
                    while u and u[-1] == 0:
                        u.pop()
                    return c_string(u, True)
            items = [self.value(em, off + i * es, names + [em.get("name")], in_arr=True) for i in range(m["n"])]
            return Brace(trim(items), em["k"] in ("prim", "ptr", "enum"))
        if k in ("struct", "union"):
            mem = m["members"]
            if k == "union":
                nm, mo, mm = mem[0]
                cover = set(range(mo, mo + mm["size"]))
                if any(raw[off + i] for i in range(n) if i not in cover) or any(off <= r < off + n and (r - off) not in cover for r in self.relocs):
                    raise Unreadable("union_tail_not_zero")
                x = self.value(mm, off + mo, names + [m.get("name"), nm])
                return Brace([x], isinstance(x, str))
            if m.get("name") == "Unicode" and len(mem) == 1 and mem[0][2]["k"] == "prim":
                v = int.from_bytes(raw[off:off + n], "little")
                c = char_const(v) if v < 0x80 else None
                return Brace([c or ("0" if v == 0 else "0x%04X" % v)], True)
            cover = bytearray(n); items = []; last = -1
            for nm, mo, mm in mem:
                if mo < last:
                    raise Unreadable("members_out_of_order")
                last = mo + mm["size"]
                for i in range(mo, min(mo + mm["size"], n)):
                    cover[i] = 1
                items.append(self.value(mm, off + mo, names + [m.get("name"), nm]))
            for i in range(n):
                if not cover[i] and (raw[off + i] or any(r <= off + i < r + 4 for r in self.relocs)):
                    raise Unreadable("padding_not_zero")
            return Brace(trim(items), all(isinstance(x, str) for x in items) and len(items) > 8)
        raise Unreadable(m.get("why", "type"))


# ---------------------------------------------------------------------------------------------------------------

def symbols(r, img, fn_types):
    """The pointer resolver of gendata.render_parts for one record."""
    by_target = {}
    for off, t, how, nm, o, kind in r["pointers"]:
        by_target.setdefault(int(t, 16), (how, nm, o, kind))

    def sym(t_va, spell, fn=None):
        res = by_target.get(t_va)
        if res is None:
            raise G.Unresolved("0x%08X" % t_va)
        how, nm, off, kind = res
        if how == "literal":
            return G.sym_expr(("literal", G.image_text(img, t_va), 0, "string"), spell, fn)
        if how == "owner" and kind == "func" and not (fn if fn is not None else "(" in spell):
            ft = fn_types.get(nm)
            if ft:
                return "(%s)(unsigned int)(%s)&%s" % (spell, ft, nm)
        return G.sym_expr(res, spell, fn)
    return sym


def packed_init(raw, relocs, rd):
    """The initialiser of gendata's packed struct of byte runs and pointers (bytes_form's fields, in order)."""
    items = []; pos = 0; n = len(raw)
    for r in sorted(relocs):
        if r > pos:
            items.append(Brace(trim(["0x%02X" % c for c in raw[pos:r]]), True))
        items.append(rd.ptr(r, "const void*", False))
        pos = r + 4
    if pos < n:
        items.append(Brace(trim(["0x%02X" % c for c in raw[pos:]]), True))
    return lay(Brace(items, False))


def strip_extern(head, name, ftext):
    """`extern T x = ` -> `T x = ` where that keeps the linkage: C++ linkage, an object that is not const, and no
    static declaration of it in the file."""
    if head.startswith("extern ") and not head.startswith('extern "C"') and not re.search(r"\bconst\b", head) and \
            not re.search(r"^[ \t]*static\b[^;\n]*\b%s\b" % re.escape(name), ftext, re.M):
        return head[len("extern "):]
    return head


def definition(head, init, tail, va):
    """head + init + tail with the `// 0x<VA>` marker on the line that names the definition: a definition that spans
    lines carries it on its first line, as the checker reads a declaration's marker from the line that names it."""
    mark = "; // 0x%08X" % va
    if "\n" not in init or not tail.startswith(mark):
        return head + init + tail
    first, rest = (head + init).split("\n", 1)
    return first + " // 0x%08X\n" % va + rest + ";" + tail[len(mark):]


class Piece:
    def __init__(self, r, sdef, fwd, text, how):
        self.r, self.sdef, self.fwd, self.text, self.how = r, sdef, fwd, text, how
        self.name = r.get("cname") or r["name"]


def readable(r, img, ent, ftext, gen, chars=(), arrays=None):
    """(struct definition or None, forward declaration or None, definition text, how) for one record.
    gen is gendata's own (fwd, sdef, head, init, tail), the fallback."""
    fwd, sdef, head, init, tail = gen
    va = int(r["va"], 16); raw = img.read(va, r["size"])
    _, relocs = G.check_record(r, img)
    fn_types = (r.get("fn_types") if G.is_static(r) else ent.get("fn_types")) or {}
    sym = symbols(r, img, fn_types)
    esc = (lambda s: G.escape_parens(s)) if r.get("escape") == G.ESCAPE_PAREN else (lambda s: s)
    ec = "extern " if ent.get("lang") == "c" else 'extern "C" '
    if r["form"] == "string":
        return None, fwd, definition(head, init, tail, va), "string"
    if "model" in r and r["form"] in ("declared", "declared_owner") or G.is_static(r):
        nm = [r["name"], r.get("type"), r["model"].get("name")]
        v = Rd(raw, relocs, sym, False, chars, arrays).value(r["model"], 0, nm)
        h = strip_extern(head, r["name"], ftext) if not G.is_static(r) else head
        return None, fwd, definition(h, esc(lay(v, 0, len(h) + 18)), tail, va), "typed"
    if r["form"] != "bytes":
        raise Unreadable("form " + r["form"])
    cname = r["cname"]; n = r["size"]
    cst = "const " if r["region"] == "rdata" else ""
    if len(re.findall(r"\b%s\b" % re.escape(cname), ftext)) > 0:
        raise Unreadable("the file names %s itself" % cname)
    rd = Rd(raw, relocs, sym, True, chars, arrays)
    if not relocs:
        s = raw.rstrip(b"\0")
        if text_blob(img, r):
            decl = "%s%schar %s[%d]" % (ec, cst, cname, n)
            return None, decl + "; // 0x%08X" % va, decl + " = " + esc(c_string(s, False)) + tail, "text"
        items = trim(["0x%02X" % c for c in raw])
        decl = "%s%sunsigned char %s[%d]" % (ec, cst, cname, n)
        return None, decl + "; // 0x%08X" % va, definition(decl + " = ", lay(Brace(items, True), 0, len(decl) + 19), tail, va), "bytes"
    if va % 4 == 0 and n % 4 == 0 and all(o % 4 == 0 for o in relocs) and \
            all(o in relocs or not any(raw[o:o + 4]) for o in range(0, n, 4)):
        lit = all(p[2] == "literal" for p in r["pointers"])
        et = "const char*" if lit else "const void*"
        items = [rd.ptr(o, et, False) if o in relocs else "0" for o in range(0, n, 4)]
        decl = "%s%s%s %s%s[%d]" % (ec, et, " const" if cst else "", "", cname, n // 4)
        body = lay(Brace(trim(items), False), 0, len(decl) + 19)
        return None, decl + "; // 0x%08X" % va, definition(decl + " = ", esc(body), tail, va), "pointers"
    init = packed_init(raw, relocs, rd)
    return sdef, fwd, definition(head, esc(init), tail, va), "packed"


def text_blob(img, r):
    """True for a pointer-free byte blob that reads as text: printable bytes, then at least one NUL."""
    if r["form"] != "bytes" or r["pointers"]:
        return False
    raw = img.read(int(r["va"], 16), r["size"]); s = raw.rstrip(b"\0")
    return len(s) < len(raw) and len(s) >= 3 and all(0x20 <= c < 0x7F or c in (9, 10, 13) for c in s)


def plan_and_image():
    s = settings(); check_image(s["image"])
    plan = G.load_plan(PLAN)
    pe, img, isha = G.open_image(s["image"])
    if plan.get("image_sha256") and isha != plan["image_sha256"]:
        die("the image is not the one the data plan was made from")
    return plan, img


def gen_parts(f, ent, recs, img):
    """gendata's checked rendering of each record: {va: (fwd, sdef, head, init, tail)}."""
    out = {}
    for r in recs:
        bad, relocs = G.check_record(r, img)
        if bad:
            raise G.PlanError("%s %s %s: %s" % (f, r["va"], r["name"], "; ".join(bad)))
        fn_types = (r.get("fn_types") if G.is_static(r) else ent.get("fn_types")) or {}
        sym = symbols(r, img, fn_types)
        d = dict(r, va_int=int(r["va"], 16), relocs=relocs)
        parts = G.def_text(d, img.read(int(r["va"], 16), r["size"]), sym, "extern " if ent.get("lang") == "c" else 'extern "C" ', fixed=True)
        if (parts[0], parts[1], parts[2], parts[4]) != (r.get("fwd"), r.get("struct"), r["head"], r["tail"]):
            raise G.PlanError("%s %s %s: the rendered declarators differ from the plan's" % (f, r["va"], r["name"]))
        out[r["va"]] = parts
    return out


def extern_name(line):
    """The name an extern line declares, or None where it is not plain enough to tell."""
    code = re.sub(r"//.*$", "", line)
    if "__declspec" in code or "operator" in code:
        return None
    m = re.search(r"\b([A-Za-z_]\w*)\s*[\[\(;]", code)
    return m.group(1) if m else None


def names_in(text):
    return set(re.findall(r"\b[A-Za-z_]\w*\b", text))


def inline_file(f, plan, img, guard, by):
    """(new text, sourced records, kept records, notes) for one file, or None when there is nothing to move."""
    ent = plan["files"][f]
    if ent["state"] not in G.GEN_STATES:
        return None
    path = os.path.join(ROOT, f)
    if not os.path.exists(path):
        return dict(skip="the plan's file does not exist")
    text = open(path, encoding="latin-1", newline="").read()
    recs = [r for r in by.get(f, []) if not r.get("sourced")]
    if not recs:
        return None
    gen = gen_parts(f, ent, recs, img)
    kept = {r["va"]: guard.refusal(r) for r in recs}
    kept = {va: why for va, why in kept.items() if why}
    # a definition that names a kept one stays generated with it: the kept one is declared only in the include
    while True:
        knames = {r.get("cname") or r["name"] for r in recs if r["va"] in kept}
        more = [r for r in recs if r["va"] not in kept and knames & names_in("".join(x or "" for x in gen[r["va"]]))]
        if not more:
            break
        for r in more:
            kept[r["va"]] = "points at a definition that stays generated"
    move = [r for r in recs if r["va"] not in kept]
    if not move:
        return dict(kept=kept, move=[])
    main_inc = G.include_path(f)
    body = text
    lines_in = set(x.strip() for x in text.splitlines())
    hows = collections.Counter()
    chars = char_arrays([dict(r, text=text_blob(img, r)) for r in move], ent.get("externs"))
    # the one-dimensional arrays of structs or scalars this file now defines with their plan type
    arrays = {r.get("cname") or r["name"]: r["model"] for r in move if r.get("model") and r["form"] != "bytes"
              and r["model"]["k"] == "arr" and r["model"]["elem"]["k"] in ("struct", "prim") and r["model"]["elem"].get("name")}
    # statics: each in place of its own include line
    for r in [r for r in move if G.is_static(r)]:
        g = gen[r["va"]]
        try:
            _, _, t, how = readable(r, img, ent, text, g, chars, arrays)
        except (Unreadable, G.NotRepresentable, G.Unresolved):
            t, how = definition(g[2], G.one_line(g[3]), g[4], int(r["va"], 16)), "generated form"
        hows[how] += 1
        ext = [e for e in (r.get("externs") or ()) if e.strip() not in lines_in]
        new = "\n".join(ext + [t])
        pat = re.compile(r'^[ \t]*#[ \t]*include[ \t]+"%s"[ \t]*$' % re.escape(r["include"]), re.M)
        if len(pat.findall(body)) != 1:
            raise G.PlanError("%s: no single include line for %s" % (f, r["include"]))
        body = pat.sub(lambda m: new, body)
    main = [r for r in move if not G.is_static(r)]
    if main:
        pieces = []
        for r in main:
            g = gen[r["va"]]
            try:
                sdef, fwd, t, how = readable(r, img, ent, text, g, chars, arrays)
            except (Unreadable, G.NotRepresentable, G.Unresolved):
                sdef, fwd, t, how = g[1], g[0], definition(g[2], g[3], g[4], int(r["va"], 16)), "generated form"
            hows[how] += 1
            pieces.append(Piece(r, sdef, fwd, t, how))
        seen = set(); fwds = []
        for i, p in enumerate(pieces):
            before = names_in("\n".join(q.text for q in pieces[:i]))
            if p.fwd and p.name in before:
                fwds.append(p.fwd)
        ext = []
        for e in ent.get("externs") or ():
            if e.strip() in lines_in or e in seen:
                continue
            nm = extern_name(e)
            if nm and not kept and not any(nm in names_in(p.text) for p in pieces):
                continue
            seen.add(e); ext.append(e)
        parts = []
        if ext:
            parts.append("\n".join(ext))
        types = [p.sdef for p in pieces if p.sdef]
        if types:
            parts.append("\n\n".join(types))
        if fwds:
            parts.append("\n".join(fwds))
        parts.append("\n\n".join(p.text for p in pieces))
        block = "\n\n".join(x.strip("\n") for x in parts)
        pat = re.compile(r'^[ \t]*#[ \t]*include[ \t]+"%s"[ \t]*$' % re.escape(main_inc), re.M)
        if len(pat.findall(body)) != 1:
            raise G.PlanError("%s: no single include line for %s" % (f, main_inc))
        keep_main = any(not G.is_static(r) for r in recs if r["va"] in kept)
        body = pat.sub(lambda m: block + ("\n\n" + m.group(0) if keep_main else ""), body)
    if "\r\n" in text:
        body = re.sub(r"(?<!\r)\n", "\r\n", body)
    return dict(text=body, move=move, kept=kept, hows=hows)


def update_plan(plan, f, res):
    ent = plan["files"][f]
    vas = {r["va"] for r in res["move"]}
    for r in plan["definitions"]:
        if r["file"] == f and r["va"] in vas:
            r["sourced"] = True
    left = [r for r in plan["definitions"] if r["file"] == f and not r.get("sourced")]
    main = [r for r in left if not G.is_static(r)]; st = [r for r in left if G.is_static(r)]
    ent["definitions"] = len(main); ent["bytes"] = sum(r["size"] for r in main)
    if "static_definitions" in ent or st:
        ent["static_definitions"] = len(st)
    ent["sourced"] = sum(1 for r in plan["definitions"] if r["file"] == f and r.get("sourced"))
    if not left:
        ent["state"] = "sourced"
        for k in ("include", "externs", "fn_types", "static_definitions", "inc_hmac"):
            ent.pop(k, None)
    elif not main:
        ent.pop("include", None)


NOTE = ("initialised game data: addresses, sizes, types, names and pointer targets; a record marked sourced is defined "
        "in its source file (tools/inlinedata.py), the values of the others are rendered from your own Game.exe into "
        "gen/data by tools/gendata.py")


def write_plan(plan):
    plan["note"] = NOTE
    with open(PLAN, "w", encoding="utf-8", newline="\n") as fh:
        fh.write(json.dumps(plan, indent=1) + "\n")


def check(plan):
    bad = 0
    for f, ent in sorted(plan["files"].items()):
        srec = [r for r in plan["definitions"] if r["file"] == f and r.get("sourced")]
        if not srec:
            continue
        path = os.path.join(ROOT, f)
        text = open(path, encoding="latin-1").read() if os.path.exists(path) else ""
        if ent["state"] == "sourced" and GEN_INCLUDE.search(text):
            print("%s: sourced but still includes gen/data" % f); bad += 1
        for r in srec:
            if not re.search(r"\b%s\b[^;]*=[^;]*" % re.escape(r.get("cname") or r["name"]), text) or \
                    ("// %s" % r["va"]) not in text:
                print("%s %s %s: sourced but not defined in the file" % (f, r["va"], r["name"])); bad += 1
    print("check: %s" % ("%d problems" % bad if bad else "every sourced definition is in its file"))
    return 1 if bad else 0


def main():
    a = sys.argv[1:]
    if not a or "-h" in a or "--help" in a:
        print(__doc__); return 0
    if "--check" in a:
        return check(G.load_plan(PLAN))
    mods = [a[i + 1] for i, x in enumerate(a) if x == "--module" and i + 1 < len(a)]
    files = [x.replace("\\", "/") for i, x in enumerate(a) if not x.startswith("--") and (i == 0 or a[i - 1] != "--module")]
    plan, img = plan_and_image()
    guard = Guard(img)
    todo = [f for f in sorted(plan["files"]) if any(f.startswith("Source/%s/" % m) for m in mods)]
    for f in files:
        f = os.path.relpath(os.path.abspath(f), ROOT).replace("\\", "/") if os.path.exists(f) else f
        if f not in plan["files"]:
            die("%s: the data plan has no definitions for it" % f)
        todo.append(f)
    if not todo:
        die("no files: name files or --module M")
    by = G.plan_defs(plan)
    tot = collections.Counter(); changed = False
    for f in todo:
        try:
            res = inline_file(f, plan, img, guard, by)
        except G.PlanError as e:
            die(str(e))
        if res is None:
            continue
        if res.get("skip"):
            print("%s: skipped, %s" % (f, res["skip"])); continue
        for va, why in sorted(res.get("kept", {}).items()):
            print("%s %s: stays generated, %s" % (f, va, why))
        if not res["move"]:
            continue
        nb = sum(r["size"] for r in res["move"])
        tot["files"] += 1; tot["definitions"] += len(res["move"]); tot["bytes"] += nb
        print("%s: %d definitions, %d bytes into source (%s)" % (f, len(res["move"]), nb, ", ".join("%d %s" % (v, k) for k, v in sorted(res["hows"].items()))))
        if "--print" in a:
            print(res["text"]); continue
        if "--dry" in a:
            continue
        with open(os.path.join(ROOT, f), "w", encoding="latin-1", newline="") as fh:
            fh.write(res["text"])
        update_plan(plan, f, res); changed = True
    if changed:
        write_plan(plan)
    print("%d files, %d definitions, %d bytes%s" % (tot["files"], tot["definitions"], tot["bytes"],
                                                   "" if changed else " (nothing written)"))
    return 0


if __name__ == "__main__":
    sys.exit(main())
