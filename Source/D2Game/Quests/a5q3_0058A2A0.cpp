#include "D2Game.h"

struct D2Act5Quest3Strc
{
    char unk0x00[0xE2];
    unsigned char bDefrostPotionAcquired;
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
    D2Act5Quest3Strc* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    void* pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
};

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

#define QUESTSTATEFLAG_A5Q3 37
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_CUSTOM4 8
#define QFLAG_CUSTOM5 9
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
int __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int dwCode);                       // 0x00558110
void __fastcall ACT5Q3_UnitIterate_CheckForDefrostPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs); // 0x0058A270
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

// 0x0058A2A0
static int sub_0058A2A0_HasDefrostPotion(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer)
{
    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' eci'))
    {
        return 1;
    }

    D2Act5Quest3Strc* pQuestDataEx = pQuest->pQuestDataEx;
    const unsigned short nPartyId = SUNIT_GetPartyId(pPlayer);
    if (nPartyId == 0xFFFF)
    {
        return 0;
    }

    pQuestDataEx->bDefrostPotionAcquired = 0;
    PARTY_IteratePartyMembers(pQuest->pGame, nPartyId, ACT5Q3_UnitIterate_CheckForDefrostPotion, 0);
    return pQuestDataEx->bDefrostPotionAcquired != 0;
}

// 0x0058A300
bool __fastcall ACT5Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDGRANTED))
    {
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDPENDING) || QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q3, QFLAG_PRIMARYGOALDONE))
    {
        if (QUESTRECORD_GetQuestState(pFlags, pQuest->nQuestFilter, QFLAG_CUSTOM4) && !QUESTRECORD_GetQuestState(pFlags, pQuest->nQuestFilter, QFLAG_CUSTOM5))
        {
            *pStatus = 6;
            return true;
        }

        if (!QUESTRECORD_GetQuestState(pFlags, pQuest->nQuestFilter, QFLAG_CUSTOM4))
        {
            *pStatus = 5;
            return true;
        }

        *pStatus = 13;
        return true;
    }

    if (!pQuest->bNotIntro)
    {
        return true;
    }

    if (sub_0058A2A0_HasDefrostPotion(pQuest, pPlayer))
    {
        *pStatus = 4;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q3, QFLAG_COMPLETEDNOW))
    {
        *pStatus = 12;
    }
    else if (pQuest->fState < 5)
    {
        *pStatus = pQuest->fLastState;
    }

    return true;
}
