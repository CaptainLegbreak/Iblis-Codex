#!/usr/bin/env python3
"""mutsearch.py <root> <va> <unit> <start.cpp> <outdir> [minutes]
Greedy hill-climb over small source mutations inside the function marked // 0x<VA>.
Mutations: commute ==/!=/+/* operands, flip relational operators, ++x/x++/x+=1 forms, swap adjacent
simple statements, swap the order of two adjacent declarations, add/remove `const` on a local,
int<->unsigned on a local, `if (!x)` <-> `if (x == 0)`. Score = unmasked bytes + 20*|length diff|
(+100000 for compile errors or other functions of the unit becoming unequal). Keeps <outdir>/best.cpp."""
import sys, os, re, json, random, subprocess, time
root, va, unit, start, out = sys.argv[1:6]
mins = float(sys.argv[6]) if len(sys.argv) > 6 else 240
os.makedirs(out, exist_ok=True)
deadline = time.time() + 60 * mins
src = open(start, encoding='latin-1').read()
mark = '// 0x%08X\n' % int(va, 16)
def body_span(t):
    a = t.index('\n' + mark) + 1; b = t.index('\n}\n', a) + 3; return a, b
seen = {}
logf = open(out + '/log.jsonl', 'a')
def score(t):
    h = hash(t)
    if h in seen: return seen[h]
    open(os.path.join(root, unit), 'w', encoding='latin-1').write(t)
    r = subprocess.run(['nice', '-n', '10', 'python3', '/home/claude/work/evalfn.py', root, va, unit], capture_output=True, text=True).stdout.strip().splitlines()
    try: j = json.loads(r[-1])
    except Exception: j = {'status': 'NO_OUTPUT'}
    if j.get('status') in ('RAW_EQUAL', 'RELOCATION_RESOLVED_EQUAL'): s = -1 if not j.get('others') else 100000
    elif j.get('ours') is None: s = 10 ** 6
    else: s = (j.get('unmasked') or 0) + 20 * abs(j['ours'] - j['orig']) + 100000 * len(j.get('others', []))
    seen[h] = s
    logf.write(json.dumps({'s': s, 'r': j, 't': time.strftime('%H:%M:%S')}) + '\n'); logf.flush()
    return s
ID = r'[A-Za-z_][\w]*(?:(?:->|\.)[A-Za-z_]\w*|\[[^\]\[]+\])*'
def mutations(t):
    a, b = body_span(t); f = t[a:b]; L = f.split('\n'); M = []
    for i, l in enumerate(L):
        if i < 2: continue
        s = l.strip()
        if s.startswith('//') or not s: continue
        for op in ('==', '!='):
            for m in re.finditer(r'(%s) %s (%s)' % (ID, re.escape(op), ID), l):
                M.append((i, l[:m.start()] + '%s %s %s' % (m.group(2), op, m.group(1)) + l[m.end():]))
        for m in re.finditer(r'(%s) \+ (%s)' % (ID, ID), l):
            M.append((i, l[:m.start()] + '%s + %s' % (m.group(2), m.group(1)) + l[m.end():]))
        for m in re.finditer(r'(%s) \* (%s)' % (ID, ID), l):
            M.append((i, l[:m.start()] + '%s * %s' % (m.group(2), m.group(1)) + l[m.end():]))
        flip = {'<': '>', '>': '<', '<=': '>=', '>=': '<='}
        for m in re.finditer(r'(%s) (<=|>=|<|>) (%s)' % (ID, ID), l):
            M.append((i, l[:m.start()] + '%s %s %s' % (m.group(3), flip[m.group(2)], m.group(1)) + l[m.end():]))
        m = re.match(r'^(\s*)\+\+(%s);$' % ID, l)
        if m: M += [(i, '%s%s++;' % (m.group(1), m.group(2))), (i, '%s%s += 1;' % (m.group(1), m.group(2)))]
        m = re.match(r'^(\s*)(%s)\+\+;$' % ID, l)
        if m: M += [(i, '%s++%s;' % (m.group(1), m.group(2))), (i, '%s%s += 1;' % (m.group(1), m.group(2)))]
        m = re.match(r'^(\s*)(%s) \+= 1;$' % ID, l)
        if m: M += [(i, '%s++%s;' % (m.group(1), m.group(2)))]
        m = re.match(r'^(\s*)if \(!(%s)\)$' % ID, l)
        if m: M.append((i, '%sif (%s == 0)' % (m.group(1), m.group(2))))
        m = re.match(r'^(\s*)if \((%s) == 0\)$' % ID, l)
        if m: M.append((i, '%sif (!%s)' % (m.group(1), m.group(2))))
        m = re.match(r'^(\s*)const (int|unsigned int|unsigned short|short) (\w+ = .*;)$', l)
        if m: M.append((i, '%s%s %s' % (m.group(1), m.group(2), m.group(3))))
        m = re.match(r'^(\s*)(int|unsigned int) (\w+)( = .*)?;$', l)
        if m:
            o = 'unsigned int' if m.group(2) == 'int' else 'int'
            M.append((i, '%s%s %s%s;' % (m.group(1), o, m.group(3), m.group(4) or '')))
            if m.group(4): M.append((i, '%sconst %s %s%s;' % (m.group(1), m.group(2), m.group(3), m.group(4))))
        TYPES = ['int', 'unsigned int', 'short', 'unsigned short', 'char', 'unsigned char', 'BOOL']
        m = re.match(r'^(\s*)(const )?(int|unsigned int|short|unsigned short|char|unsigned char|BOOL) (\w+)( = [^;]*)?;$', l)
        if m:
            for ty in TYPES:
                if ty != m.group(3): M.append((i, '%s%s%s %s%s;' % (m.group(1), m.group(2) or '', ty, m.group(4), m.group(5) or '')))
        for m in re.finditer(r'\((%s) (&&|\|\|) (%s)\)' % (r'[^()&|]+', r'[^()&|]+'), l):
            M.append((i, l[:m.start()] + '(%s %s %s)' % (m.group(3), m.group(2), m.group(1)) + l[m.end():]))
        for m in re.finditer(r'(%s) (==|!=|<|>|<=|>=) (%s)' % (ID, ID), l):
            for c in ('(int)', '(unsigned int)', '(short)', '(unsigned short)', '(unsigned char)'):
                M.append((i, l[:m.start()] + '%s%s %s %s' % (c, m.group(1), m.group(2), m.group(3)) + l[m.end():]))
                M.append((i, l[:m.start()] + '%s %s %s%s' % (m.group(1), m.group(2), c, m.group(3)) + l[m.end():]))
        m = re.match(r'^(\s*)(%s) \+= (.+);$' % ID, l)
        if m: M.append((i, '%s%s = %s + %s;' % (m.group(1), m.group(2), m.group(2), m.group(3))))
    # adjacent simple statements swap
    simple = re.compile(r'^\s+[^{}/]*;$')
    for i in range(2, len(L) - 1):
        if simple.match(L[i]) and simple.match(L[i + 1]) and len(L[i]) - len(L[i].lstrip()) == len(L[i + 1]) - len(L[i + 1].lstrip()) \
           and not L[i].strip().startswith(('return', 'break', 'continue', 'goto')) and not L[i + 1].strip().startswith(('return', 'break', 'continue', 'goto')):
            if independent(L[i], L[i + 1]): M.append((i, ('SWAP',)))
    return a, b, L, M
def ids(s): return set(re.findall(r'[A-Za-z_]\w*', s))
def lhs(s):
    s = s.strip().rstrip(';')
    m = re.match(r'^(?:\+\+|--)?(.+?)(?:\+\+|--)?$', s) if not re.search(r'[^=!<>]=[^=]', s) else None
    if m and ('++' in s or '--' in s): return ids(m.group(1))
    m = re.match(r'^(?:[\w:<>\*\s]+\s)?([^=]+?)\s*(?:[-+*/|&^]?=)(?!=)', s)
    return ids(m.group(1)) if m else ids(s)
def independent(x, y):
    if '(' in x and '(' in y and re.search(r'\w\(', x) and re.search(r'\w\(', y): return False
    return not (lhs(x) & ids(y)) and not (lhs(y) & ids(x))
def apply(t, a, b, L, mut):
    L2 = L[:]
    i, new = mut
    if new == ('SWAP',): L2[i], L2[i + 1] = L2[i + 1], L2[i]
    else: L2[i] = new
    return t[:a] + '\n'.join(L2) + t[b:]
visited = set(); cur = src; cs = score(cur); print('start', cs, flush=True)
best = (cs, cur); open(out + '/best.cpp', 'w', encoding='latin-1').write(cur)
try:
    while time.time() < deadline:
        a, b, L, M = mutations(cur); random.shuffle(M); improved = False
        print('pass: %d mutations' % len(M), flush=True)
        for mut in M:
            if time.time() > deadline: break
            t2 = apply(cur, a, b, L, mut); s = score(t2)
            if s < cs or (s == cs and random.random() < 0.15 and hash(t2) not in visited):
                visited.add(hash(t2))
                cur, cs, improved = t2, s, True
                if cs < best[0]:
                    best = (cs, cur); open(out + '/best.cpp', 'w', encoding='latin-1').write(cur)
                print('improved', cs, 'best', best[0], mut[0], flush=True)
                if cs < 0: raise SystemExit
                break
        if not improved:
            print('local optimum', cs, flush=True)
            # kick: apply two random mutations and continue from there if it compiles
            a, b, L, M = mutations(cur); random.shuffle(M)
            if len(M) < 2: break
            t2 = apply(cur, a, b, L, M[0]); a2, b2, L2, M2 = mutations(t2); random.shuffle(M2)
            t3 = apply(t2, a2, b2, L2, M2[0]) if M2 else t2
            s3 = score(t3)
            if s3 < 10 ** 5: cur, cs = t3, s3; print('kick to', cs, flush=True)
finally:
    open(os.path.join(root, unit), 'w', encoding='latin-1').write(src)
    print('DONE', cs, flush=True)
