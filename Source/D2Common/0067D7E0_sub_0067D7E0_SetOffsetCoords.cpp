// build: context DRLGOUTROOM_LinkLevelsByOffsetCoords

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgCoordsStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2DrlgLinkStrc
{
    void* pfLinker;
    int nLevel;
    int nLevelLink;
    int nLevelLinkEx;
};

struct D2DrlgLevelLinkDataStrc
{
    D2SeedStrc pSeed;
    D2DrlgCoordsStrc pLevelCoord[15];
    D2DrlgLinkStrc* pLink;
    int nRand[4][15];
    int nIteration;
    int nCurrentLevel;
};

extern const D2CoordStrc gOutdoorOrthOffsets_006F1F7C[4]; // 0x006F1F7C

// 0x0067D7E0
static __forceinline void __fastcall sub_0067D7E0_SetOffsetCoords(D2DrlgCoordsStrc* pCoords, D2DrlgCoordsStrc* pLinkCoords, int nRand, int nLinkRand)
{
    switch (nRand)
    {
    case 0:
        pCoords->nWidth = 64;
        pCoords->nHeight = 160;
        break;
    case 1:
        pCoords->nWidth = 160;
        pCoords->nHeight = 64;
        break;
    }

    const int nIndex = nRand + 2 * nLinkRand;
    pCoords->nPosX = gOutdoorOrthOffsets_006F1F7C[nIndex].nX + pLinkCoords->nPosX;
    pCoords->nPosY = gOutdoorOrthOffsets_006F1F7C[nIndex].nY + pLinkCoords->nPosY;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// build: context SEED_RollRandomNumber
int __fastcall DRLGOUTROOM_LinkLevelsByOffsetCoords(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        const int bRand0IsNull = pLevelLinkData->nRand[0][pLevelLinkData->nIteration] == 0;
        if (bRand0IsNull == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = bRand0IsNull;
    }

    const int nLevelLink = pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink;
    sub_0067D7E0_SetOffsetCoords(&pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration], &pLevelLinkData->pLevelCoord[nLevelLink], pLevelLinkData->nRand[0][pLevelLinkData->nIteration], pLevelLinkData->nRand[0][nLevelLink]);
    return 1;
}
