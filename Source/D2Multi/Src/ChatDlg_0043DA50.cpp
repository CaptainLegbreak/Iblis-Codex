#include "D2Multi.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define CREATE_CELL_FILE CHATDLG_CreateChatCellFile
struct D2LaunchFuncsStrc;
struct D2StartupInfoAStrc;
struct D2ProcessInformationStrc;
struct D2LaunchCharInfoStrc;


struct D2StartupInfoAStrc
{
    unsigned long cb;
    char* lpReserved;
    char* lpDesktop;
    char* lpTitle;
    unsigned long dwX;
    unsigned long dwY;
    unsigned long dwXSize;
    unsigned long dwYSize;
    unsigned long dwXCountChars;
    unsigned long dwYCountChars;
    unsigned long dwFillAttribute;
    unsigned long dwFlags;
    unsigned short wShowWindow;
    unsigned short cbReserved2;
    unsigned char* lpReserved2;
    void* hStdInput;
    void* hStdOutput;
    void* hStdError;
};

struct D2ProcessInformationStrc
{
    void* hProcess;
    void* hThread;
    unsigned long dwProcessId;
    unsigned long dwThreadId;
};

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(void* hKey, const char* szSubKey, unsigned long ulOptions, unsigned long samDesired, void** phkResult); // 0x006CC010
extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(void* hKey, const char* szValueName, unsigned long* lpReserved, unsigned long* lpType, unsigned char* lpData, unsigned long* lpcbData); // 0x006CC00C
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey); // 0x006CC030
extern "C" __declspec(dllimport) void* __stdcall GetDesktopWindow(); // 0x006CC494
extern "C" __declspec(dllimport) int __stdcall SetForegroundWindow(void* hWnd); // 0x006CC490
extern "C" __declspec(dllimport) int __stdcall CreateProcessA(const char* szApplicationName, char* szCommandLine, void* pProcessAttributes, void* pThreadAttributes, int bInheritHandles, unsigned long dwCreationFlags, void* pEnvironment, const char* szCurrentDirectory, D2StartupInfoAStrc* pStartupInfo, D2ProcessInformationStrc* pProcessInformation); // 0x006CC33C
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall CHATDLG_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140
extern D2LaunchFuncsStrc* gpLaunchFuncs; // 0x0077B09C

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610
void* __stdcall sub_004FAC80(int nArg); // 0x004FAC80
int __fastcall sub_005259C0(void* pArg, int nArg); // 0x005259C0
void __cdecl STRTABLE_UnloadStringTables(); // 0x00524E40
void __cdecl CHATDLG_LoadFrontEndCels(); // 0x0043CC30
void __cdecl sub_0043DDD0_CreateCharControls(); // 0x0043DDD0
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00
int __stdcall CONTROL_SetFocusedEditBox(void* pEditBox); // 0x004F91C0
void __cdecl COMCALLBACK_RefreshChatButtons(); // 0x004477A0
void __cdecl CHARSEL_ClearHistory(); // 0x0043F4D0
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed); // 0x005009A0
void __fastcall GAME_SetMcpChatCallback(void (__fastcall* pfnCallback)(void* pArg)); // 0x0044B220
void __cdecl VIEW_SendMcpMotdRequest(); // 0x0044AA50
void __cdecl COMCALLBACK_UpdateNameListText(); // 0x0043F730
void __cdecl D2SOUND_InitWaveSlots(); // 0x00514DB0
void __fastcall D2SOUND_PreloadWave(const char* szFile); // 0x00514E10
int __cdecl D2SOUND_GetOptionsMusicOption(); // 0x00514D80
void __fastcall D2SOUND_10034(int nArg); // 0x005148F0
int __cdecl CHATDLG_ConnectRealm(); // 0x00441A90
void __stdcall sub_00449E50_SetValue(int nValue); // 0x00449E50
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590
void __cdecl VIEW_SendMcpCancelGameCreate(); // 0x0044AA80
void __cdecl D2MCPClientCloseMCP(); // 0x00449AD0
void __cdecl sub_00515070(); // 0x00515070
void __cdecl COMCALLBACK_ClearChannel(); // 0x004495A0
void __stdcall D2Win_10146(); // 0x00505100
void __cdecl CHATDLG_FreeNameList(); // 0x0043F800
void __cdecl sub_0043D510_FreeCellFiles(); // 0x0043D510
void* __stdcall sub_005066C0(int nA, int nMode, char* szA, char* szB); // 0x005066C0
void __stdcall sub_005052B0(void* pObject, int nValue); // 0x005052B0
int __stdcall COMCALLBACK_ButtonCallback(void* pMsg); // 0x00448C70
void __fastcall CHATDLG_SetPlayerName(void* pArg); // 0x00440D10
void __fastcall sub_0043E4C0(void* pA, void* pB); // 0x0043E4C0
int __stdcall CHATDLG_OnTick(int nUnused); // 0x00441500
extern int gnChatLaunchMode; // 0x0077BBE4
extern D2LaunchCharInfoStrc* gpCharInfo; // 0x0077BBD8
extern D2WinControlStrc* gpChatTextBox; // 0x0077BD8C
extern D2CelFileStrc* gpWaitingRoomBkgdCelFile; // 0x0077BC08
extern D2WinControlStrc* gapChatDlgControls[17]; // 0x0077B058
extern D2WinControlInitStrc gatChatControlInits_0070CE50[17]; // 0x0070CE50
extern D2WinControlInitStrc gtControlInit_0070D2A0; // 0x0070D2A0
extern D2WinControlInitStrc gtChatTextBoxInit; // 0x0070D240
extern D2WinControlInitStrc gtChatEditInit; // 0x0070D270
extern D2WinControlStrc* gpChatUpButtonA; // 0x0077B084
extern D2WinControlStrc* gpChatDownButtonA; // 0x0077B088
extern D2WinControlStrc* gpChatUpButtonB; // 0x0077B08C
extern D2WinControlStrc* gpChatDownButtonB; // 0x0077B090
extern D2WinControlInitStrc gtControlInit_0070D210; // 0x0070D210
extern D2WinControlInitStrc gtGemButtonInit; // 0x0070D390
extern D2WinControlStrc* gpCreateScreenButton; // 0x0077B070
extern D2WinControlStrc* gpChatControl_0077B074; // 0x0077B074
extern D2WinControlStrc* gpJoinScreenButton; // 0x0077B078
extern D2WinControlStrc* gpControlC_0077B07C; // 0x0077B07C
extern D2WinControlInitStrc gtControlInit_0070D2D0; // 0x0070D2D0
extern D2WinControlInitStrc gtBlankBckgImageInit; // 0x0070D300
extern D2WinControlInitStrc gtControlInit_0070D330; // 0x0070D330
extern D2WinControlStrc* gpControlMain_0077BC4C; // 0x0077BC4C
extern D2WinControlInitStrc gtControlInit_0070D360; // 0x0070D360
extern D2WinControlStrc* gpQuitButton; // 0x0077B080
extern int gbCheck; // 0x0077BD58

static void __cdecl CHATDLG_CreateChatCellFile(D2LaunchCharInfoStrc* pInfo); // 0x0043DC50

void* gpLaunchContext; // 0x0077B0A4

// 0x0043DA50
static int __stdcall CHATDLG_ReadRegValueHKLM(const char* szSubKey, const char* szValueName, unsigned char* pData, unsigned long nSize, unsigned long* pcbData)
{
    void* hKey;
    unsigned long dwType;
    *pcbData = 0;
    if (RegOpenKeyExA((void*)0x80000002, szSubKey, 0, 0x20019, &hKey))
    {
        return 0;
    }
    *pcbData = nSize;
    if (RegQueryValueExA(hKey, szValueName, 0, &dwType, pData, pcbData))
    {
        RegCloseKey(hKey);
        return 0;
    }
    return RegCloseKey(hKey) == 0;
}

// 0x00440DE0
int __stdcall CHATDLG_OpenAdUrl(int nUnused)
{
    const char* szURL = gpLaunchFuncs->pfn0xA4(gpLaunchContext);
    if (!szURL)
    {
        return 1;
    }
    char szCommand[0x800] = { 0 };
    int bOk = 0;
    SetForegroundWindow(GetDesktopWindow());
    char szKey[0x400];
    sprintf(szKey, "%s\\.html", "SOFTWARE\\Classes");
    unsigned long cbData;
    if (CHATDLG_ReadRegValueHKLM(szKey, 0, (unsigned char*)szCommand, 0x400, &cbData))
    {
        char szOpenKey[0x400];
        sprintf(szOpenKey, "%s\\%s\\shell\\open\\command", "SOFTWARE\\Classes", szCommand);
        char szPath[0x400] = { 0 };
        if (CHATDLG_ReadRegValueHKLM(szOpenKey, 0, (unsigned char*)szPath, 0x400, &cbData))
        {
            strcat(szPath, " ");
            strcat(szPath, szURL);
            D2StartupInfoAStrc si;
            D2ProcessInformationStrc pi;
            SMemZero(&si, sizeof(si));
            si.cb = sizeof(si);
            if (CreateProcessA(0, szPath, 0, 0, 0, 0x20, 0, 0, &si, &pi))
            {
                CloseHandle(pi.hThread);
                CloseHandle(pi.hProcess);
                bOk = 1;
            }
        }
    }
    if (!bOk)
    {
        CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14DC), 0);
    }
    gpLaunchFuncs->pfn0x6C(gpLaunchContext, bOk == 0);
    return 1;
}

static int gbDone; // 0x0077BDA0

static int gdwGlobal_0077BBF8; // 0x0077BBF8

D2LaunchFuncsStrc* gpLaunchFuncs; // 0x0077B09C

static int gnLoopValueOut_0077BC14; // 0x0077BC14

D2WinControlStrc* gpControl_0077BD98; // 0x0077BD98

D2WinControlStrc* gpChatEdit; // 0x0077BD94

D2WinControlStrc* gapChatButtons[11]; // 0x0077AD78

D2WinControlStrc* gpChatControl_0077BC44; // 0x0077BC44

static int gbGemToggle; // 0x0077BBEC

D2WinControlStrc* gpGemButton; // 0x0077BC48

D2WinControlStrc* gpNamesButton; // 0x0077BD08

char gszText_0077B1D0[8]; // 0x0077B1D0

char gszText_0077B0B4[28]; // 0x0077B0B4

static D2CriticalSectionStrc gtChatLock; // 0x0077AE28

D2WinControlStrc* gapControls_0077B050[2]; // 0x0077B050

D2WinControlStrc* gpControl_0077BC40; // 0x0077BC40

D2CelFileStrc* gpChatCellFile; // 0x0077BBFC

// 0x0043DC50
static void __cdecl CHATDLG_CreateChatCellFile(D2LaunchCharInfoStrc* pInfo)
{
    int nMode = 5;
    const unsigned short wFlags = *(unsigned short*)pInfo->wFlags0x3CB;
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if ((wFlags & 4) && !(wFlags & 8) && (FOG_IsExpansion() || pInfo->nValue0x1EE < 5))
        nMode = 1;
    gpChatCellFile = (D2CelFileStrc*)sub_005066C0(pInfo->nValue0x1EE, nMode, pInfo->szText0x3A1, (char*)&pInfo->unk0x3B1);
    if (gpChatCellFile)
    {
        sub_005052B0(gpChatCellFile, 0x42);
        sub_005052F0(gpChatCellFile, 0x23B);
        sub_005051A0(gpChatCellFile, 0);
        sub_00505260(gpChatCellFile, 0);
    }
}

// 0x00441B70
int __fastcall CHATDLG_RunChat(D2LaunchCharInfoStrc* pInfo)
{
    char szTitle[256];
    D2WinControlStrc* pControl8;
    D2WinControlStrc* pControl4;

    GetTickCount();
    if (!sub_005259C0(sub_004FAC80(FOG_IsExpansion()), 0))
        return 1;

    gnChatLaunchMode = 0;
    gbDone = 0;
    gdwGlobal_0077BBF8 = 1;
    gpLaunchFuncs = *(D2LaunchFuncsStrc**)((char*)pInfo + 0x225);
    D2_ASSERT(gpLaunchFuncs, 3303);
    if (!gpLaunchFuncs->pfn0x68())
        gbDone = 4;
    else
    {
    CHATDLG_LoadFrontEndCels();
    sub_004F9160_SetLoopValue(gnLoopValueOut_0077BC14);
    gpChatTextBox = 0;
    if (gpCharInfo->szRealm0x361[0])
        BACKGROUND_SetCellFile(gpChatBackground_0077BC04);
    else
        BACKGROUND_SetCellFile(gpWaitingRoomBkgdCelFile);
    if (gpCharInfo->szRealm0x361[0])
    {
        for (int i = 0; i < 17; i++)
            gapChatDlgControls[i] = CONTROL_Create(&gatChatControlInits_0070CE50[i]);
        gpControl_0077BD98 = CONTROL_Create(&gtControlInit_0070D2A0);
    }
    else
    {
        sub_0043DDD0_CreateCharControls();
        CREATE_CELL_FILE(pInfo);
    }
    gpChatTextBox = CONTROL_Create(&gtChatTextBoxInit);
    if (gpCharInfo->szRealm0x361[0])
    {
        gpChatEdit = CONTROL_Create(&gtChatEditInit);
        sub_004FDAD0_SetKeyCallback(gpChatEdit, sub_0043F9B0_EditKey);
        sub_004FDB00_SetEnterCallback(gpChatEdit, sub_0043DB90);
        CONTROL_SetFocusedEditBox(gpChatEdit);
        sub_004FDD50_SetMaxLength(gpChatEdit, 200);
        COMCALLBACK_RefreshChatButtons();
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatUpButtonA, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatDownButtonA, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatUpButtonB, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatDownButtonB, 1);
        D2WinControlStrc** ppButton = gapChatButtons;
        for (int nX = 40; nX < 700; nX += 60, ppButton++)
            *ppButton = BUTTON_Create(nX, 591, 60, 100, 0, (int)COMCALLBACK_ButtonCallback, 0, 0, 4, 0, 0);
        gpChatControl_0077BC44 = CONTROL_Create(&gtControlInit_0070D210);
        sub_004F9740_SetControlState(gpChatControl_0077BC44, 0);
        gpGemButton = CONTROL_Create(&gtGemButtonInit);
        if (gbGemToggle)
            sub_00500B20_SetValue(gpGemButton, 2);
    }
    CHARSEL_ClearHistory();
// build: symbol ?CHARSEL_ResetLaunchState@* 0x0043F8C0
    CHARSEL_ResetLaunchState();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gnChatLaunchMode = 0;
    pControl8 = CONTROL_Create(&gtControlInit_0070D2D0);
    gpNamesButton = CONTROL_Create(&gtBlankBckgImageInit);
    gpControlMain_0077BC4C = CONTROL_Create(&gtControlInit_0070D330);
    GAME_SetMcpChatCallback(CHATDLG_SetPlayerName);
    VIEW_SendMcpMotdRequest();
    COMCALLBACK_UpdateNameListText();
    pControl4 = CONTROL_Create(&gtControlInit_0070D360);
    const unsigned short wFlags = *(unsigned short*)gpCharInfo->wFlags;
    if ((wFlags & 8) && (wFlags & 4))
    {
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpCreateScreenButton, 0);
        CONTROL_SetEnabled(gpJoinScreenButton, 0);
    }
    sub_004FA450_SetActive(gpQuitButton);
    gszText_0077B1D0[0] = 0;
    gszText_0077B0B4[0] = 0;
    D2SOUND_InitWaveSlots();
    D2SOUND_PreloadWave("data\\global\\sfx\\cursor\\button.wav");
    if (D2SOUND_GetOptionsMusicOption())
        D2SOUND_10034(1);
    gbCheck = gpCharInfo->nType0x35E == 4;
    CONTROL_SetEnabled(gpControlC_0077B07C, gbCheck == 0);
    if (CHATDLG_ConnectRealm())
    {
        sprintf(szTitle, "%s,%s", pInfo->szRealm0x22D, pInfo->szName0xBD);
        int nFlags = 0;
        if (*(unsigned short*)pInfo->wFlags & 0x20)
            nFlags = 1;
        if (gpCharInfo->szRealm0x361[0])
            nFlags |= 2;
        gpLaunchFuncs->pfn0x54(pInfo->szName0xBD, szTitle, 0x25, pInfo->szRealm0x361, nFlags);
    }
    else
    {
        sub_00410610_WriteLogLine("[D2MULTI]  Could not restore MCP connection.");
        gpLaunchFuncs->pfn0x10();
    }
    if (gpLaunchFuncs->pfn0x68())
    {
        sub_00449E50_SetValue(0);
        InitializeCriticalSection(&gtChatLock);
        if (!gpCharInfo->szRealm0x361[0])
// build: symbol ?CHATDLG_PostClearMessage@* 0x0043E570
            gpLaunchFuncs->pfn0xA8(sub_0043E4C0, (void (__cdecl*)())CHATDLG_PostClearMessage);
        sub_004FA590_RunLoop(CHATDLG_OnTick);
        if (sub_00449E40())
        {
            VIEW_SendMcpCancelGameCreate();
            sub_00449E50_SetValue(0);
        }
        if (!gpCharInfo->szRealm0x361[0])
            gpLaunchFuncs->pfn0xAC();
        DeleteCriticalSection(&gtChatLock);
        gpLaunchFuncs->pfn0x58();
        if (gbDone != 4)
            D2MCPClientCloseMCP();
    }
    else
        gbDone = 4;

    GetTickCount();
    sub_00515070();
    COMCALLBACK_ClearChannel();
    D2Win_10146();
    CHARSEL_ResetLaunchState();
    CHATDLG_FreeNameList();
    sub_004F95C0_ControlDestroy(&gpChatTextBox);
    if (gpControl_0077BD98)
        sub_004F95C0_ControlDestroy(&gpControl_0077BD98);
    sub_004F95C0_ControlDestroy(&pControl8);
    sub_004F95C0_ControlDestroy(&pControl4);
    sub_004F95C0_ControlDestroy(&gpNamesButton);
    sub_004F95C0_ControlDestroy(&gpControlMain_0077BC4C);
    if (gpGemButton)
        sub_004F95C0_ControlDestroy(&gpGemButton);
    if (gpChatEdit)
        sub_004F95C0_ControlDestroy(&gpChatEdit);
    for (int j = 0; j < 11; j++)
    {
        if (gapChatButtons[j])
            sub_004F95C0_ControlDestroy(&gapChatButtons[j]);
        gapChatButtons[j] = 0;
    }
    sub_004F95C0_ControlDestroy(&gpChatControl_0077BC44);
    for (int k = 0; k < 17; k++)
    {
        if (gapChatDlgControls[k])
            sub_004F95C0_ControlDestroy(&gapChatDlgControls[k]);
        gapChatDlgControls[k] = 0;
    }
    if (!gpCharInfo->szRealm0x361[0])
    {
        for (int m = 0; m <= 1; m++)
        {
            if (gapControls_0077B050[m])
            {
                sub_004F95C0_ControlDestroy(&gapControls_0077B050[m]);
                gapControls_0077B050[m] = 0;
            }
        }
        if (gpControl_0077BC40)
        {
            sub_004F95C0_ControlDestroy(&gpControl_0077BC40);
            gpControl_0077BC40 = 0;
        }
    }
    BACKGROUND_SetCellFile(0);
    sub_004F9160_SetLoopValue(0);
    sub_0043D510_FreeCellFiles();
    }
    STRTABLE_UnloadStringTables();
    return 1;
}

#include "gen/data/Source/D2Multi/Src/ChatDlg_0043DA50.inc"
