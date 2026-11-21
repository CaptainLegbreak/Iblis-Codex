#include "D2Game.h"
#include "D2GameTypes.h"

#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define STAT_STAMINA 10

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260


int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

// 0x0057A950
static __forceinline void sub_0057A950_DrainLife(D2UnitStrc* pUnit, int nDrain)
{
    if (nDrain > 0)
    {
        int nLife = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) - nDrain;
        if (nLife < DRAIN_MIN)
        {
            nLife = 0;
        }
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nLife, 0);
    }
}

void __fastcall sub_M120_Emit_0057A950(D2UnitStrc* pUnit, int nDrain)
{
    sub_0057A950_DrainLife(pUnit, nDrain);
}

// 0x0057A980
static __declspec(noinline) int __stdcall SUNITDMG_AddLeechedLife(D2UnitStrc* pUnit, int nLifeLeeched)
{
    if (nLifeLeeched <= 0)
    {
        return 0;
    }

    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, STATE_DEATH_DELAY))
    {
        return 0;
    }

    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    const int nHp = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const int nNewHp = (nHp + nLifeLeeched < nMaxHp) ? nHp + nLifeLeeched : nMaxHp;
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewHp, 0);

    if (nNewHp != nMaxHp)
    {
        return nLifeLeeched;
    }

    return nMaxHp - nHp;
}

// 0x0057AA00
static __declspec(noinline) int __stdcall SUNITDMG_AddLeechedMana(D2UnitStrc* pUnit, int nManaLeeched)
{
    if (nManaLeeched <= 0)
    {
        return 0;
    }

    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    const int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    const int nNewMana = (nMana + nManaLeeched < nMaxMana) ? nMana + nManaLeeched : nMaxMana;
    STATLIST_SetUnitStat(pUnit, STAT_MANA, nNewMana, 0);

    if (nNewMana != nMaxMana)
    {
        return nManaLeeched;
    }

    return nMaxMana - nMana;
}

// 0x0057AA60
static __declspec(noinline) int sub_0057AA60_DrainMana(D2UnitStrc* pUnit, int nDrain)
{
    if (nDrain <= 0)
    {
        return 0;
    }

    int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) - nDrain;
    if (nMana < DRAIN_MIN)
    {
        nMana = 0;
    }

    STATLIST_SetUnitStat(pUnit, STAT_MANA, nMana, 0);
    return nMana ? nDrain : 0;
}

// 0x0057AAA0
static __declspec(noinline) int sub_0057AAA0_DrainStamina(D2UnitStrc* pUnit, int nDrain)
{
    if (nDrain <= 0)
    {
        return 0;
    }

    int nStamina = STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) - nDrain;
    if (nStamina < 0 || nStamina < DRAIN_MIN)
    {
        nStamina = 0;
    }

    STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nStamina, 0);
    return nStamina ? nDrain : 0;
}

void __fastcall sub_A13_Emit_0057C6C0(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    SUNITDMG_AddLeechedLife(pAttacker, pDamage->dwColdLen);
    SUNITDMG_AddLeechedMana(pAttacker, pDamage->dwFrzLen);
    sub_0057AA60_DrainMana(pDefender, pDamage->dwLifeLeech);
    sub_0057AAA0_DrainStamina(pDefender, pDamage->dwManaLeech);
}
