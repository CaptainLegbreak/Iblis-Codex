#include "D2MissileIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"

struct D2StaticPathStrc;
struct D2MissileStrc;
union D2SeedStrc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;





extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __fastcall sub_004DCD40_ShowTimedHint(void* pOwner, int nDelayA, int nDelayC, unsigned int nIndex, int nArgE, int nDelayF, int nArgG); // 0x004DCD40
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
D2UnitStrc* __stdcall sub_0065A620_FindUnitInAdjacentRooms(D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId); // 0x0065A620





D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* room, int x, int y); // 0x00463740
D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg); // 0x00466730
extern D2DataTablesStrc* sgptDataTables; // 0x00744304

static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    int nResult;
    switch (pUnit->dwUnitType)
    {
    default:
        if (pUnit->pDynamicPath) nResult = PATH_GetXPosition(pUnit->pDynamicPath); else nResult = 0;
        break;
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nResult = pUnit->pStaticPath->nXPos;
        break;
    }
    return nResult;
}

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    int nResult;
    switch (pUnit->dwUnitType)
    {
    default:
        if (pUnit->pDynamicPath) nResult = PATH_GetYPosition(pUnit->pDynamicPath); else nResult = 0;
        break;
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nResult = pUnit->pStaticPath->nYPos;
        break;
    }
    return nResult;
}

// 0x0046B850
void __fastcall sub_0046B850_SpawnMissileAtObject182(D2UnitStrc* unit)
{
 D2UnitStrc* object=sub_0065A620_FindUnitInAdjacentRooms(UNITS_GetRoom(unit),2,0x182);
 int x,y;
 if(object) {
  sub_004DCD40_ShowTimedHint((void*)0x124F,0,0x15E,0,0,0,0);
  x=CLIENTS_GetUnitXInline(object);
  y=CLIENTS_GetUnitYInline(object);
 } else {
  x=CLIENTS_GetUnitXInline(unit)-15;
  y=CLIENTS_GetUnitYInline(unit)-15;
 }
 D2MissileStrc params;
 memset(&params,0,sizeof(params));
 params.dwFlags=0x420;
 params.nMissile=MISSILE_ORBMIST;
 params.pOwner=unit;
 params.pOrigin=unit;
 params.nTargetX=x;
 params.nTargetY=y;
 params.nSkillLevel=1;
 D2UnitStrc* missile=sub_004CD540_CreateMissile(&params);
 if(missile&&object)MISSILE_SetTargetX(missile,object->dwUnitId);
}

static inline D2MonStats2Txt* GetMonStats2(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nEx >= 0 && nEx < sgptDataTables->nMonStats2TxtRecordCount)
            return &sgptDataTables->pMonStats2Txt[nEx];
    }
    return 0;
}

// 0x0046C320
void __fastcall sub_0046C320_SpawnAroundUnit(D2UnitStrc* pUnit, int nMonsterId, int nCount)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2MonStats2Txt* pTxt = GetMonStats2(nMonsterId);
    if (!pTxt)
        return;

    D2CoordStrc tCoord;
    UNITS_GetCoords(pUnit, &tCoord);
    for (int i = 0; i < 10; ++i)
    {
        unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
        pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
        const int nX = tCoord.nX + (unsigned int)lSeed % 5 - 2;
        lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
        pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
        const int nY = tCoord.nY + (unsigned int)lSeed % 5 - 2;
        pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
        if (!COLLISION_CheckMaskWithSize(pRoom, nX, nY, pTxt->nSizeX, 0x3F11))
        {
            sub_00466730_SpawnPresetUnit(nMonsterId, nX, nY, 1, 0);
            --nCount;
        }
        if (nCount <= 0)
            break;
    }
}
