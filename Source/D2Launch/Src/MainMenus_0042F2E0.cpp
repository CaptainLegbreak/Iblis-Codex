#include "D2Launch.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2ConfigStrc;
struct D2FileTimeStrc;
struct D2LaunchRecordStrc;
struct D2LaunchSlotStrc;
struct D2MenuListStrc;

struct Unicode
{
    unsigned short wChar;
    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2FuncTable_0077ABF0Strc
{
    char unk_00[0x40];
    D2MenuListStrc* (__fastcall* pfnGetMenuList)(int nArg);
    unsigned char unk_44[0x3C];
    void (__fastcall* pfnSlot80)(int* pValue);
};

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2FindDataStrc
{
    unsigned long dwFileAttributes;
    D2FileTimeStrc ftCreationTime;
    D2FileTimeStrc ftLastAccessTime;
    D2FileTimeStrc ftLastWriteTime;
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};

struct D2LaunchRecordStrc
{
    char unk0x000[0x19];
    char aState19[4];
    char aWord1D[2];
    char unk0x01F[0x18];
    char szName[0x10];
    char unk0x047[0x76];
    char szCharName[0x18];
    char nByteD5;
    char unk0x0D6[0x17];
    char aDataED[0x101];
    char nClass;
    char aFlags1EF[2];
    char unk0x1F1[0x18];
    char aState209[4];
    char unk0x20D[0x16];
    char bFlag223;
    char unk0x224[9];
    char nByte22D;
    char unk0x22E[0x130];
    char nByte35E;
    char unk0x35F[0x42];
    char aData3A1[0x10];
    char aData3B1[0x10];
    char nByte3C1;
    char nByte3C2;
    char unk0x3C3[8];
    char aWord3CB[2];
};
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

typedef int (__stdcall* D2LaunchCallback)(int nArg);
void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300
void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069A0_CloseFile(void* hFile); // 0x004069A0
void __cdecl sub_0042FDD0(); // 0x0042FDD0
void __cdecl sub_0042F3F0_DestroyControls(); // 0x0042F3F0
void __cdecl sub_0042F480_Reset(); // 0x0042F480
void __cdecl sub_0042F6E0(); // 0x0042F6E0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId); // 0x0042F430
void __cdecl sub_004317D0_FlushInput(); // 0x004317D0
void __cdecl sub_00430520(); // 0x00430520
void __stdcall sub_004313D0(int nLevel); // 0x004313D0
void __cdecl sub_00431AF0(); // 0x00431AF0
void __fastcall sub_00433380_ShowMessage(const Unicode* pText, D2LaunchCallback pfnDone, int nArg); // 0x00433380
void __cdecl sub_004365B0_CreateCharacter(); // 0x004365B0
void __cdecl sub_0043B080(); // 0x0043B080
void __cdecl sub_0043B9A0(); // 0x0043B9A0
void __fastcall sub_0043C6A0(int bSet); // 0x0043C6A0
void __cdecl sub_0043C4F0(); // 0x0043C4F0
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590
int __fastcall sub_004F9190(); // 0x004F9190
void __fastcall sub_004FCF80_SetTextA(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(short nIndex); // 0x00524A30
void __stdcall sub_00525260(void* pOut, int nField); // 0x00525260
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
extern int gbConnected_0077959C; // 0x0077959C
extern char gszAddress_007795F8[]; // 0x007795F8
extern D2WinControlStrc* gpAddressEdit_00779958; // 0x00779958
extern int gbPaletteBusy_00779970; // 0x00779970
extern int gdwGlobal_00779974; // 0x00779974
extern D2CellFileStrc* gpCellFile_007796F8; // 0x007796F8
extern D2CellFileStrc* gpCellFile_007796FC; // 0x007796FC
extern D2CellFileStrc* gpCellFile_00779704; // 0x00779704
extern D2CellFileStrc* gpCellFile_00779708; // 0x00779708
extern D2CellFileStrc* gpCellFile_0077970C; // 0x0077970C
extern D2CellFileStrc* gpCellFile_00779710; // 0x00779710
extern D2CellFileStrc* gpCellFile_00779714; // 0x00779714
extern D2CellFileStrc* gpCellFile_00779718; // 0x00779718
extern D2CellFileStrc* gpCellFile_0077971C; // 0x0077971C
extern D2CellFileStrc* gpCellFile_00779720; // 0x00779720
extern D2CellFileStrc* gpCellFile_0077972C; // 0x0077972C
extern D2CellFileStrc* gpCellFile_00779730; // 0x00779730
extern D2CellFileStrc* gpCellFile_00779734; // 0x00779734
extern D2CellFileStrc* gpCellFile_00779738; // 0x00779738
extern D2CellFileStrc* gpCellFile_0077973C; // 0x0077973C
extern D2CellFileStrc* gpCellFile_00779740; // 0x00779740
extern D2CellFileStrc* gpCellFile_00779748; // 0x00779748
extern D2CellFileStrc* gpCellFile_0077974C; // 0x0077974C
extern D2CellFileStrc* gpCellFile_00779750; // 0x00779750
extern D2CellFileStrc* gpCellFile_00779754; // 0x00779754
extern D2CellFileStrc* gpCellFile_00779758; // 0x00779758
extern D2CellFileStrc* gpCellFile_0077975C; // 0x0077975C
extern D2CellFileStrc* gpCellFile_00779764; // 0x00779764
extern D2CellFileStrc* gpCellFile_00779768; // 0x00779768
extern D2CellFileStrc* gpCellFile_0077976C; // 0x0077976C
extern D2CellFileStrc* gpCellFile_00779770; // 0x00779770
extern D2CellFileStrc* gpCellFile_00779774; // 0x00779774
extern D2CellFileStrc* gpCellFile_00779778; // 0x00779778
extern D2CellFileStrc* gpCellFile_0077977C; // 0x0077977C
extern D2CellFileStrc* gpCellFile_00779780; // 0x00779780
extern D2CellFileStrc* gpCellFile_00779784; // 0x00779784
extern D2CellFileStrc* gpCellFile_00779788; // 0x00779788
extern D2CellFileStrc* gpCellFile_0077978C; // 0x0077978C
extern D2CellFileStrc* gpCellFile_00779790; // 0x00779790
extern D2CellFileStrc* gpCellFile_00779794; // 0x00779794
extern D2CellFileStrc* gpCellFile_00779798; // 0x00779798
extern D2CellFileStrc* gpCellFile_0077979C; // 0x0077979C
extern D2CellFileStrc* gpCellFile_007797A0; // 0x007797A0
extern D2CellFileStrc* gpCellFile_007797A4; // 0x007797A4
extern D2CellFileStrc* gpCellFile_007797A8; // 0x007797A8
extern D2CellFileStrc* gpCellFile_007797AC; // 0x007797AC
extern D2CellFileStrc* gpCellFile_007797B0; // 0x007797B0
extern D2CellFileStrc* gpCellFile_007797B4; // 0x007797B4
extern D2CellFileStrc* gpCellFile_007797B8; // 0x007797B8
extern D2CellFileStrc* gpCellFile_007797C8; // 0x007797C8
extern D2CellFileStrc* gpCellFile_007797CC; // 0x007797CC
extern D2CellFileStrc* gpCellFile_007797D0; // 0x007797D0
extern D2CellFileStrc* gpCellFile_007797D4; // 0x007797D4
extern D2CellFileStrc* gpCellFile_007797D8; // 0x007797D8
extern D2CellFileStrc* gpCellFile_007797DC; // 0x007797DC
extern D2CellFileStrc* gpCellFile_00779724; // 0x00779724
extern D2CellFileStrc* gpCellFile_00779728; // 0x00779728
extern D2CellFileStrc* gpCellFile_00779744; // 0x00779744
extern D2CellFileStrc* gpCellFile_007797BC; // 0x007797BC
extern D2CellFileStrc* gpCellFile_007797C0; // 0x007797C0
extern D2CellFileStrc* gpCellFile_007797C4; // 0x007797C4
extern D2CellFileStrc* gpCellFile_007797E0; // 0x007797E0
extern D2CellFileStrc* gpCellFile_007797F4; // 0x007797F4
extern D2CellFileStrc* gpCellFile_00779808; // 0x00779808
extern D2CellFileStrc* gpCellFile_0077981C; // 0x0077981C
extern D2CellFileStrc* gpCellFile_00779830; // 0x00779830
extern D2CellFileStrc* gpCellFile_00779844; // 0x00779844
extern D2CellFileStrc* gpCellFile_00779858; // 0x00779858
extern D2CellFileStrc* gpCellFile_00779888; // 0x00779888
extern D2CellFileStrc* gpCellFile_0077989C; // 0x0077989C
extern D2CellFileStrc* gpCellFile_007798B0; // 0x007798B0
extern D2CellFileStrc* gpCellFile_007798C4; // 0x007798C4
int __cdecl sub_00525150(); // 0x00525150
int __cdecl sub_004F9050(); // 0x004F9050
void __stdcall D2Win_10004(int nResolution); // 0x004F9060
int __stdcall sub_00431600_ShowLevelScreen(int nUnused); // 0x00431600
void __cdecl sub_0042FB20(); // 0x0042FB20
void __cdecl sub_004FAD70(); // 0x004FAD70
int __fastcall ARCHIVE_LoadExpansionArchives(int (__cdecl* pfnPlayDisc)(), int (__cdecl* pfnExpansionDisc)(), int nUnused, D2ConfigStrc* pCfg); // 0x004FAEC0
int __cdecl sub_00431A00_ShowDiscMessage(); // 0x00431A00
int __cdecl sub_00434220_PlayDisc(); // 0x00434220
int __cdecl sub_004342E0_ExpansionDisc(); // 0x004342E0
extern D2ConfigStrc* gpConfig_007795D4; // 0x007795D4
extern "C" const char gszMainMenusFile_006D41C0[]; // 0x006D41C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __fastcall sub_004068E0(const char* szFileName, void** phFile); // 0x004068E0
void __fastcall sub_004068F0(void* hFile); // 0x004068F0
int __fastcall sub_00406900(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900
int __fastcall sub_00406930(void* hFile, unsigned int* pnSizeHigh); // 0x00406930
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __fastcall sub_0042E5D0_SwapUnicodeBytes(Unicode* pText, int nLength); // 0x0042E5D0
Unicode* __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
extern D2WinControlStrc* gpList_0077995C; // 0x0077995C
extern D2WinControlStrc* gpList_00779960; // 0x00779960
extern D2WinControlStrc* gpList_00779964; // 0x00779964
extern "C" int __cdecl isalpha(int c); // 0x00686DA5
Unicode* __stdcall sub_00430CD0_LoadCreditsText(int* pnLength); // 0x00430CD0
void __cdecl sub_00430C80_FillList(); // 0x00430C80
void __cdecl sub_00430EF0_SyncLists(); // 0x00430EF0
extern "C" const char gszDiablo2_006CC8B8[]; // 0x006CC8B8
extern "C" const char gszDottedQuadFormat_006CDEA4[]; // 0x006CDEA4
extern "C" const char gszAuxBattleNet_006D4164[]; // 0x006D4164
extern "C" const char gszLastTcpIp_006D4224[]; // 0x006D4224
extern "C" const char gszDottedQuadLongFormat_006D4174[]; // 0x006D4174
extern "C" const char gszEng_006D41A4[]; // 0x006D41A4
extern "C" const char gszAuxAddressFormat_006D4868[]; // 0x006D4868
extern "C" const char gszIntroFormatEng_006D4878[]; // 0x006D4878
extern "C" const char gszIntroFormat_006D4894[]; // 0x006D4894
extern "C" const char gszVersionSuffix_006D48D0[]; // 0x006D48D0
extern "C" const char gszVersionFormat_006D48D4[]; // 0x006D48D4
extern "C" const char gszDotsFormat_006D4D9C[]; // 0x006D4D9C
extern "C" const char gszDots_006D4DA4[]; // 0x006D4DA4
extern D2WinControlStrc* gpOkButton_00779330; // 0x00779330
extern D2WinControlStrc* gpControl_007795AC; // 0x007795AC
extern D2LaunchRecordStrc* gpLaunchRecord_007795D4; // 0x007795D4
extern int gbFeCharPalette_007795F0; // 0x007795F0
extern int gbFlag_00779984; // 0x00779984
extern D2WinControlStrc* gpStatusText_007799A8; // 0x007799A8
extern D2WinControlStrc* gpCounterText_007799AC; // 0x007799AC
extern int gnStatusStringId_007799B0; // 0x007799B0
extern unsigned long gdwStatusStart_007799B8; // 0x007799B8
extern "C" const char gszCellPath_006D4100[]; // 0x006D4100
extern "C" const char gszCellPath_006D40DC[]; // 0x006D40DC
extern "C" const char gszCellPath_006D40C0[]; // 0x006D40C0
extern "C" const char gszCellPath_006D40AC[]; // 0x006D40AC
extern "C" const char gszCellPath_006D4094[]; // 0x006D4094
extern "C" const char gszCellPath_006D4074[]; // 0x006D4074
extern "C" const char gszCellPath_006D4054[]; // 0x006D4054
extern "C" const char gszCellPath_006D4034[]; // 0x006D4034
extern "C" const char gszCellPath_006D4014[]; // 0x006D4014
extern "C" const char gszCellPath_006D3FF0[]; // 0x006D3FF0
extern "C" const char gszCellPath_006D3FD4[]; // 0x006D3FD4
extern "C" const char gszCellPath_006D3FB0[]; // 0x006D3FB0
extern "C" const char gszCellPath_006D3F90[]; // 0x006D3F90
extern "C" const char gszCellPath_006D3F70[]; // 0x006D3F70
extern "C" const char gszCellPath_006D3F4C[]; // 0x006D3F4C
extern "C" const char gszCellPath_006D3F28[]; // 0x006D3F28
extern "C" const char gszCellPath_006D3F0C[]; // 0x006D3F0C
extern "C" const char gszCellPath_006D3EE8[]; // 0x006D3EE8
extern "C" const char gszCellPath_006D3EC4[]; // 0x006D3EC4
extern "C" const char gszCellPath_006D3E98[]; // 0x006D3E98
extern "C" const char gszCellPath_006D3E70[]; // 0x006D3E70
extern "C" const char gszCellPath_006D3E4C[]; // 0x006D3E4C
extern "C" const char gszCellPath_006D3E28[]; // 0x006D3E28
extern "C" const char gszCellPath_006D3E10[]; // 0x006D3E10
extern "C" const char gszCellPath_006D3DF0[]; // 0x006D3DF0
extern "C" const char gszCellPath_006D3DD0[]; // 0x006D3DD0
extern "C" const char gszCellPath_006D3DB0[]; // 0x006D3DB0
extern "C" const char gszCellPath_006D3D8C[]; // 0x006D3D8C
extern "C" const char gszCellPath_006D3D68[]; // 0x006D3D68
extern "C" const char gszCellPath_006D3D48[]; // 0x006D3D48
extern "C" const char gszCellPath_006D3D24[]; // 0x006D3D24
extern "C" const char gszCellPath_006D3D00[]; // 0x006D3D00
extern "C" const char gszCellPath_006D3CE8[]; // 0x006D3CE8
extern "C" const char gszCellPath_006D3CC8[]; // 0x006D3CC8
extern "C" const char gszCellPath_006D3CAC[]; // 0x006D3CAC
extern "C" const char gszCellPath_006D3C90[]; // 0x006D3C90
extern "C" const char gszCellPath_006D3C70[]; // 0x006D3C70
extern "C" const char gszCellPath_006D3C58[]; // 0x006D3C58
extern "C" const char gszCellPath_006D3C38[]; // 0x006D3C38
extern "C" const char gszCellPath_006D3C18[]; // 0x006D3C18
extern "C" const char gszCellPath_006D3BF4[]; // 0x006D3BF4
extern "C" const char gszCellPath_006D3BD0[]; // 0x006D3BD0
extern "C" const char gszCellPath_006D3BAC[]; // 0x006D3BAC
extern "C" const char gszCellPath_006D3B8C[]; // 0x006D3B8C
extern "C" const char gszCellPath_006D3B74[]; // 0x006D3B74
extern "C" const char gszCellPath_006D3B4C[]; // 0x006D3B4C
extern "C" const char gszCellPath_006D3B28[]; // 0x006D3B28
extern "C" const char gszCellPath_006D3B0C[]; // 0x006D3B0C
extern "C" const char gszCellPath_006D3AF0[]; // 0x006D3AF0
extern "C" const char gszCellPath_006D3ACC[]; // 0x006D3ACC
extern "C" const char gszCellPath_006D3AB0[]; // 0x006D3AB0
extern "C" const char gszCellPath_006D3A94[]; // 0x006D3A94
extern "C" const char gszCellPath_006D3A78[]; // 0x006D3A78
extern "C" const char gszCellPath_006D3A54[]; // 0x006D3A54
extern "C" const char gszCellPath_006D3A30[]; // 0x006D3A30
extern "C" const char gszCellPath_006D3A10[]; // 0x006D3A10
extern "C" const char gszCellPath_006D4844[]; // 0x006D4844
extern "C" const char gszCellPath_006D4818[]; // 0x006D4818
extern "C" const char gszCellPath_006D47F8[]; // 0x006D47F8
extern "C" const char gszCellPath_006D47E4[]; // 0x006D47E4
extern "C" const char gszCellPath_006D47CC[]; // 0x006D47CC
extern "C" const char gszCellPath_006D47B4[]; // 0x006D47B4
extern "C" const char gszCellPath_006D4790[]; // 0x006D4790
extern "C" const char gszCellPath_006D4770[]; // 0x006D4770
extern "C" const char gszCellPath_006D4750[]; // 0x006D4750
extern "C" const char gszCellPath_006D4730[]; // 0x006D4730
extern "C" const char gszCellPath_006D4710[]; // 0x006D4710
extern "C" const char gszCellPath_006D46F0[]; // 0x006D46F0
extern "C" const char gszCellPath_006D46D4[]; // 0x006D46D4
extern "C" const char gszCellPath_006D46B8[]; // 0x006D46B8
extern "C" const char gszCellPath_006D469C[]; // 0x006D469C
extern "C" const char gszCellPath_006D4680[]; // 0x006D4680
extern "C" const char gszCellPath_006D4664[]; // 0x006D4664
extern "C" const char gszCellPath_006D4648[]; // 0x006D4648
extern "C" const char gszCellPath_006D462C[]; // 0x006D462C
extern "C" const char gszCellPath_006D4610[]; // 0x006D4610
extern "C" const char gszCellPath_006D45F4[]; // 0x006D45F4
extern "C" const char gszCellPath_006D45D8[]; // 0x006D45D8
extern "C" const char gszCellPath_006D45B4[]; // 0x006D45B4
extern "C" const char gszCellPath_006D4590[]; // 0x006D4590
extern "C" const char gszCellPath_006D4570[]; // 0x006D4570
extern "C" const char gszCellPath_006D454C[]; // 0x006D454C
extern "C" const char gszCellPath_006D452C[]; // 0x006D452C
extern "C" const char gszCellPath_006D450C[]; // 0x006D450C
extern "C" const char gszCellPath_006D44EC[]; // 0x006D44EC
extern "C" const char gszCellPath_006D44CC[]; // 0x006D44CC
extern "C" const char gszCellPath_006D44AC[]; // 0x006D44AC
extern "C" const char gszCellPath_006D448C[]; // 0x006D448C
extern "C" const char gszCellPath_006D446C[]; // 0x006D446C
extern "C" const char gszCellPath_006D444C[]; // 0x006D444C
extern "C" const char gszCellPath_006D442C[]; // 0x006D442C
extern "C" const char gszCellPath_006D440C[]; // 0x006D440C
extern "C" const char gszCellPath_006D43EC[]; // 0x006D43EC
extern "C" const char gszCellPath_006D43CC[]; // 0x006D43CC
extern "C" const char gszCellPath_006D43AC[]; // 0x006D43AC
extern "C" const char gszCellPath_006D4390[]; // 0x006D4390
extern "C" const char gszCellPath_006D4370[]; // 0x006D4370
extern "C" const char gszCellPath_006D4354[]; // 0x006D4354
extern "C" const char gszCellPath_006D4334[]; // 0x006D4334
extern "C" const char gszCellPath_006D4314[]; // 0x006D4314
extern "C" const char gszCellPath_006D42F4[]; // 0x006D42F4
extern "C" const char gszCellPath_006D42D0[]; // 0x006D42D0
extern "C" const char gszCellPath_006D42AC[]; // 0x006D42AC
extern "C" const char gszCellPath_006D4288[]; // 0x006D4288
extern "C" const char gszCellPath_006D4268[]; // 0x006D4268
extern "C" const char gszCellPath_006D4248[]; // 0x006D4248
extern D2CellFileStrc* gpCellFile_007797E4; // 0x007797E4
extern D2CellFileStrc* gpCellFile_007797E8; // 0x007797E8
extern D2CellFileStrc* gpCellFile_007797EC; // 0x007797EC
extern D2CellFileStrc* gpCellFile_007797F0; // 0x007797F0
extern D2CellFileStrc* gpCellFile_007797F8; // 0x007797F8
extern D2CellFileStrc* gpCellFile_007797FC; // 0x007797FC
extern D2CellFileStrc* gpCellFile_00779800; // 0x00779800
extern D2CellFileStrc* gpCellFile_00779804; // 0x00779804
extern D2CellFileStrc* gpCellFile_0077980C; // 0x0077980C
extern D2CellFileStrc* gpCellFile_00779810; // 0x00779810
extern D2CellFileStrc* gpCellFile_00779814; // 0x00779814
extern D2CellFileStrc* gpCellFile_00779818; // 0x00779818
extern D2CellFileStrc* gpCellFile_00779820; // 0x00779820
extern D2CellFileStrc* gpCellFile_00779824; // 0x00779824
extern D2CellFileStrc* gpCellFile_00779828; // 0x00779828
extern D2CellFileStrc* gpCellFile_0077982C; // 0x0077982C
extern D2CellFileStrc* gpCellFile_00779834; // 0x00779834
extern D2CellFileStrc* gpCellFile_00779838; // 0x00779838
extern D2CellFileStrc* gpCellFile_0077983C; // 0x0077983C
extern D2CellFileStrc* gpCellFile_00779840; // 0x00779840
extern D2CellFileStrc* gpCellFile_00779848; // 0x00779848
extern D2CellFileStrc* gpCellFile_0077984C; // 0x0077984C
extern D2CellFileStrc* gpCellFile_00779850; // 0x00779850
extern D2CellFileStrc* gpCellFile_00779854; // 0x00779854
extern D2CellFileStrc* gpCellFile_0077985C; // 0x0077985C
extern D2CellFileStrc* gpCellFile_00779860; // 0x00779860
extern D2CellFileStrc* gpCellFile_00779864; // 0x00779864
extern D2CellFileStrc* gpCellFile_00779868; // 0x00779868
extern D2CellFileStrc* gpCellFile_0077988C; // 0x0077988C
extern D2CellFileStrc* gpCellFile_00779890; // 0x00779890
extern D2CellFileStrc* gpCellFile_007798A0; // 0x007798A0
extern D2CellFileStrc* gpCellFile_007798A4; // 0x007798A4

struct D2LaunchSlotStrc
{
    char* szName;
    void* pData;
};

struct D2MenuListStrc
{
    int unk_00;
    int nCount;
};

extern "C" unsigned int __cdecl strlen(const char* szText);
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void __cdecl qsort(void* pBase, unsigned int nCount, unsigned int nSize, int (__cdecl* pfnCompare)(const void*, const void*)); // 0x00685B50
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
int __stdcall sub_00431D10_ClearLoop(int nArg); // 0x00431D10
int __cdecl sub_00430B00_CompareNames(const void* pEntry1, const void* pEntry2); // 0x00430B00
extern D2MenuListStrc* gpMenuList_007795C0; // 0x007795C0
extern int gdwGlobal_0077998C; // 0x0077998C

int __cdecl sub_00431F70_SaveExists();

D2WinControlStrc* gpOkButton_00779330; // 0x00779330

D2WinControlStrc* gpControl_007795AC; // 0x007795AC

D2LaunchRecordStrc* gpLaunchRecord_007795D4; // 0x007795D4

int gbFeCharPalette_007795F0; // 0x007795F0

int gbFlag_00779984; // 0x00779984

D2WinControlStrc* gpStatusText_007799A8; // 0x007799A8

D2WinControlStrc* gpCounterText_007799AC; // 0x007799AC

int gnStatusStringId_007799B0; // 0x007799B0

unsigned long gdwStatusStart_007799B8; // 0x007799B8

D2CellFileStrc* gpCellFile_007797E4; // 0x007797E4

D2CellFileStrc* gpCellFile_007797E8; // 0x007797E8

D2CellFileStrc* gpCellFile_007797EC; // 0x007797EC

D2CellFileStrc* gpCellFile_007797F0; // 0x007797F0

D2CellFileStrc* gpCellFile_007797F8; // 0x007797F8

D2CellFileStrc* gpCellFile_007797FC; // 0x007797FC

D2CellFileStrc* gpCellFile_00779800; // 0x00779800

D2CellFileStrc* gpCellFile_00779804; // 0x00779804

D2CellFileStrc* gpCellFile_0077980C; // 0x0077980C

D2CellFileStrc* gpCellFile_00779810; // 0x00779810

D2CellFileStrc* gpCellFile_00779814; // 0x00779814

D2CellFileStrc* gpCellFile_00779818; // 0x00779818

D2CellFileStrc* gpCellFile_00779820; // 0x00779820

D2CellFileStrc* gpCellFile_00779824; // 0x00779824

D2CellFileStrc* gpCellFile_00779828; // 0x00779828

D2CellFileStrc* gpCellFile_0077982C; // 0x0077982C

D2CellFileStrc* gpCellFile_00779834; // 0x00779834

D2CellFileStrc* gpCellFile_00779838; // 0x00779838

D2CellFileStrc* gpCellFile_0077983C; // 0x0077983C

D2CellFileStrc* gpCellFile_00779840; // 0x00779840

D2CellFileStrc* gpCellFile_00779848; // 0x00779848

D2CellFileStrc* gpCellFile_0077984C; // 0x0077984C

D2CellFileStrc* gpCellFile_00779850; // 0x00779850

D2CellFileStrc* gpCellFile_00779854; // 0x00779854

D2CellFileStrc* gpCellFile_0077985C; // 0x0077985C

D2CellFileStrc* gpCellFile_00779860; // 0x00779860

D2CellFileStrc* gpCellFile_00779864; // 0x00779864

D2CellFileStrc* gpCellFile_00779868; // 0x00779868

D2CellFileStrc* gpCellFile_0077988C; // 0x0077988C

D2CellFileStrc* gpCellFile_00779890; // 0x00779890

D2CellFileStrc* gpCellFile_007798A0; // 0x007798A0

D2CellFileStrc* gpCellFile_007798A4; // 0x007798A4

// 0x0042E6D0
void __cdecl sub_0042E6D0_LoadFrontEndCells()
{
    char szPath[0x104];
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\blizno", szDataGlobal_006D4118);
    gpCellFile_007796F8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\trademarkscreenEXP", szDataGlobal_006D4118);
    else
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\trademark", szDataGlobal_006D4118);
    gpCellFile_007796FC = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\CURSOR\\ohand", szDataGlobal_006D4118);
    gpCellFile_0077971C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\Diablo2", szDataGlobal_006D4118);
    gpCellFile_00779704 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoBlackLeft", szDataGlobal_006D4118);
    gpCellFile_00779708 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoFireLeft", szDataGlobal_006D4118);
    gpCellFile_0077970C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoBlackRight", szDataGlobal_006D4118);
    gpCellFile_00779710 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoFireRight", szDataGlobal_006D4118);
    gpCellFile_00779714 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\gameselectscreenEXP", szDataGlobal_006D4118);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\TitleScreen", szDataGlobal_006D4118);
    gpCellFile_00779718 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\creditsbckgexpand", szDataGlobal_006D4118);
    else
        wsprintfA(szPath, "%s\\ui\\CharSelect\\creditsbckg", szDataGlobal_006D4118);
    gpCellFile_00779720 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\WideButtonBlank", szDataGlobal_006D4118);
    gpCellFile_00779738 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\WideButtonBlank02", szDataGlobal_006D4118);
    gpCellFile_00779754 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\NarrowButtonBlank", szDataGlobal_006D4118);
    gpCellFile_00779758 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\GWListBox", szDataGlobal_006D4118);
    gpCellFile_0077975C = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
    {
        wsprintfA(szPath, "%s\\ui\\CharSelect\\Realmselectbutton", szDataGlobal_006D4118);
        gpCellFile_0077972C = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\CharSelect\\TallButtonBlank", szDataGlobal_006D4118);
        gpCellFile_00779730 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\CharSelect\\characterselectscreenEXP", szDataGlobal_006D4118);
        gpCellFile_00779734 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CinematicsSelectionEXP", szDataGlobal_006D4118);
        gpCellFile_00779774 = sub_004FA9B0_LoadCellFile(szPath, 0);
    }
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\MediumButtonBlank", szDataGlobal_006D4118);
    gpCellFile_0077973C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\ShortButtonBlank", szDataGlobal_006D4118);
    gpCellFile_00779740 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\textbox2", szDataGlobal_006D4118);
    gpCellFile_00779748 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\3WideButtonBlank", szDataGlobal_006D4118);
    gpCellFile_0077974C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\TermsofUseBckg", szDataGlobal_006D4118);
    gpCellFile_00779764 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectbckg", szDataGlobal_006D4118);
    gpCellFile_00779768 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\DifficultyLevels", szDataGlobal_006D4118);
    gpCellFile_0077976C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\CinematicsSelection", szDataGlobal_006D4118);
    gpCellFile_00779770 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectbox", szDataGlobal_006D4118);
    gpCellFile_00779778 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectboxgrey", szDataGlobal_006D4118);
    gpCellFile_0077977C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\CreateNewCharImage", szDataGlobal_006D4118);
    gpCellFile_00779794 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOK", szDataGlobal_006D4118);
    gpCellFile_00779798 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUp_340x224", szDataGlobal_006D4118);
    gpCellFile_0077979C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpWide", szDataGlobal_006D4118);
    gpCellFile_007797A0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpLargest", szDataGlobal_006D4118);
    gpCellFile_007797A4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\TileableDialog", szDataGlobal_006D4118);
    gpCellFile_007797A8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOK2", szDataGlobal_006D4118);
    gpCellFile_007797AC = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOKCancel", szDataGlobal_006D4118);
    gpCellFile_00779780 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOKCancel2", szDataGlobal_006D4118);
    gpCellFile_00779784 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\OkCancelButtonBlank", szDataGlobal_006D4118);
    gpCellFile_007797B0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\CancelButtonBlank", szDataGlobal_006D4118);
    gpCellFile_007797B4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\selectchararrows", szDataGlobal_006D4118);
    gpCellFile_00779788 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\Realmselect", szDataGlobal_006D4118);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CurRealm", szDataGlobal_006D4118);
    gpCellFile_0077978C = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\RealmSelectbuttonthin", szDataGlobal_006D4118);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\NarrowButtonBlank02", szDataGlobal_006D4118);
    gpCellFile_00779790 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\password", szDataGlobal_006D4118);
    gpCellFile_007797B8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\realmbckg", szDataGlobal_006D4118);
    gpCellFile_007797C8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\FRONTEND\\joingamescrollbars", szDataGlobal_006D4118);
    gpCellFile_007797CC = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\tcpipscreen", szDataGlobal_006D4118);
    else
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\tcpipbckg", szDataGlobal_006D4118);
    gpCellFile_007797D0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\IPAddressBox", szDataGlobal_006D4118);
    gpCellFile_007797D4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\downloadpatchbckg", szDataGlobal_006D4118);
    gpCellFile_007797D8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\downloadpatchball2", szDataGlobal_006D4118);
    gpCellFile_007797DC = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\EditTextBoxWide", szDataGlobal_006D4118);
    gpCellFile_00779750 = sub_004FA9B0_LoadCellFile(szPath, 0);
}

// 0x0042F2E0
int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2)
{
    char szPathA[0x104];
    char szPathB[0x104];
    gbPaletteBusy_00779970 = 1;
    wsprintfA(szPathA, gszPathFormat_006D4124, szDataGlobal_006D4118, szFile1);
    wsprintfA(szPathB, gszPathFormat_006D4124, szDataGlobal_006D4118, szFile2);
    gbFeCharPalette_007795F0 = strcmp(szFile1, "palette\\fechar\\pal.dat") == 0;
    sub_004FB500(szPathA, szPathB);
    return 1;
}

// 0x0042FA40
int __cdecl sub_0042FA40_InitAuxBattleNet()
{
    char szAddress[0x64];
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
        return 1;
    sprintf(szAddress, "%d.%d.%d.%d", 0xD8, 0x94, 0xF6, 0x22);
    SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
    return 0;
}

// 0x0042FAB0
int __cdecl sub_0042FAB0_GetAuxFlag()
{
    char szAddress[0x64];
    int a;
    int b;
    int c;
    int d;
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
    {
        d = 0x22;
        sscanf(szAddress, "%ld.%ld.%ld.%ld", &a, &b, &c, &d);
        unsigned char nLow = (unsigned char)d;
        if (nLow & 0x10)
            return (unsigned char)~nLow >> 7;
    }
    return 0;
}

// 0x00430620
void __cdecl sub_00430620_UpdateNameOk()
{
    char szText[0x20];
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit_0077934C);
    int bValid = 0;
    if (pText)
    {
        const int nLen = sub_00526800(pText);
        sub_005263E0(szText, pText, 0x20);
        if (nLen >= 2 && nLen <= 15)
        {
            const char cLast = szText[nLen - 1];
            const char cFirst = szText[0];
            if (cLast != '_' && cFirst != '_' && cLast != '-' && cFirst != '-')
            {
                int nCount = 0;
                for (int i = 0; i < nLen; i += 1)
                {
                    if (szText[i] == '-' || szText[i] == '_')
                        nCount += 1;
                }
                if (nCount < 2)
                    bValid = 1;
            }
        }
    }
    sub_004F96F0_ControlClearState(gpOkButton_00779330, bValid);
}

// 0x00430BC0
int __cdecl sub_00430BC0_HasSaveFiles()
{
    char szDir[0x400];
    char szPattern[0x400];
    D2FindDataStrc tFind;
    sub_00407050_GetSavePath(szDir, 0x400);
    sprintf(szPattern, gszSaveMask_006D41D4, szDir);
    void* hFind = FindFirstFileA(szPattern, &tFind);
    if (hFind != (void*)-1)
    {
        FindClose(hFind);
        return 1;
    }
    return 0;
}

// 0x00431600
int __stdcall sub_00431600_ShowLevelScreen(int nUnused)
{
    char szAddress[0x64];
    unsigned char nLevel;
    sub_00515F50(0xB4);
    sub_00514930();
    sub_00515CE0_SetMasterVolume(0xFF);
    sub_0043C4F0();
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
    {
        int a;
        int b;
        int c;
        int d = 0x22;
        sscanf(szAddress, "%ld.%ld.%ld.%ld", &a, &b, &c, &d);
        const unsigned char nLow = (unsigned char)d;
        if (nLow & 1)
            nLevel = 7;
        else if (nLow & 0x80)
            nLevel = 6;
        else if (nLow & 0x10)
            nLevel = 5;
        else if (nLow & 0x08)
            nLevel = 4;
        else if (nLow & 0x40)
            nLevel = 3;
        else
            nLevel = (nLow & 4) ? 2 : 1;
    }
    else
    {
        nLevel = 1;
        sprintf(szAddress, "%d.%d.%d.%d", 0xD8, 0x94, 0xF6, 0x22);
        SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
    }
    if (sub_00408F20_HasExpansionMpq())
    {
        sub_004313D0(nLevel);
        return 1;
    }
    sub_0042F430_CreateControl(0x32);
    D2WinControlStrc* pTitle = sub_0042F430_CreateControl(0x33);
    sub_004FD060_SetText(pTitle, D2LANG_GetStringFromTblIndex(0x13FA));
    sub_0042F430_CreateControl(0x34);
    D2WinControlStrc* pField1 = sub_0042F430_CreateControl(0x35);
    D2WinControlStrc* pField2 = sub_0042F430_CreateControl(0x36);
    D2WinControlStrc* pField3 = sub_0042F430_CreateControl(0x37);
    D2WinControlStrc* pField4 = sub_0042F430_CreateControl(0x38);
    switch (nLevel)
    {
    default:
        sub_004F96F0_ControlClearState(pField1, 0);
    case 2:
        sub_004F96F0_ControlClearState(pField2, 0);
    case 3:
        sub_004F96F0_ControlClearState(pField3, 0);
    case 4:
        sub_004F96F0_ControlClearState(pField4, 0);
    case 5:
    case 6:
    case 7:
        break;
    }
    sub_0042F430_CreateControl(0x39);
    return 1;
}

// 0x004326F0
void __cdecl sub_004326F0_LoadFrontEndCells2()
{
    char szPath[0x104];
    if (gpCellFile_00779724)
        return;
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\MediumSelButtonBlank", szDataGlobal_006D4118);
    gpCellFile_00779744 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\charactercreationscreenEXP", szDataGlobal_006D4118);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CharacterCreate", szDataGlobal_006D4118);
    gpCellFile_00779724 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\fire", szDataGlobal_006D4118);
    gpCellFile_00779728 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\textbox", szDataGlobal_006D4118);
    gpCellFile_007797BC = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\clickbox", szDataGlobal_006D4118);
    gpCellFile_007797C0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
    {
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\joingameclickboxgrey", szDataGlobal_006D4118);
        gpCellFile_007797C4 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu1", szDataGlobal_006D4118);
        gpCellFile_007797E0 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu2", szDataGlobal_006D4118);
        gpCellFile_007797E4 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asfw", szDataGlobal_006D4118);
        gpCellFile_007797E8 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu3", szDataGlobal_006D4118);
        gpCellFile_007797EC = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asbw", szDataGlobal_006D4118);
        gpCellFile_007797F0 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu1", szDataGlobal_006D4118);
        gpCellFile_007797F4 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu2", szDataGlobal_006D4118);
        gpCellFile_007797F8 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dzfw", szDataGlobal_006D4118);
        gpCellFile_007797FC = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu3", szDataGlobal_006D4118);
        gpCellFile_00779800 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dzbw", szDataGlobal_006D4118);
        gpCellFile_00779804 = sub_004FA9B0_LoadCellFile(szPath, 0);
    }
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu1", szDataGlobal_006D4118);
    gpCellFile_00779808 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu2", szDataGlobal_006D4118);
    gpCellFile_0077980C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amfw", szDataGlobal_006D4118);
    gpCellFile_00779810 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu3", szDataGlobal_006D4118);
    gpCellFile_00779814 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\ambw", szDataGlobal_006D4118);
    gpCellFile_00779818 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu1", szDataGlobal_006D4118);
    gpCellFile_0077981C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu2", szDataGlobal_006D4118);
    gpCellFile_00779820 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nefw", szDataGlobal_006D4118);
    gpCellFile_00779824 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu3", szDataGlobal_006D4118);
    gpCellFile_00779828 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nebw", szDataGlobal_006D4118);
    gpCellFile_0077982C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu1", szDataGlobal_006D4118);
    gpCellFile_00779830 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu2", szDataGlobal_006D4118);
    gpCellFile_00779834 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\bafw", szDataGlobal_006D4118);
    gpCellFile_00779838 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu3", szDataGlobal_006D4118);
    gpCellFile_0077983C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\babw", szDataGlobal_006D4118);
    gpCellFile_00779840 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu1", szDataGlobal_006D4118);
    gpCellFile_00779844 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu2", szDataGlobal_006D4118);
    gpCellFile_00779848 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sofw", szDataGlobal_006D4118);
    gpCellFile_0077984C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu3", szDataGlobal_006D4118);
    gpCellFile_00779850 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sobw", szDataGlobal_006D4118);
    gpCellFile_00779854 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu1", szDataGlobal_006D4118);
    gpCellFile_00779858 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu2", szDataGlobal_006D4118);
    gpCellFile_0077985C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pafw", szDataGlobal_006D4118);
    gpCellFile_00779860 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu3", szDataGlobal_006D4118);
    gpCellFile_00779864 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pabw", szDataGlobal_006D4118);
    gpCellFile_00779868 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sofws", szDataGlobal_006D4118);
    gpCellFile_0077989C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu3s", szDataGlobal_006D4118);
    gpCellFile_007798A0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sobws", szDataGlobal_006D4118);
    gpCellFile_007798A4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nefws", szDataGlobal_006D4118);
    gpCellFile_00779888 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu3s", szDataGlobal_006D4118);
    gpCellFile_0077988C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nebws", szDataGlobal_006D4118);
    gpCellFile_00779890 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\bafws", szDataGlobal_006D4118);
    gpCellFile_007798B0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pafws", szDataGlobal_006D4118);
    gpCellFile_007798C4 = sub_004FA9B0_LoadCellFile(szPath, 0);
}

// 0x004334E0
void __cdecl sub_004334E0_PlayIntro()
{
    char szPath[0x104];
    char szAddress[0x64];
    int a;
    int b;
    int c;
    int d;
    void* hFile;
    char szLanguage[4];
    char szSize[8];
    sub_004317D0_FlushInput();
    int nMode = 0;
    if (!sub_0040EB10())
    {
        strcpy(szSize, "640x292");
    }
    else
    {
        nMode = 2;
        strcpy(szSize, "640x146");
    }
    sub_00525260(szLanguage, 0);
    sprintf(szPath, "%s\\video\\%s\\D2x_Intro_%s.bik", gszDataLocal_006D41A8, szLanguage, szSize);
    if (SFileOpenFileEx(0, szPath, 0, &hFile))
        sub_004198D0(hFile);
    else
        sprintf(szPath, "%s\\video\\%s\\D2x_Intro%s.bik", gszDataLocal_006D41A8, "ENG", szSize);
    sub_004F5D90_PlayVideo(szPath, nMode, 0);
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
        sscanf(szAddress, "%ld.%ld.%ld.%ld", &a, &b, &c, &d);
    d |= 0x80;
    sprintf(szAddress, "%d.%d.%d.%ld", 0xD8, 0x94, 0xF6, d);
    SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
}

// 0x004336C0
void __cdecl sub_004336C0_ShowMainMenu()
{
    char szVersion[0x40];
    D2WinControlStrc* pFirst;
    D2WinControlStrc* pSecond;
    sub_0043B9A0();
    gpLaunchRecord_007795D4->szName[0] = 0;
    sub_0043C4F0();
    if (sub_00408F20_HasExpansionMpq())
    {
        gpControl_007795AC = sub_0042F430_CreateControl(0x12);
        sub_00431AF0();
        pFirst = sub_0042F430_CreateControl(0x11);
        pSecond = sub_0042F430_CreateControl(0x13);
        sub_0042F430_CreateControl(0x10);
    }
    else
    {
        pFirst = sub_0042F430_CreateControl(0x0A);
        gpControl_007795AC = sub_0042F430_CreateControl(0x0B);
        sub_00431AF0();
        sub_0042F430_CreateControl(0x09);
        pSecond = sub_0042F430_CreateControl(0x0C);
    }
    if (sub_004FAC90())
    {
        sub_004F96F0_ControlClearState(pFirst, 0);
        sub_004F96F0_ControlClearState(pSecond, 0);
        sub_004F96F0_ControlClearState(gpControl_007795AC, 0);
    }
    sub_0042F430_CreateControl(0x0D);
    sub_0042F430_CreateControl(0x0E);
    sub_0042F430_CreateControl(0x0F);
    D2WinControlStrc* pText = sub_0042F430_CreateControl(0x115);
    const int nLen = SStrPrintf(szVersion, 0x40, "v %d.%d%c", 1, 0x0E, 0x64);
    if (gpLaunchRecord_007795D4->bFlag223)
        SStrPrintf(&szVersion[nLen], 0x40 - nLen, " %d", 0x47);
    sub_004FCFF0_SetTextA(pText, szVersion, 0);
    if (sub_00514D80())
        D2SOUND_10034(1);
}

// 0x00434790
int __stdcall sub_00434790_JoinTcpIp(int nUnused)
{
    char szText[0x400];
    int a;
    int b;
    int c;
    int d;
    const Unicode* pText = sub_004FDD90_GetEditText(gpAddressEdit_00779958);
    sub_005263E0(szText, pText, 0x100);
    if (!szText[0])
        return 1;
    strncpy(gszAddress_007795F8, szText, 0xFF);
    gszAddress_007795F8[0xFF] = 0;
    SRegSaveString("Diablo II", "LastTcpIp", 0, gszAddress_007795F8);
    if (sscanf(szText, "%d.%d.%d.%d", &a, &b, &c, &d) != 4)
    {
        const char* szResolved = FOG_ResolveHostIPAddress(szText);
        if (szResolved)
        {
            strcpy(szText, szResolved);
        }
        else
        {
            sub_004FFE10_SetTextA(gpAddressEdit_00779958, &gszEmptyAssertText);
            return 1;
        }
    }
    strcpy(gpLaunchRecord_007795D4->szName, szText);
    sub_0042F6E0();
    sub_004FA590_RunLoop(sub_00431D10);
    gbConnected_0077959C = 0;
    sub_0052A750(0, szText);
    sub_004FA590_RunLoop(sub_00431E30);
    if (!gbConnected_0077959C)
    {
        sub_0052A7E0();
        sub_0042F3F0_DestroyControls();
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x145B);
        sub_00433380_ShowMessage(pMessage, sub_0042FFE0, 1);
        return 1;
    }
    sub_0042F3F0_DestroyControls();
    sub_0042F6E0();
    sub_004FA590_RunLoop(sub_00431C90);
    sub_0052A7E0();
    sub_0042F3F0_DestroyControls();
    if (!gdwGlobal_00779974)
    {
        gnLaunchMode_007795EC = 2;
        *(int*)gpLaunchRecord_007795D4->aState19 = 9;
        *(unsigned short*)gpLaunchRecord_007795D4->aWord1D = 1;
        sub_00515020();
        sub_0042F480_Reset();
        sub_0043B080();
    }
    return 1;
}

// 0x004365B0
void __cdecl sub_004365B0_CreateCharacter()
{
    char szName[0x100];
    if (sub_00431F70_SaveExists() == 1 && gnLaunchMode_007795EC != 1)
    {
        sub_00433460_ShowMessage(D2LANG_GetStringFromTblIndex(0x142D), sub_0042F3F0_DestroyControls);
        return;
    }
    if (gpLaunchRecord_007795D4->nClass == 6 || gpLaunchRecord_007795D4->nClass == 5)
        *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF |= 0x20;
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit_0077934C);
    sub_005263E0(szName, pText, 0x100);
    sprintf(gpLaunchRecord_007795D4->szCharName, gszStringFormat_006FFC58, szName);
    gpLaunchRecord_007795D4->nByteD5 = 0;
    if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
        gbFlag_00779984 = 1;
    if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
    {
        sub_00430520();
        return;
    }
    if (gnLaunchMode_007795EC == 0)
    {
        sub_0042F480_Reset();
        sub_0043C540(gpLaunchRecord_007795D4->szCharName, gpLaunchRecord_007795D4->nClass, gpLaunchRecord_007795D4->aDataED, *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0(gpLaunchRecord_007795D4->szCharName);
        gpLaunchRecord_007795D4->nByte35E = 1;
        *(int*)gpLaunchRecord_007795D4->aState19 = 0;
        gnLaunchState_007795E8 = 1;
        *(int*)gpLaunchRecord_007795D4->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
            *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord_007795D4->aState209 |= 0x100000;
        sub_004F9190();
    }
    else if (gnLaunchMode_007795EC == 2)
    {
        sub_0042F480_Reset();
        sub_0043C6A0(0);
        sub_0043C540(gpLaunchRecord_007795D4->szCharName, gpLaunchRecord_007795D4->nClass, gpLaunchRecord_007795D4->aDataED, *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0(gpLaunchRecord_007795D4->szCharName);
        gpLaunchRecord_007795D4->nByte35E = 3;
        gnLaunchState_007795E8 = 1;
        *(int*)gpLaunchRecord_007795D4->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
            *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord_007795D4->aState209 |= 0x100000;
        sub_004F9190();
    }
    else if (gnLaunchMode_007795EC == 3)
    {
        sub_0042F480_Reset();
        D2MCPClientCloseMCP();
        sub_0043C6A0(0);
        sub_0043C540(gpLaunchRecord_007795D4->szCharName, gpLaunchRecord_007795D4->nClass, gpLaunchRecord_007795D4->aDataED, *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0(gpLaunchRecord_007795D4->szCharName);
        gpLaunchRecord_007795D4->nByte3C1 = 1;
        SMemCopy(gpLaunchRecord_007795D4->aData3A1, gabDefault_006D4D88, 0x10);
        SMemZero(gpLaunchRecord_007795D4->aData3B1, 0x10);
        gpLaunchRecord_007795D4->nByte3C2 = (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF >> 6) & 1;
        *(unsigned short*)gpLaunchRecord_007795D4->aWord3CB = *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF;
        gpLaunchRecord_007795D4->nByte35E = 4;
        gpLaunchRecord_007795D4->nByte22D = 0;
        gpLaunchRecord_007795D4->nByteD5 = 0;
        gnLaunchState_007795E8 = 3;
        *(int*)gpLaunchRecord_007795D4->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
            *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord_007795D4->aState209 |= 0x100000;
        sub_004F9190();
    }
    else if (gnLaunchMode_007795EC == 1)
    {
        sub_00435E10();
    }
}

// 0x004369F0
int __stdcall sub_004369F0_OkClick(int nUnused)
{
    char szPath[0x400];
    if (sub_004F9710_TestFlags(gpOkButton_00779330))
    {
        sub_00407050_GetSavePath(szPath, 0x400);
        for (unsigned int i = 0; i < 0x400; i += 1)
        {
            if (szPath[i] == '\\')
            {
                szPath[i + 1] = 0;
                break;
            }
        }
        unsigned long nSectorsPerCluster = 0;
        unsigned long nBytesPerSector = 0;
        unsigned long nFreeClusters = 0;
        unsigned long nTotalClusters = 0;
        GetDiskFreeSpaceA(szPath, &nSectorsPerCluster, &nBytesPerSector, &nFreeClusters, &nTotalClusters);
        if (nFreeClusters * nBytesPerSector * nSectorsPerCluster < 5000)
        {
            sub_00433460_ShowMessage(D2LANG_GetStringFromTblIndex(0x141D), sub_0042FDD0);
            return 1;
        }
        sub_004F96F0_ControlClearState(gpOkButton_00779330, 0);
        sub_004365B0_CreateCharacter();
    }
    return 1;
}

// 0x00436AD0
void __cdecl sub_00436AD0_UpdateStatus()
{
    char szText[0x100];
    int nState;
    if (!gpStatusText_007799A8)
        return;
    gpFuncTable_0077ABF0->pfnSlot80(&nState);
    switch (nState)
    {
    case 0:
        gnStatusStringId_007799B0 = 0x1433;
        break;
    case 1:
        gnStatusStringId_007799B0 = 0x1434;
        break;
    case 2:
        gnStatusStringId_007799B0 = 0x1435;
        break;
    case 3:
        gnStatusStringId_007799B0 = 0x1436;
        break;
    case 4:
        gnStatusStringId_007799B0 = 0x1437;
        break;
    case 5:
        gnStatusStringId_007799B0 = 0x1438;
        break;
    case 6:
        gnStatusStringId_007799B0 = 0x1439;
        break;
    default:
        gnStatusStringId_007799B0 = -1;
        break;
    }
    sub_004FB6A0_ClearText(gpStatusText_007799A8);
    if (gnStatusStringId_007799B0 >= 0)
        sub_004FC9B0_SetText(gpStatusText_007799A8, D2LANG_GetStringFromTblIndex(gnStatusStringId_007799B0), 0, 0, 0);
    const unsigned long nCounter = (GetTickCount() - gdwStatusStart_007799B8) / 250 % 20 + 1;
    sprintf(szText, "%.*s", nCounter, "....................");
    sub_004FB6A0_ClearText(gpCounterText_007799AC);
    sub_004FCF80_SetTextA(gpCounterText_007799AC, szText);
}

static int sub_0042FCE0_ArchiveFilePresent(const char* szFile)
{
    void* hFile;
    if (!SFileOpenFileEx(0, szFile, 0, &hFile))
        return 0;
    sub_004198D0(hFile);
    return 1;
}

// 0x0042FD10
static void sub_0042FD10_BuildLocalizedVideoPath(char* szOut, const char* szFormat, const char* szFile)
{
    char szLang[4];
    sub_00525260(szLang, 0);
    sprintf(szOut, szFormat, gszDataLocal_006D41A8, szLang, szFile);
    if (sub_0042FCE0_ArchiveFilePresent(szOut))
        return;
    if (sub_00525150())
    {
        sprintf(szOut, szFormat, gszDataLocal_006D41A8, "ENG", szFile);
        sub_0042FCE0_ArchiveFilePresent(szOut);
    }
    else
    {
        sprintf(szOut, szFormat, gszDataLocal_006D41A8, "CHI", szFile);
        sub_0042FCE0_ArchiveFilePresent(szOut);
    }
}

// 0x00431870
static void __stdcall sub_00431870_PlayVideo(int nArg, const char* szFormat)
{
    char szPath[0x104];
    char szSize[8];
    sub_0042F480_Reset();
    sub_0042F3F0_DestroyControls();
    sub_004317D0_FlushInput();
    if (sub_004F9050())
    {
        int nMode = 0;
        if (!sub_0040EB10())
        {
            strcpy(szSize, "640x292");
        }
        else
        {
            nMode = 2;
            strcpy(szSize, "640x146");
        }
        sub_0042FD10_BuildLocalizedVideoPath(szPath, szFormat, szSize);
        sub_004F5D90_PlayVideo(szPath, nMode, 0);
        D2Win_10004(1);
    }
    sub_004317D0_FlushInput();
    sub_00431600_ShowLevelScreen(nArg);
}

// 0x00433640
void __cdecl sub_00433640_PlayIntroVideo()
{
    char szPath[0x104];
    char szSize[8];
    sub_004317D0_FlushInput();
    int nMode = 0;
    if (!sub_0040EB10())
    {
        strcpy(szSize, "640x292");
    }
    else
    {
        nMode = 2;
        strcpy(szSize, "640x146");
    }
    sub_0042FD10_BuildLocalizedVideoPath(szPath, "%s\\video\\%s\\d2intro%s.bik", szSize);
    sub_004F5D90_PlayVideo(szPath, nMode, 0);
    sub_0042FB20();
}

// 0x00434320
int __stdcall sub_00434320_PlayD2Intro(int nArg)
{
    sub_004FAD70();
    if (!ARCHIVE_LoadVideoArchives((void*)sub_00431A00_ShowDiscMessage, 0, 0))
    {
        sub_004FAD70();
        ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    sub_00431870_PlayVideo(nArg, "%s\\video\\%s\\d2intro%s.bik");
    return 1;
}

// 0x00434380
int __stdcall sub_00434380_PlayAct2Start(int nArg)
{
    sub_004FAD70();
    if (!ARCHIVE_LoadVideoArchives((void*)sub_00431A00_ShowDiscMessage, 0, 0))
    {
        sub_004FAD70();
        ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    sub_00431870_PlayVideo(nArg, "%s\\video\\%s\\Act02start%s.bik");
    return 1;
}

// 0x004343E0
int __stdcall sub_004343E0_PlayAct3Start(int nArg)
{
    sub_004FAD70();
    if (!ARCHIVE_LoadVideoArchives((void*)sub_00431A00_ShowDiscMessage, 0, 0))
    {
        sub_004FAD70();
        ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    sub_00431870_PlayVideo(nArg, "%s\\video\\%s\\Act03start%s.bik");
    return 1;
}

// 0x00434440
int __stdcall sub_00434440_PlayAct4Start(int nArg)
{
    sub_004FAD70();
    if (!ARCHIVE_LoadVideoArchives((void*)sub_00431A00_ShowDiscMessage, 0, 0))
    {
        sub_004FAD70();
        ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    sub_00431870_PlayVideo(nArg, "%s\\video\\%s\\Act04start%s.bik");
    return 1;
}

// 0x004344A0
int __stdcall sub_004344A0_PlayAct4End(int nArg)
{
    sub_004FAD70();
    if (!ARCHIVE_LoadVideoArchives((void*)sub_00431A00_ShowDiscMessage, 0, 0))
    {
        sub_004FAD70();
        ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    sub_00431870_PlayVideo(nArg, "%s\\video\\%s\\Act04end%s.bik");
    return 1;
}

// 0x00434500
int __stdcall sub_00434500_PlayXIntro(int nArg)
{
    sub_004FAD70();
    if (!ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4))
        ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
    sub_00431870_PlayVideo(nArg, "%s\\video\\%s\\D2x_Intro_%s.bik");
    return 1;
}

// 0x00434560
int __stdcall sub_00434560_PlayXOutro(int nArg)
{
    sub_004FAD70();
    if (!ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4))
        ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
    sub_00431870_PlayVideo(nArg, "%s\\video\\%s\\D2x_Out_%s.bik");
    return 1;
}

// 0x00430CD0
Unicode* __stdcall sub_00430CD0_LoadCreditsText(int* pnLength)
{
    void* hFile;
    char szLanguage[4];
    sub_00525260(szLanguage, 0);

    char szCredits[] = "Credits.txt";
    char szExpansionCredits[] = "ExpansionCredits.txt";
    char szPath[260];
    if (!sub_00408F20_HasExpansionMpq())
        SStrPrintf(szPath, 260, "%s\\UI\\%s\\%s", "DATA\\LOCAL", szLanguage, szCredits);
    else
        SStrPrintf(szPath, 260, "%s\\UI\\%s\\%s", "DATA\\LOCAL", szLanguage, szExpansionCredits);

    if (!sub_004068E0(szPath, &hFile))
        return 0;

    const int nSize = sub_00406930(hFile, 0);
    char* pBuffer = (char*)FOG_Alloc(nSize, gszMainMenusFile_006D41C0, 0x138B, 0);
    D2_ASSERT(pBuffer, 0x138C);

    memset(pBuffer, 0, nSize);
    Unicode* pText = 0;
    sub_00406900(hFile, pBuffer, nSize, 0, 0, 0, 0);
    sub_004068F0(hFile);

    if (nSize <= 2)
    {
        *pnLength = 0;
    }
    else if (*(unsigned short*)pBuffer == 0xFEFF)
    {
        const int nLength = (nSize - 2) / 2;
        *pnLength = nLength;
        pText = (Unicode*)FOG_Alloc(sizeof(Unicode) * nLength, gszMainMenusFile_006D41C0, 0x13B8, 0);
        memcpy(pText, pBuffer + 2, sizeof(Unicode) * *pnLength);
    }
    else if (*(unsigned short*)pBuffer == 0xFFFE)
    {
        const int nLength = (nSize - 2) / 2;
        *pnLength = nLength;
        pText = (Unicode*)FOG_Alloc(sizeof(Unicode) * nLength, gszMainMenusFile_006D41C0, 0x13BF, 0);
        memcpy(pText, pBuffer + 2, sizeof(Unicode) * *pnLength);
        sub_0042E5D0_SwapUnicodeBytes(pText, *pnLength);
    }
    else
    {
        *pnLength = nSize;
        pText = (Unicode*)FOG_Alloc(sizeof(Unicode) * nSize + 1, gszMainMenusFile_006D41C0, 0x13C8, 0);
        sub_00526F20_ToUnicode(pText, pBuffer, nSize);
    }

    FOG_Free(pBuffer, gszMainMenusFile_006D41C0, 0x13CC, 0);

    int i = 0;
    while (i < *pnLength)
    {
        if (pText[i].wChar != '\n' && pText[i].wChar != '\r')
        {
            ++i;
            continue;
        }
        pText[i].wChar = 0;
        ++i;
    }

    return pText;
}

// 0x00431050
int __fastcall sub_00431050_ShowCredits(int nUnused)
{
    int nLength = 0;
    Unicode* pText = sub_00430CD0_LoadCreditsText(&nLength);
    Unicode wszLine[1024];
    D2_ASSERT(pText, 0x141B);

    for (int i = 0; i < 50; ++i)
    {
        sub_004FCF80_SetTextA(gpList_00779964, &gszEmptyAssertText);
        sub_004FCF80_SetTextA(gpList_0077995C, &gszEmptyAssertText);
        sub_004FCF80_SetTextA(gpList_00779960, &gszEmptyAssertText);
    }

    int nRemain = nLength;
    Unicode* pCursor = pText;
    while (nRemain)
    {
        if (pCursor->wChar == 0x2A)
        {
            sub_004FCF80_SetTextA(gpList_0077995C, &gszEmptyAssertText);
            sub_004FCF80_SetTextA(gpList_00779960, &gszEmptyAssertText);
            ++pCursor;
            if (sub_005267E0(wszLine, pCursor))
                sub_004FC9B0_SetText(gpList_00779964, wszLine, 1, 0, 0);
            else
                nRemain = 0;
            int nSkip = sub_00526800(wszLine) + 2;
            nRemain -= nSkip;
            pCursor += nSkip;
        }
        else
        {
            do
            {
                if (!nRemain)
                    break;
                Unicode wszLeft[256];
                Unicode wszRight[256];
                wszLeft[0].wChar = 0;
                wszRight[0].wChar = 0;
                if (pCursor->wChar < 0x80 && isalpha((char)pCursor->wChar) && sub_005267E0(wszLine, pCursor))
                {
                    sub_005267E0(wszLeft, wszLine);
                    int nSkip = sub_00526800(wszLine) + 2;
                    nRemain -= nSkip;
                    pCursor += nSkip;
                }
                else
                {
                    nRemain = 0;
                }

                if (nRemain && pCursor->wChar != 0x2A)
                {
                    if (sub_005267E0(wszLine, pCursor))
                    {
                        sub_005267E0(wszRight, wszLine);
                        int nSkip = sub_00526800(wszLine) + 2;
                        nRemain -= nSkip;
                        pCursor += nSkip;
                    }
                    else
                    {
                        nRemain = 0;
                    }
                }

                if (wszLeft[0].wChar && wszRight[0].wChar)
                {
                    sub_004FD060_SetText(gpList_0077995C, wszLeft);
                    sub_004FD060_SetText(gpList_00779960, wszRight);
                }
                else
                {
                    sub_004FD060_SetText(gpList_00779964, wszLeft);
                }
                sub_004FCF80_SetTextA(gpList_00779964, &gszEmptyAssertText);
            } while (pCursor->wChar != 0x2A);
        }
        sub_00430EF0_SyncLists();
    }

    sub_00430C80_FillList();
    FOG_Free(pText, ".\\Src\\MainMenus.cpp", 0x146F, 0);
    return 1;
}

// 0x00431F70
int __cdecl sub_00431F70_SaveExists()
{
    char szDir[0x400];
    char szUtf8[0x100];
    char szPath[0x104];
    char szName[0x100];
    sub_00407050_GetSavePath(szDir, 0x400);
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit_0077934C);
    sub_005263E0(szUtf8, pText, 0x100);
    sprintf(szName, gszStringFormat_006FFC58, szUtf8);
    sprintf(szPath, gszSavePathFormat_006D4230, szDir, szName);
    void* hFile = sub_00406960_CreateFile(szPath, 0x80000000, 0, 0, 3, 0x8000000, 0);
    if (hFile != (void*)-1)
    {
        sub_004069A0_CloseFile(hFile);
        return 1;
    }
    return 0;
}

static D2LaunchSlotStrc** gppSlots_00779988; // 0x00779988

// 0x004309C0
int __stdcall sub_004309C0_AddToSlots(void* pEntry)
{
    D2_ASSERT(gppSlots_00779988, 4383);
    for (int i = 0; i < gdwGlobal_0077998C; i++)
    {
        if (!gppSlots_00779988[i])
        {
            gppSlots_00779988[i] = (D2LaunchSlotStrc*)pEntry;
            return 1;
        }
    }
    return 0;
}

// 0x00430A20
int __cdecl sub_00430A20_FreeSlots()
{
    if (!gppSlots_00779988)
        return 1;
    for (int i = 0; i < gdwGlobal_0077998C; i++)
    {
        D2LaunchSlotStrc* pSlot = gppSlots_00779988[i];
        if (pSlot)
        {
            D2_ASSERT(pSlot->pData, 0x1139);
            sub_0040B3C0(pSlot->pData, gszMainMenusFile_006D41C0, 0x113A, 0);
            D2_ASSERT(gppSlots_00779988[i]->szName, 0x113B);
            sub_0040B3C0(gppSlots_00779988[i]->szName, gszMainMenusFile_006D41C0, 0x113C, 0);
            sub_0040B3C0(gppSlots_00779988[i], gszMainMenusFile_006D41C0, 0x113E, 0);
        }
    }
    sub_0040B3C0(gppSlots_00779988, gszMainMenusFile_006D41C0, 0x1141, 0);
    gppSlots_00779988 = 0;
    return 1;
}

// 0x00434060
void __cdecl sub_00434060_BuildMenuList()
{
    sub_0042F6E0();
    sub_004FA590_RunLoop(sub_00431D10_ClearLoop);
    if (gpFuncTable_0077ABF0)
        gpMenuList_007795C0 = gpFuncTable_0077ABF0->pfnGetMenuList(0);
    sub_0042F3F0_DestroyControls();
    D2MenuListStrc* pList = gpMenuList_007795C0;
    if (!pList)
    {
        gdwGlobal_0077998C = -1;
        return;
    }
    gdwGlobal_0077998C = pList->nCount;
    D2_ASSERT(gdwGlobal_0077998C < 512, 4481);
    char* pText = (char*)(pList + 1);
    sub_00430A20_FreeSlots();
    int nCount = gdwGlobal_0077998C;
    if (gdwGlobal_0077998C)
    {
        const unsigned int nSize = gdwGlobal_0077998C * sizeof(D2LaunchSlotStrc*);
        gppSlots_00779988 = (D2LaunchSlotStrc**)FOG_Alloc(nSize, gszMainMenusFile_006D41C0, 4492, 0);
        memset(gppSlots_00779988, 0, nSize);
        for (int i = 0; i < nCount; ++i)
        {
            D2LaunchSlotStrc* pSlot = (D2LaunchSlotStrc*)FOG_Alloc(sizeof(D2LaunchSlotStrc), gszMainMenusFile_006D41C0, 4498, 0);
            pText += sizeof(int);
            unsigned int nLength = strlen(pText) + 1;
            pSlot->szName = (char*)FOG_Alloc(nLength, gszMainMenusFile_006D41C0, 4511, 0);
            SStrCopy(pSlot->szName, pText, nLength);
            pText += nLength;
            nLength = strlen(pText) + 1;
            pSlot->pData = FOG_Alloc(nLength, gszMainMenusFile_006D41C0, 4516, 0);
            SStrCopy((char*)pSlot->pData, pText, nLength);
            pText += nLength;
            sub_004309C0_AddToSlots(pSlot);
        }
        qsort(gppSlots_00779988, gdwGlobal_0077998C, sizeof(D2LaunchSlotStrc*), sub_00430B00_CompareNames);
    }
}
