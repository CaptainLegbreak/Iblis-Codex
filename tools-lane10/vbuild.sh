#!/bin/bash
# Full Iblis-Codex build; on "matches the original" record the exact source tree that passed.
# usage: verify.sh [repo] [log]
REPO=${1:-/home/claude/iblis-codex}; LOG=${2:-$REPO/out/verify.log}
cd "$REPO" || exit 1
TREE=$(tmp=$(mktemp -u); GIT_INDEX_FILE=$tmp git add -A >/dev/null 2>&1 && GIT_INDEX_FILE=$tmp git write-tree; rm -f $tmp)
env -u TMPDIR WINEDEBUG=-all python3 tools/build.py -j "$(nproc)" > "$LOG" 2>&1; rc=$?
TREE2=$(tmp=$(mktemp -u); GIT_INDEX_FILE=$tmp git add -A >/dev/null 2>&1 && GIT_INDEX_FILE=$tmp git write-tree; rm -f $tmp)
if [ $rc -eq 0 ] && grep -q "matches the original" "$LOG" && grep -q "placed \([0-9]*\) of \1 verified" "$LOG" && grep -q " 0 not all equal" "$LOG" && ! grep -qE "NOT_ALL_EQUAL|COMPILE_ERROR|MISSING_GEN" "$LOG" && [ "$(grep -oE 'borrowed code [0-9,]+ B in [0-9]+ functions' "$LOG" | grep -oE '[0-9]+ functions' | cut -d' ' -f1)" -le "${BORROW_MAX:-9}" ] && [ -n "$TREE" ] && [ "$TREE" = "$TREE2" ]; then
  echo "$TREE $(date -u +%FT%TZ)" >> "$REPO/out/.verified_trees"; echo "VERIFIED tree $TREE"; tail -1 "$LOG"
else
  echo "NOT VERIFIED (exit $rc; tree changed during build: $([ "$TREE" = "$TREE2" ] && echo no || echo yes))"; grep -E "not all equal|placed|borrowed|sha256|NOT_ALL_EQUAL|COMPILE_ERROR" "$LOG" | tail -8; exit 1
fi
