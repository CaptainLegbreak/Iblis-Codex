struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct T0041FA40
{
    void* hLog;
    T0041FA40* pNext;
};

struct D2WinMsgStrc
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
    unsigned int dwTime;
    int f_14;
    int nPointY;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(const D2WinMsgStrc* pMsg);                  // 0x006CC478
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const D2WinMsgStrc* pMsg);                  // 0x006CC47C
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax, unsigned int nRemove); // 0x006CC480
extern "C" __declspec(dllimport) int __stdcall GetMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax); // 0x006CC484
void __stdcall SLogClose(void* hLog);                                                                       // 0x0041FD00
void __cdecl SLogFlushAll();                                                                                // 0x0041FFF0
void __stdcall sub_0041D1E0_ReportHandleLeak(const char* szName);                                           // 0x0041D1E0
extern D2CriticalSectionStrc gaSLogLocks_00779238[4];                                                       // 0x00779238
extern T0041FA40* gapSLogBuckets_00779298[4];                                                              // 0x00779298

// 0x00420220
void __cdecl sub_00420220_SLogDestroy()
{
    SLogFlushAll();
    D2CriticalSectionStrc* pLock = gaSLogLocks_00779238;
    T0041FA40** ppBucket = gapSLogBuckets_00779298;
    for (int n = 4; n; --n)
    {
        EnterCriticalSection(pLock);
        while (*ppBucket)
        {
            SLogClose((*ppBucket)->hLog);
            sub_0041D1E0_ReportHandleLeak("HSLOG");
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

typedef int (__stdcall* SMSGIDLEPROC)(int nCount);

// 0x004202A0
unsigned int __stdcall SMsgDoMessageLoop(SMSGIDLEPROC pfIdle, int bCleanUponQuit)
{
    D2WinMsgStrc tMsg;
    int nCount = 0;
    for (;;)
    {
        if (PeekMessageA(&tMsg, 0, 0, 0, 0) || !pfIdle || !pfIdle(nCount++))
        {
            nCount = 0;
            if (!GetMessageA(&tMsg, 0, 0, 0))
            {
                break;
            }
            TranslateMessage(&tMsg);
            DispatchMessageA(&tMsg);
        }
    }
    return tMsg.wParam;
}

struct D2TSLinkStrc
{
    D2TSLinkStrc* pPrevLink;
    D2TSLinkStrc* pNext;

    D2TSLinkStrc* NextLink(int nLinkOffset)
    {
        const int nNext = (int)pNext;
        if (nNext < 0)
        {
            return (D2TSLinkStrc*)~nNext;
        }
        if (nLinkOffset < 0)
        {
            nLinkOffset = (int)this - (int)pPrevLink->pNext;
        }
        return (D2TSLinkStrc*)(nNext + nLinkOffset);
    }

    void Unlink()
    {
        if (pPrevLink)
        {
            NextLink(-1)->pPrevLink = pPrevLink;
            pPrevLink->pNext = pNext;
            pPrevLink = 0;
            pNext = 0;
        }
    }
};

struct D2TSListStrc
{
    int nLinkOffset;
    D2TSLinkStrc tTerminator;

    D2TSLinkStrc* Head()
    {
        return (int)tTerminator.pNext > 0 ? tTerminator.pNext : 0;
    }

    void sub_00420750_UnlinkAll();
    int sub_004206C0_IsEmpty();
    void sub_00420790_Destroy();
};

// 0x004206C0
int D2TSListStrc::sub_004206C0_IsEmpty()
{
    return Head() == 0;
}

// 0x00420790
void D2TSListStrc::sub_00420790_Destroy()
{
    sub_00420750_UnlinkAll();
    tTerminator.Unlink();
}

struct D2Strc00420D80
{
    int f_0;
    int f_4;
    int f_8;
    void sub_00420D80_Clear();
};

// 0x00420D80
void D2Strc00420D80::sub_00420D80_Clear()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

struct D2Strc00420DA0
{
    int f_0;
    int nEnd;
    int f_8;
    int nFieldC;
    int nStart;
    int sub_00420DA0_GetSpan();
};

// 0x00420DA0
int D2Strc00420DA0::sub_00420DA0_GetSpan()
{
    return nEnd - nStart;
}

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
static __forceinline unsigned int sub_00420E90_TakeLow32(unsigned __int64* pValue)
{
    const unsigned int nLow = (unsigned int)*pValue;
    *pValue >>= 32;
    return nLow;
}

// 0x00420F00
static __forceinline unsigned int sub_00420F00_TakeLow32Ext(unsigned __int64* pValue)
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
