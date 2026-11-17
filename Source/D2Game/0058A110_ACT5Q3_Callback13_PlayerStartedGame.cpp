struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2MapAIStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2QuestGUIDStrc
{
    int nPlayerGUIDs[32];
    unsigned short nGUIDCount;
    unsigned short unk0x82;
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
};

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
    char pad0xA5[0xC];
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
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
extern char gpAct5Q3NpcMessages[];                                                                          // 0x00734320

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID);                                   // 0x00545300
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
void __fastcall ACT5Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00589D20
void __fastcall ACT5Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x00589D80
void __fastcall ACT5Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x00589B00
void __fastcall ACT5Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x00588F80
void __fastcall ACT5Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x00589580
void __fastcall ACT5Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT5Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
bool __fastcall ACT5Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0058A300
bool __fastcall ACT5Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00589F10
bool __fastcall ACT5Q3_SeqCallback(D2QuestDataStrc* pQuestData);                                            // 0x00589160
int __fastcall ACT5Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x00588EB0

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
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 15))
    {
        pQuestDataEx->unk0x84 = 2;
        pQuestDataEx->unk0x88 = 1;
        return;
    }
    if (!pQuestData->bNotIntro)
    {
        return;
    }
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 3))
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 2))
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
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[10] = ACT5Q3_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[3] = ACT5Q3_Callback03_ChangedLevel;
    pQuestData->pfCallback[0] = ACT5Q3_Callback00_NpcActivate;
    pQuestData->pfCallback[2] = ACT5Q3_Callback02_NpcDeactivate;
    pQuestData->pfCallback[11] = ACT5Q3_Callback11_ScrollMessage;
    pQuestData->pfCallback[13] = ACT5Q3_Callback13_PlayerStartedGame;
    pQuestData->pfCallback[14] = ACT5Q3_Callback14_PlayerJoinedGame;
    pQuestData->pNPCMessages = gpAct5Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest3Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 1482, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->nQuestFilter = 37;
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
        EVENT_SetEvent(pQuestData->pGame, pOp->pObject, 7, pQuestData->pGame->dwGameFrame + 25, 0, 0);
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
    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), pQuestDataEx->pDrehyaPortalCoords.nX, pQuestDataEx->pDrehyaPortalCoords.nY);
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

#include "gen/data/Source/D2Game/0058A110_ACT5Q3_Callback13_PlayerStartedGame.inc"
