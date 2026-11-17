struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2ClientStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0xA8];
    unsigned int dwDropItemCode;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestGUIDStrc
{
    int nGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char unk0x82[2];
};

struct D2Act1Quest6Strc
{
    D2QuestGUIDStrc pGUID1;
    D2QuestGUIDStrc pGUID2;
    D2QuestGUIDStrc pGUID3;
    int nAndarielGUID;
    short unk0x190;
    short nTimerInvocations;
    unsigned char bAndarielKilled;
};

struct D2QuestDataStrc;
struct D2QuestArgStrc;
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc*, D2UnitStrc*, void*);
typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc*, D2QuestDataStrc*);
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char unk0x08;
    unsigned char bNotIntro;
    char unk0x0A[0x0E];
    D2Act1Quest6Strc* pQuestDataEx;
    char unk0x1C[0x84];
    QUESTCALLBACK pfCallback[15];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

#define ACT_I 0
#define QUEST_A1Q6_ANDARIEL 6
#define QUESTSTATEFLAG_A1Q6 6
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDBEFORE 15
#define LEVEL_CATACOMBSLEV4 37
#define QUESTEVENT_NPCDEACTIVATE 2
#define QUESTEVENT_MONSTERKILLED 8
#define QUESTEVENT_PLAYERLEAVESGAME 10
#define ITEMQUAL_NORMAL 2

extern "C" const unsigned int gdwA1Q6ChippedGemCodes[7];                                                    // 0x007361DC
extern "C" const unsigned int gdwA1Q6NormalGemCodes[7];                                                     // 0x00736444

void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty);       // 0x00538680
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame);                                            // 0x005438B0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                               // 0x00543640
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);           // 0x00543F10
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID);                              // 0x00545200
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, void* pItemDrop, int a6, int a7); // 0x00559A30
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
int __fastcall ACT1Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00596170
void __fastcall ACT1Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pArgs);    // 0x005961C0
int __fastcall ACT1Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);     // 0x005963E0
int __fastcall ACT1Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00596440
bool __fastcall ACT1Q6_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuest);                      // 0x00596500

inline unsigned __int64 A1Q6_RollSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline D2BitBufferStrc* A1Q6_GetQuestFlagsInline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

inline int A1Q6_GetQuestStateInline(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nState)
{
    D2BitBufferStrc* pQuestFlags = A1Q6_GetQuestFlagsInline(pGame, pPlayer);
    return QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, nState);
}

static void __stdcall sub_00596210_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, D2BitBufferStrc* pQuestFlags)
{
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING);
    CLIENTS_UpdateCharacterProgression(SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp", 451), 1, pGame->nDifficulty);
}

// 0x00596260
int __fastcall ACT1Q6_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_COMPLETEDBEFORE) == 1)
    {
        return 0;
    }

    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_CATACOMBSLEV4)
    {
        return 0;
    }

    D2Act1Quest6Strc* pQuestDataEx = QUESTS_GetQuestData(pGame, QUEST_A1Q6_ANDARIEL)->pQuestDataEx;
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID1, nUnitId);
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID2, nUnitId);
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID3, nUnitId);
    sub_00596210_SetPrimaryGoalDone(pGame, pUnit, pQuestFlags);
    return 0;
}

void __fastcall ACT1Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != ACT_I)
    {
        return;
    }

    D2Act1Quest6Strc* pQuestDataEx = QUESTS_GetQuestData(pGame, QUEST_A1Q6_ANDARIEL)->pQuestDataEx;
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID1, nUnitId);
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID2, nUnitId);
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID3, nUnitId);
    sub_00596210_SetPrimaryGoalDone(pGame, pUnit, pQuestFlags);
}

// 0x005965A0
void __fastcall ACT1Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act1Quest6Strc* pQuestDataEx = pQuestData->pQuestDataEx;

    pQuestData->pfCallback[QUESTEVENT_NPCDEACTIVATE] = 0;

    if (pQuestData->bNotIntro)
    {
        if (pQuestArg->pPlayer
            && !A1Q6_GetQuestStateInline(pQuestData->pGame, pQuestArg->pPlayer, QFLAG_REWARDGRANTED)
            && !A1Q6_GetQuestStateInline(pQuestData->pGame, pQuestArg->pPlayer, QFLAG_REWARDPENDING))
        {
            D2BitBufferStrc* pQuestFlags = A1Q6_GetQuestFlagsInline(pQuestData->pGame, pQuestArg->pPlayer);
            sub_00596210_SetPrimaryGoalDone(pQuestData->pGame, pQuestArg->pPlayer, pQuestFlags);

            int nItemLevel;
            for (int i = 0; i < 2; ++i)
            {
                pQuestArg->pTarget->dwDropItemCode = gdwA1Q6ChippedGemCodes[(unsigned int)A1Q6_RollSeedInline(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7];
                D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pQuestArg->pTarget, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0);
            }

            pQuestArg->pTarget->dwDropItemCode = gdwA1Q6NormalGemCodes[(unsigned int)A1Q6_RollSeedInline(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7];
            D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pQuestArg->pTarget, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0);

            pQuestArg->pTarget->dwDropItemCode = 0;
        }

        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q6_UnitIterate_SetRewardPending);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q6_UnitIterate_SetCompletionFlag);
    }

    pQuestDataEx->nAndarielGUID = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwUnitId;
    pQuestDataEx->nTimerInvocations = 1;

    if (pQuestData->bNotIntro)
    {
        QUESTS_CreateTimer(pQuestData, ACT1Q6_Timer_StatusCycler, 1);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q6_UnitIterate_AttachCompletionSound);
    }

    pQuestDataEx->bAndarielKilled = 1;
    QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp", 688);
    pQuestData->pfCallback[QUESTEVENT_PLAYERLEAVESGAME] = ACT1Q6_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[QUESTEVENT_MONSTERKILLED] = 0;
}

#include "gen/data/Source/D2Game/005965A0_ACT1Q6_Callback08_MonsterKilled.inc"
