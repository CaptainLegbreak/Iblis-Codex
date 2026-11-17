struct D2UnitStrc;

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

// 0x00644150
int __stdcall SKILLS_GetShrineSkillLevelBonus(D2UnitStrc* pUnit)
{
    int nBonus = 0;
    if (STATES_CheckState(pUnit, 134))
    {
        nBonus += 2;
    }

    return nBonus;
}
