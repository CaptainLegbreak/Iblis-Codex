#include "D2Common.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define ROOMFLAG_2 0x00000002
#define ROOMFLAG_4 0x00000004
#define gpUniquePrefixTxt (gpUniqueNameTxtTables_0096D488[1])
#define gpUniqueSuffixTxt (gpUniqueNameTxtTables_0096D488[2])
#define gpUniqueAppellationTxt (gpUniqueNameTxtTables_0096D488[3])
#define gnUniquePrefixTxtRecordCount (gnUniqueNameTxtRecordCounts_0096D498[1])
#define gnUniqueSuffixTxtRecordCount (gnUniqueNameTxtRecordCounts_0096D498[2])
#define gnUniqueAppellationTxtRecordCount (gnUniqueNameTxtRecordCounts_0096D498[3])

struct D2GameStrc;
struct D2DrlgStrc;
struct D2DrlgEnvironmentStrc;
struct D2DrlgActStrc;
struct D2DrlgDeleteStrc;
struct D2PresetUnitStrc;
struct D2DrlgTileDataStrc;
struct D2RoomCoordListStrc;
struct D2DrlgRoomTilesStrc;
struct D2ClientStrc;
struct RoomEx;
struct Coord;
struct D2DrlgCoordsStrc;
struct Obj00619720;
struct sub_Z16_EmitRoomHolder;
struct D2SeedStrc;
struct D2ActRoom00619DA0Strc;
struct D2Act00619DA0Strc;
struct Obj00619EE0;
struct D2ItemCalcStrc;
struct D2SkillCalcStrc;
struct Unicode;
struct D2UniqueNameTxt;
struct Room;
struct Obj0061AFA0;

typedef void (__stdcall* AUTOMAPFN)(void* pRoom);

typedef void (__stdcall* TOWNAUTOMAPFN)(int nLevelId, int nPickedFile, int nX, int nY);

typedef void (__fastcall* ACTCALLBACKFN)(D2ActiveRoomStrc* pRoom);

struct D2DrlgActStrc
{
    int bHasPendingUnitListUpdates;
    D2DrlgEnvironmentStrc* pEnvironment;
    int nTownId;
    unsigned int dwInitSeed;
    D2ActiveRoomStrc* pRoom;
    unsigned char nAct;
    char pad0x15[3];
    void* pTileData[12];
    D2DrlgStrc* pDrlg;
    ACTCALLBACKFN pfnActCallBack;
    int bClient;
    int bHasPendingRoomsUpdates;
    char unk0x58[4];
    void* pMemPool;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2DrlgStrc* __fastcall DRLG_AllocDrlg(D2DrlgActStrc* pAct, unsigned char nActNo, void* hArchive, unsigned int nInitSeed, int nTownLevelId, unsigned int nFlags, D2GameStrc* pGame, unsigned char nDifficulty, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap); // 0x00642DA0
D2DrlgEnvironmentStrc* __fastcall ENVIRONMENT_AllocDrlgEnvironment(void* pMemPool); // 0x0061BE40
void __fastcall DRLGANIM_InitCache(D2DrlgStrc* pDrlg, void** ppTileData); // 0x00642A30

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

struct D2DrlgRoomTilesStrc
{
    D2DrlgTileDataStrc* pWallTiles;
    int nWalls;
    D2DrlgTileDataStrc* pFloorTiles;
    int nFloors;
    D2DrlgTileDataStrc* pRoofTiles;
    int nRoofs;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ActiveRoomStrc
{
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nMaxClients;
    D2DrlgRoomTilesStrc* pRoomTiles;
    char unk0x0C[4];
    D2DrlgRoomStrc* pDrlgRoom;
    char unk0x14[4];
    D2DrlgDeleteStrc* pDrlgDelete;
    D2UnitStrc* pUnitUpdate;
    void* pCollisionGrid;
    int nNumRooms;
    int nAllies;
    D2DrlgActStrc* pAct;
    char unk0x30[4];
    unsigned int dwFlags;
    unsigned char unk_38[0x10];
    D2ClientStrc** ppClients;
    D2DrlgCoordsStrc tCoords;
    D2SeedStrc tSeed;
    D2UnitStrc* pUnitFirst;
    unsigned int nNumClients;
    D2ActiveRoomStrc* pRoomNext;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __fastcall DRLGWARP_ToggleRoomTilesEnableFlag(D2DrlgRoomStrc* pDrlgRoom, int bEnabled); // 0x0066AB70

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
};

D2LvlWarpTxt* __fastcall DRLGWARP_GetLvlWarpTxtRecordFromUnit(D2DrlgRoomStrc* pDrlgRoom, D2UnitStrc* pUnit); // 0x0066AF80
void __fastcall DRLGROOM_GetRGB_IntensityFromRoomEx(D2DrlgRoomStrc* pDrlgRoom, unsigned char* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0066BFD0
D2ActiveRoomStrc* __fastcall sub_6FD788D0(D2DrlgStrc* pDrlg, int nLevelId, int nTileIndex, int* pX, int* pY); // 0x0066B2B0
D2PresetUnitStrc* __fastcall DRLGROOM_GetPresetUnits(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BFA0
void __fastcall DRLGACTIVATE_SetClientIsInSight(D2DrlgStrc* pDrlg, int nLevelId, int nX, int nY, D2DrlgRoomStrc* pDrlgRoom); // 0x0061B640
void __fastcall DRLGACTIVATE_UnsetClientIsInSight(D2DrlgStrc* pDrlg, int nLevelId, int nX, int nY, D2DrlgRoomStrc* pDrlgRoom); // 0x0061B690
void __fastcall DRLGACTIVATE_ChangeClientRoom(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2); // 0x0061B6F0
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_StreamRoomAtCoords(D2DrlgStrc* pDrlg, int nX, int nY); // 0x0061B7B0
int __fastcall DRLGROOM_GetLevelId(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BAB0
int __fastcall DRLGROOM_GetLevelIdFromPopulatedRoom(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BB20
int __fastcall DRLGROOM_HasWaypoint(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BB60
const char* __fastcall DRLGROOM_GetPickedLevelPrestFilePathFromRoomEx(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BBA0
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_GetARoomInClientSight(D2DrlgStrc* pDrlg); // 0x0061B840
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_GetARoomInSightButWithoutClient(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom); // 0x0061B870
int __fastcall DRLGACTIVATE_TestRoomCanUnTile(D2DrlgRoomStrc* pDrlgRoom); // 0x0061BA30
void __fastcall sub_6FD745C0(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2); // 0x00643020
void __fastcall DRLG_UpdateAndFreeInactiveRooms(D2DrlgStrc* pDrlg); // 0x00643200
int __fastcall DRLGROOM_CheckLOSDraw(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BA70
int __fastcall DRLG_IsTownLevel(int nLevelId); // 0x006426A0
int __fastcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x00642740
int __fastcall sub_6FD779F0(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BA90
int __fastcall DRLG_GetNumberOfPopulatedRoomsInLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642BE0
int* __fastcall DRLG_GetRoomCenterX_RoomWarpXFromRoom(D2DrlgRoomStrc* pDrlgRoom); // 0x00642380
void __fastcall DRLGWARP_UpdateWarpRoomSelect(D2DrlgRoomStrc* pDrlgRoom, int nLevelId); // 0x0066AB90
void __fastcall DRLGWARP_UpdateWarpRoomDeselect(D2DrlgRoomStrc* pDrlgRoom, int nLevelId); // 0x0066ABE0
void __fastcall DRLGPRESET_UpdatePops(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, int bOtherRoom); // 0x006671E0
D2RoomCoordListStrc* __fastcall sub_6FD77110(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY); // 0x0066CEB0
D2RoomCoordListStrc* __fastcall DRLGLOGIC_GetRoomCoordList(D2DrlgRoomStrc* pDrlgRoom); // 0x0066CF30
void __fastcall DRLGACTIVATE_ToggleHasPortalFlag(D2DrlgRoomStrc* pDrlgRoom, int bReset); // 0x0061BAC0
void __fastcall DRLGANIM_AnimateTiles(D2DrlgRoomStrc* pDrlgRoom); // 0x0066D410
void __fastcall DRLGANIM_UpdateFrameInAdjacentRooms(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2); // 0x0066D750
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

struct Obj00619720 { unsigned int dwUnknown00[6]; unsigned int dwMember18; };

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
int __fastcall sub_0066BCF0(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BCF0
int __fastcall DRLGROOM_ReorderNearRoomList(D2DrlgRoomStrc* pDrlgRoom, D2ActiveRoomStrc** ppRoomList); // 0x0066BD00

struct sub_Z16_EmitRoomHolder
{
    char unk0x00[0x5C];
    void* pMemory;
};

typedef char sub_G03_AssertRoomSize[sizeof(D2ActiveRoomStrc) == 0x80 ? 1 : -1];

typedef char sub_G03_AssertRoomSeed[(int)&((D2ActiveRoomStrc*)0)->tSeed == 0x6C ? 1 : -1];

typedef char sub_G03_AssertRoomNext[(int)&((D2ActiveRoomStrc*)0)->pRoomNext == 0x7C ? 1 : -1];

typedef char sub_G03_AssertActPool[(int)&((D2DrlgActStrc*)0)->pMemPool == 0x5C ? 1 : -1];

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
void __fastcall COLLISION_AllocRoomCollisionGrid(void* pMemPool, D2ActiveRoomStrc* pRoom); // 0x0064C900
void __fastcall DRLGROOM_SetRoom(D2DrlgRoomStrc* pDrlgRoom, D2ActiveRoomStrc* pRoom); // 0x0066BFC0

struct D2ActRoom00619DA0Strc
{
    unsigned char unk_00[0x4C];
    int nX4C;
    int nY50;
    int nWidth54;
    int nHeight58;
    unsigned char unk_5C[0x7C - 0x5C];
    D2ActRoom00619DA0Strc* pNext7C;
};

struct D2Act00619DA0Strc
{
    unsigned char unk_00[0x10];
    D2ActRoom00619DA0Strc* pFirstRoom10;
};

struct Obj00619EE0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    int nCount28;
};

struct D2DrlgDeleteStrc
{
    int nUnitType;
    int nUnitGUID;
    D2DrlgDeleteStrc* pNext;
};

void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
unsigned char __fastcall DRLGACTIVATE_GetRoomStatusFlags(D2DrlgRoomStrc*); // 0x0061BAE0
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0

struct D2ItemCalcStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pItem;
};

struct D2SkillCalcStrc
{
    D2UnitStrc* pUnit;
};

struct Unicode
{
    unsigned short wChar;
};

struct D2UniqueNameTxt
{
    unsigned short wStringId;
};

enum D2C_J11CalcConstants
{
    UNIT_ITEM = 4,
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90

struct Room { char pad[0x10]; RoomEx* roomEx[2]; };

void __fastcall sub_00666A80(RoomEx*,Coord**,int*); // 0x00666A80

enum { ROOM_SLOT = 0 };

struct Obj0061AFA0 { unsigned char bUnknown00[0x14]; unsigned char bIndex14; unsigned char bUnknown15[0x23]; unsigned int dwRing38[4]; };

// 0x006194A0
D2DrlgActStrc* __stdcall DUNGEON_AllocAct(unsigned char nAct, unsigned int nInitSeed, int bClient, D2GameStrc* pGame, unsigned char nDifficulty, void* pMemPool, int nTownLevelId, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap)
{
    D2DrlgActStrc* pAct = (D2DrlgActStrc*)sub_0040B430(pMemPool, sizeof(D2DrlgActStrc), ".\\DUNGEON\\Dungeon.cpp", 0x19, 0);
    memset(pAct, 0, sizeof(D2DrlgActStrc));

    pAct->dwInitSeed = nInitSeed;
    pAct->bClient = bClient;
    pAct->nAct = nAct;
    pAct->pMemPool = pMemPool;

    if (bClient)
    {
        pAct->pDrlg = DRLG_AllocDrlg(pAct, nAct, 0, nInitSeed, 0, 1, pGame, nDifficulty, pfAutoMap, pfTownAutoMap);
    }
    else
    {
        pAct->nTownId = nTownLevelId;
        pAct->pDrlg = DRLG_AllocDrlg(pAct, nAct, 0, nInitSeed, nTownLevelId, 0, pGame, nDifficulty, pfAutoMap, pfTownAutoMap);
    }

    pAct->pEnvironment = ENVIRONMENT_AllocDrlgEnvironment(pMemPool);
    DRLGANIM_InitCache(pAct->pDrlg, pAct->pTileData);
    return pAct;
}

// 0x00619550
void* __fastcall DUNGEON_GetMemPoolFromAct(D2DrlgActStrc* pAct)
{
    return pAct->pMemPool;
}

// 0x00619560
void __stdcall DUNGEON_ToggleRoomTilesEnableFlag(D2ActiveRoomStrc* pRoom, int bEnabled)
{
    D2_ASSERT(pRoom, 98);

    DRLGWARP_ToggleRoomTilesEnableFlag(pRoom->pDrlgRoom, bEnabled);
}

// 0x00619620
D2LvlWarpTxt* __stdcall DUNGEON_GetLvlWarpTxtRecordFromRoomAndUnit(D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit)
{
    D2_ASSERT(pRoom, 138);

    return DRLGWARP_GetLvlWarpTxtRecordFromUnit(pRoom->pDrlgRoom, pUnit);
}

// 0x00619660
D2DrlgTileDataStrc* __stdcall DUNGEON_GetFloorTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pFloorCount)
{
    if (pRoom && pRoom->pRoomTiles)
    {
        *pFloorCount = pRoom->pRoomTiles->nFloors;
        return pRoom->pRoomTiles->pFloorTiles;
    }

    *pFloorCount = 0;
    return 0;
}

// 0x006196A0
D2DrlgTileDataStrc* __stdcall DUNGEON_GetWallTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pWallCount)
{
    D2_ASSERT(pRoom, 177);

    *pWallCount = pRoom->pRoomTiles->nWalls;
    return pRoom->pRoomTiles->pWallTiles;
}

// 0x006196E0
D2DrlgTileDataStrc* __stdcall DUNGEON_GetRoofTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pRoofCount)
{
    D2_ASSERT(pRoom, 190);

    *pRoofCount = pRoom->pRoomTiles->nRoofs;
    return pRoom->pRoomTiles->pRoofTiles;
}

// 0x00619730
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords)
{
    D2_ASSERT(pCoords, 209);

    if (!pRoom)
    {
        memset(pCoords, 0x00, sizeof(D2DrlgCoordsStrc));
        return;
    }

    memcpy(pCoords, &pRoom->tCoords, sizeof(D2DrlgCoordsStrc));
}

// 0x00619790
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms)
{
    D2_ASSERT(pRoom, 236);

    *pNumRooms = pRoom->nNumRooms;
    *pppRoomList = pRoom->ppRoomList;
}

// 0x00619D70
void __stdcall DUNGEON_GetRGB_IntensityFromRoom(D2ActiveRoomStrc* pRoom, unsigned char* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    DRLGROOM_GetRGB_IntensityFromRoomEx(pRoom->pDrlgRoom, pIntensity, pRed, pGreen, pBlue);
}

// 0x00619E50
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocation(D2DrlgActStrc* pAct, int nLevelId, int nTileIndex, int* pX, int* pY)
{
    D2_ASSERT(pAct, 545);

    return sub_6FD788D0(pAct->pDrlg, nLevelId, nTileIndex, pX, pY);
}

// 0x00619F00
int __stdcall DUNGEON_GetAlliedCountFromRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return pRoom->nAllies;
}

// 0x00619F60
D2UnitStrc** __fastcall DUNGEON_GetUnitListFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 646);

    return &pRoom->pUnitFirst;
}

// 0x00619F90
D2UnitStrc** __fastcall DUNGEON_GetUnitUpdateListFromRoom(D2ActiveRoomStrc* pRoom, int bUpdate)
{
    D2_ASSERT(pRoom, 685);

    if (bUpdate)
    {
        pRoom->pAct->bHasPendingUnitListUpdates = 1;
    }

    return &pRoom->pUnitUpdate;
}

// 0x00619FD0
D2PresetUnitStrc* __stdcall DUNGEON_GetPresetUnitsFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 699);

    return DRLGROOM_GetPresetUnits(pRoom->pDrlgRoom);
}

// 0x0061A010
void* __fastcall DUNGEON_GetCollisionGridFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 709);

    return pRoom->pCollisionGrid;
}

// 0x0061A040
void __fastcall DUNGEON_SetCollisionGridInRoom(D2ActiveRoomStrc* pRoom, void* pCollisionGrid)
{
    D2_ASSERT(pRoom, 718);

    pRoom->pCollisionGrid = pCollisionGrid;
}

// 0x0061A070
void __stdcall DUNGEON_SetClientIsInSight(D2DrlgActStrc* pAct, int nLevelId, int nX, int nY, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pAct, 727);

    DRLGACTIVATE_SetClientIsInSight(pAct->pDrlg, nLevelId, nX, nY, pRoom ? pRoom->pDrlgRoom : 0);
}

// 0x0061A0C0
void __stdcall DUNGEON_UnsetClientIsInSight(D2DrlgActStrc* pAct, int nLevelId, int nX, int nY, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pAct, 745);

    DRLGACTIVATE_UnsetClientIsInSight(pAct->pDrlg, nLevelId, nX, nY, pRoom ? pRoom->pDrlgRoom : 0);
}

// 0x0061A110
void __stdcall DUNGEON_ChangeClientRoom(D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2)
{
    D2DrlgRoomStrc* pDrlgRoom1 = 0;
    D2DrlgRoomStrc* pDrlgRoom2 = 0;

    if (pRoom1)
    {
        pDrlgRoom1 = pRoom1->pDrlgRoom;
    }

    if (pRoom2)
    {
        pDrlgRoom2 = pRoom2->pDrlgRoom;
    }

    DRLGACTIVATE_ChangeClientRoom(pDrlgRoom1, pDrlgRoom2);
}

// 0x0061A140
D2ActiveRoomStrc* __stdcall DUNGEON_StreamRoomAtCoords(D2DrlgActStrc* pAct, int nX, int nY)
{
    D2_ASSERT(pAct, 787);

    return DRLGACTIVATE_StreamRoomAtCoords(pAct->pDrlg, nX, nY);
}

// 0x0061A180
D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct)
{
    D2_ASSERT(pAct, 798);

    return pAct->pRoom;
}

// 0x0061A1B0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLGROOM_GetLevelId(pRoom->pDrlgRoom);
}

// 0x0061A1F0
int __stdcall DUNGEON_GetLevelIdFromPopulatedRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLGROOM_GetLevelIdFromPopulatedRoom(pRoom->pDrlgRoom);
}

// 0x0061A210
int __stdcall DUNGEON_HasWaypoint(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 867);

    return DRLGROOM_HasWaypoint(pRoom->pDrlgRoom);
}

// 0x0061A250
const char* __stdcall DUNGEON_GetPickedLevelPrestFilePathFromRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLGROOM_GetPickedLevelPrestFilePathFromRoomEx(pRoom->pDrlgRoom);
}

// 0x0061A330
D2DrlgDeleteStrc* __stdcall DUNGEON_GetDrlgDeleteFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 934);

    return pRoom->pDrlgDelete;
}

// 0x0061A360
D2ActiveRoomStrc* __stdcall DUNGEON_GetARoomInClientSight(D2DrlgActStrc* pAct)
{
    D2_ASSERT(pAct, 965);

    return DRLGACTIVATE_GetARoomInClientSight(pAct->pDrlg);
}

// 0x0061A3A0
D2ActiveRoomStrc* __stdcall DUNGEON_GetARoomInSightButWithoutClient(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pAct, 974);

    D2_ASSERT(pRoom, 977);

    return DRLGACTIVATE_GetARoomInSightButWithoutClient(pAct->pDrlg, pRoom->pDrlgRoom);
}

// 0x0061A3F0
int __stdcall DUNGEON_TestRoomCanUnTile(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pAct, 989);
    D2_ASSERT(!pAct->bClient, 990);
    D2_ASSERT(pRoom, 991);

    return DRLGACTIVATE_TestRoomCanUnTile(pRoom->pDrlgRoom);
}

// 0x0061A4D0
int __stdcall D2Common_10074(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 1071);

    return pRoom->dwFlags & ROOMFLAG_2;
}

// 0x0061A510
void __stdcall D2Common_10075(D2ActiveRoomStrc* pRoom, int bSet)
{
    D2_ASSERT(pRoom, 1080);

    if (bSet)
    {
        pRoom->dwFlags |= ROOMFLAG_2;
    }
    else
    {
        pRoom->dwFlags &= ~ROOMFLAG_2;
    }
}

// 0x0061A9F0
void __stdcall D2Common_10077(D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2)
{
    D2DrlgRoomStrc* pDrlgRoom1 = pRoom1 ? pRoom1->pDrlgRoom : 0;
    D2DrlgRoomStrc* pDrlgRoom2 = pRoom2 ? pRoom2->pDrlgRoom : 0;
    sub_6FD745C0(pDrlgRoom1, pDrlgRoom2);
}

// 0x0061AA20
void __stdcall DUNGEON_UpdateAndFreeInactiveRooms(D2DrlgActStrc* pAct)
{
    DRLG_UpdateAndFreeInactiveRooms(pAct->pDrlg);
}

// 0x0061AA40
int __stdcall DUNGEON_CheckLOSDraw(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLGROOM_CheckLOSDraw(pRoom->pDrlgRoom);
}

// 0x0061AA60
D2DrlgEnvironmentStrc* __fastcall DUNGEON_GetEnvironmentFromAct(D2DrlgActStrc* pAct)
{
    D2_ASSERT(pAct, 1351);

    return pAct->pEnvironment;
}

// 0x0061AA90
D2DrlgStrc* __stdcall DUNGEON_GetDrlgFromAct(D2DrlgActStrc* pAct)
{
    D2_ASSERT(pAct, 1360);

    return pAct->pDrlg;
}

// 0x0061AAE0
D2DrlgRoomStrc* __fastcall DUNGEON_GetRoomExFromRoom(D2ActiveRoomStrc* pRoom)
{
    return pRoom->pDrlgRoom;
}

// 0x0061AAF0
int __stdcall DUNGEON_IsTownLevelId(int nLevelId)
{
    return DRLG_IsTownLevel(nLevelId);
}

// 0x0061AB00
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLG_IsTownLevel(DRLGROOM_GetLevelId(pRoom->pDrlgRoom));
}

// 0x0061AB30
int __stdcall sub_0061AB30(D2ActiveRoomStrc* pRoom)
{
    return DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
}

// 0x0061AB60
int __stdcall D2Common_10084(D2ActiveRoomStrc* pRoom)
{
    return pRoom->dwFlags & ROOMFLAG_4;
}

// 0x0061ABB0
int __stdcall D2Common_10087(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 1445);

    return sub_6FD779F0(pRoom->pDrlgRoom);
}

// 0x0061ABF0
int __stdcall DUNGEON_GetNumberOfPopulatedRoomsInLevel(D2DrlgActStrc* pAct, int nLevelId)
{
    return DRLG_GetNumberOfPopulatedRoomsInLevel(pAct->pDrlg, nLevelId);
}

// 0x0061AC10
int* __stdcall DUNGEON_GetWarpCoordinatesFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 1465);

    return DRLG_GetRoomCenterX_RoomWarpXFromRoom(pRoom->pDrlgRoom);
}

// 0x0061AC50
void __stdcall DUNGEON_UpdateWarpRoomSelect(D2ActiveRoomStrc* pRoom, int nLevelId)
{
    D2_ASSERT(pRoom, 1476);

    DRLGWARP_UpdateWarpRoomSelect(pRoom->pDrlgRoom, nLevelId);
}

// 0x0061AC90
void __stdcall DUNGEON_UpdateWarpRoomDeselect(D2ActiveRoomStrc* pRoom, int nLevelId)
{
    D2_ASSERT(pRoom, 1487);

    DRLGWARP_UpdateWarpRoomDeselect(pRoom->pDrlgRoom, nLevelId);
}

// 0x0061ACD0
void __stdcall DUNGEON_UpdatePops(D2ActiveRoomStrc* pRoom, int nX, int nY, int bOtherRoom)
{
    D2_ASSERT(pRoom, 1498);

    DRLGPRESET_UpdatePops(pRoom->pDrlgRoom, nX, nY, bOtherRoom);
}

// 0x0061AD30
D2RoomCoordListStrc* __stdcall D2Common_10096(D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    return sub_6FD77110(pRoom->pDrlgRoom, nX, nY);
}

// 0x0061AD50
D2RoomCoordListStrc* __stdcall DUNGEON_GetRoomCoordList(D2ActiveRoomStrc* pRoom)
{
    return DRLGLOGIC_GetRoomCoordList(pRoom->pDrlgRoom);
}

// 0x0061AE80
int __stdcall DUNGEON_GetTownLevelIdFromAct(D2DrlgActStrc* pAct)
{
    D2_ASSERT(pAct, 1588);

    return pAct->nTownId;
}

// 0x0061AED0
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bReset)
{
    if (pRoom)
    {
        DRLGACTIVATE_ToggleHasPortalFlag(pRoom->pDrlgRoom, bReset);
    }
}

// 0x0061AEF0
void __stdcall DUNGEON_AnimateTiles(D2ActiveRoomStrc* pRoom)
{
    if (pRoom)
    {
        DRLGANIM_AnimateTiles(pRoom->pDrlgRoom);
    }
}

// 0x0061AF10
void __stdcall DUNGEON_InitRoomTileAnimation(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2)
{
    D2DrlgRoomStrc* pDrlgRoom1 = 0;
    D2DrlgRoomStrc* pDrlgRoom2 = 0;

    if (pRoom1)
    {
        for (D2ActiveRoomStrc* pRoom = pAct->pRoom; pRoom; pRoom = pRoom->pRoomNext)
        {
            if (pRoom == pRoom1)
            {
                pDrlgRoom1 = pRoom1->pDrlgRoom;
                break;
            }
        }
    }

    if (pRoom2)
    {
        pDrlgRoom2 = pRoom2->pDrlgRoom;
    }

    DRLGANIM_UpdateFrameInAdjacentRooms(pDrlgRoom1, pDrlgRoom2);
}

// 0x0061AF60
void __stdcall DUNGEON_SetActCallbackFunc(D2DrlgActStrc* pAct, ACTCALLBACKFN pActCallbackFunction)
{
    D2_ASSERT(pAct, 1663);

    pAct->pfnActCallBack = pActCallbackFunction;
}

// 0x00619720
extern "C" __declspec(dllexport) unsigned int* __stdcall sub_00619720(Obj00619720* pObj) {
    return &pObj->dwMember18;
}

// 0x00619800
static void __stdcall sub_00619800(void* pMemory, D2ActiveRoomStrc* pRoom)
{
    const int nNear = sub_0066BCF0(pRoom->pDrlgRoom);
    pRoom->ppRoomList = (D2ActiveRoomStrc**)FOG_AllocPool(pMemory, sizeof(D2ActiveRoomStrc*) * nNear, ".\\DUNGEON\\Dungeon.cpp", 256, 0);
    pRoom->nNumRooms = DRLGROOM_ReorderNearRoomList(pRoom->pDrlgRoom, pRoom->ppRoomList);
    for (unsigned int i = 0; i < pRoom->nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pAdjacentRoom = pRoom->ppRoomList[i];
        D2_ASSERT(pAdjacentRoom, 264);
        if (pAdjacentRoom != pRoom)
            pAdjacentRoom->nNumRooms = DRLGROOM_ReorderNearRoomList(pAdjacentRoom->pDrlgRoom, pAdjacentRoom->ppRoomList);
    }
}

D2ActiveRoomStrc* __fastcall sub_Z16_EmitUpdateRoomsNear(sub_Z16_EmitRoomHolder* pOther, D2ActiveRoomStrc* pRoom)
{
    sub_00619800(pOther->pMemory, pRoom);
    return pRoom;
}

// 0x00619890
D2ActiveRoomStrc* __fastcall DUNGEON_AllocRoom(D2DrlgActStrc* pAct, D2DrlgRoomStrc* pDrlgRoom, D2DrlgCoordsStrc* pDrlgCoords, D2DrlgRoomTilesStrc* pRoomTiles, int nLowSeed, unsigned int dwFlags)
{
    D2_ASSERT(pAct, 281);

    D2ActiveRoomStrc* pRoom = (D2ActiveRoomStrc*)FOG_AllocPool(pAct->pMemPool, sizeof(D2ActiveRoomStrc), ".\\DUNGEON\\Dungeon.cpp", 245, 0);
    memset(pRoom, 0, sizeof(D2ActiveRoomStrc));

    pRoom->dwFlags = dwFlags;
    SEED_InitLowSeed(&pRoom->tSeed, nLowSeed);

    pRoom->pDrlgRoom = pDrlgRoom;
    pRoom->tCoords = *pDrlgCoords;
    pRoom->pRoomTiles = pRoomTiles;
    pRoom->pRoomNext = pAct->pRoom;
    pAct->pRoom = pRoom;
    pAct->bHasPendingRoomsUpdates = 1;
    pRoom->pAct = pAct;

    DRLGROOM_SetRoom(pDrlgRoom, pRoom);
    sub_00619800(pAct->pMemPool, pRoom);
    COLLISION_AllocRoomCollisionGrid(pAct->pMemPool, pRoom);

    if (pAct->pfnActCallBack)
    {
        pAct->pfnActCallBack(pRoom);
    }

    return pRoom;
}

// 0x00619DA0
D2ActRoom00619DA0Strc* __stdcall sub_00619DA0_ActLookup(D2Act00619DA0Strc* pAct, int nX, int nY)
{
    if (!pAct)
    {
        return 0;
    }
    for (D2ActRoom00619DA0Strc* pRoom = pAct->pFirstRoom10; pRoom; pRoom = pRoom->pNext7C)
    {
        if (pRoom && nX >= pRoom->nX4C && nX < pRoom->nX4C + pRoom->nWidth54 && nY >= pRoom->nY50 && nY < pRoom->nY50 + pRoom->nHeight58)
        {
            return pRoom;
        }
    }
    return 0;
}

// 0x00619EE0
extern "C" __declspec(dllexport) void __stdcall sub_00619EE0(Obj00619EE0* pObj) {
    if (pObj) {
        pObj->nCount28++;
    }
}

// 0x0061A2C0
void __stdcall DUNGEON_FreeDrlgDelete(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 912);

    D2DrlgDeleteStrc* pDrlgDelete = pRoom->pDrlgDelete;
    void* pMemPool = pRoom->pAct->pMemPool;
    if (pDrlgDelete)
    {
        do
        {
            D2DrlgDeleteStrc* pFree = pDrlgDelete;
            pDrlgDelete = pDrlgDelete->pNext;
            FOG_FreePool(pMemPool, pFree, ".\\DUNGEON\\Dungeon.cpp", 924, 0);
        }
        while (pDrlgDelete);
        pRoom->pDrlgDelete = 0;
    }
}

// 0x0061A440
int __stdcall DUNGEON_GetRoomStatusFlags(D2ActiveRoomStrc* pRoom)
{
    return DRLGACTIVATE_GetRoomStatusFlags(pRoom->pDrlgRoom) >= 3;
}

// 0x0061A550
static int sub_0061A550_CheckClientsOfRoom(D2ActiveRoomStrc* pRoom)
{
    for (unsigned int i = 0; i < pRoom->nNumClients; ++i)
    {
        D2_ASSERT(pRoom->ppClients[i], 0x453);
    }
    return 1;
}

// 0x0061A5A0
static void DUNGEON_UpdateClientListOfRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(sub_0061A550_CheckClientsOfRoom(pRoom), 0x45B);

    for (int nClients = pRoom->nNumClients - 1; nClients > 0; --nClients)
    {
        int bContinue = 0;
        for (int i = 0; i < nClients; ++i)
        {
            if (pRoom->ppClients[i] > pRoom->ppClients[i + 1])
            {
                D2ClientStrc* pTemp = pRoom->ppClients[i];
                pRoom->ppClients[i] = pRoom->ppClients[i + 1];
                pRoom->ppClients[i + 1] = pTemp;
                bContinue = 1;
            }
        }
        if (!bContinue)
            return;
    }

    sub_0061A550_CheckClientsOfRoom(pRoom);
}

// 0x0061A660
void __stdcall DUNGEON_AddClientToRoom(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x473);
    D2_ASSERT(pClient, 0x474);
    D2_ASSERT(sub_0061A550_CheckClientsOfRoom(pRoom), 0x475);
    D2_ASSERT(pRoom->nNumClients <= pRoom->nMaxClients, 0x477);

    if (pRoom->nNumClients == pRoom->nMaxClients)
    {
        pRoom->nMaxClients += 4;
        pRoom->ppClients = (D2ClientStrc**)FOG_ReallocPool(pRoom->pAct->pMemPool, pRoom->ppClients, sizeof(D2ClientStrc*) * pRoom->nMaxClients, ".\\DUNGEON\\Dungeon.cpp", 0x47B, 0);
    }

    pRoom->ppClients[pRoom->nNumClients] = pClient;
    ++pRoom->nNumClients;
    DUNGEON_UpdateClientListOfRoom(pRoom);
}

// 0x0061A700
void __stdcall DUNGEON_RemoveClientFromRoom(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x487);
    D2_ASSERT(pClient, 0x488);
    D2_ASSERT(sub_0061A550_CheckClientsOfRoom(pRoom), 0x489);

    unsigned int i = 0;
    for (i = 0; i < pRoom->nNumClients; ++i)
    {
        if (pRoom->ppClients[i] == pClient)
            break;
    }
    D2_ASSERT(i < pRoom->nNumClients, 0x490);

    pRoom->ppClients[i] = pRoom->ppClients[pRoom->nNumClients - 1];
    --pRoom->nNumClients;
    DUNGEON_UpdateClientListOfRoom(pRoom);
}

D2UniqueNameTxt* gpUniqueNameTxtTables_0096D488[4]; // 0x0096D488

int gnUniqueNameTxtRecordCounts_0096D498[4]; // 0x0096D498

Unicode gwszDataTablesDefault; // 0x0096D4B4

// 0x0061AAC0
int __stdcall DUNGEON_GetInitSeedFromAct(D2DrlgActStrc* pAct)
{
    if (!pAct)
    {
        return 0;
    }
    return pAct->dwInitSeed;
}

// 0x00627B70
int __fastcall sub_6FD98220(int nMin, int nMax, int nUnused, void* pUserData)
{
    D2ItemCalcStrc* pItemCalc = (D2ItemCalcStrc*)pUserData;
    if (!pItemCalc)
    {
        return 0;
    }
    D2SeedStrc* pSeed = &pItemCalc->pUnit->pSeed;
    if (nMin >= nMax)
    {
        return nMin;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1);
}

// 0x00643700
int __fastcall sub_00643700_SkillCalcGetRandomNumberInRange(int nMin, int nMax, int nUnused, void* pUserData)
{
    D2SkillCalcStrc* pSkillCalc = (D2SkillCalcStrc*)pUserData;
    if (!pSkillCalc)
    {
        return 0;
    }
    D2SeedStrc* pSeed = &pSkillCalc->pUnit->pSeed;
    if (nMin >= nMax)
    {
        return nMin;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1);
}

// 0x0064B720
int __fastcall MISSILE_GetRandomNumberInRange(int nMin, int nMax, int nUnused, void* pUserData)
{
    D2UnitStrc* pMissile = (D2UnitStrc*)pUserData;
    if (!pMissile)
    {
        return 0;
    }
    if (nMin >= nMax)
    {
        return nMin;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, nMax - nMin + 1);
}

// 0x00650E50
unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed)
{
    return pSeed->nLowSeed;
}

// 0x00653ED0
const Unicode* __fastcall DATATBLS_RollRandomUniquePrefixString(D2UnitStrc* pUnit)
{
    if (pUnit && gnUniquePrefixTxtRecordCount > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniquePrefixTxtRecordCount);
        if (gpUniquePrefixTxt[nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniquePrefixTxt[nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}

// 0x00653F10
const Unicode* __fastcall DATATBLS_RollRandomUniqueSuffixString(D2UnitStrc* pUnit)
{
    if (pUnit && gnUniqueSuffixTxtRecordCount > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniqueSuffixTxtRecordCount);
        if (gpUniqueSuffixTxt[nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniqueSuffixTxt[nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}

// 0x00653F50
const Unicode* __fastcall DATATBLS_RollRandomUniqueAppellationString(D2UnitStrc* pUnit)
{
    if (pUnit && gnUniqueAppellationTxtRecordCount > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniqueAppellationTxtRecordCount);
        if (gpUniqueAppellationTxt[nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniqueAppellationTxt[nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}

// 0x0065E9E0
int __fastcall ITEMMODS_RollRandomValueInRange(D2UnitStrc* pItem, int nMin, int nMax)
{
    if (nMax == nMin)
    {
        return nMin;
    }
    if (nMax < nMin)
    {
        const int nTemp = nMax;
        nMax = nMin;
        nMin = nTemp;
    }
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);
        if (nMin >= nMax)
        {
            return nMin;
        }
        return nMin + ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1);
    }
    if (nMin >= nMax)
    {
        return nMin;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nMax - nMin + 1);
}

// 0x0061AD10
void __stdcall sub_0061AD10(Room* room,Coord** tiles,int* count)
{
    sub_00666A80(room->roomEx[ROOM_SLOT],tiles,count);
}

// 0x0061AFA0
extern "C" __declspec(dllexport) void __stdcall sub_0061AFA0(Obj0061AFA0* pObj, unsigned int dwValue) {
    if (pObj) {
        pObj->dwRing38[pObj->bIndex14] = dwValue;
        pObj->bIndex14 = (pObj->bIndex14 + 1) & 3;
    }
}
