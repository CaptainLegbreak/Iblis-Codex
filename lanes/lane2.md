# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/questlog-records f4189478 562->562 D2ClientQuestLog.h: the quest table, the packed 0x26A-byte quest panel entry and the button layout. QuestLog, text, text_0049A950, Unknown_004A43E0 and Unknown_004A6460 each had private copies with the same text, now in a small header only they include. The quest text message stays private (QuestLog types its text as unsigned short where the rest use Unicode), and so does the log state that embeds it; VERIFIED 302c0d5fa0520de1a0083154e92e1ffe2138269b
  - On d4484343. The 5 units build equal.
  - Outside lane 2: the five D2Client UI units (lane 4).

- lane2/win-popup 0400c7bd 562->562 D2WinPopupLine.h: the popup menu line (64 characters of text, click handler at 0x80). D2Comp, D2WinImage, D2WinMain, D2WinPopup and D2WinScrollbar each had a private copy with the same text. It goes in a small header only those five include, because adding it to D2WinControls.h broke D2WinAnimImage; VERIFIED 6ca786193acebf9f3d7380225415e9d781a1762e
  - On c4ce2baa. The 5 units build equal.
  - Outside lane 2: the five D2Win units (lane 6).


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
9. D2LaunchRequestStrc (WINMAIN, Unknown_0044B400, CharSel, CharSel_0042E600, Unknown_0044A170, Unknown_00444020).
10. D2BeltSlotStrc (text, Unknown_004A43E0/004A6460/004A76C0).
11. Char save file and ladder entry (ChatDlg, ChatDlg_00441B70).
12. Key config file (CmdTbl, CUnit), text panel (panel, Unknown_00499500).
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
