#!/usr/bin/env python3
"""glcap.py VA SOURCE OUTDIR [--timeout S]: copy SOURCE to OUTDIR/c.cpp, run `tools/scratch.py VA OUTDIR/c.cpp --gl`
(uncharged, the owner-side /GL link mode) and record every link.exe command line it starts, with its working folder, in
OUTDIR/links.json. scratch.py leaves its LTCG work folder in OUTDIR/gl, so glread.py can re-run the real LTCG link
there under a c2diag reader. OUTDIR must be outside the repository (scratch.py refuses candidates inside it).
Diagnostic only: nothing is delivered, no attempt is charged. See contrib/c2diag/README.md ("/GL readers")."""
import argparse, json, os, shutil, subprocess, sys, time

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.environ.get('D2REPO', os.path.abspath(os.path.join(HERE, '..', '..', '..')))


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('va'); ap.add_argument('source'); ap.add_argument('outdir')
    ap.add_argument('--timeout', type=int, default=900, help='seconds scratch.py --gl may run (default 900)')
    a = ap.parse_args()
    od = os.path.abspath(a.outdir)
    if od.startswith(REPO + os.sep): sys.exit('glcap: OUTDIR must be outside the repository')
    os.makedirs(od, exist_ok=True)
    cpp = os.path.join(od, 'c.cpp')
    if os.path.abspath(a.source) != cpp: shutil.copy(a.source, cpp)
    mine = set(int(p) for p in os.listdir('/proc') if p.isdigit())
    log = open(os.path.join(od, 'scratch.log'), 'wb')
    sc = subprocess.Popen([sys.executable, os.path.join(REPO, 'tools', 'scratch.py'), a.va, cpp, '--gl'], cwd=REPO,
                          stdout=log, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL)
    seen = {}; t0 = time.time()
    while sc.poll() is None:
        if time.time() - t0 > a.timeout:
            sc.kill(); sys.exit('glcap: scratch.py --gl TIMEOUT after %d s' % a.timeout)
        for p in os.listdir('/proc'):
            if not p.isdigit() or int(p) in mine or p in seen: continue
            try:
                cmd = open('/proc/%s/cmdline' % p, 'rb').read().decode('latin1').split('\x00')
                if not any(c.lower().endswith('link.exe') for c in cmd): continue
                seen[p] = dict(cmd=cmd, cwd=os.readlink('/proc/%s/cwd' % p))
            except OSError:
                pass
        time.sleep(0.01)
    log.close()
    json.dump(list(seen.values()), open(os.path.join(od, 'links.json'), 'w'), indent=1)
    out = open(os.path.join(od, 'scratch.log'), encoding='latin1').read()
    st = [l for l in out.splitlines() if l.startswith('status') or 'die' in l or 'error' in l.lower()]
    print('glcap: %d link commands captured; %s' % (len(seen), ' | '.join(st[:3]) or out[-400:]))
    if not any('/MAP:A.map' in c for l in seen.values() for c in l['cmd']):
        sys.exit('glcap: no `A` link captured (did scratch.py --gl reach the link step? see %s/scratch.log)' % od)


if __name__ == '__main__':
    main()
