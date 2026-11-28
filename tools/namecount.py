#!/usr/bin/env python3
"""Count the names declared ahead of a symbol, and say which units a change moves.

A function's code can depend on how many names are declared before a global it references, modulo 64
(docs/declaration-order.md). This tool counts those names the way the compiler does, closely enough to compare
two versions of the tree:

  python tools/namecount.py --diff origin/main        which units this tree moves against REF, and by how much
  python tools/namecount.py --known [--diff REF]      the known sensitive functions: names before their symbols
  python tools/namecount.py --unit Source/X.cpp       the running count at every declaration of one unit
  python tools/namecount.py --unit Source/X.cpp --symbol gszEmptyAssertText

--diff compares each unit of build/units.json, with its headers expanded in include order, against the same unit
at REF. A unit whose count ahead of its own first declaration changed by a multiple of 64 cannot change; the
others are listed with the amount, largest group first. For the functions listed in docs/declaration-order.md it
reports the change at the symbol itself, which is what decides.

What a declaration counts (measured against the compiler; see the page above):
  variable or typedef 1 - enum 1 + enumerators - prototype 1 + parameters, every redeclaration again; the
  parameters of a function-pointer parameter or typedef count too - struct/class/union 6 + data members, +1 for
  a tag not seen before or for no tag at all - forward declaration 1 if the tag is new -
  D2_CHECK_SIZE 2, D2_CHECK_OFFSET 3 - function definition 2 + parameters + locals + string literals -
  a file included for the first time 1.
Methods, templates and function bodies are approximated; a change inside one is marked `~`.

Standard library only.
"""
import os, re, sys, json, subprocess, collections

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PERIOD = 64
TAG = re.compile(r"\b(struct|class|union|enum)\s+([A-Za-z_]\w*)")
CHECKS = {"D2_CHECK_SIZE": 2, "D2_CHECK_OFFSET": 3}


class Tree(object):
    """The sources of one version: the working tree, or a git revision."""

    def __init__(self, ref=None):
        self.ref = ref; self.cache = {}; self.items = {}

    def read(self, rel):
        if rel not in self.cache:
            if self.ref is None or rel.startswith("gen/"):
                # gen/ is generated from build/data_plan.json and not in git: both versions read the tree's copy
                p = os.path.join(ROOT, rel)
                self.cache[rel] = open(p, encoding="latin-1").read() if os.path.isfile(p) else None
            else:
                r = subprocess.run(["git", "show", "%s:%s" % (self.ref, rel)], capture_output=True, cwd=ROOT)
                self.cache[rel] = r.stdout.decode("latin-1") if r.returncode == 0 else None
        return self.cache[rel]

    def find(self, name, cur):
        parts = cur.split("/")
        cands = [os.path.normpath(os.path.join(os.path.dirname(cur), name)).replace("\\", "/"), "Source/Include/" + name, name]
        if len(parts) > 2 and parts[0] == "Source":
            cands.insert(1, "Source/%s/%s" % (parts[1], name))
        for c in cands:
            if self.read(c) is not None:
                return c
        return None


def strip(text):
    """Comments out, string and character literals reduced to a marker, line structure kept."""
    out = []; i = 0; n = len(text)
    while i < n:
        c = text[i]
        if text.startswith("//", i):
            j = text.find("\n", i); j = n if j < 0 else j; i = j
        elif text.startswith("/*", i):
            j = text.find("*/", i + 2); j = n - 2 if j < 0 else j
            out.append("\n" * text.count("\n", i, j + 2)); i = j + 2
        elif c == '"' or c == "'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            out.append('"S"' if c == '"' else "'c'"); i = j + 1
        else:
            out.append(c); i += 1
    return "".join(out)


def split_top(s, sep=","):
    """Split at `sep` outside (), [], {} and <>."""
    parts = []; depth = 0; cur = []
    for ch in s:
        if ch in "([{<": depth += 1
        elif ch in ")]}>": depth -= 1
        if ch == sep and depth == 0:
            parts.append("".join(cur)); cur = []
        else:
            cur.append(ch)
    parts.append("".join(cur))
    return parts


def params_of(decl):
    """Number of parameters of the last parenthesised list in a declarator."""
    depth = 0; end = decl.rfind(")")
    if end < 0:
        return 0
    i = end
    while i >= 0:
        if decl[i] == ")": depth += 1
        elif decl[i] == "(":
            depth -= 1
            if depth == 0: break
        i -= 1
    inner = decl[i + 1:end].strip()
    if inner in ("", "void"):
        return 0
    # a parameter that is itself a function pointer brings its own parameters, named or not
    return sum(1 + (params_of(p) if re.search(r"\(\s*(?:__\w+\s*)?\*[^()]*\)\s*\(", p) else 0) for p in split_top(inner))


def statements(code, line0=1):
    """Top-level items of a scope: (first line, text before any brace block, block text or None, text after it)."""
    i = 0; n = len(code); line = line0; start = None; head = []; sline = line
    while i < n:
        c = code[i]
        if c == "\n":
            line += 1
        if start is None and not c.isspace():
            start = i; sline = line; head = []
        if start is None:
            i += 1; continue
        if c == "#" and "".join(head).strip() == "":
            j = i
            while True:
                k = code.find("\n", j); k = n if k < 0 else k
                if k > 0 and code[k - 1] == "\\" and k < n:
                    line += 1; j = k + 1; continue
                break
            yield (sline, code[i:k].strip(), None, ""); i = k; start = None; continue
        if c == ";":
            yield (sline, "".join(head).strip(), None, ""); start = None; i += 1; continue
        if c == "{":
            depth = 0; j = i
            while j < n:
                if code[j] == "{": depth += 1
                elif code[j] == "}":
                    depth -= 1
                    if depth == 0: break
                j += 1
            block = code[i + 1:j]; hd = "".join(head).strip()
            k = j + 1; tail = []
            is_type = re.match(r"^(typedef\s+)?(struct|class|union|enum)\b", hd) and "(" not in hd
            is_init = hd.rstrip().endswith("=")
            if is_type or is_init:
                while k < n and code[k] != ";":
                    tail.append(code[k]); k += 1
                k += 1
            yield (sline, hd, block, "".join(tail).strip())
            line += code.count("\n", i, k); i = k; start = None; continue
        head.append(c); i += 1
    if start is not None and "".join(head).strip():
        yield (sline, "".join(head).strip(), None, "")


def body_cost(block):
    """Locals, string literals and nested blocks of a function body (approximate)."""
    n = block.count('"S"') + block.count("{")
    for st in re.split(r"[;{}]", block):
        st = st.strip()
        m = re.match(r"^(?:for\s*\(\s*)?(?:const\s+|static\s+|unsigned\s+|signed\s+|struct\s+)*[A-Za-z_]\w*(?:\s*[\*&]+\s*|\s+)(?:const\s+)?[A-Za-z_]\w*\s*(\[[^\]]*\])*\s*(=|$|,)", st)
        if m and not re.match(r"^(return|delete|goto|case|else|typedef|new|sizeof|throw)\b", st):
            n += len(split_top(st.split("=")[0])) if "=" not in st else 1 + st.count(",") * 0
    return n


class Counter(object):
    """Counts one translation unit. `tags` holds the struct, class, union and enum names seen so far."""

    def __init__(self, tree):
        self.t = tree; self.tags = set(); self.seen = set(); self.count = 0; self.rows = []; self.approx = False

    def new_tags(self, text, skip=None):
        n = 0
        for m in TAG.finditer(text):
            if m.group(2) != skip and m.group(2) not in self.tags:
                self.tags.add(m.group(2)); n += 1
        return n

    def add(self, rel, line, name, n, kind):
        self.count += n
        self.rows.append((rel, line, name, kind, n, self.count))

    def members(self, block):
        n = 0
        for _, hd, blk, tail in statements(block):
            if hd.startswith("#") or not (hd or blk):
                continue
            hd = re.sub(r"^(public|private|protected)\s*:\s*", "", hd)
            m = re.match(r"^(typedef\s+)?(struct|class|union)\b\s*(\w*)", hd)
            if blk is not None and m and "(" not in hd:
                n += 6 + self.members(blk) + (0 if m.group(3) and m.group(3) in self.tags else 1)
                if m.group(3): self.tags.add(m.group(3))
                n += len(split_top(tail)) if tail else 0
            elif blk is not None and hd.startswith("enum"):
                n += 1 + len([e for e in split_top(blk) if e.strip()])
            elif blk is not None:
                n += 3 + params_of(hd); self.approx = True
            elif "(" in hd and not re.search(r"\(\s*[\w:]*\s*\*", hd):
                n += 1 + params_of(hd); self.approx = self.approx or params_of(hd) > 0
            elif hd:
                n += self.new_tags(hd) + len(split_top(re.sub(r"\([^()]*\)\s*\(.*\)", "()", hd)))
                if re.search(r"\(\s*[\w:]*\s*\*", hd): n += params_of(hd)
        return n

    def scope(self, rel, code, line0=1):
        for line, hd, blk, tail in statements(code, line0):
            if hd.startswith("#"):
                m = re.match(r'#\s*include\s+"S"', hd)
                if m:
                    continue
                continue
            if not hd and blk is None:
                continue
            first = hd.split("(")[0].strip()
            mm = re.match(r"^(\w+)\s*\(", hd)
            if mm and mm.group(1) in CHECKS and blk is None:
                self.add(rel, line, mm.group(1), CHECKS[mm.group(1)], "check"); continue
            if re.match(r'^extern\s+"S"\s*$', hd) and blk is not None:
                self.scope(rel, blk, line); continue
            if re.match(r"^namespace\b", hd) and blk is not None:
                self.scope(rel, blk, line); continue
            if hd.startswith("template"):
                self.approx = True
                self.add(rel, line, "template", 2 + (self.members(blk) if blk is not None else 0), "template"); continue
            m = re.match(r"^(typedef\s+)?(struct|class|union)\b\s*(\w*)\s*(:[^{]*)?$", hd)
            if m and blk is not None:
                name = m.group(3); n = 6 + self.members(blk)
                if name and name not in self.tags:
                    self.tags.add(name); n += 1
                elif not name:
                    n += 1
                n += len(split_top(tail)) if tail else 0
                self.add(rel, line, name or tail, n, "struct"); continue
            m = re.match(r"^(typedef\s+)?enum\b\s*(\w*)\s*$", hd)
            if m and blk is not None:
                if m.group(2): self.tags.add(m.group(2))
                n = 1 + len([e for e in split_top(blk) if e.strip()]) + (len(split_top(tail)) if tail and m.group(1) else 0)
                self.add(rel, line, m.group(2) or "enum", n, "enum"); continue
            m = re.match(r"^(struct|class|union|enum)\s+(\w+)$", hd)
            if m and blk is None:
                n = 0 if m.group(2) in self.tags else 1
                self.tags.add(m.group(2)); self.add(rel, line, m.group(2), n, "forward"); continue
            if blk is not None and not hd.rstrip().endswith("=") and "(" in hd:
                nm = re.findall(r"([A-Za-z_~][\w:~]*)\s*\(", hd.split(")")[0] + ")")
                n = self.new_tags(hd) + 2 + params_of(hd) + body_cost(blk); self.approx = True
                self.add(rel, line, nm[-1] if nm else "?", n, "function"); continue
            if hd.startswith(("using ", "__pragma", "static_assert")):
                continue
            # a declaration: variables, a prototype, a typedef
            decl = hd[:-1].rstrip() if hd.endswith("=") else hd
            n = self.new_tags(decl)
            base = re.sub(r"=.*$", "", decl) if blk is None else decl
            names = re.findall(r"([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*(?:=|,|$|\()", re.sub(r"\([^()]*\)", "()", base))
            fnptr = re.search(r"\(\s*(?:__\w+\s*)?\*\s*(\w+)\s*\)\s*\(", decl)
            if fnptr and "(" in decl[:fnptr.start()]:
                fnptr = None    # a prototype with a function-pointer parameter, not a function-pointer variable
            if fnptr:
                n += 1 + params_of(decl); nm = fnptr.group(1); kind = "variable"
            elif re.search(r"\w\s*\(", base) and not base.startswith("typedef") or (base.startswith("typedef") and "(" in base):
                m2 = re.search(r"([A-Za-z_~]\w*)\s*\(", base)
                nm = m2.group(1) if m2 else "?"
                n += 1 + params_of(base); kind = "typedef" if base.startswith("typedef") else "prototype"
            else:
                parts = split_top(base)
                n += len(parts); kind = "typedef" if base.startswith("typedef") else "variable"
                m3 = re.search(r"([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*$", parts[0].strip())
                nm = m3.group(1) if m3 else "?"
            self.add(rel, line, nm, n, kind)

    def unit(self, rel):
        self.file(rel)
        return self

    def file(self, rel):
        text = self.t.read(rel)
        if text is None:
            return
        # includes are expanded in place, once each
        pos = 0; line = 1; chunks = []
        for m in re.finditer(r'^[ \t]*#[ \t]*include[ \t]+"([^"]+)"[^\n]*$', text, re.M):
            chunks.append((line, text[pos:m.start()], None))
            line += text.count("\n", pos, m.end()); pos = m.end()
            chunks.append((line, None, m.group(1)))
        chunks.append((line, text[pos:], None))
        for ln, code, inc in chunks:
            if inc is not None:
                tgt = self.t.find(inc, rel)
                if tgt and tgt not in self.seen:
                    self.seen.add(tgt); self.count += 1
                    self.rows.append((rel, ln, inc, "include", 1, self.count)); self.file(tgt)
                continue
            self.scope(rel, strip(code), ln)


def units():
    u = json.load(open(os.path.join(ROOT, "build", "units.json")))
    u = u["units"] if isinstance(u, dict) else u
    return [x["file"] for x in u if x.get("file", "").lower().endswith((".cpp", ".c"))]


def known():
    """The table of docs/declaration-order.md: (function, unit, [symbols])."""
    p = os.path.join(ROOT, "docs", "declaration-order.md"); out = []
    if not os.path.isfile(p):
        return out
    seen_header = False
    for ln in open(p, encoding="utf-8"):
        if ln.startswith("| Function |"):
            seen_header = True; continue
        if seen_header and ln.startswith("|") and not ln.startswith("|---"):
            c = [x.strip() for x in ln.strip().strip("|").split("|")]
            if len(c) >= 3:
                unit = c[1] if c[1].startswith("Source/") else "Source/" + c[1]
                out.append((c[0].replace("`", ""), unit, re.findall(r"`([A-Za-z_]\w*)`", c[2])))
        elif seen_header and not ln.startswith("|"):
            seen_header = False
    return out


def before(counter, unit, symbol):
    """Names declared before the first declaration of `symbol` (None if it is not declared by name)."""
    for rel, line, name, kind, n, total in counter.rows:
        if name == symbol and kind != "include":
            return total - n, rel, line
    return None


def first_own(counter, unit):
    for rel, line, name, kind, n, total in counter.rows:
        if rel == unit and kind != "include":
            return total - n
    return counter.count


def main(argv):
    ref = None; unit = None; symbol = None; want_known = False
    i = 0
    while i < len(argv):
        a = argv[i]
        if a == "--diff": ref = argv[i + 1]; i += 1
        elif a == "--unit": unit = argv[i + 1]; i += 1
        elif a == "--symbol": symbol = argv[i + 1]; i += 1
        elif a == "--known": want_known = True
        else:
            print(__doc__); return 2
        i += 1
    new = Tree(None); old = Tree(ref) if ref else None
    if unit and not want_known:
        c = Counter(new).unit(unit)
        if symbol:
            b = before(c, unit, symbol)
            if b is None:
                print("%s: %s is not declared by that name" % (unit, symbol)); return 1
            print("%s: %d names before %s (%s:%d); %d modulo %d" % (unit, b[0], symbol, b[1], b[2], b[0] % PERIOD, PERIOD))
            if old:
                co = Counter(old).unit(unit); bo = before(co, unit, symbol)
                if bo:
                    d = b[0] - bo[0]
                    print("  against %s: %+d (%d modulo %d)%s" % (ref, d, d % PERIOD, PERIOD, "" if d % PERIOD else "  -- no change possible"))
            return 0
        for rel, line, name, kind, n, total in c.rows:
            if rel == unit:
                print("%6d %+4d  %s:%d  %s %s" % (total, n, os.path.basename(rel), line, kind, name))
        print("%d names in all%s" % (c.count, " (some function bodies, methods or templates approximated)" if c.approx else ""))
        return 0
    if want_known:
        rows = known()
        if not rows:
            print("docs/declaration-order.md lists no functions"); return 1
        for fn, u, syms in rows:
            c = Counter(new).unit(u); co = Counter(old).unit(u) if old else None
            for s in syms:
                b = before(c, u, s)
                if b is None:
                    print("%-48s %-38s %s: not declared by that name" % (fn, u[7:], s)); continue
                msg = "%-48s %-38s %-28s %5d (%2d mod %d)" % (fn, u[7:], s, b[0], b[0] % PERIOD, PERIOD)
                if co:
                    bo = before(co, u, s)
                    if bo is not None:
                        d = b[0] - bo[0]
                        msg += "   %+d against %s%s" % (d, ref, "" if d % PERIOD == 0 else "   <-- MOVED")
                print(msg)
        return 0
    if not ref:
        print(__doc__); return 2
    kn = collections.defaultdict(list)
    for fn, u, syms in known():
        kn[u].append((fn, syms))
    groups = collections.defaultdict(list); moved_known = []
    for u in units():
        if new.read(u) is None:
            continue
        c = Counter(new).unit(u); co = Counter(old).unit(u)
        if old.read(u) is None:
            continue
        d = first_own(c, u) - first_own(co, u)
        e = c.count - co.count
        if d % PERIOD or e % PERIOD:
            groups[(d, e)].append((u, c.approx or co.approx))
        for fn, syms in kn.get(u, ()):
            for s in syms:
                b = before(c, u, s); bo = before(co, u, s)
                if b and bo and (b[0] - bo[0]) % PERIOD:
                    moved_known.append((u, fn, s, b[0] - bo[0]))
    if not groups:
        print("no unit moves against %s: every count changed by a multiple of %d" % (ref, PERIOD)); return 0
    print("units whose declaration count changed against %s by other than a multiple of %d" % (ref, PERIOD))
    print("(ahead of the unit's own first declaration / at its end; ~ = includes approximated function bodies)\n")
    for (d, e), us in sorted(groups.items(), key=lambda kv: -len(kv[1])):
        print("%+d / %+d names: %d unit%s" % (d, e, len(us), "" if len(us) == 1 else "s"))
        for u, ap in sorted(us)[:12]:
            print("    %s%s" % (u, " ~" if ap else ""))
        if len(us) > 12:
            print("    ... and %d more" % (len(us) - 12))
    if moved_known:
        print("\nknown sensitive functions whose symbol moved (these need checking first):")
        for u, fn, s, d in moved_known:
            print("    %s  %s: %s moved %+d (%d modulo %d)" % (u, fn, s, d, d % PERIOD, PERIOD))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
