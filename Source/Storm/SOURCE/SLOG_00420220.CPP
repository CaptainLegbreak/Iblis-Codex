#include "D2GameTypes.h"
#include "Storm.h"
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
void __stdcall SLogClose(void* hLog);                                                                       // 0x0041FD00
void __cdecl SLogFlushAll();                                                                                // 0x0041FFF0
void __stdcall SErrReportResourceLeak(const char* szName);                                           // 0x0041D1E0
extern D2CriticalSectionStrc gaSLogLocks_00779238[4];                                                       // 0x00779238
extern D2SLogStrc* gapSLogBuckets_00779298[4];                                                              // 0x00779298

// 0x00420220
void __cdecl SLogDestroy()
{
    SLogFlushAll();
    D2CriticalSectionStrc* pLock = gaSLogLocks_00779238;
    D2SLogStrc** ppBucket = gapSLogBuckets_00779298;
    for (int n = 4; n; --n)
    {
        EnterCriticalSection(pLock);
        while (*ppBucket)
        {
            SLogClose((*ppBucket)->hLog);
            SErrReportResourceLeak("HSLOG");
        }
        LeaveCriticalSection(pLock);
        ++ppBucket;
        ++pLock;
    }
    pLock = gaSLogLocks_00779238;
    for (int n = 4; n; --n)
    {
        DeleteCriticalSection(pLock);
        ++pLock;
    }
}
