#include "D2Common.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2DrlgTileDataStrc;
struct D2SeedStrc;
union D2C_PackedTileInformation;
struct D2DrlgRoomTilesStrc;
struct Tile;
struct T0066E090;
struct Drlg;
struct Level;
struct Room;
struct D2DrlgTileLinkStrc;
struct D2DrlgCoordStrc;
struct D2RoomTileStrc;

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

struct D2DrlgRoomStrc
{
    char unk0x00[0x4];
    unsigned int dwInitSeed;
    char unk0x08[0xC];
    D2SeedStrc pSeed;
    unsigned char unk_1C[0xC];
    unsigned int dwFlags;
    char unk0x2C[0x4];
    D2ActiveRoomStrc* pRoom;
    union
    {
        struct
        {
            D2DrlgCoordStrc pDrlgCoord;
        };
        struct
        {
            int nTileXPos;
            int nTileYPos;
        };
    };
    unsigned char unk_44[0x4];
    int nType;
    D2RoomTileStrc* pRoomTiles;
    char unk0x50[0x4];
    D2DrlgTileGridStrc* pTileGrid;
    D2DrlgLevelStrc* pLevel;
    unsigned char unk_5C[0xC];
    void* pTiles;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __stdcall D2CMP_GetTiles(void** ppTiles, int nTileType, int nStyle, int nSequence, D2TileLibraryEntryStrc** ppTileEntries, int nMaxEntries); // 0x00604AE0
int __stdcall TILE_GetRarity(D2TileLibraryEntryStrc* pTile); // 0x00604C20

union D2C_PackedTileInformation
{
    unsigned int nPackedValue;
    struct
    {
        unsigned int bIsWall : 1;
        unsigned int bIsFloor : 1;
        unsigned int bLOS : 1;
        unsigned int bEnclosed : 1;
        unsigned int bExit : 1;
        unsigned int bUnk0x20 : 1;
        unsigned int bLayerBelow : 1;
        unsigned int bLayerAbove : 1;
        unsigned int nTileSequence : 8;
        unsigned int bFillLOS : 1;
        unsigned int bUnwalkable : 1;
        unsigned int nWallLayer : 2;
        unsigned int nTileStyle : 6;
        unsigned int bRevealHidden : 1;
        unsigned int bShadow : 1;
        unsigned int bLinkage : 1;
        unsigned int bObjectWall : 1;
        unsigned int bUnk0x40000000 : 1;
        unsigned int bHidden : 1;
    };
};

struct D2DrlgTileDataStrc
{
    int nWidth;
    int nHeight;
    int nPosX;
    int nPosY;
    int unk0x10;
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

struct D2DrlgRoomTilesStrc
{
    D2DrlgTileDataStrc* pWallTiles;
    int nWalls;
    D2DrlgTileDataStrc* pFloorTiles;
    int nFloors;
    D2DrlgTileDataStrc* pRoofTiles;
    int nRoofs;
};

struct D2DrlgTileGridStrc
{
    D2DrlgTileLinkStrc* pMapLinks;
    void* pAnimTiles;
    int nWalls;
    int nFloors;
    int nShadows;
    D2DrlgRoomTilesStrc pTiles;
};

void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY); // 0x00643310
D2TileLibraryEntryStrc* __fastcall DRLGROOMTILE_GetTileCache(D2DrlgRoomStrc* pDrlgRoom, int nType, unsigned int nPackedTileInformation); // 0x0066D820
void __fastcall DRLGROOMTILE_AddTilePresetUnits(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, unsigned int nPackedTileInformation, int nX, int nY, int nTileType); // 0x0066D9E0

struct Tile { char pad0[0x20]; Tile* next; char f_24[0xC]; };

struct T0066E090 { char pad0[0x10]; int count; char pad14[0x10]; Tile* tiles; int capacity; };

struct Drlg { char pad0[0x478]; void* pool; };

struct Level { char pad0[0x1B4]; Drlg* drlg; };

struct Room { char pad0[0x54]; T0066E090* grid; Level* level; };

void __fastcall sub_0040B480(void*,void*,const char*,int,int); // 0x0040B480
void* __fastcall sub_0040B4B0(void*,void*,int,const char*,int,int); // 0x0040B4B0

struct D2DrlgTileLinkStrc
{
    int bFloor;
    D2DrlgTileDataStrc* pMapTile;
    D2DrlgTileLinkStrc* pNext;
};

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall sub_M105_EmitSink_0066E5E0(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY);
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY); // 0x0067C570
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
void __fastcall DRLGOUTPLACE_InitOutdoorRoomGrids(D2DrlgRoomStrc* pDrlgRoom); // 0x0067D2D0
void __fastcall DRLGPRESET_InitPresetRoomGrids(D2DrlgRoomStrc* pDrlgRoom); // 0x006667D0

struct D2RoomTileStrc
{
    void* pDrlgRoom;
    D2RoomTileStrc* pNext;
    int bEnabled;
    void* unk0x0C;
    void* pLvlWarpTxtRecord;
    void* unk0x14;
};

D2DrlgRoomStrc* __fastcall DUNGEON_GetRoomExFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061AAE0

static __forceinline unsigned int SEED_RollRandomNumberHighFirst(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumberHighFirst(pSeed) % nMax;
    }

    return SEED_RollRandomNumberHighFirst(pSeed) & (nMax - 1);
}

// 0x0066D820
D2TileLibraryEntryStrc* __fastcall DRLGROOMTILE_GetTileCache(D2DrlgRoomStrc* pDrlgRoom, int nType, unsigned int nPackedTileInformation)
{
    D2TileLibraryEntryStrc* ppTileEntries[40];

    const unsigned char nStyle = nPackedTileInformation ? (unsigned char)(nPackedTileInformation >> 20) & 0x3F : 0;
    const unsigned char nSequence = nPackedTileInformation ? (unsigned char)(nPackedTileInformation >> 8) : 0;

    const unsigned int nTiles = D2CMP_GetTiles(&pDrlgRoom->pTiles, nType, nStyle, nSequence, ppTileEntries, 40);
    if (!nTiles)
    {
        D2_ASSERT(D2CMP_GetTiles(&pDrlgRoom->pTiles, 10, 0, 0, ppTileEntries, 40), 0x73);
        return ppTileEntries[0];
    }

    int nTotalRarity = 0;
    for (unsigned int i = 0; i < nTiles; ++i)
    {
        D2_ASSERT(ppTileEntries[i], 0x7C);
        nTotalRarity += TILE_GetRarity(ppTileEntries[i]);
    }

    int nRand = SEED_RollLimitedRandomNumber(&pDrlgRoom->pSeed, nTotalRarity) + 1;
    int nIndex = 0;
    while (nTotalRarity && nTiles > 1 && nRand > 0)
    {
        nRand -= TILE_GetRarity(ppTileEntries[nIndex]);
        ++nIndex;
    }

    if (nIndex)
    {
        --nIndex;
    }

    return ppTileEntries[nIndex];
}

// build: symbol ?DRLGROOMTILE_InitializeTileDataFlags@@YAXPAUD2DrlgRoomStrc@@PAUD2DrlgTileDataStrc@@IHHH@Z 0x0066DB20
static void DRLGROOMTILE_InitializeTileDataFlags(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, unsigned int nTileFlags, int nType, int nX, int nY)
{
    D2C_PackedTileInformation nTileInfo;
    nTileInfo.nPackedValue = nTileFlags;

    if (pDrlgRoom && (nType == 9 || nType == 8))
    {
        DRLGROOMTILE_AddTilePresetUnits(pDrlgRoom, pTileData, nTileFlags, nX, nY, 0);
    }

    if (nType != 13)
    {
        pTileData->dwFlags |= ((int)((nTileFlags >> 18) & 3) + 1) << 14;
    }

    if (nType == 14)
    {
        pTileData->dwFlags |= 4;
    }
    else if (nType == 11 || nType == 10 || nType == 9 || nType == 8)
    {
        pTileData->dwFlags |= 2;
    }

    if (nTileInfo.bLayerAbove)
    {
        pTileData->dwFlags |= 1;
    }

    if (nTileInfo.bLinkage)
    {
        pTileData->dwFlags |= 0x102;
    }

    if (nTileInfo.bUnwalkable)
    {
        pTileData->dwFlags |= 0x40;
    }

    if (nTileInfo.bFillLOS)
    {
        pTileData->dwFlags |= 0x80;
    }

    if (nTileInfo.bEnclosed)
    {
        pTileData->dwFlags |= 4;
    }

    if (nTileInfo.bHidden)
    {
        pTileData->dwFlags |= 8;
    }
    else
    {
        pTileData->dwFlags &= ~8;
    }

    if (nTileInfo.bRevealHidden)
    {
        pTileData->dwFlags |= 0x20C;
    }

    if (nTileInfo.bObjectWall)
    {
        pTileData->dwFlags |= 0x800;
    }

    if (nTileInfo.bLOS)
    {
        pTileData->dwFlags |= 0x2000;
    }

    const unsigned int nFlags = D2CMP_10079_GetTileFlags(pTileData->pTile);
    if (nFlags & 1)
    {
        pTileData->dwFlags |= 4;
    }

    if (nFlags & 4)
    {
        pTileData->dwFlags |= 0x800;
    }
}

// 0x0066DC10
static void __stdcall sub_0066DC10(D2DrlgTileDataStrc* pTileData, D2DrlgRoomStrc* pDrlgRoom, int nX, int nY)
{
    pTileData->nPosX = nX - pDrlgRoom->nTileXPos;
    pTileData->nPosY = nY - pDrlgRoom->nTileYPos;

    nY += 1;
    DUNGEON_GameTileToClientCoords(&nX, &nY);

    nY += 40;
    pTileData->nWidth = nX;
    pTileData->nHeight = nY;
}

D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitWallTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry, int nTileType)
{
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->pTileGrid;
    D2DrlgTileDataStrc* pTileData = &pTileGrid->pTiles.pWallTiles[pTileGrid->nWalls];
    if (ppTileData)
    {
        pTileData->pNext = *ppTileData;
        *ppTileData = pTileData;
    }
    else
    {
        pTileData->pNext = 0;
    }

    ++pTileGrid->nWalls;

    sub_0066DC10(pTileData, pDrlgRoom, nX, nY);
    pTileData->pTile = pTileLibraryEntry;
    pTileData->nTileType = nTileType;
    pTileData->dwFlags = 0;
    pTileData->unk0x24 = 0;
    pTileData->nGreen = 0xFF;
    pTileData->nBlue = 0xFF;
    pTileData->nRed = 0xFF;

    DRLGROOMTILE_InitializeTileDataFlags(pDrlgRoom, pTileData, nPackedTileInformation, nTileType, nX, nY);

    if (nTileType == 3)
    {
        DRLGROOMTILE_InitializeTileDataFlags(pDrlgRoom, DRLGROOMTILE_InitWallTileData(pDrlgRoom, ppTileData, nX, nY, nPackedTileInformation, DRLGROOMTILE_GetTileCache(pDrlgRoom, 4, nPackedTileInformation), 4), nPackedTileInformation, 4, nX, nY);
    }

    return pTileData;
}

// 0x0066DDE0
void __fastcall DRLGROOMTILE_InitTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    pTileData->pTile = pTileLibraryEntry;
    pTileData->nTileType = 0;
    pTileData->dwFlags = 0;
    pTileData->unk0x24 = 0;
    pTileData->nGreen = 0xFF;
    pTileData->nBlue = 0xFF;
    pTileData->nRed = 0xFF;

    if (pDrlgRoom)
    {
        sub_0066DC10(pTileData, pDrlgRoom, nX, nY);
    }

    DRLGROOMTILE_InitializeTileDataFlags(pDrlgRoom, pTileData, nPackedTileInformation, 0, nX, nY);
}

// 0x0066DF40
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitShadowTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->pTileGrid;
    D2DrlgTileDataStrc* pTileData = &pTileGrid->pTiles.pRoofTiles[pTileGrid->nShadows];
    if (ppTileData)
    {
        pTileData->pNext = *ppTileData;
        *ppTileData = pTileData;
    }
    else
    {
        pTileData->pNext = 0;
    }

    ++pTileGrid->nShadows;

    sub_0066DC10(pTileData, pDrlgRoom, nX, nY);
    pTileData->pTile = pTileLibraryEntry;
    pTileData->nTileType = 13;
    pTileData->dwFlags = 0;
    pTileData->unk0x24 = 0;
    pTileData->nGreen = 0xFF;
    pTileData->nBlue = 0xFF;
    pTileData->nRed = 0xFF;

    DRLGROOMTILE_InitializeTileDataFlags(pDrlgRoom, pTileData, nPackedTileInformation, 13, nX, nY);

    return pTileData;
}

// 0x0066E090
void __fastcall sub_0066E090(Room* room)
{
    void* pool=room->level->drlg->pool;
    T0066E090* grid=room->grid;
    if(!grid->count)
    {
        if(grid->tiles) sub_0040B480(pool,grid->tiles,".\\DRLG\\RoomTile.cpp",0x257,0);
        grid->tiles=0;
        return;
    }
    if(grid->capacity>grid->count)
    {
        grid->tiles=(Tile*)sub_0040B4B0(pool,grid->tiles,grid->count*sizeof(Tile),".\\DRLG\\RoomTile.cpp",0x25F,0);
        int i;
        const int& nCount=grid->count;
        for(i=0;i<nCount-1;++i) grid->tiles[i].next=&grid->tiles[i+1];
        grid->tiles[i].next=0;
        grid->capacity=grid->count;
    }
}

// 0x0066E5E0
static D2DrlgTileLinkStrc* __stdcall sub_0066E5E0_NewTileLink(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom, int bFloor)
{
    D2DrlgTileLinkStrc* pTileLink = (D2DrlgTileLinkStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgTileLinkStrc), ".\\DRLG\\RoomTile.cpp", 891, 0);
    pTileLink->bFloor = bFloor;
    pTileLink->pMapTile = 0;
    pTileLink->pNext = pDrlgRoom->pTileGrid->pMapLinks;
    pDrlgRoom->pTileGrid->pMapLinks = pTileLink;
    return pTileLink;
}

void __fastcall sub_M105_Emit_0066E5E0(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom, int nTileType, int nX, int nY)
{
    D2DrlgTileLinkStrc* pCurLink;
    for (pCurLink = pDrlgRoom->pTileGrid->pMapLinks; pCurLink; pCurLink = pCurLink->pNext)
    {
        if ((pCurLink->bFloor && nTileType == 0) || (!pCurLink->bFloor && nTileType != 0))
            break;
    }
    if (!pCurLink)
        pCurLink = sub_0066E5E0_NewTileLink(pMemPool, pDrlgRoom, nTileType == 0);
    sub_M105_EmitSink_0066E5E0(pDrlgRoom, &pCurLink->pMapTile, nX, nY);
}

// 0x0066EDB0
void __fastcall DRLGROOMTILE_CountWallWarpTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileInfoGrid, D2DrlgGridStrc* pTileTypeGrid, int bKillEdgeX, int bKillEdgeY)
{
    const int nTileCountX = pDrlgRoom->pDrlgCoord.nWidth + (bKillEdgeX == 0);
    const int nTileCountY = pDrlgRoom->pDrlgCoord.nHeight + (bKillEdgeY == 0);
    D2DrlgRoomTilesStrc* pTiles = &pDrlgRoom->pTileGrid->pTiles;

    for (int nY = 0; nY < nTileCountY; ++nY)
    {
        for (int nX = 0; nX < nTileCountX; ++nX)
        {
            switch (DRLGGRID_GetGridEntry(pTileTypeGrid, nX, nY))
            {
            case 3:
                ++pTiles->nWalls;
                break;

            case 10:
            case 11:
                if (DRLGGRID_GetGridEntry(pTileInfoGrid, nX, nY) & 0x80000000)
                {
                    pTiles->nFloors += 6;
                }
                else
                {
                    ++pTiles->nWalls;
                }
                break;

            default:
                break;
            }
        }
    }
}

// 0x0066EE40
void __fastcall DRLGROOMTILE_InitRoomGrids(D2DrlgRoomStrc* pDrlgRoom)
{
    SEED_InitLowSeed(&pDrlgRoom->pSeed, pDrlgRoom->dwInitSeed);

    switch (pDrlgRoom->nType)
    {
    case 1:
        DRLGOUTPLACE_InitOutdoorRoomGrids(pDrlgRoom);
        break;

    case 2:
        DRLGPRESET_InitPresetRoomGrids(pDrlgRoom);
        break;
    }
}

// 0x0066F030
int __fastcall DRLGROOMTILE_GetNumberOfShadowsFromRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
        return 0;
    return DUNGEON_GetRoomExFromRoom(pRoom)->pTileGrid->nShadows;
}

// 0x0066F180
static void sub_0066F180_ResetRoomTiles(D2DrlgRoomStrc* pDrlgRoom)
{
    for (D2RoomTileStrc* pRoomTile = pDrlgRoom->pRoomTiles; pRoomTile; pRoomTile = pRoomTile->pNext)
    {
        pRoomTile->unk0x14 = 0;
        pRoomTile->unk0x0C = 0;
    }
}

void __fastcall sub_M107_Emit_0066F180(D2DrlgRoomStrc* pDrlgRoom, int bReset)
{
    if (bReset)
        sub_0066F180_ResetRoomTiles(pDrlgRoom);
}
