#include "D2Game.h"
#include "D2GameTypes.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2MonsterIds.h"
#include "D2LanguageNames.h"

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x005723C0

// 0x00586B50
void __fastcall ACT5Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nPlayerClass = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;

    int nSpecialIntroClass1 = 7;
    int nSpecialIntroClass2 = 7;
    switch (nNpcId)
    {
    case 513:
        nSpecialIntroClass1 = 4;
        nSpecialIntroClass2 = 1;
        break;
    case 514:
        nSpecialIntroClass1 = 6;
        nSpecialIntroClass2 = 2;
        break;
    case 515:
        nSpecialIntroClass1 = 5;
        nSpecialIntroClass2 = 3;
        break;
    case 512:
    case 520:
        break;
    default:
        return;
    }

    if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId))
    {
        return;
    }

    if (nPlayerClass == nSpecialIntroClass1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
    else if (nPlayerClass == nSpecialIntroClass2)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
    }
}

// 0x00586C40
bool __fastcall sub_00586C40_StatusFilterCallback(D2QuestDataStrc* quest, D2UnitStrc* player, D2BitBufferStrc* globalFlags, D2BitBufferStrc* flags, unsigned char* status)
{
    *status = 0;
    return false;
}

// 0x00586C50
bool __fastcall ACT5Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_MALAH && !PLRINTRO_GetQuestIntroFlag(pPlayer, pQuest->pGame, MONSTER_MALAH))
    {
        return true;
    }

    return false;
}

#include "gen/data/Source/D2Game/Unknown_00586B50.inc"
