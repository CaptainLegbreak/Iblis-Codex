extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();

struct D2BitBufferStrc;
struct D2ActiveRoomStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x6D - 0x20];
    unsigned char nDifficulty;
    char unk0x6E[0xA8 - 0x6E];
    int dwGameFrame;
};

struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

struct D2QuestGUIDStrc
{
    int nPlayerGUIDs[32];
    short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2Act1Quest5Strc
{
    int nUnitGUIDs1[12];
    unsigned short nUnitCount1;
    unsigned char pad0x32[2];
    int nUnitGUIDs2[12];
    unsigned short nUnitCount2;
    unsigned char pad0x66[2];
    int nObjectGUIDs[8];
    unsigned short nCountessChestCount;
    unsigned char pad0x8A[2];
    D2QuestGUIDStrc tPlayerGUIDs;
    D2CoordStrc pCoord;
    unsigned char bCountessKilled;
    unsigned char bDeathMissilesCreated;
    unsigned char bTriggerSeqFilter;
    unsigned char bTowerTomeActivated;
    unsigned char unk0x11C;
    unsigned char pad0x11D[3];
};

struct D2QuestDataStrc;

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

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);
typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

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
    D2Act1Quest5Strc* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern char gpAct1Q5NpcMessages[];                                                                          // 0x00737ED8

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);           // 0x00543F10
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID);                                   // 0x00545300
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct);              // 0x00545920
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
int __fastcall ACT1Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x00594830
void __fastcall ACT1Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x00594960
void __fastcall ACT1Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00594BB0
void __fastcall ACT1Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x00594C50
int __fastcall ACT1Q5_UnitIterate_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);      // 0x00594DD0
int __fastcall ACT1Q5_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00594F10
void __fastcall ACT1Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x00595010
bool __fastcall ACT1Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005952C0
void __fastcall sub_00595420_UpdatePlayerListQuestState(D2GameStrc* pGame, D2QuestGUIDStrc* pQuestGUID, int nQuestId, int nSoundId); // 0x00595420
void __stdcall ACT1Q5_SpawnTowerChestMissiles(D2QuestDataStrc* pQuestData, D2Act1Quest5Strc* pQuestDataEx); // 0x005954F0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// 0x00595240
bool __fastcall ACT1Q5_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState < 2 && pQuestData->bNotIntro == 1)
    {
        return true;
    }
    if (pQuestData->fState != 5 && pQuestData->bNotIntro)
    {
        return true;
    }
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 736);
        return pQuest->pfSeqFilter(pQuest);
    }
    return false;
}

// 0x00595320
int __fastcall ACT1Q5_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 0) == 1)
    {
        return 0;
    }
    QUESTRECORD_SetQuestState(pQuestFlags, 5, 14);
    QUESTS_SendLogUpdateEx(pUnit, 5, 0);
    return 0;
}

// 0x00595370
void __fastcall ACT1Q5_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 0) == 1)
    {
        return;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId && DRLG_GetActNoFromLevelId(nLevelId) == 0)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 5, 13);
        QUESTRECORD_SetQuestState(pQuestFlags, 5, 0);
    }
}

// 0x005953D0
int __fastcall ACT1Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 5, 13))
    {
        return 0;
    }
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT1Q5_UnitIterate_SetPrimaryGoalDone, 0);
    }
    return 0;
}

// 0x005954C0
bool __fastcall ACT1Q5_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act1Quest5Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (pQuestData->fState == 5)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 13, 0, ACT1Q5_UnitIterate_StatusCyclerEx, 1);
    }
    pQuestDataEx->unk0x11C = 0;
    return true;
}

// 0x00595710
void __fastcall ACT1Q5_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act1Quest5Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    UNITS_GetCoords(pQuestArg->pTarget, &pQuestDataEx->pCoord);
    if (pQuestData->bNotIntro)
    {
        QUESTS_DebugOutput(pQuestData->pGame, "Finished quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 945);
        pQuestData->pfCallback[2] = 0;
        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 947);
        pQuestDataEx->bTriggerSeqFilter = 1;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q5_UnitIterate_AttachCompletionSound);
        QUESTS_SetGlobalState(pQuestData->pGame, 5, 13);
        if (!pQuestData->pQuestDataEx->nUnitCount2)
        {
            pQuestData->bActive = 0;
        }
        else
        {
            pQuestData->pfCallback[10] = ACT1Q5_Callback10_PlayerLeavesGame;
        }
        pQuestDataEx->bCountessKilled = 1;
        pQuestData->pfCallback[8] = 0;
        QUESTS_SetGlobalState(pQuestArg->pGame, pQuestData->nQuestFilter, 13);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q5_UnitIterate_SetRewardGranted);
        sub_00595420_UpdatePlayerListQuestState(pQuestArg->pGame, &pQuestDataEx->tPlayerGUIDs, pQuestData->nQuestFilter, 37);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q5_UnitIterate_SetCompletionFlag);
        QUESTS_CreateTimer(pQuestData, ACT1Q5_Timer_StatusCycler, 7);
    }
    ACT1Q5_SpawnTowerChestMissiles(pQuestData, pQuestDataEx);
    if (!pQuestDataEx->bDeathMissilesCreated)
    {
        EVENT_SetEvent(pQuestData->pGame, pQuestArg->pTarget, 7, pQuestData->pGame->dwGameFrame + 10, 0, 0);
    }
}

// 0x00595860
void __fastcall ACT1Q5_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 15))
    {
        return;
    }
    if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 4) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 6) == 1)
    {
        pQuestData->fLastState = 4;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 5) == 1)
    {
        pQuestData->fLastState = 3;
        pQuestData->fState = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 3) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 2) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x00595920
void __fastcall ACT1Q5_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[3] = ACT1Q5_Callback03_ChangedLevel;
    pQuestData->pfCallback[11] = ACT1Q5_Callback11_ScrollMessage;
    pQuestData->pfCallback[0] = ACT1Q5_Callback00_NpcActivate;
    pQuestData->pfCallback[10] = ACT1Q5_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[8] = ACT1Q5_Callback08_MonsterKilled;
    pQuestData->pfCallback[13] = ACT1Q5_Callback13_PlayerStartedGame;
    pQuestData->nQuestFilter = 5;
    pQuestData->pNPCMessages = gpAct1Q5NpcMessages;
    pQuestData->fLastState = 0;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT1Q5_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT1Q5_SeqCallback;
    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act1Quest5Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 1039, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->nSeqId = 3;
    memset(pQuestDataEx, 0x00, sizeof(D2Act1Quest5Strc));
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

// 0x00595A00
void __fastcall OBJECTS_InitFunction04_TowerTome(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 5);
    if (pQuestData)
    {
        if (!pQuestData->bNotIntro)
        {
            UNITS_ChangeAnimMode(pOp->pObject, 3);
        }
        return;
    }
    D2_ASSERT(pQuestData, 1059);
}

#include "gen/data/Source/D2Game/00595240_ACT1Q5_SeqCallback.inc"
