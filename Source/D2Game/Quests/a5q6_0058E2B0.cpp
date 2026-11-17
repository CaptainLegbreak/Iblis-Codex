#include "D2Game.h"

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
    void* pQuestDataEx;
    char unk0x1C[0xC4];
    int nQuestFilter;
};

struct D2Act5Quest5Strc
{
    char unk0x00[0x44];
    int nAncientsAlive;
    unsigned char bAncientsActivated;
};

struct D2Act5Quest6Strc
{
    char unk0x00[0x90];
    unsigned char bQuestStarted;
};

#define QUEST_A5Q5_ANCIENTS 35
#define QUESTSTATEFLAG_A5Q6 40
#define QFLAG_REWARDGRANTED 0
#define QFLAG_ENTERAREA 4
#define QFLAG_CUSTOM1 5
#define QFLAG_CUSTOM2 6
#define QFLAG_CUSTOM3 7
#define QFLAG_CUSTOM4 8
#define QFLAG_CUSTOM5 9
#define QFLAG_CUSTOM6 10
#define MONSTER_LARZUK 511
#define MONSTER_DREHYA 512
#define MONSTER_MALAH 513
#define MONSTER_QUAL_KEHK 515
#define MONSTER_CAIN6 520
#define MONSTER_TYRAEL3 521
#define MONSTER_ANCIENTSTATUE1 537
#define MONSTER_ANCIENTSTATUE3 539

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

// 0x0058E2B0
bool __fastcall ACT5Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId >= MONSTER_ANCIENTSTATUE1 && nNpcId <= MONSTER_ANCIENTSTATUE3)
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuest->pGame, QUEST_A5Q5_ANCIENTS);
        if (pQuestData)
        {
            D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
            if (pQuestDataEx->bAncientsActivated && !pQuestDataEx->nAncientsAlive && pQuest->fState == 1 && !((D2Act5Quest6Strc*)pQuest->pQuestDataEx)->bQuestStarted)
            {
                return true;
            }
        }
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_REWARDGRANTED))
    {
        return false;
    }

    switch (nNpcId)
    {
    case MONSTER_LARZUK:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_ENTERAREA))
        {
            return true;
        }
        break;

    case MONSTER_CAIN6:
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM6))
        {
            break;
        }
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM1))
        {
            return true;
        }
        break;

    case MONSTER_MALAH:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM2))
        {
            return true;
        }
        break;

    case MONSTER_TYRAEL3:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM3))
        {
            return true;
        }
        break;

    case MONSTER_QUAL_KEHK:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM4))
        {
            return true;
        }
        break;

    case MONSTER_DREHYA:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM5))
        {
            return true;
        }
        break;

    default:
        break;
    }

    return false;
}
