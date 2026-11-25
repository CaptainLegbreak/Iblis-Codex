#!/bin/bash
# glforce.sh OUTDIR VA KIND=VALUE [KIND=VALUE ...] [-- gldis args]: re-run OUTDIR's captured LTCG link (glcap.py
# first) with c2force_gdb.py applying the overrides (c2force's CLI forms: prio=1:pInfo:-20, reg=1:pInfo:edx,
# sched=9:4:+1025, jskip=10b2d0db:1 ...), then gldis.py's aligned diff of the forced image against the original
# (-q by default; pass `-- ` with nothing after it for the full diff) and the number of overrides applied.
# Diagnostic only; an override is never a deliverable.
set -e
here=$(cd "$(dirname "$0")" && pwd)
out=$1; va=$2; shift 2
ov=(); while [ $# -gt 0 ] && [ "$1" != "--" ]; do ov+=(--ov "$1"); shift; done
dis=(-q); if [ "$1" == "--" ]; then shift; dis=("$@"); fi
timeout 750 python3 "$here/glread.py" "$out" --func "$va" --reader force "${ov[@]}" --events "$out/force.jsonl"
python3 "$here/gldis.py" "$out" "$va" --tag R "${dis[@]}"
echo "overrides applied: $(grep -c '"applied"' "$out/force.jsonl" || true)"
