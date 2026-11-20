#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2QuestData.h"


D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                          // 0x005DC5C0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

#define QUESTSTATEFLAG_A2Q6 14
#define QUEST_A2Q4_HORAZONTOME 11
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1

// 0x0059B820
int __fastcall ACT2Q4_UnitIterate_CheckDistanceToHaremBlocker(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)QUESTS_GetQuestData(pGame, QUEST_A2Q4_HORAZONTOME)->pQuestDataEx;

    if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pQuestDataEx->pHaremBlockerCoords.nX, pQuestDataEx->pHaremBlockerCoords.nY) > 30)
    {
        return 0;
    }

    pQuestDataEx->bPlayerCloseToHaremBlocker = 1;
    pQuestDataEx->nPlayerCloseToHaremBlockerGUID = !pUnit ? -1 : pUnit->dwUnitId;
    return 1;
}
