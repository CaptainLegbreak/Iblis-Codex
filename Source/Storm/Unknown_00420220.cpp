#include "D2GameTypes.h"
#include "Storm.h"
#include "D2Win32Message.h"


extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(const D2WinMsgStrc* pMsg);                  // 0x006CC478
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const D2WinMsgStrc* pMsg);                  // 0x006CC47C
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax, unsigned int nRemove); // 0x006CC480
extern "C" __declspec(dllimport) int __stdcall GetMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax); // 0x006CC484
void __stdcall SLogClose(void* hLog);                                                                       // 0x0041FD00
void __cdecl SLogFlushAll();                                                                                // 0x0041FFF0
void __stdcall SErrReportResourceLeak(const char* szName);                                           // 0x0041D1E0
extern D2CriticalSectionStrc gaSLogLocks_00779238[4];                                                       // 0x00779238
extern D2SLogStrc* gapSLogBuckets_00779298[4];                                                              // 0x00779298

typedef int (__stdcall* SMSGIDLEPROC)(int nCount);

struct D2Strc00420E80
{
    char pad0x00[0x158];
    char tField158;
    void* sub_00420E80_GetField158();
};

// 0x00420E80
void* D2Strc00420E80::sub_00420E80_GetField158()
{
    return &tField158;
}

// 0x00420E90
static inline unsigned int sub_00420E90_TakeLow32(unsigned __int64* pValue)
{
    const unsigned int nLow = (unsigned int)*pValue;
    *pValue >>= 32;
    return nLow;
}

// 0x00420F00
static inline unsigned int sub_00420F00_TakeLow32Ext(unsigned __int64* pValue)
{
    const unsigned int nLow = (unsigned int)*pValue;
    *pValue >>= 32;
    if (*pValue >= 0x80000000)
    {
        *pValue |= 0xFFFFFFFF00000000ull;
    }
    return nLow;
}

unsigned int __fastcall sub_M119_Emit_00420E90(unsigned __int64* pValue, int nOther)
{
    return sub_00420E90_TakeLow32(pValue) + sub_00420F00_TakeLow32Ext((unsigned __int64*)nOther);
}
