#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2PlayerDataStrc;
struct D2ItemsTxt;
struct D2Act3Quest5Strc;

typedef int (__stdcall* FARPROC)();

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4A];
    unsigned char nGameType;
    char unk0x6B[0x02];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
    char unk0xAC[0x10];
    void* pAct[5];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xD4];
    D2UnitStrc* pRoomNext;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuest);

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

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
    void* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
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
    unsigned int unk0x10;
    int nOldLevel;
    int nNewLevel;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
};

struct D2Act3Quest5Strc
{
    char unk0x00[0x05];
    unsigned char bMonstersSpawned;
    unsigned char unk_06[0x2];
    int bQuest1RewardGranted;
    unsigned char bOrbSmashed;
    char bFlailDropped[0x2F];
    int nFlailsMissing;
    int nHoradricCubesMissing;
    unsigned char unk_44[0xC];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern char gpAct3Q5NpcMessages[]; // 0x007408B8
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId); // 0x00544190
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

// 0x005BBEB0
void __fastcall ACT3Q5_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pNPCMessages = gpAct3Q5NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->pfCallback[8] = ACT3Q5_Callback08_MonsterKilled;
    pQuestData->pfCallback[0] = ACT3Q5_Callback00_NpcActivate;
    pQuestData->pfCallback[11] = ACT3Q5_Callback11_ScrollMessage;
    pQuestData->pfCallback[3] = ACT3Q5_Callback03_ChangedLevel;
    pQuestData->pfCallback[13] = ACT3Q5_Callback13_PlayerStartedGame;
    pQuestData->pfCallback[10] = ACT3Q5_Callback10_PlayerLeavesGame;
    pQuestData->pfSeqFilter = ACT3Q5_SeqCallback;
    pQuestData->nSeqId = 20;
    pQuestData->fState = 0;
    pQuestData->nQuestFilter = 21;
    pQuestData->pfActiveFilter = ACT3Q5_ActiveFilterCallback;
    pQuestData->nInitNo = 6;
    pQuestData->pfStatusFilter = 0;

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest5Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 1061, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest5Strc));
    memset(pQuestData->pQuestDataEx, 0x00, sizeof(D2Act3Quest5Strc));
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
        pQuestData->pfCallback[2] = ACT3Q5_Callback02_NpcDeactivate;
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
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 4) == 1)
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
