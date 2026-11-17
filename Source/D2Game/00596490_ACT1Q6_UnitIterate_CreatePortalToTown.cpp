struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2TextHeaderStrc;
struct D2DrlgActStrc;
struct D2ItemDropStrc;

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
    char pad0x6E[0x4E];
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
    D2TextHeaderStrc* pTextControl;
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2QuestDataStrc;
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);
typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc*, D2QuestDataStrc*);

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

struct D2Act1Quest4Strc
{
    char pad0x00[0x4C];
    unsigned char unk0x4C;
    unsigned char bActivateCairnStones;
    unsigned char bDecipheredScrollAcquired;
    char pad0x4F[0x03];
    unsigned char unk0x52;
    unsigned char bAkaraIntroActivated;
    int nCainGibbetObjectMode;
    int unk0x58;
    char pad0x5C[0x07];
    unsigned char bQuestCompleteBefore;
    char pad0x64[0x14];
    unsigned char bScrollAcquired;
    char pad0x79[0x03];
    int nScrollsInGame;
};

struct D2Act1Quest6Strc
{
    D2QuestGUIDStrc pGUID1;
    D2QuestGUIDStrc pGUID2;
    D2QuestGUIDStrc pGUID3;
};

struct D2Act2Quest1Strc
{
    unsigned char bRadamentKilled;
    unsigned char pad0x01[3];
    D2ActiveRoomStrc* pRoom;
    unsigned char bAtmaActivated;
    unsigned char unk0x09;
    unsigned char bStatusTimerStarted;
    unsigned char pad0x0B;
    int nSkillBookDropCount;
};

struct D2Act2Quest4Strc
{
    char pad0x00[0x0C];
    unsigned char bJerhynStartInitialized;
    unsigned char bJerhynPalaceInitialized;
    unsigned char bPalaceOpen;
    char pad0x0F[0x2D];
    int nJerhynGUID;
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

struct D2Act2Quest6Strc
{
    char pad0x00[0x34];
    int nStaffTombLevelId;
    unsigned char bObjectIdsInitialized;
    unsigned char pad0x39;
    unsigned short nArcaneThings;
    char pad0x3C[0x0C];
    int nArcaneThingObjectIds[6];
};

#define LEVEL_ROGUEENCAMPMENT 1
#define LEVEL_CATACOMBSLEV4 37
#define LEVEL_SEWERSLEV3 49
#define LEVEL_TALRASHASTOMB1 66
#define MONSTER_AKARA 148
#define MONSTER_KASHYA 150
#define MONSTER_WARRIV1 155
#define MONSTER_CAIN5 265
#define UNIT_MONSTER 1
#define QUEST_A1Q4_CAIN 4
#define QUEST_A2Q1_RADAMENT 8
#define QUEST_A2Q6_DURIEL 13
#define QUESTSTATEFLAG_A2Q0 8
#define QUESTSTATEFLAG_A2Q4 12
#define MONSTER_JERHYN 201
#define QUESTSTATEFLAG_A1Q4 4
#define QUESTSTATEFLAG_A1Q6 6
#define QUESTSTATEFLAG_A2Q3 11
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define OBJMODE_SPECIAL1 3
#define ITEMQUAL_NORMAL 2

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
int __fastcall QUESTS_QuickCheckPlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                            // 0x00545290
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID);                                 // 0x005452C0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine);  // 0x00544070
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);   // 0x00544350
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*)); // 0x005537D0
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);           // 0x00543F10
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate); // 0x00544300
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
int __stdcall DUNGEON_GetHoradricStaffTombLevelId(D2DrlgActStrc* pAct);                                     // 0x0061AEB0
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                          // 0x00544760
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned int fCollision, D2ActiveRoomStrc** ppRoom, int nRadius, int a7); // 0x00545340
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int nFlags); // 0x005B2F20

int __fastcall ACT2Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00598E20
int __fastcall ACT2Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);     // 0x00598DC0
int __fastcall ACT2Q1_UnitIterate_DetermineSkillBookDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00598FA0
bool __fastcall ACT2Q1_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);                  // 0x00598F70
int __fastcall ACT2Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005988B0
int __fastcall ACT2Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005989E0

static int nIndices_0073A620[] =                                                                            // 0x0073A620
{
    -1, 0, 1, 2, 3, 0
};

static int nArcaneThingObjectIds_00738FAC[] =                                                               // 0x00738FAC
{
    313, 312, 308, 310, 311, 309, 307
};

// 0x00596490
int __fastcall ACT1Q6_UnitIterate_CreatePortalToTown(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_CATACOMBSLEV4)
    {
        return 0;
    }

    D2CoordStrc pCoord;
    UNITS_GetCoords(pUnit, &pCoord);
    D2GAME_CreatePortalObject_6FD13DF0(pGame, pUnit, pRoom, pCoord.nX, pCoord.nY, LEVEL_ROGUEENCAMPMENT, 0, 59, 0);
    return 1;
}

// 0x005967F0
char __fastcall ACT1Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    const int nUnitId = !pPlayer ? -1 : pPlayer->dwUnitId;

    D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)pQuest->pQuestDataEx;
    if (nNpcId == MONSTER_CAIN5)
    {
        if (QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->pGUID1, nUnitId))
        {
            return 1;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED) != 1 && pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING))
        {
            return 1;
        }
    }
    else if (nNpcId == MONSTER_WARRIV1)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED) != 1)
        {
            return QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING) == 1;
        }
    }
    else if (nNpcId == MONSTER_AKARA)
    {
        return QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->pGUID2, nUnitId) != 0;
    }
    if (nNpcId == MONSTER_KASHYA)
    {
        return QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->pGUID3, nUnitId) != 0;
    }

    return 0;
}

// 0x00597030
void __fastcall ACT1Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDGRANTED) == 1)
    {
        D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A1Q4_CAIN);
        if (pQuest)
        {
            ((D2Act1Quest4Strc*)pQuest->pQuestDataEx)->unk0x52 = 1;
        }

        QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A1Q4, QFLAG_PRIMARYGOALDONE);
        pQuestDataEx->nCainGibbetObjectMode = OBJMODE_SPECIAL1;
        pQuestDataEx->unk0x4C = 1;
        pQuestDataEx->bActivateCairnStones = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_COMPLETEDBEFORE) == 1)
    {
        D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A1Q4_CAIN);
        if (pQuest)
        {
            ((D2Act1Quest4Strc*)pQuest->pQuestDataEx)->unk0x52 = 1;
        }

        pQuest = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A1Q4_CAIN);
        if (pQuest)
        {
            ((D2Act1Quest4Strc*)pQuest->pQuestDataEx)->bQuestCompleteBefore = 1;
        }

        pQuestDataEx->nCainGibbetObjectMode = OBJMODE_SPECIAL1;
        pQuestDataEx->unk0x4C = 1;
        pQuestDataEx->bActivateCairnStones = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_ENTERAREA) == 1)
    {
        pQuestData->fLastState = 4;
        pQuestData->fState = 5;
        pQuestDataEx->unk0x4C = 1;
        pQuestDataEx->bDecipheredScrollAcquired = 1;
        pQuestDataEx->bActivateCairnStones = 1;
        pQuestDataEx->bScrollAcquired = 1;
        pQuestDataEx->unk0x58 = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_STARTED) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }

    D2UnitStrc* pDecipheredScroll = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' dkb');
    D2UnitStrc* pBarkScroll = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' skb');
    if (pDecipheredScroll)
    {
        ++pQuestDataEx->nScrollsInGame;
    }

    if (pBarkScroll)
    {
        ++pQuestDataEx->nScrollsInGame;
    }

    if (pDecipheredScroll)
    {
        pQuestData->fState = 5;
        pQuestData->fLastState = 3;
        pQuestDataEx->bDecipheredScrollAcquired = 1;
        pQuestDataEx->bScrollAcquired = 1;
        pQuestDataEx->unk0x58 = 1;
    }
    else if (pBarkScroll)
    {
        pQuestDataEx->bScrollAcquired = 1;
        pQuestData->fState = 4;
        pQuestData->fLastState = 2;
        pQuestDataEx->unk0x58 = 1;
    }
}

// 0x00599020
void __fastcall ACT2Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    QUESTS_DebugOutput(pQuestData->pGame, "killed radament for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q1.cpp", 495);
    QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q1.cpp", 496);
    QUESTS_SetGlobalState(pQuestArg->pGame, pQuestData->nQuestFilter, QFLAG_PRIMARYGOALDONE);

    D2Act2Quest1Strc* pQuestDataEx = (D2Act2Quest1Strc*)pQuestData->pQuestDataEx;
    pQuestData->pfCallback[2] = 0;
    pQuestDataEx->bRadamentKilled = 1;
    pQuestDataEx->pRoom = UNITS_GetRoom(pQuestArg->pTarget);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q1_UnitIterate_SetCompletionFlag);
    pQuestDataEx->nSkillBookDropCount = 0;
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q1_UnitIterate_DetermineSkillBookDropCount);

    if (!pQuestDataEx->bStatusTimerStarted)
    {
        pQuestDataEx->bStatusTimerStarted = 1;
        QUESTS_CreateTimer(pQuestData, ACT2Q1_Timer_StatusCycler, 12);
    }

    if (!pQuestDataEx->nSkillBookDropCount)
    {
        return;
    }

    pQuestArg->pTarget->dwDropItemCode = ' ssa';
    for (int i = 0; i < pQuestDataEx->nSkillBookDropCount; ++i)
    {
        int nItemLevel;
        D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pQuestArg->pTarget, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0);
    }
}

// 0x00599420
void __fastcall ACT2Q1_OnRadamentActivated(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q1_RADAMENT);
    if (!pQuestData || pQuestData->bNotIntro != 1 || (pQuestData->fState >= 3u && pQuestData->fLastState >= 2u))
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_SEWERSLEV3)
    {
        return;
    }

    pQuestData->pfCallback[2] = 0;

    bool bStepped = false;
    if (pQuestData->fState < 3)
    {
        bStepped = true;
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q1.cpp", 708);
    }

    if (pQuestData->fLastState < 2)
    {
        D2Act2Quest1Strc* pQuestDataEx = (D2Act2Quest1Strc*)pQuestData->pQuestDataEx;
        pQuestData->dwFlags &= 0xFFFFFF00;

        bool bIterate = false;
        if (!pQuestDataEx->unk0x09)
        {
            pQuestDataEx->unk0x09 = 1;
            bIterate = true;
        }
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT2Q1_UnitIterate_StatusCyclerEx, bIterate);
    }
    else if (!bStepped)
    {
        return;
    }
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q1_UnitIterate_UpdateQuestStateFlags);
}

// 0x0059A270
void __fastcall ACT2Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDPENDING))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
    }
    else if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_COMPLETEDNOW))
    {
        if (QUESTS_CheckPlayerGUID(pQuestData, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId)) == 1)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        }
        else if (pQuestData->fState && pQuestData->bNotIntro && QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDGRANTED) != 1 && pQuestData->fState < 4)
        {
            const int nIndex = nIndices_0073A620[pQuestData->fState];
            if (nIndex != -1 && (unsigned int)nIndex < 6)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
            }
        }
    }
}

// 0x0059D720
int __fastcall sub_0059D720_ACT2Q6_GetArcaneThingObjectId(D2QuestDataStrc* pQuestData)
{
    const int nTombStaffLevel = DUNGEON_GetHoradricStaffTombLevelId(pQuestData->pGame->pAct[1]);
    if (nTombStaffLevel)
    {
        D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
        const int nTombOffset = nTombStaffLevel - LEVEL_TALRASHASTOMB1;
        if (!pQuestDataEx->bObjectIdsInitialized)
        {
            pQuestDataEx->bObjectIdsInitialized = 1;

            int i = 0;
            int j = 0;
            for (int k = 0; k < 7; ++k)
            {
                if (j == nTombOffset)
                {
                    ++j;
                }
                else if (j < 7 && i < 6)
                {
                    pQuestDataEx->nArcaneThingObjectIds[i] = nArcaneThingObjectIds_00738FAC[j];
                    ++i;
                    ++j;
                }
            }
        }

        if (pQuestDataEx->nArcaneThings == 6)
        {
            pQuestDataEx->nArcaneThings = 0;
        }

        return pQuestDataEx->nArcaneThingObjectIds[pQuestDataEx->nArcaneThings++];
    }

    return 307;
}

// 0x0059F380
void __fastcall ACT2Q4_InitializeJerhynStartObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bJerhynPalaceInitialized || QUESTS_GetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A2Q0, QFLAG_PRIMARYGOALDONE) || QUESTS_GetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A2Q4, QFLAG_PRIMARYGOALDONE))
    {
        return;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A2Q6_DURIEL);
    if (!pQuest || !pQuest->bNotIntro || pQuest->fState >= 2)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = pOp->pRoom;
    D2CoordStrc pCoord;
    pCoord.nX = pOp->nX;
    pCoord.nY = pOp->nY;

    QUESTS_GetFreePosition(pRoom, &pCoord, 2, 0x100, &pRoom, 10, 100);

    D2UnitStrc* pJerhyn = D2GAME_SpawnMonster_6FC69F10(pQuestData->pGame, pRoom, pCoord.nX, pCoord.nY, MONSTER_JERHYN, 1, -1, 0);
    if (pJerhyn)
    {
        pQuestDataEx->bJerhynStartInitialized = 1;
        pQuestDataEx->nJerhynGUID = pJerhyn->dwUnitId;
    }
}
