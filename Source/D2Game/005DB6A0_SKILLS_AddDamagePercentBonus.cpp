struct D2UnitStrc;

#define STAT_DAMAGEPERCENT 25

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

// 0x005DB6A0
void __fastcall SKILLS_AddDamagePercentBonus(D2UnitStrc* pUnit, int nBonus)
{
    if (nBonus)
    {
        const int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0);
        STATLIST_SetUnitStat(pUnit, STAT_DAMAGEPERCENT, nValue + nBonus, 0);
    }
}
