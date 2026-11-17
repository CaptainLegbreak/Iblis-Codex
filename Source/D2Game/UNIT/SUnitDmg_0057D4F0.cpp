#include "D2Game.h"

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DamageStrc
{
    unsigned int wResultFlags;
    unsigned int dwHitFlags;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int dwAbsLife;
    int dwDmgTotal;
    int unk0x50;
    int dwPiercePct;
    int dwDamageRate;
    int unk0x5C;
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    char nConvType;
    unsigned char unk0x66;
    unsigned char unk0x67;
    int dwConvPct;
    int nOverlay;
};

struct D2CombatStrc
{
    D2GameStrc* pGame;
    int dwAttackerType;
    int dwAttackerId;
    int dwDefenderType;
    int dwDefenderId;
    D2DamageStrc tDamage;
    D2CombatStrc* pNext;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    void* f_14;
    int unk0x18;
    int unk0x1C;
    D2SeedStrc pSeed;
    int unk0x28[14];
    D2InventoryStrc* pInventory;
    int unk0x64[18];
    D2CombatStrc* pCombat;
};

struct D2BodyLocWeightStrc
{
    int nBodyLoc;
    int nWeight;
};

extern D2BodyLocWeightStrc gaBodyLocWeights_00732B90[];                                                     // 0x00732B90
extern int gnBodyLocWeightCount_00732BC8;                                                                   // 0x00732BC8

int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                  // 0x0045C3E0
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit);                                                     // 0x00535BC0
void __fastcall sub_00559E30_DamageItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);           // 0x00559E30
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057C9F0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
void __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nEvent, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage); // 0x005C0C30
void __fastcall SKILLS_ApplyThornsDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005D10C0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3);                                   // 0x00621E40
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40
unsigned int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit);                                               // 0x00623C20
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0

static __forceinline int SUNITDMG_IsInDeathMode(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType != UNIT_OBJECT)
    {
        switch (pUnit->dwUnitType)
        {
        case UNIT_PLAYER:
            if (pUnit->dwAnimMode == 0)
            {
                return 1;
            }
            break;
        case UNIT_MONSTER:
            if (pUnit->dwAnimMode == 0)
            {
                return 1;
            }
            break;
        }
    }
    return 0;
}

static void __stdcall sub_0057D3D0_DamageItems(D2UnitStrc* pAttacker, D2GameStrc* pGame, D2UnitStrc* pDefender)
{
    if (pAttacker && pAttacker->dwUnitType == UNIT_PLAYER)
    {
        D2UnitStrc* pWeapon = sub_6FC7C7B0(pAttacker);
        if (pWeapon)
        {
            sub_00559E30_DamageItem(pGame, pAttacker, pWeapon);
        }
    }

    if (!pDefender || pDefender->dwUnitType != UNIT_PLAYER || !pDefender->pInventory)
    {
        return;
    }

    D2InventoryStrc* pInventory = pDefender->pInventory;
    D2UnitStrc* pItems[7] = {};
    int nTotal = 0;
    for (int i = 0; i < gnBodyLocWeightCount_00732BC8; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, gaBodyLocWeights_00732B90[i].nBodyLoc);
        if (pItem && ITEMS_CheckItemTypeId(pItem, 0x32))
        {
            nTotal += gaBodyLocWeights_00732B90[i].nWeight;
            pItems[i] = pItem;
        }
    }

    if (nTotal <= 0)
    {
        return;
    }

    int nIndex = ITEMS_RollLimitedRandomNumber(&pDefender->pSeed, gnBodyLocWeightCount_00732BC8);
    int nRoll = ITEMS_RollLimitedRandomNumber(&pDefender->pSeed, nTotal);
    do
    {
        if (pItems[nIndex])
        {
            if (nRoll < gaBodyLocWeights_00732B90[nIndex].nWeight)
            {
                sub_00559E30_DamageItem(pGame, pDefender, pItems[nIndex]);
                return;
            }
            nRoll -= gaBodyLocWeights_00732B90[nIndex].nWeight;
        }
        nIndex = (nIndex + 1) % gnBodyLocWeightCount_00732BC8;
    }
    while (nRoll >= 0);
}

// 0x0057D4F0
void __fastcall sub_0057D4F0_ExecuteMeleeDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nUnused)
{
    if (!pAttacker || !pDefender)
    {
        return;
    }

    D2CombatStrc* pCombat = pAttacker->pCombat;
    while (pCombat)
    {
        if (pCombat->dwAttackerType == sub_0044BE50_GetUnitTypeOrInvalid(pAttacker) && pCombat->dwAttackerId == sub_00451F50_GetUnitGUID(pAttacker)
            && pCombat->dwDefenderType == sub_0044BE50_GetUnitTypeOrInvalid(pDefender) && pCombat->dwDefenderId == sub_00451F50_GetUnitGUID(pDefender))
        {
            break;
        }
        pCombat = pCombat->pNext;
    }

    if (!pCombat)
    {
        return;
    }

    const int nUnitType = pAttacker->dwUnitType;
    D2DamageStrc tDamage = pCombat->tDamage;
    if (UNITS_IsInMeleeRange(pAttacker, pDefender, nUnitType == UNIT_MONSTER ? 3 : 1))
    {
        if (tDamage.dwHitFlags & 1)
        {
            if (SUNITDMG_IsInDeathMode(pAttacker))
            {
                return;
            }

            tDamage.wResultFlags = 0x20;
            SUNITDMG_ExecuteEvents(pGame, pAttacker, pDefender, 0, &tDamage);
            if (tDamage.nOverlay > 0)
            {
                UNITS_SetOverlay(pDefender, tDamage.nOverlay, 0);
            }

            if (!tDamage.nHitClassActiveSet && !(tDamage.dwHitClass & 0xF))
            {
                tDamage.dwHitClass |= UNITS_GetHitClass(pAttacker);
            }

            sub_0057D3D0_DamageItems(pAttacker, pGame, pDefender);
        }

        SUNITEVENT_Trigger(pGame, 7, pAttacker, pDefender, &tDamage);
        SUNITEVENT_Trigger(pGame, 3, pDefender, pAttacker, &tDamage);
        if (tDamage.dwHitFlags & 1)
        {
            if (SUNITDMG_IsInDeathMode(pAttacker))
            {
                return;
            }

            SKILLS_ApplyThornsDamage(pGame, pAttacker, pDefender, &tDamage);
        }

        SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pDefender, &tDamage);
    }

    SUNITDMG_FreeAttackerDefenderCombatList(pGame, pAttacker, pDefender);
}

#include "gen/data/Source/D2Game/UNIT/SUnitDmg_0057D4F0.inc"
