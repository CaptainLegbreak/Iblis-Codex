#!/usr/bin/env python3
"""users.py Header.h[,Header2.h] : units (from build/units.json) whose include closure contains any named header."""
import json, os, re, sys
ROOT = os.environ.get('IBLIS_ROOT', '/home/claude/iblis-codex')
sys.path.insert(0, ROOT + '/tools')
from common import unit_headers
want = set(sys.argv[1].split(','))
units = [u['file'] for u in json.load(open(ROOT + '/build/units.json'))['units']]
out = []
for f in units:
    t = open(os.path.join(ROOT, f), encoding='latin-1').read()
    if any(os.path.basename(h) in want for h in unit_headers(t, f)):
        out.append(f)
print(','.join(out))
