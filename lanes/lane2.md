# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/small-records-k 89000292 562->562 One commit, six small headers, each included only by the units that had identical private copies: D2CoordPair.h (an x/y pair; D2DDraw Unknown_005125E0, D2Gdi Unknown_006C8DA0, D2Launch MainMenus), D2TileLight.h (a tile's four corner light values; the same D2DDraw and D2Gdi units), D2CmpDC6CacheEntry.h (CelCmp, Unknown_005FE210), D2ColorBlock.h (FastCmp, Unknown_006056D0), D2UnitEventArgs.h (client Item, PlrSkills), D2ClientRange.h (client Game, Game_0044B7B0). D2WeatherLayerStateStrc stays private: shared, one of its units flips; VERIFIED 989e543043c9246561ffd94966d3a0f8e27c642e
  - Verified on e40ccd0c (#355), rebased onto a6db6df9 (#356): CelCmp.cpp's conflict with small-records-i was include lines only. Precheck of all 11 changed units is equal there.
  - Outside lane 2: CelCmp, FastCmp, Unknown_005FE210/006056D0 (lane 6), Unknown_005125E0, Unknown_006C8DA0 (lanes 6 and 9), MainMenus (lane 6), client Item, PlrSkills, Game, Game_0044B7B0 (lanes 1 and 4).

- lane2/small-records-j 1e1cec7e 562->562 One commit, nine small headers, each included only by the two units that had identical private copies: D2MonTypeTxt.h (the part of a montype.txt record the client reads; SkillDesc, Unknown_004E2320), D2Win32RgbQuad.h (RGBQUAD; gdiCore, Unknown_006C7CF0), D2ClientBallistic.h (GfxUtil, client Skills), D2QuestLookupEntry.h (View, QuestLog), D2TextIdEntry.h (text, text_0049DA50), D2NpcIndex.h (pack 1; npcmenu, Unknown_004B6DD0), D2HintKeyList.h (Unknown_004B8720, Unknown_004BA890), D2ListBoxLine.h (Unknown_004BC1B0, Unknown_004BC1B0_004BE770), D2WaypointActRange.h (Unknown_0049BB40, WardenClient). D2CltMissileModeStrc stays private: shared, both its units flip; VERIFIED 7e465a62f46450291dcbbdb2e315093ff08f5920
  - On e40ccd0c (#355). All 18 changed units build equal. Independent of small-records-h and -i.
  - Outside lane 2: 16 D2Client units (lanes 1 and 4), gdiCore, Unknown_006C7CF0 (lane 6).

## Working on

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
18. Field names in shared and module headers where the code gives clear evidence: done in mcp-fields, header-fields, storm-hash, storm-arrays, storm-critsect, storm-bitoutput, fog-fields, more-fields and client-fields. What is left (D2TileListHeaderStrc 0x0C/0x10, D2NpcSoundStrc and D2UnitSndPlayerStrc 0x00, TSExportTableSimple 0x44, D2GSPacketSrv83's two words, D2LaunchRecord3Strc 0x08, the profiling counter's 0x74) has no reader that says what it is, so it stays as is.
17. (done: storm-arrays)
16. (done: sound-environ, which also took T005C40D0.) The address names left in shared headers are Fog.h's QServer client and packet records (T006BFAD0, T006C23B0); Fog's QServer units have several overlapping views of them (D2QClientStrc, D2QConn006C23B0Strc, D2QMsg006C23B0Strc, ...), so I'm leaving them to lane 3's unit work. Single-unit address names (T006090E0 in LRUCache, T00648730 in Path, T004DA110 in GfxUtil, T00516950 in D2SoundUtil, T00552FD0 in SUnit) belong to those units.
15. (done: split-text)
14. (done: small-records-f, small-records-g)
13. Rescan on #332 done. Taken from it: records-c. Next from it: D2UIVarRecordStrc (Select, automap, ui, Unknown_0046ACE0); D2UiCelFileStrc (spellsel, Unknown_004A76C0/004A9BD0/004AA9C0); D2DrlgDeleteStrc (Dungeon, Level, PlrSave); D2UnitDropItemsPacketStrc (SCmd, CharSel, CharSel_0042E600); D2SoundUnitNodeStrc and D2DialogWidgetNodeStrc (sound and dialog units). The big clusters in text/Unknown_004A43E0/004A6460 and inv/Unknown_00482C70 look like context copies, so I'm leaving them to the unit work.
No borrowed-data block or language split is in lane 2's range: the coord block is runtime-library data.

## Questions


## Notes for other lanes

- Lane 3, zlib: Source/Storm/zlib has no headers, so deflate.c and trees.c each define ct_data and tree_desc, and deflate.c and inflate.c each define gz_header, with the same text. In zlib's own source these live in deflate.h and zlib.h. If you add those headers to the zlib folder, the private copies can go; I haven't touched it because it's your module.

- Lane 8: `lane2/path-records-2` touches your D2Common pathfinding units PathWF, Unknown_00679380 and Unknown_0067B9C0. Each loses its private D2PathMovStrc/D2CollisionTestStrc and includes D2PathFind.h instead. If you move those functions, the records now come from that header.

- All lanes, language-name copies: to turn a planned copy into the include, drop the copy's definition from build/data_plan.json and add `#include "D2LanguageNames.h"` to the unit. Put the include before the unit's other data definitions: a top-of-file include goes before everything in the gen/data .inc, which comes last. That only matches when the copy is the unit's first data. A copy in the middle or at the end of a planned file starts the next original unit, so split the file first. The header has `#pragma once`, so one file can hold only one copy through it. Fog's ErrorManager declares `extern const char* const gaszLanguageNames[]`; drop that when it takes the include.

- Lanes 1 and 4: the 0x225 table, and the pointer the client keeps at 0x007A05F4, is D2ComInterfaceStrc (D2ComInterface.h). 0xC4 is `pfnClose`. D2ClientNotifyStrc is a temporary view of the same table.
- Lane 1: 0x711470 has two names, `gnScreenHeight_00711470` in D2Client.h and `gnScreenHeight` declared privately in about 60 units. Left alone; your header.

## Left in place (and why)

- D2ExceptionPointersStrc stays private in Exceptions, LogManager and Unknown_00402820. Two copies type the record as `void*` and the context as `D2ThreadContextStrc*`; the third types the record as `D2ExceptionRecordStrc*` and the context as `void*`. Sharing it needs one typing for both fields.

- D2DataTablesStrc+0xC30 stays `void* pMonPropTxt`. It is monprop.txt (0x138-byte records, compiled by DATATBLS_LoadMonPropTxt), and Unknown_00573470 is its getter through D2MonStatsTxt+0x1A (wMonProp; that unit's private copy calls it wMonStatsEx). I retested on #314: typing it `D2MonPropTxt*`, with a forward declaration or an elaborated type, still flips inv_0048DD90, LvlTbls, ItemTbls and MonsterTbls. So 0x573470 stays alone with its private records. MonsterTbls also keeps `gpMonpropTxt`/`gnMonpropTxtRecordCount` (0x0096C860/64): these are sgtDataTables+0xC30/0xC34 under a second name.

- D2ClientNotifyStrc in D2ClientUi.h (see Questions). GAME_GetClientNotify still converts `gpClientConfig->pComInterface` to it.
- D2Launch's `gpLaunchRecord` (0x7795D4) and D2Multi's `gpCharInfo` are their modules' own pointers to the config record. They aren't aliases of 0x7A0438.
