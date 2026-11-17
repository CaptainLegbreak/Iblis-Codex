struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2PresetCodeStrc
{
    char c0;
    char c1;
    char c2;
    char c3;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
int __fastcall DRLGPRESET_MapTileType(int nId);                                                             // 0x0066D7F0
extern D2CriticalSectionStrc gLevelFilesCriticalSection;                                                    // 0x0096D610

// 0x00665810
static void sub_00665810_CopyCodePadded(D2PresetCodeStrc* pDst, const char* pSrc)
{
    if (!pSrc[0])
    {
        const char c = 0x20;
        pDst->c0 = c;
        pDst->c1 = c;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c0 = pSrc[0];
    if (!pSrc[1])
    {
        const char c = 0x20;
        pDst->c1 = c;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c1 = pSrc[1];
    if (!pSrc[2])
    {
        const char c = 0x20;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c2 = pSrc[2];
    pDst->c3 = 0x20;
}

// 0x00665900
static void sub_00665900_MapTileTypes(int* pTileTypes, int nCount)
{
    if (nCount > 0)
    {
        do
        {
            *pTileTypes = DRLGPRESET_MapTileType(*pTileTypes);
            ++pTileTypes;
        }
        while (--nCount);
    }
}

// 0x00665930
void __cdecl sub_00665930_LockLevelFiles()
{
    EnterCriticalSection(&gLevelFilesCriticalSection);
}

// 0x00665940
void __cdecl sub_00665940_UnlockLevelFiles()
{
    LeaveCriticalSection(&gLevelFilesCriticalSection);
}

void __fastcall sub_M107_Emit_00665810(D2PresetCodeStrc* pDst, const char* pSrc, int bCopy)
{
    if (bCopy)
        sub_00665810_CopyCodePadded(pDst, pSrc);
}

void __fastcall sub_M107_Emit_00665900(int* pTileTypes, int nCount, int bMap)
{
    if (bMap)
        sub_00665900_MapTileTypes(pTileTypes, nCount);
}
