# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/game-records-2 17112da0 562->562 Replaces the held `lane2/game-records`. The roster-iteration and door-finding callback arguments now go in a small header, D2GameCallbackArgs.h, that only their six users include (Game, Player, PlrSave, AiThink, AiUtil, MissMode); D2GameTypes.h is untouched, so D2Comp and AiThink4 can't flip; VERIFIED 3ace9016c0d210db3642e61a0e47967defc52d62
  - Verified on 5929eec6, rebased onto c4ce2baa. Precheck is equal there.
  - Outside lane 2: the six D2Game units (lane 5).

- lane2/path-records-2 3e8f3fb9 562->562 Replaces `lane2/path-records`, redone on #327's path regroup: D2PathFind.h gets the wall-following move state (PathWF, Unknown_00679380, Unknown_0067B9C0) and the collision test argument (Unknown_00679380, Unknown_0067B9C0). Each unit had a private copy with the same text; VERIFIED 2479a82dbb66e4c18a06922dde91c85b1f1a9fe3
  - Verified on #328, rebased onto 5929eec6. All includers of D2PathFind.h build equal there.
  - Outside lane 2: the three pathfinding units (lane 6).

- lane2/win32-system-2 dbdfa445 562->562 D2Win32System.h: the Win32 PROCESS_INFORMATION (five units) and MEMORYSTATUS (five units) records, which units in Fog, D2Multi, D2Hell, D2Launch and D2Client each defined privately. A small header that only those units include. Ignore `lane2/win32-system`: it missed Unknown_00477620 after #327 moved the memory-status code there; VERIFIED 2995b14acbe8bf4593c0586bafdbc7b178247b82
  - Verified on #328, rebased onto the newest main (f5e0e3e9). Precheck is equal there.
  - Outside lane 2: ErrorManager, ErrorManager_004082E0, Safesock, system.cpp, Unknown_00401070 (lane 3); ChatDlg, MainMenus, D2Hell Unknown_00516D8B (lane 6); Unknown_00477620 (lane 4). In ErrorManager the private copy started mid-line after a declaration; the declaration stays.


## Working on

Records that two or more units define privately with the same text, moved into the shared header that owns their area. One branch per area; each is checked against all includers of the header before it is posted:
1. (done: fog-records-c)
2. (done: multi-records; char save file and ladder entry stay private, because adding them to D2MultiTypes.h flips CharSel)
3. (done: d3d-records)
4. (done: bn-messages)
5. (done: path-records)
6. (done: win32-system-2)
7. D2WinPopUpLineStrc (five D2Win units).
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
