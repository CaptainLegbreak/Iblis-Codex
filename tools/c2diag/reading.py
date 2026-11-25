#!/usr/bin/env python3
"""reading.py <va> <unit> <block-file> <outdir> : put a candidate function (block from its `// 0x<VA>` line to its
closing brace) into <unit> in the /home/claude/vsw worktree (replacing an unmarked definition of the same function,
else inserted before the first marker with a higher address), score it with evalfn.py (length, differing bytes, other
functions of the unit still equal?), and take the allocator reading of our compile with c2prio. Restores the unit."""
import os, re, sys, json, subprocess
va, unit, blk, out = sys.argv[1:5]; V = int(va, 16); W = '/home/claude/vsw'; os.makedirs(out, exist_ok=True)
p = os.path.join(W, unit); base = open(p, encoding='latin-1').read(); b = open(blk, encoding='latin-1').read().strip('\n') + '\n'
_ls = b.split('\n'); _mi = [i for i, l in enumerate(_ls) if l.strip().lower() == '// 0x%08x' % V][0]
hdr = [l for l in _ls[_mi + 1:_mi + 4] if '(' in l][0]
name = [n for n in re.findall(r'([A-Za-z_]\w*)\s*\(', hdr) if not n.startswith('__')][0]
m = re.search(r'^[^\n;]*\b%s\s*\([^;{]*\)\s*\n\{' % re.escape(name), base, re.M)
if m:
    e = base.index('\n}\n', m.start()) + 3; new = base[:m.start()] + b + base[e:]; how = 'replaced the unmarked definition'
else:
    pos = len(base)
    for mm in re.finditer(r'^// 0x([0-9A-Fa-f]{8})\s*$', base, re.M):
        if os.environ.get('INSERT') != 'end' and int(mm.group(1), 16) > V: pos = mm.start(); break
    new = base[:pos] + b + '\n' + base[pos:]; how = 'inserted by address'
try:
    open(p, 'w', encoding='latin-1').write(new)
    env = {k: v for k, v in os.environ.items() if k != 'TMPDIR'}
    r = subprocess.run(['python3', '/home/claude/work/evalfn.py', W, va, unit], capture_output=True, text=True, env=env).stdout.strip().splitlines()
    score = r[-1] if r else '{}'
    open(os.path.join(out, 'score.json'), 'w').write(score + '\n')
    d = subprocess.run(['python3', '/home/claude/scripts/idiff.py', unit, '4'], capture_output=True, text=True, env=dict(env, IBLIS_ROOT=W))
    open(os.path.join(out, 'idiff.txt'), 'w').write(d.stdout + d.stderr[-1000:])
    pp = subprocess.run(['python3', '/home/claude/c2diag/iblis_pp.py', unit, os.path.join(out, 'unit.i.cpp')], capture_output=True, text=True, env=dict(env, IBLIS_ROOT=W))
    if pp.returncode: print('preprocess failed', pp.stderr[-500:]); sys.exit(1)
    flags = pp.stdout.strip()
    for cls in ('0',):
        c = subprocess.run(['python3', '/home/claude/c2diag/c2prio.py', os.path.join(out, 'unit.i.cpp'), '--func', name, '--flags', flags, '--class', cls, '--blocks', '--json', os.path.join(out, 'prio.jsonl')], capture_output=True, text=True, env=env, cwd=out, timeout=900)
        open(os.path.join(out, 'prio.txt'), 'w').write(c.stdout); open(os.path.join(out, 'prio.err'), 'w').write(c.stderr)
    open(os.path.join(out, 'candidate.cpp'), 'w', encoding='latin-1').write(b)
    print(va, name, how, '| flags:', flags or '(base)', '|', score[:220])
finally:
    open(p, 'w', encoding='latin-1').write(base)
