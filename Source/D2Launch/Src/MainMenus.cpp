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

int gnFlag_007798D0; // 0x007798D0

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

int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0

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

int gnLastClickX; // 0x00779998

int gnLastClickY; // 0x0077999C

int gnLastClickTick; // 0x007799A0

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

int __stdcall sub_0042FE70_FilterChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FE70

int __stdcall MAINMENUS_FilterRestrictedChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FEF0

int __stdcall MAINMENUS_OnEditChange(int nArg); // 0x00436F20

int __stdcall sub_004372A0_OnEnter(int nArg); // 0x004372A0

void __cdecl MAINMENUS_UpdateEmailOk(); // 0x00436EB0

void __cdecl MAINMENUS_UpdatePasswordOk(); // 0x004371E0

D2WinControlStrc* gpCreatePasswordConfirmEdit; // 0x007795A8

extern D2WinControlStrc* gpPasswordOk; // 0x007799A4

extern D2WinControlStrc* gpStatusText; // 0x007799A8

extern D2WinControlStrc* gpCounterText; // 0x007799AC

extern int gnStatusStringId; // 0x007799B0

extern int gnStatusDots; // 0x007799B4

extern unsigned long gdwStatusStart; // 0x007799B8

extern D2WinControlStrc* gpButton_007799E4; // 0x007799E4

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

int __cdecl GAME_GetWaitHandle(); // 0x00449AC0

int __cdecl sub_00449C50(); // 0x00449C50

int __cdecl sub_00449C70(); // 0x00449C70

void __stdcall CHATDLG_SetCharDeleteReceived(int nValue); // 0x00449C60

void __stdcall CHATDLG_SetCharUpgradeReceived(int nValue); // 0x00449C80

void __cdecl MAINMENUS_UpdateNameOk(); // 0x00430620

void __cdecl CHARSEL_UpdateLoginOk(); // 0x004306C0

int gdwGlobal_00779974; // 0x00779974

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

int gnCmdShow; // 0x0074C71C

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

int __stdcall sub_0042FDE0_FilterChar(void* pControl, int nUnused, const char* pChar); // 0x0042FDE0

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

int __cdecl sub_00449C10(); // 0x00449C10

void __stdcall CHATDLG_SetCharCreateReceived(int nValue); // 0x00449C20

int __cdecl sub_00449C30(); // 0x00449C30

void __stdcall CHATDLG_SetCharLogonReceived(int nValue); // 0x00449C40

D2WinControlStrc* gpTextControl1; // 0x007795D8

D2WinControlStrc* gpTextControl2; // 0x007795DC

char gszEnteredName[256]; // 0x00779C88

int gbFlag_0077ADA4; // 0x0077ADA4

D2LaunchRecord3Strc gtRecord_0077B0A8; // 0x0077B0A8

struct D2WinTextBoxStrc;

int gbStopMainLoop;                                                                                     // 0x0077932C

D2WinControlStrc* gapControlsB[0x40];                                                              // 0x00779350

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

char gszOldPassword[24];                                                                           // 0x00779550

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

D2WinControlStrc* gpControl_00779968; // 0x00779968

int gnFlag_007798D4; // 0x007798D4

void* gpfnArchiveLoader; // 0x007798D8

int gbConnectResult; // 0x0077959C

D2WinControlStrc* gpControl_00779344; // 0x00779344

D2WinControlStrc* gpAddressEdit; // 0x00779958

char gszLastTcpIpAddress[255]; // 0x007795F8

int __stdcall sub_00432040_OnCancel2(int nArg);

int __stdcall MAINMENUS_OnLoginScreen(int nArg); // 0x00432300

D2WinControlStrc* gpCreatePasswordEdit; // 0x00779340

D2WinControlStrc* gpChangePwAccountEdit; // 0x007799BC

D2WinControlStrc* gpOldPasswordEdit; // 0x007799C0

D2WinControlStrc* gpNewPasswordConfirmEdit; // 0x007799C4

D2WinControlStrc* gpNewPasswordEdit; // 0x007799C8

D2WinControlStrc* gpEdit_007799DC; // 0x007799DC

D2WinControlStrc* gpEdit_007799E0; // 0x007799E0

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

// 0x004065E0
void __stdcall D2ServerServiceMain(unsigned long dwArgc, char** lpszArgv)
{
    gbRunningAsService = 1;
    ghD2ServerServiceStatus = RegisterServiceCtrlHandlerA(gszServiceName, D2ServerServiceHandlerProc);
    SetServiceStatus(ghD2ServerServiceStatus, &gD2ServerServiceStatus);
    GameInit(dwArgc, (const char**)lpszArgv);
    gD2ServerServiceStatus.dwCurrentState = 1;
    SetServiceStatus(ghD2ServerServiceStatus, &gD2ServerServiceStatus);
    gbRunningAsService = 0;
}

// 0x004066E0
extern "C" int __stdcall WinMain(void* hInstance, void* hPrevInstance, char* lpCmdLine, int nShowCmd)
{
    ghCurrentProcess_0074C718 = hInstance;
    gnCmdShow = nShowCmd;
    if (!ERRORMANAGER_StartServiceDispatcher())
    {
        const char* argv[2];
        argv[0] = "d2server";
        argv[1] = lpCmdLine;
        ERRORMANAGER_DenyProcessAccess();
        GameInit(2, argv);
    }
    return 0;
}

// 0x00406870
void __fastcall MAINMENUS_InitStorm(int nDirectFlags, int nValue)
{
    SFileSetBasePath(".\\");
    sub_00415F70(nDirectFlags);
    SFileSetIoErrorMode(0, 0);
    sub_00415F90_SetValue(nValue);
    gnStormDirectFlags_0074C82C = nDirectFlags;
    int nChunkSize = 0x8000;
    StormGetOption(2, &nChunkSize, 4);
    int bEnable = 1;
    StormGetOption(1, &bEnable, 4);
    StormGetOption(3, &bEnable, 4);
}

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

// 0x004098B0
void* __fastcall MAINMENUS_PoolReallocLarge(D2PoolSystemStrc* pSystem, int* pBlock, int nSize, const char* szFile, int nLine)
{
    pBlock -= 1;
    const int nBucket = (int)pBlock % 1023;
    int* pPrevious = 0;
    EnterCriticalSection(&pSystem->tLock);
    int* pCurrent = pSystem->apLargeBlocks[nBucket];
    while (pCurrent)
    {
        if (pCurrent == pBlock)
        {
            if (!pPrevious)
            {
                pSystem->apLargeBlocks[nBucket] = (int*)*pCurrent;
            }
            else
            {
                *pPrevious = *pCurrent;
            }
            int* pNewBlock = (int*)realloc(pBlock, nSize + 4);
            if (!pNewBlock)
            {
                MAINMENUS_LogPoolError("Unable to allocate free block of %s", nSize);
                D2_ASSERT(pNewBlock, 1057);
            }
            const int nNewBucket = (int)pNewBlock % 1023;
            *pNewBlock = (int)pSystem->apLargeBlocks[nNewBucket];
            pSystem->apLargeBlocks[nNewBucket] = pNewBlock;
            LeaveCriticalSection(&pSystem->tLock);
            return pNewBlock + 1;
        }
        pPrevious = pCurrent;
        pCurrent = (int*)*pCurrent;
    }
    LeaveCriticalSection(&pSystem->tLock);
    return 0;
}

// 0x00410700
void __cdecl MAINMENUS_LogWrite(const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 354);
    va_list args;
    va_start(args, szFormat);
    sub_00410340_LogV(&gszEmptyAssertText, 0, 0, szFormat, args);
}

// 0x00410740
void __cdecl MAINMENUS_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 371);
    if (!szPrefix)
    {
        szPrefix = &gszEmptyAssertText;
    }
    va_list args;
    va_start(args, szFormat);
    sub_00410340_LogV(szPrefix, 0, 0, szFormat, args);
}

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

int gnValue_0077994C; // 0x0077994C
int gnValue_00779950; // 0x00779950
int gbGatewayFlag; // 0x00779954

// 0x0042E6A0
void __fastcall MAINMENUS_SetGatewayValue(int nValue)
{
    gnGatewayValue_007795BC = nValue;
}

// 0x0042E6B0
void __cdecl MAINMENUS_SetGatewayFlag()
{
    gbGatewayFlag = 1;
}

// 0x0042EF50
void __cdecl MAINMENUS_FreeFrontEndCells()
{
    ARCHIVE_FreeCellFile(gpBlizNoCelFile);
    ARCHIVE_FreeCellFile(gpTrademarkCelFile);
    ARCHIVE_FreeCellFile(gpCellFile_00779700);
    ARCHIVE_FreeCellFile(gpCursorOHandCelFile);
    ARCHIVE_FreeCellFile(gpDiablo2LogoCelFile);
    ARCHIVE_FreeCellFile(gpD2LogoBlackLeftCelFile);
    ARCHIVE_FreeCellFile(gpD2LogoFireLeftCelFile);
    ARCHIVE_FreeCellFile(gpD2LogoBlackRightCelFile);
    ARCHIVE_FreeCellFile(gpD2LogoFireRightCelFile);
    ARCHIVE_FreeCellFile(gpTitleScreenCelFile);
    ARCHIVE_FreeCellFile(gpCreditsBckgCelFile);
    ARCHIVE_FreeCellFile(gpWideButtonBlankCelFile);
    ARCHIVE_FreeCellFile(gpWideButtonBlank02CelFile);
    ARCHIVE_FreeCellFile(gpNarrowButtonBlankCelFile);
    ARCHIVE_FreeCellFile(gpGWListBoxCelFile);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        ARCHIVE_FreeCellFile(gpRealmSelectButtonCelFile);
        ARCHIVE_FreeCellFile(gpTallButtonBlankCelFile);
        ARCHIVE_FreeCellFile(gpCharacterSelectScreenExpCelFile);
        ARCHIVE_FreeCellFile(gpCinematicsSelectionExpCelFile);
    }
    ARCHIVE_FreeCellFile(gpMediumButtonBlankCelFile);
    ARCHIVE_FreeCellFile(gpShortButtonBlankCelFile);
    ARCHIVE_FreeCellFile(gpTextBox2CelFile);
    ARCHIVE_FreeCellFile(gp3WideButtonBlankCelFile);
    ARCHIVE_FreeCellFile(gpTermsOfUseBckgCelFile);
    ARCHIVE_FreeCellFile(gpCharSelectBckgCelFile);
    ARCHIVE_FreeCellFile(gpDifficultyLevelsCelFile);
    ARCHIVE_FreeCellFile(gpCinematicsSelectionCelFile);
    ARCHIVE_FreeCellFile(gpCharSelectBoxCelFile);
    ARCHIVE_FreeCellFile(gpCharSelectBoxGreyCelFile);
    ARCHIVE_FreeCellFile(gpPopUpOkCelFile);
    ARCHIVE_FreeCellFile(gpPopUp340x224CelFile);
    ARCHIVE_FreeCellFile(gpPopUpWideCelFile);
    ARCHIVE_FreeCellFile(gpPopUpLargestCelFile);
    ARCHIVE_FreeCellFile(gpTileableDialogCelFile);
    ARCHIVE_FreeCellFile(gpPopUpOk2CelFile);
    ARCHIVE_FreeCellFile(gpPopUpOkCancelCelFile);
    ARCHIVE_FreeCellFile(gpPopUpOkCancel2CelFile);
    ARCHIVE_FreeCellFile(gpOkCancelButtonBlankCelFile);
    ARCHIVE_FreeCellFile(gpCancelButtonBlankCelFile);
    ARCHIVE_FreeCellFile(gpSelectCharArrowsCelFile);
    ARCHIVE_FreeCellFile(gpRealmSelectCelFile);
    ARCHIVE_FreeCellFile(gpRealmSelectButtonThinCelFile);
    ARCHIVE_FreeCellFile(gpPasswordCelFile);
    ARCHIVE_FreeCellFile(gpCreateNewCharImageCelFile);
    if (gpCharacterCreateCelFile)
    {
        ARCHIVE_FreeCellFile(gpCharacterCreateCelFile);
        gpCharacterCreateCelFile = 0;
        ARCHIVE_FreeCellFile(gpFireCelFile);
        ARCHIVE_FreeCellFile(gpMediumSelButtonBlankCelFile);
        ARCHIVE_FreeCellFile(gpTextBoxCelFile);
        ARCHIVE_FreeCellFile(gpClickBoxCelFile);
        for (int i = 0; i < 5; ++i)
            ARCHIVE_FreeCellFile(gapCellFiles_00779808[i]);
        for (int i = 0; i < 5; ++i)
            ARCHIVE_FreeCellFile(gapCellFiles_0077981C[i]);
        for (int i = 0; i < 5; ++i)
            ARCHIVE_FreeCellFile(gapCellFiles_00779830[i]);
        for (int i = 0; i < 5; ++i)
            ARCHIVE_FreeCellFile(gapCellFiles_00779844[i]);
        for (int i = 0; i < 5; ++i)
            ARCHIVE_FreeCellFile(gapCellFiles_00779858[i]);
        for (int i = 0; i < 3; ++i)
            ARCHIVE_FreeCellFile(gapCellFiles_0077989C[i]);
        for (int i = 0; i < 3; ++i)
            ARCHIVE_FreeCellFile(gapCellFiles_00779888[i]);
        ARCHIVE_FreeCellFile(gpBaFwSCelFile);
        ARCHIVE_FreeCellFile(gpPaFwSCelFile);
        if (FOG_IsExpansion())
        {
            for (int i = 0; i < 5; ++i)
                ARCHIVE_FreeCellFile(gapCellFiles_007797E0[i]);
            for (int i = 0; i < 5; ++i)
                ARCHIVE_FreeCellFile(gapCellFiles_007797F4[i]);
            ARCHIVE_FreeCellFile(gpJoinGameClickBoxGreyCelFile);
        }
    }
    ARCHIVE_FreeCellFile(gpRealmBckgCelFile);
    ARCHIVE_FreeCellFile(gpJoinGameScrollBarsCelFile);
    ARCHIVE_FreeCellFile(gpTcpIpBckgCelFile);
    ARCHIVE_FreeCellFile(gpIPAddressBoxCelFile);
    ARCHIVE_FreeCellFile(gpDownloadPatchBckgCelFile);
    ARCHIVE_FreeCellFile(gpDownloadPatchBall2CelFile);
    ARCHIVE_FreeCellFile(gpEditTextBoxWideCelFile);
}

// 0x0042F6C0
void __cdecl MAINMENUS_SetDone()
{
    gdwGlobal_00779974 = 1;
}

// 0x0042F790
int __stdcall MAINMENUS_ShowCantConnect(SMSGHANDLER_PARAMS* pMsg)
{
    gpfnGatewayDone = MAINMENUS_SetDone;
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xDE);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControlB = MAINMENUS_CreateFromTemplate(0xFD);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlB, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xFE);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FCF80_SetTextA(pControl, "Can't connect to Battle.Net. Try again later.");
    return 1;
}

// 0x0042F3A0
D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId)
{
    D2_ASSERT(gnControlCountA < 0x40, 0x610);
    D2WinControlStrc* pControl = CONTROL_Create(&gatControlTemplates[nTemplateId]);
    gapControlsA[gnControlCountA++] = pControl;
    return pControl;
}

// 0x0042F3F0
void __cdecl MAINMENUS_DestroyControls()
{
    for (int i = 0; i < gnControlCountA; ++i)
        sub_004F95C0_ControlDestroy(&gapControlsA[i]);
    gnControlCountA = 0;
}

// 0x0042F430
D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId)
{
    D2_ASSERT(gnControlCountB < 0x40, 0x627);
    D2WinControlStrc* pControl = CONTROL_Create(&gatControlTemplates[nId]);
    gapControlsB[gnControlCountB++] = pControl;
    return pControl;
}

// 0x0042F480
void __cdecl MAINMENUS_Reset()
{
    for (int i = 0; i < gnControlCountB; ++i)
        sub_004F95C0_ControlDestroy(&gapControlsB[i]);
    gnValue_0077994C = 0;
    gnValue_00779950 = 0;
    gnControlCountB = 0;
    for (int i = 0; i < gnControlCountA; ++i)
        sub_004F95C0_ControlDestroy(&gapControlsA[i]);
    gnControlCountA = 0;
    BACKGROUND_SetCellFile(0);
    if (gbPaletteBusy)
    {
        sub_0042F2E0_ReadPaletteFiles(gszFeCharPalDat, "palette\\fechar\\pal.pl2");
        gbPaletteBusy = 0;
    }
    CHARSEL_FreeCharList();
    CHARSEL_FreeCache();
    D2Win_10029(1);
}

// 0x0042F540
void __fastcall MAINMENUS_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2)
{
    D2_ASSERT(nButton1StringId, 0x746);
    int nButtons = 1;
    if (nButton2StringId)
        nButtons = 2;
    MAINMENUS_DestroyControls();
    switch (nButtons)
    {
    case 1:
    {
        D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xE7);
        D2Win_10033(pControl, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        gatControlTemplates[0x11A].nStringId = nButton1StringId;
        if (bFlag2)
            gatControlTemplates[0x11A].nFlags = 0x1B;
        else
            gatControlTemplates[0x11A].nFlags = bFlag1 ? 0xD : 0;
        gatControlTemplates[0x11A].pfnCallback = pfnButton1;
        pControl = MAINMENUS_CreateFromTemplate(0x11A);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        break;
    }
    case 2:
    {
        D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0x119);
        D2Win_10033(pControl, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        gatControlTemplates[0x11B].nStringId = nButton1StringId;
        gatControlTemplates[0x11B].nFlags = bFlag1 ? 0xD : 0;
        gatControlTemplates[0x11B].pfnCallback = pfnButton1;
        pControl = MAINMENUS_CreateFromTemplate(0x11B);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        gatControlTemplates[0x11C].nStringId = nButton2StringId;
        gatControlTemplates[0x11C].nFlags = bFlag1 ? 0x1B : 0;
        gatControlTemplates[0x11C].pfnCallback = pfnButton2;
        pControl = MAINMENUS_CreateFromTemplate(0x11C);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        break;
    }
    }
    if (pTitle)
    {
        D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0x11D);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        sub_004FD060_SetText(pControl, pTitle);
    }
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(pTitle ? 0x11E : 0x11F);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FD060_SetText(pControl, pMessage);
}

// 0x0042F6E0
void __cdecl MAINMENUS_ShowConnectingPopup()
{
    MAINMENUS_DestroyControls();
    gbGatewayFlag = 1;
    gdwGlobal_00779974 = 0;
    D2WinControlStrc* pControlA;
    D2WinControlStrc* pControlB;
    D2WinControlStrc* pControlC;
    if (gbFeCharPalette)
    {
        pControlA = MAINMENUS_CreateFromTemplate(0xF7);
        D2Win_10033(pControlA, 0);
        pControlB = MAINMENUS_CreateFromTemplate(0xFA);
        pControlC = MAINMENUS_CreateFromTemplate(0xF9);
    }
    else
    {
        pControlA = MAINMENUS_CreateFromTemplate(0xDE);
        D2Win_10033(pControlA, 0);
        pControlB = MAINMENUS_CreateFromTemplate(0xDF);
        pControlC = MAINMENUS_CreateFromTemplate(0xE0);
    }
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlA, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlB, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlC, 1);
    sub_004FD060_SetText(pControlC, D2LANG_GetStringFromTblIndex(0x147B));
    gpfnGatewayDone = MAINMENUS_SetDone;
}

// 0x00430430
int __stdcall MAINMENUS_OnBack(int nArg)
{
    MAINMENUS_CreateMultiplayerScreen();
    return 1;
}

// 0x00430440
int __stdcall MAINMENUS_ScrollUp(int nArg)
{
    D2WinControlStrc* pControl = 0;
    for (int i = 0; i <= gnControlCountB; ++i)
    {
        pControl = gapControlsB[i];
        if (CONTROL_GetType(pControl) == 4)
            break;
    }
    D2_ASSERT(pControl, 3304);
    const int nLines = D2Win_10054((D2WinTextBoxStrc*)pControl);
    if (nLines > 0)
        D2Win_10053(pControl, nLines - 1);
    return 1;
}

// 0x004304B0
int __stdcall MAINMENUS_ScrollDown(int nArg)
{
    D2WinControlStrc* pControl = 0;
    for (int i = 0; i <= gnControlCountB; ++i)
    {
        pControl = gapControlsB[i];
        if (CONTROL_GetType(pControl) == 4)
            break;
    }
    D2_ASSERT(pControl, 3327);
    const int nLines = D2Win_10054((D2WinTextBoxStrc*)pControl);
    D2Win_10053(pControl, nLines + 1);
    return 1;
}

// 0x00430600
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

// 0x00430730
int __stdcall MAINMENUS_ToggleHardcore(int nArg)
{
    *(unsigned short*)gpLaunchRecord->aFlags1EF ^= 4;
    return 1;
}

// 0x00430750
int __stdcall MAINMENUS_ToggleLadder(int nArg)
{
    *(unsigned short*)gpLaunchRecord->aFlags1EF ^= 0x40;
    return 1;
}

// 0x00430770
int __stdcall MAINMENUS_ToggleExpansion(int nArg)
{
    if (!FOG_IsExpansion())
        return 0;
    *(unsigned short*)gpLaunchRecord->aFlags1EF ^= 0x20;
    return 1;
}

// 0x004307A0
int __fastcall MAINMENUS_ShowOptionDescription(unsigned int nArg, int nMode, int nStringId1, int nStringId2)
{
// build: symbol ?gnTextSentinel@* 0x0070CB80
    if (gnTextSentinel == -1)
    {
        if (nArg)
        {
            sub_004FB6A0_ClearText(gpTextControl1);
            sub_004FC9B0_SetText(gpTextControl1, D2LANG_GetStringFromTblIndex(nStringId1), 0, 0, 0);
            sub_004FB6A0_ClearText(gpTextControl2);
            sub_004FC9B0_SetText(gpTextControl2, D2LANG_GetStringFromTblIndex(nStringId2), 0, 0, 0);
            gnTextMode = nMode;
            return 1;
        }
        if (gnTextMode == nMode)
        {
            sub_004FB6A0_ClearText(gpTextControl1);
            sub_004FB6A0_ClearText(gpTextControl2);
        }
    }
    return 1;
}

// 0x004308A0
int __stdcall MAINMENUS_OnSelectAssassin(D2MenuCallbackArgStrc* pArg)
{
    if (!FOG_IsExpansion())
    {
        return 0;
    }
    MAINMENUS_ShowOptionDescription(pArg->nArg, 6, 0x2772, 0x57F7);
    return 1;
}

// 0x004308E0
int __stdcall MAINMENUS_OnSelectDruid(D2MenuCallbackArgStrc* pArg)
{
    if (!FOG_IsExpansion())
    {
        return 0;
    }
    MAINMENUS_ShowOptionDescription(pArg->nArg, 5, 0x2771, 0x57F6);
    return 1;
}

// 0x004309B0
void __cdecl MAINMENUS_ClearLaunchState()
{
// build: symbol ?gnLaunchState@* 0x007795E8
    gnLaunchState = 0;
}

// 0x0042FDD0
void __cdecl MAINMENUS_ReturnToCharSelect()
{
    sub_00515020();
    MAINMENUS_Reset();
    CHARSEL_InitCharSelectScreen();
}

// 0x0042FE60
int __stdcall sub_0042FE60_FilterChar(void* pControl, int nUnused, const char* pChar)
{
    return 1;
}

// 0x0042FEF0
int __stdcall MAINMENUS_FilterRestrictedChar(void* pControl, int nUnused, const char* pChar)
{
    return sub_0042FDE0_FilterChar(pControl, nUnused, pChar);
}

// 0x0042FF00
int __stdcall sub_0042FF00_FilterChar(void* pControl, int nUnused, const char* pChar)
{
    return 1;
}

// 0x0042FFD0
int __stdcall MAINMENUS_ShowAddress(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0042FF20_ShowLocalAddress();
    return 1;
}

// 0x004301A0
void __cdecl MAINMENUS_CreateMultiplayerScreen()
{
    CHARSEL_CreateBaseScreen();
    MAINMENUS_CreateControl(0x15);
    MAINMENUS_CreateControl(0x16);
    MAINMENUS_CreateControl(0x17);
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x1A);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    pControl = MAINMENUS_CreateControl(0x1B);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1469));
    pControl = MAINMENUS_CreateControl(0x1C);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2A52));
    if (!FOG_IsExpansion())
    {
        pControl = MAINMENUS_CreateControl(0x1F);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1466), 0, 0, 0);
    }

    pControl = MAINMENUS_CreateControl(0x20);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1467), 0, 0, 0);

// build: symbol ?gpAccountEdit@* 0x0077958C
    gpAccountEdit = MAINMENUS_CreateControl(0x54);
    sub_004FDAD0_SetKeyCallback(gpAccountEdit, sub_0042FE70_FilterChar);
    sub_004FDD50_SetMaxLength(gpAccountEdit, 0x10);
    sub_004FFE10_SetTextA(gpAccountEdit, gpLaunchRecord->szAccount);

// build: symbol ?gpPasswordEdit@* 0x00779334
    gpPasswordEdit = MAINMENUS_CreateControl(0x55);
    sub_004FDAD0_SetKeyCallback(gpPasswordEdit, sub_0042FF00_FilterChar);
    sub_004FDD50_SetMaxLength(gpPasswordEdit, 0x0D);
    sub_004FFE10_SetTextA(gpPasswordEdit, gpLaunchRecord->szPassword);

    gpCreatePasswordConfirmEdit = MAINMENUS_CreateControl(0x56);
    sub_004FDD50_SetMaxLength(gpCreatePasswordConfirmEdit, 0x0D);

    if (gpLaunchRecord->szAccount[0])
    {
        if (gpLaunchRecord->szPassword[0])
        {
            CONTROL_SetFocusedEditBox(gpCreatePasswordConfirmEdit);
        }
        else
        {
            CONTROL_SetFocusedEditBox(gpPasswordEdit);
        }
    }
    else
    {
        CONTROL_SetFocusedEditBox(gpAccountEdit);
    }

    sub_004FDDD0_LinkTab(gpAccountEdit, gpPasswordEdit);
    sub_004FDDD0_LinkTab(gpPasswordEdit, gpCreatePasswordConfirmEdit);
    sub_004FDDD0_LinkTab(gpCreatePasswordConfirmEdit, gpAccountEdit);
    MAINMENUS_CreateControl(0x57);
    MAINMENUS_CreateControl(0x58);
}

// 0x00430390
void __cdecl MAINMENUS_CreateTermsControls()
{
    MAINMENUS_Reset();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(6);
    ANIMIMAGE_SetIsRunning((D2WinAnimImageStrc*)pControl, 0);
    pControl = MAINMENUS_CreateControl(7);
    ANIMIMAGE_SetIsRunning((D2WinAnimImageStrc*)pControl, 0);
    MAINMENUS_CreateControl(8);
    sub_0042F2E0_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
}

// 0x00430400
int __stdcall MAINMENUS_PollDownloadDone(int nArg)
{
    if (gpFuncTable_0077ABF0->pfnSlot4C() == 0x65 || gbStopMainLoop)
        D2Win_StopMessageLoop();
    return 1;
}

extern "C" int __fastcall sub_0043DAD0_SetControlFlag(int value)
{
    sub_004F9740_ControlFlag(gControl, value);
    return 1;
}

// 0x00430A20
int __cdecl MAINMENUS_FreeSlots()
{
    if (!gppSlots)
        return 1;
    for (int i = 0; i < gnSlotCount; i++)
    {
        D2LaunchSlotStrc* pSlot = ((D2LaunchSlotStrc**)gppSlots)[i];
        if (pSlot)
        {
            D2_ASSERT(pSlot->pData, 0x1139);
            sub_0040B3C0(pSlot->pData, ".\\Src\\MainMenus.cpp", 0x113A, 0);
            D2_ASSERT(((D2LaunchSlotStrc**)gppSlots)[i]->szName, 0x113B);
            sub_0040B3C0(((D2LaunchSlotStrc**)gppSlots)[i]->szName, ".\\Src\\MainMenus.cpp", 0x113C, 0);
            sub_0040B3C0(gppSlots[i], ".\\Src\\MainMenus.cpp", 0x113E, 0);
        }
    }
    sub_0040B3C0(gppSlots, ".\\Src\\MainMenus.cpp", 0x1141, 0);
    gppSlots = 0;
    return 1;
}

int __stdcall sub_M121_Emit_00430600(const char* szText, int nLength) { return MAINMENUS_CountNameSeparators(szText, nLength); }

// 0x00430B80
int __fastcall MAINMENUS_GetSlotValue(int nSlot)
{
    D2SlotEntryStrc* pSlot = (D2SlotEntryStrc*)gppSlots[nSlot];
    D2_ASSERT(pSlot, 0x1162);
    return pSlot->nField04;
}

// 0x00430BB0
int __stdcall MAINMENUS_IdleLoopCallback(int nArg)
{
    return 1;
}

// 0x00430C30
int __stdcall sub_00430C30_OnCancel(int nArg)
{
    D2SOUND_FadeOutWaves();
    MAINMENUS_Reset();
    CHARSEL_InitCharSelectScreen();
    return 1;
}

// 0x00430C50
int __stdcall MAINMENUS_OnCreate(int nArg)
{
    CHARSEL_CreateBaseScreen();
    MAINMENUS_CreateControl(0xFF);
    MAINMENUS_CreateControl(0x100);
    MAINMENUS_CreateControl(0x101);
    return 1;
}

// 0x00431020
void __cdecl MAINMENUS_ClearCreditsLists()
{
    D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
    D2Win_10045(gpList_00779960, &gszEmptyAssertText);
}

// 0x00431040
void __cdecl MAINMENUS_ClearCreditsList() {
 D2Win_10045(gpList_00779964,&gszEmptyAssertText);
}

// 0x004312C0
int __stdcall MAINMENUS_CreateCreditsScreen(int nUnused)
{
    MAINMENUS_Reset();
    sub_0042F2E0_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    MAINMENUS_CreateControl(0x29);
    MAINMENUS_CreateControl(0x2A);
    if (!FOG_IsExpansion())
    {
        gpList_0077995C = MAINMENUS_CreateControl(0x2B);
        gpList_00779960 = MAINMENUS_CreateControl(0x2C);
        gpList_00779964 = MAINMENUS_CreateControl(0x2D);
    }
    else
    {
        gpList_0077995C = MAINMENUS_CreateControl(0x2F);
        gpList_00779960 = MAINMENUS_CreateControl(0x30);
        gpList_00779964 = MAINMENUS_CreateControl(0x31);
    }
    gpControl_00779968 = MAINMENUS_CreateControl(0x2E);
    sub_004FD830(gpControl_00779968);
    sub_004FDA50(gpControl_00779968);
    MAINMENUS_ShowCredits(0);
    D2Win_10053(gpList_00779964, 20);
    D2Win_10053(gpList_0077995C, 20);
    D2Win_10053(gpList_00779960, 20);
    return 1;
}

// 0x004313A0
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

// 0x004313D0
void __stdcall MAINMENUS_CreateLevelScreen(int nLevel)
{
    MAINMENUS_Reset();
    MAINMENUS_DestroyControls();
    sub_0042F2E0_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    MAINMENUS_CreateControl(8);
    MAINMENUS_CreateControl(0x3D);
    D2WinControlStrc* pTitle = MAINMENUS_CreateControl(0x3E);
    sub_004FD060_SetText(pTitle, D2LANG_GetStringFromTblIndex(0x13FA));
    MAINMENUS_CreateControl(0x3F);
    D2WinControlStrc* pField1 = MAINMENUS_CreateControl(0x40);
    D2WinControlStrc* pField2 = MAINMENUS_CreateControl(0x41);
    D2WinControlStrc* pField3 = MAINMENUS_CreateControl(0x42);
    D2WinControlStrc* pField4 = MAINMENUS_CreateControl(0x43);
    D2WinControlStrc* pField5 = MAINMENUS_CreateControl(0x44);
    D2WinControlStrc* pField6 = MAINMENUS_CreateControl(0x45);
    MAINMENUS_CreateControl(0x46);
    unsigned short wszEmpty[1] = { 0 };
    switch (nLevel)
    {
    default:
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(pField1, 0);
        sub_005009D0_SetValue(pField1, 10, wszEmpty, 0);
    case 2:
        CONTROL_SetEnabled(pField2, 0);
        sub_005009D0_SetValue(pField2, 10, wszEmpty, 0);
    case 3:
        CONTROL_SetEnabled(pField3, 0);
        sub_005009D0_SetValue(pField3, 10, wszEmpty, 0);
    case 4:
        CONTROL_SetEnabled(pField4, 0);
        sub_005009D0_SetValue(pField4, 10, wszEmpty, 0);
    case 5:
        CONTROL_SetEnabled(pField5, 0);
        sub_005009D0_SetValue(pField5, 10, wszEmpty, 0);
    case 6:
        CONTROL_SetEnabled(pField6, 0);
        sub_005009D0_SetValue(pField6, 10, wszEmpty, 0);
    case 7:
        break;
    }
}

// calling-convention shim (not game code)
int __fastcall sub_004313A0_Shim(const unsigned char* pFlags, int nCount)
{
    int nSum = 0;
    for (int i = 0; i < nCount; ++i)
        nSum += MAINMENUS_GetFlagIndex(pFlags[i]);
    return nSum;
}

// 0x004317D0
void __cdecl MAINMENUS_FlushInput()
{
    D2WinMsgStrc tMsg;
    while (PeekMessageA(&tMsg, 0, 0, 0, 1))
    {
        switch (tMsg.uMessage)
        {
        case 0x12:
        case 0x102:
        case 0x201:
        case 0x202:
        case 0x204:
        case 0x205:
        case 0x207:
        case 0x208:
            break;
        default:
            TranslateMessage(&tMsg);
            DispatchMessageA(&tMsg);
            break;
        }
    }
}

// 0x00431910
int __stdcall sub_00431910_SetFlagD4(int nArg)
{
    gnFlag_007798D4 = 1;
    return 1;
}

// 0x00431920
int __stdcall sub_00431920_SetFlagD4(int nArg)
{
    gnFlag_007798D4 = 1;
    return 1;
}

// 0x00431930
int __stdcall MAINMENUS_ShowLevelAndStop(int nArg)
{
    MAINMENUS_ShowLevelScreen(nArg);
    gnFlag_007798D0 = 1;
    return 1;
}

// 0x00431950
int __stdcall MAINMENUS_LoopCallback(int nArg)
{
    if (gnFlag_007798D0 || gnFlag_007798D4)
        D2Win_StopMessageLoop();
    return 1;
}

// 0x00431970
void __cdecl MAINMENUS_CreateArchivePopup()
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xD6);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = MAINMENUS_CreateFromTemplate(0x3A);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = MAINMENUS_CreateFromTemplate(0x3B);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xD9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1430), 0, 0, 0);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1432), 0, 0, 0);
}

// 0x00431A00
int __cdecl MAINMENUS_ShowArchiveMessage()
{
    MAINMENUS_CreateArchivePopup();
    gnFlag_007798D0 = 0;
    gnFlag_007798D4 = 0;
    gpfnArchiveLoader = (void*)ARCHIVE_LoadVideoArchives;
    gnLoaderFlag = 1;
    sub_004FA590_RunLoop(MAINMENUS_LoopCallback);
    MAINMENUS_DestroyControls();
    return gnFlag_007798D4;
}

// 0x00431C30
int __stdcall MAINMENUS_Leave(int nArg)
{
    gnLaunchState = 0;
    sub_00515F50(0xB4);
    D2Win_StopMessageLoop();
    return 1;
}

// 0x00431C60
void __fastcall MAINMENUS_HandleCompressionMessage(unsigned char* pMsg, int nSize)
{
    if (nSize != -1)
    {
        switch (*pMsg)
        {
        case 0xAF:
            gdwGlobal_00779990 = 1;
            break;
        case 0xB0:
            gdwGlobal_00779990 = 0;
            break;
        }
    }
}

// 0x00431D10
int __stdcall MAINMENUS_StopLoop(int nArg)
{
    D2Win_StopMessageLoop();
    return 1;
}

// 0x00431A40
int __stdcall MAINMENUS_OpenTcpIpScreen(int nArg)
{
    gnLaunchMode = 2;
// build: symbol ?CHARSEL_CreateTcpIpScreen@* 0x0042FFE0
    CHARSEL_CreateTcpIpScreen();
    return 1;
}

// 0x00431A60
int __fastcall MAINMENUS_IsDoubleClick(SMSGHANDLER_PARAMS* pMsg)
{
    int bResult = 1;
    if (pMsg->uMessage != 0x201)
        bResult = 0;
    int nTick = GetTickCount();
    if (nTick - gnLastClickTick > 300)
        bResult = 0;
    D2CoordPairStrc tPoint;
    GetCursorPos(&tPoint);
    if (abs(tPoint.nY - gnLastClickY) + abs(tPoint.nX - gnLastClickX) > 4)
        bResult = 0;
    gnLastClickY = tPoint.nY;
    gnLastClickTick = nTick;
    gnLastClickX = tPoint.nX;
    return bResult;
}

// 0x00431D20
int __stdcall MAINMENUS_CreateTcpIpScreen(int nArg)
{
    sub_0042F2E0_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    sub_004F95C0_ControlDestroy(&gpControl_00779344);
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0x10F);
    D2Win_10033(pControl, 0);
    MAINMENUS_CreateFromTemplate(0x10E);
    pControl = MAINMENUS_CreateFromTemplate(0x10C);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B1F));
    gpAddressEdit = MAINMENUS_CreateFromTemplate(0x10D);
    if (!gszLastTcpIpAddress[0])
        SRegLoadString("Diablo II", "LastTcpIp", 0, gszLastTcpIpAddress, 0x100);
    sub_004FFE10_SetTextA(gpAddressEdit, gszLastTcpIpAddress);
    CONTROL_SetFocusedEditBox(gpAddressEdit);
    D2Win_10082(gpAddressEdit);
    sub_004FA450_SetActive(MAINMENUS_CreateFromTemplate(0x110));
    MAINMENUS_CreateFromTemplate(0x111);
    return 1;
}

// 0x00431E00
int __stdcall MAINMENUS_OnTcpIpJoin(int nArg)
{
    MAINMENUS_DestroyControls();
    gpControl_00779344 = MAINMENUS_CreateControl(0x10B);
    sub_004FD830(gpControl_00779344);
    sub_004FDA50(gpControl_00779344);
    return 1;
}

// 0x00431E30
int __stdcall MAINMENUS_PollConnection(int nArg)
{
    const int nStatus = CLIENT_GetConnectionStatus();
    if (!nStatus)
    {
        gbConnectResult = nStatus;
        D2Win_StopMessageLoop();
        return 1;
    }
    if (nStatus == 2)
    {
        gbConnectResult = 1;
        D2Win_StopMessageLoop();
    }
    return 1;
}

// 0x00431E70
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

// 0x00431F50
int __stdcall sub_00431F50_OnCancel(int nArg)
{
    D2SOUND_FadeOutWaves();
    MAINMENUS_Reset();
    sub_0043B080();
    return 1;
}

// 0x00432020
int __stdcall sub_00432020_OnCancel(int nArg)
{
    D2SOUND_FadeOutWaves();
    MAINMENUS_Reset();
    CHARSEL_InitCharSelectScreen();
    return 1;
}

// 0x00432040
int __stdcall sub_00432040_OnCancel2(int nArg)
{
    D2SOUND_FadeOutWaves();
    MAINMENUS_Reset();
    CHARSEL_InitCharSelectScreen();
    return 1;
}

// 0x00432060
int __stdcall MAINMENUS_CallGatewayDone(int nArg)
{
    if (gpfnGatewayDone)
        gpfnGatewayDone();
    return 1;
}

// 0x00432080
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

// 0x00432100
void __cdecl MAINMENUS_CreateLoginScreen()
{
    CHARSEL_CreateBaseScreen();
    MAINMENUS_CreateControl(0x15);
    MAINMENUS_CreateControl(0x16);
    MAINMENUS_CreateControl(0x18);
    MAINMENUS_CreateControl(0x19);
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x1A);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    pControl = MAINMENUS_CreateControl(0x1B);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B2C));
    pControl = MAINMENUS_CreateControl(0x1D);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B2D));
    pControl = MAINMENUS_CreateControl(0x1E);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B2E));
    if (FOG_IsExpansion())
        pControl = MAINMENUS_CreateControl(0x21);
    else
        pControl = MAINMENUS_CreateControl(0x1F);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B2B), 0x0, 0x0, 0x0);
    gpAccountEdit = MAINMENUS_CreateControl(0x59);
    sub_004FDAD0_SetKeyCallback(gpAccountEdit, sub_0042FE70_FilterChar);
    sub_004FDD50_SetMaxLength(gpAccountEdit, 0x10);
    sub_004FFE10_SetTextA(gpAccountEdit, gpLaunchRecord->szAccount);
    gpPasswordEdit = MAINMENUS_CreateControl(0x5A);
    sub_004FDAD0_SetKeyCallback(gpPasswordEdit, sub_0042FF00_FilterChar);
    sub_004FDD50_SetMaxLength(gpPasswordEdit, 0xD);
    gpCreatePasswordEdit = MAINMENUS_CreateControl(0x5B);
    sub_004FDD50_SetMaxLength(gpCreatePasswordEdit, 0xD);
    gpCreatePasswordConfirmEdit = MAINMENUS_CreateControl(0x5C);
    sub_004FDD50_SetMaxLength(gpCreatePasswordConfirmEdit, 0xD);
    if (gpLaunchRecord->szAccount[0] != 0x0)
        CONTROL_SetFocusedEditBox(gpPasswordEdit);
    else
        CONTROL_SetFocusedEditBox(gpAccountEdit);
    sub_004FDDD0_LinkTab(gpAccountEdit, gpPasswordEdit);
    sub_004FDDD0_LinkTab(gpPasswordEdit, gpCreatePasswordEdit);
    sub_004FDDD0_LinkTab(gpCreatePasswordEdit, gpCreatePasswordConfirmEdit);
    sub_004FDDD0_LinkTab(gpCreatePasswordConfirmEdit, gpAccountEdit);
    MAINMENUS_CreateControl(0x5D);
    MAINMENUS_CreateControl(0x5E);
}

// 0x00432300
int __stdcall MAINMENUS_OnLoginScreen(int nArg)
{
    MAINMENUS_CreateLoginScreen();
    return 1;
}

// 0x00432310
int __stdcall MAINMENUS_StoreAccount(int nArg)
{
    const Unicode* pText = sub_004FDD90_GetEditText(gpAccountEdit);
    sub_00526F70(gpLaunchRecord->szAccount, pText, 0x100);
    sub_004370C0();
    return 1;
}

// 0x00432340
int __stdcall MAINMENUS_OpenInfoScreen(int nUnused)
{
    sub_004370C0();
    return 1;
}

// 0x00432350
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

// 0x00432400
int __cdecl MAINMENUS_PollStatus()
{
    if (gnWaitDone)
        return 1;
    if (!sub_00449AC0_GetHandle())
        return 2;
    switch (WaitForSingleObject(sub_00449AC0_GetHandle(), 0))
    {
    default:
        return 2;
    case 0x102:
        _ReadWriteBarrier();
        return 3;
    case 0:
// build: symbol ?GAME_GetConnectError@* 0x00449C00
        GAME_GetConnectError();
        return sub_00432350_GetStatus() ? 2 : 0;
    }
}

// 0x00432480
int __fastcall MAINMENUS_ConnectToRealm(const char* szName, int bFlag)
{
    if (*szName && (&gpLaunchRecord->nByte22D)[0] && !strcmp(szName, (&gpLaunchRecord->nByte22D)) && sub_00449B30_QueryAddress())
    {
        return 0;
    }

    if (!bFlag)
    {
        MAINMENUS_ShowConnectingPopup();
    }

    D2MCPClientCloseMCP();
    gnWaitDone = 0;

    if (!*szName)
    {
        (&gpLaunchRecord->nByte22D)[0] = 0;
        (gpLaunchRecord->szPassword + 0x30)[0] = 0;
        if (!bFlag)
        {
            MAINMENUS_DestroyControls();
        }

        return 0;
    }

    D2LaunchPayloadStrc* pPayload;
    if (!gpFuncTable_0077ABF0)
        goto fail;
    pPayload = gpFuncTable_0077ABF0->pfn0x44(szName, "password");
    if (!pPayload)
        goto fail;
    if (pPayload->nSize == 8)
    {
fail:
        if (!bFlag)
            MAINMENUS_DestroyControls();
        return 2;
    }
    SStrCopy((&gpLaunchRecord->nByte22D), szName, 0x100);
    SStrCopy((gpLaunchRecord->szPassword + 0x30), szName, 0x100);
    CHATDLG_StartThread(&pPayload->tRecord);
    int nResult = 3;
    if (!bFlag)
    {
        sub_004FA590_RunLoop(MAINMENUS_OnWait);
        nResult = sub_00432400_GetStatus();
        MAINMENUS_DestroyControls();
    }
    return nResult;
}

// 0x00432450
int __stdcall MAINMENUS_OnWait(int nArg)
{
    if (gdwGlobal_00779974)
        gnWaitDone = 1;
    if (sub_00432400_GetStatus() != 3)
        D2Win_StopMessageLoop();
    return 1;
}

// 0x00432EE0
int __stdcall MAINMENUS_CloseBox(int nArg)
{
    MAINMENUS_DestroyControls();
    return 1;
}

// 0x00432EF0
extern "C" void __cdecl MAINMENUS_ConfigureLanguageLayout()
{
    if (sub_00525150_Language() == 9)
    {
        gLayout_00709C48 = 0x9B;
        gLayout_007091F8 = 0x14E;
        gLayout_00709228 = 0x184;
        gLayout_00709258 = 0x1BA;
        gLayout_007092E8 = 0xF0;
        gLayout_00709318 = 0x158;
        gLayout_00709EE8 = 0x9C;
        gLayout_0070B2C8 = 0x1FA;
        gLayout_0070B2F8 = 0x22B;
        gLayout_0070B088 = 0x23F;
        gLayout_0070B4A8 = 0x22B;
        gLayout_0070B0E8 = 0x22B;
        gLayout_0070B148 = 0x23F;
        gLayout_0070B1A8 = 0x253;
        gLayout_0070BDA8 = 0x46;
        gLayout_0070BF58 = 0xEE;
    }
}

// 0x00432FA0
int __stdcall MAINMENUS_PollCharCreate(int nArg)
{
    sub_00449B70_Receive();
    if (sub_00449C10() || !sub_00449B30_QueryAddress() || gdwGlobal_00779974)
    {
        CHATDLG_SetCharCreateReceived(0);
        D2Win_StopMessageLoop();
    }
    return 1;
}

// 0x00432FE0
int __stdcall MAINMENUS_PollCharLogon(int nArg)
{
    sub_00449B70_Receive();
    if (sub_00449C30() || !sub_00449B30_QueryAddress() || gdwGlobal_00779974)
    {
        CHATDLG_SetCharLogonReceived(0);
        D2Win_StopMessageLoop();
    }
    return 1;
}

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

// 0x00433020
int __stdcall MAINMENUS_PollCharDelete(int nArg)
{
    sub_00449B70_Receive();
    if (sub_00449C50() || !sub_00449B30_QueryAddress() || gdwGlobal_00779974)
    {
        CHATDLG_SetCharDeleteReceived(0);
        D2Win_StopMessageLoop();
    }
    return 1;
}

// 0x00433060
int __stdcall MAINMENUS_PollCharUpgrade(int nArg)
{
    sub_00449B70_Receive();
    if (sub_00449C70() || !sub_00449B30_QueryAddress() || gdwGlobal_00779974)
    {
        CHATDLG_SetCharUpgradeReceived(0);
        D2Win_StopMessageLoop();
    }
    return 1;
}

// 0x00433440
void __fastcall MAINMENUS_ShowMessageNoArg(const Unicode* pText, D2LaunchDoneFn pfnDone)
{
    MAINMENUS_ShowMessage(pText, pfnDone, 0);
}

// 0x004334D0
int __stdcall MAINMENUS_OnCloseBox(int nArg)
{
    MAINMENUS_DestroyControls();
    return 1;
}

// 0x00433BD0
int __stdcall MAINMENUS_OnNameChanged(int nArg)
{
    MAINMENUS_UpdateNameOk();
    return 1;
}

// 0x00437550
void __cdecl MAINMENUS_CreateStatusScreen()
{
    gdwStatusStart = GetTickCount();
    MAINMENUS_DestroyControls();
    sub_0042E6B0(0x1);
    D2WinControlStrc* pFrame = MAINMENUS_CreateFromTemplate(0xE2);
    D2Win_10033(pFrame, 0x0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 0x1);
    D2WinControlStrc* pOther = MAINMENUS_CreateFromTemplate(0xE3);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 0x1);
    D2WinControlStrc* pText = MAINMENUS_CreateFromTemplate(0xE4);
    D2Win_10030_CONTROL_ToggleFourthFlag(pText, 0x1);
    D2Win_10051(pText, D2LANG_GetStringFromTblIndex(0x1433), 0x0, 0x0, 0x0);
    gpStatusText = MAINMENUS_CreateFromTemplate(0xE5);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpStatusText, 0x1);
    gpCounterText = MAINMENUS_CreateFromTemplate(0xE6);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpCounterText, 0x1);
    gnStatusStringId = -1;
    gnStatusDots = 0x0;
    sub_0042E6A0(CHARSEL_SetCancelled);
    MAINMENUS_UpdateStatus();
}

// 0x0043B4C0
int __stdcall MAINMENUS_OnRealmListClick(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?gpNameControl@* 0x007799E8
    const Unicode* pText = sub_004FBB30_GetText(gpNameControl);
    sub_005263E0(gszEnteredName, pText, 0x100);
    CHARSEL_UseName(gszEnteredName);
    CHARSEL_RefreshCharEntry();
    if (MAINMENUS_IsDoubleClick(pMsg))
        return CHARSEL_OnRealmChosen(pMsg);
    return 1;
}

// 0x00440CA0
int __fastcall MAINMENUS_RequestProfile(int nA, int nB, int nC, int nD)
{
    gtRecord_0077B0A8.nValue0 = nB;
    gtRecord_0077B0A8.nValue1 = nC;
    gtRecord_0077B0A8.f_8 = nD;
// build: symbol ?gpLaunchFuncs@* 0x0077B09C
    gpLaunchFuncs->pfn0x78(nA, 3, 1, &gKey_0070CD54);
    gbFlag_0077ADA4 = 0;
    CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), CHATDLG_SetUserDataFlag);
    sub_004FA590_RunLoop(CHATDLG_GetUserDataReply);
    CHARSEL_DestroyPopupControls();
    return gbFlag_0077ADA4 == 0;
}

// 0x004431B0
void __cdecl MAINMENUS_LoadMaxPlayers()
{
    unsigned long nValue = 4;
    if (!SRegLoadValue("Diablo II", "MAX_PLAYER", 0, &nValue))
        SRegSaveValue("Diablo II", "MAX_PLAYER", 0, nValue);
    char szText[2] = "4";
    int nPlayers = nValue;
    if (nPlayers < 9 && nPlayers > 0)
    {
// build: symbol ?gszFormatD@* 0x006D57BC
        sprintf(szText, gszFormatD, nPlayers);
        sub_004FFE10_SetTextA(gpMaxPlayerControl_00798C38, szText);
    }
}

// 0x00443C10
int __stdcall sub_00443C10_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00435CD0
int __stdcall MAINMENUS_OnSinglePlayer(int nArg)
{
    gnLaunchMode = 0;
    if (MAINMENUS_HasSaveFiles() == 1)
    {
        D2SOUND_FadeOutWaves();
        MAINMENUS_Reset();
        CHARSEL_InitCharSelectScreen();
        return 1;
    }

    MAINMENUS_CreateCharCreateScreen();
    return 1;
}

// 0x00435D10
int __stdcall MAINMENUS_OnOpenBattleNet(int nArg)
{
    gnLaunchMode = 3;
    MAINMENUS_ShowLoginScreen();
    return 1;
}

// 0x00435D30
int __stdcall MAINMENUS_OnBattleNet(int nArg)
{
    gnLaunchMode = 1;
    MAINMENUS_ShowLoginScreen();
    return 1;
}

// 0x004361B0
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
            CHARSEL_InitCharSelectScreen();
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

// 0x00435D50
int __stdcall MAINMENUS_OnRealmDoubleClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (MAINMENUS_IsDoubleClick(pMsg))
        return CHARSEL_OnRealmSelected(pMsg);
    return 1;
}

// 0x00436910
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

// 0x00436F30
void __cdecl MAINMENUS_CreateEmailScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        CHARSEL_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0);
        return;
    }
    CHARSEL_CreateBaseScreen();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x12B);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B6A), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x12E);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B5F), 0x0, 0x0, 0x0);
    MAINMENUS_CreateControl(0x12F);
    pControl = MAINMENUS_CreateControl(0x130);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    gpEdit_007799DC = MAINMENUS_CreateControl(0x131);
    sub_004FDD50_SetMaxLength(gpEdit_007799DC, 0x10);
    sub_004FDAD0_SetKeyCallback(gpEdit_007799DC, MAINMENUS_FilterRestrictedChar);
    sub_004FDB00_SetEnterCallback(gpEdit_007799DC, MAINMENUS_OnEditChange);
    MAINMENUS_CreateControl(0x132);
    pControl = MAINMENUS_CreateControl(0x133);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B57));
    gpEdit_007799E0 = MAINMENUS_CreateControl(0x134);
    sub_004FDB00_SetEnterCallback(gpEdit_007799E0, MAINMENUS_OnEditChange);
    sub_004FFE10_SetTextA(gpEdit_007799DC, gpLaunchRecord->szAccount);
    CONTROL_SetFocusedEditBox(gpEdit_007799DC);
    sub_004FDDD0_LinkTab(gpEdit_007799DC, gpEdit_007799E0);
    sub_004FDDD0_LinkTab(gpEdit_007799E0, gpEdit_007799DC);
    gpButton_007799E4 = MAINMENUS_CreateControl(0x12C);
    MAINMENUS_CreateControl(0x12D);
    MAINMENUS_UpdateEmailOk();
}

// 0x004370C0
void __cdecl MAINMENUS_CreateInfoScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        CHARSEL_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0);
        return;
    }
    CHARSEL_CreateBaseScreen();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x135);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B65), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x136);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B66), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x137);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B67), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x138);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B68), 0x0, 0x0, 0x0);
    MAINMENUS_CreateControl(0x139);
    MAINMENUS_CreateControl(0x13A);
    MAINMENUS_CreateControl(0x13B);
    MAINMENUS_CreateControl(0x13C);
}

// 0x004372B0
void __cdecl MAINMENUS_CreatePasswordScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        CHARSEL_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0);
        return;
    }
    CHARSEL_CreateBaseScreen();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x13D);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B6C), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x13E);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B70), 0x0, 0x0, 0x0);
    MAINMENUS_CreateControl(0x13F);
    pControl = MAINMENUS_CreateControl(0x140);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    gpChangePwAccountEdit = MAINMENUS_CreateControl(0x141);
    sub_004FFE10_SetTextA(gpChangePwAccountEdit, gpLaunchRecord->szAccount);
    sub_004FDD50_SetMaxLength(gpChangePwAccountEdit, 0x10);
    sub_004FDAD0_SetKeyCallback(gpChangePwAccountEdit, MAINMENUS_FilterRestrictedChar);
    sub_004FDB00_SetEnterCallback(gpChangePwAccountEdit, sub_004372A0_OnEnter);
    MAINMENUS_CreateControl(0x142);
    pControl = MAINMENUS_CreateControl(0x143);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B6D));
    gpOldPasswordEdit = MAINMENUS_CreateControl(0x144);
    sub_004FDB00_SetEnterCallback(gpOldPasswordEdit, sub_004372A0_OnEnter);
    MAINMENUS_CreateControl(0x145);
    pControl = MAINMENUS_CreateControl(0x146);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B6E));
    gpNewPasswordEdit = MAINMENUS_CreateControl(0x147);
    sub_004FDB00_SetEnterCallback(gpNewPasswordEdit, sub_004372A0_OnEnter);
    MAINMENUS_CreateControl(0x148);
    pControl = MAINMENUS_CreateControl(0x149);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B6F));
    gpNewPasswordConfirmEdit = MAINMENUS_CreateControl(0x14A);
    sub_004FDB00_SetEnterCallback(gpNewPasswordConfirmEdit, sub_004372A0_OnEnter);
    gpPasswordOk = MAINMENUS_CreateControl(0x14B);
    MAINMENUS_CreateControl(0x14C);
    CONTROL_SetFocusedEditBox(gpChangePwAccountEdit);
    sub_004FDDD0_LinkTab(gpChangePwAccountEdit, gpOldPasswordEdit);
    sub_004FDDD0_LinkTab(gpOldPasswordEdit, gpNewPasswordEdit);
    sub_004FDDD0_LinkTab(gpNewPasswordEdit, gpNewPasswordConfirmEdit);
    sub_004FDDD0_LinkTab(gpNewPasswordConfirmEdit, gpChangePwAccountEdit);
    MAINMENUS_UpdatePasswordOk();
}

// 0x00435030
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

// 0x00435200
int __stdcall MAINMENUS_CancelDownload(int nArg)
{
    gpFuncTable_0077ABF0->pfnSlot70();
    gbStopMainLoop = 1;
    MAINMENUS_ShowMainMenu();
    return 1;
}

// 0x00435D80
int __stdcall MAINMENUS_OnTcpIpHost(int nArg)
{
    gpLaunchRecord->nState19 = 8;
    strcpy(gpLaunchRecord->szName, FOG_GetHostIPAddress());
    gnLaunchMode = 2;
    gpLaunchRecord->nValue209 = 4;
    if (!MAINMENUS_HasSaveFiles())
    {
        MAINMENUS_CreateCharCreateScreen();
        return 1;
    }

    D2SOUND_FadeOutWaves();
    MAINMENUS_Reset();
    CHARSEL_InitCharSelectScreen();
    return 1;
}

// 0x00433BE0
int __stdcall MAINMENUS_OnLoginChanged(int nArg)
{
    CHARSEL_UpdateLoginOk();
    return 1;
}

#include "gen/data/Source/D2Launch/Src/MainMenus.inc"
