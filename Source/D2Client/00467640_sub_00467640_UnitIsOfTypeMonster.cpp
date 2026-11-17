struct SGAMEDATA;

struct D2UnitStrc
{
    int dwUnitType;
};

// 0x00467640
int __fastcall sub_00467640_UnitIsOfTypeMonster(D2UnitStrc* pUnit, SGAMEDATA* pGame)
{
    if ((pUnit ? pUnit->dwUnitType : 6) != 1)
    {
        return 0;
    }
    return 1;
}
