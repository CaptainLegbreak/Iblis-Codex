#include "Fog.h"
#include "D2GameTypes.h"


struct D2TimeStampStrc
{
    long nTime;
    unsigned long nTick;
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall GetThreadPriority(void* hThread);                            // 0x006CC268
extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int nPriority);             // 0x006CC264
extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6
void __fastcall sub_004107B0_AtomicStore64(void* pDest, const void* pSource);                               // 0x004107B0
void __fastcall sub_004107D0_Read64Locked(void* pDest, const void* pSource);                                // 0x004107D0
D2CriticalSectionStrc gtTimeLock;                                                                   // 0x0075E880
D2TimeStampStrc gtTimeBase;                                                                        // 0x0075E878

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x004109D0
void __cdecl SYSTEM_InitTimeBase()
{
    InitializeCriticalSection(&gtTimeLock);
    __int64 nShared = 0;
    __int64 nTest = 666;
    __int64 nRead = -1;
    sub_004107B0_AtomicStore64(&nShared, &nTest);
    sub_004107D0_Read64Locked(&nRead, &nShared);
    D2_ASSERT(nRead == 666, 0x3C);
    D2TimeStampStrc tNow;
    tNow.nTime = _time32(0);
    tNow.nTick = GetTickCount();
    sub_004107B0_AtomicStore64(&gtTimeBase, &tNow);
}

// 0x00410A80
long __cdecl FOG_GetSyncTime()
{
    const unsigned long nTick = GetTickCount();
    D2TimeStampStrc tBase;
    sub_004107D0_Read64Locked(&tBase, &gtTimeBase);
    if (nTick - tBase.nTick > 30000)
    {
        const int nPriority = GetThreadPriority(GetCurrentThread());
        if (nPriority != 0x7FFFFFFF)
        {
            SetThreadPriority(GetCurrentThread(), nPriority);
        }
        D2TimeStampStrc tNow;
        tNow.nTime = _time32(0);
        tNow.nTick = GetTickCount();
        sub_004107B0_AtomicStore64(&gtTimeBase, &tNow);
    }
    return (nTick - tBase.nTick) / 1000 + tBase.nTime;
}
