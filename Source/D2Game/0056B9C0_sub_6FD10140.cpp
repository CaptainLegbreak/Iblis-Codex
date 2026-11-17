struct D2GameStrc;
struct D2InventoryStrc;
struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x5C];
    D2InventoryStrc* pInventory;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
};

D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit);                                                     // 0x00535BC0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
int __fastcall sub_6FD11340(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);                       // 0x0056C310
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
int __fastcall SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4, int a5); // 0x0057DFB0
void __fastcall D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005A5560
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                    // 0x006289F0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0
int __stdcall D2Common_11024(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType, int* pHasThrowBonus); // 0x00645720

#define UNIT_PLAYER 0
#define UNIT_MISSILE 3
#define ITEMTYPE_BOW 27
#define ITEMTYPE_CROSSBOW 35
#define BODYLOC_RARM 4
#define BODYLOC_LARM 5
#define STAT_TOHIT 19
#define STAT_DAMAGEPERCENT 25
#define STAT_ITEM_THROWABLE 125
#define STATE_UNINTERRUPTABLE 0x36
#define DAMAGERESULTFLAG_SUCCESSFULHIT 1

// 0x0056B9C0
void __fastcall sub_6FD10140(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nUnused)
{
    if (!pAttacker)
    {
        return;
    }

    if (!pUnit)
    {
        return;
    }

    if (pAttacker->dwUnitType == UNIT_MISSILE)
    {
        D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pAttacker);
        if (pOwner)
        {
            pAttacker = pOwner;
        }
    }

    if ((pDamage->wResultFlags == 0) & 1)
    {
        return;
    }

    const int nBlockFlags = SUNITDMG_ApplyBlockOrDodge(pGame, pAttacker, pUnit, 1, 0);
    if (nBlockFlags & 2)
    {
        pDamage->wResultFlags |= 0x100;
    }

    if (nBlockFlags & 4)
    {
        pDamage->wResultFlags |= 0x80;
    }

    if (nBlockFlags & 0x10)
    {
        pDamage->wResultFlags |= 0x8000;
    }

    if (nBlockFlags & 1)
    {
        pDamage->wResultFlags |= 0x10;
    }

    if (nBlockFlags)
    {
        pDamage->wResultFlags &= ~DAMAGERESULTFLAG_SUCCESSFULHIT;
    }

    if (pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT && !STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        pDamage->wResultFlags |= 4;
    }

    D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(pAttacker, pUnit, pDamage);

    if (pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, pDamage);
    }

    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, pDamage);
}

// 0x0056C3F0
int __fastcall sub_6FD118C0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2UnitStrc* pWeapon = sub_6FC7C7B0(pUnit);
        int bNoBow = 1;

        if (ITEMS_CheckItemTypeId(pWeapon, ITEMTYPE_BOW) || ITEMS_CheckItemTypeId(pWeapon, ITEMTYPE_CROSSBOW))
        {
            bNoBow = 0;
        }

        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
        if (pItem && (!bNoBow || pItem == pWeapon) && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0)))
        {
            return sub_6FD11340(pGame, pUnit, pItem);
        }

        pItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
        if (pItem && (!bNoBow || pItem == pWeapon) && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0)))
        {
            return sub_6FD11340(pGame, pUnit, pItem);
        }
    }

    return 0;
}

// 0x0056C600
void __fastcall sub_0056C600_ApplyWeaponBonusToMissile(D2UnitStrc* pUnit, D2UnitStrc* pMissile, D2UnitStrc* pWeapon)
{
    if (pUnit && pMissile && pWeapon)
    {
        const int nToHit = STATLIST_UnitGetStatValue(pMissile, STAT_TOHIT, 0);
        const int nToHitBonus = D2Common_11024(pUnit, pWeapon, 0, 0, 0);
        STATLIST_SetUnitStat(pMissile, STAT_TOHIT, nToHitBonus + nToHit, 0);
        const int nDamageBonus = D2Common_11024(pUnit, pWeapon, 0, 1, 0);
        STATLIST_AddUnitStat(pMissile, STAT_DAMAGEPERCENT, nDamageBonus, 0);
    }
}
