#!/bin/bash
# glprio.sh VA SRC.cpp OUTDIR [c2prio report args...]: scratch --gl capture (glcap.py), the c2prio collector on the
# real LTCG link (glread.py), then c2prio.py's report from the events. OUTDIR outside the repository. Diagnostic only.
set -e
here=$(cd "$(dirname "$0")" && pwd); c2d=$(dirname "$here")
va=$1; src=$2; out=$3; shift 3
timeout 900 python3 "$here/glcap.py" "$va" "$src" "$out"
timeout 750 python3 "$here/glread.py" "$out" --func "$va" --reader prio --events "$out/prio.jsonl"
python3 "$c2d/c2prio.py" "$out/c.cpp" --func "$va" --events "$out/prio.jsonl" "$@"
