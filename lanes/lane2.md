# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/game-timer 058c52dd 562->562 D2ClientTimer.h: the 8-byte client timer (start tick, length) that GAME_IsTimerExpired/Running test. It was defined privately, with the same text, in Game, Game_0044B7B0, Game_0044D080 and Game_0044E5A0. It goes in a small header only these four include, because adding it to D2ClientTypes.h flipped inv and inv_004886C0; VERIFIED 4c999e9c6d63db058d31eb30fcb5386a69f7e0f0
  - Verified on #314, rebased onto #317. None of #315-#317 touches the 4 units; precheck is equal on #317.
  - Outside lane 2: the four D2Client GAME units (lane 4).

- lane2/fog-records c9defc5f 562->562 D2FogTypes.h: the D2Server service status (passed to SetServiceStatus) and the crash handler's minidump request, shared. Each was defined privately with the same text in four units (ErrorManager, ErrorManager_004082E0, Safesock, plus MainMenus or Unknown_00402820); VERIFIED 255cb65f887771557bc73a1af17a11e35d3349c2
  - Verified on #312, rebased onto #314. #313/#314 touch none of the 5 units; precheck of all 16 includers is equal on #314.
  - Outside lane 2: Fog (lane 3) and MainMenus (lane 6). Private-copy removal only.


## Questions


## Notes for other lanes

- All lanes, language-name copies: to turn a planned copy into the include, drop the copy's definition from build/data_plan.json and add `#include "D2LanguageNames.h"` to the unit. Put the include before the unit's other data definitions: a top-of-file include goes before everything in the gen/data .inc, which comes last. That only matches when the copy is the unit's first data. A copy in the middle or at the end of a planned file starts the next original unit, so split the file first. The header has `#pragma once`, so one file can hold only one copy through it. Fog's ErrorManager declares `extern const char* const gaszLanguageNames[]`; drop that when it takes the include.

- Lanes 1 and 4: the 0x225 table, and the pointer the client keeps at 0x007A05F4, is D2ComInterfaceStrc (D2ComInterface.h). 0xC4 is `pfnClose`. D2ClientNotifyStrc is a temporary view of the same table.
- Lane 1: 0x711470 has two names, `gnScreenHeight_00711470` in D2Client.h and `gnScreenHeight` declared privately in about 60 units. Left alone; your header.

## Left in place (and why)

- D2DataTablesStrc+0xC30 stays `void* pMonPropTxt`. It is monprop.txt (0x138-byte records, compiled by DATATBLS_LoadMonPropTxt), and Unknown_00573470 is its getter through D2MonStatsTxt+0x1A (wMonProp; that unit's private copy calls it wMonStatsEx). I retested on #314: typing it `D2MonPropTxt*`, with a forward declaration or an elaborated type, still flips inv_0048DD90, LvlTbls, ItemTbls and MonsterTbls. So 0x573470 stays alone with its private records. MonsterTbls also keeps `gpMonpropTxt`/`gnMonpropTxtRecordCount` (0x0096C860/64): these are sgtDataTables+0xC30/0xC34 under a second name.

- D2ClientNotifyStrc in D2ClientUi.h (see Questions). GAME_GetClientNotify still converts `gpClientConfig->pComInterface` to it.
- D2Launch's `gpLaunchRecord` (0x7795D4) and D2Multi's `gpCharInfo` are their modules' own pointers to the config record. They aren't aliases of 0x7A0438.
