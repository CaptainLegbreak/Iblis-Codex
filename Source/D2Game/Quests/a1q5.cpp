#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"

#define QUEST_A1Q4_CAIN 4
#define QUEST_A1Q5_COUNTESS 5
#define QUESTSTATEFLAG_A1Q5 5
#define QFLAG_REWARDPENDING 1
#define QFLAG_COMPLETEDNOW 14
#define OBJMODE_NEUTRAL 0
#define OBJMODE_SPECIAL1 3
#define OBJECT_CAINPORTAL 189
#define PORTAL_RETRY_STEP 3
#define LEVEL_TOWERCELLARLEV5 25
#define EVENTTYPE_QUESTFN 7
#define QUESTFN_DELAY 25
#define PORTAL_INVOCATIONS_MAX 5
#define MSG_TOWER_TOME 127
#define LINE_TOME_STATE2 514
struct D2NPCMessageTableStrc;
struct D2StaticPathStrc;
struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2ObjInitFnStrc;
struct D2ObjOperateFnStrc;
struct D2Act1Quest4Strc;
struct D2Act1Quest5Strc;
struct D2Act2Quest6Strc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};


struct D2GameStrc
{
    char pad0x00[0x1C];
    void* pMemoryPool;
    char pad0x20[0x4D];
    unsigned char nDifficulty;
    char pad0x6E[0x02];
    int bExpansion;
    char pad0x74[0x34];
    int dwGameFrame;
};

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

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

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
    D2NPCMessageTableStrc* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    int unk0x0C;
    int nObjectIdx;
};

struct D2ObjectsTxt
{
    char pad0x00[0xD8];
    unsigned int dwFrameCnt[8];
};

struct D2Act1Quest4Strc
{
    char unk0x00[0x34];
    int nCainGibbetGUID;
    char unk0x38[0x10];
    unsigned char bCageModeChanged;
    char unk0x49[0x0B];
    int nCainGibbetObjectMode;
    unsigned char unk_58[0xF];
    unsigned char bCainPortalCoordsInitialized;
    char pad0x68[0x18];
    int nObjectUpdateInvocations;
    char pad0x84[0x0D];
    unsigned char bChangePortalOutsideTownToSpecialMode;
    unsigned char bChangePortalInTownToSpecialMode;
    char pad0x93[0x02];
    unsigned char bCainPortalOutsideTownSpawned;
    char pad0x96[0x02];
    int nCainPortalOutsideTownGUID;
    D2CoordStrc pCainPortalOutsideTownCoords;
};

struct D2Act1Quest5Strc
{
    int nUnitGUIDs1[12];
    unsigned short nUnitCount1;
    unsigned char pad0x32[2];
    int nUnitGUIDs2[12];
    unsigned short nUnitCount2;
    unsigned char pad0x66[2];
    int nObjectGUIDs[8];
    unsigned short nCountessChestCount;
    unsigned char pad0x8A[2];
    D2QuestGUIDStrc tPlayerGUIDs;
    D2CoordStrc pCoord;
    unsigned char bCountessKilled;
    unsigned char bDeathMissilesCreated;
    unsigned char bTriggerSeqFilter;
    unsigned char bTowerTomeActivated;
    unsigned char unk0x11C;
    unsigned char pad0x11D[3];
};

D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId); // 0x005436B0
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId); // 0x00544190
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200
int __fastcall QUESTS_QuickCheckPlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545290
void __fastcall QUESTS_SendScrollMessage(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nMessage); // 0x005456A0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
void __fastcall ACT1Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00594BB0
int __fastcall ACT1Q5_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00594F10

enum D2C_Q05QuestConstants
{
    LEVEL_ROGUEENCAMPMENT = 1,
    LEVEL_MOOMOOFARM = 39,
    OBJECT_PERMANENT_TOWN_PORTAL = 60,
    QUESTSTATEFLAG_A1Q4 = 4,
    QUESTSTATEFLAG_A4Q2 = 26,
    QUESTSTATEFLAG_A5Q6 = 40,
    OBJECT_PORTAL_TO_DURIELS_LAIR = 100,
    OBJMODE_OPERATING = 1,
    OBJMODE_OPENED = 2,
    EVENTTYPE_ENDANIM = 1,
    QFLAG_REWARDGRANTED = 0,
    QFLAG_PRIMARYGOALDONE = 13,
    QFLAG_CUSTOM6 = 10,
    QFLAG_CUSTOM7 = 11,
};

struct D2Act2Quest6Strc
{
    unsigned char unk0x00;
    unsigned char bDurielKilled;
    unsigned char unk0x02;
    unsigned char bTimerActive;
    unsigned char bHoradricOrificeInitialized;
    unsigned char bTyraelsDoorInitialized;
    unsigned char bUnusedObjectInitialized;
    unsigned char unused0x07;
    unsigned char bInitJerhynActivated;
    unsigned char bTyraelActivated;
    unsigned char bEndJerhynActivated;
    unsigned char bDurielLairTombOpen;
    unsigned char bDurielLairPortalNeedsToOpen;
    unsigned char bObjectsNeedUpdate;
    unsigned char unk0x0E[0x12];
    int nHoradricOrificeGUID;
    unsigned char unused0x24[4];
    int nUnusedObjectGUID;
};

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544760
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned int fCollision, D2ActiveRoomStrc** ppRoom, int nRadius, int a7); // 0x00545340
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nSoundId, D2UnitStrc* pOrigin); // 0x00553380
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

static __forceinline int UNITS_GetGUIDOrNone(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

static __forceinline int UNITS_GetAnimModeOrZero(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->dwAnimMode;
}

// 0x00594020
void __fastcall OBJECTS_InitFunction13_InvisibleObject(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A1Q4_CAIN);
    if (pQuestData)
    {
        QUESTS_CreateChainRecord(pQuestData->pGame, pOp->pObject, QUEST_A1Q4_CAIN);
    }
    else
    {
        if (!pOp->pObject || pOp->pObject->dwAnimMode != OBJMODE_OPENED)
        {
            UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
        }
    }
}

// 0x00594290
void __fastcall OBJECTS_InitFunction61_CainPortal(D2ObjInitFnStrc* pOp)
{
    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_QUESTFN, pOp->pGame->dwGameFrame + QUESTFN_DELAY, 0, 0);
}

// 0x005942C0
void __fastcall ACT1Q4_UpdatePortalInTown(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    switch (UNITS_GetAnimModeOrZero(pUnit))
    {
    case OBJMODE_OPERATING:
        UNITS_ChangeAnimMode(pUnit, OBJMODE_OPENED);
        break;

    case OBJMODE_OPENED:
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == LEVEL_ROGUEENCAMPMENT)
        {
            ++pQuestDataEx->nObjectUpdateInvocations;
            if (pQuestDataEx->nObjectUpdateInvocations > PORTAL_INVOCATIONS_MAX)
            {
                pQuestDataEx->bChangePortalInTownToSpecialMode = 1;
            }

            if (pQuestDataEx->bChangePortalInTownToSpecialMode)
            {
                UNITS_ChangeAnimMode(pUnit, OBJMODE_SPECIAL1);
            }
        }
        else
        {
            if (pQuestDataEx->bChangePortalOutsideTownToSpecialMode)
            {
                UNITS_ChangeAnimMode(pUnit, OBJMODE_SPECIAL1);
            }
        }
        break;
    }

    case OBJMODE_SPECIAL1:
        UNITS_ChangeAnimMode(pUnit, OBJMODE_SPECIAL2);
        break;
    }

    EVENT_SetEvent(pQuestData->pGame, pUnit, EVENTTYPE_QUESTFN, pQuestData->pGame->dwGameFrame + QUESTFN_DELAY, 0, 0);
}

// 0x005943B0
int __fastcall ACT1Q4_SpawnCainPortalOutsideTown(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN);
    if (!pQuestData)
    {
        return 1;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bCainPortalOutsideTownSpawned)
    {
        return 1;
    }

    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), pQuestDataEx->pCainPortalOutsideTownCoords.nX, pQuestDataEx->pCainPortalOutsideTownCoords.nY);
    if (!pRoom)
    {
        pQuestDataEx->pCainPortalOutsideTownCoords.nX += PORTAL_RETRY_STEP;
        pQuestDataEx->pCainPortalOutsideTownCoords.nY += PORTAL_RETRY_STEP;
        return 1;
    }

    D2UnitStrc* pCainPortal = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_CAINPORTAL, pQuestDataEx->pCainPortalOutsideTownCoords.nX, pQuestDataEx->pCainPortalOutsideTownCoords.nY, pGame, pRoom, 1, 1, 0);
    if (pCainPortal)
    {
        pQuestDataEx->bCainPortalOutsideTownSpawned = 1;
        pQuestDataEx->nCainPortalOutsideTownGUID = pCainPortal->dwUnitId;
    }

    return 1;
}

// 0x005944B0
int __fastcall ACT1Q4_UpdateCainPortalCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bCainPortalCoordsInitialized)
    {
        return 0;
    }

    UNITS_GetCoords(pUnit, &pQuestDataEx->pCainPortalOutsideTownCoords);
    pQuestDataEx->bCainPortalCoordsInitialized = 1;
    return 1;
}

// 0x00594830
int __fastcall ACT1Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_REWARDGRANTED)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A1Q5_COUNTESS);
    }

    return 0;
}

// 0x00594DD0
int __fastcall ACT1Q5_UnitIterate_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_REWARDPENDING))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_TOWERCELLARLEV5)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q5_COUNTESS);
    if (!pQuestData)
    {
        return 0;
    }

    const int nUnitId = UNITS_GetGUIDOrNone(pUnit);

    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;
    if (!QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->tPlayerGUIDs, nUnitId))
    {
        QUESTS_AddPlayerGUID(&pQuestDataEx->tPlayerGUIDs, nUnitId);
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_REWARDGRANTED);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_PRIMARYGOALDONE);
    return 0;
}

// 0x00594E70
int __fastcall OBJECTS_OperateFunction06_TowerTome(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->pObject || pOp->pObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, pOp->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A1Q5_COUNTESS);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return 0;
    }

    QUESTS_SendScrollMessage(pOp->pPlayer, pOp->pObject, MSG_TOWER_TOME);

    if (pQuestData->fState > 1)
    {
        return 0;
    }

    QUESTS_StateDebug(pQuestData, QSTATE_2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", LINE_TOME_STATE2);
    if (pQuestData->fLastState < 1)
    {
        ((D2Act1Quest5Strc*)pQuestData->pQuestDataEx)->bTowerTomeActivated = 1;
    }

    return 0;
}

// 0x00594060
void __fastcall sub_00594060_InitCainGibbet(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    if (pQuestData)
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nCainGibbetObjectMode);
        pQuestDataEx->bCageModeChanged = 1;
        pQuestDataEx->nCainGibbetGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    }
}

// 0x00594DB0
void __fastcall sub_00594DB0_InitTowerTome(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    if (!pQuestData->bNotIntro)
        UNITS_ChangeAnimMode(pOp->pObject, 3);
}

// 0x00594FD0
static __forceinline void sub_00594FD0_FinishCountessQuest(D2QuestDataStrc* pQuestData)
{
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q5_UnitIterate_AttachCompletionSound);
    QUESTS_SetGlobalState(pQuestData->pGame, 5, 13);
    if (!((D2Act1Quest5Strc*)pQuestData->pQuestDataEx)->nUnitCount2)
        pQuestData->bActive = 0;
    else
        pQuestData->pfCallback[10] = ACT1Q5_Callback10_PlayerLeavesGame;
}

void __fastcall sub_M129_Emit_00594FD0(D2QuestDataStrc* pQuestData)
{
    sub_00594FD0_FinishCountessQuest(pQuestData);
}

__forceinline D2BitBufferStrc* QUESTS_GetPlayerQuestFlags_Inline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00594140
int __fastcall ACT1Q4_CreateCowPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom;
    if (QUESTS_GetGlobalState(pGame, QUESTSTATEFLAG_A1Q4, QFLAG_CUSTOM7)
        || QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pGame, pUnit), QUESTSTATEFLAG_A1Q4, QFLAG_CUSTOM6))
    {
        goto fail;
    }

    if (!((!pGame->bExpansion && QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pGame, pUnit), QUESTSTATEFLAG_A4Q2, QFLAG_REWARDGRANTED))
        || (pGame->bExpansion && QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pGame, pUnit), QUESTSTATEFLAG_A5Q6, QFLAG_REWARDGRANTED))))
    {
        goto fail;
    }

    pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_ROGUEENCAMPMENT)
    {
fail:
        SUNIT_AttachSound(pUnit, 20, pUnit);
        return 0;
    }

    D2CoordStrc pCoord;
    D2ActiveRoomStrc* pFreeRoom = 0;
    UNITS_GetCoords(pUnit, &pCoord);
    QUESTS_GetFreePosition(pRoom, &pCoord, 3, 0x400, &pFreeRoom, 4, 100);
    if (pFreeRoom && D2GAME_CreatePortalObject_6FD13DF0(pGame, pUnit, pFreeRoom, pCoord.nX, pCoord.nY, LEVEL_MOOMOOFARM, 0, OBJECT_PERMANENT_TOWN_PORTAL, 0))
    {
        QUESTS_SetGlobalState(pGame, QUESTSTATEFLAG_A1Q4, QFLAG_CUSTOM7);
        return 1;
    }

    SUNIT_AttachSound(pUnit, 20, pUnit);
    return 0;
}

// 0x00595420
void __fastcall sub_00595420_UpdatePlayerListQuestState(D2GameStrc* pGame, D2QuestGUIDStrc* pQuestGUID, int nQuestId, int nSoundId)
{
    for (int i = 0; i < pQuestGUID->nPlayerCount; ++i)
    {
        D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pQuestGUID->nPlayerGUIDs[i]);
        if (pPlayer)
        {
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, nQuestId, QFLAG_REWARDGRANTED) != 1)
            {
                QUESTRECORD_SetQuestState(pQuestFlags, nQuestId, QFLAG_PRIMARYGOALDONE);
                QUESTRECORD_SetQuestState(pQuestFlags, nQuestId, QFLAG_REWARDGRANTED);
                if (nSoundId)
                {
                    SUNIT_AttachSound(pPlayer, nSoundId, pPlayer);
                }
            }
        }
    }
}

// 0x0059D870
bool __fastcall ACT2Q6_Timer_UpdateObjects(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    int nObjects = 0;
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bObjectsNeedUpdate == 1)
    {
        if (pQuestDataEx->bUnusedObjectInitialized)
        {
            D2UnitStrc* pUnusedObject = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, pQuestDataEx->nUnusedObjectGUID);
            if (pUnusedObject)
            {
                nObjects = 1;
                if (!pUnusedObject->dwAnimMode)
                {
                    if (pQuestDataEx->bDurielLairPortalNeedsToOpen)
                    {
                        UNITS_ChangeAnimMode(pUnusedObject, OBJMODE_OPENED);
                    }
                    else
                    {
                        UNITS_ChangeAnimMode(pUnusedObject, OBJMODE_OPERATING);
                        const int nClassId = pUnusedObject->dwClassId;
                        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
                        EVENT_SetEvent(pQuestData->pGame, pUnusedObject, EVENTTYPE_ENDANIM, pQuestData->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
                    }
                }
            }
        }

        if (pQuestDataEx->bHoradricOrificeInitialized)
        {
            D2UnitStrc* pHoradricOrifice = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, pQuestDataEx->nHoradricOrificeGUID);
            if (pHoradricOrifice)
            {
                const int nX = UNITS_GetXPosition(pHoradricOrifice) - 13;
                const int nY = CLIENTS_GetUnitY(pHoradricOrifice) + 3;

                D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pHoradricOrifice), nX, nY);
                if (pRoom)
                {
                    D2UnitStrc* pDurielLairPortal = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_PORTAL_TO_DURIELS_LAIR, nX, nY, pGame, pRoom, 1, 1, 0);
                    if (pDurielLairPortal)
                    {
                        ++nObjects;
                        if (pQuestDataEx->bDurielLairPortalNeedsToOpen)
                        {
                            UNITS_ChangeAnimMode(pDurielLairPortal, OBJMODE_OPENED);
                        }
                        else
                        {
                            UNITS_ChangeAnimMode(pDurielLairPortal, OBJMODE_OPERATING);
                            DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pHoradricOrifice), 1);
                            DUNGEON_ToggleHasPortalFlag(pRoom, 1);
                        }
                    }
                }
            }
        }

        if (!nObjects)
        {
            return false;
        }

        pQuestDataEx->bDurielLairTombOpen = 1;
        pQuestDataEx->bObjectsNeedUpdate = 0;
    }

    pQuestDataEx->bTimerActive = 0;
    return true;
}

// 0x00594700
static void __stdcall sub_00594700_ACT1Q5_AddUnitGUID(D2Act1Quest5Strc* pQuestDataEx, int nUnitId, int bSecondList)
{
    if (bSecondList)
    {
        if (pQuestDataEx->nUnitCount2 < 12)
        {
            pQuestDataEx->nUnitGUIDs2[pQuestDataEx->nUnitCount2] = nUnitId;
            pQuestDataEx->nUnitCount2 += 1;
        }
    }
    else
    {
        if (pQuestDataEx->nUnitCount1 < 12)
        {
            pQuestDataEx->nUnitGUIDs1[pQuestDataEx->nUnitCount1] = nUnitId;
            pQuestDataEx->nUnitCount1 += 1;
        }
    }
}

__forceinline D2BitBufferStrc* ACT1Q5_GetPlayerQuestFlags_Inline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00594F10
int __fastcall ACT1Q5_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = ACT1Q5_GetPlayerQuestFlags_Inline(pGame, pUnit);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 0) == 1)
        return 0;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;

    if (DUNGEON_GetLevelIdFromRoom(pRoom) == 0x19)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 5, 0xD);
        QUESTRECORD_SetQuestState(pQuestFlags, 5, 0);
        QUESTRECORD_ClearQuestState(pQuestFlags, 5, 1);
        SUNIT_AttachSound(pUnit, 0x25, pUnit);

        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 5);
        if (!pQuestData)
            return 0;

        D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;
        const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
        sub_00594700_ACT1Q5_AddUnitGUID(pQuestDataEx, nUnitId, 1);
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 5, 0xE);
    return 0;
}

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005954F0
void __stdcall ACT1Q5_SpawnTowerChestMissiles(D2QuestDataStrc* pQuestData, D2Act1Quest5Strc* pQuestDataEx)
{
    if (!pQuestDataEx->bCountessKilled || pQuestDataEx->bDeathMissilesCreated)
    {
        return;
    }

    D2UnitStrc* pTrapFirebolt = 0;

    for (int i = 0; i < pQuestDataEx->nCountessChestCount; ++i)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nObjectGUIDs[i]);
        if (pObject)
        {
            D2CoordStrc pCoord;
            pCoord.nX = pQuestDataEx->pCoord.nX;
            pCoord.nY = pQuestDataEx->pCoord.nY;

            if (!pTrapFirebolt)
            {
                D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pObject), pCoord.nX, pCoord.nY);

                if (pRoom)
                {
                    pTrapFirebolt = D2GAME_SpawnMonster_6FC69F10(pQuestData->pGame, pRoom, pCoord.nX, pCoord.nY, 0x146, 0xC, -1, 8);
                }

                if (!pTrapFirebolt)
                {
                    UNITS_GetCoords(pObject, &pCoord);

                    pCoord.nX += 5;
                    pCoord.nY += 5;

                    pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pObject), pCoord.nX, pCoord.nY);
                    pTrapFirebolt = D2GAME_SpawnMonster_6FC69F10(pQuestData->pGame, pRoom, pCoord.nX, pCoord.nY, 0x146, 0xC, -1, 8);
                }
            }

            if (pTrapFirebolt)
            {
                pQuestDataEx->bDeathMissilesCreated = 1;

                D2UnitStrc* pMissile = D2GAME_CreateMissile_6FD115E0(pQuestData->pGame, pTrapFirebolt, 0, 1, 0x14C, CLIENTS_GetUnitXInline(pObject), CLIENTS_GetUnitYInline(pObject));
                if (pMissile)
                {
                    MISSILE_SetTargetX(pMissile, pQuestDataEx->nObjectGUIDs[i]);
                    MISSILE_SetTargetY(pMissile, 0);
                    D2ActiveRoomStrc* pMissileRoom = UNITS_GetRoom(pMissile);
                    DUNGEON_ToggleHasPortalFlag(pMissileRoom, 0);
                }
            }
        }
    }
}
