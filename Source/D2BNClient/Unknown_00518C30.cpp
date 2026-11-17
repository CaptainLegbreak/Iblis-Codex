#include "D2BNClient.h"

struct D2CriticalSectionStrc;
struct D2BnLogStrc;

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern D2CriticalSectionStrc gBnLogLock_00881860; // 0x00881860

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

extern unsigned int* gpCacheTable_00881888; // 0x00881888
static __declspec(noinline) void sub_00518EC0_EncryptBlock(unsigned int* pData, unsigned int nLength, unsigned int dwKey);
unsigned int __stdcall sub_00518FA0_HashString(unsigned int nHashType, const char* szString); // 0x00518FA0

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

// 0x00518EC0
static void sub_00518EC0_EncryptBlock(unsigned int* pData, unsigned int nLength, unsigned int dwKey)
{
    unsigned int dwSeed = 0xEEEEEEEE;
    unsigned int nCount = nLength >> 2;
    if (nCount != 0)
    {
        const unsigned int* pTable = gpCacheTable_00881888;
        do
        {
            --nCount;
            unsigned int ch = *pData;
            dwSeed += pTable[0x400 + (dwKey & 0xFF)];
            *pData = ch ^ (dwKey + dwSeed);
            dwSeed = ch + dwSeed + (dwSeed << 5) + 3;
            dwKey = ((~dwKey << 0x15) + 0x11111111) | (dwKey >> 0x0B);
            ++pData;
        } while (nCount != 0);
    }
}

// build: context sub_00518EC0_Shim
// calling-convention shim (not game code)
void __cdecl sub_00518EC0_Shim(unsigned int* pData, unsigned int nSize)
{
    sub_00518EC0_EncryptBlock(pData, nSize, sub_00518FA0_HashString(3, "x"));
}

// 0x00519000
void __cdecl sub_00519000_InitCryptTable()
{
    unsigned int* pTable = gpCacheTable_00881888;
    if (!pTable)
    {
        return;
    }

    unsigned int dwSeed = 0x00100001;
    for (unsigned int i = 0; i < 0x100; ++i)
    {
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x100];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x200];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x300];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x400];
            *pEntry = dwValue;
        }
    }
}
