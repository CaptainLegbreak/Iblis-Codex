struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2TextHeaderStrc;
struct D2DrlgActStrc;
struct D2ItemDropStrc;

enum D2C_P08QuestConstants
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    ACT_II = 1,
    LEVEL_LUTGHOLEIN = 40,
    LEVEL_CANYONOFTHEMAGI = 46,
    LEVEL_DURIELSLAIR = 73,
    LEVEL_KURASTDOCKTOWN = 75,
    MONSTER_AKARA = 148,
    MONSTER_KASHYA = 150,
    MONSTER_WARRIV1 = 155,
    MONSTER_CAIN6 = 244,
    MONSTER_CAIN5 = 265,
    OBJECT_CAINPORTAL = 189,
    QUEST_A1Q4_CAIN = 4,
    QUEST_A1Q5_COUNTESS = 5,
    QUESTSTATEFLAG_A1Q4 = 4,
    QUESTSTATEFLAG_A1Q5 = 5,
    QUESTSTATEFLAG_A1Q6 = 6,
    QUESTSTATEFLAG_A2Q2 = 10,
    QUESTSTATEFLAG_A2Q3 = 11,
    QUESTSTATEFLAG_A2Q4 = 12,
    QUESTSTATEFLAG_A4Q2 = 26,
    QUESTSTATEFLAG_A5Q6 = 40,
    QFLAG_REWARDGRANTED = 0,
    QFLAG_REWARDPENDING = 1,
    QFLAG_STARTED = 2,
    QFLAG_LEAVETOWN = 3,
    QFLAG_ENTERAREA = 4,
    QFLAG_CUSTOM1 = 5,
    QFLAG_CUSTOM2 = 6,
    QFLAG_CUSTOM6 = 10,
    QFLAG_PRIMARYGOALDONE = 13,
    EVENTTYPE_QUESTFN = 7,
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x04];
    int dwUnitId;
    char pad0x10[0xA8];
    unsigned int dwDropItemCode;
};

struct D2GameStrc
{
    char pad0x00[0x6D];
    unsigned char nDifficulty;
    char pad0x6E[0x02];
    int bExpansion;
    char pad0x74[0x34];
    int dwGameFrame;
    char pad0xAC[0x10];
    D2DrlgActStrc* pAct[5];
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
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    void* pObjectregion;
    void* pObjectTxt;
    int nX;
    int nY;
};

struct D2Act1Quest4Strc
{
    char pad0x00[0x51];
    unsigned char bCainInTownSpawned;
    unsigned char unk0x52;
    char pad0x53[0x15];
    int nCainMonsterInTownGUID;
    int nCainObjectGUID;
    unsigned char bCainObjectInitialized;
    char pad0x71[0x20];
    unsigned char bChangePortalOutsideTownToSpecialMode;
    char pad0x92[0x04];
    unsigned char bCainPortalInTownSpawned;
    char pad0x97[0x0D];
    int nCainPortalInTownGUID;
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
};

struct D2Act1Quest6Strc
{
    D2QuestGUIDStrc pGUID1;
    D2QuestGUIDStrc pGUID2;
    D2QuestGUIDStrc pGUID3;
    int nAndarielGUID;
    short unk0x190;
    short nTimerInvocations;
    unsigned char bAndarielKilled;
    unsigned char bCainActivated;
};

struct D2Act2Quest4Strc
{
    char pad0x00[0x0E];
    unsigned char bPalaceOpen;
    char pad0x0F[0x2D];
    int nJerhynGUID;
    unsigned short nHaremBlockerObjectMode;
};

struct D2Act2Quest6Strc
{
    unsigned char unk0x00;
    unsigned char bDurielKilled;
    char pad0x02[0x32];
    int nStaffTombLevelId;
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);         // 0x0065C3A0
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*)); // 0x005537D0
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
void __fastcall sub_00545990(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, int nValue); // 0x00545990
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
void __stdcall ACT1Q5_SpawnTowerChestMissiles(D2QuestDataStrc* pQuestData, D2Act1Quest5Strc* pQuestDataEx);  // 0x005954F0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);   // 0x00544350
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget);    // 0x00545780
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                            // 0x00545240
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID);                              // 0x00545200
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit);                             // 0x005455B0
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate); // 0x00544300
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
int __fastcall QUESTS_QuickCheckPlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                            // 0x00545290
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID);                                 // 0x005452C0
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode);                      // 0x00544160
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);           // 0x00545310
int __stdcall DUNGEON_GetHoradricStaffTombLevelId(D2DrlgActStrc* pAct);                                     // 0x0061AEB0
void __fastcall sub_0059C6C0_ACT2Q6_UpdateRewardFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnused); // 0x0059C6C0

int __fastcall ACT1Q4_UnitIterate_SetCustom6Flag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x00593E30
void __fastcall OBJECTS_InitFunction54_CainStartPosition(D2ObjInitFnStrc* pOp);                             // 0x005940E0
int __fastcall ACT1Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x00595B20
int __fastcall ACT1Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00595BD0
int __fastcall ACT2Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x0059C650

static unsigned int nIndices_007382AC[] =                                                                   // 0x007382AC
{
    0xFFFFFFFF, 0xFFFFFFFF, 0, 1, 2, 3
};

static unsigned int nIndices_007382C4[] =                                                                   // 0x007382C4
{
    0xFFFFFFFF, 0, 1, 2, 3, 4, 0
};

static int nIndices_007398FC[] =                                                                            // 0x007398FC
{
    -1, 0, 1, 2, 3, 4, 0
};

__forceinline D2BitBufferStrc* QUESTS_GetPlayerQuestFlags_Inline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

__forceinline int ACT1Q5_ContainsGUID_Inline(const int* pGUIDs, int nCount, int nUnitId)
{
    for (int i = 0; i < nCount; ++i)
    {
        if (pGUIDs[i] == nUnitId)
        {
            return 1;
        }
    }

    return 0;
}

// 0x00593E70
void __fastcall ACT1Q4_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nItemLevel;
    if (pQuestArg->pPlayer)
    {
        if (QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pQuestArg->pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A1Q4, QFLAG_CUSTOM6))
        {
            return;
        }

        D2GameStrc* pGame = pQuestArg->pGame;
        if (pGame->bExpansion)
        {
            if (!QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A5Q6, QFLAG_REWARDGRANTED))
            {
                return;
            }
        }
        else
        {
            if (!QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A4Q2, QFLAG_REWARDGRANTED))
            {
                return;
            }
        }

        QUESTRECORD_SetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pQuestArg->pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A1Q4, QFLAG_CUSTOM6);
    }

    SUNIT_IterateUnitsOfType(pQuestArg->pGame, UNIT_PLAYER, pQuestArg->pTarget, ACT1Q4_UnitIterate_SetCustom6Flag);
    sub_00545990(pQuestData, pQuestArg, 64);
    pQuestArg->pTarget->dwDropItemCode = 0x20737076;
    for (int i = 0; i < 8; ++i)
    {
        D2GAME_DropItemAtUnit_6FC4FEC0(pQuestArg->pGame, pQuestArg->pTarget, 0, &nItemLevel, 0, -1, 0);
    }
}

// 0x005944F0
void __fastcall ACT1Q4_SpawnCainPortalOutsideTown(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN);
    if (!pQuestData)
    {
        return;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bChangePortalOutsideTownToSpecialMode = 1;
    pQuestDataEx->unk0x52 = 1;
    if (pQuestDataEx->bCainObjectInitialized != 1)
    {
        return;
    }

    D2UnitStrc* pCainObject = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, pQuestDataEx->nCainObjectGUID);
    if (!pCainObject)
    {
        return;
    }

    D2ObjInitFnStrc tObjInit;
    tObjInit.pObject = pCainObject;
    tObjInit.pGame = pGame;
    tObjInit.pRoom = UNITS_GetRoom(pCainObject);
    tObjInit.nX = CLIENTS_GetUnitX(pCainObject);
    tObjInit.nY = CLIENTS_GetUnitY(pCainObject);
    OBJECTS_InitFunction54_CainStartPosition(&tObjInit);

    if (pQuestDataEx->bCainInTownSpawned != 1)
    {
        return;
    }

    D2UnitStrc* pCain = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pQuestDataEx->nCainMonsterInTownGUID);
    if (!pCain)
    {
        return;
    }

    D2CoordStrc tCoord;
    UNITS_GetCoords(pCain, &tCoord);
    D2ActiveRoomStrc* pRoom = COLLISION_GetRoomBySubTileCoordinates(UNITS_GetRoom(pCain), tCoord.nX, tCoord.nY);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pPortal = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_CAINPORTAL, tCoord.nX, tCoord.nY, pGame, pRoom, 1, 1, 0);
    if (pPortal)
    {
        pQuestDataEx->bCainPortalInTownSpawned = 1;
        pQuestDataEx->nCainPortalInTownGUID = pPortal->dwUnitId;
    }
}

// 0x00594C50
void __fastcall ACT1Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = QUESTS_GetPlayerQuestFlags_Inline(pQuestArg->pGame, pQuestArg->pPlayer);
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_REWARDGRANTED);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_PRIMARYGOALDONE);
    if (bRewardGranted == 1 && !bPrimaryGoalDone)
    {
        return;
    }

    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    const int nUnitId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;
    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->fState >= 4)
    {
        if (!ACT1Q5_ContainsGUID_Inline(pQuestDataEx->nUnitGUIDs2, pQuestDataEx->nUnitCount2, nUnitId) && !ACT1Q5_ContainsGUID_Inline(pQuestDataEx->nUnitGUIDs1, pQuestDataEx->nUnitCount1, nUnitId))
        {
            return;
        }
    }

    if (ACT1Q5_ContainsGUID_Inline(pQuestDataEx->nUnitGUIDs2, pQuestDataEx->nUnitCount2, nUnitId))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
        return;
    }

    if (bRewardGranted == 1 && bPrimaryGoalDone == 1)
    {
        if (ACT1Q5_ContainsGUID_Inline(pQuestDataEx->nUnitGUIDs1, pQuestDataEx->nUnitCount1, nUnitId))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        }
        return;
    }

    const unsigned int nIndex = nIndices_007382AC[pQuestData->fState];
    if (nIndex != -1 && nIndex < 5)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

// 0x00595A50
void __fastcall OBJECTS_InitFunction47_CountessChest(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A1Q5_COUNTESS);
    if (!pQuestData)
    {
        return;
    }

    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;
    const int nUnitId = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    for (int i = 0; i < pQuestDataEx->nCountessChestCount; ++i)
    {
        if (pQuestDataEx->nObjectGUIDs[i] == nUnitId)
        {
            return;
        }
    }

    if (pQuestDataEx->nCountessChestCount < 8)
    {
        pQuestDataEx->nObjectGUIDs[pQuestDataEx->nCountessChestCount] = nUnitId;
        ++pQuestDataEx->nCountessChestCount;
    }

    ACT1Q5_SpawnTowerChestMissiles(pQuestData, pQuestDataEx);
    if (pQuestDataEx->bCountessKilled && !pQuestDataEx->bDeathMissilesCreated)
    {
        EVENT_SetEvent(pQuestData->pGame, pOp->pObject, EVENTTYPE_QUESTFN, pQuestData->pGame->dwGameFrame + 10, 0, 0);
    }
}

// 0x00595C60
void __fastcall ACT1Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    const int nUnitId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;
    D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)pQuestData->pQuestDataEx;

    if (nNPCNo == MONSTER_CAIN5)
    {
        if (nMessageIndex == 166)
        {
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp", 192);
            pQuestDataEx->bCainActivated = 1;
            SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT1Q6_UnitIterate_UpdateQuestStateFlags);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
        else if (nMessageIndex == 184)
        {
            QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pGUID1, nUnitId);
        }
    }
    else if (nNPCNo == MONSTER_WARRIV1)
    {
        if (nMessageIndex != 183)
        {
            return;
        }

        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING))
        {
            return;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_PRIMARYGOALDONE))
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 13, 0, ACT1Q6_UnitIterate_StatusCyclerEx, 0);
            QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp", 214);
            QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A1Q6, QFLAG_PRIMARYGOALDONE);
        }

        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED);
        QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        QUESTS_UpdatePlayerFlags(pQuestData->pGame, pQuestArg->pPlayer);
    }
    else if (nNPCNo == MONSTER_AKARA)
    {
        if (nMessageIndex == 179)
        {
            QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pGUID2, nUnitId);
        }
    }
    else if (nNPCNo == MONSTER_KASHYA)
    {
        if (nMessageIndex == 181)
        {
            QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pGUID3, nUnitId);
        }
    }
}

// 0x00595E20
void __fastcall ACT1Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_PRIMARYGOALDONE);
    const int bRewardPending = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)pQuestData->pQuestDataEx;
    const int nUnitId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;

    switch (nNpcId)
    {
    case MONSTER_AKARA:
        if (QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->pGUID2, nUnitId))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_AKARA, 3);
            return;
        }
        break;
    case MONSTER_KASHYA:
        if (QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->pGUID3, nUnitId))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_KASHYA, 3);
            return;
        }
        break;
    case MONSTER_CAIN5:
        if (QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->pGUID1, nUnitId))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_CAIN5, 3);
            return;
        }
        break;
    }

    if (bRewardPending)
    {
        if (nNpcId == MONSTER_CAIN5 || nNpcId == MONSTER_AKARA || nNpcId == MONSTER_KASHYA)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        }
        else
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        }
    }
    else if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
    }
    else if (pQuestData->fState == 1 && nNpcId == MONSTER_CAIN5 && !bRewardGranted)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_CAIN5, 0);
    }
    else
    {
        if (!pQuestData->fState || (bRewardGranted == 1 && !bPrimaryGoalDone))
        {
            return;
        }

        if (pQuestData->fState >= 4 && !bPrimaryGoalDone)
        {
            return;
        }

        if (bRewardGranted == 1 && bPrimaryGoalDone == 1)
        {
            return;
        }

        const unsigned int nIndex = nIndices_007382C4[pQuestData->fState];
        if (nIndex != -1 && nIndex < 6)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

// 0x00598C40
void __fastcall ACT2Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_PRIMARYGOALDONE);
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDGRANTED);

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDPENDING))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
    }
    else if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
    }
    else if (bRewardGranted != 1)
    {
        if (!pQuestData->fState || (pQuestData->fState >= 4 && !bPrimaryGoalDone))
        {
            return;
        }

        const unsigned int nIndex = nIndices_007398FC[pQuestData->fState];
        if (nIndex != -1 && nIndex < 9)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

// 0x005997F0
void __fastcall ACT2Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (nNPCNo == MONSTER_CAIN6)
    {
        switch (nMessageIndex)
        {
        case 335:
            QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20317274);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN);
            break;

        case 336:
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_ENTERAREA);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN);
            break;

        case 337:
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM1);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN);
            break;

        case 338:
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM2);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN);
            break;

        case 339:
            QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDPENDING);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN);

            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));

            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM6);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_ENTERAREA);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM2);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM1);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            break;

        default:
            return;
        }
    }
}

// 0x0059B530
void __fastcall ACT2Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDGRANTED))
    {
        pQuestDataEx->bPalaceOpen = 1;
        pQuestDataEx->nHaremBlockerObjectMode = 2;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A2Q4, QFLAG_PRIMARYGOALDONE);
        pQuestDataEx->bPalaceOpen = 1;
        pQuestDataEx->nHaremBlockerObjectMode = 2;
        return;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20747368))
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 1;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM1) == 1)
    {
        pQuestData->fLastState = 4;
        pQuestData->fState = 4;
        pQuestDataEx->bPalaceOpen = 1;
        pQuestDataEx->nHaremBlockerObjectMode = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_ENTERAREA) == 1)
    {
        pQuestData->fLastState = 3;
        pQuestData->fState = 4;
        pQuestDataEx->bPalaceOpen = 1;
        pQuestDataEx->nHaremBlockerObjectMode = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fLastState = 3;
        pQuestData->fState = 3;
        pQuestDataEx->bPalaceOpen = 1;
        pQuestDataEx->nHaremBlockerObjectMode = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_STARTED) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 2;
        pQuestDataEx->bPalaceOpen = 1;
        pQuestDataEx->nHaremBlockerObjectMode = 2;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDGRANTED) == 1)
    {
        pQuestDataEx->bPalaceOpen = 1;
        pQuestDataEx->nHaremBlockerObjectMode = 2;
    }
}

// 0x0059D1C0
void __fastcall ACT2Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    if (nNewLevel < LEVEL_LUTGHOLEIN || nNewLevel >= LEVEL_KURASTDOCKTOWN)
    {
        return;
    }

    if (pQuestArg->nOldLevel == LEVEL_LUTGHOLEIN)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    }

    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bDurielKilled)
    {
        if (!pQuestDataEx->nStaffTombLevelId)
        {
            pQuestDataEx->nStaffTombLevelId = DUNGEON_GetHoradricStaffTombLevelId(pQuestArg->pGame->pAct[ACT_II]);
        }

        const int nTombLevelId = pQuestDataEx->nStaffTombLevelId;
        if (!nTombLevelId)
        {
            return;
        }

        if (nNewLevel == nTombLevelId)
        {
            if (pQuestData->fState == 2)
            {
                return;
            }

            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 881);
            if (pQuestData->fLastState <= 1)
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 2, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 0);
            }

            sub_0059C6C0_ACT2Q6_UpdateRewardFlags(pQuestArg->pGame, pQuestArg->pPlayer, 0);
            return;
        }

        if (nNewLevel == LEVEL_CANYONOFTHEMAGI)
        {
            if (!pQuestData->fState)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 897);
                sub_0059C6C0_ACT2Q6_UpdateRewardFlags(pQuestArg->pGame, pQuestArg->pPlayer, 0);
            }

            if (!pQuestData->fLastState)
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 1);
            }

            return;
        }
    }

    if (nNewLevel != LEVEL_DURIELSLAIR || pQuestData->fState > 1)
    {
        return;
    }

    QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 912);
    if (pQuestData->fLastState > 1)
    {
        return;
    }

    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 2, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 0);
    sub_0059C6C0_ACT2Q6_UpdateRewardFlags(pQuestArg->pGame, pQuestArg->pPlayer, 0);
}
