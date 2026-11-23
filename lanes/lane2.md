# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/config-record-3 ad384c0b 581->581 D2ConfigStrc: the configuration record (was D2LaunchRecordStrc) with its field names, one client global `gpClientConfig` at 0x7A0438 in D2Client.h, private copies dropped, GAME_GetClientNotify declared once in D2Client.h; VERIFIED 85ec161326338788b4045cec50278ad7d468a41b
  - Based on main #294 (a337ecd8), not stacked. Replaces `lane2/config-record` and `lane2/config-record-2`; drop both.
  - Outside lane 2: renames in D2Client units (lanes 1 and 4), D2Launch/D2Multi/D2Win (lane 6) and Storm Unknown_00405710 (lane 3). Field and global renames only, plus dropped private record copies.
  - Precheck: all 228 includers of D2Client.h, D2MultiTypes.h and D2Launch.h plus the changed units build equal.

## Questions

## Notes for other lanes

- All lanes: the 0x7A0438 client global is `gpClientConfig` (type `D2ConfigStrc*`, declared in D2Client.h). Don't declare it privately. `GAME_GetClientNotify` is in D2Client.h too.
- Lane 1: 0x711470 has two names, `gnScreenHeight_00711470` in D2Client.h and `gnScreenHeight` declared privately in about 60 units. Left alone; your header.

## Left in place (and why)

- The 0x225 callback table still has several views: D2FuncTable_0077ABF0Strc (D2MultiTypes.h), D2ClientNotifyStrc (D2ClientUi.h), D2ComInterfaceStrc (private in Storm Unknown_00404F40), and D2FuncTable (private in MainMenus_00431AF0, gpFuncTable 0x77ABF0). Their fields don't overlap, so they can merge into one record. That's my next branch, per the decision that the table is one record. Until then, D2ConfigStrc+0x225 has one member type and GAME_GetClientNotify converts it.
- Storm Unknown_00404F40 keeps its private D2ConfigStrc copy until the table merge, because it reads 0x225 as the third view.
- D2Launch's `gpLaunchRecord` (0x7795D4) and D2Multi's `gpCharInfo` are their modules' own pointers to the record. They aren't aliases of 0x7A0438.
