struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2LvlPrestTxt
{
    int dwDef;
    char unk0x04[0x28 - 0x04];
    int nSizeX;
    int nSizeY;
    char unk0x30[0x40 - 0x30];
    int dwFiles;
};

struct D2DrlgMapStrc
{
    int nLevelPrest;
    int nPickedFile;
    D2LvlPrestTxt* pLvlPrestTxtRecord;
    void* pFile;
    D2DrlgCoordStrc pDrlgCoord;
    char unk0x20[0x3C - 0x20];
    int bInited;
    char unk0x40[0x54 - 0x40];
    D2DrlgMapStrc* pNext;
};

struct D2DrlgStrc
{
    char unk0x000[0x478];
    void* pMempool;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B0];
    D2DrlgMapStrc* pCurrentMap;
    D2DrlgStrc* pDrlg;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
extern "C" const char gszDrlgPresetSourceFile;                                                              // 0x006EE7C4
D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nLvlPrestId);                                    // 0x0061F0B0

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x00666ED0
D2DrlgMapStrc* __fastcall DRLGPRESET_AllocDrlgMap(D2DrlgLevelStrc* pLevel, int nLvlPrestId, D2DrlgCoordStrc* pDrlgCoord, D2SeedStrc* pSeed)
{
    D2DrlgMapStrc* pDrlgMap = (D2DrlgMapStrc*)FOG_AllocPool(pLevel->pDrlg->pMempool, sizeof(D2DrlgMapStrc), &gszDrlgPresetSourceFile, 2477, 0);
    memset(pDrlgMap, 0x00, sizeof(D2DrlgMapStrc));

    pDrlgMap->pLvlPrestTxtRecord = DATATBLS_GetLvlPrestTxtRecord(nLvlPrestId);
    pDrlgMap->nLevelPrest = nLvlPrestId;

    pDrlgMap->nPickedFile = SEED_RollLimitedRandomNumber(pSeed, pDrlgMap->pLvlPrestTxtRecord->dwFiles);
    pDrlgMap->pDrlgCoord.nPosX = pDrlgCoord->nPosX;
    pDrlgMap->pDrlgCoord.nPosY = pDrlgCoord->nPosY;

    if (pDrlgMap->pLvlPrestTxtRecord->nSizeX && pDrlgMap->pLvlPrestTxtRecord->nSizeY)
    {
        pDrlgMap->pDrlgCoord.nWidth = pDrlgMap->pLvlPrestTxtRecord->nSizeX;
        pDrlgMap->pDrlgCoord.nHeight = pDrlgMap->pLvlPrestTxtRecord->nSizeY;
    }
    else
    {
        pDrlgMap->pDrlgCoord.nWidth = pDrlgCoord->nWidth;
        pDrlgMap->pDrlgCoord.nHeight = pDrlgCoord->nHeight;
    }

    pDrlgMap->bInited = 1;
    pDrlgMap->pNext = pLevel->pCurrentMap;
    pLevel->pCurrentMap = pDrlgMap;

    return pDrlgMap;
}
