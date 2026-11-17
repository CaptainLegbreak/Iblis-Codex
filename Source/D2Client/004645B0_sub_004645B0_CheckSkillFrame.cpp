struct D2SkillStrc;

struct D2UnitStrc
{
    char unk0x00[0x38];
    int nFrame;
};

struct D2SkillsTxt
{
    char unk0x00[0x10];
    unsigned char nAnim;
    char unk0x11[0x5];
    unsigned char nFrame;
};

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140

// 0x004645B0
static int __stdcall sub_004645B0_CheckSkillFrame(int nUnused, D2UnitStrc* pUnit);

static __declspec(noinline) int __stdcall sub_004645B0_CheckSkillFrame(int nUnused, D2UnitStrc* pUnit)
{
    int* pDead = &nUnused;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAnim != 0x12)
    {
        return 1;
    }

    const unsigned char nFrame = pSkillsTxtRecord->nFrame;
    if (!nFrame)
    {
        return 0;
    }

    if (nFrame == 0xFF)
    {
        return 0;
    }

    return (pUnit->nFrame >> 8) >= nFrame;
}

int __fastcall sub_Emit_004645B0(D2UnitStrc* pUnit, int nArg)
{
    return sub_004645B0_CheckSkillFrame(nArg, pUnit);
}
