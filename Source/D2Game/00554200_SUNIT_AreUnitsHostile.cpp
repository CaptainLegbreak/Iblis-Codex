struct D2GameStrc;
struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x90];
    int dwOwnerType;
    int dwOwnerGUID;
    char unk0x9C[0x2C];
    unsigned int dwFlagEx;
};

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitId); // 0x00552F60
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nFlag); // 0x0055B300
int __stdcall STATLIST_AreUnitsAligned(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00650D70

#define UNITFLAGEX_STOREOWNERINFO 0x400

// build: context UNIT_HasFlagEx
inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// build: context sub_0044BE50
inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

// 0x00552FD0
__forceinline D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!UNIT_HasFlagEx(pUnit, UNITFLAGEX_STOREOWNERINFO))
    {
        return 0;
    }

    return SUNIT_GetServerUnit(pGame, pUnit->dwOwnerType, pUnit->dwOwnerGUID);
}

// 0x00554200
int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pUnit)
    {
        D2UnitStrc* pOwner = 0;
        if (pUnit->dwUnitType == 1)
        {
            pOwner = AIGENERAL_GetMinionOwner(pUnit);
        }
        else if (pUnit->dwUnitType == 3)
        {
            pOwner = SUNIT_GetOwner(pGame, pUnit);
        }

        if (pOwner)
        {
            pUnit = pOwner;
        }
    }

    D2UnitStrc* i = pTarget;
    while (sub_0044BE50(i) == 1)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(i);
        if (!pOwner || pOwner == i)
        {
            break;
        }

        i = pOwner;
    }

    if (pUnit == i)
    {
        return 0;
    }

    if (pUnit && pUnit->dwUnitType == 0 && i && i->dwUnitType == 0)
    {
        return PLAYERLIST_CheckFlag(pUnit, i, 8);
    }

    return STATLIST_AreUnitsAligned(pUnit, i) == 0;
}
