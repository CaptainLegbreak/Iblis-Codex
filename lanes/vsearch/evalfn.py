"""evalfn.py <root> <va> <unit.cpp> : build <unit> in worktree <root> with <va> registered in it (scratch edit of
build/units.json, restored after), compare the function with the original; print one JSON line:
{status, ours, orig, diff_lines, unmasked, others}. The unit's source must mark the function with `// 0x<VA>`."""
import sys, json, os, re, subprocess
root, va_s, f = sys.argv[1:4]; va = int(va_s, 16)
sys.path.insert(0, root + '/tools'); os.chdir(root)
import checker, capstone
from common import PE, expand_gen_includes
F = {int(r[0], 16): int(r[1]) for r in json.load(open('build/functions.json'))['functions']}
U0 = open('build/units.json').read(); U = json.loads(U0)
e = [x for x in U['units'] if x['file'] == f][0]
if not any(int(x['va'], 16) == va for x in e['functions']):
    e['functions'].append({'va': '0x%08X' % va, 'length': F[va]}); e['functions'].sort(key=lambda x: int(x['va'], 16))
try:
    open('build/units.json.tmp', 'w').write(json.dumps(U, indent=1) + '\n'); os.replace('build/units.json.tmp', 'build/units.json')
    env = {k: v for k, v in dict(os.environ, WINEDEBUG='-all').items() if k != 'TMPDIR'}
    try:
        subprocess.run(['python3', 'tools/build.py', '-j', '1', '--files', f], capture_output=True, text=True, env=env, timeout=240)
    except subprocess.TimeoutExpired:
        subprocess.run('pkill -f "tools/build.py -j 1 --files %s"' % f, shell=True)
        print(json.dumps({'status': 'TIMEOUT'})); sys.exit()
finally:
    open('build/units.json.tmp', 'w').write(U0); os.replace('build/units.json.tmp', 'build/units.json')
base = re.sub(r"[^A-Za-z0-9_.-]", "_", os.path.splitext(f)[0]); o = json.load(open('out/obj/%s.json' % base))
if 'functions' not in o or not o['functions']:
    print(json.dumps({'status': 'COMPILE_ERROR', 'err': o.get('output', '')[-400:]})); sys.exit()
others = [x['va'] for x in o['functions'] if not x['equal'] and int(x['va'], 16) != va]
pe = PE(json.load(open('local.json'))['image']); src = expand_gen_includes(open(f, encoding='latin-1').read(), f)
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
fn = [x for x in o['functions'] if int(x['va'], 16) == va]
if not fn:
    print(json.dumps({'status': 'NOT_FOUND', 'others': others})); sys.exit()
res = checker.compare(open('out/' + o['obj'], 'rb').read(), src, va, F[va], pe.read, F.get)
D = set(res.get('_diffs', []))
B = [(i.address - va, i.size) for i in md.disasm(bytes(res.get('_body', b'')), va)]
A = [(i.address - va, i.size) for i in md.disasm(bytes(res.get('_orig', b'')), va)]
import difflib
TA = ['%s %s' % (i.mnemonic, re.sub(r'0x[0-9a-f]{5,}', 'A', i.op_str)) for i in md.disasm(bytes(res.get('_orig', b'')), va)]
TB = ['%s %s' % (i.mnemonic, re.sub(r'0x[0-9a-f]{5,}', 'A', i.op_str)) for i in md.disasm(bytes(res.get('_body', b'')), va)]
sm = difflib.SequenceMatcher(None, TA, TB, autojunk=False)
matched = sum(b.size for b in sm.get_matching_blocks())
first = next((k for k in range(min(len(TA), len(TB))) if TA[k] != TB[k]), min(len(TA), len(TB)))
n = 0
for k in range(max(len(A), len(B))):
    a = A[k] if k < len(A) else (None, 0); b = B[k] if k < len(B) else (None, 0)
    if a[0] != b[0] or any(x in D for x in range(b[0] or 0, (b[0] or 0) + b[1])): n += 1
print(json.dumps({'status': res.get('status'), 'ours': res.get('compiled_length'), 'orig': res.get('expected_length'),
                  'diff_lines': n, 'unaligned': len(TA) + len(TB) - 2 * matched, 'prefix': first, 'unmasked': res.get('unmasked_diff_bytes'), 'others': others}))
