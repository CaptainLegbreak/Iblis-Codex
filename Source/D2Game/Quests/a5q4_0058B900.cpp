#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2QuestGUIDStrc;
struct D2SeedStrc;
struct D2Act5Quest4Strc;
struct D2StaticPathStrc;
struct D2PlayerDataStrc;
struct D2MonStatsTxt;
struct D2ObjInitFnStrc;
struct D2ObjOperateFnStrc;
struct D2Act5Quest5Strc;
struct D2Act5Quest6Strc;
struct D2Act1Quest3Strc;
struct D2Act1Quest2Strc;
struct D2Act1Quest4Strc;


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
    void* pCallback[15];
    void* pNPCMessages;
    int eFilter;
    char unk0xE4[0x0C];
    QUESTSEQFILTER pfSeqFilter;
};

struct D2Act5Quest4Strc
{
    char unk0x00[0x87];
    unsigned char bNeedsToOpenPortal;
    unsigned char bPortalCreated;
    unsigned char bWaypointNotActivated;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640


void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

enum D2C_F33QuestConstants
{
    ACT_V = 4,
    LEVEL_ROGUEENCAMPMENT = 1,
    LEVEL_TRISTRAM = 38,
    LEVEL_HARROGATH = 109,
    LEVEL_ROCKYSUMMIT = 120,
    LEVEL_NIHLATHAKSTEMPLE = 121,
    LEVEL_HALLSOFDEATHSCALLING = 123,
    QUEST_A1Q2_BLOODRAVEN = 2,
    QUEST_A1Q3_MALUS = 3,
    QUEST_A1Q4_CAIN = 4,
    QUEST_A1Q5_COUNTESS = 5,
    QUEST_A5Q4_NIHLATHAK = 34,
    QUEST_A5Q5_ANCIENTS = 35,
    QUEST_A5Q6_BAAL = 36,
    QUESTSTATEFLAG_A1Q2 = 2,
    QUESTSTATEFLAG_A1Q3 = 3,
    QUESTSTATEFLAG_A1Q4 = 4,
    QUESTSTATEFLAG_A5Q4 = 38,
    QUESTSTATEFLAG_A5Q6 = 40,
    QFLAG_REWARDGRANTED = 0,
    QFLAG_REWARDPENDING = 1,
    QFLAG_STARTED = 2,
    QFLAG_LEAVETOWN = 3,
    QFLAG_PRIMARYGOALDONE = 13,
    QFLAG_CUSTOM6 = 10,
    MONSTER_CHARSI = 154,
    MONSTER_KASHYA = 150,
    MONSTER_AKARA = 148,
    MONSTER_CAIN5 = 265,
    MONSTER_TYRAEL3 = 521,
    OBJECT_PERMANENT_TOWN_PORTAL = 60,
    OBJMODE_NEUTRAL = 0,
    OBJMODE_OPERATING = 1,
    OBJMODE_OPENED = 2,
    OBJMODE_SPECIAL1 = 3,
    MONMODE_NEUTRAL = 1,
    EVENTTYPE_ENDANIM = 1,
    EVENTTYPE_QUESTFN = 7,
    STAT_LEVEL = 12,
    ITEMQUAL_NORMAL = 2,
    MONSTATSFLAGINDEX_ZOO = 22,
};



struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
    D2WaypointDataStrc* pWaypointData[3];
    char unk0x28[0x24];
    int bBusy;
};



struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
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

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* hObject;
    D2UnitStrc* hPlayer;
};

struct D2Act5Quest5Strc
{
    unsigned char bAncientsDefeated;
    unsigned char bQualKehkActivated;
    unsigned char unused0x02[2];
    unsigned char bTimerActive;
    unsigned char unused0x05[7];
    int nActivePortalCount;
    unsigned char unk0x10;
    unsigned char bActivatable;
    unsigned char pad0x12[2];
    int nAncientStatueGUID[3];
    int nAncientMonsterGUID[3];
    unsigned char bAncientMonsterSpawned[3];
    unsigned char pad0x2F;
    int nAncientStatueObjectMode[3];
    unsigned char bAncienStatueRespawned[3];
    unsigned char pad0x3F;
    int nAncientsSpawned;
    int nAncientsAlive;
    char unk0x48[0x10];
    unsigned char bSummitDoorInitialized;
    unsigned char pad0x59[3];
    int nSummitDoorGUID;
    int nSummitDoorObjectMode;
};

struct D2Act5Quest6Strc
{
    char unk0x00[0x9C];
    int nLastPortalObjectMode;
    unsigned char bZooInitialized;
    unsigned char pad0xA1[3];
    int nZooMonsterId;
};

struct D2Act1Quest3Strc
{
    unsigned char unk0x00;
    unsigned char bMalusInitialized;
    unsigned char bCharsiIntroActivated;
    unsigned char bCharsiEndActivated;
    int nMalusGUID;
    char unk0x08[0x90];
    int nMalusObjectMode;
    int nMalusItemsInGame;
};

struct D2Act1Quest2Strc
{
    unsigned char unk0x00[2];
    unsigned char bBloodravenKilled;
    unsigned char bKashyaActivated;
    char unk0x04[4];
    int nBloodravenGUID;
};

struct D2Act1Quest4Strc
{
    char unk0x00[0x40];
    int nCairnStoneAlphaGUID;
    unsigned char bOpenPortalTimerActive;
    unsigned char bPortalToTristramOpened;
    char unk0x46[0x4F];
    unsigned char bCainPortalOutsideTownSpawned;
    char unk0x96[6];
    D2CoordStrc pCainPortalOutsideTownCoords;
    char unk0xA4[0x10];
    char pQuestGUID[0x84];
    char tPlayerGUIDs[0x84];
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
extern "C" const unsigned int gnAct1Quest2NpcIndices[]; // 0x00737180
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004BC500
void __fastcall sub_6FC37B10(D2GameStrc* pGame); // 0x0052E2A0
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
void __fastcall sub_0053D940_SendPacket0x61(D2ClientStrc* pClient, unsigned char nValue); // 0x0053D940
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame); // 0x005438B0
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200
int __fastcall QUESTS_QuickCheckPlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545290
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190
int __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int dwCode); // 0x00558110
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, void* pItemDrop, int a6, int a7); // 0x00559A30
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0
int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo); // 0x00660E00
int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, unsigned short wField); // 0x00660E50
int __fastcall ACT5Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058AEA0
int __fastcall ACT5Q6_UnitIterate_SendZooMonsterIdToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058E180
int __fastcall ACT5Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058BE20
int __fastcall ACT5Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058C210
int __fastcall ACT1Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00590830
int __fastcall ACT1Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005912E0
int __fastcall ACT1Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00594830
int __fastcall ACT1Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00594890

// 0x0058B900
void __fastcall sub_0058B900_RescheduleDrehyaPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q4_NIHLATHAK);
    if (pQuestData && ((D2Act5Quest4Strc*)pQuestData->pQuestDataEx)->bNeedsToOpenPortal)
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_QUESTFN, pGame->dwGameFrame + 12, 0, 0);
    }
}

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nX;
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
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

// 0x0058B990
void __fastcall ACT5Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro)
    {
        pQuestData->fState = 5;
        D2GameStrc* pGame = pQuestArg->pGame;
        D2WaypointDataStrc* pWaypointFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pWaypointData[pGame->nDifficulty];
        unsigned short nWpNo;
        if (WAYPOINTS_GetWaypointNoFromLevelId(LEVEL_HALLSOFDEATHSCALLING, &nWpNo) && !WAYPOINTS_IsActivated(pWaypointFlags, nWpNo))
        {
            pQuestDataEx->bWaypointNotActivated = 1;
        }
    }
    else
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_LEAVETOWN))
            {
                pQuestDataEx->bNeedsToOpenPortal = 1;
                QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);
                QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", 705);
            }
            else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_STARTED))
            {
                pQuestDataEx->bNeedsToOpenPortal = 1;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", 711);
            }
        }
    }
}

// 0x0058BC80
void __fastcall ACT5Q4_AnyaOpenPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)QUESTS_GetQuestData(pGame, QUEST_A5Q4_NIHLATHAK)->pQuestDataEx;
    if (!pQuestDataEx->bWaypointNotActivated)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) != ACT_V)
    {
        return;
    }

    if (D2GAME_CreatePortalObject_6FD13DF0(pGame, 0, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit) + 10, CLIENTS_GetUnitY(pUnit) + 5, LEVEL_NIHLATHAKSTEMPLE, 0, OBJECT_PERMANENT_TOWN_PORTAL, 1))
    {
        pQuestDataEx->bWaypointNotActivated = 0;
    }
}

// 0x0058BD50
bool __fastcall ACT5Q5_Timer_RespawnAncientStatueObjects(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    bool bStatueNotFound = false;
    if (!pQuestDataEx->nActivePortalCount && pQuestDataEx->bActivatable)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (pQuestDataEx->bAncienStatueRespawned[i])
            {
                D2UnitStrc* pAncientStatue = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, pQuestDataEx->nAncientStatueGUID[i]);
                if (pAncientStatue)
                {
                    UNITS_ChangeAnimMode(pAncientStatue, OBJMODE_OPERATING);
                    const int nClassId = pAncientStatue->dwClassId;
                    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
                    const int nFrame = pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8);
                    EVENT_SetEvent(pGame, pAncientStatue, EVENTTYPE_ENDANIM, nFrame, 0, 0);
                    pQuestDataEx->bAncienStatueRespawned[i] = 0;
                    pQuestDataEx->nAncientStatueObjectMode[i] = OBJMODE_OPENED;
                }
                else
                {
                    bStatueNotFound = true;
                }
            }
        }

        if (bStatueNotFound)
        {
            return false;
        }
    }

    pQuestDataEx->bTimerActive = 0;
    return true;
}

// 0x0058BF40
int __stdcall sub_0058BF40_ActivateAncientStatues(D2QuestDataStrc* pQuestData, D2Act5Quest5Strc* pQuestDataEx)
{
    D2UnitStrc* pUnit[3];
    for (int i = 0; i < 3; ++i)
    {
        pUnit[i] = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, pQuestDataEx->nAncientStatueGUID[i]);
        if (!pUnit[i])
        {
            return 0;
        }

        DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pUnit[i]), 0);
    }

    for (int k = 0; k < 3; ++k)
    {
        UNITS_ChangeAnimMode(pUnit[k], OBJMODE_SPECIAL1);
        UNITS_FreeCollisionPath(pUnit[k]);
        EVENT_SetEvent(pQuestData->pGame, pUnit[k], EVENTTYPE_QUESTFN, pQuestData->pGame->dwGameFrame + 20, 0, 0);
        pQuestDataEx->nAncientStatueObjectMode[k] = OBJMODE_SPECIAL1;
    }

    pQuestDataEx->nAncientsSpawned = 0;
    pQuestDataEx->nAncientsAlive = 0;
    return 1;
}

// 0x0058CBA0
void __fastcall ACT5Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    const int nNewLevel = pQuestArg->nNewLevel;
    if (pQuestArg->nOldLevel == LEVEL_HARROGATH)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (!pQuestData->bNotIntro)
        {
            return;
        }

        if (pQuestData->fState == 2)
        {
            D2UnitStrc* pPlayer = pQuestArg->pPlayer;
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) == 1)
            {
                return;
            }

            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q5.cpp", 899);
            if (pQuestData->fLastState != 1)
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q5_UnitIterate_StatusCyclerEx, 1);
            }

            SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT5Q5_UnitIterate_UpdateQuestStateFlags);
        }
    }

    if (nNewLevel == LEVEL_ROCKYSUMMIT)
    {
        unsigned char bUpdate = 0;
        if (pQuestData->fLastState < 2 && pQuestData->fState > 2)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q5_UnitIterate_StatusCyclerEx, 1);
            bUpdate = 1;
        }

        if (pQuestData->fState < 3)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q5.cpp", 919);
            bUpdate = 1;
        }

        if (bUpdate)
        {
            SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT5Q5_UnitIterate_UpdateQuestStateFlags);
        }

        if (!pQuestDataEx->bAncientsDefeated && pQuestDataEx->bSummitDoorInitialized)
        {
            D2UnitStrc* pSummitDoor = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, pQuestDataEx->nSummitDoorGUID);
            if (pSummitDoor && pQuestDataEx->nSummitDoorObjectMode == OBJMODE_NEUTRAL)
            {
                pQuestDataEx->nSummitDoorObjectMode = OBJMODE_OPENED;
                UNITS_ChangeAnimMode(pSummitDoor, OBJMODE_OPERATING);
            }
        }
    }
}

// 0x0058D030
D2UnitStrc* __fastcall sub_0058D030_FindAncientMonsterByClassId(D2GameStrc* pGame, int nClassId)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)QUESTS_GetQuestData(pGame, QUEST_A5Q5_ANCIENTS)->pQuestDataEx;
    for (int i = 0; i < pQuestDataEx->nAncientsSpawned; ++i)
    {
        D2UnitStrc* pAncient = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pQuestDataEx->nAncientMonsterGUID[i]);
        const int nAncientClassId = !pAncient ? -1 : pAncient->dwClassId;
        if (nAncientClassId == nClassId)
        {
            return pAncient;
        }
    }

    return 0;
}

// 0x0058E740
int __fastcall OBJECTS_OperateFunction72_LastPortal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A5Q6_BAAL);
    if (((D2Act5Quest6Strc*)pQuestData->pQuestDataEx)->nLastPortalObjectMode != OBJMODE_OPENED)
    {
        return 0;
    }

    D2UnitStrc* pPlayer = pOp->hPlayer;
    D2GameStrc* pGame = pOp->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_PRIMARYGOALDONE))
    {
        LEVEL_WarpUnit(pOp->pGame, pOp->hPlayer, LEVEL_HARROGATH, 0);
        D2ClientStrc* pClient = UnitGetClient(pOp->hPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 923);
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pOp->hPlayer);
        sub_6FC37B10(pQuestData->pGame);
        if (pClient && !PLAYER_IsBusy(pOp->hPlayer))
        {
            SUNIT_ResetInteractInfo(pOp->hPlayer);
            pPlayerData->bBusy = 1;
            sub_0053D940_SendPacket0x61(pClient, 7);
            QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_CUSTOM6);
        }
    }
    else
    {
        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
    }

    return 0;
}

// 0x0058E830
void __fastcall OBJECTS_InitFunction79_Zoo(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A5Q6_BAAL);
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bZooInitialized)
    {
        return;
    }

    int i = 0;
    const int nRecordCount = sgptDataTables->nMonStatsTxtRecordCount;
    while (!pQuestDataEx->bZooInitialized)
    {
        if (i >= 10)
        {
            break;
        }

        pQuestDataEx->nZooMonsterId = OBJECTS_RollRandomNumber(QUESTS_GetGlobalSeed(pQuestData->pGame), 1, nRecordCount);
        ++i;
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordInline(pQuestDataEx->nZooMonsterId);
        int bZoo = 0;
        if (pMonStatsTxtRecord)
        {
            bZoo = pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_ZOO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_ZOO & 7];
        }

        if (bZoo)
        {
            pQuestDataEx->bZooInitialized = 1;
        }
    }

    if (!pQuestDataEx->bZooInitialized)
    {
        pQuestDataEx->bZooInitialized = 1;
        pQuestDataEx->nZooMonsterId = 0;
    }

    if (pQuestDataEx->bZooInitialized)
    {
        SUNIT_IterateUnitsOfType(pOp->pGame, UNIT_PLAYER, 0, ACT5Q6_UnitIterate_SendZooMonsterIdToClient);
    }
}

// 0x0058E920
void __fastcall ACT5Q6_SpawnTyrael(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit)
{
    D2CoordStrc coord;
    D2ActiveRoomStrc* pFreeRoom = 0;
    UNITS_GetCoords(pUnit, &coord);
    coord.nX -= 5;
    coord.nY -= 5;
    QUESTS_GetFreePosition(pRoom, &coord, 5, 0x400, &pFreeRoom, 19, 100);
    if (pFreeRoom)
    {
        D2GAME_SpawnMonster_6FC69F10(pGame, pFreeRoom, coord.nX, coord.nY, MONSTER_TYRAEL3, MONMODE_NEUTRAL, 4, 66);
    }
}

// 0x00590980
void __fastcall ACT1Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (nNPCNo != MONSTER_KASHYA)
    {
        return;
    }

    if (nMessageIndex == 81)
    {
        ((D2Act1Quest2Strc*)pQuestData->pQuestDataEx)->bKashyaActivated = 1;
        QUESTS_StateDebug(pQuestData, 2, gszA1Q2SourceFile, 192);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT1Q2_UnitIterate_UpdateQuestStateFlags);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
    else if (nMessageIndex == 92)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING))
        {
            return;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_PRIMARYGOALDONE) && pQuestData->fState != 5)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 13, 0, ACT1Q2_UnitIterate_StatusCyclerEx, 0);
            QUESTS_StateDebug(pQuestData, 5, gszA1Q2SourceFile, 205);
            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 206);
            pQuestData->pfSeqFilter(pQuestData);
        }

        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED);
        QUESTRECORD_ClearQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING);
        QUESTS_UpdatePlayerFlags(pQuestData->pGame, pQuestArg->pPlayer);
        QUESTS_AddPlayerGUID((D2QuestGUIDStrc*)pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        D2GAME_NPC_AssignMercenary_6FCCB520(pQuestData->pGame, pQuestArg->pPlayer, MONSTER_KASHYA);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
}

// 0x00590B10
void __fastcall ACT1Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED);
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        return;
    }

    if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        return;
    }

    if (!pQuestData->fState)
    {
        return;
    }

    if (bRewardGranted == 1)
    {
        return;
    }

    if (pQuestData->fState >= 4)
    {
        return;
    }

    const unsigned int nIndex = gnAct1Quest2NpcIndices[pQuestData->fState];
    if (nIndex != -1 && nIndex < 6)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

// 0x00590C40
int __fastcall ACT1Q2_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(pUnit);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q2_BLOODRAVEN);
    D2_ASSERT(pQuestData, 307);

    D2Act1Quest2Strc* pQuestDataEx = (D2Act1Quest2Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bBloodravenKilled)
    {
        return 0;
    }

    D2ActiveRoomStrc* pMonsterRoom = UNITS_GetRoom(SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pQuestDataEx->nBloodravenGUID));
    if (!pPlayerRoom)
    {
        return 0;
    }

    int bInRange = 0;
    if (pPlayerRoom == pMonsterRoom)
    {
        bInRange = 1;
    }
    else
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        D2_ASSERT(pRoom, 334);

        D2ActiveRoomStrc** ppRoomList;
        unsigned int nRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nRooms);
        for (unsigned int i = 0; i < nRooms; ++i)
        {
            if (ppRoomList[i] == pMonsterRoom)
            {
                bInRange = 1;
                break;
            }
        }
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDGRANTED))
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDPENDING))
    {
        return 0;
    }

    if (!bInRange)
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDPENDING);
    return 0;
}

// 0x00591AC0
int __fastcall OBJECTS_OperateFunction21_HoradrimMalus(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A1Q3_MALUS);
    if (!pQuestData)
    {
        return 0;
    }

    const int nAnimMode = !pOp->hObject ? 0 : pOp->hObject->dwAnimMode;
    if (!pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPENED);
        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        return 0;
    }

    if (!nAnimMode)
    {
        D2UnitStrc* pPlayer = pOp->hPlayer;
        D2GameStrc* pGame = pOp->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDGRANTED) == 1)
        {
            return 0;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDPENDING) == 1)
        {
            return 0;
        }

        if (STATLIST_GetUnitBaseStat(pOp->hPlayer, STAT_LEVEL, 0) < 8)
        {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
            return 0;
        }

        int nItemLevel;
        pOp->hObject->dwDropItemCode = ' mdh';
        if (D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0))
        {
            UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPENED);
            D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
            pQuestDataEx->bMalusInitialized = 1;
            pQuestDataEx->nMalusObjectMode = OBJMODE_OPENED;
            pQuestDataEx->nMalusGUID = !pOp->hObject ? -1 : pOp->hObject->dwUnitId;
            ++pQuestDataEx->nMalusItemsInGame;
            if (pQuestData->fState != 4)
            {
                QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", 706);
                SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT1Q3_UnitIterate_UpdateQuestStateFlags);
            }

            if (pQuestData->fLastState != 1)
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q3_UnitIterate_StatusCyclerEx, 0);
            }
        }
    }

    return 0;
}

// 0x00591C30
bool __fastcall ACT1Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_CHARSI && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDGRANTED) != 1)
    {
        if (pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDPENDING))
        {
            return true;
        }

        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0) >= 8 && ITEMS_FindQuestItem(SUNIT_GetGameFromUnit(pPlayer), pPlayer, ' mdh'))
        {
            return true;
        }
    }

    return false;
}

// 0x00592D50
bool __fastcall ACT1Q4_OpenPortalToTristram(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    D2UnitStrc* pCairnStone = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, pQuestDataEx->nCairnStoneAlphaGUID);
    if (pCairnStone)
    {
        if (D2GAME_CreatePortalObject_6FD13DF0(pGame, 0, UNITS_GetRoom(pCairnStone), CLIENTS_GetUnitX(pCairnStone) + 4, CLIENTS_GetUnitY(pCairnStone) + 4, LEVEL_TRISTRAM, 0, OBJECT_PERMANENT_TOWN_PORTAL, 1))
        {
            pQuestDataEx->bPortalToTristramOpened = 1;
            pQuestDataEx->bOpenPortalTimerActive = 0;
            return true;
        }

        return false;
    }

    pQuestDataEx->bOpenPortalTimerActive = 0;
    return true;
}

// 0x00592FB0
bool __fastcall ACT1Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_PRIMARYGOALDONE);
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDGRANTED);
    const int bRewardPending = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDPENDING);
    if (nNpcId == MONSTER_AKARA)
    {
        if (pQuest->fState == 4 && !bRewardGranted && !bRewardPending)
        {
            if (ITEMS_FindQuestItem(SUNIT_GetGameFromUnit(pPlayer), pPlayer, ' skb'))
            {
                return true;
            }
        }

        if (pQuest->fState == 1 && !bRewardGranted && !bRewardPending)
        {
            return true;
        }

        if (pQuest->fState == 6 && bPrimaryGoalDone == 1 && !bRewardGranted)
        {
            return true;
        }

        if (bRewardPending)
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_CAIN5)
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuest->pQuestDataEx;
        if (QUESTS_QuickCheckPlayerGUID((D2QuestGUIDStrc*)pQuestDataEx->pQuestGUID, !pPlayer ? -1 : pPlayer->dwUnitId) == 1)
        {
            return true;
        }

        if (!QUESTS_QuickCheckPlayerGUID((D2QuestGUIDStrc*)pQuestDataEx->tPlayerGUIDs, !pPlayer ? -1 : pPlayer->dwUnitId) && bPrimaryGoalDone)
        {
            return true;
        }
    }

    return false;
}

// 0x00594450
int __fastcall ACT1Q4_GetCainPortalOutsideTownCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bCainPortalOutsideTownSpawned)
    {
        UNITS_GetCoords(pUnit, pCoord);
    }
    else
    {
        pCoord->nX = pQuestDataEx->pCainPortalOutsideTownCoords.nX;
        pCoord->nY = pQuestDataEx->pCainPortalOutsideTownCoords.nY;
    }

    return 1;
}

// 0x00595160
void __fastcall sub_00595160_UpdateCountessQuestState(D2GameStrc* pGame, D2UnitStrc* pUnit, int bPending)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q5_COUNTESS);
    if (!pQuestData)
    {
        return;
    }

    if (!pQuestData->bNotIntro)
    {
        return;
    }

    if (pQuestData->fState >= 4)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) == 1)
    {
        return;
    }

    if (bPending)
    {
        if (pQuestData->fState == 2 || pQuestData->fState == 3)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING);
        }
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING) != 1)
    {
        return;
    }

    if (pQuestData->fState == 3)
    {
        return;
    }

    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 705);
    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q5_UnitIterate_StatusCyclerEx, true);
    SUNIT_IterateUnitsOfType(pGame, UNIT_PLAYER, 0, ACT1Q5_UnitIterate_UpdateQuestStateFlags);
}

#include "gen/data/Source/D2Game/Quests/a5q4_0058B900.inc"
