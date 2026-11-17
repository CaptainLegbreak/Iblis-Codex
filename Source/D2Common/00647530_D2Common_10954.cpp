struct D2UnitStrc;

void __stdcall sub_00647320_UpdateChargedSkill(D2UnitStrc* pUnit, int nOwnerGUID, int nSkillId, int nSkillLevel, int nCharges, int bFreeMemory); // 0x00647320

// 0x00647530
void __stdcall D2Common_10954(D2UnitStrc* pUnit, int nOwnerGUID, int nSkillId, int nSkillLevel, int nCharges, int bFreeMemory)
{
    sub_00647320_UpdateChargedSkill(pUnit, nOwnerGUID, nSkillId, nSkillLevel, nCharges, bFreeMemory);
}
