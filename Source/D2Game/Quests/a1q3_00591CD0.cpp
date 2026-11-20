#include "D2Game.h"

struct D2Act1Quest3Strc
{
    char unk0x00[0xA0];
    unsigned char bMalusAcquired;
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
    D2Act1Quest3Strc* pQuestDataEx;
};

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

#define STAT_LEVEL 12
#define QUESTSTATEFLAG_A1Q3 3
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                          // 0x00544760
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
void __fastcall ACT1Q3_UnitIterate_CheckForMalus(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);        // 0x00591CA0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x006253B0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

// 0x00591CD0
static int sub_00591CD0_HasHoradricMalus(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer)
{
    if (ITEMS_FindQuestItem(SUNIT_GetGameFromUnit(pPlayer), pPlayer, ' mdh'))
    {
        return 1;
    }

    D2Act1Quest3Strc* pQuestDataEx = pQuest->pQuestDataEx;
    const unsigned short nPartyId = SUNIT_GetPartyId(pPlayer);
    if (nPartyId == 0xFFFF)
    {
        return 0;
    }

    pQuestDataEx->bMalusAcquired = 0;
    PARTY_IteratePartyMembers(pQuest->pGame, nPartyId, ACT1Q3_UnitIterate_CheckForMalus, 0);
    return pQuestDataEx->bMalusAcquired != 0;
}

// 0x00591D30
bool __fastcall ACT1Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDPENDING))
    {
        *pStatus = 10;
        return true;
    }

    if (sub_00591CD0_HasHoradricMalus(pQuest, pPlayer))
    {
        if (!QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDGRANTED))
        {
            *pStatus = 2;
        }
        return true;
    }

    if (!pQuest->bNotIntro)
    {
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q3, QFLAG_PRIMARYGOALDONE))
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDPENDING) ? 10 : 13;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q3, QFLAG_COMPLETEDNOW))
    {
        *pStatus = 12;
        return true;
    }

    if (pQuest->fState < 5)
    {
        *pStatus = pQuest->fLastState;
        return true;
    }

    if (QUESTS_GetGlobalState(pQuest->pGame, QUESTSTATEFLAG_A1Q3, QFLAG_PRIMARYGOALDONE))
    {
        *pStatus = STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0) >= 8 ? 12 : 4;
    }

    return true;
}
