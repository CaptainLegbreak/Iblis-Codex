#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2StaticPathStrc;
struct D2UnkMonCreateStrc3;
struct D2UnkMonCreateStrc;
struct D2SpawnRequest005B3130Strc;
struct D2SeedStrc;
struct D2LevelsTxt;
struct D2MonStatsTxt;
struct D2PlayerDataStrc;
struct D2Act4Quest1Strc;
struct D2QuestGUIDStrc;
struct D2ObjOperateFnStrc;
struct D2GSPacketSrv5D;
struct D2GSPacketSrv50;
struct D2Act4Quest2Strc;
struct D2Act4Quest3Strc;
struct D2Act3Quest1Strc;
struct D2Act3Quest3Strc;
struct D2Act3Quest4Strc;
struct D2Act3Quest5Strc;
struct D2Act3Quest6Strc;
struct D2Act3Quest7Strc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    int dwAnimMode;
    unsigned char unk_14[0x18];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    unsigned char unk_30[0x88];
    unsigned int dwDropItemCode;
};

struct D2UnkMonCreateStrc3
{
    int nXOffset;
    int nYOffset;
    int nSpawnType;
};

struct D2UnkMonCreateStrc2
{
    int nRecordCount;
    int unk0x04;
    unsigned char unk0x08;
    unsigned char pad0x09[3];
    D2UnkMonCreateStrc3 records[4];
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId); // 0x0063EC70

struct D2GameStrc
{
    char pad0x00[0x6D];
    unsigned char nDifficulty;
    char pad0x6E[0x02];
    int bExpansion;
    unsigned char unk_74[0x48];
    void* pAct[5];
};

D2UnitStrc* __fastcall sub_6FC68D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion); // 0x0058F100
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
extern D2UnkMonCreateStrc2 gBonePrisonSpawnInfo_0073D4F0; // 0x0073D4F0

struct D2UnkMonCreateStrc
{
    D2GameStrc* pGame;
    D2ActiveRoomStrc* pRoom;
    D2RoomCoordListStrc* pRoomCoordList;
    int nMonsterId;
    int nAnimMode;
    int nUnitGUID;
    int nX;
    int nY;
    int field_20;
    short nFlags;
};

D2UnitStrc* __fastcall sub_005B2A00_SpawnNormalMonster(D2UnkMonCreateStrc*); // 0x005B2A00

struct D2SpawnRequest005B3130Strc
{
    D2GameStrc* pGame;
    void* pRoom;
    int n08;
    int n0C;
    int n10;
    int n14;
    int n18;
    int n1C;
    int n20;
    unsigned short n24;
};

D2UnitStrc* __fastcall sub_005B2A00_Spawn(D2SpawnRequest005B3130Strc* pRequest); // 0x005B2A00

struct D2LevelsTxt
{
    char unk0x000[0x33];
    unsigned char nNumNormalMonsters;
    unsigned char nNumNightmareHellMonsters;
    unsigned char nNumUniqueMonsters;
    short wNormalMonsters[25];
};

struct D2MonStatsTxt
{
    char unk0x000[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x010[0x198];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
};

enum D2C_SpawnRandomConstants
{
    MONSTATSFLAGINDEX_ISSPAWN = 0,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2UnitStrc* __fastcall sub_005B2A00_SpawnNormalMonster(D2UnkMonCreateStrc* pMonCreate); // 0x005B2A00
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
    char pad0x1C[0x30];
    int bBusy;
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

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern char gpAct4Q0NpcMessages[]; // 0x0073D580
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestRecord, int nQuest); // 0x0065C3E0
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
D2ActiveRoomStrc* __stdcall sub_00619DA0_ActLookup(void* pAct, int a2, int a3); // 0x00619DA0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
bool __fastcall ACT4Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B3750
bool __fastcall ACT4Q0_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005B3740
int __fastcall ACT4Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pData); // 0x005B3940
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId); // 0x00544190

typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc*, D2QuestDataStrc*);

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

struct D2GSPacketSrv50
{
    unsigned char nHeader;
    unsigned char nQuestId[2];
    unsigned char data[0x0C];
};

struct D2Act4Quest2Strc
{
    char pad0x00[0x20];
    D2UnitStrc* unk0x20;
};

struct D2Act4Quest3Strc
{
    char pad0x00[0x02];
    unsigned char bCainActivated;
    char pad0x03[0x0D];
    int nHellforgeHammersInGame;
    char pad0x14[0x08];
    unsigned char bSoulstoneAcquired;
};

struct D2Act3Quest1Strc
{
    unsigned char bCanGetReward;
    unsigned char bTomeDropped;
    unsigned char bTomeActive;
    char pad0x03[0x05];
    int nTomesInGame;
    char pad0x0C[0x08];
    int nTomeGUID;
    int nTomeObjectMode;
};

struct D2Act3Quest3Strc
{
    unsigned char bGidbinnDropped;
    unsigned char bHratliActivated;
    unsigned char bBossHasSpawned;
    char pad0x03[0x19];
    int nGidbinnsInGame;
    unsigned char bPlayerWithGidbinnDropped;
    char pad0x21[0x0B];
    int nAltarObjectMode;
};

struct D2Act3Quest4Strc
{
    unsigned char bGoldenBirdBroughtToAlkor;
    unsigned char unk0x01;
    unsigned char unk0x02;
    char pad0x03[0x09];
    unsigned char unk0x0C;
    char pad0x0D[0x03];
    int nGoldenBirdsInGame;
    unsigned char bJadeFigurineDropped;
    unsigned char bPlayerDroppedWithItem;
};

struct D2Act3Quest5Strc
{
    int nLastKilledMonsterGUID;
    unsigned char bOrmusActivated;
    char pad0x05[0x07];
    unsigned char bOrbSmashed;
};

struct D2Act3Quest6Strc
{
    unsigned char bTimerStarted;
    unsigned char bHellGatePortalInitialized;
    unsigned char bMephistoBridgeInitialized;
    unsigned char bOrmusActivated;
};

struct D2Act3Quest7Strc
{
    unsigned char bDarkWandererInitialized;
    unsigned char bPrimaryGoalOpen;
    unsigned char bWandererCoordsCalculated;
    unsigned char pad0x03;
    D2CoordStrc tDarkWandererCoords;
};

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C3A0
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode); // 0x00544160
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544760
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780
int __fastcall QUESTS_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int dwCode, int nLevel, int nQuality, int bDroppable); // 0x005466B0
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
int __stdcall MONSTERS_IsBoss(void* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
void __fastcall sub_6FC7BEC0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005351C0
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710
void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket); // 0x0053D7E0
void __fastcall sub_0053D940_SendPacket0x61(D2ClientStrc* pClient, unsigned char nValue); // 0x0053D940
void __fastcall D2GAME_PlayerChangeAct_6FC867C0(D2GameStrc* pGame, D2UnitStrc* pUnit, int dwDestLvl, int nTileCalc); // 0x0054B830
void __stdcall sub_005B4FF0_ActivateHarrogathWaypoint(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005B4FF0
bool __fastcall sub_005BBF80_ACT3Q5_IsOrbNotSmashed(D2GameStrc* pGame); // 0x005BBF80
int __fastcall ACT4Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3CD0
int __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3DE0
bool __fastcall ACT4Q1_SpawnIzualGhost(D2GameStrc* pGame, D2QuestDataStrc* pQuest); // 0x005B3E60
int __fastcall ACT4Q1_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3F20
int __fastcall ACT4Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B59C0
int __fastcall ACT3Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B7340
void __fastcall ACT3Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B7740
int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BAF70
int __fastcall ACT3Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC210

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3D70

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// build: context sub_6FC6A150
D2UnitStrc* __fastcall sub_6FC6A150(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!DUNGEON_GetLevelIdFromPopulatedRoom(pRoom))
    {
        return 0;
    }

    return sub_6FC68D70(pGame, pUnit, D2Common_11063(pRoom, nMonsterId), nAnimMode, a5, nFlags);
}

// 0x005B24E0
int __fastcall sub_6FC6A230(D2GameStrc* pGame, D2UnitStrc* pOwner, int nMonsterId, int nAnimMode, int a5, int nCount, short nFlags)
{
    if (!pOwner)
        return 0;

    int nResult = 0;
    const int nOwnerId = pOwner->dwUnitId;
    for (int i = 0; i < nCount; ++i)
    {
        D2UnitStrc* pMinion = sub_6FC68D70(pGame, pOwner, nMonsterId, nAnimMode, a5, nFlags);
        if (pMinion)
        {
            nResult = 1;
            AIGENERAL_SetOwnerData(pGame, pMinion, nOwnerId, 1, 0, 0);
            AIGENERAL_AllocMinionList(pGame, pOwner, pMinion);
        }
    }
    return nResult;
}

// 0x005B34C0
int __fastcall sub_6FC6A810(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int a4, D2UnitStrc* pTargetUnit, int a6, short a7)
{
    int nResult = 0;
    if (a6 == 340)
    {
        if (!pTargetUnit)
            return 0;

        const int nX = CLIENTS_GetUnitX(pTargetUnit);
        const int nY = CLIENTS_GetUnitY(pTargetUnit);
        nResult = sub_005B3270(pGame, pRoom, nX, nY, 0, 340, 8, &gBonePrisonSpawnInfo_0073D4F0, a7);
    }
    return nResult;
}

#include "gen/data/Source/D2Game/Quests/a4q1.inc"

// 0x005B3040
D2UnitStrc* __fastcall sub_005B3040_SpawnInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nX, int nY, int nMonsterId, int nAnimMode, int a8, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = pRoom;
    monCreate.field_20 = a8;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = pCoordList;
    monCreate.nFlags = nFlags;
    monCreate.nX = nX;
    monCreate.nY = nY;
    return sub_005B2A00_SpawnNormalMonster(&monCreate);
}

// 0x005B3090
D2UnitStrc* __fastcall sub_005B3090_SpawnAtPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pGame = pGame;
    monCreate.pRoom = pRoom;
    monCreate.pRoomCoordList = 0;
    monCreate.field_20 = -1;
    monCreate.nFlags = nFlags;
    monCreate.nX = nX;
    monCreate.nY = nY;
    return sub_005B2A00_SpawnNormalMonster(&monCreate);
}

// 0x005B30E0
D2UnitStrc* __fastcall sub_005B30E0_SpawnWithUnitId(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nUnitGUID, int a8, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = nUnitGUID;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = pRoom;
    monCreate.field_20 = a8;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = 0;
    monCreate.nFlags = nFlags;
    monCreate.nX = nX;
    monCreate.nY = nY;
    return sub_005B2A00_SpawnNormalMonster(&monCreate);
}

// 0x005B3130
D2UnitStrc* __fastcall sub_005B3130_SpawnOwned(D2GameStrc* pGame, void* pRoom, int a1, int a2, int a3, int a4, int a5, int a6, unsigned short a7)
{
    D2SpawnRequest005B3130Strc tRequest;
    tRequest.n14 = 0;
    tRequest.n0C = a3;
    tRequest.n10 = a4;
    tRequest.pGame = pGame;
    tRequest.pRoom = pRoom;
    tRequest.n08 = 0;
    tRequest.n20 = a5;
    tRequest.n24 = a7;
    tRequest.n18 = a1;
    tRequest.n1C = a2;
    D2UnitStrc* pUnit = sub_005B2A00_Spawn(&tRequest);
    if (pUnit)
    {
        AIGENERAL_SetOwnerData(pGame, pUnit, !pUnit ? -1 : pUnit->dwUnitId, 1, 1, a6);
    }
    return pUnit;
}

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x005B3570
int __fastcall MONSTERSPAWN_SpawnRandomMonsterForLevel(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pLevelsTxtRecord->nNumNormalMonsters, 1264);

    int nIndex = ITEMS_RollLimitedRandomNumber(pRoom ? &pRoom->pSeed : 0, pLevelsTxtRecord->nNumNormalMonsters);
    int nMonsterId = -1;
    int nCounter = 0;
    for (nCounter = 0; nCounter < pLevelsTxtRecord->nNumNormalMonsters; ++nCounter)
    {
        ++nIndex;
        if (nIndex >= pLevelsTxtRecord->nNumNormalMonsters)
        {
            nIndex = 0;
        }

        nMonsterId = pLevelsTxtRecord->wNormalMonsters[nIndex];
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_ISSPAWN >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_ISSPAWN & 7])
        {
            break;
        }
    }

    if (nMonsterId == -1)
    {
        return 0;
    }

    D2_ASSERT(nCounter < pLevelsTxtRecord->nNumNormalMonsters, 1287);

    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = 1;
    monCreate.pRoom = pRoom;
    monCreate.pRoomCoordList = 0;
    monCreate.field_20 = 5;
    monCreate.pGame = pGame;
    monCreate.nFlags = 0;
    monCreate.nX = nX;
    monCreate.nY = nY;
    return sub_005B2A00_SpawnNormalMonster(&monCreate) != 0;
}

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

// 0x005B3740
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    return false;
}

bool __fastcall ACT3Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    return false;
}

void __cdecl sub_005BDB10_Return()
{
}

// 0x005B3940
int __fastcall ACT4Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 25, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 25, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 25, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pPlayer, 22);
    }

    return 0;
}

static int nIndices_0073D56C[] =                                                                            // 0x0073D56C
{
    -1, 0, 1, -1, -1
};

static int nIndices_0073DBA0[] =                                                                            // 0x0073DBA0
{
    -1, 0, 1, 2, 3, 4
};

static int nIndices_0073F188[] =                                                                            // 0x0073F188
{
    -1, 0, 1, 2, 3, 4
};

static int nIndices_007401B8[] =                                                                            // 0x007401B8
{
    -1, 0, 1, 2, 3, 4
};

// 0x005B3BB0
void __fastcall ACT4Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 13);

    int nNpcId;
    if (!pQuestArg->pTarget)
    {
        nNpcId = -1;
    }
    else
    {
        nNpcId = pQuestArg->pTarget->dwClassId;
        if (nNpcId == 406 && !QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 5))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 406, 3);
            return;
        }
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
    }
    else if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
    }
    else if (bRewardGranted != 1 && (pQuestData->fState < 4 || bPrimaryGoalDone))
    {
        if (!pQuestData->bNotIntro)
        {
            return;
        }

        const int nIndex = nIndices_0073DBA0[pQuestData->fState];
        if (nIndex != -1 && (unsigned int)nIndex < 6)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

// 0x005B4020
void __fastcall ACT4Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
    QUESTS_DebugOutput(pQuestData->pGame, "Finished quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 511);

    pQuestData->pfCallback[2] = 0;

    QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 513);

    pQuestData->pfCallback[8] = 0;

    pQuestDataEx->pTargetUnit = pQuestArg->pTarget;
    if (pQuestData->bNotIntro)
    {
        if (pQuestArg->pPlayer)
        {
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 25, 1))
            {
                QUESTRECORD_SetQuestState(pQuestFlags, 25, 13);
                QUESTRECORD_SetQuestState(pQuestFlags, 25, 1);
                QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, pQuestData->nQuestFilter);
            }
        }
        pQuestDataEx->bNeedToSpawnIzualGhost = 1;
        UNITS_GetCoords(pQuestArg->pTarget, &pQuestDataEx->pCoords);

        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q1_UnitIterate_SetRewardPending);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q1_UnitIterate_SetCompletionFlag);
    }

    if (!pQuestDataEx->bIzualGhostIsSpawning)
    {
        pQuestDataEx->bIzualGhostIsSpawning = 1;
        QUESTS_CreateTimer(pQuestData, ACT4Q1_SpawnIzualGhost, 3);
    }
}

// 0x005B4790
void __fastcall ACT4Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 13);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    const int bCustom3 = QUESTRECORD_GetQuestState(pQuestFlags, 26, 7);
    const int bCustom2 = QUESTRECORD_GetQuestState(pQuestFlags, 26, 6);
    const int bCustom5 = QUESTRECORD_GetQuestState(pQuestFlags, 26, 9);
    const int bCustom4 = QUESTRECORD_GetQuestState(pQuestFlags, 26, 8);

    if (!pQuestData->pGame->bExpansion)
    {
        if (bCustom3 && nNpcId == 367)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 367, 2);
            return;
        }
        if (bCustom2 && nNpcId == 246)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 246, 2);
            return;
        }
        if (bCustom3)
        {
            if (nNpcId == 246)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 246, 3);
            }
            return;
        }
        if (bCustom2)
        {
            if (nNpcId == 367)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 367, 3);
            }
            return;
        }
    }

    if (bRewardGranted == 1)
    {
        if (!pQuestData->pGame->bExpansion)
        {
            return;
        }

        if (!bCustom5)
        {
            if (nNpcId == 367)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 367, 4);
            }
            else if (nNpcId == 246)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 246, 5);
            }
        }

        if (!bCustom4)
        {
            if (nNpcId == 246)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 246, 4);
            }
            else if (nNpcId == 367)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 367, 5);
            }
        }
        return;
    }

    if ((pQuestData->fState < 4 || bPrimaryGoalDone) && pQuestData->bNotIntro && pQuestData->fState)
    {
        const int nIndex = nIndices_0073D56C[pQuestData->fState];
        if (nIndex != -1 && (unsigned int)nIndex < 7)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

// 0x005B4A80
int __fastcall ACT4Q2_UnitIterate_WarpToTownEndGame(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    sub_6FC7BEC0(pGame, pUnit);
    UNITS_GetPlayerData(pUnit)->bBusy = 1;

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)QUESTS_GetQuestData(pGame, 23)->pQuestDataEx;
    pQuestDataEx->unk0x20 = pUnit;

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 13))
    {
        LEVEL_WarpUnit(pGame, pUnit, 103, 0);

        D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 440);
        D2GSPacketSrv5D packet5D = {};
        packet5D.nHeader = 0x5D;
        packet5D.nQuestId = 23;
        packet5D.nFlags = 1;
        sub_6FC3F380(pClient, &packet5D);
    }
    else
    {
        D2GSPacketSrv50 packet50;
        packet50.nHeader = 0x50;
        *(unsigned short*)packet50.nQuestId = 23;
        D2GAME_SendPacket0x50_6FC3F440(SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 474), &packet50);
    }

    return 0;
}

// 0x005B5880
int __fastcall OBJECTS_OperateFunction73_LastLastPortal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2GameStrc* pGame = pOp->pGame;
    if (!pGame->bExpansion)
    {
        return 0;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pOp->pPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 26, 13))
    {
        SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pPlayer);
    if (!pRoom)
    {
        return 0;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) != 3)
    {
        return 0;
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 28, 0))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 28, 0);
        QUESTRECORD_SetQuestState(pQuestFlags, 28, 13);

        D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pOp->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 1370);
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pOp->pPlayer);
        if (pClient && !PLAYER_IsBusy(pOp->pPlayer))
        {
            SUNIT_ResetInteractInfo(pOp->pPlayer);
            pPlayerData->bBusy = 1;

            D2GSPacketSrv5D packet5D = {};
            packet5D.nHeader = 0x5D;
            packet5D.nQuestId = 23;
            packet5D.nFlags = 2;
            sub_6FC3F380(pClient, &packet5D);
            sub_0053D940_SendPacket0x61(pClient, 5);
        }
    }

    D2GAME_PlayerChangeAct_6FC867C0(pOp->pGame, pOp->pPlayer, 109, 5);
    QUESTS_UpdatePlayerFlags(pOp->pGame, pOp->pPlayer);
    sub_005B4FF0_ActivateHarrogathWaypoint(pOp->pGame, pOp->pPlayer);
    return 0;
}

// 0x005B6100
void __fastcall ACT4Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (nNPCNo != 246)
    {
        return;
    }

    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;
    if (nMessageIndex == 678)
    {
        pQuestDataEx->bCainActivated = 1;
        QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 462);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
    else if (nMessageIndex == 679)
    {
        if (QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' ssm', 0, 2, 1))
        {
            pQuestDataEx->bCainActivated = 1;
            if (pQuestData->fState < 2)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 513);
            }
            pQuestDataEx->bSoulstoneAcquired = 1;
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
    else if (nMessageIndex == 680)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 13) && pQuestData->fState != 5)
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 13, 0, ACT4Q3_UnitIterate_StatusCyclerEx, false);
                QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 530);
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 531);
                pQuestData->pfSeqFilter(pQuestData);
            }

            QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0);
            QUESTRECORD_ClearQuestState(pQuestFlags, pQuestData->nQuestFilter, 1);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
}

// 0x005B62D0
void __fastcall ACT4Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 13);

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
    }
    else if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
    }
    else if (pQuestData->fState && bRewardGranted != 1 && (pQuestData->fState < 4 || bPrimaryGoalDone)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 27, 1) && pQuestData->bNotIntro)
    {
        if (pQuestData->fState == 1)
        {
            if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' ssm'))
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
            }
            else if (!((D2Act4Quest3Strc*)pQuestData->pQuestDataEx)->bSoulstoneAcquired && pQuestData->fLastState < 3)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
            }
        }
        else
        {
            if (!ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' ssm') && pQuestData->fLastState < 3 && !((D2Act4Quest3Strc*)pQuestData->pQuestDataEx)->bSoulstoneAcquired)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
            }
        }
    }
}

// 0x005B65D0
void __fastcall ACT4Q3_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    pQuestArg->pTarget->dwDropItemCode = ' hfh';
    int nItemLevel;
    if (D2GAME_DropItemAtUnit_6FC4FEC0(pQuestArg->pGame, pQuestArg->pTarget, 7, &nItemLevel, 0, -1, 0))
    {
        ++pQuestDataEx->nHellforgeHammersInGame;
    }
}

// 0x005B7400
void __fastcall ACT3Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, 17, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, 17, 13);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (bRewardGranted == 1 && !bPrimaryGoalDone)
    {
        return;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' bbb'))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
    }
    else if (bRewardGranted == 1)
    {
        if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        }
    }
    else if (pQuestData->bNotIntro && pQuestData->fState < 4)
    {
        const int nIndex = nIndices_0073F188[pQuestData->fState];
        if (nIndex != -1 && (unsigned int)nIndex < 6)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

// 0x005B74E0
int __fastcall ACT3Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom)
    {
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 17, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 17, 1) && DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) == 2)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 17, 13);
            QUESTRECORD_SetQuestState(pQuestFlags, 17, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 17, 1);
            QUESTS_UpdatePlayerFlags(pGame, pUnit);
        }
    }
    return 0;
}

// 0x005B7A60
int __fastcall OBJECTS_OperateFunction28_LamEsenTome(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 15);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return 0;
    }

    if (!pOp->pObject || pOp->pObject->dwAnimMode == 0)
    {
        D2GameStrc* pGame = pOp->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pOp->pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, 17, 0) == 1)
        {
            SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
            return 0;
        }

        pOp->pObject->dwDropItemCode = ' bbb';
        int nItemLevel;
        if (D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, 2, &nItemLevel, 0, -1, 0))
        {
            UNITS_ChangeAnimMode(pOp->pObject, 2);

            D2Act3Quest1Strc* pQuestDataEx = (D2Act3Quest1Strc*)pQuestData->pQuestDataEx;
            pQuestDataEx->nTomesInGame += 1;
            pQuestDataEx->bTomeActive = 1;
            pQuestDataEx->bTomeDropped = 1;
            pQuestDataEx->nTomeObjectMode = 2;
            pQuestDataEx->nTomeGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

            pQuestData->pfCallback[0] = ACT3Q1_Callback00_NpcActivate;
            pQuestData->pfCallback[11] = ACT3Q1_Callback11_ScrollMessage;

            if (pQuestData->fState != 3)
            {
                QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q1.cpp", 699);
            }

            if (pQuestData->fLastState != 1)
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q1_UnitIterate_StatusCyclerEx, false);
            }
        }
    }

    return 0;
}

// 0x005B8B20
int __fastcall ACT3Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 19, 6) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 17);
    if (!pQuestData)
    {
        return 0;
    }

    if (ITEMS_FindQuestItem(pGame, pUnit, ' 33g'))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 19, 5);
        return 0;
    }

    if (((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->bGidbinnDropped)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 19, 4);

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 3))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 19, 2);
        }
    }
    else
    {
        if (pQuestData->fState == 2)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 19, 3);
        }
    }

    return 0;
}

// 0x005B8E10
bool __fastcall ACT3Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 0))
    {
        return false;
    }

    if (nNpcId == 253)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 33g') || pQuest->fState != 1)
        {
            return false;
        }

        return true;
    }
    else if (nNpcId == 255)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 33g'))
        {
            return true;
        }

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 6))
        {
            return false;
        }

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 8))
        {
            return true;
        }
    }
    else if (nNpcId == 252)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 6))
        {
            return false;
        }

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 7))
        {
            return true;
        }
    }

    return false;
}

// 0x005B8EC0
void __fastcall ACT3Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, 19, 0);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (bRewardGranted == 1)
    {
        if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        }
        return;
    }

    D2UnitStrc* pGidbinn = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 33g');
    if (pGidbinn && QUESTRECORD_GetQuestState(pQuestFlags, 19, 5) && !QUESTRECORD_GetQuestState(pQuestFlags, 19, 8))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 6))
    {
        const int bNoCustom4 = !QUESTRECORD_GetQuestState(pQuestFlags, 19, 8);
        const int bNoCustom3 = !QUESTRECORD_GetQuestState(pQuestFlags, 19, 7);
        if (nNpcId == 252)
        {
            if (bNoCustom3)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
                return;
            }
        }
        else
        {
            if (nNpcId == 255 && bNoCustom4)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 6);
                return;
            }

            if (bNoCustom3)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
                return;
            }
        }

        if (bNoCustom4)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 6);
        }
    }
    else
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 5))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
            return;
        }

        if (pQuestData->fState < 4 && !pGidbinn)
        {
            const int nIndex = nIndices_007401B8[pQuestData->fState];
            if (nIndex != -1 && (unsigned int)nIndex < 8)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
            }
        }
    }
}

// 0x005B9700
void __fastcall ACT3Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    D2UnitStrc* pGidbinn = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 33g');
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
    if (pGidbinn)
    {
        ++pQuestDataEx->nGidbinnsInGame;
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 0))
    {
    if (pGidbinn)
    {
        pQuestData->fLastState = 4;
        pQuestData->fState = 4;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q3_UnitIterate_UpdateQuestStateFlags);
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 6) == 1)
    {
        pQuestDataEx->nAltarObjectMode = 2;
        pQuestData->fState = 5;

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 7))
        {
            pQuestData->fLastState = 5;
        }
        else if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 8))
        {
            pQuestData->fLastState = 6;
        }
        else
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 19, 0);
            pQuestData->bNotIntro = 0;
        }
    }
    else
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 5) == 1)
        {
            pQuestData->fState = 3;
            pQuestData->fLastState = 2;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 4) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 19, 3) == 1)
        {
            pQuestData->fState = 2;
            pQuestData->fLastState = 2;
        }
        else if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 2) == 1)
        {
            pQuestData->fState = 3;
            pQuestData->fLastState = 1;
        }
    }
    }
    else
    {
        pQuestDataEx->nAltarObjectMode = 2;
    }
}

// 0x005B9980
void __fastcall ACT3Q3_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "killed boss for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 991);

    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;

    if (!pQuestDataEx->bBossHasSpawned || !pQuestData->bNotIntro || (!MONSTERUNIQUE_CheckMonTypeFlag(pQuestArg->pTarget, 14) && !MONSTERS_IsBoss(0, pQuestArg->pTarget)))
    {
        return;
    }

    pQuestArg->pTarget->dwDropItemCode = ' 33g';
    int nItemLevel;
    if (D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pQuestArg->pTarget, 2, &nItemLevel, 0, -1, 0))
    {
        pQuestDataEx->bGidbinnDropped = 1;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q3_UnitIterate_UpdateQuestStateFlags);
        pQuestData->pfCallback[8] = 0;
    }
    else
    {
        pQuestDataEx->bBossHasSpawned = 0;
    }
}

// 0x005B9D90
bool __fastcall ACT3Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
    {
        return false;
    }

    if (nNpcId == 254)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43g'))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
        {
            return true;
        }
    }
    else if (nNpcId == 264)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43j'))
        {
            return true;
        }
    }
    else if (nNpcId == 245)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43j') && !QUESTRECORD_GetQuestState(pQuestFlags, 20, 2))
        {
            return true;
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43g') && !QUESTRECORD_GetQuestState(pQuestFlags, 20, 4))
        {
            return true;
        }
    }

    return false;
}

// 0x005BA870
void __fastcall ACT3Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;

    if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
    {
        pQuestData->bNotIntro = 0;
        pQuestDataEx->unk0x01 = 0;
        pQuestDataEx->unk0x0C = 0;
        return;
    }

    D2UnitStrc* pGoldenBird = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43g');
    D2UnitStrc* pJadeFigurine = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43j');
    if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
    {
        pQuestData->bNotIntro = 0;
        pQuestDataEx->unk0x01 = 0;
        pQuestDataEx->unk0x0C = 0;
        return;
    }

    if (pGoldenBird)
    {
        pQuestDataEx->unk0x01 = 0;
        pQuestDataEx->unk0x0C = 0;
        if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 4))
        {
            pQuestData->fState = 3;
            pQuestData->fLastState = 4;
        }
        else
        {
            pQuestData->fState = 3;
            pQuestData->fLastState = 3;
        }
    }
    else if (pJadeFigurine)
    {
        pQuestDataEx->unk0x01 = 0;
        pQuestDataEx->unk0x0C = 0;
        if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 2))
        {
            pQuestData->fState = 2;
            pQuestData->fLastState = 2;
        }
        else
        {
            pQuestData->fState = 1;
            pQuestData->fLastState = 1;
        }
    }
}

// 0x005BB210
void __fastcall ACT3Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 0) == 1)
    {
        return;
    }

    if (nNPCNo == 255)
    {
        if (nMessageIndex == 594)
        {
            if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 432);
            }
            else
            {
                QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 436);
            }

            ((D2Act3Quest5Strc*)pQuestData->pQuestDataEx)->bOrmusActivated = 1;
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
    else if (nNPCNo == 245)
    {
        if (nMessageIndex == 626 && QUESTRECORD_GetQuestState(pQuestFlags, 21, 4))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, 18, 0))
            {
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' yeq');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' rhq');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' rbq');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 1fq');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 2fq');
            }

            if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 13) && pQuestData->fState != 7)
            {
                QUESTS_SetGlobalState(pQuestArg->pGame, 21, 13);
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 13, 0, ACT3Q5_UnitIterate_StatusCyclerEx, false);
                QUESTS_StateDebug(pQuestData, 7, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 462);
            }

            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 465);
            pQuestData->pfSeqFilter(pQuestData);

            QUESTRECORD_SetQuestState(pQuestFlags, 21, 0);
            QUESTRECORD_ClearQuestState(pQuestFlags, 21, 4);

            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
}

// 0x005BC5A0
void __fastcall ACT3Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 22, 11) && QUESTRECORD_GetQuestState(pQuestFlags, 22, 0))
    {
        return;
    }

    if (nNPCNo == 255 && nMessageIndex == 628)
    {
        if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
        {
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 463);
        }
        else
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 467);
        }

        ((D2Act3Quest6Strc*)pQuestData->pQuestDataEx)->bOrmusActivated = 1;
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        return;
    }

    if (nMessageIndex == 658 || nMessageIndex == 657 || nMessageIndex == 659 || nMessageIndex == 660
        || nMessageIndex == 661 || nMessageIndex == 662 || nMessageIndex == 663)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 22, 11))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, 22, 13))
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 13, 0, ACT3Q6_UnitIterate_StatusCyclerEx, false);
                QUESTS_StateDebug(pQuestData, 7, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 487);
            }

            QUESTRECORD_ClearQuestState(pQuestFlags, 22, 11);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        }
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
}

// 0x005BD0D0
int __fastcall ACT3Q7_GetWandererCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 28);
    if (pQuestData)
    {
        D2Act3Quest7Strc* pQuestDataEx = (D2Act3Quest7Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bDarkWandererInitialized)
        {
            *pCoord = pQuestDataEx->tDarkWandererCoords;

            if (pQuestDataEx->bWandererCoordsCalculated)
            {
                return 1;
            }

            pCoord->nY += -20;
            pQuestDataEx->bWandererCoordsCalculated = 1;

            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                pQuestDataEx->tDarkWandererCoords = *pCoord;
                return 1;
            }

            pCoord->nY += 9;
            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                pQuestDataEx->tDarkWandererCoords = *pCoord;
                return 1;
            }

            pCoord->nX += 2;
            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                pQuestDataEx->tDarkWandererCoords = *pCoord;
                return 1;
            }

            pCoord->nX += -4;
            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                pQuestDataEx->tDarkWandererCoords = *pCoord;
                return 1;
            }

            *pCoord = pQuestDataEx->tDarkWandererCoords;
            pCoord->nY += -8;
            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                pQuestDataEx->tDarkWandererCoords = *pCoord;
                return 1;
            }

            pCoord->nY += 5;
            pQuestDataEx->tDarkWandererCoords = *pCoord;
            return 1;
        }
    }

    return 0;
}

// 0x005BD500
bool __fastcall ACT3Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 245)
    {
        if (pQuest->fState >= 1 && !QUESTRECORD_GetQuestState(pQuestFlags, 18, 2))
        {
            return true;
        }

        int nParts = 0;
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 1fq'))
        {
            ++nParts;
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 5))
            {
                return true;
            }
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' yeq'))
        {
            ++nParts;
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 3))
            {
                return true;
            }
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' rhq'))
        {
            ++nParts;
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 6))
            {
                return true;
            }
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' rbq'))
        {
            ++nParts;
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 4))
            {
                return true;
            }
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 2fq') && !QUESTRECORD_GetQuestState(pQuestFlags, 18, 7) && sub_005BBF80_ACT3Q5_IsOrbNotSmashed(pQuest->pGame))
        {
            return true;
        }

        if (nParts == 4 && !QUESTRECORD_GetQuestState(pQuestFlags, 18, 5))
        {
            return true;
        }
    }

    return false;
}

// 0x005BD850
bool __fastcall ACT3Q2_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;

    if (!QUESTRECORD_GetQuestState(pFlags, 15, 0))
    {
        return true;
    }

    const int bStarted = QUESTRECORD_GetQuestState(pFlags, 18, 2);
    if (bStarted || pQuest->bNotIntro && pQuest->fState >= 2)
    {
        *pStatus = 1;
    }

    int nParts = 0;
    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 2fq'))
    {
        D2QuestDataStrc* pQuestData19 = QUESTS_GetQuestData(pQuest->pGame, 19);
        const bool bNotSmashed = pQuestData19 ? ((D2Act3Quest5Strc*)pQuestData19->pQuestDataEx)->bOrbSmashed == 0 : true;
        if (bNotSmashed)
        {
            *pStatus = 6;
        }
        else
        {
            *pStatus = 12;
        }
        return true;
    }

    int bBaseFlail = 0;
    int bEye = 0;
    int bHeart = 0;
    int bBrain = 0;
    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 1fq'))
    {
        ++nParts;
        bBaseFlail = 1;
    }

    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' yeq'))
    {
        ++nParts;
        bEye = 1;
    }

    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' rhq'))
    {
        ++nParts;
        bHeart = 1;
    }

    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' rbq'))
    {
        ++nParts;
        bBrain = 1;
    }

    if (nParts == 4)
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 18, 5) ? 5 : 7;
        return true;
    }

    if (nParts)
    {
        if (!bEye)
        {
            *pStatus = 1;
            return true;
        }

        if (!bBrain)
        {
            *pStatus = 2;
            return true;
        }

        if (!bHeart)
        {
            *pStatus = 4;
            return true;
        }

        *pStatus = bBaseFlail ? 7 : 3;
        return true;
    }

    if (bStarted)
    {
        *pStatus = 1;
        return true;
    }

    *pStatus = pQuest->fState > 1;
    return true;
}

// 0x005B3DE0
int __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 25, 13))
    {
        return 0;
    }
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT4Q1_UnitIterate_SetPrimaryGoalDone, 0);
    }
    return 0;
}
