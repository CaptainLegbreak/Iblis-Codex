#include "Fog.h"
#include "D2GameTypes.h"
#include "D2FogTypes.h"
struct D2CrashInputStrc;

#define FOG_ASSERT(expr, line) if (!(expr)) { const char* szAssertFile = sub_00408090(); FOG_SOCKET_WSACleanup(); sub_00408900_RaiseErrorReport(6, &gszEmptyAssertText, line, "Unrecoverable internal error %08x", szAssertFile); sub_0040F960_CloseLogFiles(); exit(-1); }
struct D2CriticalSectionStrc;
struct D2InspectorInfoStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
void __cdecl sub_00408900_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...); // 0x00408900
void __cdecl sub_0040F960_CloseLogFiles(); // 0x0040F960
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464
extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args); // 0x00682F22
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" int __cdecl SStrPrintf(char* szDest, size_t nSize, const char* szFormat, ...); // 0x00413A40
const char* __fastcall sub_00408000_StripSourcePath(const char* szFile); // 0x00408000
void __cdecl sub_004106B0_LogWritePrefixed0(const char* szPrefix, const char* szFormat, ...); // 0x004106B0

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" int __cdecl atexit(void (__cdecl* pfnExit)()); // 0x00683824
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
void __cdecl sub_004016A0_StartDbgHelpThread(); // 0x004016A0
void __fastcall sub_00401740_SetText(const char* szText); // 0x00401740
void __fastcall sub_00403F60_SetCrashHandler(void* pfnHandler, void* pContext, int nUnused); // 0x00403F60
int __fastcall sub_00406B60_GetModuleDirectory(char* szPath, unsigned int nSize); // 0x00406B60
void __cdecl sub_004076B0_LogSystemInfo(); // 0x004076B0
void __cdecl AUTOMAP_CaptureSystemInfo(); // 0x00407DE0
void __cdecl sub_00407F20_ExitHandler(); // 0x00407F20
int __fastcall sub_004082E0_CrashHandler(D2CrashInputStrc* pInput); // 0x004082E0
int __cdecl sub_0040D5B0_LoadImageHlp(); // 0x0040D5B0
void __cdecl sub_00410540_InitLogSystem(); // 0x00410540
int __cdecl sub_00410960_IsPlatformNT(); // 0x00410960
void __cdecl sub_004109D0_InitTimeBase(); // 0x004109D0
void __cdecl sub_00411210_InitTimer(); // 0x00411210
void __fastcall sub_0041C0E0_SetCallback(void* pfnHandler); // 0x0041C0E0
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
extern unsigned int gdwInvBitMasks_006CE2E8[]; // 0x006CE2E8
extern D2CriticalSectionStrc gtLock_0074C830; // 0x0074C830
extern D2CriticalSectionStrc gtLock_0074D848; // 0x0074D848
extern int gbErrorMgrInit_0074F0D0; // 0x0074F0D0
int __fastcall FOG_GetInstallPath(char* szPath, unsigned int nSize); // 0x00406BA0
extern "C" const char gszExpansionMpq_006CD3A0[]; // 0x006CD3A0

extern D2PoolDirectoryStrc gtPoolManager_0074F0E8; // 0x0074F0E8

// 0x00408A60
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    sub_00408900_RaiseErrorReport(6, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    sub_0040F960_CloseLogFiles();
}

// 0x00408B20
void __fastcall sub_00408B20_ShowErrorBox(int nType, const char* szFile, int nLine, const char* szFormat, va_list args)
{
    char szCaption[0x100];
    char szMessage[0x1000];
    char szText[0x1000];
    char szBoxText[0x1000];
    if (szFile)
    {
        SStrPrintf(szMessage, 0x1000, "--------  FILE: %s    LINE: %d  --------\n\n", sub_00408000_StripSourcePath(szFile), nLine);
        sub_004106B0_LogWritePrefixed0(&gszEmptyAssertText, gszStringFormat_006FFC58, szMessage);
    }
    FOG_ASSERT(szFormat, 0x8DE);
    _vsnprintf(szMessage, 0x1000, szFormat, args);
    szMessage[0xFFF] = 0;
    if (szFile)
    {
        SStrPrintf(szText, 0x1000, "%s\nLocation : %s, line #%d\nExpression : %s", gaszErrorTypeNames_00706654[nType], sub_00408000_StripSourcePath(szFile), nLine, szMessage);
    }
    else
    {
        strcpy(szText, szMessage);
    }
    SStrPrintf(szCaption, 0x100, "%s Error", "Diablo II");
    strcpy(szBoxText, szText);
    strcat(szText, "\n");
    sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, gszStringFormat_006FFC58, szText);
    sub_0040F960_CloseLogFiles();
    MessageBoxA(0, szBoxText, szCaption, 0x30);
}

char gszVersion_0074C848[4096]; // 0x0074C848

D2InspectorInfoStrc gtInspectorInfo_0074D868; // 0x0074D868

char gszInspectorVersion_0074D8C8[4096]; // 0x0074D8C8

int gnValue_0074F0CC; // 0x0074F0CC

unsigned long gdwRegValue_0074F0E0; // 0x0074F0E0

// 0x00408CE0
void __fastcall FOG_InitErrorMgr(const char* szProgramName, const char* szVersion, int bLogToFile)
{
    char szPath[0x1000];
    if (gbErrorMgrInit_0074F0D0)
    {
        if (bLogToFile)
        {
            sub_004076B0_LogSystemInfo();
        }
        return;
    }
    sub_004016A0_StartDbgHelpThread();
    sub_00403F60_SetCrashHandler(sub_004082E0_CrashHandler, 0, 0);
    if (sub_00406B60_GetModuleDirectory(szPath, 0x1000))
    {
        sub_00401740_SetText(szPath);
    }
    gtInspectorInfo_0074D868.f_0 = 0x108;
    gtInspectorInfo_0074D868.szUnused04 = "Diablo II";
    gtInspectorInfo_0074D868.szApplication = "Diablo II";
    gtInspectorInfo_0074D868.szModule = "Diablo II";
    sprintf(gszInspectorVersion_0074D8C8, "D2 %i.%i%c", 1, 14, 'd');
    gtInspectorInfo_0074D868.szMilestone = gszInspectorVersion_0074D8C8;
    gtInspectorInfo_0074D868.szBuildNumber = "77";
    gtInspectorInfo_0074D868.f_18 = "Windows";
    gtInspectorInfo_0074D868.szPrimaryAssignment = ".ClassicErrorReporter";
    gtInspectorInfo_0074D868.szAssignments = ".ClassicErrorReporter";
    if (szVersion)
    {
        SStrCopy(gszVersion_0074C848, szVersion, 0x1000);
    }
    gnValue_0074F0CC = sub_00410960_IsPlatformNT();
    InitializeCriticalSection(&gtLock_0074C830);
    InitializeCriticalSection(&gtLock_0074D848);
    gbErrorMgrInit_0074F0D0 = 1;
    sub_004109D0_InitTimeBase();
    unsigned long dwValue = 0;
    SRegLoadValue("Diablo II", "TraceUnfreedMemory", 0, &dwValue);
    gdwRegValue_0074F0E0 = dwValue;
    sub_00409DD0_InitPoolSystem(0, "Global Pool System", 0x40000, 0x8000);
    sub_00411210_InitTimer();
    for (int i = 0; i < 0x20; ++i)
    {
        const unsigned int nMask = 1 << i;
        FOG_ASSERT(gdwBitMasks_006CE268[i] == nMask, 0x576);
        FOG_ASSERT(gdwInvBitMasks_006CE2E8[i] == ~nMask, 0x577);
    }
    AUTOMAP_CaptureSystemInfo();
    sub_00410540_InitLogSystem();
    if (bLogToFile)
    {
        sub_004076B0_LogSystemInfo();
    }
    atexit(sub_00407F20_ExitHandler);
    sub_0040D5B0_LoadImageHlp();
    sub_0041C0E0_SetCallback(sub_00408660_ShowErrorReport);
}

static int s_bExpansionChecked_0074F0DC; // 0x0074F0DC

static int s_bExpansionMpq_0074F0D8; // 0x0074F0D8

static int FOG_FileExists(const char* szFile)
{
    return GetFileAttributesA(szFile) != (unsigned long)-1;
}

// 0x00408F20
int __cdecl sub_00408F20_HasExpansionMpq()
{
    if (!s_bExpansionChecked_0074F0DC)
    {
        char szPath[0x104];
        s_bExpansionChecked_0074F0DC = 1;
        FOG_GetInstallPath(szPath, 0x104);
        SStrPack(szPath, gszExpansionMpq_006CD3A0, 0x104);
        int bExists = FOG_FileExists(szPath);
        if (!bExists)
        {
            SStrCopy(szPath, gszExpansionMpq_006CD3A0, 0x104);
            bExists = FOG_FileExists(szPath);
        }
        if (bExists)
            s_bExpansionMpq_0074F0D8 = 1;
    }
    return s_bExpansionMpq_0074F0D8;
}

// 0x00409000
int __fastcall sub_00409000_GetBitWidth(unsigned int nValue)
{
    if (!nValue)
    {
        return 0;
    }
    __asm
    {
        bsr eax, nValue
        inc eax
        mov nValue, eax
    }
    return nValue;
}

static inline int Log2Ceil(int nValue)
{
    if (nValue < 3)
    {
        return 1;
    }
    return sub_00409000_GetBitWidth(nValue - 1);
}

// 0x004091B0
static int sub_004091B0_GetPoolIndex(int nSize)
{
    if (nSize <= 0x10)
    {
        return 0;
    }
    return Log2Ceil(nSize) - 4;
}

int __fastcall sub_M289_Emit_004091B0(int nUnused, int nSize)
{
    return sub_004091B0_GetPoolIndex(nSize);
}

// 0x00409200
static int sub_00409200_GetBlockSize(int nIndex)
{
    if (!nIndex)
    {
        return 0x10;
    }
    return 1 << (nIndex + 4);
}

int __fastcall sub_M126_Emit_00409200(int a, int nIndex, int nUnused)
{
    return sub_00409200_GetBlockSize(nIndex) + a;
}

// 0x004099C0
static D2PoolSystemStrc* sub_004099C0_GetPoolSystem(D2PoolSystemStrc* pSystem)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    return pSystem;
}

D2PoolSystemStrc* __fastcall sub_M126_Emit_004099C0(int a, D2PoolSystemStrc* pSystem, int nUnused)
{
    return sub_004099C0_GetPoolSystem(pSystem);
}

// 0x004095D0
void __cdecl sub_004095D0_Nop()
{
}

// 0x00409C70
void __cdecl sub_00409C70_Nop()
{
}

// 0x0047B4D0
void __cdecl sub_0047B4D0_Nop()
{
}

// 0x004BF9C0
void __cdecl sub_004BF9C0_Nop()
{
}

// 0x0050B7A0
void __cdecl sub_0050B7A0_Nop()
{
}

// 0x00408A90
void __cdecl FOG_DisplayWarning(const char* szMsg, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    sub_00408900_RaiseErrorReport(7, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    sub_0040F960_CloseLogFiles();
}

// 0x00408AC0
void __cdecl sub_00408AC0_DisplayDeadlock(unsigned long dwThreadId, int nTicks)
{
    FOG_SOCKET_WSACleanup();
    sub_00408900_RaiseErrorReport(10, (const char*)dwThreadId, 2175, "Deadlocked in thread %X for %d ticks", dwThreadId, nTicks);
    sub_0040F960_CloseLogFiles();
}

// 0x00408AF0
void __cdecl FOG_DisplayError(int nCategory, const char* szMsg, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    sub_00408900_RaiseErrorReport(nCategory, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    sub_0040F960_CloseLogFiles();
}

// 0x00408A30
void __cdecl FOG_DisplayAssert(const char* szMsg, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    sub_00408900_RaiseErrorReport(5, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    sub_0040F960_CloseLogFiles();
}
