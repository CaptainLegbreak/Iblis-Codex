enum D2C_U04DrlgLogicConstants
{
    FLAG_OPERATION_OVERWRITE = 3,
};

struct D2DrlgGridStrc
{
    char unk0x00[0x14];
};

struct D2DrlgStrc
{
    char unk0x000[0x478];
    void* pMempool;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgStrc* pDrlg;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x34];
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
    char unk0x44[0x14];
    D2DrlgLevelStrc* pLevel;
};

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2RoomCoordListStrc
{
    D2DrlgCoordStrc pBox[2];
    int bNode;
    int bRoomActive;
    int nIndex;
    D2RoomCoordListStrc* pNext;
};

struct D2DrlgLogicalRoomInfoStrc
{
    int dwFlags;
    int nLists;
    D2DrlgGridStrc pIndexX;
    D2DrlgGridStrc pIndexY;
    D2RoomCoordListStrc* pCoordList;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pDrlgGrid, int nWidth, int nHeight); // 0x0067CB80
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY);                            // 0x0067C570
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pDrlgGrid, int nX, int nY, int nFlag, int nOperation); // 0x0067C4F0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

// 0x0066CA50
void __stdcall DRLGLOGIC_AssignCoordListsForGrids(D2DrlgRoomStrc* pDrlgRoom, D2DrlgLogicalRoomInfoStrc* pDrlgCoordList)
{
    void* pMempool = pDrlgRoom->pLevel->pDrlg->pMempool;
    DRLGGRID_InitializeGridCells(pMempool, &pDrlgCoordList->pIndexY, pDrlgRoom->nTileWidth + 1, pDrlgRoom->nTileHeight + 1);
    const int nWidth = pDrlgRoom->nTileWidth + 1;
    const int nHeight = pDrlgRoom->nTileHeight + 1;

    for (int nY = 0; nY < nHeight; ++nY)
    {
        for (int nX = 0; nX < nWidth; ++nX)
        {
            const int nFlags = DRLGGRID_GetGridEntry(&pDrlgCoordList->pIndexX, nX, nY);
            const int nIndex = nFlags & 0x0FFFFFFF;

            if (!DRLGGRID_GetGridEntry(&pDrlgCoordList->pIndexY, nX, nY))
            {
                D2RoomCoordListStrc* pRoomCoordList = (D2RoomCoordListStrc*)FOG_AllocPool(pMempool, sizeof(D2RoomCoordListStrc), ".\\DRLG\\DrlgLogic.cpp", 0x201, 0);
                memset(pRoomCoordList, 0, sizeof(D2RoomCoordListStrc));

                pRoomCoordList->nIndex = nIndex;
                pRoomCoordList->bNode = (nFlags & 0x20000000) == 0x20000000;
                pRoomCoordList->pNext = pDrlgCoordList->pCoordList;

                pDrlgCoordList->pCoordList = pRoomCoordList;

                pRoomCoordList->pBox[0].nPosX = nX;
                pRoomCoordList->pBox[0].nPosY = nY;
                int nTmpWidth;
                for (nTmpWidth = nX; nTmpWidth < nWidth; ++nTmpWidth)
                {
                    if (nIndex != (DRLGGRID_GetGridEntry(&pDrlgCoordList->pIndexX, nTmpWidth, nY) & 0x0FFFFFFF))
                    {
                        break;
                    }

                    if (DRLGGRID_GetGridEntry(&pDrlgCoordList->pIndexY, nTmpWidth, nY))
                    {
                        break;
                    }
                }
                pRoomCoordList->pBox[0].nWidth = nTmpWidth;

                int bBreak = 0;
                int nTmpHeight;
                for (nTmpHeight = nY; !bBreak && nTmpHeight < nHeight; ++nTmpHeight)
                {
                    for (int i = nX; i < pRoomCoordList->pBox[0].nWidth; ++i)
                    {
                        if (nIndex != (DRLGGRID_GetGridEntry(&pDrlgCoordList->pIndexX, i, nTmpHeight) & 0x0FFFFFFF) || DRLGGRID_GetGridEntry(&pDrlgCoordList->pIndexY, i, nTmpHeight))
                        {
                            bBreak = 1;
                            --nTmpHeight;
                            break;
                        }
                    }
                }
                pRoomCoordList->pBox[0].nHeight = nTmpHeight;

                for (nTmpHeight = pRoomCoordList->pBox[0].nPosY; nTmpHeight < pRoomCoordList->pBox[0].nHeight; ++nTmpHeight)
                {
                    for (int i = pRoomCoordList->pBox[0].nPosX; i < pRoomCoordList->pBox[0].nWidth; ++i)
                    {
                        DRLGGRID_AlterGridFlag(&pDrlgCoordList->pIndexY, i, nTmpHeight, (int)pRoomCoordList, FLAG_OPERATION_OVERWRITE);
                    }
                }

                pRoomCoordList->pBox[0].nPosY += pDrlgRoom->nTileYPos;
                pRoomCoordList->pBox[0].nHeight += pDrlgRoom->nTileYPos;
                pRoomCoordList->pBox[0].nPosX += pDrlgRoom->nTileXPos;
                pRoomCoordList->pBox[0].nWidth += pDrlgRoom->nTileXPos;

                pRoomCoordList->pBox[1] = pRoomCoordList->pBox[0];

                if (pRoomCoordList->pBox[1].nWidth >= pDrlgRoom->nTileWidth + pDrlgRoom->nTileXPos)
                {
                    pRoomCoordList->pBox[1].nWidth = pDrlgRoom->nTileWidth + pDrlgRoom->nTileXPos;
                }

                if (pRoomCoordList->pBox[1].nHeight >= pDrlgRoom->nTileYPos + pDrlgRoom->nTileHeight)
                {
                    pRoomCoordList->pBox[1].nHeight = pDrlgRoom->nTileYPos + pDrlgRoom->nTileHeight;
                }

                if (pRoomCoordList->pBox[1].nPosX >= pDrlgRoom->nTileWidth + pDrlgRoom->nTileXPos || pRoomCoordList->pBox[1].nPosY >= pDrlgRoom->nTileYPos + pDrlgRoom->nTileHeight)
                {
                    pRoomCoordList->pBox[1].nPosX = 0;
                    pRoomCoordList->pBox[1].nPosY = 0;
                    pRoomCoordList->pBox[1].nWidth = 0;
                    pRoomCoordList->pBox[1].nHeight = 0;
                }
            }
        }
    }
}
