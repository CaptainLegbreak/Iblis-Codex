# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/game-records a56b9979 562->562 D2GameTypes.h: the roster-iteration callback argument (Game, Player, PlrSave) and the door-finding callback argument (AiThink, AiUtil, MissMode). Each unit had a private copy with the same text; VERIFIED 18754bec2b45ca97877cb09a77b98459f9cfe41b
  - Verified on #318, rebased onto #320. Precheck of all 202 includers of D2GameTypes.h is equal on #320.
  - Outside lane 2: the six D2Game units (lane 5). Private-copy removal only.

- lane2/cmp-records-2 12d0f1a3 562->562 D2CmpTypes.h: the find-tiles node and its sub node, which FindTiles and TileLib each defined privately with the same text. Ignore `lane2/cmp-records`: it also moved the subtile block and flips D2Win's D2Comp on #318; VERIFIED 86c772d2bde5a0aa61c3bc01a7d4ae079770bfd9
  - On #318. All 36 includers of D2CmpTypes.h build equal.
  - Outside lane 2: FindTiles and TileLib (lane 6).


## Questions


## Notes for other lanes

- All lanes, language-name copies: to turn a planned copy into the include, drop the copy's definition from build/data_plan.json and add `#include "D2LanguageNames.h"` to the unit. Put the include before the unit's other data definitions: a top-of-file include goes before everything in the gen/data .inc, which comes last. That only matches when the copy is the unit's first data. A copy in the middle or at the end of a planned file starts the next original unit, so split the file first. The header has `#pragma once`, so one file can hold only one copy through it. Fog's ErrorManager declares `extern const char* const gaszLanguageNames[]`; drop that when it takes the include.

- Lanes 1 and 4: the 0x225 table, and the pointer the client keeps at 0x007A05F4, is D2ComInterfaceStrc (D2ComInterface.h). 0xC4 is `pfnClose`. D2ClientNotifyStrc is a temporary view of the same table.
- Lane 1: 0x711470 has two names, `gnScreenHeight_00711470` in D2Client.h and `gnScreenHeight` declared privately in about 60 units. Left alone; your header.

## Left in place (and why)

- D2DataTablesStrc+0xC30 stays `void* pMonPropTxt`. It is monprop.txt (0x138-byte records, compiled by DATATBLS_LoadMonPropTxt), and Unknown_00573470 is its getter through D2MonStatsTxt+0x1A (wMonProp; that unit's private copy calls it wMonStatsEx). I retested on #314: typing it `D2MonPropTxt*`, with a forward declaration or an elaborated type, still flips inv_0048DD90, LvlTbls, ItemTbls and MonsterTbls. So 0x573470 stays alone with its private records. MonsterTbls also keeps `gpMonpropTxt`/`gnMonpropTxtRecordCount` (0x0096C860/64): these are sgtDataTables+0xC30/0xC34 under a second name.

- D2ClientNotifyStrc in D2ClientUi.h (see Questions). GAME_GetClientNotify still converts `gpClientConfig->pComInterface` to it.
- D2Launch's `gpLaunchRecord` (0x7795D4) and D2Multi's `gpCharInfo` are their modules' own pointers to the config record. They aren't aliases of 0x7A0438.
