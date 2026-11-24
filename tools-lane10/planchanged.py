#!/usr/bin/env python3
"""planchanged.py : comma list of source files whose data-plan entry or definitions differ from origin/main."""
import json, subprocess, collections
R = '/home/claude/iblis-codex'
def plan(rev): return json.loads(subprocess.run(['git', 'show', rev + ':build/data_plan.json'], cwd=R, capture_output=True, text=True).stdout)
A, B = plan('origin/main'), plan('HEAD')
def defs(p):
    d = collections.defaultdict(list)
    for x in p['definitions']: d[x['file']].append(json.dumps(x, sort_keys=True))
    return {k: sorted(v) for k, v in d.items()}
da, db = defs(A), defs(B)
ch = {f for f in set(A['files']) | set(B['files']) if A['files'].get(f) != B['files'].get(f)}
ch |= {f for f in set(da) | set(db) if da.get(f) != db.get(f)}
print(','.join(sorted(ch)))
