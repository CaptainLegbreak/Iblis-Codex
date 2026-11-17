struct D2BitBufferStrc;
struct D2TextHeaderStrc;

struct D2GameStrc
{
    char pad0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
};

struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
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
};

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

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                          // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);             // 0x0065C310
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);   // 0x00558110
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID);                                  // 0x005452C0
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

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
