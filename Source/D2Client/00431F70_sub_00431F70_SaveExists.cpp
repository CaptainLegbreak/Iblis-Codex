struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;
struct D2CellFileStrc;

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x80];
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

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" int __cdecl sscanf(const char* szSource, const char* szFormat, ...);                             // 0x00684BD5
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);         // 0x00413A40

extern "C" __declspec(dllimport) int __stdcall FindClose(void* hFindFile);                                  // 0x006CC1C4
extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* szFileName, D2FindDataStrc* pFindData); // 0x006CC1CC
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall GetDiskFreeSpaceA(const char* szRootPathName, unsigned long* pnSectorsPerCluster, unsigned long* pnBytesPerSector, unsigned long* pnFreeClusters, unsigned long* pnTotalClusters); // 0x006CC270
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

typedef int (__stdcall* D2LaunchCallback)(int nArg);

int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned int nBufferSize); // 0x00414E50
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, int nSearchScope, void** phFile);         // 0x004192F0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                              // 0x0041D2A0
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300
int __stdcall sub_004198D0(void* pArg);                                                                     // 0x004198D0
void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069A0_CloseFile(void* hFile);                                                         // 0x004069A0
void __fastcall sub_00407050_GetSavePath(char* szPath, int nSize);                                          // 0x00407050
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
int __cdecl sub_0040EB10();                                                                                 // 0x0040EB10
const char* __fastcall FOG_ResolveHostIPAddress(const char* szHostName);                                    // 0x0040E0D0
void __cdecl sub_0042FDD0();                                                                                // 0x0042FDD0
int __stdcall sub_0042FFE0(int nArg);                                                                       // 0x0042FFE0
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
void __cdecl sub_0042F6E0();                                                                                // 0x0042F6E0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430
void __cdecl sub_004317D0_FlushInput();                                                                     // 0x004317D0
void __cdecl sub_00430520();                                                                                // 0x00430520
void __stdcall sub_004313D0(int nLevel);                                                                    // 0x004313D0
int __stdcall sub_00431C90(int nArg);                                                                       // 0x00431C90
int __stdcall sub_00431D10(int nArg);                                                                       // 0x00431D10
int __stdcall sub_00431E30(int nArg);                                                                       // 0x00431E30
void __cdecl sub_00431AF0();                                                                                // 0x00431AF0
void __fastcall sub_00433380_ShowMessage(const Unicode* pText, D2LaunchCallback pfnDone, int nArg);         // 0x00433380
void __fastcall sub_00433460_ShowMessage(const Unicode* pText, void (__cdecl* pfnDone)());                  // 0x00433460
void __cdecl sub_004365B0_CreateCharacter();                                                                                // 0x004365B0
void __cdecl sub_00435E10();                                                                                // 0x00435E10
void __cdecl sub_0043B080();                                                                                // 0x0043B080
void __cdecl sub_0043B9A0();                                                                                // 0x0043B9A0
void __fastcall sub_0043C540(char* szName, char nClass, char* pData, int nFlags);                           // 0x0043C540
void __fastcall sub_0043C6A0(int bSet);                                                                     // 0x0043C6A0
void __fastcall sub_0043C6B0(char* szName);                                                                 // 0x0043C6B0
void __cdecl sub_0043C4F0();                                                                                // 0x0043C4F0
void __cdecl D2MCPClientCloseMCP();                                                                         // 0x00449AD0
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590
void __stdcall sub_004F5D90_PlayVideo(const char* szFile, int nMode, int nArg);                             // 0x004F5D90
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
int __fastcall sub_004F9710_TestFlags(D2WinControlStrc* pControl);                                          // 0x004F9710
int __fastcall sub_004F9190();                                                            // 0x004F9190
int __cdecl sub_004FAC90();                                                                                 // 0x004FAC90
int __stdcall sub_004FB500(const char* szPath1, const char* szPath2);                           // 0x004FB500
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
void __fastcall sub_004FCF80_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FCF80
void __fastcall sub_004FCFF0_SetTextA(D2WinControlStrc* pControl, const char* szText, int nArg);            // 0x004FCFF0
D2CellFileStrc* __fastcall sub_004FA9B0_LoadCellFile(const char* szFile, int nType);                        // 0x004FA9B0
void __fastcall sub_004FFE10_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FFE10
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl);                             // 0x004FDD90
void __cdecl sub_00515020();                                                                                // 0x00515020
void __cdecl sub_00514930();                                                                                // 0x00514930
void __fastcall sub_00515CE0_SetMasterVolume(int nVolume);                                                  // 0x00515CE0
void __fastcall sub_00515F50(int nArg);                                                                     // 0x00515F50
int __cdecl sub_00514D80();                                                                                 // 0x00514D80
void __fastcall D2SOUND_10034(int nArg);                                                                    // 0x005148F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(short nIndex);                                       // 0x00524A30
void __stdcall sub_00525260(void* pOut, int nField);                                                 // 0x00525260
void __stdcall sub_0052A750(int nArg, const char* szAddress);                                               // 0x0052A750
void __cdecl sub_0052A7E0();                                                                                // 0x0052A7E0
void __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength);                // 0x005263E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern "C" const char gszDiablo2_006CC8B8[];                                                                // 0x006CC8B8
extern "C" const char gszDottedQuadFormat_006CDEA4[];                                                       // 0x006CDEA4
extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118
extern "C" const char gszPathFormat_006D4124[];                                                             // 0x006D4124
extern "C" const char gszAuxBattleNet_006D4164[];                                                           // 0x006D4164
extern "C" const char gszLastTcpIp_006D4224[];                                                              // 0x006D4224
extern "C" const char gszDottedQuadLongFormat_006D4174[];                                                   // 0x006D4174
extern "C" const char gszEng_006D41A4[];                                                                    // 0x006D41A4
extern "C" const char gszDataLocal_006D41A8[];                                                              // 0x006D41A8
extern "C" const char gszSaveMask_006D41D4[];                                                               // 0x006D41D4
extern "C" const char gszSavePathFormat_006D4230[];                                                         // 0x006D4230
extern "C" const char gszAuxAddressFormat_006D4868[];                                                       // 0x006D4868
extern "C" const char gszIntroFormatEng_006D4878[];                                                         // 0x006D4878
extern "C" const char gszIntroFormat_006D4894[];                                                            // 0x006D4894
extern "C" const char gszVersionSuffix_006D48D0[];                                                          // 0x006D48D0
extern "C" const char gszVersionFormat_006D48D4[];                                                          // 0x006D48D4
extern "C" const char gszDotsFormat_006D4D9C[];                                                             // 0x006D4D9C
extern "C" const char gszDots_006D4DA4[];                                                                   // 0x006D4DA4
extern "C" const unsigned char gabDefault_006D4D88[];                                                       // 0x006D4D88
extern "C" const char gszStringFormat_006FFC58[];                                                           // 0x006FFC58
extern D2WinControlStrc* gpOkButton_00779330;                                                               // 0x00779330
extern D2WinControlStrc* gpNameEdit_0077934C;                                                               // 0x0077934C
extern D2WinControlStrc* gpControl_007795AC;                                                                // 0x007795AC
extern int gbConnected_0077959C;                                                                            // 0x0077959C
extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                         // 0x007795D4
extern int gnLaunchMode_007795EC;                                                                           // 0x007795EC
extern int gnLaunchState_007795E8;                                                                          // 0x007795E8
extern int gbFeCharPalette_007795F0;                                                                        // 0x007795F0
extern char gszAddress_007795F8[];                                                                          // 0x007795F8
extern D2WinControlStrc* gpAddressEdit_00779958;                                                            // 0x00779958
extern int gbPaletteBusy_00779970;                                                                          // 0x00779970
extern int gbFlag_00779984;                                                                                 // 0x00779984
extern int gdwGlobal_00779974;                                                                              // 0x00779974
extern D2WinControlStrc* gpStatusText_007799A8;                                                             // 0x007799A8
extern D2WinControlStrc* gpCounterText_007799AC;                                                            // 0x007799AC
extern int gnStatusStringId_007799B0;                                                                       // 0x007799B0
extern unsigned long gdwStatusStart_007799B8;                                                               // 0x007799B8
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0
extern "C" const char gszCellPath_006D4100[];                                                               // 0x006D4100
extern "C" const char gszCellPath_006D40DC[];                                                               // 0x006D40DC
extern "C" const char gszCellPath_006D40C0[];                                                               // 0x006D40C0
extern "C" const char gszCellPath_006D40AC[];                                                               // 0x006D40AC
extern "C" const char gszCellPath_006D4094[];                                                               // 0x006D4094
extern "C" const char gszCellPath_006D4074[];                                                               // 0x006D4074
extern "C" const char gszCellPath_006D4054[];                                                               // 0x006D4054
extern "C" const char gszCellPath_006D4034[];                                                               // 0x006D4034
extern "C" const char gszCellPath_006D4014[];                                                               // 0x006D4014
extern "C" const char gszCellPath_006D3FF0[];                                                               // 0x006D3FF0
extern "C" const char gszCellPath_006D3FD4[];                                                               // 0x006D3FD4
extern "C" const char gszCellPath_006D3FB0[];                                                               // 0x006D3FB0
extern "C" const char gszCellPath_006D3F90[];                                                               // 0x006D3F90
extern "C" const char gszCellPath_006D3F70[];                                                               // 0x006D3F70
extern "C" const char gszCellPath_006D3F4C[];                                                               // 0x006D3F4C
extern "C" const char gszCellPath_006D3F28[];                                                               // 0x006D3F28
extern "C" const char gszCellPath_006D3F0C[];                                                               // 0x006D3F0C
extern "C" const char gszCellPath_006D3EE8[];                                                               // 0x006D3EE8
extern "C" const char gszCellPath_006D3EC4[];                                                               // 0x006D3EC4
extern "C" const char gszCellPath_006D3E98[];                                                               // 0x006D3E98
extern "C" const char gszCellPath_006D3E70[];                                                               // 0x006D3E70
extern "C" const char gszCellPath_006D3E4C[];                                                               // 0x006D3E4C
extern "C" const char gszCellPath_006D3E28[];                                                               // 0x006D3E28
extern "C" const char gszCellPath_006D3E10[];                                                               // 0x006D3E10
extern "C" const char gszCellPath_006D3DF0[];                                                               // 0x006D3DF0
extern "C" const char gszCellPath_006D3DD0[];                                                               // 0x006D3DD0
extern "C" const char gszCellPath_006D3DB0[];                                                               // 0x006D3DB0
extern "C" const char gszCellPath_006D3D8C[];                                                               // 0x006D3D8C
extern "C" const char gszCellPath_006D3D68[];                                                               // 0x006D3D68
extern "C" const char gszCellPath_006D3D48[];                                                               // 0x006D3D48
extern "C" const char gszCellPath_006D3D24[];                                                               // 0x006D3D24
extern "C" const char gszCellPath_006D3D00[];                                                               // 0x006D3D00
extern "C" const char gszCellPath_006D3CE8[];                                                               // 0x006D3CE8
extern "C" const char gszCellPath_006D3CC8[];                                                               // 0x006D3CC8
extern "C" const char gszCellPath_006D3CAC[];                                                               // 0x006D3CAC
extern "C" const char gszCellPath_006D3C90[];                                                               // 0x006D3C90
extern "C" const char gszCellPath_006D3C70[];                                                               // 0x006D3C70
extern "C" const char gszCellPath_006D3C58[];                                                               // 0x006D3C58
extern "C" const char gszCellPath_006D3C38[];                                                               // 0x006D3C38
extern "C" const char gszCellPath_006D3C18[];                                                               // 0x006D3C18
extern "C" const char gszCellPath_006D3BF4[];                                                               // 0x006D3BF4
extern "C" const char gszCellPath_006D3BD0[];                                                               // 0x006D3BD0
extern "C" const char gszCellPath_006D3BAC[];                                                               // 0x006D3BAC
extern "C" const char gszCellPath_006D3B8C[];                                                               // 0x006D3B8C
extern "C" const char gszCellPath_006D3B74[];                                                               // 0x006D3B74
extern "C" const char gszCellPath_006D3B4C[];                                                               // 0x006D3B4C
extern "C" const char gszCellPath_006D3B28[];                                                               // 0x006D3B28
extern "C" const char gszCellPath_006D3B0C[];                                                               // 0x006D3B0C
extern "C" const char gszCellPath_006D3AF0[];                                                               // 0x006D3AF0
extern "C" const char gszCellPath_006D3ACC[];                                                               // 0x006D3ACC
extern "C" const char gszCellPath_006D3AB0[];                                                               // 0x006D3AB0
extern "C" const char gszCellPath_006D3A94[];                                                               // 0x006D3A94
extern "C" const char gszCellPath_006D3A78[];                                                               // 0x006D3A78
extern "C" const char gszCellPath_006D3A54[];                                                               // 0x006D3A54
extern "C" const char gszCellPath_006D3A30[];                                                               // 0x006D3A30
extern "C" const char gszCellPath_006D3A10[];                                                               // 0x006D3A10
extern D2CellFileStrc* gpCellFile_007796F8;                                                                 // 0x007796F8
extern D2CellFileStrc* gpCellFile_007796FC;                                                                 // 0x007796FC
extern D2CellFileStrc* gpCellFile_00779704;                                                                 // 0x00779704
extern D2CellFileStrc* gpCellFile_00779708;                                                                 // 0x00779708
extern D2CellFileStrc* gpCellFile_0077970C;                                                                 // 0x0077970C
extern D2CellFileStrc* gpCellFile_00779710;                                                                 // 0x00779710
extern D2CellFileStrc* gpCellFile_00779714;                                                                 // 0x00779714
extern D2CellFileStrc* gpCellFile_00779718;                                                                 // 0x00779718
extern D2CellFileStrc* gpCellFile_0077971C;                                                                 // 0x0077971C
extern D2CellFileStrc* gpCellFile_00779720;                                                                 // 0x00779720
extern D2CellFileStrc* gpCellFile_0077972C;                                                                 // 0x0077972C
extern D2CellFileStrc* gpCellFile_00779730;                                                                 // 0x00779730
extern D2CellFileStrc* gpCellFile_00779734;                                                                 // 0x00779734
extern D2CellFileStrc* gpCellFile_00779738;                                                                 // 0x00779738
extern D2CellFileStrc* gpCellFile_0077973C;                                                                 // 0x0077973C
extern D2CellFileStrc* gpCellFile_00779740;                                                                 // 0x00779740
extern D2CellFileStrc* gpCellFile_00779748;                                                                 // 0x00779748
extern D2CellFileStrc* gpCellFile_0077974C;                                                                 // 0x0077974C
extern D2CellFileStrc* gpCellFile_00779750;                                                                 // 0x00779750
extern D2CellFileStrc* gpCellFile_00779754;                                                                 // 0x00779754
extern D2CellFileStrc* gpCellFile_00779758;                                                                 // 0x00779758
extern D2CellFileStrc* gpCellFile_0077975C;                                                                 // 0x0077975C
extern D2CellFileStrc* gpCellFile_00779764;                                                                 // 0x00779764
extern D2CellFileStrc* gpCellFile_00779768;                                                                 // 0x00779768
extern D2CellFileStrc* gpCellFile_0077976C;                                                                 // 0x0077976C
extern D2CellFileStrc* gpCellFile_00779770;                                                                 // 0x00779770
extern D2CellFileStrc* gpCellFile_00779774;                                                                 // 0x00779774
extern D2CellFileStrc* gpCellFile_00779778;                                                                 // 0x00779778
extern D2CellFileStrc* gpCellFile_0077977C;                                                                 // 0x0077977C
extern D2CellFileStrc* gpCellFile_00779780;                                                                 // 0x00779780
extern D2CellFileStrc* gpCellFile_00779784;                                                                 // 0x00779784
extern D2CellFileStrc* gpCellFile_00779788;                                                                 // 0x00779788
extern D2CellFileStrc* gpCellFile_0077978C;                                                                 // 0x0077978C
extern D2CellFileStrc* gpCellFile_00779790;                                                                 // 0x00779790
extern D2CellFileStrc* gpCellFile_00779794;                                                                 // 0x00779794
extern D2CellFileStrc* gpCellFile_00779798;                                                                 // 0x00779798
extern D2CellFileStrc* gpCellFile_0077979C;                                                                 // 0x0077979C
extern D2CellFileStrc* gpCellFile_007797A0;                                                                 // 0x007797A0
extern D2CellFileStrc* gpCellFile_007797A4;                                                                 // 0x007797A4
extern D2CellFileStrc* gpCellFile_007797A8;                                                                 // 0x007797A8
extern D2CellFileStrc* gpCellFile_007797AC;                                                                 // 0x007797AC
extern D2CellFileStrc* gpCellFile_007797B0;                                                                 // 0x007797B0
extern D2CellFileStrc* gpCellFile_007797B4;                                                                 // 0x007797B4
extern D2CellFileStrc* gpCellFile_007797B8;                                                                 // 0x007797B8
extern D2CellFileStrc* gpCellFile_007797C8;                                                                 // 0x007797C8
extern D2CellFileStrc* gpCellFile_007797CC;                                                                 // 0x007797CC
extern D2CellFileStrc* gpCellFile_007797D0;                                                                 // 0x007797D0
extern D2CellFileStrc* gpCellFile_007797D4;                                                                 // 0x007797D4
extern D2CellFileStrc* gpCellFile_007797D8;                                                                 // 0x007797D8
extern D2CellFileStrc* gpCellFile_007797DC;                                                                 // 0x007797DC

extern "C" const char gszCellPath_006D4844[];                                                               // 0x006D4844
extern "C" const char gszCellPath_006D4818[];                                                               // 0x006D4818
extern "C" const char gszCellPath_006D47F8[];                                                               // 0x006D47F8
extern "C" const char gszCellPath_006D47E4[];                                                               // 0x006D47E4
extern "C" const char gszCellPath_006D47CC[];                                                               // 0x006D47CC
extern "C" const char gszCellPath_006D47B4[];                                                               // 0x006D47B4
extern "C" const char gszCellPath_006D4790[];                                                               // 0x006D4790
extern "C" const char gszCellPath_006D4770[];                                                               // 0x006D4770
extern "C" const char gszCellPath_006D4750[];                                                               // 0x006D4750
extern "C" const char gszCellPath_006D4730[];                                                               // 0x006D4730
extern "C" const char gszCellPath_006D4710[];                                                               // 0x006D4710
extern "C" const char gszCellPath_006D46F0[];                                                               // 0x006D46F0
extern "C" const char gszCellPath_006D46D4[];                                                               // 0x006D46D4
extern "C" const char gszCellPath_006D46B8[];                                                               // 0x006D46B8
extern "C" const char gszCellPath_006D469C[];                                                               // 0x006D469C
extern "C" const char gszCellPath_006D4680[];                                                               // 0x006D4680
extern "C" const char gszCellPath_006D4664[];                                                               // 0x006D4664
extern "C" const char gszCellPath_006D4648[];                                                               // 0x006D4648
extern "C" const char gszCellPath_006D462C[];                                                               // 0x006D462C
extern "C" const char gszCellPath_006D4610[];                                                               // 0x006D4610
extern "C" const char gszCellPath_006D45F4[];                                                               // 0x006D45F4
extern "C" const char gszCellPath_006D45D8[];                                                               // 0x006D45D8
extern "C" const char gszCellPath_006D45B4[];                                                               // 0x006D45B4
extern "C" const char gszCellPath_006D4590[];                                                               // 0x006D4590
extern "C" const char gszCellPath_006D4570[];                                                               // 0x006D4570
extern "C" const char gszCellPath_006D454C[];                                                               // 0x006D454C
extern "C" const char gszCellPath_006D452C[];                                                               // 0x006D452C
extern "C" const char gszCellPath_006D450C[];                                                               // 0x006D450C
extern "C" const char gszCellPath_006D44EC[];                                                               // 0x006D44EC
extern "C" const char gszCellPath_006D44CC[];                                                               // 0x006D44CC
extern "C" const char gszCellPath_006D44AC[];                                                               // 0x006D44AC
extern "C" const char gszCellPath_006D448C[];                                                               // 0x006D448C
extern "C" const char gszCellPath_006D446C[];                                                               // 0x006D446C
extern "C" const char gszCellPath_006D444C[];                                                               // 0x006D444C
extern "C" const char gszCellPath_006D442C[];                                                               // 0x006D442C
extern "C" const char gszCellPath_006D440C[];                                                               // 0x006D440C
extern "C" const char gszCellPath_006D43EC[];                                                               // 0x006D43EC
extern "C" const char gszCellPath_006D43CC[];                                                               // 0x006D43CC
extern "C" const char gszCellPath_006D43AC[];                                                               // 0x006D43AC
extern "C" const char gszCellPath_006D4390[];                                                               // 0x006D4390
extern "C" const char gszCellPath_006D4370[];                                                               // 0x006D4370
extern "C" const char gszCellPath_006D4354[];                                                               // 0x006D4354
extern "C" const char gszCellPath_006D4334[];                                                               // 0x006D4334
extern "C" const char gszCellPath_006D4314[];                                                               // 0x006D4314
extern "C" const char gszCellPath_006D42F4[];                                                               // 0x006D42F4
extern "C" const char gszCellPath_006D42D0[];                                                               // 0x006D42D0
extern "C" const char gszCellPath_006D42AC[];                                                               // 0x006D42AC
extern "C" const char gszCellPath_006D4288[];                                                               // 0x006D4288
extern "C" const char gszCellPath_006D4268[];                                                               // 0x006D4268
extern "C" const char gszCellPath_006D4248[];                                                               // 0x006D4248
extern D2CellFileStrc* gpCellFile_00779724;                                                                 // 0x00779724
extern D2CellFileStrc* gpCellFile_00779728;                                                                 // 0x00779728
extern D2CellFileStrc* gpCellFile_00779744;                                                                 // 0x00779744
extern D2CellFileStrc* gpCellFile_007797BC;                                                                 // 0x007797BC
extern D2CellFileStrc* gpCellFile_007797C0;                                                                 // 0x007797C0
extern D2CellFileStrc* gpCellFile_007797C4;                                                                 // 0x007797C4
extern D2CellFileStrc* gpCellFile_007797E0;                                                                 // 0x007797E0
extern D2CellFileStrc* gpCellFile_007797E4;                                                                 // 0x007797E4
extern D2CellFileStrc* gpCellFile_007797E8;                                                                 // 0x007797E8
extern D2CellFileStrc* gpCellFile_007797EC;                                                                 // 0x007797EC
extern D2CellFileStrc* gpCellFile_007797F0;                                                                 // 0x007797F0
extern D2CellFileStrc* gpCellFile_007797F4;                                                                 // 0x007797F4
extern D2CellFileStrc* gpCellFile_007797F8;                                                                 // 0x007797F8
extern D2CellFileStrc* gpCellFile_007797FC;                                                                 // 0x007797FC
extern D2CellFileStrc* gpCellFile_00779800;                                                                 // 0x00779800
extern D2CellFileStrc* gpCellFile_00779804;                                                                 // 0x00779804
extern D2CellFileStrc* gpCellFile_00779808;                                                                 // 0x00779808
extern D2CellFileStrc* gpCellFile_0077980C;                                                                 // 0x0077980C
extern D2CellFileStrc* gpCellFile_00779810;                                                                 // 0x00779810
extern D2CellFileStrc* gpCellFile_00779814;                                                                 // 0x00779814
extern D2CellFileStrc* gpCellFile_00779818;                                                                 // 0x00779818
extern D2CellFileStrc* gpCellFile_0077981C;                                                                 // 0x0077981C
extern D2CellFileStrc* gpCellFile_00779820;                                                                 // 0x00779820
extern D2CellFileStrc* gpCellFile_00779824;                                                                 // 0x00779824
extern D2CellFileStrc* gpCellFile_00779828;                                                                 // 0x00779828
extern D2CellFileStrc* gpCellFile_0077982C;                                                                 // 0x0077982C
extern D2CellFileStrc* gpCellFile_00779830;                                                                 // 0x00779830
extern D2CellFileStrc* gpCellFile_00779834;                                                                 // 0x00779834
extern D2CellFileStrc* gpCellFile_00779838;                                                                 // 0x00779838
extern D2CellFileStrc* gpCellFile_0077983C;                                                                 // 0x0077983C
extern D2CellFileStrc* gpCellFile_00779840;                                                                 // 0x00779840
extern D2CellFileStrc* gpCellFile_00779844;                                                                 // 0x00779844
extern D2CellFileStrc* gpCellFile_00779848;                                                                 // 0x00779848
extern D2CellFileStrc* gpCellFile_0077984C;                                                                 // 0x0077984C
extern D2CellFileStrc* gpCellFile_00779850;                                                                 // 0x00779850
extern D2CellFileStrc* gpCellFile_00779854;                                                                 // 0x00779854
extern D2CellFileStrc* gpCellFile_00779858;                                                                 // 0x00779858
extern D2CellFileStrc* gpCellFile_0077985C;                                                                 // 0x0077985C
extern D2CellFileStrc* gpCellFile_00779860;                                                                 // 0x00779860
extern D2CellFileStrc* gpCellFile_00779864;                                                                 // 0x00779864
extern D2CellFileStrc* gpCellFile_00779868;                                                                 // 0x00779868
extern D2CellFileStrc* gpCellFile_00779888;                                                                 // 0x00779888
extern D2CellFileStrc* gpCellFile_0077988C;                                                                 // 0x0077988C
extern D2CellFileStrc* gpCellFile_00779890;                                                                 // 0x00779890
extern D2CellFileStrc* gpCellFile_0077989C;                                                                 // 0x0077989C
extern D2CellFileStrc* gpCellFile_007798A0;                                                                 // 0x007798A0
extern D2CellFileStrc* gpCellFile_007798A4;                                                                 // 0x007798A4
extern D2CellFileStrc* gpCellFile_007798B0;                                                                 // 0x007798B0
extern D2CellFileStrc* gpCellFile_007798C4;                                                                 // 0x007798C4
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
