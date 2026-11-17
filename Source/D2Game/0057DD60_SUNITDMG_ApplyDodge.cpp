struct D2InventoryStrc;
struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2UnitStrc {
    int dwUnitType; char pad04[12]; int dwAnimMode; char pad14[12];
    D2SeedStrc pSeed; char pad28[56]; D2InventoryStrc* pInventory;
};
struct D2GameStrc { char pad00[112]; int bExpansion; };
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc*); // 0x00554010
void __fastcall sub_005347C0_Stub6(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, const char*); // 0x005347C0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc*, D2InventoryStrc*, int*, int, int); // 0x0064F380
int __stdcall UNITS_GetBlockRate(D2UnitStrc*, int); // 0x00622720
int __stdcall UNITS_IsInMovingMode(D2UnitStrc*); // 0x00622D00

struct D2StatStrc
{
    unsigned short nLayer;
    unsigned short nStat;
    int nValue;
};

int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize);     // 0x006261D0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0

static __declspec(noinline) int sub_0057DCA0_GetWieldedTypeStatMax(D2UnitStrc* pUnit);

// 0x0057DCA0
static int sub_0057DCA0_GetWieldedTypeStatMax(D2UnitStrc* pUnit)
{
    int i;
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightItem = 0;
    D2UnitStrc* pLeftItem = 0;
    if (pInventory)
    {
        pRightItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        pLeftItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    }

    D2StatStrc aStats[0x20];
    const int nCount = STATLIST_CopyStats(pUnit, 0x15C, aStats, 0x20);
    int nBest = 0;
    for (i = 0; i < nCount; ++i)
    {
        const int nItemType = aStats[i].nLayer;
        const int nValue = aStats[i].nValue;
        if (nItemType <= 0)
        {
            nBest = nValue;
        }
        else if (pLeftItem && ITEMS_CheckItemTypeId(pLeftItem, nItemType))
        {
            if (nValue > nBest)
            {
                nBest = nValue;
            }
        }
        else if (pRightItem && ITEMS_CheckItemTypeId(pRightItem, nItemType))
        {
            if (nValue > nBest)
            {
                nBest = nValue;
            }
        }
    }

    return nBest;
}

// build: context SEED_RollRandomNumber
static __forceinline unsigned __int64 __fastcall SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5ui64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static __declspec(noinline) int __stdcall SUNITDMG_ApplyDodge(D2UnitStrc*, D2UnitStrc*, int);

// 0x0057DD60
static int __stdcall SUNITDMG_ApplyDodge(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bAvoid)
{
    int nResult = 0;
    if (pDefender && pDefender->dwUnitType == 0)
    {
        if (pDefender->dwAnimMode == 3 || pDefender->dwAnimMode == 2)
        {
            const int nEvade = STATLIST_UnitGetStatValue(pDefender, 340, 0);
            if (nEvade > 0)
            {
                const int nRand = (unsigned int)SEED_RollRandomNumber(&pDefender->pSeed) % 100;
                sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nEvade, nRand, "evades");
                if (nRand < nEvade)
                {
                    nResult = 8;
                }
            }
            return nResult;
        }

        const int nWeaponBlock = sub_0057DCA0_GetWieldedTypeStatMax(pDefender);
        if (nWeaponBlock > 0)
        {
            int nWeaponClassId;
            COMPOSIT_GetWeaponClassId(pDefender, pDefender->pInventory, &nWeaponClassId, -1, 1);
            if (nWeaponClassId == 13)
            {
                const int nRand = SEED_RollLimitedRandomNumber(&pDefender->pSeed, 100);
                sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nWeaponBlock, nRand, "block");
                if (nRand < nWeaponBlock)
                {
                    return 16;
                }
            }
        }
        if (!bAvoid)
        {
            const int nDodge = STATLIST_UnitGetStatValue(pDefender, 338, 0);
            if (nDodge > 0)
            {
                const int nRand = SEED_RollLimitedRandomNumber(&pDefender->pSeed, 100);
                sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nDodge, nRand, "dodges");
                if (nRand < nDodge)
                {
                    return 4;
                }
            }
        }
        else
        {
            const int nAvoid = STATLIST_UnitGetStatValue(pDefender, 339, 0);
            if (nAvoid > 0)
            {
                const int nRand = SEED_RollLimitedRandomNumber(&pDefender->pSeed, 100);
                sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nAvoid, nRand, "avoids");
                if (nRand < nAvoid)
                {
                    return 2;
                }
            }
        }
    }
    else
    {
        const int bMoving = pDefender && (pDefender->dwAnimMode == 15 || pDefender->dwAnimMode == 2);
        if (!bMoving)
        {
            const int nWeaponBlock = sub_0057DCA0_GetWieldedTypeStatMax(pDefender);
            if (nWeaponBlock > 0)
            {
                int nWeaponClassId;
                COMPOSIT_GetWeaponClassId(pDefender, pDefender->pInventory, &nWeaponClassId, -1, 1);
                if (nWeaponClassId == 13)
                {
                    const int nRand = SEED_RollLimitedRandomNumber(&pDefender->pSeed, 100);
                    sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nWeaponBlock, nRand, "block");
                    if (nRand < nWeaponBlock)
                    {
                        return 16;
                    }
                }
            }
            if (!bAvoid)
            {
                const int nDodge = STATLIST_UnitGetStatValue(pDefender, 338, 0);
                if (nDodge > 0)
                {
                    const int nRand = SEED_RollLimitedRandomNumber(&pDefender->pSeed, 100);
                    sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nDodge, nRand, "dodges");
                    if (nRand < nDodge)
                    {
                        return 4;
                    }
                }
            }
            else
            {
                const int nAvoid = STATLIST_UnitGetStatValue(pDefender, 339, 0);
                if (nAvoid > 0)
                {
                    const int nRand = SEED_RollLimitedRandomNumber(&pDefender->pSeed, 100);
                    sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nAvoid, nRand, "avoids");
                    if (nRand < nAvoid)
                    {
                        return 2;
                    }
                }
            }
        }
        else
        {
            const int nEvade = STATLIST_UnitGetStatValue(pDefender, 340, 0);
            if (nEvade > 0)
            {
                const int nRand = (unsigned int)SEED_RollRandomNumber(&pDefender->pSeed) % 100;
                sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nEvade, nRand, "evades");
                if (nRand < nEvade)
                {
                    nResult = 8;
                }
            }
            return nResult;
        }
    }

    return 0;
}

// 0x0057DFB0
int __fastcall SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bAvoid, int bBlock)
{
    if (!bBlock) return SUNITDMG_ApplyDodge(pAttacker, pDefender, bAvoid);
    int nBlockChance = UNITS_GetBlockRate(pDefender, pGame->bExpansion);
    if (nBlockChance <= 0) return SUNITDMG_ApplyDodge(pAttacker, pDefender, bAvoid);
    if (pDefender && pDefender->dwUnitType == 0 && UNITS_IsInMovingMode(pDefender) && pDefender->dwAnimMode != 2)
        nBlockChance /= 3;
    unsigned __int64 nSeed = pDefender->pSeed.nHighSeed + 0x6AC690C5ui64 * pDefender->pSeed.nLowSeed;
    pDefender->pSeed.nHighSeed = (unsigned int)(nSeed >> 32);
    pDefender->pSeed.nLowSeed = (unsigned int)nSeed;
    const int nRand = (unsigned int)nSeed % 100;
    sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nBlockChance, nRand, "blocks");
    if (nRand >= nBlockChance) return SUNITDMG_ApplyDodge(pAttacker, pDefender, bAvoid);
    return 1;
}
