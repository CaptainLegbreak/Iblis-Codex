extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2TextHeaderStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2GameStrc
{
    char pad0x00[0x6D];
    unsigned char nDifficulty;
    char pad0x6E[0xBC - 0x6E];
    void* pAct[5];
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
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    union
    {
        D2TextHeaderStrc* pTextControl;
        unsigned short nNPCNo;
        int nOldLevel;
    };
    union
    {
        unsigned short nMessageIndex;
        int nNewLevel;
    };
};

struct D2Act4Quest1Strc
{
    int unused0x00;
    D2CoordStrc pCoords;
    unsigned char unk0x0C;
    unsigned char bIzualGhostIsSpawning;
    unsigned char unused0x0E;
    unsigned char unk0x0F;
    unsigned char bNeedToSpawnIzualGhost;
    unsigned char bTyraelActivated;
    unsigned char bIzualGhostActivated;
    unsigned char pad0x13;
    D2UnitStrc* pTargetUnit;
    unsigned char bCloseToIzualGhost;
    unsigned char pad0x19[3];
};

struct D2QuestDataStrc;
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern char gpAct4Q0NpcMessages[];                                                                          // 0x0073D580
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestRecord, int nQuest);         // 0x0065C3E0
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct);              // 0x00545920
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
D2ActiveRoomStrc* __stdcall sub_00619DA0_ActLookup(void* pAct, int a2, int a3);                              // 0x00619DA0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
bool __fastcall ACT4Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B3750
bool __fastcall ACT4Q0_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005B3740
int __fastcall ACT4Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pData);      // 0x005B3940

// 0x005B36A0
void __fastcall ACT4Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nNPCNo == 367 && pQuestArg->nMessageIndex == 664)
    {
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, 24, 0);
    }
}

// 0x005B36D0
void __fastcall ACT4Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pTarget = pQuestArg->pTarget;
    if (!pTarget || pTarget->dwClassId != 367)
    {
        return;
    }

    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 24, 0))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId, 0);
    }
}

// 0x005B3780
void __fastcall ACT4Q0_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[0] = ACT4Q0_Callback00_NpcActivate;
    pQuestData->pfCallback[11] = ACT4Q0_Callback11_ScrollMessage;
    pQuestData->pNPCMessages = gpAct4Q0NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->nQuestFilter = 24;
    pQuestData->pfStatusFilter = ACT4Q0_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT4Q0_ActiveFilterCallback;
}

// 0x005B3860
int __fastcall ACT4Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 22);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 25, 2);
        return 0;
    }

    if (pQuestData->fState == 3)
    {
        if (pQuestDataEx->unk0x0C)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 25, 4);
            return 0;
        }
        QUESTRECORD_SetQuestState(pQuestFlags, 25, 3);
    }

    return 0;
}

// 0x005B38E0
bool __fastcall ACT4Q1_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != 5 && pQuestData->bNotIntro)
    {
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pfSeqFilter), 0xA1);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x005B3CD0
int __fastcall ACT4Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, 25, 1) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 25, 14);
        QUESTS_SendLogUpdateEx(pUnit, 22, 0);
    }

    return 0;
}

// 0x005B3D30
int __fastcall ACT4Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 13))
    {
        SUNIT_AttachSound(pUnit, 74, pUnit);
    }

    return 0;
}

// 0x005B3D70
void __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 25, 1))
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 3)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 25, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 25, 1);
    QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, 25);
}

// 0x005B3E60
bool __fastcall ACT4Q1_SpawnIzualGhost(D2GameStrc* pGame, D2QuestDataStrc* pQuest)
{
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuest->pQuestDataEx;
    if (pQuest->fState == 4 && pQuest->fLastState != 4 && pQuest->fLastState != 13)
    {
        pQuest->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuest, 3, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 1);
    }

    if (pQuestDataEx->bNeedToSpawnIzualGhost)
    {
        pQuestDataEx->bNeedToSpawnIzualGhost = 0;

        D2ActiveRoomStrc* pRoom = sub_00619DA0_ActLookup(pGame->pAct[3], pQuestDataEx->pCoords.nX, pQuestDataEx->pCoords.nY);
        if (pRoom)
        {
            if (!D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, pQuestDataEx->pCoords.nX, pQuestDataEx->pCoords.nY, 406, 8, -1, 0)
                && !D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, pQuestDataEx->pCoords.nX, pQuestDataEx->pCoords.nY, 406, 8, 3, 0))
            {
                D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, pQuestDataEx->pCoords.nX, pQuestDataEx->pCoords.nY, 406, 8, 5, 0);
            }
        }
    }

    pQuestDataEx->bIzualGhostIsSpawning = 0;
    return 1;
}

#include "gen/data/Source/D2Game/005B36A0_ACT4Q0_Callback11_ScrollMessage.inc"
