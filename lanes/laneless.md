# Laneless (borrowed functions)

Written by the laneless chat only. It works on the 9 borrowed functions across lanes, with the user's approval.
Nothing here is ready to merge yet.

## Status

- 2026-11-24 00:30 PT: no match yet. Two near versions and a faster search tool are on this board.
  - **Tool: `lanes/tools/vbatch/`** compiles dozens of variants of one function in a single build of its real unit
    and ranks them against the original (about 4 s for 40 variants of 0x5EDC50 in AiThink4.cpp); `greedy.py`
    searches a template in the coordinator's `<<{...<<ALT>>...}>>` syntax with it. See its README. Lane 7 and
    the coordinator's overnight search can use it as is.
  - **0x6BD230** (lane 3/7 notes): `lanes/vsearch/006BD230-near.cpp` has the original's registers and layout
    (pLink in ebx, the realloc size from `lea esi, [eax + 64]`); only the unused `push ecx` slot is missing.
    What fixed the registers: the entries pointer read into a local at the top of the outer loop, the inner loop
    written `for (nHigh = pLink->count; nLow < nHigh; )`, and the grow test as `if (pLink->unk_04 <= pLink->count)`.
  - **What makes an unused 4-byte slot** (found on the verified 0x458DC0 AUTOMAP_RevealRoomObjects, which has
    one): its slot goes away when the inlined `AUTOMAP_CheckFlagEx` (two `return`s) in `if (...) continue;` is
    written out by hand, and stays when only the other call is. A single-return (`?:`) version of the helper
    gives no slot; a version returning through a local does. In small functions without register pressure no
    slot appears. So the slot is the result temporary of an inlined multi-return function used in a condition,
    under register pressure. For 0x6BD230 that points to the search or a compare written as such a helper; about
    60 shapes tried so far (compare helpers, grow-test helpers, found-flag helpers by pointer and by reference,
    helpers returning -1 or the index) didn't produce it inlined. One non-inlined helper did produce the slot.
  - **0x5EDC50** (D2Game AiThink4.cpp, between 0x5EDC40 and 0x5EDF70): `lanes/vsearch/005EDC50-near.cpp`, 789/791.
    The seed rolls need helpers that pass the halves by reference (as `SEED_RollPercentageAgain` does), with
    the `% 20` in the call arguments, so the first roll of a pair isn't written back. Left: the ecx/edx swap of
    the two tick-field loads, the first X's -40 folded into the quotient, and the order of the +-30 term.
  - **0x4A4AD0** and **0x677880**: greedy runs on simple groups didn't move them; nothing new beyond lanes 1 and 7.

## Notes for other lanes

- **Lane 7:** all of the above is yours to use; I'm not holding any of the 9. Tell me here if you'd rather I stay
  off one.
