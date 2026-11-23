#include "D2Common.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"

struct D2DrlgVertexStrc;
struct D2DrlgOrthStrc;
struct D2DrlgOutdoorInfoStrc;
struct D2DrlgRouteNodeStrc;






int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
int __fastcall DRLGOUTDOORS_TestGridCellSpawnValid(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674200
void __fastcall DRLGOUTWILD_GetBridgeCoords(D2DrlgLevelStrc* pLevel, int* pX, int* pY); // 0x0067FC20
extern const int gnOutdoorScanXOffsets[4]; // 0x006F2810
extern const int gnOutdoorScanYOffsets[4]; // 0x006F2800

struct D2DrlgRouteNodeStrc
{
    int unk0x00[5];
    int nTries;
    unsigned char* pTurn;
    unsigned char nDirection;
    unsigned char unk0x1D[3];
    D2DrlgRouteNodeStrc* pParent;
};

static D2DrlgRouteNodeStrc* __stdcall sub_00681560(D2DrlgRouteNodeStrc* pNode, D2DrlgRouteNodeStrc** ppStart);

// build: symbol ?DRLGOUTDOORS_CalculatePathCoordinates@@YAXPAUD2DrlgLevelStrc@@PAUD2DrlgVertexStrc@@1@Z 0x00680CC0
static void DRLGOUTDOORS_CalculatePathCoordinates(D2DrlgLevelStrc* pLevel, D2DrlgVertexStrc* pVertex1, D2DrlgVertexStrc* pVertex2)
{
    pVertex2->nPosX = pVertex1->nPosX - pLevel->nPosX;
    pVertex2->nPosY = pVertex1->nPosY - pLevel->nPosY;

    switch (pVertex1->nDirection)
    {
    case 0:
        pVertex2->nPosX = 8 * (pVertex2->nPosX / 8) + 11;
        break;

    case 1:
        pVertex2->nPosY = 8 * (pVertex2->nPosY / 8) + 11;
        break;

    case 2:
        pVertex2->nPosX = 8 * (pVertex2->nPosX / 8) - 5;
        break;

    case 3:
        pVertex2->nPosY = 8 * (pVertex2->nPosY / 8) - 5;
        break;

    default:
        break;
    }

    pVertex2->nPosX += pLevel->nPosX;
    pVertex2->nPosY += pLevel->nPosY;
}

// 0x00681000
void __stdcall sub_00681000(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    int nX = -1;
    int nY = -1;

    if (pOutdoors->dwFlags & 0x10 && (DRLGOUTWILD_GetBridgeCoords(pLevel, &nX, &nY), nX != -1))
    {
        const int nPosX = pLevel->nPosX + 8 * nX + 3;
        const int nPosY = pLevel->nPosY + 8 * nY + 3;

        for (int i = 0; i < pOutdoors->nVertices; ++i)
        {
            if (pOutdoors->pVertices[i].nPosX > nPosX)
            {
                pOutdoors->pVertices[18 + i].nPosX = nPosX + 8;
                pOutdoors->pVertices[18 + i].nDirection = 0;
                pOutdoors->pVertices[18 + i].nPosY = nPosY;
            }
            else
            {
                pOutdoors->pVertices[18 + i].nPosX = nPosX;
                pOutdoors->pVertices[18 + i].nDirection = 2;
                pOutdoors->pVertices[18 + i].nPosY = nPosY;
            }
        }
    }
    else
    {
        const int* pnCount = &pOutdoors->nVertices;
        for (int i = 0; i < *pnCount; ++i)
        {
            if (!i)
            {
                int nPosX = 0;
                int nPosY = 0;
                int j = 0;
                if (*pnCount == 1)
                {
                    nPosX = pOutdoors->nGridWidth / 2;
                    nPosY = pOutdoors->nGridHeight / 2;
                }
                else
                {
                    for (int m = 0; m < *pnCount; ++m)
                    {
                        nPosX += pOutdoors->pVertices[m].nPosX - pLevel->nPosX;
                        nPosY += pOutdoors->pVertices[m].nPosY - pLevel->nPosY;
                    }
                    nPosX /= 8 * pOutdoors->nVertices;
                    nPosY /= 8 * pOutdoors->nVertices;
                }
                int bBreak = 0;
                for (; j < 8; ++j)
                {
                    if (bBreak)
                    {
                        break;
                    }

                    for (int k = 0; k < 4; ++k)
                    {
                        nX = nPosX + j * gnOutdoorScanXOffsets[k];
                        nY = nPosY + j * gnOutdoorScanYOffsets[k];

                        if (nX >= 0 && nX < pOutdoors->nGridWidth && nY >= 0 && nY < pOutdoors->nGridHeight)
                        {
                            if (DRLGOUTDOORS_TestGridCellSpawnValid(pLevel, nX, nY))
                            {
                                bBreak = 1;
                                break;
                            }
                        }
                    }
                }

                pOutdoors->pVertices[18].nPosX = pLevel->nPosX + 8 * nX + 3;
                pOutdoors->pVertices[18].nPosY = pLevel->nPosY + 8 * nY + 3;
                pOutdoors->pVertices[18].nDirection = 4;
            }
            else
            {
                pOutdoors->pVertices[18 + i].nPosX = pOutdoors->pVertices[18].nPosX;
                pOutdoors->pVertices[18 + i].nPosY = pOutdoors->pVertices[18].nPosY;
                pOutdoors->pVertices[18 + i].nDirection = 4;
            }
        }
    }

    for (int i = 0; i < pOutdoors->nVertices; ++i)
    {
        DRLGOUTDOORS_CalculatePathCoordinates(pLevel, &pOutdoors->pVertices[18 + i], &pOutdoors->pVertices[12 + i]);
    }
}

#include "gen/data/Source/D2Common/Unknown_00681000.inc"

// 0x00681560
static D2DrlgRouteNodeStrc* __stdcall sub_00681560(D2DrlgRouteNodeStrc* pNode, D2DrlgRouteNodeStrc** ppStart)
{
    if (pNode->nTries < 4)
    {
        ++pNode->pTurn;
        pNode->nDirection = (*pNode->pTurn + pNode->nDirection) & 3;
    }
    ++pNode->nTries;

    while (pNode->nTries == 3)
    {
        if (pNode == *ppStart)
        {
            return 0;
        }

        pNode = pNode->pParent;
        ++pNode->pTurn;
        pNode->nDirection = (*pNode->pTurn + pNode->nDirection) & 3;
        ++pNode->nTries;
    }

    return pNode;
}

// build: context sub_00681560_Shim
// calling-convention shim (not game code)
D2DrlgRouteNodeStrc* __stdcall sub_00681560_Shim(D2DrlgRouteNodeStrc* pNode, D2DrlgRouteNodeStrc** ppStart)
{
    return sub_00681560(pNode, ppStart);
}
