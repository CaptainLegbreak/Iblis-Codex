#!/usr/bin/env python3
"""idiff.py unit.cpp [ctx] : for each unequal function, print original vs ours instructions around each unmasked
difference (relocated operands are shown as-is; only real differences are listed)."""
import sys, json, os, re
ROOT=os.environ.get('IBLIS_ROOT','/home/claude/iblis-codex'); sys.path.insert(0, ROOT+'/tools'); os.chdir(ROOT)
import checker, capstone
from common import PE, expand_gen_includes
pe = PE(json.load(open('local.json'))['image'])
F = {int(r[0], 16): int(r[1]) for r in json.load(open('build/functions.json'))['functions']}
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.syntax = capstone.CS_OPT_SYNTAX_INTEL
f = sys.argv[1]; ctx = int(sys.argv[2]) if len(sys.argv) > 2 else 3
base = re.sub(r"[^A-Za-z0-9_.-]", "_", os.path.splitext(f)[0]); r = json.load(open('out/obj/%s.json' % base))
src = expand_gen_includes(open(f, encoding='latin-1').read(), f)
def ins(b, va): return [(i.address - va, '%s %s' % (i.mnemonic, i.op_str)) for i in md.disasm(bytes(b), va)]
for fn in r['functions']:
    if fn['equal']: continue
    va = int(fn['va'], 16)
    res = checker.compare(open('out/' + r['obj'], 'rb').read(), src, va, F[va], pe.read, F.get)
    A, B = ins(res['_orig'], va), ins(res['_body'], va)
    print('== %s %s unmasked diffs at %s' % (f.split('/')[-1], fn['va'], ['+0x%x' % d for d in res['_diffs']][:12]))
    shown = set()
    for d in res['_diffs'][:12]:
        for name, L in (('orig', A), ('ours', B)):
            k = max(i for i, (o, _) in enumerate(L) if o <= d)
            for o, t in L[max(0, k - ctx):k + ctx + 1]:
                key = (name, o)
                if key in shown: continue
                shown.add(key); print('  %s +0x%03x %s%s' % (name, o, t, '   <==' if o == L[k][0] else ''))
        print('  --')
