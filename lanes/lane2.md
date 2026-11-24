# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/msg-record 73c40a00 562->562 D2MsgRecord.h: the input recorder's 16-byte message record and its 500-record chunk, shared, instead of nine private copies. Three of them called the record D2WinMsgStrc, which is the name for the Windows MSG layout elsewhere. The tick is signed (CUnit playback compares with jle), and 0x1F44 is nIndex; VERIFIED f8b6f14cc9371aebaaa7b0834bab26030a488d80
  - Verified on #306, rebased onto #307. #307 touches none of the 9 changed units; precheck is equal on #307.
  - Outside lane 2: Game, Game_0044B7B0, Game_0044D080, Record, SCmd, inv, text, CUnit (lanes 1 and 4), ComCallback (lane 6). Private-copy removal and field renames only.
- lane2/lang-names e7b077c1 562->562 D2LanguageNames.h: the 15-entry language-name table, defined once as a static array of non-const string pointers so each includer keeps its own .data copy; nothing includes it yet; VERIFIED 8645efc339552b4f7d4a99ae75ba23ed6f57aca9
  - Verified on #305, rebased onto #306 (no Source overlap: the header is new and unincluded).
  - Tested locally on a3q7.cpp. I swapped its planned copy (0x00741578) in the generated .inc for `#include "D2LanguageNames.h"` at the same place: the full build stayed identical. So the static is emitted unread, its pointers land on the shared literals at 0x006CC77C-0x006CC81C, and the copy sits where the include sits in definition order.
- lane2/party-row 4e40655f 562->562 D2ClientParty.h: the party panel row (0xD1, packed) and its button slot (0x20), shared, instead of seven private copies under the name D2RosterUnitStrc. The row becomes D2PartyRowStrc, so the name no longer clashes with Gfx/Roster's real roster unit. The "aButtons" view 4 bytes in is the same slot fields; VERIFIED bebc4c9c9aa4b33896a2d3bfc7365b0280f59a6e
  - Verified on #303, rebased onto #304. panel.cpp moved on #304 and precheck of the 7 units is still equal there.
  - Outside lane 2: Party, panel and Unknown_0049AAF0/AF60/B030/B330/BB40 (lane 4). Renames and private-copy removal only. D2RosterButtonStrc in D2Client.h (lane 1) has no users left.

## Questions


## Notes for other lanes

- All lanes, language-name copies: to turn a planned copy into the include, drop the copy's definition from build/data_plan.json and add `#include "D2LanguageNames.h"` to the unit. Put the include before the unit's other data definitions: a top-of-file include goes before everything in the gen/data .inc, which comes last. That only matches when the copy is the unit's first data. A copy in the middle or at the end of a planned file starts the next original unit, so split the file first. The header has `#pragma once`, so one file can hold only one copy through it. Fog's ErrorManager declares `extern const char* const gaszLanguageNames[]`; drop that when it takes the include.

- Lanes 1 and 4: the 0x225 table, and the pointer the client keeps at 0x007A05F4, is D2ComInterfaceStrc (D2ComInterface.h). 0xC4 is `pfnClose`. D2ClientNotifyStrc is a temporary view of the same table.
- Lane 1: 0x711470 has two names, `gnScreenHeight_00711470` in D2Client.h and `gnScreenHeight` declared privately in about 60 units. Left alone; your header.

## Left in place (and why)

- D2ClientNotifyStrc in D2ClientUi.h (see Questions). GAME_GetClientNotify still converts `gpClientConfig->pComInterface` to it.
- D2Launch's `gpLaunchRecord` (0x7795D4) and D2Multi's `gpCharInfo` are their modules' own pointers to the config record. They aren't aliases of 0x7A0438.
