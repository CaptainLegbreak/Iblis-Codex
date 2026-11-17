struct D2GameStrc;
struct D2SkillStrc;

#define UNIT_PLAYER 0
#define UNIT_INVALID 6
#define STAT_MANA 8
#define SKILLSRVDO_SHAPESHIFT 116

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2SkillStrc
{
    char unk0x00[0x38];
    int nCharges;
};

struct D2SkillsTxt
{
    char unk0x00[0x2E];
    unsigned short wSrvDoFunc;
    char unk0x30[0x158];
    unsigned char nManaShift;
    char unk0x189;
    short wMana;
    short wLevelMana;
    char unk0x18E[0xAE];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[4];
    int nSkillsTxtRecordCount;
};

struct D2DamageStrc
{
    char unk0x00[0x08];
    int dwPhysDamage;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit);                                                 // 0x0063A400
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00647BC0
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00647D00
int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam); // 0x0057B420
void __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x0056C160
int __fastcall SKILLS_HasManaOrChargesForUsedSkill(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_PLAYER)
    {
        return 1;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (SKILLS_GetOwnerGUIDFromSkill(pSkill) != -1)
    {
        return pSkill->nCharges > 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1) - 1;
    if (nSkillLevel < 0)
    {
        nSkillLevel = 0;
    }

    const int nManaCost = (pSkillsTxtRecord->wMana + nSkillLevel * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift;
    if (pSkillsTxtRecord->wSrvDoFunc == SKILLSRVDO_SHAPESHIFT && STATES_IsUnitShapeShifted(pUnit))
    {
        return 1;
    }

    return STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) >= nManaCost;
}

// 0x0056D370
void __fastcall SKILLS_EnlargeVector(int* pX, int* pY)
{
    int nDistance = *pX * *pX + *pY * *pY;
    if (nDistance < 4)
    {
        *pX <<= 2;
        *pY <<= 2;
        nDistance = *pX * *pX + *pY * *pY;
    }

    if (nDistance < 16)
    {
        *pX <<= 1;
        *pY <<= 1;
    }
}

// 0x0056D3B0
void __fastcall SKILLS_MakeShortPerpendicularVector(int* pX, int* pY)
{
    int nX = *pY;
    int nY = -*pX;
    while (nX * nX + nY * nY > 3)
    {
        nX /= 2;
        nY /= 2;
    }

    *pX = nX;
    *pY = nY;
}

// 0x0057E270
void __fastcall SUNITDMG_RollSuckBloodDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        const int nMinDamage = SKILLS_GetMinPhysDamage(pAttacker, nSkillId, nSkillLevel, 0);
        const int nMaxDamage = SKILLS_GetMaxPhysDamage(pAttacker, nSkillId, nSkillLevel, 0);
        pDamage->dwPhysDamage = SUNITDMG_ApplyDamageBonuses(pAttacker, 0, 0, nMinDamage, nMaxDamage, 0, 0, 128);
        D2GAME_RollElementalDamage_6FD14DD0(pAttacker, pDamage, nSkillId, nSkillLevel);
    }
}
