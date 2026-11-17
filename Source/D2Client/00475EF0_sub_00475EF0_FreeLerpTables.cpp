extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct D2ViewStrc
{
    unsigned int dwFlags;
    tagRECT tRect;
    int unk0x14[6];
    void* pLerpData;
    void* pLerpTable;
    void* pLerpRows;
};

struct D2PalShiftNodeStrc
{
    int nId;
    char unk0x04[0x1000];
    D2PalShiftNodeStrc* pNext;
};

struct T0044A980
{
    int nId;
    int nValue;
};

struct D2CacheStatsStrc
{
    unsigned int nFloorSize;
    int unk0x04;
    int nFloorMisses;
    unsigned int nSubtileSize;
    int unk0x10;
    int nSubtileMisses;
    unsigned int nSpriteSize[3];
    int unk0x24[3];
    int nSpriteMisses[3];
    int unk0x3C[3];
    int nSpriteAccesses[3];
    int unk0x54[3];
    int unk0x60[3];
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __fastcall sub_005179A4_VirtualFree(void* pMemory);                                                    // 0x005179A4
void __cdecl sub_00475EB0();                                                                                // 0x00475EB0
void __fastcall sub_004DCF30(D2ViewStrc* pView);                                                            // 0x004DCF30
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
void __fastcall sub_004DDB70_PrepareWallCells(D2ViewStrc* pView, int nValue);                               // 0x004DDB70
D2CacheStatsStrc* __cdecl sub_004F5290_GetCacheStats();                                                     // 0x004F5290
extern "C" void __cdecl sub_005FE060_ClearPair88CB10();                                                     // 0x005FE060

extern "C" int gnModeValue_00712CCC;                                                                        // 0x00712CCC
int gnGlobal_007B8D20;                                                                                      // 0x007B8D20
extern int gnGlobal_007B8D2C;                                                                               // 0x007B8D2C
extern int gnGlobal_007B9534;                                                                               // 0x007B9534
int gnGlobal_007B9538;                                                                                      // 0x007B9538
extern unsigned char** gppLerpRows_007B953C;                                                                // 0x007B953C
void* gpLerpTable_007B9540;                                                                                 // 0x007B9540
void* gpLerpTable_007B9544;                                                                                 // 0x007B9544
void* gpLerpTable_007B954C;                                                                                 // 0x007B954C
void* gpLerpTable_007B9550;                                                                                 // 0x007B9550
extern T0044A980* gpPalShiftEntries_007B9578;                                                     // 0x007B9578
D2PalShiftNodeStrc* gpPalShiftList_007B957C;                                                                // 0x007B957C
void* gpGlobal_007BB384;                                                                                    // 0x007BB384
int gbCacheStats_007BB3A4;                                                                                  // 0x007BB3A4
extern int gnGlobal_007BB3AC;                                                                               // 0x007BB3AC

// 0x00475EF0
void __cdecl sub_00475EF0_FreeLerpTables()
{
    if (!gppLerpRows_007B953C)
        return;

    D2_ASSERT(gpLerpTable_007B9540, 0xFB);
    D2_ASSERT(gpLerpTable_007B9544, 0xFC);
    D2_ASSERT(gpLerpTable_007B954C, 0xFD);
    D2_ASSERT(gpLerpTable_007B9550, 0xFE);
    sub_005179A4_VirtualFree(gppLerpRows_007B953C);
    if (gpLerpTable_007B9540)
        sub_005179A4_VirtualFree(gpLerpTable_007B9540);
    if (gpLerpTable_007B9544)
        sub_005179A4_VirtualFree(gpLerpTable_007B9544);
    if (gpLerpTable_007B954C)
        sub_005179A4_VirtualFree(gpLerpTable_007B954C);
    if (gpLerpTable_007B9550)
        sub_005179A4_VirtualFree(gpLerpTable_007B9550);
    gppLerpRows_007B953C = 0;
    gpLerpTable_007B9540 = 0;
    gpLerpTable_007B9544 = 0;
    gpLerpTable_007B954C = 0;
    gpLerpTable_007B9550 = 0;
    gnGlobal_007B8D2C = 0;
    sub_00475EB0();
}

// 0x00475FD0
void __fastcall sub_00475FD0(D2ViewStrc* pView)
{
    sub_004DCF30(pView);
    FOG_Free(pView, ".\\GAME\\View.cpp", 0x141, 0);
}

// 0x00475FF0
void __fastcall sub_00475FF0_SetViewDirty(D2ViewStrc* pView)
{
    pView->dwFlags |= 1;
}

// 0x00476140
void __fastcall sub_00476140(D2ViewStrc* pView, int nArg)
{
    D2_ASSERT(pView, 0x1DD);
    if (pView->tRect.right || pView->tRect.bottom)
    {
        if (sub_0045AE90() != 3)
            sub_004DDB70_PrepareWallCells(pView, nArg);
        pView->dwFlags &= ~1;
    }
}

// 0x00476AC0
int __fastcall sub_00476AC0_GetViewShift(int* pX, int* pY)
{
    if (!gnGlobal_007B9534)
        return 0;

    *pX = gnGlobal_007B9538;
    *pY = gnGlobal_007B8D20;
    return 1;
}

// 0x00476FB0
void __cdecl sub_00476FB0()
{
    while (gpPalShiftList_007B957C)
    {
        D2PalShiftNodeStrc* pNext = gpPalShiftList_007B957C->pNext;
        FOG_Free(gpPalShiftList_007B957C, ".\\GAME\\PalShift.cpp", 0x84, 0);
        gpPalShiftList_007B957C = pNext;
    }
    if (gpPalShiftEntries_007B9578)
    {
        FOG_Free(gpPalShiftEntries_007B9578, ".\\GAME\\PalShift.cpp", 0x8A, 0);
        gpPalShiftEntries_007B9578 = 0;
    }
    if (gpGlobal_007BB384)
    {
        FOG_Free(gpGlobal_007BB384, ".\\GAME\\PalShift.cpp", 0x90, 0);
        gpGlobal_007BB384 = 0;
    }
}

// 0x00477030
D2PalShiftNodeStrc* __fastcall sub_00477030_FindPalShiftNode(int nId)
{
    for (D2PalShiftNodeStrc* pNode = gpPalShiftList_007B957C; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nId)
            return pNode;
    }
    return 0;
}

// 0x00477750
int __cdecl sub_00477750_IsModeAtLeast4()
{
    return gnModeValue_00712CCC >= 4;
}

// 0x00477C00
void __cdecl sub_00477C00_ToggleCacheStats()
{
    gnGlobal_007BB3AC = 0;
    gbCacheStats_007BB3A4 = !gbCacheStats_007BB3A4;
    if (!gbCacheStats_007BB3A4)
        return;

    D2CacheStatsStrc* pStats = sub_004F5290_GetCacheStats();
    if (pStats)
    {
        pStats->unk0x04 = 0;
        pStats->nFloorMisses = 0;
        pStats->unk0x10 = 0;
        pStats->nSubtileMisses = 0;
        memset(pStats->unk0x24, 0, sizeof(pStats->unk0x24));
        memset(pStats->nSpriteMisses, 0, sizeof(pStats->nSpriteMisses));
        memset(pStats->nSpriteAccesses, 0, sizeof(pStats->nSpriteAccesses));
        memset(pStats->unk0x60, 0, sizeof(pStats->unk0x60));
    }
    sub_005FE060_ClearPair88CB10();
}
