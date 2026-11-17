struct D2UnitStrc;
struct D2ShrinesTxt;

struct D2ObjOperateFnStrc
{
    char unk0x00[0x08];
    D2UnitStrc* pPlayer;
};

struct D2DataTablesStrc
{
    char unk0x000[0xAE0];
    unsigned short nSuperUniqueIds[66];
};

#define STAT_HITPOINTS 6
#define STAT_MANA 8

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0

// 0x005828E0
void __fastcall D2GAME_SHRINES_Refill_6FC76730(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nHpDiff = STATLIST_GetMaxLifeFromUnit(pOp->pPlayer) - STATLIST_UnitGetStatValue(pOp->pPlayer, STAT_HITPOINTS, 0);
    if (nHpDiff)
    {
        STATLIST_AddUnitStat(pOp->pPlayer, STAT_HITPOINTS, nHpDiff, 0);
    }

    const int nManaDiff = STATLIST_GetMaxManaFromUnit(pOp->pPlayer) - STATLIST_UnitGetStatValue(pOp->pPlayer, STAT_MANA, 0);
    if (nManaDiff)
    {
        STATLIST_AddUnitStat(pOp->pPlayer, STAT_MANA, nManaDiff, 0);
    }
}

// 0x00586B30
int __fastcall sub_00586B30_GetSuperUniqueId(unsigned int nIndex)
{
    if (nIndex <= 65)
    {
        return sgptDataTables->nSuperUniqueIds[nIndex];
    }

    return -1;
}
