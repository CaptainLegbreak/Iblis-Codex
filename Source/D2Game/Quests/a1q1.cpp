#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2UnitData.h"
#include "D2QuestData.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2QuestGUIDStrc;

struct D2PlayerDataStrc;

struct D2Act1Quest1Strc;

struct Sub005901E0;

struct Obj005901E0;

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef int(__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern "C" const unsigned int gnAct1Quest1NpcIndices[]; // 0x00736CD0

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0

void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestRecord, int nQuest); // 0x0065C3E0

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300

void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350


void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780

void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0

int __fastcall ACT1Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058FC90

int __fastcall ACT1Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058FBE0

struct Sub005901E0 { unsigned char bUnknown00[0x88]; unsigned int dwValue88; };

struct Obj005901E0 { unsigned char bUnknown00[0x18]; Sub005901E0* pSub18; };

struct D2GameStrc;

struct D2UnitStrc;

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                            // 0x00545240

void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit);                             // 0x005455B0

void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct);              // 0x00545920

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

#define QFLAG_CUSTOM7 11

#define QFLAG_PRIMARYGOALDONE 13

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

#define ACT_III 2

#define QUESTSTATEFLAG_A1Q1 1

void __fastcall ACT1Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

#define LEVEL_DENOFEVIL 8

#define LEVEL_ROGUEENCAMPMENT 1

struct D2NPCMessageTableStrc;

struct D2MonsterRegionStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct D2MonsterRegionStrc
{
    int unk0x00;
    int unk0x04;
    char unk0x08[0x2C4];
    unsigned int dwMonSpawnCount;
    unsigned int dwMonKillCount;
};

typedef void (__fastcall* QUESTUPDATE)(D2QuestDataStrc* pQuest);

typedef int (__fastcall* SUNIT_ITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern D2NPCMessageTableStrc gpAct1Q1NpcMessages; // 0x007366B0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10

void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070


void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720

extern "C" int __fastcall sub_00545290(D2QuestGUIDStrc* pQuestGUID, unsigned int dwGUID); // 0x00545290

void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pGUIDs); // 0x00545300

void __fastcall QUESTS_GUIDUpdate(D2GameStrc* pGame, D2QuestGUIDStrc* pQuestGUID, int nQuest, int nSoundCMD); // 0x005455F0

void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2); // 0x00545760

D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0

D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, SUNIT_ITERATEFN pfIterate); // 0x005537D0

void __fastcall ACT1Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058FC40

void __fastcall ACT1Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058FDD0

void __fastcall ACT1Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058FF90

int __fastcall ACT1Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00590080

int __fastcall ACT1Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005900E0

int __fastcall ACT1Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00590190

void __fastcall ACT1Q1_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005901F0

bool __fastcall ACT1Q1_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x00590230

void __fastcall ACT1Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590470

bool __fastcall ACT1Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005905B0

bool __fastcall sub_00590620_SeqCallback(D2QuestDataStrc* pQuestData); // 0x00590620

void __fastcall ACT1Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590690

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

#define PREFIX

#define TERMINAL_STATE 5

#define ASSERT_LINE 679

struct D2QuestDataStrc;

// 0x0058FDD0
void __fastcall ACT1Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg)
{
    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)pQuest->pQuestDataEx;
    const unsigned short nMessageIndex = pArg->nMessageIndex;
    if (pArg->nNPCNo != 0x94)
    {
        return;
    }

    D2UnitStrc* pPlayer = pArg->pPlayer;
    D2GameStrc* pGame = pQuest->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (nMessageIndex == 0x40)
    {
        pQuestDataEx->bAkaraActivated = 1;
        QUESTS_StateDebug(pQuest, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q1.cpp", 0xFD);
        SUNIT_IterateUnitsOfType(pQuest->pGame, 0, 0, ACT1Q1_UnitIterate_UpdateQuestStateFlags);
        QUESTS_NPCActivateSpeeches(pArg->pGame, pArg->pPlayer, pArg->pTarget);
    }
    else if (nMessageIndex == 0x4C)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, 1) != 1)
        {
            return;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, 0xD))
        {
            if (pQuest->fState != 5)
            {
                QUESTS_StateDebug(pQuest, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q1.cpp", 0x109);
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pfSeqFilter), 0x10A);
                pQuest->pfSeqFilter(pQuest);
                pQuest->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuest, 0xD, 0, ACT1Q1_UnitIterate_StatusCyclerEx, 0);
            }

            pQuest->pCallback[2] = 0;
        }

        QUESTRECORD_SetQuestState(pQuestFlags, pQuest->eFilter, 0);
        QUESTRECORD_ClearQuestState(pQuestFlags, pQuest->eFilter, 1);
        QUESTRECORD_SetQuestState(pQuestFlags, *(int*)pQuest->unk0xE4, 0xD);
        QUESTRECORD_SetQuestState(pQuestFlags, *(int*)pQuest->unk0xE4, 1);
        QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, pQuest->eFilter);
        STATLIST_AddUnitStat(pArg->pPlayer, 5, 1, 0);
        QUESTS_AddPlayerGUID(&pQuest->tPlayerGUIDs, !pArg->pPlayer ? -1 : pArg->pPlayer->dwUnitId);
        QUESTS_NPCActivateSpeeches(pArg->pGame, pArg->pPlayer, pArg->pTarget);
    }
}

// 0x0058FF90
void __fastcall ACT1Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg)
{
    D2GameStrc* pGame = pQuest->pGame;
    D2UnitStrc* pPlayer = pArg->pPlayer;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, 0xD);
    const int nNpcId = !pArg->pTarget ? -1 : pArg->pTarget->dwClassId;
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, 1))
    {
        QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpcId, 3);
        return;
    }

    if (QUESTS_CheckPlayerGUID(pQuest, !pArg->pPlayer ? -1 : pArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpcId, 4);
        return;
    }

    if (bRewardGranted == 1)
    {
        return;
    }

    if ((unsigned char)pQuest->fState >= 4 && !bPrimaryGoalDone)
    {
        return;
    }

    if (!pQuest->bNotIntro)
    {
        return;
    }

    const unsigned int nIndex = gnAct1Quest1NpcIndices[(unsigned char)pQuest->fState];
    if (nIndex != -1 && nIndex < 8)
    {
        QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpcId, nIndex);
    }
}

// 0x00590080
int __fastcall ACT1Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_COMPLETEDNOW);
    QUESTS_SendLogUpdateEx(pUnit, 1, 0);
    QUESTS_UpdatePlayerFlags(pGame, pUnit);
    return 0;
}

// 0x005900E0
int __fastcall ACT1Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE))
    {
        SUNIT_AttachSound(pUnit, 35, pUnit);
    }

    return 0;
}

// 0x00590120
void __fastcall ACT1Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId && DRLG_GetActNoFromLevelId(nLevelId) == ACT_I)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDPENDING);
    }
}

// 0x00590190
int __fastcall ACT1Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT1Q1_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x005901E0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_005901E0(Obj005901E0* pObj) {
    return pObj->pSub18->dwValue88;
}

// 0x005901F0
void __fastcall ACT1Q1_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pQuestGUID, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
}

// 0x00590230
bool __fastcall ACT1Q1_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->fState == 4)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 5, 0, ACT1Q1_UnitIterate_StatusCyclerEx, 1);
    }

    pQuestDataEx->bTimerActive = 0;
    return 1;
}

// 0x00590260
void __fastcall ACT1Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)pQuestData->pQuestDataEx;
    D2MonsterRegionStrc* pMonRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pQuestArg->pGame->pMonReg, LEVEL_DENOFEVIL);

    D2_ASSERT(pMonRegion, 484);

    pQuestDataEx->nMonstersLeft = pMonRegion->dwMonSpawnCount - pMonRegion->dwMonKillCount;

    if (pQuestArg->pPlayer)
    {
        const int nUnitId = pQuestArg->pPlayer->dwUnitId;
        if (!sub_00545290(&pQuestDataEx->pQuestGUID, nUnitId))
        {
            QUESTS_AddPlayerGUID(&pQuestDataEx->pQuestGUID, nUnitId);
        }
    }

    const int nPopulatedRooms = DUNGEON_GetNumberOfPopulatedRoomsInLevel(pQuestArg->pGame->pAct[DRLG_GetActNoFromLevelId(LEVEL_DENOFEVIL)], LEVEL_DENOFEVIL);

    if (nPopulatedRooms > pMonRegion->unk0x04 || pMonRegion->dwMonKillCount != pMonRegion->dwMonSpawnCount)
    {
        if (nPopulatedRooms > pMonRegion->unk0x04 || pQuestDataEx->nMonstersLeft > 5)
        {
            if (pQuestData->fLastState == 4 && pQuestDataEx->nMonstersLeft > 5)
            {
                pQuestData->dwFlags = (pQuestData->dwFlags & 0xFFFFFF00) | 0x20;
                QUESTS_UnitIterate(pQuestData, 4, 0, ACT1Q1_UnitIterate_StatusCyclerEx, 1);
            }
        }
        else
        {
            pQuestData->dwFlags = (pQuestData->dwFlags & 0xFFFFFF00) | 0x20;
            QUESTS_UnitIterate(pQuestData, 4, 0, ACT1Q1_UnitIterate_StatusCyclerEx, 1);
            pQuestData->pCallback[2] = 0;
        }
    }
    else
    {
        QUESTS_DebugOutput(pQuestData->pGame, "Finished quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q1.cpp", 503);
        pQuestDataEx->bFinished = 1;
        pQuestData->pCallback[2] = 0;
        QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q1.cpp", 506);
        pQuestData->pCallback[8] = 0;
        QUESTS_SetGlobalState(pQuestArg->pGame, pQuestData->eFilter, QFLAG_PRIMARYGOALDONE);
        QUESTS_GUIDUpdate(pQuestArg->pGame, &pQuestDataEx->pQuestGUID, pQuestData->eFilter, 0);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q1_UnitIterate_SetCompletionFlag);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q1_UnitIterate_AttachCompletionSound);
        QUESTS_TriggerFX(pQuestData->pGame, 0);

        if (!pQuestDataEx->bTimerActive)
        {
            pQuestDataEx->bTimerActive = 1;
            QUESTS_CreateTimer(pQuestData, (QUESTUPDATE)ACT1Q1_Timer_StatusCycler, 8);
        }
    }
}

// 0x00590470
void __fastcall ACT1Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)pQuestData->pQuestDataEx;
    const int nOldLevel = pQuestArg->nOldLevel;

    if (pQuestArg->nNewLevel == LEVEL_DENOFEVIL)
    {
        if (!pQuestData->bNotIntro)
        {
            return;
        }

        bool bUpdated = false;
        if (pQuestData->fState == 1 || pQuestData->fState == 2)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q1.cpp", 601);
            bUpdated = true;
        }

        pQuestDataEx->bEnteredDen = 1;
        if (pQuestData->fLastState < 2)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 2, 0, ACT1Q1_UnitIterate_StatusCyclerEx, 1);
            pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = 0;
        }
        else if (!bUpdated)
        {
            return;
        }

        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q1_UnitIterate_UpdateQuestStateFlags);
    }
    else if (nOldLevel == LEVEL_ROGUEENCAMPMENT)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (pQuestData->fState != 2)
        {
            return;
        }

        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING) == 1)
        {
            return;
        }

        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q1.cpp", 629);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q1_UnitIterate_UpdateQuestStateFlags);

        if (pQuestData->fLastState == 1)
        {
            return;
        }

        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q1_UnitIterate_StatusCyclerEx, 1);
        pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = 0;
    }
}

// 0x00590620
bool __fastcall sub_00590620_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != TERMINAL_STATE && pQuestData->bNotIntro)
        return true;
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        if (IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter))
        {
            sub_00408A60(&gszEmptyAssertText, sub_00408090(), ASSERT_LINE);
            exit(-1);
        }
        return pQuest->pfSeqFilter(pQuest);
    }
    return false;
}

// 0x00590690
void __fastcall ACT1Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_COMPLETEDBEFORE))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_ENTERAREA) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_STARTED) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x00590720
void __fastcall ACT1Q1_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));

    pQuestData->pCallback[10] = ACT1Q1_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT1Q1_Callback03_ChangedLevel;
    pQuestData->pCallback[8] = ACT1Q1_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT1Q1_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT1Q1_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT1Q1_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT1Q1_Callback13_PlayerStartedGame;

    pQuestData->pNPCMessages = &gpAct1Q1NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 1;
    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act1Quest1Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q1.cpp", 750, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = QUESTSTATEFLAG_A1Q1;
    *(int*)pQuestData->unk0xE4 = 0x29;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT1Q1_ActiveFilterCallback;
    pQuestData->pfSeqFilter = sub_00590620_SeqCallback;
    pQuestData->nSeqId = 2;

    memset(pQuestDataEx, 0x00, sizeof(D2Act1Quest1Strc));
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->pQuestGUID);
}

#include "gen/data/Source/D2Game/Quests/a1q1.inc"
