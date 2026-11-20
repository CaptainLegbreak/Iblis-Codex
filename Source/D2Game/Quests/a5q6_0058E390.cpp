#include "D2Game.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"



struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);


struct D2Act5Quest6Strc
{
    D2QuestGUIDStrc tPlayerGUIDs;
    char unk0x84[0x86 - 0x84];
    unsigned char bWorldStoneChamberOpen;
    char unk0x87[0x90 - 0x87];
    unsigned char bQuestStarted;
    char unk0x91[0x94 - 0x91];
    int nBaalPortalObjectMode;
    char unk0x98[0x9C - 0x98];
    int nLastPortalObjectMode;
    char unk0xA0[0xA8 - 0xA0];
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* hObject;
    D2UnitStrc* hPlayer;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
extern char gpAct5Q6NpcMessages[];                                                                          // 0x00735800

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID);                                   // 0x00545300
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty);      // 0x00538680
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
int __fastcall ACT5Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x0058D770
void __fastcall ACT5Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x0058D870
void __fastcall sub_0058D940_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x0058D940
void __fastcall ACT5Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x0058D9F0
void __fastcall ACT5Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058DCF0
void __fastcall sub_0058DF20_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x0058DF20
void __fastcall ACT5Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x0058E190
bool __fastcall ACT5Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0058E2B0
void __fastcall ACT5Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT5Q6_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
bool __fastcall ACT5Q6_SeqCallback(D2QuestDataStrc* pQuestData);

// 0x0058E390
bool __fastcall ACT5Q6_SeqCallback(D2QuestDataStrc* pQuestData)
{
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 36);

    if (pQuest->bNotIntro && !pQuest->fState)
    {
        ((D2Act5Quest6Strc*)pQuest->pQuestDataEx)->bQuestStarted = 1;
        pQuest->fState = 2;
        pQuest->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuest, 1, 0, ACT5Q6_UnitIterate_StatusCyclerEx, 1);
        SUNIT_IterateUnitsOfType(pQuest->pGame, 0, 0, ACT5Q6_UnitIterate_UpdateQuestStateFlags);
    }

    return true;
}

// 0x0058E3F0
void __fastcall ACT5Q6_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 10);
    }
}

// 0x0058E430
void __fastcall ACT5Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 10);
        CLIENTS_UpdateCharacterProgression(UnitGetClient(pQuestArg->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 766), 5, pQuestData->pGame->nDifficulty);
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) != 1)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 3) == 1)
        {
            pQuestData->fLastState = 1;
            pQuestData->fState = 3;
        }
        else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 2) == 1)
        {
            ((D2Act5Quest6Strc*)pQuestData->pQuestDataEx)->bQuestStarted = 1;
            pQuestData->fLastState = 1;
            pQuestData->fState = 3;
        }
    }
}

// 0x0058E500
void __fastcall ACT5Q6_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[10] = ACT5Q6_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT5Q6_Callback03_ChangedLevel;
    pQuestData->pCallback[8] = sub_0058DF20_MonsterKilled;
    pQuestData->pCallback[0] = ACT5Q6_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT5Q6_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = sub_0058D940_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT5Q6_Callback13_PlayerStartedGame;
    pQuestData->pCallback[14] = ACT5Q6_Callback14_PlayerJoinedGame;
    pQuestData->pNPCMessages = gpAct5Q6NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest6Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 809, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = 40;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT5Q6_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT5Q6_SeqCallback;
    pQuestData->nSeqId = 37;
    memset(pQuestDataEx, 0x00, sizeof(D2Act5Quest6Strc));
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
    pQuestDataEx->nBaalPortalObjectMode = 1;
    pQuestDataEx->nLastPortalObjectMode = 1;
}

// 0x0058E670
void __fastcall OBJECTS_InitFunction75_BaalsPortal(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)QUESTS_GetQuestData(pOp->pGame, 36)->pQuestDataEx;

    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nBaalPortalObjectMode);
    pQuestDataEx->nBaalPortalObjectMode = 2;
}

// 0x0058E6A0
int __fastcall OBJECTS_OperateFunction70_BaalPortal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 36);
    if (!pQuestData)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hPlayer);
    if (!pRoom)
    {
        return 0;
    }

    if (DUNGEON_GetLevelIdFromRoom(pRoom) == 131)
    {
        if (((D2Act5Quest6Strc*)pQuestData->pQuestDataEx)->bWorldStoneChamberOpen == 1)
        {
            LEVEL_WarpUnit(pOp->pGame, pOp->hPlayer, 132, 11);
        }
    }
    else
    {
        LEVEL_WarpUnit(pOp->pGame, pOp->hPlayer, 131, 0);
    }

    return 0;
}

// 0x0058E710
void __fastcall OBJECTS_InitFunction77_LastPortal(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)QUESTS_GetQuestData(pOp->pGame, 36)->pQuestDataEx;

    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nLastPortalObjectMode);
    pQuestDataEx->nLastPortalObjectMode = 2;
}

#include "gen/data/Source/D2Game/Quests/a5q6_0058E390.inc"
