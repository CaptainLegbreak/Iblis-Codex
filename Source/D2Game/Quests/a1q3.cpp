#include "D2Game.h"

struct D2PlayerDataStrc;
struct D2Act1Quest3Strc;
struct D2Act1Quest3ExStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
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
    unsigned char nFlags;
    unsigned char unk0x15[3];
    union
    {
        void* pQuestDataEx;
        D2Act1Quest3ExStrc* data;
    };
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

extern "C" const unsigned int gnAct1Quest3NpcIndices[]; // 0x00737630
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
int __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int dwCode); // 0x00558110
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

struct D2Act1Quest3Strc
{
    unsigned char unk0x00;
    unsigned char bMalusInitialized;
    unsigned char bCharsiIntroActivated;
    unsigned char bCharsiEndActivated;
    int nMalusGUID;
    unsigned char unk0x08;
    char unk0x09[0x8F];
    int nMalusObjectMode;
    int nMalusItemsInGame;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __fastcall ACT1Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005912E0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

struct D2Act1Quest3ExStrc { unsigned char padding[0xA0]; unsigned char malusFound; };
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* game, int questId); // 0x00543640

// 0x005916A0
void __fastcall ACT1Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg)
{
    D2UnitStrc* pPlayer = pArg->pPlayer;
    D2GameStrc* pGame = pArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, 3, 0xD);
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, 3, 0);
    const int nNpcId = !pArg->pTarget ? -1 : pArg->pTarget->dwClassId;
    if (bRewardGranted == 1 && !bPrimaryGoalDone)
    {
        return;
    }

    if (ITEMS_FindQuestItem(pArg->pGame, pArg->pPlayer, 0x206D6468))
    {
        if (STATLIST_GetUnitBaseStat(pArg->pPlayer, 0xC, 0) >= 8 && !QUESTRECORD_GetQuestState(pQuestFlags, 3, 0))
        {
            QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpcId, 3);
        }
    }
    else if (bRewardGranted != 1)
    {
        if (!pQuest->fState || pQuest->fState == 4)
        {
            return;
        }

        const unsigned int nIndex = gnAct1Quest3NpcIndices[pQuest->fState];
        if (nIndex != -1 && nIndex < 6)
        {
            QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpcId, nIndex);
        }
    }
}

#include "gen/data/Source/D2Game/Quests/a1q3.inc"

// 0x005918D0
static __declspec(noinline) bool sub_005918D0_ResetMalus(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->bNotIntro)
    {
        return false;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->nMalusObjectMode = 0;
    if (!pQuestDataEx->bMalusInitialized)
    {
        return false;
    }

    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", 0x1C8);
    pQuestData->nFlags = 1;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q3_UnitIterate_StatusCyclerEx, true);
    pQuestDataEx->unk0x08 = 0;
    if (pQuestDataEx->bMalusInitialized == 1)
    {
        D2UnitStrc* pMalus = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nMalusGUID);
        if (pMalus && pMalus->dwClassId == 0x6C)
        {
            UNITS_ChangeAnimMode(pMalus, 0);
            return true;
        }

        pQuestDataEx->bMalusInitialized = 0;
    }

    return true;
}

// 0x00591A90
void __fastcall ACT1Q3_Callback06_MalusRemoved(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    --pQuestDataEx->nMalusItemsInGame;
    if (!pQuestDataEx->nMalusItemsInGame && pQuestDataEx->nMalusObjectMode == 2)
    {
        sub_005918D0_ResetMalus(pQuestData);
    }
}

// 0x00591CA0
void __fastcall ACT1Q3_UnitIterate_CheckForMalus(D2GameStrc* game, D2UnitStrc* unit, void* unused)
{
    if (ITEMS_FindQuestItem(game, unit, 0x206D6468))
    {
        D2QuestDataStrc* quest = QUESTS_GetQuestData(game, 3);
        if (quest)
            quest->data->malusFound = 1;
    }
}
