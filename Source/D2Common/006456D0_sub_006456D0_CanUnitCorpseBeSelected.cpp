struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x34];
    int dwFrameCountPrecise;
};

int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2);                                            // 0x00623990
int __stdcall ITEMS_GetWeaponAttackSpeed(D2UnitStrc* pUnit, D2UnitStrc* pItem);                             // 0x0062A710
int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit);                                                 // 0x0063A400
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A770

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define MONMODE_DEAD 12
#define MONSTATS2FLAGINDEX_CORPSESEL 7

// 0x006456D0
int __stdcall sub_006456D0_CanUnitCorpseBeSelected(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    const int bCorpseSelectable = (nUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_DEAD && !STATES_CheckStateMaskUdeadOnUnit(pUnit)) ? sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, MONSTATS2FLAGINDEX_CORPSESEL) : 0;
    if (!bCorpseSelectable)
    {
        return 0;
    }

    return 1;
}

// 0x00646170
unsigned int __stdcall D2Common_11043(D2UnitStrc* pUnit)
{
    D2UnitStrc* pItem = 0;
    int nAttackSpeed;

    int bShapeShifted = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        bShapeShifted = STATES_IsUnitShapeShifted(pUnit);
    }

    if (!bShapeShifted)
    {
        return 0;
    }

    nAttackSpeed = 19;
    pItem = D2Common_10434(pUnit, 0);
    if (pItem)
    {
        nAttackSpeed = ITEMS_GetWeaponAttackSpeed(pUnit, pItem);
        if (nAttackSpeed <= 0)
        {
            return 0;
        }
    }

    return (pUnit->dwFrameCountPrecise & ~0xFF) / nAttackSpeed;
}
