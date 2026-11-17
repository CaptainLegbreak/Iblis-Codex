struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};
struct D2PoolSystemStrc;
struct _iobuf;

namespace crashy
{
class Report
{
public:
    Report();
    virtual ~Report();
    int sub_00401380(const char* szFormat, ...);                                  // 0x00401380

    _iobuf* m_pFile;
};
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
void __cdecl FOG_AsyncDataDestroy();                                                                        // 0x0040A440
void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem);                                        // 0x00409C80
int __cdecl sub_0040B500_UnloadImageHlp();                                                                  // 0x0040B500
void __cdecl sub_0040F8A0_CloseLogFilesNow();                                                               // 0x0040F8A0
void __cdecl sub_004107A0_DeleteTimeLock();                                                                 // 0x004107A0
void __cdecl sub_0040FFD0_ShutdownLogSystem();                                                              // 0x0040FFD0

extern "C" const char gszStringFormat_006FFC58[];                                                           // 0x006FFC58
D2CriticalSectionStrc gtLock_0074C830;                                                                      // 0x0074C830
D2CriticalSectionStrc gtLock_0074D848;                                                                      // 0x0074D848
int gbErrorMgrInit_0074F0D0;                                                                                // 0x0074F0D0

// 0x00407980
void __fastcall sub_00407980_ReportPrint(void* pContext, const char* szText)
{
    ((crashy::Report*)pContext)->sub_00401380(gszStringFormat_006FFC58, szText);
}

// 0x00407F20
void __cdecl sub_00407F20_ExitHandler()
{
    if (gbErrorMgrInit_0074F0D0)
    {
        FOG_AsyncDataDestroy();
        FOG_DestroyMemoryPoolSystem(0);
        sub_0040B500_UnloadImageHlp();
        sub_0040F8A0_CloseLogFilesNow();
        sub_004107A0_DeleteTimeLock();
        sub_0040FFD0_ShutdownLogSystem();
        gbErrorMgrInit_0074F0D0 = 0;
        DeleteCriticalSection(&gtLock_0074C830);
        DeleteCriticalSection(&gtLock_0074D848);
    }
}
