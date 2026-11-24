#!/usr/bin/env python3
"""join.py ROOT PLACEHOLDER_REL OWNER_REL: move every function of a placeholder unit into its owner unit, in address
order, and check the owner unit still builds equal. Edits the checkout at ROOT (a worktree) only if it does.

- The placeholder's declarations (everything before its first function, minus #include lines) go after the owner's
  own declarations; ones the compiler reports as redefined are dropped, one round at a time.
- Each marked function goes in front of the owner's first function with a higher address.
- An unmarked definition the owner already has (a context copy, a shared static) is dropped.
- units.json: the placeholder's functions join the owner's unit; the placeholder's unit and file go.
Prints JOINED or FAILED <reason>."""
import sys, os, re, json, subprocess, tempfile, shutil
ROOT, P, F = sys.argv[1:4]
sys.path.insert(0, ROOT + '/tools'); os.chdir(ROOT)
import checker
from common import settings, compile_env, unit_env, cl_command, expand_gen_includes, PE, default_flags, load_json

S = settings(); ENV = compile_env(S); pe = PE(S['image'])
L = {int(r[0], 16): int(r[1]) for r in load_json('functions.json')['functions']}
UJ = json.load(open('build/units.json'))
U = {u['file']: u for u in UJ['units']}
if P not in U or F not in U: print('FAILED unit missing'); sys.exit(1)
if U[P].get('ltcg') or U[F].get('ltcg'): print('FAILED ltcg unit'); sys.exit(1)
fp = list(U[P].get('flags') or default_flags(P)); ff = list(U[F].get('flags') or default_flags(F))
FLAGSETS = [ff] if fp == ff else [ff, fp]
DP_PATH = 'build/data_plan.json'
DP_TEXT = open(DP_PATH).read(); DP = json.loads(DP_TEXT)
P_DATA = DP.get('files', {}).get(P)
P_INC = P_DATA.get('include') if P_DATA else None
F_DATA = DP.get('files', {}).get(F)


def render_gen():
    import gendata
    gendata.render_all(S['image'])


def plan_with_data():
    """The placeholder's planned data moves to the owner: its definitions, and its files entry merged into the owner's."""
    d = json.loads(DP_TEXT)
    for x in d['definitions']:
        if x.get('file') == P: x['file'] = F
    pe_ = d['files'].pop(P)
    if F in d['files']:
        fe = d['files'][F]
        fe['bytes'] += pe_['bytes']; fe['definitions'] += pe_['definitions']
        fe['externs'] = fe['externs'] + [e for e in pe_['externs'] if e not in fe['externs']]
        fe.setdefault('fn_types', {}).update(pe_.get('fn_types', {}))
    else:
        fe = dict(pe_); fe['include'] = 'gen/data/' + os.path.splitext(F)[0] + '.inc'
        d['files'][F] = fe
    return d, fe['include']
EQ = ('RAW_EQUAL', 'RELOCATION_RESOLVED_EQUAL')
pt = open(P, encoding='latin-1').read(); ft = open(F, encoding='latin-1').read()
nl = '\r\n' if '\r\n' in ft else '\n'
pt = pt.replace('\r\n', '\n'); ft_n = ft.replace('\r\n', '\n')

FUNC_START = re.compile(r'(?m)^(?:// 0x[0-9A-Fa-f]{8}\n)?(?:// build: [^\n]*\n)*[^\s#/][^;{}()\n]*\b([A-Za-z_]\w*)\s*\([^;{}]*\)\s*(?:const\s*)?\n?\{')


def top_level_functions(t):
    """(start, end, name, va or None) for each top-level function definition."""
    out = []; i = 0
    for m in FUNC_START.finditer(t):
        if m.start() < i: continue
        # top level only: brace depth 0 at the match
        if t[:m.start()].count('{') != t[:m.start()].count('}'): continue
        b = t.index('{', m.end() - 1); d = 0; e = b
        while e < len(t):
            if t[e] == '{': d += 1
            elif t[e] == '}':
                d -= 1
                if d == 0: break
            e += 1
        head = t[m.start():b]
        mv = re.match(r'// 0x([0-9A-Fa-f]{8})\n', head)
        # take a preceding marker line if the regex started below it
        s0 = m.start()
        pm = re.search(r'(?:^|\n)(// 0x([0-9A-Fa-f]{8})\n(?:// build: [^\n]*\n)*)$', t[:s0])
        if not mv and pm:
            s0 = pm.start(1); mv = re.match(r'// 0x([0-9A-Fa-f]{8})\n', pm.group(1))
        out.append((s0, e + 1, m.group(1), int(mv.group(1), 16) if mv else None))
        i = e + 1
    return out


pf = top_level_functions(pt)
if not pf: print('FAILED no functions found in placeholder'); sys.exit(1)
pre = pt[:pf[0][0]]
p_includes = [l.strip() for l in pre.split('\n') if l.startswith('#include') and 'gen/data/' not in l]
P_INC_LINE = '#include "%s"' % P_INC if P_INC else None
f_includes = {l.strip() for l in ft_n.split('\n') if l.startswith('#include')}
NEW_INCLUDES = [l for l in p_includes if l not in f_includes]
pre = '\n'.join(l for l in pre.split('\n') if not l.startswith('#include') or ('gen/data/' in l and l.strip() != P_INC_LINE)) + '\n'
# anything between the placeholder's functions that isn't a function (declarations, statics, data) rides with pre
mid = ''
for (a, b, _, _), (c, _, _, _) in zip(pf, pf[1:]):
    seg = pt[b:c]
    if seg.strip(): mid += seg.strip('\n') + '\n'
tail = pt[pf[-1][1]:]
mid = '\n'.join(l for l in mid.split('\n') if l.strip() != P_INC_LINE); tail = '\n'.join(l for l in tail.split('\n') if l.strip() != P_INC_LINE)
if re.search(r'(?m)^#include (?!"gen/data/)', mid + tail): print('FAILED include after code'); sys.exit(1)
pre = pre + mid + tail.strip('\n') + '\n'
fdefs = {n for _, _, n, v in top_level_functions(ft_n)}
owned = {int(f['va'], 16) for f in U[P]['functions']}
moves = [(va, pt[a:b]) for a, b, n, va in pf if va in owned]
# everything else in the placeholder is a copy kept for inlining: drop it when the owner has that function
drops = [n for a, b, n, va in pf if va not in owned and n in fdefs]
keeps = [(n, pt[a:b]) for a, b, n, va in pf if va not in owned and n not in fdefs]
missing = owned - {va for va, _ in moves}
if missing: print('FAILED owned functions without a body found: %s' % ', '.join('0x%08X' % v for v in sorted(missing))); sys.exit(1)
if not moves: print('FAILED no marked functions'); sys.exit(1)


def strip_owner_copies(t):
    # the owner's unmarked copies of functions that now move in (context copies) go, with their directive lines
    names = {re.search(r'([A-Za-z_]\w*)\s*\(', body[:body.index('{')]).group(1) for _, body in moves}
    for a, b, n, va in sorted(top_level_functions(t), reverse=True):
        if va is None and n in names:
            pre_ = t[:a]
            m = re.search(r'(?:\n// build: context [^\n]*)+\n?$', pre_)
            body_ = t[a:b]; hdr_ = body_[:body_.index('{')].rstrip()
            hdr_ = '\n'.join(l for l in hdr_.split('\n') if not l.startswith('//'))
            if m: a = m.start() + 1
            # keep a prototype where the copy was, for callers above the moved definition
            t = t[:a] + hdr_ + ';\n' + t[b:].lstrip('\n')
    t = re.sub(r'(?m)^// build: context (?:\?)?(%s)\b[^\n]*\n' % '|'.join(map(re.escape, names)), '', t) if names else t
    return t


def add_includes(t):
    # headers the placeholder used that the owner doesn't: after the owner's last #include line before its code
    if not USE_INCLUDES[0] or not NEW_INCLUDES: return t
    first = top_level_functions(t)[0][0]
    lines = t[:first].split('\n')
    idx = max((i for i, l in enumerate(lines) if l.startswith('#include') and 'gen/data/' not in l), default=-1)
    lines[idx + 1:idx + 1] = NEW_INCLUDES
    return '\n'.join(lines) + t[first:]


USE_INCLUDES = [False]


def build_text(pre_text):
    t = add_includes(strip_owner_copies(ft_n))
    ff_ = top_level_functions(t)
    # declarations and the placeholder's helper bodies go in front of the owner's first function
    ins = ff_[0][0]
    t = t[:ins] + '// --- from %s\n' % os.path.basename(P) + pre_text + ''.join(k + '\n\n' for _, k in keeps) + t[ins:]
    for va, body in sorted(moves):
        cur = top_level_functions(t)
        nxt = [a for a, b, n, v in cur if v is not None and v > va]
        pos = nxt[0] if nxt else len(t.rstrip('\n')) + 1
        if not nxt and not t.endswith('\n'): t += '\n'
        t = t[:pos] + body + '\n\n' + t[pos:]
    return t


def compile_text(text):
    wd = tempfile.mkdtemp(prefix='join_', dir='/tmp')
    try:
        open(os.path.join(wd, 'unit.cpp'), 'w', encoding='latin-1', newline='').write(text.replace('\n', nl))
        r = subprocess.run(cl_command(S, CUR_FLAGS[0], 'unit.obj', 'unit.cpp'), capture_output=True, text=True, env=unit_env(S, ENV, F), cwd=wd)
        p = os.path.join(wd, 'unit.obj')
        return (open(p, 'rb').read() if r.returncode == 0 and os.path.exists(p) else None), r.stdout + r.stderr
    finally:
        shutil.rmtree(wd, ignore_errors=True)


def tidy_pre(lines):
    """Drop what the owner already declares, what nothing uses, and empty pack pairs."""
    owner = strip_owner_copies(ft_n)
    body_all = owner + '\n'.join(b for _, b in moves) + '\n'.join(k for _, k in keeps)
    # macros and other declarations in the placeholder's own preamble count as uses too
    body_all += '\n' + '\n'.join(x for x in lines if x.startswith('#define'))
    norm = lambda x: re.sub(r'\s+', ' ', re.sub(r'//.*$', '', x)).strip()
    owner_lines = {norm(x) for x in owner.split('\n')}
    out = []; i = 0
    while i < len(lines):
        l = lines[i]; n = norm(l)
        # keep multi-line blocks (struct bodies etc.) whole
        if re.match(r'^(struct|union|enum|class)\b', l) and not l.rstrip().endswith(';'):
            j = i
            while j < len(lines) and not re.match(r'^\};', lines[j]): j += 1
            blk = lines[i:j + 1]; name = re.match(r'^(?:struct|union|enum|class)\s+(\w+)', l)
            if not (name and re.search(r'\b(struct|union|enum|class)\s+%s\s*\n?\{' % name.group(1), owner)):
                out += blk
            i = j + 1; continue
        if n and n in owner_lines:
            i += 1; continue
        if l.startswith('// build:') and l.strip() in {x.strip() for x in owner.split('\n')}:
            i += 1; continue
        n_ = re.sub(r'__declspec\([^)]*\)', '', n)
        m = re.search(r'\b([A-Za-z_]\w*)\s*\(', n_) if n.endswith(';') and '(' in n_ and not n.startswith(('typedef', '#')) else None
        if m and not n.startswith('typedef'):
            nm = m.group(1)
            if re.search(r'(?m)^[^\s/#][^/\n;{}]*\b%s\s*\([^;{]*\)\s*(;|\n?\{)' % nm, owner):
                i += 1; continue
            if len(re.findall(r'\b%s\b' % nm, body_all)) == 0:
                i += 1; continue
        m2 = re.match(r'^extern\b.*?\b([A-Za-z_]\w*)\s*(\[[^\]]*\])?\s*;', n)
        if m2 and not m:
            nm = m2.group(1)
            if re.search(r'(?m)^[^/\n]*\b%s\b\s*(\[[^\]]*\])?\s*(=|;)' % nm, owner) or not re.search(r'\b%s\b' % nm, body_all):
                i += 1; continue
        m3 = re.match(r'^struct (\w+);$', n)
        if m3 and re.search(r'\bstruct %s\b' % m3.group(1), owner):
            i += 1; continue
        m4 = re.match(r'^#define (\w+)', n)
        if m4 and re.search(r'(?m)^#define %s\b' % m4.group(1), owner):
            i += 1; continue
        out.append(l); i += 1
    t = '\n'.join(out)
    t = re.sub(r'#pragma pack\(push, ?\d\)\s*\n\s*#pragma pack\(pop\)\n?', '', t)
    t = re.sub(r'\n{3,}', '\n\n', t).strip('\n') + '\n\n'
    return t.split('\n')


NEW_PLAN = None
if P_DATA:
    NEW_PLAN, F_INC = plan_with_data()
    open(DP_PATH, 'w').write(json.dumps(NEW_PLAN, indent=1) + '\n')
    render_gen()
    if not F_DATA:
        # the owner had no planned data: its include goes where the placeholder's first moved function lands
        moves[0] = (moves[0][0], '#include "%s"\n' % F_INC + moves[0][1])


def restore_plan():
    if P_DATA:
        open(DP_PATH, 'w').write(DP_TEXT); render_gen()


import atexit
atexit.register(lambda: None)
_exit = sys.exit
def _fail_exit(c=0):
    if c: restore_plan()
    _exit(c)
sys.exit = _fail_exit
CUR_FLAGS = [ff]
pre_lines = tidy_pre(pre.split('\n'))
for rnd in range(12):
    text = build_text('\n'.join(pre_lines))
    ob, log = compile_text(text)
    if ob is not None: break
    errs = re.findall(r'unit\.cpp\((\d+)\) : error (C\d+): (.*)', log)
    if not errs: print('FAILED compile: ' + log[-400:].replace('\n', ' | ')); sys.exit(1)
    if not USE_INCLUDES[0] and NEW_INCLUDES and any(c in ('C3861', 'C2065', 'C2027', 'C2146', 'C2144', 'C2079', 'C2061', 'C2143', 'C4430') for _, c, _ in errs):
        USE_INCLUDES[0] = True; continue
    # map error lines back into the inserted declarations and drop those items
    tl = text.split('\n'); start = tl.index('// --- from %s' % os.path.basename(P)) + 1
    bad = set()
    for ln, code, msg in errs:
        ln = int(ln) - 1
        if start <= ln < start + len(pre_lines) and code in ('C2011', 'C2371', 'C2084', 'C2373', 'C2365', 'C2086', 'C2374', 'C2370', 'C2556', 'C2040', 'C2732', 'C2375', 'C2377', 'C2378', 'C2059', 'C2143', 'C2447'):
            bad.add(ln - start)
    if not bad: print('FAILED compile: ' + '; '.join('%s %s' % (c, m) for _, c, m in errs[:3])); sys.exit(1)
    # drop whole items: for a struct/union/enum, its block; else the line
    nb = set()
    for i in bad:
        j = i
        while j > 0 and not re.match(r'^(struct|union|enum|typedef|#pragma pack|class)\b', pre_lines[j]) and pre_lines[j].strip() and not pre_lines[j].startswith('}'):
            if pre_lines[j].rstrip().endswith(';') and j != i: break
            j -= 1
        if re.match(r'^(struct|union|enum|class)\b', pre_lines[j]) and not pre_lines[j].rstrip().endswith(';'):
            k = j
            while k < len(pre_lines) and not re.match(r'^\};', pre_lines[k]): k += 1
            nb.update(range(j, k + 1))
        else:
            nb.add(i)
    pre_lines = [l for i, l in enumerate(pre_lines) if i not in nb]
else:
    print('FAILED compile after 12 rounds'); sys.exit(1)

# check: every function of the joined unit builds equal
funcs = sorted(U[F]['functions'] + U[P]['functions'], key=lambda f: int(f['va'], 16))
src = expand_gen_includes(text, F)
bad = []
for f in funcs:
    rr = checker.compare(ob, src, int(f['va'], 16), f['length'], pe.read, L.get)
    st = rr.get('status')
    ok = (st in EQ or (rr.get('compiled_length') == f['length'] and rr.get('unmasked_diff_bytes') == 0)) and not rr.get('target_problems')
    if not ok: bad.append('%s:%s' % (f['va'], st))
def check(ob):
    out = []
    for f in funcs:
        rr = checker.compare(ob, src, int(f['va'], 16), f['length'], pe.read, L.get)
        st = rr.get('status')
        ok = (st in EQ or (rr.get('compiled_length') == f['length'] and rr.get('unmasked_diff_bytes') == 0)) and not rr.get('target_problems')
        if not ok: out.append('%s:%s' % (f['va'], st))
    return out
used = ff
if bad and len(FLAGSETS) > 1:
    CUR_FLAGS[0] = fp
    ob2, log2 = compile_text(text)
    if ob2 is not None:
        bad2 = check(ob2)
        if not bad2: bad, used = [], fp
if bad: print('FAILED not equal: ' + ', '.join(bad[:6]) + (' (also tried the placeholder\'s flags)' if len(FLAGSETS) > 1 else '')); sys.exit(1)

# write
text = text.replace('// --- from %s\n' % os.path.basename(P), '')
text = re.sub(r'\n{3,}', '\n\n', text)
open(F, 'w', encoding='latin-1', newline='').write(text.replace('\n', nl))
os.remove(P)
U[F]['functions'] = funcs
if used != ff:
    if used == list(default_flags(F)): U[F].pop('flags', None)
    else: U[F]['flags'] = used
UJ['units'] = [u for u in UJ['units'] if u['file'] != P]
open('build/units.json', 'w').write(json.dumps(UJ, indent=1) + '\n')
print(('JOINED (with the placeholder\'s flags) ' if used != ff else 'JOINED ') + '%d functions, %d copies dropped, %d declarations kept' % (len(moves), len(drops), len([l for l in pre_lines if l.strip()])))
