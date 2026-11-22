#include "D2Common.h"
#include "D2GameTypes.h"
#include "D2Win32Types.h"


extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode);                               // 0x0068239A
extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC
void __cdecl LOG_11100(int nThreadId, int nLogLevel, int nComponent, int nSubsystem, const char* szContext, int nSequence, const char* szFormat, ...); // 0x006248E0

D2CriticalSectionStrc gLogLock;                                                                    // 0x0096CA30
_iobuf* gpLogFile;                                                                                 // 0x0096CA48
int gbLogEnabled;                                                                                  // 0x0096CA4C
int gnLogValue;                                                                                    // 0x0096CA50

// 0x00624700
void __fastcall LOG_SetLogValue(int nValue)
{
    gnLogValue = nValue;
}

// 0x00624720
static _iobuf* LOG_OpenLogFile(const char* szFileName)
{
    return fopen(szFileName, "wt");
}

// 0x00624730
static void LOG_CloseLogFile(_iobuf* pFile)
{
    fclose(pFile);
}

typedef char* va_list;

#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, v) (ap = (va_list)&(v) + _INTSIZEOF(v))

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40

extern "C" int __cdecl SStrVPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, va_list va); // 0x00413A80

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

extern "C" unsigned int __cdecl strlen(const char* sz);

// 0x00624780
static void __stdcall StoreLogging(_iobuf* pFile, int nThreadId, int nLogLevel, int nComponent, int nSubsystem, const char* szContext, int nSequence, const char* szFormat, va_list va)
{
    if (!gbLogEnabled)
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

// 0x006248B0
void __cdecl LOG_WriteLogEntry(_iobuf* pFile, int nThreadId, int nLogLevel, int nComponent, int nSubsystem, const char* szContext, int nSequence, const char* szFormat, ...)
{
    va_list va;
    va_start(va, szFormat);
    StoreLogging(pFile, nThreadId, nLogLevel, nComponent, nSubsystem, szContext, nSequence, szFormat, va);
}

// 0x00624AC0
int __fastcall LOG_OpenLog(const char* szFileName)
{
    if (!gpLogFile)
    {
        gpLogFile = LOG_OpenLogFile(szFileName);
        if (!gpLogFile)
            return 0;
        InitializeCriticalSection(&gLogLock);
        LOG_11100(1, 8, 2, 0x80000, ".\\Logging\\Logging.cpp", 249, "Log Started");
    }
    return 1;
}

// 0x006248E0
void __cdecl LOG_11100(int nThreadId, int nLogLevel, int nComponent, int nSubsystem, const char* szContext, int nSequence, const char* szFormat, ...)
{
    if (!gpLogFile)
        return;

    EnterCriticalSection(&gLogLock);
    va_list va;
    va_start(va, szFormat);
    StoreLogging(gpLogFile, nThreadId, nLogLevel, nComponent, nSubsystem, szContext, nSequence, szFormat, va);
    LeaveCriticalSection(&gLogLock);
}

// 0x00624930
void __cdecl LOG_WriteGameLogLine(int nGame, int nFrame, int nClient, int nType, int nSize, const char* szFormat, ...)
{
    if (!gpLogFile)
    {
        return;
    }
    if (!gbLogEnabled)
    {
        return;
    }

    EnterCriticalSection(&gLogLock);

    char szBuffer[500];
    SStrPrintf(szBuffer, 500, "Game:%02d\tFrame:%d\tClient:%02d\t", nGame, nFrame, nClient);
    if (nType == 1)
    {
        strcat(szBuffer, "Type:System\t");
    }
    else
    {
        strcat(szBuffer, "Type:Game\t");
    }

    const int nLength = strlen(szBuffer);
    char* pCursor = &szBuffer[nLength];
    int nRemaining = 500 - nLength;
    const int nWritten = SStrPrintf(pCursor, nRemaining, "Size:%d\n", nSize);
    nRemaining -= nWritten;
    pCursor += nWritten;

    va_list va;
    va_start(va, szFormat);
    SStrVPrintf(pCursor, nRemaining, szFormat, va);
    strcat(pCursor, "\n\n");

    fwrite(szBuffer, strlen(szBuffer), 1, gpLogFile);
    fflush(gpLogFile);
    LeaveCriticalSection(&gLogLock);
}

// 0x00624B20
void __cdecl LOG_CloseLog()
{
    if (gpLogFile)
    {
        LOG_CloseLogFile(gpLogFile);
        DeleteCriticalSection(&gLogLock);
        gpLogFile = 0;
    }
}

// 0x00624B50
void __fastcall LOG_SetLoggingEnabled(int bEnable)
{
    gbLogEnabled = bEnable;
    if (bEnable)
    {
        LOG_OpenLog("d2log.txt");
        return;
    }
    LOG_CloseLog();
}
