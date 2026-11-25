#!/bin/bash
# gllayout.sh VA SRC.cpp OUTDIR [c2layout report args...]: as glprio.sh, with the block-layout reader (c2layout).
set -e
here=$(cd "$(dirname "$0")" && pwd); c2d=$(dirname "$here")
va=$1; src=$2; out=$3; shift 3
timeout 900 python3 "$here/glcap.py" "$va" "$src" "$out"
timeout 750 python3 "$here/glread.py" "$out" --func "$va" --reader layout --events "$out/layout.jsonl"
python3 "$c2d/c2layout.py" "$out/c.cpp" --func "$va" --events "$out/layout.jsonl" "$@"
