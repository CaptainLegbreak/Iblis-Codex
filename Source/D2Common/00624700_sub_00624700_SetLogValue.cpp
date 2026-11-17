struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct _iobuf;

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode);                               // 0x0068239A
extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC
void __cdecl LOG_11100(int nThreadId, int nLogLevel, int nComponent, int nSubsystem, const char* szContext, int nSequence, const char* szFormat, ...); // 0x006248E0

D2CriticalSectionStrc gLogLock_0096CA30;                                                                    // 0x0096CA30
_iobuf* gpLogFile_0096CA48;                                                                                 // 0x0096CA48
int gbLogEnabled_0096CA4C;                                                                                  // 0x0096CA4C
int gnLogValue_0096CA50;                                                                                    // 0x0096CA50

// 0x00624700
void __fastcall sub_00624700_SetLogValue(int nValue)
{
    gnLogValue_0096CA50 = nValue;
}

// 0x00624720
static _iobuf* sub_00624720_OpenLogFile(const char* szFileName)
{
    return fopen(szFileName, "wt");
}

// 0x00624730
static void sub_00624730_CloseLogFile(_iobuf* pFile)
{
    fclose(pFile);
}

// 0x00624AC0
int __fastcall sub_00624AC0_OpenLog(const char* szFileName)
{
    if (!gpLogFile_0096CA48)
    {
        gpLogFile_0096CA48 = sub_00624720_OpenLogFile(szFileName);
        if (!gpLogFile_0096CA48)
            return 0;
        InitializeCriticalSection(&gLogLock_0096CA30);
        LOG_11100(1, 8, 2, 0x80000, ".\\Logging\\Logging.cpp", 249, "Log Started");
    }
    return 1;
}

// 0x00624B20
void __cdecl sub_00624B20_CloseLog()
{
    if (gpLogFile_0096CA48)
    {
        sub_00624730_CloseLogFile(gpLogFile_0096CA48);
        DeleteCriticalSection(&gLogLock_0096CA30);
        gpLogFile_0096CA48 = 0;
    }
}

// 0x00624B50
void __fastcall sub_00624B50(int bEnable)
{
    gbLogEnabled_0096CA4C = bEnable;
    if (bEnable)
    {
        sub_00624AC0_OpenLog("d2log.txt");
        return;
    }
    sub_00624B20_CloseLog();
}
