#include "D2BNClient.h"

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218

D2CriticalSectionStrc gBnLogLock_00881860;                                                                  // 0x00881860

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

static D2BnLogStrc& sub_00518C30_GetLog()
{
    static D2BnLogStrc tLog_00881878; // 0x00881878
    return tLog_00881878;
}

// build: symbol ?$S1@?1??sub_00518C30_GetLog@@YAAAUD2BnLogStrc@@XZ@4IA 0x0088187C
// build: symbol ??__FtLog_00881878@?1??sub_00518C30_GetLog@@YAAAUD2BnLogStrc@@XZ@YAXXZ 0x006CB430
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

// 0x00518D40
void __cdecl sub_00518D40_Log(const char* szFormat, ...)
{
    char szBuffer[0x200];
    EnterCriticalSection(&gBnLogLock_00881860);
    _vsnprintf(szBuffer, sizeof(szBuffer), szFormat, (char*)(&szFormat + 1));
    szBuffer[sizeof(szBuffer) - 1] = 0;
    SLogWrite(sub_00518C30_GetLog().hLog, szBuffer);
    LeaveCriticalSection(&gBnLogLock_00881860);
}
