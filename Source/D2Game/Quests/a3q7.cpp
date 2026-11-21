#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"




typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);




extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005BD0B0
bool __fastcall ACT3Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005BD0C0
void __fastcall ACT3Q7_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

// 0x005BD1F0
void __fastcall OBJECTS_InitFunction43_DarkWanderer(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 28);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest7Strc* pQuestDataEx = (D2Act3Quest7Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bPrimaryGoalOpen)
    {
        pQuestDataEx->bDarkWandererInitialized = 1;
        return;
    }

    pQuestDataEx->nDarkWandererX = pOp->nX + 7;
    pQuestDataEx->nDarkWandererY = pOp->nY;

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(pOp->pRoom, pQuestDataEx->nDarkWandererX, pQuestDataEx->nDarkWandererY);
    if (D2GAME_SpawnMonster_6FC69F10(pOp->pGame, pRoom, pQuestDataEx->nDarkWandererX, pQuestDataEx->nDarkWandererY, MONSTER_DARKWANDERER, 1, -1, 0))
    {
        pQuestDataEx->bPrimaryGoalOpen = 0;
    }
    pQuestDataEx->bDarkWandererInitialized = 1;
}

// 0x005BD260
int __fastcall ACT3Q7_UnitIterate_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 32, 0) || !UNITS_GetRoom(pUnit))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId && DRLG_GetActNoFromLevelId(nLevelId) == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 32, 0);
    }

    return 0;
}

// 0x005BD2C0
void __fastcall ACT3Q7_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 32, 0) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, 32, 13);
        ((D2Act3Quest7Strc*)pQuestData->pQuestDataEx)->bPrimaryGoalOpen = 0;
    }
}

// 0x005BD300
void __fastcall ACT3Q7_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[13] = ACT3Q7_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = 0;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest7Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q7.cpp", 185, 0);
    memset(pQuestData->pQuestDataEx, 0x00, sizeof(D2Act3Quest7Strc));
    pQuestData->eFilter = 16;
    pQuestData->pfStatusFilter = ACT3Q7_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT3Q7_ActiveFilterCallback;
    ((D2Act3Quest7Strc*)pQuestData->pQuestDataEx)->bPrimaryGoalOpen = 1;
}
