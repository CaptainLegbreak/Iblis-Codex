# Lane 9

Written by lane 9 only. Newest entries at the top of each section; delete what is done.

Owns the renderers and D2Hell (`Source/D2Gfx`, `D2Direct3D`, `D2DDraw`, `D2Gdi`, `D2Glide`, `D2Hell`) and the repo-wide
1.10-address names. New chat, reopened 2026-11-26 11:57 PT (from lane 6, which held these modules since 2026-11-25).

## Status
- 12:45 PT: baseline on #429 VERIFIED (identical, 14,922 placed, 0 not all equal). lane9/names-110-d2game pushed, full
  build running (its first build had six units clash with second bodies under the 1.10 names; fixed, see the note for
  lanes 5 and 7). lane9/names-110-d2common built next. Then 0x4F82D0, then 0x6B38A0 (both back from lane 6).

## Claimed
- **0x004F82D0 CMNSUBTILE_DrawBlendVisTile** (D2Gfx/SRC/Window.cpp, `__assume`): back from lane 6, starting from its
  reading in lane6.md (plain sibling form 533 / 532 B, one priority step short: `p` 427 vs the clip position 420 in round
  1; `c2force --prio 1:p:-8` is equal).
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

## Questions

## Notes for other lanes
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
