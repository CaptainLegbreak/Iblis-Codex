#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

#define QUEST_A2Q2_HORADRICSTAFF 9
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
struct D2PlayerDataStrc;
struct D2ItemsTxt;



struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2ItemsTxt
{
    char pad0x00[0x80];
    unsigned int dwCode;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    D2TextHeaderStrc* pTextControl;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId); // 0x00544190
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

enum D2C_M11A2Q2Constants
{
    MONSTER_CAIN2 = 244,
    QUESTSTATEFLAG_A2Q2 = 10,
    QFLAG_REWARDGRANTED = 0,
    QFLAG_REWARDPENDING = 1,
    QFLAG_LEAVETOWN = 3,
    QFLAG_ENTERAREA = 4,
    QFLAG_CUSTOM1 = 5,
    QFLAG_CUSTOM2 = 6,
    QFLAG_CUSTOM6 = 10,
    QFLAG_PRIMARYGOALDONE = 13,
};

D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

// 0x00599510
static int __stdcall sub_00599510(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_COMPLETEDNOW))
    {
        return 1;
    }

    return 0;
}

// 0x00599570
static int sub_00599570_ACT2Q2_CycleStatusIfDone(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (sub_00599510(pGame, pPlayer))
    {
        QUESTS_StatusCyclerEx(pGame, pPlayer, QUEST_A2Q2_HORADRICSTAFF);
    }

    return 0;
}

void __fastcall ACT2Q2_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nItemId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bLeftTown = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN);

    pQuestData->dwFlags &= 0xFFFFFF00;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pQuestArg->pPlayer);
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (pQuestData->nActNo == DRLG_GetActNoFromLevelId(nLevelId))
    {
        sub_00599510(pQuestArg->pGame, pQuestArg->pPlayer);
    }

    if (pItemsTxtRecord->dwCode == ' 1rt' && !bLeftTown)
    {
        pQuestData->fLastState = 1;
        sub_00599570_ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
    }
    else if (pItemsTxtRecord->dwCode == ' piv')
    {
        if (bLeftTown)
        {
            pQuestData->fLastState = 2;
            sub_00599570_ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
        else
        {
            pQuestData->fLastState = 6;
            sub_00599570_ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
    }
    else if (pItemsTxtRecord->dwCode == ' xob')
    {
        if (bLeftTown)
        {
            pQuestData->fLastState = 2;
            sub_00599570_ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
        else
        {
            pQuestData->fLastState = 6;
            sub_00599570_ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
    }
    else if (pItemsTxtRecord->dwCode == ' fsm')
    {
        if (bLeftTown)
        {
            pQuestData->fLastState = 2;
            sub_00599570_ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
        else
        {
            pQuestData->fLastState = 6;
            sub_00599570_ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
    }
}

// 0x00599590
static bool __stdcall ACT2Q2_CheckItemsAndState(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit, unsigned char* pData)
{
    *pData = 0xFF;

    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (ITEMS_FindQuestItem(pQuestData->pGame, pUnit, ' tsh'))
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM6))
        {
            *pData = 4;
            return true;
        }
        else
        {
            *pData = 5;
            return false;
        }
    }
    else
    {
        if (ITEMS_FindQuestItem(pQuestData->pGame, pUnit, ' xob'))
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM2))
            {
                *pData = 3;
                return true;
            }
            *pData = 9;
        }

        if (ITEMS_FindQuestItem(pQuestData->pGame, pUnit, ' 1rt'))
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN))
            {
                *pData = 0;
                return true;
            }
            *pData = 6;
        }

        if (ITEMS_FindQuestItem(pQuestData->pGame, pUnit, ' piv'))
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_ENTERAREA))
            {
                *pData = 1;
                return true;
            }
            *pData = 7;
        }

        if (ITEMS_FindQuestItem(pQuestData->pGame, pUnit, ' fsm'))
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM1))
            {
                *pData = 2;
                return true;
            }
            *pData = 8;
        }

        return false;
    }
}

// 0x005996C0
bool __fastcall ACT2Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_CAIN2)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDPENDING) == 1)
        {
            return true;
        }

        unsigned char nData;
        if (ACT2Q2_CheckItemsAndState(pQuest, pPlayer, &nData))
        {
            return true;
        }
    }

    return false;
}

// 0x00599910
void __fastcall ACT2Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int nPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_PRIMARYGOALDONE);
    const int nRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDGRANTED);

    const int nTargetClassId = pQuestArg->pTarget ? pQuestArg->pTarget->dwClassId : -1;
    if (nTargetClassId != MONSTER_CAIN2)
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDPENDING))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_CAIN2, 4);
        return;
    }

    unsigned char nData;
    if (ACT2Q2_CheckItemsAndState(pQuestData, pQuestArg->pPlayer, &nData) && nData != 0xFF)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_CAIN2, nData);
        return;
    }

    if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_CAIN2, 5);
        return;
    }

    if (nRewardGranted == 1)
    {
        if (!nPrimaryGoalDone || nPrimaryGoalDone == 1)
        {
            return;
        }
    }

    if (nData > 9)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN))
        {
            return;
        }

        nData = 6;
    }

    QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_CAIN2, nData);
}
