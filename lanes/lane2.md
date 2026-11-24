# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/records-c-2 465be83b 562->562 Replaces `lane2/records-c` (rebased onto #338; the WINMAIN.CPP conflict was include lines only). Two commits. D2McpPackets.h gets the incoming MCP packets (0x03, 0x04, 0x08, 0x09, 0x0A, 0x0E), the packet value record and the create-game body, which WINMAIN, Unknown_0044B400 and Unknown_0044A170 each had private copies of. D2FogTypes.h gets the exception reporter's imagehlp address/stack-frame/symbol/module records, FPO data, toolhelp module entry, module list node and crash dump entry, which Exceptions and Safesock each had copies of; VERIFIED 723f04aedab365a716b6a0446bf001c1a4fbd45f
  - Verified on 386d6e91 (#337), rebased onto 55b20d70 (#338). Precheck of all 20 includers and changed units is equal there; namesync has nothing to rename.
  - Outside lane 2: WINMAIN, Unknown_0044B400 (lane 4), Unknown_0044A170 (lane 6), Exceptions, Safesock (lane 3).

- lane2/client-records-b-2 55eacec9 562->562 Replaces `lane2/client-records-b` (rebased onto #337; its first commit, D2LaunchRequest.h, is already in #336, so three commits are left). D2ClientStatButton.h (gaStatButtons' 0xE-byte pack(2) record, still named D2BeltSlotStrc because the data plan names it; 4 units), D2ClientKeyConfig.h (the 0x47A-byte .key file; CmdTbl, CUnit), D2ClientTextPanel.h (the scrolling text panel and its line; panel, Unknown_00499500); VERIFIED 49bb5f40d45fd48749eb56e502b9c224145ea2f7
  - On 386d6e91. Merges cleanly onto #338, which touches none of its files.
  - Outside lane 2: lanes 4 and 6 (private-copy removal plus one include per unit).

- lane2/client-records-c da5dea13 562->562 Two commits. D2ClientSound.h gets the sound units' unit list node, which SoundInst, SoundInst_004B9B50 and Unknown_004B82F0 each defined. A new small D2ClientUiRecords.h holds the UI-variable close table (Select, automap, ui, Unknown_0046ACE0) and the UI cel file (spellsel, Unknown_004A76C0/004A9BD0/004AA9C0). One cel-file copy was pack 1 and the others pack 2; the layout is the same either way; VERIFIED bd01be9e53f1c71f67fd5d0c571ff223f8885be7
  - On 89693ff5. All 54 includers and changed units build equal. Merges cleanly onto #338.
  - Outside lane 2: 11 D2Client units (lanes 1 and 4).

- `lane2/small-records-d-2`: rebased onto #338, verify running; posted here when it passes. It replaces `lane2/small-records-d`.

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
13. Rescan on #332 done. Taken from it: records-c. Next from it: D2UIVarRecordStrc (Select, automap, ui, Unknown_0046ACE0); D2UiCelFileStrc (spellsel, Unknown_004A76C0/004A9BD0/004AA9C0); D2DrlgDeleteStrc (Dungeon, Level, PlrSave); D2UnitDropItemsPacketStrc (SCmd, CharSel, CharSel_0042E600); D2SoundUnitNodeStrc and D2DialogWidgetNodeStrc (sound and dialog units). The big clusters in text/Unknown_004A43E0/004A6460 and inv/Unknown_00482C70 look like context copies, so I'm leaving them to the unit work.
No borrowed-data block or language split is in lane 2's range: the coord block is runtime-library data.

## Questions


## Notes for other lanes

- Lane 8: `lane2/path-records-2` touches your D2Common pathfinding units PathWF, Unknown_00679380 and Unknown_0067B9C0. Each loses its private D2PathMovStrc/D2CollisionTestStrc and includes D2PathFind.h instead. If you move those functions, the records now come from that header.

- All lanes, language-name copies: to turn a planned copy into the include, drop the copy's definition from build/data_plan.json and add `#include "D2LanguageNames.h"` to the unit. Put the include before the unit's other data definitions: a top-of-file include goes before everything in the gen/data .inc, which comes last. That only matches when the copy is the unit's first data. A copy in the middle or at the end of a planned file starts the next original unit, so split the file first. The header has `#pragma once`, so one file can hold only one copy through it. Fog's ErrorManager declares `extern const char* const gaszLanguageNames[]`; drop that when it takes the include.

- Lanes 1 and 4: the 0x225 table, and the pointer the client keeps at 0x007A05F4, is D2ComInterfaceStrc (D2ComInterface.h). 0xC4 is `pfnClose`. D2ClientNotifyStrc is a temporary view of the same table.
- Lane 1: 0x711470 has two names, `gnScreenHeight_00711470` in D2Client.h and `gnScreenHeight` declared privately in about 60 units. Left alone; your header.

## Left in place (and why)

- D2ExceptionPointersStrc stays private in Exceptions, LogManager and Unknown_00402820. Two copies type the record as `void*` and the context as `D2ThreadContextStrc*`; the third types the record as `D2ExceptionRecordStrc*` and the context as `void*`. Sharing it needs one typing for both fields.

- D2DataTablesStrc+0xC30 stays `void* pMonPropTxt`. It is monprop.txt (0x138-byte records, compiled by DATATBLS_LoadMonPropTxt), and Unknown_00573470 is its getter through D2MonStatsTxt+0x1A (wMonProp; that unit's private copy calls it wMonStatsEx). I retested on #314: typing it `D2MonPropTxt*`, with a forward declaration or an elaborated type, still flips inv_0048DD90, LvlTbls, ItemTbls and MonsterTbls. So 0x573470 stays alone with its private records. MonsterTbls also keeps `gpMonpropTxt`/`gnMonpropTxtRecordCount` (0x0096C860/64): these are sgtDataTables+0xC30/0xC34 under a second name.

- D2ClientNotifyStrc in D2ClientUi.h (see Questions). GAME_GetClientNotify still converts `gpClientConfig->pComInterface` to it.
- D2Launch's `gpLaunchRecord` (0x7795D4) and D2Multi's `gpCharInfo` are their modules' own pointers to the config record. They aren't aliases of 0x7A0438.
