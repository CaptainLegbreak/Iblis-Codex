# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/small-records-d-2 55410626 562->562 Replaces `lane2/small-records-d` (rebased onto #339; namesync has nothing to rename). Two small headers, each included only by the units that had identical private copies: D2UnitDropPacket.h (the 10-byte drop-items packet SCMD_DropUnitItems reads; SCmd, CharSel_0042E600) and D2DrlgDelete.h (the deletion node an active room keeps in pDrlgDelete; Dungeon, Level, PlrSave). CharSel.cpp now keeps its own drop-packet copy: with #336's D2LaunchRequest.h also included there, 0x439210 swaps the operands of one add (either header alone is equal, both are not); VERIFIED c2ab76bf23b4af2eb144967e426ecf093f045090
  - Verified on 55b20d70 (#338), rebased onto b28fd264 (#339). Precheck is equal there.
  - Outside lane 2: SCmd (lane 4), CharSel_0042E600 (lane 6), Dungeon (lane 8), Level and PlrSave (lane 5).

- lane2/small-records-f-2 06753c8e 562->562 Replaces `lane2/small-records-f` (rebased onto #340; its Safesock.cpp conflict was include lines only; namesync has nothing to rename). Five commits, each a small header included only by the units that had the private copies: D2Win32Message.h (the Win32 MSG record GetMessage/PeekMessage fill; SCmd, MainMenus, SMSG, Unknown_00420220), D2CmdArg.h (gaCmdArguments' entry; ErrorManager, ErrorManager_004082E0, Safesock, Unknown_00404F40), D2DrlgWarp.h (the level warp list entry at D2DrlgStrc+0x90; Drlg, DrlgWarp, Unknown_0066AE70), D2ClientGfxState.h (the state overlay node, three partial views merged into one record, and its owner; the three Gfx units), D2CelDataHash.h (the cel data name hash and its entry, which was T00604AE0 and is now D2CelDataHashEntryStrc; CelDataHash, FastCmp, GfxHash, TileLib, plus the rename in SpriteCache and Unknown_005FE010). Views that differ under the same name stay private (ChatDlg's 0x10-byte MSG, WINMAIN's other D2CmdArgStrc, DrlgRoom's 16-int warp arrays); VERIFIED 3438458b050fe709b1408e55e004d69a936291e8
  - Verified on b28fd264 (#339), rebased onto c2f64d25 (#340). Precheck of all 20 changed units is equal there.
  - Outside lane 2: SCmd, Gfx x3 (lanes 1 and 4), MainMenus (lane 6), SMSG, Unknown_00420220, Unknown_00404F40, the Fog units (lane 3), Drlg x3 (lane 8), the D2CMP units (lane 6).

- lane2/small-records-g-2 b964479a 562->562 Replaces `lane2/small-records-g` (rebased onto #340; Unknown_0040E300.cpp, which it touched, is gone from main and its private copy of the record went with it, so that file is left out; Safesock.cpp's conflict was include lines only). Three commits, independent of small-records-f-2. T004013C0 was two records: the Win32 SYSTEM_INFO in Fog's Unknown_00401070 and Storm's SFILE/SMEM is now D2SystemInfoStrc (D2Win32SystemInfo.h), and Fog's captured system info at 0x0074D88C, which FOG_GetSystemInfo returns, is D2FogSystemInfoStrc (D2FogSystemInfo.h) with the field names Unknown_00401070 already uses for its four globals (bCaptured, nOsKind, fOsVersion, dwTotalPhys); its partial views in ddCore, Unknown_00510020, SpriteCache, Skills and two D2Direct3D units now include the header. Three more address names in shared headers: T00681490 is D2DrlgPathNodeStrc (D2DrlgRooms.h), T00473470 is D2WeatherParticleStrc (D2Client.h, D2ClientGame.h), T00481720 is Fog's AsyncData (a forward declaration in D2Client.h, D2ClientSound.h); VERIFIED ce9e0de092168809d01abf27dae6ba7768bec4e7
  - On c2f64d25 (#340). All 289 includers of the changed headers build equal.
  - Outside lane 2: Fog and Storm units (lane 3), D2DDraw/D2Direct3D/D2CMP units and D2Direct3D.h (lane 6 and 9), Skills, Gfx and the weather units (lanes 1 and 4), Unknown_00681490 (lane 8), Storm.h and D2Client.h (one forward declaration or type name each).

- lane2/split-text 8c3ea9bf 562->562 T0044CB60 is D2Win's split-text line, the record D2Win_AllocateSplitText allocates and D2Win_10200 frees as a list. D2WinFont and D2WinFont_00501DF0 already define it as D2SplittedTextStrc with wszLine/pNextLine; it now has that name and those fields everywhere, in a small D2WinSplitText.h that replaces the identical private copies in the two D2Win units and 19 D2Client units (D2WinFont also loses its second, void*-typed copy). QuestLog and editbox_004BB620 type the text as unsigned short*, so they keep their own copy under the new name; VERIFIED b89d612a445c3faa7b7a6467d1b7dcd0db298050
  - Verified on b28fd264 (#339), rebased onto c2f64d25 (#340): the conflicts in text.cpp, Unknown_004A43E0 and Unknown_004A6460 were include lines only. Precheck of all 187 includers of D2Client.h and the new header is equal there.
  - Outside lane 2: 22 D2Client units (lanes 1 and 4), D2WinFont x2 (lane 6), one forward declaration in D2Client.h.

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
9, 10, 12. (done: client-records-b)
11. Skipped: ChatDlg's D2CharSaveFileStrc is a 0x2000-byte view of the .d2s file that reads 0x18 as old flags; merging it with D2SaveHeaderStrc needs a union there. The ladder entry alone isn't worth a header.
16. Next: T00481920 is the SoundEnviron.txt record (sub_00481920_GetSoundEnvironTxtRecord); its nine partial views in D2Client name Song/ambience/event/indoors/material/EAX fields at the txt column offsets, so one record replaces them. T0046E1B0 is the IME context handle (HIMC__, as windows.h spells it, like HWND__).
15. (done: split-text)
14. (done: small-records-f, small-records-g)
13. Rescan on #332 done. Taken from it: records-c. Next from it: D2UIVarRecordStrc (Select, automap, ui, Unknown_0046ACE0); D2UiCelFileStrc (spellsel, Unknown_004A76C0/004A9BD0/004AA9C0); D2DrlgDeleteStrc (Dungeon, Level, PlrSave); D2UnitDropItemsPacketStrc (SCmd, CharSel, CharSel_0042E600); D2SoundUnitNodeStrc and D2DialogWidgetNodeStrc (sound and dialog units). The big clusters in text/Unknown_004A43E0/004A6460 and inv/Unknown_00482C70 look like context copies, so I'm leaving them to the unit work.
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
