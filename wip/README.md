# Lane 3's working files for 0x6BD230 and 0x402A90 (not for merging)

This branch is main plus: the typed declaration and call of `sub_006BD230_AddCode` in Excel.cpp, the candidate
bodies below, and one script. Lane 3's notes are in `lanes/lane3.md` on the coord branch (0x6BD230: notes (8)-(12)
under Claimed; 0x402A90: under Questions).

## The script

    unset TMPDIR
    python3 wip/swapfn.py Source/Fog/Src/Excel/Excel.cpp 0x006BD230 246 wip/6BD230/baseline_244.cpp
    python3 wip/swapfn.py Source/Fog/Unknown_00402820.cpp 0x00402A90 70 wip/402A90/size_as_high_half.cpp

It puts the candidate into the unit (replacing the definition under the marker, or before the gen include when the
function is borrowed), compiles the unit with its own flags plus `/FAs`, prints the size, the compiler's frame
symbols for the function (`tvNNN = offset` is a compiler temporary with a frame slot) and the instruction diff
against the original, and restores the unit. It writes nothing under `out/`. A few seconds per try.

## 0x6BD230

- `6BD230/baseline_244.cpp`: 244 of 246 bytes. Every byte is the original's except `push ecx` after the prologue and
  `mov esp,ebp` before `pop ebp` (and the loop's alignment nop, which follows from the one byte).
- The missing slot is [ebp-4]. Nothing in the original reads or writes it.
- The baseline's frame symbols are `tv201 = 8 | _pLink$ = 8 | _nKey$ = 12`: the compiler already has a temporary
  with a slot and no reference (the count, shared by `nHigh = pLink->count` and `pLink->count - nLow`), and it sits
  in pLink's home. The original is that temporary at -4, which happens when something else holds [ebp+8] across the
  search at the time slots are given out.
- `6BD230/slot_with_pointer_252.cpp`: the same with a real occupant of [ebp+8] (`tv201 = -4 | tv207 = 8`), to see
  the mechanism. The occupant is visible there (252 bytes).

## 0x402A90

- The original: read base, read ppBase, read size, store, read pSize, store.
- `402A90/plain_locals.cpp`: what every plain form gives (ppBase, base, pSize, store, size, store).
- `402A90/size_as_high_half.cpp`: the size read as the high half of a 64-bit view of the struct. The second half is
  then the original's; only the first two reads are swapped. It shows the mechanism (the compiler evaluates the
  heavier operand of each store first) and is not a proposed source.
