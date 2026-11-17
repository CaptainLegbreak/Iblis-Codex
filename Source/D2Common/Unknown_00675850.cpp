#include "D2Common.h"

struct D2DrlgVertexStrc;
struct D2DrlgOutdoorInfoStrc;
struct D2SeedStrc;
struct D2DrlgCoordStrc;
struct D2DrlgLinkStrc;
struct D2DrlgLevelLinkDataStrc;
struct D2CoordStrc;
struct D2MotionPathStrc;

struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int field_10;
};

struct D2DrlgVertexStrc
{
    int nPosX;
    int nPosY;
    unsigned char nDirection;
    unsigned int dwFlags;
    D2DrlgVertexStrc* pNext;
};

struct D2DrlgOutdoorInfoStrc
{
    int field_00;
    D2DrlgGridStrc pGrid[3];
    char pad_40[0x24];
    D2DrlgVertexStrc* pVertex;
};

struct D2DrlgLevelStrc
{
    char pad_000[0x14];
    D2DrlgOutdoorInfoStrc* pOutdoors;
    char pad_018[0x1C0 - 0x18];
    int nLevelType;
    char pad_1C4[0x0C];
    int nLevelId;
};
extern int gaDesertBorderIds_006F112C[][2]; // 0x006F112C
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nPickedFile, int bFlag); // 0x006743C0
void __fastcall DRLGOUTPLACE_SetBlankBorderGridCells(D2DrlgLevelStrc* pLevel); // 0x00675670
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation); // 0x0067C4F0
void __fastcall sub_0067D280(D2DrlgVertexStrc* pVertex, int* pDirectionX, int* pDirectionY); // 0x0067D280
int __fastcall sub_0067DCE0(D2DrlgLevelStrc* pLevel); // 0x0067DCE0

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

struct D2PathPointStrc { unsigned short nX, nY; };

struct D2CoordStrc { int nX, nY; };

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

void __fastcall sub_0064FD70_GetDirectionVectorFromPoints(D2CoordStrc* pDirectionVector, int* pOutDirection, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0064FD70

// 0x006755C0
int __fastcall sub_006755C0_LookupTable(int nA, int nB, int nC)
{
    const int nRow = gaLookupRow_006F0FD0[nA + 3 * nB];
    if (nC >= 4)
    {
        return gaLookupLarge_006F06F0[nRow][nC - 4];
    }
    return gaLookupSmall_006F0630[nRow][nC];
}

// 0x00675600
int __fastcall sub_00675600_LookupTable(int nA, int nB, int nC, int nD, int nE)
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

    const int nRow = gaLookupRow_006F1088[nA + 9 * (nC + nD) + nB];
    if (nRow == -1)
    {
        return 0;
    }

    if (nE >= 4)
    {
        return gaLookupLarge_006F06F0[nRow - 1][nE - 4];
    }

    return gaLookupSmall_006F0630[nRow - 1][nE];
}

// 0x006757E0
int __fastcall sub_006757E0_GetLevelStyle(D2DrlgLevelStrc* pLevel, bool bFlag)
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
        return sub_0067DCE0(pLevel);
    }
    return -1;
}

// 0x00675850
void __fastcall DRLGOUTPLACE_PlaceAct1245OutdoorBorders(D2DrlgLevelStrc* pLevel)
{
    int nCurrentDiffX;
    int nCurrentDiffY;
    int nNextDiffX;
    int nNextDiffY;
    int nCurrentDiffXAbs;
    int nCurrentDiffYAbs;
    int nCurrentX;
    int nCurrentY;
    int nNextX;
    int nNextY;
    int nDelta;
    int nDiff;
    int nX;
    int nY;
    int nIndex;
    int nLevelPrestId;
    int nStyle;
    int nPacked;
    unsigned char nDirection;

    unsigned char nAct = DRLG_GetActNoFromLevelId(pLevel->nLevelId);
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgVertexStrc* pVertex = pOutdoors->pVertex;
    D2DrlgVertexStrc* pNext = pVertex->pNext;

    do
    {
        sub_0067D280(pVertex, &nCurrentDiffX, &nCurrentDiffY);
        sub_0067D280(pNext, &nNextDiffX, &nNextDiffY);

        if (nCurrentDiffX >= 0)
        {
            nCurrentDiffXAbs = nCurrentDiffX;
        }
        else
        {
            nCurrentDiffXAbs = -nCurrentDiffX;
        }

        if (nCurrentDiffY < 0)
        {
            nCurrentDiffYAbs = -nCurrentDiffY;
        }
        else
        {
            nCurrentDiffYAbs = nCurrentDiffY;
        }

        nCurrentX = pVertex->nPosX;
        nCurrentY = pVertex->nPosY;
        nNextX = pNext->nPosX;
        nNextY = pNext->nPosY;
        if (nCurrentDiffXAbs)
        {
            nDelta = nCurrentX - nNextX;
            if (nDelta < 0)
            {
                nDiff = -nDelta;
            }
            else
            {
                nDiff = nDelta;
            }
        }
        else
        {
            nDelta = nCurrentY - nNextY;
            if (nDelta < 0)
            {
                nDiff = -nDelta;
            }
            else
            {
                nDiff = nDelta;
            }
        }

        nDirection = pVertex->nDirection;
        nPacked = nDirection != 0 ? 3 : 1;

        nLevelPrestId = sub_006755C0_LookupTable(nCurrentDiffX, nCurrentDiffY, sub_006757E0_GetLevelStyle(pLevel, nDirection != 0));

        if (!(pVertex->dwFlags & 2))
        {
            while (nCurrentX != nNextX || nCurrentY != nNextY)
            {
                nCurrentX += nCurrentDiffX;
                nCurrentY += nCurrentDiffY;
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nCurrentX, nCurrentY, nLevelPrestId, -1, 0);
                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nCurrentX, nCurrentY, nPacked, 0);
            }
        }

        if (pVertex->dwFlags & 1 && !(pVertex->dwFlags & 2))
        {
            switch (nAct)
            {
            case 0:
            case 4:
                nX = (pVertex->nPosX < pNext->nPosX ? pVertex->nPosX : pNext->nPosX) + nCurrentDiffXAbs * nDiff / 2;

                nY = (pVertex->nPosY < pNext->nPosY ? pVertex->nPosY : pNext->nPosY) + nCurrentDiffYAbs * nDiff / 2;

                if (pLevel->nLevelId == 17)
                {
                    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0xF0000, 5);
                    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0x40400, 0);
                }
                else
                {
                    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0xF0000, 5);
                    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0x30400, 0);
                }
                break;

            case 3:
                nX = (pVertex->nPosX < pNext->nPosX ? pVertex->nPosX : pNext->nPosX) + nCurrentDiffXAbs * nDiff / 2;

                nY = (pVertex->nPosY < pNext->nPosY ? pVertex->nPosY : pNext->nPosY) + nCurrentDiffYAbs * nDiff / 2;

                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0xF0000, 5);
                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0x30400, 0);
                break;

            case 1:
                nX = (pVertex->nPosX < pNext->nPosX ? pVertex->nPosX : pNext->nPosX) + nCurrentDiffXAbs * nDiff / 2;

                nY = (pVertex->nPosY < pNext->nPosY ? pVertex->nPosY : pNext->nPosY) + nCurrentDiffYAbs * nDiff / 2;

                nIndex = nCurrentDiffX + 2 * nCurrentDiffY + 2;
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, gaDesertBorderIds_006F112C[nIndex][0], -1, 0);
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX + nCurrentDiffXAbs, nY + nCurrentDiffYAbs, gaDesertBorderIds_006F112C[nIndex][1], -1, 0);
                break;
            }
        }

        if (nDirection || (nDirection = pNext->nDirection) != 0)
        {
            nPacked |= 2;
        }

        nStyle = sub_006757E0_GetLevelStyle(pLevel, nDirection != 0);

        if (pVertex->dwFlags & 2)
        {
            if (pNext->dwFlags & 2)
            {
                nLevelPrestId = sub_00675600_LookupTable(nCurrentDiffX, nCurrentDiffY, nNextDiffX, nNextDiffY, nStyle);
            }
            else
            {
                nLevelPrestId = sub_00675600_LookupTable(nCurrentDiffX, nCurrentDiffY, 2 * nNextDiffX, 2 * nNextDiffY, nStyle);
            }
        }
        else
        {
            if (pNext->dwFlags & 2)
            {
                nLevelPrestId = sub_00675600_LookupTable(2 * nCurrentDiffX, 2 * nCurrentDiffY, nNextDiffX, nNextDiffY, nStyle);
            }
            else
            {
                nLevelPrestId = sub_00675600_LookupTable(2 * nCurrentDiffX, 2 * nCurrentDiffY, 2 * nNextDiffX, 2 * nNextDiffY, nStyle);
            }
        }

        if (nLevelPrestId == 19)
        {
            if (pVertex->nDirection == 1)
            {
                if (pNext->nDirection != 1)
                {
                    nLevelPrestId = 20;
                }
                else
                {
                    nLevelPrestId = 19;
                }
            }
            else
            {
                nLevelPrestId = 21;
            }
        }

        if (nLevelPrestId != 0)
        {
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nNextX, nNextY, nLevelPrestId, -1, 0);
            DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nNextX, nNextY, nPacked, 0);
        }

        pVertex = pNext;
        pNext = pNext->pNext;
    }
    while (pVertex != pOutdoors->pVertex);

    DRLGOUTPLACE_SetBlankBorderGridCells(pLevel);
}

#include "gen/data/Source/D2Common/Unknown_00675850.inc"

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

// 0x00678E30
int __fastcall sub_00678E30_UpdateMotion(D2MotionPathStrc* pPath)
{
    if (pPath->tStart.nX == pPath->tTarget.nX && pPath->tStart.nY == pPath->tTarget.nY)
    {
        pPath->tDirectionVector.nX = 0;
        pPath->tDirectionVector.nY = 0;
        pPath->tVelocity.nX = 0;
        pPath->tVelocity.nY = 0;
        pPath->nSpeed = 0;
        return 1;
    }
    int nDirection;
    sub_0064FD70_GetDirectionVectorFromPoints(&pPath->tDirectionVector, &nDirection, pPath->tStart, pPath->tTarget);
    pPath->nDirection = nDirection;
    if (pPath->nFlags & 0x200)
        pPath->nDirection = (pPath->nDirection - 32) & 63;
    pPath->tVelocity.nX = (pPath->tDirectionVector.nX * pPath->nSpeed) >> 8;
    pPath->tVelocity.nY = (pPath->tDirectionVector.nY * pPath->nSpeed) >> 8;
    const int nVelocityX = pPath->tVelocity.nX < 0 ? -pPath->tVelocity.nX : pPath->tVelocity.nX;
    unsigned short nTargetCoordinate = pPath->tTarget.nX;
    const int nDiffX = (int)pPath->tStart.nX - nTargetCoordinate;
    const int nDeltaX = (nDiffX < 0 ? -nDiffX : nDiffX) << 16;
    const int nVelocityY = pPath->tVelocity.nY < 0 ? -pPath->tVelocity.nY : pPath->tVelocity.nY;
    nTargetCoordinate = pPath->tTarget.nY;
    const int nDiffY = (int)pPath->tStart.nY - nTargetCoordinate;
    const int nDeltaY = nDiffY < 0 ? -nDiffY : nDiffY;
    return (nVelocityX <= nDeltaX || nVelocityY <= (nDeltaY << 16)) ? 1 : 0;
}
