#!/usr/bin/env python3
"""Write a module's export header from its definitions, and replace the other modules' private copies with it.

  python tools/genheaders.py --module M [--header NAME.h] [--inside] [--exclude FILE] [--only VA,...]
                             [--min-units N] [--apply] [--units-out FILE] [--report FILE]

For module M (the second component of the path under Source/), every function and global that a file of M defines
and that a unit of another module declares (the same identifier, on a line ending in the definition's `// 0xVA`)
gets one declaration, taken from the definition: the exact return and parameter types, the calling convention, and
C linkage where the definition has it (extern "C", or a .c file). The declarations go to Source/Include/<M>Api.h
(or --header), the header the other modules' units include; a declaration a Source/Include header already has
stays in that header and is corrected there. The include path of every unit is the repository root, its module's
directory and Source/Include, so an export header has to be in Source/Include to be seen by other modules.

Without --apply it prints what it would do: per symbol, the address, the name, the units that declare it and the
header it goes to, or why it is left out. With --apply:

  - the export header is written (created, or the new declarations appended after its last line, with the forward
    declarations they need);
  - a declaration of the address in another header is rewritten to the definition's;
  - in each unit that declared a symbol privately (a single line at file scope), that line goes, and the unit
    includes the export header after its last #include (unless it already does).

--inside also takes M's own units (a file of M that declares what another file of M defines). --exclude FILE
names what to leave alone, one per line: an address (0x...), a unit path, or a unit path and an address separated
by whitespace; # starts a comment. --units-out writes the units to rebuild (every changed unit and every unit that
includes a changed header) as one comma-separated line for `tools/build.py --files`.

Left out, with the reason printed: a definition that is static, inline, a member or a function-pointer global; a
signature that needs a type no Source/Include header defines (a typedef, or a struct taken by value, declared only
in a .cpp); a const global without extern (internal linkage); an address defined in more than one file of M (the
duplicate_data item, which needs its extra definitions removed first); and a unit whose copy has another name.

The tool only edits text. Build the units it lists with tools/build.py and leave out (--exclude) any unit or
symbol whose bytes change.
"""
import argparse, collections, glob, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
if os.path.isdir('Source') and os.path.isdir('tools'):
    ROOT = os.getcwd()          # run from a checkout: that checkout

VA_TAIL = re.compile(r'//\s*(0x[0-9A-Fa-f]{8})\s*$')
CONV = ('__cdecl', '__stdcall', '__fastcall', '__thiscall')

BUILTIN = set('''void char short int long unsigned signed float double const volatile bool wchar_t __int64 __int8 __int16
__int32 struct union enum class extern __cdecl __stdcall __fastcall __thiscall'''.split())


def read(path):
    with open(os.path.join(ROOT, path), encoding='latin-1', newline='') as f:
        return f.read()


def write(path, text):
    with open(os.path.join(ROOT, path), 'w', encoding='latin-1', newline='') as f:
        f.write(text)


def rel(path):
    return os.path.relpath(path, ROOT).replace(os.sep, '/')


def module_of(path):
    p = path.split('/')
    return p[1] if len(p) > 2 and p[0] == 'Source' else None


def sources():
    out = []
    for ext in ('cpp', 'c', 'CPP', 'C'):
        out += glob.glob(os.path.join(ROOT, 'Source', '**', '*.' + ext), recursive=True)
    return sorted({rel(p) for p in out})


def headers():
    out = glob.glob(os.path.join(ROOT, 'Source', '**', '*.h'), recursive=True)
    out += glob.glob(os.path.join(ROOT, 'Source', '**', '*.H'), recursive=True)
    return sorted({rel(p) for p in out})


def squash(s):
    return re.sub(r'\s+', ' ', s.replace('\r', '')).strip()


def strip_comments(s):
    s = re.sub(r'/\*.*?\*/', ' ', s, flags=re.S)
    return re.sub(r'//[^\n]*', ' ', s)


# ---------------------------------------------------------------- types the headers and sources define

class Types:
    def __init__(self, hdrs, srcs):
        self.kind = {}       # name -> struct/union/class/enum/typedef
        self.where = collections.defaultdict(set)   # name -> files defining it
        for f in hdrs + srcs:
            t = strip_comments(read(f))
            for m in re.finditer(r'^\s*(?:typedef\s+)?(struct|union|enum|class)\s+(\w+)\s*(?::[^{;]*)?\{', t, re.M):
                self.add(m.group(2), m.group(1), f)
            for m in re.finditer(r'\}\s*(\w+)\s*;', t):
                pass
            for m in re.finditer(r'^\s*typedef\b([^;{]*?)\b(\w+)\s*(?:\[[^\]]*\])?\s*;', t, re.M):
                self.add(m.group(2), 'typedef', f)
            for m in re.finditer(r'^\s*typedef\b[^;{]*\(\s*(?:__\w+\s*)?\*\s*(\w+)\s*\)', t, re.M):
                self.add(m.group(1), 'typedef', f)
            for m in re.finditer(r'^\s*typedef\s+(?:struct|union|enum)\s*\w*\s*\{.*?\}\s*(\w+)\s*;', t, re.M | re.S):
                self.add(m.group(1), 'typedef', f)

    def add(self, name, kind, f):
        self.kind.setdefault(name, kind)
        self.where[name].add(f)

    def shared_header(self, name):
        hs = sorted(f for f in self.where.get(name, ()) if f.startswith('Source/Include/') and f.lower().endswith('.h'))
        return hs[0] if hs else None


def type_words(sig, name):
    s = strip_comments(sig)
    words = re.findall(r'\b([A-Za-z_]\w*)\b', s)
    return [w for w in words if w not in BUILTIN and w != name and not w.startswith('__')]


def needs(sig, name, types):
    """(forward declarations, headers to include, problem) for a declaration's type names."""
    fwd, inc = set(), set()
    flat = re.sub(r'\b(struct|union|class|enum)\s+', '', strip_comments(sig))
    params = flat[flat.find('(') + 1:flat.rfind(')')] if '(' in flat else ''
    ret = flat[:flat.find('(')] if '(' in flat else flat
    pieces = [ret] + [p for p in params.split(',')]
    for w in sorted(set(type_words(sig, name))):
        k = types.kind.get(w)
        if k is None:
            # a parameter name, a Windows typedef or an unknown type: parameter names are the usual case
            if any(re.search(r'\b%s\b\s*[\*&]' % re.escape(w), p) or re.match(r'\s*(?:const\s+)?%s\b\s*\w' % re.escape(w), p)
                   for p in pieces):
                hdr = None
                if hdr is None and not re.match(r'^[A-Z][A-Z0-9_]*$', w):
                    return fwd, inc, 'unknown type %s' % w
            continue
        by_value = any(re.search(r'(?:^|[\s,(])(?:const\s+)?%s\b(?!\s*[\*&])\s*\w*\s*(?:\[[^\]]*\])?\s*$' % re.escape(w), p.strip())
                       for p in pieces)
        if k in ('struct', 'union', 'class') and not by_value:
            fwd.add((k if k != 'class' else 'struct', w))
            continue
        hdr = types.shared_header(w)
        if not hdr:
            return fwd, inc, '%s %s is defined only in %s' % (k, w, ', '.join(sorted(types.where[w]))[:120])
        inc.add(os.path.basename(hdr))
    return fwd, inc, None


# ---------------------------------------------------------------- definitions

FUNC_HEAD = re.compile(r'^// (0x[0-9A-Fa-f]{8})[ \t]*\r?\n', re.M)


def function_defs(path):
    """(va, name, signature text, c linkage) of every function defined after a `// 0xVA` line."""
    t = read(path)
    is_c = path.lower().endswith('.c')
    out = []
    for m in FUNC_HEAD.finditer(t):
        p = m.end()
        while t.startswith('//', p):
            p = t.index('\n', p) + 1
        brace = t.find('{', p)
        semi = t.find(';', p)
        if brace < 0 or (0 <= semi < brace):
            continue
        sig = t[p:brace]
        if '#' in sig or '(' not in sig:
            continue
        sig = squash(strip_comments(sig))
        head = sig[:sig.find('(')]
        nm = re.search(r'([A-Za-z_]\w*)\s*$', head)
        if not nm:
            continue
        name = nm.group(1)
        why = None
        if re.match(r'^(static|inline|__inline|__forceinline)\b', sig) or re.search(r'\b(static|inline|__inline|__forceinline)\b', head):
            why = 'static or inline'
        elif '::' in head or 'operator' in head:
            why = 'member'
        c = is_c
        if sig.startswith('extern "C"'):
            c = True
            sig = sig[len('extern "C"'):].strip()
        sig = re.sub(r'__declspec\s*\(\s*(?:noinline|dllexport|naked|noreturn)\s*\)\s*', '', sig).strip()
        out.append((m.group(1).upper().replace('0X', '0x'), name, sig, c, why))
    return out


DATA_LINE = re.compile(r'^(?!\s)(?!extern\b|static\b|typedef\b|#|//|return\b)([^;{}()]*?)\b([A-Za-z_]\w*)\s*((?:\[[^\]]*\]\s*)*)\s*(=[^\n]*|;)[^\n]*$')


def data_defs(path):
    """(va, name, declaration, c linkage, problem) of every global defined on a line that carries its `// 0xVA`."""
    t = read(path)
    is_c = path.lower().endswith('.c')
    lines = t.split('\n')
    out = []
    for i, l in enumerate(lines):
        l = l.rstrip('\r')
        m = VA_TAIL.search(l)
        va = m.group(1) if m else None
        code = l[:m.start()].rstrip() if m else l
        if not va and i > 0:
            pm = re.match(r'^// (0x[0-9A-Fa-f]{8})\s*$', lines[i - 1].rstrip('\r'))
            if pm and not code.endswith(')') and '(' not in code.split('=')[0]:
                va = pm.group(1)
        if not va or not code or code[0].isspace():
            continue
        c = is_c
        if code.startswith('extern "C" ') and '=' in code:
            c = True
            code = code[len('extern "C" '):]
        if code.startswith('extern') or code.startswith('static') or code.startswith('typedef'):
            continue
        lhs = code.split('=')[0].rstrip()
        if '(' in lhs:
            if re.search(r'\(\s*(?:__\w+\s*)?\*', lhs):
                out.append((va.upper().replace('0X', '0x'), re.findall(r'\*\s*(\w+)', lhs)[0] if re.findall(r'\*\s*(\w+)', lhs) else '?', None, c, 'function-pointer global'))
            continue
        if not (code.endswith(';') or code.endswith('{') or '=' in code):
            continue
        lhs = lhs.rstrip(';').rstrip()
        dm = re.match(r'^(.*?)\b([A-Za-z_]\w*)\s*((?:\[[^\]]*\]\s*)*)$', lhs)
        if not dm or not dm.group(1).strip():
            continue
        ty, name, dims = dm.group(1).strip(), dm.group(2), re.sub(r'\s+', '', dm.group(3))
        if ty in ('return', 'goto', 'case', 'else', 'delete') or ty.endswith(','):
            continue
        why = None
        if re.match(r'^const\b', ty) and not c and '*' not in ty:
            why = 'const without extern (internal linkage)'
        if dims and '[]' in dims and '=' not in code:
            why = 'array of unknown bound without initializer'
        decl = '%s %s%s' % (ty, name, dims)
        out.append((va.upper().replace('0X', '0x'), name, decl, c, why))
    return out


# ---------------------------------------------------------------- references

def decl_lines(text, va):
    """Lines (index, text) at file scope that end in `// va` and declare something (end in ';')."""
    out = []
    for i, l in enumerate(text.split('\n')):
        m = VA_TAIL.search(l.rstrip('\r'))
        if not m or m.group(1).lower() != va.lower():
            continue
        code = l[:m.start()].rstrip()
        if not code.endswith(';') or not code or code[0].isspace():
            continue
        out.append((i, l))
    return out


def declared_name(code):
    code = strip_comments(code).strip().rstrip(';').strip()
    if '(' in code:
        head = code[:code.find('(')]
        if re.search(r'\(\s*(?:__\w+\s*)?\*', code):
            return None, 'pointer'
        m = re.search(r'([A-Za-z_]\w*)\s*$', head)
        return (m.group(1), 'func') if m else (None, None)
    m = re.search(r'([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*$', code)
    if not m:
        return None, None
    return m.group(1), 'data' if code.startswith('extern') else 'def'


def add_include(text, hdr):
    if re.search(r'^#include\s+"%s"' % re.escape(hdr), text, re.M):
        return text
    incs = list(re.finditer(r'^#include\s+"(?!gen/)[^"\n]+"[^\n]*\n', text, re.M))
    if not incs:
        incs = list(re.finditer(r'^#include[^\n]*\n', text, re.M))
    nl = '\r\n' if '\r\n' in text else '\n'
    if not incs:
        return '#include "%s"%s' % (hdr, nl) + text
    e = incs[-1].end()
    return text[:e] + '#include "%s"%s' % (hdr, nl) + text[e:]


# ---------------------------------------------------------------- main

def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--module', required=True)
    ap.add_argument('--header', help='export header in Source/Include (default <M>Api.h)')
    ap.add_argument('--inside', action='store_true', help="also take M's own units")
    ap.add_argument('--exclude', help='file of addresses, units, or "unit address" pairs to leave alone')
    ap.add_argument('--only', help='comma-separated addresses to take (default every one)')
    ap.add_argument('--min-units', type=int, default=1, help='take a symbol only when at least N units declare it')
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--units-out')
    ap.add_argument('--report')
    a = ap.parse_args()

    M = a.module
    hname = a.header or '%sApi.h' % M
    hpath = 'Source/Include/' + hname
    srcs = sources()
    hdrs = headers()
    types = Types(hdrs, srcs)

    ex_va, ex_unit, ex_pair = set(), set(), set()
    if a.exclude and os.path.exists(a.exclude):
        for l in open(a.exclude):
            l = l.split('#')[0].split()
            if len(l) == 1:
                (ex_va if l[0].lower().startswith('0x') else ex_unit).add(l[0].lower() if l[0].lower().startswith('0x') else l[0])
            elif len(l) >= 2:
                ex_pair.add((l[0], l[1].lower()))
    only = set(v.strip().lower() for v in a.only.split(',')) if a.only else None

    # definitions of M
    defs = collections.defaultdict(list)    # va -> [(file, name, decl, c, why, kind)]
    for f in srcs:
        if module_of(f) != M:
            continue
        for va, name, sig, c, why in function_defs(f):
            defs[va.lower()].append((f, name, sig, c, why, 'func'))
        for va, name, decl, c, why in data_defs(f):
            defs[va.lower()].append((f, name, decl, c, why, 'data'))

    # references: declaration lines ending in a defined address
    texts = {f: read(f) for f in srcs + hdrs}
    refs = collections.defaultdict(list)    # va -> [(file, line index, line)]
    pat = re.compile(r'//\s*(0x[0-9A-Fa-f]{8})\s*\r?$', re.M)
    for f in srcs + hdrs:
        if f.startswith('Source/Include/') or (module_of(f) == M and not a.inside and not f.lower().endswith('.h')):
            pass
        t = texts[f]
        for m in pat.finditer(t):
            va = m.group(1).lower()
            if va in defs:
                ls = t.rfind('\n', 0, m.start()) + 1
                line = t[ls:m.end()].rstrip('\r')
                code = line[:VA_TAIL.search(line).start()].rstrip()
                if code.endswith(';') and code and not code[0].isspace():
                    refs[va].append((f, line))

    shared_hdrs = [h for h in hdrs if h.startswith('Source/Include/')]
    plan = []           # (va, name, decl, header, [units], [header lines to fix], fwd, inc)
    report = []
    for va in sorted(defs, key=lambda v: int(v, 16)):
        if only is not None and va not in only:
            continue
        ds = defs[va]
        name = ds[0][1]
        users = []
        others = []
        hfix = []
        for f, line in refs[va]:
            if f in [d[0] for d in ds]:
                continue
            isunit = not f.lower().endswith('.h')
            if isunit and module_of(f) == M and not a.inside:
                continue
            if not isunit and module_of(f) == M and not f.startswith('Source/Include/'):
                continue
            code = line[:VA_TAIL.search(line).start()]
            dn, kind = declared_name(code)
            if kind == 'def':
                continue          # another definition (duplicate_data)
            if dn != name:
                others.append((f, dn))
                continue
            if isunit:
                if f in ex_unit or (f, va) in ex_pair:
                    continue
                users.append((f, line))
            else:
                hfix.append((f, line))
        if not users and not hfix:
            continue
        nunits = len({f for f, _ in users})
        if va in ex_va:
            report.append((va, name, nunits, 'excluded')); continue
        if len({d[0] for d in ds}) > 1:
            report.append((va, name, nunits, 'defined in %d files of %s (duplicate_data)' % (len({d[0] for d in ds}), M))); continue
        f, name, decl, c, why, kind = ds[0]
        if why:
            report.append((va, name, nunits, why)); continue
        if nunits < a.min_units and not hfix:
            report.append((va, name, nunits, 'fewer than %d units' % a.min_units)); continue
        fwd, inc, prob = needs(decl, name, types)
        if prob:
            report.append((va, name, nunits, prob)); continue
        text = ('extern "C" ' if c else '') + ('extern ' if kind == 'data' else '') + decl + ';'
        target = None
        for h, line in hfix:
            if h in shared_hdrs:
                target = h
                break
        plan.append((va, name, text, target or hpath, users, hfix, fwd, inc, others))
        report.append((va, name, nunits, 'to %s' % os.path.basename(target or hpath) + ('' if not others else '; named otherwise in %d' % len(others))))

    for va, name, n, what in report:
        print('%s %-48s %3d units  %s' % (va, name, n, what))
    took = [p for p in plan]
    print('%s: %d symbols declared by other units; %d to headers, %d left out; %d private copies replaced' %
          (M, len(report), len(took), len(report) - len(took), sum(len(p[4]) for p in took)))
    if a.report:
        with open(a.report, 'w') as fo:
            for va, name, n, what in report:
                fo.write('%s\t%s\t%d\t%s\n' % (va, name, n, what))

    if not a.apply:
        return

    changed = set()
    newtext = {}

    def cur(f):
        return newtext[f] if f in newtext else texts.get(f) if f in texts else (read(f) if os.path.exists(os.path.join(ROOT, f)) else None)

    # header lines that already declare an address: correct them
    for va, name, text, target, users, hfix, fwd, inc, _ in took:
        for h, line in hfix:
            t = cur(h)
            new = text + ' // ' + va_fmt(va)
            if line.strip() != new.strip():
                t = t.replace(line, new, 1)
                newtext[h] = t
                changed.add(h)

    # new declarations for the export header (those whose target header does not have them yet)
    add = collections.defaultdict(list)
    for va, name, text, target, users, hfix, fwd, inc, _ in took:
        if target in [h for h, _ in hfix]:
            continue
        add[target].append((va, text, fwd, inc))
    for target, rows in add.items():
        t = cur(target)
        nl = '\r\n' if t and '\r\n' in t else '\n'
        known_fwd = set(re.findall(r'^\s*(?:struct|union|class)\s+(\w+)\s*;', t or '', re.M))
        known_def = set(re.findall(r'^\s*(?:typedef\s+)?(?:struct|union|class)\s+(\w+)\s*\{', t or '', re.M))
        incs = sorted({i for _, _, _, ii in rows for i in ii if i != os.path.basename(target)} -
                      set(re.findall(r'^#include\s+"([^"]+)"', t or '', re.M)))
        fwds = sorted({fw for _, _, ff, _ in rows for fw in ff if fw[1] not in known_fwd and fw[1] not in known_def}, key=lambda x: x[1])
        body = ''.join('%s // %s%s' % (text, va_fmt(va), nl) for va, text, _, _ in sorted(rows, key=lambda r: int(r[0], 16)))
        block = ''.join('#include "%s"%s' % (i, nl) for i in incs) + ''.join('%s %s;%s' % (k, w, nl) for k, w in fwds)
        if t is None:
            t = ('#pragma once%s// %s\'s exports that the other modules call; included only by the units that use it.%s%s'
                 % (nl, M, nl, nl)) + block + (nl if block else '') + body
        else:
            if not t.endswith(nl):
                t += nl
            t += nl + block + body
        newtext[target] = t
        changed.add(target)

    # private copies go; the unit includes the header
    for va, name, text, target, users, hfix, fwd, inc, _ in took:
        hb = os.path.basename(target)
        for u, line in users:
            t = cur(u)
            nl = '\r\n' if line + '\r\n' in t else '\n'
            i = t.find(line + nl)
            if i < 0:
                t = t.replace(line, '', 1)
            else:
                t = t[:i] + t[i + len(line + nl):]
                # a copy that stood between blank lines leaves one blank line, not two
                if t[:i].endswith(nl + nl) and t.startswith(nl, i):
                    t = t[:i] + t[i + len(nl):]
            t = add_include(t, hb)
            newtext[u] = t
            changed.add(u)

    for f in sorted(changed):
        write(f, newtext[f])
    print('wrote %d files' % len(changed))

    if a.units_out:
        hb = {os.path.basename(h) for h in changed if h.lower().endswith('.h')}
        units = {f for f in changed if not f.lower().endswith('.h')}
        if hb:
            inc_re = re.compile(r'^#include\s+"([^"]+)"', re.M)
            # units that include a changed header, directly or through another header
            hdr_inc = {os.path.basename(h): set(inc_re.findall(read(h))) for h in hdrs + [h for h in changed if h.endswith('.h')]}
            closed = set(hb)
            grew = True
            while grew:
                grew = False
                for h, ii in hdr_inc.items():
                    if h not in closed and ii & closed:
                        closed.add(h); grew = True
            for f in srcs:
                if set(inc_re.findall(read(f))) & closed:
                    units.add(f)
        with open(a.units_out, 'w') as fo:
            fo.write(','.join(sorted(units)) + '\n')
        print('%d units to rebuild: %s' % (len(units), a.units_out))


def va_fmt(va):
    return '0x' + va[2:].upper()


if __name__ == '__main__':
    main()
