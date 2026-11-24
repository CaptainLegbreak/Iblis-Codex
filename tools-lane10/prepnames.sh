#!/bin/bash
# prepnames.sh <plan.tsv> <out.json> : lane 10's plan.tsv -> rename plan, without the spellings that are other
# functions (emit helpers, shims, inline/impl copies) or file names (Unknown_<VA>, which would rename files).
python3 /home/claude/tools-lane10/mkplan.py "$1" /tmp/prep-raw.json && python3 -I -c "
import json,re,sys
P=json.load(open('/tmp/prep-raw.json'))
Q=[p for p in P if not p['old'].startswith('Unknown_') and not (p.get('alt') and re.search(r'_Emit_|Emit\d|Shim|_Inline|Impl',p['old']))]
json.dump(Q,open('$2','w'),indent=1); print(len(P),'->',len(Q),'renames')"
