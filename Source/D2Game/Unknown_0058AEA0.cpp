#include "D2Game.h"
#include "D2GameStrc.h"

struct D2PlayerDataStrc;


struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
    D2WaypointDataStrc* pWaypointData[3];
};

enum D2C_M54A5Q4Constants
{
    QUEST_A5Q4_NIHLATHAK = 34,
    QUESTSTATEFLAG_A5Q4 = 38,
    QFLAG_REWARDGRANTED = 0,
    QFLAG_PRIMARYGOALDONE = 13,
    QFLAG_COMPLETEDNOW = 14,
    QFLAG_COMPLETEDBEFORE = 15,
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId); // 0x00544190

struct D2QuestDataStrc { char unknown0[9]; unsigned char notIntro, active, lastState, state; };

// 0x0058AEA0
int __fastcall ACT5Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A5Q4_NIHLATHAK);
    }

    return 0;
}

// 0x0058AF00
bool __fastcall sub_0058AF00_GetQuestStatus(D2QuestDataStrc* quest, D2UnitStrc* unit, D2BitBufferStrc* globalFlags, D2BitBufferStrc* flags, unsigned char* status)
{
    *status = 0;
    if (QUESTRECORD_GetQuestState(flags, 38, 0)) return true;
    if (QUESTRECORD_GetQuestState(flags, 38, 1) || QUESTRECORD_GetQuestState(flags, 38, 13)) {
        *status = QUESTRECORD_GetQuestState(flags, 38, 4) != 0 ? 5 : 4;
    } else if (quest->notIntro) {
        if (QUESTRECORD_GetQuestState(flags, 38, 14)) { *status = 12; return true; }
        if (quest->state < 4) { *status = quest->lastState; return true; }
    }
    return true;
}
