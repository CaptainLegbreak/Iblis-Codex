struct D2UnitStrc
{
    int dwUnitType;
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

// 0x005A0E40
void __fastcall sub_005A0E40_IncreaseMonsterLevelAndExperience(D2UnitStrc* pUnit, void* unused, void* context)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        const int nLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
        STATLIST_SetUnitStat(pUnit, 12, nLevel + 3, 0);
        const int nExperience = STATLIST_GetUnitBaseStat(pUnit, 13, 0);
        STATLIST_SetUnitStat(pUnit, 13, 5 * nExperience, 0);
    }
}
