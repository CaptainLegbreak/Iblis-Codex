struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2TextHeaderStrc;
struct D2NPCMessageTableStrc;
struct D2DynamicPathStrc;

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
    char pad0x08[0x04];
    int dwUnitId;
    int dwAnimMode;
    char pad0x14[0x18];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2GameStrc
{
    char pad0x00[0x1C];
    void* pMemoryPool;
    char pad0x20[0x4D];
    unsigned char nDifficulty;
    char pad0x6E[0x3A];
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

struct D2QuestDataStrc;
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
    union
    {
        unsigned int dwFlags;
        unsigned char nFlagsByte;
    };
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
    char pad0x00[0x67];
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
    char pad0x00[0x8C];
    D2QuestGUIDStrc tPlayerGUIDs;
    char pad0x110[0x0B];
    unsigned char bTowerTomeActivated;
};

#define QUEST_A1Q4_CAIN 4
#define QUEST_A1Q5_COUNTESS 5
#define QUESTSTATEFLAG_A1Q5 5
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QSTATE_2 2
#define OBJMODE_NEUTRAL 0
#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2
#define OBJMODE_SPECIAL1 3
#define OBJMODE_SPECIAL2 4
#define UNIT_OBJECT 2
#define OBJECT_CAINPORTAL 189
#define PORTAL_RETRY_STEP 3
#define LEVEL_ROGUEENCAMPMENT 1
#define LEVEL_TOWERCELLARLEV5 25
#define EVENTTYPE_ENDANIM 1
#define EVENTTYPE_QUESTFN 7
#define QUESTFN_DELAY 25
#define PORTAL_INVOCATIONS_MAX 5
#define MSG_TOWER_TOME 127
#define LINE_TOME_STATE2 514

D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                               // 0x00543640
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId);              // 0x005436B0
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId);               // 0x00544190
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID);                             // 0x00545200
int __fastcall QUESTS_QuickCheckPlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                           // 0x00545290
void __fastcall QUESTS_SendScrollMessage(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nMessage);  // 0x005456A0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

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
