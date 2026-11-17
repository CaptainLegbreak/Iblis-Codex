struct D2GameStrc;
struct D2UnitStrc { char unk00[0xC4]; unsigned int dwFlags; };
struct D2SkillsTxt { char unk00[0x4E]; short wSrvOverlay; char unk50[0xDE]; unsigned short wResultFlags; unsigned int dwHitFlags; unsigned int dwHitClass; char unk138[0x104]; };
struct D2DataTablesStrc { char unk00[0xB98]; D2SkillsTxt* pSkillsTxt; void* pLinker; int nSkillsTxtRecordCount; char unkBA4[0x1C]; int nOverlayTxtRecordCount; };
struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int unk0x10[9];
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int unk0x40[3];
    int dwDmgTotal;
    int unk0x50[4];
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc*, D2UnitStrc*); // 0x00553540
int __stdcall SKILLS_GetElementalLength(D2UnitStrc*, int, int, int); // 0x00644F20
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc*, D2DamageStrc*, int, int); // 0x0056E0C0
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, D2DamageStrc*); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2DamageStrc*); // 0x0057CEE0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
void __stdcall UNITS_SetOverlay(D2UnitStrc*, int, int); // 0x00621E40
static __forceinline D2SkillsTxt* GetSkillsTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nId];
    return 0;
}
// 0x005CCE80
int __fastcall sub_005CCE80_ApplyFreezingSkillDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2DamageStrc damage;
    D2SkillsTxt* pSkillsTxt = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
        return 0;
    if (pUnit)
        pUnit->dwFlags |= 0x40;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        memset(&damage, 0, sizeof(damage));
        damage.wResultFlags |= 1;
        damage.wResultFlags |= *(unsigned short*)&pSkillsTxt->wResultFlags;
        damage.dwHitFlags |= pSkillsTxt->dwHitFlags;
        if (pSkillsTxt->dwHitClass)
            damage.dwHitClass = pSkillsTxt->dwHitClass;
        damage.dwFrzLen = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        SUNITDMG_ExecuteEvents(pGame, pUnit, pTarget, 1, &damage);
        if (!STATLIST_UnitGetStatValue(pTarget, 6, 0))
            damage.wResultFlags |= 2;
        SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pTarget, &damage);
        if (pSkillsTxt->wSrvOverlay > 0 && pSkillsTxt->wSrvOverlay <= sgptDataTables->nOverlayTxtRecordCount)
            UNITS_SetOverlay(pTarget, pSkillsTxt->wSrvOverlay, 0);
    }
    return 1;
}
