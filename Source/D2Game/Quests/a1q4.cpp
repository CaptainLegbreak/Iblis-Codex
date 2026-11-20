#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define QUEST_A1Q4_CAIN 4
#define QUESTSTATEFLAG_A1Q4 4
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define MONSTER_AKARA 148
#define MONSTER_CAIN1 146
#define LINE_ITEM_PICKED 1222
struct D2NPCMessageTableStrc;
struct D2SeedStrc;
struct D2PlayerDataStrc;
struct D2StaticPathStrc;
struct D2QuestGUIDStrc;
struct D2ObjOperateFnStrc;
struct D2MissilesTxt;
struct D2Act1Quest4Strc;
struct D2Act1Quest5Strc;
struct D2Act2Quest0Strc;
struct D2Act2Quest1Strc;
struct D2Act2Quest6Strc;
struct D2Act3Quest5Strc;
struct D2Act5Quest2Strc;
struct D2GSPacketSrv50;


struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};




struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

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
    union
    {
        unsigned int dwFlags;
        unsigned char nFlagsByte;
        unsigned char nFlags;
    };
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

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    D2TextHeaderStrc* pTextControl;
    unsigned short nMessageIndex;
    unsigned char unk_1A[0x2];
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
    unsigned int dwFrameCnt[2];
};

struct D2MissilesTxt
{
    char unk0x00[0x96];
    short wRange;
    char unk0x98[0x10C];
};


struct D2Act1Quest4Strc
{
    unsigned short nStoneOrder[5];
    unsigned short pad0x0A;
    unsigned short nCurrentMonolithNo;
    unsigned char pad0x0E[2];
    int nMonolithGUIDs[5];
    int unused0x24;
    int nInvisibleObjectGUID;
    short nCairnStoneInteractions;
    unsigned char pad0x2E[2];
    int nInifussTreeGUID;
    int nCainGibbetGUID;
    int nDecipheredScrollGUID;
    int nPlayerGUID;
    int nCairnStoneAlphaGUID;
    unsigned char bOpenPortalTimerActive;
    unsigned char bPortalToTristramOpened;
    unsigned char bTimerActive;
    unsigned char bInifussTreeInitialized;
    unsigned char bCageModeChanged;
    unsigned char bInvisbleObjectInitialized;
    unsigned char bStoneOrderInitialized;
    unsigned char unk0x4B;
    unsigned char unk0x4C;
    unsigned char bActivateCairnStones;
    unsigned char bDecipheredScrollAcquired;
    unsigned char bOperatedWithLastCairnStone;
    unsigned char unk0x50;
    unsigned char bCainInTownSpawned;
    unsigned char bCainInTownSpawnPending;
    unsigned char bAkaraIntroActivated;
    int nCainGibbetObjectMode;
    int unk0x58;
    unsigned char bCairnStonesActive[5];
    unsigned char bCainRemovedFromTristram;
    unsigned char bCainNotCreated;
    unsigned char bQuestCompleteBefore;
    unsigned char bAkaraActivatedForScroll;
    unsigned char unk0x65;
    unsigned char bPortalFromTristramToTownSpawned;
    unsigned char bCainPortalCoordsInitialized;
    int nCainMonsterInTownGUID;
    int nCainObjectGUID;
    unsigned char bCainObjectInitialized;
    unsigned char pad0x71[3];
    D2UnitStrc* pPlayerInTristram;
    unsigned char bScrollAcquired;
    unsigned char pad0x79[3];
    int nScrollsInGame;
    char pad0x80[0x13];
    unsigned char bCainInTristramDeactivated;
    char pad0x94[0x20];
    D2QuestGUIDStrc pQuestGUID;
    D2QuestGUIDStrc tPlayerGUIDs;
};

struct D2Act1Quest5Strc
{
    int nUnitGUIDs1[12];
    unsigned short nUnitCount1;
    unsigned char pad0x32[2];
    int nUnitGUIDs2[12];
    unsigned short nUnitCount2;
};

struct D2Act2Quest0Strc
{
    D2QuestGUIDStrc tPlayerGUIDs;
};

struct D2Act2Quest1Strc
{
    char unk0x00[0x04];
    D2ActiveRoomStrc* pRoom;
};

struct D2Act2Quest6Strc
{
    char unk0x00[0x03];
    unsigned char bTimerActive;
    char unk0x04[0x09];
    unsigned char bObjectsNeedUpdate;
    unsigned char bStaffItemsRemoved;
};

struct D2Act3Quest5Strc
{
    char unk0x00[0x0C];
    unsigned char bOrbSmashed;
    char unk0x0D[0x1F];
    int nCompellingOrbGUID;
    char unk0x30[0x08];
    int nHits;
};

struct D2Act5Quest2Strc
{
    char unk0x00[0xEC];
    int nPortalGUIDs[3];
    unsigned char bPortalSpawned[3];
    unsigned char pad0xFB;
    int nPortalUpdateInvocations[3];
    unsigned char unk0x108[3];
    unsigned char bChangeToSpecialObjectMode[3];
    unsigned char unk0x10E[6];
    int unk0x114[3];
};

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

typedef int (__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode); // 0x00544160
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520
int __fastcall QUESTS_QuickCheckPlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545290
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2); // 0x00545760
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x005723C0
int __fastcall sub_00587FC0_GetWussieGroupIndex(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00587FC0
void __fastcall ACT1Q4_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005930B0
void __fastcall sub_005940A0_ACT1Q4_RemovePlayerGUID(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005940A0
void __fastcall ACT2Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00598D40
bool __fastcall ACT2Q6_Timer_UpdateObjects(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x0059D870
void __fastcall ACT2Q6_UnitIterate_DeleteHoradricItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059DBD0
void __fastcall ACT3Q5_UnitIterate_DeleteKhalimItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BB850
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
void __fastcall QUESTSFX_SpawnCompellingOrbMissile(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005DFEE0
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId); // 0x00544190
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
void __fastcall QUESTS_RemovePlayerGUID(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00545530
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
void __fastcall SUNITINACTIVE_DeleteSingleListNode(D2GameStrc* pGame, unsigned short nUnitType, unsigned short nClassId, unsigned char nAct); // 0x00543140
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, void* pItemDrop, int a6, int a7); // 0x00559A30
int __fastcall ACT1Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005920D0
int __fastcall ACT1Q4_UnitIterate_RemoveCainFromTristram(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005928C0
int __fastcall ACT1Q4_UnitIterate_AddPlayerGUIDs(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00592B10
void __fastcall ACT1Q4_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592C80
bool __fastcall ACT1Q4_Timer_RemoveCainFromTristram(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x00593260

#pragma pack(push, 1)
struct D2GSPacketSrv50
{
    unsigned char nHeader;
    unsigned short nQuestId;
    unsigned short nStoneOrder[5];
    unsigned char unk0x0D[3];
};

#pragma pack(pop)

extern const char gszAct1Q4SourceFile[]; // 0x006E1C48
void __fastcall sub_00592E90_InitializeStoneOrder(D2QuestDataStrc* pQuestData); // 0x00592E90
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket); // 0x0053D7E0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2MapAIStrc
{
    int unk0x00;
    void* pPosition;
};
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300
void __fastcall ACT1Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005921B0
void __fastcall ACT1Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592250
void __fastcall ACT1Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592580
void __fastcall ACT1Q4_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592B90
void __fastcall ACT1Q4_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592CF0
void __fastcall ACT1Q4_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592E20
void __fastcall ACT1Q4_Callback06_ResetInifussTree(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592E60
bool __fastcall ACT1Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00592FB0
bool __fastcall ACT1Q4_SeqCallback(D2QuestDataStrc* pQuestData); // 0x00593D70
void __fastcall ACT1Q4_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00593E70
void __fastcall ACT1Q4_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00596DE0
void __fastcall ACT1Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00597030

inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    D2MissilesTxt* pRecord;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        pRecord = 0;
    }
    else
    {
        pRecord = &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return pRecord;
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00586B50
void __fastcall ACT5Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nPlayerClass = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;

    int nSpecialIntroClass1 = 7;
    int nSpecialIntroClass2 = 7;
    switch (nNpcId)
    {
    case 513:
        nSpecialIntroClass1 = 4;
        nSpecialIntroClass2 = 1;
        break;
    case 514:
        nSpecialIntroClass1 = 6;
        nSpecialIntroClass2 = 2;
        break;
    case 515:
        nSpecialIntroClass1 = 5;
        nSpecialIntroClass2 = 3;
        break;
    case 512:
    case 520:
        break;
    default:
        return;
    }

    if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId))
    {
        return;
    }

    if (nPlayerClass == nSpecialIntroClass1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
    else if (nPlayerClass == nSpecialIntroClass2)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
    }
}

// 0x00588880
void __fastcall ACT5Q2_UpdateWussieCounters(D2GameStrc* pGame, int nUnused, D2UnitStrc* pWussie)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 32);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return;
    }

    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    int nIndex = sub_00587FC0_GetWussieGroupIndex(pQuestData, pWussie);
    if (nIndex >= 0)
    {
        pQuestDataEx->unk0x114[nIndex] += 1;
        if (pQuestDataEx->unk0x114[nIndex] >= 5)
        {
            pQuestDataEx->unk0x108[nIndex] = 1;
        }
    }
}

// 0x00588D60
int __fastcall ACT5Q2_FindPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc** ppPortal)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 32);
    if (pQuestData)
    {
        D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
        int nIndex = sub_00587FC0_GetWussieGroupIndex(pQuestData, pUnit);
        if (nIndex >= 0 && pQuestDataEx->bPortalSpawned[nIndex])
        {
            D2UnitStrc* pPortal = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nPortalGUIDs[nIndex]);
            if (pPortal)
            {
                *ppPortal = pPortal;
                return 1;
            }
        }
    }

    return 0;
}

// 0x0058F8F0
void __fastcall ACT1Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nPlayerClass = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;

    int nSpecialClass;
    switch (nNpcId)
    {
    case 150:
        nSpecialClass = 0;
        break;
    case 147:
        nSpecialClass = 2;
        break;
    case 154:
        nSpecialClass = 4;
        break;
    case 148:
        nSpecialClass = 1;
        break;
    default:
        return;
    }

    if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId))
    {
        return;
    }

    if (nPlayerClass == nSpecialClass)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
    }
}

// 0x00593480
int __fastcall OBJECTS_OperateFunction10_CainGibbet(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 4);
    D2Act1Quest4Strc* pQuestDataEx = 0;
    if (pQuestData)
    {
        pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (!pQuestData->bNotIntro || pQuestDataEx->unk0x50 == 1 || pQuestData->fState >= 6)
        {
            return 0;
        }
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 4, 1) || QUESTRECORD_GetQuestState(pQuestFlags, 4, 0))
    {
        SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
        return 0;
    }

    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);

    if (pOp->pObject && pOp->pObject->dwAnimMode != 0)
    {
        return 0;
    }

    UNITS_ChangeAnimMode(pOp->pObject, 1);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame, 0, 0);

    if (pQuestDataEx)
    {
        pQuestDataEx->nCainGibbetObjectMode = 3;
        pQuestDataEx->nPlayerGUID = !pOp->pPlayer ? -1 : pOp->pPlayer->dwUnitId;
    }

    EVENT_SetEvent(pOp->pGame, pOp->pObject, 7, pOp->pGame->dwGameFrame + 17, 0, 0);
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pOp->pObject), 0);

    QUESTRECORD_SetQuestState(pQuestFlags, 4, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 4, 1);

    QUESTS_UpdatePlayerFlags(pOp->pGame, pOp->pPlayer);

    const unsigned short nPartyId = SUNIT_GetPartyId(pOp->pPlayer);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pOp->pGame, nPartyId, ACT1Q4_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x005952C0
bool __fastcall ACT1Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuest->pQuestDataEx;
    int nUnitId = !pPlayer ? -1 : pPlayer->dwUnitId;

    for (int i = 0; i < pQuestDataEx->nUnitCount2; ++i)
    {
        if (pQuestDataEx->nUnitGUIDs2[i] == nUnitId)
        {
            if (nNpcId == 155 || nNpcId == 147)
            {
                return false;
            }

            return true;
        }
    }

    return false;
}

// 0x005984C0
void __fastcall ACT2Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nPlayerClass = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;

    int nSpecialIntroClass = 7;
    switch (nNpcId)
    {
    case 199:
        nSpecialIntroClass = 2;
        break;
    case 200:
        nSpecialIntroClass = 4;
        break;
    case 210:
        nSpecialIntroClass = 0;
        break;
    case 178:
        nSpecialIntroClass = 3;
        break;
    case 177:
        nSpecialIntroClass = 1;
        break;
    case 175:
    case 198:
    case 202:
        break;
    default:
        return;
    }

    if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId))
    {
        return;
    }

    if (nPlayerClass == nSpecialIntroClass)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
    }
}

// 0x005986B0
void __fastcall ACT2Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (nNpcId == 201)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 8, 0))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 201, 0);
        }
    }
    else if (nNpcId == 244)
    {
        D2Act2Quest0Strc* pQuestDataEx = (D2Act2Quest0Strc*)pQuestData->pQuestDataEx;
        if (QUESTRECORD_GetQuestState(pQuestFlags, 4, 14) != 1)
        {
            return;
        }

        const int nUnitId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;
        if (QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->tPlayerGUIDs, nUnitId))
        {
            return;
        }

        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 244, 1);
        sub_005940A0_ACT1Q4_RemovePlayerGUID(pQuestData->pGame, pQuestArg->pPlayer);
    }
}

// 0x00598E20
int __fastcall ACT2Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 8);
    D2_ASSERT(pQuestData, 390);

    D2Act2Quest1Strc* pQuestDataEx = (D2Act2Quest1Strc*)pQuestData->pQuestDataEx;
    int bInRange = 0;
    if (pRoom == pQuestDataEx->pRoom)
    {
        bInRange = 1;
    }
    else
    {
        D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
        D2_ASSERT(pUnitRoom, 405);

        D2ActiveRoomStrc** ppRoomList;
        unsigned int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pUnitRoom, &ppRoomList, &nNumRooms);
        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] == pQuestDataEx->pRoom)
            {
                bInRange = 1;
                break;
            }
        }
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0))
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1))
    {
        return 0;
    }

    if (!bInRange)
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->nQuestFilter, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1);
    QUESTRECORD_SetQuestState(pQuestFlags, 9, 5);
    QUESTS_UpdatePlayerFlags(pQuestData->pGame, pUnit);

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT2Q1_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x0059DD80
void __fastcall ACT2Q6_DeleteAllHoradricItemsAndOpenTomb(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_SetQuestState(pQuestFlags, 10, 0);
    pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_SetQuestState(pQuestFlags, 10, 13);

    QUESTS_DeleteItem(pGame, pUnit, ' tsh');
    QUESTS_DeleteItem(pGame, pUnit, ' piv');
    QUESTS_DeleteItem(pGame, pUnit, ' fsm');

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT2Q6_UnitIterate_DeleteHoradricItems, 0);
    }

    QUESTS_TriggerFX(pGame, 3);

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(338);
    const int nTicks = (pMissilesTxtRecord->wRange - 75) / 20;

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bObjectsNeedUpdate = 1;
    pQuestDataEx->bStaffItemsRemoved = 1;
    if (!pQuestDataEx->bTimerActive)
    {
        QUESTS_CreateTimer(pQuestData, ACT2Q6_Timer_UpdateObjects, nTicks);
        pQuestDataEx->bTimerActive = 1;
    }

    UNITS_ChangeAnimMode(pObject, 1);

    D2ActiveRoomStrc* pObjectRoom = UNITS_GetRoom(pObject);
    D2_ASSERT(pObjectRoom, 1670);

    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(pObjectRoom, UNITS_GetUnitXPosition(pObject) - 13, UNITS_GetUnitYPosition(pObject) + 3);
    DUNGEON_ToggleHasPortalFlag(pObjectRoom, 0);
    if (pRoom)
    {
        DUNGEON_ToggleHasPortalFlag(pRoom, 0);
    }
}

// 0x005B6D30
void __fastcall ACT3Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nPlayerClass = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;

    int nSpecialIntroClass = 7;
    switch (nNpcId)
    {
    case 254:
        nSpecialIntroClass = 2;
        break;
    case 264:
        nSpecialIntroClass = 4;
        break;
    case 252:
        nSpecialIntroClass = 0;
        break;
    case 255:
        nSpecialIntroClass = 3;
        break;
    case 245:
    case 297:
        break;
    default:
        return;
    }

    if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId))
    {
        return;
    }

    if (nPlayerClass == nSpecialIntroClass)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
    }
}

// 0x005BB980
int __fastcall OBJECTS_OperateFunction53_CompellingOrb(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->pObject || pOp->pObject->dwAnimMode == 0)
    {
        D2UnitStrc* pItem = INVENTORY_GetLeftHandWeapon(pOp->pPlayer->pInventory);
        if (!pItem || ITEMS_GetBaseCode(pItem) != ' 2fq')
        {
            SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
        }
        else
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 19);
            D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;

            pQuestDataEx->nHits += 1;
            if (pQuestDataEx->nHits >= 2)
            {
                D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
                QUESTRECORD_SetQuestState(pQuestFlags, 18, 0);
                pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
                QUESTRECORD_SetQuestState(pQuestFlags, 18, 13);

                QUESTS_DeleteItem(pOp->pGame, pOp->pPlayer, ' 2fq');

                pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
                if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 4) && !QUESTRECORD_GetQuestState(sub_00543520(pOp->pGame, pOp->pPlayer), 21, 0))
                {
                    QUESTRECORD_SetQuestState(sub_00543520(pOp->pGame, pOp->pPlayer), 21, 0);
                }

                D2UnitStrc* pCompellingOrb = SUNIT_GetServerUnit(pOp->pGame, 1, pQuestDataEx->nCompellingOrbGUID);
                if (pCompellingOrb)
                {
                    AITACTICS_ChangeModeAndTargetCoordinates(pOp->pGame, pCompellingOrb, 0, 0, 0);
                    QUESTSFX_SpawnCompellingOrbMissile(pOp->pGame, pCompellingOrb);
                }

                UNITS_ChangeAnimMode(pOp->pObject, 1);
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pOp->pObject ? -1 : pOp->pObject->dwClassId);
                EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame, 0, 0);
                pQuestDataEx->bOrbSmashed = 1;

                QUESTS_TriggerFX(pQuestData->pGame, 10);
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 851);
                pQuestData->pfSeqFilter(pQuestData);

                const unsigned short nPartyId = SUNIT_GetPartyId(pOp->pPlayer);
                if (nPartyId != 0xFFFF)
                {
                    PARTY_IteratePartyMembers(pOp->pGame, nPartyId, ACT3Q5_UnitIterate_DeleteKhalimItems, 0);
                }
            }
        }
    }

    return 0;
}

static __forceinline int UNITS_GetGUIDOrNone(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

static __forceinline int UNITS_GetClassIdOrNone(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x005920D0
int __fastcall ACT1Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A1Q4_CAIN);
    }

    return 0;
}

// 0x005921B0
void __fastcall ACT1Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const short nClassId = UNITS_GetClassIdOrNone(pQuestArg->pTarget);
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;

    if (nClassId == MONSTER_AKARA)
    {
        if (pQuestDataEx->bAkaraIntroActivated == 1)
        {
            pQuestData->nFlagsByte = 0;
            QUESTS_UnitIterate(pQuestData, 1, pQuestArg->pPlayer, ACT1Q4_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bAkaraIntroActivated = 0;
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q4_UnitIterate_UpdateQuestStateFlags);
        }

        if (pQuestDataEx->bAkaraActivatedForScroll == 1)
        {
            pQuestData->nFlagsByte = 0;
            QUESTS_UnitIterate(pQuestData, QSTATE_3, pQuestArg->pPlayer, ACT1Q4_UnitIterate_StatusCyclerEx, 1);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q4_UnitIterate_UpdateQuestStateFlags);
            pQuestDataEx->bAkaraActivatedForScroll = 0;
        }
    }
    else if (nClassId == MONSTER_CAIN1)
    {
        pQuestDataEx->bCainInTristramDeactivated = 1;
    }
}

// 0x00592B10
int __fastcall ACT1Q4_UnitIterate_AddPlayerGUIDs(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDPENDING))
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_COMPLETEDNOW);

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN)->pQuestDataEx;
    QUESTS_AddPlayerGUID(&pQuestDataEx->pQuestGUID, UNITS_GetGUIDOrNone(pUnit));

    return 0;
}

// 0x00592B90
void __fastcall ACT1Q4_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;

    D2UnitStrc* pScroll = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEM_SCROLL_BKD);
    D2UnitStrc* pBook = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEM_BOOK_BKS);
    if (pScroll)
    {
        ++pQuestDataEx->nScrollsInGame;
    }

    if (pBook)
    {
        ++pQuestDataEx->nScrollsInGame;
    }
}

// 0x00592CF0
void __fastcall ACT1Q4_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pQuestGUID, UNITS_GetGUIDOrNone(pQuestArg->pPlayer));
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, UNITS_GetGUIDOrNone(pQuestArg->pPlayer));
}

// 0x00592E20
void __fastcall ACT1Q4_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "cairn stone item acquired", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", LINE_ITEM_PICKED);
    if (pQuestData->bNotIntro)
    {
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q4_UnitIterate_UpdateQuestStateFlags);
    }
}

// 0x00592860
static void sub_00592860_DebugStartedQuest(D2QuestDataStrc* pQuestData)
{
    QUESTS_DebugOutput(pQuestData->pGame, "Started quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 599);
}

int __fastcall OBJECTS_OperateFunction12_InifussTree(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 4);
    D2_ASSERT(pQuestData, 0x828);

    if (!pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 1);
        return 0;
    }

    if (pQuestData->fState >= 6)
    {
        return 0;
    }

    D2UnitStrc* pObject = pOp->pObject;
    if (pObject && pObject->dwAnimMode)
    {
        return 0;
    }

    D2GameStrc* pGame = pOp->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pOp->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 4, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 4, 1) == 1)
    {
        return 0;
    }

    if (ITEMS_FindQuestItem(pOp->pGame, pOp->pPlayer, ' dkb') || ITEMS_FindQuestItem(pOp->pGame, pOp->pPlayer, ' skb'))
    {
        SUNIT_AttachSound(pOp->pPlayer, 0x13, pOp->pPlayer);
        return 0;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    SUNIT_AttachSound(pOp->pPlayer, 0x2D, 0);
    pOp->pObject->dwDropItemCode = ' skb';
    sub_00592860_DebugStartedQuest(pQuestData);
    QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x84B);

    int nItemLevel;
    D2UnitStrc* pItem = D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, 2, &nItemLevel, 0, -1, 0);
    if (pItem)
    {
        pQuestData->pfCallback[9] = ACT1Q4_Callback09_PlayerDroppedWithQuestItem;
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 2, pOp->pPlayer, ACT1Q4_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->unk0x4B = 1;
        pQuestDataEx->nDecipheredScrollGUID = pItem->dwUnitId;
        pQuestDataEx->unk0x58 = 1;
        pQuestDataEx->bScrollAcquired = 1;
        ++pQuestDataEx->nScrollsInGame;
        UNITS_ChangeAnimMode(pOp->pObject, 1);
    }

    pQuestDataEx->bInifussTreeInitialized = 1;
    pQuestDataEx->nInifussTreeGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    return 0;
}

// 0x00596CA0
static void __stdcall ACT1Q4_UpdateObjects(char bUseRemovalTimer, char bMoveCainToTown, D2QuestDataStrc* pQuestData)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    D2UnitStrc* pCage = 0;
    if (pQuestDataEx->bCageModeChanged == 1)
    {
        pCage = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nCainGibbetGUID);
    }

    if (pCage && pCage->dwClassId == 0x1A)
    {
        int nAnimMode = 0;
        if (pCage)
        {
            nAnimMode = pCage->dwAnimMode;
        }

        if (nAnimMode != 3)
        {
            UNITS_ChangeAnimMode(pCage, 3);
            pQuestDataEx->nCainGibbetObjectMode = 3;
        }
    }
    else
    {
        pQuestDataEx->nCainGibbetObjectMode = 3;
    }

    if (pQuestDataEx->bInifussTreeInitialized == 1)
    {
        D2UnitStrc* pInifussTree = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nInifussTreeGUID);
        if (pInifussTree)
        {
            UNITS_ChangeAnimMode(pInifussTree, 1);
        }
    }

    if (bUseRemovalTimer)
    {
        if (!pQuestDataEx->bTimerActive)
        {
            pQuestDataEx->bTimerActive = 1;
            QUESTS_CreateTimer(pQuestData, ACT1Q4_Timer_RemoveCainFromTristram, 1);
        }
    }
    else if (bMoveCainToTown)
    {
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 1, 0, ACT1Q4_UnitIterate_RemoveCainFromTristram);
    }
    else
    {
        pQuestDataEx->unk0x50 = 1;
        return;
    }

    if (!bMoveCainToTown)
    {
        pQuestDataEx->unk0x50 = 1;
        return;
    }

    if (!pQuestDataEx->bCainRemovedFromTristram)
    {
        SUNITINACTIVE_DeleteSingleListNode(pQuestData->pGame, 1, 0x92, 0);
    }

    pQuestDataEx->unk0x50 = 1;
    if (!pQuestDataEx->bCainInTownSpawned)
    {
        pQuestDataEx->bCainInTownSpawnPending = 1;
    }
}

// 0x00596D70
void __fastcall sub_00596D70_StartCainRemoval(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (!pQuestDataEx->unk0x65)
        {
            ACT1Q4_UpdateObjects(1, 0, pQuestData);
            QUESTS_StateDebug(pQuestData, 6, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x351);
            pQuestDataEx->unk0x65 = 1;
        }
    }
    else
    {
        D2_ASSERT(pQuestData, 0x357);
    }
}

// 0x00597310
void __fastcall ACT1Q4_UpdateQuestStateOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1) == 1 || ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->unk0x50)
    {
        return;
    }

    if (pQuestData->fState >= 6)
    {
        return;
    }

    sub_00592860_DebugStartedQuest(pQuestData);
    ACT1Q4_UpdateObjects(0, 1, pQuestData);
    QUESTS_StateDebug(pQuestData, 7, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x9FD);
    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 5, pUnit, ACT1Q4_UnitIterate_StatusCyclerEx, 1);
    QUESTS_SetGlobalState(pGame, 4, 13);
    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT1Q4_UnitIterate_AddPlayerGUIDs);
}

// 0x00592BD0
static __declspec(noinline) void ACT1Q4_ResetInifussTree(D2QuestDataStrc* pQuestData)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;

    if (pQuestDataEx->bInifussTreeInitialized == 1)
    {
        D2UnitStrc* pInifussTree = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nInifussTreeGUID);
        if (pInifussTree && pInifussTree->dwClassId == 0x1E)
        {
            UNITS_ChangeAnimMode(pInifussTree, 0);
        }

        pQuestData->nFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q4_UnitIterate_StatusCyclerEx, true);
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x397);
        pQuestDataEx->unk0x58 = 0;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q4_UnitIterate_UpdateQuestStateFlags);
    }
    else
    {
        pQuestData->nFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q4_UnitIterate_StatusCyclerEx, true);
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x39F);
        pQuestDataEx->unk0x58 = 0;
    }
}

// 0x00592C80
void __fastcall ACT1Q4_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro || pQuestData->fState == 6)
    {
        return;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    const int dwItemCode = ITEMS_GetBaseCode(pQuestArg->pTarget);
    if (dwItemCode == 0x20646B62 || dwItemCode == 0x20736B62)
    {
        --pQuestDataEx->nScrollsInGame;
    }

    if (!pQuestDataEx->nScrollsInGame && pQuestData->fState <= 5 && pQuestDataEx->bOperatedWithLastCairnStone != 1 && pQuestDataEx->bInifussTreeInitialized == 1)
    {
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x3F7);
        ACT1Q4_ResetInifussTree(pQuestData);
    }
}

// 0x00592E60
void __fastcall ACT1Q4_Callback06_ResetInifussTree(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bOperatedWithLastCairnStone != 1 && pQuestData->fState <= 5)
    {
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x501);
        ACT1Q4_ResetInifussTree(pQuestData);
    }
}

// 0x00593CB0
void __fastcall ACT1Q4_SendStoneOrderToClient(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (!pQuestData)
    {
        return;
    }
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (!pQuestDataEx->bStoneOrderInitialized)
        {
            pQuestDataEx->bStoneOrderInitialized = 1;
            sub_00592E90_InitializeStoneOrder(pQuestData);
        }
        D2GSPacketSrv50 packet;
        packet.nHeader = 0x50;
        packet.nQuestId = 4;
        D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, gszAct1Q4SourceFile, 2169);
        int i = 0;
        if (i < 5)
        {
            do
            {
                packet.nStoneOrder[i] = pQuestDataEx->nStoneOrder[i] - 17;
                if (packet.nStoneOrder[i] >= 5)
                {
                    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 2175);
                    exit(-1);
                }
                ++i;
            } while (i < 5);
        }
        D2GAME_SendPacket0x50_6FC3F440(pClient, &packet);
    }
}

// 0x005971B0
void __fastcall ACT1Q4_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[3] = ACT1Q4_Callback03_ChangedLevel;
    pQuestData->pfCallback[4] = ACT1Q4_Callback04_ItemPickedUp;
    pQuestData->pfCallback[6] = ACT1Q4_Callback06_ResetInifussTree;
    pQuestData->pfCallback[14] = ACT1Q4_Callback14_PlayerJoinedGame;
    pQuestData->pfCallback[9] = ACT1Q4_Callback09_PlayerDroppedWithQuestItem;
    pQuestData->pfCallback[8] = ACT1Q4_Callback08_MonsterKilled;
    pQuestData->pNPCMessages = gpAct1Q4NpcMessages;
    pQuestData->nQuestFilter = 4;
    pQuestData->fLastState = 0;
    pQuestData->bActive = 1;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 6;
    pQuestData->pfActiveFilter = ACT1Q4_ActiveFilterCallback;
    pQuestData->pfCallback[0] = ACT1Q4_Callback00_NpcActivate;
    pQuestData->pfCallback[11] = ACT1Q4_Callback11_ScrollMessage;
    pQuestData->pfCallback[10] = ACT1Q4_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[2] = ACT1Q4_Callback02_NpcDeactivate;
    pQuestData->pfCallback[13] = ACT1Q4_Callback13_PlayerStartedGame;
    pQuestData->pfSeqFilter = ACT1Q4_SeqCallback;
    pQuestData->nSeqId = 3;

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act1Quest4Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 2399, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act1Quest4Strc));

    pQuestDataEx->nCurrentMonolithNo = 0;
    pQuestDataEx->bStoneOrderInitialized = 0;
    pQuestDataEx->bDecipheredScrollAcquired = 0;
    pQuestDataEx->unk0x4B = 0;
    pQuestDataEx->nCairnStoneInteractions = 0;
    pQuestDataEx->nInvisibleObjectGUID = 0;
    pQuestDataEx->bInvisbleObjectInitialized = 0;
    pQuestDataEx->nInifussTreeGUID = 0;
    pQuestDataEx->nDecipheredScrollGUID = 0;
    pQuestDataEx->bInifussTreeInitialized = 0;
    pQuestDataEx->bTimerActive = 0;
    pQuestDataEx->unk0x58 = 0;
    pQuestDataEx->nCainGibbetObjectMode = 0;
    pQuestDataEx->unk0x50 = 0;
    pQuestDataEx->bCairnStonesActive[0] = 0;
    pQuestDataEx->bCairnStonesActive[1] = 0;
    pQuestDataEx->bCairnStonesActive[2] = 0;
    pQuestDataEx->bCairnStonesActive[3] = 0;
    pQuestDataEx->bCairnStonesActive[4] = 0;
    pQuestDataEx->bCainInTownSpawned = 0;
    pQuestDataEx->bCainInTownSpawnPending = 0;
    pQuestDataEx->bCainRemovedFromTristram = 0;
    pQuestDataEx->bCainNotCreated = 0;
    pQuestDataEx->bAkaraIntroActivated = 0;
    pQuestDataEx->bAkaraActivatedForScroll = 0;
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->pQuestGUID);
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

#include "gen/data/Source/D2Game/Quests/a1q4.inc"
