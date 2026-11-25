# Laneless (borrowed functions)

Written by the laneless chat only. It works on the 9 borrowed functions across lanes, with the user's approval.
Nothing here is ready to merge yet.

## Board check (for the coordinator)

The user asked the laneless chat to take board upkeep off the coordinator: every 30 minutes it posts here any
duplicate claims, quiet lanes, stale headers and questions waiting an hour or more. It decides nothing; every
call stays the coordinator's. This section is replaced at each check.

- **2026-11-24 17:46 PT**, main #375:
  - **Quiet:** lane 2, last post 50 minutes ago. Everyone else has posted within 25 minutes.
  - **Review of #375** (one round): nothing to flag.
    - The one `noinline` hit is lane 10's prefix rename of an existing one (SOUNDINST_RefreshHint, 6d7a9f557).
    - Six functions crossed between D2Glide and D2DDraw (lane 9, 6e55e8edf). Each now sits in the module whose
      address run holds it: 0x50BEF0 and 0x50FD10 in D2Glide, 0x511660-0x512410 in D2DDraw.
    - sub_ names 23,442 -> 22,485.
  - **Object map** refreshed on #375: 249 placeholder files, 112 clear leads (`lanes/tools/objmap/report-375.md`).
- **2026-11-24 16:54 PT, test builds on 0x5EDC50 and 0x5DD7F0** (main #372, real units). All negative, so nobody repeats them:
  - **0x5EDC50 (789/791):** the -40 fold (`add edx, 2`) survived 25 more forms in AiThink4.cpp: the constant from a
    local, from `nX - 40` kept in a local, split across terms, cast, through inline helpers that take the base or the
    offset as an argument, and through five guarded random-range helpers (`if (nMax <= 0) return 0;` and similar).
    Every one gives the same 112 differing lines.
    - Flags: /O1, /Os and /Ob0 rewrite the whole function (510-990 B). /Ot, /Oy-, /Ob1, /GS-, /Op and /fp:precise
      change nothing.
    - Link-time code generation (/GL + /LTCG) still folds, and adds an `and esp, -8` the original doesn't have.
  - **0x5DD7F0 (lane7/005DD7F0-wip, 1120/1084):** /GL + /LTCG makes it worse, 1141 B and 321 differing lines against 238.
  - **Tool:** `lanes/tools/vbatch/ltlab.py` runs a batch of variants through /GL + /LTCG (see the vbatch README).
  - **0x5DD7F0's block layout isn't source order.** The original's out-of-line block (0x1B0-0x22A: the sight check,
    the bit-3 test and the vision toggle) sits in the first gap after the inner `for (;;)`'s back edge, `jmp 0x170`.
    Moving that code through a label to four other source positions (after the inner loop, after the `< 55` block, at
    the end of the first loop's body, at the end of the function) compiles byte-identical to the draft. So VC8 orders
    these blocks itself.
    - In the original, the "flag 0x40 set" branch falls into the join and the else is parked in that gap. In the draft,
      the set branch jumps over an inline else. Inverting the test, a default `bCheckCollision = 1`, a flag local and
      nested forms don't flip which branch falls through.
    - A greedy search over 11 control-flow groups (the flag block, the threat lookup, the first loop's header, the
      dead/min updates, nested collision test, inner-loop exit, the second loop as while/for/do, the tail) found
      nothing better than 310 from the default start or a random seed. Template: `lanes/vsearch/005DD7F0-wide.tpl`.
- **2026-11-24 17:43 PT, 0x5EDC50: 112 -> 13 differing lines from a declaration change** (main #374):
  - AITACTICS_WalkToTargetCoordinatesDeleteAiEvent (0x5DEE50) takes `unsigned int nX, unsigned int nY`. With that
    prototype VC8 no longer folds the first X's -40 into the quotient, which no expression form avoided.
  - The change is safe on its own. The function's body only copies nX and nY into the mode-change struct, and
    with the prototype changed in all three files that declare it, AiTatics.cpp and AiThink4.cpp still build equal.
  - With it, the +-30 term written `+ 30 * (bDirection ? -1 : 1)` (third call `(bDirection ? 1 : -1)`) and bCombat
    read before nTargetDistance give 786/791 and 13 differing lines: `lanes/vsearch/005EDC50-near.cpp`.
  - Left: the original forms the direction value as -30 * sign with `neg` and adds it. Here the sign test and
    `neg` land one roll apart, and one prologue store moves.
  - **For every lane:** a callee's parameter types change the caller's code where the body doesn't. When rewrites
    of a stuck function's body stop moving it, try its callees' prototypes (signedness, width), since a
    caller's arithmetic is done in the parameter's type.
  - Follow-up, all on #375, so nobody repeats them:
    - **0x5EDC50:** a greedy run over 6 groups on top of the 13-line version found nothing better. The groups
      were the two direction spellings, the field read order, bDirection's type and form, const or unsigned
      nX/nY, and the seed-half order.
    - **0x6BD230:** the callees' size types (memmove, memset, the pool realloc; int, unsigned, long), the
      realloc's size and nKey's type change nothing (35 variants, all 244/246 and 5 lines). No slot.
    - **0x679C80:** passing the point to PATH_GetDirections and/or sub_6FDAA880 as a packed `unsigned int`,
      and four ways of reading the halves, don't beat the near version (35 lines). Both packed gives 449/450 but
      37 lines; reading `.X`/`.Y` instead of the shift loses the frame.
- **Suggestions from the user's discussion**, for you to take or leave:
  1. Lane 10 could apply its own naming plans module by module (the call-site rename sweep), so rounds only
     merge them.
  2. For a stale or conflicting branch, post "rebase X onto main" and let the lane do it, rather than resolving
     it by hand.
  3. Answer open questions at the start of each round, so a lane isn't blocked through a whole round.

## Status

- 2026-11-24 14:53 PT: **Review of what landed on main from #352 to #368** (16 rounds, 566 files). From now
  on the laneless chat reviews each round instead of keeping join branches; see the next item.
  - **Rule checks pass:**
    - no new `volatile` or `#pragma optimize`;
    - no banned words anywhere in the tree;
    - no workflow chatter in Source/, README.md, docs/ or STATUS.md;
    - borrowed data down every round (1,114 -> 844 B).
  - **Coordinator, one judgment to confirm:** 15 `__assume` uses now sit behind `STORM_ASSUME` and
    `FOG_ASSUME` module macros (d0a47f83a), and status.py no longer counts a body that uses them as forcing.
    So part of STATUS's drop from 43 to 38 is a change of counting, not a removal. That's fine if those
    macros are believed to be the original's (release-build asserts and unreachable switch defaults).
    If they're only a home for the construct, the count should still show them.
  - **New `__forceinline` copies (net 218 -> 220):** lane 5's AiThink4.cpp split copied SKILLS_GetSkillsTxtRecord,
    AI_RollPercentage_005F0CD0 and MONSTERS_ValidateMonsterIdInline into Unknown_005EFB80.cpp. Each is now in
    two files: copies, not new constructs, but a header inline would serve both (lane 2's records work).
    InitFaultHandlerListInline (lane 9's D2Hell join) replaced an older `__forceinline`, so it's not new.
  - **104 functions moved across modules.** I spot-checked the biggest: the MCP connect object into
    D2MCPClient; Storm SCMD.CPP's 13 stubs at 0x6C7A60-0x6C8A40, which are D2Gdi addresses, into gdiCore.cpp;
    the end-of-.text static initializers in Storm placeholders into their D2Client owners. All are consistent
    with the addresses.
  - **Readability trend:**
    - `sub_<addr>` names 25,413 -> 24,270;
    - `_Shim` 60 -> 38;
    - address-named types (`T00xxxxxx`) 156 -> 34;
    - `unk0x` 2,830 -> 2,743;
    - `goto` unchanged at 600 (worth a look some time).
- 2026-11-24 14:53 PT: **Laneless join branches stop.** The lanes are doing these joins themselves (nine of mine
  landed through them), so `laneless/objmap-joins-7` won't be replayed again. If the coordinator doesn't take
  it, owner lanes can take these from it: Unknown_004B6DD0, Unknown_006C7CF0, Unknown_00462D00, Unknown_0060D280, Unknown_005271A0, Unknown_004C51D0, Unknown_005241A0, Unknown_00475C30, Unknown_0050CD40, Unknown_006BE190, Unknown_005C8BF0, Unknown_0051C7E0, Unknown_00477760, Unknown_0050C890, Unknown_00664530. `lanes/tools/objmap/join.py` still works for anyone.
- 2026-11-24 14:21 PT: **Ready: `laneless/objmap-joins-7` 4e73ed04b**, on main #367 (7de5c518c). It replaces
  objmap-joins-6, which conflicted with #367. 15 placeholders -> 0. Full build: 0 not all equal; Game.exe
  identical (VERIFIED tree e98822ff622e5e02bb4b5b7e65121cddee55244c); borrowed data 844 B (main's).
  - Since joins-6, nine of its joins landed on main through the owner lanes, and Unknown_005D3AC0 is now
    lane 5's, so all ten are out. Two new clear leads from the object map on #367 came in.
  - The joins: OverlayTbls.cpp <- Unknown_00664530.cpp; Unknown_0050BD30.cpp <- Unknown_0050C890.cpp; inv.cpp <- Unknown_00477760.cpp; Unknown_0051C760.cpp <- Unknown_0051C7E0.cpp; Unknown_005C8CA0.cpp <- Unknown_005C8BF0.cpp; Excel.cpp <- Unknown_006BE190.cpp; Unknown_0050BD30.cpp <- Unknown_0050CD40.cpp; View.cpp <- Unknown_00475C30.cpp; Unknown_00520DC0.cpp <- Unknown_005241A0.cpp; Skills.cpp <- Unknown_004C51D0.cpp; strtable.cpp <- Unknown_005271A0.cpp; FastCmp.cpp <- Unknown_0060D280.cpp; Player.cpp <- Unknown_00462D00.cpp; gdiCore.cpp <- Unknown_006C7CF0.cpp; npcmenu.cpp <- Unknown_004B6DD0.cpp.
- 2026-11-24 13:52 PT: **The borrowed functions re-tested in main #366's files.** Today's joins, splits
  and context-copy cuts changed their surroundings a lot: AiThink4.cpp lost about 100 functions to
  Unknown_005EFB80.cpp, and lane 2 cut the context copies to 3. Nothing moved. Every near version builds to
  the same bytes it did this morning:
  - 0x5EDC50: 789/791, 344 unmasked (lane 10's draft, with its seed and coordinate helpers carried from
    Unknown_005EFB80.cpp).
  - 0x5DD7F0: 1120/1084.
  - 0x4F8B80: 580/561.
  - 0x55A6D0: 2239/2253.
  - 0x677880: 4232/4232, 661 unmasked.
  - 0x6BD230: 244/246 (only the slot).
  - 0x679C80: my 447/450.
  So what blocks them is inside each function (its structure or types), not the file around it. Lane 7:
  that holds for the four you hold too, at least for the file changes so far.
- 2026-11-24 13:36 PT: **Ready: `laneless/objmap-joins-6` 262677184**, on main #365 (ef33aa543). It replaces objmap-joins-5 and
  files-joins-1, which both conflicted with #365; their joins are replayed here as one branch. 24 placeholders
  -> 0. Full build: 0 not all equal; Game.exe identical (VERIFIED tree 34636475d8d8a95b310cb395ad484aefd5b824f0); borrowed data 844 B (main's).
  - **Changes from those two branches:**
    - SBig.cpp <- Unknown_00421470 is gone: main did it.
    - Game.cpp <- Unknown_006CA9C0 is left to lane 4, as lane 3's note hands it over.
    - Everything else is as listed in the joins-5 and files-joins-1 entries below.
  - **Coordinator:** none of these join branches has been merged or mentioned on your board since the first
    one at 09:30, so I'm replaying them every round. If you'd rather not take them, say so here and I'll stop.
- 2026-11-24 13:20 PT: **Ready: `laneless/files-joins-1` 9f7bb9643**, stacked on `laneless/objmap-joins-5` (8d735419d),
  main #361. 6 more placeholders -> 0. Lane 10's file plans (lanes/names/files-*.tsv), strong and medium
  rows, tried as joins. Full build: 0 not all equal; Game.exe identical (VERIFIED tree 787bdb413f7bd026d7f6745a9278da9a5b54658f); borrowed data
  898 B (main's).
  - **From lane 10's plans:**
    - Game.cpp <- Storm/Unknown_006CA9C0. Lane 10: an end-of-.text static finalizer that belongs to Game.cpp,
      though it's filed under Storm. Lane 4.
    - Quests/a5q2.cpp <- Unknown_00588830; Quests/a1q3.cpp <- Unknown_00592090. Lane 5.
    - SRP/SRP.cpp <- Bnclient/Unknown_00528010 (lane 10's call, across modules). Lane 3.
  - **From the object map, carrying their planned data** (the join tool now moves a placeholder's definitions
    and its data-plan entry into the owner's):
    - D2Glide Unknown_0050BD30 <- Unknown_0050C890. Lane 9.
    - DATATBLS/OverlayTbls.cpp <- Unknown_00664530. Lane 8.
  - **Dropped:** PlrSave2.cpp <- Unknown_0056B180. It builds equal but raises borrowed data by 60 B (the
    moved data isn't placed). Lane 5: its data needs placing by hand.
  - Of lane 10's other strong and medium rows: 17 carry data (3 of those joined, with the object-map ones);
    the rest fail on compile or equality (lanes/tools/objmap/join-log.txt).
- 2026-11-24 12:09 PT: **Ready: `laneless/objmap-joins-5` 8d735419d**, on main #361 (ef7b4a195). It
  replaces objmap-joins-4 and the earlier ones. 20 placeholders -> 0. Each commit puts one placeholder file
  into the file the object map names as its clear owner, and every function of the joined unit builds equal.
  Full build: 0 not all equal; Game.exe identical (VERIFIED tree c96254a3bd78a300473a8d426a9750a8edb103b6); borrowed data 898 B (main's).
  - **Left out, because the owner lane does them itself:** Unknown_0066AE70 (lane 8's join-drlgwarp),
    Unknown_005D3BA0 (lane 5's skill-runs-2) and Unknown_005201E0 (lane 6's join-bnmessqueue). The lists
    below still name them; ignore those three.
  - **The 4 new joins:**
    - lane 4: UI/inv.cpp <- Unknown_00477760.
    - lane 6: BnMessQueue.cpp <- Unknown_005201E0; Unknown_0051C760 <- Unknown_0051C7E0.
    - lane 9: Unknown_005173EF <- Unknown_005173DF (D2Hell).
  - **The joins, by owner lane:**
    - lane 1: npcmenu.cpp <- Unknown_004B6DD0; UNIT/Player.cpp <- Unknown_00462D00; SKILLS/Skills.cpp <-
      Unknown_004C51D0.
    - lane 3: SBig.cpp <- Unknown_00421470; Excel.cpp <- Unknown_006BE190.
    - lane 4: GAME/View.cpp <- Unknown_00475C30.
    - lane 5: SkillAss.cpp <- Unknown_005D3BA0 and Unknown_005D3AC0; Unknown_005C8CA0 <- Unknown_005C8BF0.
    - lane 6: ComCallback.cpp <- Unknown_00446B30; FastCmp.cpp <- Unknown_0060D280; strtable.cpp <-
      Unknown_005271A0; Bnclient Unknown_00520DC0 <- Unknown_005241A0.
    - lane 8: DrlgWarp.cpp <- Unknown_0066AE70.
    - lane 9: glTextureCache.cpp <- Unknown_0050DB70; gdiCore.cpp <- Unknown_006C7C90 and Unknown_006C7CF0;
      D2Glide Unknown_0050BD30 <- Unknown_0050CD40; D2Hell Unknown_005173EF <- Unknown_005178E9.
  - **Lane 9 and coordinator:** the gdiCore commits touch the D2Gdi question lane 9 asked about, and the
    D2Hell commit its D2Hell grouping question. Drop them if those went the other way; the other commits
    don't depend on them.
  - **How a join is done** (`lanes/tools/objmap/join.py`):
    - The placeholder's functions go in address order.
    - Its copies of functions the owner defines are dropped.
    - The owner's context copies of the moved functions are dropped.
    - Declarations the owner already has are dropped.
    - units.json is updated.
    - The branch skips placeholders with planned data, and any placeholder a lane file or COORDINATOR.md
      names.
  - **tools/link.py:** still the 4 FOG_FreeServerMemory (0x40B480) unresolved externals, from units this
    branch doesn't touch.
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
