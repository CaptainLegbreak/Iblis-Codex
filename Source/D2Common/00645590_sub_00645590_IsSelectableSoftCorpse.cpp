struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[2];
    int dwAnimMode;
};

#define UNIT_MONSTER 1
#define MONMODE_DEAD 12
#define MONSTATS2FLAGINDEX_CORPSESEL 7

int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A770
int __stdcall UNITS_IsSoftMonster(D2UnitStrc* pUnit);                                                       // 0x00621F60

static __forceinline int CORPSE_CanUnitCorpseBeSelected(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_DEAD && !STATES_CheckStateMaskUdeadOnUnit(pUnit))
    {
        if (sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, MONSTATS2FLAGINDEX_CORPSESEL))
            return 1;
    }
    return 0;
}

// 0x00645590
int __stdcall sub_00645590_IsSelectableSoftCorpse(D2UnitStrc* pUnit)
{
    if (!CORPSE_CanUnitCorpseBeSelected(pUnit))
        return 0;
    return UNITS_IsSoftMonster(pUnit) != 0;
}

// 0x00645630
int __stdcall sub_00645630_IsSelectableSoftCorpse(D2UnitStrc* pUnit)
{
    if (!CORPSE_CanUnitCorpseBeSelected(pUnit))
        return 0;
    return UNITS_IsSoftMonster(pUnit) != 0;
}
