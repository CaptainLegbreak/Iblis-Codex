#include "D2Common.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2DrlgRooms.h"
#define DRLGROOMFLAG_HAS_ROOM 0x100000
#define DRLGROOMFLAG_HASPORTAL 0x400000
#define DRLGROOMFLAG_TILELIB_LOADED 0x1000000
#define DRLGROOMFLAG_PRESET_UNITS_ADDED 0x2000000
#define DRLGTYPE_PRESET 2
struct D2DrlgEnvironmentStrc;
struct D2DrlgStrc;
struct D2DrlgActStrc;

enum D2C_J07DungeonConstants
{
    UNITFLAGINDEX_ISCLIENTUNIT = 22,
    UNITFLAG_J07_PATHUPDATE = 0x800000,
    UNITFLAGEX_J07_REMOVED = 0x20,
};

void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit); // 0x0064C450
void __fastcall COLLISION_FreeRoomCollisionGrid(void* pMemPool, D2ActiveRoomStrc* pRoom); // 0x0064CA10
void __stdcall DUNGEON_FreeDrlgDelete(D2ActiveRoomStrc* pRoom); // 0x0061A2C0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern const int gnTownLevelIds_006E7D1C[5]; // 0x006E7D1C
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480
int __fastcall DRLG_GetHoradricStaffTombLevelId(D2DrlgStrc* pDrlg); // 0x00642230
void __fastcall DRLGROOMTILE_LoadDT1FilesForRoom(D2DrlgRoomStrc* pDrlgRoom); // 0x0066F240
void __fastcall DRLGROOM_InitNearRooms(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom); // 0x0066C370
void __fastcall DRLGROOMTILE_InitRoomGrids(D2DrlgRoomStrc* pDrlgRoom); // 0x0066EE40
void __fastcall DRLG_CreateRoomForRoomEx(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom); // 0x006422A0
D2DrlgStrc* __fastcall DRLGROOM_GetDrlgFromRoomEx(D2DrlgRoomStrc* pRoom); // 0x0066C0B0
int __fastcall DRLG_IsOnClient(D2DrlgStrc* pDrlg); // 0x00642A00
int __fastcall DRLG_IsTownLevel(int nLevelId); // 0x006426A0

static __forceinline void DUNGEON_GetClientUnitFlag(D2UnitStrc* pUnit, unsigned int dwFlags, int* pResult)
{
    *pResult = pUnit ? (dwFlags >> UNITFLAGINDEX_ISCLIENTUNIT) & 1 : 0;
}

// 0x0061A840
void __fastcall DUNGEON_FreeRoom(void* pMemPool, D2ActiveRoomStrc* pRoom)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pRoom->pUnitFirst)
    {
        const unsigned int dwFlags = pUnit->dwFlags;
        int bClient;
        DUNGEON_GetClientUnitFlag(pUnit, dwFlags, &bClient);
        if (!bClient)
        {
            pUnit->dwFlagEx |= UNITFLAGEX_J07_REMOVED;
        }

        pUnit->dwFlags = dwFlags | UNITFLAG_J07_PATHUPDATE;
        UNITROOM_UpdatePath(pUnit);
    }

    COLLISION_FreeRoomCollisionGrid(pMemPool, pRoom);
    DUNGEON_FreeDrlgDelete(pRoom);

    if (pRoom->ppClients)
    {
        FOG_FreeServerMemory(pRoom->pAct->pMemPool, pRoom->ppClients, ".\\DUNGEON\\Dungeon.cpp", 0x4E2, 0);
    }

    FOG_FreeServerMemory(pMemPool, pRoom->ppRoomList, ".\\DUNGEON\\Dungeon.cpp", 0x4E4, 0);
    FOG_FreeServerMemory(pMemPool, pRoom, ".\\DUNGEON\\Dungeon.cpp", 0x4E5, 0);
}

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

#include "gen/data/Source/D2Common/DUNGEON/Dungeon_0061A840.inc"
