extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2TextHeaderStrc;
struct D2ClientStrc;
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
    int dwAnimMode;
    char pad0x14[0xA4];
    unsigned int dwDropItemCode;
};

struct D2GameStrc
{
    char pad0x00[0x6A];
    unsigned char nGameType;
    char pad0x6B[0x02];
    unsigned char nDifficulty;
    char pad0x6E[0x02];
    int bExpansion;
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

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2QuestDataStrc;
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);
typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc*, D2QuestDataStrc*);
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

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
    char unk0xE4[0x0C];
    QUESTSEQFILTER pfSeqFilter;
};

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

struct D2Act4Quest1Strc
{
    int unused0x00;
    D2CoordStrc pCoords;
    unsigned char unk0x0C;
    unsigned char bIzualGhostIsSpawning;
    unsigned char unused0x0E;
    unsigned char unk0x0F;
    unsigned char bNeedToSpawnIzualGhost;
    unsigned char pad0x11[3];
    D2UnitStrc* pTargetUnit;
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

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState);           // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState);         // 0x0065C3A0
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestRecord, int nQuest);         // 0x0065C3E0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);          // 0x00543F10
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode);                      // 0x00544160
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                          // 0x00544760
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID);                              // 0x00545200
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID);                                 // 0x005452C0
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit);                             // 0x005455B0
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget);    // 0x00545780
int __fastcall QUESTS_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int dwCode, int nLevel, int nQuality, int bDroppable); // 0x005466B0
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                  // 0x00554190
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                          // 0x00624690
int __stdcall UNITS_TestCollisionByCoordinates(D2UnitStrc* pUnit, int nX, int nY, int nCollisionMask);      // 0x006229F0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
int __stdcall MONSTERS_IsBoss(void* pMonStatsTxtRecord, D2UnitStrc* pMonster);                              // 0x0063E9F0
void __fastcall sub_6FC7BEC0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x005351C0
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                            // 0x00535060
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket);                              // 0x0053D710
void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket);            // 0x0053D7E0
void __fastcall sub_0053D940_SendPacket0x61(D2ClientStrc* pClient, unsigned char nValue);                   // 0x0053D940
void __fastcall D2GAME_PlayerChangeAct_6FC867C0(D2GameStrc* pGame, D2UnitStrc* pUnit, int dwDestLvl, int nTileCalc); // 0x0054B830
void __stdcall sub_005B4FF0_ActivateHarrogathWaypoint(D2GameStrc* pGame, D2UnitStrc* pPlayer);              // 0x005B4FF0
bool __fastcall sub_005BBF80_ACT3Q5_IsOrbNotSmashed(D2GameStrc* pGame);                                     // 0x005BBF80
int __fastcall ACT4Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);     // 0x005B3CD0
int __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3DE0
bool __fastcall ACT4Q1_SpawnIzualGhost(D2GameStrc* pGame, D2QuestDataStrc* pQuest);                         // 0x005B3E60
int __fastcall ACT4Q1_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);      // 0x005B3F20
int __fastcall ACT4Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005B59C0
int __fastcall ACT3Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005B7340
void __fastcall ACT3Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005B7740
int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005BAF70
int __fastcall ACT3Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005BC210

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
