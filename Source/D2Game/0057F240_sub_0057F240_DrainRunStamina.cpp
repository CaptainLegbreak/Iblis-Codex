struct D2ActiveRoomStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x58];
    D2InventoryStrc* pInventory;
};

struct D2CharStatsTxt
{
    char unk0x00[0x42];
    unsigned char nRunDrain;
    char unk0x43[0xC4 - 0x43];
};

struct D2ItemsTxt
{
    char unk0x00[0xD8];
    int dwSpeed;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
void __fastcall sub_0057F240_EmitWalk(D2UnitStrc* pPlayer);

static inline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

static __declspec(noinline) int sub_0057F240_DrainRunStamina(D2UnitStrc* pPlayer);

// 0x0057F240
static int sub_0057F240_DrainRunStamina(D2UnitStrc* pPlayer)
{
    if (!pPlayer)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pPlayer)))
    {
        return 1;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pPlayer->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return 0;
    }

    int nStaminaLost = 2 * pCharStatsTxtRecord->nRunDrain;
    if (!pPlayer->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pTorsoArmor = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, 3);
    if (pTorsoArmor)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pTorsoArmor ? -1 : pTorsoArmor->dwClassId);
        if (pItemsTxtRecord)
        {
            int nSpeed = pItemsTxtRecord->dwSpeed;
            nSpeed = nSpeed / 10 + 1;
            nStaminaLost *= nSpeed;
        }
    }

    const int nStaminaDrainPct = STATLIST_UnitGetItemStatOrSkillStatValue(pPlayer, 154, 0);
    if (nStaminaDrainPct)
    {
        nStaminaLost += nStaminaLost * nStaminaDrainPct / -100;
    }

    if (nStaminaLost < 1)
    {
        nStaminaLost = 1;
    }

    STATLIST_AddUnitStat(pPlayer, 10, -nStaminaLost, 0);

    if (STATLIST_UnitGetStatValue(pPlayer, 10, 0) <= 0)
    {
        STATLIST_SetUnitStat(pPlayer, 10, 0, 0);
        return 0;
    }

    return 1;
}

void __fastcall sub_0057F240_EmitCaller(void* pGame, D2UnitStrc* pPlayer)
{
    if (pPlayer && pPlayer->dwUnitType == 0 && !sub_0057F240_DrainRunStamina(pPlayer))
    {
        sub_0057F240_EmitWalk(pPlayer);
    }
}
