struct D2UnitStrc;

D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType);              // 0x004639B0

char gbGlobal_007C0260;                                                                                     // 0x007C0260
extern unsigned int gnQuestUnitId_007C0261;                                                                 // 0x007C0261

// 0x004A3120
char __cdecl sub_004A3120_IsQuestUnitPresent()
{
    if (gbGlobal_007C0260 && sub_004639B0_FindServerSideUnit(gnQuestUnitId_007C0261, 1))
    {
        return 1;
    }
    return 0;
}
