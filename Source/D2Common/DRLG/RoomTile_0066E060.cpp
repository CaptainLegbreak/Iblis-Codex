struct D2DrlgActStrc;
struct D2ActiveRoomStrc;
struct D2TileLibraryEntryStrc;

struct D2DrlgStrc
{
    char unk0x000[0x468];
    int nFreedRooms;
    D2DrlgActStrc* pAct;
    char unk0x470[0x8];
    void* pMempool;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgStrc* pDrlg;
};

struct D2DrlgTileDataStrc
{
    char unk0x00[0x20];
    D2DrlgTileDataStrc* pNext;
    char unk0x24[0xC];
};

struct D2DrlgRoomTilesStrc
{
    D2DrlgTileDataStrc* pWallTiles;
    int nWalls;
    D2DrlgTileDataStrc* pFloorTiles;
    int nFloors;
    D2DrlgTileDataStrc* pRoofTiles;
    int nRoofs;
};

struct D2DrlgTileLinkStrc
{
    int bFloor;
    D2DrlgTileDataStrc* pMapTile;
    D2DrlgTileLinkStrc* pNext;
};

struct D2DrlgAnimTileGridStrc
{
    D2DrlgTileDataStrc** ppMapTileData;
    int nFrames;
    int nCurrentFrame;
    int nAnimationSpeed;
    D2DrlgAnimTileGridStrc* pNext;
};

struct D2DrlgTileGridStrc
{
    D2DrlgTileLinkStrc* pMapLinks;
    D2DrlgAnimTileGridStrc* pAnimTiles;
    int nWalls;
    int nFloors;
    int nShadows;
    D2DrlgRoomTilesStrc pTiles;
};

struct D2RoomTileStrc
{
    void* pDrlgRoom;
    D2RoomTileStrc* pNext;
    int bEnabled;
    void* unk0x0C;
    void* pLvlWarpTxtRecord;
    void* unk0x14;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x28];
    unsigned int dwFlags;
    char unk0x2C[0x4];
    D2ActiveRoomStrc* pRoom;
    char unk0x34[0x14];
    int nType;
    D2RoomTileStrc* pRoomTiles;
    char unk0x50[0x4];
    D2DrlgTileGridStrc* pTileGrid;
    D2DrlgLevelStrc* pLevel;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                  // 0x00681EF0
#pragma function(memset)
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);  // 0x0040B480
void* __fastcall sub_0040B4B0(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B4B0
void __stdcall DUNGEON_RemoveRoomFromAct(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom);                   // 0x0061A910
void __fastcall DRLGPRESET_FreeDrlgGridsFromPresetRoom(D2DrlgRoomStrc* pDrlgRoom);                                     // 0x00666610
void __fastcall DRLGPRESET_AddPresetRoomMapTiles(D2DrlgRoomStrc* pDrlgRoom);                                    // 0x00666AC0
void __fastcall DRLGLOGIC_FreeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom);                                      // 0x0066C6E0
D2TileLibraryEntryStrc* __fastcall DRLGROOMTILE_GetTileCache(D2DrlgRoomStrc* pDrlgRoom, int nType, unsigned int nPackedTileInformation);   // 0x0066D820
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitShadowTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry);   // 0x0066DF40
void __fastcall DRLGOUTROOM_FreeDrlgOutdoorRoomData(D2DrlgRoomStrc* pDrlgRoom);                                        // 0x0067D680
void __fastcall DRLGOUTROOM_InitializeDrlgOutdoorRoom(D2DrlgRoomStrc* pDrlgRoom);                                        // 0x0067D710

// 0x0066E060
void __fastcall DRLGROOMTILE_InitTileShadow(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, unsigned int nPackedTileInformation)
{
    DRLGROOMTILE_InitShadowTileData(pDrlgRoom, 0, nX, nY, nPackedTileInformation, DRLGROOMTILE_GetTileCache(pDrlgRoom, 13, nPackedTileInformation));
}

// 0x0066EE70
void __fastcall DRLGROOMTILE_AddRoomMapTiles(D2DrlgRoomStrc* pDrlgRoom)
{
    switch (pDrlgRoom->nType)
    {
    case 1:
        DRLGOUTROOM_InitializeDrlgOutdoorRoom(pDrlgRoom);
        break;

    case 2:
        DRLGPRESET_AddPresetRoomMapTiles(pDrlgRoom);
        break;
    }

    pDrlgRoom->dwFlags |= 0x100000;
}

// 0x0066EEA0
void __fastcall DRLGROOMTILE_AllocTileGrid(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!pDrlgRoom->pTileGrid)
    {
        pDrlgRoom->pTileGrid = (D2DrlgTileGridStrc*)sub_0040B430(pDrlgRoom->pLevel->pDrlg->pMempool, sizeof(D2DrlgTileGridStrc), ".\\DRLG\\RoomTile.cpp", 1331, 0);
        memset(pDrlgRoom->pTileGrid, 0, sizeof(D2DrlgTileGridStrc));
    }
}

// 0x0066EEE0
void __fastcall DRLGROOMTILE_AllocTileData(D2DrlgRoomStrc* pDrlgRoom)
{
    void* pMemPool = pDrlgRoom->pLevel->pDrlg->pMempool;
    D2DrlgRoomTilesStrc* pRoomTiles = &pDrlgRoom->pTileGrid->pTiles;

    if (pRoomTiles->nFloors)
    {
        pRoomTiles->pFloorTiles = (D2DrlgTileDataStrc*)sub_0040B430(pMemPool, sizeof(D2DrlgTileDataStrc) * pRoomTiles->nFloors, ".\\DRLG\\RoomTile.cpp", 1349, 0);
        memset(pRoomTiles->pFloorTiles, 0, sizeof(D2DrlgTileDataStrc) * pRoomTiles->nFloors);
    }

    if (pRoomTiles->nWalls)
    {
        pRoomTiles->pWallTiles = (D2DrlgTileDataStrc*)sub_0040B430(pMemPool, sizeof(D2DrlgTileDataStrc) * pRoomTiles->nWalls, ".\\DRLG\\RoomTile.cpp", 1355, 0);
        memset(pRoomTiles->pWallTiles, 0, sizeof(D2DrlgTileDataStrc) * pRoomTiles->nWalls);
    }

    if (pRoomTiles->nRoofs && !pRoomTiles->pRoofTiles)
    {
        pRoomTiles->pRoofTiles = (D2DrlgTileDataStrc*)sub_0040B430(pMemPool, sizeof(D2DrlgTileDataStrc) * pRoomTiles->nRoofs, ".\\DRLG\\RoomTile.cpp", 1361, 0);
        memset(pRoomTiles->pRoofTiles, 0, sizeof(D2DrlgTileDataStrc) * pRoomTiles->nRoofs);
    }
}

// 0x0066EFB0
void __fastcall DRLGROOMTILE_ReallocRoofTileGrid(void* pMemPool, D2DrlgTileGridStrc* pTileGrid, int nAdditionalRoofs)
{
    if (nAdditionalRoofs)
    {
        D2DrlgRoomTilesStrc* pRoomTiles = &pTileGrid->pTiles;
        pRoomTiles->pRoofTiles = (D2DrlgTileDataStrc*)sub_0040B4B0(pMemPool, pRoomTiles->pRoofTiles, sizeof(D2DrlgTileDataStrc) * (nAdditionalRoofs + pRoomTiles->nRoofs), ".\\DRLG\\RoomTile.cpp", 1377, 0);

        int nCounter = 0;
        while (nCounter < pTileGrid->nShadows - 1)
        {
            pRoomTiles->pRoofTiles[nCounter].pNext = &pRoomTiles->pRoofTiles[nCounter + 1];
            ++nCounter;
        }

        pRoomTiles->pRoofTiles[nCounter].pNext = 0;
        pRoomTiles->nRoofs += nAdditionalRoofs;
    }
}

// 0x0066F050
static void sub_0066F050(D2DrlgRoomStrc* pDrlgRoom, void* pMemPool)
{
    D2DrlgRoomTilesStrc* pRoomTiles = pDrlgRoom->pTileGrid ? &pDrlgRoom->pTileGrid->pTiles : 0;
    if (pRoomTiles)
    {
        if (pRoomTiles->pWallTiles)
        {
            sub_0040B480(pMemPool, pRoomTiles->pWallTiles, ".\\DRLG\\RoomTile.cpp", 1426, 0);
        }

        if (pRoomTiles->pFloorTiles)
        {
            sub_0040B480(pMemPool, pRoomTiles->pFloorTiles, ".\\DRLG\\RoomTile.cpp", 1427, 0);
        }

        if (pRoomTiles->pRoofTiles)
        {
            sub_0040B480(pMemPool, pRoomTiles->pRoofTiles, ".\\DRLG\\RoomTile.cpp", 1428, 0);
        }
    }
}

// 0x0066F0B0
void __fastcall DRLGROOMTILE_FreeTileGrid(D2DrlgRoomStrc* pDrlgRoom)
{
    void* pMemPool = pDrlgRoom->pLevel->pDrlg->pMempool;

    sub_0066F050(pDrlgRoom, pMemPool);

    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->pTileGrid;
    if (pTileGrid)
    {
        D2DrlgTileLinkStrc* pTileLink = pTileGrid->pMapLinks;
        while (pTileLink)
        {
            D2DrlgTileLinkStrc* pFree = pTileLink;
            pTileLink = pTileLink->pNext;
            sub_0040B480(pMemPool, pFree, ".\\DRLG\\RoomTile.cpp", 1453, 0);
        }
        pTileGrid->pMapLinks = 0;

        D2DrlgAnimTileGridStrc* pAnimTileGrid = pTileGrid->pAnimTiles;
        while (pAnimTileGrid)
        {
            D2DrlgAnimTileGridStrc* pFree = pAnimTileGrid;
            pAnimTileGrid = pAnimTileGrid->pNext;
            sub_0040B480(pMemPool, pFree->ppMapTileData, ".\\DRLG\\RoomTile.cpp", 1465, 0);
            sub_0040B480(pMemPool, pFree, ".\\DRLG\\RoomTile.cpp", 1466, 0);
        }

        sub_0040B480(pMemPool, pTileGrid, ".\\DRLG\\RoomTile.cpp", 1469, 0);
        pDrlgRoom->pTileGrid = 0;
    }
}

// 0x0066F1A0
void __fastcall DRLGROOMTILE_FreeRoom(D2DrlgRoomStrc* pDrlgRoom, int bKeepRoom)
{
    D2DrlgStrc* pDrlg = pDrlgRoom->pLevel->pDrlg;

    if (!bKeepRoom && pDrlgRoom->pRoom)
    {
        DUNGEON_RemoveRoomFromAct(pDrlg->pAct, pDrlgRoom->pRoom);
    }

    pDrlgRoom->pRoom = 0;

    DRLGLOGIC_FreeDrlgCoordList(pDrlgRoom);

    if (pDrlgRoom->dwFlags & 0x100000)
    {
        pDrlgRoom->dwFlags ^= 0x100000;
        ++pDrlg->nFreedRooms;
        DRLGROOMTILE_FreeTileGrid(pDrlgRoom);

        switch (pDrlgRoom->nType)
        {
        case 1:
            DRLGOUTROOM_FreeDrlgOutdoorRoomData(pDrlgRoom);
            break;

        case 2:
            DRLGPRESET_FreeDrlgGridsFromPresetRoom(pDrlgRoom);
            break;
        }

        for (D2RoomTileStrc* pRoomTile = pDrlgRoom->pRoomTiles; pRoomTile; pRoomTile = pRoomTile->pNext)
        {
            pRoomTile->unk0x14 = 0;
            pRoomTile->unk0x0C = 0;
        }

        if (bKeepRoom)
        {
            pDrlgRoom->dwFlags |= 0x200000;
        }
    }
}
