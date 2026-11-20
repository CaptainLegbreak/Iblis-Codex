#include "D2Game.h"
#include "D2Structs.h"
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_COMPLETEDBEFORE 15
#define SUPERUNIQUE_SIEGE_BOSS 42
#define UNIT_INVALID 6
#define STAT_FIRERESIST 39
#define STAT_LIGHTRESIST 41
#define STAT_COLDRESIST 43
#define STAT_POISONRESIST 45
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2QuestGUIDStrc;
struct D2PlayerDataStrc;
struct D2ObjInitFnStrc;
struct D2Act5Quest1Strc;
struct D2Act5Quest2Strc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2GameStrc
{
    char pad0x00[0x1C];
    void* pMemoryPool;
    char pad0x20[0x4D];
    unsigned char nDifficulty;
    char pad0x6E[0x2];
};


struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2MapAIStrc
{
    int nPathNodes;
    void* pPosition;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    char pad0x0C[0x8];
    int nX;
    int nY;
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

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
    char pad0x0E[0x2];
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    char pad0xE4[0x4];
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    char pad0x10[0x4];
    union
    {
        D2TextHeaderStrc* pTextControl;
        int nOldLevel;
    };
    int nNewLevel;
};

struct D2Act5Quest1Strc
{
    D2MapAIStrc* pLarzukMapAI;
    D2ActiveRoomStrc* pRoom;
    char pad0x08[0x8];
    int nLarzukGUID;
    char pad0x14[0x1];
    unsigned char bLarzukSpawned;
    char pad0x16[0x1];
    unsigned char bLarzukMapAIChanged;
};

struct D2Act5Quest2Strc
{
    char tPlayerGUIDs[0x84];
    unsigned char unk_84[0x2];
    unsigned char bWussiesSpawned[3];
    char unk0x89[0x1B];
    int nSpawnedWussies;
    int nKilledWussies;
    int nFreedWussies;
    int nWussieGUIDs[3][5];
    unsigned char unk_EC[0x28];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern char gpAct5Q1NpcMessages[]; // 0x00733308
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId); // 0x00544190
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned int fCollision, D2ActiveRoomStrc** ppRoom, int nRadius, int a7); // 0x00545340
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2); // 0x00545760
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x005723C0
bool __fastcall ACT5Q1_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x00586CE0
int __fastcall ACT5Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00586C80
void __fastcall ACT5Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00586D80
int __fastcall ACT5Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00586DE0
void __fastcall ACT5Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00586E70
void __fastcall ACT5Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00586FF0
int __fastcall ACT5Q1_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00587100
int __fastcall ACT5Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005872F0
bool __fastcall ACT5Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005874E0
bool __fastcall ACT5Q1_SeqCallback(D2QuestDataStrc* pQuestData); // 0x00587560
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit); // 0x0058F000
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2); // 0x00666120
void __fastcall ACT5Q1_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005870D0
void __fastcall ACT5Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005873E0

typedef int(__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520
int __fastcall ACT5Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005879D0
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit); // 0x005A01E0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0

// 0x005871C0
void __fastcall ACT5Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 1) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0xD) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 4)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 0x23, 1);
    QUESTRECORD_SetQuestState(pQuestFlags, 0x23, 0xD);
}

// 0x00587240
int __fastcall ACT5Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0xD))
    {
        const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
        if (nPartyId != 0xFFFF)
        {
            PARTY_IteratePartyMembers(pGame, nPartyId, ACT5Q1_UnitIterate_SetPrimaryGoalDone, 0);
        }
    }

    return 0;
}

// 0x00587290
int __fastcall ACT5Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 1) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0xD) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x23, 0xE);
        QUESTS_SendLogUpdateEx(pUnit, 0x1F, 0);
    }

    return 0;
}

// 0x00587330
void __fastcall ACT5Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pQuestArg->pTarget);
    if (!pRoom)
    {
        return;
    }

    ((D2Act5Quest1Strc*)pQuestData->pQuestDataEx)->pRoom = pRoom;

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q1_UnitIterate_SetRewardPending);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q1_UnitIterate_SetCompletionFlag);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q1_UnitIterate_AttachCompletionSound);

    QUESTS_SetGlobalState(pQuestData->pGame, 0x23, 0xD);
    QUESTS_TriggerFX(pQuestData->pGame, 0xF);

    if (pQuestData->fLastState < 3)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x005875F0
void __fastcall ACT5Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0)
        || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0xF)
        || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1) == 1)
    {
        pQuestData->fLastState = 5;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 4) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 3) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 2) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 2;
    }
    else if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, 0x201) && !pQuestData->fState && pQuestData->bNotIntro)
    {
        pQuestData->fState = 1;
    }
}

// 0x005876E0
void __fastcall ACT5Q1_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[10] = ACT5Q1_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[3] = ACT5Q1_Callback03_ChangedLevel;
    pQuestData->pfCallback[8] = ACT5Q1_Callback08_MonsterKilled;
    pQuestData->pfCallback[0] = ACT5Q1_Callback00_NpcActivate;
    pQuestData->pfCallback[2] = ACT5Q1_Callback02_NpcDeactivate;
    pQuestData->pfCallback[11] = ACT5Q1_Callback11_ScrollMessage;
    pQuestData->pfCallback[13] = ACT5Q1_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = gpAct5Q1NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;

    D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest1Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0x2D3, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->nQuestFilter = 0x23;
    pQuestData->pfStatusFilter = ACT5Q1_StatusFilterCallback;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT5Q1_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT5Q1_SeqCallback;
    pQuestData->nSeqId = 0x20;
    memset(pQuestDataEx, 0x00, sizeof(D2Act5Quest1Strc));
}

// 0x005879D0
int __fastcall ACT5Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0xF)
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0xD)
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0xE))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 0x20);
    }

    return 0;
}

// 0x00587A90
int __fastcall ACT5Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 1) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x20);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 2);
    }
    else if (pQuestData->fState == 3)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 3);
    }

    return 0;
}

// 0x00587F60
int __fastcall ACT5Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 1) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0xD) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 0xE);
        QUESTS_SendLogUpdateEx(pUnit, 0x20, 0);
    }

    return 0;
}

#include "gen/data/Source/D2Game/Quests/a5q1_005871C0.inc"

// 0x005877C0
void __fastcall ACT5Q1_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED);
    QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDPENDING);

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_COMPLETEDBEFORE))
    {
        D2_ASSERT(QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK), 750);
    }
}

// 0x00587900
void __fastcall ACT5Q1_OnSiegeBossActivated(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK);

    if (!pQuestData || !pQuestData->bNotIntro || pQuestData->fLastState >= 2 || MONSTERUNIQUE_GetBossHcIdx(pUnit) != SUPERUNIQUE_SIEGE_BOSS)
    {
        return;
    }

    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
}

// 0x00587FC0
int __fastcall sub_00587FC0_GetWussieGroupIndex(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    const int nGUID = !pUnit ? -1 : pUnit->dwUnitId;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (nGUID == pQuestDataEx->nWussieGUIDs[i][j])
            {
                return i;
            }
        }
    }

    return -1;
}

// 0x00588C50
int __fastcall ACT5Q2_GetBarbsToBeRescued(D2QuestDataStrc* pQuestData)
{
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;

    int nBarbs = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (!pQuestDataEx->bWussiesSpawned[i])
        {
            nBarbs += 5;
        }
    }

    nBarbs += pQuestDataEx->nSpawnedWussies - pQuestDataEx->nFreedWussies - pQuestDataEx->nKilledWussies;
    if (nBarbs < 0)
    {
        nBarbs = 0;
    }

    return nBarbs;
}

// 0x00588DD0
void __fastcall ACT5Q2_OnWussieActivated(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPlayer)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q2_RESCUESOLDIERS);

    if (!pQuestData || !pQuestData->bNotIntro || pQuestData->fLastState == 5)
    {
        return;
    }

    if (((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->nKilledWussies >= 5)
    {
        return;
    }

    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 5, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
}

// 0x00589160
bool __fastcall ACT5Q3_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState < 5 && pQuestData->bNotIntro)
    {
        if (!pQuestData->fState)
        {
            pQuestData->fState = 1;
        }
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 331);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x00589FF0
void __fastcall ACT5Q3_UpdateResistances(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    if (!pStatList)
    {
        return;
    }

    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);

    STATLIST_SetStat(pStatList, STAT_FIRERESIST, nValue, 0);
    STATLIST_SetStat(pStatList, STAT_LIGHTRESIST, nValue, 0);
    STATLIST_SetStat(pStatList, STAT_COLDRESIST, nValue, 0);
    STATLIST_SetStat(pStatList, STAT_POISONRESIST, nValue, 0);

    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_FIRERESIST, nValue, pUnit);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_LIGHTRESIST, nValue, pUnit);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_COLDRESIST, nValue, pUnit);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_POISONRESIST, nValue, pUnit);
}
