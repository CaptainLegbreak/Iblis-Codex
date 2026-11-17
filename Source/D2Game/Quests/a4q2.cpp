#include "D2Game.h"

#define QUEST_A4Q2_DIABLO 23
#define QUESTSTATEFLAG_A4Q2 26
#define QFLAG_REWARDGRANTED 0
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_COMPLETEDBEFORE 15
#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2
struct D2PlayerDataStrc;
struct D2Act4Quest1Strc;
struct D2Act4Quest2Strc;
struct D2Act3Quest2Strc;
struct D2Act3Quest3Strc;
struct D2Act3Quest4Strc;
struct D2Act3Quest5Strc;
struct D2Act3Quest6Strc;
struct D2GSPacketSrv5D;
struct D2ObjInitFnStrc;
struct D2ModeChangeStrc;
struct D2ObjOperateFnStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
    unsigned char unk_74[0x34];
    unsigned int dwGameFrame;
    char unk0xAC[0x10];
    D2DrlgActStrc* pAct[5];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    unsigned char unk_14[0xB0];
    unsigned int dwFlags;
    unsigned char unk_C8[0x20];
    D2UnitStrc* pRoomNext;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

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
    void* pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2Act4Quest1Strc
{
    char unk0x00[0x12];
    unsigned char bIzualGhostActivated;
    unsigned char unk0x13;
    D2UnitStrc* pTargetUnit;
    unsigned char bCloseToIzualGhost;
};

struct D2Act4Quest2Strc
{
    unsigned char bTalkedToTyrael;
    unsigned char bTimerCreated;
    unsigned char bNeedToSpawnDiablo;
    unsigned char unk0x03;
    unsigned char bNeedToEndGame;
    unsigned char bNeedToWarpPlayers;
    unsigned char bDiabloStartPointInitialized;
    unsigned char pad0x07;
    int nDiabloStartPointObjectGUID;
    unsigned char bSealActivated[5];
    unsigned char bDiabloSpawned;
    unsigned char unused0x12;
    unsigned char bSanctumCleared;
    unsigned char bDiabloKilled;
    unsigned char bClientsSaved;
    unsigned char pad0x16[2];
    unsigned int dwTickCount;
    int nPlayerCount;
    char unk0x20[0x1C];
    D2ActiveRoomStrc* pRoom;
    int nLastLastPortalObjectMode;
    unsigned char unk0x44;
    unsigned char bPortalToAct5Spawned;
    unsigned char pad0x46[2];
    int nBossesKilled;
};

struct D2Act3Quest2Strc
{
    unsigned char bSewerStairsInitialized;
    unsigned char bInitiallyTalkedToCain;
    unsigned char pad0x02[2];
    int nSewerStairsObjectGUID;
    int nSewerStairsObjectMode;
    int nItemDropCount;
    int nEyesDropped;
    int nBrainsDropped;
    int nHeartsDropped;
    int nFlailsDropped;
    int nCubedFlails;
};

struct D2Act3Quest3Strc
{
    char unk0x00[0x06];
    unsigned char bAltarCanBeActivated;
    char unk0x07[0x09];
    int nAltarX;
    int nAltarY;
};

struct D2Act3Quest4Strc
{
    unsigned char bGoldenBirdBroughtToAlkor;
};

struct D2Act3Quest5Strc
{
    char unk0x00[0x0C];
    unsigned char bOrbSmashed;
};

struct D2Act3Quest6Strc
{
    unsigned char bTimerStarted;
    unsigned char bHellGatePortalInitialized;
    unsigned char bMephistoBridgeInitialized;
    unsigned char bOrmusActivated;
    int nHellGatePortalGUID;
    int nMephistoBridgeGUID;
    int nHellGatePortalObjectMode;
    int nMephistoBridgeObjectMode;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall ACT4Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pData); // 0x005B3940
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0
void __fastcall ACT4Q1_UnitIterate_CheckDistanceToIzualGhost(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B43D0
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall ACT4Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3D30

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
    char unk0x78[0x04];
    D2ActiveRoomStrc* pRoomNext;
};

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestRecord, int nQuest); // 0x0065C3E0
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty); // 0x00538680
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    int unk10;
    int nOldLevel;
    int nNewLevel;
};
void __fastcall QUESTS_StateDebug(D2QuestDataStrc*, int, const char*, int); // 0x00544350
int __fastcall ACT4Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc*, D2UnitStrc*, void*); // 0x005B4560
int __fastcall ACT4Q2_UnitIterate_StatusCyclerEx(D2GameStrc*, D2UnitStrc*, void*); // 0x005B4E40
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

extern int gpAct4Q2NpcMessages[]; // 0x0073DBB8
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
bool __fastcall ACT4Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B4450
bool __fastcall ACT4Q2_SeqCallback(D2QuestDataStrc* pQuestData); // 0x005B4530
void __fastcall ACT4Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B4670
void __fastcall ACT4Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B4790
void __fastcall ACT4Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B4EA0
void __fastcall ACT4Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B4F90
void __fastcall ACT4Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B52E0
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    unsigned char unk0x14;
    unsigned char nEventFlag;
    unsigned short unk0x16;
    int unk0x18;
    int unk0x1C;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    void* pObjectregion;
    int nObjectIdx;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[8];
};

typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2); // 0x00545760
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
bool __fastcall ACT4Q2_SpawnDiablo(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x005B4BE0

// 0x005B4390
void __fastcall ACT4Q1_OnIzualActivated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 22);

    if (pQuestData && pQuestData->bNotIntro && pQuestData->fLastState < 2)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x005B43F0
int __fastcall ACT4Q1_IsAnyPlayerInRangeOfIzualGhost(D2GameStrc* pGame, D2UnitStrc* pTargetUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 22);
    if (pQuestData)
    {
        D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bIzualGhostActivated)
        {
            pQuestDataEx->bCloseToIzualGhost = 0;
            pQuestDataEx->pTargetUnit = pTargetUnit;
            SUNIT_IterateLivingPlayers(pGame, ACT4Q1_UnitIterate_CheckDistanceToIzualGhost, pQuestDataEx);

            return !pQuestDataEx->bCloseToIzualGhost;
        }
    }

    return 0;
}

// 0x005B4440
void __fastcall ACT4Q1_AttachCompletionSoundToPlayers(D2GameStrc* pGame)
{
    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT4Q1_UnitIterate_AttachCompletionSound);
}

// 0x005B4B60
D2UnitStrc* __fastcall sub_005B4B60_SpawnDiablo(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2Act4Quest2Strc* pQuestDataEx)
{
    D2UnitStrc* pDiablo = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, 243, 1, -1, 0);
    if (!pDiablo)
    {
        pDiablo = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, 243, 1, 5, 0);
    }

    if (!pDiablo)
    {
        pDiablo = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, 243, 1, 10, 0);
        if (!pDiablo)
        {
            return 0;
        }
    }

    pDiablo->dwFlags |= 0x3000000;
    pQuestDataEx->bDiabloSpawned = 1;
    return pDiablo;
}

// 0x005B5810
int __fastcall ACT4Q2_HasDiabloBeenKilled(D2GameStrc* pGame)
{
    if (pGame->bExpansion)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (pQuestData && !((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bDiabloKilled)
    {
        return 0;
    }

    return 1;
}

// 0x005B6930
void __fastcall sub_005B6930_Return(D2GameStrc* pGame, int nSoulStonesDropped)
{
}

// 0x005B86E0
void __fastcall ACT3Q2_UpdateKhalimItemCounts(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 0))
    {
        QUESTRECORD_GetQuestState(pQuestFlags, 18, 1);
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 16);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;

    --pQuestDataEx->nEyesDropped;
    --pQuestDataEx->nHeartsDropped;
    --pQuestDataEx->nBrainsDropped;
    --pQuestDataEx->nFlailsDropped;
    ++pQuestDataEx->nCubedFlails;
}

// 0x005B9CA0
int __fastcall ACT3Q3_GetAltarCoordinates(D2GameStrc* pGame, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 17);
    if (pQuestData)
    {
        D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bAltarCanBeActivated)
        {
            pCoord->nX = pQuestDataEx->nAltarX;
            pCoord->nY = pQuestDataEx->nAltarY;
            return 1;
        }
    }

    return 0;
}

// 0x005BAD20
int __fastcall ACT3Q4_GoldenBirdBroughtToAlkor(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 18);
    if (pQuestData && ((D2Act3Quest4Strc*)pQuestData->pQuestDataEx)->bGoldenBirdBroughtToAlkor)
    {
        return 1;
    }

    return 0;
}

// 0x005BAD40
void __fastcall ACT3Q4_ResetAlkor(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 18);

    if (pQuestData)
    {
        ((D2Act3Quest4Strc*)pQuestData->pQuestDataEx)->bGoldenBirdBroughtToAlkor = 0;
    }
}

// 0x005BBF80
bool __fastcall sub_005BBF80_IsOrbNotSmashed(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 19);
    if (pQuestData)
    {
        return ((D2Act3Quest5Strc*)pQuestData->pQuestDataEx)->bOrbSmashed == 0;
    }

    return true;
}

// 0x005BBFA0
int __fastcall ACT3Q5_IsDuranceOfHateClosed(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 19);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);

    if (pRoom && DUNGEON_GetLevelIdFromRoom(pRoom) == 101)
    {
        return 0;
    }

    if (pQuestData)
    {
        return ((D2Act3Quest5Strc*)pQuestData->pQuestDataEx)->bOrbSmashed == 0;
    }

    return 0;
}

// 0x005BCFD0
void __fastcall ACT3Q6_SetObjectModes(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 20);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;

    pQuestDataEx->nHellGatePortalObjectMode = 2;
    pQuestDataEx->nMephistoBridgeObjectMode = 2;

    if (pQuestDataEx->bHellGatePortalInitialized)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nHellGatePortalGUID);
        if (pObject)
        {
            UNITS_ChangeAnimMode(pObject, 1);
        }
    }

    if (pQuestDataEx->bMephistoBridgeInitialized)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nMephistoBridgeGUID);
        if (pObject)
        {
            UNITS_ChangeAnimMode(pObject, 2);
        }
    }
}

// 0x005B4A30
static void sub_005B4A30_ACT4Q2_WarpPlayerAndSendQuestPacket(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    LEVEL_WarpUnit(pGame, pPlayer, 103, 0);
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 440);
    D2GSPacketSrv5D packet = {};
    packet.nHeader = 0x5D;
    packet.nQuestId = 0x17;
    packet.nFlags = 1;
    sub_6FC3F380(pClient, &packet);
}

// build: context sub_K13_Emit_005B4A30
void __fastcall sub_K13_Emit_005B4A30(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    sub_005B4A30_ACT4Q2_WarpPlayerAndSendQuestPacket(pGame, pPlayer);
}

// 0x005B4D20
static void __stdcall sub_005B4D20(D2BitBufferStrc* pQuestFlags, D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    QUESTRECORD_SetQuestState(pQuestFlags, 26, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 26, 0);
    QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, 26);
    if (!pGame->bExpansion)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 26, 6);
        QUESTRECORD_SetQuestState(pQuestFlags, 26, 7);
        CLIENTS_UpdateCharacterProgression(SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 592), 4, pGame->nDifficulty);
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (pQuestData)
    {
        ++((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->nPlayerCount;
    }
}

int __fastcall ACT4Q2_UnitIterate_UpdatePlayerState(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) == 1)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    int bInRange = 0;
    if (pRoom == pQuestDataEx->pRoom)
    {
        bInRange = 1;
    }
    else
    {
        D2ActiveRoomStrc** ppRoomList;
        unsigned int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] == pQuestDataEx->pRoom)
            {
                bInRange = 1;
                break;
            }
        }
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 26, 1) && bInRange)
    {
        sub_005B4D20(pQuestFlags, pGame, pUnit);
    }

    return 0;
}

// 0x005B4DA0
void __fastcall sub_005B4DA0_ACT4Q2_UnitIterate_SetCompleted(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) != 3)
    {
        return;
    }

    sub_005B4D20(pQuestFlags, pGame, pUnit);
}

// 0x005B4EA0
void __fastcall ACT4Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNewLevel = pQuestArg->nNewLevel;
    if (pQuestArg->nOldLevel == 103 && pQuestData->fState == 2)
    {
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) == 1)
            return;
        if (pQuestData->fState < 3)
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 687);
        if (pQuestData->fLastState < 1)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT4Q2_UnitIterate_StatusCyclerEx, false);
        }
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q2_UnitIterate_UpdateQuestStateFlags);
    }
    if (nNewLevel == 108 && pQuestData->bNotIntro)
    {
        if (pQuestData->fState < 3)
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 703);
        if (pQuestData->fLastState < 1)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT4Q2_UnitIterate_StatusCyclerEx, true);
        }
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q2_UnitIterate_UpdateQuestStateFlags);
    }
}

inline D2BitBufferStrc* ACT4Q2_GetQuestFlagsInline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B5030
void __fastcall ACT4Q2_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    if (!pGame->bExpansion)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_CUSTOM5) && !QUESTRECORD_GetQuestState(pQuestFlags, 28, QFLAG_REWARDGRANTED))
    {
        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_CUSTOM5);
    }
}

// 0x005B5080
void __fastcall ACT4Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = ACT4Q2_GetQuestFlagsInline(pQuestArg->pGame, pQuestArg->pPlayer);

    if (pQuestArg->pGame->bExpansion && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_CUSTOM5) && !QUESTRECORD_GetQuestState(pQuestFlags, 28, QFLAG_REWARDGRANTED))
    {
        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_CUSTOM5);
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_COMPLETEDBEFORE))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_ENTERAREA) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_STARTED) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x005B54C0
void __fastcall ACT4Q2_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[QUESTEVENT_MONSTERKILLED] = ACT4Q2_Callback08_MonsterKilled;
    pQuestData->pfCallback[QUESTEVENT_CHANGEDLEVEL] = ACT4Q2_Callback03_ChangedLevel;
    pQuestData->pfCallback[QUESTEVENT_NPCACTIVATE] = ACT4Q2_Callback00_NpcActivate;
    pQuestData->pfCallback[QUESTEVENT_NPCDEACTIVATE] = ACT4Q2_Callback02_NpcDeactivate;
    pQuestData->pfCallback[QUESTEVENT_SCROLLMESSAGE] = ACT4Q2_Callback11_ScrollMessage;
    pQuestData->pfCallback[QUESTEVENT_PLAYERSTARTEDGAME] = ACT4Q2_Callback13_PlayerStartedGame;
    pQuestData->pfCallback[QUESTEVENT_PLAYERJOINEDGAME] = ACT4Q2_Callback14_PlayerJoinedGame;
    pQuestData->pNPCMessages = gpAct4Q2NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->nQuestFilter = QUESTSTATEFLAG_A4Q2;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pfActiveFilter = ACT4Q2_ActiveFilterCallback;

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act4Quest2Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 1048, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->pfSeqFilter = ACT4Q2_SeqCallback;
    memset(pQuestDataEx, 0x00, sizeof(D2Act4Quest2Strc));
}

// 0x005B5840
void __fastcall OBJECTS_InitFunction78_LastLastPortal(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A4Q2_DIABLO);
    if (!pQuestData)
    {
        return;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->nLastLastPortalObjectMode != OBJMODE_OPENED)
    {
        pQuestDataEx->nLastLastPortalObjectMode = OBJMODE_OPENED;
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
    }
}

#include "gen/data/Source/D2Game/Quests/a4q2.inc"

// 0x005B5230
static void __stdcall ACT4Q2_KillAllMonstersInCS(D2GameStrc* pGame, D2Act4Quest2Strc* pQuestDataEx)
{
    if (pQuestDataEx->bSanctumCleared)
    {
        return;
    }

    pQuestDataEx->bSanctumCleared = 1;
    QUESTS_TriggerFX(pGame, 12);

    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[3]); pRoom; pRoom = pRoom->pRoomNext)
    {
        if (DUNGEON_GetLevelIdFromRoom(pRoom) == 108)
        {
            D2UnitStrc* pNext = 0;
            for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNext)
            {
                pNext = pUnit->pRoomNext;
                if (pUnit->dwUnitType == 1 && pUnit->dwClassId != 243 && !SUNIT_IsDead(pUnit) && STATLIST_GetUnitAlignment(pUnit) == 0)
                {
                    D2ModeChangeStrc modeChange;
                    MONSTERMODE_GetModeChangeInfo(pUnit, 0, &modeChange);
                    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
                }
            }
        }
    }
}

int __fastcall OBJECTS_OperateFunction52_DiabloSeal(D2ObjOperateFnStrc* pOp)
{
    if (pOp->pObject && pOp->pObject->dwAnimMode != 0)
    {
        return 0;
    }

    UNITS_ChangeAnimMode(pOp->pObject, 1);

    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 7) + pOp->pGame->dwGameFrame, 0, 0);

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 23);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;

    switch (UNIT_CLASSID_OR_INVALID(pOp->pObject))
    {
    case 392:
        pQuestDataEx->bSealActivated[0] = 1;
        break;
    case 393:
        pQuestDataEx->bSealActivated[1] = 1;
        break;
    case 394:
        pQuestDataEx->bSealActivated[2] = 1;
        break;
    case 395:
        pQuestDataEx->bSealActivated[3] = 1;
        break;
    case 396:
        pQuestDataEx->bSealActivated[4] = 1;
        break;
    default:
        break;
    }

    for (int nCounter = 0; nCounter < 5; ++nCounter)
    {
        if (!pQuestDataEx->bSealActivated[nCounter])
        {
            return 0;
        }
    }

    if (pQuestDataEx->nBossesKilled != 3)
    {
        return 0;
    }

    ACT4Q2_KillAllMonstersInCS(pOp->pGame, pQuestDataEx);
    if (pQuestDataEx->bTimerCreated)
    {
        return 0;
    }

    pQuestDataEx->dwTickCount = 0;
    pQuestDataEx->bNeedToSpawnDiablo = 1;
    pQuestDataEx->unk0x03 = 0;
    pQuestDataEx->bTimerCreated = 1;
    QUESTS_CreateTimer(pQuestData, ACT4Q2_SpawnDiablo, 1);
    return 0;
}

// 0x005B5620
void __cdecl sub_005B5620_Return()
{
}
