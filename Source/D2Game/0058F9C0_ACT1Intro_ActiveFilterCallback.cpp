struct D2BitBufferStrc;
struct D2UnitStrc;

struct D2GameStrc
{
    char pad0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char pad0x08[0x01];
    unsigned char bNotIntro;
    char pad0x0A[0x02];
    unsigned char fState;
    char pad0x0D[0x0B];
    void* pQuestDataEx;
};

struct D2Act2Quest4Strc
{
    char pad0x00[0x40];
    unsigned short nHaremBlockerObjectMode;
    char pad0x42[0x04];
    unsigned char bIsHaremBlockerNeutral;
};

int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId);                // 0x005723C0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

#define MONSTER_AKARA 148
#define MONSTER_DROGNAN 177
#define MONSTER_JERHYN 201
#define MONSTER_ACT2GUARD2 331
#define MONSTER_ACT2GUARD4 377
#define QUESTSTATEFLAG_A1Q1 1
#define QUESTSTATEFLAG_A2Q1 9
#define QUESTSTATEFLAG_A2Q4 12
#define QUESTSTATEFLAG_A2Q7 30
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_CUSTOM3 7
#define QFLAG_CUSTOM4 8
#define QFLAG_PRIMARYGOALDONE 13
#define OBJMODE_OPENED 2

// 0x0058F9C0
bool __fastcall ACT1Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    D2GameStrc* pGame = pQuest->pGame;
    D2BitBufferStrc* pPlayerQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pPlayerQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDGRANTED) != 1
        && nNpcId == MONSTER_AKARA
        && !PLRINTRO_GetQuestIntroFlag(pPlayer, pQuest->pGame, MONSTER_AKARA))
    {
        return true;
    }

    return false;
}

// 0x0059ACA0
bool __fastcall ACT2Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED) == 1)
    {
        return false;
    }

    if (nNpcId == MONSTER_ACT2GUARD2)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING) == 1)
        {
            return false;
        }

        D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuest->pQuestDataEx;
        switch (pQuestDataEx->nHaremBlockerObjectMode)
        {
        case OBJMODE_OPENED:
            if (pQuestDataEx->bIsHaremBlockerNeutral && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM4))
            {
                return true;
            }
            break;

        case 0:
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM3))
            {
                return true;
            }
            break;
        }
    }
    else if (nNpcId == MONSTER_DROGNAN)
    {
        if (pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING)
            && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED))
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_JERHYN)
    {
        if (pQuest->fState == 2 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING)
            && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED))
        {
            return true;
        }
    }

    return false;
}

// 0x0059E2C0
bool __fastcall ACT2Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_ACT2GUARD4)
    {
        D2GameStrc* pGame = pQuest->pGame;
        D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q7, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q7, QFLAG_PRIMARYGOALDONE))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q1, QFLAG_PRIMARYGOALDONE) == 1 && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q7, QFLAG_REWARDGRANTED))
        {
            return true;
        }
    }

    return false;
}
