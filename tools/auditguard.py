#!/usr/bin/env python3
"""auditguard.py [BASE] : compare the working tree's Source/ with BASE (default origin/main) and fail if any audit
count rises: forcing constructs (volatile, #pragma optimize, bare __assume), identical if/else arms,
__declspec(noinline), emit helpers, names carrying a 1.10 DLL address, decompiler types and labels, Hex-Rays
parameter names, address-named T<VA> structs, raw offset access (`*(T*)((char*)p + N)`), byte pointer math (`(char*)p + N`) and C-style pointer casts. Counts are whole-tree totals, so code moved between files nets out.
Prints each category's before -> after and, for a rise, the files whose count rose (git log those to find the
branch). Exit 1 on any rise. AUDIT_ALLOW=cat1,cat2 lets named categories rise (a board ruling)."""
import os, re, sys, subprocess, collections
ROOT = os.environ.get('IBLIS_ROOT', '/home/claude/iblis-codex'); os.chdir(ROOT)
BASE = sys.argv[1] if len(sys.argv) > 1 else 'origin/main'
sys.path.insert(0, ROOT + '/tools')
CATS = {
 'volatile': r'\bvolatile\b',
 'pragma optimize': r'#pragma\s+optimize',
 'bare __assume': r'(?<!define )\b__assume\s*\(',
 'noinline': r'__declspec\s*\(\s*noinline\s*\)',
 'emit helpers': r'\b\w*_Emit\w*\s*\(',
 '1.10 address in a name': r'\b\w+_6F[0-9A-F]{6}\b',
 'decompiler types': r'\b(?:U8|U16|U32|S32|_BYTE|_WORD|_DWORD|_QWORD|__int8|__int16|__int32|LOBYTE|HIBYTE|LOWORD|HIWORD)\b',
 'decompiler labels': r'\b(?:LABEL_\w+|loc_[0-9A-Fa-f]+)\b',
 'a1/v12 names': r'\b(?:v\d{1,3}|a\d{1,2})\b',
 'T<VA> structs': r'\bT[0-9A-Fa-f]{8}\b',
 'nullptr': r'\bnullptr\b',
 'raw offset access': r'\*\s*\(\s*[\w\s]+\*+\s*\)\s*\(\s*\(\s*(?:const\s+)?(?:unsigned\s+)?char\s*\*\s*\)',
 'byte pointer math': r'\(\s*(?:const\s+)?(?:unsigned\s+)?char\s*\*\s*\)\s*\w+(?:->\w+)*\s*\+\s*(?:0x[0-9A-Fa-f]+|\d+)',
 'pointer casts': r'\(\s*(?:const\s+)?(?:unsigned\s+)?\w+\s*\*+\s*\)',
}
def _block_end(t, i):
    d = 0
    for j in range(i, len(t)):
        if t[j] == '{': d += 1
        elif t[j] == '}':
            d -= 1
            if d == 0: return j + 1
def _norm(x): return re.sub(r'\s+', ' ', re.sub(r'//[^\n]*', '', x)).strip()
def arms(t):
    n = 0
    for m in re.finditer(r'\bif\s*\(', t):
        k, dep = m.end(), 1
        while k < len(t) and dep:
            dep += {'(': 1, ')': -1}.get(t[k], 0); k += 1
        rest = t[k:k + 6000].lstrip(); off = k + (len(t[k:k + 6000]) - len(rest))
        if rest.startswith('{'):
            e = _block_end(t, off)
            if not e: continue
            a1, after = t[off + 1:e - 1], t[e:e + 6000].lstrip()
            if not after.startswith('else'): continue
            r2 = after[4:].lstrip()
            if r2.startswith('{'):
                q = t.index(r2[:40], e) if r2[:40] in t[e:] else None
                e2 = _block_end(t, q) if q is not None else None
                a2 = t[q + 1:e2 - 1] if e2 else ''
            else: a2 = r2[:r2.find(';') + 1]
        else:
            sc = rest.find(';'); a1 = rest[:sc + 1]; after = rest[sc + 1:].lstrip()
            if not after.startswith('else') or after[4:].lstrip().startswith(('if', '{')): continue
            r2 = after[4:].lstrip(); a2 = r2[:r2.find(';') + 1]
        if _norm(a1) and _norm(a1) == _norm(a2): n += 1
    return n
def strip_comments(t): return re.sub(r'//[^\n]*', '', t)
def count_tree(files):
    tot = collections.Counter(); per = collections.defaultdict(collections.Counter)
    for f, t in files:
        if not f.startswith('Source/') or not f.endswith(('.cpp', '.c', '.h')): continue
        c = strip_comments(t)
        for k, p in CATS.items():
            n = len(re.findall(p, c))
            if n: tot[k] += n; per[k][f] = n
        n = arms(t)
        if n: tot['identical if/else arms'] += n; per['identical if/else arms'][f] = n
    return tot, per
def base_files():
    ls = subprocess.run(['git', 'ls-tree', '-r', '--name-only', BASE, '--', 'Source'], capture_output=True, text=True).stdout.split()
    ls = [f for f in ls if f.endswith(('.cpp', '.c', '.h'))]
    p = subprocess.Popen(['git', 'cat-file', '--batch'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    out = []
    for f in ls:
        p.stdin.write(('%s:%s\n' % (BASE, f)).encode()); p.stdin.flush()
        h = p.stdout.readline().split(); n = int(h[2]); out.append((f, p.stdout.read(n).decode('latin-1'))); p.stdout.read(1)
    p.stdin.close(); return out
def work_files():
    out = []
    for d, _, fs in os.walk('Source'):
        for f in fs:
            if f.endswith(('.cpp', '.c', '.h')):
                p = os.path.join(d, f); out.append((p, open(p, encoding='latin-1').read()))
    return out
allow = set(x.strip() for x in os.environ.get('AUDIT_ALLOW', '').split(',') if x.strip())
bt, bp = count_tree(base_files()); wt, wp = count_tree(work_files())
bad = []
for k in list(CATS) + ['identical if/else arms']:
    a, b = bt[k], wt[k]; flag = ''
    if b > a and k not in allow:
        bad.append(k); flag = '  RISES'
    print('audit %-24s %6d -> %-6d%s' % (k, a, b, flag))
    if b > a:
        rose = sorted(((wp[k][f] - bp[k].get(f, 0), f) for f in wp[k] if wp[k][f] > bp[k].get(f, 0)), reverse=True)[:8]
        for n, f in rose: print('    +%d %s' % (n, f))
if bad: print('AUDIT GUARD FAILED: %s rose (AUDIT_ALLOW=<category> only for a board ruling)' % ', '.join(bad)); sys.exit(1)
print('audit guard: no count rose')
