#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2DrlgTiles.h"


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


D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                         // 0x0061E470

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x0067D8E0
int __fastcall DRLGOUTROOM_LinkLevelsByLevelDef(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    int nRand = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1;

    pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nRand;
    pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = nRand;

    D2DrlgCoordStrc* pCoord = &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration];
    switch (nRand)
    {
    case 0:
        pCoord->nWidth = 64;
        pCoord->nHeight = 160;
        break;

    case 1:
        pCoord->nWidth = 160;
        pCoord->nHeight = 64;
        break;
    }

    D2LevelDefBin* pLevelDefBin = DATATBLS_GetLevelDefRecord(pLevelLinkData->nCurrentLevel);

    pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration].nPosX = pLevelDefBin->dwOffsetX;
    pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration].nPosY = pLevelDefBin->dwOffsetY;

    return 1;
}
