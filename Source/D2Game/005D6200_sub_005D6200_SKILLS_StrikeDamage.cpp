struct D2GameStrc;
struct D2UnitStrc
{
    char unk0x00[0x38];
    int nParityField;
    char unk0x3C[0x88];
    unsigned int dwFlags;
};
struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int unk0x10[21];
    unsigned char nHitClassActiveSet;
    char nConvType;
    unsigned short wUnk0x66;
    int dwConvPct;
    int nOverlay;
};
struct D2SkillsTxt
{
    char unk0x000[0x138];
    unsigned int dwCalc[4];
    char unk0x148[0x5D];
    unsigned char nSrcDam;
    char unk0x1A6[0x36];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};
struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                 // 0x00681EF0
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);                       // 0x006449F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x00625480
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
void __fastcall sub_005D3AC0_SKILLS_PrepareStrikeDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage);           // 0x005D3AC0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a5, unsigned char nSrcDam); // 0x0057B7D0
void __fastcall sub_005D3BA0_SKILLS_FinishStrikeDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage);            // 0x005D3BA0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                             // 0x00553540
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget);                // 0x0057D690
void __fastcall sub_6FCF77E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage);                   // 0x005D5220
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005D6200
static void __stdcall sub_005D6200_SKILLS_StrikeDamage(D2GameStrc* pGame, D2UnitStrc* pTarget, int nSkillLevel, D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel) + STATLIST_UnitGetStatValue(pUnit, 325, 0);
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwHitFlags |= 2;
        sub_005D3AC0_SKILLS_PrepareStrikeDamage(pUnit, &damage);
        damage.dwEnDmgPct += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
            D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        }
        SUNITDMG_FillDamageValues(pGame, pUnit, pTarget, &damage, 0, pSkillsTxtRecord->nSrcDam);
        sub_005D3BA0_SKILLS_FinishStrikeDamage(pUnit, &damage);
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);
}

// 0x005D6340
int __fastcall sub_005D6340_SKILLS_SrvDo_AlternatingStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if ((pUnit->nParityField >> 8) % 2 == 0)
    {
        sub_005D6200_SKILLS_StrikeDamage(pGame, pTarget, nSkillLevel, pUnit, nSkillId);
        D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
        if (pDamage)
        {
            sub_6FCF77E0(pGame, pUnit, pDamage);
        }
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        pUnit->dwFlags &= ~0x40;
    }
    else
    {
        sub_005D6200_SKILLS_StrikeDamage(pGame, pTarget, nSkillLevel, pUnit, nSkillId);
        D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
        if (pDamage)
        {
            sub_6FCF77E0(pGame, pUnit, pDamage);
        }
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        pUnit->dwFlags |= 0x40;
    }

    return 1;
}
