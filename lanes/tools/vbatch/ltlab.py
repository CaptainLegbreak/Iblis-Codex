#!/usr/bin/env python3
"""ltlab.py UNIT_REL FILE VA [+flag|-flag ...]: like multi.py, but compiles with /GL and links /LTCG into a scratch DLL,
then compares every exported V_ function with the original at VA. Variants must be `extern "C"` so they can be exported.
Env: INTO/ANCHOR (insert FILE into a real unit), SHOW=V_name (print that variant's diff), IBLIS_ROOT."""
import sys, os, subprocess, tempfile, shutil, re, difflib, struct
ROOT = os.environ.get('IBLIS_ROOT', os.getcwd()); F = os.path.abspath(sys.argv[2]); sys.path.insert(0, ROOT + '/tools'); os.chdir(ROOT)
from common import settings, compile_env, unit_env, cl_command, PE, default_flags, load_json
rel, va = sys.argv[1], int(sys.argv[3], 16)
S = settings(); pe = PE(S['image']); L = {int(r[0], 16): int(r[1]) for r in load_json('functions.json')['functions']}
U = next((u for u in load_json('units.json')['units'] if u['file'] == rel), None)
flags = list((U or {}).get('flags') or default_flags(rel))
for t in [x for x in sys.argv[4:] if x[:1] in '+-']:
    if t[0] == '+': flags.append(t[1:])
    elif t[1:] in flags: flags.remove(t[1:])
flags.append('/GL')
wd = tempfile.mkdtemp(dir='/tmp')
txt = open(F, encoding='latin-1').read()
if os.environ.get('INTO'):
    base = open(os.environ['INTO'], encoding='latin-1').read(); anc = os.environ['ANCHOR']; assert anc in base, 'anchor'
    txt = base.replace(anc, txt + '\n' + anc, 1)
names = re.findall(r'extern "C" \w[\w\s\*]*?__(fastcall|stdcall|cdecl) (V_\w+)\(', txt)
open(wd + '/unit.cpp', 'w', encoding='latin-1', newline='').write(txt)
r = subprocess.run(cl_command(S, flags, 'unit.obj', 'unit.cpp'), capture_output=True, text=True, env=unit_env(S, compile_env(S), rel), cwd=wd)
if r.returncode: print((r.stdout + r.stderr)[-3000:]); sys.exit(1)
link = os.path.join(os.path.dirname(S['cl']), 'link.exe')
exp = []
for cc, n in names:
    exp.append('/EXPORT:' + n)
args = ['/nologo', '/LTCG', '/DLL', '/NOENTRY', '/NODEFAULTLIB', '/FORCE:UNRESOLVED', '/OPT:NOREF', '/OPT:NOICF',
        '/SAFESEH:NO', '/INCREMENTAL:NO', '/MAP:unit.map', '/OUT:unit.dll', 'unit.obj'] + exp
env = dict(os.environ); env.setdefault('WINEDEBUG', '-all')
r = subprocess.run(['wine', link] + args, capture_output=True, text=True, cwd=wd, env=env)
if not os.path.exists(wd + '/unit.dll'): print((r.stdout + r.stderr)[-3000:]); sys.exit(1)
img = open(wd + '/unit.dll', 'rb').read()
pe_off = struct.unpack_from('<I', img, 0x3c)[0]; nsec = struct.unpack_from('<H', img, pe_off + 6)[0]
optsz = struct.unpack_from('<H', img, pe_off + 20)[0]; sh = pe_off + 24 + optsz
imgbase = struct.unpack_from('<I', img, pe_off + 24 + 28)[0]
secs = []
for i in range(nsec):
    o = sh + 40 * i; vsz, vaddr, rsz, rptr = struct.unpack_from('<IIII', img, o + 8); secs.append((vaddr, vsz, rptr, rsz))
def read(rva, n):
    for vaddr, vsz, rptr, rsz in secs:
        if vaddr <= rva < vaddr + max(vsz, rsz): return img[rptr + rva - vaddr: rptr + rva - vaddr + n]
    return b''
syms = []
for l in open(wd + '/unit.map', encoding='latin-1'):
    m = re.match(r'\s*[0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})\s', l)
    if m: syms.append((int(m.group(2), 16), m.group(1)))
syms.sort()
def dis(b):
    p = subprocess.run(['llvm-mc-18', '--disassemble', '-triple=i686', '--output-asm-variant=1'], input=' '.join('0x%02x' % x for x in b), capture_output=True, text=True)
    out = []
    for l in p.stdout.split('\n'):
        l = l.strip()
        if not l or l.startswith('.'): continue
        l = re.sub(r'^(call|jmp)\s+-?\d+$', r'\1 X', l); l = re.sub(r'push\s+\d{6,}$', 'push ADDR', l); l = re.sub(r'^call\s+0$', 'call X', l)
        out.append(l)
    return out
O = dis(pe.read(va, L[va]))
for i, (a, n) in enumerate(syms):
    m = re.match(r'_?@?(V_\w+?)(@\d+)?$', n)
    if not m: continue
    nxt = next((b for b, _ in syms[i + 1:] if b > a), a + 4096)
    body = read(a - imgbase, nxt - a).rstrip(b'\xcc')
    A = dis(body); nm = m.group(1)
    sm = difflib.SequenceMatcher(None, O, A, autojunk=False); d = sum(max(t[2] - t[1], t[4] - t[3]) for t in sm.get_opcodes() if t[0] != 'equal')
    if os.environ.get('SHOW') == nm:
        for l in difflib.unified_diff(O, A, 'orig', 'ours', n=1, lineterm=''): print('   ', l)
    print('PRO_OK' if A[:3] == O[:3] else 'PRO_BAD', '%-12s len %4d/%d difflines %3d' % (nm, len(body), L[va], d))
shutil.rmtree(wd)
