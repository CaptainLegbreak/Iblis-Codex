#!/usr/bin/env python3
"""c2probe.py - c2force's overrides on ANY source (a small reproducer, no queue VA), scored by how the target
function's own code changes against the plain compile, not against an original. For finding which c2.dll step makes a
decision: write a few-line reproducer of the shape, sweep the steps of a pass with --in, drill into the step whose skip
changes what you are after. Owner-side diagnostic like c2force (README.md, "c2force, more decisions"); lane TOOL-C2X.

usage:
  c2probe.py SOURCE FUNCFRAG [--flags "/GS-"] [--skip ADDR[:N]] [--rot ..] [--pick ..] ... --show   # print the code
  c2probe.py SOURCE FUNCFRAG [fixed overrides] --in 0xFN[,0xFN] [--max N]                          # skip sweep
FUNCFRAG is a fragment of the decorated name. The profile is match.py's (/nologo /c /TP /Zl /Z7 /Gy /MT /O2 /Oy- /Ob2
/Gd) plus --flags (default /GS-).
"""
import argparse, difflib, json, os, re, subprocess, sys, tempfile
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import c2force as F

PROFILE = ['/nologo', '/c', '/TP', '/Zl', '/Z7', '/Gy', '/MT', '/O2', '/Oy-', '/Ob2', '/Gd']


def body(objb, frag):
    d = tempfile.mkdtemp(prefix='probe-', dir=os.path.join(F.WORK, 'runs')); p = os.path.join(d, 'o.obj')
    open(p, 'wb').write(objb)
    out = subprocess.run(['objdump', '-d', '-r', '--no-show-raw-insn', '-M', 'intel', p], capture_output=True, text=True).stdout
    os.remove(p); os.rmdir(d)
    lines = []; on = False
    for l in out.splitlines():
        if l.endswith('>:'): on = frag in l; continue
        if on and ':\t' in l: lines.append(re.sub(r'^\s*[0-9a-f]+:\t', '', l).strip())
        elif on and l.strip() and 'R_386' in l and lines: lines[-1] += '   ; ' + l.split()[-1]
    return lines


def comp(src, flags, func, spec):
    objb, evs, out, _ = F.gdb_compile(src, flags, 'c2force_gdb.py', dict(C2FORCE_OUT='@EVENTS', C2FORCE_FUNC=func,
                                                                          C2FORCE_SPEC=json.dumps(spec)), tag='probe')
    return (body(objb, func) if objb else None), evs, out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('source'); ap.add_argument('func')
    ap.add_argument('--flags', default='/GS-')
    for k in F.OVERRIDES: ap.add_argument('--' + k, action='append', default=[])
    ap.add_argument('--in', dest='inside', help='skip sweep over the direct call sites of these c2.dll routines')
    ap.add_argument('--max', type=int, default=8, help='calls tried per call site (plus every call at once)')
    ap.add_argument('--show', action='store_true', help='print the target\'s code under the fixed overrides')
    ap.add_argument('--timeout', type=int, default=20)
    a = ap.parse_args()
    F.EARLY[0] = True; F.GDB_TIMEOUT = a.timeout
    F.JPOPS.update(F.jsite_pops())
    src = open(a.source, encoding='latin-1', newline='').read()
    flags = PROFILE + a.flags.split()
    fixed = [F.parse_override(k, s) for k in F.OVERRIDES for s in getattr(a, k)]
    base, evs, out = comp(src, flags, a.func, fixed)
    if base is None: sys.exit(out)
    for e in evs:
        if e['ev'] in ('applied', 'refused', 'miss', 'error'): print('%s:' % e['ev'], {k: v for k, v in e.items() if k != 'ev'})
    if a.show or not a.inside:
        print('\n'.join(base)); return
    print('plain (with the fixed overrides): %d instructions' % len(base))
    sites = [x for fn in a.inside.split(',') for x in F.c2calls(int(fn, 16))]
    _, evs, _, _ = F.gdb_compile(src, flags, 'c2force_gdb.py', dict(C2FORCE_OUT='@EVENTS', C2FORCE_FUNC=a.func,
                                 C2FORCE_SPEC=json.dumps(fixed), C2FORCE_SKIPREC=json.dumps(sorted({x[0] for x in sites}))), tag='probe')
    counts = {}; lns = {}
    for e in evs:
        if e['ev'] == 'srec':
            counts = {int(k): v for k, v in e['counts'].items()}; lns = {int(k): v for k, v in (e.get('lines') or {}).items()}
    print('%d call sites, %d reached for %s' % (len(sites), len(counts), a.func))
    for site, ret, callee in sites:
        c = counts.get(site, 0)
        for n in ([0] if c > 1 else []) + list(range(1, min(c, a.max) + 1)):
            sp = fixed + [dict(kind='skip', fn=callee, n=n, ret=0, pop=F.c2pop(callee), **{'from': ret})]
            b, _, _ = comp(src, flags, a.func, sp)
            if b == base: continue
            if b is None: r = 'compile error / timeout'
            else:
                sm = difflib.SequenceMatcher(None, base, b, autojunk=False)
                r = '%d lines differ (%d -> %d instructions)' % (
                    sum(max(i2 - i1, j2 - j1) for t, i1, i2, j1, j2 in sm.get_opcodes() if t != 'equal'), len(base), len(b))
            ln = (lns.get(site) or [None] * n)[n - 1] if n and n <= len(lns.get(site) or []) else None
            print('--skip 0x%x:%d   (0x%x, call %s of %d%s): %s' % (site, n, callee, n or 'every', c, ' L%s' % ln if ln else '', r))
            sys.stdout.flush()


if __name__ == '__main__':
    main()
