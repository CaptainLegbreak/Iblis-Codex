#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameServer.h"

struct D2UnkMonCreateStrc;
struct D2PlayerDataStrc;
struct D2Act4Quest1Strc;

D2UnitStrc* __fastcall D2GAME_SpawnNormalMonster_6FC68E30(D2UnkMonCreateStrc* pMonCreate); // 0x005B2A00

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion); // 0x0058F100
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
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
        int nOldLevel;
        unsigned short nNpcId;
    };
    unsigned short nMessageId;
    unsigned char unk_1A[0x2];
};

struct D2Act4Quest1Strc
{
    char unk0x00[0x0C];
    unsigned char unk0x0C;
    unsigned char unk_0D[0x2];
    unsigned char bGhostActivated;
    unsigned char unk10;
    unsigned char bTyraelActivated;
    unsigned char bGhostTold;
    unsigned char unk_13[0x9];
};

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

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
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    QUESTCALLBACK pCallback[15];
    void* pNPCMessages;
    int eFilter;
    int unk0xE4;
    void* pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern "C" const char gszAct4Q2SourceFile[]; // 0x006E2DA4
extern char gpAct4Q1NpcMessages[]; // 0x0073D708
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190
int __fastcall ACT4Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3860
int __fastcall ACT4Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pData); // 0x005B3940
void __fastcall ACT4Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B3E30
void __fastcall ACT4Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B4020
void __fastcall ACT4Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B3BB0
void __fastcall ACT4Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B39A0
void __fastcall ACT4Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT4Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT4Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
bool __fastcall ACT4Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B37F0
bool __fastcall ACT4Q1_SeqCallback(D2QuestDataStrc* pQuestData); // 0x005B38E0
void __fastcall sub_005B4DA0_ACT4Q2_UnitIterate_SetCompleted(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B4DA0
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void*);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
void __fastcall QUESTS_SetGlobalState(D2GameStrc*, int, int); // 0x00544720
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x00545780
void __fastcall QUESTS_SendLogUpdate(D2UnitStrc*, int); // 0x005458E0
void __fastcall QUESTS_AddPlayerGUID(void*, int); // 0x00545200
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc*, int, int); // 0x0065C3A0
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc*, int); // 0x0065C3E0
void __stdcall STATLIST_AddUnitStat(D2UnitStrc*, int, int, int); // 0x006272B0

// 0x005B31B0
int __fastcall sub_6FC6A230(D2GameStrc* pGame, D2UnitStrc* pOwner, int nX, int nY, int nMonsterId, int nAnimMode, int a5, int nCount, short nFlags)
{
    int nResult = 0;
    if (!pOwner)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOwner);
    const int nOwnerId = pOwner->dwUnitId;
    for (int i = 0; i < nCount; ++i)
    {
        D2UnkMonCreateStrc monCreate;
        monCreate.nUnitGUID = 0;
        monCreate.nMonsterId = nMonsterId;
        monCreate.nAnimMode = nAnimMode;
        monCreate.pGame = pGame;
        monCreate.pRoomCoordList = 0;
        monCreate.pRoom = pRoom;
        monCreate.unk0x20 = a5;
        monCreate.nFlags = nFlags;
        monCreate.nX = nX;
        monCreate.nY = nY;

        D2UnitStrc* pMinion = D2GAME_SpawnNormalMonster_6FC68E30(&monCreate);
        if (pMinion)
        {
            nResult = 1;
            AIGENERAL_SetOwnerData(pGame, pMinion, nOwnerId, 1, 0, 0);
            AIGENERAL_AllocMinionList(pGame, pOwner, pMinion);
        }
    }

    return nResult;
}

// 0x005B39A0
void __fastcall ACT4Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
    D2GameStrc* pGame = pQuestData->pGame;
    unsigned short nNpcId = pQuestArg->nNpcId;
    unsigned short nMessageId = pQuestArg->nMessageId;
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (nNpcId == 0x16F)
    {
        if (nMessageId == 0x29E)
        {
            pQuestDataEx->bTyraelActivated = 1;
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 0xD3);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q1_UnitIterate_UpdateQuestStateFlags);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            return;
        }
        if (nMessageId == 0x2A4 && QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 1))
        {
            if (QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 13))
            {
                if (pQuestData->fState != 5)
                {
                    QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 0xDE);
                    if (IsBadCodePtr((void*)pQuestData->pfSeqFilter))
                    {
                        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xDF);
                        exit(-1);
                    }
                    pQuestData->pfSeqFilter(pQuestData);
                    pQuestData->dwFlags &= 0xFFFFFF00;
                    QUESTS_UnitIterate(pQuestData, 13, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 0);
                }
                pQuestData->pCallback[2] = 0;
                QUESTS_SetGlobalState(pQuestArg->pGame, pQuestData->eFilter, 13);
            }
            QUESTRECORD_SetQuestState(pFlags, pQuestData->eFilter, 0);
            QUESTRECORD_ClearQuestState(pFlags, pQuestData->eFilter, 1);
            QUESTRECORD_ResetIntermediateStateFlags(pFlags, pQuestData->eFilter);
            STATLIST_AddUnitStat(pQuestArg->pPlayer, 5, 2, 0);
            QUESTS_SendLogUpdate(pQuestArg->pPlayer, 22);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
    else if (nNpcId == 0x196 && nMessageId == 0x2A3)
    {
        pQuestDataEx->bGhostTold = 1;
        pQuestDataEx->bGhostActivated = 1;
        QUESTRECORD_SetQuestState(pFlags, pQuestData->eFilter, 5);
        if (pQuestData->fLastState != 4)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 4, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 1);
        }
    }
}

// 0x005B4140
void __fastcall ACT4Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nOldLevel != 103)
    {
        return;
    }
    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1)
    {
        return;
    }
    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 571);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q1_UnitIterate_UpdateQuestStateFlags);
    if (!pQuestData->fLastState)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 0);
    }
}

// 0x005B41D0
void __fastcall ACT4Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != 367)
    {
        return;
    }
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bTyraelActivated != 1)
    {
        return;
    }
    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 1);
    pQuestDataEx->bTyraelActivated = 0;
    pQuestData->pCallback[2] = 0;
}

// 0x005B4220
void __fastcall ACT4Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15))
    {
        return;
    }
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 4) == 1)
    {
        D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->unk0x0C = 1;
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 3) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 2) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x005B42B0
void __fastcall ACT4Q1_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->bActive = 1;
    pQuestData->fState = 1;
    pQuestData->pNPCMessages = gpAct4Q1NpcMessages;
    pQuestData->pCallback[10] = ACT4Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT4Q1_Callback03_ChangedLevel;
    pQuestData->pCallback[8] = ACT4Q1_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT4Q1_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT4Q1_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT4Q1_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT4Q1_Callback13_PlayerStartedGame;
    pQuestData->eFilter = 25;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pfActiveFilter = ACT4Q1_ActiveFilterCallback;
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act4Quest1Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 672, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->pfSeqFilter = ACT4Q1_SeqCallback;
    pQuestData->nSeqId = 24;
    memset(pQuestDataEx, 0x00, sizeof(D2Act4Quest1Strc));
}

// 0x005B4530
bool __fastcall ACT4Q2_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 145);
    }
    return 1;
}

// 0x005B4560
int __fastcall ACT4Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) == 1)
    {
        return 0;
    }
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (!pQuestData)
    {
        return 0;
    }
    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 26, 2);
        return 0;
    }
    if (pQuestData->fState == 3)
    {
        if (pQuestData->fLastState == 1)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 26, 3);
            return 0;
        }
        QUESTRECORD_SetQuestState(pQuestFlags, 26, 4);
    }
    return 0;
}

// 0x005B4970
int __fastcall ACT4Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) == 1)
    {
        return 0;
    }
    QUESTRECORD_SetQuestState(pQuestFlags, 26, 14);
    QUESTS_SendLogUpdateEx(pUnit, 23, 0);
    return 0;
}

// 0x005B4DF0
int __fastcall ACT4Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 13))
    {
        return 0;
    }
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, sub_005B4DA0_ACT4Q2_UnitIterate_SetCompleted, 0);
    }
    return 0;
}

// 0x005B4E40
int __fastcall ACT4Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 26, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 26, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 26, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 23);
    }
    return 0;
}

#include "gen/data/Source/D2Game/Quests/a4q1_005B31B0.inc"
struct D2GameStrc;
struct D2UnitStrc;
