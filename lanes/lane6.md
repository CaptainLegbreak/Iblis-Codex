# Lane 6

Written by lane 6 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane6/bnsend-empty d1c5a247 0 placeholders (plan-only). The 4 zero bytes at 0x006DEF80 sit among BnSend.cpp's .rdata literals (after "Registration Version", before ".\BnSend.cpp") and BnSend reads them first (szEmpty_006DEF80); SRP's SHA1 pad gabSha1Pad00 (lane 3's SHA.cpp, unchanged) reads the same bytes. Planned in BnSend.cpp as one record with both names as alternatenames. Not stacked; independent of celcmp-rtti; no other lane's file changed. VERIFIED 6ecb4ee2 (on #351; borrowed data 1,114 -> 1,107 B).


## Claimed

- ChatDlg.cpp's object, what's left: 0x004423B0, 0x00445020, 0x004450D0, 0x004456D0, 0x0043F850 and 0x00445FF0 build unequal in ChatDlg.cpp even with noinline on their callees. Game.cpp's 0x0043DB10 and 0x0043F840 (lane 4's file) are inside the object: lane 4, they're yours to hand over when convenient.

## Handover to lane 8 (D2Common)

All my D2Common branches are merged (path-d-2 in #327). Nothing of mine is in flight there. Open items:
- Question (was mine for the coordinator): PathWF.cpp (0x0067C2D0, its only function) calls the static 0x0067B9F0 and carries marked copies of 0x0067B9F0 and 0x0067BD80, so it is one object with the tail run 0x0067B9C0-0x0067C1C8 (Unknown_0067B9C0.cpp). "PathWF.cpp" is a D2MOO name and there is no assert. Join them under one name; the static's shim goes away with the join.
- Borrowed functions: 0x0062B5B0 (Items.cpp; 0x00628830 takes nRequiredLevel in eax; same length reached, the original keeps nRequiredLevel in esi, ours spills it). 0x00677880 (needs DRLG/OutPlace.cpp and Unknown_00675600.cpp joined; 296 B of borrowed data at 0x006F13F0 comes with it). 0x00679C80 (needs Unknown_006793E0 (/GS-) and Unknown_00679A60 joined; path-b/c/d regrouped that area, check what is left).
- Language splits in language-objects.md: FieldTbls.cpp (15 copies), MonsterTbls (5), Waypoint (5) and the other D2Common rows.
- Left in place, with reasons (also in "Left in place" below): PATHMISC_SetRoom 0x0064FAA0 (callerless static), Unknown_00650D70, Path.cpp 0x00648020, DUNGEON_ 0x00643260-0x00643560, Items.cpp 0x006313E0-0x006314A0, OutDesr.cpp 0x006801A0-0x006803D0.
- Tools I used for the path cluster (data-reader map, const-table groups) are described in the path-b/c/d commit messages (#326, #327).

## Handover to lane 9 (renderers, D2Hell)

Nothing of mine in flight. Open items:
- D2DDraw software renderer 0x00511DF0-0x005132C0: ddCore.cpp is asserted only at 0x00511B80-0x00511CE0, and 0x007C9138 is shared by a dozen files; Unknown_00512930, Unknown_00512C20 and the rest of Unknown_005125E0 stay until something ties them.
- glVertex.cpp 0x0050D6A0 waits on lane 2's shared D2GlideSettingsStrc (the private copy lacks bLowQuality).
- d3dSprite pieces: shelved join (calling-convention shims, conflicting prototypes), waiting on shared headers.
- Strays in Storm's range (see the lane 3 note below): D2Gdi Unknown_006C81A0/_006C84B0/_006C86A0/_006C8750, D2Direct3D Unknown_006B1C70, D2Hell Unknown_006CAE5F and Unknown_006CB401.

## Notes for other lanes

- **Lane 4 and lane 8, the same fix in your files:** a TypeDescriptor header (type_info vftable pointer, spare word) is still copied before a planned type name at 0x0070F564 (before gszTypeSGameData, D2Client/Unknown_0044F9B0.cpp), 0x0070F5EC (before gszTypeHashObjectChunk, same file) and 0x00743624 (after 3 B of padding, before gszTypeNameMappingEntryNode_0074362C, D2Common/Chat/Ignorelist.cpp). An 8-B bytes record at each, with the pointer to gData_006F28F8, places them (lane6/celcmp-rtti does it for CelCmp.cpp).
- Coordinator (borrowed data): several small lane-6 blocks are RTTI TypeDescriptor headers, not data: 8 bytes {&type_info vftable 0x006F28F8, 0} in front of a planned ".?AV...@@" name string (0x00741F0C and 0x00741FAA in CelCmp.cpp, 0x00743621 before Ignorelist.cpp's ChatIgnoreList name, 0x0074C0C8 before ATL's Thank_you@Define_the_symbol__ATL_MIXED). They should come from the compiler as ??_R0 symbols, the way WardenClient's do, rather than as data. I have left them.

- Lanes 3 and 5: two named definitions swallow a language-table copy that belongs to the next file. gaTable_0070896C (Storm/Unknown_00426900.cpp) holds 0x00708970, MainMenus.cpp's copy. gabDirection8To64 (D2Game ItemMode.cpp) holds 0x00745738, Skills.cpp's. Those definitions are probably sized too big.
- Lane 3: D2Gdi `Unknown_006C81A0`, `Unknown_006C84B0`, `Unknown_006C86A0`, `Unknown_006C8750` sit in the Storm SCMD run; D2Direct3D `Unknown_006B1C70` sits in the Fog QServer run; MainMenus 0x00409020 and 0x004107F0 are Fog code. Storm-region stubs: D2Win `Unknown_006B1BC0`, D2Hell `Unknown_006CAE5F`, D2CMP `Unknown_006CB4C0`. SRP 0x00528550, 0x00528890. Yours to place; lane 6 has not moved them.
- Lane 4: D2Client-range functions filed in lane-6 files: CharSel/ComCallback/ChatDlg 0x00451920, 0x00453470, 0x00458CD0, 0x004756D0, 0x00478160, 0x0044CCA0, 0x00451B30, 0x00451DB0, 0x00449AD0, 0x0044A130; D2Hell `Unknown_006CB401`.
- Lane 5: D2Game-range functions in SpriteCache.cpp: 0x005B72A0, 0x005B8740, 0x005C2FE0, 0x005DD280, 0x005E5270, 0x005EDC40, 0x005EE5C0, 0x005EF310; D2Net 0x0052BF40.

## Left in place (and why)

- 0x006FFF80 (64 B) is the linker's RSDS debug record (Game.pdb path), counted as stamp, not borrowed data. 0x00700A6C (4 zero B after ___rtc_tzz) and 0x0070244C (8 zero B before the import descriptors) are CRT/linker tail bytes, not lane 6 objects. 0x0072FFA4 (4 zero B between BNNews.cpp's type name and BnDownload.cpp's gnLastStatus) has no reader; most likely BnDownload's .data alignment, so no record.
- MainMenus.cpp 0x0070C204 (4 B, the start of gatControlTemplates[0x11A], written by 0x0042F540): a 4-B planned record there, like entry 0x11B's gData_0070C234, verifies but does not place; the bytes stay copied.
- D2WinFont_00501DF0.cpp (0x00501DF0, 0x00501FE0, 0x00502970): inside D2WinFont.cpp's run, but it builds equal only with a POD Unicode; in D2WinFont.cpp (D2Unicode.h) the frame grows by 4 B and registers change. Same case as MainMenus_00431AF0.
- D2Win_10076 0x004FFE10 (in D2WinTextBox.cpp): inside EditBox's run, but it zeroes its buffer with an inline rep stosd, and D2WinEditBox.cpp has #pragma function(memset) (its other functions call memset).
- D2SoundSmp_005153C0.cpp: inside D2SoundSmp's run; in D2SoundSmp.cpp its true body allocates registers differently, so D2SoundSmp.cpp keeps its context copy.
- D2Lang 0x00526100-0x00527BE0: three data-less objects lie between the UTF-8 table's object and SRP.cpp's, but the casetable's object (copy 0x00730538) comes before the UTF-8 one in .data while its readers come after in code, so the code order there is not settled yet.
- D2Net/D2Game edge: ganClientPacketSizes (Unknown_0052B920.cpp, 572 B) holds two copies after its 452 B; the two data-less objects sit in the interleaved D2Net/Game.cpp stubs 0x0052BDA0-0x0052BFE0, and nothing there says which.
- D2CMP 0x0060AE80 and 0x0060B130-0x0060B1F0 (bit-buffer helpers, FastCmp.cpp's CodecSkipBits): between CelDataHash.cpp and the Codec run, no callers. CodecInitLock/CodecReleaseLock 0x0060CD30/0x0060CD50 (in GfxHash.cpp) and FindTileHash 0x0060CD70 (in FastCmp.cpp): between Codec.cpp and FindTiles.cpp, inferred names. Both sides weak.

- PATHMISC_SetRoom 0x0064FAA0 (Unknown_0064FAA0.cpp): it is static (pPath in ESI), but nothing in the image calls it. It sits between Composit.cpp and the new Unknown_0064FAD0.cpp run.
- Unknown_00650D70.cpp (0x00650D70-0x00650EA0): it lies between the 0x0064FB90 run and MonsterTbls.cpp, and nothing ties it to either.

- Path.cpp 0x00648020 (sub_00648020_GetTablePair, in Unknown_00648020.cpp): it shares gnOrthogonalStepTable with Path.cpp's 0x00648050, but no code calls it. Its register calling convention reproduces only with the placeholder's dummy caller (sub_K15_Emit8), so it stays until that pattern has a home in Path.cpp.
- CharSel_0042FFE0.cpp 0x0043B080 shares CharSel.cpp's gapszSkyPalette, but in CharSel.cpp it inlines a callee the original calls. The table is declared extern, so it is no proof, and the piece stays.
- DUNGEON_ coordinate functions 0x00643260-0x00643560: filed alternately in Drlg.cpp and Skills.cpp, so there is no run. Drlg.cpp is asserted only to 0x00643060, and the names are d2moo. Unknown_00641320's 0x006432C0 and Unknown_00643560 stay.
- D2DDraw software renderer 0x00511DF0-0x005132C0: ddCore.cpp is asserted only at 0x00511B80-0x00511CE0, and the shared global 0x007C9138 is used by a dozen files. No run, so Unknown_00512930, Unknown_00512C20 and the rest of Unknown_005125E0 stay.
- Items.cpp 0x006313E0-0x006314A0 (Unknown_00631430): Items.cpp is scattered into ItemTbls.cpp's asserted span (0x006315D0-0x00639CC0), so adjacency here says little.
- Waiting on lane 2's shared structs: glVertex.cpp 0x0050D6A0 (private D2GlideSettingsStrc lacks bLowQuality); UNISYS.CPP 0x00527A50 (unequal); CACHE.CPP 0x005191D0 (private D2CacheHeaderStrc, and its static callee must move with it).
- `MAINMENUS_ReturnToCharSelect` (0x0042FDD0) stays in MainMenus.cpp, per the coordinator. It is probably misfiled: 15 bytes, and 0x00435030 and 0x004361B0 (both in MainMenus.cpp by shared globals) call it without inlining; it lies before the asserted span (0x00430A20-0x00434060). Evidence is in the block-c commit message (#294).
- D2CMP palette code 0x00604DB0-0x006069F0 (FastCmp.cpp Palette* functions 0x006056D0, 0x006057A0, 0x00605880, 0x006059B0, and its neighbours in Palette.cpp, Tilecmp.cpp, TileLib.cpp, Unknown_00604DB0.cpp, Unknown_006056D0.cpp): no assert path, no small cross-file calls, no data to test; nothing in the image names a D2CMP Palette.cpp.
- OutDesr.cpp 0x006801A0-0x006803D0: sits between OutWild.cpp's 0x00680040 and 0x006804E0, and OutWild's Act 1 init (0x006807F0) calls 0x00680200; but every name on both sides is inferred or d2moo, and no inlined copies show. Both weak.
- D2Launch/D2Multi interleave, neighbours in different files: 0x00430590 (ComCallback.cpp), and in CharSel.cpp 0x0043D990, 0x0043DB20, 0x0043DC30, 0x0043E130, 0x004429A0, 0x004437E0, 0x00443F80, 0x00446890.
- Shelved joins: d3dSprite pieces (calling-convention shims, conflicting prototypes); CelCmp pieces (own Storm templates); MainMenus_00431AF0 (POD Unicode). They wait on lane 2's shared headers.
