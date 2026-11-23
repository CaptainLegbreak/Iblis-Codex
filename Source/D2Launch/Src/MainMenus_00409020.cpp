#include "D2Launch.h"
#include "D2FogTypes.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"
#pragma intrinsic(_ReadWriteBarrier)
#pragma intrinsic(strcmp)
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))
struct D2ServiceStatusStrc;
struct D2PoolSystemStrc;
struct D2MemoryStatusStrc;
struct D2MenuCallbackArgStrc;
struct D2SlotEntryStrc;
struct SMSGHANDLER_PARAMS;
struct D2WinMsgStrc;
struct D2CoordPairStrc;
struct D2LaunchRecordStrc;
struct D2CriticalSectionStrc;
struct Unicode;
struct D2FuncTable_0077ABF0Strc;
struct D2LaunchThreadRecordStrc;
struct D2LaunchPayloadStrc;
typedef char* va_list;
struct D2ServiceStatusStrc
{
    unsigned long dwServiceType;
    unsigned long dwCurrentState;
    unsigned long dwControlsAccepted;
    unsigned long dwWin32ExitCode;
    unsigned long dwServiceExitCode;
    unsigned long dwCheckPoint;
    unsigned long dwWaitHint;
};
struct D2MemoryStatusStrc
{
    unsigned long dwLength;
    unsigned long dwMemoryLoad;
    unsigned long dwTotalPhys;
    unsigned long dwAvailPhys;
    unsigned long dwTotalPageFile;
    unsigned long dwAvailPageFile;
    unsigned long dwTotalVirtual;
    unsigned long dwAvailVirtual;
};
struct D2MenuCallbackArgStrc
{
    int nUnk0x00;
    int nUnk0x04;
    int nUnk0x08;
    unsigned int nArg;
};
typedef int (__stdcall* D2GetDiskFreeSpaceExFn)(const char* szDirectory, unsigned __int64* pnFreeToCaller, unsigned __int64* pnTotal, unsigned __int64* pnTotalFree);
extern "C" __declspec(dllimport) void* __stdcall RegisterServiceCtrlHandlerA(const char* szServiceName, void (__stdcall* pfnHandler)(unsigned long dwCtrlCode)); // 0x006CC024
extern "C" __declspec(dllimport) int __stdcall SetServiceStatus(void* hServiceStatus, D2ServiceStatusStrc* pStatus); // 0x006CC048
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C
extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pBuffer); // 0x006CC1F4
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(); // 0x006CC20C
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int nExitCode); // 0x006CC2E0
extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args); // 0x00682DA1
extern "C" void* __cdecl realloc(void* pMemory, size_t nSize); // 0x00683BA5
void __stdcall D2ServerServiceHandlerProc(unsigned long dwCtrlCode); // 0x00406410
int __fastcall GameInit(int argc, const char** argv); // 0x004064C0
int __cdecl ERRORMANAGER_StartServiceDispatcher(); // 0x00406650
int __cdecl ERRORMANAGER_DenyProcessAccess(); // 0x004061C0
void __fastcall sub_00410340_LogV(const char* szPrefix, int nArg2, int nArg3, const char* szFormat, va_list args); // 0x00410340
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410660
char* __fastcall Int64ToString(char* szBuffer, unsigned int nBufferSize, __int64 nValue); // 0x00411540
int __stdcall sub_00415F70(int nFlags); // 0x00415F70
void __stdcall sub_00415F90_SetValue(int nValue); // 0x00415F90
int __stdcall SFileSetBasePath(const char* szPath); // 0x004164B0
int __stdcall SFileSetIoErrorMode(int nValueA, int nValueB); // 0x004166B0
int __stdcall StormGetOption(unsigned int nOption, const void* pInput, unsigned int nSize); // 0x0041BFC0
void __cdecl sub_0041C1A0_LockErrorState(); // 0x0041C1A0
void __cdecl sub_0041C1E0_UnlockErrorState(); // 0x0041C1E0
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300
int __stdcall sub_004269C0_RegisterHandler(unsigned long dwId, void* pContext); // 0x004269C0
int __fastcall MAINMENUS_ShowOptionDescription(unsigned int nArg, int nMode, int nStringId1, int nStringId2); // 0x004307A0
int __stdcall MAINMENUS_ShowLevelScreen(int nArg); // 0x00431600
extern "C" const char gszPercentS_006FFC58[]; // 0x006FFC58
extern "C" const char gszKernel32[]; // 0x006CD6E4
extern char gszServiceName[]; // 0x007065DC
extern D2ServiceStatusStrc gD2ServerServiceStatus; // 0x007065FC
extern void* ghD2ServerServiceStatus; // 0x0074C714
extern void* ghCurrentProcess_0074C718; // 0x0074C718
extern int gbRunningAsService; // 0x0074C720
extern int gnStormDirectFlags_0074C82C; // 0x0074C82C
extern void* gpStormOwnerB_007790C4; // 0x007790C4
extern unsigned long gdwStormOwnerThread_007790C8; // 0x007790C8
extern int gnFlag_007798D0; // 0x007798D0
struct D2SlotEntryStrc
{
    int unk0x00;
    int nField04;
};
extern void** gppSlots; // 0x00779988
extern int gnSlotCount; // 0x0077998C
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80
extern D2WinControlStrc* gpList_0077995C; // 0x0077995C
extern D2WinControlStrc* gpList_00779960; // 0x00779960
extern int gdwGlobal_00779990; // 0x00779990
extern D2WinControlStrc* gpList_00779964; // 0x00779964
void __cdecl MAINMENUS_Reset(); // 0x0042F480
int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0
D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId); // 0x0042F430
int __fastcall MAINMENUS_ShowCredits(int nUnused); // 0x00431050
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine); // 0x004FBA30
static unsigned char MAINMENUS_GetFlagIndex(unsigned char nFlags); // 0x004313A0
struct D2WinMsgStrc
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
    unsigned int dwTime;
    int f_14;
    int nPointY;
};
struct D2CoordPairStrc
{
    int nX;
    int nY;
};
extern "C" int __cdecl abs(int nValue);
extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(const D2WinMsgStrc* pMsg); // 0x006CC478
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const D2WinMsgStrc* pMsg); // 0x006CC47C
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax, unsigned int nRemove); // 0x006CC480
extern "C" __declspec(dllimport) int __stdcall GetCursorPos(D2CoordPairStrc* pPoint); // 0x006CC48C
extern int gnLastClickX; // 0x00779998
extern int gnLastClickY; // 0x0077999C
extern int gnLastClickTick; // 0x007799A0
void __cdecl MAINMENUS_DestroyControls(); // 0x0042F3F0
int __cdecl CLIENT_GetConnectionStatus(); // 0x0052B050
D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId); // 0x0042F3A0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __stdcall CONTROL_SetFocusedEditBox(D2WinControlStrc* pEditBox); // 0x004F91C0
int __fastcall D2Win_10082(D2WinControlStrc* pEditBox); // 0x004FDD00
int __fastcall D2Win_StopMessageLoop(); // 0x004F9190
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590
void __cdecl MAINMENUS_CreateArchivePopup(); // 0x00431970
extern int gnLoaderFlag; // 0x007798E0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
extern D2WinControlStrc* gpEdit_007799CC; // 0x007799CC
extern D2WinControlStrc* gpEdit_007799D0; // 0x007799D0
extern D2WinControlStrc* gpControl_007799D4; // 0x007799D4
extern D2LaunchRecordStrc* gpLaunchRecord; // 0x007795D4
void __cdecl D2SOUND_FadeOutWaves(); // 0x00515020
void __cdecl sub_0043B080();
void __cdecl MAINMENUS_CreateLoginScreen(); // 0x00432100
void __cdecl CHARSEL_CreateBaseScreen(); // 0x0043C4F0
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
void __fastcall CHARSEL_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450
void __fastcall sub_0042E6B0(int nValue); // 0x0042E6B0
void __fastcall sub_0042E6A0(void (__cdecl* pfnCallback)()); // 0x0042E6A0
void __cdecl CHARSEL_SetCancelled(); // 0x0043B810
void __cdecl MAINMENUS_UpdateStatus(); // 0x00436AD0
int __stdcall CHARSEL_FilterLoginChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FE70
int __stdcall MAINMENUS_FilterRestrictedChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FEF0
int __stdcall MAINMENUS_OnEditChange(int nArg); // 0x00436F20
int __stdcall sub_004372A0_OnEnter(int nArg); // 0x004372A0
void __cdecl MAINMENUS_UpdateEmailOk(); // 0x00436EB0
void __cdecl MAINMENUS_UpdatePasswordOk(); // 0x004371E0
extern D2WinControlStrc* gpCreatePasswordConfirmEdit; // 0x007795A8
extern D2WinControlStrc* gpPasswordOk; // 0x007799A4
extern D2WinControlStrc* gpStatusText; // 0x007799A8
extern D2WinControlStrc* gpCounterText; // 0x007799AC
extern int gnStatusStringId; // 0x007799B0
extern int gnStatusDots; // 0x007799B4
extern unsigned long gdwStatusStart; // 0x007799B8
extern D2WinControlStrc* gpButton_007799E4; // 0x007799E4
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
int __cdecl GAME_GetWaitHandle(); // 0x00449AC0
int __cdecl GAME_IsMcpCharDeleteReceived(); // 0x00449C50
int __cdecl GAME_IsMcpCharUpgradeReceived(); // 0x00449C70
void __stdcall CHATDLG_SetCharDeleteReceived(int nValue); // 0x00449C60
void __stdcall CHATDLG_SetCharUpgradeReceived(int nValue); // 0x00449C80
void __cdecl MAINMENUS_UpdateNameOk(); // 0x00430620
void __cdecl CHARSEL_UpdateLoginOk(); // 0x004306C0
extern int gdwGlobal_00779974; // 0x00779974
void __fastcall MAINMENUS_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg); // 0x00433380
extern "C" void _ReadWriteBarrier(void);
void* __cdecl sub_00449AC0_GetHandle(); // 0x00449AC0
int __cdecl sub_00432350_GetStatus(); // 0x00432350
extern "C" int __cdecl strcmp(const char* szA, const char* szB);
struct D2LaunchThreadRecordStrc
{
    int nData[0x52];
};
struct D2LaunchPayloadStrc
{
    unsigned int nSize;
    D2LaunchThreadRecordStrc tRecord;
};
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
void __cdecl MAINMENUS_ShowConnectingPopup(); // 0x0042F6E0
int __stdcall MAINMENUS_OnWait(int nArg); // 0x00432450
void __stdcall CHATDLG_StartThread(D2LaunchThreadRecordStrc* pRecord); // 0x0044A130
extern int gnCmdShow; // 0x0074C71C
struct D2LaunchControlTemplateStrc;
struct D2LaunchRecord3Strc;
struct D2LaunchRecord3Strc
{
    int nValue0;
    int nValue1;
    int f_8;
};
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long nValue); // 0x004150E0
void __fastcall sub_005009D0_SetValue(D2WinControlStrc* pControl, int nMode, unsigned short* pText, int nArg); // 0x005009D0
int __stdcall CHARSEL_IsRestrictedChar(void* pControl, int nUnused, const char* pChar); // 0x0042FDE0
int __fastcall MAINMENUS_IsDoubleClick(SMSGHANDLER_PARAMS* pMsg); // 0x00431A60
int __stdcall CHARSEL_OnRealmSelected(SMSGHANDLER_PARAMS* pMsg); // 0x00434700
void __cdecl CHARSEL_RefreshCharEntry(); // 0x0043A650
int __stdcall CHARSEL_OnRealmChosen(SMSGHANDLER_PARAMS* pMsg); // 0x0043A950
void __fastcall CHARSEL_UseName(char* szName); // 0x0043ADB0
void __cdecl CHARSEL_DestroyPopupControls(); // 0x0043EA20
int __stdcall CHATDLG_SetUserDataFlag(int nArg); // 0x0043F580
int __stdcall CHATDLG_GetUserDataReply(int nUnused); // 0x0043F590
void __fastcall CHATDLG_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone); // 0x004401C0
extern D2LaunchControlTemplateStrc gatControlTemplates[]; // 0x00708D10
extern int gnTextMode; // 0x00708D0C
extern char gKey_0070CD54; // 0x0070CD54
void __cdecl CHARSEL_InitCharSelectScreen(); // 0x0043B080
extern void (__cdecl* gpfnGatewayDone)(); // 0x007795BC
int __cdecl GAME_IsMcpCharCreateReceived(); // 0x00449C10
void __stdcall CHATDLG_SetCharCreateReceived(int nValue); // 0x00449C20
int __cdecl GAME_IsMcpCharLogonReceived(); // 0x00449C30
void __stdcall CHATDLG_SetCharLogonReceived(int nValue); // 0x00449C40
extern D2WinControlStrc* gpTextControl1; // 0x007795D8
extern D2WinControlStrc* gpTextControl2; // 0x007795DC
extern char gszEnteredName[256]; // 0x00779C88
extern int gbFlag_0077ADA4; // 0x0077ADA4
extern D2LaunchRecord3Strc gtRecord_0077B0A8; // 0x0077B0A8
struct D2WinTextBoxStrc;
extern int gbStopMainLoop;                                                                                     // 0x0077932C
extern D2WinControlStrc* gapControlsB[0x40];                                                              // 0x00779350
extern int gnControlCountB;                                                                        // 0x00779944
int __stdcall CONTROL_GetType(D2WinControlStrc* pControl);                                                  // 0x004FA490
int __fastcall D2Win_10054(D2WinTextBoxStrc* pTextBox);                                                     // 0x004FB950
void __cdecl MAINMENUS_CreateMultiplayerScreen();                                                                                // 0x004301A0
unsigned int __stdcall SStrHashHT(const char* szPath);                                           // 0x00414150
int __fastcall sub_00526590_Compare(const Unicode* pString1, const Unicode* pString2);                      // 0x00526590
int __fastcall sub_0043C180_Connect(D2LaunchRecordStrc* pRecord, int bFlag, int nMode);                    // 0x0043C180
int __cdecl MAINMENUS_HasSaveFiles();                                                                    // 0x00430BC0
void __cdecl MAINMENUS_ReturnToCharSelect();                                                                                // 0x0042FDD0
void __cdecl MAINMENUS_ShowLoginScreen();                                                                // 0x00435330
void __cdecl sub_004325B0_CreateScreen();                                                                   // 0x004325B0
extern char gszOldPassword[24];                                                                           // 0x00779550
extern int gbConnectCancelled;                                                                              // 0x007795F4
typedef unsigned short U16;
struct U16Cell
{
    U16 value;

};
typedef char U16_is_two[(sizeof(U16)==2)?1:-1];
typedef char Cell_size[(sizeof(U16Cell)==2)?1:-1];
typedef char Cell_value_zero[((unsigned int)&((U16Cell*)0)->value==0)?1:-1];
struct UiControl;
extern "C" int __cdecl sub_00525150_Language();
extern "C" void __fastcall sub_004F9740_ControlFlag(UiControl* control,int value);
extern "C" int __fastcall sub_00526800_UnicodeLength(const U16* text);
extern "C" UiControl* gControl;
extern "C" const U16Cell gUpperTable[];
extern "C" int gLayout_00709C48; // 0x00709C48
extern "C" int gLayout_007091F8; // 0x007091F8
extern "C" int gLayout_00709228; // 0x00709228
extern "C" int gLayout_00709258; // 0x00709258
extern "C" int gLayout_007092E8; // 0x007092E8
extern "C" int gLayout_00709318; // 0x00709318
extern "C" int gLayout_00709EE8; // 0x00709EE8
extern "C" int gLayout_0070B2C8; // 0x0070B2C8
extern "C" int gLayout_0070B2F8; // 0x0070B2F8
extern "C" int gLayout_0070B088; // 0x0070B088
extern "C" int gLayout_0070B4A8; // 0x0070B4A8
extern "C" int gLayout_0070B0E8; // 0x0070B0E8
extern "C" int gLayout_0070B148; // 0x0070B148
extern "C" int gLayout_0070B1A8; // 0x0070B1A8
extern "C" int gLayout_0070BDA8; // 0x0070BDA8
extern "C" int gLayout_0070BF58; // 0x0070BF58
extern D2WinControlStrc* gpControl_00779968; // 0x00779968
extern int gnFlag_007798D4; // 0x007798D4
extern void* gpfnArchiveLoader; // 0x007798D8
extern int gbConnectResult; // 0x0077959C
extern D2WinControlStrc* gpControl_00779344; // 0x00779344
extern D2WinControlStrc* gpAddressEdit; // 0x00779958
extern char gszLastTcpIpAddress[255]; // 0x007795F8
int __stdcall sub_00432040_OnCancel2(int nArg);
int __stdcall MAINMENUS_OnLoginScreen(int nArg); // 0x00432300
extern D2WinControlStrc* gpCreatePasswordEdit; // 0x00779340
extern D2WinControlStrc* gpChangePwAccountEdit; // 0x007799BC
extern D2WinControlStrc* gpOldPasswordEdit; // 0x007799C0
extern D2WinControlStrc* gpNewPasswordConfirmEdit; // 0x007799C4
extern D2WinControlStrc* gpNewPasswordEdit; // 0x007799C8
extern D2WinControlStrc* gpEdit_007799DC; // 0x007799DC
extern D2WinControlStrc* gpEdit_007799E0; // 0x007799E0
static int gnWaitDone; // 0x00779994
struct D2WinAnimImageStrc;
int __stdcall ANIMIMAGE_SetIsRunning(D2WinAnimImageStrc* pAnimImage, int bIsRunning); // 0x00500810
int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg);                                            // 0x004FA470
void __cdecl sub_0042FF20_ShowLocalAddress();                                                               // 0x0042FF20
void __cdecl MAINMENUS_UpdateTwoEditOk(); // 0x00436CF0
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
#pragma intrinsic(strcpy)
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0
extern int gnLaunchMode;                                                                           // 0x007795EC
const char* __fastcall FOG_GetHostIPAddress(); // 0x0040DF60
void __cdecl MAINMENUS_ShowMainMenu();                                                                                // 0x004336C0
void __cdecl MAINMENUS_CreateCharCreateScreen();                                                                                // 0x00435580
extern int gnControlCountA; // 0x00779948
D2WinControlStrc* __stdcall CONTROL_Create(D2LaunchControlTemplateStrc* pTemplate); // 0x004F93C0
extern D2WinControlStrc* gapControlsA[0x40]; // 0x00779450
int __stdcall BACKGROUND_SetCellFile(D2CelFileStrc* pCellFile); // 0x004F9140
extern int gbPaletteBusy; // 0x00779970
extern "C" const char gszFeCharPalDat[]; // 0x006D39E8
void __cdecl CHARSEL_FreeCharList(); // 0x00438EA0
void __cdecl CHARSEL_FreeCache(); // 0x00437B90
extern int gbFeCharPalette; // 0x007795F0
extern D2CelFileStrc* gpPopUpWideCelFile; // 0x007797A0
void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile); // 0x004FAAE0
extern D2CelFileStrc* gpPopUpLargestCelFile; // 0x007797A4
extern D2CelFileStrc* gpTileableDialogCelFile; // 0x007797A8
extern D2CelFileStrc* gpPopUpOk2CelFile; // 0x007797AC
extern D2CelFileStrc* gpPopUpOkCancelCelFile; // 0x00779780
extern D2CelFileStrc* gpPopUpOkCancel2CelFile; // 0x00779784
extern D2CelFileStrc* gpOkCancelButtonBlankCelFile; // 0x007797B0
extern D2CelFileStrc* gpCancelButtonBlankCelFile; // 0x007797B4
extern D2CelFileStrc* gpSelectCharArrowsCelFile; // 0x00779788
extern D2CelFileStrc* gpRealmSelectCelFile; // 0x0077978C
extern D2CelFileStrc* gpRealmSelectButtonThinCelFile; // 0x00779790
extern D2CelFileStrc* gpPasswordCelFile; // 0x007797B8
extern D2CelFileStrc* gpCreateNewCharImageCelFile; // 0x00779794
extern D2CelFileStrc* gapCellFiles_00779808[5]; // 0x00779808
extern D2CelFileStrc* gapCellFiles_0077981C[5]; // 0x0077981C
extern D2CelFileStrc* gapCellFiles_007797E0[5]; // 0x007797E0
extern D2CelFileStrc* gapCellFiles_007797F4[5]; // 0x007797F4
extern D2CelFileStrc* gapCellFiles_00779830[5]; // 0x00779830
extern D2CelFileStrc* gapCellFiles_00779844[5]; // 0x00779844
extern D2CelFileStrc* gapCellFiles_00779858[5]; // 0x00779858
extern D2CelFileStrc* gapCellFiles_00779888[3]; // 0x00779888
extern D2CelFileStrc* gapCellFiles_0077989C[3]; // 0x0077989C
extern D2CelFileStrc* gpBlizNoCelFile; // 0x007796F8
extern D2CelFileStrc* gpTrademarkCelFile; // 0x007796FC
extern D2CelFileStrc* gpDiablo2LogoCelFile; // 0x00779704
extern D2CelFileStrc* gpD2LogoBlackLeftCelFile; // 0x00779708
extern D2CelFileStrc* gpD2LogoFireLeftCelFile; // 0x0077970C
extern D2CelFileStrc* gpD2LogoBlackRightCelFile; // 0x00779710
extern D2CelFileStrc* gpD2LogoFireRightCelFile; // 0x00779714
extern D2CelFileStrc* gpTitleScreenCelFile; // 0x00779718
extern D2CelFileStrc* gpCursorOHandCelFile; // 0x0077971C
extern D2CelFileStrc* gpCreditsBckgCelFile; // 0x00779720
extern D2CelFileStrc* gpRealmSelectButtonCelFile; // 0x0077972C
extern D2CelFileStrc* gpTallButtonBlankCelFile; // 0x00779730
extern D2CelFileStrc* gpCharacterSelectScreenExpCelFile; // 0x00779734
extern D2CelFileStrc* gpWideButtonBlankCelFile; // 0x00779738
extern D2CelFileStrc* gpMediumButtonBlankCelFile; // 0x0077973C
extern D2CelFileStrc* gpShortButtonBlankCelFile; // 0x00779740
extern D2CelFileStrc* gpTextBox2CelFile; // 0x00779748
extern D2CelFileStrc* gp3WideButtonBlankCelFile; // 0x0077974C
extern D2CelFileStrc* gpEditTextBoxWideCelFile; // 0x00779750
extern D2CelFileStrc* gpWideButtonBlank02CelFile; // 0x00779754
extern D2CelFileStrc* gpNarrowButtonBlankCelFile; // 0x00779758
extern D2CelFileStrc* gpGWListBoxCelFile; // 0x0077975C
extern D2CelFileStrc* gpTermsOfUseBckgCelFile; // 0x00779764
extern D2CelFileStrc* gpCharSelectBckgCelFile; // 0x00779768
extern D2CelFileStrc* gpDifficultyLevelsCelFile; // 0x0077976C
extern D2CelFileStrc* gpCinematicsSelectionCelFile; // 0x00779770
extern D2CelFileStrc* gpCinematicsSelectionExpCelFile; // 0x00779774
extern D2CelFileStrc* gpCharSelectBoxCelFile; // 0x00779778
extern D2CelFileStrc* gpCharSelectBoxGreyCelFile; // 0x0077977C
extern D2CelFileStrc* gpPopUpOkCelFile; // 0x00779798
extern D2CelFileStrc* gpPopUp340x224CelFile; // 0x0077979C
extern D2CelFileStrc* gpRealmBckgCelFile; // 0x007797C8
extern D2CelFileStrc* gpJoinGameScrollBarsCelFile; // 0x007797CC
extern D2CelFileStrc* gpTcpIpBckgCelFile; // 0x007797D0
extern D2CelFileStrc* gpIPAddressBoxCelFile; // 0x007797D4
extern D2CelFileStrc* gpDownloadPatchBckgCelFile; // 0x007797D8
extern D2CelFileStrc* gpDownloadPatchBall2CelFile; // 0x007797DC
extern D2CelFileStrc* gpCellFile_00779700; // 0x00779700
extern D2CelFileStrc* gpFireCelFile; // 0x00779728
extern D2CelFileStrc* gpMediumSelButtonBlankCelFile; // 0x00779744
extern D2CelFileStrc* gpTextBoxCelFile; // 0x007797BC
extern D2CelFileStrc* gpClickBoxCelFile; // 0x007797C0
extern D2CelFileStrc* gpJoinGameClickBoxGreyCelFile; // 0x007797C4
extern D2CelFileStrc* gpBaFwSCelFile; // 0x007798B0
extern D2CelFileStrc* gpPaFwSCelFile; // 0x007798C4
extern D2CelFileStrc* gpCharacterCreateCelFile; // 0x00779724
extern int gnGatewayValue_007795BC; // 0x007795BC
void __stdcall D2ServerServiceMain(unsigned long dwArgc, char** lpszArgv); // 0x004065E0
extern "C" int __stdcall WinMain(void* hInstance, void* hPrevInstance, char* lpCmdLine, int nShowCmd); // 0x004066E0
void __fastcall MAINMENUS_InitStorm(int nDirectFlags, int nValue); // 0x00406870
// 0x00409020
void __cdecl MAINMENUS_LogPoolError(const char* szFormat, ...)
{
    char szText[0x1000];
    va_list args;
    va_start(args, szFormat);
    vsprintf(szText, szFormat, args);
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "--------------------------------------------------------");
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "ERROR: Out of memory!");
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, gszPercentS_006FFC58, szText);
    D2MemoryStatusStrc tStatus;
    GlobalMemoryStatus(&tStatus);
    char szNumber[0x20];
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "total physical:     %s", Int64ToString(szNumber, sizeof(szNumber), tStatus.dwTotalPhys));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "available physical: %s", Int64ToString(szNumber, sizeof(szNumber), tStatus.dwAvailPhys));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "total page:         %s", Int64ToString(szNumber, sizeof(szNumber), tStatus.dwTotalPageFile));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "available page:     %s", Int64ToString(szNumber, sizeof(szNumber), tStatus.dwAvailPageFile));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "total virtual:      %s", Int64ToString(szNumber, sizeof(szNumber), tStatus.dwTotalVirtual));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "available virtual:  %s", Int64ToString(szNumber, sizeof(szNumber), tStatus.dwAvailVirtual));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, &gszEmptyAssertText);
}
void* __fastcall MAINMENUS_PoolReallocLarge(D2PoolSystemStrc* pSystem, int* pBlock, int nSize, const char* szFile, int nLine); // 0x004098B0
void __cdecl MAINMENUS_LogWrite(const char* szFormat, ...); // 0x00410700
void __cdecl MAINMENUS_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410740
// 0x004107F0
unsigned __int64 __cdecl MAINMENUS_GetSaveDiskFreeSpace()
{
    char szPath[0x400];
// build: symbol ?FOG_GetSavePath@* 0x00407050
    FOG_GetSavePath(szPath, sizeof(szPath));
    void* hKernel = LoadLibraryA(gszKernel32);
    if (hKernel)
    {
        D2GetDiskFreeSpaceExFn pfnGetDiskFreeSpaceEx = (D2GetDiskFreeSpaceExFn)GetProcAddress(hKernel, "GetDiskFreeSpaceExA");
        if (pfnGetDiskFreeSpaceEx)
        {
            unsigned __int64 nTotalFree = 0;
            unsigned __int64 nTotal = 0;
            unsigned __int64 nFreeToCaller = 0;
            pfnGetDiskFreeSpaceEx(szPath, &nFreeToCaller, &nTotal, &nTotalFree);
            FreeLibrary(hKernel);
            return nFreeToCaller;
        }
    }
    for (unsigned int i = 0; i < sizeof(szPath); i++)
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
    return nFreeClusters * nBytesPerSector * nSectorsPerCluster;
}
extern int gnValue_0077994C; // 0x0077994C
extern int gnValue_00779950; // 0x00779950
extern int gbGatewayFlag; // 0x00779954
void __fastcall MAINMENUS_SetGatewayValue(int nValue); // 0x0042E6A0
void __cdecl MAINMENUS_SetGatewayFlag(); // 0x0042E6B0
void __cdecl MAINMENUS_FreeFrontEndCells(); // 0x0042EF50
void __cdecl MAINMENUS_SetDone(); // 0x0042F6C0
int __stdcall MAINMENUS_ShowCantConnect(SMSGHANDLER_PARAMS* pMsg); // 0x0042F790
D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId); // 0x0042F3A0
void __cdecl MAINMENUS_DestroyControls(); // 0x0042F3F0
D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId); // 0x0042F430
void __cdecl MAINMENUS_Reset(); // 0x0042F480
void __fastcall MAINMENUS_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540
void __cdecl MAINMENUS_ShowConnectingPopup(); // 0x0042F6E0
int __stdcall MAINMENUS_OnBack(int nArg); // 0x00430430
int __stdcall MAINMENUS_ScrollUp(int nArg); // 0x00430440
int __stdcall MAINMENUS_ScrollDown(int nArg); // 0x004304B0
static inline int MAINMENUS_CountNameSeparators(const char* szText, int nLength)
{
    int nCount = 0;
    for (int i = 0; i < nLength; ++i)
    {
        if (szText[i] == '-' || szText[i] == '_')
        {
            ++nCount;
        }
    }
    return nCount;
}
int __stdcall MAINMENUS_ToggleHardcore(int nArg); // 0x00430730
int __stdcall MAINMENUS_ToggleLadder(int nArg); // 0x00430750
int __stdcall MAINMENUS_ToggleExpansion(int nArg); // 0x00430770
int __fastcall MAINMENUS_ShowOptionDescription(unsigned int nArg, int nMode, int nStringId1, int nStringId2); // 0x004307A0
int __stdcall MAINMENUS_OnSelectAssassin(D2MenuCallbackArgStrc* pArg); // 0x004308A0
int __stdcall MAINMENUS_OnSelectDruid(D2MenuCallbackArgStrc* pArg); // 0x004308E0
void __cdecl MAINMENUS_ClearLaunchState(); // 0x004309B0
void __cdecl MAINMENUS_ReturnToCharSelect(); // 0x0042FDD0
int __stdcall sub_0042FE60_FilterChar(void* pControl, int nUnused, const char* pChar); // 0x0042FE60
int __stdcall MAINMENUS_FilterRestrictedChar(void* pControl, int nUnused, const char* pChar); // 0x0042FEF0
int __stdcall sub_0042FF00_FilterChar(void* pControl, int nUnused, const char* pChar); // 0x0042FF00
int __stdcall MAINMENUS_ShowAddress(SMSGHANDLER_PARAMS* pMsg); // 0x0042FFD0
void __cdecl MAINMENUS_CreateMultiplayerScreen(); // 0x004301A0
void __cdecl MAINMENUS_CreateTermsControls(); // 0x00430390
int __stdcall MAINMENUS_PollDownloadDone(int nArg); // 0x00430400
extern "C" int __fastcall sub_0043DAD0_SetControlFlag(int value)
{
    sub_004F9740_ControlFlag(gControl, value);
    return 1;
}
int __cdecl MAINMENUS_FreeSlots(); // 0x00430A20
int __stdcall sub_M121_Emit_00430600(const char* szText, int nLength) { return MAINMENUS_CountNameSeparators(szText, nLength); }
int __fastcall MAINMENUS_GetSlotValue(int nSlot); // 0x00430B80
int __stdcall MAINMENUS_IdleLoopCallback(int nArg); // 0x00430BB0
int __stdcall sub_00430C30_OnCancel(int nArg); // 0x00430C30
int __stdcall MAINMENUS_OnCreate(int nArg); // 0x00430C50
void __cdecl MAINMENUS_ClearCreditsLists(); // 0x00431020
void __cdecl MAINMENUS_ClearCreditsList(); // 0x00431040
int __stdcall MAINMENUS_CreateCreditsScreen(int nUnused); // 0x004312C0
static unsigned char MAINMENUS_GetFlagIndex(unsigned char nFlags)
{
    if (nFlags & 0x01)
        return 7;
    if (nFlags & 0x80)
        return 6;
    if (nFlags & 0x10)
        return 5;
    if (nFlags & 0x08)
        return 4;
    if (nFlags & 0x40)
        return 3;
    if (nFlags & 0x04)
        return 2;
    return 1;
}
void __stdcall MAINMENUS_CreateLevelScreen(int nLevel); // 0x004313D0
// calling-convention shim (not game code)
int __fastcall sub_004313A0_Shim(const unsigned char* pFlags, int nCount)
{
    int nSum = 0;
    for (int i = 0; i < nCount; ++i)
        nSum += MAINMENUS_GetFlagIndex(pFlags[i]);
    return nSum;
}
void __cdecl MAINMENUS_FlushInput(); // 0x004317D0
int __stdcall sub_00431910_SetFlagD4(int nArg); // 0x00431910
int __stdcall sub_00431920_SetFlagD4(int nArg); // 0x00431920
int __stdcall MAINMENUS_ShowLevelAndStop(int nArg); // 0x00431930
int __stdcall MAINMENUS_LoopCallback(int nArg); // 0x00431950
void __cdecl MAINMENUS_CreateArchivePopup(); // 0x00431970
int __cdecl MAINMENUS_ShowArchiveMessage(); // 0x00431A00
int __stdcall MAINMENUS_Leave(int nArg); // 0x00431C30
void __fastcall MAINMENUS_HandleCompressionMessage(unsigned char* pMsg, int nSize); // 0x00431C60
int __stdcall MAINMENUS_StopLoop(int nArg); // 0x00431D10
int __stdcall MAINMENUS_OpenTcpIpScreen(int nArg); // 0x00431A40
int __fastcall MAINMENUS_IsDoubleClick(SMSGHANDLER_PARAMS* pMsg); // 0x00431A60
int __stdcall MAINMENUS_CreateTcpIpScreen(int nArg); // 0x00431D20
int __stdcall MAINMENUS_OnTcpIpJoin(int nArg); // 0x00431E00
int __stdcall MAINMENUS_PollConnection(int nArg); // 0x00431E30
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
void __cdecl sub_I03_Emit_00431E70(char nMode)
{
    MAINMENUS_SetModeFlags(gnTextSentinel);
    MAINMENUS_SetModeFlags(nMode);
}
int __stdcall sub_00431F50_OnCancel(int nArg); // 0x00431F50
int __stdcall sub_00432020_OnCancel(int nArg); // 0x00432020
int __stdcall sub_00432040_OnCancel2(int nArg); // 0x00432040
int __stdcall MAINMENUS_CallGatewayDone(int nArg); // 0x00432060
void __cdecl MAINMENUS_CreateLoginScreen(); // 0x00432100
int __stdcall MAINMENUS_OnLoginScreen(int nArg); // 0x00432300
int __stdcall MAINMENUS_StoreAccount(int nArg); // 0x00432310
int __stdcall MAINMENUS_OpenInfoScreen(int nUnused); // 0x00432340
static int sub_00432350_IsListedCode(int nCode)
{
    switch (nCode)
    {
    case 2:
    case 10:
    case 11:
    case 12:
    case 13:
    case 126:
    case 127:
        return 1;
    }
    return 0;
}
int __cdecl MAINMENUS_PollStatus(); // 0x00432400
int __fastcall MAINMENUS_ConnectToRealm(const char* szName, int bFlag); // 0x00432480
int __stdcall MAINMENUS_OnWait(int nArg); // 0x00432450
int __stdcall MAINMENUS_CloseBox(int nArg); // 0x00432EE0
extern "C" void __cdecl MAINMENUS_ConfigureLanguageLayout(); // 0x00432EF0
int __stdcall MAINMENUS_PollCharCreate(int nArg); // 0x00432FA0
int __stdcall MAINMENUS_PollCharLogon(int nArg); // 0x00432FE0
int __cdecl sub_00432400_GetWaitStatus()
{
    if (gnWaitDone)
        return 1;

    if (GAME_GetWaitHandle())
    {
        switch (WaitForSingleObject((void*)GAME_GetWaitHandle(), 0))
        {
        case 0:
            return sub_00432350_IsListedCode(GAME_GetConnectError()) ? 2 : 0;
        case 0x102:
            return 3;
        }
    }

    return 2;
}
int __stdcall MAINMENUS_PollCharDelete(int nArg); // 0x00433020
int __stdcall MAINMENUS_PollCharUpgrade(int nArg); // 0x00433060
void __fastcall MAINMENUS_ShowMessageNoArg(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433440
int __stdcall MAINMENUS_OnCloseBox(int nArg); // 0x004334D0
int __stdcall MAINMENUS_OnNameChanged(int nArg); // 0x00433BD0
void __cdecl MAINMENUS_CreateStatusScreen(); // 0x00437550
int __stdcall MAINMENUS_OnRealmListClick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B4C0
int __fastcall MAINMENUS_RequestProfile(int nA, int nB, int nC, int nD); // 0x00440CA0
void __cdecl MAINMENUS_LoadMaxPlayers(); // 0x004431B0
int __stdcall sub_00443C10_AlwaysOne(int nArg); // 0x00443C10
int __stdcall MAINMENUS_OnSinglePlayer(int nArg); // 0x00435CD0
int __stdcall MAINMENUS_OnOpenBattleNet(int nArg); // 0x00435D10
int __stdcall MAINMENUS_OnBattleNet(int nArg); // 0x00435D30
int __stdcall MAINMENUS_LoginOk(int nArg); // 0x004361B0
int __stdcall MAINMENUS_OnRealmDoubleClick(SMSGHANDLER_PARAMS* pMsg); // 0x00435D50
int __stdcall MAINMENUS_CreateAccountOk(int nArg); // 0x00436910
void __cdecl MAINMENUS_CreateEmailScreen(); // 0x00436F30
void __cdecl MAINMENUS_CreateInfoScreen(); // 0x004370C0
void __cdecl MAINMENUS_CreatePasswordScreen(); // 0x004372B0
int __stdcall MAINMENUS_ChangePasswordOk(int nArg); // 0x00435030
int __stdcall MAINMENUS_CancelDownload(int nArg); // 0x00435200
int __stdcall MAINMENUS_OnTcpIpHost(int nArg); // 0x00435D80
int __stdcall MAINMENUS_OnLoginChanged(int nArg); // 0x00433BE0
