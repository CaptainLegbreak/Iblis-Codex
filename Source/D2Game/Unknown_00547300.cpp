#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameServer.h"
#include "D2GameObjs.h"
#include "D2ItemsWorld.h"

struct D2ObjectControlStrc;
struct Entry00547390;
struct Sub00547390;
struct Obj00547390;
struct D2MonRegDataStrc;
struct D2MonsterRegionStrc;
struct D2ObjOperateFnStrc;

struct Entry00547390 { unsigned int dwUnknown00[4]; int nCount10; };

struct Sub00547390 { unsigned char bUnknown00[0x48]; Entry00547390* pEntries48[1]; };

struct Obj00547390 { unsigned char bUnknown00[0x10F0]; Sub00547390* pSub10F0; };

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

enum
{
    ACT_II = 1,
};

// 0x00547300
bool __fastcall OBJRGN_CanNotSpawnMoreWells(D2GameStrc* pGame, int nLevelId)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nWells == 4 || pObjectRegion->nWells > pObjectRegion->nPopulatedRooms / 8)
    {
        return true;
    }
    return false;
}

// 0x00547330
bool __fastcall OBJRGN_ShouldSpawnHealingShrineOrWell(D2GameStrc* pGame, int nLevelId)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nPopulatedRooms > 0 && (pObjectRegion->nProcessedRooms << 7) / pObjectRegion->nPopulatedRooms > 96 && !pObjectRegion->nHealingShrines)
    {
        return true;
    }
    return false;
}

// 0x00547360
bool __fastcall OBJRGN_CanNotSpawnMoreShrines(D2GameStrc* pGame, int nLevelId)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nShrines == 10 || pObjectRegion->nShrines > pObjectRegion->nPopulatedRooms / 8)
    {
        return true;
    }
    return false;
}

// 0x00547390
extern "C" __declspec(dllexport) void __fastcall sub_00547390(Obj00547390* pObj, int nIndex) {
    pObj->pSub10F0->pEntries48[nIndex]->nCount10++;
}
