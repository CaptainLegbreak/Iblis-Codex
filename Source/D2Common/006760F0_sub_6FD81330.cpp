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

struct D2LevelDefBin
{
    char unk0x00[0x24];
    int dwOffsetX;
    int dwOffsetY;
};

D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                         // 0x0061E470

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static void __fastcall sub_6FD815E0(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int a3, int a4)
{
    switch (a3)
    {
    case 0:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosX -= pDrlgCoord2->nWidth / 2 + 8;
        }
        break;
    case 1:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosX += pDrlgCoord2->nWidth / 2 + 8;
        }
        break;
    case 2:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosY -= pDrlgCoord2->nHeight / 2 + 8;
        }
        break;
    case 3:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosY += pDrlgCoord2->nHeight / 2 + 8;
        }
        break;
    case 4:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosX -= pDrlgCoord2->nWidth / 2 + 8;
        }
        break;
    case 5:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosX += pDrlgCoord2->nWidth / 2 + 8;
        }
        break;
    case 6:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosY -= pDrlgCoord2->nHeight / 2 + 8;
        }
        break;
    case 7:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosY += pDrlgCoord2->nHeight / 2 + 8;
        }
        break;
    default:
        return;
    }
}

// 0x006760F0
int __fastcall sub_6FD81330(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }

    D2LevelDefBin* pLevelDefBinRecord = DATATBLS_GetLevelDefRecord(pLevelLinkData->nCurrentLevel);
    pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration].nPosX = pLevelDefBinRecord->dwOffsetX;
    pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration].nPosY = pLevelDefBinRecord->dwOffsetY;

    return 1;
}

// 0x00676AE0
int __fastcall sub_6FD81BF0(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    int nRand = 0;

    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 7;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        nRand = (pLevelLinkData->nRand[0][pLevelLinkData->nIteration] + 1) % 8;

        if (nRand == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }

        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nRand;
    }

    sub_6FD815E0(&pLevelLinkData->pLevelCoord[pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink], &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration], pLevelLinkData->nRand[0][pLevelLinkData->nIteration], 0);

    return 1;
}
