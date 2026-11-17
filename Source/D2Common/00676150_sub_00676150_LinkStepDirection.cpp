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

static __forceinline void DRLGOUTPLACE_PlaceCoord(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int a3, int a4)
{
    switch (a3)
    {
    case 0:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight;

        if (a4 == 1)
        {
            pDrlgCoord2->nPosX -= 16;
        }
        break;

    case 1:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;

        if (a4 == 1)
        {
            pDrlgCoord2->nPosY -= 16;
        }
        else if (a4 == 2)
        {
            pDrlgCoord2->nPosY += 8;
        }
        break;

    case 2:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth - pDrlgCoord2->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight;

        if (a4 == 1)
        {
            pDrlgCoord2->nPosX += 16;
        }
        break;

    case 3:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight - pDrlgCoord2->nHeight;

        switch (a4)
        {
        case 1:
            pDrlgCoord2->nPosY += 16;
            break;

        case 2:
            pDrlgCoord2->nPosY -= 8;
            break;

        case 3:
            pDrlgCoord2->nPosY += 8;
            break;

        default:
            break;
        }
        break;

    default:
        return;
    }
}

// 0x00676150
int __fastcall sub_00676150_LinkStepDirection(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 3;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        const int nNext = (pLevelLinkData->nRand[0][pLevelLinkData->nIteration] + 1) % 4;
        if (nNext == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }

        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nNext;
    }

    DRLGOUTPLACE_PlaceCoord(&pLevelLinkData->pLevelCoord[pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink], &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration], pLevelLinkData->nRand[0][pLevelLinkData->nIteration], 1);

    return 1;
}
