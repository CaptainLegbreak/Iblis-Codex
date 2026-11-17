struct D2GameStrc;
struct D2DamageStrc;
struct D2UnitStrc { int dwUnitType; };
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int nUnused); // 0x00621E40

// 0x005C0130
int __fastcall sub_005C0130_RestoreManaAfterKill(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit || pAttacker->dwUnitType != 0)
        return 0;
    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
        return 0;
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pAttacker);
    int nMana = STATLIST_UnitGetStatValue(pAttacker, 8, 0);
    if (nMana >= nMaxMana)
        return 0;
    nMana += nValue << 8;
    nMana = nMana > 0 ? nMana : 0;
    STATLIST_SetUnitStat(pAttacker, 8, nMana < nMaxMana ? nMana : nMaxMana, 0);
    UNITS_SetOverlay(pAttacker, 152, 0);
    return 1;
}
