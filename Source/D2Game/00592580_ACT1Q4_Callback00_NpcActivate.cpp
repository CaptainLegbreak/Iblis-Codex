struct D2BitBufferStrc;
struct D2TextHeaderStrc;
struct D2GameStrc { char unk_00[0x6D]; unsigned char nDifficulty; };
struct D2UnitStrc { int dwUnitType; int dwClassId; int pMemoryPool; int dwUnitId; };
struct D2PlayerDataStrc { char unk_00[0x10]; D2BitBufferStrc* pQuestData[3]; };
struct D2QuestGUIDStrc { unsigned int nPlayerGUIDs[32]; unsigned short nPlayerCount; unsigned char pad[2]; };
struct D2Act1Quest4Strc { char unk_00[0x4F]; unsigned char bOperatedWithLastCairnStone; char unk_50[0x2C]; int nScrolls; char unk_80[0x34]; D2QuestGUIDStrc pQuestGUID; D2QuestGUIDStrc tPlayerGUIDs; };
struct D2QuestDataStrc { char unk_00[0xC]; unsigned char fState; char unk_0D[0xB]; D2Act1Quest4Strc* pQuestDataEx; };
struct D2QuestArgStrc { D2GameStrc* pGame; int nEvent; D2UnitStrc* pTarget; D2UnitStrc* pPlayer; int unk_10; D2TextHeaderStrc* pTextControl; };
extern const int gnA1Q4MessageIndices[]; // 0x00737648
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode); // 0x00558110
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pText, int nNpc, int nMessage); // 0x00543790
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode); // 0x00544160
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pFlags, int nQuest, int nState); // 0x0065C310
int __fastcall QUESTS_QuickCheckPlayerGUID(D2QuestGUIDStrc* pGuids, int nId); // 0x00545290
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int nId); // 0x005452C0
__forceinline int GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwUnitId;
}
// 0x00592580
void __fastcall ACT1Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg)
{
    D2UnitStrc* pScroll = ITEMS_FindQuestItem(pArg->pGame, pArg->pPlayer, ' skb');
    int nNpc;
    if (!pArg->pTarget) nNpc = -1;
    else nNpc = pArg->pTarget->dwClassId;
    D2UnitStrc* pPlayer = pArg->pPlayer;
    D2GameStrc* pGame = pArg->pGame;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2BitBufferStrc* pFlags = pPlayerData->pQuestData[pGame->nDifficulty];
    D2Act1Quest4Strc* pEx = pQuest->pQuestDataEx;
    if (nNpc == 146) QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, 146, 9);
    if (pEx->bOperatedWithLastCairnStone == 1 && ITEMS_FindQuestItem(pArg->pGame, pArg->pPlayer, ' dkb'))
    {
        QUESTS_DeleteItem(pArg->pGame, pArg->pPlayer, ' dkb');
        --pEx->nScrolls;
    }
    int bRewardPending = QUESTRECORD_GetQuestState(pFlags, 4, 1);
    int bCompletedNow = QUESTRECORD_GetQuestState(pFlags, 4, 13);
    if (nNpc == 265 && !QUESTS_QuickCheckPlayerGUID(&pEx->tPlayerGUIDs, GetUnitId(pArg->pPlayer)) && bCompletedNow)
    {
        QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, 265, 5);
        return;
    }
    if (bRewardPending)
    {
        if (nNpc == 265)
        {
            if (QUESTS_QuickCheckPlayerGUID(&pEx->tPlayerGUIDs, GetUnitId(pArg->pPlayer))) QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, 265, 7);
            else QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, 265, 5);
        }
        else QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpc, 5);
        return;
    }
    if (QUESTS_QuickCheckPlayerGUID(&pEx->pQuestGUID, GetUnitId(pArg->pPlayer)) == 1)
    {
        QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpc, 6);
        return;
    }
    if (QUESTS_CheckPlayerGUID(pQuest, GetUnitId(pArg->pPlayer)) == 1 && nNpc == 265 && !QUESTS_QuickCheckPlayerGUID(&pEx->tPlayerGUIDs, GetUnitId(pArg->pPlayer)))
    {
        QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, 265, 5);
        return;
    }
    if (QUESTS_CheckPlayerGUID(pQuest, GetUnitId(pArg->pPlayer)) == 1)
    {
        if (QUESTRECORD_GetQuestState(pFlags, 4, 14))
        {
            QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpc, 8);
            return;
        }
        if (QUESTRECORD_GetQuestState(pFlags, 4, 0)) QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpc, 7);
        return;
    }
    else if (!QUESTRECORD_GetQuestState(pFlags, 4, 14) && pQuest->fState && QUESTRECORD_GetQuestState(pFlags, 4, 0) != 1 && !QUESTRECORD_GetQuestState(pFlags, 4, 15))
    {
        if (!pScroll && pQuest->fState == 4)
        {
            QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpc, 2);
        }
        else if (pScroll)
        {
            QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpc, 3);
        }
        else if (pQuest->fState < 6)
        {
            int nMessage = gnA1Q4MessageIndices[pQuest->fState];
            if (nMessage != -1 && (unsigned int)nMessage < 11) QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpc, nMessage);
        }
    }
}

#include "gen/data/Source/D2Game/00592580_ACT1Q4_Callback00_NpcActivate.inc"
