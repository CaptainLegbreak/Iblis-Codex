extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2DrlgEnvironmentStrc;
struct D2DrlgRoomStrc;
struct D2DrlgStrc;

struct D2DrlgActStrc
{
    char unk0x00[0x48];
    D2DrlgStrc* pDrlg;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x10];
    D2DrlgRoomStrc* pFirstRoomEx;
    char unk0x014[0x1A0];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x18];
    int nLevelId;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x24];
    D2DrlgRoomStrc* pDrlgRoomNext;
    unsigned int dwFlags;
    int nRoomsNear;
    D2ActiveRoomStrc* pRoom;
    char unk0x34[0x10];
    unsigned char fRoomStatus;
    char unk0x45[0x03];
    int nType;
    char unk0x4C[0x0C];
    D2DrlgLevelStrc* pLevel;
};

struct D2DrlgStrc
{
    char unk0x000[0x08];
    int nAllocatedRooms;
    char unk0x00C[0x8C];
    unsigned char nRoomsInitSinceLastUpdate;
    char unk0x099[0x3DF];
    void* pMempool;
};

#define DRLGROOMFLAG_HAS_ROOM 0x100000
#define DRLGROOMFLAG_HASPORTAL 0x400000
#define DRLGROOMFLAG_TILELIB_LOADED 0x1000000
#define DRLGROOMFLAG_PRESET_UNITS_ADDED 0x2000000
#define DRLGTYPE_PRESET 2
#define LEVEL_ROCKYSUMMIT 120

extern const int gnTownLevelIds_006E7D1C[5];                                                                // 0x006E7D1C

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
int __fastcall DRLG_GetHoradricStaffTombLevelId(D2DrlgStrc* pDrlg);                                         // 0x00642230
void __fastcall DRLGROOMTILE_LoadDT1FilesForRoom(D2DrlgRoomStrc* pDrlgRoom);                                // 0x0066F240
void __fastcall DRLGPRESET_SpawnHardcodedPresetUnits(D2DrlgRoomStrc* pDrlgRoom);                            // 0x00667890
void __fastcall DRLGROOM_InitNearRooms(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom);                          // 0x0066C370
void __fastcall DRLGROOMTILE_InitRoomGrids(D2DrlgRoomStrc* pDrlgRoom);                                      // 0x0066EE40
void __fastcall DRLGROOMTILE_AddRoomMapTiles(D2DrlgRoomStrc* pDrlgRoom);                                    // 0x0066EE70
void __fastcall DRLG_CreateRoomForRoomEx(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom);                     // 0x006422A0
D2DrlgStrc* __fastcall DRLGROOM_GetDrlgFromRoomEx(D2DrlgRoomStrc* pRoom);                                   // 0x0066C0B0
int __fastcall DRLG_IsOnClient(D2DrlgStrc* pDrlg);                                                          // 0x00642A00
int __fastcall DRLG_IsTownLevel(int nLevelId);                                                              // 0x006426A0

// 0x0061AB70
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct)
{
    D2_ASSERT(nAct < 5, 0x59A);
    return gnTownLevelIds_006E7D1C[nAct];
}

// 0x0061AEB0
int __stdcall DUNGEON_GetHoradricStaffTombLevelId(D2DrlgActStrc* pAct)
{
    if (pAct)
        return DRLG_GetHoradricStaffTombLevelId(pAct->pDrlg);
    return 0;
}

// 0x0061B730
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_InitializeRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!(pDrlgRoom->dwFlags & DRLGROOMFLAG_TILELIB_LOADED))
        DRLGROOMTILE_LoadDT1FilesForRoom(pDrlgRoom);

    if (!(pDrlgRoom->dwFlags & DRLGROOMFLAG_PRESET_UNITS_ADDED) && pDrlgRoom->nType == DRLGTYPE_PRESET)
        DRLGPRESET_SpawnHardcodedPresetUnits(pDrlgRoom);

    if (!(pDrlgRoom->dwFlags & DRLGROOMFLAG_HAS_ROOM))
    {
        D2DrlgStrc* pDrlg = pDrlgRoom->pLevel->pDrlg;
        if (!pDrlgRoom->nRoomsNear)
            DRLGROOM_InitNearRooms(pDrlg->pMempool, pDrlgRoom);

        DRLGROOMTILE_InitRoomGrids(pDrlgRoom);
        DRLGROOMTILE_AddRoomMapTiles(pDrlgRoom);
        DRLG_CreateRoomForRoomEx(pDrlg, pDrlgRoom);
        ++pDrlg->nRoomsInitSinceLastUpdate;
        ++pDrlg->nAllocatedRooms;
    }
    return pDrlgRoom->pRoom;
}

// 0x0061BA30
int __fastcall DRLGACTIVATE_TestRoomCanUnTile(D2DrlgRoomStrc* pDrlgRoom)
{
    if (pDrlgRoom->dwFlags & DRLGROOMFLAG_HASPORTAL)
        return 0;

    D2_ASSERT(!DRLG_IsOnClient(DRLGROOM_GetDrlgFromRoomEx(pDrlgRoom)), 0x2E7);

    if (pDrlgRoom->fRoomStatus <= 1)
        return 0;

    int nLevelId = pDrlgRoom->pLevel->nLevelId;
    if (DRLG_IsTownLevel(nLevelId) || nLevelId == LEVEL_ROCKYSUMMIT)
    {
        for (D2DrlgRoomStrc* pCurrentRoomEx = pDrlgRoom->pLevel->pFirstRoomEx; pCurrentRoomEx; pCurrentRoomEx = pCurrentRoomEx->pDrlgRoomNext)
        {
            if (pCurrentRoomEx->fRoomStatus <= 1)
                return 0;
        }
    }
    return 1;
}

// 0x0061BEC0
void __fastcall ENVIRONMENT_FreeDrlgEnvironment(void* pMemPool, D2DrlgEnvironmentStrc* pEnvironment)
{
    FOG_FreePool(pMemPool, pEnvironment, ".\\ENVIRONMENT\\Env.cpp", 0x13F, 0);
}

#include "gen/data/Source/D2Common/0061AB70_DUNGEON_GetTownLevelIdFromActNo.inc"
