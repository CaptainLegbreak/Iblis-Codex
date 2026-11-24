# Laneless (borrowed functions)

Written by the laneless chat only. It works on the 9 borrowed functions across lanes, with the user's approval.
Nothing here is ready to merge yet.

## Board check (for the coordinator)

The user asked the laneless chat to take board upkeep off the coordinator: every 30 minutes it posts here any
duplicate claims, quiet lanes, stale headers and questions waiting an hour or more. It decides nothing; every
call stays the coordinator's. This section is replaced at each check.

- **2026-11-24 09:32 PT**, main #356:
  - **Waiting:** `laneless/objmap-joins-1` (13 placeholder joins, verified on #354), posted at 09:30.
  - **Quiet:** lane 3, last post 51 minutes ago. Lane 7 is back (forcing constructs since 08:47).
  - **Future timestamp:** lane 8's top entry says 09:55; it was posted before 09:32.
  - **Object map** refreshed on #356: `lanes/tools/objmap/report-356.md`, 414 placeholder files, 175 clear
    leads.
- **Suggestions from the user's discussion**, for you to take or leave:
  1. Lane 10 could apply its own naming plans module by module (the call-site rename sweep), so rounds only
     merge them.
  2. For a stale or conflicting branch, post "rebase X onto main" and let the lane do it, rather than resolving
     it by hand.
  3. Answer open questions at the start of each round, so a lane isn't blocked through a whole round.

## Status

- 2026-11-24 09:30 PT: **Ready: `laneless/objmap-joins-1` e1279d27a**, on main #354 (9ec68ba89). 13
  placeholders -> 0. Each commit puts one placeholder file into the file the object map names as its clear
  owner, and every function of the joined unit builds equal. Full build: 0 not all equal; Game.exe identical
  (VERIFIED tree 2ddf88708ee93211e16bd7d208758d724f696722); borrowed data 1,041 B.
  - **The joins, by owner lane:**
    - lane 1: npcmenu.cpp <- Unknown_004B6DD0; UNIT/Player.cpp <- Unknown_00462D00; SKILLS/Skills.cpp <-
      Unknown_004C51D0.
    - lane 3: SBig.cpp <- Unknown_00421470.
    - lane 5: SkillAss.cpp <- Unknown_005D3BA0 and Unknown_005D3AC0.
    - lane 6: ComCallback.cpp <- Unknown_00446B30; FastCmp.cpp <- Unknown_0060D280; strtable.cpp <-
      Unknown_005271A0.
    - lane 8: DrlgWarp.cpp <- Unknown_0066AE70.
    - lane 9: glTextureCache.cpp <- Unknown_0050DB70; gdiCore.cpp <- Unknown_006C7C90 and Unknown_006C7CF0.
  - **Lane 9 and coordinator:** the two gdiCore commits touch the D2Gdi object question lane 9 asked about.
    Drop them if that went the other way; the other commits don't depend on them.
  - **How a join is done** (`lanes/tools/objmap/join.py`):
    - The placeholder's functions go in address order.
    - Its copies of functions the owner defines are dropped.
    - The owner's context copies of the moved functions are dropped.
    - Declarations the owner already has are dropped.
    - units.json is updated.
    - The placeholder's own flags are kept only if the owner's flags don't build it equal; none of these
      needed that.
    - The branch skips placeholders with planned data, and any placeholder a lane file or COORDINATOR.md
      names.
  - **tools/link.py** on this branch: 4 unresolved externals, all FOG_FreeServerMemory (0x40B480). It's
    referenced from units this branch doesn't touch (most of D2Common/D2Game), so it's probably the same on
    main. Coordinator, worth a look.
  - **Not joined:** 34 other clear leads fail to compile or to build equal as a plain move. The usual
    causes are conflicting private types and different flags. A lane can still take them by hand; the
    failures are in `lanes/tools/objmap/join-354.log`.
- 2026-11-24 05:40 PT: **overnight searches on the four claimed functions** (no match).
  - **Tool:** `lanes/tools/vbatch/mutbatch.py` compiles every one-mutation neighbour of the current best in
    one build of the real unit. It uses lane 7's mutation set without the `&&`/`||` swap (it crossed macro
    arguments and moved null checks behind the dereference) and without narrowing a local's type, plus a
    "fold a single-use local into its use" mutation.
  - **0x55A6D0** (Items.cpp, the existing body marked): 2256/2253 (was 2239), 320 -> 244 differing
    lines. The changes are all on the pick loop's index: `unsigned int nIndex`, the two compares against
    pTC->nTypes as `(int)nIndex`, and the final test as `(unsigned char)nIndex >= pTC->nTypes`. That
    last cast looks odd for source, so treat it as a lead.
  - **0x4F8B80** (lane 7's draft on main's Window.cpp, with the new CMNSUBTILE_ names): best 569/561 with
    the corner loads ordered nL22, nL12, nL11, nL21. The original keeps pTile, nX, the block pointer's
    offset, pDst, nBlockX/Y, an int bFlat (-0x38) and a byte nLight (own slot -0x4) in memory: 18 frame
    slots against our 16. That's more register pressure than any statement order gives, so it's likely
    a structural difference.
  - **0x5EDC50:** stuck at lane 10's 789/791. The `% 20` fold (`add edx, 2`) is robust. In a test unit VC8
    folds a following -40 into the quotient for every form of the expression and dividend I tried. It
    doesn't fold only when the dividend is a call's result, or under /O1 or /Os (which change the rest of
    the unit).
  - **0x5DD7F0:** mutations don't touch the block layout. The best valid run reached 291 differing lines,
    from 310.
- 2026-11-24 03:00 PT: **Claim (laneless), with the user's go-ahead:** 0x5EDC50, 0x5DD7F0, 0x4F8B80 and
  0x55A6D0, which lane 10 parked for its naming queue. Lane 7 keeps 0x677880, 0x62B5B0, 0x679C80 and 0x6BD230;
  lane 1 keeps 0x4A4AD0. Lane 7: 0x679C80's 447/450 version with the frame right is in
  `lanes/vsearch/00679C80-near.cpp`, if it helps. Matches come back as `laneless/<va>` branches.
- 2026-11-24 03:00 PT: **placeholder object map** (asked for by the user): `lanes/tools/objmap/` with
  `report-341.md`. For every placeholder file it ranks the files of the same module it most likely belongs to,
  scored on:
  - path strings;
  - call edges only that pair of files uses;
  - data that file defines;
  - sitting between two runs of that file, or next to one.
  Tested on main #339 against the five joins made since, its best candidate was the right file every time.
  On #341 it gives **180 clear leads** among the 450 placeholder files: lane 1 23, lane 3 34, lane 4 27,
  lane 5 18, lane 6 31, lane 8 18, lane 9 29. Each lane's section lists its files, clear ones first.
  - **All lanes:** take the clear leads in your section as your next joins. Each still has to build equal.
  - **Coordinator:** 32 files STATUS counts as whole have a placeholder sitting between two of their own runs.
    They're listed at the end of the report; those files most likely aren't whole yet.
- 2026-11-24 02:45 PT: **context-copy sweep on main #340** (asked for by the user), tool and results in
  `lanes/tools/sweep/`. It covers all 393 `// build: context` lines in the 160 non-LTCG units.
  - **The directive line itself never matters.** All 393 can go without changing any verdict: tools/build.py
    counts a function equal on its bytes even when an extra form is left over. So deleting the lines (as
    `lane4/context-sweep` does for 127) only lowers STATUS's "context copies" count; the copies stay in the
    source. Coordinator: you may want STATUS to count the copies rather than the lines, or keep the lines as
    labels.
  - **Copies that really can go: 8, all lane 1's.** The unit still checks equal with the copy deleted (a
    static one) or replaced by its prototype (an external one):
    - Unknown_004A6460.cpp 1722, 1795, 1814;
    - Unknown_004A43E0.cpp 1734, 1807, 1826;
    - UI/SkillDesc_004E72D0.cpp 58;
    - UNIT/Monster.cpp 600 (sub_0044BE50).
    Lane 1: a full verify decides.
  - **The rest:**
    - 284 are used and defined only in their file;
    - 71 change code when they go;
    - 30 name a symbol not defined in their file.
    By lane (used and defined only here / change code / not found): 1: 65/7/2, 3: 13/11/24, 4: 68/19/0,
    5: 97/8/2, 6: 14/11/2, 8: 17/12/0, 9: 10/3/0.
  - **Lane 2:** 49 helpers have context copies in two or more files (120 copies in all). They're the candidates
    for one shared inline in a header, which is how the original most likely had them. The most copied:
    - sub_0044BE50 (10 files), sub_00623C60 (5), SEED_RollRandomNumber (4);
    - in 3 files each: sub_SetPlayerAction, sub_J06_IntersectsAnyHoverRect, sub_GetPlayerDataOrNull,
      TEXT_ReadLine, Shl, MonStatsTxtRecord;
    - UNIT_HasFlag, TestMonStatsFlag and SEED_RollLimitedRandomNumberInline in 2 each.
    The full list is in results-340.json.
- 2026-11-24 02:35 PT: **0x5DD7F0** (lane 7's `lane7/005DD7F0-wip`, 1120/1084, 238 differing lines). Apart from
  the layout below, the body already has the original's shape: the three node loops and their spill slots
  line up instruction for instruction. What's left:
  - **Layout:** the original puts the "flag 0x40 not set" branch (the line-of-sight check, the bit-3 test and
    the vision toggle) out of line, after the first loop's inner `for (;;)`, and jumps back. Its then-branch
    falls straight into the join. The draft lays the else branch inline. Writing it as an inverted test, a
    goto chain, a `do { } while (0)` or an inline helper didn't move it. VC8 won't inline a helper that large
    into this function, and in a test build an inlined helper's blocks stay in place anyway.
  - **Registers:** ebx and edi are swapped all through the function. The original has pGame and then pNode in
    ebx, and pUnit and then the distance in edi.
  - **Frame:** 4 bytes smaller. The draft shares pRoom's slot with ppNode; the original doesn't.
  - The ebx/edi swap and the frame probably follow from the layout.
  - One real fix: the bit-3 test is a null-checking flag helper, `if (!p) return 0; return (p->nAiFlags >> n)
    & 1;`, compared `== 0`. That gives the original's `shr / and / cmp / sete` (the draft's `& 8` gives
    `not / and`).
  - A greedy run over 10 groups (declaration order, the nX/nY and nAct forms, the vision accessor, the
    min-distance compare) found nothing that changes the listing.
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
