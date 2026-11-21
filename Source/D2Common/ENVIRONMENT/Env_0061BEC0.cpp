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

// 0x0061BEC0
void __fastcall ENVIRONMENT_FreeDrlgEnvironment(void* pMemPool, D2DrlgEnvironmentStrc* pEnvironment)
{
    FOG_FreePool(pMemPool, pEnvironment, ".\\ENVIRONMENT\\Env.cpp", 0x13F, 0);
}
