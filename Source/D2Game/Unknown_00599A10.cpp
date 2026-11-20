#include "D2Game.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#define QFLAG_PRIMARYGOALDONE 13



struct D2Act3Quest5Strc
{
    int nLastKilledMonsterGUID;
    unsigned char bOrmusActivated;
    unsigned char bMonstersSpawned;
    unsigned char pad0x06[2];
    int bQuest1RewardGranted;
    unsigned char bOrbSmashed;
    unsigned char bFlailDropped;
    unsigned char bCubeDropped;
    unsigned char pad0x0F;
    int nMonsterGUIDs[6];
    unsigned char bCompellingOrbSpawned;
    unsigned char pad0x29[3];
    int nCompellingOrbGUID;
    int nSpawnCount;
    int nMonstersLeftToKill;
};

typedef int (__fastcall* QUESTITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" const char gszAct3Q5SourceFile[];
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTITERATE pfIterate, bool bIterate);
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestState, int nFlag);
void __fastcall QUESTS_RemovePlayerGUID(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);            // 0x00545530
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nUnitType, void* pData, QUESTITERATE pfnCallback);
int __fastcall ACT3Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

// 0x00599A10
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);
}

void __fastcall ACT3Q5_SpawnCouncil(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q5_TRAVINCAL);
    if (!pQuestData || !pQuestData->bNotIntro)
        return;

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bMonstersSpawned = 1;
    if (pQuestDataEx->nSpawnCount >= 6)
        return;

    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;

    for (int i = 0; i < pQuestDataEx->nSpawnCount; ++i)
    {
        if (pQuestDataEx->nMonsterGUIDs[i] == nUnitId)
            return;
    }

    pQuestDataEx->nMonsterGUIDs[pQuestDataEx->nSpawnCount] = nUnitId;
    ++pQuestDataEx->nSpawnCount;
    pQuestDataEx->nMonstersLeftToKill = pQuestDataEx->nSpawnCount;

    if (pQuestData->fState <= 1)
    {
        if (pQuestData->fLastState != 1)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q5_UnitIterate_StatusCyclerEx, 1);
        }
    }
    else
    {
        if (pQuestData->fLastState != 3)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q5_UnitIterate_StatusCyclerEx, 1);
        }
    }

    if (QUESTS_GetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A3Q1, QFLAG_PRIMARYGOALDONE) == 1)
        QUESTS_StateDebug(pQuestData, 4, gszAct3Q5SourceFile, 630);
    else
        QUESTS_StateDebug(pQuestData, 5, gszAct3Q5SourceFile, 634);

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_UpdateQuestStateFlags);
}
