// 0x00621450
static __forceinline int UNITS_IsAnimModeKnockBack(int nUnitType, int nAnimMode)
{
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 0x13)
            return 1;
        break;
    case 1:
        if (nAnimMode == 0x0D)
            return 1;
        break;
    }
    return 0;
}

// 0x00621480
static __forceinline int sub_00621480(int nAnimMode)
{
    switch (nAnimMode)
    {
    case 2:
    case 0x0F:
        return 1;
    }
    return 0;
}

// 0x00621680
static __forceinline int UNITS_IsAnimModeGetHit(int nUnitType, int nAnimMode)
{
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 4)
            return 1;
        break;
    case 1:
        if (nAnimMode == 3)
            return 1;
        break;
    }
    return 0;
}

int __stdcall sub_M110_Emit_00621450(int nUnitType, int nAnimMode)
{
    if (UNITS_IsAnimModeKnockBack(nUnitType, nAnimMode))
        return 7;
    if (UNITS_IsAnimModeGetHit(nUnitType, nAnimMode))
        return 9;
    return sub_00621480(nAnimMode);
}
