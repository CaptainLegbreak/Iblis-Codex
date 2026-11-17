extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2TileStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2LevelsTxt
{
    char unk0x000[0x09];
    unsigned char nDrawEdges;
    char unk0x00A[0x20A];
    unsigned int dwFloorFilter;
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

struct D2DrlgTileDataStrc
{
    int nWidth;
    int nHeight;
    int nPosX;
    int nPosY;
    int nCoordList;
    unsigned int dwFlags;
    char unk0x18[0x18];
};

struct D2FloorViewArgStrc
{
    char unk0x00[0x24];
    int nX;
    int nY;
};

struct D2FloorTileViewStrc
{
    int nMode;
    int bPerspective;
    int bTickFlag;
    int bMudFlag;
    int nPhase;
    unsigned int dwTickA;
    unsigned int dwTickB;
    D2SeedStrc* pSeed;
    int nBorder;
    D2FloorViewArgStrc* pArg;
    int bEdges;
    int nMinX;
    int nMaxX;
    int nMinY;
    int nMaxY;
    int nOffsetX;
    int nOffsetY;
    void __thiscall sub_004DE410_DrawFloorTile(D2TileStrc* pTile, int nArg, int nScreenX, int nScreenY, int nX, int nY);
    void __thiscall sub_004DE630_DrawTileAt(int nX, int nY);
    void __thiscall sub_004DE6C0_DrawTileTriple(int nX, int nY, int nStepX, int nStepY);
    void __thiscall sub_004DE730_UpdateView(void* pArgument);
};

int __cdecl sub_0044DB00();                                                                                 // 0x0044DB00
int __cdecl sub_0045AE90();                                                                         // 0x0045AE90
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                           // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom();                                                     // 0x004646A0
int __cdecl sub_00473770_IsMudLevel();                                                                      // 0x00473770
float __cdecl sub_00473C80_GetPhaseLevel();                                                                 // 0x00473C80
int __stdcall D2GFX_GetResolutionMode();                                                                    // 0x004F5160
int __stdcall D2GFX_CheckPerspective();                                                                     // 0x004F51D0
int __cdecl sub_004F5210();                                                                                 // 0x004F5210
D2DrlgTileDataStrc* __stdcall DUNGEON_GetFloorTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pFloorCount);     // 0x00619660
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

static __forceinline int CLIENTS_GetUnitX_FloorView(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitY_FloorView(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004DE730
void __thiscall D2FloorTileViewStrc::sub_004DE730_UpdateView(void* pArgument)
{
    D2ActiveRoomStrc** ppRooms;
    int nRooms;
    int nTiles;

    nMode = sub_004F5210();
    bPerspective = D2GFX_CheckPerspective();
    const unsigned int dwTick = sub_0044DB00();
    bTickFlag = 0;
    bMudFlag = 0;
    nPhase = (int)(sub_00473C80_GetPhaseLevel() * 1000.0);
    const int nBorderType = sub_0045AE90();
    nBorder = nBorderType;
    pArg = (D2FloorViewArgStrc*)pArgument;

    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    bEdges = pRoom && DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom))->nDrawEdges && !nBorderType && D2GFX_GetResolutionMode() == 2;

    nMinX = 0x7FFFFFFF;
    nMaxX = 0x80000000;
    nMinY = 0x7FFFFFFF;
    nMaxY = 0x80000000;
    nOffsetX = 0x50 - pArg->nX;
    nOffsetY = -0x50 - pArg->nY;

    if (dwTick > dwTickA + 3)
    {
        dwTickA = dwTick;
        if (nPhase)
            bTickFlag = 1;
    }

    if (sub_00473770_IsMudLevel() && dwTick > dwTickB + 0x19)
    {
        dwTickB = dwTick;
        bMudFlag = 1;
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x11E);
    pSeed = &pPlayer->pSeed;

    pRoom = sub_004646A0_GetPlayerRoom();
    if (!pRoom)
        return;

    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
    D2LevelsTxt* pLevelsTxt = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pLevelsTxt, 0x130);
    const int bNoFilter = pLevelsTxt->dwFloorFilter == 0;

    const int& nViewX = nOffsetX;
    for (int i = 0; i < nRooms; ++i)
    {
        D2DrlgCoordsStrc tCoords;
        DUNGEON_GetRoomCoordinates(ppRooms[i], &tCoords);
        for (unsigned int nLayer = 1; nLayer < 3; ++nLayer)
        {
            const int bArg = !bNoFilter && nLayer == 1;
            D2DrlgTileDataStrc* pTile = DUNGEON_GetFloorTilesFromRoom(ppRooms[i], &nTiles);
            while (nTiles)
            {
                if (((pTile->dwFlags >> 0xE) & 7) == nLayer)
                {
                    sub_004DE410_DrawFloorTile((D2TileStrc*)pTile, bArg, nViewX + pTile->nWidth,
                        pTile->nHeight + nOffsetY, tCoords.nSubtileX + 5 * pTile->nPosX, tCoords.nSubtileY + 5 * pTile->nPosY);
                }
                --nTiles;
                ++pTile;
            }
        }
    }

    if (!bEdges)
        return;

    const int nRangeA = bPerspective ? 0x21 : 0x1E;
    const int nRangeB = bPerspective ? 0x17 : 0x19;
    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    if (!pUnit)
        return;

    const int nX = CLIENTS_GetUnitX_FloorView(pUnit);
    const int nY = CLIENTS_GetUnitY_FloorView(pUnit);
    if (nX - nMinX < nRangeA)
        sub_004DE6C0_DrawTileTriple(nMinX - 5, nY, 0, -5);
    if (nMaxX - nX < nRangeB)
        sub_004DE6C0_DrawTileTriple(nMaxX + 5, nY, 0, 5);
    if (nY - nMinY < nRangeA)
        sub_004DE6C0_DrawTileTriple(nX, nMinY - 5, -5, 0);
    if (nMaxY - nY < nRangeB)
        sub_004DE6C0_DrawTileTriple(nX, nMaxY + 5, 5, 0);
}
