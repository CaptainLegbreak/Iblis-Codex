#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2Path.h"
#include "D2DrlgRooms.h"
struct D2DrlgGridStrc;


void __fastcall sub_0067C890(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, int nFlag); // 0x0067C890
void __stdcall sub_00680D70(D2DrlgLevelStrc* pLevel); // 0x00680D70
void __stdcall sub_00681000(D2DrlgLevelStrc* pLevel); // 0x00681000
int __fastcall sub_006817D0(D2DrlgLevelStrc* pLevel, int nRoad); // 0x006817D0
D2DrlgVertexStrc* __fastcall DRLGVER_AllocVertex(void* pMemPool, unsigned char nDirection); // 0x0067CDD0
extern const int gnAct1PathOffsetX[4]; // 0x006F2820
extern const int gnAct1PathOffsetY[4]; // 0x006F2830

// build: context SEED_RollRandomNumber
static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x00681240
static void __stdcall sub_00681240(D2DrlgLevelStrc* pLevel, int nRoad)
{
    void* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgVertexStrc* pVertex = pOutdoors->pRoads[nRoad];
    int nRand = SEED_RollRandomNumber(&pLevel->pSeed) & 3;
    if (!pVertex)
    {
        return;
    }

    D2DrlgRoadStrc* pRoad = (D2DrlgRoadStrc*)((char*)pOutdoors + 20 * nRoad);
    if (pRoad->nStartType != 4)
    {
        D2DrlgVertexStrc* pNew = DRLGVER_AllocVertex(pMemPool, 0);
        pNew->nPosX = pRoad->tStart.nX;
        pNew->nPosY = pRoad->tStart.nY;
        pNew->pNext = pVertex;
        pOutdoors->pRoads[nRoad] = pNew;
    }

    pVertex->nPosX = pRoad->tStartInner.nX;
    pVertex->nPosY = pRoad->tStartInner.nY;

    for (pVertex = pVertex->pNext; pVertex; pVertex = pVertex->pNext)
    {
        if (!pVertex->pNext)
        {
            pVertex->nPosX = pRoad->tEndInner.nX;
            pVertex->nPosY = pRoad->tEndInner.nY;
            D2DrlgVertexStrc* pNew = DRLGVER_AllocVertex(pMemPool, 0);
            pNew->nPosX = pRoad->tEnd.nX;
            pNew->nPosY = pRoad->tEnd.nY;
            pVertex->pNext = pNew;
            return;
        }

        int nOffsetX = ((SEED_RollRandomNumber(&pLevel->pSeed) & 1) + 2) * gnAct1PathOffsetX[nRand];
        int nOffsetY = ((SEED_RollRandomNumber(&pLevel->pSeed) & 1) + 2) * gnAct1PathOffsetY[nRand];
        nRand = (nRand + 1) % 4;
        pVertex->nPosX *= 8;
        pVertex->nPosY *= 8;
        pVertex->nPosX = pLevel->nPosX + pVertex->nPosX + nOffsetX + 3;
        pVertex->nPosY = pLevel->nPosY + pVertex->nPosY + nOffsetY + 3;
    }
}

// 0x00681420
void __fastcall DRLGOUTDOORS_SpawnAct1DirtPaths(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    sub_00680D70(pLevel);
    sub_00681000(pLevel);

    for (int nPath = 0; nPath < pOutdoors->nVertices; ++nPath)
    {
        if (sub_006817D0(pLevel, nPath))
        {
            sub_0067C890(&pOutdoors->pGrid[2], pOutdoors->pRoads[nPath], 0x80);
            sub_00681240(pLevel, nPath);
        }
    }
}

#include "gen/data/Source/D2Common/Unknown_00681240.inc"
