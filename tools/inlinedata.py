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
  pointers            &symbol, &array[i], &function, string literals, as the plan resolves each relocation. A
                      pointer is written without a cast where the target's declared type (in the file or its
                      headers, under any name its address marker gives it) is the slot's: a function's return type,
                      calling convention and parameter types against a function-pointer slot or its typedef, an
                      object's type against a data-pointer slot. A placeholder extern `void __cdecl F()` from the
                      plan is replaced by F's own declaration (from its definition in Source/) where that makes the
                      types agree. A struct member the plan spells otherwise than the file's struct declares it
                      takes the file's typedef, and the plan model is corrected
  function tables     a blob of function pointers of one type is an array of that function-pointer type; a packed
                      struct gives each function pointer field its function's own type
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
--allow-casts  also write definitions that need a C-style pointer cast or volatile (the source audit counts both);
             without it such a definition stays generated and is listed
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
                tu = CUR.get("tu")
                own = tu and tu.members.get((m.get("name"), nm))
                if own and mm["k"] == "ptr" and mm.get("fn") and own in tu.fptr and tu.fptr[own] != tu.slot_sig(mm["spell"]):
                    # the plan's spelling of this member is not the file's: the struct declares it with its typedef
                    mm["spell"] = own; CUR.setdefault("model_fixes", []).append((m.get("name"), nm, own))
                items.append(self.value(mm, off + mo, names + [m.get("name"), nm]))
            for i in range(n):
                if not cover[i] and (raw[off + i] or any(r <= off + i < r + 4 for r in self.relocs)):
                    raise Unreadable("padding_not_zero")
            return Brace(trim(items), all(isinstance(x, str) for x in items) and len(items) > 8)
        raise Unreadable(m.get("why", "type"))


# ---------------------------------------------------------------------------------------------------------------

# ---------------------------------------------------------------------------------------------------------------
# the declarations a file sees, to write a pointer without a cast where the target's type is the slot's

CCS = ("__cdecl", "__stdcall", "__fastcall", "__thiscall")
TYPE_WORDS = {"int", "char", "short", "long", "unsigned", "signed", "void", "float", "double", "bool", "wchar_t",
              "__int64", "const", "volatile"}
STORAGE = {"extern", "static", "inline", "__inline", "__forceinline", "register", "typedef"}


def type_tokens(s):
    s = re.sub(r"__declspec\s*\((?:[^()]|\([^()]*\))*\)", " ", s)
    return [t for t in re.findall(r"[A-Za-z_]\w*|\*|&|\(|\)|,|\[|\]|\.\.\.", s) if t not in ("struct", "class", "union", "enum")]


def join_type(tok):
    out = ""
    for t in tok:
        if out and re.match(r"\w", t) and re.match(r".*\w$", out):
            out += " "
        out += t
    return out


class Sig:
    """A function type: return type, calling convention and parameter types, all normalised."""

    def __init__(self, ret, cc, params, text=None):
        self.ret, self.cc, self.params, self.text = ret, cc, params, text   # text: the declaration's own parameters

    def __eq__(self, o):
        return isinstance(o, Sig) and (self.ret, self.cc, self.params) == (o.ret, o.cc, o.params)

    def pointer(self, name=""):
        ps = " ".join(self.text.split()) if self.text is not None else ", ".join(self.params)
        return "%s (%s* %s)(%s)" % (self.ret, self.cc, name, ps or "void") if name else \
            "%s (%s*)(%s)" % (self.ret, self.cc, ", ".join(self.params))


def split_top(s, sep=","):
    out = []; d = 0; cur = ""
    for c in s:
        if c in "([":
            d += 1
        elif c in ")]":
            d -= 1
        if c == sep and d == 0:
            out.append(cur); cur = ""
        else:
            cur += c
    out.append(cur)
    return out


ALLOW_AUDIT = False   # --allow-casts: write a definition even where it needs a counted construct

PLACEHOLDER = re.compile(r'^extern (?:"C" )?void __cdecl ([A-Za-z_]\w*)\(\); // (0x[0-9A-F]{8})$')


class Defs:
    """Every function definition head in Source/ by address, to declare a callee with its own type where the data
    plan's externs only give it a placeholder `void __cdecl F()`."""

    def __init__(self):
        self.heads = None

    def load(self):
        self.heads = {}
        deco = {}
        for x in json.load(open(os.path.join(ROOT, "build", "functions.json")))["functions"]:
            if len(x) > 3:
                deco[int(x[0], 16)] = x[3]
        self.deco = deco
        for dp, dn, fn in os.walk(os.path.join(ROOT, "Source")):
            for n in fn:
                if not n.lower().endswith((".cpp", ".c")):
                    continue
                p = os.path.join(dp, n)
                lines = open(p, encoding="latin-1").read().splitlines()
                for i, ln in enumerate(lines):
                    m = re.match(r"^\s*//\s*(0x[0-9A-Fa-f]{8})\s*$", ln)
                    if not m:
                        continue
                    j = i + 1
                    while j < len(lines) and (not lines[j].strip() or lines[j].strip().startswith("//")):
                        j += 1
                    head = ""
                    while j < len(lines) and len(head) < 2000:
                        head += " " + lines[j].split("//")[0]
                        if "(" in head and head.count("(") == head.count(")"):
                            break
                        j += 1
                    nxt = lines[j + 1].strip() if j + 1 < len(lines) else ""
                    if nxt.startswith("{") or head.rstrip().endswith("{"):
                        self.heads.setdefault(int(m.group(1), 16), (head.strip().rstrip("{").strip(), n.lower().endswith(".c")))

    def declaration(self, tu, name, want):
        """`R CC name(params);` with the definition's own types, when they are the slot's, else None."""
        if self.heads is None:
            self.load()
        va = tu.placeholders[name]
        h = self.heads.get(va)
        if not h:
            return None
        head, is_c = h
        m = re.match(r"^(?P<pre>[^()]*?)\b%s\s*\((?P<params>.*)\)\s*$" % re.escape(name), head)
        if not m or re.search(r"\bstatic\b|\binline\b|__forceinline|::", m.group("pre")):
            return None
        g = tu.sig(m.group("pre"), m.group("params"))
        if g is None or (want is not None and g != want) or (want is None and not tu.known(g)):
            return None
        pre = re.sub(r"__declspec\s*\(\s*noinline\s*\)\s*", "", m.group("pre")).strip()
        pre = re.sub(r'^extern\s+"C"\s+', "", pre)
        d = self.deco.get(va)
        c_link = not (d or "").startswith("?") if d else (is_c or 'extern "C"' in head)
        decl = "%s%s %s(%s); // 0x%08X" % ('extern "C" ' if c_link and not CUR.get("lang_c") else "", pre, name,
                                          m.group("params").strip(), va)
        decl = " ".join(decl.split())
        if audit_hits(decl):
            return None
        return decl, g


DEFS = Defs()


class TU:
    """Typedefs, function and data declarations of one translation unit (the file and its headers)."""

    def __init__(self, text):
        self.alias = {}; self.fptr = {}; self.funcs = {}; self.data = {}
        self.placeholders = {}; self.redecl = {}; self.members = {}
        self.types = set(re.findall(r"\b(?:struct|class|union|enum)\s+([A-Za-z_]\w*)", text))
        t = re.sub(r"//[^\n]*|/\*.*?\*/", " ", text, flags=re.S)
        t = re.sub(r'"(?:\\.|[^"\\\n])*"', '""', t)
        t = re.sub(r"'(?:\\.|[^'\\\n])+'", "0", t)
        t = re.sub(r"^[ \t]*#[^\n]*", " ", t, flags=re.M)
        for st, opens in self.statements(t):
            try:
                self.take(st, opens)
            except (IndexError, ValueError):
                pass

    @staticmethod
    def statements(t):
        """Top-level statements: (text, True when a { body follows it)."""
        i = 0; n = len(t); cur = []; out = []
        while i < n:
            c = t[i]
            if c == ";":
                out.append(("".join(cur), False)); cur = []; i += 1; continue
            if c == "{":
                head = "".join(cur)
                if re.search(r'extern\s*""\s*$', head):
                    cur = []; i += 1; continue
                d = 0; j = i
                while j < n:
                    if t[j] == "{":
                        d += 1
                    elif t[j] == "}":
                        d -= 1
                        if d == 0:
                            break
                    j += 1
                if "=" in head and not re.search(r"\boperator\b", head):
                    cur.append(" = {}"); i = j + 1; continue
                m = re.match(r"\s*(?:typedef\s+)?(?:struct|class|union)\s+([A-Za-z_]\w*)\s*$", head)
                if m:
                    out.append(("\0members " + m.group(1) + " " + t[i + 1:j], False))
                if re.match(r"\s*(typedef\s+)?(struct|class|union|enum)\b", head):
                    cur.append(" {}"); i = j + 1; continue
                out.append((head, True)); cur = []; i = j + 1; continue
            if c == "}":
                cur = []; i += 1; continue
            cur.append(c); i += 1
        return out

    def norm(self, tok):
        out = []
        for x in tok:
            if x in self.alias:
                out.extend(self.alias[x])
            else:
                out.append(x)
        return join_type(out)

    def param(self, p):
        p = p.split("=")[0]
        p = re.sub(r"\(\s*(__\w+)?\s*\*\s*[A-Za-z_]\w*\s*\)", lambda m: "(%s*)" % (m.group(1) or "__cdecl"), p)
        m = re.match(r"^(?P<ret>[^()]*)\(\s*(?P<cc>__\w+)?\s*\*\s*\)\s*\((?P<params>.*)\)\s*$", p.strip())
        if m:
            g = self.sig(m.group("ret") + " " + (m.group("cc") or ""), m.group("params"))
            return g.pointer() if g else None
        tok = type_tokens(p)
        if "(" in tok or "[" in tok:
            return None
        if tok == ["..."]:
            return "..."
        if len(tok) > 1 and re.match(r"[A-Za-z_]\w*$", tok[-1]) and tok[-1] not in TYPE_WORDS and tok[-1] not in self.alias \
                and not all(x in TYPE_WORDS for x in tok):
            tok = tok[:-1]
        return self.norm(tok)

    def params(self, s):
        s = s.strip()
        if s in ("", "void"):
            return ()
        ps = [self.param(p) for p in split_top(s)]
        return None if None in ps else tuple(ps)

    def sig(self, pre, params):
        tok = [x for x in type_tokens(pre) if x not in STORAGE]
        cc = next((x for x in tok if x in CCS), "__cdecl")
        tok = [x for x in tok if x not in CCS]
        ps = self.params(params)
        if ps is None or not tok:
            return None
        return Sig(self.norm(tok), cc, ps, params.strip())

    def slot_sig(self, spell):
        """The function type of a slot's spelling: `R (CC*)(P)` or a typedef of one."""
        s = (spell or "").strip()
        if re.match(r"^[A-Za-z_]\w*$", s):
            return self.fptr.get(s)
        m = re.match(r"^(?P<ret>[^()]*)\(\s*(?P<cc>__\w+)?\s*\*\s*(?:const\s*)?\)\s*\((?P<params>.*)\)\s*$", s)
        if not m:
            return None
        return self.sig(m.group("ret") + " " + (m.group("cc") or ""), m.group("params"))

    def take(self, st, opens):
        if st.startswith("\0members "):
            _, name, body = st.split(" ", 2)
            for d in body.split(";"):
                d = " ".join(d.split())
                m = re.match(r"^([^(){}\[\]]*?)\b([A-Za-z_]\w*)$", d)
                if m and "," not in m.group(1) and m.group(1).strip():
                    self.members[(name, m.group(2))] = m.group(1).strip()
            return
        s = " ".join(st.split())
        s = re.sub(r'^extern\s*""\s*', "extern ", s)
        if not s or "::" in s or "<" in s or "operator" in s:
            return
        if s.startswith("typedef "):
            m = re.match(r"^typedef (?P<ret>[^()]*)\(\s*(?P<cc>__\w+)?\s*\*\s*(?P<name>\w+)\s*\)\s*\((?P<params>.*)\)$", s)
            if m:
                g = self.sig(m.group("ret") + " " + (m.group("cc") or ""), m.group("params"))
                if g:
                    self.fptr[m.group("name")] = g
                return
            m = re.match(r"^typedef ([^(){}\[\]]*?)\b(\w+)$", s)
            if m and "," not in m.group(1):
                tok = [x for x in type_tokens(m.group(1)) if x != "typedef"]
                if tok and m.group(2) not in tok:
                    self.alias[m.group(2)] = tok
            return
        s = re.sub(r"\s*=.*$", "", s) if not opens else s
        m = re.match(r"^(?P<pre>[^()]*?)\b(?P<name>[A-Za-z_]\w*)\s*\((?P<params>.*)\)(?:\s*const)?$", s)
        if m and "=" not in m.group("pre"):
            g = self.sig(m.group("pre"), m.group("params"))
            name = m.group("name")
            if g and name not in self.funcs:
                self.funcs[name] = g
            elif g and self.funcs[name] != g:
                self.funcs[name] = False
            return
        if opens:
            return
        m = re.match(r"^(?P<pre>[^()\[\],]*?)\b(?P<name>[A-Za-z_]\w*)\s*(?P<dims>(?:\[[^\]]*\]\s*)*)$", s)
        if m:
            tok = [x for x in type_tokens(m.group("pre")) if x not in STORAGE]
            if not tok:
                return
            dims = m.group("dims").count("[")
            v = (self.norm(tok), dims)
            if self.data.setdefault(m.group("name"), v) != v:
                self.data[m.group("name")] = False

    def func_type(self, nm):
        """The type `&nm` has here: its own declaration's, a placeholder replaced by the definition's where the
        definition's types are all declared here."""
        if nm in self.placeholders and nm not in self.redecl:
            d = DEFS.declaration(self, nm, None)
            if d:
                self.redecl[nm] = d[0]; self.funcs[nm] = d[1]
        g = self.funcs.get(nm)
        return g if isinstance(g, Sig) else None

    def known(self, g):
        words = set(re.findall(r"[A-Za-z_]\w*", g.pointer())) - set(CCS) - TYPE_WORDS
        return all(w in self.types or w in self.alias or w in self.fptr for w in words)

    def pointer(self, names, kind, spell):
        """An expression for the target under one of its names that has the slot's type without a cast, or None."""
        sp = (spell or "").strip()
        fs = self.slot_sig(sp)
        for nm in names:
            if kind == "func" or nm in self.funcs:
                g = self.funcs.get(nm)
                if g and fs and g == fs:
                    return "&" + nm
                if fs and nm in self.placeholders and nm not in self.redecl:
                    d = DEFS.declaration(self, nm, fs)
                    if d:
                        self.redecl[nm] = d[0]; self.funcs[nm] = d[1]
                        return "&" + nm
                continue
            d = self.data.get(nm)
            if not d or fs:
                continue
            base, dims = d
            m = re.match(r"^(.*?)\s*\*\s*(const)?$", sp)
            if not m or dims > 1:
                continue
            pointee = self.norm(type_tokens(m.group(1)))
            expr = nm if dims == 1 else "&" + nm
            if pointee == base or pointee == "const " + base or (pointee in ("void", "const void") and not base.startswith("const")) \
                    or pointee == "const void":
                return expr
        return None


CUR = {}   # the declarations of the file being written ("tu") and the names the markers give each address ("at")


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
        tu = CUR.get("tu")
        if tu and not off:
            e = tu.pointer([nm] + [x for x in CUR["at"].get(t_va, ()) if x != nm], kind, spell)
            if e:
                return e
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


def typed_packed(va, raw, relocs, rd, fsig):
    """gendata's packed struct with each function pointer field given the function's own type, so it needs no cast."""
    fields = []; items = []; pos = 0; k = 0; n = len(raw)
    for r in sorted(relocs):
        if r > pos:
            fields.append("    unsigned char b%d[%d];" % (k, r - pos))
            items.append(Brace(trim(["0x%02X" % c for c in raw[pos:r]]), True)); k += 1
        if r in fsig:
            fields.append("    %s;" % fsig[r][0].pointer("p%d" % k)); items.append("&" + fsig[r][1])
        else:
            fields.append("    const void* p%d;" % k); items.append(rd.ptr(r, "const void*", False))
        k += 1; pos = r + 4
    if pos < n:
        fields.append("    unsigned char b%d[%d];" % (k, n - pos))
        items.append(Brace(trim(["0x%02X" % c for c in raw[pos:]]), True))
    sdef = "#pragma pack(push, 1)\nstruct d2data_%08X_t\n{\n%s\n};\n#pragma pack(pop)" % (va, "\n".join(fields))
    return sdef, lay(Brace(items, False))


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
    bt = CUR.get("blobs", {}).get(cname) if not relocs else None
    if bt:
        ty, kind, size = bt
        items = trim([int_text(int.from_bytes(raw[i:i + size], "little"), size, kind, False, False) for i in range(0, n, size)])
        decl = "%s%s%s %s[%d]" % (ec, cst, ty, cname, n // size)
        return None, decl + "; // 0x%08X" % va, definition(decl + " = ", lay(Brace(items, True), 0, len(decl) + 19), tail, va), "typed"
    if not relocs:
        s = raw.rstrip(b"\0")
        if text_blob(img, r):
            decl = "%s%schar %s[%d]" % (ec, cst, cname, n)
            return None, decl + "; // 0x%08X" % va, decl + " = " + esc(c_string(s, False)) + tail, "text"
        items = trim(["0x%02X" % c for c in raw])
        decl = "%s%sunsigned char %s[%d]" % (ec, cst, cname, n)
        return None, decl + "; // 0x%08X" % va, definition(decl + " = ", lay(Brace(items, True), 0, len(decl) + 19), tail, va), "bytes"
    fsig = {}
    tu = CUR.get("tu")
    if tu:
        for o, tva, how, nm, po, kind in r["pointers"]:
            if kind == "func" and not po and o in relocs:
                g = tu.func_type(nm)
                if g:
                    fsig[o] = (g, nm)
    if va % 4 == 0 and n % 4 == 0 and all(o % 4 == 0 for o in relocs) and \
            all(o in relocs or not any(raw[o:o + 4]) for o in range(0, n, 4)):
        lit = all(p[2] == "literal" for p in r["pointers"])
        sigs = {fsig[o][0].pointer() for o in relocs if o in fsig}
        if not lit and len(fsig) == len(relocs) and len(sigs) == 1:
            g = fsig[min(fsig)][0]
            decl = "%s%s" % (ec, g.pointer(("const " if cst else "") + "%s[%d]" % (cname, n // 4)))
            items = ["&" + fsig[o][1] if o in relocs else "0" for o in range(0, n, 4)]
            body = lay(Brace(trim(items), False), 0, len(decl) + 19)
            return None, decl + "; // 0x%08X" % va, definition(decl + " = ", body, tail, va), "function table"
        if not fsig:
            et = "const char*" if lit else "const void*"
            items = [rd.ptr(o, et, False) if o in relocs else "0" for o in range(0, n, 4)]
            decl = "%s%s%s %s%s[%d]" % (ec, et, " const" if cst else "", "", cname, n // 4)
            body = lay(Brace(trim(items), False), 0, len(decl) + 19)
            return None, decl + "; // 0x%08X" % va, definition(decl + " = ", esc(body), tail, va), "pointers"
    if fsig:
        sdef, init = typed_packed(va, raw, relocs, rd, fsig)
        return sdef, fwd, definition(head, esc(init), tail, va), "packed"
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


def spell_at(m, off):
    """The model's pointer member at byte offset off, or None."""
    k = m["k"]
    if k == "ptr":
        return m if off == 0 else None
    if k == "arr":
        es = m["elem"]["size"]
        return spell_at(m["elem"], off % es) if es and off < m["size"] else None
    if k in ("struct", "union"):
        for nm, mo, mm in m["members"]:
            if mo <= off < mo + mm["size"]:
                return spell_at(mm, off - mo)
    return None


def blob_types(move):
    """{cname: (element type, kind, size)} for this file's pointer-free byte blobs that a typed slot of the file
    points at as an array of a scalar type: the blob is written with that type."""
    blobs = {r["cname"]: r for r in move if r["form"] == "bytes" and not r["pointers"]}
    out = {}
    for r in move:
        if not r.get("model") or r["form"] == "bytes":
            continue
        for off, tva, how, nm, po, kind in r["pointers"]:
            b = blobs.get(nm)
            p = spell_at(r["model"], off) if b and not po else None
            mt = p and re.match(r"^(const )?\s*([A-Za-z_][\w ]*?)\s*\*$", p["spell"] or "")
            if not mt or mt.group(2) not in G.PRIM_KIND:
                continue
            kind_, size = G.PRIM_KIND[mt.group(2)]
            if kind_ in "su" and b["size"] % size == 0 and int(b["va"], 16) % size == 0:
                if out.setdefault(nm, (mt.group(2), kind_, size)) != (mt.group(2), kind_, size):
                    out[nm] = None
    return {k: v for k, v in out.items() if v}


def file_types(f, text, ent, move):
    """The declarations the file sees once its data is written into it, and the addresses its markers name."""
    import checker
    from common import expand_gen_includes
    src = expand_gen_includes(GEN_INCLUDE.sub("", text), f)
    bt = blob_types(move)
    extra = list(ent.get("externs") or ()) + [r["head"].rstrip().rstrip("=").rstrip() + ";" for r in move
                                               if r.get("model") and r["form"] != "bytes"]
    for nm, (ty, k, sz) in bt.items():
        r = next(x for x in move if x["cname"] == nm)
        extra.append("%s%s %s[%d];" % ("const " if r["region"] == "rdata" else "", ty, nm, r["size"] // sz))
    src = src + "\n" + "\n".join(extra)
    at = collections.defaultdict(list)
    defs, decls, symbols = checker.parse_markers(src)
    for d in (decls, defs):
        for nm, va in d.items():
            if isinstance(va, int) and nm not in at[va]:
                at[va].append(nm)
    tu = TU(src)
    base = TU(expand_gen_includes(GEN_INCLUDE.sub("", text), f))
    for e in ent.get("externs") or ():
        m = PLACEHOLDER.match(e.strip())
        if m and m.group(1) not in base.funcs and not re.search(r"\b%s\b" % m.group(1), GEN_INCLUDE.sub("", text)):
            tu.placeholders[m.group(1)] = int(m.group(2), 16)
    return dict(tu=tu, at=at, lang_c=ent.get("lang") == "c", blobs=bt)


AUDIT = (("pointer cast", re.compile(r"\(\s*(?:const\s+)?(?:unsigned\s+)?\w+\s*\*+\s*\)")),
         ("volatile", re.compile(r"\bvolatile\b")))


def audit_hits(text):
    """The constructs the source audit counts (C-style pointer casts, volatile) in text written into a file."""
    code = re.sub(r"//[^\n]*", "", re.sub(r'"(?:\\.|[^"\\\n])*"', '""', text or ""))
    return [nm for nm, rx in AUDIT for _ in rx.findall(code)]


def inline_file(f, plan, img, guard, by, hold=None):
    """hold: {va: reason} of definitions to leave generated besides the refused ones."""
    res = None
    hold = dict(hold or {})
    for _ in range(20):
        res = inline_once(f, plan, img, guard, by, hold)
        if not res or not res.get("audit"):
            return res
        hold.update(res["audit"])
    return res


def inline_once(f, plan, img, guard, by, hold):
    """(new text, sourced records, kept records, notes) for one file, or None when there is nothing to move."""
    ent = plan["files"][f]
    if ent["state"] not in G.GEN_STATES and not companions(plan, f) or ent["state"] == "static":
        return None
    path = os.path.join(ROOT, f)
    if not os.path.exists(path):
        return dict(skip="the plan's file does not exist")
    text = open(path, encoding="latin-1", newline="").read()
    recs = [r for r in by.get(f, []) + [x for g in companions(plan, f) for x in by.get(g, [])] if not r.get("sourced")]
    if not recs:
        return None
    gen = gen_parts(f, ent, recs, img)
    kept = {r["va"]: guard.refusal(r) or hold.get(r["va"]) for r in recs}
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
    CUR.clear(); CUR.update(file_types(f, text, ent, move))
    if any(not G.is_static(r) for r in recs if r["va"] in kept):
        CUR["tu"].placeholders.clear()   # the include keeps the placeholder externs: no second declaration
    main_inc = G.include_path(f)
    body = text
    lines_in = set(x.strip() for x in text.splitlines())
    hows = collections.Counter(); audit = {}; written = 0
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
        hows[how] += 1; written += audit_hits(t).count("pointer cast")
        if audit_hits(t) and not ALLOW_AUDIT:
            audit[r["va"]] = "would need %s" % ", ".join(sorted(set(audit_hits(t))))
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
            hows[how] += 1; written += audit_hits(t + (sdef or "")).count("pointer cast")
            if audit_hits(t + (sdef or "")) and not ALLOW_AUDIT:
                audit[r["va"]] = "would need %s" % ", ".join(sorted(set(audit_hits(t + (sdef or "")))))
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
            seen.add(e); ext.append(CUR["tu"].redecl.get(nm, e) if nm else e)
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
    if audit:
        return dict(audit=audit)
    for nm, d in CUR["tu"].redecl.items():
        if audit_hits(d):
            return dict(audit={})   # not reached: declarations with counted constructs are not written
    if "\r\n" in text:
        body = re.sub(r"(?<!\r)\n", "\r\n", body)
    gen_casts = sum(audit_hits("".join(x or "" for x in gen[r["va"]])).count("pointer cast") for r in move)
    return dict(text=body, move=move, kept=kept, hows=hows, casts=(gen_casts, written))


def companions(plan, f):
    """The plan's `<file>.static.<ext>` entries: statics the file itself includes, recorded under a name of their own."""
    stem, ext = os.path.splitext(f)
    return [g for g, e in plan["files"].items() if e["state"] == "static" and g.lower() == (stem + ".static" + ext).lower()]


def update_plan(plan, f, res):
    for g in companions(plan, f):
        update_entry(plan, g, res)
    update_entry(plan, f, res)


def update_entry(plan, f, res):
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
        if ent["state"] == "sourced" and G.include_path(f) in GEN_INCLUDE.findall(text):
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
    global ALLOW_AUDIT
    ALLOW_AUDIT = "--allow-casts" in a
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
        tot["gen_casts"] += res["casts"][0]; tot["casts"] += res["casts"][1]
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
    print("%d files, %d definitions, %d bytes%s; pointer casts: %d written, %d of gendata's avoided"
          % (tot["files"], tot["definitions"], tot["bytes"], "" if changed else " (nothing written)", tot["casts"],
             tot["gen_casts"] - tot["casts"]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
