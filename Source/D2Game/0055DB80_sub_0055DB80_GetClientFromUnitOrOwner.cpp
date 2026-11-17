struct D2ClientStrc;

struct D2UnitStrc
{
    int dwUnitType;
};

enum
{
    UNIT_PLAYER = 0,
};

D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0

// 0x0055DB80
D2ClientStrc* __fastcall sub_0055DB80_GetClientFromUnitOrOwner(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        return SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xA44);
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
    {
        return SUNIT_GetClientFromPlayer(pOwner, ".\\ITEMS\\ItemMode.cpp", 0xA49);
    }

    return 0;
}
