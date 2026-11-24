# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- `lane2/shim-trim-d2glide` (on #367, fully verified): glSprite called sub_0050A450_UploadSprite, a stand-in with a dummy body for 0x0050A450. The real GLSPRITE_UploadTexInfo is in the same unit, so the call now goes to it and the shim and its prototype go. 1 more marker removed (26 in all).
- `lane2/shim-trim-d2client`, `-d2common`, `-d2game`, `-d2cmp`, `-d2multi`, `-d2bnclient`: shim trim round 1, one commit per module on #367, each fully verified (Game.exe matches; 0 not all equal). Deletions only: 8 stale markers and 17 shims nothing calls. Per module: D2Client 4 markers + UnitMode's sub_004812E0_Shim; D2Common 6 shims (Items x4, Units, Unknown_0067B9C0); D2Game 6 shims (AiBaal, MonsterMode, Objects, PlrModes, Skills, SUnitDmg) + SUnitDmg's marker on an inline helper; D2CMP FastCmp's shim; D2Multi 2 shims (ChatDlg, ComCallback) + ChatDlg_004423B0's marker; D2BNClient grid's shim + BnDownload.cpp:334's marker. 25 markers removed in all. What stays, and the joins, are under Notes.
## Working on

22. **The shim trim** (coordinator's Answers). Round 1 is under Ready. Deletions only: 25 markers removed in all (8 stale markers, 17 uncalled shims). D2Direct3D, D2Win, D2Launch, D2Hell and Bnclient have nothing to remove: each of their shims changes its unit when it goes. Fog's 7 markers are lane 3's, so I am only listing them (see Notes). D2Glide's is under Ready. What's left in lane 2's range is shims whose units change without them, plus the joins and lane 3's Fog markers listed under Notes.
Records that two or more units define privately with the same text, moved into the shared header that owns their area. One branch per area; each is checked against all includers of the header before it is posted:
1. (done: fog-records-c)
2. (done: multi-records; char save file and ladder entry stay private, because adding them to D2MultiTypes.h flips CharSel)
3. (done: d3d-records)
4. (done: bn-messages)
5. (done: path-records)
6. (done: win32-system-2)
7. (done: win-popup)
8. (done: questlog-records)
9, 10, 12. (done: client-records-b)
11. Skipped: ChatDlg's D2CharSaveFileStrc is a 0x2000-byte view of the .d2s file that reads 0x18 as old flags; merging it with D2SaveHeaderStrc needs a union there. The ladder entry alone isn't worth a header.
21. (done as far as a rename goes: unit-views-a, unit-views-b; the rest is unit work, see unit-views-b's line) **The `struct Unit` / `Unit*` views** (coordinator's decompiler-style list): about 30 files use a private, padded `Unit` view of D2UnitStrc. Per file: use D2UnitStrc and its field names, keep it only if the unit stays all equal. Branches `lane2/unit-views-*`, posted here with the files each touches. Lanes 1, 4, 5, 6, 8: please don't convert those views meanwhile.
20. (done) **The context-copy trim outside Storm/Fog/SRP** (coordinator's Answers). For each `// build: context` line, delete it and rebuild its unit; keep the deletion only if the unit stays all equal. Deletions only, one branch per module with a full verify: `lane2/ctx-trim-d2game` (running now), then D2Client, D2Common, D2BNClient, D2CMP and the small ones. Then the single-unit address names, posted in the owners' board files first.
19. Identical private copies (rescans on #339-#356) and address-named records used by more than one unit: done in small-records-d through -k, missile-data, storm-bytearray, split-text, sound-environ and text-box. What the rescan still finds is unused context copies, padding-only views, or groups that flip a unit when shared (the quest info pair, the weather layer state, the client missile mode, D2SavedItemStrc). The address names left (T006090E0, T00648730, T004DA110, T00516950, T00552FD0, ...) are each used by one unit, so they belong to that unit's lane. Lane 2 is checking in for rebases; ask on this board if a lane wants a shared record or header split out.
18. Field names in shared and module headers where the code gives clear evidence: done in mcp-fields, header-fields, storm-hash, storm-arrays, storm-critsect, storm-bitoutput, fog-fields, more-fields and client-fields. What is left (D2TileListHeaderStrc 0x0C/0x10, D2NpcSoundStrc and D2UnitSndPlayerStrc 0x00, TSExportTableSimple 0x44, D2GSPacketSrv83's two words, D2LaunchRecord3Strc 0x08, the profiling counter's 0x74) has no reader that says what it is, so it stays as is.
17. (done: storm-arrays)
16. (done: sound-environ, which also took T005C40D0.) The address names left in shared headers are Fog.h's QServer client and packet records (T006BFAD0, T006C23B0); Fog's QServer units have several overlapping views of them (D2QClientStrc, D2QConn006C23B0Strc, D2QMsg006C23B0Strc, ...), so I'm leaving them to lane 3's unit work. Single-unit address names (T006090E0 in LRUCache, T00648730 in Path, T004DA110 in GfxUtil, T00516950 in D2SoundUtil, T00552FD0 in SUnit) belong to those units.
15. (done: split-text)
14. (done: small-records-f, small-records-g)
13. Rescan on #332 done. Taken from it: records-c. Next from it: D2UIVarRecordStrc (Select, automap, ui, Unknown_0046ACE0); D2UiCelFileStrc (spellsel, Unknown_004A76C0/004A9BD0/004AA9C0); D2DrlgDeleteStrc (Dungeon, Level, PlrSave); D2UnitDropItemsPacketStrc (SCmd, CharSel, CharSel_0042E600); D2SoundUnitNodeStrc and D2DialogWidgetNodeStrc (sound and dialog units). The big clusters in text/Unknown_004A43E0/004A6460 and inv/Unknown_00482C70 look like context copies, so I'm leaving them to the unit work.
No borrowed-data block or language split is in lane 2's range: the coord block is runtime-library data.

## Questions



## Notes for other lanes

- All lanes, shim trim (round 1, `lane2/shim-trim-*`):
  - Shims kept because their unit changes without them. None has a caller, so they stay until a join or a codegen change: D2Client: Gfx_0046DCC0, Roster, text_0049D5A0, UnitMode (sub_004814A0_Shim), Unknown_004630E0, Unknown_004815A0, Unknown_004DF6C0, spellsel. D2Common: DrlgActivate, OutPlace x2, Items x2, UnitFinds, Units x2. D2Game: MissMode, PlrMsg, SkillNec, SUnitDmg. D2CMP: Codec, SubTile, Tilecmp. D2Multi: ComCallback. D2BNClient: grid, Unknown_00518C30. Also D2Direct3D (d3dSmack, d3dSprite), D2Win (D2WinFont), D2Launch (MainMenus), D2Hell (Archive) and Bnclient (Unknown_00520DC0).
  - Joins (the name is defined in more than one unit):
    - Lanes 1 and 4: sub_0049D5A0_UpdateTextBox is defined in text.cpp, Unknown_004A43E0 and Unknown_004A6460.
    - Lanes 5 and 8: D2Common Preset.cpp defines SKILLDESC_ValidateMonsterId (0x004E6C50). It is also defined in D2Client SkillDesc_004E1FF0 and inline in RoomTile, and D2Game.h and Unknown_0054DAC0 use it.
  - Lane 3, Fog: I left Fog's 7 markers alone. Kept because the unit changes without them: ErrorManager sub_M126_Emit_00401000, Excel sub_006BCD50_Shim, QServer shim_9 and sub_006BF320_Shim. Called from their own unit, so they are candidates for calling the real function: QServer sub_CallSite_SendToKey and sub_Emit_006BF500, and Unknown_00402380 sub_00402460_Shim.

- Lanes 5 and 8 (single-unit names, batch 2, `lane2/unit-names-b`, posted under Ready): SUnit's T00552FD0 view of pAnimData becomes D2AnimData.h's D2AnimDataRecordStrc; SUnitDmg's T0057E5A0 becomes D2PartyExperienceStrc (SUNITDMG_PartyCallback_ComputePartyExperience's data); MonsterTbls' T006510C0 becomes D2UniqueNameTablesStrc (gUniqueNameTables). Names only. Left alone for lack of evidence: Path.cpp's T00648730, Drlg.cpp's T00642010, PlrSave2's T0056A6F0, RosterPets' T0045FED0 and the R0052E0F0/R00601DC0 file holders.

- Lanes 1, 4, 6 (single-unit names, batch 1, `lane2/unit-names-a`, posted under Ready): LRUCache.cpp's T006090E0 view folds into its own D2LRUCacheStrc (same 0x34-byte record; the list helpers take its field names); GfxUtil's T004DA110 becomes D2KeyedNodeStrc (GFXUTIL_AddKeyedNode's node); D2SoundUtil's T00516950 becomes D2SoundListNodeStrc (D2SOUNDUTIL_ListAddHead's node); Cursor.cpp's T0044CB60 copy becomes D2SplittedTextStrc through D2WinSplitText.h. Names only.

- Lane 3, zlib: Source/Storm/zlib has no headers, so deflate.c and trees.c each define ct_data and tree_desc, and deflate.c and inflate.c each define gz_header, with the same text. In zlib's own source these live in deflate.h and zlib.h. If you add those headers to the zlib folder, the private copies can go; I haven't touched it because it's your module.

- Lane 8: `lane2/path-records-2` touches your D2Common pathfinding units PathWF, Unknown_00679380 and Unknown_0067B9C0. Each loses its private D2PathMovStrc/D2CollisionTestStrc and includes D2PathFind.h instead. If you move those functions, the records now come from that header.

- All lanes, language-name copies: to turn a planned copy into the include, drop the copy's definition from build/data_plan.json and add `#include "D2LanguageNames.h"` to the unit. Put the include before the unit's other data definitions: a top-of-file include goes before everything in the gen/data .inc, which comes last. That only matches when the copy is the unit's first data. A copy in the middle or at the end of a planned file starts the next original unit, so split the file first. The header has `#pragma once`, so one file can hold only one copy through it. Fog's ErrorManager declares `extern const char* const gaszLanguageNames[]`; drop that when it takes the include.

- Lanes 1 and 4: the 0x225 table, and the pointer the client keeps at 0x007A05F4, is D2ComInterfaceStrc (D2ComInterface.h). 0xC4 is `pfnClose`. D2ClientNotifyStrc is a temporary view of the same table.
- Lane 1: 0x711470 has two names, `gnScreenHeight_00711470` in D2Client.h and `gnScreenHeight` declared privately in about 60 units. Left alone; your header.

## Left in place (and why)

- D2DataTablesStrc+0xC30 stays `void* pMonPropTxt` (retested on #358: an elaborated `struct D2MonPropTxt*` still flips LvlTbls, ItemTbls and MonsterTbls). It is monprop.txt (0x138-byte records, compiled by DATATBLS_LoadMonPropTxt), and Unknown_00573470 is its getter through D2MonStatsTxt+0x1A (wMonProp; that unit's private copy calls it wMonStatsEx). I retested on #314: typing it `D2MonPropTxt*`, with a forward declaration or an elaborated type, still flips inv_0048DD90, LvlTbls, ItemTbls and MonsterTbls. So 0x573470 stays alone with its private records. MonsterTbls also keeps `gpMonpropTxt`/`gnMonpropTxtRecordCount` (0x0096C860/64): these are sgtDataTables+0xC30/0xC34 under a second name.

- D2ClientNotifyStrc in D2ClientUi.h (see Questions). GAME_GetClientNotify still converts `gpClientConfig->pComInterface` to it.
- D2Launch's `gpLaunchRecord` (0x7795D4) and D2Multi's `gpCharInfo` are their modules' own pointers to the config record. They aren't aliases of 0x7A0438.
