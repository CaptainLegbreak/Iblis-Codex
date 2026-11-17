struct D2GameStrc;
struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2SkillStrc;
struct D2UnitStrc { unsigned int dwUnitType; int dwClassId; unsigned int dwMemoryPool; int dwUnitId; };
struct D2CoordStrc { int nX; int nY; };
struct D2LvlWarpTxt { char unk0[0x14]; int nOffsetX; int nOffsetY; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr,line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(),line); exit(-1); }
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
D2UnitStrc* __stdcall DUNGEON_GetWarpTileFromRoomAndSourceLevelId(D2ActiveRoomStrc*,int,D2LvlWarpTxt**); // 0x006195A0
int __fastcall sub_0045ADF0(D2UnitStrc*); // 0x0045ADF0
int __fastcall sub_0045AE20(D2UnitStrc*); // 0x0045AE20
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc*); // 0x00620510
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc*,D2CoordStrc*,int,unsigned int,int); // 0x0064E7B0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc*); // 0x0061A1B0
int __fastcall QUESTS_LevelWarpCheck(D2GameStrc*,D2UnitStrc*,int,int); // 0x00545B80
int __fastcall sub_00554EA0_WarpUnit(D2GameStrc*,D2UnitStrc*,D2ActiveRoomStrc*,int,int,int,int); // 0x00554EA0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc*,const char*,int); // 0x005531C0
void __fastcall sub_005809D0_ChangeMode(D2GameStrc*,D2UnitStrc*,D2SkillStrc*,int,int,int,int); // 0x005809D0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc*); // 0x00621F20
void __fastcall sub_0053B4B0(D2ClientStrc*,unsigned char,unsigned char,int,unsigned char,unsigned short,unsigned short,unsigned char,unsigned char); // 0x0053B4B0

static __forceinline int GetClassId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwClassId;
}

// 0x005550B0
void __fastcall sub_005550B0_WarpPlayer(D2GameStrc* pGame,D2UnitStrc* pPlayer,D2UnitStrc* pTile)
{
    D2_ASSERT(pGame,329);
    D2_ASSERT(pPlayer,330);
    D2ActiveRoomStrc* pOldRoom = UNITS_GetRoom(pTile);
    int nLevel = GetClassId(pTile);
    D2LvlWarpTxt* pWarp;
    D2UnitStrc* pDestination = DUNGEON_GetWarpTileFromRoomAndSourceLevelId(pOldRoom,nLevel,&pWarp);
    if (!pDestination) return;
    D2ActiveRoomStrc* pTargetRoom = UNITS_GetRoom(pDestination);
    D2CoordStrc point;
    point.nX = sub_0045ADF0(pDestination);
    point.nY = sub_0045AE20(pDestination);
    D2_ASSERT(pPlayer->dwUnitType == 0,348);
    D2ActiveRoomStrc* pFreeRoom = COLLISION_GetFreeCoordinates(pTargetRoom,&point,UNITS_GetUnitSizeX(pPlayer),0x1C09,1);
    if (!pFreeRoom) return;
    int nOldLevel = DUNGEON_GetLevelIdFromRoom(pOldRoom);
    int nNewLevel = DUNGEON_GetLevelIdFromRoom(pFreeRoom);
    if (nNewLevel == 73 || nNewLevel == 128 || nNewLevel == 132 || nNewLevel == 118 || nNewLevel == 100)
        if (QUESTS_LevelWarpCheck(pGame,pPlayer,nOldLevel,nNewLevel)) return;
    int nX = point.nX;
    int nY = point.nY;
    if (sub_00554EA0_WarpUnit(pGame,pPlayer,pTargetRoom,nX,nY,0,0))
    {
        D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer,".\\UNIT\\SUnit.cpp",376);
        int nDestX = pWarp->nOffsetX + nX;
        int nDestY = pWarp->nOffsetY + nY;
        sub_005809D0_ChangeMode(pGame,pPlayer,0,2,nDestX,nDestY,0);
        unsigned char nLife = UNITS_GetCurrentLifePercentage(pPlayer);
        sub_0053B4B0(pClient,0x0D,!pPlayer ? 6 : pPlayer->dwUnitType,!pPlayer ? -1 : pPlayer->dwUnitId,1,nDestX,nDestY,0,nLife);
    }
}
