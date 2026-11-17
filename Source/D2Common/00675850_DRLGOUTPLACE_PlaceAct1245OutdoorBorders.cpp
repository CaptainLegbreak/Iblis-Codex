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

extern int gaLookupRow_006F0FD0[];                                                                          // 0x006F0FD0
extern int gaLookupRow_006F1088[];                                                                          // 0x006F1088
extern int gaLookupSmall_006F0630[][4];                                                                     // 0x006F0630
extern int gaLookupLarge_006F06F0[][2];                                                                     // 0x006F06F0
extern int gaDesertBorderIds_006F112C[][2];                                                                 // 0x006F112C

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nPickedFile, int bFlag); // 0x006743C0
void __fastcall DRLGOUTPLACE_SetBlankBorderGridCells(D2DrlgLevelStrc* pLevel);                              // 0x00675670
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation);   // 0x0067C4F0
void __fastcall sub_0067D280(D2DrlgVertexStrc* pVertex, int* pDirectionX, int* pDirectionY);  // 0x0067D280
int __fastcall sub_0067DCE0(D2DrlgLevelStrc* pLevel);                                               // 0x0067DCE0

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

#include "gen/data/Source/D2Common/00675850_DRLGOUTPLACE_PlaceAct1245OutdoorBorders.inc"
