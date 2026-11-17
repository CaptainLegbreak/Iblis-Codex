struct D2ActiveRoomStrc;
struct D2BitBufferStrc;
struct D2DrlgActStrc;
struct D2ItemDropStrc;
struct D2QuestDataStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2GameStrc
{
    char unk0[0x6D];
    unsigned char nDifficulty;
    char nMaxPlayers[0x4E];
    D2DrlgActStrc* pAct[5];
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0[0x8];
    int dwUnitId;
    int dwAnimMode;
    char f_10[0xA4];
    unsigned int dwDropItemCode;
};

struct D2PlayerDataStrc
{
    char unk0[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char unk0[0x1];
    unsigned char bNotIntro;
    char f_A[0xE];
    void* pQuestDataEx;
    char f_1C[0xC4];
    int nQuestFilter;
};

struct D2Act2Quest2Strc
{
    char unk0[0x24];
    int nAmulets;
};

struct D2Act2Quest3Strc
{
    char unk0[0x2];
    unsigned char bDarknessApplied;
    char bDarknessPending[0x1];
    unsigned char bAltarDestroyed;
    unsigned char bAltarInitialized;
    char unk0x06[0x2];
    int nAltarMode;
    int nAltarGUID;
    D2ActiveRoomStrc* pRoom;
    char tPlayerGUIDs[0x84];
    int nAltarLevelId;
    int nViperAmuletDropCount;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame);                                            // 0x005438B0
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);           // 0x00543F10
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2);                                      // 0x00545760
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality); // 0x00585970
D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality);      // 0x00585B90
int __fastcall ACT2Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);     // 0x00599FE0
int __fastcall ACT2Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A0B0
int __fastcall ACT2Q3_UnitIterate_SendPacket0x53ToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A170
int __fastcall ACT2Q3_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);      // 0x0059A680
bool __fastcall ACT2Q3_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);                  // 0x0059A700
int __fastcall ACT2Q3_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A730
int __fastcall ACT2Q3_UnitIterate_DetermineViperAmuletDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A770
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __stdcall ENVIRONMENT_TaintedSunEnd(D2DrlgActStrc* pAct);                                              // 0x0061C4D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);         // 0x0065C3A0

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x0059A7E0
int __fastcall OBJECTS_OperateFunction24_TaintedSunAltar(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 10);
    if (!pQuestData)
    {
        return 0;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
    if ((QUESTRECORD_GetQuestState(pQuestFlags, 11, 1) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 11, 0) == 1)
        && (QUESTRECORD_GetQuestState(pQuestFlags, 10, 0) == 1 || ITEMS_FindQuestItem(pOp->pGame, pOp->pPlayer, ' piv') || ITEMS_FindQuestItem(pOp->pGame, pOp->pPlayer, ' tsh')))
    {
        SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
        return 0;
    }

    if (pOp->pObject && pOp->pObject->dwAnimMode)
    {
        return 0;
    }

    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 1);
        pQuestDataEx->nAltarMode = 2;
        pQuestDataEx->nViperAmuletDropCount = 0;
        pQuestDataEx->bAltarDestroyed = 1;
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pPlayer, ACT2Q3_UnitIterate_DetermineViperAmuletDropCount);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pObject);
        int nItemLevel = DUNGEON_GetLevelIdFromRoom(pRoom);
        int nAmuletsDropped = 0;
        pOp->pObject->dwDropItemCode = ' piv';
        for (int i = 0; i < pQuestDataEx->nViperAmuletDropCount; ++i)
        {
            D2UnitStrc* pItem = D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, 7, &nItemLevel, 0, -1, 0);
            if (pItem)
            {
                ITEMS_SetItemFlag(pItem, 16, 1);
                ++nAmuletsDropped;
            }
        }

        OBJMODE_DropFromChestTCWithQuality(pOp, 4);
        D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
        const int nGoldDropCount = SEED_RollRandomNumber(pSeed) % 5 + 5;
        for (int i = 0; i < nGoldDropCount; ++i)
        {
            OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->pObject, ' dlg', 2);
        }

        D2QuestDataStrc* pQuestDataStaff = QUESTS_GetQuestData(pQuestData->pGame, 9);
        if (pQuestDataStaff)
        {
            ((D2Act2Quest2Strc*)pQuestDataStaff->pQuestDataEx)->nAmulets += nAmuletsDropped;
        }
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pObject);
    pQuestDataEx->pRoom = pRoom;
    pQuestDataEx->nAltarLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    UNITS_ChangeAnimMode(pOp->pObject, 1);
    pQuestDataEx->nAltarMode = 2;
    pQuestDataEx->bAltarInitialized = 1;
    pQuestDataEx->nAltarGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    pQuestDataEx->bAltarDestroyed = 1;

    if (pQuestData->bNotIntro)
    {
        D2GameStrc* pGame = pQuestData->pGame;
        if (pGame->pAct[1])
        {
            ((D2Act2Quest3Strc*)pQuestData->pQuestDataEx)->bDarknessApplied = 0;
            ENVIRONMENT_TaintedSunEnd(pGame->pAct[1]);
            SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT2Q3_UnitIterate_SendPacket0x53ToClient);
        }

        QUESTS_DebugOutput(pQuestData->pGame, "Finished quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 991);
        QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 992);
        QUESTS_TriggerFX(pQuestData->pGame, 6);
    }

    pQuestDataEx->nViperAmuletDropCount = 0;
    SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pPlayer, ACT2Q3_UnitIterate_DetermineViperAmuletDropCount);

    if (pQuestData->bNotIntro)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 11, 0))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 11, 1);
            QUESTRECORD_SetQuestState(pQuestFlags, 11, 13);
            QUESTRECORD_ClearQuestState(pQuestFlags, 11, 14);
        }

        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pObject, ACT2Q3_UnitIterate_SetRewardPending);
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pObject, ACT2Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pObject, ACT2Q3_UnitIterate_AttachCompletionSound);
        QUESTS_SetGlobalState(pOp->pGame, pQuestData->nQuestFilter, 13);
    }

    int nItemLevel = DUNGEON_GetLevelIdFromRoom(pQuestDataEx->pRoom);
    int nAmuletsDropped = 0;
    pOp->pObject->dwDropItemCode = ' piv';
    for (int i = 0; i < pQuestDataEx->nViperAmuletDropCount; ++i)
    {
        D2UnitStrc* pItem = D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, 7, &nItemLevel, 0, -1, 0);
        if (pItem)
        {
            ITEMS_SetItemFlag(pItem, 16, 1);
            ++nAmuletsDropped;
        }
    }

    D2QuestDataStrc* pQuestDataStaff = QUESTS_GetQuestData(pQuestData->pGame, 9);
    if (pQuestDataStaff)
    {
        ((D2Act2Quest2Strc*)pQuestDataStaff->pQuestDataEx)->nAmulets += nAmuletsDropped;
    }

    OBJMODE_DropFromChestTCWithQuality(pOp, 4);
    D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
    const int nGoldDropCount = SEED_RollRandomNumber(pSeed) % 5 + 5;
    for (int i = 0; i < nGoldDropCount; ++i)
    {
        OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->pObject, ' dlg', 2);
    }

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q3_UnitIterate_SetCompletionFlag);
    QUESTS_CreateTimer(pQuestData, ACT2Q3_Timer_StatusCycler, 10);
    return 0;
}
