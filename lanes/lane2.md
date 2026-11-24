# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/sound-environ 48390c47 562->562 Three commits. T00481920 is the 0x58-byte SoundEnviron.txt record that sub_00481920_GetSoundEnvironTxtRecord returns from SoundHdr's table (SoundHdr typed it D2SoundEnvironTxtStrc with one field named). Nine D2Client units had partial views; together they are the txt columns in order (Song, Day/Night Ambience, Day/Night Event, Event Delay, Indoors, Material1/2, the 13 EAX values), so one record with those names replaces them, in D2SoundEnvironTxt.h. T0046E1B0 is the IME context handle, now HIMC__ as windows.h spells it (chat and Unknown_0047CC90 already typedef it as HIMC). T005C40D0 in D2Game.h, SkillDruid and SkillNec is D2StatListStrc (what STATLIST_AllocStatList returns); VERIFIED b14bf7a3ff16fb8b1a6946230456cfef1b267482
  - Verified on c2f64d25 (#340), rebased onto 0b750228 (#341) without conflicts. Precheck of all 328 includers of D2Client.h, D2Game.h and the new header is equal there.
  - Outside lane 2: SoundHdr, SoundInst, SkillDesc x2, Missile, UnitSnd, Unknown_004B8100/004B8410/004DCAA0/004DF6C0, Gfx, chat, Unknown_0047CC90 (lanes 1 and 4), SkillDruid, SkillNec (lane 5), one forward declaration each in D2Client.h and D2Game.h.

- lane2/split-text-2 0e32edae 562->562 Replaces `lane2/split-text` (rebased onto #341; text_0049D5A0's conflict was #341 dropping a context comment on the line it renames). T0044CB60 is D2Win's split-text line, the record D2Win_AllocateSplitText allocates and D2Win_10200 frees; D2WinFont already calls it D2SplittedTextStrc with wszLine/pNextLine. It now has that name and those fields everywhere, in D2WinSplitText.h, which replaces the identical private copies in the two D2WinFont units and 23 D2Client units (four of them new in #341: Record, Unknown_00451290, Unknown_004BABF0, Unknown_004BBE10). QuestLog and editbox_004BB620 type the text as unsigned short* and keep their own copy under the new name; VERIFIED 32221e357e8371c824392d92947ecce50fbd75b3
  - On 0b750228 (#341). All 189 includers of D2Client.h and the new header build equal.
  - Outside lane 2: 27 D2Client units (lanes 1 and 4), D2WinFont x2 (lane 6), one forward declaration in D2Client.h.

- lane2/small-records-g-3 44e8d706 562->562 Replaces `lane2/small-records-g` and `-g-2` (rebased onto #341: Unknown_006B4C90.cpp joined Unknown_006B3570.cpp, which now holds the one D2Direct3D view; namesync has nothing to rename). Three commits. T004013C0 was two records: the Win32 SYSTEM_INFO in Fog's Unknown_00401070 and Storm's SFILE/SMEM is now D2SystemInfoStrc (D2Win32SystemInfo.h), and Fog's captured system info at 0x0074D88C, which FOG_GetSystemInfo returns, is D2FogSystemInfoStrc (D2FogSystemInfo.h) with the field names Unknown_00401070 already uses for its four globals (bCaptured, nOsKind, fOsVersion, dwTotalPhys); its partial views in ddCore, Unknown_00510020, SpriteCache, Skills and Unknown_006B3570 include the header. T00681490 is D2DrlgPathNodeStrc (D2DrlgRooms.h), T00473470 is D2WeatherParticleStrc (D2Client.h, D2ClientGame.h), T00481720 is Fog's AsyncData (forward declarations in D2Client.h, D2ClientSound.h); VERIFIED ce9e0de092168809d01abf27dae6ba7768bec4e7
  - Verified on c2f64d25 (#340), rebased onto 0b750228 (#341). Precheck of all 288 includers of the changed headers is equal there.
  - Outside lane 2: Fog and Storm units (lane 3), D2DDraw/D2Direct3D/D2CMP units and D2Direct3D.h (lanes 6 and 9), Skills, Gfx and the weather units (lanes 1 and 4), Unknown_00681490 (lane 8), Storm.h and D2Client.h (one forward declaration or type name each).

- lane2/small-records-f-3 bca90c8b 562->562 Replaces `lane2/small-records-f` and `-f-2` (rebased onto #341; SCmd.cpp's conflict was include lines only). Five commits, each a small header included only by the units that had the private copies: D2Win32Message.h (the Win32 MSG record; SCmd, MainMenus, SMSG, Unknown_00420220), D2CmdArg.h (gaCmdArguments' entry; ErrorManager, ErrorManager_004082E0, Safesock, Unknown_00404F40), D2DrlgWarp.h (the level warp list entry at D2DrlgStrc+0x90; Drlg, DrlgWarp, Unknown_0066AE70), D2ClientGfxState.h (the state overlay node, three partial views merged into one record, and its owner; the three Gfx units), D2CelDataHash.h (the cel data name hash and its entry, T00604AE0, now D2CelDataHashEntryStrc; CelDataHash, FastCmp, GfxHash, TileLib, plus the rename in SpriteCache and Unknown_005FE010). Views that differ under the same name stay private (ChatDlg's 0x10-byte MSG, WINMAIN's other D2CmdArgStrc, DrlgRoom's 16-int warp arrays); VERIFIED 3438458b050fe709b1408e55e004d69a936291e8
  - Verified on b28fd264 (#339), rebased onto 0b750228 (#341). Precheck of all 20 changed units is equal there.
  - Outside lane 2: SCmd, Gfx x3 (lanes 1 and 4), MainMenus (lane 6), SMSG, Unknown_00420220, Unknown_00404F40, the Fog units (lane 3), Drlg x3 (lane 8), the D2CMP units (lane 6).

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
16. (done: sound-environ, which also took T005C40D0.) The address names left in shared headers are Fog.h's QServer client and packet records (T006BFAD0, T006C23B0); Fog's QServer units have several overlapping views of them (D2QClientStrc, D2QConn006C23B0Strc, D2QMsg006C23B0Strc, ...), so I'm leaving them to lane 3's unit work. Single-unit address names (T006090E0 in LRUCache, T00648730 in Path, T004DA110 in GfxUtil, T00516950 in D2SoundUtil, T00552FD0 in SUnit) belong to those units.
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
