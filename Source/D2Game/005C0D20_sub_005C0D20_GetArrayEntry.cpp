struct D2SkillPairStrc
{
    int nA;
    int nB;
};

// 0x005C0D20
static D2SkillPairStrc* __stdcall sub_005C0D20_GetArrayEntry(int nCount, D2SkillPairStrc* pArray, int nIndex)
{
    if (nIndex >= nCount)
    {
        return 0;
    }
    return &pArray[nIndex];
}

D2SkillPairStrc* __stdcall sub_K13_Emit_005C0D20(D2SkillPairStrc* pArray, int nIndex, int nCount)
{
    return sub_005C0D20_GetArrayEntry(nCount, pArray, nIndex);
}
