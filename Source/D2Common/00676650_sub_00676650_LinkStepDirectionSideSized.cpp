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

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static __forceinline void DRLGOUTPLACE_PlaceCoordSide1(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4)
{
    switch (nDirection)
    {
    case 0:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosX -= 16;
        }
        break;
    case 1:
        pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY -= 16;
        }
        break;
    case 2:
        pCoord->nPosX = pLinkCoord->nWidth - pCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY - pCoord->nHeight;
        if (a4 == 1)
        {
            pCoord->nPosX += 16;
        }
        break;
    case 3:
        pCoord->nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight - pCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY += 16;
        }
        break;
    }
}

static __forceinline void DRLGOUTPLACE_PlaceCoordSide0(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4)
{
    switch (nDirection)
    {
    case 0:
        pCoord->nPosX = pLinkCoord->nWidth - pCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosX += 16;
        }
        break;
    case 1:
        pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
        pCoord->nPosY = pLinkCoord->nHeight - pCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY += 16;
        }
        break;
    case 2:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY - pCoord->nHeight;
        if (a4 == 1)
        {
            pCoord->nPosX -= 16;
        }
        break;
    case 3:
        pCoord->nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY -= 16;
        }
        break;
    }
}

// 0x00676650
int __fastcall sub_00676650_LinkStepDirectionSideSized(D2DrlgLevelLinkDataStrc* pData)
{
    if (pData->nRand[1][pData->nIteration] == -1)
    {
        pData->nRand[1][pData->nIteration] = SEED_RollRandomNumber(&pData->pSeed) & 3;
        pData->nRand[0][pData->nIteration] = pData->nRand[1][pData->nIteration];
        pData->nRand[3][pData->nIteration] = SEED_RollRandomNumber(&pData->pSeed) & 1;
        pData->nRand[2][pData->nIteration] = pData->nRand[3][pData->nIteration];
    }
    else
    {
        const int nNext = (pData->nRand[0][pData->nIteration] + pData->nRand[2][pData->nIteration]) % 4;
        const int nSide = (pData->nRand[2][pData->nIteration] + 1) % 2;
        if (nNext == pData->nRand[1][pData->nIteration] && nSide == pData->nRand[3][pData->nIteration])
        {
            return 0;
        }

        pData->nRand[0][pData->nIteration] = nNext;
        pData->nRand[2][pData->nIteration] = nSide;
    }

    pData->pLevelCoord[pData->nIteration].nWidth = (pData->nRand[0][pData->nIteration] % 2) ? 96 : 56;
    pData->pLevelCoord[pData->nIteration].nHeight = (pData->nRand[0][pData->nIteration] % 2) ? 56 : 96;

    const int nIndex = pData->nIteration;
    D2DrlgCoordStrc* pLinkCoord = &pData->pLevelCoord[pData->pLink[nIndex].nLevelLink];
    if (pData->nRand[2][nIndex] == 1)
    {
        DRLGOUTPLACE_PlaceCoordSide1(pLinkCoord, &pData->pLevelCoord[nIndex], pData->nRand[0][nIndex], 1);
    }
    else
    {
        DRLGOUTPLACE_PlaceCoordSide0(pLinkCoord, &pData->pLevelCoord[nIndex], pData->nRand[0][nIndex], 1);
    }

    return 1;
}
