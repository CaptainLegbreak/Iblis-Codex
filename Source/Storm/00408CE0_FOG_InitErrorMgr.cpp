struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2InspectorInfoStrc
{
    int f_0;
    const char* szUnused04;
    const char* szApplication;
    const char* szModule;
    const char* szMilestone;
    const char* szBuildNumber;
    const char* f_18;
    const char* szPrimaryAssignment;
    const char* szAssignments;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
int __fastcall FOG_SOCKET_WSACleanup();                                                                     // 0x0040D8D0
void __cdecl sub_00408900_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...); // 0x00408900
void __cdecl sub_0040F960_CloseLogFiles();                                                                  // 0x0040F960
#define FOG_ASSERT(expr, line) if (!(expr)) { const char* szAssertFile = sub_00408090(); FOG_SOCKET_WSACleanup(); sub_00408900_RaiseErrorReport(6, &gszEmptyAssertText, line, "Unrecoverable internal error %08x", szAssertFile); sub_0040F960_CloseLogFiles(); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" int __cdecl atexit(void (__cdecl* pfnExit)());                                                   // 0x00683824
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void __cdecl sub_004016A0_StartDbgHelpThread();                                                             // 0x004016A0
void __fastcall sub_00401740_SetText(const char* szText);                                                   // 0x00401740
void __fastcall sub_00403F60_SetCrashHandler(void* pfnHandler, void* pContext, int nUnused);                // 0x00403F60
int __fastcall sub_00406B60_GetModuleDirectory(char* szPath, int nSize);                                    // 0x00406B60
void __cdecl sub_004076B0_LogSystemInfo();                                                                  // 0x004076B0
void __cdecl sub_00407DE0_InitStep();                                                                       // 0x00407DE0
void __cdecl sub_00407F20_ExitHandler();                                                                    // 0x00407F20
void __cdecl sub_004082E0_CrashHandler();                                                                   // 0x004082E0
void __fastcall sub_00408660_ShowErrorReport(const char* szText, const char* szMessage, int nArg3, int nArg4, int nLine, int nArg6); // 0x00408660
void __cdecl sub_00409DD0_InitPoolSystem(void* pReserved, const char* szName, int nSize, int nBlockSize);   // 0x00409DD0
void __cdecl sub_0040D5B0_InitStep();                                                                       // 0x0040D5B0
void __cdecl sub_00410540_InitStep();                                                                       // 0x00410540
int __cdecl sub_00410960_GetValue();                                                                        // 0x00410960
void __cdecl sub_004109D0_InitTimeBase();                                                                   // 0x004109D0
void __cdecl sub_00411210_InitStep();                                                                       // 0x00411210
void __fastcall sub_0041C0E0_SetReportHandler(void* pfnHandler);                                            // 0x0041C0E0

extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268
extern unsigned int gdwInvBitMasks_006CE2E8[];                                                              // 0x006CE2E8
extern D2CriticalSectionStrc gtLock_0074C830;                                                               // 0x0074C830
char gszVersion_0074C848[4096];                                                                             // 0x0074C848
extern D2CriticalSectionStrc gtLock_0074D848;                                                               // 0x0074D848
D2InspectorInfoStrc gtInspectorInfo_0074D868;                                                               // 0x0074D868
char gszInspectorVersion_0074D8C8[4096];                                                                    // 0x0074D8C8
int gnValue_0074F0CC;                                                                                       // 0x0074F0CC
extern int gbErrorMgrInit_0074F0D0;                                                                         // 0x0074F0D0
unsigned long gdwRegValue_0074F0E0;                                                                         // 0x0074F0E0

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
    gnValue_0074F0CC = sub_00410960_GetValue();
    InitializeCriticalSection(&gtLock_0074C830);
    InitializeCriticalSection(&gtLock_0074D848);
    gbErrorMgrInit_0074F0D0 = 1;
    sub_004109D0_InitTimeBase();
    unsigned long dwValue = 0;
    SRegLoadValue("Diablo II", "TraceUnfreedMemory", 0, &dwValue);
    gdwRegValue_0074F0E0 = dwValue;
    sub_00409DD0_InitPoolSystem(0, "Global Pool System", 0x40000, 0x8000);
    sub_00411210_InitStep();
    for (int i = 0; i < 0x20; ++i)
    {
        const unsigned int nMask = 1 << i;
        FOG_ASSERT(gdwBitMasks_006CE268[i] == nMask, 0x576);
        FOG_ASSERT(gdwInvBitMasks_006CE2E8[i] == ~nMask, 0x577);
    }
    sub_00407DE0_InitStep();
    sub_00410540_InitStep();
    if (bLogToFile)
    {
        sub_004076B0_LogSystemInfo();
    }
    atexit(sub_00407F20_ExitHandler);
    sub_0040D5B0_InitStep();
    sub_0041C0E0_SetReportHandler(sub_00408660_ShowErrorReport);
}
