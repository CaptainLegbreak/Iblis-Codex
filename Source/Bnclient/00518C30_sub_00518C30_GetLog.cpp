struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern "C" int __cdecl _vsnprintf(char* szDest, unsigned int nCount, const char* szFormat, char* pArgs);   // 0x00682F22
void __stdcall SLogClose(void* hLog);                                                                       // 0x0041FD00
int __stdcall SLogCreate(const char* szFileName, unsigned int nFlags, void** phLog);                        // 0x0041FD40
void __stdcall sub_00420120_LogAdjust(void* hLog, int nValue);                                              // 0x00420120
int __cdecl SLogWrite(void* hLog, const char* szFormat, ...);                                               // 0x00420190

extern D2CriticalSectionStrc gBnLogLock_00881860;                                                           // 0x00881860

struct D2BnLogStrc
{
    void* hLog;

    D2BnLogStrc()
    {
        SLogCreate("BnetLog.txt", 0, &hLog);
    }

    ~D2BnLogStrc()
    {
        SLogClose(hLog);
    }
};

// build: symbol ?$S1@?1??sub_00518C30_GetLog@@YAAAUD2BnLogStrc@@XZ@4IA 0x0088187C
// build: symbol ??__FtLog_00881878@?1??sub_00518C30_GetLog@@YAAAUD2BnLogStrc@@XZ@YAXXZ 0x006CB430
// 0x00518C30
static D2BnLogStrc& sub_00518C30_GetLog()
{
    static D2BnLogStrc tLog_00881878; // 0x00881878
    return tLog_00881878;
}

// 0x00518C70
int __cdecl sub_00518C70_StartLogging(int nMode, int nValue)
{
    int nResult = 0;
    EnterCriticalSection(&gBnLogLock_00881860);
    if (nMode == 1)
    {
        SLogClose(sub_00518C30_GetLog().hLog);
        SLogCreate("BnetLog.txt", 0, &sub_00518C30_GetLog().hLog);
        nResult = 1;
    }
    else if (nMode == 2)
    {
        sub_00420120_LogAdjust(sub_00518C30_GetLog().hLog, nValue);
    }
    LeaveCriticalSection(&gBnLogLock_00881860);
    return nResult;
}

// build: context sub_00518D40_Log
void __cdecl sub_00518D40_Log(const char* szFormat, ...)
{
    char szBuffer[0x200];
    EnterCriticalSection(&gBnLogLock_00881860);
    _vsnprintf(szBuffer, sizeof(szBuffer), szFormat, (char*)(&szFormat + 1));
    szBuffer[sizeof(szBuffer) - 1] = 0;
    SLogWrite(sub_00518C30_GetLog().hLog, szBuffer);
    LeaveCriticalSection(&gBnLogLock_00881860);
}
