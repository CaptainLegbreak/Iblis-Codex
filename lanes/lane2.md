# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/sets-txt 3d42f692 562->562 D2SetsTxt.h: one shared sets.txt record (0x128) instead of nine private copies (BnSend, inv, CUnit, ItemMods, Items, Unknown_005C2740 include it; text.cpp and ddDebugFont drop an unused copy); VERIFIED 36e2333234abc46b207e52806e0bf76ceecdb72a
  - Verified on #301. Rebased onto #302 (e5714a07) right before the push; #302 touches none of the changed files, and precheck of the 8 changed units is equal on #302 (D2Client.h moved).
  - Outside lane 2: private-copy removal and field renames in D2Client units (lanes 1 and 4), D2Common, D2Game (lane 5), D2BNClient and D2DDraw (lane 6).
  - Its own header, not D2Records.h. Adding the record to D2Records.h flipped 6 of its 161 includers.

## Questions

- The client's D2ClientNotifyStrc (D2ClientUi.h, used by GAME_GetClientNotify and its callers) is the same table, but I left it as a separate view. Any change to D2ClientUi.h flips gnScreenHeight/gnPanelOffsetY operand order in inv_0048BC10 and inv_0048DD90 (lane 4). Nothing natural I tried fixed it, about 60 combinations: where the include goes, how the gaps are written, where the declarations sit in D2Client.h, and using one name for 0x711470 in those units. Main's D2ClientUi.h keeps them equal. Should it stay a view until those units change for other reasons, or do you want the merge forced some other way?

## Notes for other lanes

- Lanes 1 and 4: the 0x225 table, and the pointer the client keeps at 0x007A05F4, is D2ComInterfaceStrc (D2ComInterface.h). 0xC4 is `pfnClose`. D2ClientNotifyStrc is a temporary view of the same table.
- Lane 1: 0x711470 has two names, `gnScreenHeight_00711470` in D2Client.h and `gnScreenHeight` declared privately in about 60 units. Left alone; your header.

## Left in place (and why)

- D2ClientNotifyStrc in D2ClientUi.h (see Questions). GAME_GetClientNotify still converts `gpClientConfig->pComInterface` to it.
- D2Launch's `gpLaunchRecord` (0x7795D4) and D2Multi's `gpCharInfo` are their modules' own pointers to the config record. They aren't aliases of 0x7A0438.
