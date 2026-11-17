struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x14];
    unsigned short wNameSeed;
    char unk0x16[0x10];
    unsigned short wBossHcIdx;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x0C];
    D2MonsterDataStrc* pMonsterData;
};

struct D2AuraEnchantStrc
{
    int nLevel;
    int nLevelAdd;
    int nMul;
    int nDiv;
    int nSkillId;
};

extern D2AuraEnchantStrc gAuraEnchantTable_0073BF68[8];                                                     // 0x0073BF68
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C390
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove);   // 0x0056DEB0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags);           // 0x005701B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

// 0x005A0140
unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == 1) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 5382;
    }
    return pMonsterData->wNameSeed;
}

// 0x005A01E0
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == 1) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return -1;
    }
    return pMonsterData->wBossHcIdx;
}

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

// 0x005A1650
void __fastcall MONSTERUNIQUE_UMod30_AuraEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if ((!pUnit ? 6 : pUnit->dwUnitType) != 1 || !bUnique)
    {
        return;
    }

    int nLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
    if (nLevel <= 0)
    {
        nLevel = 1;
    }

    int nCount = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (gAuraEnchantTable_0073BF68[i].nLevel <= nLevel)
        {
            ++nCount;
        }
    }

    if (!nCount)
    {
        nCount = 1;
    }

    const unsigned short wNameSeed = MONSTERUNIQUE_GetNameSeed(pUnit);
    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, wNameSeed);
    int nIndex = SEED_RollLimitedRandomNumber(&tSeed, nCount);
    if (MONSTERUNIQUE_GetBossHcIdx(pUnit) == 37)
    {
        nIndex = 5;
    }

    if (pUnit->dwClassId == 0x2C0)
    {
        D2GAME_SetSkills_6FD14C60(pUnit, 0x7B, 20, 1);
        D2GAME_AssignSkill_6FD13800(pUnit, 0, 0x7B, -1);
        return;
    }

    int nSkillLevel = (gAuraEnchantTable_0073BF68[nIndex].nLevelAdd + nLevel) * gAuraEnchantTable_0073BF68[nIndex].nMul / gAuraEnchantTable_0073BF68[nIndex].nDiv;
    nSkillLevel = D2_MIN(D2_MAX(nSkillLevel, 1), 99);

    D2GAME_SetSkills_6FD14C60(pUnit, gAuraEnchantTable_0073BF68[nIndex].nSkillId, nSkillLevel, 1);
    D2GAME_AssignSkill_6FD13800(pUnit, 0, gAuraEnchantTable_0073BF68[nIndex].nSkillId, -1);
}

#include "gen/data/Source/D2Game/005A1650_MONSTERUNIQUE_UMod30_AuraEnchanted.inc"
