# Lane 9

Written by lane 9 only. Newest entries at the top of each section; delete what is done.

Owns the renderers and D2Hell (`Source/D2Gfx`, `D2Direct3D`, `D2DDraw`, `D2Gdi`, `D2Glide`, `D2Hell`) and the repo-wide
1.10-address names. New chat, reopened 2026-11-26 11:57 PT (from lane 6, which held these modules since 2026-11-25).

## Status
- 2026-11-27 03:05 UTC: h, locals, moo in (#458, #459). Building: names-d2game-verbs2 (verbs regenerated on #459) and params-d2game-tail (D2Game unused stub parameters, bTimedEvents, the join check nGameId/nVersion; a1/v12 295 -> 244 alone).
- 2026-11-27 02:45 UTC: names-d2game-h conflicts with #457 (Skills.cpp); regenerated as -h2 on #457 (131 includers compile equal), full build running. locals-d2game, names-d2game-moo, -verbs merge cleanly onto #457.
- 2026-11-27 02:17 UTC: names-d2game-h and locals-d2game Ready; names-d2game-moo (17 D2MOO names) building. D2Game placeholders left after these: about 170 a1/v12 (packet-struct fields, unused stub parameters, save flags D2MOO leaves unnamed) and 54 bare sub_<VA> definitions D2MOO has no note for.
- 2026-11-27 01:50 UTC: every D2Game folder and top-level unit is in (#447-#452). Now D2Game.h / D2GameFuncs.h (lane9/names-d2game-h, building).
- 2026-11-27 01:03 UTC: a2, c2 in (#449). b3 conflicts with #450 (a2q7.cpp, a2q8.cpp): reposting as -b4 (unit builds equal, a1/v12 531 -> 437 alone), full build running. e2 still merges cleanly.
- 2026-11-27 00:32 UTC: params-d2game-d (#447) and glide-spans-2 (#448) are in. params-d2game-b2 now conflicts with #448 in MonsterUnique.cpp: reposting as -b3; a2 and c2 still merge cleanly. params-d2game-e (top-level units) is building.
- 2026-11-27 00:00 UTC: glide-spans-2 and params-d2game-d Ready; both, and a2/b2/c2, merge cleanly onto #445. a2/b2/c2 full builds running.
- 2026-11-26 23:35 UTC: rebuilding glide-spans and the D2Game naming branches on #443. Next: D2Game.h (38 placeholder parameters, 91 sub_<VA> declarations with names.csv names) after these merge; lane 5, tell me if you have that header in flight.
- 14:20 PT: 1.10-address names done (54 -> 0, #435). decls-renderers-2 Ready; names-spritevalidate in its full
  build. Both forcing rows parked and offered to lane 7 (Questions). Waiting on the coordinator for lane 9's next work.

## Claimed
- **D2Game's names (the coordinator's 14:40 assignment): `a1`/`v12` parameters and locals and `sub_<VA>` functions,
  one branch per folder.** Lane 5, skip these folders: **MISSILES, INVENTORY, DEBUG, ITEMS** (built, lane9/params-d2game-a) and **Ai,
  MONSTER, OBJECTS, Quests** (lane9/params-d2game-b), **UNIT, PLAYER** (lane9/params-d2game-c), **SKILLS, GAME** (lane9/params-d2game-d), D2Game's top-level Unknown_*.cpp units (lane9/params-d2game-e2), **D2Game.h and D2GameFuncs.h** (lane9/names-d2game-h), D2Game's sub_<VA> definitions that D2MOO's 1.14d notes name (lane9/names-d2game-moo); D2Game's tail outside Quests/ and OBJECTS/ (lane 7's), one folder at a time (now). Parameters take the name the function's own
  definition gives that position, else D2MOO's; definitions take D2MOO's names; `sub_<VA>` functions take
  names.csv/D2MOO names or `sub_<VA>_<Verb>` from the body.
- **0x004F82D0 CMNSUBTILE_DrawBlendVisTile** (D2Gfx/SRC/Window.cpp, `__assume`), parked again with lane 6's reading
  confirmed: the plain sibling form is 533 / 532 B, and in round 1 the clip block (`pNextSrc` .. `nLength`) is one
  block with w=2, K=15: the clip temporary gets 14 x 2 x 15 = 420, `p` gets 427 (+120 there). The `__assume` form wins
  by adding a 16th candidate to that block (a second web of nPosX): 448 against 435. So the plain source needs one
  more candidate referenced in that block, or 8 less for `p` elsewhere. Tried today, all 533 B / 219 diffs unless
  noted: nLeft/nRight as compound `-=` from the globals, nPosX built in two statements, nPosX first, the globals in
  named locals, `nX + (int)p - (int)pDst`, a copy of p for the run (`pRun`), the clamps duplicated inline,
  `-nPosX + global`, `x < 0 ? 0 : x` (221), the count clamp as a ternary; worse: if-clamps (513 B), the negation
  first or as `pDst - p - nX` (527 B), nRight before nLeft (534 B), a per-branch row cursor (543 B).
- **The 1.10-address names (78 names, 374 uses on #429, all in D2Game, D2Common and StandIns).** Plan, one line per
  name with the evidence: [names/v110-d2game.tsv](names/v110-d2game.tsv) (63) and
  [names/v110-d2common.tsv](names/v110-d2common.tsv) (15). How the new names were chosen:
  - **The address already has a name in names.csv (55):** d2moo, inferred or blizzard. Mostly the 1.10 spelling
    survives only in callers' private prototypes and calls; a few definitions still carry it. All take the names.csv
    name.
  - **D2MOO names only by address (11):** `sub_<1.14d VA>_<Verb>`, the verb from D2MOO's body, e.g.
    D2GAME_DropTC_6FC51360 -> sub_0055A6D0_DropTC, sub_6FDAA880 -> sub_006793E0_FindFreeDirection. names.csv follows.
  - **D2MOO has an address-free name (2):** sub_6FCF2110 -> AIUTIL_FindAiTarget (0x5DD7F0), sub_6FC7D260 ->
    PLAYERPETS_RemovePet (SkillBar.cpp's prototype; names.csv's 0x5750E0).
  - **Statics with no body of their own in 1.14d (5):** D2GAME_GetMonsterBaseId (three units inline it),
    EVENT_GetTimerListHead (Event.cpp, which already has a second inline of that name: compared first, one goes if the
    bodies agree), and OutPlace.cpp's three link-coordinate placers as DRLGOUTPLACE_PlaceLinkedCoord / ...Centered /
    ...Far.
  - **Globals (4):** hGameArray_6FD447F8 -> ghGameArray; dword_6FD4581C / dword_6FD45820 -> gnGlobal_00883D3C /
    gnGlobal_00883D40; gnPeakMemoryUsageInLast10s_6FD45828 goes in favour of the `static unsigned int
    gnPeakMemoryUsageInLast10s; // 0x00883D48` each of the three units already defines beside it.
  - D2GAME_Return1_6FC41900 is one spelling for two functions: sub_0052DAF0_Return1 (CCmd.cpp) and
    sub_00564CA0_Return1 (PlrSave.cpp, Clients.cpp).
  - **Branches:** one per module, `lane9/names-110-d2game` and `lane9/names-110-d2common` (StandIns go with the
    module of the function they stand in for), every unit of the module built, plus a full build.

## Ready
- lane9/params-d2game-tail2 509dbbad (on names-d2game-verbs2; merge after it): ACT2Q4_GetAndUpdatePalaceNpcState's
  out-parameter pContinueAi (1 when the quest leaves Jerhyn to the normal AI; its caller's bContinueAi), and
  pFreeStackCount (D2MOO's name) in SUNITNPC.CPP's second copy of the store stack search. Merges cleanly onto #461 and
  with params-d2game-tail. auditguard against its base no count rose. Full build: Game.exe identical, tree
  f59334d3687562df58c4de973b8b567ad4b024cd, borrowed code / data 5,424 / 261 B.
- lane9/names-d2game-verbs2 74d5b6cc (on #459): thirty-seven D2Game placeholder stubs and accessors take sub_<VA>_<Verb>
  names from their bodies (_Nop, _Return0/_Return5/_Return43, GetWaypointData, GetMonStats2Record, ...); exported
  functions keep theirs. auditguard no count rose; merges cleanly onto #460. Full build: Game.exe identical, tree
  a54bd6a14ed7030628a6fe267934c7c74be7e0ca, borrowed code / data 5,424 / 261 B.
- lane9/params-d2game-tail 087baef3 (on #459): D2Game: nUnused1.. for the Debug.cpp and Game.cpp stubs' unused
  parameters, bTimedEvents for the event dispatchers' flag (D2MOO's name), nGameId/nVersion for CCMD_CanClientJoinGame
  (from D2MOO's caller). a1/v12 295 -> 244 alone; auditguard no count rose; merges cleanly onto #460 and with verbs2.
  Full build: Game.exe identical, tree c0ee6925f17c6438ad75aac9dbd5f65e473f51f8, borrowed code / data 5,424 / 261 B.
- MERGED (as -h, #458) lane9/names-d2game-h2 974efeca (on #457): names-d2game-h regenerated on #457: D2Game.h, D2GameFuncs.h placeholder
  parameters; names.csv names for seventeen sub_<VA> declarations, renamed in the 23 units that call them. a1/v12
  377 -> 341 alone; auditguard no count rose; 131 includers compile equal. Full build: Game.exe identical, tree
  516404c0f4df65c96a2715fab5146f130b12e405, borrowed code / data 5,424 / 261 B.
- WITHDRAWN (stacked on moo, which merged as a new commit; replaced by -verbs2) lane9/names-d2game-verbs c798910a (on names-d2game-moo, so merge it after that one): thirty-seven D2Game placeholder
  stubs and accessors take sub_<VA>_<Verb> names from their bodies (_Nop for the empty ones, _Return0/_Return5/_Return43,
  GetWaypointData, GetMonStats2Record, ...); exported functions keep their names. auditguard against its base: no count
  rose. Full build: Game.exe identical, tree b33c0c3f92c2914e11cfd4c64b0843b150cd6c83, borrowed code / data 7,677 / 261 B.
- MERGED (#459) lane9/names-d2game-moo e53ec740 (on #455): seventeen D2Game placeholder functions take the name D2MOO's 1.14d note gives
  their address (AITHINK_Fn000, ACT3Q3_SpawnGidbinnBoss, ITEMS_RollLegacySetItem, MONSTERREGION_SpawnMonsterGroup, ...),
  in source, units.json, functions.json, data_plan.json and names.csv. Also touches lane 1's Unknown_00463720.cpp and
  UNIT/Monster.cpp and lane 8's Inventory.cpp, Items.cpp, Units.cpp (0x463720 is ITEMS_CheckUnitFlagEx). Merges cleanly
  onto #456. auditguard no count rose. Full build: Game.exe identical, tree c4b41e5dc9a2cf5a7a412bf7bed51538f5af0c6f,
  borrowed code / data 7,677 / 261 B.
- MERGED (#459) lane9/locals-d2game 6b5f2c2d (on #455): D2Game: placeholder locals passed to calls take the callee's parameter name
  (out-parameters `&a5` into `pItemStatus` -> nItemStatus), plus bIdle, nParam2Value/nParam3Value, nResult by hand;
  6 units, none shared with names-d2game-h. auditguard no count rose. Full build: Game.exe identical, tree
  5325f7d7a0fccf5c727726dfd7e9fbfa96db451b, borrowed code / data 7,677 / 261 B.
- WITHDRAWN (Skills.cpp conflict with #457; replaced by -h2) lane9/names-d2game-h 97603fd4 (on #453): D2Game.h, D2GameFuncs.h: placeholder parameters from the definitions and
  D2MOO; names.csv names for seventeen sub_<VA> declarations, renamed in the 23 units that call them (the 48 left are in
  Notes). a1/v12 387 -> 351 alone; auditguard no count rose; merges cleanly onto #455. Full build: Game.exe identical,
  tree 7c933685309edf6baa94c1ed5f270cdd9f85d543, borrowed code / data 7,677 / 261 B.
- MERGED (as b3, #451) lane9/params-d2game-b4 8546d082 (on #450): D2Game Ai, MONSTER, OBJECTS, Quests: placeholder parameters and names.csv
  callee names (regenerated on #450). a1/v12 531 -> 437 alone; auditguard no count rose. Full build: Game.exe
  identical, tree 69e218c9d3ea14d90378f750c49b6850a1bdc006, borrowed code / data 7,923 / 261 B. Shares no file with e2.
- WITHDRAWN (a2q7.cpp, a2q8.cpp conflict with #450; replaced by -b4) lane9/params-d2game-b3 06f2fac6 (on #448): D2Game Ai, MONSTER, OBJECTS, Quests: placeholder parameters and names.csv
  callee names (b2 regenerated on #448). a1/v12 628 -> 534 alone; auditguard no count rose. Full build: Game.exe
  identical, tree 3c000ce89efee35e94f1a253160f48cf658e78fd, borrowed code / data 7,923 / 261 B.
- MERGED (#452) lane9/params-d2game-e2 83cb7652 (on #448): D2Game's 13 top-level Unknown_*.cpp units: the same naming. a1/v12
  628 -> 578 alone; auditguard no count rose. Full build: Game.exe identical, tree
  c6d7bfe007ef3ac458697b826f276e33620b37e7, borrowed code / data 7,923 / 261 B.
- MERGED (#448) lane9/glide-spans-2 bb945f89 (on #443): glide-spans rebased (glCore.cpp and four others: prototypes main's
  D2Glide.h now holds are dropped from the moved code). auditguard no count rose. Full build: Game.exe identical,
  tree 504165c957670f8cd2aad791ce7cda32a325d5df, borrowed code / data 7,923 / 261 B.
- MERGED (#447) lane9/params-d2game-d 36bcb08b (on #443): D2Game SKILLS, GAME: placeholder parameters in prototypes and
  definitions from the definitions and D2MOO, parameters passed on unchanged take the callee's name, names.csv names
  for sub_<VA> callees the unit declares; Clients.cpp's SKILLS_ExecuteSkill declaration gets its address marker.
  a1/v12 892 -> 779 alone; auditguard no count rose. Full build: Game.exe identical, tree
  c9bd8942f00b4b8627ddcfb632139d7e5645508c, borrowed code / data 7,923 / 261 B.
- MERGED (#449) lane9/params-d2game-a2 77b84dae (on #443): D2Game MISSILES, INVENTORY, DEBUG, ITEMS: prototype parameter names from
  the definitions and D2MOO. a1/v12 892 -> 869 alone; auditguard no count rose. Full build: Game.exe identical, tree
  a062956e36bc3547455acc767abbcb2ffaaec5b9, borrowed code / data 7,923 / 261 B.
- WITHDRAWN (MonsterUnique.cpp conflict with #448; replaced by -b3) lane9/params-d2game-b2 23aa5a93 (on #443): D2Game Ai, MONSTER, OBJECTS, Quests: the same naming plus names.csv names
  for sub_<VA> callees the unit declares. a1/v12 892 -> 798 alone; auditguard no count rose. Full build: Game.exe
  identical, tree 3588394561ab58b3743a6f8bbc4834c0597398e6, borrowed code / data 7,923 / 261 B.
- MERGED (#449) lane9/params-d2game-c2 4ed51fe3 (on #443): D2Game UNIT, PLAYER: the same; PlrMsg, PlrSave and PlrTrade keep three
  callee spellings D2Game.h declares or that clash on return type. a1/v12 892 -> 818 alone; auditguard no count rose.
  Full build: Game.exe identical, tree 94657e88995b1387c587db252f419ce6db099c43, borrowed code / data 7,923 / 261 B.
- The five lane9 D2Game/D2Glide branches touch disjoint files and each merges cleanly onto #445.
- WITHDRAWN (conflicts with #441; replaced by the -2 / d branches above) lane9/params-d2game-c 1ccf64af (on #439): D2Game UNIT, PLAYER: the same naming (definitions'/D2MOO's parameter
  names; parameters passed on unchanged take the callee's name; names.csv names for sub_<VA> callees the unit itself
  declares). auditguard no count rose. Full build: Game.exe identical, tree 60312fd861ed667fb18d90861620112566073147,
  borrowed code / data 8,373 / 261 B.
- WITHDRAWN (conflicts with #441; replaced by the -2 / d branches above) lane9/params-d2game-b 492ae490 (on #439): D2Game Ai, MONSTER, OBJECTS, Quests: the same naming as params-d2game-a
  (definitions' or D2MOO's parameter names, the Raven walk's two by the arguments they become, names.csv names for
  sub_<VA> callees; ObjMode.cpp keeps its second spelling of 0x620510). a1/v12 1,747 -> 1,482 alone; auditguard no
  count rose. Full build: Game.exe identical, tree 37b84929ceee44e2b1310ccc37fb9c941837b3c8, borrowed code / data
  8,373 / 261 B.
- WITHDRAWN (conflicts with #441; replaced by the -2 / d branches above) lane9/params-d2game-a a64d4e0a (on #439): D2Game MISSILES, INVENTORY, DEBUG, ITEMS: Hex-Rays parameters take the
  name the function's own definition gives that position, else D2MOO's (by name or its 1.14d notes); a few named by
  use (nTargetFlags/nPathFlags, bRecharge; the empty debug stubs' nArg1..); callees spelled sub_<VA> take names.csv's
  name; 0x55E9A0's definition takes names.csv's sub_0055E9A0_Return0, and names.csv's 0x564CA0 row returns to its
  exported definition's spelling. a1/v12 1,747 -> 1,661; auditguard no count rose. Full build: Game.exe identical,
  tree 37a90c100edbb65c652c089f8b3bb337e355812f, borrowed code / data 8,373 / 261 B.
- WITHDRAWN (conflicts with #441; replaced by the -2 / d branches above) lane9/glide-spans b53e11bb (on #435): eight D2Glide functions move to the file whose `.\Src\gl*.cpp` span they sit in
  (lane 6's scan): 0x50A110 -> glSprite.cpp; 0x50DFE0, 0x50E330 -> glSmack.cpp; 0x50EAE0, 0x50EC40 ->
  glTextureCache.cpp (its unmarked copy of the evict goes); 0x50F570, 0x50F6D0, 0x50F750 -> glFloorCache.cpp, beside
  their callers; inferred names take the new file's prefix. All 12 D2Glide units equal; auditguard no count rose.
  Full build: Game.exe identical, tree dbcc1d94dd57b602413334d3e22b6b5cb453f8f5, borrowed code / data 8,373 / 261 B.
- lane9/names-110-d2game WITHDRAWN: superseded by names-110-d2game-2, merged in #432. Don't merge 03c35c9a2 (the old
  tip): its content is on main already.
- lane9/names-110-d2common WITHDRAWN: superseded by names-110-d2common-2, merged in #435.
- lane9/names-spritevalidate 1691211c (on #434): 0x6001F0 takes its Blizzard name D2CMPSpriteValidate in the
  renderer files (d3dSprite.cpp, D2DDraw Unknown_00511DF0.cpp, D2Gdi.h, gdiCore.cpp, glSprite.cpp), replacing three
  placeholder spellings; d3dSprite.cpp's second identical prototype goes (Unknown_00511DF0.cpp keeps its repeats: it
  differs without them). auditguard no count rose. Full build: Game.exe identical, tree
  35e9103119d4e2064874a185b7c50c176055b9b7, borrowed code / data 8,373 / 261 B.
- lane9/decls-renderers WITHDRAWN: superseded by decls-renderers-2 below.
- lane9/decls-renderers-2 09b67cd9 (on #434): functions D2Gdi, D2DDraw, D2Direct3D and D2Glide define that other
  files of the same module declared privately are declared once in the module header (2 + 7 + 13 + 41), with the
  private copies' spelling, and the copies go; ten private copies of declarations an included header already had go
  too. Every includer of the four headers builds all equal; kept private where a unit differs or doesn't include the
  header (listed in the commit). auditguard no count rose. Full build: Game.exe identical, tree
  ea7c98399e6a44fbc1bc5adda75660781a8b7a7e, borrowed code / data 8,373 / 261 B.

## Questions
- **Lane 9, after D2Game's names (02:17 UTC):** what's left in D2Game is the tail (about 170 a1/v12 that need reading
  each body, 54 bare sub_<VA> without a D2MOO note, 48 header sub_ spellings waiting on D2CommonApi.h). I'll keep
  working that tail one folder at a time with sub_<VA>_<Verb> names from the bodies unless you'd rather point me at
  another module's placeholders (D2Common 35, D2Client 6 a1/v12 left) or something else.
- **Coordinator / lane 7: lane 9's two forcing rows are parked and handed to lane 7** (its job for parked rows), with
  the readings above (0x4F82D0) and here (0x6B38A0). **0x6B38A0 D3DCORE_CopySurface (d3dCore.cpp, identical
  arms):** the plain loop is 267 / 267 B, 18 diffs, all register choice. Round 1: pSrcBits 87 (+14 where it is set
  before the second Lock, +84 in the loop), the row counter 61, pDstBits 60; colouring order pSrcBits esi, counter
  edi, pDstBits ebx, where the original gives the counter esi, pSrcBits edi, pDstBits ebx. So the counter needs about
  27 more, or pSrcBits about 27 less; the arm's extra counter use in the loop is what does it now. Tried today, all
  18-21 diffs: the parameter as the counter (59), `while (n) { --n; ... }`, do/while under an if, `for (int ...)`,
  an int counter, `n-- > 0`, the two pointer steps swapped; a named source pitch is worse (276 B). Lane 9 has no
  other plain idea for either row; lane 7, they're yours if you take them.
- **Coordinator: lane 9's queue after that.** Done or Ready: the 1.10-address names (D2Game merged, D2Common Ready),
  module declarations (decls-renderers-2 Ready). Left in lane 9's modules: placeholders already argued as their own
  objects (Left in place), 7 emit helpers and 8 noinlines each shown needed, 13 bare `sub_<VA>` placeholders with no
  names.csv/D2MOO/Blizzard name (D2MOO has no renderers). Lane 9 can take another lane's names or join work, or a
  tools job; say which.

## Notes for other lanes
- **Lanes 2, 8 (D2CommonApi.h):** D2Game.h still declares 44 D2Common/Fog/D2Game functions under sub_<VA> spellings whose
  names.csv name the shared headers already declare with other types (e.g. sub_0063B2C0_First vs
  INVENTORY_GetFirstItem(D2InventoryStrc*), sub_0040B430_Alloc vs FOG_AllocPool). Renaming them means the D2Game
  callers take the shared declaration's types; I leave them for whoever moves D2Game onto D2CommonApi.h. Four more
  (CLIENTS_GetFirstClient, CLIENTS_SetWeaponSwitch, GAME_LockDebugGame, GAME_UnlockDebugGame) clash on linkage or
  calling convention with their own definitions in Clients.cpp / Game.cpp.
- **Lane 7 (0x5D3BA0) and lane 5:** on lane9/names-110-d2game, SkillAss.cpp's second, unmarked body of
  SKILLS_ApplyProgressiveLeechAndElementalDamage (it was spelled sub_6FCF5870, called only by 0x5D54B0
  SKILLS_FillKickDamage) goes, and 0x5D54B0 calls the marked 0x5D3BA0; the unit stays all equal. The same in
  MonsterMode.cpp (an unmarked __stdcall copy of 0x5A6DF0, called by 0x5A6FF0) and SCmd.cpp (an uncalled copy of
  0x53CDF0). D2Game.h's prototypes of CLIENTS_SetPlayerUnitAlive (now extern "C", as defined) and
  MONSTERAI_SetTargetOverride (returns int) match their definitions. Lane 5: your decls-d2game-2 and this branch
  both touch D2Game declarations; whichever merges second rebases, I'll take that if it's mine.
- **Lane 5 (D2Game) and lane 8 (D2Common):** the 1.10-name plans above rename in your files (63 names in D2Game, 15 in
  D2Common). If you disagree with a name, say so in your file and I'll drop or change it before posting. I'll build
  every unit of the module, so the declaration-sensitive units are covered.

## Left in place (from before, still parked)
- D2Gdi / D2DDraw DrawLine helpers (0x6C8DA0, 0x512A50) and their per-file copies: the callers want a register
  convention only a per-file static gives; probably a header static folded by the linker.
- 0x6B38A0 D3DCORE_CopySurface's identical arm: the plain form swaps esi/edi for the whole function.
- Kept noinline/emit helpers in the renderers (cache append statics, gdiCore's EmitCelClip, glSprite's 0x50A1E0
  helper, the cache EmitCallers): each unit differs without them.
- Unknown_006B7530.cpp, Unknown_006BBBF0.cpp (Bink player), D2Glide Unknown_0050F910.cpp: objects of their own.
- The two D2Hell list constructors are /O2; d3dCore.cpp's /EHsc is needed.
