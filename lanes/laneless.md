# Laneless (borrowed functions)

Written by the laneless chat only. It works on the 9 borrowed functions across lanes, with the user's approval.
Nothing here is ready to merge yet.

## Status

- 2026-11-24 01:50 PT: still no match. New results, so nobody repeats them:
  - **0x677880:** declaration order doesn't matter. 60 random orders of all 27 locals (hoisted C-style) compile
    byte-identical to each other: same length as the original (4232), 308 differing lines. The differences are
    register choices as well as stack slots (about 210 of the 290 changed lines aren't just a different
    `[ebp - N]`), so it isn't a slot permutation that declarations could fix.
  - **0x6BD230, the unused slot:** 43 verified functions have one (an unused `push ecx` slot, no `[ebp - N]`
    use), for example 0x55BF30, 0x5531E0, 0x573040, 0x458DC0. In all of them it's the result of an inlined
    null-checking test (`UNIT_HasFlag`, `p ? p->f : -1`, `CheckFlagEx`), kept as a value (`and eax, 1` /
    `je`) rather than folded into a `test`. 0x6BD230 has no such value test, and none of these produced the
    slot (about 90 more shapes):
    - those helpers at each condition (both asserts, the grow test, the inner compare, the memmove test);
    - ternaries on pLink;
    - memcpy through address-taken locals;
    - a local copy of nKey;
    - asserts written as inline functions;
    - search helpers that return -1 for "found";
    - goto-free forms of the loop (they also break the registers: only the `goto found` form keeps them).
    VC8 won't inline an accessor called in the outer loop's head (entries or count), and that's the only
    place a slot appeared (from the real call's spill).
- 2026-11-24 01:15 PT: still no match. Tried and ruled out, so nobody repeats them:
  - **0x679C80:** 5 random-restart greedy runs over 14 groups all end at the same 447/450 (one scratch-register
    tie: eax vs ecx for the first Y shift). Not moved by comparison forms, union layouts, a start-point pointer,
    point-advance helpers, C-style declarations in any of 41 orders, compiler options (/Ox /Ot /Ob1 /G7 /arch /fp
    /GF /Gs), or 0-15 extra declarations in the unit.
  - **0x6BD230:** no slot from cached-count locals, found-flag helpers by pointer or reference, null-checking
    accessors (VC8 won't inline them in this function), memmove declared noalias/restrict, or 4-byte local aggregates
    (VC8 removes those entirely). The slot appears only when a value really is spilled.
  - **0x4F8B80 (lane 7's WIP, 580/561):** VC8 rematerialises the nL21/nL12 loads where the original spills them;
    moving aLight to function scope doesn't change that. The original's frame is 8 bytes larger.
- 2026-11-24 00:55 PT: **0x679C80** is at 447/450 with the original's frame and stack layout
  (`lanes/vsearch/00679C80-near.cpp`, lane 7's was 456/450). The key was reading tPoint through a 32-bit
  view (`(unsigned short)(dw >> 16)` for Y): with a plain struct VC8 keeps an extra stack copy just to read .Y.
  Left: one scratch-register choice in the first point comparison (eax vs ecx), and every ecx/edx swap after it.
  Declaration count in the unit doesn't change it (tested 0-15 extra declarations). 0x5EDC50 is unchanged at
  789/791; its two left differences (the folded -40 and the order of the +-30 term) didn't move under any
  expression, type or statement-order rewrite, or with 0-15 extra declarations in a minimal unit.
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
