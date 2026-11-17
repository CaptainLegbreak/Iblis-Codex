struct D2SkillsTxt00643D00Strc
{
    short nSkillId;
    unsigned char unk_02[0x11];
    unsigned char nValue13;
};
struct D2Skill00643D00Strc
{
    D2SkillsTxt00643D00Strc* pSkillsTxt;
};
struct D2Owner00643D00Strc
{
    int bMonster;
    int nMonsterId;
};
struct D2MonStatsTxt
{
    unsigned char unk_000[0x170];
    short nSkill[8];
    unsigned char unk_180[0x8];
    short nSkillLevel[8];
};
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

// 0x00643D00
int __fastcall sub_00643D00_GetSkillLevel(D2Owner00643D00Strc* pOwner, D2Skill00643D00Strc* pSkill)
{
    if (!pOwner || !pSkill)
    {
        return 0;
    }
    const int bMonster = pOwner ? pOwner->bMonster : 6;
    const int nMonsterId = pOwner->nMonsterId;
    if (!bMonster)
    {
        return pSkill->pSkillsTxt->nValue13;
    }
    const int nSkillId = pSkill->pSkillsTxt->nSkillId;
    if (nSkillId == 199)
    {
        return 0;
    }
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    for (int i = 0; i < 8; ++i)
    {
        if (pMonStatsTxtRecord->nSkill[i] == nSkillId)
        {
            return pMonStatsTxtRecord->nSkillLevel[i];
        }
    }
    return 0;
}
