#include "D2LevelIds.h"
#include "D2Common.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2DrlgPresets.h"

struct D2DrlgVertexStrc;
struct D2DrlgOutdoorInfoStrc;
union D2SeedStrc;
struct D2DrlgCoordStrc;
struct D2DrlgLinkStrc;
struct D2DrlgLevelLinkDataStrc;
struct D2CoordStrc;
struct D2MotionPathStrc;




extern int gaDesertBorderIds[][2]; // 0x006F112C
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nPickedFile, int bFlag); // 0x006743C0
void __fastcall DRLGOUTPLACE_SetBlankBorderGridCells(D2DrlgLevelStrc* pLevel); // 0x00675670
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation); // 0x0067C4F0
void __fastcall DRLGVER_GetCoordDiff(D2DrlgVertexStrc* pVertex, int* pDirectionX, int* pDirectionY); // 0x0067D280
int __fastcall DRLGOUTSIEGE_GetBorderLookupId(D2DrlgLevelStrc* pLevel); // 0x0067DCE0





struct D2MotionPathStrc
{
    D2PathPointStrc tStart;
    D2PathPointStrc tTarget;
    D2CoordStrc tDirectionVector;
    D2CoordStrc tVelocity;
    int nSpeed;
    unsigned char nDirection;
    char unk_1D[3];
    unsigned int nFlags;
};

void __fastcall PATH_GetDirectionVectorFromPoints(D2CoordStrc* pDirectionVector, int* pOutDirection, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0064FD70

// 0x006755C0
int __fastcall DRLGOUTDOORS_GetBorderLevelPrestId(int nA, int nB, int nC)
{
// build: symbol ?gaBorderIndices@* 0x006F0FD0
    const int nRow = gaBorderIndices[nA + 3 * nB];
    if (nC >= 4)
    {
// build: symbol ?gaBarricadeCliffBorderIds@* 0x006F06F0
        return gaBarricadeCliffBorderIds[nRow][nC - 4];
    }
// build: symbol ?gaBorderLevelPrestIds@* 0x006F0630
    return gaBorderLevelPrestIds[nRow][nC];
}

// 0x00675600
int __fastcall DRLGOUTDOORS_GetCornerPresetId(int nA, int nB, int nC, int nD, int nE)
{
    if (nA < 0)
    {
        nA -= 2;
    }
    else if (nA > 0)
    {
        nA += 2;
    }

    if (nC < 0)
    {
        nC -= 2;
    }
    else if (nC > 0)
    {
        nC += 2;
    }

// build: symbol ?gaBorderIndicesByDelta@* 0x006F1088
    const int nRow = gaBorderIndicesByDelta[nA + 9 * (nC + nD) + nB];
    if (nRow == -1)
    {
        return 0;
    }

    if (nE >= 4)
    {
        return gaBarricadeCliffBorderIds[nRow - 1][nE - 4];
    }

    return gaBorderLevelPrestIds[nRow - 1][nE];
}

// 0x006757E0
int __fastcall DRLGOUTDOORS_GetBorderLookupId(D2DrlgLevelStrc* pLevel, bool bFlag)
{
    switch (pLevel->nLevelType)
    {
    case 2:
        return !bFlag;
    case 16:
        return 2;
    case 27:
        return 3;
    case 31:
        return DRLGOUTSIEGE_GetBorderLookupId(pLevel);
    }
    return -1;
}

#include "gen/data/Source/D2Common/Unknown_00675850.inc"

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
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

static inline void DRLGOUTPLACE_PlaceCoordSide1(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4)
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

static inline void DRLGOUTPLACE_PlaceCoordSide0(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4)
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

