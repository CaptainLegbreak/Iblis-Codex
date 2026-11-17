struct D2MonStatsTxt;
struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
};
extern "C" int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __fastcall UNITS_CanSwitchAI(int nMonsterId); // 0x00623470
int __fastcall sub_00451F30_HasFlags(D2UnitStrc* pUnit, unsigned int nFlags); // 0x00451F30
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall sub_005A0180_HasMask(D2UnitStrc* pUnit, unsigned short wMask); // 0x005A0180
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __fastcall AITHINK_CanUnitSwitchAi(D2UnitStrc* pUnit, D2MonStatsTxt* pMonStatsTxtRecord, int nAiMode, int a4); // 0x005B0DA0

// 0x005DD480
int __fastcall sub_005DD480_CanSwitchAiMode(D2UnitStrc* pUnit, int nAiMode)
{
    if (!pUnit)
    {
        return 0;
    }
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return 0;
    }
    if (nAiMode > 0x13)
    {
        return 0;
    }
    if (STATES_CheckState(pUnit, 0x36))
    {
        return 0;
    }
    if (!UNITS_CanSwitchAI(pUnit->dwClassId))
    {
        return 0;
    }
    if (!sub_00451F30_HasFlags(pUnit, 4) && !SUNIT_IsDead(pUnit))
    {
        return 0;
    }
    if (sub_005A0180_HasMask(pUnit, 10))
    {
        return 0;
    }
    if (nAiMode != 0x13)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (!AITHINK_CanUnitSwitchAi(pUnit, pMonStatsTxtRecord, nAiMode, 1))
        {
            return 0;
        }
    }
    return 1;
}
