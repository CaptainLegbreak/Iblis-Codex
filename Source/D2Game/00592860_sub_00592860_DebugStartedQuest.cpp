struct D2BitBufferStrc;
struct D2SeedStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xA4];
    unsigned int dwDropItemCode;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
};

struct D2QuestDataStrc;
struct D2QuestArgStrc;
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

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
    void* pNPCMessages;
    int nQuestFilter;
};

struct D2Act1Quest4Strc
{
    char unk0x00[0x30];
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
    unsigned char bMonolithStonesOrdered;
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
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);           // 0x00543F10
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
void __fastcall SUNITINACTIVE_DeleteSingleListNode(D2GameStrc* pGame, unsigned short nUnitType, unsigned short nClassId, unsigned char nAct); // 0x00543140
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);              // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);            // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, void* pItemDrop, int a6, int a7); // 0x00559A30
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
int __fastcall ACT1Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005920D0
int __fastcall ACT1Q4_UnitIterate_RemoveCainFromTristram(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005928C0
int __fastcall ACT1Q4_UnitIterate_AddPlayerGUIDs(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);       // 0x00592B10
void __fastcall ACT1Q4_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592C80
bool __fastcall ACT1Q4_Timer_RemoveCainFromTristram(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);       // 0x00593260

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
