# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/shared-copies cdb9c9fd 562->562 Shared headers replace eight private record copies whose layout already agrees with the header: D2DataTablesStrc (inv_004886C0), D2GSPacketSrv73 (Missiles), D2GSPacketSrvAA (PlrEval, Unknown_00570420), D2GSPacketSrv5D (a5q3), D2RoomCoordListStrc (Unknown_0054DAC0), D2ObjInitFnStrc (Unknown_0059F440), D2StormArrayAStrc (Storm Unknown_004212F0); VERIFIED 4c77adfc7ff97a0aea2eca2579de942cd8382406
  - Verified on #309, rebased onto #310. #310 touches none of the 8 units; precheck is equal on #310.
  - Outside lane 2: lanes 3, 4 and 5 (one include replaces the private copy in each unit).
  - Found by a sweep of every unit whose private struct shares its name with a shared-header struct (about 230 names). Only these build equal as they are. The rest fail to compile (different field names, or other private records in the unit that clash with the header) or change code (sizeof, or a different layout). Those need work unit by unit.


## Questions


## Notes for other lanes

- All lanes, language-name copies: to turn a planned copy into the include, drop the copy's definition from build/data_plan.json and add `#include "D2LanguageNames.h"` to the unit. Put the include before the unit's other data definitions: a top-of-file include goes before everything in the gen/data .inc, which comes last. That only matches when the copy is the unit's first data. A copy in the middle or at the end of a planned file starts the next original unit, so split the file first. The header has `#pragma once`, so one file can hold only one copy through it. Fog's ErrorManager declares `extern const char* const gaszLanguageNames[]`; drop that when it takes the include.

- Lanes 1 and 4: the 0x225 table, and the pointer the client keeps at 0x007A05F4, is D2ComInterfaceStrc (D2ComInterface.h). 0xC4 is `pfnClose`. D2ClientNotifyStrc is a temporary view of the same table.
- Lane 1: 0x711470 has two names, `gnScreenHeight_00711470` in D2Client.h and `gnScreenHeight` declared privately in about 60 units. Left alone; your header.

## Left in place (and why)

- D2ClientNotifyStrc in D2ClientUi.h (see Questions). GAME_GetClientNotify still converts `gpClientConfig->pComInterface` to it.
- D2Launch's `gpLaunchRecord` (0x7795D4) and D2Multi's `gpCharInfo` are their modules' own pointers to the config record. They aren't aliases of 0x7A0438.
