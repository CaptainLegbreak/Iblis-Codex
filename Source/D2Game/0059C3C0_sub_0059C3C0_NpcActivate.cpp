struct D2BitBufferStrc;
struct D2TextHeaderStrc;
struct D2GameStrc { char unk_00[0x6D]; unsigned char nDifficulty; };
struct D2UnitStrc { int dwUnitType; int dwClassId; int pMemoryPool; int dwUnitId; };
struct D2PlayerDataStrc { char unk_00[0x10]; D2BitBufferStrc* pQuestData[3]; };
struct D2Act2Quest6Strc { char unk_00[0x18]; int nTyraelState; };
struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char f_8[4];
    unsigned char fState;
    char unk_0D[0xB];
    D2Act2Quest6Strc* pQuestDataEx;
};
struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    int unk_10;
    D2TextHeaderStrc* pTextControl;
};
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc*, D2TextHeaderStrc*, int, int); // 0x00543790
int __fastcall QUESTS_GetGlobalState(D2GameStrc*, int, int); // 0x00544760
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc*, int); // 0x005452C0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*, int, int); // 0x0065C310
extern unsigned int gnAct2Quest6DialogIndex_0073B8A8[]; // 0x0073B8A8
// 0x0059C3C0
void __fastcall sub_0059C3C0_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (nNpcId == 251)
    {
        if (pQuestData->pQuestDataEx->nTyraelState == 2)
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
        return;
    }
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 13))
    {
        if (nNpcId == 176 && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 6))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 176, 6);
            return;
        }
        if (nNpcId == 175 && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 7))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 175, 6);
            return;
        }
        if (nNpcId == 177 && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 8))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 177, 6);
            return;
        }
        if (nNpcId == 202 && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 9))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 202, 6);
            return;
        }
        if (nNpcId == 244 && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 10))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 244, 6);
            return;
        }
        if (nNpcId == 178 && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 11))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 178, 6);
            return;
        }
    }
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 3))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        return;
    }
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 4))
    {
        if (nNpcId == 210)
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
        else
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        return;
    }
    if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        return;
    }
    if (!pQuestData->fState)
        return;
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, 14, 0);
    const int bCustom1 = QUESTRECORD_GetQuestState(pQuestFlags, 14, 13);
    if (bRewardGranted == 1 && !bCustom1)
        return;
    const unsigned char nState = pQuestData->fState;
    if (nState >= 4 && !bCustom1)
        return;
    const unsigned int nIndex = gnAct2Quest6DialogIndex_0073B8A8[nState];
    if (gnAct2Quest6DialogIndex_0073B8A8[nState] == 1 && nNpcId == 177)
    {
        if (QUESTS_GetGlobalState(pQuestData->pGame, 12, 13) == 1)
            return;
    }
    else
    {
        if (nIndex == -1 || static_cast<unsigned int>(nIndex) >= 8)
            return;
    }
    QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
}

#include "gen/data/Source/D2Game/0059C3C0_sub_0059C3C0_NpcActivate.inc"
