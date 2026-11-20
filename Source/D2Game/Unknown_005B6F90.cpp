#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"

struct D2Act3Quest0Strc;
struct D2Act3Quest1Strc;
struct D2ObjInitFnStrc;






D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

// 0x005B6F90
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

// 0x005B7120
int __fastcall sub_005B7120_GetHratliEndCoords(D2GameStrc* pGame, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 14);
    if (!pQuestData)
    {
        return 0;
    }
    D2Act3Quest0Strc* pQuestDataEx = (D2Act3Quest0Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bHratliEndObjectInitialized != 1 || !pQuestDataEx->bHratliStartIsPresent)
    {
        return 0;
    }
    pCoord->nX = pQuestDataEx->nHratliX;
    pCoord->nY = pQuestDataEx->nHratliY;
    return 1;
}

// 0x005B7310
void __fastcall sub_005B7310(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    if (!pQuestData)
    {
        return;
    }
    if (!pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, ((D2Act3Quest1Strc*)pQuestData->pQuestDataEx)->nTomeObjectMode);
    }
}

// 0x005B7FE0
void __cdecl sub_005B7FE0_Nop()
{
}
