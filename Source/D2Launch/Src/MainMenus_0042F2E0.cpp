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

extern int gbConnectResult;                                                                            // 0x0077959C

D2LaunchRecordStrc* gpLaunchRecord; // 0x007795D4

int gbFeCharPalette; // 0x007795F0

extern char gszLastTcpIpAddress[];                                                                          // 0x007795F8

extern D2WinControlStrc* gpAddressEdit;                                                            // 0x00779958

extern int gbPaletteBusy;                                                                          // 0x00779970

int gbFlag_00779984; // 0x00779984

extern int gdwGlobal_00779974;                                                                              // 0x00779974

D2WinControlStrc* gpStatusText; // 0x007799A8

D2WinControlStrc* gpCounterText; // 0x007799AC

int gnStatusStringId; // 0x007799B0

unsigned long gdwStatusStart; // 0x007799B8

D2CelFileStrc* gpBlizNoCelFile;                                                                        // 0x007796F8

D2CelFileStrc* gpTrademarkCelFile;                                                                        // 0x007796FC

D2CelFileStrc* gpDiablo2LogoCelFile;                                                                        // 0x00779704

D2CelFileStrc* gpD2LogoBlackLeftCelFile;                                                                        // 0x00779708

D2CelFileStrc* gpD2LogoFireLeftCelFile;                                                                        // 0x0077970C

D2CelFileStrc* gpD2LogoBlackRightCelFile;                                                                        // 0x00779710

D2CelFileStrc* gpD2LogoFireRightCelFile;                                                                        // 0x00779714

D2CelFileStrc* gpTitleScreenCelFile;                                                                        // 0x00779718

D2CelFileStrc* gpCursorOHandCelFile;                                                                        // 0x0077971C

D2CelFileStrc* gpCreditsBckgCelFile;                                                                        // 0x00779720

D2CelFileStrc* gpRealmSelectButtonCelFile;                                                                        // 0x0077972C

D2CelFileStrc* gpTallButtonBlankCelFile;                                                                        // 0x00779730

D2CelFileStrc* gpCharacterSelectScreenExpCelFile;                                                                        // 0x00779734

D2CelFileStrc* gpWideButtonBlankCelFile;                                                                        // 0x00779738

D2CelFileStrc* gpMediumButtonBlankCelFile;                                                                        // 0x0077973C

D2CelFileStrc* gpShortButtonBlankCelFile;                                                                        // 0x00779740

D2CelFileStrc* gpTextBox2CelFile;                                                                        // 0x00779748

D2CelFileStrc* gp3WideButtonBlankCelFile;                                                                        // 0x0077974C

D2CelFileStrc* gpEditTextBoxWideCelFile;                                                                        // 0x00779750

D2CelFileStrc* gpWideButtonBlank02CelFile;                                                                        // 0x00779754

D2CelFileStrc* gpNarrowButtonBlankCelFile;                                                                        // 0x00779758

D2CelFileStrc* gpGWListBoxCelFile;                                                                        // 0x0077975C

D2CelFileStrc* gpTermsOfUseBckgCelFile;                                                                        // 0x00779764

D2CelFileStrc* gpCharSelectBckgCelFile;                                                                        // 0x00779768

D2CelFileStrc* gpDifficultyLevelsCelFile;                                                                        // 0x0077976C

D2CelFileStrc* gpCinematicsSelectionCelFile;                                                                        // 0x00779770

D2CelFileStrc* gpCinematicsSelectionExpCelFile;                                                                        // 0x00779774

D2CelFileStrc* gpCharSelectBoxCelFile;                                                                        // 0x00779778

D2CelFileStrc* gpCharSelectBoxGreyCelFile;                                                                        // 0x0077977C

D2CelFileStrc* gpPopUpOkCancelCelFile;                                                                        // 0x00779780

D2CelFileStrc* gpPopUpOkCancel2CelFile;                                                                        // 0x00779784

D2CelFileStrc* gpSelectCharArrowsCelFile;                                                                        // 0x00779788

D2CelFileStrc* gpRealmSelectCelFile;                                                                        // 0x0077978C

D2CelFileStrc* gpRealmSelectButtonThinCelFile;                                                                        // 0x00779790

D2CelFileStrc* gpCreateNewCharImageCelFile;                                                                        // 0x00779794

D2CelFileStrc* gpPopUpOkCelFile;                                                                        // 0x00779798

D2CelFileStrc* gpPopUp340x224CelFile;                                                                        // 0x0077979C

D2CelFileStrc* gpPopUpWideCelFile;                                                                        // 0x007797A0

D2CelFileStrc* gpPopUpLargestCelFile;                                                                        // 0x007797A4

D2CelFileStrc* gpTileableDialogCelFile;                                                                        // 0x007797A8

D2CelFileStrc* gpPopUpOk2CelFile;                                                                        // 0x007797AC

D2CelFileStrc* gpOkCancelButtonBlankCelFile;                                                                        // 0x007797B0

D2CelFileStrc* gpCancelButtonBlankCelFile;                                                                        // 0x007797B4

D2CelFileStrc* gpPasswordCelFile;                                                                        // 0x007797B8

D2CelFileStrc* gpRealmBckgCelFile;                                                                        // 0x007797C8

D2CelFileStrc* gpJoinGameScrollBarsCelFile;                                                                        // 0x007797CC

D2CelFileStrc* gpTcpIpBckgCelFile;                                                                        // 0x007797D0

D2CelFileStrc* gpIPAddressBoxCelFile;                                                                        // 0x007797D4

D2CelFileStrc* gpDownloadPatchBckgCelFile;                                                                        // 0x007797D8

D2CelFileStrc* gpDownloadPatchBall2CelFile;                                                                        // 0x007797DC

extern D2CelFileStrc* gpCharacterCreateCelFile;                                                                 // 0x00779724

extern D2CelFileStrc* gpFireCelFile;                                                                 // 0x00779728

extern D2CelFileStrc* gpMediumSelButtonBlankCelFile;                                                                 // 0x00779744

extern D2CelFileStrc* gpTextBoxCelFile;                                                                 // 0x007797BC

extern D2CelFileStrc* gpClickBoxCelFile;                                                                 // 0x007797C0

extern D2CelFileStrc* gpJoinGameClickBoxGreyCelFile;                                                                 // 0x007797C4

D2CelFileStrc* gapAssassinCelFiles;                                                                        // 0x007797E0

D2CelFileStrc* gpAsNu2CelFile; // 0x007797E4

D2CelFileStrc* gpAsFwCelFile; // 0x007797E8

D2CelFileStrc* gpAsNu3CelFile; // 0x007797EC

D2CelFileStrc* gpAsBwCelFile; // 0x007797F0

D2CelFileStrc* gapDruidCelFiles;                                                                        // 0x007797F4

D2CelFileStrc* gpDzNu2CelFile; // 0x007797F8

D2CelFileStrc* gpDzFwCelFile; // 0x007797FC

D2CelFileStrc* gpDzNu3CelFile; // 0x00779800

D2CelFileStrc* gpDzBwCelFile; // 0x00779804

D2CelFileStrc* gapAmazonCelFiles;                                                                        // 0x00779808

D2CelFileStrc* gpAmNu2CelFile; // 0x0077980C

D2CelFileStrc* gpAmFwCelFile; // 0x00779810

D2CelFileStrc* gpAmNu3CelFile; // 0x00779814

D2CelFileStrc* gpAmBwCelFile; // 0x00779818

D2CelFileStrc* gapNecromancerCelFiles;                                                                        // 0x0077981C

D2CelFileStrc* gpNeNu2CelFile; // 0x00779820

D2CelFileStrc* gpNeFwCelFile; // 0x00779824

D2CelFileStrc* gpNeNu3CelFile; // 0x00779828

D2CelFileStrc* gpNeBwCelFile; // 0x0077982C

D2CelFileStrc* gapBarbarianCelFiles;                                                                        // 0x00779830

D2CelFileStrc* gpBaNu2CelFile; // 0x00779834

D2CelFileStrc* gpBaFwCelFile; // 0x00779838

D2CelFileStrc* gpBaNu3CelFile; // 0x0077983C

D2CelFileStrc* gpBaBwCelFile; // 0x00779840

D2CelFileStrc* gapSorceressCelFiles;                                                                        // 0x00779844

D2CelFileStrc* gpSoNu2CelFile; // 0x00779848

D2CelFileStrc* gpSoFwCelFile; // 0x0077984C

D2CelFileStrc* gpSoNu3CelFile; // 0x00779850

D2CelFileStrc* gpSoBwCelFile; // 0x00779854

D2CelFileStrc* gapPaladinCelFiles;                                                                        // 0x00779858

D2CelFileStrc* gpPaNu2CelFile; // 0x0077985C

D2CelFileStrc* gpPaFwCelFile; // 0x00779860

D2CelFileStrc* gpPaNu3CelFile; // 0x00779864

D2CelFileStrc* gpPaBwCelFile; // 0x00779868

D2CelFileStrc* gapNecromancerSCelFiles;                                                                        // 0x00779888

D2CelFileStrc* gpNeNu3SCelFile; // 0x0077988C

D2CelFileStrc* gpNeBwSCelFile; // 0x00779890

D2CelFileStrc* gapSorceressSCelFiles;                                                                        // 0x0077989C

D2CelFileStrc* gpSoNu3SCelFile; // 0x007798A0

D2CelFileStrc* gpSoBwSCelFile; // 0x007798A4

extern D2CelFileStrc* gpBaFwSCelFile;                                                                 // 0x007798B0

extern D2CelFileStrc* gpPaFwSCelFile;                                                                 // 0x007798C4

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

extern "C" const char gszMainMenusFile[]; // 0x006D41C0

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

extern "C" const char gszDiabloII[]; // 0x006CC8B8

extern "C" const char gszDottedQuadFormat[]; // 0x006CDEA4

extern "C" const char gszAuxBattleNet[]; // 0x006D4164

extern "C" const char gszLastTcpIp[]; // 0x006D4224

extern "C" const char gszDottedQuadLongFormat[]; // 0x006D4174

extern "C" const char gszEng[]; // 0x006D41A4

extern "C" const char gszAuxAddressFormat[]; // 0x006D4868

extern "C" const char gszIntroFormatEng[]; // 0x006D4878

extern "C" const char gszIntroFormat[]; // 0x006D4894

extern "C" const char gszVersionSuffix[]; // 0x006D48D0

extern "C" const char gszVersionFormat[]; // 0x006D48D4

extern "C" const char gszDotsFormat[]; // 0x006D4D9C

extern "C" const char gszDots[]; // 0x006D4DA4

extern "C" const char gszBlizNoCelPath[]; // 0x006D4100

extern "C" const char gszTrademarkScreenExpCelPath[]; // 0x006D40DC

extern "C" const char gszTrademarkCelPath[]; // 0x006D40C0

extern "C" const char gszCursorOHandCelPath[]; // 0x006D40AC

extern "C" const char gszDiablo2LogoCelPath[]; // 0x006D4094

extern "C" const char gszD2LogoBlackLeftCelPath[]; // 0x006D4074

extern "C" const char gszD2LogoFireLeftCelPath[]; // 0x006D4054

extern "C" const char gszD2LogoBlackRightCelPath[]; // 0x006D4034

extern "C" const char gszD2LogoFireRightCelPath[]; // 0x006D4014

extern "C" const char gszGameSelectScreenExpCelPath[]; // 0x006D3FF0

extern "C" const char gszTitleScreenCelPath[]; // 0x006D3FD4

extern "C" const char gszCreditsBckgExpandCelPath[]; // 0x006D3FB0

extern "C" const char gszCreditsBckgCelPath[]; // 0x006D3F90

extern "C" const char gszWideButtonBlankCelPath[]; // 0x006D3F70

extern "C" const char gszWideButtonBlank02CelPath[]; // 0x006D3F4C

extern "C" const char gszNarrowButtonBlankCelPath[]; // 0x006D3F28

extern "C" const char gszGWListBoxCelPath[]; // 0x006D3F0C

extern "C" const char gszRealmSelectButtonCelPath[]; // 0x006D3EE8

extern "C" const char gszTallButtonBlankCelPath[]; // 0x006D3EC4

extern "C" const char gszCharacterSelectScreenExpCelPath[]; // 0x006D3E98

extern "C" const char gszCinematicsSelectionExpCelPath[]; // 0x006D3E70

extern "C" const char gszMediumButtonBlankCelPath[]; // 0x006D3E4C

extern "C" const char gszShortButtonBlankCelPath[]; // 0x006D3E28

extern "C" const char gszTextBox2CelPath[]; // 0x006D3E10

extern "C" const char gsz3WideButtonBlankCelPath[]; // 0x006D3DF0

extern "C" const char gszTermsOfUseBckgCelPath[]; // 0x006D3DD0

extern "C" const char gszCharSelectBckgCelPath[]; // 0x006D3DB0

extern "C" const char gszDifficultyLevelsCelPath[]; // 0x006D3D8C

extern "C" const char gszCinematicsSelectionCelPath[]; // 0x006D3D68

extern "C" const char gszCharSelectBoxCelPath[]; // 0x006D3D48

extern "C" const char gszCharSelectBoxGreyCelPath[]; // 0x006D3D24

extern "C" const char gszCreateNewCharImageCelPath[]; // 0x006D3D00

extern "C" const char gszPopUpOkCelPath[]; // 0x006D3CE8

extern "C" const char gszPopUp340x224CelPath[]; // 0x006D3CC8

extern "C" const char gszPopUpWideCelPath[]; // 0x006D3CAC

extern "C" const char gszPopUpLargestCelPath[]; // 0x006D3C90

extern "C" const char gszTileableDialogCelPath[]; // 0x006D3C70

extern "C" const char gszPopUpOk2CelPath[]; // 0x006D3C58

extern "C" const char gszPopUpOkCancelCelPath[]; // 0x006D3C38

extern "C" const char gszPopUpOkCancel2CelPath[]; // 0x006D3C18

extern "C" const char gszOkCancelButtonBlankCelPath[]; // 0x006D3BF4

extern "C" const char gszCancelButtonBlankCelPath[]; // 0x006D3BD0

extern "C" const char gszSelectCharArrowsCelPath[]; // 0x006D3BAC

extern "C" const char gszRealmSelectCelPath[]; // 0x006D3B8C

extern "C" const char gszCurRealmCelPath[]; // 0x006D3B74

extern "C" const char gszRealmSelectButtonThinCelPath[]; // 0x006D3B4C

extern "C" const char gszNarrowButtonBlank02CelPath[]; // 0x006D3B28

extern "C" const char gszPasswordCelPath[]; // 0x006D3B0C

extern "C" const char gszRealmBckgCelPath[]; // 0x006D3AF0

extern "C" const char gszJoinGameScrollBarsCelPath[]; // 0x006D3ACC

extern "C" const char gszTcpIpScreenCelPath[]; // 0x006D3AB0

extern "C" const char gszTcpIpBckgCelPath[]; // 0x006D3A94

extern "C" const char gszIPAddressBoxCelPath[]; // 0x006D3A78

extern "C" const char gszDownloadPatchBckgCelPath[]; // 0x006D3A54

extern "C" const char gszDownloadPatchBall2CelPath[]; // 0x006D3A30

extern "C" const char gszEditTextBoxWideCelPath[]; // 0x006D3A10

extern "C" const char gszMediumSelButtonBlankCelPath[]; // 0x006D4844

extern "C" const char gszCharacterCreationScreenExpCelPath[]; // 0x006D4818

extern "C" const char gszCharacterCreateCelPath[]; // 0x006D47F8

extern "C" const char gszFireCelPath[]; // 0x006D47E4

extern "C" const char gszTextBoxCelPath[]; // 0x006D47CC

extern "C" const char gszClickBoxCelPath[]; // 0x006D47B4

extern "C" const char gszJoinGameClickBoxGreyCelPath[]; // 0x006D4790

extern "C" const char gszAsNu1CelPath[]; // 0x006D4770

extern "C" const char gszAsNu2CelPath[]; // 0x006D4750

extern "C" const char gszAsFwCelPath[]; // 0x006D4730

extern "C" const char gszAsNu3CelPath[]; // 0x006D4710

extern "C" const char gszAsBwCelPath[]; // 0x006D46F0

extern "C" const char gszDzNu1CelPath[]; // 0x006D46D4

extern "C" const char gszDzNu2CelPath[]; // 0x006D46B8

extern "C" const char gszDzFwCelPath[]; // 0x006D469C

extern "C" const char gszDzNu3CelPath[]; // 0x006D4680

extern "C" const char gszDzBwCelPath[]; // 0x006D4664

extern "C" const char gszAmNu1CelPath[]; // 0x006D4648

extern "C" const char gszAmNu2CelPath[]; // 0x006D462C

extern "C" const char gszAmFwCelPath[]; // 0x006D4610

extern "C" const char gszAmNu3CelPath[]; // 0x006D45F4

extern "C" const char gszAmBwCelPath[]; // 0x006D45D8

extern "C" const char gszNeNu1CelPath[]; // 0x006D45B4

extern "C" const char gszNeNu2CelPath[]; // 0x006D4590

extern "C" const char gszNeFwCelPath[]; // 0x006D4570

extern "C" const char gszNeNu3CelPath[]; // 0x006D454C

extern "C" const char gszNeBwCelPath[]; // 0x006D452C

extern "C" const char gszBaNu1CelPath[]; // 0x006D450C

extern "C" const char gszBaNu2CelPath[]; // 0x006D44EC

extern "C" const char gszBaFwCelPath[]; // 0x006D44CC

extern "C" const char gszBaNu3CelPath[]; // 0x006D44AC

extern "C" const char gszBaBwCelPath[]; // 0x006D448C

extern "C" const char gszSoNu1CelPath[]; // 0x006D446C

extern "C" const char gszSoNu2CelPath[]; // 0x006D444C

extern "C" const char gszSoFwCelPath[]; // 0x006D442C

extern "C" const char gszSoNu3CelPath[]; // 0x006D440C

extern "C" const char gszSoBwCelPath[]; // 0x006D43EC

extern "C" const char gszPaNu1CelPath[]; // 0x006D43CC

extern "C" const char gszPaNu2CelPath[]; // 0x006D43AC

extern "C" const char gszPaFwCelPath[]; // 0x006D4390

extern "C" const char gszPaNu3CelPath[]; // 0x006D4370

extern "C" const char gszPaBwCelPath[]; // 0x006D4354

extern "C" const char gszSoFwSCelPath[]; // 0x006D4334

extern "C" const char gszSoNu3SCelPath[]; // 0x006D4314

extern "C" const char gszSoBwSCelPath[]; // 0x006D42F4

extern "C" const char gszNeFwSCelPath[]; // 0x006D42D0

extern "C" const char gszNeNu3SCelPath[]; // 0x006D42AC

extern "C" const char gszNeBwSCelPath[]; // 0x006D4288

extern "C" const char gszBaFwSCelPath[]; // 0x006D4268

extern "C" const char gszPaFwSCelPath[]; // 0x006D4248

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

extern D2MenuListStrc* gpMenuList; // 0x007795C0

extern int gnSlotCount; // 0x0077998C

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

extern int gnLaunchState; // 0x007795E8

extern int gnLaunchMode; // 0x007795EC

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

extern D2WinControlStrc* gpOkButton; // 0x00779330

extern D2WinControlStrc* gpControl_00779348; // 0x00779348

extern D2WinControlStrc* gpControl_00779568; // 0x00779568

extern D2WinControlStrc* gpControl_00779598; // 0x00779598

extern D2WinControlStrc* gpControl_007795B4; // 0x007795B4

extern D2WinControlStrc* gpControl_007795C8; // 0x007795C8

extern D2WinControlStrc* gpControl_007795D8; // 0x007795D8

extern D2WinControlStrc* gpControl_007795DC; // 0x007795DC

const Unicode* __fastcall D2Win_10077_EDITBOX_GetText(D2WinControlStrc*); // 0x004FDD90

extern D2WinControlStrc* gpControl_007799D4; // 0x007799D4

static D2LaunchSlotStrc** gppSlots; // 0x00779988

D2WinControlStrc* gpPasswordEdit; // 0x00779334

D2WinControlStrc* gpAccountEdit; // 0x0077958C

D2WinControlStrc* gpControl_00779594; // 0x00779594

static int s_bGatewayFlag_00779954; // 0x00779954

D2WinControlStrc* gpControl_0077933C; // 0x0077933C

D2WinControlStrc* gpNameEdit; // 0x0077934C

D2WinControlStrc* gapClassImages; // 0x0077956C

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

extern D2LaunchControlTemplateStrc gatControlTemplates[]; // 0x00708D10

extern D2WinControlStrc* gpCreatePasswordEdit; // 0x00779340

extern D2LaunchDoneFn gpfnGatewayDone; // 0x007795BC

extern int gbConnectCancelled; // 0x007795F4

char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0

int __fastcall sub_005264F0_Compare(const Unicode* pString1, const Unicode* pString2); // 0x005264F0

void __fastcall MAINMENUS_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540

extern D2WinControlStrc* gpPasswordOk; // 0x007799A4

extern D2WinControlStrc* gpEdit_007799DC; // 0x007799DC

extern D2WinControlStrc* gpEdit_007799E0; // 0x007799E0

extern D2WinControlStrc* gpButton_007799E4; // 0x007799E4

D2WinControlStrc* gapControlsA[0x40]; // 0x00779450

int gnControlCountA; // 0x00779948

extern "C" const unsigned char gabDefault[]; // 0x006D4D88

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
    gpBlizNoCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\trademarkscreenEXP", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\trademark", gszDataGlobal);
    gpTrademarkCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\CURSOR\\ohand", gszDataGlobal);
    gpCursorOHandCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\Diablo2", gszDataGlobal);
    gpDiablo2LogoCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoBlackLeft", gszDataGlobal);
    gpD2LogoBlackLeftCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoFireLeft", gszDataGlobal);
    gpD2LogoFireLeftCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoBlackRight", gszDataGlobal);
    gpD2LogoBlackRightCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoFireRight", gszDataGlobal);
    gpD2LogoFireRightCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\gameselectscreenEXP", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\TitleScreen", gszDataGlobal);
    gpTitleScreenCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\creditsbckgexpand", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\CharSelect\\creditsbckg", gszDataGlobal);
    gpCreditsBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\WideButtonBlank", gszDataGlobal);
    gpWideButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\WideButtonBlank02", gszDataGlobal);
    gpWideButtonBlank02CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\NarrowButtonBlank", gszDataGlobal);
    gpNarrowButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\GWListBox", gszDataGlobal);
    gpGWListBoxCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
    {
        wsprintfA(szPath, "%s\\ui\\CharSelect\\Realmselectbutton", gszDataGlobal);
        gpRealmSelectButtonCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\CharSelect\\TallButtonBlank", gszDataGlobal);
        gpTallButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\CharSelect\\characterselectscreenEXP", gszDataGlobal);
        gpCharacterSelectScreenExpCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CinematicsSelectionEXP", gszDataGlobal);
        gpCinematicsSelectionExpCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    }
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\MediumButtonBlank", gszDataGlobal);
    gpMediumButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\ShortButtonBlank", gszDataGlobal);
    gpShortButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\textbox2", gszDataGlobal);
    gpTextBox2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\3WideButtonBlank", gszDataGlobal);
    gp3WideButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\TermsofUseBckg", gszDataGlobal);
    gpTermsOfUseBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectbckg", gszDataGlobal);
    gpCharSelectBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\DifficultyLevels", gszDataGlobal);
    gpDifficultyLevelsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\CinematicsSelection", gszDataGlobal);
    gpCinematicsSelectionCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectbox", gszDataGlobal);
    gpCharSelectBoxCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectboxgrey", gszDataGlobal);
    gpCharSelectBoxGreyCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\CreateNewCharImage", gszDataGlobal);
    gpCreateNewCharImageCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOK", gszDataGlobal);
    gpPopUpOkCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUp_340x224", gszDataGlobal);
    gpPopUp340x224CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpWide", gszDataGlobal);
    gpPopUpWideCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpLargest", gszDataGlobal);
    gpPopUpLargestCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\TileableDialog", gszDataGlobal);
    gpTileableDialogCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOK2", gszDataGlobal);
    gpPopUpOk2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOKCancel", gszDataGlobal);
    gpPopUpOkCancelCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOKCancel2", gszDataGlobal);
    gpPopUpOkCancel2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\OkCancelButtonBlank", gszDataGlobal);
    gpOkCancelButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\CancelButtonBlank", gszDataGlobal);
    gpCancelButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\selectchararrows", gszDataGlobal);
    gpSelectCharArrowsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\Realmselect", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CurRealm", gszDataGlobal);
    gpRealmSelectCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\RealmSelectbuttonthin", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\NarrowButtonBlank02", gszDataGlobal);
    gpRealmSelectButtonThinCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\password", gszDataGlobal);
    gpPasswordCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\realmbckg", gszDataGlobal);
    gpRealmBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\FRONTEND\\joingamescrollbars", gszDataGlobal);
    gpJoinGameScrollBarsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\tcpipscreen", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\tcpipbckg", gszDataGlobal);
    gpTcpIpBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\IPAddressBox", gszDataGlobal);
    gpIPAddressBoxCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\downloadpatchbckg", gszDataGlobal);
    gpDownloadPatchBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\downloadpatchball2", gszDataGlobal);
    gpDownloadPatchBall2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\EditTextBoxWide", gszDataGlobal);
    gpEditTextBoxWideCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
}

// 0x0042F2E0
int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2)
{
    char szPathA[0x104];
    char szPathB[0x104];
    gbPaletteBusy = 1;
    wsprintfA(szPathA, gszPathFormat_006D4124, gszDataGlobal, szFile1);
    wsprintfA(szPathB, gszPathFormat_006D4124, gszDataGlobal, szFile2);
    gbFeCharPalette = strcmp(szFile1, "palette\\fechar\\pal.dat") == 0;
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
// build: symbol ?gszSaveMask@* 0x006D41D4
    sprintf(szPattern, gszSaveMask, szDir);
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
    char* pBuffer = (char*)FOG_Alloc(nSize, gszMainMenusFile, 0x138B, 0);
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
        pText = (Unicode*)FOG_Alloc(sizeof(Unicode) * nLength, gszMainMenusFile, 0x13B8, 0);
        memcpy(pText, pBuffer + 2, sizeof(Unicode) * *pnLength);
    }
    else if (*(unsigned short*)pBuffer == 0xFFFE)
    {
        const int nLength = (nSize - 2) / 2;
        *pnLength = nLength;
        pText = (Unicode*)FOG_Alloc(sizeof(Unicode) * nLength, gszMainMenusFile, 0x13BF, 0);
        memcpy(pText, pBuffer + 2, sizeof(Unicode) * *pnLength);
        sub_0042E5D0_SwapUnicodeBytes(pText, *pnLength);
    }
    else
    {
        *pnLength = nSize;
        pText = (Unicode*)FOG_Alloc(sizeof(Unicode) * nSize + 1, gszMainMenusFile, 0x13C8, 0);
        sub_00526F20_ToUnicode(pText, pBuffer, nSize);
    }

    FOG_Free(pBuffer, gszMainMenusFile, 0x13CC, 0);

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
// build: symbol ?gszStringFormat@* 0x006FFC58
    sprintf(szName, gszStringFormat, szUtf8);
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
    gpLaunchRecord->wFlags1EF = 0;
    sub_0042F2E0_ReadPaletteFiles(gszFecharPalDat_006D39E8, "palette\\fechar\\pal.pl2");

    MAINMENUS_CreateControl(0xB1);
    gpControl_007795D8 = MAINMENUS_CreateControl(0xC5);
    gpControl_007795DC = MAINMENUS_CreateControl(0xC6);
    D2WinControlStrc* pTitle = MAINMENUS_CreateControl(0xAE);
    sub_004FC9B0_SetText(pTitle, D2LANG_GetStringFromTblIndex(0x1407), 0, 0, 0);

    if (gnLaunchMode == 1)
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
    gpNameEdit = MAINMENUS_CreateControl(0xCC);
    sub_004FDD50_SetMaxLength(gpNameEdit, 0x10);
    sub_004FDAD0_SetKeyCallback(gpNameEdit, COMCALLBACK_FilterNameChar);
    sub_004FDB00_SetEnterCallback(gpNameEdit, MAINMENUS_OnNameChanged);

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
        if (gnLaunchMode == 1)
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
        if (gnLaunchMode == 1)
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

    if (gnLaunchMode == 1)
    {
        sub_004FC9B0_SetText(gpControl_007795B8, D2LANG_GetStringFromTblIndex(0x2AAF), 4, 0, 0);
    }

    gpOkButton = MAINMENUS_CreateControl(0xB0);
    if (!gnGlobal_00779DA4)
    {
        CONTROL_SetEnabled(gpControl_007795C4, 0);
        CONTROL_SetEnabled(gpControl_007795B0, 0);
    }

    sub_004F9740_SetControlState(gpControl_00779598, 0);
    sub_004F9740_SetControlState(gpControl_007795CC, 0);
    sub_004F9740_SetControlState(gpControl_007795B0, 0);
    sub_004F9740_SetControlState(gpControl_007795C4, 0);
    sub_004F9740_SetControlState(gpNameEdit, 0);
    sub_004F9740_SetControlState(gpOkButton, 0);
    if (gnLaunchMode == 1)
    {
        sub_004F9740_SetControlState(gpControl_007795B8, 0);
        sub_004F9740_SetControlState(gpControl_00779348, 0);
    }

    gapClassImages = MAINMENUS_CreateControl(0xB6);
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
    if (gpCharacterCreateCelFile)
        return;
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\MediumSelButtonBlank", gszDataGlobal);
    gpMediumSelButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\charactercreationscreenEXP", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CharacterCreate", gszDataGlobal);
    gpCharacterCreateCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\fire", gszDataGlobal);
    gpFireCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\textbox", gszDataGlobal);
    gpTextBoxCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\clickbox", gszDataGlobal);
    gpClickBoxCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
    {
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\joingameclickboxgrey", gszDataGlobal);
        gpJoinGameClickBoxGreyCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu1", gszDataGlobal);
        gapAssassinCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu2", gszDataGlobal);
        gpAsNu2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asfw", gszDataGlobal);
        gpAsFwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu3", gszDataGlobal);
        gpAsNu3CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asbw", gszDataGlobal);
        gpAsBwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu1", gszDataGlobal);
        gapDruidCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu2", gszDataGlobal);
        gpDzNu2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dzfw", gszDataGlobal);
        gpDzFwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu3", gszDataGlobal);
        gpDzNu3CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dzbw", gszDataGlobal);
        gpDzBwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    }
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu1", gszDataGlobal);
    gapAmazonCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu2", gszDataGlobal);
    gpAmNu2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amfw", gszDataGlobal);
    gpAmFwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu3", gszDataGlobal);
    gpAmNu3CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\ambw", gszDataGlobal);
    gpAmBwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu1", gszDataGlobal);
    gapNecromancerCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu2", gszDataGlobal);
    gpNeNu2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nefw", gszDataGlobal);
    gpNeFwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu3", gszDataGlobal);
    gpNeNu3CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nebw", gszDataGlobal);
    gpNeBwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu1", gszDataGlobal);
    gapBarbarianCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu2", gszDataGlobal);
    gpBaNu2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\bafw", gszDataGlobal);
    gpBaFwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu3", gszDataGlobal);
    gpBaNu3CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\babw", gszDataGlobal);
    gpBaBwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu1", gszDataGlobal);
    gapSorceressCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu2", gszDataGlobal);
    gpSoNu2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sofw", gszDataGlobal);
    gpSoFwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu3", gszDataGlobal);
    gpSoNu3CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sobw", gszDataGlobal);
    gpSoBwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu1", gszDataGlobal);
    gapPaladinCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu2", gszDataGlobal);
    gpPaNu2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pafw", gszDataGlobal);
    gpPaFwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu3", gszDataGlobal);
    gpPaNu3CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pabw", gszDataGlobal);
    gpPaBwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sofws", gszDataGlobal);
    gapSorceressSCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu3s", gszDataGlobal);
    gpSoNu3SCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sobws", gszDataGlobal);
    gpSoBwSCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nefws", gszDataGlobal);
    gapNecromancerSCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu3s", gszDataGlobal);
    gpNeNu3SCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nebws", gszDataGlobal);
    gpNeBwSCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\bafws", gszDataGlobal);
    gpBaFwSCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pafws", gszDataGlobal);
    gpPaFwSCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
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
    D2_ASSERT(gppSlots, 4383);
    for (int i = 0; i < gnSlotCount; i++)
    {
        if (!gppSlots[i])
        {
            gppSlots[i] = (D2LaunchSlotStrc*)pEntry;
            return 1;
        }
    }
    return 0;
}

// build: symbol ?MAINMENUS_FreeSlots@* 0x00430A20
int __cdecl MAINMENUS_FreeSlots()
{
    if (!gppSlots)
        return 1;
    for (int i = 0; i < gnSlotCount; i++)
    {
        D2LaunchSlotStrc* pSlot = gppSlots[i];
        if (pSlot)
        {
            D2_ASSERT(pSlot->pData, 0x1139);
            sub_0040B3C0(pSlot->pData, gszMainMenusFile, 0x113A, 0);
            D2_ASSERT(gppSlots[i]->szName, 0x113B);
            sub_0040B3C0(gppSlots[i]->szName, gszMainMenusFile, 0x113C, 0);
            sub_0040B3C0(gppSlots[i], gszMainMenusFile, 0x113E, 0);
        }
    }
    sub_0040B3C0(gppSlots, gszMainMenusFile, 0x1141, 0);
    gppSlots = 0;
    return 1;
}

// 0x004336C0
void __cdecl MAINMENUS_ShowMainMenu()
{
    char szVersion[0x40];
    D2WinControlStrc* pFirst;
    D2WinControlStrc* pSecond;
    CHARSEL_DisconnectBattleNet();
    gpLaunchRecord->szName[0] = 0;
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
    if (gpLaunchRecord->bFlag223)
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
    gpLaunchRecord->nMode = nMode;
    gpLaunchRecord->nFlag085 = 0;
    gpLaunchRecord->nFlag089 = 0;
    gpLaunchRecord->nFlag088 = 0;
    gpLaunchRecord->nFlag086 = 0;
    gpLaunchRecord->nFlag087 = 0;
    gpLaunchRecord->nFlag08A = 0;
    gpLaunchRecord->nFlag08B = 0;

    if (nMode == 0)
    {
        gpLaunchRecord->nFlag085 = 1;
    }
    else if (nMode == 4)
    {
        gpLaunchRecord->nFlag089 = 1;
    }
    else if (nMode == 2)
    {
        gpLaunchRecord->nFlag088 = 1;
    }
    else if (nMode == 3)
    {
        gpLaunchRecord->nFlag086 = 1;
    }
    else if (nMode == 1)
    {
        gpLaunchRecord->nFlag087 = 1;
    }
    else if (nMode == 5)
    {
        gpLaunchRecord->nFlag08A = 1;
    }
    else if (nMode == 6)
    {
        gpLaunchRecord->nFlag08B = 1;
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
    const Unicode* pText = sub_004FDD90_GetEditText(gpAddressEdit);
    sub_005263E0(szText, pText, 0x100);
    if (!szText[0])
        return 1;
    strncpy(gszLastTcpIpAddress, szText, 0xFF);
    gszLastTcpIpAddress[0xFF] = 0;
    SRegSaveString("Diablo II", "LastTcpIp", 0, gszLastTcpIpAddress);
    if (sscanf(szText, "%d.%d.%d.%d", &a, &b, &c, &d) != 4)
    {
        const char* szResolved = FOG_ResolveHostIPAddress(szText);
        if (szResolved)
        {
            strcpy(szText, szResolved);
        }
        else
        {
            sub_004FFE10_SetTextA(gpAddressEdit, &gszEmptyAssertText);
            return 1;
        }
    }
    strcpy(gpLaunchRecord->szName, szText);
    MAINMENUS_ShowConnectingPopup();
    sub_004FA590_RunLoop(sub_00431D10);
    gbConnectResult = 0;
    sub_0052A750(0, szText);
    sub_004FA590_RunLoop(sub_00431E30);
    if (!gbConnectResult)
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
        gnLaunchMode = 2;
        *(int*)gpLaunchRecord->aState19 = 9;
        *(unsigned short*)gpLaunchRecord->aWord1D = 1;
        sub_00515020();
        MAINMENUS_Reset();
        CHARSEL_InitCharSelectScreen();
    }
    return 1;
}

// build: symbol ?MAINMENUS_CreateFromTemplate@* 0x0042F3A0
D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId)
{
    D2_ASSERT(gnControlCountA < 0x40, 0x610);
    D2WinControlStrc* pControl = CONTROL_Create(&gatControlTemplates[nTemplateId]);
    gapControlsA[gnControlCountA++] = pControl;
    return pControl;
}

void __cdecl MAINMENUS_DestroyControls()
{
    for (int i = 0; i < gnControlCountA; ++i)
        CONTROL_Destroy(&gapControlsA[i]);
    gnControlCountA = 0;
}

// build: symbol ?MAINMENUS_StoreAccountTexts@* 0x00432080
static void MAINMENUS_StoreAccountTexts(D2WinControlStrc* pAccountEdit, D2WinControlStrc* pPasswordEdit)
{
    if (pAccountEdit)
    {
        const Unicode* pText = sub_004FDD90_GetEditText(pAccountEdit);
        sub_00526F70(gpLaunchRecord->szAccount, pText, 0x100);
    }
    if (pPasswordEdit)
    {
        const Unicode* pText = sub_004FDD90_GetEditText(pPasswordEdit);
        sub_00526F70(gpLaunchRecord->szPassword, pText, 0x100);
        gpLaunchRecord->dwPasswordHash = SStrHashHT(gpLaunchRecord->szPassword);
        gpLaunchRecord->nPasswordLength = SStrLen(gpLaunchRecord->szPassword);
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
    if (gbFeCharPalette)
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
    gpfnGatewayDone = pfnDone;
}

// 0x00434E00
int __stdcall MAINMENUS_CheckFreeSpace(int nUnused)
{
    char szPath[0x400];
    MAINMENUS_StoreAccountTexts(gpAccountEdit, gpPasswordEdit);
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
    gpAccountEdit = 0;
    gpPasswordEdit = 0;
// build: symbol ?gpCreatePasswordConfirmEdit@* 0x007795A8
    gpCreatePasswordConfirmEdit = 0;
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
    gpAccountEdit = MAINMENUS_CreateControl(0x22);
    sub_004FDD50_SetMaxLength(gpAccountEdit, 0x10);
    sub_004FDB00_SetEnterCallback(gpAccountEdit, MAINMENUS_OnLoginChanged);
    sub_004FDAD0_SetKeyCallback(gpAccountEdit, sub_0042FDE0_KeyFilter);
    gpPasswordEdit = MAINMENUS_CreateControl(0x23);
    sub_004FDD50_SetMaxLength(gpPasswordEdit, 0xD);
    sub_004FDB00_SetEnterCallback(gpPasswordEdit, MAINMENUS_OnLoginChanged);
    sub_004FDAD0_SetKeyCallback(gpPasswordEdit, sub_0042FE60_KeyFilter);
    if (SRegLoadString("Diablo II", "Last BNet", 0, szAccount, 0x400))
    {
        D2Win_10076(gpAccountEdit, szAccount);
        CONTROL_SetFocusedEditBox(gpPasswordEdit);
    }
    else
        CONTROL_SetFocusedEditBox(gpAccountEdit);
    sub_004FDDD0_LinkTab(gpAccountEdit, gpPasswordEdit);
    sub_004FDDD0_LinkTab(gpPasswordEdit, gpAccountEdit);
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
            gpLaunchRecord->nByte3C1 = 1;
            SMemCopy(gpLaunchRecord->aData3A1, gabDefault, 0x10);
            SMemZero(gpLaunchRecord->aData3B1, 0x10);
            gpLaunchRecord->nByte3C2 = (gpLaunchRecord->wFlags1EF >> 6) & 1;
            gpLaunchRecord->wFlags3CB = gpLaunchRecord->wFlags1EF;
            CHATDLG_RequestCharCreate(gpLaunchRecord->szCharName, gpLaunchRecord->nClass, gpLaunchRecord->wFlags1EF);
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
                    sub_00410610_WriteLogLine("Error from MCP trying to create '%s' (err=%d)", gpLaunchRecord->szCharName, GAME_GetConnectError());
                    D2MCPClientCloseMCP();
                    Unicode wszText[255];
                    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x145E));
                    Unicode wszTail[255];
                    sub_005267E0(wszTail, D2LANG_GetStringFromTblIndex(0x145F));
                    char szName[80];
                    sprintf(szName, "%s", gpLaunchRecord->szCharName);
                    sub_00526320_ToUnicode(wszName, szName, 100);
                    sub_00526700(wszText, wszName);
                    sub_00526700(wszText, wszTail);
                    ShowText(wszText, sub_00435580);
                    return;
                }

                D2MCPClientCloseMCP();
                Unicode wszText[256];
                Unicode wszName[256];
                sub_00526F20_ToUnicode(wszName, gpLaunchRecord->szCharName, 256);
                sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0x2B33), wszName);
                ShowText(wszText, sub_00435580);
                return;
            }

            sub_0043C6A0(1);
            SStrCopy(gpLaunchRecord->szDataD5, sub_00437D00(), 0x7FFFFFFF);
            gpLaunchRecord->wFlags1EF |= 2;
            gpLaunchRecord->nByte35E = 2;
            gnLaunchState = 3;
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
    if (MAINMENUS_SaveExists() == 1 && gnLaunchMode != 1)
    {
        sub_00433460_ShowMessage(D2LANG_GetStringFromTblIndex(0x142D), MAINMENUS_DestroyControls);
        return;
    }
    if (gpLaunchRecord->nMode == 6 || gpLaunchRecord->nMode == 5)
        *(unsigned short*)gpLaunchRecord->aFlags1EF |= 0x20;
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit_0077934C);
    sub_005263E0(szName, pText, 0x100);
    sprintf((gpLaunchRecord->szPassword + 0x18), gszStringFormat, szName);
    gpLaunchRecord->szPassword[0x30] = 0;
    if (*(unsigned short*)gpLaunchRecord->aFlags1EF & 0x20)
        gbFlag_00779984 = 1;
    if (*(unsigned short*)gpLaunchRecord->aFlags1EF & 4)
    {
        sub_00430520();
        return;
    }
    if (gnLaunchMode == 0)
    {
        MAINMENUS_Reset();
        AUTOMAP_InitCharSaveHeader((gpLaunchRecord->szPassword + 0x18), gpLaunchRecord->nMode, (gpLaunchRecord->szPassword + 0x48), *(unsigned short*)gpLaunchRecord->aFlags1EF);
        sub_0043C6B0((gpLaunchRecord->szPassword + 0x18));
        gpLaunchRecord->nByte35E = 1;
        *(int*)gpLaunchRecord->aState19 = 0;
        gnLaunchState = 1;
        *(int*)gpLaunchRecord->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord->aFlags1EF & 4)
            *(int*)gpLaunchRecord->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord->aState209 |= 0x100000;
        D2Win_StopMessageLoop();
    }
    else if (gnLaunchMode == 2)
    {
        MAINMENUS_Reset();
        sub_0043C6A0(0);
        AUTOMAP_InitCharSaveHeader((gpLaunchRecord->szPassword + 0x18), gpLaunchRecord->nMode, (gpLaunchRecord->szPassword + 0x48), *(unsigned short*)gpLaunchRecord->aFlags1EF);
        sub_0043C6B0((gpLaunchRecord->szPassword + 0x18));
        gpLaunchRecord->nByte35E = 3;
        gnLaunchState = 1;
        *(int*)gpLaunchRecord->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord->aFlags1EF & 4)
            *(int*)gpLaunchRecord->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord->aState209 |= 0x100000;
        D2Win_StopMessageLoop();
    }
    else if (gnLaunchMode == 3)
    {
        MAINMENUS_Reset();
        D2MCPClientCloseMCP();
        sub_0043C6A0(0);
        AUTOMAP_InitCharSaveHeader((gpLaunchRecord->szPassword + 0x18), gpLaunchRecord->nMode, (gpLaunchRecord->szPassword + 0x48), *(unsigned short*)gpLaunchRecord->aFlags1EF);
        sub_0043C6B0((gpLaunchRecord->szPassword + 0x18));
        gpLaunchRecord->nByte3C1 = 1;
        SMemCopy(gpLaunchRecord->aData3A1, gabDefault, 0x10);
        SMemZero(gpLaunchRecord->aData3B1, 0x10);
        gpLaunchRecord->nByte3C2 = (*(unsigned short*)gpLaunchRecord->aFlags1EF >> 6) & 1;
        *(unsigned short*)gpLaunchRecord->aWord3CB = *(unsigned short*)gpLaunchRecord->aFlags1EF;
        gpLaunchRecord->nByte35E = 4;
        gpLaunchRecord->nByte22D = 0;
        gpLaunchRecord->szPassword[0x30] = 0;
        gnLaunchState = 3;
        *(int*)gpLaunchRecord->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord->aFlags1EF & 4)
            *(int*)gpLaunchRecord->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord->aState209 |= 0x100000;
        D2Win_StopMessageLoop();
    }
    else if (gnLaunchMode == 1)
    {
        MAINMENUS_CreateRealmCharacter();
    }
}

// 0x00436AD0
void __cdecl MAINMENUS_UpdateStatus()
{
    char szText[0x100];
    int nState;
    if (!gpStatusText)
        return;
    gpFuncTable_0077ABF0->pfnSlot80(&nState);
    switch (nState)
    {
    case 0:
        gnStatusStringId = 0x1433;
        break;
    case 1:
        gnStatusStringId = 0x1434;
        break;
    case 2:
        gnStatusStringId = 0x1435;
        break;
    case 3:
        gnStatusStringId = 0x1436;
        break;
    case 4:
        gnStatusStringId = 0x1437;
        break;
    case 5:
        gnStatusStringId = 0x1438;
        break;
    case 6:
        gnStatusStringId = 0x1439;
        break;
    default:
        gnStatusStringId = -1;
        break;
    }
    sub_004FB6A0_ClearText(gpStatusText);
    if (gnStatusStringId >= 0)
        sub_004FC9B0_SetText(gpStatusText, D2LANG_GetStringFromTblIndex(gnStatusStringId), 0, 0, 0);
    const unsigned long nCounter = (GetTickCount() - gdwStatusStart) / 250 % 20 + 1;
    sprintf(szText, "%.*s", nCounter, "....................");
    sub_004FB6A0_ClearText(gpCounterText);
    D2Win_10045(gpCounterText, szText);
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
    MAINMENUS_StoreAccountTexts(gpAccountEdit, gpCreatePasswordEdit);
    const Unicode* pAccount = sub_004FDD90_GetEditText(gpAccountEdit);
    const Unicode* pOldPassword = sub_004FDD90_GetEditText(gpPasswordEdit);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpCreatePasswordEdit);
    const Unicode* pConfirm = sub_004FDD90_GetEditText(gpCreatePasswordConfirmEdit);
// build: symbol ?gszOldPassword@* 0x00779550
    sub_00526F70(gszOldPassword, pOldPassword, 0x100);
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
    gbConnectCancelled = 0;
    if (!sub_0043C180_Connect(gpLaunchRecord, 0, 1))
    {
        if (gbConnectCancelled)
        {
            MAINMENUS_CreateLoginScreen();
            return 1;
        }
    }
    else
    {
        SRegSaveString("Diablo II", "Last BNet", 0, gpLaunchRecord->szAccount);
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
    MAINMENUS_StoreAccountTexts(gpAccountEdit, gpPasswordEdit);
    if (sub_0043C180_Connect(gpLaunchRecord, 0, 0))
    {
        SRegSaveString("Diablo II", "Last BNet", 0, gpLaunchRecord->szAccount);
        if (gnLaunchMode == 1)
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
    MAINMENUS_StoreAccountTexts(gpAccountEdit, gpPasswordEdit);
    const Unicode* pAccount = sub_004FDD90_GetEditText(gpAccountEdit);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpPasswordEdit);
    const Unicode* pConfirm = sub_004FDD90_GetEditText(gpCreatePasswordConfirmEdit);
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
// build: symbol ?gpChangePwAccountEdit@* 0x007799BC
    int bOk = sub_00526800(sub_004FDD90_GetEditText(gpChangePwAccountEdit)) > 2;
    if (bOk)
    {
// build: symbol ?gpOldPasswordEdit@* 0x007799C0
        const Unicode* pText1 = sub_004FDD90_GetEditText(gpOldPasswordEdit);
            sub_005263E0(szText1, pText1, 0x100);
        bOk = MAINMENUS_CheckAtAndDot(szText1);
        if (bOk)
        {
// build: symbol ?gpNewPasswordEdit@* 0x007799C8
            const Unicode* pText2 = sub_004FDD90_GetEditText(gpNewPasswordEdit);
            sub_005263E0(szText2, pText2, 0x100);
            bOk = MAINMENUS_CheckAtAndDot(szText2);
            if (bOk)
            {
// build: symbol ?gpNewPasswordConfirmEdit@* 0x007799C4
                const Unicode* pText3 = sub_004FDD90_GetEditText(gpNewPasswordConfirmEdit);
            sub_005263E0(szText3, pText3, 0x100);
                bOk = MAINMENUS_CheckAtAndDot(szText3);
            }
        }
    }
    CONTROL_SetEnabled(gpPasswordOk, bOk);
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
        gpMenuList = gpFuncTable_0077ABF0->pfnGetMenuList(0);
    MAINMENUS_DestroyControls();
    D2MenuListStrc* pList = gpMenuList;
    if (!pList)
    {
        gnSlotCount = -1;
        return;
    }
    gnSlotCount = pList->nCount;
    D2_ASSERT(gnSlotCount < 512, 4481);
    char* pText = (char*)(pList + 1);
    MAINMENUS_FreeSlots();
    int nCount = gnSlotCount;
    if (gnSlotCount)
    {
        const unsigned int nSize = gnSlotCount * sizeof(D2LaunchSlotStrc*);
        gppSlots = (D2LaunchSlotStrc**)FOG_Alloc(nSize, gszMainMenusFile, 4492, 0);
        memset(gppSlots, 0, nSize);
        for (int i = 0; i < nCount; ++i)
        {
            D2LaunchSlotStrc* pSlot = (D2LaunchSlotStrc*)FOG_Alloc(sizeof(D2LaunchSlotStrc), gszMainMenusFile, 4498, 0);
            pText += sizeof(int);
            unsigned int nLength = strlen(pText) + 1;
            pSlot->szName = (char*)FOG_Alloc(nLength, gszMainMenusFile, 4511, 0);
            SStrCopy(pSlot->szName, pText, nLength);
            pText += nLength;
            nLength = strlen(pText) + 1;
            pSlot->pData = FOG_Alloc(nLength, gszMainMenusFile, 4516, 0);
            SStrCopy((char*)pSlot->pData, pText, nLength);
            pText += nLength;
            CHARSEL_AddToSlots(pSlot);
        }
        qsort(gppSlots, gnSlotCount, sizeof(D2LaunchSlotStrc*), CHARSEL_CompareNames);
    }
}

// 0x00434A00
int __fastcall MAINMENUS_JoinGame(const char* szGameName, unsigned short wFlags, char nMode, const char* szPassword)
{
    int bPassword = szPassword[0] != 0;
    strcpy(gpLaunchRecord->szGameName, szGameName);
    strcpy(gpLaunchRecord->szGamePassword, szPassword);
    gpLaunchRecord->wFlags1EF = wFlags;
    MAINMENUS_SetModeFlags(nMode);

    if (gnLaunchMode == 1 || gnLaunchMode == 3)
    {
        if (!gpFuncTable_0077ABF0->pfnSlot68())
        {
            CHARSEL_CreateBaseScreen();
            if (!sub_0043BF60())
                return 0;
            if (!sub_0043C180_Connect(gpLaunchRecord, 0, 0))
                return 0;
        }
    }

    if (gnLaunchMode == 0)
    {
        gpLaunchRecord->nByte35E = 1;
        gnLaunchState = 1;
        gpLaunchRecord->nState19 = 0;
        gpLaunchRecord->dwFlags209 = 4;
        if (wFlags & 4)
            gpLaunchRecord->dwFlags209 = 0x804;
        if (gpLaunchRecord->wFlags1EF & 0x20)
            gpLaunchRecord->dwFlags209 |= 0x100000;
        D2Win_StopMessageLoop();
        return 1;
    }

    if (gnLaunchMode == 2)
    {
        gpLaunchRecord->nByte35E = 3;
        gnLaunchState = 1;
        gpLaunchRecord->dwFlags209 = 4;
        if (wFlags & 4)
            gpLaunchRecord->dwFlags209 = 0x804;
        if (gpLaunchRecord->wFlags1EF & 0x20)
            gpLaunchRecord->dwFlags209 |= 0x100000;
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

            CHATDLG_RequestCharLogon(gpLaunchRecord->szGameName);
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
                sub_00526F20_ToUnicode(wszName, gpLaunchRecord->szGameName, 256);
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
            gpLaunchRecord->nByte22D = 0;
            gpLaunchRecord->szGamePassword[0] = 0;
            bNewGame = 1;
        }

        if (!bNewGame)
        {
            gpLaunchRecord->nByte35E = 2;
        }
        else
        {
            gpLaunchRecord->nByte35E = 4;
            gpLaunchRecord->dwFlags209 = 4;
            if (wFlags & 4)
                gpLaunchRecord->dwFlags209 = 0x804;
            if (gpLaunchRecord->wFlags1EF & 0x20)
                gpLaunchRecord->dwFlags209 |= 0x100000;
        }

        gnLaunchState = 3;
        MAINMENUS_ShowConnectingPopup();
        sub_004FA590_RunLoop(MAINMENUS_StopLoop);
        D2Win_StopMessageLoop();
        return 1;
    }
}

#include "gen/data/Source/D2Launch/Src/MainMenus_0042F2E0.inc"
