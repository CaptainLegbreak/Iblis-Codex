struct D2UnitStrc
{
    char unk0x000[0xC4];
    unsigned int dwFlags;
};
struct D2SkillsTxt
{
    char unk0x000[0xEA];
    short wCltMissileA;
    char unk0x0EC[0x4C];
    unsigned int dwCalc[4];
    char unk0x148[0xF4];
};
struct D2MissilesTxt
{
    char unk0x000[0x38];
    int dwParam[2];
    char unk0x040[0x164];
};
struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
};
struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[9];
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const int gnOffsetsX_006DBAF8[16]; // 0x006DBAF8
extern const int gnOffsetsY_006DBAB8[16]; // 0x006DBAB8
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540

static __forceinline D2SkillsTxt* GetSkillsRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}
static __forceinline D2MissilesTxt* GetMissilesRecord(int nMissile)
{
    if (nMissile >= 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissile];
    return 0;
}

// 0x004E1770
int __fastcall sub_004E1770_SpawnSkillMissileRing(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2MissileStrc missileParams;
    D2SkillsTxt* pSkillsTxt = GetSkillsRecord(nSkillId);
    if (!pSkillsTxt)
        return 0;
    int nMissile = pSkillsTxt->wCltMissileA;
    D2MissilesTxt* pMissilesTxt = 0;
    if (nMissile >= 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
        pMissilesTxt = &sgptDataTables->pMissilesTxt[nMissile];
    if (pMissilesTxt)
    {
    if (pUnit)
        pUnit->dwFlags |= 0x40;

    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x1F;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nMissile = nMissile;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nLoops = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    missileParams.nVelocity = pMissilesTxt->dwParam[0] << 6;
    int nStep = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[1], nSkillId, nSkillLevel);
    if (nStep < 1)
        nStep = 1;
    for (int i = 0; i < 16; i += 2)
    {
        missileParams.nTargetX = gnOffsetsX_006DBAF8[i];
        missileParams.nTargetY = gnOffsetsY_006DBAB8[i];
        sub_004CD540_CreateMissile(&missileParams);
    }
    missileParams.nVelocity = pMissilesTxt->dwParam[1] << 6;
    if (nStep > 1)
    {
        for (int i = 0; i < 15; i += nStep)
        {
            missileParams.nTargetX = gnOffsetsX_006DBAF8[i + 1];
            missileParams.nTargetY = gnOffsetsY_006DBAB8[i + 1];
            sub_004CD540_CreateMissile(&missileParams);
        }
    }
    return 1;
    }
    return 0;
}

#include "gen/data/Source/D2Client/004E1770_sub_004E1770_SpawnSkillMissileRing.inc"
