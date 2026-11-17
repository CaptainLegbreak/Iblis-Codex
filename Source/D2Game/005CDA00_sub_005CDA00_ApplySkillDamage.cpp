struct D2GameStrc;
struct D2SkillStrc;
struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2UnitStrc { char unk_00[0x20]; D2SeedStrc pSeed; char unk_28[0x20]; unsigned int dwFrame; };
struct D2SkillsTxt { char unk_000[0x140]; unsigned int f_13C; int unk_144; int nAnimFrame; char unk_14C[0xF0]; };
struct D2DataTablesStrc { char unk_000[0xB98]; D2SkillsTxt* pSkillsTxt; int unk_B9C; int nSkillsTxtRecordCount; };
struct D2DamageStrc {
    unsigned int dwHitFlags; unsigned short wResultFlags; unsigned short wExtra;
    int dwPhysDamage; int unk_0C; int unk_10; int unk_14; int unk_18; int unk_1C;
    int unk_20; int unk_24; int dwPoisonDamage; int dwPoisonLength; int unk_30; int unk_34;
    int unk_38; int dwManaLeech; int dwStaminaLeech; int unk_44; int unk_48; int unk_4C;
    int unk_50; int unk_54; int unk_58; int unk_5C; int unk_60; int unk_64; int unk_68; int unk_6C;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc*); // 0x00620250
int __stdcall SKILLS_GetParam1(D2SkillStrc*); // 0x006444A0
int __stdcall SKILLS_GetParam2(D2SkillStrc*); // 0x006444D0
int __stdcall SKILLS_GetParam3(D2SkillStrc*); // 0x00644500
void __stdcall SKILLS_SetParam1(D2SkillStrc*, int); // 0x00644560
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc*, D2UnitStrc*, int); // 0x00622C40
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc*, int, int, int); // 0x00647BC0
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc*, int, int, int); // 0x00647D00
void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc*, D2DamageStrc*, int, int); // 0x0056E170
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc*, D2DamageStrc*, int, int); // 0x0056E0C0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C3E0
int __stdcall SKILLS_GetElementalLength(D2UnitStrc*, int, int, int); // 0x00644F20
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0
int __fastcall DATATBLS_ApplyRatio(int, int, int); // 0x00483360
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, D2DamageStrc*); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2DamageStrc*); // 0x0057CEE0
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc*, int); // 0x006212C0
inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}
// 0x005CDA00
int __fastcall sub_005CDA00_ApplySkillDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt) return 0;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill) return 0;
    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam3(pSkill), SKILLS_GetParam2(pSkill));
    if (!pTarget) return 0;
    if (!UNITS_IsInMeleeRange(pUnit, pTarget, 0)) return 0;
    int nCount = SKILLS_GetParam1(pSkill);
    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pSeed) return 0;
    const int nMin = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
    const int nMax = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    damage.dwPoisonDamage = 2 * (ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin) + nMin);
    damage.dwPoisonLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
    damage.dwManaLeech = (ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin) + nMin) << 8;
    damage.dwStaminaLeech = (ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin) + nMin) << 8;
    damage.wResultFlags = 1;
    const int nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->f_13C, nSkillId, nSkillLevel);
    const int nHeal = DATATBLS_ApplyRatio(damage.dwPhysDamage, nPercent, 100);
    int nLife = STATLIST_UnitGetStatValue(pUnit, 6, 0) + nHeal;
    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nLife >= nMaxLife) nLife = nMaxLife;
    STATLIST_SetUnitStat(pUnit, 6, nLife, 0);
    SUNITDMG_ExecuteEvents(pGame, pUnit, pTarget, 1, &damage);
    if (!STATLIST_UnitGetStatValue(pTarget, 6, 0)) damage.wResultFlags |= 2;
    SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pTarget, &damage);
    --nCount;
    if (nCount > 0)
    {
        SKILLS_SetParam1(pSkill, nCount);
        UNITS_SetAnimationFrame(pUnit, pSkillsTxt->nAnimFrame);
        pUnit->dwFrame = (pUnit->dwFrame & 0xFFFFFF00) + 0x100;
    }
    return 1;
}
