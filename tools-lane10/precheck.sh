#!/bin/bash
# precheck.sh : build every unit changed on this branch (vs origin/main) plus every includer of a changed header.
# Must end " 0 not all equal" before verify.sh. Also checks commits for banned words and conflict markers.
R=${IBLIS_ROOT:-/home/claude/iblis-codex}; S=/home/claude/tools-lane10; cd $R || exit 1
git fetch -q origin main
BAD=$(git log --format=%B origin/main..HEAD | grep -v -E 'Co-Authored-By: Claude [^<]*<noreply@anthropic\.com>|Claude-Session: https://claude\.ai/code/session_' | grep -inE 'redivivus|jaenster|libd2|earlier reconstruction|lineage|clean-?room|claude|anthropic|chatgpt|assistant')
ADD=$(git diff origin/main...HEAD -- Source build docs | grep '^+' | grep -inE 'redivivus|jaenster|libd2|earlier reconstruction|lineage|clean-?room|claude|anthropic|// CONFLICT|STAND-IN')
[ -z "$BAD$ADD" ] || { echo "RESIDUE:"; echo "$BAD$ADD" | head; exit 1; }
CH=$(git diff --name-only --diff-filter=AMR origin/main...HEAD -- Source | grep -iE '\.(cpp|c)$' | paste -sd,)
HD=$(git diff --name-only origin/main...HEAD -- Source | grep -iE '\.h$' | xargs -r -n1 basename | sort -u | paste -sd,)
U="$CH"; [ -n "$HD" ] && U="$U,$(IBLIS_ROOT=$R python3 $S/users.py $HD)"
U="$U,$(python3 $S/planchanged.py)"
U=$(echo "$U" | tr ',' '\n' | grep . | sort -u | while read f; do [ -f "$f" ] && echo $f; done | paste -sd,)
[ -n "$U" ] || { echo "no units changed"; exit 0; }
echo "headers changed: ${HD:-none}; building $(echo $U | tr ',' '\n' | wc -l) units"
env -u TMPDIR WINEDEBUG=-all python3 tools/build.py -j "$(nproc)" --files "$U" 2>&1 | grep -E 'NOT_ALL_EQUAL|COMPILE_ERROR|MISSING|not all equal' | tail -20
