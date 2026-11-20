#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2MapAIPathPositionStrc;
struct D2ObjectControlStrc;
struct D2PlayerDataStrc;
struct D2Act5Quest3Strc;
struct D2Act5Quest5Strc;
struct D2Act5Quest6Strc;
struct D2QuestGUIDStrc;
struct D2ObjInitFnStrc;




typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);



struct D2Act5Quest3Strc
{
    D2QuestGUIDStrc tPlayerGUIDs;
    int unk0x84;
    int unk0x88;
    char pad0x8C[0x6];
    unsigned char bNilathakOutsideTownSpawned;
    unsigned char bNihlathakMonsterInTownSpawned;
    char pad0x94[0x8];
    int NihlathakMonsterInTownGUID;
    int nNihlathakOutsideTownGUID;
    unsigned char bFrozenAnyaObjectSpawned;
    char pad0xA5[0x3];
    int nFrozenDrehyaObjectGUID;
    unsigned char unk_AC[0x2];
    unsigned char bChangeToSpecialObjectModeInTown;
    unsigned char bUnk0xAF;
    unsigned char unk_B0[0x1];
    unsigned char bDrehyaPortalOutsideTownSpawned;
    char pad0xB2[0xE];
    int nDrehyaPortalOutsideTownGUID;
    D2CoordStrc pDrehyaPortalCoords;
    char pad0xCC[0xC];
    int nDefrostPotionsInGame;
    char pad0xDC[0x4];
    unsigned char bDrehyaPortalCoordsInitialized;
    char pad0xE1[0x1];
    unsigned char bDefrostPotionAcquired;
    char pad0xE3[0x15];
    int nDrehyaObjectOutsideTownGUID;
    int nFrozenAnyaObjectGUID;
    char pad0x100[0x8];
    D2MapAIStrc* pNilathakMapAI;
    char pad0x10C[0x1];
    unsigned char bNilathakMapAIChanged;
    char pad0x10E[0x2];
    int nNihlathakObjectInTownGUID;
};

struct D2Act5Quest5Strc
{
    unsigned char bAncientsDefeated;
    unsigned char unk0x01[0x0B];
    int nActivePortalCount;
    unsigned char unk0x10;
    unsigned char bActivatable;
};

struct D2Act5Quest6Strc
{
    char unk0x00[0x86];
    unsigned char bWorldStoneChamberOpen;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0
void __fastcall ACT5Q3_UpdateResistances(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue); // 0x00589FF0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall ACT5Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00588EB0
int __fastcall ACT5Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058AEA0
int __fastcall ACT5Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058D770
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    D2ObjectControlStrc* pObjectregion;
    D2ObjectsTxt* pObjectTxt;
    int nX;
    int nY;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern char gpAct5Q3NpcMessages[]; // 0x00734320
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
void __fastcall ACT5Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00589D20
void __fastcall ACT5Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00589D80
void __fastcall ACT5Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00589B00
void __fastcall ACT5Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00588F80
void __fastcall ACT5Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00589580
void __fastcall ACT5Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT5Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
bool __fastcall ACT5Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0058A300
bool __fastcall ACT5Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00589F10
bool __fastcall ACT5Q3_SeqCallback(D2QuestDataStrc* pQuestData); // 0x00589160

struct D2MapAIStrc
{
    int nPathNodes;
    D2MapAIPathPositionStrc* pPosition;
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __fastcall sub_005459A0_SpawnMonsterNear(D2GameStrc* pGame, int nX, int nY, D2ActiveRoomStrc* pRoom, int a5, int nMonsterId); // 0x005459A0
extern "C" D2MapAIStrc* __stdcall sub_0058F000(D2UnitStrc* pUnit); // 0x0058F000
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2); // 0x00666120
D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600

// 0x0058A0A0
void __fastcall ACT5Q3_ApplyResistanceReward(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nValue = 0;
    if (QUESTRECORD_GetQuestState(UNITS_GetPlayerData(pUnit)->pQuestData[0], 0x25, 7))
    {
        nValue = 10;
    }

    if (QUESTRECORD_GetQuestState(UNITS_GetPlayerData(pUnit)->pQuestData[1], 0x25, 7))
    {
        nValue += 10;
    }

    if (QUESTRECORD_GetQuestState(UNITS_GetPlayerData(pUnit)->pQuestData[2], 0x25, 7))
    {
        nValue += 10;
    }

    if (nValue)
    {
        ACT5Q3_UpdateResistances(pGame, pUnit, nValue);
    }
}

// 0x0058A9F0
int __fastcall sub_0058A9F0_ACT5Q3_IsDrehyaStateZero(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x21);
    if (!pQuestData)
    {
        return 0;
    }

    return ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->unk0x84 == 0;
}

// 0x0058AA10
void __fastcall sub_0058AA10_ACT5Q3_UpdateStatusOnActivate(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x21);
    if (pQuestData && pQuestData->bNotIntro && pQuestData->fLastState < 2)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x0058BC00
void __fastcall ACT5Q4_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_SetQuestState(pQuestFlags, 0x26, 0);
    QUESTRECORD_ClearQuestState(pQuestFlags, 0x26, 1);

    QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0x0F);
}

// 0x0058BC40
void __fastcall ACT5Q4_OnNihlathakActivated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x22);
    if (!pQuestData || !pQuestData->bNotIntro || pQuestData->fLastState >= 3)
    {
        return;
    }

    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);
}

// 0x0058CF50
void __fastcall ACT5Q5_OnPortalClosed(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (DUNGEON_GetLevelIdFromRoom(pRoom) != 0x78)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    --((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->nActivePortalCount;
    if (!((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->nActivePortalCount && ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->unk0x10)
    {
        ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bActivatable = 1;
    }
}

// 0x0058CF90
int __fastcall ACT5Q5_IsNotActivatable(D2GameStrc* pGame)
{
    return ((D2Act5Quest5Strc*)QUESTS_GetQuestData(pGame, 0x23)->pQuestDataEx)->bActivatable == 0;
}

// 0x0058D090
int __fastcall ACT5Q5_IsArreatSummitClosed(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetLevel)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    if (!pQuestData->bNotIntro)
    {
        return 0;
    }

    return ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bAncientsDefeated == 0;
}

// 0x0058E600
void __fastcall ACT5Q6_OpenWorldStoneChamber(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x24);
    if (!pQuestData)
    {
        return;
    }

    ((D2Act5Quest6Strc*)pQuestData->pQuestDataEx)->bWorldStoneChamberOpen = 1;

    if (pQuestData->bNotIntro && pQuestData->fLastState < 3)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q6_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x0058E640
int __fastcall ACT5Q6_IsWorldStoneChamberClosed(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x24);
    if (pQuestData && ((D2Act5Quest6Strc*)pQuestData->pQuestDataEx)->bWorldStoneChamberOpen == 1)
    {
        return 0;
    }

    return 1;
}

// 0x0058FD20
void __fastcall sub_0058FD20_ACT1Q1_SetRespecRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_SetQuestState(pQuestFlags, 0x29, 0x0D);
    QUESTRECORD_SetQuestState(pQuestFlags, 0x29, 1);
}

// 0x0058FD50
void __fastcall sub_0058FD50_ACT1Q1_SetRespecRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_SetQuestState(pQuestFlags, 0x29, 0);
    QUESTRECORD_ClearQuestState(pQuestFlags, 0x29, 1);

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x29, 0x0F))
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x1E);
        D2_ASSERT(pQuestData, 0xE1);

        pQuestData->bActive = 0;

        QUESTS_DebugOutput(pGame, "deactivated respec quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q1.cpp", 0xE5);
    }
}

// 0x00591790
void __fastcall ACT1Q3_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_SetQuestState(pQuestFlags, 3, 0);
    QUESTRECORD_ClearQuestState(pQuestFlags, 3, 1);

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 3, 0x0F))
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 3);
        D2_ASSERT(pQuestData, 0x160);

        pQuestData->bActive = 0;

        QUESTS_DebugOutput(pGame, "deactivated tools of trade", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", 0x164);
    }
}

// 0x0058A110
void __fastcall ACT5Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (ITEMS_FindQuestItem(pQuestData->pGame, pQuestArg->pPlayer, 0x20656369))
    {
        pQuestDataEx->nDefrostPotionsInGame = 1;
    }
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15))
    {
        pQuestDataEx->unk0x84 = 2;
        pQuestDataEx->unk0x88 = 1;
        return;
    }
    if (!pQuestData->bNotIntro)
    {
        return;
    }
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 3))
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 2))
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
    if (pQuestDataEx->nDefrostPotionsInGame)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 4;
    }
}

// 0x0058A1E0
void __fastcall ACT5Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20656369))
    {
        ++((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->nDefrostPotionsInGame;
    }
    if (pQuestData->bNotIntro && pQuestData->fState < 5)
    {
        return;
    }
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 34);
    if (!pQuest)
    {
        return;
    }
    if (!pQuest->bNotIntro)
    {
        return;
    }
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 37, 1)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 37, 6)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 37, 0))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 38, 14);
    }
}

// 0x0058A270
void __fastcall ACT5Q3_UnitIterate_CheckForDefrostPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (!ITEMS_FindQuestItem(pGame, pUnit, 0x20656369))
    {
        return;
    }
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 3);
    if (pQuestData)
    {
        ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->bDefrostPotionAcquired = 1;
    }
}

// 0x0058A410
void __fastcall ACT5Q3_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[10] = ACT5Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT5Q3_Callback03_ChangedLevel;
    pQuestData->pCallback[0] = ACT5Q3_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT5Q3_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT5Q3_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT5Q3_Callback13_PlayerStartedGame;
    pQuestData->pCallback[14] = ACT5Q3_Callback14_PlayerJoinedGame;
    pQuestData->pNPCMessages = gpAct5Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest3Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 1482, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = 37;
    pQuestData->pfStatusFilter = ACT5Q3_StatusFilterCallback;
    pQuestData->nInitNo = 5;
    pQuestData->pfActiveFilter = ACT5Q3_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT5Q3_SeqCallback;
    pQuestData->nSeqId = 34;
    memset(pQuestDataEx, 0x00, sizeof(D2Act5Quest3Strc));
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
    pQuestDataEx->unk0x84 = 0;
    pQuestDataEx->unk0x88 = 0;
}

// 0x0058A5B0
void __fastcall OBJECTS_InitFunction67_DrehyaStartOutsideTown(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 33);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return;
    }
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->nDrehyaObjectOutsideTownGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    if (!pQuestDataEx->bFrozenAnyaObjectSpawned)
    {
        sub_005417D0_DirectDated(pQuestData->pGame, pOp->pObject, 7, pQuestData->pGame->dwGameFrame + 25, 0, 0);
    }
}

// 0x0058A820
int __fastcall ACT5Q3_SpawnDrehyaPortalOutsideTown(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
    if (!pQuestData)
    {
        return 0;
    }
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bDrehyaPortalOutsideTownSpawned)
    {
        return 1;
    }
    if (!pQuestDataEx->unk0x84)
    {
        return 0;
    }
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), pQuestDataEx->pDrehyaPortalCoords.nX, pQuestDataEx->pDrehyaPortalCoords.nY);
    if (!pRoom)
    {
        pQuestDataEx->pDrehyaPortalCoords.nX += 3;
        pQuestDataEx->pDrehyaPortalCoords.nY += 3;
        return 0;
    }
    D2UnitStrc* pDrehyaPortal = SUNIT_AllocUnitData(2, 189, pQuestDataEx->pDrehyaPortalCoords.nX, pQuestDataEx->pDrehyaPortalCoords.nY, pGame, pRoom, 1, 1, 0);
    if (!pDrehyaPortal)
    {
        return 0;
    }
    pQuestDataEx->bDrehyaPortalOutsideTownSpawned = 1;
    pQuestDataEx->nDrehyaPortalOutsideTownGUID = pDrehyaPortal->dwUnitId;
    return 1;
}

// 0x0058A940
int __fastcall ACT5Q3_InitializeDrehyaPortalCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
    if (!pQuestData)
    {
        return 0;
    }
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    UNITS_GetCoords(pUnit, &pQuestDataEx->pDrehyaPortalCoords);
    pQuestDataEx->bDrehyaPortalCoordsInitialized = 1;
    return 1;
}

// 0x0058AA50
void __fastcall OBJECTS_InitFunction74_FrozenAnya(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 33);
    if (!pQuestData)
    {
        return;
    }
    ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->nFrozenAnyaObjectGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    if (pQuestData->bNotIntro && pQuestData->fLastState < 2)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
    }
}

#include "gen/data/Source/D2Game/Quests/a5q3_0058A0A0.inc"

int __fastcall sub_00586B30_GetSuperUniqueId(unsigned int nIndex)
{
    if (nIndex <= 65)
    {
        return sgptDataTables->nSuperUniqueIds[nIndex];
    }

    return -1;
}

// 0x0058A500
void __fastcall ACT5Q3_SpawnFrozenDrehya(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
    if (!pQuestData)
    {
        return;
    }

    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bFrozenAnyaObjectSpawned)
    {
        return;
    }

    D2UnitStrc* pFrozenDrehya = SUNIT_AllocUnitData(2, 558, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), pGame, UNITS_GetRoom(pUnit), 1, 0, 0);
    if (pFrozenDrehya)
    {
        pFrozenDrehya->dwFlags |= 0x3000000;
        pQuestDataEx->bFrozenAnyaObjectSpawned = 1;
        pQuestDataEx->nFrozenDrehyaObjectGUID = !pFrozenDrehya ? -1 : pFrozenDrehya->dwUnitId;
    }
    else
    {
        sub_005417D0_DirectDated(pQuestData->pGame, pUnit, 7, pQuestData->pGame->dwGameFrame + 25, 0, 0);
    }
}

// 0x0058A610
void __fastcall OBJECTS_InitFunction68_NihlathakStartInTown(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 33);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->nNihlathakObjectInTownGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    if (pQuestDataEx->unk0x88 || pQuestDataEx->bNihlathakMonsterInTownSpawned)
    {
        return;
    }

    D2UnitStrc* pNihlathak = sub_005459A0_SpawnMonsterNear(pOp->pGame, pOp->nX, pOp->nY, pOp->pRoom, 1, 514);
    if (!pNihlathak)
    {
        return;
    }

    pQuestDataEx->NihlathakMonsterInTownGUID = !pNihlathak ? -1 : pNihlathak->dwUnitId;
    pQuestDataEx->bNihlathakMonsterInTownSpawned = 1;

    D2MapAIStrc* pMapAI = sub_0058F000(pNihlathak);
    if (pQuestDataEx->pNilathakMapAI && pQuestDataEx->pNilathakMapAI->pPosition && !pQuestDataEx->bNilathakMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pNilathakMapAI, pMapAI);
        pQuestDataEx->bNilathakMapAIChanged = 1;
    }
}

// 0x0058A6C0
void __fastcall OBJECTS_InitFunction69_NihlathakStartOutsideTown(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 33);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->unk0x88 != 1 || pQuestDataEx->bNilathakOutsideTownSpawned)
    {
        return;
    }

    const int nMonsterId = DATATBLS_MapSuperUniqueId(2, sub_00586B30_GetSuperUniqueId(60));
    const int nY = pOp->nY;
    const int nX = pOp->nX;
    D2UnitStrc* pNihlathak = D2GAME_SpawnPresetMonster_6FC66560(pOp->pGame, pOp->pRoom, nMonsterId, nX, nY, 1);
    if (pNihlathak)
    {
        pQuestDataEx->nNihlathakOutsideTownGUID = !pNihlathak ? -1 : pNihlathak->dwUnitId;
        pQuestDataEx->bNilathakOutsideTownSpawned = 1;
    }
}

// 0x0058A9B0
void __fastcall sub_0058A9B0_SetDrehyaSpecialModeInTown(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
    if (pQuestData)
    {
        ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->bChangeToSpecialObjectModeInTown = 1;
    }
}

// 0x0058A9D0
int __fastcall sub_0058A9D0_GetQuestFlagAF(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
    if (!pQuestData)
    {
        return 0;
    }
    return ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->bUnk0xAF != 0;
}
