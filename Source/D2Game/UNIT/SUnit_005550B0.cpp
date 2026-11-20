#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

#define D2_ASSERT(expr,line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(),line); exit(-1); }
union D2SeedStrc;
struct D2LvlWarpTxt;



struct D2LvlWarpTxt { char unk0[0x14]; int nOffsetX; int nOffsetY; };

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
D2UnitStrc* __stdcall DUNGEON_GetWarpTileFromRoomAndSourceLevelId(D2ActiveRoomStrc*,int,D2LvlWarpTxt**); // 0x006195A0
int __fastcall sub_0045ADF0(D2UnitStrc*); // 0x0045ADF0
int __fastcall sub_0045AE20(D2UnitStrc*); // 0x0045AE20
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc*); // 0x00620510
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc*,D2CoordStrc*,int,unsigned int,int); // 0x0064E7B0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc*); // 0x0061A1B0
int __fastcall QUESTS_LevelWarpCheck(D2GameStrc*,D2UnitStrc*,int,int); // 0x00545B80
int __fastcall sub_00554EA0_WarpUnit(D2GameStrc*,D2UnitStrc*,D2ActiveRoomStrc*,int,int,int,int); // 0x00554EA0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc*,const char*,int); // 0x005531C0
void __fastcall sub_005809D0_ChangeMode(D2GameStrc*,D2UnitStrc*,D2SkillStrc*,int,int,int,int); // 0x005809D0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc*); // 0x00621F20
void __fastcall sub_0053B4B0(D2ClientStrc*,unsigned char,unsigned char,int,unsigned char,unsigned short,unsigned short,unsigned char,unsigned char); // 0x0053B4B0

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    D2SeedStrc* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    unsigned int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    D2ActiveRoomStrc* pRoom;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int bForce;
    int nQuality;
    int nQuantity;
    int nMinDur;
    int nMaxDur;
    int nItemIndex;
    unsigned int dwFlags1;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    int eEarLvl;
    int nQtyOverride;
    char szName[16];
    int nPrefix[3];
    int nSuffix[3];
    unsigned int dwFlags2;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall sub_0054E600_SpawnPresetMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600
D2UnitStrc* __fastcall sub_0054F490_SpawnPresetObject(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054F490
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
int __fastcall D2GAME_InitItemStats_6FC4E520(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop, int a4); // 0x00557AB0

static __forceinline int GetClassId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwClassId;
}

// 0x005550B0
void __fastcall sub_005550B0_WarpPlayer(D2GameStrc* ptGame,D2UnitStrc* hUnit,D2UnitStrc* pTile)
{
    D2_ASSERT(ptGame,329);
    D2_ASSERT(hUnit,330);
    D2ActiveRoomStrc* pOldRoom = UNITS_GetRoom(pTile);
    int nLevel = GetClassId(pTile);
    D2LvlWarpTxt* pWarp;
    D2UnitStrc* pDestination = DUNGEON_GetWarpTileFromRoomAndSourceLevelId(pOldRoom,nLevel,&pWarp);
    if (!pDestination) return;
    D2ActiveRoomStrc* pTargetRoom = UNITS_GetRoom(pDestination);
    D2CoordStrc point;
    point.nX = sub_0045ADF0(pDestination);
    point.nY = sub_0045AE20(pDestination);
    D2_ASSERT(hUnit->dwUnitType == 0,348);
    D2ActiveRoomStrc* pFreeRoom = COLLISION_GetFreeCoordinates(pTargetRoom,&point,UNITS_GetUnitSizeX(hUnit),0x1C09,1);
    if (!pFreeRoom) return;
    int nOldLevel = DUNGEON_GetLevelIdFromRoom(pOldRoom);
    int nNewLevel = DUNGEON_GetLevelIdFromRoom(pFreeRoom);
    if (nNewLevel == 73 || nNewLevel == 128 || nNewLevel == 132 || nNewLevel == 118 || nNewLevel == 100)
        if (QUESTS_LevelWarpCheck(ptGame,hUnit,nOldLevel,nNewLevel)) return;
    int nX = point.nX;
    int nY = point.nY;
    if (sub_00554EA0_WarpUnit(ptGame,hUnit,pTargetRoom,nX,nY,0,0))
    {
        D2ClientStrc* pClient = UnitGetClient(hUnit,".\\UNIT\\SUnit.cpp",376);
        int nDestX = pWarp->nOffsetX + nX;
        int nDestY = pWarp->nOffsetY + nY;
        sub_005809D0_ChangeMode(ptGame,hUnit,0,2,nDestX,nDestY,0);
        unsigned char nLife = UNITS_GetCurrentLifePercentage(hUnit);
        sub_0053B4B0(pClient,0x0D,!hUnit ? 6 : hUnit->dwUnitType,!hUnit ? -1 : hUnit->dwUnitId,1,nDestX,nDestY,0,nLife);
    }
}

// 0x005557D0
D2UnitStrc* __fastcall SUNIT_CreatePresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId, int nX, int nY, int nMode, int nUnitFlags)
{
    D2UnitStrc* pUnit = 0;

    switch (nUnitType)
    {
    case 2:
        if (nClassId > 573)
        {
            pUnit = sub_0054F490_SpawnPresetObject(pGame, pRoom, nClassId, nX, nY, nMode);
            break;
        }
        if (nClassId == 573)
        {
            return 0;
        }

    default:
        pUnit = SUNIT_AllocUnitData(nUnitType, nClassId, nX, nY, pGame, pRoom, 1, nMode, 0);
        if (nUnitType == 4 && pUnit)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));
            itemDrop.nQuality = 2;
            itemDrop.nItemLvl = DUNGEON_GetLevelIdFromRoom(pRoom);
            if (!D2GAME_InitItemStats_6FC4E520(pGame, &pUnit, &itemDrop, 1))
            {
                SUNIT_RemoveUnit(pGame, pUnit);
                return 0;
            }
        }
        if (pUnit)
        {
            pUnit->dwFlags |= 0x3000000;
        }
        return pUnit;

    case 1:
        pUnit = sub_0054E600_SpawnPresetMonster(pGame, pRoom, nClassId, nX, nY, nMode);
        break;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x3000000;
    }

    return pUnit;
}
