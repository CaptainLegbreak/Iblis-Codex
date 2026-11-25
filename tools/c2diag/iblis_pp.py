#!/usr/bin/env python3
"""iblis_pp.py <unit.cpp> <out.cpp> : preprocess one Iblis-Codex unit exactly as tools/build.py compiles it (its
INCLUDE paths, gen/ data expanded, its units.json flags) into a self-contained source for the c2diag readers, and
print the flags to pass them after the fixed profile (--flags). Runs from the repo root (IBLIS_ROOT)."""
import os, sys, json, subprocess
ROOT = os.environ.get('IBLIS_ROOT', '/home/claude/iblis-codex'); os.chdir(ROOT); sys.path.insert(0, ROOT + '/tools')
import common
unit, out = sys.argv[1], os.path.abspath(sys.argv[2])
s = json.load(open('local.json'))
u = [x for x in json.load(open('build/units.json'))['units'] if x['file'] == unit][0]
BASE = ['/nologo', '/c', '/TP', '/Zl', '/Z7', '/Gy', '/MT', '/O2', '/Oy-', '/Ob2', '/Gd']
flags = u.get('flags') or BASE
extra = [f for f in flags if f not in BASE]
text = common.expand_gen_includes(open(unit, encoding='latin-1').read(), unit)
tmp = out + '.src.cpp'; open(tmp, 'w', encoding='latin-1').write(text)
env = {k: v for k, v in common.unit_env(s, common.compile_env(s), unit).items() if k != 'TMPDIR'}
pp = [f for f in flags if f not in ('/c', '/Z7', '/Gy')] + ['/E', 'Z:' + tmp.replace('/', '\\')]
r = subprocess.run(['wine', s['cl']] + pp, capture_output=True, env=env, cwd=os.path.dirname(unit) or '.')
if r.returncode:
    sys.exit('preprocess failed:\n' + r.stderr.decode('latin-1')[-2000:])
open(out, 'wb').write(r.stdout); os.remove(tmp)
print(' '.join(extra))
