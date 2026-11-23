#include "D2Launch.h"
#include "D2MultiTypes.h"
#include "D2Unicode.h"

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300

void* __fastcall FOG_CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960

int __fastcall FOG_CloseFile(void* hFile);                                                         // 0x004069A0

void __cdecl MAINMENUS_ReturnToCharSelect();                                                                                // 0x0042FDD0

void __cdecl MAINMENUS_DestroyControls();                                                                // 0x0042F3F0

void __cdecl MAINMENUS_Reset();                                                                          // 0x0042F480

void __cdecl MAINMENUS_ShowConnectingPopup();                                                                                // 0x0042F6E0

D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId);                                           // 0x0042F430

void __cdecl MAINMENUS_FlushInput();                                                                     // 0x004317D0

void __cdecl sub_00430520();                                                                                // 0x00430520

void __stdcall MAINMENUS_CreateLevelScreen(int nLevel);                                                                    // 0x004313D0

void __cdecl MAINMENUS_ShowCurrentGateway();                                                                                // 0x00431AF0


void __cdecl MAINMENUS_CreateCharacter();                                                                                // 0x004365B0

void __cdecl CHARSEL_InitCharSelectScreen();                                                                                // 0x0043B080

void __cdecl CHARSEL_DisconnectBattleNet();                                                                                // 0x0043B9A0

void __fastcall sub_0043C6A0(int bSet);                                                                     // 0x0043C6A0

void __cdecl CHARSEL_CreateBaseScreen();                                                                                // 0x0043C4F0

void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590

int __fastcall D2Win_StopMessageLoop();                                                            // 0x004F9190

void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText);                      // 0x004FCF80

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __stdcall STRTABLE_GetLanguageInfoField(void* pOut, int nField);                                                 // 0x00525260

int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

D2WinControlStrc* gpOkButton_00779330; // 0x00779330

D2WinControlStrc* gpControl_007795AC; // 0x007795AC

extern int gbConnected_0077959C;                                                                            // 0x0077959C

D2LaunchRecordStrc* gpLaunchRecord_007795D4; // 0x007795D4

int gbFeCharPalette_007795F0; // 0x007795F0

extern char gszAddress_007795F8[];                                                                          // 0x007795F8

extern D2WinControlStrc* gpAddressEdit_00779958;                                                            // 0x00779958

extern int gbPaletteBusy_00779970;                                                                          // 0x00779970

int gbFlag_00779984; // 0x00779984

extern int gdwGlobal_00779974;                                                                              // 0x00779974

D2WinControlStrc* gpStatusText_007799A8; // 0x007799A8

D2WinControlStrc* gpCounterText_007799AC; // 0x007799AC

int gnStatusStringId_007799B0; // 0x007799B0

unsigned long gdwStatusStart_007799B8; // 0x007799B8

D2CelFileStrc* gpCellFile_007796F8;                                                                        // 0x007796F8

D2CelFileStrc* gpCellFile_007796FC;                                                                        // 0x007796FC

D2CelFileStrc* gpCellFile_00779704;                                                                        // 0x00779704

D2CelFileStrc* gpCellFile_00779708;                                                                        // 0x00779708

D2CelFileStrc* gpCellFile_0077970C;                                                                        // 0x0077970C

D2CelFileStrc* gpCellFile_00779710;                                                                        // 0x00779710

D2CelFileStrc* gpCellFile_00779714;                                                                        // 0x00779714

D2CelFileStrc* gpCellFile_00779718;                                                                        // 0x00779718

D2CelFileStrc* gpCellFile_0077971C;                                                                        // 0x0077971C

D2CelFileStrc* gpCellFile_00779720;                                                                        // 0x00779720

D2CelFileStrc* gpCellFile_0077972C;                                                                        // 0x0077972C

D2CelFileStrc* gpCellFile_00779730;                                                                        // 0x00779730

D2CelFileStrc* gpCellFile_00779734;                                                                        // 0x00779734

D2CelFileStrc* gpCellFile_00779738;                                                                        // 0x00779738

D2CelFileStrc* gpCellFile_0077973C;                                                                        // 0x0077973C

D2CelFileStrc* gpCellFile_00779740;                                                                        // 0x00779740

D2CelFileStrc* gpCellFile_00779748;                                                                        // 0x00779748

D2CelFileStrc* gpCellFile_0077974C;                                                                        // 0x0077974C

D2CelFileStrc* gpCellFile_00779750;                                                                        // 0x00779750

D2CelFileStrc* gpCellFile_00779754;                                                                        // 0x00779754

D2CelFileStrc* gpCellFile_00779758;                                                                        // 0x00779758

D2CelFileStrc* gpCellFile_0077975C;                                                                        // 0x0077975C

D2CelFileStrc* gpCellFile_00779764;                                                                        // 0x00779764

D2CelFileStrc* gpCellFile_00779768;                                                                        // 0x00779768

D2CelFileStrc* gpCellFile_0077976C;                                                                        // 0x0077976C

D2CelFileStrc* gpCellFile_00779770;                                                                        // 0x00779770

D2CelFileStrc* gpCellFile_00779774;                                                                        // 0x00779774

D2CelFileStrc* gpCellFile_00779778;                                                                        // 0x00779778

D2CelFileStrc* gpCellFile_0077977C;                                                                        // 0x0077977C

D2CelFileStrc* gpCellFile_00779780;                                                                        // 0x00779780

D2CelFileStrc* gpCellFile_00779784;                                                                        // 0x00779784

D2CelFileStrc* gpCellFile_00779788;                                                                        // 0x00779788

D2CelFileStrc* gpCellFile_0077978C;                                                                        // 0x0077978C

D2CelFileStrc* gpCellFile_00779790;                                                                        // 0x00779790

D2CelFileStrc* gpCellFile_00779794;                                                                        // 0x00779794

D2CelFileStrc* gpCellFile_00779798;                                                                        // 0x00779798

D2CelFileStrc* gpCellFile_0077979C;                                                                        // 0x0077979C

D2CelFileStrc* gpCellFile_007797A0;                                                                        // 0x007797A0

D2CelFileStrc* gpCellFile_007797A4;                                                                        // 0x007797A4

D2CelFileStrc* gpCellFile_007797A8;                                                                        // 0x007797A8

D2CelFileStrc* gpCellFile_007797AC;                                                                        // 0x007797AC

D2CelFileStrc* gpCellFile_007797B0;                                                                        // 0x007797B0

D2CelFileStrc* gpCellFile_007797B4;                                                                        // 0x007797B4

D2CelFileStrc* gpCellFile_007797B8;                                                                        // 0x007797B8

D2CelFileStrc* gpCellFile_007797C8;                                                                        // 0x007797C8

D2CelFileStrc* gpCellFile_007797CC;                                                                        // 0x007797CC

D2CelFileStrc* gpCellFile_007797D0;                                                                        // 0x007797D0

D2CelFileStrc* gpCellFile_007797D4;                                                                        // 0x007797D4

D2CelFileStrc* gpCellFile_007797D8;                                                                        // 0x007797D8

D2CelFileStrc* gpCellFile_007797DC;                                                                        // 0x007797DC

extern D2CelFileStrc* gpCellFile_00779724;                                                                 // 0x00779724

extern D2CelFileStrc* gpCellFile_00779728;                                                                 // 0x00779728

extern D2CelFileStrc* gpCellFile_00779744;                                                                 // 0x00779744

extern D2CelFileStrc* gpCellFile_007797BC;                                                                 // 0x007797BC

extern D2CelFileStrc* gpCellFile_007797C0;                                                                 // 0x007797C0

extern D2CelFileStrc* gpCellFile_007797C4;                                                                 // 0x007797C4

D2CelFileStrc* gpCellFile_007797E0;                                                                        // 0x007797E0

D2CelFileStrc* gpCellFile_007797E4; // 0x007797E4

D2CelFileStrc* gpCellFile_007797E8; // 0x007797E8

D2CelFileStrc* gpCellFile_007797EC; // 0x007797EC

D2CelFileStrc* gpCellFile_007797F0; // 0x007797F0

D2CelFileStrc* gpCellFile_007797F4;                                                                        // 0x007797F4

D2CelFileStrc* gpCellFile_007797F8; // 0x007797F8

D2CelFileStrc* gpCellFile_007797FC; // 0x007797FC

D2CelFileStrc* gpCellFile_00779800; // 0x00779800

D2CelFileStrc* gpCellFile_00779804; // 0x00779804

D2CelFileStrc* gpCellFile_00779808;                                                                        // 0x00779808

D2CelFileStrc* gpCellFile_0077980C; // 0x0077980C

D2CelFileStrc* gpCellFile_00779810; // 0x00779810

D2CelFileStrc* gpCellFile_00779814; // 0x00779814

D2CelFileStrc* gpCellFile_00779818; // 0x00779818

D2CelFileStrc* gpCellFile_0077981C;                                                                        // 0x0077981C

D2CelFileStrc* gpCellFile_00779820; // 0x00779820

D2CelFileStrc* gpCellFile_00779824; // 0x00779824

D2CelFileStrc* gpCellFile_00779828; // 0x00779828

D2CelFileStrc* gpCellFile_0077982C; // 0x0077982C

D2CelFileStrc* gpCellFile_00779830;                                                                        // 0x00779830

D2CelFileStrc* gpCellFile_00779834; // 0x00779834

D2CelFileStrc* gpCellFile_00779838; // 0x00779838

D2CelFileStrc* gpCellFile_0077983C; // 0x0077983C

D2CelFileStrc* gpCellFile_00779840; // 0x00779840

D2CelFileStrc* gpCellFile_00779844;                                                                        // 0x00779844

D2CelFileStrc* gpCellFile_00779848; // 0x00779848

D2CelFileStrc* gpCellFile_0077984C; // 0x0077984C

D2CelFileStrc* gpCellFile_00779850; // 0x00779850

D2CelFileStrc* gpCellFile_00779854; // 0x00779854

D2CelFileStrc* gpCellFile_00779858;                                                                        // 0x00779858

D2CelFileStrc* gpCellFile_0077985C; // 0x0077985C

D2CelFileStrc* gpCellFile_00779860; // 0x00779860

D2CelFileStrc* gpCellFile_00779864; // 0x00779864

D2CelFileStrc* gpCellFile_00779868; // 0x00779868

D2CelFileStrc* gpCellFile_00779888;                                                                        // 0x00779888

D2CelFileStrc* gpCellFile_0077988C; // 0x0077988C

D2CelFileStrc* gpCellFile_00779890; // 0x00779890

D2CelFileStrc* gpCellFile_0077989C;                                                                        // 0x0077989C

D2CelFileStrc* gpCellFile_007798A0; // 0x007798A0

D2CelFileStrc* gpCellFile_007798A4; // 0x007798A4

extern D2CelFileStrc* gpCellFile_007798B0;                                                                 // 0x007798B0

extern D2CelFileStrc* gpCellFile_007798C4;                                                                 // 0x007798C4

struct D2ConfigStrc;

struct D2FileTimeStrc;

struct D2LaunchRecordStrc;

struct D2LaunchSlotStrc;

struct D2MenuListStrc;

void __fastcall MAINMENUS_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg); // 0x00433380


int __cdecl STRTABLE_GetLanguage(); // 0x00525150

int __cdecl D2Win_10003(); // 0x004F9050

void __stdcall D2Win_10004(int nResolution); // 0x004F9060

int __stdcall MAINMENUS_ShowLevelScreen(int nUnused); // 0x00431600

void __cdecl sub_0042FB20(); // 0x0042FB20

void __cdecl ARCHIVE_UnloadExpansionArchives(); // 0x004FAD70

int __fastcall ARCHIVE_LoadExpansionArchives(int (__cdecl* pfnPlayDisc)(), int (__cdecl* pfnExpansionDisc)(), int nUnused, D2ConfigStrc* pCfg); // 0x004FAEC0

int __cdecl MAINMENUS_ShowArchiveMessage(); // 0x00431A00

int __cdecl MAINMENUS_PromptPlayDisc(); // 0x00434220

int __cdecl MAINMENUS_PromptExpansionDisc(); // 0x004342E0

extern D2ConfigStrc* gpConfig_007795D4; // 0x007795D4

extern "C" const char gszMainMenusFile_006D41C0[]; // 0x006D41C0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __fastcall FOG_FOpenFile(const char* szFileName, void** phFile); // 0x004068E0

int __fastcall FOG_FCloseFile(void* pArg); // 0x004068F0

int __fastcall FOG_FReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900

int __fastcall FOG_FGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00406930

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __fastcall sub_0042E5D0_SwapUnicodeBytes(Unicode* pText, int nLength); // 0x0042E5D0

Unicode* __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

extern D2WinControlStrc* gpList_0077995C; // 0x0077995C

extern D2WinControlStrc* gpList_00779960; // 0x00779960

extern D2WinControlStrc* gpList_00779964; // 0x00779964

extern "C" int __cdecl isalpha(int c); // 0x00686DA5

Unicode* __stdcall MAINMENUS_LoadCreditsText(int* pnLength); // 0x00430CD0

void __cdecl CHARSEL_FillCreditsList(); // 0x00430C80

void __cdecl CHARSEL_SyncCreditsLists(); // 0x00430EF0

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

struct D2MenuListStrc
{
    int unk_00;
    int nCount;
};

extern "C" unsigned int __cdecl strlen(const char* szText);

extern "C" void __cdecl qsort(void* pBase, unsigned int nCount, unsigned int nSize, int (__cdecl* pfnCompare)(const void*, const void*)); // 0x00685B50

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

int __stdcall MAINMENUS_StopLoop(int nArg); // 0x00431D10

int __cdecl CHARSEL_CompareNames(const void* pEntry1, const void* pEntry2); // 0x00430B00

extern D2MenuListStrc* gpMenuList_007795C0; // 0x007795C0

extern int gdwGlobal_0077998C; // 0x0077998C

struct Unicode;

int __stdcall MAINMENUS_PollCharLogon(int nArg); // 0x00432FE0

int __cdecl sub_0043BF60(); // 0x0043BF60

int __fastcall sub_0043C180_Connect(D2LaunchRecordStrc* pRecord, int bFlag, int nMode); // 0x0043C180

int __cdecl sub_00449B30_QueryAddress(); // 0x00449B30

int __cdecl GAME_GetConnectError(); // 0x00449C00

int __stdcall CHATDLG_RequestCharLogon(const char* szName); // 0x00449E10

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

extern char gaGlobal_007089C4[]; // 0x007089C4

extern void* gpGlobal_0070B738; // 0x0070B738

extern int gnLaunchState_007795E8; // 0x007795E8

extern int gnLaunchMode_007795EC; // 0x007795EC

extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0; // 0x0077ABF0

static void MAINMENUS_SetModeFlags(char nMode); // 0x00431E70

int __stdcall sub_0042FDE0_KeyFilter(D2WinControlStrc* pControl, int nArg, const char* pChar); // 0x0042FDE0

int __stdcall sub_0042FE60_KeyFilter(D2WinControlStrc* pControl, int nArg, const char* pChar); // 0x0042FE60

void __cdecl CHARSEL_UpdateLoginOk(); // 0x004306C0

int __stdcall MAINMENUS_OnLoginChanged(int nArg); // 0x00433BE0

int __cdecl sub_0043B840(); // 0x0043B840

int __stdcall CONTROL_SetFocusedEditBox(D2WinControlStrc* pEditBox); // 0x004F91C0

void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0

void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060

void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0

void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00

void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength); // 0x004FDD50

void __fastcall sub_004FDDD0_LinkTab(D2WinControlStrc* pControl, D2WinControlStrc* pNext); // 0x004FDDD0

int __fastcall D2Win_10076(D2WinControlStrc* pControl, const char* szText); // 0x004FFE10

extern int gnValue_00779980; // 0x00779980

int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0

int __stdcall COMCALLBACK_FilterNameChar(D2WinControlStrc* pControl, int bAllowSep, const char* pChar); // 0x00430590

void __cdecl MAINMENUS_UpdateNameOk(); // 0x00430620

void __cdecl MAINMENUS_LoadCharCreateCells(); // 0x004326F0

int __stdcall MAINMENUS_OnNameChanged(int nArg); // 0x00433BD0

void __fastcall CONTROL_SetEnabled(D2WinControlStrc* pControl, int nFlags); // 0x004F96F0

void __stdcall CONTROL_SetEscapeButton(void* a1); // 0x004FA450

void __fastcall sub_004FB740(D2WinControlStrc* pList, int nA, int nB); // 0x004FB740

extern "C" const char gszFecharPalDat_006D39E8[]; // 0x006D39E8

extern int gnGlobal_00708D0C; // 0x00708D0C

extern int gnGlobal_0070CB80; // 0x0070CB80

extern D2WinControlStrc* gpControl_00779330; // 0x00779330

extern D2WinControlStrc* gpControl_00779348; // 0x00779348

extern D2WinControlStrc* gpControl_00779568; // 0x00779568

extern D2WinControlStrc* gpControl_00779598; // 0x00779598

extern D2WinControlStrc* gpControl_007795B4; // 0x007795B4

extern D2WinControlStrc* gpControl_007795C8; // 0x007795C8

extern D2WinControlStrc* gpControl_007795D8; // 0x007795D8

extern D2WinControlStrc* gpControl_007795DC; // 0x007795DC

const Unicode* __fastcall D2Win_10077_EDITBOX_GetText(D2WinControlStrc*); // 0x004FDD90

extern D2WinControlStrc* gpControl_007799D4; // 0x007799D4

static D2LaunchSlotStrc** gppSlots_00779988; // 0x00779988

D2WinControlStrc* gpEdit_00779334; // 0x00779334

D2WinControlStrc* gpEdit_0077958C; // 0x0077958C

D2WinControlStrc* gpControl_00779594; // 0x00779594

static int s_bGatewayFlag_00779954; // 0x00779954

D2WinControlStrc* gpControl_0077933C; // 0x0077933C

D2WinControlStrc* gpControl_0077934C; // 0x0077934C

D2WinControlStrc* gpControl_0077956C; // 0x0077956C

D2WinControlStrc* gpControl_00779570; // 0x00779570

D2WinControlStrc* gpControl_00779574; // 0x00779574

D2WinControlStrc* gpControl_00779578; // 0x00779578

D2WinControlStrc* gpControl_0077957C; // 0x0077957C

D2WinControlStrc* gpControl_00779580; // 0x00779580

D2WinControlStrc* gpControl_00779584; // 0x00779584

D2WinControlStrc* gpControl_007795B0; // 0x007795B0

D2WinControlStrc* gpControl_007795B8; // 0x007795B8

D2WinControlStrc* gpControl_007795C4; // 0x007795C4

D2WinControlStrc* gpControl_007795CC; // 0x007795CC

int gnGlobal_00779DA4; // 0x00779DA4

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2LaunchControlTemplateStrc;

struct D2FuncTable_0077ABF0Strc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall GetDiskFreeSpaceA(const char* szRootPathName, unsigned long* pnSectorsPerCluster, unsigned long* pnBytesPerSector, unsigned long* pnFreeClusters, unsigned long* pnTotalClusters); // 0x006CC270

int __fastcall FOG_GetSavePath(char* szPath, int nSize); // 0x00407050

unsigned int __stdcall SStrHashHT(const char* szPath); // 0x00414150

int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070

void __cdecl MAINMENUS_CreateLoginScreen(); // 0x00432100

void __cdecl sub_004325B0_CreateScreen(); // 0x004325B0

int __cdecl MAINMENUS_ShowTerms(); // 0x00433810

void __cdecl MAINMENUS_ShowLoginScreen(); // 0x00435330

D2WinControlStrc* __stdcall CONTROL_Create(D2LaunchControlTemplateStrc* pTemplate); // 0x004F93C0

int __stdcall CONTROL_Destroy(D2WinControlStrc** ppControl); // 0x004F95C0

int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg); // 0x004FA470

int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0

const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl); // 0x004FDD90

int __fastcall sub_00526590_Compare(const Unicode* pString1, const Unicode* pString2); // 0x00526590

Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790

char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70

extern D2LaunchControlTemplateStrc gtControlTemplates_00708D10[]; // 0x00708D10

extern D2WinControlStrc* gpEdit_00779340; // 0x00779340

extern D2LaunchDoneFn gpfnGatewayDone_007795BC; // 0x007795BC

extern int gdwGlobal_007795F4; // 0x007795F4

char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0

int __fastcall sub_005264F0_Compare(const Unicode* pString1, const Unicode* pString2); // 0x005264F0

void __fastcall MAINMENUS_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540

extern D2WinControlStrc* gpPasswordOk_007799A4; // 0x007799A4

extern D2WinControlStrc* gpEdit_007799DC; // 0x007799DC

extern D2WinControlStrc* gpEdit_007799E0; // 0x007799E0

extern D2WinControlStrc* gpButton_007799E4; // 0x007799E4

D2WinControlStrc* gapControlsA_00779450[0x40]; // 0x00779450

int gnControlCountA_00779948; // 0x00779948

extern "C" const unsigned char gabDefault_006D4D88[]; // 0x006D4D88

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

int __stdcall MAINMENUS_PollCharCreate(int nArg); // 0x00432FA0

char* __cdecl sub_00437D00(); // 0x00437D00

int __stdcall CHATDLG_RequestCharCreate(const char* szName, int nClass, int nFlags); // 0x00449DF0

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

void __cdecl sub_0042E6D0_LoadFrontEndCells();

int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2);

int __cdecl MAINMENUS_InitAuxBattleNet(); // 0x0042FA40

int __cdecl MAINMENUS_GetAuxBattleNetFlag(); // 0x0042FAB0

void __cdecl MAINMENUS_UpdateNameOk(); // 0x00430620

int __cdecl MAINMENUS_HasSaveFiles(); // 0x00430BC0

int __stdcall MAINMENUS_ShowLevelScreen(int nUnused); // 0x00431600

int __cdecl MAINMENUS_SaveExists(); // 0x00431F70

void __cdecl MAINMENUS_LoadCharCreateCells(); // 0x004326F0

void __cdecl MAINMENUS_PlayIntro(); // 0x004334E0

void __cdecl MAINMENUS_ShowMainMenu(); // 0x004336C0

int __stdcall MAINMENUS_JoinTcpIp(int nUnused); // 0x00434790

int __stdcall MAINMENUS_OnCharCreateOk(int nUnused); // 0x004369F0

void __cdecl MAINMENUS_UpdateStatus(); // 0x00436AD0

// 0x0042E6D0
void __cdecl sub_0042E6D0_LoadFrontEndCells()
{
    char szPath[0x104];
// build: symbol ?gszDataGlobal@* 0x006D4118
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\blizno", gszDataGlobal);
    gpCellFile_007796F8 = sub_004FA9B0_LoadCellFile(szPath, 0);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\trademarkscreenEXP", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\trademark", gszDataGlobal);
    gpCellFile_007796FC = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\CURSOR\\ohand", gszDataGlobal);
    gpCellFile_0077971C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\Diablo2", gszDataGlobal);
    gpCellFile_00779704 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoBlackLeft", gszDataGlobal);
    gpCellFile_00779708 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoFireLeft", gszDataGlobal);
    gpCellFile_0077970C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoBlackRight", gszDataGlobal);
    gpCellFile_00779710 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoFireRight", gszDataGlobal);
    gpCellFile_00779714 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\gameselectscreenEXP", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\TitleScreen", gszDataGlobal);
    gpCellFile_00779718 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\creditsbckgexpand", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\CharSelect\\creditsbckg", gszDataGlobal);
    gpCellFile_00779720 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\WideButtonBlank", gszDataGlobal);
    gpCellFile_00779738 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\WideButtonBlank02", gszDataGlobal);
    gpCellFile_00779754 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\NarrowButtonBlank", gszDataGlobal);
    gpCellFile_00779758 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\GWListBox", gszDataGlobal);
    gpCellFile_0077975C = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
    {
        wsprintfA(szPath, "%s\\ui\\CharSelect\\Realmselectbutton", gszDataGlobal);
        gpCellFile_0077972C = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\CharSelect\\TallButtonBlank", gszDataGlobal);
        gpCellFile_00779730 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\CharSelect\\characterselectscreenEXP", gszDataGlobal);
        gpCellFile_00779734 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CinematicsSelectionEXP", gszDataGlobal);
        gpCellFile_00779774 = sub_004FA9B0_LoadCellFile(szPath, 0);
    }
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\MediumButtonBlank", gszDataGlobal);
    gpCellFile_0077973C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\ShortButtonBlank", gszDataGlobal);
    gpCellFile_00779740 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\textbox2", gszDataGlobal);
    gpCellFile_00779748 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\3WideButtonBlank", gszDataGlobal);
    gpCellFile_0077974C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\TermsofUseBckg", gszDataGlobal);
    gpCellFile_00779764 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectbckg", gszDataGlobal);
    gpCellFile_00779768 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\DifficultyLevels", gszDataGlobal);
    gpCellFile_0077976C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\CinematicsSelection", gszDataGlobal);
    gpCellFile_00779770 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectbox", gszDataGlobal);
    gpCellFile_00779778 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectboxgrey", gszDataGlobal);
    gpCellFile_0077977C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\CreateNewCharImage", gszDataGlobal);
    gpCellFile_00779794 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOK", gszDataGlobal);
    gpCellFile_00779798 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUp_340x224", gszDataGlobal);
    gpCellFile_0077979C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpWide", gszDataGlobal);
    gpCellFile_007797A0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpLargest", gszDataGlobal);
    gpCellFile_007797A4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\TileableDialog", gszDataGlobal);
    gpCellFile_007797A8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOK2", gszDataGlobal);
    gpCellFile_007797AC = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOKCancel", gszDataGlobal);
    gpCellFile_00779780 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOKCancel2", gszDataGlobal);
    gpCellFile_00779784 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\OkCancelButtonBlank", gszDataGlobal);
    gpCellFile_007797B0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\CancelButtonBlank", gszDataGlobal);
    gpCellFile_007797B4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\selectchararrows", gszDataGlobal);
    gpCellFile_00779788 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\Realmselect", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CurRealm", gszDataGlobal);
    gpCellFile_0077978C = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\RealmSelectbuttonthin", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\NarrowButtonBlank02", gszDataGlobal);
    gpCellFile_00779790 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\password", gszDataGlobal);
    gpCellFile_007797B8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\realmbckg", gszDataGlobal);
    gpCellFile_007797C8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\FRONTEND\\joingamescrollbars", gszDataGlobal);
    gpCellFile_007797CC = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\tcpipscreen", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\tcpipbckg", gszDataGlobal);
    gpCellFile_007797D0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\IPAddressBox", gszDataGlobal);
    gpCellFile_007797D4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\downloadpatchbckg", gszDataGlobal);
    gpCellFile_007797D8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\downloadpatchball2", gszDataGlobal);
    gpCellFile_007797DC = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\EditTextBoxWide", gszDataGlobal);
    gpCellFile_00779750 = sub_004FA9B0_LoadCellFile(szPath, 0);
}

// 0x0042F2E0
int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2)
{
    char szPathA[0x104];
    char szPathB[0x104];
    gbPaletteBusy_00779970 = 1;
    wsprintfA(szPathA, gszPathFormat_006D4124, gszDataGlobal, szFile1);
    wsprintfA(szPathB, gszPathFormat_006D4124, gszDataGlobal, szFile2);
    gbFeCharPalette_007795F0 = strcmp(szFile1, "palette\\fechar\\pal.dat") == 0;
    sub_004FB500(szPathA, szPathB);
    return 1;
}

// 0x0042FA40
int __cdecl MAINMENUS_InitAuxBattleNet()
{
    char szAddress[0x64];
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
        return 1;
    sprintf(szAddress, "%d.%d.%d.%d", 0xD8, 0x94, 0xF6, 0x22);
    SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
    return 0;
}

// 0x0042FAB0
int __cdecl MAINMENUS_GetAuxBattleNetFlag()
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

static int sub_0042FCE0_ArchiveFilePresent(const char* szFile)
{
    void* hFile;
    if (!SFileOpenFileEx(0, szFile, 0, &hFile))
        return 0;
    SFileCloseFile(hFile);
    return 1;
}

// 0x0042FD10
static void MAINMENUS_BuildLocalizedVideoPath(char* szOut, const char* szFormat, const char* szFile)
{
    char szLang[4];
    STRTABLE_GetLanguageInfoField(szLang, 0);
// build: symbol ?gszDataLocal@* 0x006D41A8
    sprintf(szOut, szFormat, gszDataLocal, szLang, szFile);
    if (sub_0042FCE0_ArchiveFilePresent(szOut))
        return;
    if (STRTABLE_GetLanguage())
    {
        sprintf(szOut, szFormat, gszDataLocal, "ENG", szFile);
        sub_0042FCE0_ArchiveFilePresent(szOut);
    }
    else
    {
        sprintf(szOut, szFormat, gszDataLocal, "CHI", szFile);
        sub_0042FCE0_ArchiveFilePresent(szOut);
    }
}

// 0x00430620
void __cdecl MAINMENUS_UpdateNameOk()
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
    CONTROL_SetEnabled(gpOkButton_00779330, bValid);
}

// 0x00430BC0
int __cdecl MAINMENUS_HasSaveFiles()
{
    char szDir[0x400];
    char szPattern[0x400];
    D2FindDataStrc tFind;
    FOG_GetSavePath(szDir, 0x400);
    sprintf(szPattern, gszSaveMask_006D41D4, szDir);
    void* hFind = FindFirstFileA(szPattern, &tFind);
    if (hFind != (void*)-1)
    {
        FindClose(hFind);
        return 1;
    }
    return 0;
}

// 0x00431050
int __fastcall MAINMENUS_ShowCredits(int nUnused)
{
    int nLength = 0;
    Unicode* pText = MAINMENUS_LoadCreditsText(&nLength);
    Unicode wszLine[1024];
    D2_ASSERT(pText, 0x141B);

    for (int i = 0; i < 50; ++i)
    {
        D2Win_10045(gpList_00779964, &gszEmptyAssertText);
        D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
        D2Win_10045(gpList_00779960, &gszEmptyAssertText);
    }

    int nRemain = nLength;
    Unicode* pCursor = pText;
    while (nRemain)
    {
        if (pCursor->wChar == 0x2A)
        {
            D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
            D2Win_10045(gpList_00779960, &gszEmptyAssertText);
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
                D2Win_10045(gpList_00779964, &gszEmptyAssertText);
            } while (pCursor->wChar != 0x2A);
        }
        CHARSEL_SyncCreditsLists();
    }

    CHARSEL_FillCreditsList();
    FOG_Free(pText, ".\\Src\\MainMenus.cpp", 0x146F, 0);
    return 1;
}

// 0x00430CD0
Unicode* __stdcall MAINMENUS_LoadCreditsText(int* pnLength)
{
    void* hFile;
    char szLanguage[4];
    STRTABLE_GetLanguageInfoField(szLanguage, 0);

    char szCredits[] = "Credits.txt";
    char szExpansionCredits[] = "ExpansionCredits.txt";
    char szPath[260];
    if (!FOG_IsExpansion())
        SStrPrintf(szPath, 260, "%s\\UI\\%s\\%s", "DATA\\LOCAL", szLanguage, szCredits);
    else
        SStrPrintf(szPath, 260, "%s\\UI\\%s\\%s", "DATA\\LOCAL", szLanguage, szExpansionCredits);

    if (!FOG_FOpenFile(szPath, &hFile))
        return 0;

    const int nSize = FOG_FGetFileSize(hFile, 0);
    char* pBuffer = (char*)FOG_Alloc(nSize, gszMainMenusFile_006D41C0, 0x138B, 0);
    D2_ASSERT(pBuffer, 0x138C);

    memset(pBuffer, 0, nSize);
    Unicode* pText = 0;
    FOG_FReadFile(hFile, pBuffer, nSize, 0, 0, 0, 0);
    FOG_FCloseFile(hFile);

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

// 0x00431600
int __stdcall MAINMENUS_ShowLevelScreen(int nUnused)
{
    char szAddress[0x64];
    unsigned char nLevel;
    sub_00515F50(0xB4);
    sub_00514930();
// build: symbol ?D2SOUND_SetMasterVolume@* 0x00515CE0
    D2SOUND_SetMasterVolume(0xFF);
    CHARSEL_CreateBaseScreen();
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
    if (FOG_IsExpansion())
    {
        MAINMENUS_CreateLevelScreen(nLevel);
        return 1;
    }
    MAINMENUS_CreateControl(0x32);
    D2WinControlStrc* pTitle = MAINMENUS_CreateControl(0x33);
    sub_004FD060_SetText(pTitle, D2LANG_GetStringFromTblIndex(0x13FA));
    MAINMENUS_CreateControl(0x34);
    D2WinControlStrc* pField1 = MAINMENUS_CreateControl(0x35);
    D2WinControlStrc* pField2 = MAINMENUS_CreateControl(0x36);
    D2WinControlStrc* pField3 = MAINMENUS_CreateControl(0x37);
    D2WinControlStrc* pField4 = MAINMENUS_CreateControl(0x38);
    switch (nLevel)
    {
    default:
        CONTROL_SetEnabled(pField1, 0);
    case 2:
        CONTROL_SetEnabled(pField2, 0);
    case 3:
        CONTROL_SetEnabled(pField3, 0);
    case 4:
        CONTROL_SetEnabled(pField4, 0);
    case 5:
    case 6:
    case 7:
        break;
    }
    MAINMENUS_CreateControl(0x39);
    return 1;
}

// 0x00431870
static void __stdcall MAINMENUS_PlayVideo(int nArg, const char* szFormat)
{
    char szPath[0x104];
    char szSize[8];
    MAINMENUS_Reset();
    MAINMENUS_DestroyControls();
    MAINMENUS_FlushInput();
    if (D2Win_10003())
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
        MAINMENUS_BuildLocalizedVideoPath(szPath, szFormat, szSize);
        sub_004F5D90_PlayVideo(szPath, nMode, 0);
        D2Win_10004(1);
    }
    MAINMENUS_FlushInput();
    MAINMENUS_ShowLevelScreen(nArg);
}

// 0x00431F70
int __cdecl MAINMENUS_SaveExists()
{
    char szDir[0x400];
    char szUtf8[0x100];
    char szPath[0x104];
    char szName[0x100];
    FOG_GetSavePath(szDir, 0x400);
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit_0077934C);
    sub_005263E0(szUtf8, pText, 0x100);
    sprintf(szName, gszStringFormat_006FFC58, szUtf8);
    sprintf(szPath, gszSavePathFormat_006D4230, szDir, szName);
    void* hFile = FOG_CreateFileA(szPath, 0x80000000, 0, 0, 3, 0x8000000, 0);
    if (hFile != (void*)-1)
    {
        FOG_CloseFile(hFile);
        return 1;
    }
    return 0;
}

// 0x00435580
void __cdecl MAINMENUS_CreateCharCreateScreen()
{
    MAINMENUS_LoadCharCreateCells();
    MAINMENUS_Reset();
    gnGlobal_00708D0C = -1;
    gnGlobal_0070CB80 = -1;
    gpLaunchRecord_007795D4->wFlags1EF = 0;
    sub_0042F2E0_ReadPaletteFiles(gszFecharPalDat_006D39E8, "palette\\fechar\\pal.pl2");

    MAINMENUS_CreateControl(0xB1);
    gpControl_007795D8 = MAINMENUS_CreateControl(0xC5);
    gpControl_007795DC = MAINMENUS_CreateControl(0xC6);
    D2WinControlStrc* pTitle = MAINMENUS_CreateControl(0xAE);
    sub_004FC9B0_SetText(pTitle, D2LANG_GetStringFromTblIndex(0x1407), 0, 0, 0);

    if (gnLaunchMode_007795EC == 1)
    {
        gpControl_0077933C = MAINMENUS_CreateControl(0xC7);
        sub_004FB740(gpControl_0077933C, -6, 0);
        sub_004FC9B0_SetText(gpControl_0077933C, D2LANG_GetStringFromTblIndex(0x2B87), 1, 0, 0);
        sub_004FC9B0_SetText(gpControl_0077933C, D2LANG_GetStringFromTblIndex(0x2B88), 1, 0, 0);
    }

    CONTROL_SetEscapeButton(MAINMENUS_CreateControl(0xAF));
    gpControl_00779598 = MAINMENUS_CreateControl(0xC8);
    gpControl_007795CC = MAINMENUS_CreateControl(0xC9);
    sub_004FC9B0_SetText(gpControl_007795CC, D2LANG_GetStringFromTblIndex(0x1405), 4, 0, 0);
    gpControl_0077934C = MAINMENUS_CreateControl(0xCC);
    sub_004FDD50_SetMaxLength(gpControl_0077934C, 0x10);
    sub_004FDAD0_SetKeyCallback(gpControl_0077934C, COMCALLBACK_FilterNameChar);
    sub_004FDB00_SetEnterCallback(gpControl_0077934C, MAINMENUS_OnNameChanged);

    if (FOG_IsExpansion())
    {
        gpControl_00779568 = MAINMENUS_CreateControl(0xD3);
        sub_004FC9B0_SetText(gpControl_00779568, D2LANG_GetStringFromTblIndex(0x58CB), 4, 0, 0);
        sub_004F9740_SetControlState(gpControl_00779568, 0);
        gpControl_007795C8 = MAINMENUS_CreateControl(0xD4);
        sub_004F9740_SetControlState(gpControl_007795C8, 0);
        gpControl_007795B4 = MAINMENUS_CreateControl(0xD5);
        sub_004F9740_SetControlState(gpControl_007795B4, 0);
        gpControl_007795B0 = MAINMENUS_CreateControl(0xBD);
        sub_004FC9B0_SetText(gpControl_007795B0, D2LANG_GetStringFromTblIndex(0x1406), 4, 0, 0);
        gpControl_007795C4 = MAINMENUS_CreateControl(0xBE);
        if (gnLaunchMode_007795EC == 1)
        {
            if (gnGlobal_00779DA4)
            {
                gpControl_007795B8 = MAINMENUS_CreateControl(0xC3);
                gpControl_00779348 = MAINMENUS_CreateControl(0xC4);
            }
            else
            {
                gpControl_007795B8 = MAINMENUS_CreateControl(0xC1);
                gpControl_00779348 = MAINMENUS_CreateControl(0xC2);
            }
        }
    }
    else
    {
        gpControl_007795B0 = MAINMENUS_CreateControl(0xCA);
        sub_004FC9B0_SetText(gpControl_007795B0, D2LANG_GetStringFromTblIndex(0x1406), 4, 0, 0);
        gpControl_007795C4 = MAINMENUS_CreateControl(0xCB);
        if (gnLaunchMode_007795EC == 1)
        {
            if (gnGlobal_00779DA4)
            {
                gpControl_007795B8 = MAINMENUS_CreateControl(0xC1);
                gpControl_00779348 = MAINMENUS_CreateControl(0xC2);
            }
            else
            {
                gpControl_007795B8 = MAINMENUS_CreateControl(0xBF);
                gpControl_00779348 = MAINMENUS_CreateControl(0xC0);
            }
        }
    }

    if (gnLaunchMode_007795EC == 1)
    {
        sub_004FC9B0_SetText(gpControl_007795B8, D2LANG_GetStringFromTblIndex(0x2AAF), 4, 0, 0);
    }

    gpControl_00779330 = MAINMENUS_CreateControl(0xB0);
    if (!gnGlobal_00779DA4)
    {
        CONTROL_SetEnabled(gpControl_007795C4, 0);
        CONTROL_SetEnabled(gpControl_007795B0, 0);
    }

    sub_004F9740_SetControlState(gpControl_00779598, 0);
    sub_004F9740_SetControlState(gpControl_007795CC, 0);
    sub_004F9740_SetControlState(gpControl_007795B0, 0);
    sub_004F9740_SetControlState(gpControl_007795C4, 0);
    sub_004F9740_SetControlState(gpControl_0077934C, 0);
    sub_004F9740_SetControlState(gpControl_00779330, 0);
    if (gnLaunchMode_007795EC == 1)
    {
        sub_004F9740_SetControlState(gpControl_007795B8, 0);
        sub_004F9740_SetControlState(gpControl_00779348, 0);
    }

    gpControl_0077956C = MAINMENUS_CreateControl(0xB6);
    if (FOG_IsExpansion())
    {
        gpControl_00779578 = MAINMENUS_CreateControl(0xBA);
        gpControl_0077957C = MAINMENUS_CreateControl(0xBB);
        gpControl_00779570 = MAINMENUS_CreateControl(0xB5);
        gpControl_00779584 = MAINMENUS_CreateControl(0xD1);
        gpControl_00779574 = MAINMENUS_CreateControl(0xBC);
        gpControl_00779580 = MAINMENUS_CreateControl(0xD2);
        MAINMENUS_CreateControl(0xB2);
    }
    else
    {
        gpControl_00779570 = MAINMENUS_CreateControl(0xB5);
        gpControl_00779578 = MAINMENUS_CreateControl(0xB7);
        gpControl_00779574 = MAINMENUS_CreateControl(0xB4);
        gpControl_0077957C = MAINMENUS_CreateControl(0xB8);
        MAINMENUS_CreateControl(0xB3);
    }

    MAINMENUS_UpdateNameOk();
}

// 0x004326F0
void __cdecl MAINMENUS_LoadCharCreateCells()
{
    char szPath[0x104];
    if (gpCellFile_00779724)
        return;
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\MediumSelButtonBlank", gszDataGlobal);
    gpCellFile_00779744 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\charactercreationscreenEXP", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CharacterCreate", gszDataGlobal);
    gpCellFile_00779724 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\fire", gszDataGlobal);
    gpCellFile_00779728 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\textbox", gszDataGlobal);
    gpCellFile_007797BC = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\clickbox", gszDataGlobal);
    gpCellFile_007797C0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
    {
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\joingameclickboxgrey", gszDataGlobal);
        gpCellFile_007797C4 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu1", gszDataGlobal);
        gpCellFile_007797E0 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu2", gszDataGlobal);
        gpCellFile_007797E4 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asfw", gszDataGlobal);
        gpCellFile_007797E8 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu3", gszDataGlobal);
        gpCellFile_007797EC = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asbw", gszDataGlobal);
        gpCellFile_007797F0 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu1", gszDataGlobal);
        gpCellFile_007797F4 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu2", gszDataGlobal);
        gpCellFile_007797F8 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dzfw", gszDataGlobal);
        gpCellFile_007797FC = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu3", gszDataGlobal);
        gpCellFile_00779800 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dzbw", gszDataGlobal);
        gpCellFile_00779804 = sub_004FA9B0_LoadCellFile(szPath, 0);
    }
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu1", gszDataGlobal);
    gpCellFile_00779808 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu2", gszDataGlobal);
    gpCellFile_0077980C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amfw", gszDataGlobal);
    gpCellFile_00779810 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu3", gszDataGlobal);
    gpCellFile_00779814 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\ambw", gszDataGlobal);
    gpCellFile_00779818 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu1", gszDataGlobal);
    gpCellFile_0077981C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu2", gszDataGlobal);
    gpCellFile_00779820 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nefw", gszDataGlobal);
    gpCellFile_00779824 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu3", gszDataGlobal);
    gpCellFile_00779828 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nebw", gszDataGlobal);
    gpCellFile_0077982C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu1", gszDataGlobal);
    gpCellFile_00779830 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu2", gszDataGlobal);
    gpCellFile_00779834 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\bafw", gszDataGlobal);
    gpCellFile_00779838 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu3", gszDataGlobal);
    gpCellFile_0077983C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\babw", gszDataGlobal);
    gpCellFile_00779840 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu1", gszDataGlobal);
    gpCellFile_00779844 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu2", gszDataGlobal);
    gpCellFile_00779848 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sofw", gszDataGlobal);
    gpCellFile_0077984C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu3", gszDataGlobal);
    gpCellFile_00779850 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sobw", gszDataGlobal);
    gpCellFile_00779854 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu1", gszDataGlobal);
    gpCellFile_00779858 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu2", gszDataGlobal);
    gpCellFile_0077985C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pafw", gszDataGlobal);
    gpCellFile_00779860 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu3", gszDataGlobal);
    gpCellFile_00779864 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pabw", gszDataGlobal);
    gpCellFile_00779868 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sofws", gszDataGlobal);
    gpCellFile_0077989C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu3s", gszDataGlobal);
    gpCellFile_007798A0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sobws", gszDataGlobal);
    gpCellFile_007798A4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nefws", gszDataGlobal);
    gpCellFile_00779888 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu3s", gszDataGlobal);
    gpCellFile_0077988C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nebws", gszDataGlobal);
    gpCellFile_00779890 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\bafws", gszDataGlobal);
    gpCellFile_007798B0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pafws", gszDataGlobal);
    gpCellFile_007798C4 = sub_004FA9B0_LoadCellFile(szPath, 0);
}

// 0x004334E0
void __cdecl MAINMENUS_PlayIntro()
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
    MAINMENUS_FlushInput();
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
    STRTABLE_GetLanguageInfoField(szLanguage, 0);
    sprintf(szPath, "%s\\video\\%s\\D2x_Intro_%s.bik", gszDataLocal, szLanguage, szSize);
    if (SFileOpenFileEx(0, szPath, 0, &hFile))
        SFileCloseFile(hFile);
    else
        sprintf(szPath, "%s\\video\\%s\\D2x_Intro%s.bik", gszDataLocal, "ENG", szSize);
    sub_004F5D90_PlayVideo(szPath, nMode, 0);
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
        sscanf(szAddress, "%ld.%ld.%ld.%ld", &a, &b, &c, &d);
    d |= 0x80;
    sprintf(szAddress, "%d.%d.%d.%ld", 0xD8, 0x94, 0xF6, d);
    SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
}

// 0x00433640
void __cdecl MAINMENUS_PlayIntroVideo()
{
    char szPath[0x104];
    char szSize[8];
    MAINMENUS_FlushInput();
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
    MAINMENUS_BuildLocalizedVideoPath(szPath, "%s\\video\\%s\\d2intro%s.bik", szSize);
    sub_004F5D90_PlayVideo(szPath, nMode, 0);
    sub_0042FB20();
}

// build: symbol ?CHARSEL_AddToSlots@* 0x004309C0
int __stdcall CHARSEL_AddToSlots(void* pEntry)
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

// build: symbol ?MAINMENUS_FreeSlots@* 0x00430A20
int __cdecl MAINMENUS_FreeSlots()
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

// 0x004336C0
void __cdecl MAINMENUS_ShowMainMenu()
{
    char szVersion[0x40];
    D2WinControlStrc* pFirst;
    D2WinControlStrc* pSecond;
    CHARSEL_DisconnectBattleNet();
    gpLaunchRecord_007795D4->szName[0] = 0;
    CHARSEL_CreateBaseScreen();
    if (FOG_IsExpansion())
    {
        gpControl_007795AC = MAINMENUS_CreateControl(0x12);
        MAINMENUS_ShowCurrentGateway();
        pFirst = MAINMENUS_CreateControl(0x11);
        pSecond = MAINMENUS_CreateControl(0x13);
        MAINMENUS_CreateControl(0x10);
    }
    else
    {
        pFirst = MAINMENUS_CreateControl(0x0A);
        gpControl_007795AC = MAINMENUS_CreateControl(0x0B);
        MAINMENUS_ShowCurrentGateway();
        MAINMENUS_CreateControl(0x09);
        pSecond = MAINMENUS_CreateControl(0x0C);
    }
    if (sub_004FAC90())
    {
        CONTROL_SetEnabled(pFirst, 0);
        CONTROL_SetEnabled(pSecond, 0);
        CONTROL_SetEnabled(gpControl_007795AC, 0);
    }
    MAINMENUS_CreateControl(0x0D);
    MAINMENUS_CreateControl(0x0E);
    MAINMENUS_CreateControl(0x0F);
    D2WinControlStrc* pText = MAINMENUS_CreateControl(0x115);
    const int nLen = SStrPrintf(szVersion, 0x40, "v %d.%d%c", 1, 0x0E, 0x64);
    if (gpLaunchRecord_007795D4->bFlag223)
        SStrPrintf(&szVersion[nLen], 0x40 - nLen, " %d", 0x47);
    sub_004FCFF0_SetTextA(pText, szVersion, 0);
// build: symbol ?D2SOUND_GetOptionsMusicOption@* 0x00514D80
    if (D2SOUND_GetOptionsMusicOption())
        D2SOUND_10034(1);
}

// 0x00434320
int __stdcall MAINMENUS_PlayClassicIntro(int nArg)
{
    ARCHIVE_UnloadExpansionArchives();
    if (!ARCHIVE_LoadVideoArchives((void*)MAINMENUS_ShowArchiveMessage, 0, 0))
    {
        ARCHIVE_UnloadExpansionArchives();
        ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    MAINMENUS_PlayVideo(nArg, "%s\\video\\%s\\d2intro%s.bik");
    return 1;
}

// 0x00434380
int __stdcall MAINMENUS_PlayActTwoStart(int nArg)
{
    ARCHIVE_UnloadExpansionArchives();
    if (!ARCHIVE_LoadVideoArchives((void*)MAINMENUS_ShowArchiveMessage, 0, 0))
    {
        ARCHIVE_UnloadExpansionArchives();
        ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    MAINMENUS_PlayVideo(nArg, "%s\\video\\%s\\Act02start%s.bik");
    return 1;
}

// 0x004343E0
int __stdcall MAINMENUS_PlayActThreeStart(int nArg)
{
    ARCHIVE_UnloadExpansionArchives();
    if (!ARCHIVE_LoadVideoArchives((void*)MAINMENUS_ShowArchiveMessage, 0, 0))
    {
        ARCHIVE_UnloadExpansionArchives();
        ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    MAINMENUS_PlayVideo(nArg, "%s\\video\\%s\\Act03start%s.bik");
    return 1;
}

// 0x00434440
int __stdcall MAINMENUS_PlayActFourStart(int nArg)
{
    ARCHIVE_UnloadExpansionArchives();
    if (!ARCHIVE_LoadVideoArchives((void*)MAINMENUS_ShowArchiveMessage, 0, 0))
    {
        ARCHIVE_UnloadExpansionArchives();
        ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    MAINMENUS_PlayVideo(nArg, "%s\\video\\%s\\Act04start%s.bik");
    return 1;
}

// 0x004344A0
int __stdcall MAINMENUS_PlayActFourEnd(int nArg)
{
    ARCHIVE_UnloadExpansionArchives();
    if (!ARCHIVE_LoadVideoArchives((void*)MAINMENUS_ShowArchiveMessage, 0, 0))
    {
        ARCHIVE_UnloadExpansionArchives();
        ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    MAINMENUS_PlayVideo(nArg, "%s\\video\\%s\\Act04end%s.bik");
    return 1;
}

// 0x00434500
int __stdcall MAINMENUS_PlayExpansionIntro(int nArg)
{
    ARCHIVE_UnloadExpansionArchives();
    if (!ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4))
        ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
    MAINMENUS_PlayVideo(nArg, "%s\\video\\%s\\D2x_Intro_%s.bik");
    return 1;
}

// 0x00434560
int __stdcall MAINMENUS_PlayExpansionOutro(int nArg)
{
    ARCHIVE_UnloadExpansionArchives();
    if (!ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4))
        ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
    MAINMENUS_PlayVideo(nArg, "%s\\video\\%s\\D2x_Out_%s.bik");
    return 1;
}

// 0x00436CF0
void __cdecl MAINMENUS_UpdateTwoEditOk()
{
 const Unicode* pText1=D2Win_10077_EDITBOX_GetText(gpEdit_007799CC);
 const Unicode* pText2=D2Win_10077_EDITBOX_GetText(gpEdit_007799D0);
 int bOk=sub_00526800(pText1)>0;
 bOk|=sub_00526800(pText2)>0;
 CONTROL_SetEnabled(gpControl_007799D4,bOk);
}

static void MAINMENUS_SetModeFlags(char nMode)
{
    gpLaunchRecord_007795D4->nMode = nMode;
    gpLaunchRecord_007795D4->nFlag085 = 0;
    gpLaunchRecord_007795D4->nFlag089 = 0;
    gpLaunchRecord_007795D4->nFlag088 = 0;
    gpLaunchRecord_007795D4->nFlag086 = 0;
    gpLaunchRecord_007795D4->nFlag087 = 0;
    gpLaunchRecord_007795D4->nFlag08A = 0;
    gpLaunchRecord_007795D4->nFlag08B = 0;

    if (nMode == 0)
    {
        gpLaunchRecord_007795D4->nFlag085 = 1;
    }
    else if (nMode == 4)
    {
        gpLaunchRecord_007795D4->nFlag089 = 1;
    }
    else if (nMode == 2)
    {
        gpLaunchRecord_007795D4->nFlag088 = 1;
    }
    else if (nMode == 3)
    {
        gpLaunchRecord_007795D4->nFlag086 = 1;
    }
    else if (nMode == 1)
    {
        gpLaunchRecord_007795D4->nFlag087 = 1;
    }
    else if (nMode == 5)
    {
        gpLaunchRecord_007795D4->nFlag08A = 1;
    }
    else if (nMode == 6)
    {
        gpLaunchRecord_007795D4->nFlag08B = 1;
    }
}

// 0x00434790
int __stdcall MAINMENUS_JoinTcpIp(int nUnused)
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
    MAINMENUS_ShowConnectingPopup();
    sub_004FA590_RunLoop(sub_00431D10);
    gbConnected_0077959C = 0;
    sub_0052A750(0, szText);
    sub_004FA590_RunLoop(sub_00431E30);
    if (!gbConnected_0077959C)
    {
        sub_0052A7E0();
        MAINMENUS_DestroyControls();
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x145B);
// build: symbol ?CHARSEL_CreateTcpIpScreen@* 0x0042FFE0
        MAINMENUS_ShowMessage(pMessage, CHARSEL_CreateTcpIpScreen, 1);
        return 1;
    }
    MAINMENUS_DestroyControls();
    MAINMENUS_ShowConnectingPopup();
    sub_004FA590_RunLoop(sub_00431C90);
    sub_0052A7E0();
    MAINMENUS_DestroyControls();
    if (!gdwGlobal_00779974)
    {
        gnLaunchMode_007795EC = 2;
        *(int*)gpLaunchRecord_007795D4->aState19 = 9;
        *(unsigned short*)gpLaunchRecord_007795D4->aWord1D = 1;
        sub_00515020();
        MAINMENUS_Reset();
        CHARSEL_InitCharSelectScreen();
    }
    return 1;
}

// build: symbol ?MAINMENUS_CreateFromTemplate@* 0x0042F3A0
D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId)
{
    D2_ASSERT(gnControlCountA_00779948 < 0x40, 0x610);
    D2WinControlStrc* pControl = CONTROL_Create(&gtControlTemplates_00708D10[nTemplateId]);
    gapControlsA_00779450[gnControlCountA_00779948++] = pControl;
    return pControl;
}

void __cdecl MAINMENUS_DestroyControls()
{
    for (int i = 0; i < gnControlCountA_00779948; ++i)
        CONTROL_Destroy(&gapControlsA_00779450[i]);
    gnControlCountA_00779948 = 0;
}

// build: symbol ?MAINMENUS_StoreAccountTexts@* 0x00432080
static void MAINMENUS_StoreAccountTexts(D2WinControlStrc* pAccountEdit, D2WinControlStrc* pPasswordEdit)
{
    if (pAccountEdit)
    {
        const Unicode* pText = sub_004FDD90_GetEditText(pAccountEdit);
        sub_00526F70(gpLaunchRecord_007795D4->szAccount, pText, 0x100);
    }
    if (pPasswordEdit)
    {
        const Unicode* pText = sub_004FDD90_GetEditText(pPasswordEdit);
        sub_00526F70(gpLaunchRecord_007795D4->szPassword, pText, 0x100);
        gpLaunchRecord_007795D4->dwPasswordHash = SStrHashHT(gpLaunchRecord_007795D4->szPassword);
        gpLaunchRecord_007795D4->nPasswordLength = SStrLen(gpLaunchRecord_007795D4->szPassword);
    }
}

// build: symbol ?MAINMENUS_SetMultilineText@* 0x004330A0
static int __stdcall MAINMENUS_SetMultilineText(D2WinControlStrc* pControl, int nArg, const Unicode* pText, bool bWrapped)
{
    Unicode aBuffer[0x400];
    for (int i = 0; i < 0x400; ++i)
        aBuffer[i].wChar = 0;
    sub_00526790(aBuffer, pText, 0x400);
    Unicode* pChar = aBuffer;
    Unicode* pLine = pChar;
    while (pChar->wChar)
    {
        if (pChar->wChar == 0xA)
        {
            pChar->wChar = 0;
            D2Win_10051(pControl, pLine, nArg, bWrapped, 0);
            pLine = pChar + 1;
        }
        ++pChar;
    }
    if (pLine < pChar)
        D2Win_10051(pControl, pLine, nArg, bWrapped, 0);
    return 1;
}

void __fastcall MAINMENUS_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg)
{
    D2WinControlStrc* pFrame;
    D2WinControlStrc* pButton;
    D2WinControlStrc* pTextBox;
    MAINMENUS_DestroyControls();
    if (gbFeCharPalette_007795F0)
    {
        pFrame = MAINMENUS_CreateFromTemplate(0xF7);
        D2Win_10033(pFrame, 1);
        pButton = MAINMENUS_CreateFromTemplate(nArg ? 0xF8 : 0xFA);
        pTextBox = MAINMENUS_CreateFromTemplate(0xF9);
    }
    else
    {
        pFrame = MAINMENUS_CreateFromTemplate(0xDE);
        D2Win_10033(pFrame, 1);
        pButton = MAINMENUS_CreateFromTemplate(nArg ? 0xE1 : 0xDF);
        pTextBox = MAINMENUS_CreateFromTemplate(0xE0);
    }
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pButton, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pTextBox, 1);
    MAINMENUS_SetMultilineText(pTextBox, 0, pText, false);
    gpfnGatewayDone_007795BC = pfnDone;
}

// 0x00434E00
int __stdcall MAINMENUS_CheckFreeSpace(int nUnused)
{
    char szPath[0x400];
    MAINMENUS_StoreAccountTexts(gpEdit_0077958C, gpEdit_00779334);
    FOG_GetSavePath(szPath, 0x400);
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
        MAINMENUS_ShowMessage(D2LANG_GetStringFromTblIndex(0x141D), MAINMENUS_ReturnToCharSelect, 1);
        return 1;
    }
    return MAINMENUS_ShowTerms();
}

struct D2WinControlStrc;

// 0x00435330
void __cdecl MAINMENUS_ShowLoginScreen()
{
    char szAccount[0x400];
    s_bGatewayFlag_00779954 = 1;
    int bConnected = gpFuncTable_0077ABF0->pfnSlot68();
    if (bConnected && !sub_0043B840())
        goto create;
    if (bConnected)
        CHARSEL_DisconnectBattleNet();
    sub_004336C0();
    if (!sub_0043BF60())
        return;
create:
    gpEdit_0077958C = 0;
    gpEdit_00779334 = 0;
    gpEdit_007795A8 = 0;
    gpControl_00779594 = 0;
    CHARSEL_CreateBaseScreen();
    MAINMENUS_CreateControl(0x15);
    MAINMENUS_CreateControl(0x16);
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x1A);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    pControl = MAINMENUS_CreateControl(0x1B);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1469));
    if (!FOG_IsExpansion())
    {
        pControl = MAINMENUS_CreateControl(0x1F);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1454), 0, 0, 0);
    }
    pControl = MAINMENUS_CreateControl(0x20);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1455), 0, 0, 0);
    gpEdit_0077958C = MAINMENUS_CreateControl(0x22);
    sub_004FDD50_SetMaxLength(gpEdit_0077958C, 0x10);
    sub_004FDB00_SetEnterCallback(gpEdit_0077958C, MAINMENUS_OnLoginChanged);
    sub_004FDAD0_SetKeyCallback(gpEdit_0077958C, sub_0042FDE0_KeyFilter);
    gpEdit_00779334 = MAINMENUS_CreateControl(0x23);
    sub_004FDD50_SetMaxLength(gpEdit_00779334, 0xD);
    sub_004FDB00_SetEnterCallback(gpEdit_00779334, MAINMENUS_OnLoginChanged);
    sub_004FDAD0_SetKeyCallback(gpEdit_00779334, sub_0042FE60_KeyFilter);
    if (SRegLoadString("Diablo II", "Last BNet", 0, szAccount, 0x400))
    {
        D2Win_10076(gpEdit_0077958C, szAccount);
        CONTROL_SetFocusedEditBox(gpEdit_00779334);
    }
    else
        CONTROL_SetFocusedEditBox(gpEdit_0077958C);
    sub_004FDDD0_LinkTab(gpEdit_0077958C, gpEdit_00779334);
    sub_004FDDD0_LinkTab(gpEdit_00779334, gpEdit_0077958C);
    MAINMENUS_CreateControl(0x24);
    MAINMENUS_CreateControl(0x25);
    gpControl_00779594 = MAINMENUS_CreateControl(0x26);
    MAINMENUS_CreateControl(0x27);
    CHARSEL_UpdateLoginOk();
    if (gnValue_00779980)
    {
        pControl = MAINMENUS_CreateControl(0x28);
        D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B62));
    }
    if (D2SOUND_GetOptionsMusicOption())
        D2SOUND_10034(1);
}

// 0x004369F0
int __stdcall MAINMENUS_OnCharCreateOk(int nUnused)
{
    char szPath[0x400];
    if (sub_004F9710_TestFlags(gpOkButton_00779330))
    {
        FOG_GetSavePath(szPath, 0x400);
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
            sub_00433460_ShowMessage(D2LANG_GetStringFromTblIndex(0x141D), MAINMENUS_ReturnToCharSelect);
            return 1;
        }
        CONTROL_SetEnabled(gpOkButton_00779330, 0);
        MAINMENUS_CreateCharacter();
    }
    return 1;
}

static inline void __fastcall ShowText(const Unicode* pText, void (__cdecl* pfnDone)())
{
    MAINMENUS_ShowMessage(pText, pfnDone, 1);
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00435E10
void __cdecl MAINMENUS_CreateRealmCharacter()
{
// build: symbol ?MAINMENUS_ConnectToRealm@* 0x00432480
    switch (MAINMENUS_ConnectToRealm(sub_00437D00(), 0))
    {
    case 1:
    case 2:
        sub_00435580();
        return;
    }

    if (!GAME_GetConnectError() && sub_00449B30_QueryAddress())
    {
        if (sub_00449B30_QueryAddress())
        {
            gpLaunchRecord_007795D4->nByte3C1 = 1;
            SMemCopy(gpLaunchRecord_007795D4->aData3A1, gabDefault_006D4D88, 0x10);
            SMemZero(gpLaunchRecord_007795D4->aData3B1, 0x10);
            gpLaunchRecord_007795D4->nByte3C2 = (gpLaunchRecord_007795D4->wFlags1EF >> 6) & 1;
            gpLaunchRecord_007795D4->wFlags3CB = gpLaunchRecord_007795D4->wFlags1EF;
            CHATDLG_RequestCharCreate(gpLaunchRecord_007795D4->szCharName, gpLaunchRecord_007795D4->nClass, gpLaunchRecord_007795D4->wFlags1EF);
            MAINMENUS_ShowConnectingPopup();
            sub_004FA590_RunLoop(MAINMENUS_PollCharCreate);
            if (gdwGlobal_00779974)
            {
                MAINMENUS_DestroyControls();
                return;
            }

            int nError = GAME_GetConnectError();
            if (nError)
            {
                if (nError != 20)
                {
                    Unicode wszName[100];
                    sub_00410610_WriteLogLine("Error from MCP trying to create '%s' (err=%d)", gpLaunchRecord_007795D4->szCharName, GAME_GetConnectError());
                    D2MCPClientCloseMCP();
                    Unicode wszText[255];
                    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x145E));
                    Unicode wszTail[255];
                    sub_005267E0(wszTail, D2LANG_GetStringFromTblIndex(0x145F));
                    char szName[80];
                    sprintf(szName, "%s", gpLaunchRecord_007795D4->szCharName);
                    sub_00526320_ToUnicode(wszName, szName, 100);
                    sub_00526700(wszText, wszName);
                    sub_00526700(wszText, wszTail);
                    ShowText(wszText, sub_00435580);
                    return;
                }

                D2MCPClientCloseMCP();
                Unicode wszText[256];
                Unicode wszName[256];
                sub_00526F20_ToUnicode(wszName, gpLaunchRecord_007795D4->szCharName, 256);
                sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0x2B33), wszName);
                ShowText(wszText, sub_00435580);
                return;
            }

            sub_0043C6A0(1);
            SStrCopy(gpLaunchRecord_007795D4->szDataD5, sub_00437D00(), 0x7FFFFFFF);
            gpLaunchRecord_007795D4->wFlags1EF |= 2;
            gpLaunchRecord_007795D4->nByte35E = 2;
            gnLaunchState_007795E8 = 3;
        }

        D2Win_StopMessageLoop();
        return;
    }

    D2MCPClientCloseMCP();
    int nString;
    switch (GAME_GetConnectError())
    {
    case 2:
        nString = 0x145B;
        break;

    case 10:
    case 11:
    case 12:
        ShowText(D2LANG_GetStringFromTblIndex(0x145D), sub_00435580);
        return;

    case 71:
        nString = 0x145C;
        break;

    default:
        nString = 0x145C;
        break;
    }

    ShowText(D2LANG_GetStringFromTblIndex(nString), MAINMENUS_ReturnToCharSelect);
}

// 0x004365B0
void __cdecl MAINMENUS_CreateCharacter()
{
    char szName[0x100];
    if (MAINMENUS_SaveExists() == 1 && gnLaunchMode_007795EC != 1)
    {
        sub_00433460_ShowMessage(D2LANG_GetStringFromTblIndex(0x142D), MAINMENUS_DestroyControls);
        return;
    }
    if (gpLaunchRecord_007795D4->nMode == 6 || gpLaunchRecord_007795D4->nMode == 5)
        *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF |= 0x20;
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit_0077934C);
    sub_005263E0(szName, pText, 0x100);
    sprintf((gpLaunchRecord_007795D4->szPassword + 0x18), gszStringFormat_006FFC58, szName);
    gpLaunchRecord_007795D4->szPassword[0x30] = 0;
    if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
        gbFlag_00779984 = 1;
    if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
    {
        sub_00430520();
        return;
    }
    if (gnLaunchMode_007795EC == 0)
    {
        MAINMENUS_Reset();
        AUTOMAP_InitCharSaveHeader((gpLaunchRecord_007795D4->szPassword + 0x18), gpLaunchRecord_007795D4->nMode, (gpLaunchRecord_007795D4->szPassword + 0x48), *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0((gpLaunchRecord_007795D4->szPassword + 0x18));
        gpLaunchRecord_007795D4->nByte35E = 1;
        *(int*)gpLaunchRecord_007795D4->aState19 = 0;
        gnLaunchState_007795E8 = 1;
        *(int*)gpLaunchRecord_007795D4->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
            *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord_007795D4->aState209 |= 0x100000;
        D2Win_StopMessageLoop();
    }
    else if (gnLaunchMode_007795EC == 2)
    {
        MAINMENUS_Reset();
        sub_0043C6A0(0);
        AUTOMAP_InitCharSaveHeader((gpLaunchRecord_007795D4->szPassword + 0x18), gpLaunchRecord_007795D4->nMode, (gpLaunchRecord_007795D4->szPassword + 0x48), *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0((gpLaunchRecord_007795D4->szPassword + 0x18));
        gpLaunchRecord_007795D4->nByte35E = 3;
        gnLaunchState_007795E8 = 1;
        *(int*)gpLaunchRecord_007795D4->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
            *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord_007795D4->aState209 |= 0x100000;
        D2Win_StopMessageLoop();
    }
    else if (gnLaunchMode_007795EC == 3)
    {
        MAINMENUS_Reset();
        D2MCPClientCloseMCP();
        sub_0043C6A0(0);
        AUTOMAP_InitCharSaveHeader((gpLaunchRecord_007795D4->szPassword + 0x18), gpLaunchRecord_007795D4->nMode, (gpLaunchRecord_007795D4->szPassword + 0x48), *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0((gpLaunchRecord_007795D4->szPassword + 0x18));
        gpLaunchRecord_007795D4->nByte3C1 = 1;
        SMemCopy(gpLaunchRecord_007795D4->aData3A1, gabDefault_006D4D88, 0x10);
        SMemZero(gpLaunchRecord_007795D4->aData3B1, 0x10);
        gpLaunchRecord_007795D4->nByte3C2 = (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF >> 6) & 1;
        *(unsigned short*)gpLaunchRecord_007795D4->aWord3CB = *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF;
        gpLaunchRecord_007795D4->nByte35E = 4;
        gpLaunchRecord_007795D4->nByte22D = 0;
        gpLaunchRecord_007795D4->szPassword[0x30] = 0;
        gnLaunchState_007795E8 = 3;
        *(int*)gpLaunchRecord_007795D4->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
            *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord_007795D4->aState209 |= 0x100000;
        D2Win_StopMessageLoop();
    }
    else if (gnLaunchMode_007795EC == 1)
    {
        MAINMENUS_CreateRealmCharacter();
    }
}

// 0x00436AD0
void __cdecl MAINMENUS_UpdateStatus()
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
    D2Win_10045(gpCounterText_007799AC, szText);
}

// 0x00436C10
static int MAINMENUS_CheckAtAndDot(const char* szText)
{
    if (!szText)
        return 0;
    int bValid = 0;
    const char* pAt = SStrChr(szText, '@');
    if (pAt)
    {
        const char* pDot = SStrChr(pAt, '.');
        if (pDot && pAt > szText && pDot > pAt + 1 && (int)SStrLen(szText) > pDot - szText + 1)
            bValid = 1;
    }
    return bValid;
}

// build: symbol ?MAINMENUS_ChangePasswordOk@* 0x00435030
int __stdcall MAINMENUS_ChangePasswordOk(int nArg)
{
    if (!nArg)
    {
        sub_004370C0();
        return 1;
    }
    MAINMENUS_StoreAccountTexts(gpEdit_0077958C, gpEdit_00779340);
    const Unicode* pAccount = sub_004FDD90_GetEditText(gpEdit_0077958C);
    const Unicode* pOldPassword = sub_004FDD90_GetEditText(gpEdit_00779334);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpEdit_00779340);
    const Unicode* pConfirm = sub_004FDD90_GetEditText(gpEdit_007795A8);
    sub_00526F70(gszOldPassword_00779550, pOldPassword, 0x100);
    int nLength = sub_00526800(pAccount);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1460);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateLoginScreen, 1);
        return 1;
    }
    if (nLength > 0xF)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1461);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateLoginScreen, 1);
        return 1;
    }
    if (sub_00526590_Compare(pPassword, pConfirm))
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1462);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateLoginScreen, 1);
        return 1;
    }
    nLength = sub_00526800(pPassword);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1463);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateLoginScreen, 1);
        return 1;
    }
    if (nLength > 0x14)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1464);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateLoginScreen, 1);
        return 1;
    }
    gdwGlobal_007795F4 = 0;
    if (!sub_0043C180_Connect(gpLaunchRecord_007795D4, 0, 1))
    {
        if (gdwGlobal_007795F4)
        {
            MAINMENUS_CreateLoginScreen();
            return 1;
        }
    }
    else
    {
        SRegSaveString("Diablo II", "Last BNet", 0, gpLaunchRecord_007795D4->szAccount);
        MAINMENUS_DestroyControls();
        MAINMENUS_ReturnToCharSelect();
    }
    return 1;
}

// build: symbol ?MAINMENUS_LoginOk@* 0x004361B0
int __stdcall MAINMENUS_LoginOk(int nArg)
{
    if (!nArg)
    {
        sub_004336C0();
        return 1;
    }
    if (!sub_004F9710_TestFlag(gpControl_00779594))
        return 0;
    MAINMENUS_StoreAccountTexts(gpEdit_0077958C, gpEdit_00779334);
    if (sub_0043C180_Connect(gpLaunchRecord_007795D4, 0, 0))
    {
        SRegSaveString("Diablo II", "Last BNet", 0, gpLaunchRecord_007795D4->szAccount);
        if (gnLaunchMode_007795EC == 1)
        {
            sub_00515020();
            MAINMENUS_Reset();
            sub_0043B080();
            return 1;
        }
        if (MAINMENUS_HasSaveFiles())
        {
            MAINMENUS_ReturnToCharSelect();
            return 1;
        }
        sub_00435580();
    }
    return 1;
}

// build: symbol ?MAINMENUS_CreateAccountOk@* 0x00436910
int __stdcall MAINMENUS_CreateAccountOk(int nArg)
{
    if (!nArg)
    {
        MAINMENUS_ShowLoginScreen();
        return 1;
    }
    MAINMENUS_StoreAccountTexts(gpEdit_0077958C, gpEdit_00779334);
    const Unicode* pAccount = sub_004FDD90_GetEditText(gpEdit_0077958C);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpEdit_00779334);
    const Unicode* pConfirm = sub_004FDD90_GetEditText(gpEdit_007795A8);
    int nLength = sub_00526800(pAccount);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1460);
// build: symbol ?MAINMENUS_CreateMultiplayerScreen@* 0x004301A0
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateMultiplayerScreen, 1);
        return 1;
    }
    if (nLength > 0xF)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1461);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateMultiplayerScreen, 1);
        return 1;
    }
    if (sub_00526590_Compare(pPassword, pConfirm))
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1462);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateMultiplayerScreen, 1);
        return 1;
    }
    nLength = sub_00526800(pPassword);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1463);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateMultiplayerScreen, 1);
        return 1;
    }
    if (nLength > 0x14)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1464);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateMultiplayerScreen, 1);
        return 1;
    }
    sub_004325B0_CreateScreen();
    return 1;
}

// 0x00436EB0
void __cdecl MAINMENUS_UpdateEmailOk()
{
    char szText[0x100];
    int bOk = sub_00526800(sub_004FDD90_GetEditText(gpEdit_007799DC)) > 0;
    if (bOk)
    {
        const Unicode* pText = sub_004FDD90_GetEditText(gpEdit_007799E0);
        sub_005263E0(szText, pText, 0x100);
        bOk = MAINMENUS_CheckAtAndDot(szText);
    }
    CONTROL_SetEnabled(gpButton_007799E4, bOk);
}

// 0x004371E0
void __cdecl MAINMENUS_UpdatePasswordOk()
{
    char szText3[0x100];
    char szText1[0x100];
    char szText2[0x100];
    int bOk = sub_00526800(sub_004FDD90_GetEditText(gpPasswordEdit_007799BC)) > 2;
    if (bOk)
    {
        const Unicode* pText1 = sub_004FDD90_GetEditText(gpPasswordEdit_007799C0);
            sub_005263E0(szText1, pText1, 0x100);
        bOk = MAINMENUS_CheckAtAndDot(szText1);
        if (bOk)
        {
            const Unicode* pText2 = sub_004FDD90_GetEditText(gpPasswordEdit_007799C8);
            sub_005263E0(szText2, pText2, 0x100);
            bOk = MAINMENUS_CheckAtAndDot(szText2);
            if (bOk)
            {
                const Unicode* pText3 = sub_004FDD90_GetEditText(gpPasswordEdit_007799C4);
            sub_005263E0(szText3, pText3, 0x100);
                bOk = MAINMENUS_CheckAtAndDot(szText3);
            }
        }
    }
    CONTROL_SetEnabled(gpPasswordOk_007799A4, bOk);
}

// 0x00437620
int __stdcall MAINMENUS_ConfirmText(int nArg)
{
    char szText[0x100];
    const Unicode* pText1 = sub_004FDD90_GetEditText(gpEdit_007799CC);
    const Unicode* pText2 = sub_004FDD90_GetEditText(gpEdit_007799D0);
    if (!sub_005264F0_Compare(pText1, pText2))
    {
        sub_005263E0(szText, pText1, 0x100);
        if (!MAINMENUS_CheckAtAndDot(szText))
        {
            MAINMENUS_ShowMessageBox(D2LANG_GetStringFromTblIndex(0x2B5C), D2LANG_GetStringFromTblIndex(0x2B5D), 0x13EE, 0, sub_004334D0_CloseBox, 0, 1, 0);
            return 1;
        }
        gpFuncTable_0077ABF0->pfnSlotB8(szText);
        D2Win_StopMessageLoop();
        return 1;
    }
    MAINMENUS_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B5B), 0x13EE, 0, sub_004334D0_CloseBox, 0, 1, 0);
    return 1;
}

// 0x00434060
void __cdecl MAINMENUS_BuildRealmList()
{
    MAINMENUS_ShowConnectingPopup();
    sub_004FA590_RunLoop(MAINMENUS_StopLoop);
    if (gpFuncTable_0077ABF0)
        gpMenuList_007795C0 = gpFuncTable_0077ABF0->pfnGetMenuList(0);
    MAINMENUS_DestroyControls();
    D2MenuListStrc* pList = gpMenuList_007795C0;
    if (!pList)
    {
        gdwGlobal_0077998C = -1;
        return;
    }
    gdwGlobal_0077998C = pList->nCount;
    D2_ASSERT(gdwGlobal_0077998C < 512, 4481);
    char* pText = (char*)(pList + 1);
    MAINMENUS_FreeSlots();
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
            CHARSEL_AddToSlots(pSlot);
        }
        qsort(gppSlots_00779988, gdwGlobal_0077998C, sizeof(D2LaunchSlotStrc*), CHARSEL_CompareNames);
    }
}

// 0x00434A00
int __fastcall MAINMENUS_JoinGame(const char* szGameName, unsigned short wFlags, char nMode, const char* szPassword)
{
    int bPassword = szPassword[0] != 0;
    strcpy(gpLaunchRecord_007795D4->szGameName, szGameName);
    strcpy(gpLaunchRecord_007795D4->szGamePassword, szPassword);
    gpLaunchRecord_007795D4->wFlags1EF = wFlags;
    MAINMENUS_SetModeFlags(nMode);

    if (gnLaunchMode_007795EC == 1 || gnLaunchMode_007795EC == 3)
    {
        if (!gpFuncTable_0077ABF0->pfnSlot68())
        {
            CHARSEL_CreateBaseScreen();
            if (!sub_0043BF60())
                return 0;
            if (!sub_0043C180_Connect(gpLaunchRecord_007795D4, 0, 0))
                return 0;
        }
    }

    if (gnLaunchMode_007795EC == 0)
    {
        gpLaunchRecord_007795D4->nByte35E = 1;
        gnLaunchState_007795E8 = 1;
        gpLaunchRecord_007795D4->nState19 = 0;
        gpLaunchRecord_007795D4->dwFlags209 = 4;
        if (wFlags & 4)
            gpLaunchRecord_007795D4->dwFlags209 = 0x804;
        if (gpLaunchRecord_007795D4->wFlags1EF & 0x20)
            gpLaunchRecord_007795D4->dwFlags209 |= 0x100000;
        D2Win_StopMessageLoop();
        return 1;
    }

    if (gnLaunchMode_007795EC == 2)
    {
        gpLaunchRecord_007795D4->nByte35E = 3;
        gnLaunchState_007795E8 = 1;
        gpLaunchRecord_007795D4->dwFlags209 = 4;
        if (wFlags & 4)
            gpLaunchRecord_007795D4->dwFlags209 = 0x804;
        if (gpLaunchRecord_007795D4->wFlags1EF & 0x20)
            gpLaunchRecord_007795D4->dwFlags209 |= 0x100000;
        D2Win_StopMessageLoop();
        return 1;
    }
    {
        int bNewGame;
        if (bPassword)
        {
            switch (MAINMENUS_ConnectToRealm(szPassword, 0))
            {
            case 1:
                return 0;
            case 2:
            {
                const Unicode* pText = D2LANG_GetStringFromTblIndex(0x145B);
                MAINMENUS_ShowMessage(pText, MAINMENUS_ReturnToCharSelect, 1);
                return 1;
            }
            }

            if (GAME_GetConnectError())
            {
                D2MCPClientCloseMCP();
                int nString;
                switch (GAME_GetConnectError())
                {
                case 2:
                    nString = 0x145B;
                    break;
                case 0x47:
                    nString = 0x145C;
                    break;
                default:
                    nString = 0x145B;
                    break;
                }
                const Unicode* pText = D2LANG_GetStringFromTblIndex(nString);
                MAINMENUS_ShowMessage(pText, MAINMENUS_ReturnToCharSelect, 1);
                return 1;
            }

            CHATDLG_RequestCharLogon(gpLaunchRecord_007795D4->szGameName);
            MAINMENUS_ShowConnectingPopup();
            sub_004FA590_RunLoop(MAINMENUS_PollCharLogon);
            int nState = GAME_GetConnectError();
            if (nState == 0x46 || !sub_00449B30_QueryAddress())
            {
                MAINMENUS_DestroyControls();
                const Unicode* pText = D2LANG_GetStringFromTblIndex(0x140D);
                MAINMENUS_ShowMessage(pText, MAINMENUS_ReturnToCharSelect, 1);
                return 0;
            }

            if (nState == 0x7B)
            {
                Unicode wszText[256];
                Unicode wszName[256];
                sub_00526F20_ToUnicode(wszName, gpLaunchRecord_007795D4->szGameName, 256);
                D2MCPClientCloseMCP();
                sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0x2B89), wszName);
                MAINMENUS_DestroyControls();
                void* pSaved = gpGlobal_0070B738;
                gpGlobal_0070B738 = gaGlobal_007089C4;
                MAINMENUS_ShowMessage(wszText, MAINMENUS_ReturnToCharSelect, 1);
                gpGlobal_0070B738 = pSaved;
                return 0;
            }

            if (gdwGlobal_00779974)
            {
                MAINMENUS_DestroyControls();
                return 0;
            }

            bNewGame = 0;
        }
        else
        {
            gpLaunchRecord_007795D4->nByte22D = 0;
            gpLaunchRecord_007795D4->szGamePassword[0] = 0;
            bNewGame = 1;
        }

        if (!bNewGame)
        {
            gpLaunchRecord_007795D4->nByte35E = 2;
        }
        else
        {
            gpLaunchRecord_007795D4->nByte35E = 4;
            gpLaunchRecord_007795D4->dwFlags209 = 4;
            if (wFlags & 4)
                gpLaunchRecord_007795D4->dwFlags209 = 0x804;
            if (gpLaunchRecord_007795D4->wFlags1EF & 0x20)
                gpLaunchRecord_007795D4->dwFlags209 |= 0x100000;
        }

        gnLaunchState_007795E8 = 3;
        MAINMENUS_ShowConnectingPopup();
        sub_004FA590_RunLoop(MAINMENUS_StopLoop);
        D2Win_StopMessageLoop();
        return 1;
    }
}

#include "gen/data/Source/D2Launch/Src/MainMenus_0042F2E0.inc"
