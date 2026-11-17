struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int unk0x10;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgOutdoorInfoStrc
{
    int unk0x00;
    D2DrlgGridStrc tGrid04;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    int unk0x24;
    int unk0x28;
    D2DrlgGridStrc tGrid2C;
    int unk0x40;
    int unk0x44;
    int unk0x48;
    int unk0x4C;
    int unk0x50;
    int unk0x54;
    int unk0x58;
    int nWidth;
    int nHeight;
};

struct D2DrlgLevelStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    D2DrlgOutdoorInfoStrc* pOutdoorInfo;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    int nSizeX;
    int nSizeY;
    char unk0x2C[0x198];
    D2SeedStrc pSeed;
    int unk0x1CC;
    int nLevelId;
};

struct D2LvlPrestRecordStrc
{
    char unk0x00[0x28];
    int nSizeX;
    int nSizeY;
};

struct D2DrlgOutPlaceCtxStrc
{
    D2DrlgLevelStrc* pLevel;
    int* pUnk54;
    D2DrlgGridStrc* pGrid04;
    D2DrlgGridStrc* pGrid2C;
    int unk0x10;
    int n14;
    int n18;
    int unk0x1C;
    int unk0x20;
    int (__fastcall* pfnTest)(D2DrlgLevelStrc*, int, int, int, int, unsigned int);
    int (__fastcall* pfnGetPreset)(D2DrlgLevelStrc*, int, int);
    int (__fastcall* pfn2C)(D2DrlgLevelStrc*, int, int);
    int (__fastcall* pfn30)(D2DrlgLevelStrc*, int, int);
    void (__fastcall* pfnPlace)(D2DrlgLevelStrc*, int, int, int, int, int);
};

struct D2DrlgOutSiegeInitStrc
{
    int nLevelId;
    int field_4;
    int field_8;
    int nLevelPrestId1;
    int nLevelPrestId2;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern const D2DrlgOutSiegeInitStrc gaOutSiegeCaves[3]; // 0x006F1F9C

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2LvlPrestRecordStrc* __stdcall sub_0061F0B0(int nPresetId); // 0x0061F0B0
int __fastcall DRLGOUTDOORS_GetPresetIndexFromGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674120
void __fastcall sub_006743C0(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nDirection, int a6); // 0x006743C0
void __fastcall sub_00670750(D2DrlgOutPlaceCtxStrc* pCtx); // 0x00670750
int __fastcall sub_00674160(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674160
int __fastcall sub_006741A0(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x006741A0
int __fastcall sub_0067E000(D2DrlgLevelStrc* pLevel, int nType, int nIndex); // 0x0067E000
int __fastcall sub_0067E080(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nUnused, unsigned int dwCellFlags); // 0x0067E080

void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel); // 0x00675770
void __stdcall sub_0067DB50(D2DrlgLevelStrc* pLevel); // 0x0067DB50
void __stdcall sub_0067DCF0(D2DrlgLevelStrc* pLevel); // 0x0067DCF0
void __stdcall sub_0067DEF0(D2DrlgLevelStrc* pLevel); // 0x0067DEF0
void __stdcall sub_0067E160(D2DrlgLevelStrc* pLevel); // 0x0067E160
void __stdcall sub_0067E560(D2DrlgLevelStrc* pLevel); // 0x0067E560

static __declspec(noinline) void DRLGOUTSIEGE_PlaceCaves(D2DrlgLevelStrc* pLevel); // 0x0067DA70
static __declspec(noinline) void sub_0067E0E0(D2DrlgLevelStrc* pLevel); // 0x0067E0E0
static __declspec(noinline) void sub_0067E240(D2DrlgLevelStrc* pLevel); // 0x0067E240
static __declspec(noinline) void sub_0067E4B0(D2DrlgLevelStrc* pLevel); // 0x0067E4B0

static void DRLGOUTSIEGE_PlaceCaves(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoorInfo;
    for (int i = 0; i < 3; ++i)
    {
        if (pLevel->nLevelId == gaOutSiegeCaves[i].nLevelId)
        {
            int nLevelPrestId;
            int nX;
            int nY;
            if (pLevel->nSizeX > pLevel->nSizeY)
            {
                nLevelPrestId = gaOutSiegeCaves[i].nLevelPrestId2;
                sub_0061F0B0(nLevelPrestId);
                nX = gaOutSiegeCaves[i].field_8 ? pOutdoors->nWidth - 2 : 0;
                nY = 2;
            }
            else
            {
                nLevelPrestId = gaOutSiegeCaves[i].nLevelPrestId1;
                sub_0061F0B0(nLevelPrestId);
                nX = 2;
                nY = gaOutSiegeCaves[i].field_8 ? pOutdoors->nHeight - 2 : 0;
            }
            sub_006743C0(pLevel, nX, nY, nLevelPrestId, gaOutSiegeCaves[i].field_4, 0);
        }
    }
}

static void sub_0067E0E0(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->nLevelId == 110)
    {
        return;
    }

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
    D2DrlgOutPlaceCtxStrc tCtx;
    memset(&tCtx, 0, sizeof(tCtx));
    tCtx.pLevel = pLevel;
    tCtx.pUnk54 = &pInfo->unk0x54;
    tCtx.pGrid04 = &pInfo->tGrid04;
    tCtx.pGrid2C = &pInfo->tGrid2C;
    tCtx.pfnTest = sub_0067E080;
    tCtx.pfn2C = sub_00674160;
    tCtx.pfn30 = sub_006741A0;
    tCtx.pfnPlace = sub_006743C0;
    tCtx.pfnGetPreset = sub_0067E000;
    tCtx.n14 = -1;
    tCtx.n18 = 12;
    sub_00670750(&tCtx);
}

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;
    if ((nMax - 1) & nMax)
        return SEED_RollRandomNumber_Inline(pSeed) % nMax;
    return SEED_RollRandomNumber_Inline(pSeed) & (nMax - 1);
}

static __forceinline int sub_0067E210_PlaceShiftedPreset(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    const int nPreset = DRLGOUTDOORS_GetPresetIndexFromGridCell(pLevel, nX, nY);
    if (nPreset >= 0x393 && nPreset <= 0x39A)
    {
        sub_006743C0(pLevel, nX, nY, nPreset + 0x10, -1, 0);
        return 1;
    }
    return 0;
}

static void sub_0067E240(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->nLevelId != 111)
        return;

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
    if (!pInfo)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 564);
        exit(-1);
    }

    int nPlaced;
    int i;
    for (i = 0, nPlaced = 0; i < 90 && nPlaced < 3; ++i)
    {
        const int nX = 2 * SEED_RollLimitedRandomNumber(&pLevel->pSeed, pInfo->nWidth / 2);
        const int nY = 2 * SEED_RollLimitedRandomNumber(&pLevel->pSeed, pInfo->nHeight / 2);
        if (sub_0067E210_PlaceShiftedPreset(pLevel, nX, nY))
            ++nPlaced;
    }

    const int nOffsetX = SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, pInfo->nWidth / 2);
    const int nOffsetY = SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, pInfo->nHeight / 2);
    for (int y = 0; y < pInfo->nHeight && nPlaced < 3; ++y)
    {
        for (int x = 0; x < pInfo->nWidth && nPlaced < 3; ++x)
        {
            const int nX = (x + 2 * nOffsetX) % pInfo->nWidth;
            const int nY = (y + 2 * nOffsetY) % pInfo->nHeight;
            if (sub_0067E210_PlaceShiftedPreset(pLevel, nX, nY))
                ++nPlaced;
        }
    }

    if (nPlaced < 3)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 601);
        exit(-1);
    }
}

static void sub_0067E4B0(D2DrlgLevelStrc* pLevel)
{
    if (!pLevel)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 623);
        exit(-1);
    }

    if (pLevel->nLevelId != 111)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 624);
        exit(-1);
    }

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
    if (!pInfo)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 627);
        exit(-1);
    }

    D2LvlPrestRecordStrc* pRecord = sub_0061F0B0(0x370);
    if (!pRecord)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 631);
        exit(-1);
    }

    int nX = pInfo->nWidth - pRecord->nSizeX / 8;
    int nY = pInfo->nHeight - pRecord->nSizeY / 8;
    sub_006743C0(pLevel, nX, nY, 0x370, -1, 0);
    sub_006743C0(pLevel, nX, nY - 2, 0x380, -1, 0);
}

// 0x0067E600
void __fastcall sub_0067E600(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->nLevelId == 110)
    {
        sub_0067E560(pLevel);
        return;
    }

    DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    sub_0067DCF0(pLevel);
    sub_0067DEF0(pLevel);
    sub_0067DB50(pLevel);
    DRLGOUTSIEGE_PlaceCaves(pLevel);

    if (pLevel->nLevelId == 111)
    {
        sub_0067E4B0(pLevel);
    }

    sub_0067E0E0(pLevel);
    sub_0067E240(pLevel);
    sub_0067E160(pLevel);
}
