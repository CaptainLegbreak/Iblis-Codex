#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
struct D2PresetUnitStrc;

struct D2DrlgTileDataStrc;

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


struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgStrc
{
    char unk0x00[0x478];
    void* pMempool;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x1B4];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x18];
    int eLevelId;
};

struct D2LvlWarpTxt
{
    int dwLevelId;
    char unk0x04[0x18];
    int dwOffsetX;
    int dwOffsetY;
    int dwLitVersion;
    int dwTiles;
    char szDirection[4];
};

struct D2RoomTileStrc
{
    void* pUnused;
    D2RoomTileStrc* pNext;
    int unk0x08;
    D2DrlgTileDataStrc* pUnselectedTiles;
    D2LvlWarpTxt* pLvlWarpTxtRecord;
    D2DrlgTileDataStrc* pSelectedTiles;
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

struct D2DrlgTileLinkStrc
{
    int bFloor;
    D2DrlgTileDataStrc* pMapTile;
    D2DrlgTileLinkStrc* pNext;
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

struct D2DrlgRoomStrc
{
    char unk0x00[0x08];
    D2DrlgRoomStrc** ppRoomsNear;
    char unk0x0C[8];
    D2SeedStrc pSeed;
    char unk0x1C[12];
    unsigned int dwFlags;
    int nRoomsNear;
    D2ActiveRoomStrc* pRoom;
    D2DrlgCoordStrc pDrlgCoord;
    char unk0x44[8];
    D2RoomTileStrc* pRoomTiles;
    int unk0x50;
    D2DrlgTileGridStrc* ptDrlgTiles;
    D2DrlgLevelStrc* ptDrlgLevel;
};


struct D2UnkDrlgRoomTileStrc2
{
    int nTileStyle;
    int nTileSequence;
    int bIsRightWallWithDoor;
    int nUnitId;
    int nUnitType;
    int nX;
    int nY;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

extern const D2UnkDrlgRoomTileStrc2 gDrlgRoomTilePresetUnits_006EF188[];                                   // 0x006EF188
extern const D2CoordStrc gWarpTileOffsets_006EF554[4];                                                     // 0x006EF554

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall sub_004E6C50_ValidateMonsterId(int nMonsterId);                                              // 0x004E6C50
void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY);                                            // 0x00643310
void __fastcall sub_0064C860(D2ActiveRoomStrc* pRoom, D2DrlgTileDataStrc* pTileData, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0064C860
int __fastcall DRLGWARP_GetWarpDestinationFromArray(D2DrlgLevelStrc* pLevel, unsigned char nWarpId); // 0x0066AF30
D2LvlWarpTxt* __fastcall DRLGWARP_GetLvlWarpTxtRecordFromWarpIdAndDirection(D2DrlgLevelStrc* pLevel, unsigned char nWarpId, char nDirection); // 0x0066AF50
int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pCoords, int nX, int nY);                   // 0x0066B980
int __fastcall DRLGROOM_AreXYInsideCoordinatesOrOnBorder(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY);      // 0x0066B9D0
D2PresetUnitStrc* __fastcall DRLGROOM_AllocPresetUnit(D2DrlgRoomStrc* pDrlgRoom, void* pMemPool, int nUnitType, int nIndex, int nMode, int nX, int nY); // 0x0066BF30
D2TileLibraryEntryStrc* __fastcall DRLGROOMTILE_GetTileCache(D2DrlgRoomStrc* pDrlgRoom, int nType, unsigned int nPackedTileInformation); // 0x0066D820
void __fastcall DRLGROOMTILE_InitTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0066DDE0
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitFloorTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0066DEF0
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitShadowTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0066DF40
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                // 0x0067C570

D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitWallTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry, int nTileType); // 0x0066DC50
static void __stdcall DRLGROOMTILE_AddTilePresetUnits(D2DrlgTileDataStrc* pTileData, int nX, int nTileType, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation, int nY); // 0x0066D9E0
static int __stdcall DRLGROOMTILE_AddWarp(int nX, int nTileType, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation, int nY); // 0x0066E1C0
static void __stdcall DRLGROOMTILE_LoadWallWarpTiles(D2DrlgTileDataStrc* pTileData, unsigned int nPackedTileInformation, int nTileType, D2DrlgRoomStrc* pDrlgRoom); // 0x0066E260
static void __stdcall DRLGROOMTILE_LoadFloorWarpTiles(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, int nTileType, unsigned int nPackedTileInformation); // 0x0066E360
static void __stdcall DRLGROOMTILE_GetCreateLinkedTileData(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom, int nTileType, unsigned int nPackedTileInformation, int nX, int nY); // 0x0066E940

static __forceinline D2DrlgTileDataStrc* sub_B04_InitFloorTileDataInline(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->ptDrlgTiles;
    D2DrlgTileDataStrc* pTileData = &pTileGrid->pTiles.pFloorTiles[pTileGrid->nFloors];
    if (ppTileData)
    {
        pTileData->pNext = *ppTileData;
        *ppTileData = pTileData;
    }
    else
    {
        pTileData->pNext = 0;
    }

    ++pTileGrid->nFloors;

    DRLGROOMTILE_InitTileData(pDrlgRoom, pTileData, nX, nY, nPackedTileInformation, pTileLibraryEntry);
    return pTileData;
}

static void __stdcall DRLGROOMTILE_AddTilePresetUnits(D2DrlgTileDataStrc* pTileData, int nX, int nTileType, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation, int nY)
{
    int bIsRightWallWithDoor;
    if (pTileData)
    {
        if (pTileData->dwFlags & 0x20)
        {
            return;
        }

        bIsRightWallWithDoor = pTileData->nTileType == 9;
    }
    else
    {
        bIsRightWallWithDoor = nTileType == 9;
    }

    const int nIndex = sub_0066D960_FindTilePresetEntry(pDrlgRoom->ptDrlgLevel->eLevelId, nPackedTileInformation, bIsRightWallWithDoor);
    if (nIndex == -1)
    {
        return;
    }

    int nPosX = nX - pDrlgRoom->pDrlgCoord.nPosX;
    int nPosY = nY - pDrlgRoom->pDrlgCoord.nPosY;

    DUNGEON_GameTileToSubtileCoords(&nPosX, &nPosY);

    nPosX += gDrlgRoomTilePresetUnits_006EF188[nIndex].nX;
    nPosY += gDrlgRoomTilePresetUnits_006EF188[nIndex].nY;

    if (nPosX >= 0 && nPosY >= 0 && nPosX < 5 * pDrlgRoom->pDrlgCoord.nWidth && nPosY < 5 * pDrlgRoom->pDrlgCoord.nHeight)
    {
        int nUnitId = gDrlgRoomTilePresetUnits_006EF188[nIndex].nUnitId;
        const int nUnitType = gDrlgRoomTilePresetUnits_006EF188[nIndex].nUnitType;
        int nMode;

        switch (nUnitType)
        {
        case 1:
            nUnitId = sub_004E6C50_ValidateMonsterId(nUnitId);
            nMode = 1;
            DRLGROOM_AllocPresetUnit(pDrlgRoom, pDrlgRoom->ptDrlgLevel->pDrlg->pMempool, nUnitType, nUnitId, nMode, nPosX, nPosY);
            break;

        case 2:
            nMode = 0;
            if (nUnitId < 91 || nUnitId > 92 || SEED_RollLimitedRandomNumber(&pDrlgRoom->pSeed, 3))
            {
                DRLGROOM_AllocPresetUnit(pDrlgRoom, pDrlgRoom->ptDrlgLevel->pDrlg->pMempool, nUnitType, nUnitId, nMode, nPosX, nPosY);
            }
            break;

        default:
            nMode = 0;
            DRLGROOM_AllocPresetUnit(pDrlgRoom, pDrlgRoom->ptDrlgLevel->pDrlg->pMempool, nUnitType, nUnitId, nMode, nPosX, nPosY);
            break;
        }

        if (pTileData)
        {
            pTileData->dwFlags |= 0x20;
        }
    }
}

static void __stdcall DRLGROOMTILE_InitializeTileDataFlags(unsigned int nTileFlags, int nY, D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nType, int nX)
{
    if (pDrlgRoom && (nType == 9 || nType == 8))
    {
        DRLGROOMTILE_AddTilePresetUnits(pTileData, nX, 0, pDrlgRoom, nTileFlags, nY);
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

    if (nTileFlags & 0x80)
    {
        pTileData->dwFlags |= 1;
    }

    if (nTileFlags & 0x10000000)
    {
        pTileData->dwFlags |= 0x102;
    }

    if (nTileFlags & 0x20000)
    {
        pTileData->dwFlags |= 0x40;
    }

    if (nTileFlags & 0x10000)
    {
        pTileData->dwFlags |= 0x80;
    }

    if (nTileFlags & 8)
    {
        pTileData->dwFlags |= 4;
    }

    if (nTileFlags & 0x80000000)
    {
        pTileData->dwFlags |= 8;
    }
    else
    {
        pTileData->dwFlags &= ~8;
    }

    if (nTileFlags & 0x4000000)
    {
        pTileData->dwFlags |= 0x20C;
    }

    if (nTileFlags & 0x20000000)
    {
        pTileData->dwFlags |= 0x800;
    }

    if (nTileFlags & 4)
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

D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitWallTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry, int nTileType)
{
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->ptDrlgTiles;
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

    int nPosY = nY + 1;
    int nPosX = nX;
    pTileData->nPosX = nX - pDrlgRoom->pDrlgCoord.nPosX;
    pTileData->nPosY = nY - pDrlgRoom->pDrlgCoord.nPosY;
    DUNGEON_GameTileToClientCoords(&nPosX, &nPosY);
    pTileData->nWidth = nPosX;
    pTileData->nHeight = nPosY + 40;

    pTileData->pTile = pTileLibraryEntry;
    pTileData->nTileType = nTileType;
    pTileData->dwFlags = 0;
    pTileData->unk0x24 = 0;
    pTileData->nGreen = 0xFF;
    pTileData->nBlue = 0xFF;
    pTileData->nRed = 0xFF;

    DRLGROOMTILE_InitializeTileDataFlags(nPackedTileInformation, nY, pDrlgRoom, pTileData, nTileType, nX);

    if (nTileType == 3)
    {
        DRLGROOMTILE_InitializeTileDataFlags(nPackedTileInformation, nY, pDrlgRoom, DRLGROOMTILE_InitWallTileData(pDrlgRoom, ppTileData, nX, nY, nPackedTileInformation, DRLGROOMTILE_GetTileCache(pDrlgRoom, 4, nPackedTileInformation), 4), 4, nX);
    }

    return pTileData;
}

static void __stdcall DRLGROOMTILE_UpdateAndGetLvlWarpTxtRecord(int nTileType, D2RoomTileStrc* pWarpTile)
{
    D2_ASSERT(pWarpTile, 627);

    D2LvlWarpTxt* pLvlWarpTxtRecord = pWarpTile->pLvlWarpTxtRecord;
    D2_ASSERT(pLvlWarpTxtRecord, 628);

    if (pLvlWarpTxtRecord->szDirection[0] != 'b')
    {
        const char szDirection = nTileType == 11 ? 'r' : 'l';
        if (pLvlWarpTxtRecord->szDirection[0] != szDirection)
        {
            pWarpTile->pLvlWarpTxtRecord = DATATBLS_GetLvlWarpTxtRecordFromLevelIdAndDirection(pLvlWarpTxtRecord->dwLevelId, szDirection);
        }
    }
}

static int __stdcall DRLGROOMTILE_AddWarp(int nX, int nTileType, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation, int nY)
{
    int nPosX;
    int nPosY;
    D2LvlWarpTxt* pLvlWarpTxtRecord = DRLGWARP_GetLvlWarpTxtRecordFromWarpIdAndDirection(pDrlgRoom->ptDrlgLevel, (nPackedTileInformation >> 20) & 0x3F, nTileType == 11 ? 'r' : 'l');
    if (pLvlWarpTxtRecord)
    {
        nPosX = nX - pDrlgRoom->pDrlgCoord.nPosX;
        nPosY = nY - pDrlgRoom->pDrlgCoord.nPosY;

        if (nPosX != pDrlgRoom->pDrlgCoord.nWidth && nPosY != pDrlgRoom->pDrlgCoord.nHeight)
        {
            DUNGEON_GameTileToSubtileCoords(&nPosX, &nPosY);

            nPosX += pLvlWarpTxtRecord->dwOffsetX;
            nPosY += pLvlWarpTxtRecord->dwOffsetY;

            DRLGROOM_AllocPresetUnit(pDrlgRoom, pDrlgRoom->ptDrlgLevel->pDrlg->pMempool, 5, pLvlWarpTxtRecord->dwLevelId, 0, nPosX, nPosY);
            return 1;
        }
    }

    return 0;
}

static void __stdcall DRLGROOMTILE_LoadWallWarpTiles(D2DrlgTileDataStrc* pTileData, unsigned int nPackedTileInformation, int nTileType, D2DrlgRoomStrc* pDrlgRoom)
{
    const unsigned char nTileSequence = (unsigned char)(nPackedTileInformation >> 8);
    D2RoomTileStrc* pWarpTile = pDrlgRoom->pRoomTiles;
    const int nDestinationLevelId = DRLGWARP_GetWarpDestinationFromArray(pDrlgRoom->ptDrlgLevel, (nPackedTileInformation >> 20) & 0x3F);
    while (pWarpTile && pWarpTile->pLvlWarpTxtRecord->dwLevelId != nDestinationLevelId)
    {
        pWarpTile = pWarpTile->pNext;
    }

    D2_ASSERT(pWarpTile, 689);

    if (nTileSequence == 0 || nTileSequence == 4)
    {
        int nY = pDrlgRoom->pDrlgCoord.nPosY;
        nY += pTileData->nPosY;
        if (!DRLGROOMTILE_AddWarp(pTileData->nPosX + pDrlgRoom->pDrlgCoord.nPosX, nTileType, pDrlgRoom, nPackedTileInformation, nY))
        {
            return;
        }
    }

    DRLGROOMTILE_UpdateAndGetLvlWarpTxtRecord(nTileType, pWarpTile);

    pTileData->pNext = pWarpTile->pUnselectedTiles;
    pWarpTile->pUnselectedTiles = pTileData;

    D2LvlWarpTxt* pWarpDef = pWarpTile->pLvlWarpTxtRecord;
    D2_ASSERT(pWarpDef, 715);

    if (pWarpDef->dwLitVersion)
    {
        const unsigned int nLitPackedTileInformation = (pWarpDef->dwTiles << 8) | nPackedTileInformation;
        D2TileLibraryEntryStrc* pTileCache = DRLGROOMTILE_GetTileCache(pDrlgRoom, nTileType, nLitPackedTileInformation);
        D2DrlgTileDataStrc* pLitTileData = DRLGROOMTILE_InitWallTileData(pDrlgRoom, &pWarpTile->pSelectedTiles, pTileData->nPosX + pDrlgRoom->pDrlgCoord.nPosX, pDrlgRoom->pDrlgCoord.nPosY + pTileData->nPosY, nLitPackedTileInformation, pTileCache, nTileType);
        if (pLitTileData)
        {
            pLitTileData->dwFlags |= 8;
        }
    }
}

static void __stdcall DRLGROOMTILE_LoadFloorWarpTiles(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, int nTileType, unsigned int nPackedTileInformation)
{
    --nX;
    --nY;

    pDrlgRoom->dwFlags |= 0x800000;

    D2RoomTileStrc* pWarpTile = pDrlgRoom->pRoomTiles;
    const int nDestinationLevelId = DRLGWARP_GetWarpDestinationFromArray(pDrlgRoom->ptDrlgLevel, (nPackedTileInformation >> 20) & 0x3F);
    while (pWarpTile && pWarpTile->pLvlWarpTxtRecord->dwLevelId != nDestinationLevelId)
    {
        pWarpTile = pWarpTile->pNext;
    }

    if (pWarpTile)
    {
        DRLGROOMTILE_UpdateAndGetLvlWarpTxtRecord(nTileType, pWarpTile);

        if (pWarpTile->pLvlWarpTxtRecord->dwLitVersion)
        {
            const unsigned char nTileSequence = (unsigned char)(nPackedTileInformation >> 8);
            for (int i = 0; i < 4; ++i)
            {
                const unsigned int nDestinationPacked = (nTileSequence << 20) | ((i | 4) << 8);
                D2TileLibraryEntryStrc* pTileCache = DRLGROOMTILE_GetTileCache(pDrlgRoom, 0, nDestinationPacked);
                D2DrlgTileDataStrc* pDestTileData = sub_B04_InitFloorTileDataInline(pDrlgRoom, &pWarpTile->pSelectedTiles, gWarpTileOffsets_006EF554[i].nX + nX, gWarpTileOffsets_006EF554[i].nY + nY, nDestinationPacked, pTileCache);
                pDestTileData->dwFlags |= 8;
            }

            D2DrlgTileDataStrc* pFloorTileData = pDrlgRoom->ptDrlgTiles->pTiles.pFloorTiles;
            for (int i = 0; i < pDrlgRoom->ptDrlgTiles->nFloors; ++i, ++pFloorTileData)
            {
                if (sub_00604B90_GetTileStyle(pFloorTileData->pTile) == nTileSequence && (unsigned int)sub_00604C50_GetTileSequence(pFloorTileData->pTile) < 4)
                {
                    pFloorTileData->pNext = pWarpTile->pUnselectedTiles;
                    pWarpTile->pUnselectedTiles = pFloorTileData;
                }
            }
        }
    }
}

static D2DrlgTileDataStrc* __stdcall sub_0066E4C0_FindLinkedTileInRoom(D2DrlgRoomStrc* pNearRoom, int bFloor, int nX, int nY, unsigned int nPackedTileInformation)
{
    if (!pNearRoom->ptDrlgTiles)
    {
        return 0;
    }

    if (!DRLGROOM_AreXYInsideCoordinatesOrOnBorder(&pNearRoom->pDrlgCoord, nX, nY))
    {
        return 0;
    }

    for (D2DrlgTileLinkStrc* pTileLink = pNearRoom->ptDrlgTiles->pMapLinks; pTileLink; pTileLink = pTileLink->pNext)
    {
        D2DrlgTileDataStrc* pTileData = pTileLink->pMapTile;
        if (pTileLink->bFloor)
        {
            if (!bFloor)
            {
                continue;
            }
        }
        else if (bFloor)
        {
            continue;
        }

        {
            for (; pTileData; pTileData = pTileData->pNext)
            {
                if (pNearRoom->pDrlgCoord.nPosX + pTileData->nPosX == nX && pNearRoom->pDrlgCoord.nPosY + pTileData->nPosY == nY)
                {
                    if (pTileData->nTileType != 4 && (pTileData->nTileType == 13 || !(nPackedTileInformation & 0x8000000)))
                    {
                        if (!(pTileData->dwFlags & 0x1C000) || ((pTileData->dwFlags >> 14) & 7) - 1 == ((nPackedTileInformation >> 18) & 3))
                        {
                            return pTileData;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

static D2DrlgTileDataStrc* __stdcall DRLGROOMTILE_GetLinkedTileData(int bFloor, int nX, int nY, D2DrlgRoomStrc** ppDrlgRoom, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation)
{
    for (int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
    {
        if (pDrlgRoom->ppRoomsNear[i] != pDrlgRoom)
        {
            D2DrlgTileDataStrc* pTileData = sub_0066E4C0_FindLinkedTileInRoom(pDrlgRoom->ppRoomsNear[i], bFloor, nX, nY, nPackedTileInformation);
            if (pTileData)
            {
                *ppDrlgRoom = pDrlgRoom->ppRoomsNear[i];
                return pTileData;
            }
        }
    }

    *ppDrlgRoom = 0;
    return 0;
}

static D2DrlgTileDataStrc* __stdcall DRLGROOMTILE_AddLinkedTileData(void* pMemPool, unsigned int nPackedTileInformation, int nX, int nY, D2DrlgRoomStrc* pDrlgRoom, int nTileType)
{
    if ((nTileType == 11 || nTileType == 10) && !DRLGROOM_AreXYInsideCoordinates(&pDrlgRoom->pDrlgCoord, nX, nY))
    {
        return 0;
    }

    const int bFloor = nTileType == 0;
    D2DrlgTileLinkStrc* pTileLink;
    for (pTileLink = pDrlgRoom->ptDrlgTiles->pMapLinks; pTileLink; pTileLink = pTileLink->pNext)
    {
        if ((pTileLink->bFloor && bFloor) || (!pTileLink->bFloor && !bFloor))
        {
            break;
        }
    }

    if (!pTileLink)
    {
        D2DrlgTileLinkStrc* pNewTileLink = (D2DrlgTileLinkStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgTileLinkStrc), ".\\DRLG\\RoomTile.cpp", 891, 0);
        pNewTileLink->bFloor = bFloor;
        pNewTileLink->pMapTile = 0;
        pNewTileLink->pNext = pDrlgRoom->ptDrlgTiles->pMapLinks;
        pDrlgRoom->ptDrlgTiles->pMapLinks = pNewTileLink;
        pTileLink = pNewTileLink;
    }

    D2TileLibraryEntryStrc* pTileCache = DRLGROOMTILE_GetTileCache(pDrlgRoom, nTileType, nPackedTileInformation);
    D2DrlgTileDataStrc* pTileData;
    if (nTileType == 0)
    {
        pTileData = DRLGROOMTILE_InitFloorTileData(pDrlgRoom, &pTileLink->pMapTile, nX, nY, nPackedTileInformation, pTileCache);
    }
    else if (nTileType == 13)
    {
        pTileData = DRLGROOMTILE_InitShadowTileData(pDrlgRoom, &pTileLink->pMapTile, nX, nY, nPackedTileInformation, pTileCache);
    }
    else
    {
        DRLGROOMTILE_InitWallTileData(pDrlgRoom, &pTileLink->pMapTile, nX, nY, nPackedTileInformation, pTileCache, nTileType);
        pTileData = pTileLink->pMapTile;
        if (nTileType == 11 || nTileType == 10)
        {
            DRLGROOMTILE_LoadWallWarpTiles(pTileData, nPackedTileInformation, nTileType, pDrlgRoom);
        }
    }

    return pTileData;
}

static void __stdcall DRLGROOMTILE_LinkedTileDataManager(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom2, int nTileType, unsigned int nPackedTileInformation, int nX, int nY, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgTileDataStrc* pTileData)
{
    const int nRemapIndex = gnWallRemapIndices_006EF620[nTileType];

    if (pTileData->dwFlags & 1)
    {
        if (pTileData->nTileType == 9 || pTileData->nTileType == 8)
        {
            DRLGROOMTILE_InitializeTileDataFlags(nPackedTileInformation, nY, pDrlgRoom1, pTileData, pTileData->nTileType, nX);
        }

        return;
    }

    if (!(nPackedTileInformation & 0x80))
    {
        int bRemap = 0;
        if (nTileType != 9 && nTileType != 8)
        {
            if ((pTileData->nTileType == 9 || pTileData->nTileType == 8) && (nX - pDrlgRoom2->pDrlgCoord.nPosX == 0 || nY - pDrlgRoom2->pDrlgCoord.nPosY == 0))
            {
                return;
            }

            bRemap = 1;
        }

        if (bRemap || nX - pDrlgRoom1->pDrlgCoord.nPosX != 0 && nY - pDrlgRoom1->pDrlgCoord.nPosY != 0)
        {
            if (nRemapIndex < 0 || pTileData->nTileType > 7)
            {
                if (nRemapIndex != -1)
                {
                    return;
                }
            }
            else
            {
                nTileType = gnWallTileTypeRemap_006EF578[nRemapIndex][pTileData->nTileType - 1];
            }
        }
    }

    if (pTileData->nTileType == 3)
    {
        if (nTileType != 3)
        {
            pTileData->pNext->dwFlags |= 8;
            sub_0064C860(pDrlgRoom2->pRoom, pTileData->pNext, 0);
        }
    }
    else if (nTileType == 3)
    {
        pTileData->dwFlags |= 0xC008;
        sub_0064C860(pDrlgRoom2->pRoom, pTileData, 0);
        DRLGROOMTILE_AddLinkedTileData(pMemPool, nPackedTileInformation, nX, nY, pDrlgRoom1, 3);
    }

    const int bBlankFloor = pTileData->nTileType == 0 && sub_00604B90_GetTileStyle(pTileData->pTile) == 30 && sub_00604C50_GetTileSequence(pTileData->pTile) == 0;
    if (nTileType != pTileData->nTileType || bBlankFloor)
    {
        D2TileLibraryEntryStrc* pTileCache = DRLGROOMTILE_GetTileCache(pDrlgRoom2, nTileType, nPackedTileInformation);
        pTileData->nTileType = nTileType;

        if (pTileCache != pTileData->pTile && pDrlgRoom2->pRoom)
        {
            sub_0064C860(pDrlgRoom2->pRoom, pTileData, pTileCache);
        }

        pTileData->pTile = pTileCache;
    }

    DRLGROOMTILE_InitializeTileDataFlags(nPackedTileInformation, nY, pDrlgRoom1, pTileData, pTileData->nTileType, nX);
}

static void __stdcall DRLGROOMTILE_GetCreateLinkedTileData(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom, int nTileType, unsigned int nPackedTileInformation, int nX, int nY)
{
    D2DrlgRoomStrc* pLinkedRoom = 0;
    D2DrlgTileDataStrc* pLinkedTileData = DRLGROOMTILE_GetLinkedTileData(nTileType == 0, nX, nY, &pLinkedRoom, pDrlgRoom, nPackedTileInformation);
    if (pLinkedTileData)
    {
        DRLGROOMTILE_LinkedTileDataManager(pMemPool, pLinkedRoom, nTileType, nPackedTileInformation, nX, nY, pDrlgRoom, pLinkedTileData);
    }
    else
    {
        DRLGROOMTILE_AddLinkedTileData(pMemPool, nPackedTileInformation, nX, nY, pDrlgRoom, nTileType);
    }
}

// 0x0066E9B0
static void __stdcall sub_0066E9B0_LoadInitRoomTile(void* pMemPool, int nX, int nY, int bFillBlanks, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation, int nTileType)
{
    const unsigned char nTileStyle = (unsigned char)((nPackedTileInformation >> 20) & 0x3F);
    const unsigned char nTileSequence = (unsigned char)(nPackedTileInformation >> 8);

    if ((nTileType == 11 || nTileType == 10) && nTileStyle >= 8)
    {
        return;
    }

    if (nTileType == 0 && nTileStyle == 30 && (nTileSequence == 0 || nTileSequence == 1))
    {
        nPackedTileInformation |= 0x80000000;
    }

    const unsigned int bHidden = nPackedTileInformation & 0x80000000;
    if (bHidden)
    {
        switch (nTileType)
        {
        case 10:
        case 11:
            if (nTileStyle < 8)
            {
                DRLGROOMTILE_AddWarp(nX, nTileType, pDrlgRoom, nPackedTileInformation, nY);
                DRLGROOMTILE_LoadFloorWarpTiles(pDrlgRoom, nX, nY, nTileType, nPackedTileInformation);
            }
            return;

        case 8:
        case 9:
            switch (pDrlgRoom->ptDrlgLevel->eLevelId)
            {
            case 111:
            case 112:
            case 117:
                break;

            default:
                DRLGROOMTILE_AddTilePresetUnits(0, nX, nTileType, pDrlgRoom, nPackedTileInformation, nY);
                return;
            }
            break;

        default:
            break;
        }
    }

    if (nPackedTileInformation & 4)
    {
        if (nPackedTileInformation & 2)
        {
            if (nTileStyle == 30 && (nTileSequence == 0 || nTileSequence == 1))
            {
                nPackedTileInformation &= ~0x80;
            }

            DRLGROOMTILE_GetCreateLinkedTileData(pMemPool, pDrlgRoom, 0, nPackedTileInformation, nX, nY);
            return;
        }

        if (nPackedTileInformation & 1)
        {
            DRLGROOMTILE_GetCreateLinkedTileData(pMemPool, pDrlgRoom, nTileType, nPackedTileInformation, nX, nY);
            return;
        }

        if ((nPackedTileInformation & 0x8000000) && !bHidden)
        {
            DRLGROOMTILE_GetCreateLinkedTileData(pMemPool, pDrlgRoom, 13, nPackedTileInformation, nX, nY);
            return;
        }
    }

    if (nPackedTileInformation & 2)
    {
        sub_B04_InitFloorTileDataInline(pDrlgRoom, 0, nX, nY, nPackedTileInformation, DRLGROOMTILE_GetTileCache(pDrlgRoom, 0, nPackedTileInformation));
    }
    else if (bFillBlanks && DRLGROOM_AreXYInsideCoordinates(&pDrlgRoom->pDrlgCoord, nX, nY))
    {
        D2C_PackedTileInformation nBlankTileInformation;
        nBlankTileInformation.nPackedValue = (nPackedTileInformation & ~0x80) | 0x80000000;

        D2TileLibraryEntryStrc* pTileCache;
        if (pDrlgRoom->ptDrlgLevel->eLevelId != 74)
        {
            pTileCache = DRLGROOMTILE_GetTileCache(pDrlgRoom, 0, 0x1E00000);
        }
        else
        {
            pTileCache = DRLGROOMTILE_GetTileCache(pDrlgRoom, 0, 0x1E00100);
        }

        sub_B04_InitFloorTileDataInline(pDrlgRoom, 0, nX, nY, nBlankTileInformation.nPackedValue, pTileCache);
    }

    if (nPackedTileInformation & 1)
    {
        D2TileLibraryEntryStrc* pWallTileCache = DRLGROOMTILE_GetTileCache(pDrlgRoom, nTileType, nPackedTileInformation);
        D2DrlgTileDataStrc* pWallTileData = DRLGROOMTILE_InitWallTileData(pDrlgRoom, 0, nX, nY, nPackedTileInformation, pWallTileCache, nTileType);
        if ((nTileType == 11 || nTileType == 10) && pDrlgRoom->ptDrlgLevel->eLevelId != 133)
        {
            DRLGROOMTILE_LoadWallWarpTiles(pWallTileData, nPackedTileInformation, nTileType, pDrlgRoom);
        }
    }

    if (nPackedTileInformation & 0x8000000)
    {
        DRLGROOMTILE_InitShadowTileData(pDrlgRoom, 0, nX, nY, nPackedTileInformation, DRLGROOMTILE_GetTileCache(pDrlgRoom, 13, nPackedTileInformation));
    }
}

void __fastcall DRLGROOMTILE_LoadInitRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int bCheckCoordinatesValidity, int bKillEdgeX, int bKillEdgeY)
{
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;

    const int nTileCountX = pDrlgRoom->pDrlgCoord.nWidth + (bKillEdgeX == 0);
    const int nTileCountY = pDrlgRoom->pDrlgCoord.nHeight + (bKillEdgeY == 0);

    const int nRoomX = pDrlgRoom->pDrlgCoord.nPosX;
    const int nRoomY = pDrlgRoom->pDrlgCoord.nPosY;

    for (int nTileOffsetY = 0; nTileOffsetY < nTileCountY; ++nTileOffsetY)
    {
        for (int nTileOffsetX = 0; nTileOffsetX < nTileCountX; ++nTileOffsetX)
        {
            const unsigned int nPackedTileInformation = DRLGGRID_GetGridEntry(pGrid, nTileOffsetX, nTileOffsetY);
            const int nTileType = pTileTypeGrid ? DRLGGRID_GetGridEntry(pTileTypeGrid, nTileOffsetX, nTileOffsetY) : 0;
            sub_0066E9B0_LoadInitRoomTile(pMemPool, nRoomX + nTileOffsetX, nRoomY + nTileOffsetY, bCheckCoordinatesValidity, pDrlgRoom, nPackedTileInformation, nTileType);
        }
    }
}
