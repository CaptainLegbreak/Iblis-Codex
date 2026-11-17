#define STAT_HITPOINTS 6

struct D2GameStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
};

struct D2MissilesTxt
{
    char pad0x000[0x36];
    unsigned short wProgOverlay;
    char pad0x038[0x14E];
    unsigned char nCollideKill;
    char pad0x187[0x1D];
};

struct D2SkillsTxt
{
    char pad0x000[0x23C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0xB6C - 0xB64 - 4];
    int nMissilesTxtRecordCount;
    char unk0xB70[0xB98 - 0xB6C - 4];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0xBA0 - 0xB98 - 4];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3);                                   // 0x00621E40
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00647BC0
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00647D00
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }

    return 0;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005AC350
int __fastcall sub_005AC350(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (!pUnit)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 1;
    }

    const int nMin = SKILLS_GetMinPhysDamage(SUNIT_GetOwner(pGame, pMissile), nSkillId, nSkillLevel, 1);
    const int nMax = SKILLS_GetMaxPhysDamage(SUNIT_GetOwner(pGame, pMissile), nSkillId, nSkillLevel, 1);
    const int nHeal = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, nMax - nMin) + nMin;

    int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const int nMaxHitpoints = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nHitpoints != nMaxHitpoints && (short)pMissilesTxtRecord->wProgOverlay > 0)
    {
        UNITS_SetOverlay(pUnit, (short)pMissilesTxtRecord->wProgOverlay, 0);
    }

    nHitpoints += nHeal;
    if (nHitpoints >= nMaxHitpoints)
    {
        nHitpoints = nMaxHitpoints;
    }

    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nHitpoints, 0);
    return pMissilesTxtRecord->nCollideKill != 0;
}
