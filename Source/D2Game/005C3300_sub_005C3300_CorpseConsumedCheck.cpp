struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __stdcall D2COMMON_11017_CheckUnitIfConsumeable(D2UnitStrc* pUnit, int a2); // 0x00645510
int __fastcall SKILLS_CanSwitchAi(D2UnitStrc* pUnit, int nAiSpecialState); // 0x0056E2F0

static __declspec(noinline) int sub_005C3300_CorpseConsumedCheck(D2UnitStrc* pUnit);

// 0x005C3300
static int sub_005C3300_CorpseConsumedCheck(D2UnitStrc* pUnit)
{
    if ((pUnit ? pUnit->dwUnitType : 6) != 1)
    {
        return 0;
    }

    if (!sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, 8))
    {
        return 0;
    }

    if (!SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    if (!D2COMMON_11017_CheckUnitIfConsumeable(pUnit, 0))
    {
        return 0;
    }

    return SKILLS_CanSwitchAi(pUnit, 7) != 0;
}

// build: context sub_005C3300_Shim

// calling-convention shim (not game code)
int __fastcall sub_005C3300_Shim(D2UnitStrc* pUnit)
{
    return sub_005C3300_CorpseConsumedCheck(pUnit);
}
