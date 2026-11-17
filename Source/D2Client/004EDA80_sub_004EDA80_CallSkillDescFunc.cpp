struct D2UnitStrc;
struct D2SkillStrc;

struct D2SkillsTxt
{
    short nSkillId;
};

struct D2SkillDescTxt
{
    char unk0x00[0x14];
    unsigned short wDescFunc;
};

typedef void (__fastcall* SKILLDESCFN)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4);

D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId);                                        // 0x004A89D0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0

extern SKILLDESCFN gpfSkillDescFuncs_0072D7F8[];                                                            // 0x0072D7F8

// 0x004EDA80
int __fastcall sub_004EDA80_CallSkillDescFunc(D2UnitStrc* pUnit, int bLeft)
{
    if (!pUnit)
    {
        return 0;
    }

    D2SkillStrc* pSkill;
    if (bLeft)
    {
        pSkill = UNITS_GetLeftSkill(pUnit);
    }
    else
    {
        pSkill = UNITS_GetRightSkill(pUnit);
    }

    D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxt)
    {
        return 0;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(pSkillsTxt->nSkillId);
    if (!pSkillDescTxt)
    {
        return 0;
    }

    int nValue1 = 0;
    int nValue2;
    int nValue3 = 0;
    int nValue4;
    if (pSkillDescTxt->wDescFunc < 72 && gpfSkillDescFuncs_0072D7F8[pSkillDescTxt->wDescFunc])
    {
        const int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
        gpfSkillDescFuncs_0072D7F8[pSkillDescTxt->wDescFunc](pUnit, pSkill, pSkillsTxt, nLevel, &nValue1, &nValue2, &nValue3, &nValue4);
    }

    return nValue1;
}

#include "gen/data/Source/D2Client/004EDA80_sub_004EDA80_CallSkillDescFunc.inc"
