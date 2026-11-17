struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgStrc
{
    char unk0x000[0x478];
    void* pMempool;
};

struct D2DrlgOutdoorInfoStrc
{
    char unk0x00[0x5C];
    int nGridWidth;
    int nGridHeight;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x14];
    D2DrlgOutdoorInfoStrc* pOutdoors;
    char unk0x018[0x1B4 - 0x18];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x1C4 - 0x1B8];
    D2SeedStrc pSeed;
};

struct D2DrlgCoordStrc
{
    int nX;
    int nY;
};

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);            // 0x0040B430
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);             // 0x0040B480
int __fastcall DRLGOUTDOORS_TestOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nX, int nY, int nId, int nOffset, char nFlags); // 0x00674230
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nPickedFile, int bFlag); // 0x006743C0

static __forceinline unsigned int OUTJUNG_SeedStepInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int OUTJUNG_RollLimitedInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return OUTJUNG_SeedStepInline(pSeed) % nMax;
    }

    return OUTJUNG_SeedStepInline(pSeed) & (nMax - 1);
}

// 0x0067EED0
void __fastcall DRLGOUTJUNG_SpawnRandomPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId1, int nLevelPrestId2, int nMaxSpawns)
{
    void* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    int nVariants = nLevelPrestId2 - nLevelPrestId1 + 1;
    int nSpawned = 0;
    int nWidth = pOutdoors->nGridWidth;
    int nCount = pOutdoors->nGridHeight * nWidth;

    if (nCount)
    {
        D2DrlgCoordStrc* pCoords = (D2DrlgCoordStrc*)FOG_AllocPool(pMemPool, 8 * nCount, ".\\DRLG\\OutJung.cpp", 0xCB, 0);

        for (int i = 0; i < nCount; ++i)
        {
            pCoords[i].nX = i % nWidth;
            pCoords[i].nY = i / nWidth;
        }

        for (int i = 0; i < nCount; ++i)
        {
            const unsigned int nA = OUTJUNG_RollLimitedInline(&pLevel->pSeed, nCount);
            const unsigned int nB = OUTJUNG_RollLimitedInline(&pLevel->pSeed, nCount);
            const D2DrlgCoordStrc tTemp = pCoords[nA];
            pCoords[nA] = pCoords[nB];
            pCoords[nB] = tTemp;
        }

        for (int i = 0; i < nCount; ++i)
        {
            const int nX = pCoords[i].nX;
            const int nY = pCoords[i].nY;
            const int nPreset = nLevelPrestId1 + OUTJUNG_RollLimitedInline(&pLevel->pSeed, nVariants);

            if (DRLGOUTDOORS_TestOutdoorLevelPreset(pLevel, nX, nY, nPreset, 0, 15))
            {
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nPreset, -1, 0);
                ++nSpawned;

                if (nMaxSpawns > 0 && nSpawned >= nMaxSpawns)
                {
                    FOG_FreePool(pMemPool, pCoords, ".\\DRLG\\OutJung.cpp", 0xEB, 0);
                    return;
                }
            }
        }

        FOG_FreePool(pMemPool, pCoords, ".\\DRLG\\OutJung.cpp", 0xF2, 0);
    }
}
