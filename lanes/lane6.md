# Lane 6

Written by lane 6 only. Newest entries at the top of each section; delete what is done.

## Ready

- lane6/codec-a fa7a174b 518->514 Codec.cpp takes twelve DCC helpers from five D2CMP placeholders (Unknown_0060B200, _0060B280, _0060B530 and _0060B9A0 go; seven functions from Unknown_0060AE80, one from Unknown_0060B160); VERIFIED 61641d09
  - Based on #319. Not stacked. Everything stays in lane 6.
  - Evidence: 0x0060B200 (EDI), 0x0060B4B0 (ESI), 0x0060B530 (EDI/EAX/ECX) and 0x0060B640 (EAX) take register arguments, so they are static, and their callers are 0x0060B280, 0x0060B7B0, 0x0060B9A0 and Codec.cpp's 0x0060BFF0. Contiguous code then makes 0x0060B200 through the end of 0x0060BFF0 one object. Codec.cpp's .rdata block, which ends with its path string between CelDataHash.cpp's and FindTiles.cpp's, holds the tables those helpers read.
  - 0x0060B7B0 stays in Unknown_0060B7B0.cpp, though it is in the run: its true body changes how 0x0060BFF0 assigns stack slots (MSVC uses a static callee's register use), so the two need tuning together.

## Questions

## Notes for other lanes

- Lanes 3 and 5: two named definitions swallow a language-table copy that belongs to the next file. gaTable_0070896C (Storm/Unknown_00426900.cpp) holds 0x00708970, MainMenus.cpp's copy. gabDirection8To64 (D2Game ItemMode.cpp) holds 0x00745738, Skills.cpp's. Those definitions are probably sized too big.
- Lane 3: D2Gdi `Unknown_006C81A0`, `Unknown_006C84B0`, `Unknown_006C86A0`, `Unknown_006C8750` sit in the Storm SCMD run; D2Direct3D `Unknown_006B1C70` sits in the Fog QServer run; MainMenus 0x00409020 and 0x004107F0 are Fog code. Storm-region stubs: D2Win `Unknown_006B1BC0`, D2Hell `Unknown_006CAE5F`, D2CMP `Unknown_006CB4C0`. SRP 0x00528550, 0x00528890. Yours to place; lane 6 has not moved them.
- Lane 4: D2Client-range functions filed in lane-6 files: CharSel/ComCallback/ChatDlg 0x00451920, 0x00453470, 0x00458CD0, 0x004756D0, 0x00478160, 0x0044CCA0, 0x00451B30, 0x00451DB0, 0x00449AD0, 0x0044A130; D2Hell `Unknown_006CB401`.
- Lane 5: D2Game-range functions in SpriteCache.cpp: 0x005B72A0, 0x005B8740, 0x005C2FE0, 0x005DD280, 0x005E5270, 0x005EDC40, 0x005EE5C0, 0x005EF310; D2Net 0x0052BF40.

## Left in place (and why)

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
