struct D2GameStrc;
struct D2DynamicPathStrc;
struct D2StaticPathStrc { int unk00[3]; int nX; int nY; };
struct D2UnitStrc { int dwUnitType; int dwClassId; int unk08[9]; union { D2DynamicPathStrc* pDynamicPath; D2StaticPathStrc* pStaticPath; }; };
struct D2MissilesTxt { char unk00[0x24]; short wHitSubMissile[4]; char unk2C[0x20]; int dwHitPar[3]; char unk58[0x30]; unsigned int dwHitCalc; char unk8C[0x1C]; unsigned int dwHitFlags; unsigned short wResultFlags; char unkAE[0xF6]; };
struct D2SkillsTxt { char unk00[0x138]; unsigned int dwCalc[4]; char unk148[0xF4]; };
struct D2DataTablesStrc { char unk000[0xB64]; D2MissilesTxt* pMissilesTxt; int unkB68; int nMissilesTxtRecordCount; char unkB70[0x28]; D2SkillsTxt* pSkillsTxt; int unkB9C; int nSkillsTxtRecordCount; };
struct D2DamageStrc { unsigned int dwHitFlags; unsigned short wResultFlags; unsigned short wExtra; int unk08[26]; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc*, D2UnitStrc*); // 0x00552FD0
int __stdcall MISSILE_GetSkill(D2UnitStrc*); // 0x0064A280
int __stdcall MISSILE_GetLevel(D2UnitStrc*); // 0x0064A210
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc*, D2UnitStrc*, unsigned int, int, int); // 0x0064B7C0
void __fastcall sub_005A9530_CreateHitSubmissiles(D2GameStrc*, D2UnitStrc*, int, int, int); // 0x005A9530
int __fastcall MISSMODE_GetDamageValue(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2DamageStrc*); // 0x005A8C70
int __fastcall sub_0056BAD0_ApplyAreaDamage(D2GameStrc*, D2UnitStrc*, int, int, int, D2DamageStrc*, unsigned int); // 0x0056BAD0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
static D2MissilesTxt* GetMissilesTxt(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    return 0;
}
static D2SkillsTxt* SkillsRecordFor(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}
static int GetX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case 2: case 4: case 5: return pUnit->pStaticPath->nX; }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}
static int GetY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case 2: case 4: case 5: return pUnit->pStaticPath->nY; }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}
// 0x005AA250
int __fastcall sub_005AA250_ApplyHitExplosion(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxt(pMissile);
    if (!pMissilesTxtRecord) return 1;
    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SkillsRecordFor(nSkillId);
    if (!pSkillsTxtRecord) return 1;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (pMissilesTxtRecord->wHitSubMissile[0] >= 0)
    {
        STATLIST_SetUnitStat(pMissile, 0x38, 0, 0);
        STATLIST_SetUnitStat(pMissile, 0x86, 0, 0);
        int nCount = pMissilesTxtRecord->dwHitPar[0];
        if (nCount <= 0)
        {
            nCount = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
            if (nCount < 1) nCount = 1;
        }
        const int nValue = MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwHitCalc, !pMissile ? -1 : pMissile->dwClassId, nLevel);
        sub_005A9530_CreateHitSubmissiles(pGame, pMissile, nCount, pMissilesTxtRecord->wHitSubMissile[0], nValue);
    }
    int nRange = pMissilesTxtRecord->dwHitPar[1];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[1], nSkillId, nLevel);
        if (nRange < 1) nRange = 1;
    }
    D2DamageStrc damage = {};
    MISSMODE_GetDamageValue(pGame, pMissile, pUnit, &damage);
    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;
    sub_0056BAD0_ApplyAreaDamage(pGame, SUNIT_GetOwner(pGame, pMissile), GetX(pMissile), GetY(pMissile), nRange, &damage, 0);
    return 3;
}
