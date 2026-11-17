#include "D2Game.h"

struct D2UnitStrc { int dwUnitType; };
struct D2DamageStrc { char unk_00[0x4C]; int dwDmgTotal; };
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int nUnused); // 0x00621E40
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

static __forceinline int GetUnitType(const D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

// 0x005BFBB0
int __fastcall sub_005BFBB0_DamageToMana(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || GetUnitType(pAttacker) != 0)
    {
        return 0;
    }
    if (!pDamage)
    {
        return 0;
    }

    if (pDamage->dwDmgTotal <= 0)
    {
        return 0;
    }
    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nValue <= 0)
        return 0;
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pAttacker);
    int nMana = STATLIST_UnitGetStatValue(pAttacker, 8, 0);
    if (nMana >= nMaxMana)
        return 0;
    int nNewMana = DATATBLS_ApplyRatio(pDamage->dwDmgTotal, nValue, 100) + nMana;
    nNewMana = nNewMana > 0 ? nNewMana : 0;
    STATLIST_SetUnitStat(pAttacker, 8, nNewMana < nMaxMana ? nNewMana : nMaxMana, 0);
    UNITS_SetOverlay(pAttacker, 152, 0);
    return 1;
}
