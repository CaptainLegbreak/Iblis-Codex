struct D2BitBufferStrc;
struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xB8 - 0x14];
    unsigned int dwDropItemCode;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestDataStrc;
struct D2QuestArgStrc;
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

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
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
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
    unsigned char bEyeDropped;
    unsigned char bBrainDropped;
    unsigned char bHeartDropped;
    unsigned char bFlailDropped;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    void* pObjectregion;
    int nObjectIdx;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

#define QUEST_A3Q2_KHALIMFLAIL 16
#define QUESTSTATEFLAG_A3Q2 18
#define QFLAG_REWARDGRANTED 0
#define QFLAG_STARTED 2
#define QFLAG_CUSTOM3 7
#define MONSTER_CAIN3 245
#define QUESTEVENT_NPCDEACTIVATE 2
#define UNIT_OBJECT 2
#define OBJMODE_OPENED 2
#define ITEMQUAL_NORMAL 2
#define ITEMQUAL_MAGIC 4

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame);                                            // 0x005438B0
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall QUESTS_SetObjectSelection(D2ObjOperateFnStrc* pOp);                                          // 0x00545850
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, void* pItemDrop, int a6, int a7); // 0x00559A30
D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality); // 0x00585970
D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality);        // 0x00585B90
void __fastcall D2GAME_WarpPlayerToTile_6FCA5B20(D2ObjOperateFnStrc* pOp);                                  // 0x0059D9D0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
int __fastcall ACT3Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005B7F90

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x005B8020
void __fastcall ACT3Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != MONSTER_CAIN3)
    {
        return;
    }

    if (((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->bInitiallyTalkedToCain == 1)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q2_UnitIterate_StatusCyclerEx, 1);
        pQuestData->pfCallback[QUESTEVENT_NPCDEACTIVATE] = 0;
    }
}

// 0x005B8470
void __fastcall ACT3Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_REWARDGRANTED))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_CUSTOM3))
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 7;
    }
    else
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_STARTED))
        {
            pQuestData->fState = 2;
            pQuestData->fLastState = 7;
        }

        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;

        if (pQuestDataEx->nEyesDropped + pQuestDataEx->nBrainsDropped + pQuestDataEx->nHeartsDropped + pQuestDataEx->nFlailsDropped)
        {
            pQuestData->fState = 2;
            pQuestData->fLastState = 7;
        }
    }
}

// 0x005B84E0
int __fastcall OBJECTS_OperateFunction44_SewerStairs(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2UnitStrc* pObject = pOp->pObject;
    if (pObject && pObject->dwAnimMode == OBJMODE_OPENED)
    {
        D2GAME_WarpPlayerToTile_6FCA5B20(pOp);
    }
    return 0;
}

// 0x005B8660
void __fastcall OBJECTS_InitFunction41_SewerStairs(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bSewerStairsInitialized = 1;
    pQuestDataEx->nSewerStairsObjectGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    if (!pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nSewerStairsObjectMode);
    }
}

// 0x005B86B0
void __fastcall OBJECTS_InitFunction42_SewerLever(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData && !pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
    }
}

// 0x005B8770
int __fastcall ACT3Q2_UnitIterate_DetermineKhalimEyeDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (ITEMS_FindQuestItem(pGame, pUnit, ' yeq') || ITEMS_FindQuestItem(pGame, pUnit, ' 2fq'))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        ++((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }
    return 0;
}

// 0x005B87C0
int __fastcall ACT3Q2_UnitIterate_DetermineKhalimBrainDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (ITEMS_FindQuestItem(pGame, pUnit, ' rbq') || ITEMS_FindQuestItem(pGame, pUnit, ' 2fq'))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        ++((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }
    return 0;
}

// 0x005B8810
int __fastcall ACT3Q2_UnitIterate_DetermineKhalimHeartDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (ITEMS_FindQuestItem(pGame, pUnit, ' rhq') || ITEMS_FindQuestItem(pGame, pUnit, ' 2fq'))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        ++((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }
    return 0;
}

// 0x005B8860
int __fastcall OBJECTS_OperateFunction57_KhalimChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!QUESTS_SetObjectSelection(pOp))
    {
        return 0;
    }

    D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
    const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
    for (int i = 0; i < nCounter; ++i)
    {
        OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->pObject, ' dlg', 2);
    }
    pOp->pObject->dwDropItemCode = ' rhq';

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nItemDropCount = 0;
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pPlayer, ACT3Q2_UnitIterate_DetermineKhalimHeartDropCount);

        for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
        {
            int nItemLevel;
            if (D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 1))
            {
                ++pQuestDataEx->nHeartsDropped;
                pQuestDataEx->bHeartDropped = 1;
            }
        }
    }

    OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);
    return 0;
}

// 0x005B8940
int __fastcall OBJECTS_OperateFunction58_KhalimChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!QUESTS_SetObjectSelection(pOp))
    {
        return 0;
    }

    D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
    const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
    for (int i = 0; i < nCounter; ++i)
    {
        OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->pObject, ' dlg', 2);
    }
    pOp->pObject->dwDropItemCode = ' yeq';

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nItemDropCount = 0;
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pPlayer, ACT3Q2_UnitIterate_DetermineKhalimEyeDropCount);

        for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
        {
            int nItemLevel;
            if (D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 1))
            {
                ++pQuestDataEx->nEyesDropped;
                pQuestDataEx->bEyeDropped = 1;
            }
        }
    }

    OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);
    return 0;
}

// 0x005B8A20
int __fastcall OBJECTS_OperateFunction59_KhalimChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!QUESTS_SetObjectSelection(pOp))
    {
        return 0;
    }

    D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
    const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
    for (int i = 0; i < nCounter; ++i)
    {
        OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->pObject, ' dlg', 2);
    }
    pOp->pObject->dwDropItemCode = ' rbq';

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nItemDropCount = 0;
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pPlayer, ACT3Q2_UnitIterate_DetermineKhalimBrainDropCount);

        for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
        {
            int nItemLevel;
            if (D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 1))
            {
                ++pQuestDataEx->nBrainsDropped;
                pQuestDataEx->bBrainDropped = 1;
            }
        }
    }

    OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);
    return 0;
}
