#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2PlayerDataStrc;
struct D2ObjInitFnStrc;
struct D2ObjOperateFnStrc;
struct D2Act2Quest6Strc;
struct D2GSPacketSrv50;
struct D2GSPacketSrv58;



struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2ObjectsTxt
{
    char pad0x00[0xDC];
    unsigned int dwFrameCnt1;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    char pad0x0C[0x10];
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

typedef int (__stdcall* FARPROC)();

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
    char pad0xE4[0xC];
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    char pad0x10[0xC];
};

struct D2Act2Quest6Strc
{
    unsigned char unk0x00;
    unsigned char bDurielKilled;
    char pad0x02[0x1];
    unsigned char bTimerActive;
    unsigned char bHoradricOrificeInitialized;
    unsigned char bTyraelsDoorInitialized;
    unsigned char bUnusedObjectInitialized;
    char pad0x07[0x4];
    unsigned char bDurielLairTombOpen;
    unsigned char bDurielLairPortalNeedsToOpen;
    unsigned char bObjectsNeedUpdate;
    char pad0x0E[0xA];
    int nTyraelsDoorObjectMode;
    char pad0x1C[0x4];
    int nHoradricOrificeGUID;
    char pad0x24[0x4];
    int nUnusedObjectGUID;
    int nTyraelsDoorGUID;
    char pad0x30[0x4];
    int nStaffTombLevelId;
    char pad0x38[0x5];
    unsigned char bRewardedOrCompletedBefore;
    char pad0x3E[0x22];
    D2ActiveRoomStrc* pDurielRoom;
};

#pragma pack(push, 1)
struct D2GSPacketSrv50
{
    unsigned char nHeader;
    unsigned short nQuestId;
    unsigned short nStaffTombLevelOffset;
    unsigned char unk0x05[0x0B];
};

struct D2GSPacketSrv58
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char unk0x05;
};

#pragma pack(pop)

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszA2Q6DebugKilledDuriel[]; // 0x006E209C
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket); // 0x0053D7E0
void __fastcall sub_0053D8D0_SendPacket0x58(D2ClientStrc* pClient, D2GSPacketSrv58* pPacket); // 0x0053D8D0
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode); // 0x00544160
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2); // 0x00545760
void __fastcall sub_00545990(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, int nValue); // 0x00545990
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID); // 0x00554120
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x005678A0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
bool __fastcall sub_0059CEE0(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x0059CEE0
void __fastcall ACT2Q6_UnitIterate_SetCustom1Flag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059CF20
int __fastcall ACT2Q6_UnitIterate_SetCustom1FlagForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059CFB0
bool __fastcall ACT2Q6_Timer_UpdateObjects(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x0059D870
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0
extern "C" const char gszA2Q6SourceFile[]; // 0x006E2068

// 0x0059D450
bool __fastcall ACT2Q6_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 0x3E9);
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 0xA);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 0x3EE);
        return pQuest->pfSeqFilter(pQuest);
    }

    return true;
}

// 0x0059D4D0
void __fastcall ACT2Q6_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_ClearQuestState(pQuestFlags, 0xA, 0x9);
}

// 0x0059D4F0
void __fastcall ACT2Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_ClearQuestState(pQuestFlags, 0xA, 0x9);

    if (QUESTRECORD_GetQuestState(pQuestFlags, 0xA, 0))
    {
        ((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->bDurielLairPortalNeedsToOpen = 1;
        ((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->bObjectsNeedUpdate = 1;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0xF))
    {
        ((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->bRewardedOrCompletedBefore = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 0xE, 2) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 0xE, 3) == 1)
    {
        pQuestData->fLastState = 5;
        pQuestData->fState = 5;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 0xE, 4) == 1)
    {
        pQuestData->fLastState = 6;
        pQuestData->fState = 5;
    }
}

// 0x0059D6A0
void __fastcall ACT2Q6_SendTombIdToClient(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0xD);
    D2GSPacketSrv50 packet50;
    packet50.nHeader = 0x50;
    packet50.nQuestId = 0xD;

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 0x45F);
    const int nTombStaffLevel = DUNGEON_GetHoradricStaffTombLevelId(pGame->pAct[1]);
    if (!nTombStaffLevel)
    {
        packet50.nStaffTombLevelOffset = 0;
    }
    else
    {
        packet50.nStaffTombLevelOffset = nTombStaffLevel - 0x42;
        ((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->nStaffTombLevelId = nTombStaffLevel;
    }
    D2GAME_SendPacket0x50_6FC3F440(pClient, &packet50);
}

// 0x0059DAD0
void __fastcall OBJECTS_InitFunction38_TyraelsDoor(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0xD);
    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bTyraelsDoorInitialized = 1;
    pQuestDataEx->nTyraelsDoorGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    if (!pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nTyraelsDoorObjectMode);
    }
}

// 0x0059DB50
void __fastcall OBJECTS_InitFunction21_HoradricOrifice(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0xD);
    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bHoradricOrificeInitialized = 1;
    pQuestDataEx->nHoradricOrificeGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    if (!pQuestDataEx->bDurielLairPortalNeedsToOpen || pQuestDataEx->bTimerActive || pQuestDataEx->bDurielLairTombOpen)
    {
        if (pQuestDataEx->bDurielLairTombOpen)
        {
            UNITS_ChangeAnimMode(pOp->pObject, 2);
        }
    }
    else
    {
        QUESTS_CreateTimer(pQuestData, ACT2Q6_Timer_UpdateObjects, 1);
        pQuestDataEx->bTimerActive = 1;
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
}

// 0x0059DBD0
void __fastcall ACT2Q6_UnitIterate_DeleteHoradricItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0xA, 0) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (DRLG_GetActNoFromLevelId(nLevelId) != 1)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 0xA, 0);
    QUESTRECORD_SetQuestState(pQuestFlags, 0xA, 0xD);
    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return;
    }

    QUESTS_DeleteItem(pGame, pUnit, 0x20747368);
    QUESTS_DeleteItem(pGame, pUnit, 0x20706976);
    QUESTS_DeleteItem(pGame, pUnit, 0x2066736D);
}

// 0x0059DC70
int __fastcall OBJECTS_OperateFunction25_StaffOrifice(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!QUESTS_GetQuestData(pOp->pGame, 0xD))
    {
        return 0;
    }

    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pOp->pGame, pOp->pPlayer);
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pOp->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 0x635);
    switch (!pOp->pObject ? 0 : pOp->pObject->dwAnimMode)
    {
    case 0:
    {
        if (PLAYER_IsBusy(pOp->pPlayer) == 1)
        {
            return 1;
        }

        if (!ITEMS_FindQuestItem(pOp->pGame, pOp->pPlayer, 0x20747368))
        {
            SUNIT_AttachSound(pOp->pPlayer, 0x13, pOp->pPlayer);
            return 1;
        }

        SUNIT_SetInteractInfo(pOp->pPlayer, 2, !pOp->pObject ? -1 : pOp->pObject->dwUnitId);
        UNITS_ChangeAnimMode(pOp->pObject, 1);

        D2GSPacketSrv58 packet58;
        packet58.nHeader = 0x58;
        const int nUnitId = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
        packet58.nUnitId = nUnitId;
        packet58.unk0x05 = 0;
        sub_0053D8D0_SendPacket0x58(pClient, &packet58);
        break;
    }
    case 1:
        if (pInteractUnit == pOp->pObject)
        {
            SUNIT_ResetInteractInfo(pOp->pPlayer);
            UNITS_ChangeAnimMode(pOp->pObject, 2);
        }
        break;
    }

    return 0;
}

// 0x0059DA50
void __fastcall sub_0059DA50(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* q=QUESTS_GetQuestData(pOp->pGame,13);
    if(q)
    {
        D2Act2Quest6Strc* ex=(D2Act2Quest6Strc*)q->pQuestDataEx;
        ex->bUnusedObjectInitialized=1;
        ex->nUnusedObjectGUID=!pOp->pObject ? -1 : pOp->pObject->dwUnitId;
        if(!q->bNotIntro) UNITS_ChangeAnimMode(pOp->pObject,2);
        else if(ex->bDurielLairTombOpen==1) UNITS_ChangeAnimMode(pOp->pObject,2);
        else if(ex->bObjectsNeedUpdate==1) UNITS_ChangeAnimMode(pOp->pObject,2);
        else UNITS_ChangeAnimMode(pOp->pObject,0);
    }
    else UNITS_ChangeAnimMode(pOp->pObject,2);
}
