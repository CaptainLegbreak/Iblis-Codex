extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2TileLibraryEntryStrc;

struct tagRECT
{
    int left;
    int top;
    int right;
    int bottom;
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

struct D2DrlgTileDataStrc
{
    int nWidth;
    int nHeight;
    int nPosX;
    int nPosY;
    D2RoomCoordListStrc* pCoordList;
    unsigned int dwFlags;
    D2TileLibraryEntryStrc* pTile;
    int nTileType;
    D2DrlgTileDataStrc* pNext;
    int unk0x24;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nIntensity;
    int unk0x2C;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

D2DrlgTileDataStrc* __stdcall DUNGEON_GetWallTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pWallCount);       // 0x006196A0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
D2RoomCoordListStrc* __stdcall DUNGEON_GetRoomCoordList(D2ActiveRoomStrc* pRoom);                           // 0x0061AD50
void __stdcall sub_00643260(int* pX, int* pY);                                                   // 0x00643260
void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY);                                            // 0x00643310
int __stdcall TILE_GetFlags16(D2TileLibraryEntryStrc* pTile);                                               // 0x00604BC0
void __stdcall D2GFX_UtilDiamond(tagRECT* pRect, unsigned char nPaletteIndex);                              // 0x004F6280
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380
void __cdecl D2GFX_OutputString(int nXPos, int nYPos, const char* szFormat, ...);                           // 0x004F6890
void __fastcall sub_0045B1A0_DrawDiamond(int nX, int nY, unsigned char nColor);
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom();
extern int gdwGlobal_007A5208;                                                                              // 0x007A5208
extern int gdwGlobal_007A520C;                                                                              // 0x007A520C
extern const char gszFormatInt_006D57BC[];                                                                  // 0x006D57BC

// 0x0045B5F0
void __stdcall sub_0045B5F0(D2ActiveRoomStrc* pRoom)
{
    int nTiles;
    D2DrlgTileDataStrc* pTiles = DUNGEON_GetWallTilesFromRoom(pRoom, &nTiles);
    D2_ASSERT(pTiles || !nTiles, 725);

    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    for (unsigned int i = 0; i < (unsigned int)nTiles; ++i)
    {
        D2DrlgTileDataStrc* pTile = &pTiles[i];
        if (!pTile->pCoordList)
        {
            continue;
        }

        int nX = (pTile->nPosX + tCoords.nTileXPos) * 5 + 3;
        int nY = (pTile->nPosY + tCoords.nTileYPos) * 5 + 3;
        sub_00643260(&nX, &nY);

        if (pTile->nTileType == 15 || (pTile->dwFlags & 0x1C000) != 0x4000)
        {
            continue;
        }

        if (TILE_GetFlags16(pTile->pTile) & 4)
        {
            const int nDiamondX = nX + 0x20;
            tagRECT tRect;
            tRect.left = nDiamondX - gdwGlobal_007A520C - 0x10;
            tRect.right = nDiamondX - gdwGlobal_007A520C + 0x10;
            tRect.top = nY - gdwGlobal_007A5208;
            tRect.bottom = nY - gdwGlobal_007A5208 + 0x10;
            D2GFX_UtilDiamond(&tRect, 0x78);
        }
        else if (pTile->dwFlags & 0x800)
        {
            sub_0045B1A0_DrawDiamond(nX + 0x10, nY + 8, 0x78);
        }
        else
        {
            sub_0045B1A0_DrawDiamond(nX, nY, 0xFF);
        }

        nX -= gdwGlobal_007A520C + 7;
        nY -= gdwGlobal_007A5208;
        D2GFX_OutputString(nX, nY, gszFormatInt_006D57BC, pTile->pCoordList->nIndex);
    }

    if (pRoom == sub_004646A0_GetPlayerRoom())
    {
        int aX[4];
        int aY[4];
        for (D2RoomCoordListStrc* pCoordList = DUNGEON_GetRoomCoordList(pRoom); pCoordList; pCoordList = pCoordList->pNext)
        {
            aX[0] = aX[1] = pCoordList->pBox[0].nPosX;
            aX[2] = aX[3] = pCoordList->pBox[0].nWidth;
            aY[0] = aY[2] = pCoordList->pBox[0].nPosY;
            aY[1] = aY[3] = pCoordList->pBox[0].nHeight;

            for (int j = 0; j < 4; ++j)
            {
                DUNGEON_GameTileToClientCoords(&aX[j], &aY[j]);
                aX[j] -= gdwGlobal_007A520C;
                aY[j] -= gdwGlobal_007A5208;
            }

            if (pRoom == sub_004646A0_GetPlayerRoom())
            {
                D2GFX_DrawLine(aX[0], aY[0], aX[0], aY[0] + 0x10, 0x78, 0xFF);
                D2GFX_DrawLine(aX[1], aY[1], aX[1] + 0x10, aY[1], 0x78, 0xFF);
                D2GFX_DrawLine(aX[2], aY[2], aX[2] - 0x10, aY[2], 0x78, 0xFF);
                D2GFX_DrawLine(aX[3], aY[3], aX[3], aY[3] - 0x10, 0x78, 0xFF);
            }

            D2GFX_DrawLine(aX[0], aY[0], aX[1], aY[1], 0x78, 0xFF);
            D2GFX_DrawLine(aX[0], aY[0], aX[2], aY[2], 0x78, 0xFF);
            D2GFX_DrawLine(aX[1], aY[1], aX[3], aY[3], 0x78, 0xFF);
            D2GFX_DrawLine(aX[2], aY[2], aX[3], aY[3], 0x78, 0xFF);
        }
    }
}
