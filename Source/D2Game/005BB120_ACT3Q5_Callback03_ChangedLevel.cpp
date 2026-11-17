struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2QuestArgStrc;
struct D2QuestDataStrc;

struct D2GameStrc
{
    char unk0[0x6D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2PlayerDataStrc
{
    char unk0[0x10];
    D2BitBufferStrc* pQuestData[3];
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char unk0[0x1];
    unsigned char bNotIntro;
    char f_A[0x1];
    unsigned char fLastState;
    unsigned char fState;
    char f_1C[0x7];
    unsigned int dwFlags;
    void* pQuestDataEx;
    char f_1C_2[0x84];
    QUESTCALLBACK pfCallback[15];
    char unk4[0x4];
    int nQuestFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    char unk0[0x8];
    D2UnitStrc* pPlayer;
    char unk0x10[0x4];
    int nOldLevel;
    int nNewLevel;
};

struct D2Act3Quest5Strc
{
    char unk0[0x8];
    int bQuest1RewardGranted;
    unsigned char bOrbSmashed;
    char bFlailDropped[0x2F];
    int nFlailsMissing;
    int nHoradricCubesMissing;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemCode);                    // 0x00544160
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                          // 0x00544760
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);          // 0x00545310
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);       // 0x005678A0
void __fastcall ACT3Q5_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005BB0C0
int __fastcall ACT3Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BADC0
int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005BAF70
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005BB120
void __fastcall ACT3Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;

    if (pQuestArg->nNewLevel == 82 && pQuestData->bNotIntro && !pQuestData->fState)
    {
        pQuestData->fState = 1;
        pQuestData->pfCallback[2] = ACT3Q5_Callback02_NpcDeactivate;
    }

    if (nOldLevel != 75)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);

    if (pQuestData->fState <= 1 || pQuestData->fState > 3)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 4) == 1)
    {
        return;
    }

    if (pQuestData->fLastState < 3)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT3Q5_UnitIterate_StatusCyclerEx, 0);
    }

    if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
    {
        QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 395);
    }
    else
    {
        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 399);
    }
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_UpdateQuestStateFlags);
}

// 0x005BB7B0
int __fastcall ACT3Q5_UnitIterate_DetermineFlailAndCubeDropCounts(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 2)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 19);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 0)
        && !ITEMS_FindQuestItem(pGame, pUnit, ' 1fq') && !ITEMS_FindQuestItem(pGame, pUnit, ' 2fq'))
    {
        ++pQuestDataEx->nFlailsMissing;
    }

    if (!ITEMS_FindQuestItem(pGame, pUnit, ' xob'))
    {
        ++pQuestDataEx->nHoradricCubesMissing;
    }

    return 0;
}

// 0x005BB850
void __fastcall ACT3Q5_UnitIterate_DeleteKhalimItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 18, 0) == 1)
    {
        QUESTS_DeleteItem(pGame, pUnit, ' yeq');
        QUESTS_DeleteItem(pGame, pUnit, ' rhq');
        QUESTS_DeleteItem(pGame, pUnit, ' rbq');
        QUESTS_DeleteItem(pGame, pUnit, ' 1fq');
        QUESTS_DeleteItem(pGame, pUnit, ' 2fq');
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (DRLG_GetActNoFromLevelId(nLevelId) != 2)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 18, 0);
    QUESTRECORD_SetQuestState(pQuestFlags, 18, 13);

    if (!D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        QUESTS_DeleteItem(pGame, pUnit, ' yeq');
        QUESTS_DeleteItem(pGame, pUnit, ' rhq');
        QUESTS_DeleteItem(pGame, pUnit, ' rbq');
        QUESTS_DeleteItem(pGame, pUnit, ' 1fq');
        QUESTS_DeleteItem(pGame, pUnit, ' 2fq');
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 4) && !QUESTRECORD_GetQuestState(pQuestFlags, 21, 0))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 21, 0);
    }
}
