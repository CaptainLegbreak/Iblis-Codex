#!/usr/bin/env python3
"""greedy.py TEMPLATE UNIT_REL VA INTO ANCHOR [--start i,j,..] [--rounds N]
TEMPLATE: text with groups <<{alt0<<ALT>>alt1...}>> ; the function name must be written FNAME.
Everything before a line '//==FUNC==' is shared preamble (helpers); after it, the function template."""
import sys, os, re, subprocess, random, itertools, json
tpl_path, rel, va, into, anchor = sys.argv[1:6]
args = sys.argv[6:]
def opt(n, d=None): return args[args.index(n)+1] if n in args else d
T = open(tpl_path).read()
pre, func = T.split('//==FUNC==\n', 1)
parts = re.split(r'<<\{(.*?)\}>>', func, flags=re.S)
lits = parts[0::2]; groups = [g.split('<<ALT>>') for g in parts[1::2]]
def render(ch, name):
    s = lits[0]
    for i, g in enumerate(groups): s += g[ch[i]] + lits[i+1]
    return s.replace('FNAME', name)
def score_batch(choices):
    src = pre + '\n' + '\n'.join(render(c, 'V_%04d' % k) for k, c in enumerate(choices))
    open('/tmp/greedy_batch_%d.cpp' % os.getpid(), 'w').write(src)
    env = dict(os.environ, INTO=into, ANCHOR=anchor, WINEDEBUG='-all'); env.pop('TMPDIR', None)
    if into == '-': env.pop('INTO', None)
    r = subprocess.run(['python3', os.path.join(os.path.dirname(os.path.abspath(__file__)), 'multi.py'), rel, '/tmp/greedy_batch_%d.cpp' % os.getpid(), va], capture_output=True, text=True, env=env)
    res = {}
    for l in r.stdout.splitlines():
        m = re.search(r'V_(\d+)\s+len\s+(\d+)/(\d+) slot (\d) difflines\s+(\d+)', l)
        if m: k = int(m.group(1)); res[k] = int(m.group(5)) + 2 * abs(int(m.group(2)) - int(m.group(3))) + (0 if ('PRO_OK' in l or not os.environ.get('PRO')) else 30)
    if not res: print(r.stdout[-1500:], r.stderr[-1500:])
    return [res.get(k, 10**6) for k in range(len(choices))]
cur = [int(x) for x in opt('--start').split(',')] if opt('--start') else [0] * len(groups)
if opt('--seed'):
    random.seed(int(opt('--seed'))); cur = [random.randrange(len(g)) for g in groups]
best = score_batch([cur])[0]; print('start', cur, best, flush=True)
for rnd in range(int(opt('--rounds', '20'))):
    neigh = []
    for i, g in enumerate(groups):
        for a in range(len(g)):
            if a != cur[i]: c = list(cur); c[i] = a; neigh.append(c)
    # also some random pair moves
    for _ in range(int(opt('--pairs', '20'))):
        c = list(cur)
        for i in random.sample(range(len(groups)), min(2, len(groups))): c[i] = random.randrange(len(groups[i]))
        neigh.append(c)
    sc = []
    for k in range(0, len(neigh), 60): sc += score_batch(neigh[k:k+60])
    j = min(range(len(neigh)), key=lambda k: sc[k])
    print('round', rnd, 'best neighbour', sc[j], neigh[j], flush=True)
    if sc[j] < best: cur, best = neigh[j], sc[j]
    elif sc[j] == best and neigh[j] != cur: cur = neigh[j]
    else: break
    if best == 0: break
print('FINAL', ','.join(map(str, cur)), best)
open(tpl_path + '.best.cpp', 'w').write(render(cur, 'BEST'))
