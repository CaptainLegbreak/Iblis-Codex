#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
struct D2PlayerDataStrc;
struct D2Act1Quest6Strc;



D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

int __fastcall ACT1Q6_UnitIterate_StatusCyclerEx(D2GameStrc*, D2UnitStrc*, void*); // 0x00595B20
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc*, int, D2UnitStrc*, int (__fastcall*)(D2GameStrc*, D2UnitStrc*, void*), bool); // 0x00544300

// 0x00595B20
int __fastcall ACT1Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 6, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 6, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 6, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 6, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 6);
    }
    return 0;
}

// 0x00595BD0
int __fastcall ACT1Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 6, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 6, 1) == 1)
    {
        return 0;
    }
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 6);
    if (!pQuestData)
    {
        return 0;
    }
    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 6, 2);
    }
    else if (pQuestData->fState == 3)
    {
        if (pQuestData->fLastState == 1)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 6, 3);
        }
        else
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 6, 4);
        }
    }
    return 0;
}

// 0x00595B80
void __fastcall ACT1Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->pTarget && (unsigned short)pQuestArg->pTarget->dwClassId == 265)
    {
        D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bCainActivated == 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q6_UnitIterate_StatusCyclerEx, true);
            pQuestDataEx->bCainActivated = 0;
            pQuestData->pCallback[2] = 0;
        }
    }
}
