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

// 0x00676450
int __fastcall sub_00676450_LinkStepDirectionSide(D2DrlgLevelLinkDataStrc* pData)
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

    const int nIndex = pData->nIteration;
    D2DrlgCoordStrc* pLinkCoord = &pData->pLevelCoord[pData->pLink[nIndex].nLevelLink];
    if (pData->nRand[2][nIndex] == 1)
    {
        switch (pData->nRand[0][nIndex])
        {
        case 0:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nPosX;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
            break;
        case 1:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nPosX - pData->pLevelCoord[nIndex].nWidth;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nPosY + 8;
            break;
        case 2:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nWidth - pData->pLevelCoord[nIndex].nWidth + pLinkCoord->nPosX;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nPosY - pData->pLevelCoord[nIndex].nHeight;
            break;
        case 3:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nHeight - pData->pLevelCoord[nIndex].nHeight + pLinkCoord->nPosY - 8;
            break;
        }
    }
    else
    {
        switch (pData->nRand[0][nIndex])
        {
        case 0:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nWidth - pData->pLevelCoord[nIndex].nWidth + pLinkCoord->nPosX;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
            break;
        case 1:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nPosX - pData->pLevelCoord[nIndex].nWidth;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nHeight - pData->pLevelCoord[nIndex].nHeight + pLinkCoord->nPosY - 8;
            break;
        case 2:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nPosX;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nPosY - pData->pLevelCoord[nIndex].nHeight;
            break;
        case 3:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nPosY + 8;
            break;
        }
    }

    return 1;
}
