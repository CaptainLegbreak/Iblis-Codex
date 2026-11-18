# Status

Generated from the build data. Every address below is a virtual address in the 1.14d Game.exe.

| | |
|---|---|
| Functions | 14927 |
| Verified (built from source) | 14916 (2,601,688 bytes) |
| Unmatched (taken from your Game.exe) | 11 (12,434 bytes) |
| Function bytes verified | 99.524 % |
| Game.exe bytes built from source (code, generated data, runtime, imports, linker output, padding) | 3,578,383 of 3,618,792 (98.88 %) |
| Game.exe bytes taken from your Game.exe (unmatched code, undefined data, resources, stamps, signature) | 40,409 |
| Output SHA-256 equals the original | yes |
| Names: blizzard / d2moo / placeholder | 173 / 4394 / 10360 |

Bytes of the built Game.exe by origin:

| Origin | Bytes |
|---|---:|
| game code and data compiled from Source/ | 2,686,992 |
| initialised data generated from your Game.exe (build/data_plan.json) | 362,543 |
| C runtime (libcmt.lib, placed by identity) | 239,696 |
| import thunks and the import address table | 3,782 |
| headers, import and export tables, relocations, checksum | 163,407 |
| alignment padding | 121,963 |
| code taken from your Game.exe (unmatched functions) | 12,434 |
| data no source defines yet, taken from your Game.exe | 15,687 |
| resources (from your Game.exe) | 5,888 |
| link timestamps, Rich header, debug directory | 272 |
| Authenticode signature | 6,128 |

## Two builds

`tools/build.py` links every function at its original address and produces a file byte-identical with the original:
it proves that each verified function is the game's own code. `tools/link.py` links the same objects as an ordinary
program (the linker chooses the layout, the image is relocatable): it proves that the sources form one complete
program, with every reference resolved to exactly one definition. See README, "Building".

## Unmatched functions

These have no verified source yet. The byte-exact build takes their bytes from your Game.exe. The ordinary build
uses a functional replacement for each instead, written to do what the original does; the replacements are not the
original code, compile to different bytes, and are never used by the byte-exact build.

| Address | Size | Name | Replacement in the ordinary build |
|---|---:|---|---|
| 0x004A4AD0 | 1232 | sub_004A4AD0 | `Source/StandIns/D2Client_004A4AD0.cpp` |
| 0x004F8B80 | 561 | sub_004F8B80 | `Source/StandIns/D2Win_004F8B80.cpp` |
| 0x00502550 | 105 | sub_00502550 | `Source/StandIns/D2Win_00502550.cpp` |
| 0x0055A6D0 | 2253 | sub_0055A6D0 | `Source/StandIns/D2Game_0055A6D0.cpp` |
| 0x005DD7F0 | 1084 | sub_005DD7F0 | `Source/StandIns/D2Game_005DD7F0.cpp` |
| 0x005EDC50 | 791 | sub_005EDC50 | `Source/StandIns/D2Game_005EDC50.cpp` |
| 0x0062B5B0 | 1192 | sub_0062B5B0 | `Source/StandIns/D2Common_0062B5B0.cpp` |
| 0x0065F470 | 288 | sub_0065F470 | `Source/StandIns/D2Common_0065F470.cpp` |
| 0x00677880 | 4232 | sub_00677880 | `Source/StandIns/D2Common_00677880.cpp` |
| 0x00679C80 | 450 | sub_00679C80 | `Source/StandIns/D2Common_00679C80.cpp` |
| 0x006BD230 | 246 | sub_006BD230 | `Source/StandIns/Fog_006BD230.cpp` |

## Non-original constructs

Functions whose source needs something the original source very likely did not have to produce the original bytes: a per-file compiler option other than the default (`build/config.json`), link-time code generation, a calling-convention shim for a register-argument function, or inline assembly.

Not listed one by one: 2332 functions are compiled with `/GS-` and 91 with `/EHsc` (see `build/units.json`); the sources use `__declspec(noinline)` 2580 times and `__declspec(dllexport)` 178 times to keep a body out of line or emitted.

| Address | Name | Construct |
|---|---|---|
| 0x004013C0 | sub_004013C0_TerminateCurrentProcess | compiler option /EHa |
| 0x004013D0 | sub_004013D0_GetCurrentProcessThreadCount | compiler option /EHa |
| 0x00401690 | sub_00401690_GetCurrentThreadId | compiler option /EHa |
| 0x00401740 | sub_00401740_SetText | compiler option /EHa |
| 0x00401DF0 | sub_00401DF0_GetModuleFromAddr | calling-convention shim, link-time code generation (/GL /LTCG) |
| 0x00401F10 | sub_00401F10_GetSymbolFromAddr | link-time code generation (/GL /LTCG) |
| 0x004020D0 | sub_004020D0_GetLineFromAddr | calling-convention shim, link-time code generation (/GL /LTCG) |
| 0x004021D0 | sub_004021D0_EnumerateModules | link-time code generation (/GL /LTCG) |
| 0x00402280 | sub_00402280_SetSearchPath | link-time code generation (/GL /LTCG) |
| 0x00402380 | sub_00402380_FindFileInPath | link-time code generation (/GL /LTCG) |
| 0x00402460 | sub_00402460_LoadModule | calling-convention shim, link-time code generation (/GL /LTCG) |
| 0x00402530 | sub_00402530_UnloadModule | link-time code generation (/GL /LTCG) |
| 0x004025F0 | sub_004025F0_StackWalk | link-time code generation (/GL /LTCG) |
| 0x004026D0 | sub_004026D0_WriteMiniDump | link-time code generation (/GL /LTCG) |
| 0x004027C0 | sub_004027C0_DbgHelpThreadProc | compiler option /EHa |
| 0x00402AE0 | sub_00402AE0_ShutdownSymbols | link-time code generation (/GL /LTCG) |
| 0x00402D60 | sub_00402D60_FormatStackFrame | calling-convention shim, link-time code generation (/GL /LTCG) |
| 0x00403100 | sub_00403100_PrintFrames | link-time code generation (/GL /LTCG) |
| 0x00403F60 | sub_00403F60_SetCrashHandler | compiler option /EHa |
| 0x00404210 | sub_00404210_CreateProcessUtf8 | compiler option /EHa |
| 0x00404330 | sub_00404330_FileExistsUtf8 | compiler option /Oy, without /Oy- |
| 0x00404560 | sub_00404560_UseWidePath | compiler option /EHa |
| 0x00404AB0 | sub_00404AB0_VisitModule | compiler option /Oy |
| 0x00404C60 | sub_00404C60_EnumModulesPsapi | compiler option /Oy, without /Oy- |
| 0x00404DC0 | sub_00404DC0_EnumModulesToolhelp | compiler option /Oy, without /Oy- |
| 0x00405250 | sub_00405250_DescribeAddress | link-time code generation (/GL /LTCG) |
| 0x00406990 | sub_00406990_DeleteFile | compiler option /EHa |
| 0x004069A0 | sub_004069A0_CloseFile | compiler option /EHa |
| 0x00406B20 | sub_00406B20_AppendBackslash | compiler option /EHa |
| 0x00406B60 | sub_00406B60_GetModuleDirectory | compiler option /EHa |
| 0x00406BA0 | FOG_GetInstallPath | compiler option /EHa |
| 0x00407360 | sub_00407360_GetSystemInfo | compiler option /EHa |
| 0x00407440 | sub_00407440_JulianToDate | compiler option /EHa |
| 0x00407960 | FOG_SetLogPrefix | compiler option /EHa |
| 0x00408000 | sub_00408000_StripSourcePath | compiler option /EHa |
| 0x00408050 | sub_00408050_Empty | compiler option /EHa |
| 0x00408060 | sub_00408060_Empty | compiler option /EHa |
| 0x00408070 | sub_00408070_Empty | compiler option /EHa |
| 0x00408080 | sub_00408080_Empty | compiler option /EHa |
| 0x00408090 | sub_00408090 | compiler option /Oy, without /Oy- |
| 0x004080B0 | sub_004080B0_DebugPrintV | compiler option /EHa |
| 0x004082A0 | sub_004082A0_DebugPrintf | compiler option /EHa |
| 0x004082C0 | sub_004082C0_DebugPrintfLog | compiler option /EHa |
| 0x004082E0 | sub_004082E0_CrashHandler | compiler option /EHa |
| 0x00408660 | sub_00408660_ShowErrorReport | compiler option /EHa |
| 0x00408900 | sub_00408900_RaiseErrorReport | compiler option /EHa |
| 0x00409000 | sub_00409000_GetBitWidth | inline assembly |
| 0x00409220 | sub_00409220_FindZeroBit | inline assembly |
| 0x00409810 | sub_00409810_PoolFreeLarge | compiler option /EHa |
| 0x0040A620 | FOG_AsyncDataLoadFileEx | compiler option /EHa |
| 0x0040ABF0 | sub_0040ABF0_HeapSiftDown | compiler option /EHa |
| 0x0040ACA0 | sub_0040ACA0_CalcCodeLengths | compiler option /EHa |
| 0x0040B540 | sub_0040B540_DumpThreadStackAndCode | compiler option /EHa |
| 0x0040D540 | sub_0040D540_SETranslator | compiler option /EHa |
| 0x0040D7D0 | sub_0040D7D0_WalkCurrentStack | inline assembly |
| 0x0040E250 | sub_0040E250_GetCpuVendor | inline assembly |
| 0x0040E850 | sub_0040E850_ReadTimeStampCounter | inline assembly |
| 0x0040E960 | sub_0040E960_GetCpuSignature | inline assembly |
| 0x0040E980 | sub_0040E980_GetCpuidEbxIfBrandIndexed | inline assembly |
| 0x0040E9E0 | sub_0040E9E0_GetCpuidEdx | inline assembly |
| 0x0040EB30 | ??3D2LogMessageStrc@@SAXPAX0@Z | compiler option /EHa |
| 0x0040F000 | sub_0040F000_GetLogDirectory | compiler option /EHa |
| 0x0040F3D0 | sub_0040F3D0_SweepLogFile | compiler option /EHa |
| 0x0040F530 | ~sub_0040F530 | compiler option /EHa |
| 0x0040F5A0 | sub_0040F5A0_SetLogPrefix | compiler option /EHa |
| 0x0040F600 | sub_0040F600_MeasureLogFile | compiler option /EHa |
| 0x0040F670 | sub_0040F670_ReadLogRange | compiler option /EHa |
| 0x0040F720 | sub_0040F720_WriteMessage | compiler option /EHa |
| 0x0040F7C0 | sub_0060E440_Head | compiler option /EHa |
| 0x0040F7D0 | ~sub_0040F7D0 | compiler option /EHa |
| 0x0040F810 | sub_0040F810 | compiler option /EHa |
| 0x0040F820 | ~D2LogMsgLinkStrc | compiler option /EHa |
| 0x0040F860 | sub_0060E5F0_Reset | compiler option /EHa |
| 0x0040F960 | sub_0040F960_CloseLogFiles | compiler option /EHa |
| 0x0040FAA0 | ~D2LogMsgNodeStrc | compiler option /EHa |
| 0x0040FB50 | D2LogMsgListStrc | compiler option /EHa |
| 0x0040FCB0 | D2LogMsgNodeStrc | compiler option /EHa |
| 0x0040FD40 | ~D2LogMessageStrc | compiler option /EHa |
| 0x0040FD90 | ~D2LogMsgListStrc | compiler option /EHa |
| 0x0040FE10 | D2LogMessageStrc | compiler option /EHa |
| 0x0040FE60 | ??_GD2LogMessageStrc@@QAEPAXI@Z | compiler option /EHa |
| 0x0040FED0 | sub_0040FED0_DeleteAll | compiler option /EHa |
| 0x0040FF40 | sub_0040FF40_NewNode | compiler option /EHa |
| 0x004101C0 | sub_004101C0_LogThreadProc | compiler option /EHa |
| 0x004107B0 | sub_004107B0_AtomicStore64 | inline assembly |
| 0x004107D0 | sub_004107D0_Read64Locked | inline assembly, naked function |
| 0x00410C40 | sub_00410C40_OrBits | compiler option /EHa |
| 0x00413A00 | sub_00413A00_VPrintf | calling-convention shim |
| 0x00414B00 | sub_00414B00_SRegLoadEntry | calling-convention shim |
| 0x00414DE0 | SRegLoadData | compiler option /GS |
| 0x00414E50 | SRegLoadString | compiler option /GS |
| 0x00417780 | sub_00417780 | compiler option /EHa |
| 0x00417810 | ~sub_00417810 | compiler option /EHa |
| 0x00417850 | sub_00417850 | compiler option /EHa |
| 0x00417860 | ~sub_00417860 | compiler option /EHa |
| 0x004178B0 | sub_004178B0 | compiler option /EHa |
| 0x004178C0 | ~sub_004178C0 | compiler option /EHa |
| 0x00417900 | ~sub_00417900 | compiler option /EHa |
| 0x00417940 | sub_00417940 | compiler option /EHa |
| 0x00417950 | ~sub_00417950 | compiler option /EHa |
| 0x00417990 | sub_00417990 | compiler option /EHa |
| 0x004179B0 | ~sub_004179B0 | compiler option /EHa |
| 0x004183F0 | ~sub_004183F0 | compiler option /EHa |
| 0x00418430 | ~sub_00418430 | compiler option /EHa |
| 0x00418760 | sub_00418760 | compiler option /EHa |
| 0x00418770 | sub_00418770 | compiler option /EHa |
| 0x00418780 | ~sub_00418780 | compiler option /EHa |
| 0x004187C0 | ~sub_004187C0 | compiler option /EHa |
| 0x00418800 | ~sub_00418800 | compiler option /EHa |
| 0x00418840 | ~sub_00418840 | compiler option /EHa |
| 0x00418880 | ~sub_00418880 | compiler option /EHa |
| 0x004188C0 | ~sub_004188C0 | compiler option /EHa |
| 0x00418A40 | sub_00418A40 | compiler option /EHa |
| 0x00418BA0 | ~sub_00418BA0 | compiler option /EHa |
| 0x00418BE0 | ~sub_00418BE0 | compiler option /EHa |
| 0x00418C20 | ~sub_00418C20 | compiler option /EHa |
| 0x00418DE0 | sub_00418DE0 | compiler option /EHa |
| 0x00418DF0 | sub_00418DF0 | compiler option /EHa |
| 0x00418E00 | sub_00418E00 | compiler option /EHa |
| 0x00418E10 | ~sub_00418E10 | compiler option /EHa |
| 0x00418E50 | sub_00418E50 | compiler option /EHa |
| 0x00418FF0 | sub_00418FF0 | compiler option /EHa |
| 0x00419060 | sub_00419060 | compiler option /EHa |
| 0x0041C3D0 | ~sub_0041C3D0 | compiler option /EHa |
| 0x0041C4F0 | sub_0041C4F0 | compiler option /EHa |
| 0x0041C500 | ~sub_0041C500 | compiler option /EHa |
| 0x0041C720 | sub_0041C720 | compiler option /EHa |
| 0x0041C730 | ~sub_0041C730 | compiler option /EHa |
| 0x0041C7F0 | sub_0041C7F0 | compiler option /EHa |
| 0x0041C800 | ~sub_0041C800 | compiler option /EHa |
| 0x0041D7D0 | sub_0041D7D0_VerifySignature | compiler option /Ob1 |
| 0x00420430 | ~sub_00420430 | compiler option /EHa |
| 0x004204A0 | sub_004204A0 | compiler option /EHa |
| 0x004204B0 | ~sub_004204B0 | compiler option /EHa |
| 0x00420700 | sub_00420700 | compiler option /EHa |
| 0x00420710 | ~sub_00420710 | compiler option /EHa |
| 0x004207D0 | sub_004207D0 | compiler option /EHa |
| 0x004207E0 | ~sub_004207E0 | compiler option /EHa |
| 0x00421100 | sub_00421100_GetSelf | compiler option /Ob1 |
| 0x00426960 | ~sub_00426960 | compiler option /EHa |
| 0x00426A80 | ~sub_00426A80 | compiler option /EHa |
| 0x00426CA0 | sub_00426CA0 | compiler option /EHa |
| 0x00426CB0 | ~sub_00426CB0 | compiler option /EHa |
| 0x00426D70 | sub_00426D70 | compiler option /EHa |
| 0x00426D80 | ~sub_00426D80 | compiler option /EHa |
| 0x00427420 | putShortMSB | compiler option /TC |
| 0x00427450 | flush_pending | compiler option /TC |
| 0x00427800 | longest_match | compiler option /TC |
| 0x00427980 | fill_window | compiler option /TC |
| 0x00427BB0 | deflate_stored | compiler option /TC |
| 0x00427DD0 | deflate_fast | compiler option /TC |
| 0x00428150 | deflate_slow | compiler option /TC |
| 0x004285F0 | deflate_rle | compiler option /TC |
| 0x00428900 | deflate_huff | compiler option /TC |
| 0x00428AB0 | deflateSetDictionary | compiler option /TC |
| 0x00428C60 | deflate | compiler option /TC |
| 0x0042B9E0 | init_block | compiler option /TC |
| 0x0042BA50 | pqdownheap | compiler option /TC |
| 0x0042BB30 | gen_bitlen | compiler option /TC |
| 0x0042BD30 | scan_tree | compiler option /TC |
| 0x0042BE10 | send_tree | compiler option /TC |
| 0x0042C390 | send_all_trees | compiler option /TC |
| 0x0042C6A0 | compress_block | compiler option /TC |
| 0x0042CAB0 | detect_data_type | compiler option /TC |
| 0x0042CB20 | bi_reverse | compiler option /TC |
| 0x0042CB40 | bi_flush | compiler option /TC |
| 0x0042CBC0 | bi_windup | compiler option /TC |
| 0x0042CC40 | copy_block | compiler option /TC |
| 0x0042CCD0 | _tr_init | compiler option /TC |
| 0x0042CD30 | gen_codes | compiler option /TC |
| 0x0042CDD0 | build_tree | compiler option /TC |
| 0x0042CFD0 | build_bl_tree | compiler option /TC |
| 0x0042D0A0 | _tr_stored_block | compiler option /TC |
| 0x0042D150 | _tr_flush_bits | compiler option /TC |
| 0x0042D160 | _tr_align | compiler option /TC |
| 0x0042D250 | _tr_flush_block | compiler option /TC |
| 0x004313A0 | sub_004313A0_GetFlagIndex | calling-convention shim |
| 0x00442180 | sub_00442180_ReplyCommand | calling-convention shim |
| 0x00446D30 | sub_00446D30_GetUserRank | calling-convention shim |
| 0x00447FD0 | sub_00447FD0_UpdateUser | calling-convention shim |
| 0x004549F0 | sub_004549F0_DrawHoverLine | calling-convention shim |
| 0x00461DC0 | sub_00461DC0_InteractWithUnit | calling-convention shim |
| 0x004623C0 | sub_004623C0_ClampTarget | calling-convention shim |
| 0x00463260 | sub_00463260_UpdateStoredUnit | calling-convention shim |
| 0x00467130 | sub_00467130_GetHoverCursorPos | calling-convention shim |
| 0x00468750 | sub_00468750_SetCursorPos | compiler option /Ob1 |
| 0x0046E040 | sub_0046E040_RemoveOverlay | calling-convention shim |
| 0x00477060 | sub_00477060_BuildBloodShift | calling-convention shim |
| 0x00479770 | sub_00479770_GetOrAddGroup | calling-convention shim |
| 0x004814A0 | sub_004814A0_TryMonsterAction | calling-convention shim |
| 0x004815A0 | sub_004815A0_TryUnitAction | calling-convention shim |
| 0x00482C70 | sub_00482C70_GetFlagIndex | calling-convention shim |
| 0x004839D0 | sub_004839D0_DrawGridCells | calling-convention shim |
| 0x0048BC10 | sub_0048BC10 | compiler option /Ob1 |
| 0x004A0770 | sub_004A0770 | calling-convention shim, compiler option /Ob1 |
| 0x004A7AE0 | sub_004A7AE0_DrawHoverValueBox | calling-convention shim |
| 0x004C0F20 | sub_004C0F20_CreateWorldItem | calling-convention shim |
| 0x004C0FF0 | sub_004C0FF0_CreateOwnedItem | calling-convention shim |
| 0x004C1C20 | sub_004C1C20_SetWeaponClass | calling-convention shim |
| 0x004CD310 | sub_004CD310_UseCharge | calling-convention shim |
| 0x004CE530 | sub_004CE530_SpawnSubMissile | calling-convention shim |
| 0x004DDFD0 | sub_004DDFD0_BuildSmallFlatGrid | calling-convention shim |
| 0x004E74A0 | sub_004E74A0_FormatDamageRange | calling-convention shim |
| 0x004EA990 | sub_004EA990_DrawSkillDamage | compiler option /Ob1 |
| 0x004F0650 | sub_004F0650_CreateClientMissiles | compiler option /Ob1 |
| 0x004F4590 | sub_004F4590_DoSkillSound | compiler option /Ob1 |
| 0x00501A80 | FONT_DrawString | calling-convention shim |
| 0x00512250 | sub_00512250_DrawCel | compiler option /Ob1 |
| 0x00516D8B | sub_00516D8B_RunSurvey | compiler option /Os |
| 0x00516DE1 | sub_00516DE1_Verify | compiler option /O1 |
| 0x00516E46 | sub_00516E46_OpenFile | compiler option /O1, compiler option /Ob1 |
| 0x00516E84 | sub_00516E84_CloseFile | compiler option /O1, compiler option /Ob1 |
| 0x00516EAB | sub_00516EAB_FileSize | compiler option /Os |
| 0x00516F14 | sub_00516F14_SetFilePointer | compiler option /O1 |
| 0x00516F85 | ARCHIVE_ReadFileToBuffer | compiler option /O1 |
| 0x00517015 | sub_00517015_ReadFileToSizedBuffer | compiler option /O1 |
| 0x00517079 | ARCHIVE_AllocateBufferAndReadFile | compiler option /O1 |
| 0x005170E7 | sub_005170E7_GetModuleDirectory | calling-convention shim, compiler option /O1 |
| 0x00517128 | sub_00517128_FindArchive | compiler option /O1 |
| 0x00517299 | sub_00517299_FindAndOpenArchive | compiler option /O1 |
| 0x00517332 | ARCHIVE_LoadMPQFile | compiler option /O1 |
| 0x005173AC | sub_005173AC_Unload | compiler option /O1 |
| 0x005173EF | sub_005173EF_FatalBox | compiler option /Os |
| 0x0051740B | sub_0051740B_ErrorBox | compiler option /Os |
| 0x00517423 | FaultDoAssert | compiler option /O1 |
| 0x005174B8 | sub_005174B8_Clear | compiler option /O1 |
| 0x005174C0 | sub_005174C0 | compiler option /O1, compiler option /Ob1 |
| 0x005174E2 | Unlink | compiler option /O1, compiler option /Ob1 |
| 0x00517520 | D2StormRecordStrc | compiler option /Os |
| 0x0051752F | sub_0051752F_GetLink | compiler option /Os |
| 0x0051755C | sub_0051755C_LinkNode | compiler option /O1, compiler option /Ob1 |
| 0x005175CB | sub_005175CB_Next | compiler option /Os |
| 0x005175E3 | sub_005175E3_Initialize | compiler option /O1 |
| 0x005175F1 | sub_005175F1_UnlinkNode | compiler option /O1, compiler option /Ob1 |
| 0x00517607 | sub_00517607_RawNext | compiler option /Os |
| 0x00517619 | S | compiler option /O1 |
| 0x0051763C | sub_0051763C_UnlinkAll | compiler option /O1 |
| 0x00517669 | sub_00517669_NewNode | compiler option /Os |
| 0x005176B4 | sub_005176B4_DeletingDtor | compiler option /O1, compiler option /Ob1 |
| 0x005176F8 | Clear | compiler option /O1 |
| 0x0051772A | sub_0051772A_DeleteNode | compiler option /Os |
| 0x0051775A | sub_0051775A_FreeFaultHandlerList | compiler option /O1, compiler option /Ob1 |
| 0x00517788 | sub_00517788_InitFaultHandlerList | compiler option /O1, compiler option /Ob1 |
| 0x005177B2 | sub_005177B2_SetLoadStringFn | compiler option /O1, compiler option /Ob1 |
| 0x00517804 | sub_00517804_GetMessage | compiler option /Os |
| 0x00517874 | sub_00517874_ShowError | compiler option /O1 |
| 0x005178E9 | sub_005178E9_Format | compiler option /Os |
| 0x0051793E | sub_0051793E_FormatAndRaise | compiler option /O1, compiler option /Ob1 |
| 0x005179B3 | sub_005179B3_CopyRect | compiler option /O1, inline assembly |
| 0x00517A36 | sub_00517A36_CompareMemory | compiler option /O1, inline assembly |
| 0x00517ABB | sub_00517ABB_FindLowestSetBit | compiler option /O1, inline assembly |
| 0x00517AD6 | sub_00517AD6 | compiler option /O1 |
| 0x00517C30 | sub_00517C30_GetSignerOrganization | compiler option /O1 |
| 0x00518EC0 | sub_00518EC0_EncryptBlock | calling-convention shim |
| 0x0051E920 | sub_0051E920_ExtractFile | calling-convention shim |
| 0x005232B0 | sub_005232B0_DecodeAndValidate | calling-convention shim |
| 0x00523350 | sub_00523350_CopyOutputs | calling-convention shim |
| 0x00523480 | sub_00523480_LoadFile | calling-convention shim |
| 0x00524C60 | sub_00524C60_FindKey | calling-convention shim |
| 0x0052DFB0 | GAME_SendUnitRemovalToClient | compiler option /Ob1 |
| 0x00530270 | GAME_DisconnectClientById | compiler option /Ob1 |
| 0x00540DF0 | EVENT_AllocateUnitTimer | calling-convention shim |
| 0x00542E10 | sub_00542E10_CompressInactiveUnit | compiler option /GS |
| 0x005485B0 | sub_005485B0_GetPoisonedLifePercent | calling-convention shim |
| 0x005502F0 | sub_005502F0_CanPlace | calling-convention shim |
| 0x0055DBC0 | D2GAME_RemoveItem_6FC471F0 | compiler option /Ob1 |
| 0x005697F0 | PLRSAVE2_WriteCorpsesSection | compiler option /Ob1 |
| 0x0056EDE0 | D2GAME_CreateMissile_6FD115E0 | compiler option /Ob1 |
| 0x0056EF90 | D2GAME_SKILLS_SetDelay_6FD11C00 | calling-convention shim, compiler option /Ob1 |
| 0x0056F070 | SKILLS_SrvDo001_Attack_LeftHandSwing | compiler option /Ob1 |
| 0x0056F7F0 | SKILLS_ExecuteSkill | compiler option /Ob1 |
| 0x00574250 | MONSTER_Initialize | compiler option /Ob1 |
| 0x00575070 | sub_00575070_HasPetOfType7 | compiler option /Ob1 |
| 0x0057A880 | sub_0057A880_AddRolledDamage | calling-convention shim |
| 0x0057A8E0 | sub_0057A8E0_AddStatDamage | calling-convention shim |
| 0x0057B660 | sub_0057B660_AddUndeadDamagePercent | calling-convention shim |
| 0x0057B6A0 | sub_0057B6A0_AddMonTypeDamagePercent | calling-convention shim |
| 0x0057BF10 | sub_0057BF10_AbsorbDamage | calling-convention shim |
| 0x0057DFB0 | SUNITDMG_ApplyBlockOrDodge | compiler option /Ob1 |
| 0x0057F410 | sub_6FC802F0 | calling-convention shim |
| 0x0057F4F0 | sub_6FC803F0 | calling-convention shim |
| 0x0057F540 | sub_0057F540_DropItemsOnCorpseOverflow | calling-convention shim |
| 0x0057F690 | sub_0057F690_FreeStaleCorpses | calling-convention shim |
| 0x00588E10 | sub_00588E10_IsMonsterNearby | compiler option /Ob1 |
| 0x0059A5D0 | ACT2Q3_Callback13_PlayerStartedGame | compiler option /Ob1 |
| 0x0059C6B0 | sub_0059C6B0_RemovePlayerGUID | compiler option /Oy |
| 0x005A49B0 | D2GAME_SpawnSuperUnique_6FC6F690 | compiler option /Ob1 |
| 0x005A6380 | sub_005A6380_SetVelocityPercent | calling-convention shim |
| 0x005A68E0 | sub_005A68E0_SetAiStateForMode | calling-convention shim |
| 0x005A7B30 | sub_005A7B30_TryStartNeutral | calling-convention shim |
| 0x005A7C20 | D2GAME_ModeChange_6FC65220 | compiler option /Ob1 |
| 0x005A8C70 | MISSMODE_GetDamageValue | compiler option /Ob1 |
| 0x005ADA80 | sub_005ADA80_GetDamageTarget | calling-convention shim |
| 0x005B1C50 | MONSTERSPAWN_EquipAncientBarbarians | calling-convention shim |
| 0x005B2830 | MONSTERSPAWN_SpawnMinionParty | calling-convention shim |
| 0x005BE020 | MONSTERCHOOSE_GetBossSpawnType | compiler option /Ob1 |
| 0x005C3300 | sub_005C3300_CorpseConsumedCheck | calling-convention shim |
| 0x005D81C0 | SKILLS_SrvDo069_FindPotion | compiler option /Ob1 |
| 0x005E36F0 | AITHINK_Fn125_BloodLord | compiler option /Ob1 |
| 0x005E3EA0 | D2GAME_AI_PetMove_6FCE2BA0 | compiler option /Ob1 |
| 0x005EEDA0 | AITHINK_AncientBarb2SkillHandler | compiler option /Ob1 |
| 0x005F2850 | AITHINK_Fn021_Mummy | compiler option /Ob1 |
| 0x005FC450 | AIBAAL_RollRandomAiParamForNonCollidingUnit | calling-convention shim |
| 0x005FC630 | AIBAAL_RollRandomAiParam | calling-convention shim |
| 0x005FCFE0 | AITHINK_Fn135_BaalCrab | compiler option /Ob1 |
| 0x005FD210 | AITHINK_Fn140_BaalCrabClone | compiler option /Ob1 |
| 0x006009C0 | sub_006009C0 | compiler option /Od, compiler option /Oi, without /O2, without /Ob2, without /Oy- |
| 0x00600C60 | sub_00600C60_CallFree | compiler option /Ob1 |
| 0x00606A10 | sub_00606A10_EncodeRleCell | calling-convention shim |
| 0x006090E0 | sub_006090E0 | compiler option /Ob1, link-time code generation (/GL /LTCG) |
| 0x00609100 | sub_00609100 | compiler option /Ob1, link-time code generation (/GL /LTCG) |
| 0x00609120 | sub_00609120 | compiler option /Ob1, link-time code generation (/GL /LTCG) |
| 0x00609150 | sub_00609150 | compiler option /Ob1, link-time code generation (/GL /LTCG) |
| 0x00609180 | sub_00609180 | compiler option /Ob1, link-time code generation (/GL /LTCG) |
| 0x00609200 | sub_00609200 | compiler option /Ob1, link-time code generation (/GL /LTCG) |
| 0x00609250 | sub_00609250 | compiler option /Ob1, link-time code generation (/GL /LTCG) |
| 0x006092D0 | sub_006092D0 | compiler option /Ob1, link-time code generation (/GL /LTCG) |
| 0x00609380 | sub_00609380 | compiler option /Ob1, link-time code generation (/GL /LTCG) |
| 0x006093E0 | sub_006093E0 | compiler option /Ob1, link-time code generation (/GL /LTCG) |
| 0x00609420 | sub_00609420 | compiler option /Ob1, link-time code generation (/GL /LTCG) |
| 0x0060A050 | sub_0060A050_Serialize | calling-convention shim |
| 0x0060B280 | sub_0060B280_ReadBitsSigned | calling-convention shim, compiler option /Ob1 |
| 0x0060B5F0 | sub_0060B5F0_BuildColorMaps | calling-convention shim |
| 0x0060D6F0 | sub_0060D6F0_ConvertPixels | calling-convention shim |
| 0x0060DA80 | sub_0060DA80_MapSubTile | calling-convention shim |
| 0x0061BB60 | sub_0061BB60_SetColorForId | calling-convention shim |
| 0x00620510 | UNITS_GetUnitSizeX | calling-convention shim |
| 0x00620E80 | UNITS_CharacterStartRunningOrKnockback | calling-convention shim |
| 0x00621420 | sub_00621420_GetRecordForValue | calling-convention shim |
| 0x00628830 | sub_00628830_ApplyClassMinimum | calling-convention shim |
| 0x006292F0 | sub_006292F0_AddSocketablesCost | calling-convention shim |
| 0x0062A900 | sub_0062A900_CountSocketedItems | calling-convention shim |
| 0x0062AC80 | ITEMS_ReadStatFromItemBitstream | calling-convention shim |
| 0x0062C9F0 | ITEMS_SetDefenseOrDamage | calling-convention shim |
| 0x0062CBE0 | ITEMS_DecodeItemBitstreamComplete | calling-convention shim |
| 0x0062FFF0 | ITEMS_SerializeItemComplete | calling-convention shim |
| 0x00633F40 | DATATBLS_LoadRareSuffix_PrefixTxt | link-time code generation (/GL /LTCG) |
| 0x0064A400 | MISSILE_SetOwner | compiler option /Ob1 |
| 0x0064CA10 | COLLISION_FreeRoomCollisionGrid | link-time code generation (/GL /LTCG) |
| 0x0064CA50 | COLLISION_CheckCollisionMask | link-time code generation (/GL /LTCG) |
| 0x0064CAA0 | COLLISION_ResetCollisionMask | link-time code generation (/GL /LTCG) |
| 0x0064CAF0 | COLLISION_SetCollisionMask | link-time code generation (/GL /LTCG) |
| 0x0064CB30 | COLLISION_CheckMask | link-time code generation (/GL /LTCG) |
| 0x0064D0D0 | COLLISION_CreateBoundingBox | link-time code generation (/GL /LTCG) |
| 0x0064D450 | sub_0064D450 | link-time code generation (/GL /LTCG) |
| 0x0064D4A0 | sub_0064D4A0 | link-time code generation (/GL /LTCG) |
| 0x0064D7C0 | sub_0064D7C0 | link-time code generation (/GL /LTCG) |
| 0x0064D910 | COLLISION_CheckAnyCollisionWithPattern | compiler option /Ob1, link-time code generation (/GL /LTCG) |
| 0x0064DA40 | sub_0064DA40 | link-time code generation (/GL /LTCG) |
| 0x0064DB70 | sub_0064DB70 | link-time code generation (/GL /LTCG) |
| 0x0064DBC0 | sub_0064DBC0 | link-time code generation (/GL /LTCG) |
| 0x0064DC00 | COLLISION_ResetMaskWithSizeXY | link-time code generation (/GL /LTCG) |
| 0x0064DC80 | sub_0064DC80 | link-time code generation (/GL /LTCG) |
| 0x0064DDB0 | sub_0064DDB0 | link-time code generation (/GL /LTCG) |
| 0x0064DDF0 | sub_0064DDF0 | link-time code generation (/GL /LTCG) |
| 0x0064DE30 | COLLISION_SetMaskWithSizeXY | compiler option /Ob1, link-time code generation (/GL /LTCG) |
| 0x0065A710 | sub_0065A710_IsInRoomRange | calling-convention shim |
| 0x00661A30 | sub_00661A30_ClampMissileField | calling-convention shim |
| 0x0066CDE0 | sub_0066CDE0 | link-time code generation (/GL /LTCG) |
| 0x00675EB0 | sub_00675EB0_PlaceCoord | calling-convention shim |
| 0x00675F80 | sub_00675F80_PlaceCoordCentered | calling-convention shim |
| 0x006769A0 | sub_6FD81B30 | compiler option /Ob1 |
| 0x0067AF40 | PATH_AStar_PopBestScoreForVisit | calling-convention shim |
| 0x0067B9F0 | PATH_BresenhamLine | calling-convention shim |
| 0x0067DCA0 | sub_0067DCA0 | calling-convention shim |
| 0x00681560 | sub_00681560 | calling-convention shim |
| 0x006B2F30 | sub_006B2F30_SetGlobal | compiler option /Ob1 |
| 0x006B2F40 | sub_006B2F40_CloseKey | compiler option /Ob1 |
| 0x006B6700 | sub_006B6700_IsOutsideScreen | calling-convention shim |
| 0x006B7630 | sub_006B7630_DrawTextV | compiler option /Ob1 |
| 0x006B9EB0 | sub_006B9EB0_CopyBlock | calling-convention shim |
| 0x006BA5C0 | sub_006BA5C0_Append | compiler option /Ob1 |
| 0x006BAB30 | sub_006BAB30_Append | compiler option /Ob1 |
| 0x006BBF60 | sub_006BBF60_DecodeBase255 | compiler option /Ob1 |
| 0x006BBFA0 | sub_006BBFA0_EncodeBase255 | compiler option /Ob1 |
| 0x006BC290 | sub_006BC290_SetValues | compiler option /Ob1 |
| 0x006BC2C0 | sub_006BC2C0_SetClosing | calling-convention shim |
| 0x006BC310 | sub_006BC310_CloseSocket | calling-convention shim |
| 0x006BC7E0 | sub_006BC7E0_Wait | compiler option /Ob1 |
| 0x006BC830 | sub_006BC830_SetEvent | compiler option /Ob1 |
| 0x006BCCC0 | sub_006BCCC0_Reset | compiler option /Ob1 |
| 0x006BCD50 | sub_006BCD50_MakeCode | calling-convention shim |
| 0x006BCE20 | sub_006BCE20_MapNames | calling-convention shim |
| 0x006BD490 | sub_006BD490_InsertNode | calling-convention shim |
| 0x006BD500 | sub_006BD500_AddCode | compiler option /Ob1 |
| 0x006BE470 | sub_006BE470_IsActive | compiler option /Ob1 |
| 0x006BE510 | sub_006BE510_Enter | compiler option /Ob1 |
| 0x006BE530 | sub_006BE530_Leave | compiler option /Ob1 |
| 0x006BE650 | sub_006BE650_FreeClient | calling-convention shim |
| 0x006BEA70 | sub_006BEA70_CountBucket | compiler option /Ob1 |
| 0x006BF0F0 | sub_006BF0F0_FreeAll | calling-convention shim, compiler option /Ob1 |
| 0x006BF170 | sub_006BF170_Dispatch | compiler option /Ob1 |
| 0x006BF180 | sub_006BF180_IncrementPerIpConnCount | calling-convention shim |
| 0x006BF1F0 | sub_006BF1F0_Release | calling-convention shim |
| 0x006BF250 | sub_006BF250_Nop | compiler option /Ob1 |
| 0x006BF320 | sub_006BF320_FreePending | calling-convention shim |
| 0x006C0140 | sub_006C0140_SendToKey | calling-convention shim |
| 0x006C0420 | sub_006C0420_DisconnectClient | compiler option /EHa |
| 0x006C19C0 | DATATBLS_ExpressionBuffer_PushRawConstant | calling-convention shim |
| 0x006C1A50 | DATATBLS_ExpressionBuffer_PushCallbackConstant | calling-convention shim |
| 0x006C1FD0 | sub_006C1FD0_GetLocked | compiler option /Ob1 |
| 0x006C23B0 | sub_006C23B0_QueueMessage | calling-convention shim |
| 0x006C3DA0 | sub_006C3DA0_SetName | calling-convention shim |
| 0x006C4010 | sub_006C4010_Head | compiler option /Ob1 |
| 0x006C4040 | NextLink | compiler option /Ob1 |
| 0x006C4070 | Unlink | compiler option /Ob1 |
| 0x006C40B0 | sub_006C40B0_InitList | compiler option /Ob1 |
| 0x006C40C0 | sub_006C40C0_Identity | compiler option /Ob1 |
| 0x006C40D0 | sub_006C40D0_Head | compiler option /Ob1 |
| 0x006C40E0 | sub_006C40E0_Head | compiler option /Ob1 |
| 0x006C40F0 | sub_006C40F0_ResetLink | compiler option /Ob1 |
| 0x006C4140 | sub_006C4140_InitList | compiler option /Ob1 |
| 0x006C4160 | sub_006C4160_Link | compiler option /Ob1 |
| 0x006C4230 | sub_006C4230_Next | compiler option /Ob1 |
| 0x006C4290 | sub_006C4290 | compiler option /Ob1 |
| 0x006C4360 | D2StormListStrc | compiler option /Ob1 |
| 0x006C43A0 | sub_006C43A0_ResetLink | compiler option /Ob1 |
| 0x006C4470 | sub_006C4470_Clear | compiler option /Ob1 |
| 0x006C4980 | sub_006C4980_ApplyOptions | calling-convention shim |
| 0x006C4CA0 | sub_006C4CA0_FindValue | compiler option /Ob1 |
| 0x006C4CF0 | sub_006C4CF0_FreeBuffers | compiler option /Ob1 |
| 0x006C4DC0 | sub_006C4DC0_GetText | compiler option /Ob1 |
| 0x006C5B10 | sub_006C5B10_EncodeRow | calling-convention shim |
| 0x006C5B60 | sub_006C5B60_WritePcx | calling-convention shim |
| 0x006C5EE0 | sub_006C5EE0_FindExtension | calling-convention shim |
| 0x006C60F0 | sub_006C60F0_DecodeBmp | calling-convention shim |
| 0x006C61C0 | sub_006C61C0_WriteBmp | calling-convention shim |
| 0x006C6370 | sub_006C6370_AddChar | calling-convention shim |
| 0x006C7B00 | sub_006C7B00_CreateBackBuffer | compiler option /Ob1 |
| 0x006C7C10 | sub_006C7C10_InitPalette | compiler option /Ob1 |
| 0x006C8750 | sub_006C8750_DrawCel | compiler option /Ob1 |
| 0x006C8C50 | sub_006C8C50_SetPixel | compiler option /Ob1 |
| 0x006C95C0 | sub_006C95C0_Nop | compiler option /Ob1 |
| 0x006C99F6 | CRC32_Compute | compiler option /O1, compiler option /Ob1 |
| 0x006C9A38 | sub_006C9A38_StringLength | compiler option /O1, compiler option /Ob1, compiler option /Os |
| 0x006C9A46 | sub_006C9A46_StringEquals | compiler option /O1 |
| 0x006C9A76 | sub_006C9A76_ParseNumber | compiler option /O1 |
| 0x006C9AC7 | sub_006C9AC7_SkipSpaces | compiler option /O1 |
| 0x006C9ADF | sub_006C9ADF_CopyWord | compiler option /O1 |
| 0x006C9AFF | sub_006C9AFF_FindLastCharacter | compiler option /Os |
| 0x006C9B17 | sub_006C9B17_StripFileName | compiler option /O1 |
| 0x006C9B30 | sub_006C9B30_GetFileName | compiler option /O1 |
| 0x006CA740 | EgtLogMsgQueue_0075E868 | compiler option /EHa |
| 0x006CA890 | sub_006CA890_InitStorm | compiler option /Ob1 |
| 0x006CACD0 | sub_006CACD0_InitQuestTextBuffer | compiler option /Ob1 |
| 0x006CAE5F | sub_006CAE5F_StaticInit_gFaultHandlerList | compiler option /O1, compiler option /Ob1 |
| 0x006CB090 | sub_006CB090_DestroyLogMsgList | compiler option /Ob1 |
| 0x006CB3E0 | sub_006CB3E0_DestroyHashTable | compiler option /Ob1 |
| 0x006CB400 | sub_006CB400_Nop | compiler option /Ob1 |
| 0x006CB401 | sub_006CB401_StaticFini_gFaultHandlerList | compiler option /O1, compiler option /Ob1 |
| 0x006CB480 | sub_006CB480_DestroyBigPair | compiler option /Ob1 |
| 0x006CB4C0 | sub_006CB4C0_DestroyTable | compiler option /Ob1 |

## Names

`names.csv` gives the source of every function name: 173 `blizzard`, 4394 `d2moo`, 10360 `placeholder`. Placeholder names (mostly `sub_<address>_<Verb>`) are waiting for a real name.
