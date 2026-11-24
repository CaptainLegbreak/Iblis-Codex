# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/mcp-packets 91fc5231 562->562 D2McpPackets.h: the fifteen packed MCP protocol packets (0x01-0x0C, 0x10, 0x16, 0x18). WINMAIN, Unknown_0044B400 and D2MCPClient's Unknown_0044A170 each had a private copy with the same text; VERIFIED 31d699b117b57e1c794d42f97f55d70cab76871f
  - Verified on #321, rebased onto #324. #322-#324 touch none of the 3 units; precheck is equal on #324.
  - Outside lane 2: WINMAIN, Unknown_0044B400 (lane 4), Unknown_0044A170 (lane 6). Game.cpp keeps its own, different, unpacked view of packet 0x06.

- lane2/game-records a56b9979 562->562 D2GameTypes.h: the roster-iteration callback argument (Game, Player, PlrSave) and the door-finding callback argument (AiThink, AiUtil, MissMode). Each unit had a private copy with the same text; VERIFIED 18754bec2b45ca97877cb09a77b98459f9cfe41b
  - Verified on #318, rebased onto #320. Precheck of all 202 includers of D2GameTypes.h is equal on #320.
  - Outside lane 2: the six D2Game units (lane 5). Private-copy removal only.


## Working on

Records that two or more units define privately with the same text, moved into the shared header that owns their area. One branch per area; each is checked against all includers of the header before it is posted:
1. Fog: the 7 remaining ErrorManager/ErrorManager_004082E0 records (thread name info, mode interface/entry, service table entry, SID authority, process entry, crash input) -> D2FogTypes.h.
2. D2Multi: the ChatDlg records (char save file, ladder entry, launch game entry/list) -> D2MultiTypes.h.
3. Direct3D: d3dCore/Unknown_006B2F60 device and caps records -> D2D3DTypes.h.
4. BNClient: the BnDownload login/versioning/auth records.
After that: the coordinator's borrowed-data blocks, if no lane has them.

## Questions


## Notes for other lanes

- All lanes, language-name copies: to turn a planned copy into the include, drop the copy's definition from build/data_plan.json and add `#include "D2LanguageNames.h"` to the unit. Put the include before the unit's other data definitions: a top-of-file include goes before everything in the gen/data .inc, which comes last. That only matches when the copy is the unit's first data. A copy in the middle or at the end of a planned file starts the next original unit, so split the file first. The header has `#pragma once`, so one file can hold only one copy through it. Fog's ErrorManager declares `extern const char* const gaszLanguageNames[]`; drop that when it takes the include.

- Lanes 1 and 4: the 0x225 table, and the pointer the client keeps at 0x007A05F4, is D2ComInterfaceStrc (D2ComInterface.h). 0xC4 is `pfnClose`. D2ClientNotifyStrc is a temporary view of the same table.
- Lane 1: 0x711470 has two names, `gnScreenHeight_00711470` in D2Client.h and `gnScreenHeight` declared privately in about 60 units. Left alone; your header.

## Left in place (and why)

- D2DataTablesStrc+0xC30 stays `void* pMonPropTxt`. It is monprop.txt (0x138-byte records, compiled by DATATBLS_LoadMonPropTxt), and Unknown_00573470 is its getter through D2MonStatsTxt+0x1A (wMonProp; that unit's private copy calls it wMonStatsEx). I retested on #314: typing it `D2MonPropTxt*`, with a forward declaration or an elaborated type, still flips inv_0048DD90, LvlTbls, ItemTbls and MonsterTbls. So 0x573470 stays alone with its private records. MonsterTbls also keeps `gpMonpropTxt`/`gnMonpropTxtRecordCount` (0x0096C860/64): these are sgtDataTables+0xC30/0xC34 under a second name.

- D2ClientNotifyStrc in D2ClientUi.h (see Questions). GAME_GetClientNotify still converts `gpClientConfig->pComInterface` to it.
- D2Launch's `gpLaunchRecord` (0x7795D4) and D2Multi's `gpCharInfo` are their modules' own pointers to the config record. They aren't aliases of 0x7A0438.
