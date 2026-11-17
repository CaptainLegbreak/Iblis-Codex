#include "Storm.h"

struct D2StormLinkStrc;
struct D2StormList00708420Strc;
struct D2StormMsgSourceStrc;
struct D2CriticalSectionStrc;
struct D2StormInit0041C0C0Strc;

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    ~D2StormLinkStrc()
    {
        Unlink();
    }
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2StormList00708420Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList00708420Strc();
    void sub_0041C770_UnlinkAll();                                                                          // 0x0041C770
    void sub_0041C9C0_DeleteAll();                                                                          // 0x0041C9C0
};

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2StormInit0041C0C0Strc
{
    D2StormInit0041C0C0Strc();
};
extern "C" __declspec(dllimport) int __stdcall HeapFree(void* hHeap, unsigned long dwFlags, void* lpMem); // 0x006CC320
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
void __cdecl sub_0041BEE0_InitStorm(); // 0x0041BEE0
extern D2StormList00708420Strc gHandlerList_00708420; // 0x00708420
extern D2CriticalSectionStrc gErrorStateLock_007790CC; // 0x007790CC
extern D2StormMsgSourceStrc* gpStormMsgSources_007790E8; // 0x007790E8
extern "C" int __cdecl vsprintf(char* buffer, const char* format, char* args); // 0x00682DA1
int __stdcall sub_0041CAF0_DisplayError(int code, const char* file, int line, const char* text, int recoverable, int exitCode); // 0x0041CAF0
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
extern "C" const char gszFormatName[]; // 0x006FFC58
extern int gnErrorOutputMode_0077909C; // 0x0077909C
extern "C" int __cdecl memcmp(const void* pBuf1, const void* pBuf2, unsigned int nSize);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int gnStormDword_007790EC; // 0x007790EC

// 0x0041C0C0
D2StormInit0041C0C0Strc::D2StormInit0041C0C0Strc()
{
    sub_0041BEE0_InitStorm();
}

// 0x0041C7B0
D2StormList00708420Strc::~D2StormList00708420Strc()
{
    sub_0041C770_UnlinkAll();
}

// 0x0041CA80
int __cdecl sub_0041CA80_Destroy()
{
    gHandlerList_00708420.sub_0041C9C0_DeleteAll();
    gnStormDword_007790EC = 0;
    while (gpStormMsgSources_007790E8)
    {
        D2StormMsgSourceStrc* pNext = gpStormMsgSources_007790E8->pNext;
        HeapFree(GetProcessHeap(), 0, gpStormMsgSources_007790E8);
        gpStormMsgSources_007790E8 = pNext;
    }
    if (gnErrorLockUsers_0070841C != -1)
    {
        DeleteCriticalSection(&gErrorStateLock_007790CC);
        gnErrorLockUsers_0070841C = -1;
    }
    return 1;
}

// 0x0041CFB0
int __cdecl sub_0041CFB0_DisplayErrorFmt(int code, const char* file, int line, int recoverable, int exitCode, const char* format, ...)
{
    char buffer[0x400];
    char* args = (char*)(&format + 1);
    vsprintf(buffer, format, args);
    return sub_0041CAF0_DisplayError(code, file, line, buffer, recoverable, exitCode);
}

int gbDebugMemoryLoaded_00779204; // 0x00779204

unsigned long gdwDebugMemory_00779200; // 0x00779200

// 0x0041D010
void __stdcall sub_0041D010_ReportHandleLeak(const char* szName, const char* szDetail)
{
    if (!gbDebugMemoryLoaded_00779204)
    {
        gbDebugMemoryLoaded_00779204 = 1;
        SRegLoadValue("Internal", "Debug Memory", 0, &gdwDebugMemory_00779200);
    }
    if (!gdwDebugMemory_00779200)
        return;
    char szText[0x100];
    if (szDetail && *szDetail)
        SStrPrintf(szText, 0x100, "%s (%s)", szName, szDetail);
    else
        SStrPrintf(szText, 0x100, gszFormatName, szName);
    if (!gnErrorOutputMode_0077909C)
    {
        SErrDisplayError(0x8510007F, szText, -3, 0, 1, 1);
    }
    else
    {
        char szOutput[0xC8];
        wsprintfA(szOutput, "Storm Error : handle never released -- %s\n", szText);
        OutputDebugStringA(szOutput);
    }
}

// 0x0041D200
int __stdcall SMemCmp(void* pLocation1, void* pLocation2, unsigned int nSize)
{
    return memcmp(pLocation1, pLocation2, nSize);
}

// 0x0041D2A0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize)
{
    memcpy(pDest, pSource, nSize);
}

// 0x0041D2C0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith)
{
    memset(pLocation, nFillWith, nLength);
}

// 0x0041D2E0
void __stdcall SMemMove(void* pDest, const void* pSource, unsigned int nSize)
{
    memmove(pDest, pSource, nSize);
}

// 0x0041D300
void __stdcall SMemZero(void* pLocation, unsigned int nLength)
{
    memset(pLocation, 0, nLength);
}
