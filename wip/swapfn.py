#!/usr/bin/env python3
"""Try one candidate body for one function without touching the build's outputs.

usage (repo root of your clone):  unset TMPDIR; python3 swapfn.py <unit.cpp> <0xVA> <length> <candidate.cpp> [name-part]

The candidate file holds the whole function, starting with its `// 0x<VA>` line. If the unit already defines the
function under that marker, the definition is replaced; if not (a borrowed function), the candidate is put before
the unit's gen include. The unit is compiled with its own flags plus /FAs, the bytes of the function whose decorated
name contains name-part (default: the name after the marker) are compared with the original's, and the compiler's
frame symbols for it (`tvNNN = offset`, locals, parameters) are printed. The unit file is restored afterwards.
"""
import sys, os, re, json, struct, subprocess, tempfile
ROOT = os.getcwd(); sys.path.insert(0, os.path.join(ROOT, 'tools'))
from common import settings, compile_env, unit_env, default_flags, cl_command, _win_path
import link_exe as R
rel, va, length, cand = sys.argv[1], int(sys.argv[2], 16), int(sys.argv[3]), open(sys.argv[4]).read().rstrip('\n') + '\n'
s = settings(); os.environ.pop('TMPDIR', None)
unit = [u for u in json.load(open('build/units.json'))['units'] if u['file'] == rel][0]
flags = list(unit.get('flags') or default_flags(rel))
src = open(rel, encoding='latin-1').read(); mark = '// 0x%08X\n' % va
part = sys.argv[5] if len(sys.argv) > 5 else re.search(r'(\w+)\s*\(', cand[cand.index(mark) + len(mark):]).group(1)
if mark in src and re.match(r'[^;{]*\{', src[src.index(mark) + len(mark):]):
    i = src.index(mark); new = src[:i] + cand + src[src.index('\n}\n', i) + 3:]
else:
    i = src.rfind('#include "gen/'); i = len(src) if i < 0 else i; new = src[:i] + cand + '\n' + src[i:]
tmp = tempfile.mkdtemp(); obj, asm = os.path.join(tmp, 'u.obj'), os.path.join(tmp, 'u.asm')
env = unit_env(s, compile_env(s), rel); env.pop('TMPDIR', None); env.setdefault('WINEDEBUG', '-all')
try:
    open(rel, 'w', encoding='latin-1').write(new)
    r = subprocess.run(cl_command(s, flags + ['/FAs', '/Fa' + _win_path(asm, s)], _win_path(obj, s), _win_path(os.path.abspath(rel), s)),
                       env=env, capture_output=True, text=True)
finally:
    open(rel, 'w', encoding='latin-1').write(src)
if r.returncode:
    sys.exit((r.stdout + r.stderr)[-1500:])
o = R.Obj(open(obj, 'rb').read())
y = [y for y in o.syms if part in y['name'] and y['scn'] > 0 and y.get('type') == 0x20 and o.secs[y['scn'] - 1]['name'].startswith('.text')][0]
ours = o.secs[y['scn'] - 1]['raw'][y['value']:]
img = open(os.path.expanduser(s['image']), 'rb').read(); pe = struct.unpack_from('<I', img, 0x3C)[0]
base = struct.unpack_from('<I', img, pe + 52)[0]; sec = pe + 24 + struct.unpack_from('<H', img, pe + 20)[0]
_, vs, sva, rs, ro = struct.unpack_from('<8sIIII', img, sec); orig = img[ro + va - base - sva:][:length]
def dis(b):
    p = os.path.join(tmp, 'f.bin'); open(p, 'wb').write(b)
    t = subprocess.run(['objdump', '-D', '-b', 'binary', '-m', 'i386', '-M', 'intel', p], capture_output=True, text=True).stdout
    return [re.sub(r'0x[0-9a-f]+', 'N', l.split('\t')[-1]) for l in t.split('\n')[7:] if '\t' in l]
a = open(asm, encoding='latin-1').read(); j = a.index(y['name'] + ' PROC'); i = a.rfind('_TEXT\tSEGMENT', 0, j)
print('%s: ours %d B, original %d B' % (y['name'], len(ours.rstrip(b'\xcc')), length))
print('frame symbols:', ' | '.join('%s = %s' % m for m in re.findall(r'^(\S+) = (-?\d+)', a[i:j], re.M)))
import difflib
d = [l for l in difflib.unified_diff(dis(orig), dis(ours[:max(length, len(ours.rstrip(b'\xcc')))]), 'original', 'ours', lineterm='', n=0) if not l.startswith('@@')]
print('\n'.join(d) if d else 'instructions identical (operands with addresses are not compared: build the unit for the real check)')
