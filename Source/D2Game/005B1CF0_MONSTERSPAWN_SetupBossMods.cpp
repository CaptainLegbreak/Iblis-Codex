struct D2GameStrc
{
    char pad0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0xBC];
    unsigned int dwFlags;
};

struct D2MonsterSpawnParamsStrc
{
    D2GameStrc* pGame;
    void* pRoom;
    void* pRoomCoordList;
    int nMonsterId;
};

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    char pad0x04[0x1A4];
};

struct D2DataTablesStrc
{
    char pad0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    int nPadA7C;
    int nMonStatsTxtRecordCount;
};

struct D2ItemsTxt
{
    char pad0x00[0x88];
    unsigned int dwUltraCode;
    unsigned int dwUberCode;
};

struct D2MonsterItemCodeStrc
{
    unsigned int dwCode;
    int nUnk0x04;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2MonsterItemCodeStrc gaAncientBarbItems_006E1BB0[4][3];                                             // 0x006E1BB0

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
void __fastcall sub_00573B20_GiveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MonsterItemCodeStrc* pCode, int nLevel, int nFlags); // 0x00573B20
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId);                // 0x005436B0
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850
void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, int nFlag, int bSet);                         // 0x00573570
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
void __fastcall QUESTS_WarrivSpawn(D2GameStrc* pGame, void* pRoom, int nXpos, int nYpos, int nWarrivId);    // 0x005447A0

// build: symbol ?MONSTERSPAWN_EquipAncientBarbarians@@YAXPAUD2UnitStrc@@@Z 0x005B1C50
static __declspec(noinline) void MONSTERSPAWN_EquipAncientBarbarians(D2UnitStrc* pUnit)
{
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0);
    for (int i = 0; i < 4; ++i)
    {
        D2MonsterItemCodeStrc tCode = gaAncientBarbItems_006E1BB0[i][nClassId];
        int nItemId;
        D2ItemsTxt* pItemsTxt = DATATBLS_GetItemRecordFromItemCode(tCode.dwCode, &nItemId);
        switch (pGame->nDifficulty)
        {
        case 1:
            tCode.dwCode = pItemsTxt->dwUltraCode;
            break;
        case 2:
            tCode.dwCode = pItemsTxt->dwUberCode;
            break;
        }
        sub_00573B20_GiveItem(pGame, pUnit, &tCode, nLevel, 4);
    }
}

static __forceinline D2MonStatsTxt* MONSTERS_GetMonStatsTxtRecord_Inline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline int MONSTERS_ValidateMonsterId_Inline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }
    return nMonsterId;
}

static __forceinline void MONSTERUNIQUE_ToggleUnitFlag_Inline(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags |= nFlag;
    }
}

// 0x005B1CF0
static __declspec(noinline) void MONSTERSPAWN_SetupBossMods(D2MonsterSpawnParamsStrc* pMonCreate, D2UnitStrc* pUnit)
{
    D2GameStrc* pGame = pMonCreate->pGame;
    void* pRoom = pMonCreate->pRoom;
    const int nMonsterId = pMonCreate->nMonsterId;

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERS_GetMonStatsTxtRecord_Inline(nMonsterId);
    int nBaseId;
    if (!pMonStatsTxtRecord)
    {
        nBaseId = nMonsterId;
    }
    else
    {
        nBaseId = pMonStatsTxtRecord->nBaseId;
    }

    switch (MONSTERS_ValidateMonsterId_Inline(nBaseId))
    {
    case 0xD3:
        if (nMonsterId != 0x2C4)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0xD);
            QUESTS_CreateChainRecord(pGame, pUnit, 9);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x12, 1);
        return;
    case 0xAF:
    {
        const int nWarrivId = MONSTERS_ValidateMonsterId_Inline(0xAF);
        QUESTS_WarrivSpawn(pGame, pRoom, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nWarrivId);
        return;
    }
    case 0xFA:
        QUESTS_CreateChainRecord(pGame, pUnit, 0xC);
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x800);
        MONSTER_ToggleSummonerFlag(pUnit, 1, 1);
        return;
    case 0xF3:
        if (nMonsterId != 0x2C1)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 0x17);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        return;
    case 0x16E:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x13);
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x20000);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x154:
    case 0x155:
    case 0x156:
    case 0x157:
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x20000);
        return;
    case 0xF2:
        if (nMonsterId != 0x2C0)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0x14);
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x1E, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x11, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        return;
    case 0x9C:
        if (nMonsterId != 0x2C3)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 6);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x17, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x1D, 1);
        return;
    case 0x199:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x18);
        return;
    case 0x100:
        if (nMonsterId != 0x2C2)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 0x16);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x12, 1);
        return;
    case 0x197:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x11);
        return;
    case 0xE5:
        QUESTS_CreateChainRecord(pGame, pUnit, 8);
        return;
    case 0x10B:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xC, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        QUESTS_CreateChainRecord(pGame, pUnit, 2);
        STATES_ToggleState(pUnit, 0x76, 1);
        return;
    case 0x11C:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x17, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x124:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x1F, 0);
        return;
    case 0x192:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x1B2:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x20);
        return;
    case 0x20E:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x22);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x21C:
        MONSTERSPAWN_EquipAncientBarbarians(pUnit);
        return;
    case 0x220:
        if (nMonsterId != 0x2C5)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0x24);
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x12, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        return;
    }
}

void __fastcall sub_H02_Emit_005B1CF0(D2UnitStrc* pUnit, D2MonsterSpawnParamsStrc* pMonCreate)
{
    MONSTERSPAWN_SetupBossMods(pMonCreate, pUnit);
}

#include "gen/data/Source/D2Game/005B1CF0_MONSTERSPAWN_SetupBossMods.inc"
