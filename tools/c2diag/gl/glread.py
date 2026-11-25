#!/usr/bin/env python3
"""glread.py OUTDIR --func 0xVA|NAME [--reader prio|temps|sched|layout|force|slots|split] [--events OUT]
             [--spec JSON] [--ov KIND=VALUE ...] [--timeout S]

Re-run the `A` LTCG link that glcap.py captured in OUTDIR (OUTDIR/links.json, work folder OUTDIR/gl) with the c2diag
spin copy's link.exe ($C2DIAG_HOME/tcspin/bin, whose c2.dll colour driver spins; setup_tcspin.py builds it) and attach
an unchanged c2diag collector (c2<reader>_gdb.py) the way c2prio.py attaches to cl.exe. Under /GL the code is generated
in the link, so this is the only place the readers can see it. The image goes to OUTDIR/gl/R.exe and R.map (gldis.py
compares it with the original). The events go to --events (default OUTDIR/<reader>.jsonl); report them with the
reader's own `--events` option (c2prio.py, c2temps.py, c2sched.py, c2layout.py). --func takes the source's `// 0xVA`
marker (OUTDIR/c.cpp) or a decorated-name fragment. Any C2* variable in the environment is passed to the collector
(for example C2PRIO_BLOCKS=0). Diagnostic only."""
import argparse, json, os, subprocess, sys, time

HERE = os.path.dirname(os.path.abspath(__file__))
C2D = os.path.dirname(HERE)
sys.path.insert(0, C2D)
import c2prio
from c2prio import TC, target_name


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('outdir'); ap.add_argument('--func', required=True)
    ap.add_argument('--reader', default='prio', choices=['prio', 'temps', 'sched', 'layout', 'force', 'slots', 'split'])
    ap.add_argument('--events'); ap.add_argument('--spec', default='[]', help='c2force override list (JSON), reader force')
    ap.add_argument('--ov', action='append', default=[], help='reader force: one c2force override in its CLI form, '
                    'KIND=VALUE, e.g. prio=1:pInfo:-20 or reg=1:pInfo:edx (repeatable; added to --spec)')
    ap.add_argument('--timeout', type=int, default=700)
    a = ap.parse_args()
    od = os.path.abspath(a.outdir); gld = os.path.join(od, 'gl')
    name = target_name(os.path.join(od, 'c.cpp'), a.func)
    frag = name if name.startswith('?') else '?' + name + '@'
    links = json.load(open(os.path.join(od, 'links.json')))
    L = [l for l in links if any(c == '/MAP:A.map' for c in l['cmd'])]
    if not L: sys.exit('glread: no `A` link in links.json')
    cmd = L[0]['cmd']; i = [k for k, c in enumerate(cmd) if c.lower().endswith('link.exe')][0]
    args = [x for x in cmd[i + 1:] if x]
    args = ['/OUT:R.exe' if x.startswith('/OUT:') else '/MAP:R.map' if x.startswith('/MAP:') else x for x in args]
    R = a.reader.upper(); evp = os.path.abspath(a.events or os.path.join(od, a.reader + '.jsonl'))
    genv = {k: v for k, v in os.environ.items()}
    genv.update({'C2%s_OUT' % R: evp, 'C2%s_FUNC' % R: frag, 'C2%s_HERE' % R: C2D})
    if a.reader == 'prio': genv.setdefault('C2PRIO_BLOCKS', '1')
    if a.reader == 'sched':
        import c2sched
        genv.setdefault('C2SCHED_SITES', json.dumps([[ret - 5, callee, ret] for callee, ret in c2sched.PIPELINE]))
        genv.setdefault('C2SCHED_JCALLS', json.dumps(c2sched.JCALLS))
    if a.reader == 'force':
        import c2force
        spec = json.loads(a.spec) + [c2force.parse_override(*o.split('=', 1)) for o in a.ov]
        genv['C2FORCE_SPEC'] = json.dumps(spec)
        genv.setdefault('C2FORCE_JSITES', json.dumps({str(k): v for k, v in c2force.jsite_pops().items()}))
    env = dict(os.environ, WINEDEBUG='-all')
    logp = os.path.join(od, 'glread_link.log')
    with open(logp, 'wb') as log:
        p = subprocess.Popen(['wine', os.path.join(TC, 'link.exe')] + args, cwd=gld, env=env, stdout=log,
                             stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL)
    g = None
    try:
        pid = None; t0 = time.time()
        while pid is None:
            if p.poll() is not None: sys.exit('glread: link exited before code generation:\n' + open(logp, encoding='latin1').read()[-800:])
            if time.time() - t0 > 180: sys.exit('glread: timeout waiting for c2.dll in the link')
            try:
                if os.path.join(TC, 'c2.dll') in open('/proc/%d/maps' % p.pid).read(): pid = p.pid
            except OSError: pass
            time.sleep(0.05)
        g = subprocess.Popen(['gdb', '-q', '-batch', '-nx', '-p', str(pid), '-ex',
                              'python exec(open(%r).read())' % os.path.join(C2D, 'c2%s_gdb.py' % a.reader)],
                             env=genv, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, stdin=subprocess.DEVNULL)
        t1 = time.time()
        while g.poll() is None or p.poll() is None:
            if time.time() - t1 > a.timeout: sys.exit('glread: TIMEOUT after %d s; the link was killed' % a.timeout)
            time.sleep(0.05)
    finally:
        for q in (p, g):
            if q is not None and q.poll() is None: q.kill()
    print('glread: %s events in %s; image %s' % (a.reader, evp, os.path.join(gld, 'R.exe')))


if __name__ == '__main__':
    main()
