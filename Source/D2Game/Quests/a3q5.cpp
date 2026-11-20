#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define QFLAG_PRIMARYGOALDONE 13

struct D2PlayerDataStrc;
struct D2ItemsTxt;
struct D2Act3Quest5Strc;
struct D2ActiveRoomStrc;
struct D2GameStrc;
struct D2UnitStrc;
struct D2QuestDataStrc;
struct D2QuestArgStrc;
struct D2Act3Quest2Strc;

typedef int (__stdcall* FARPROC)();

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};




typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuest);

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);


struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    int nOldLevel;
    int nNewLevel;
};


struct D2Act3Quest5Strc
{
    int nLastKilledMonsterGUID;
    unsigned char bOrmusActivated;
    unsigned char bMonstersSpawned;
    unsigned char unk_06[0x2];
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
    unsigned char unk_38[0x4];
    int nFlailsMissing;
    int nHoradricCubesMissing;
    unsigned char unk_44[0xC];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern char gpAct3Q5NpcMessages[]; // 0x007408B8
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
bool __fastcall ACT3Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005BAD60
void __fastcall ACT3Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BAFD0
void __fastcall ACT3Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BB120
void __fastcall ACT3Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BB210
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BB400
bool __fastcall ACT3Q5_SeqCallback(D2QuestDataStrc* pQuestData); // 0x005BB410
void __fastcall ACT3Q5_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BB480
void __fastcall ACT3Q5_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BBC00
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemCode); // 0x00544160
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544760
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x005678A0
void __fastcall ACT3Q5_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BB0C0
int __fastcall ACT3Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BADC0
int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BAF70
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

typedef int (__fastcall* QUESTITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
void __fastcall QUESTS_RemovePlayerGUID(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00545530

struct D2Act3Quest2Strc
{
    char pad0x00[0x1C];
    int nFlailsDropped;
    int nCubedFlails;
    char pad0x24[0x03];
    unsigned char bFlailDropped;
};

void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
int __fastcall sub_005BAE20_UpdateQuestStateAfterMonsterKill(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BAE20
int __fastcall ACT3Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BB6C0
int __fastcall ACT3Q5_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BB710
int __fastcall ACT3Q5_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BB770
int __fastcall ACT3Q5_UnitIterate_DetermineFlailAndCubeDropCounts(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BB7B0

// 0x005BAF70
int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 21, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 21, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 21, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 21, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 19);
    }

    return 0;
}

#include "gen/data/Source/D2Game/Quests/a3q5.inc"

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005BB120
void __fastcall ACT3Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;

    if (pQuestArg->nNewLevel == 82 && pQuestData->bNotIntro && !pQuestData->fState)
    {
        pQuestData->fState = 1;
        pQuestData->pCallback[2] = ACT3Q5_Callback02_NpcDeactivate;
    }

    if (nOldLevel != 75)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);

    if (pQuestData->fState <= 1 || pQuestData->fState > 3)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 4) == 1)
    {
        return;
    }

    if (pQuestData->fLastState < 3)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT3Q5_UnitIterate_StatusCyclerEx, 0);
    }

    if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
    {
        QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 395);
    }
    else
    {
        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 399);
    }
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_UpdateQuestStateFlags);
}

// 0x005BB400
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);
}

// 0x005BB410
bool __fastcall ACT3Q5_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != 7 && pQuestData->bNotIntro)
    {
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 501);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x005BB550
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
        QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 630);
    else
        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 634);

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_UpdateQuestStateFlags);
}

// 0x005BB7B0
int __fastcall ACT3Q5_UnitIterate_DetermineFlailAndCubeDropCounts(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 2)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 19);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 0)
        && !ITEMS_FindQuestItem(pGame, pUnit, ' 1fq') && !ITEMS_FindQuestItem(pGame, pUnit, ' 2fq'))
    {
        ++pQuestDataEx->nFlailsMissing;
    }

    if (!ITEMS_FindQuestItem(pGame, pUnit, ' xob'))
    {
        ++pQuestDataEx->nHoradricCubesMissing;
    }

    return 0;
}

// 0x005BB850
void __fastcall ACT3Q5_UnitIterate_DeleteKhalimItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 18, 0) == 1)
    {
        QUESTS_DeleteItem(pGame, pUnit, ' yeq');
        QUESTS_DeleteItem(pGame, pUnit, ' rhq');
        QUESTS_DeleteItem(pGame, pUnit, ' rbq');
        QUESTS_DeleteItem(pGame, pUnit, ' 1fq');
        QUESTS_DeleteItem(pGame, pUnit, ' 2fq');
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (DRLG_GetActNoFromLevelId(nLevelId) != 2)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 18, 0);
    QUESTRECORD_SetQuestState(pQuestFlags, 18, 13);

    if (!D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        QUESTS_DeleteItem(pGame, pUnit, ' yeq');
        QUESTS_DeleteItem(pGame, pUnit, ' rhq');
        QUESTS_DeleteItem(pGame, pUnit, ' rbq');
        QUESTS_DeleteItem(pGame, pUnit, ' 1fq');
        QUESTS_DeleteItem(pGame, pUnit, ' 2fq');
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 4) && !QUESTRECORD_GetQuestState(pQuestFlags, 21, 0))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 21, 0);
    }
}

inline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

inline void SetUnitFlagMask(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags |= nFlag;
    }
}

// 0x005BBC00
void __fastcall ACT3Q5_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "killed boss for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 913);

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;
    int i;
    if (UNITS_GetClassIdInline(pQuestArg->pTarget) == 366)
    {
        SetUnitFlagMask(pQuestArg->pTarget, 0x20000);
        return;
    }

    if (!pQuestDataEx->bFlailDropped || !pQuestDataEx->bCubeDropped)
    {
        pQuestDataEx->nFlailsMissing = 0;
        pQuestDataEx->nHoradricCubesMissing = 0;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_DetermineFlailAndCubeDropCounts);
    }

    if (!pQuestDataEx->bFlailDropped)
    {
        pQuestArg->pTarget->dwDropItemCode = ' 1fq';
        int nFlailsDropped = 0;
        for (i = 0; i < pQuestDataEx->nFlailsMissing; ++i)
        {
            int nItemLevel;
            if (D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pQuestArg->pTarget, 7, &nItemLevel, 0, -1, 0))
            {
                ++nFlailsDropped;
            }
        }

        if (nFlailsDropped)
        {
            pQuestDataEx->bFlailDropped = 1;

            D2QuestDataStrc* pQuestData16 = QUESTS_GetQuestData(pQuestData->pGame, 16);
            if (pQuestData16)
            {
                D2Act3Quest2Strc* pQuestDataEx16 = (D2Act3Quest2Strc*)pQuestData16->pQuestDataEx;
                pQuestDataEx16->nFlailsDropped += nFlailsDropped;
                pQuestDataEx16->bFlailDropped = 1;
            }
        }
    }
    else if (!pQuestDataEx->bCubeDropped)
    {
        pQuestDataEx->bCubeDropped = 1;
        pQuestArg->pTarget->dwDropItemCode = ' xob';
        for (i = 0; i < pQuestDataEx->nHoradricCubesMissing; ++i)
        {
            int nItemLevel;
            D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pQuestArg->pTarget, 2, &nItemLevel, 0, -1, 0);
        }
    }

    if (!pQuestData->bNotIntro || pQuestDataEx->nMonstersLeftToKill <= 0)
    {
        return;
    }

    --pQuestDataEx->nMonstersLeftToKill;
    if (pQuestDataEx->nMonstersLeftToKill)
    {
        return;
    }

    pQuestDataEx->nLastKilledMonsterGUID = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwUnitId;
    pQuestData->dwFlags &= 0xFFFFFF00;
    if (pQuestDataEx->bOrbSmashed)
    {
        QUESTS_StateDebug(pQuestData, 7, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 972);
        QUESTS_UnitIterate(pQuestData, 13, 0, ACT3Q5_UnitIterate_StatusCyclerEx, true);
    }
    else
    {
        QUESTS_StateDebug(pQuestData, 6, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 977);
        QUESTS_UnitIterate(pQuestData, 4, 0, ACT3Q5_UnitIterate_StatusCyclerEx, true);
    }

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, sub_005BAE20_UpdateQuestStateAfterMonsterKill);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT3Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT3Q5_UnitIterate_SetCompletionFlag);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT3Q5_UnitIterate_AttachCompletionSound);
    QUESTS_SetGlobalState(pQuestData->pGame, 21, 13);
}

// 0x005BBEB0
void __fastcall ACT3Q5_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pNPCMessages = gpAct3Q5NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->pCallback[8] = ACT3Q5_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT3Q5_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT3Q5_Callback11_ScrollMessage;
    pQuestData->pCallback[3] = ACT3Q5_Callback03_ChangedLevel;
    pQuestData->pCallback[13] = ACT3Q5_Callback13_PlayerStartedGame;
    pQuestData->pCallback[10] = ACT3Q5_Callback10_PlayerLeavesGame;
    pQuestData->pfSeqFilter = ACT3Q5_SeqCallback;
    pQuestData->nSeqId = 20;
    pQuestData->fState = 0;
    pQuestData->eFilter = 21;
    pQuestData->pfActiveFilter = ACT3Q5_ActiveFilterCallback;
    pQuestData->nInitNo = 6;
    pQuestData->pfStatusFilter = 0;

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest5Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 1061, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest5Strc));
    memset(pQuestData->pQuestDataEx, 0x00, sizeof(D2Act3Quest5Strc));
}
