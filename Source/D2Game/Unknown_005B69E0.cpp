#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

#include "D2GameObjs.h"
#include "D2QuestData.h"
#include "D2UnitData.h"
struct D2ObjOperateFnStrc;
struct D2Act4Quest2Strc;



D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0
int __fastcall OBJECTS_OperateFunction52_DiabloSeal(D2ObjOperateFnStrc* pOp); // 0x005B5630
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

// 0x005B69E0
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    return false;
}

bool __fastcall ACT3Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    return false;
}

void __cdecl sub_005BDB10_Return()
{
}

static int GetAnimMode(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwAnimMode : 0;
}

// 0x005B6AD0
static void sub_005B6AD0_ACT4Q2_SpawnSealObject(D2ObjOperateFnStrc* pOp, D2CoordStrc* pCoord, int nSeal)
{
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pOp->hObject), pCoord->nX, pCoord->nY);
    if (!pRoom)
    {
        return;
    }

    D2ActiveRoomStrc* pNewRoom = 0;
    QUESTS_GetFreePosition(pRoom, pCoord, 3, 0x3F11, &pNewRoom, nSeal == 1 ? 13 : (nSeal == 3 ? 14 : 15), 100);
    if (pNewRoom && SUNIT_AllocUnitData(2, 131, pCoord->nX, pCoord->nY, pOp->pGame, pNewRoom, 1, 0, 0))
    {
        DUNGEON_ToggleHasPortalFlag(pNewRoom, 0);
        OBJECTS_OperateFunction52_DiabloSeal(pOp);
    }
}

// 0x005B6B70
int __fastcall OBJECTS_OperateFunction54_DiabloSeal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (GetAnimMode(pOp->hObject) != 0)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 23);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    D2CoordStrc* pCoord = &pQuestDataEx->pSealCoords[0];
    UNITS_GetCoords(pOp->hObject, pCoord);
    pQuestDataEx->pSealCoords[0].nX -= 12;
    pQuestDataEx->pSealCoords[0].nY -= 52;
    sub_005B6AD0_ACT4Q2_SpawnSealObject(pOp, pCoord, 1);
    return 0;
}

// 0x005B6BC0
int __fastcall OBJECTS_OperateFunction55_DiabloSeal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (GetAnimMode(pOp->hObject) != 0)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 23);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    D2CoordStrc* pCoord = &pQuestDataEx->pSealCoords[1];
    UNITS_GetCoords(pOp->hObject, pCoord);
    pQuestDataEx->pSealCoords[1].nX -= 39;
    pQuestDataEx->pSealCoords[1].nY += 33;
    sub_005B6AD0_ACT4Q2_SpawnSealObject(pOp, pCoord, 3);
    return 0;
}

// 0x005B6C10
int __fastcall OBJECTS_OperateFunction56_DiabloSeal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (GetAnimMode(pOp->hObject) != 0)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 23);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    D2CoordStrc* pCoord = &pQuestDataEx->pSealCoords[2];
    UNITS_GetCoords(pOp->hObject, pCoord);
    pQuestDataEx->pSealCoords[2].nX += 32;
    pQuestDataEx->pSealCoords[2].nY += 16;
    sub_005B6AD0_ACT4Q2_SpawnSealObject(pOp, pCoord, 5);
    return 0;
}
