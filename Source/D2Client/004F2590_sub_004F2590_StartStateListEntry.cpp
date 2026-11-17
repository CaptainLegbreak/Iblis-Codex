struct D2UnitStrc;

int __fastcall sub_004F2450_StartStateList(D2UnitStrc* pUnit, int nSkillId, int nArg);                     // 0x004F2450

// 0x004F2590
int __fastcall sub_004F2590_StartStateListEntry(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    return sub_004F2450_StartStateList(pUnit, nSkillId, nArg);
}
