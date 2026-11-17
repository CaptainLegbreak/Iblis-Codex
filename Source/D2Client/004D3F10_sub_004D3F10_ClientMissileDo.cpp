struct D2SeedStrc;

struct D2MissilesTxtStrc
{
    char pad0[0x1E];
    short nMin;
    short nMax;
    char pad1[0x1A4 - 0x22];
};

struct D2SkillsTxtStrc
{
    char pad0[0x138];
    int nCalc1;
    int nCalc2;
    char pad1[0x23C - 0x140];
};

struct D2DataTablesStrc
{
    char pad0[0xB64];
    D2MissilesTxtStrc* pMissilesTxt;
    char padB68[4];
    int nMissilesTxtRecordCount;
    char padB70[0xB98 - 0xB70];
    D2SkillsTxtStrc* pSkillsTxt;
    char padB9C[4];
    int nSkillsTxtRecordCount;
};

struct D2UnitStrc
{
    int nUnitType;
    int nClassId;
    char pad08[0x18];
    int dwSeed;
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
D2UnitStrc* __fastcall sub_004CE320(D2UnitStrc* pMissile, int nArg1, int nArg2, int nArg3); // 0x004CE320
void __fastcall sub_004CE420(D2UnitStrc* pMissile); // 0x004CE420
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280
extern D2DataTablesStrc* sgptDataTables; // 0x00744304

// 0x004D3F10
void __fastcall sub_004D3F10_ClientMissileDo(D2UnitStrc* pMissile)
{
    struct { int nValue1; int nLevel; D2UnitStrc* pOwner; int nRange; } tLocal;
    D2MissilesTxtStrc* pMissilesTxt;
    if (pMissile && pMissile->nClassId >= 0 && pMissile->nClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        pMissilesTxt = &sgptDataTables->pMissilesTxt[pMissile->nClassId];
    }
    else
    {
        pMissilesTxt = 0;
    }
    if (!pMissilesTxt || pMissilesTxt->nMin < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    int nMin = pMissilesTxt->nMin;
    tLocal.nRange = nMin;
    if (nMin < pMissilesTxt->nMax)
    {
        tLocal.nRange = ITEMS_RollLimitedRandomNumber((D2SeedStrc*)&pMissile->dwSeed, pMissilesTxt->nMax - nMin + 1) + nMin;
    }

    int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxtStrc* pSkillsTxt;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxt = &sgptDataTables->pSkillsTxt[nSkillId];
    }
    else
    {
        pSkillsTxt = 0;
    }
    if (!pSkillsTxt)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    tLocal.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tLocal.nLevel = MISSILE_GetLevel(pMissile);
    tLocal.nValue1 = SKILLS_EvaluateSkillFormula(tLocal.pOwner, pSkillsTxt->nCalc1, nSkillId, tLocal.nLevel);
    int nValue2 = SKILLS_EvaluateSkillFormula(tLocal.pOwner, pSkillsTxt->nCalc2, nSkillId, tLocal.nLevel);
    if (nValue2 && tLocal.nValue1 > 0)
    {
        D2UnitStrc* pTarget = sub_004CE320(pMissile, tLocal.nValue1, nValue2, tLocal.nRange);
        if (pTarget)
        {
            sub_004CE420(pTarget);
        }
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }
    sub_004CD390_CltDoDefault(pMissile);
}
