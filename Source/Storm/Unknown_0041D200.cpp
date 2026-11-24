#include "Storm.h"
#include "D2StormAutoLink.h"
#include "D2GameTypes.h"

struct D2StormList00708420Strc;
struct D2StormMsgSourceStrc;
struct D2CriticalSectionStrc;
struct D2StormList00708420Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList00708420Strc();
    void sub_0041C770_UnlinkAll();                                                                          // 0x0041C770
    void sub_0041C9C0_DeleteAll();                                                                          // 0x0041C9C0
};


extern "C" __declspec(dllimport) int __stdcall HeapFree(void* hHeap, unsigned long dwFlags, void* lpMem); // 0x006CC320
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
void __cdecl StormInitialize(); // 0x0041BEE0
extern D2StormList00708420Strc gHandlerList_00708420; // 0x00708420
extern D2CriticalSectionStrc gErrorStateLock_007790CC; // 0x007790CC
extern D2StormMsgSourceStrc* gpStormMsgSources_007790E8; // 0x007790E8
extern "C" int __cdecl vsprintf(char* buffer, const char* format, char* args); // 0x00682DA1
int __stdcall SErrDisplayError(unsigned int nErrorCode,const char* szFile,int nLine,const char* szDescription,int bRecoverable,unsigned int nExitCode); // 0x0041CAF0
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
