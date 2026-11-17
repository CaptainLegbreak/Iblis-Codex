struct D2UnitStrc;

unsigned int __cdecl sub_0044DA90();                                                                        // 0x0044DA90
void __fastcall sub_004AF890(D2UnitStrc* pUnit, int nArg1, int nArg2);                                      // 0x004AF890

unsigned int gdwNextTick_007C78B0;                                                                          // 0x007C78B0

// 0x004CA030
int __fastcall sub_004CA030_TickEvent(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const unsigned int nTick = sub_0044DA90();
    if (nTick > gdwNextTick_007C78B0)
    {
        gdwNextTick_007C78B0 = nTick + 5;
        sub_004AF890(pUnit, 1, 0);
    }
    return 1;
}
