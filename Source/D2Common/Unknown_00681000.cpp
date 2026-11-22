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

// 0x00680D70
void __stdcall sub_00680D70(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    pOutdoors->nVertices = 0;

    for (D2DrlgOrthStrc* pRoomData = pOutdoors->pRoomData; pRoomData; pRoomData = pRoomData->pNext)
    {
        D2DrlgLevelStrc* pRoomLevel = pRoomData->pLevel;
        D2DrlgVertexStrc* pVertex;
        switch (pRoomLevel->eLevelId)
        {
        case 1:
            pVertex = &pOutdoors->pVertices[pOutdoors->nVertices];
            pVertex->nDirection = pRoomData->nDirection;

            switch (pRoomData->nDirection)
            {
            case 0:
                pVertex->nPosX = pRoomLevel->nPosX + 59;
                pVertex->nPosY = pRoomLevel->nPosY + 19;
                break;

            case 1:
                pVertex->nPosX = pRoomLevel->nPosX + 29;
                pVertex->nPosY = pRoomLevel->nPosY + 35;
                break;

            case 2:
                pVertex->nPosX = pRoomLevel->nPosX + 4;
                pVertex->nPosY = pRoomLevel->nPosY + 22;
                break;

            case 3:
                pVertex->nPosX = pRoomLevel->nPosX + 29;
                pVertex->nPosY = pRoomLevel->nPosY + 3;
                break;

            default:
                break;
            }

            ++pOutdoors->nVertices;
            break;

        case 26:
            pVertex = &pOutdoors->pVertices[pOutdoors->nVertices];
            pVertex->nPosX = pRoomLevel->nPosX + 27;
            pVertex->nPosY = pRoomLevel->nPosY + 13;
            pVertex->nDirection = 1;
            ++pOutdoors->nVertices;
            break;
        }
    }

    for (int i = 0; i < pOutdoors->nGridWidth; ++i)
    {
        for (int j = 0; j < pOutdoors->nGridHeight; ++j)
        {
            const int nGrid0Entry = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[0], i, j);
            const unsigned int nPacked = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], i, j);

            D2DrlgVertexStrc* pVertex = &pOutdoors->pVertices[pOutdoors->nVertices];
            pVertex->nPosX = pLevel->nPosX + 8 * i + 3;
            pVertex->nPosY = pLevel->nPosY + 8 * j + 3;
            pVertex->nDirection = 4;

            const int nPickedFile = (nPacked >> 16) & 0xF;

            switch (nGrid0Entry)
            {
            case 4:
                if (nPickedFile == 3) pVertex->nDirection = 3;
                break;
            case 5:
                if (nPickedFile == 3) pVertex->nDirection = 0;
                break;
            case 6:
                if (nPickedFile == 3) pVertex->nDirection = 1;
                break;
            case 7:
                if (nPickedFile == 3) pVertex->nDirection = 2;
                break;
            case 24:
                pVertex->nDirection = 1;
                break;
            case 25:
                pVertex->nDirection = 0;
                break;
            case 51:
                pVertex->nDirection = nPickedFile != 0;
                break;
            case 52:
                pVertex->nDirection = nPickedFile != 0;
                break;
            case 28:
                if (nPickedFile == 1 && i == pOutdoors->nGridWidth - 2) pVertex->nDirection = 2;
                break;
            default:
                break;
            }

            if (pVertex->nDirection != 4)
            {
                ++pOutdoors->nVertices;
            }
        }
    }

    for (int i = 0; i < pOutdoors->nVertices; ++i)
    {
        DRLGOUTDOORS_CalculatePathCoordinates(pLevel, &pOutdoors->pVertices[i], &pOutdoors->pVertices[6 + i]);
    }
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
