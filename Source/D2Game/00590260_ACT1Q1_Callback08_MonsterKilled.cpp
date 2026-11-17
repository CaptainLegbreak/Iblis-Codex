extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct D2BitBufferStrc;
struct D2DrlgActStrc;
struct D2NPCMessageTableStrc;

struct D2MonsterRegionStrc
{
    int unk0x00;
    int unk0x04;
    char unk0x08[0x2C4];
    unsigned int dwMonSpawnCount;
    unsigned int dwMonKillCount;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x9C];
    D2DrlgActStrc* pAct[5];
    char unk0xD0[0x20];
    D2MonsterRegionStrc* pMonReg[1024];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2QuestDataStrc;
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef void (__fastcall* QUESTUPDATE)(D2QuestDataStrc* pQuest);
typedef int (__fastcall* SUNIT_ITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

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
    unsigned char bStatusFlags;
    unsigned char pad0x15[3];
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    D2NPCMessageTableStrc* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2Act1Quest1Strc
{
    D2QuestGUIDStrc pQuestGUID;
    unsigned char bFinished;
    unsigned char bEnteredDen;
    unsigned char bAkaraActivated;
    unsigned char bTimerActive;
    int nMonstersLeft;
};

extern D2NPCMessageTableStrc gpAct1Q1NpcMessages;                                                           // 0x007366B0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);          // 0x00543F10
void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                        // 0x00544720
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID);                             // 0x00545200
extern "C" int __fastcall sub_00545290(D2QuestGUIDStrc* pQuestGUID, unsigned int dwGUID);                // 0x00545290
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pGUIDs);                                      // 0x00545300
void __fastcall QUESTS_GUIDUpdate(D2GameStrc* pGame, D2QuestGUIDStrc* pQuestGUID, int nQuest, int nSoundCMD); // 0x005455F0
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2);                                     // 0x00545760
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, SUNIT_ITERATEFN pfIterate); // 0x005537D0
int __stdcall DUNGEON_GetNumberOfPopulatedRoomsInLevel(D2DrlgActStrc* pAct, int nLevelId);                 // 0x0061ABF0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                            // 0x006427F0

int __fastcall ACT1Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x0058FBE0
void __fastcall ACT1Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x0058FC40
void __fastcall ACT1Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x0058FDD0
void __fastcall ACT1Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x0058FF90
int __fastcall ACT1Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);     // 0x00590080
int __fastcall ACT1Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005900E0
int __fastcall ACT1Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00590190
void __fastcall ACT1Q1_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005901F0
bool __fastcall ACT1Q1_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);                  // 0x00590230
void __fastcall ACT1Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x00590470
bool __fastcall ACT1Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005905B0
bool __fastcall ACT1Q1_SeqCallback(D2QuestDataStrc* pQuestData);                                            // 0x00590620
void __fastcall ACT1Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590690

#define LEVEL_DENOFEVIL 8
#define QUESTSTATEFLAG_A1Q1 1
#define QFLAG_PRIMARYGOALDONE 13

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
                pQuestData->bStatusFlags = 0x20;
                QUESTS_UnitIterate(pQuestData, 4, 0, ACT1Q1_UnitIterate_StatusCyclerEx, 1);
            }
        }
        else
        {
            pQuestData->bStatusFlags = 0x20;
            QUESTS_UnitIterate(pQuestData, 4, 0, ACT1Q1_UnitIterate_StatusCyclerEx, 1);
            pQuestData->pfCallback[2] = 0;
        }
    }
    else
    {
        QUESTS_DebugOutput(pQuestData->pGame, "Finished quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q1.cpp", 503);
        pQuestDataEx->bFinished = 1;
        pQuestData->pfCallback[2] = 0;
        QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q1.cpp", 506);
        pQuestData->pfCallback[8] = 0;
        QUESTS_SetGlobalState(pQuestArg->pGame, pQuestData->nQuestFilter, QFLAG_PRIMARYGOALDONE);
        QUESTS_GUIDUpdate(pQuestArg->pGame, &pQuestDataEx->pQuestGUID, pQuestData->nQuestFilter, 0);
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

// 0x00590720
void __fastcall ACT1Q1_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));

    pQuestData->pfCallback[10] = ACT1Q1_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[3] = ACT1Q1_Callback03_ChangedLevel;
    pQuestData->pfCallback[8] = ACT1Q1_Callback08_MonsterKilled;
    pQuestData->pfCallback[0] = ACT1Q1_Callback00_NpcActivate;
    pQuestData->pfCallback[2] = ACT1Q1_Callback02_NpcDeactivate;
    pQuestData->pfCallback[11] = ACT1Q1_Callback11_ScrollMessage;
    pQuestData->pfCallback[13] = ACT1Q1_Callback13_PlayerStartedGame;

    pQuestData->pNPCMessages = &gpAct1Q1NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 1;
    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act1Quest1Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q1.cpp", 750, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->nQuestFilter = QUESTSTATEFLAG_A1Q1;
    pQuestData->unk0xE4 = 0x29;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT1Q1_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT1Q1_SeqCallback;
    pQuestData->nSeqId = 2;

    memset(pQuestDataEx, 0x00, sizeof(D2Act1Quest1Strc));
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->pQuestGUID);
}

#include "gen/data/Source/D2Game/00590260_ACT1Q1_Callback08_MonsterKilled.inc"
