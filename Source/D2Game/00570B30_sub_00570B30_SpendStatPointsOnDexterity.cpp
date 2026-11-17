struct D2UnitStrc;

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040

static __declspec(noinline) void sub_00570B30_SpendStatPointsOnDexterity(D2UnitStrc* pUnit, int nValue);

// 0x00570B30
static void sub_00570B30_SpendStatPointsOnDexterity(D2UnitStrc* pUnit, int nValue)
{
    if (nValue)
    {
        STATLIST_AddUnitStat(pUnit, 4, -nValue, 0);
        STATLIST_AddUnitStat(pUnit, 2, nValue, 0);
        UNITROOM_RefreshUnit(pUnit);
    }
}

void __fastcall sub_C899_Emit_00570B30(D2UnitStrc* pUnit, int nValue)
{
    sub_00570B30_SpendStatPointsOnDexterity(pUnit, nValue);
    sub_00570B30_SpendStatPointsOnDexterity(pUnit, nValue + 1);
}
