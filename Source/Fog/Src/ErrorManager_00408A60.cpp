#include "Fog.h"
#include "D2GameTypes.h"
#include "D2FogTypes.h"
struct D2CrashInputStrc;

#define FOG_ASSERT(expr, line) if (!(expr)) { const char* szAssertFile = sub_00408090(); FOG_SOCKET_WSACleanup(); ERRORMANAGER_RaiseErrorReport(6, &gszEmptyAssertText, line, "Unrecoverable internal error %08x", szAssertFile); LOGMANAGER_CloseLogFiles(); exit(-1); }
struct D2CriticalSectionStrc;
struct D2InspectorInfoStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
void __cdecl ERRORMANAGER_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...); // 0x00408900
void __cdecl LOGMANAGER_CloseLogFiles(); // 0x0040F960
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464
extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args); // 0x00682F22
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" int __cdecl SStrPrintf(char* szDest, size_t nSize, const char* szFormat, ...); // 0x00413A40
const char* __fastcall ERRORMANAGER_StripSourcePath(const char* szFile); // 0x00408000
void __cdecl LOGMANAGER_LogWritePrefixedNoNewline(const char* szPrefix, const char* szFormat, ...); // 0x004106B0

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" int __cdecl atexit(void (__cdecl* pfnExit)()); // 0x00683824
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
void __cdecl ERRORMANAGER_StartDbgHelpThread(); // 0x004016A0
void __fastcall ERRORMANAGER_SetReportText(const char* szText); // 0x00401740
void __fastcall ERRORMANAGER_SetCrashHandler(void* pfnHandler, void* pContext, int nUnused); // 0x00403F60
int __fastcall ERRORMANAGER_GetModuleDirectory(char* szPath, unsigned int nSize); // 0x00406B60
void __cdecl ERRORMANAGER_LogSystemInfo(); // 0x004076B0
void __cdecl AUTOMAP_CaptureSystemInfo(); // 0x00407DE0
void __cdecl ERRORMANAGER_ExitHandler(); // 0x00407F20
int __fastcall ERRORMANAGER_CrashHandler(D2CrashInputStrc* pInput); // 0x004082E0
int __cdecl sub_0040D5B0_LoadImageHlp(); // 0x0040D5B0
void __cdecl EXCEPTIONS_InitLogSystem(); // 0x00410540
int __cdecl sub_00410960_IsPlatformNT(); // 0x00410960
void __cdecl SYSTEM_InitTimeBase(); // 0x004109D0
void __cdecl sub_00411210_InitTimer(); // 0x00411210
void __fastcall sub_0041C0E0_SetCallback(void* pfnHandler); // 0x0041C0E0
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8
extern D2CriticalSectionStrc gtLock_0074C830; // 0x0074C830
extern D2CriticalSectionStrc gtLock_0074D848; // 0x0074D848
extern int gbErrorMgrInit; // 0x0074F0D0
int __fastcall FOG_GetInstallPath(char* szPath, unsigned int nSize); // 0x00406BA0
extern "C" const char gszExpansionMpq[]; // 0x006CD3A0

extern D2PoolDirectoryStrc gtPoolManager; // 0x0074F0E8

// 0x00408A60
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    ERRORMANAGER_RaiseErrorReport(6, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    LOGMANAGER_CloseLogFiles();
}

char gszVersion[4096]; // 0x0074C848

D2InspectorInfoStrc gtInspectorInfo; // 0x0074D868

char gszInspectorVersion[4096]; // 0x0074D8C8

int gbIsPlatformNT; // 0x0074F0CC

unsigned long gdwRegValue; // 0x0074F0E0

// 0x00408CE0
void __fastcall FOG_InitErrorMgr(const char* szProgramName, const char* szVersion, int bLogToFile)
{
    char szPath[0x1000];
    if (gbErrorMgrInit)
    {
        if (bLogToFile)
        {
            ERRORMANAGER_LogSystemInfo();
        }
        return;
    }
    ERRORMANAGER_StartDbgHelpThread();
    ERRORMANAGER_SetCrashHandler(ERRORMANAGER_CrashHandler, 0, 0);
    if (ERRORMANAGER_GetModuleDirectory(szPath, 0x1000))
    {
        ERRORMANAGER_SetReportText(szPath);
    }
    gtInspectorInfo.f_0 = 0x108;
    gtInspectorInfo.szUnused04 = "Diablo II";
    gtInspectorInfo.szApplication = "Diablo II";
    gtInspectorInfo.szModule = "Diablo II";
    sprintf(gszInspectorVersion, "D2 %i.%i%c", 1, 14, 'd');
    gtInspectorInfo.szMilestone = gszInspectorVersion;
    gtInspectorInfo.szBuildNumber = "77";
    gtInspectorInfo.f_18 = "Windows";
    gtInspectorInfo.szPrimaryAssignment = ".ClassicErrorReporter";
    gtInspectorInfo.szAssignments = ".ClassicErrorReporter";
    if (szVersion)
    {
        SStrCopy(gszVersion, szVersion, 0x1000);
    }
    gbIsPlatformNT = sub_00410960_IsPlatformNT();
    InitializeCriticalSection(&gtLock_0074C830);
    InitializeCriticalSection(&gtLock_0074D848);
    gbErrorMgrInit = 1;
    SYSTEM_InitTimeBase();
    unsigned long dwValue = 0;
    SRegLoadValue("Diablo II", "TraceUnfreedMemory", 0, &dwValue);
    gdwRegValue = dwValue;
    sub_00409DD0_InitPoolSystem(0, "Global Pool System", 0x40000, 0x8000);
    sub_00411210_InitTimer();
    for (int i = 0; i < 0x20; ++i)
    {
        const unsigned int nMask = 1 << i;
        FOG_ASSERT(gdwBitMasks_006CE268[i] == nMask, 0x576);
        FOG_ASSERT(gdwInvBitMasks[i] == ~nMask, 0x577);
    }
    AUTOMAP_CaptureSystemInfo();
    EXCEPTIONS_InitLogSystem();
    if (bLogToFile)
    {
        ERRORMANAGER_LogSystemInfo();
    }
    atexit(ERRORMANAGER_ExitHandler);
    sub_0040D5B0_LoadImageHlp();
// build: symbol ?ERRORMANAGER_ShowErrorReport@* 0x00408660
    sub_0041C0E0_SetCallback(ERRORMANAGER_ShowErrorReport);
}

static int gbExpansionChecked; // 0x0074F0DC

static int gbExpansionMpq; // 0x0074F0D8

static int FOG_FileExists(const char* szFile)
{
    return GetFileAttributesA(szFile) != (unsigned long)-1;
}
