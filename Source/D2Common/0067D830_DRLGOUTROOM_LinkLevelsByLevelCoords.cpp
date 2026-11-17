struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgCoordsStrc
{
    int nX;
    int nY;
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

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static __forceinline void sub_0067D7B0(D2DrlgCoordsStrc* pCoords, int nType)
{
    switch (nType)
    {
    case 0:
        pCoords->nWidth = 0x40;
        pCoords->nHeight = 0xA0;
        break;

    case 1:
        pCoords->nWidth = 0xA0;
        pCoords->nHeight = 0x40;
        break;
    }
}

// 0x0067D830
int __fastcall DRLGOUTROOM_LinkLevelsByLevelCoords(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    D2DrlgLinkStrc* const& pLinks = pLevelLinkData->pLink;
    int nRand = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1;

    pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nRand;
    pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = nRand;

    D2DrlgCoordsStrc* pCoord = &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration];
    sub_0067D7B0(pCoord, nRand);

    const int nIteration = pLevelLinkData->nIteration;
    D2DrlgCoordsStrc* pLinkCoord = &pLevelLinkData->pLevelCoord[pLinks[nIteration].nLevelLink];
    pCoord->nX = pLinkCoord->nX - pCoord->nWidth;
    pCoord->nY = pLinkCoord->nHeight - pCoord->nHeight + pLinkCoord->nY - 16;

    return 1;
}
