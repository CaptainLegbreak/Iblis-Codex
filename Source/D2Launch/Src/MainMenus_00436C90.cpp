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
extern D2WinControlStrc* gpOkButton_00779330; // 0x00779330
extern D2WinControlStrc* gpControl_007795AC; // 0x007795AC
extern int gbConnectResult;                                                                            // 0x0077959C
extern D2ConfigStrc* gpLaunchRecord; // 0x007795D4
extern int gbFeCharPalette; // 0x007795F0
extern char gszLastTcpIpAddress[];                                                                          // 0x007795F8
extern D2WinControlStrc* gpAddressEdit;                                                            // 0x00779958
extern int gbPaletteBusy;                                                                          // 0x00779970
extern int gbFlag_00779984; // 0x00779984
extern int gdwGlobal_00779974;                                                                              // 0x00779974
extern D2WinControlStrc* gpStatusText; // 0x007799A8
extern D2WinControlStrc* gpCounterText; // 0x007799AC
extern int gnStatusStringId; // 0x007799B0
extern unsigned long gdwStatusStart; // 0x007799B8
extern D2CelFileStrc* gpBlizNoCelFile;                                                                        // 0x007796F8
extern D2CelFileStrc* gpTrademarkCelFile;                                                                        // 0x007796FC
extern D2CelFileStrc* gpDiablo2LogoCelFile;                                                                        // 0x00779704
extern D2CelFileStrc* gpD2LogoBlackLeftCelFile;                                                                        // 0x00779708
extern D2CelFileStrc* gpD2LogoFireLeftCelFile;                                                                        // 0x0077970C
extern D2CelFileStrc* gpD2LogoBlackRightCelFile;                                                                        // 0x00779710
extern D2CelFileStrc* gpD2LogoFireRightCelFile;                                                                        // 0x00779714
extern D2CelFileStrc* gpTitleScreenCelFile;                                                                        // 0x00779718
extern D2CelFileStrc* gpCursorOHandCelFile;                                                                        // 0x0077971C
extern D2CelFileStrc* gpCreditsBckgCelFile;                                                                        // 0x00779720
extern D2CelFileStrc* gpRealmSelectButtonCelFile;                                                                        // 0x0077972C
extern D2CelFileStrc* gpTallButtonBlankCelFile;                                                                        // 0x00779730
extern D2CelFileStrc* gpCharacterSelectScreenExpCelFile;                                                                        // 0x00779734
extern D2CelFileStrc* gpWideButtonBlankCelFile;                                                                        // 0x00779738
extern D2CelFileStrc* gpMediumButtonBlankCelFile;                                                                        // 0x0077973C
extern D2CelFileStrc* gpShortButtonBlankCelFile;                                                                        // 0x00779740
extern D2CelFileStrc* gpTextBox2CelFile;                                                                        // 0x00779748
extern D2CelFileStrc* gp3WideButtonBlankCelFile;                                                                        // 0x0077974C
extern D2CelFileStrc* gpEditTextBoxWideCelFile;                                                                        // 0x00779750
extern D2CelFileStrc* gpWideButtonBlank02CelFile;                                                                        // 0x00779754
extern D2CelFileStrc* gpNarrowButtonBlankCelFile;                                                                        // 0x00779758
extern D2CelFileStrc* gpGWListBoxCelFile;                                                                        // 0x0077975C
extern D2CelFileStrc* gpTermsOfUseBckgCelFile;                                                                        // 0x00779764
extern D2CelFileStrc* gpCharSelectBckgCelFile;                                                                        // 0x00779768
extern D2CelFileStrc* gpDifficultyLevelsCelFile;                                                                        // 0x0077976C
extern D2CelFileStrc* gpCinematicsSelectionCelFile;                                                                        // 0x00779770
extern D2CelFileStrc* gpCinematicsSelectionExpCelFile;                                                                        // 0x00779774
extern D2CelFileStrc* gpCharSelectBoxCelFile;                                                                        // 0x00779778
extern D2CelFileStrc* gpCharSelectBoxGreyCelFile;                                                                        // 0x0077977C
extern D2CelFileStrc* gpPopUpOkCancelCelFile;                                                                        // 0x00779780
extern D2CelFileStrc* gpPopUpOkCancel2CelFile;                                                                        // 0x00779784
extern D2CelFileStrc* gpSelectCharArrowsCelFile;                                                                        // 0x00779788
extern D2CelFileStrc* gpRealmSelectCelFile;                                                                        // 0x0077978C
extern D2CelFileStrc* gpRealmSelectButtonThinCelFile;                                                                        // 0x00779790
extern D2CelFileStrc* gpCreateNewCharImageCelFile;                                                                        // 0x00779794
extern D2CelFileStrc* gpPopUpOkCelFile;                                                                        // 0x00779798
extern D2CelFileStrc* gpPopUp340x224CelFile;                                                                        // 0x0077979C
extern D2CelFileStrc* gpPopUpWideCelFile;                                                                        // 0x007797A0
extern D2CelFileStrc* gpPopUpLargestCelFile;                                                                        // 0x007797A4
extern D2CelFileStrc* gpTileableDialogCelFile;                                                                        // 0x007797A8
extern D2CelFileStrc* gpPopUpOk2CelFile;                                                                        // 0x007797AC
extern D2CelFileStrc* gpOkCancelButtonBlankCelFile;                                                                        // 0x007797B0
extern D2CelFileStrc* gpCancelButtonBlankCelFile;                                                                        // 0x007797B4
extern D2CelFileStrc* gpPasswordCelFile;                                                                        // 0x007797B8
extern D2CelFileStrc* gpRealmBckgCelFile;                                                                        // 0x007797C8
extern D2CelFileStrc* gpJoinGameScrollBarsCelFile;                                                                        // 0x007797CC
extern D2CelFileStrc* gpTcpIpBckgCelFile;                                                                        // 0x007797D0
extern D2CelFileStrc* gpIPAddressBoxCelFile;                                                                        // 0x007797D4
extern D2CelFileStrc* gpDownloadPatchBckgCelFile;                                                                        // 0x007797D8
extern D2CelFileStrc* gpDownloadPatchBall2CelFile;                                                                        // 0x007797DC
extern D2CelFileStrc* gpCharacterCreateCelFile;                                                                 // 0x00779724
extern D2CelFileStrc* gpFireCelFile;                                                                 // 0x00779728
extern D2CelFileStrc* gpMediumSelButtonBlankCelFile;                                                                 // 0x00779744
extern D2CelFileStrc* gpTextBoxCelFile;                                                                 // 0x007797BC
extern D2CelFileStrc* gpClickBoxCelFile;                                                                 // 0x007797C0
extern D2CelFileStrc* gpJoinGameClickBoxGreyCelFile;                                                                 // 0x007797C4
extern D2CelFileStrc* gapAssassinCelFiles;                                                                        // 0x007797E0
extern D2CelFileStrc* gpAsNu2CelFile; // 0x007797E4
extern D2CelFileStrc* gpAsFwCelFile; // 0x007797E8
extern D2CelFileStrc* gpAsNu3CelFile; // 0x007797EC
extern D2CelFileStrc* gpAsBwCelFile; // 0x007797F0
extern D2CelFileStrc* gapDruidCelFiles;                                                                        // 0x007797F4
extern D2CelFileStrc* gpDzNu2CelFile; // 0x007797F8
extern D2CelFileStrc* gpDzFwCelFile; // 0x007797FC
extern D2CelFileStrc* gpDzNu3CelFile; // 0x00779800
extern D2CelFileStrc* gpDzBwCelFile; // 0x00779804
extern D2CelFileStrc* gapAmazonCelFiles;                                                                        // 0x00779808
extern D2CelFileStrc* gpAmNu2CelFile; // 0x0077980C
extern D2CelFileStrc* gpAmFwCelFile; // 0x00779810
extern D2CelFileStrc* gpAmNu3CelFile; // 0x00779814
extern D2CelFileStrc* gpAmBwCelFile; // 0x00779818
extern D2CelFileStrc* gapNecromancerCelFiles;                                                                        // 0x0077981C
extern D2CelFileStrc* gpNeNu2CelFile; // 0x00779820
extern D2CelFileStrc* gpNeFwCelFile; // 0x00779824
extern D2CelFileStrc* gpNeNu3CelFile; // 0x00779828
extern D2CelFileStrc* gpNeBwCelFile; // 0x0077982C
extern D2CelFileStrc* gapBarbarianCelFiles;                                                                        // 0x00779830
extern D2CelFileStrc* gpBaNu2CelFile; // 0x00779834
extern D2CelFileStrc* gpBaFwCelFile; // 0x00779838
extern D2CelFileStrc* gpBaNu3CelFile; // 0x0077983C
extern D2CelFileStrc* gpBaBwCelFile; // 0x00779840
extern D2CelFileStrc* gapSorceressCelFiles;                                                                        // 0x00779844
extern D2CelFileStrc* gpSoNu2CelFile; // 0x00779848
extern D2CelFileStrc* gpSoFwCelFile; // 0x0077984C
extern D2CelFileStrc* gpSoNu3CelFile; // 0x00779850
extern D2CelFileStrc* gpSoBwCelFile; // 0x00779854
extern D2CelFileStrc* gapPaladinCelFiles;                                                                        // 0x00779858
extern D2CelFileStrc* gpPaNu2CelFile; // 0x0077985C
extern D2CelFileStrc* gpPaFwCelFile; // 0x00779860
extern D2CelFileStrc* gpPaNu3CelFile; // 0x00779864
extern D2CelFileStrc* gpPaBwCelFile; // 0x00779868
extern D2CelFileStrc* gapNecromancerSCelFiles;                                                                        // 0x00779888
extern D2CelFileStrc* gpNeNu3SCelFile; // 0x0077988C
extern D2CelFileStrc* gpNeBwSCelFile; // 0x00779890
extern D2CelFileStrc* gapSorceressSCelFiles;                                                                        // 0x0077989C
extern D2CelFileStrc* gpSoNu3SCelFile; // 0x007798A0
extern D2CelFileStrc* gpSoBwSCelFile; // 0x007798A4
extern D2CelFileStrc* gpBaFwSCelFile;                                                                 // 0x007798B0
extern D2CelFileStrc* gpPaFwSCelFile;                                                                 // 0x007798C4
struct D2ConfigStrc;
struct D2FileTimeStrc;
struct D2ConfigStrc;
struct D2LaunchSlotStrc;
struct D2MenuListStrc;
void __fastcall MAINMENUS_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg); // 0x00433380
int __cdecl STRTABLE_GetLanguage(); // 0x00525150
int __cdecl D2Win_10003(); // 0x004F9050
void __stdcall D2Win_10004(int nResolution); // 0x004F9060
int __stdcall MAINMENUS_ShowLevelScreen(int nUnused); // 0x00431600
void __cdecl MAINMENUS_CreateVideoScreen(); // 0x0042FB20
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
int __fastcall sub_0043C180_Connect(D2ConfigStrc* pRecord, int bFlag, int nMode); // 0x0043C180
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
int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0
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
extern D2WinControlStrc* gpPasswordEdit; // 0x00779334
extern D2WinControlStrc* gpAccountEdit; // 0x0077958C
extern D2WinControlStrc* gpControl_00779594; // 0x00779594
static int s_bGatewayFlag_00779954; // 0x00779954
extern D2WinControlStrc* gpControl_0077933C; // 0x0077933C
extern D2WinControlStrc* gpNameEdit; // 0x0077934C
extern D2WinControlStrc* gapClassImages; // 0x0077956C
extern D2WinControlStrc* gpControl_00779570; // 0x00779570
extern D2WinControlStrc* gpControl_00779574; // 0x00779574
extern D2WinControlStrc* gpControl_00779578; // 0x00779578
extern D2WinControlStrc* gpControl_0077957C; // 0x0077957C
extern D2WinControlStrc* gpControl_00779580; // 0x00779580
extern D2WinControlStrc* gpControl_00779584; // 0x00779584
extern D2WinControlStrc* gpControl_007795B0; // 0x007795B0
extern D2WinControlStrc* gpControl_007795B8; // 0x007795B8
extern D2WinControlStrc* gpControl_007795C4; // 0x007795C4
extern D2WinControlStrc* gpControl_007795CC; // 0x007795CC
extern int gnGlobal_00779DA4; // 0x00779DA4
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
extern D2WinControlStrc* gapControlsA[0x40]; // 0x00779450
extern int gnControlCountA; // 0x00779948
extern "C" const unsigned char gabDefault[]; // 0x006D4D88
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
int __stdcall MAINMENUS_PollCharCreate(int nArg); // 0x00432FA0
char* __cdecl GAME_GetPreferredRealm(); // 0x00437D00
int __stdcall CHATDLG_RequestCharCreate(const char* szName, int nClass, int nFlags); // 0x00449DF0
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
void __cdecl MAINMENUS_LoadFrontEndCells(); // 0x0042E6D0
int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0
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
void __cdecl MAINMENUS_LoadFrontEndCells(); // 0x0042E6D0
int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0
int __cdecl MAINMENUS_InitAuxBattleNet(); // 0x0042FA40
int __cdecl MAINMENUS_GetAuxBattleNetFlag(); // 0x0042FAB0
static int sub_0042FCE0_ArchiveFilePresent(const char* szFile)
{
    void* hFile;
    if (!SFileOpenFileEx(0, szFile, 0, &hFile))
        return 0;
    SFileCloseFile(hFile);
    return 1;
}
void __cdecl MAINMENUS_UpdateNameOk(); // 0x00430620
int __cdecl MAINMENUS_HasSaveFiles(); // 0x00430BC0
int __fastcall MAINMENUS_ShowCredits(int nUnused); // 0x00431050
Unicode* __stdcall MAINMENUS_LoadCreditsText(int* pnLength); // 0x00430CD0
int __stdcall MAINMENUS_ShowLevelScreen(int nUnused); // 0x00431600
int __cdecl MAINMENUS_SaveExists(); // 0x00431F70
void __cdecl MAINMENUS_CreateCharCreateScreen(); // 0x00435580
void __cdecl MAINMENUS_LoadCharCreateCells(); // 0x004326F0
void __cdecl MAINMENUS_PlayIntro(); // 0x004334E0
void __cdecl MAINMENUS_PlayIntroVideo(); // 0x00433640
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
void __cdecl MAINMENUS_ShowMainMenu(); // 0x004336C0
int __stdcall MAINMENUS_PlayClassicIntro(int nArg); // 0x00434320
int __stdcall MAINMENUS_PlayActTwoStart(int nArg); // 0x00434380
int __stdcall MAINMENUS_PlayActThreeStart(int nArg); // 0x004343E0
int __stdcall MAINMENUS_PlayActFourStart(int nArg); // 0x00434440
int __stdcall MAINMENUS_PlayActFourEnd(int nArg); // 0x004344A0
int __stdcall MAINMENUS_PlayExpansionIntro(int nArg); // 0x00434500
int __stdcall MAINMENUS_PlayExpansionOutro(int nArg); // 0x00434560
void __cdecl MAINMENUS_UpdateTwoEditOk(); // 0x00436CF0
static void MAINMENUS_SetModeFlags(char nMode)
{
    gpLaunchRecord->nMode = nMode;
    gpLaunchRecord->bAmazon = 0;
    gpLaunchRecord->bBarbarian = 0;
    gpLaunchRecord->bNecromancer = 0;
    gpLaunchRecord->bPaladin = 0;
    gpLaunchRecord->bSorceress = 0;
    gpLaunchRecord->bDruid = 0;
    gpLaunchRecord->bAssassin = 0;

    if (nMode == 0)
    {
        gpLaunchRecord->bAmazon = 1;
    }
    else if (nMode == 4)
    {
        gpLaunchRecord->bBarbarian = 1;
    }
    else if (nMode == 2)
    {
        gpLaunchRecord->bNecromancer = 1;
    }
    else if (nMode == 3)
    {
        gpLaunchRecord->bPaladin = 1;
    }
    else if (nMode == 1)
    {
        gpLaunchRecord->bSorceress = 1;
    }
    else if (nMode == 5)
    {
        gpLaunchRecord->bDruid = 1;
    }
    else if (nMode == 6)
    {
        gpLaunchRecord->bAssassin = 1;
    }
}
int __stdcall MAINMENUS_JoinTcpIp(int nUnused); // 0x00434790
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
int __stdcall MAINMENUS_CheckFreeSpace(int nUnused); // 0x00434E00
struct D2WinControlStrc;
void __cdecl MAINMENUS_ShowLoginScreen(); // 0x00435330
int __stdcall MAINMENUS_OnCharCreateOk(int nUnused); // 0x004369F0
static inline void __fastcall ShowText(const Unicode* pText, void (__cdecl* pfnDone)())
{
    MAINMENUS_ShowMessage(pText, pfnDone, 1);
}
void __cdecl MAINMENUS_CreateRealmCharacter(); // 0x00435E10
void __cdecl MAINMENUS_CreateCharacter(); // 0x004365B0
void __cdecl MAINMENUS_UpdateStatus(); // 0x00436AD0
// build: symbol ?MAINMENUS_CheckAtAndDot@* 0x00436C10
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
void __cdecl MAINMENUS_UpdateEmailOk(); // 0x00436EB0
void __cdecl MAINMENUS_UpdatePasswordOk(); // 0x004371E0
int __stdcall MAINMENUS_DeclineEmail(int nArg); // 0x00436C70

// 0x00436C90
int __stdcall MAINMENUS_AskEmailRegistration(int nArg)
{
    MAINMENUS_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B5E), 0x2B61, 0x13EF, MAINMENUS_DeclineEmail, sub_004334D0_CloseBox, 0, 1);
    return 1;
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
void __cdecl MAINMENUS_BuildRealmList(); // 0x00434060
int __fastcall MAINMENUS_JoinGame(const char* szGameName, unsigned short wFlags, char nMode, const char* szPassword); // 0x00434A00
