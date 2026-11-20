#include "D2Common.h"
#include "D2GameTypes.h"
#include "D2Win32Types.h"

typedef char* va_list;
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v) (ap = (va_list)&(v) + _INTSIZEOF(v))
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);       // 0x00413A40
extern "C" int __cdecl SStrVPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, va_list va); // 0x00413A80
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* sz);

extern D2CriticalSectionStrc gLogLock_0096CA30;                                                             // 0x0096CA30
extern _iobuf* gpLogFile_0096CA48;                                                                          // 0x0096CA48
extern int gbLogEnabled_0096CA4C;                                                                           // 0x0096CA4C

// 0x00624780
static void __stdcall sub_00624780(_iobuf* pFile, int nThreadId, int nLogLevel, int nComponent, int nSubsystem, const char* szContext, int nSequence, const char* szFormat, va_list va)
{
    if (!gbLogEnabled_0096CA4C)
        return;

    D2SystemTimeStrc tTime;
    char szBuffer[500];
    GetLocalTime(&tTime);
    const int nTime = SStrPrintf(szBuffer, 500, "%02u:%02u:%02u.%03u\t", tTime.wHour, tTime.wMinute, tTime.wSecond, tTime.wMilliseconds);
    char* pCursor = &szBuffer[nTime];
    int nRemaining = 500 - nTime;
    const int nFields = SStrPrintf(pCursor, nRemaining, "%01lu\t%01lu\t%01lu\t%02lu\t%.50s\t%.5lu\t", nThreadId, nLogLevel, nComponent, nSubsystem, szContext, nSequence);
    nRemaining -= nFields;
    pCursor += nFields;
    const int nLength = SStrVPrintf(pCursor, nRemaining, szFormat, va);
    strcat(pCursor + nLength, "\n");
    fwrite(szBuffer, strlen(szBuffer), 1, pFile);
    fflush(pFile);
}

void __cdecl sub_006248B0_StoreLoggingToFile(_iobuf* pFile, int nThreadId, int nLogLevel, int nComponent, int nSubsystem, const char* szContext, int nSequence, const char* szFormat, ...)
{
    va_list va;
    va_start(va, szFormat);
    sub_00624780(pFile, nThreadId, nLogLevel, nComponent, nSubsystem, szContext, nSequence, szFormat, va);
}

void __cdecl LOG_11100(int nThreadId, int nLogLevel, int nComponent, int nSubsystem, const char* szContext, int nSequence, const char* szFormat, ...)
{
    if (!gpLogFile_0096CA48)
        return;

    EnterCriticalSection(&gLogLock_0096CA30);
    va_list va;
    va_start(va, szFormat);
    sub_00624780(gpLogFile_0096CA48, nThreadId, nLogLevel, nComponent, nSubsystem, szContext, nSequence, szFormat, va);
    LeaveCriticalSection(&gLogLock_0096CA30);
}
