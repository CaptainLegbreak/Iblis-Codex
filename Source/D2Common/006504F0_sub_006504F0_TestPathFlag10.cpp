struct D2DynamicPathStrc
{
    char unk0x00[0x34];
    unsigned int dwFlags;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC4 - 0x04];
    unsigned int dwFlags;
};

static __forceinline int UNITS_IsServerSide(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
    {
        bResult = (pUnit->dwFlags >> 21) & 1;
    }
    return bResult;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

// 0x006504F0
int __fastcall sub_006504F0_TestPathFlag10(D2UnitStrc* pUnit, D2DynamicPathStrc* pPath)
{
    switch (sub_0044BE50(pUnit))
    {
    case 0:
        if (!(pPath->dwFlags & 0x10))
        {
            return 0;
        }
        break;

    case 1:
        if (pPath->dwFlags & 0x10)
        {
            if (!UNITS_IsServerSide(pUnit))
            {
                return 0;
            }
        }
        break;
    }

    return 1;
}
