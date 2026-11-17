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
    D2DrlgCoordStrc pLevelCoord[15];
    D2DrlgLinkStrc* pLink;
    int nRand[4][15];
    int nIteration;
    int nCurrentLevel;
};

static int gnDrlgLinkFlags_0096D66C;                                                                        // 0x0096D66C

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x00676C00
int __fastcall sub_00676C00_PlaceLevelNextTo(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = 3;
    pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];

    const int nLinkedLevel = pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink;
    D2DrlgCoordStrc* pDst = &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration];
    if (SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1)
    {
        D2DrlgCoordStrc* pSrc = &pLevelLinkData->pLevelCoord[nLinkedLevel];
        switch (pLevelLinkData->nRand[0][pLevelLinkData->nIteration])
        {
        case 0:
            pDst->nPosX = pSrc->nPosX;
            pDst->nPosY = pSrc->nHeight + pSrc->nPosY;
            break;
        case 1:
            pDst->nPosX = pSrc->nPosX - pDst->nWidth;
            pDst->nPosY = pSrc->nPosY;
            break;
        case 2:
            pDst->nPosX = pSrc->nWidth - pDst->nWidth + pSrc->nPosX;
            pDst->nPosY = pSrc->nPosY - pDst->nHeight;
            break;
        case 3:
            pDst->nPosX = pSrc->nWidth + pSrc->nPosX;
            pDst->nPosY = pSrc->nHeight - pDst->nHeight + pSrc->nPosY + 8;
            break;
        }
        gnDrlgLinkFlags_0096D66C = 0x800000;
    }
    else
    {
        D2DrlgCoordStrc* pSrc = &pLevelLinkData->pLevelCoord[nLinkedLevel];
        switch (pLevelLinkData->nRand[0][pLevelLinkData->nIteration])
        {
        case 0:
            pDst->nPosX = pSrc->nWidth - pDst->nWidth + pSrc->nPosX;
            pDst->nPosY = pSrc->nHeight + pSrc->nPosY;
            break;
        case 1:
            pDst->nPosX = pSrc->nPosX - pDst->nWidth;
            pDst->nPosY = pSrc->nHeight - pDst->nHeight + pSrc->nPosY;
            break;
        case 2:
            pDst->nPosX = pSrc->nPosX;
            pDst->nPosY = pSrc->nPosY - pDst->nHeight;
            break;
        case 3:
            pDst->nPosX = pSrc->nWidth + pSrc->nPosX;
            pDst->nPosY = pSrc->nPosY - 8;
            break;
        }
        gnDrlgLinkFlags_0096D66C = 0x400000;
    }

    return 1;
}

int __fastcall sub_Emit_0096D66C()
{
    return gnDrlgLinkFlags_0096D66C;
}
