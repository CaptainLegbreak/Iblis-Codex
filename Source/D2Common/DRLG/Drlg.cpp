#include "D2Common.h"
#include "D2Structs.h"
#include "D2DrlgTiles.h"

#define ACT_I 0
#define ACT_II 1
#define MAX_PATH 260
#define DRLGROOMFLAG_0x40000 0x40000
struct Level;
struct Room;
struct D2DrlgOutdoorInfoStrc;
struct D2DrlgActStrc;
struct D2DrlgCoordStrc;
struct D2DrlgStrc;
struct Node;
struct T00642010;
struct Dungeon;
struct D2DrlgWarpStrc;
struct D2LevelDefBin;
struct D2DrlgOrthStrc;
struct D2DrlgTableEntryStrc;
struct D2DrlgEntryTableStrc;
union D2SeedStrc;
struct D2DrlgCoordsStrc;
struct D2DrlgTileDataListStrc;
struct D2RoomTileGridStrc;
struct D2DrlgVertexStrc;
struct D2UnkDrlgRoomTileStrc;
struct D2UnkDrlgRoomTileStrc2;

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x010];
    D2DrlgRoomStrc* ptRoomFirst;
    D2DrlgOutdoorInfoStrc* pOutdoors;
    unsigned char unk_18[0x4];
    union
    {
        struct
        {
            D2DrlgCoordStrc pLevelCoords;
        };
        struct
        {
            int nPosX;
            int nPosY;
            int nWidth;
            int nHeight;
        };
    };
    char unk0x2C[0x180];
    D2DrlgLevelStrc* pNextLevel;
    char unk0x1B0[0x1B4 - 0x1B0];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x1D0 - 0x1B8];
    int eLevelId;
    char unk0x1D4[0x1E0 - 0x1D4];
    int nRoom_Center_Warp_X[4];
};

struct D2DrlgStrc
{
    char unk0x00[0x0C];
    D2TileLibraryHeaderStrc* pTiles[32];
    unsigned int dwFlags;
    D2DrlgWarpStrc* pWarp;
    int nStaffTombLevel;
    unsigned char unk_98[0x3B8];
    unsigned char nDifficulty;
    unsigned char unk_451[0x1B];
    D2DrlgActStrc* pAct;
    unsigned char unk_470[0x8];
    void* pMempool;
    D2DrlgLevelStrc* pLevel;
    unsigned char nAct;
    unsigned char unk_481[0x3];
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDst, const char* szFormat, ...); // 0x006CC468
int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pCoord, int nX, int nY); // 0x0066B980

struct Room
{
    char pad_0[36];
    Room* next;
    char pad_28[56];
    unsigned flags;
};

struct Node
{
    char pad_0[12];
    Node* next;
};

struct T00642010
{
    char pad_0[68];
    T00642010* next;
};

struct Level
{
    int kind;
    char pad_4[4];
    int f_8;
    int activeCount;
    Room* rooms;
    char pad_14[24];
    char regionA[384];
    Level* next;
    void* mapData;
    char pad_1B4[8];
    void* allocation;
    char pad_1C0[12];
    Node* nodes;
    char pad_1D0[4];
    int inactiveTicks;
    int state;
    char pad_1DC[4];
    char regionB[76];
    unsigned* savedFlags;
};

struct Dungeon
{
    char pad_0[144];
    T00642010* aux;
    char pad_94[996];
    void* pool;
    Level* levels;
};

extern "C" void* __fastcall sub_0040B430_Allocate(void*, unsigned, const char*, int, int); // 0x0040B430
extern "C" int __fastcall sub_0040B480_Free(void*, void*, const char*, int, int); // 0x0040B480
extern "C" void __fastcall sub_0066C100_FreeRoom(Room*); // 0x0066C100
extern "C" void __fastcall sub_006683D0_FreeMap(void*, void*); // 0x006683D0
extern "C" void __fastcall sub_006754C0_ClearType3(Level*, int); // 0x006754C0
extern "C" void __fastcall sub_006674D0_ClearType2(Level*, int); // 0x006674D0
extern "C" void __fastcall sub_00673FE0_ClearType1(Level*, int); // 0x00673FE0
extern "C" int __stdcall sub_00643060_CanFree(Level*); // 0x00643060

typedef unsigned int size_t;

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2DrlgWarpStrc
{
    int nLevel;
    int nVis[8];
    int nWarp[8];
    D2DrlgWarpStrc* pNext;
};



struct D2DrlgRoomStrc
{
    char unk0x00[0x14];
    D2SeedStrc pSeed;
    unsigned char unk_1C[0x8];
    D2DrlgRoomStrc* pDrlgRoomNext;
    unsigned int dwFlags;
    int unk0x2C;
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
            int nTileWidth;
            int nTileHeight;
        };
    };
    char unk0x44[0x10];
    D2RoomTileGridStrc* ptDrlgTiles;
    D2DrlgLevelStrc* ptDrlgLevel;
    unsigned char unk_5C[0x4];
    unsigned int dwOtherFlags;
};

struct D2DrlgOrthStrc
{
    D2DrlgLevelStrc* pLevel;
    int nDirection;
    char unk0x08[0x14 - 0x08];
    D2DrlgOrthStrc* pNext;
};

struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int unk0x10;
};

struct D2DrlgOutdoorInfoStrc
{
    unsigned int dwFlags;
    D2DrlgGridStrc pGrid[4];
    unsigned char unk_54[0x8];
    int nGridWidth;
    int nGridHeight;
    D2DrlgVertexStrc* pVertex;
    unsigned char unk_68[0x1FC];
    D2DrlgOrthStrc* pRoomData;
};

struct D2DrlgTableEntryStrc
{
    char unk0x00[0x38];
};

struct D2DrlgEntryTableStrc
{
    char unk0x0000[0x404];
    D2DrlgTableEntryStrc pEntries[200];
    int nEntries;
};

extern const int gnTileTypeMappingTable_006EEF20[]; // 0x006EEF20
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId); // 0x0061E470
D2DrlgLevelStrc* __fastcall DRLG_AllocLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642AE0
void __fastcall sub_00642F70_AddLevelActivity(D2DrlgLevelStrc* pLevel, int nDelta); // 0x00642F70
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0
int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags); // 0x00674730

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

struct D2DrlgTileDataListStrc
{
    void* pWallTiles;
    int nWalls;
    void* pFloorTiles;
    int nFloors;
};

struct D2RoomTileGridStrc
{
    char unk0x00[0x14];
    D2DrlgTileDataListStrc pTiles;
};

D2ActiveRoomStrc* __fastcall DUNGEON_AllocRoom(D2DrlgActStrc* pAct, D2DrlgRoomStrc* pDrlgRoom, D2DrlgCoordsStrc* pDrlgCoords, D2DrlgTileDataListStrc* pRoomTiles, int nLowSeed, int nFlags); // 0x00619890

struct D2DrlgVertexStrc
{
    int nPosX;
    int nPosY;
    unsigned char nDirection;
    unsigned char pad0x09[3];
    int dwFlags;
    D2DrlgVertexStrc* pNext;
};

int __fastcall DRLGOUTDOORS_GetOutLinkVisFlag(D2DrlgLevelStrc* pLevel, D2DrlgVertexStrc* pDrlgVertex); // 0x00674040
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY); // 0x0067C570
void __fastcall sub_0067C760(D2DrlgGridStrc* pDrlgGrid, D2DrlgVertexStrc* pDrlgVertex, int nFlag, int nOperation, int bAlterNextVertex); // 0x0067C760

struct D2UnkDrlgRoomTileStrc
{
    int nLevelId;
    int nArrayStartId;
    int nArrayEndId;
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

extern const D2UnkDrlgRoomTileStrc gDrlgRoomTileLevelRanges_006EEFC8[37]; // 0x006EEFC8
extern const D2UnkDrlgRoomTileStrc2 gDrlgRoomTilePresetUnits_006EF188[]; // 0x006EF188
static __inline D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg,int id); // 0x00642BB0

// 0x00641F60
void __fastcall sub_00641F60_LoadTownTiles(D2DrlgStrc* pDrlg)
{
    char szPath[MAX_PATH] = { 0 };
    switch (pDrlg->nAct)
    {
    case ACT_I:
        wsprintfA(szPath, "%s\\Tiles\\Act1\\Town\\Floor.dt1", szDataGlobal_006D4118);
        break;

    case ACT_II:
        wsprintfA(szPath, "%s\\Tiles\\Act2\\Town\\Ground.dt1", szDataGlobal_006D4118);
        break;

    case ACT_III:
        wsprintfA(szPath, "%s\\Tiles\\ACT3\\Kurast\\sets.dt1", szDataGlobal_006D4118);
        break;

    default:
        return;
    }

    TileLibraryAddProject(pDrlg->pTiles, szPath);
}

// 0x006427A0
int __fastcall sub_006427A0_GetLevelIdFromCoordinates(D2DrlgStrc* pDrlg, int nX, int nY)
{
    for (D2DrlgLevelStrc* pLevel = pDrlg->pLevel; pLevel; pLevel = pLevel->pNextLevel)
    {
        if (DRLGROOM_AreXYInsideCoordinates(&pLevel->pLevelCoords, nX, nY))
        {
            return pLevel->eLevelId;
        }
    }

    return 0;
}

// 0x00642010
static __declspec(noinline) void __stdcall sub_00642010_ClearLevel(void* pool, int keep, Level* level)
{
    if (keep)
    {
        if (!level->savedFlags)
        {
            if (level->f_8)
                level->savedFlags = (unsigned*)sub_0040B430_Allocate(pool, 4 * level->f_8, ".\\DRLG\\Drlg.cpp", 124, 0);
            else
                level->f_8 = 0;
            memset(level->savedFlags, 0, 4 * level->f_8);
        }
    }
    else if (level->savedFlags)
    {
        sub_0040B480_Free(pool, level->savedFlags, ".\\DRLG\\Drlg.cpp", 132, 0);
        level->savedFlags = 0;
    }
    Room* room = level->rooms;
    if (room)
    {
        int index = 0;
        do
        {
            Room* current = room;
            room = room->next;
            if (level->savedFlags)
                level->savedFlags[index++] = current->flags & 1;
            sub_0066C100_FreeRoom(current);
        } while (room);
        level->rooms = 0;
        level->f_8 = 0;
    }
    if (level->mapData)
    {
        sub_006683D0_FreeMap(pool, level->mapData);
        level->mapData = 0;
    }
    switch (level->kind)
    {
    case 1: sub_00673FE0_ClearType1(level, keep); break;
    case 2: sub_006674D0_ClearType2(level, keep); break;
    case 3: sub_006754C0_ClearType3(level, keep); break;
    }
    memset(level->regionA, 0, 384);
    level->state = 0;
    memset(level->regionB, 0, 76);
    if (!keep && level->allocation)
    {
        sub_0040B480_Free(pool, level->allocation, ".\\DRLG\\Drlg.cpp", 183, 0);
        level->allocation = 0;
    }
    Node* node = level->nodes;
    if (node)
    {
        do
        {
            Node* current = node;
            node = node->next;
            sub_0040B480_Free(pool, current, ".\\DRLG\\Drlg.cpp", 197, 0);
        } while (node);
        level->nodes = 0;
    }
}

// 0x00642190
void __fastcall sub_00642190_FreeDungeon(Dungeon* dungeon)
{
    Level* level = dungeon->levels;
    if (level)
    {
        do
        {
            Level* current = level;
            level = level->next;
            sub_00642010_ClearLevel(dungeon->pool, 0, current);
            sub_0040B480_Free(dungeon->pool, current, ".\\DRLG\\Drlg.cpp", 221, 0);
        } while (level);
        dungeon->levels = 0;
    }
    T00642010* aux = dungeon->aux;
    if (aux)
    {
        do
        {
            T00642010* current = aux;
            aux = aux->next;
            sub_0040B480_Free(dungeon->pool, current, ".\\DRLG\\Drlg.cpp", 236, 0);
        } while (aux);
        dungeon->aux = 0;
    }
    sub_0040B480_Free(dungeon->pool, dungeon, ".\\DRLG\\Drlg.cpp", 242, 0);
}

// 0x00643200
void __fastcall sub_00643200_UpdateInactive(Dungeon* dungeon)
{
    Level* level = dungeon->levels;
    void* pool = dungeon->pool;
    while (level)
    {
        if (!level->activeCount && level->rooms)
        {
            if (level->inactiveTicks)
                --level->inactiveTicks;
            else if (sub_00643060_CanFree(level))
                sub_00642010_ClearLevel(pool, 1, level);
            else
                level->inactiveTicks = 10;
        }
        level = level->next;
    }
}

inline D2DrlgLevelStrc* DRLG_InlineGetLevel(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgLevelStrc* pLevel = pDrlg->pLevel; pLevel; pLevel = pLevel->pNextLevel)
    {
        if (pLevel->eLevelId == nLevelId)
        {
            return pLevel;
        }
    }

    return DRLG_AllocLevel(pDrlg, nLevelId);
}

// 0x00642230
int __fastcall DRLG_GetHoradricStaffTombLevelId(D2DrlgStrc* pDrlg)
{
    if (pDrlg)
    {
        return pDrlg->nStaffTombLevel;
    }

    return 0;
}

// 0x00642380
int* __fastcall DRLG_GetRoomCenterX_RoomWarpXFromRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->ptDrlgLevel->nRoom_Center_Warp_X;
}

// 0x006426A0
int __fastcall DRLG_IsTownLevel(int nLevelId)
{
    switch (nLevelId)
    {
    case 1:
    case 40:
    case 75:
    case 103:
    case 109:
        return 1;

    default:
        return 0;
    }
}

// 0x00642860
D2DrlgWarpStrc* __fastcall DRLG_GetDrlgWarpFromLevelId(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgWarpStrc* i = pDrlg->pWarp; i; i = i->pNext)
    {
        if (i->nLevel == nLevelId)
        {
            return i;
        }
    }

    D2LevelDefBin* pLevelDefBin = DATATBLS_GetLevelDefRecord(nLevelId);
    D2DrlgWarpStrc* pDrlgWarp = (D2DrlgWarpStrc*)sub_0040B430(pDrlg->pMempool, sizeof(D2DrlgWarpStrc), ".\\DRLG\\Drlg.cpp", 0x3E0, 0);
    pDrlgWarp->nLevel = nLevelId;

    for (int i = 0; i < 8; ++i)
    {
        pDrlgWarp->nVis[i] = pLevelDefBin->dwVis[i];
        pDrlgWarp->nWarp[i] = pLevelDefBin->dwWarp[i];
    }

    pDrlgWarp->pNext = pDrlg->pWarp;
    pDrlg->pWarp = pDrlgWarp;

    return pDrlgWarp;
}

// 0x00642A00
int __fastcall DRLG_IsOnClient(D2DrlgStrc* pDrlg)
{
    D2_ASSERT(pDrlg, 0x42E);

    return pDrlg->dwFlags & 1;
}

// 0x00642BE0
int __fastcall DRLG_GetNumberOfPopulatedRoomsInLevel(D2DrlgStrc* pDrlg, int nLevelId)
{
    int nCounter = 0;
    D2DrlgLevelStrc* pLevel = DRLG_InlineGetLevel(pDrlg, nLevelId);

    for (D2DrlgRoomStrc* i = pLevel->ptRoomFirst; i; i = i->pDrlgRoomNext)
    {
        if (!(i->dwFlags & 0x800000))
        {
            ++nCounter;
        }
    }

    return nCounter;
}

// 0x00643020
void __fastcall sub_6FD745C0(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2)
{
    D2DrlgLevelStrc* pLevel1 = pDrlgRoom1 ? pDrlgRoom1->ptDrlgLevel : 0;
    D2DrlgLevelStrc* pLevel2 = pDrlgRoom2 ? pDrlgRoom2->ptDrlgLevel : 0;

    if (pLevel1 != pLevel2)
    {
        if (pLevel1)
        {
            sub_00642F70_AddLevelActivity(pLevel1, -1);
        }

        if (pLevel2)
        {
            sub_00642F70_AddLevelActivity(pLevel2, 1);
        }
    }
}

// 0x0066D7F0
int __fastcall DRLGPRESET_MapTileType(int nId)
{
    return gnTileTypeMappingTable_006EEF20[nId];
}

// 0x00675320
void __fastcall DRLGOUTDOORS_AllocOutdoorInfo(D2DrlgLevelStrc* pLevel)
{
    pLevel->pOutdoors = (D2DrlgOutdoorInfoStrc*)sub_0040B430(pLevel->pDrlg->pMempool, 0x268, ".\\DRLG\\Outdoors.cpp", 0x34C, 0);
    memset(pLevel->pOutdoors, 0, 0x268);
}

// 0x0067B1C0
D2DrlgTableEntryStrc* __fastcall sub_0067B1C0_AllocTableEntry(D2DrlgEntryTableStrc* pTable)
{
    if (pTable->nEntries == 200)
    {
        return 0;
    }

    D2DrlgTableEntryStrc* pEntry = &pTable->pEntries[pTable->nEntries++];
    memset(pEntry, 0, sizeof(D2DrlgTableEntryStrc));
    return pEntry;
}

// 0x0067F560
void __fastcall DRLGOUTDESR_PlaceDesertTransitionToTown(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOrthStrc* pTownRoomData = pLevel->pOutdoors->pRoomData;

    while (pTownRoomData && pTownRoomData->pLevel->eLevelId != 40)
    {
        pTownRoomData = pTownRoomData->pNext;
    }

    if (pTownRoomData)
    {
        if (pTownRoomData->nDirection == 3)
        {
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, pLevel->pOutdoors->nGridHeight - 1, 0x16B, -1, 0);
        }
        else
        {
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, pLevel->pOutdoors->nGridWidth - 1, 0, 0x16A, -1, 0);
        }
    }
}

// 0x0067F670
void __fastcall DRLGOUTDESR_AddExits(D2DrlgLevelStrc* pLevel)
{
    int nLevelPrestId = 0;

    switch (pLevel->eLevelId)
    {
    case 41:
    case 42:
        nLevelPrestId = 0x184;
        break;

    case 43:
        nLevelPrestId = 0x186;
        break;

    case 44:
        nLevelPrestId = 0x19C;
        break;

    case 45:
        nLevelPrestId = 0x185;
        break;
    }

    D2_ASSERT(nLevelPrestId && DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nLevelPrestId, -1, 0, 15), 0xAA);
}

#include "gen/data/Source/D2Common/DRLG/Drlg.inc"

// 0x00642240
int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2)
{
    if (pDrlgCoord1->nPosX > pDrlgCoord2->nPosX)
    {
        if (pDrlgCoord1->nPosX == pDrlgCoord2->nPosX + pDrlgCoord2->nWidth)
            return 0;
    }
    else
    {
        if (pDrlgCoord2->nPosX == pDrlgCoord1->nPosX + pDrlgCoord1->nWidth)
            return 2;
    }

    if (pDrlgCoord1->nPosY > pDrlgCoord2->nPosY)
    {
        if (pDrlgCoord1->nPosY == pDrlgCoord2->nPosY + pDrlgCoord2->nHeight)
            return 1;
    }
    else
    {
        if (pDrlgCoord2->nPosY == pDrlgCoord1->nPosY + pDrlgCoord1->nHeight)
            return 3;
    }

    return -1;
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x006422A0
void __fastcall DRLG_CreateRoomForRoomEx(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgCoordsStrc tDrlgCoords = { 0 };

    tDrlgCoords.nTileXPos = pDrlgRoom->nTileXPos;
    tDrlgCoords.nTileYPos = pDrlgRoom->nTileYPos;
    tDrlgCoords.nTileWidth = pDrlgRoom->nTileWidth;
    tDrlgCoords.nTileHeight = pDrlgRoom->nTileHeight;

    tDrlgCoords.nSubtileX = pDrlgRoom->nTileXPos;
    tDrlgCoords.nSubtileY = pDrlgRoom->nTileYPos;
    tDrlgCoords.nSubtileWidth = pDrlgRoom->nTileWidth;
    tDrlgCoords.nSubtileHeight = pDrlgRoom->nTileHeight;

    DUNGEON_GameTileToSubtileCoords(&tDrlgCoords.nSubtileX, &tDrlgCoords.nSubtileY);
    DUNGEON_GameTileToSubtileCoords(&tDrlgCoords.nSubtileWidth, &tDrlgCoords.nSubtileHeight);

    D2DrlgTileDataListStrc* pTiles = &pDrlgRoom->ptDrlgTiles->pTiles;
    if (pTiles->nWalls || pTiles->nFloors)
    {
        int nFlags = 0;
        if (pDrlgRoom->dwFlags & DRLGROOMFLAG_0x40000)
        {
            nFlags = 4;
        }
        else if (pDrlgRoom->dwOtherFlags & 1)
        {
            nFlags = 1;
        }

        pDrlgRoom->pRoom = DUNGEON_AllocRoom(pDrlg->pAct, pDrlgRoom, &tDrlgCoords, pTiles, (int)SEED_RollRandomNumber(&pDrlgRoom->pSeed), nFlags);
    }
}

// 0x00642520
void __fastcall DRLG_GetMinAndMaxCoordinatesFromLevel(D2DrlgLevelStrc* pLevel, int* pTileMinX, int* pTileMinY, int* pTileMaxX, int* pTileMaxY)
{
    D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst;
    const D2DrlgCoordStrc* pDrlgCoord = &pDrlgRoom->pDrlgCoord;

    *pTileMinX = pDrlgCoord->nPosX;
    *pTileMinY = pDrlgCoord->nPosY;
    *pTileMaxX = pDrlgCoord->nPosX + pDrlgCoord->nWidth;
    *pTileMaxY = pDrlgCoord->nPosY + pDrlgCoord->nHeight;

    while (pDrlgRoom)
    {
        if (pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth > *pTileMaxX)
        {
            *pTileMaxX = pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth;
        }

        if (pDrlgRoom->pDrlgCoord.nPosX < *pTileMinX)
        {
            *pTileMinX = pDrlgRoom->pDrlgCoord.nPosX;
        }

        if (pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight > *pTileMaxY)
        {
            *pTileMaxY = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight;
        }

        if (pDrlgRoom->pDrlgCoord.nPosY < *pTileMinY)
        {
            *pTileMinY = pDrlgRoom->pDrlgCoord.nPosY;
        }

        pDrlgRoom = pDrlgRoom->pDrlgRoomNext;
    }
}

// 0x00642630
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromLevelAndCoordinates(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2_ASSERT(pLevel, 0x2FD);
    D2_ASSERT(pLevel->ptRoomFirst, 0x2FE);
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (DRLGROOM_AreXYInsideCoordinates(&pDrlgRoom->pDrlgCoord, nX, nY))
            return pDrlgRoom;
    }
    return 0;
}

// 0x00674200
int __fastcall DRLGOUTDOORS_TestGridCellSpawnValid(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    return !(DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY) & 0x1B81);
}

// 0x00675770
void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgVertexStrc* pVertex = pOutdoors->pVertex;
    D2DrlgVertexStrc* pNext = pVertex->pNext;
    do
    {
        if (pVertex->dwFlags & 1)
        {
            int nVisFlag = DRLGOUTDOORS_GetOutLinkVisFlag(pLevel, pVertex);
            int nPacked = 2 * (pVertex->nDirection != 0) + 1;
            sub_0067C760(&pOutdoors->pGrid[1], pVertex, nVisFlag, 0, 1);
            sub_0067C760(&pOutdoors->pGrid[2], pVertex, nPacked, 0, 1);
        }
        pVertex = pNext;
        pNext = pVertex->pNext;
    }
    while (pVertex != pOutdoors->pVertex);
}

// 0x00642770
int __fastcall sub_00642770_GetDrlgTypeFromLevelId(int nLevelId)
{
    return DATATBLS_GetLevelDefRecord(nLevelId)->dwDrlgType;
}

// 0x00642780
static __forceinline D2DrlgLevelStrc* sub_00642780_WalkLevels(D2DrlgStrc* pDrlg)
{
    D2DrlgLevelStrc* pLevel = pDrlg->pLevel;
    while (pLevel)
    {
        pLevel = pLevel->pNextLevel;
    }
    return pLevel;
}

D2DrlgLevelStrc* __stdcall sub_M121_Emit_00642780(D2DrlgStrc* pDrlg) { return sub_00642780_WalkLevels(pDrlg); }

// 0x006429D0
void __cdecl sub_006429D0_Nop()
{
}

// 0x00642920
D2DrlgWarpStrc* __fastcall DRLG_SetWarpId(D2DrlgWarpStrc* pDrlgWarp, int nVis, int nWarp, int nId)
{
    for (int i = 0; i < 8; ++i)
    {
        if (pDrlgWarp->nVis[i] == nVis)
        {
            pDrlgWarp->nWarp[i] = nWarp;
            return pDrlgWarp;
        }
    }

    if (nId == -1)
    {
        for (int i = 0; i < 8 && nId == -1; ++i)
        {
            if (!pDrlgWarp->nVis[i] && pDrlgWarp->nWarp[i] == -1)
            {
                nId = i;
            }
        }
    }

    pDrlgWarp->nVis[nId] = nVis;
    pDrlgWarp->nWarp[nId] = nWarp;
    return pDrlgWarp;
}

// build: context sub_0066D960_FindTilePresetEntry
int __stdcall sub_0066D960_FindTilePresetEntry(int nLevelId, unsigned int nPackedTileInformation, int bIsRightWallWithDoor)
{
    for (int i = 0; i < 37; ++i)
    {
        if (gDrlgRoomTileLevelRanges_006EEFC8[i].nLevelId == nLevelId)
        {
            const int nTileStyle = (nPackedTileInformation >> 20) & 0x3F;
            const int nTileSequence = (nPackedTileInformation >> 8) & 0xFF;

            for (int j = gDrlgRoomTileLevelRanges_006EEFC8[i].nArrayStartId; j <= gDrlgRoomTileLevelRanges_006EEFC8[i].nArrayEndId; ++j)
            {
                if (nTileStyle == gDrlgRoomTilePresetUnits_006EF188[j].nTileStyle
                    && nTileSequence == gDrlgRoomTilePresetUnits_006EF188[j].nTileSequence
                    && bIsRightWallWithDoor == gDrlgRoomTilePresetUnits_006EF188[j].bIsRightWallWithDoor)
                {
                    return j;
                }
            }
        }
    }

    return -1;
}

// build: context DRLG_GetLevel
static D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg,int id)
{
 for(D2DrlgLevelStrc* p=pDrlg->pLevel;p;p=p->pNextLevel) if(p->eLevelId==id)return p;
 return DRLG_AllocLevel(pDrlg,id);
}

// 0x00642D10
void __fastcall DRLG_SetLevelPositionAndSize(D2DrlgStrc* pDrlg,D2DrlgLevelStrc* pLevel)
{
 D2LevelDefBin* def=DATATBLS_GetLevelDefRecord(pLevel->eLevelId);
 D2DrlgLevelStrc* depend=0;
 int x=0,y=0;
 const int width=def->dwSizeX[pDrlg->nDifficulty];
 const int dependencyId=def->dwDepend;
 pLevel->nWidth=width;
 pLevel->nHeight=def->dwSizeY[pDrlg->nDifficulty];
 if(dependencyId) { depend=DRLG_GetLevel(pDrlg,dependencyId);x=depend->nPosX;y=depend->nPosY; }
 pLevel->nPosX=x+def->dwOffsetX;
 pLevel->nPosY=y+def->dwOffsetY;
}
