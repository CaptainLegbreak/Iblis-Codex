# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/com-interface 5ba0cf48 581->581 D2ComInterfaceStrc: one record for the 0x225 interface table (D2Launch's D2FuncTable_0077ABF0Strc, MainMenus_00431AF0's private D2FuncTable, the private copies in Storm Unknown_00404F40 and Game_0044E5A0), in its own header D2ComInterface.h; D2ConfigStrc::pComInterface takes that type; VERIFIED 864dca04b8728bdfeefb473f17bf66c847764da6
  - Based on main #297 (34ce356b), not stacked.
  - Outside lane 2: type renames in D2Launch, D2Multi and D2Win units (lane 6). Private copies are dropped in Storm Unknown_00404F40 (lane 3), which now reads the shared D2ConfigStrc, and in Game_0044E5A0 (lane 4). MainMenus_00431AF0 uses `gpFuncTable_0077ABF0` instead of its second name `gpFuncTable` for 0x0077ABF0.
  - Precheck: all includers of D2MultiTypes.h, D2Launch.h and D2Multi.h plus the changed units build equal.

## Questions

- The client's D2ClientNotifyStrc (D2ClientUi.h, used by GAME_GetClientNotify and its callers) is the same table, but I left it as a separate view. Any change to D2ClientUi.h flips gnScreenHeight/gnPanelOffsetY operand order in inv_0048BC10 and inv_0048DD90 (lane 4). Nothing natural I tried fixed it, about 60 combinations: where the include goes, how the gaps are written, where the declarations sit in D2Client.h, and using one name for 0x711470 in those units. Main's D2ClientUi.h keeps them equal. Should it stay a view until those units change for other reasons, or do you want the merge forced some other way?

## Notes for other lanes

- Lanes 1 and 4: the 0x225 table, and the pointer the client keeps at 0x007A05F4, is D2ComInterfaceStrc (D2ComInterface.h). 0xC4 is `pfnClose`. D2ClientNotifyStrc is a temporary view of the same table.
- Lane 1: 0x711470 has two names, `gnScreenHeight_00711470` in D2Client.h and `gnScreenHeight` declared privately in about 60 units. Left alone; your header.

## Left in place (and why)

- D2ClientNotifyStrc in D2ClientUi.h (see Questions). GAME_GetClientNotify still converts `gpClientConfig->pComInterface` to it.
- D2Launch's `gpLaunchRecord` (0x7795D4) and D2Multi's `gpCharInfo` are their modules' own pointers to the config record. They aren't aliases of 0x7A0438.
