# Lane 2

Written by lane 2 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane2/storm-arrays bcdaba7c 562->562 Stacked on `lane2/storm-hash` (its first commit is storm-hash's, rebased; post them together or storm-hash first). Storm's growable and fixed arrays are viewed under about 30 names (D2StormSlotArrayStrc and D2StormEntryArrayStrc in D2CmpStormList.h, D2StormArray408Strc in D2CMP.h/Fog.h/Storm.h, and private copies such as D2StormArrayB/CStrc, D2StormListArrayStrc, D2StormGameArrayStrc, D2CommonStormSlotArrayA/BStrc and the other D2StormArrayAStrc copies), all capacity/count/data/chunk at 0x00/0x04/0x08/0x0C. Their f_0/f_4/f_8/f_C are now m_alloc/m_count/m_data/m_chunk, as #346's D2StormArrayA.h names them, with the derived types, member functions and callers (43 files); VERIFIED 158afb8970e26b72915ee328c30e884633a953b7
  - Verified on 900824d3 (#345), rebased onto 88003a4d (#346). Merges cleanly with storm-bitoutput and small-records-g-5. Precheck of all 308 includers was equal on #345.
  - Outside lane 2: Storm, Fog and LogManager units (lane 3), D2CMP units (lane 6), D2Client units (lanes 1 and 4), D2BNClient BnSend/BNNews (lane 6), Ignorelist and Unknown_0066D7E0 (lane 8), member names in D2CMP.h, D2CmpStormList.h, Fog.h, Storm.h.

- lane2/storm-hash 84c2e562 562->562 One commit; merges cleanly with storm-array, storm-bitoutput, split-text-3 and small-records-g-4. Every record with m_linktoslot at 0x04 is a view of Storm's hash table entry (TSHashObject): hash value (masked to pick the slot), slot link, full-list link, key. Their f_0/f_C/f_14 are now Storm's names m_hashval/m_linktofull/m_key, in D2CMP.h, D2CmpStormHash.h, D2Client.h, Storm.h and the private copies in Unknown_00604070, both Game.cpp files, Unknown_0044F9B0/0044F9D0/00450950, Ignorelist and LogManager, with the member functions and callers that read them; VERIFIED 4c50534f1f7e5dd45a08213a7d7ef5f191c8a348
  - On 900824d3 (#345). All 260 includers of the changed headers build equal.
  - Outside lane 2: Storm, Fog and LogManager units (lane 3), D2CMP units (lane 6), D2Client units (lanes 1 and 4), D2Game/Game.cpp (lane 5), Ignorelist (lane 8), member names in D2CMP.h, D2Client.h, Storm.h.

- lane2/storm-bitoutput 17c33fa5 562->562 One commit, independent of storm-array (they merge cleanly together). CBitOutput's 0x04 (D2StormBitOutput.h) is the count of output bytes still free: PutBits and Flush write only while it is non-zero and decrement it per byte, now nBytesLeft. D2ChatStormBaseArrayA/BStrc (D2CMP.h, D2Client.h, Storm.h and the private copies in Unknown_0044F9D0, Ignorelist, LogManager) are Storm's base array, capacity/count/elements; their f_0/f_4/f_8 are now m_alloc/m_count/m_data, as in D2StormArrayAStrc; VERIFIED 3a705a1213126b6ffd5f6abbca3100d98b055c1f
  - On 900824d3 (#345). All 257 includers of the changed headers build equal.
  - Outside lane 2: Storm units, LogManager (lane 3), D2CMP units (lane 6), Game, Game_0044D080, Unknown_0044F9B0/0044F9D0 (lanes 1 and 4), Ignorelist (lane 8), member names in D2CMP.h, D2Client.h, Storm.h.

- lane2/small-records-g-5 dd30f0eb 562->562 Replaces `lane2/small-records-g` through `-g-4` (rebased onto #346; Skills.cpp's conflict was include lines only. -g-4 was redone on #344: ddCore took in Unknown_00510020 and ErrorManager changed, so the record change was reapplied rather than merged; its first commit, D2Win32SystemInfo.h, is already in #342). Two commits. Fog's captured system info at 0x0074D88C, which FOG_GetSystemInfo returns, is D2FogSystemInfoStrc (D2FogSystemInfo.h) with the field names Unknown_00401070 uses for its four globals (bCaptured, nOsKind, fOsVersion, dwTotalPhys); the views in ErrorManager x2, Safesock, ddCore, SpriteCache, Skills and Unknown_006B3570 include the header. T00681490 is D2DrlgPathNodeStrc (D2DrlgRooms.h), T00473470 is D2WeatherParticleStrc (D2Client.h, D2ClientGame.h), T00481720 is Fog's AsyncData (forward declarations in D2Client.h, D2ClientSound.h); VERIFIED 2bdf8d6329d3e026b2cb286b91ed35e0d425cbe0
  - Verified on d5c95493 (#344), rebased onto 88003a4d (#346). Precheck of all 240 includers of the changed headers is equal there.
  - Outside lane 2: Fog units (lane 3), ddCore, Unknown_006B3570, SpriteCache and D2Direct3D.h (lanes 6 and 9), Skills, Gfx and the weather units (lanes 1 and 4), Unknown_00681490 (lane 8), D2Client.h (forward declarations).

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
17. (done: storm-arrays)
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
