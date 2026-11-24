"""nameround.py <root> <plan.json> : apply a naming plan, build every touched unit and includer, drop the addresses
whose units fail, repeat until equal. Leaves the result uncommitted. Prints the excluded addresses."""
import json, os, re, subprocess, sys
R, plan_f = sys.argv[1], sys.argv[2]; S = '/home/claude/scripts'
def sh(*a, **k): return subprocess.run(list(a), cwd=R, capture_output=True, text=True, **k)
plan = json.load(open(plan_f)); excl = set()
env = {k: v for k, v in dict(os.environ, WINEDEBUG='-all').items() if k != 'TMPDIR'}
for it in range(6):
    sh('git', 'checkout', '-q', '--', 'Source', 'build', 'names.csv')
    P = [p for p in plan if p['va'] not in excl]
    json.dump(P, open('/tmp/nr-plan.json', 'w'))
    print(sh('python3', '/home/claude/tools-lane10/apply.py', R, env=dict(os.environ, PLAN='/tmp/nr-plan.json', EXCL='/dev/null')).stdout.strip())
    ch = [f for f in sh('git', 'diff', '--name-only', '--', 'Source').stdout.split() if f]
    cpp = [f for f in ch if re.search(r'\.(cpp|c)$', f, re.I)]
    hdr = sorted({os.path.basename(f) for f in ch if f.endswith('.h')})
    if hdr:
        cpp += [x for x in sh('python3', S + '/users.py', ','.join(hdr), env=dict(os.environ, IBLIS_ROOT=R)).stdout.strip().split(',') if x]
    cpp = sorted(set(c for c in cpp if os.path.exists(os.path.join(R, c))))
    out = sh('python3', 'tools/build.py', '-j', '2', '--files', ','.join(cpp), env=env).stdout
    bad = re.findall(r'^\s+(\S+): (COMPILE_ERROR|NOT_ALL_EQUAL)', out, re.M)
    print('iteration', it, len(P), 'renames,', len(cpp), 'units,', len(bad), 'failing', flush=True)
    if not bad: break
    new2va = {}
    for p in P: new2va.setdefault(p['new'], set()).add(p['va'])
    for f, kind in bad:
        base = re.sub(r"[^A-Za-z0-9_.-]", "_", os.path.splitext(f)[0]); o = json.load(open('%s/out/obj/%s.json' % (R, base)))
        txt = o.get('output', '') if kind == 'COMPILE_ERROR' else ''
        hit = {va for n, vas in new2va.items() if re.search(r"\b%s\b" % re.escape(n), txt) for va in vas}
        if not hit:
            diff = sh('git', 'diff', '-U0', '--', f).stdout
            hit = {va for n, vas in new2va.items() if re.search(r"^\+.*\b%s\b" % re.escape(n), diff, re.M) for va in vas}
        excl |= hit
print('DONE excluded', sorted(excl))
