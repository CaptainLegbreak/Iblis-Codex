#include "D2Game.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall ACT3Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B8BF0
int __fastcall ACT3Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B8B20

// 0x005B8C50
void __fastcall sub_005B8C50_QuestCallback(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg)
{
    const int nClassId = !pArg->pTarget ? -1 : pArg->pTarget->dwClassId;
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuest->pQuestDataEx;
    if ((unsigned short)nClassId == 0xFD)
    {
        if (pQuestDataEx->bHratliActivated == 1)
        {
            pQuest->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuest, 2, 0, ACT3Q3_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bHratliActivated = 0;
            SUNIT_IterateUnitsOfType(pQuest->pGame, 0, 0, ACT3Q3_UnitIterate_UpdateQuestStateFlags);
        }
    }
    else if ((unsigned short)nClassId == 0xFF && pQuestDataEx->bGidbinnBroughtToOrmus)
    {
        pQuestDataEx->bGidbinnBroughtToOrmus = 0;
        pQuestDataEx->bAltarCanBeActivated = 1;
    }
}
