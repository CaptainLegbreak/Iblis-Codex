struct D2CriticalSectionStrc
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

struct D2CrashGuidStrc
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned long Data4[2];
};

struct D2CrashModuleStrc
{
    void* f_0;
    unsigned long nSize;
    char szName[0x100];
    char szPath[0x100];
    unsigned long nTimeStamp;
    D2CrashGuidStrc tGuid;
    unsigned long nAge;
    unsigned long nUnknown220;
    unsigned long nVersion;

    D2CrashModuleStrc();
};

struct D2CrashModuleListStrc
{
    unsigned int nCount;
    D2CrashModuleStrc aModules[0x100];
};

struct D2CrashRecord24Strc
{
    int n00;
    int n04;
    int n08;
    int n0C;
    char b10;
    int n14;
    int n18;
    int n1C;
    int n20;

    D2CrashRecord24Strc();
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);   // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC1FC
extern "C" __declspec(dllimport) void* __stdcall CreateEventW(void* pAttributes, int bManualReset, int bInitialState, const wchar_t* szName); // 0x006CC2A4
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void* pParam), void* pParam, unsigned long dwFlags, unsigned long* pThreadId); // 0x006CC250
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();                                         // 0x006CC284
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134

unsigned long __stdcall sub_004027C0_DbgHelpThreadProc(void* pParam);                                       // 0x004027C0
void __stdcall sub_M127_EmitSink(D2CrashGuidStrc* pGuid);

extern void* ghProcess_0074C6F0;                                                                            // 0x0074C6F0
extern bool gbSymInitialized_0098A6B0;                                                                      // 0x0098A6B0
bool gbMiniDumpEnabled_0098A6B1;                                                                            // 0x0098A6B1
void* gpfnSymCleanup_0098A6B8;                                                                              // 0x0098A6B8
void* ghDbgHelpDoneEvent_0098A6BC;                                                                          // 0x0098A6BC
void* ghDbgHelpWorkEvent_0098A6C0;                                                                          // 0x0098A6C0
D2CriticalSectionStrc gtDbgHelpRequestLock_0098A6C4;                                                        // 0x0098A6C4
extern D2CriticalSectionStrc gtSymbolLock_0098A6F0;                                                         // 0x0098A6F0
void* ghDbgHelpThread_00992B08;                                                                             // 0x00992B08
unsigned long gdwDbgHelpThreadId_00992B0C;                                                                  // 0x00992B0C

typedef int (__stdcall* SymCleanupFn)(void* hProcess);

// 0x00402980
void __cdecl sub_00402980_StartDbgHelpWorker()
{
    InitializeCriticalSection(&gtSymbolLock_0098A6F0);
    InitializeCriticalSection(&gtDbgHelpRequestLock_0098A6C4);
    ghDbgHelpWorkEvent_0098A6C0 = CreateEventW(0, 0, 0, 0);
    ghDbgHelpDoneEvent_0098A6BC = CreateEventW(0, 0, 0, 0);
    ghDbgHelpThread_00992B08 = CreateThread(0, 0x40000, sub_004027C0_DbgHelpThreadProc, 0, 0x10000, &gdwDbgHelpThreadId_00992B0C);
    gbMiniDumpEnabled_0098A6B1 = IsDebuggerPresent() != 1;
}

// 0x004029F0
void __cdecl sub_004029F0_StopDbgHelpWorker()
{
    SetEvent(ghDbgHelpWorkEvent_0098A6C0);
    WaitForSingleObject(ghDbgHelpThread_00992B08, 0xFFFFFFFF);
    CloseHandle(ghDbgHelpThread_00992B08);
    ghDbgHelpThread_00992B08 = 0;
    gdwDbgHelpThreadId_00992B0C = 0;
    CloseHandle(ghDbgHelpDoneEvent_0098A6BC);
    CloseHandle(ghDbgHelpWorkEvent_0098A6C0);
    DeleteCriticalSection(&gtDbgHelpRequestLock_0098A6C4);
    DeleteCriticalSection(&gtSymbolLock_0098A6F0);
    if (gbSymInitialized_0098A6B0)
    {
        ((SymCleanupFn)gpfnSymCleanup_0098A6B8)(ghProcess_0074C6F0);
        gbSymInitialized_0098A6B0 = false;
    }
}

// 0x00402B50
static __forceinline void sub_00402B50_SetProcessHandle(void* hProcess)
{
    ghProcess_0074C6F0 = hProcess;
}

// 0x00402B60
D2CrashRecord24Strc::D2CrashRecord24Strc()
{
    n00 = 0;
    n04 = 0;
    n08 = 0;
    n0C = 0;
    b10 = 0;
    n14 = 0;
    n18 = 0;
    n1C = 0;
    n20 = 0;
}

// 0x00402B80
static __forceinline void sub_00402B80_ClearGuid(D2CrashGuidStrc* pGuid)
{
    pGuid->Data1 = 0;
    pGuid->Data2 = 0;
    pGuid->Data3 = 0;
    pGuid->Data4[0] = 0;
    pGuid->Data4[1] = 0;
}

// 0x00402BA0
static __forceinline void sub_00402BA0_ClearGuidB(D2CrashGuidStrc* pGuid)
{
    pGuid->Data1 = 0;
    pGuid->Data2 = 0;
    pGuid->Data3 = 0;
    pGuid->Data4[0] = 0;
    pGuid->Data4[1] = 0;
}

// 0x00402BC0
D2CrashModuleStrc::D2CrashModuleStrc()
{
    f_0 = 0;
    nSize = 0;
    nTimeStamp = 0;
    tGuid.Data1 = 0;
    tGuid.Data2 = 0;
    tGuid.Data3 = 0;
    tGuid.Data4[0] = 0;
    tGuid.Data4[1] = 0;
    nAge = 0;
    nUnknown220 = 0;
    nVersion = 0;
    szName[0] = 0;
    szPath[0] = 0;
}

// 0x00402C30
bool __fastcall sub_00402C30_AddModule(const D2CrashModuleStrc* pModule, D2CrashModuleListStrc* pList)
{
    if (!pList)
    {
        return false;
    }
    pList->aModules[pList->nCount] = *pModule;
    ++pList->nCount;
    return pList->nCount < 0x100;
}

void __fastcall sub_M127_Emit_00402B50(void* hProcess, D2CrashGuidStrc* pGuid)
{
    sub_00402B50_SetProcessHandle(hProcess);
    sub_00402B80_ClearGuid(pGuid);
    sub_M127_EmitSink(pGuid);
    sub_00402BA0_ClearGuidB(pGuid + 1);
    sub_M127_EmitSink(pGuid + 1);
}
