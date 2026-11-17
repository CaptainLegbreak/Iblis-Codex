struct D2UnitStrc;

struct D2ObjOperateFnStrc
{
    char unk0x00[0x08];
    D2UnitStrc* pPlayer;
};

struct D2ShrinesTxt
{
    unsigned char nCode;
    char unk0x01[0x03];
    unsigned int dwArg0;
    unsigned int dwArg1;
};

#define STAT_HITPOINTS 6
#define STAT_MANA 8

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0

// 0x00582940
void __fastcall D2GAME_SHRINES_ExchangeHealth_6FC76790(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nHitpoints = STATLIST_UnitGetStatValue(pOp->pPlayer, STAT_HITPOINTS, 0) >> 8;
    const unsigned int nValue = pShrinesTxtRecord->dwArg0 * (unsigned int)nHitpoints / 100 << 8;
    STATLIST_AddUnitStat(pOp->pPlayer, STAT_HITPOINTS, -(int)nValue, 0);
    STATLIST_AddUnitStat(pOp->pPlayer, STAT_MANA, nValue * pShrinesTxtRecord->dwArg1 / 100, 0);
}

// 0x005829A0
void __fastcall D2GAME_SHRINES_ExchangeMana_6FC767F0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nMana = STATLIST_UnitGetStatValue(pOp->pPlayer, STAT_MANA, 0);
    const unsigned int nValue = pShrinesTxtRecord->dwArg0 * (unsigned int)nMana / 100;
    STATLIST_AddUnitStat(pOp->pPlayer, STAT_MANA, -(int)nValue, 0);
    STATLIST_AddUnitStat(pOp->pPlayer, STAT_HITPOINTS, nValue * pShrinesTxtRecord->dwArg1 / 100, 0);
}
