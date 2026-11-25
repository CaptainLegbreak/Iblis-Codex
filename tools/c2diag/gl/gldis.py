#!/usr/bin/env python3
"""gldis.py OUTDIR VA [--tag R] [--func NAME] [-q]: disassemble the target from OUTDIR/gl/<tag>.exe (found through
<tag>.map; R is the image glread.py links, A the one scratch.py --gl links) and print an aligned diff of its
instructions against the original's (from your own image, through tools/common; addresses masked) and the number of
differing aligned lines. The length is the queue's. Prints at run time only; never commit or paste the output.
Diagnostic only."""
import argparse, difflib, os, re, struct, sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.environ.get('D2REPO', os.path.abspath(os.path.join(HERE, '..', '..', '..')))
sys.path.insert(0, os.path.join(REPO, 'tools')); sys.path.insert(0, os.path.dirname(HERE))


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('outdir'); ap.add_argument('va'); ap.add_argument('--tag', default='R')
    ap.add_argument('--func', help='decorated-name fragment (default: from the `// 0xVA` marker in OUTDIR/c.cpp)')
    ap.add_argument('-q', action='store_true', help='only the summary lines')
    a = ap.parse_args()
    import capstone, common
    from c2prio import target_name
    va = int(a.va, 16); gld = os.path.join(os.path.abspath(a.outdir), 'gl')
    if a.func: fr = a.func
    else:
        n = target_name(os.path.join(os.path.abspath(a.outdir), 'c.cpp'), '0x%08X' % va)
        fr = n if n.startswith('?') else '?' + n + '@'
    st, _, item = common.load_queue_item('0x%08X' % va)
    if not item: sys.exit('gldis: 0x%08X is not in the queue' % va)
    n_orig = item['length']
    m = open(os.path.join(gld, a.tag + '.map'), errors='replace').read().splitlines()
    rows = [l.split() for l in m if re.match(r'\s*0001:', l) and len(l.split()) > 2 and re.fullmatch(r'[0-9a-f]{8}', l.split()[2])]
    addrs = sorted(int(r[2], 16) for r in rows)
    hits = [int(r[2], 16) for r in rows if fr in r[1] and '$' not in r[1]]
    if not hits: sys.exit('gldis: %s not in %s.map' % (fr, a.tag))
    fa = hits[0]; nxt = min([x for x in addrs if x > fa] or [fa + 0x10000])
    ours_pe = common.PE(os.path.join(gld, a.tag + '.exe'))
    code = ours_pe.read(fa, nxt - fa).rstrip(b'\xcc')
    orig = common.PE(common.local_settings()['image']).read(va, n_orig)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    def norm(b, base):
        return [re.sub(r'0x[0-9a-f]{5,}', 'X', '%s %s' % (i.mnemonic, i.op_str)) for i in md.disasm(b, base)]
    A, B = norm(orig, va), norm(code, fa)
    print('len ours %d vs original %d; instructions %d vs %d' % (len(code), n_orig, len(B), len(A)))
    nd = 0
    for op in difflib.SequenceMatcher(None, A, B, autojunk=False).get_opcodes():
        if op[0] != 'equal':
            nd += max(op[2] - op[1], op[4] - op[3])
            if not a.q: print(op[0], A[op[1]:op[2]], '=>', B[op[3]:op[4]])
    print('aligned diff lines', nd)


if __name__ == '__main__':
    main()
