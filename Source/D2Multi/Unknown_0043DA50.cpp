#include "D2Multi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define CREATE_CELL_FILE sub_0043DC50_CreateChatCellFile
struct D2LaunchFuncsStrc;
struct D2StartupInfoAStrc;
struct D2ProcessInformationStrc;
struct D2LaunchCharInfoStrc;

typedef unsigned short Unicode;

struct D2LaunchFuncsStrc
{
    char unk0x00[0x10];
    void (__fastcall* pfn0x10)();
    char unk0x14[0x40];
    void (__fastcall* pfn0x54)(char* szName, char* szTitle, int nA, char* szRealm, int nFlags);
    void (__fastcall* pfn0x58)();
    char unk0x5C[0x0C];
    int (__fastcall* pfn0x68)();
    void (__fastcall* pfn0x6C)(void* pContext, int bFailed);
    char f_70[0x34];
    const char* (__fastcall* pfn0xA4)(void* pContext);
    void (__fastcall* pfn0xA8)(void (__fastcall* pfnA)(void* pA, void* pB), void (__cdecl* pfnB)());
    void (__fastcall* pfn0xAC)();
};

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
void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C; // 0x0077B09C

struct D2WinControlInitStrc
{
    int nType;
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int field_14;
    int nStringId;
    D2CellFileStrc** ppCellFile;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
};

#pragma pack(push, 1)
struct D2LaunchCharInfoStrc
{
    char unk0x00[0xBD];
    char szName0xBD[0x131];
    unsigned char nValue0x1EE;
    char wFlags[2];
    char unk0x1F1[0x34];
    D2LaunchFuncsStrc* f_225;
    char unk0x229[0x04];
    char szRealm0x22D[0x131];
    char nType0x35E;
    char unk0x35F[0x02];
    char szText0x361[0x40];
    char szText0x3A1[0x10];
    char szText0x3B1[0x1A];
    char wFlags0x3CB[2];
};

#pragma pack(pop)
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610
void* __stdcall sub_004FAC80(int nArg); // 0x004FAC80
int __fastcall sub_005259C0(void* pArg, int nArg); // 0x005259C0
void __cdecl sub_00524E40_UnloadStringTables(); // 0x00524E40
void __cdecl sub_0043CC30_LoadFrontEndCels(); // 0x0043CC30
void __cdecl sub_0043DDD0_CreateCharControls(); // 0x0043DDD0
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00
int __stdcall sub_004F91C0(void* pEditBox); // 0x004F91C0
void __cdecl sub_004477A0_Refresh(); // 0x004477A0
void __cdecl sub_0043F4D0(); // 0x0043F4D0
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed); // 0x005009A0
void __fastcall sub_0044B220_SetCallback(void (__fastcall* pfnCallback)(void* pArg)); // 0x0044B220
void __cdecl sub_0044AA50_SendPacket12(); // 0x0044AA50
void __cdecl sub_0043F730(); // 0x0043F730
void __cdecl sub_00514DB0_InitWaveSlots(); // 0x00514DB0
void __fastcall sub_00514E10_LoadWave(const char* szFile); // 0x00514E10
int __cdecl sub_00514D80(); // 0x00514D80
void __fastcall sub_005148F0_SetChannelValue(int nArg); // 0x005148F0
int __cdecl sub_00441A90(); // 0x00441A90
void __stdcall sub_00449E50_SetValue(int nValue); // 0x00449E50
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590
void __cdecl sub_0044AA80_SendPacket13(); // 0x0044AA80
void __cdecl D2MCPClientCloseMCP(); // 0x00449AD0
void __cdecl sub_00515070(); // 0x00515070
void __cdecl sub_004495A0_ClearChannel(); // 0x004495A0
void __stdcall D2Win_10146(); // 0x00505100
void __cdecl sub_0043F800_FreeNameList(); // 0x0043F800
void __cdecl sub_0043D510_FreeCellFiles(); // 0x0043D510
void* __stdcall sub_005066C0(int nA, int nMode, char* szA, char* szB); // 0x005066C0
void __stdcall sub_005052B0(void* pObject, int nValue); // 0x005052B0
int __stdcall sub_00448C70_ButtonCallback(void* pMsg); // 0x00448C70
void __fastcall sub_00440D10(void* pArg); // 0x00440D10
void __fastcall sub_0043E4C0(void* pA, void* pB); // 0x0043E4C0
int __stdcall sub_00441500(int nUnused); // 0x00441500
extern int gnLaunchMode_0077BBE4; // 0x0077BBE4
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8; // 0x0077BBD8
extern D2WinControlStrc* gpChatTextBox_0077BD8C; // 0x0077BD8C
extern D2CellFileStrc* gpCellFile_0077BC08; // 0x0077BC08
extern D2WinControlStrc* gpChatControl_0077B058[17]; // 0x0077B058
extern D2WinControlInitStrc gatChatControlInits_0070CE50[17]; // 0x0070CE50
extern D2WinControlInitStrc gtControlInit_0070D2A0; // 0x0070D2A0
extern D2WinControlInitStrc gtControlInit_0070D240; // 0x0070D240
extern D2WinControlInitStrc gtControlInit_0070D270; // 0x0070D270
extern D2WinControlStrc* gpChatControl_0077B084; // 0x0077B084
extern D2WinControlStrc* gpChatControl_0077B088; // 0x0077B088
extern D2WinControlStrc* gpChatControl_0077B08C; // 0x0077B08C
extern D2WinControlStrc* gpChatControl_0077B090; // 0x0077B090
extern D2WinControlInitStrc gtControlInit_0070D210; // 0x0070D210
extern D2WinControlInitStrc gtControlInit_0070D390; // 0x0070D390
extern D2WinControlStrc* gpControlA_0077B070; // 0x0077B070
extern D2WinControlStrc* gpChatControl_0077B074; // 0x0077B074
extern D2WinControlStrc* gpControlB_0077B078; // 0x0077B078
extern D2WinControlStrc* gpControlC_0077B07C; // 0x0077B07C
extern D2WinControlInitStrc gtControlInit_0070D2D0; // 0x0070D2D0
extern D2WinControlInitStrc gtControlInit_0070D300; // 0x0070D300
extern D2WinControlInitStrc gtControlInit_0070D330; // 0x0070D330
extern D2WinControlStrc* gpControlMain_0077BC4C; // 0x0077BC4C
extern D2WinControlInitStrc gtControlInit_0070D360; // 0x0070D360
extern D2WinControlStrc* gpControl_0077B080; // 0x0077B080
extern int gbCheck_0077BD58; // 0x0077BD58

static void __cdecl sub_0043DC50_CreateChatCellFile(D2LaunchCharInfoStrc* pInfo);

void* gpLaunchContext_0077B0A4; // 0x0077B0A4

// 0x0043DA50
static int __stdcall sub_0043DA50_ReadRegValueHKLM(const char* szSubKey, const char* szValueName, unsigned char* pData, unsigned long nSize, unsigned long* pcbData)
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
int __stdcall sub_00440DE0(int nUnused)
{
    const char* szURL = gpLaunchFuncs_0077B09C->pfn0xA4(gpLaunchContext_0077B0A4);
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
    if (sub_0043DA50_ReadRegValueHKLM(szKey, 0, (unsigned char*)szCommand, 0x400, &cbData))
    {
        char szOpenKey[0x400];
        sprintf(szOpenKey, "%s\\%s\\shell\\open\\command", "SOFTWARE\\Classes", szCommand);
        char szPath[0x400] = { 0 };
        if (sub_0043DA50_ReadRegValueHKLM(szOpenKey, 0, (unsigned char*)szPath, 0x400, &cbData))
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
        sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14DC), 0);
    }
    gpLaunchFuncs_0077B09C->pfn0x6C(gpLaunchContext_0077B0A4, bOk == 0);
    return 1;
}

static int gbDone_0077BDA0; // 0x0077BDA0

static int gdwGlobal_0077BBF8; // 0x0077BBF8

D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C; // 0x0077B09C

static int gnLoopValueOut_0077BC14; // 0x0077BC14

D2WinControlStrc* gpControl_0077BD98; // 0x0077BD98

D2WinControlStrc* gpChatEdit_0077BD94; // 0x0077BD94

D2WinControlStrc* gapChatButtons_0077AD78[11]; // 0x0077AD78

D2WinControlStrc* gpChatControl_0077BC44; // 0x0077BC44

static int gbToggle_0077BBEC; // 0x0077BBEC

D2WinControlStrc* gpChatControl_0077BC48; // 0x0077BC48

D2WinControlStrc* gpNamesButton_0077BD08; // 0x0077BD08

char gszText_0077B1D0[8]; // 0x0077B1D0

char gszText_0077B0B4[28]; // 0x0077B0B4

static D2CriticalSectionStrc gtChatLock_0077AE28; // 0x0077AE28

D2WinControlStrc* gapControls_0077B050[2]; // 0x0077B050

D2WinControlStrc* gpControl_0077BC40; // 0x0077BC40

D2CellFileStrc* gpChatCellFile_0077BBFC; // 0x0077BBFC

// 0x0043DC50
static void __cdecl sub_0043DC50_CreateChatCellFile(D2LaunchCharInfoStrc* pInfo)
{
    int nMode = 5;
    const unsigned short wFlags = *(unsigned short*)pInfo->wFlags0x3CB;
    if ((wFlags & 4) && !(wFlags & 8) && (sub_00408F20_HasExpansionMpq() || pInfo->nValue0x1EE < 5))
        nMode = 1;
    gpChatCellFile_0077BBFC = (D2CellFileStrc*)sub_005066C0(pInfo->nValue0x1EE, nMode, pInfo->szText0x3A1, pInfo->szText0x3B1);
    if (gpChatCellFile_0077BBFC)
    {
        sub_005052B0(gpChatCellFile_0077BBFC, 0x42);
        sub_005052F0(gpChatCellFile_0077BBFC, 0x23B);
        sub_005051A0(gpChatCellFile_0077BBFC, 0);
        sub_00505260(gpChatCellFile_0077BBFC, 0);
    }
}

// 0x00441B70
int __fastcall sub_00441B70_RunChat(D2LaunchCharInfoStrc* pInfo)
{
    char szTitle[256];
    D2WinControlStrc* pControl8;
    D2WinControlStrc* pControl4;

    GetTickCount();
    if (!sub_005259C0(sub_004FAC80(sub_00408F20_HasExpansionMpq()), 0))
        return 1;

    gnLaunchMode_0077BBE4 = 0;
    gbDone_0077BDA0 = 0;
    gdwGlobal_0077BBF8 = 1;
    gpLaunchFuncs_0077B09C = pInfo->f_225;
    D2_ASSERT(gpLaunchFuncs_0077B09C, 3303);
    if (!gpLaunchFuncs_0077B09C->pfn0x68())
        gbDone_0077BDA0 = 4;
    else
    {
    sub_0043CC30_LoadFrontEndCels();
    sub_004F9160_SetLoopValue(gnLoopValueOut_0077BC14);
    gpChatTextBox_0077BD8C = 0;
    if (gpCharInfo_0077BBD8->szText0x361[0])
        BACKGROUND_SetCellFile(gpChatBackground_0077BC04);
    else
        BACKGROUND_SetCellFile(gpCellFile_0077BC08);
    if (gpCharInfo_0077BBD8->szText0x361[0])
    {
        for (int i = 0; i < 17; i++)
            gpChatControl_0077B058[i] = CONTROL_Create(&gatChatControlInits_0070CE50[i]);
        gpControl_0077BD98 = CONTROL_Create(&gtControlInit_0070D2A0);
    }
    else
    {
        sub_0043DDD0_CreateCharControls();
        CREATE_CELL_FILE(pInfo);
    }
    gpChatTextBox_0077BD8C = CONTROL_Create(&gtControlInit_0070D240);
    if (gpCharInfo_0077BBD8->szText0x361[0])
    {
        gpChatEdit_0077BD94 = CONTROL_Create(&gtControlInit_0070D270);
        sub_004FDAD0_SetKeyCallback(gpChatEdit_0077BD94, sub_0043F9B0_EditKey);
        sub_004FDB00_SetEnterCallback(gpChatEdit_0077BD94, sub_0043DB90);
        sub_004F91C0(gpChatEdit_0077BD94);
        sub_004FDD50_SetMaxLength(gpChatEdit_0077BD94, 200);
        sub_004477A0_Refresh();
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B084, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B088, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B08C, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B090, 1);
        D2WinControlStrc** ppButton = gapChatButtons_0077AD78;
        for (int nX = 40; nX < 700; nX += 60, ppButton++)
            *ppButton = BUTTON_Create(nX, 591, 60, 100, 0, (int)sub_00448C70_ButtonCallback, 0, 0, 4, 0, 0);
        gpChatControl_0077BC44 = CONTROL_Create(&gtControlInit_0070D210);
        sub_004F9740_SetControlState(gpChatControl_0077BC44, 0);
        gpChatControl_0077BC48 = CONTROL_Create(&gtControlInit_0070D390);
        if (gbToggle_0077BBEC)
            sub_00500B20_SetValue(gpChatControl_0077BC48, 2);
    }
    sub_0043F4D0();
    sub_0043F8C0_ResetLaunchState();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gnLaunchMode_0077BBE4 = 0;
    pControl8 = CONTROL_Create(&gtControlInit_0070D2D0);
    gpNamesButton_0077BD08 = CONTROL_Create(&gtControlInit_0070D300);
    gpControlMain_0077BC4C = CONTROL_Create(&gtControlInit_0070D330);
    sub_0044B220_SetCallback(sub_00440D10);
    sub_0044AA50_SendPacket12();
    sub_0043F730();
    pControl4 = CONTROL_Create(&gtControlInit_0070D360);
    const unsigned short wFlags = *(unsigned short*)gpCharInfo_0077BBD8->wFlags;
    if ((wFlags & 8) && (wFlags & 4))
    {
        sub_004F96F0_ControlClearState(gpControlA_0077B070, 0);
        sub_004F96F0_ControlClearState(gpControlB_0077B078, 0);
    }
    sub_004FA450_SetActive(gpControl_0077B080);
    gszText_0077B1D0[0] = 0;
    gszText_0077B0B4[0] = 0;
    sub_00514DB0_InitWaveSlots();
    sub_00514E10_LoadWave("data\\global\\sfx\\cursor\\button.wav");
    if (sub_00514D80())
        sub_005148F0_SetChannelValue(1);
    gbCheck_0077BD58 = gpCharInfo_0077BBD8->nType0x35E == 4;
    sub_004F96F0_ControlClearState(gpControlC_0077B07C, gbCheck_0077BD58 == 0);
    if (sub_00441A90())
    {
        sprintf(szTitle, "%s,%s", pInfo->szRealm0x22D, pInfo->szName0xBD);
        int nFlags = 0;
        if (*(unsigned short*)pInfo->wFlags & 0x20)
            nFlags = 1;
        if (gpCharInfo_0077BBD8->szText0x361[0])
            nFlags |= 2;
        gpLaunchFuncs_0077B09C->pfn0x54(pInfo->szName0xBD, szTitle, 0x25, pInfo->szText0x361, nFlags);
    }
    else
    {
        sub_00410610_WriteLogLine("[D2MULTI]  Could not restore MCP connection.");
        gpLaunchFuncs_0077B09C->pfn0x10();
    }
    if (gpLaunchFuncs_0077B09C->pfn0x68())
    {
        sub_00449E50_SetValue(0);
        InitializeCriticalSection(&gtChatLock_0077AE28);
        if (!gpCharInfo_0077BBD8->szText0x361[0])
            gpLaunchFuncs_0077B09C->pfn0xA8(sub_0043E4C0, sub_0043E570);
        sub_004FA590_RunLoop(sub_00441500);
        if (sub_00449E40())
        {
            sub_0044AA80_SendPacket13();
            sub_00449E50_SetValue(0);
        }
        if (!gpCharInfo_0077BBD8->szText0x361[0])
            gpLaunchFuncs_0077B09C->pfn0xAC();
        DeleteCriticalSection(&gtChatLock_0077AE28);
        gpLaunchFuncs_0077B09C->pfn0x58();
        if (gbDone_0077BDA0 != 4)
            D2MCPClientCloseMCP();
    }
    else
        gbDone_0077BDA0 = 4;

    GetTickCount();
    sub_00515070();
    sub_004495A0_ClearChannel();
    D2Win_10146();
    sub_0043F8C0_ResetLaunchState();
    sub_0043F800_FreeNameList();
    sub_004F95C0_ControlDestroy(&gpChatTextBox_0077BD8C);
    if (gpControl_0077BD98)
        sub_004F95C0_ControlDestroy(&gpControl_0077BD98);
    sub_004F95C0_ControlDestroy(&pControl8);
    sub_004F95C0_ControlDestroy(&pControl4);
    sub_004F95C0_ControlDestroy(&gpNamesButton_0077BD08);
    sub_004F95C0_ControlDestroy(&gpControlMain_0077BC4C);
    if (gpChatControl_0077BC48)
        sub_004F95C0_ControlDestroy(&gpChatControl_0077BC48);
    if (gpChatEdit_0077BD94)
        sub_004F95C0_ControlDestroy(&gpChatEdit_0077BD94);
    for (int j = 0; j < 11; j++)
    {
        if (gapChatButtons_0077AD78[j])
            sub_004F95C0_ControlDestroy(&gapChatButtons_0077AD78[j]);
        gapChatButtons_0077AD78[j] = 0;
    }
    sub_004F95C0_ControlDestroy(&gpChatControl_0077BC44);
    for (int k = 0; k < 17; k++)
    {
        if (gpChatControl_0077B058[k])
            sub_004F95C0_ControlDestroy(&gpChatControl_0077B058[k]);
        gpChatControl_0077B058[k] = 0;
    }
    if (!gpCharInfo_0077BBD8->szText0x361[0])
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
    sub_00524E40_UnloadStringTables();
    return 1;
}

#include "gen/data/Source/D2Multi/Unknown_0043DA50.inc"
