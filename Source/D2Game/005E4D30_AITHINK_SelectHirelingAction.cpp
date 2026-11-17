struct D2UnitStrc;
struct D2SkillStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
};

struct D2HirelingTxt
{
    char unk0x00[0x1C];
    int nHirelingLevel;
    char unk0x20[0x44];
    int dwDefaultChance;
    char unk0x68[0x10];
    int dwSkill[6];
    int dwChance[6];
    int dwChancePerLvl[6];
    unsigned char nMode[6];
};

struct D2MonStatsTxt
{
    char unk0x000[0x170];
    short nSkill[8];
    unsigned char nSkillMode[8];
    char unk0x188[0x20];
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x74];
    short nAuraState;
    char unk0x082[0x1AE];
    unsigned char nAiType;
    char unk0x231[0x0B];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0x9B0];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x114];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

#define SKILL_INFERNO 41
#define SKILLSFLAGINDEX_AURA 5
#define MONSTER_ROGUEHIRE 271
#define MONSTER_ACT2HIRE 338
#define MONSTER_ACT3HIRE 359
#define MONSTER_ACT5HIRE1 560
#define MONSTER_ACT5HIRE2 561
#define MONMODE_ATTACK1 4
#define STAT_LEVEL 12

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nRangeBonus);               // 0x00622C40
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                    // 0x006442A0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags);          // 0x005701B0
D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int bExpansion, int nId, int nLevel);  // 0x006562F0

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

static __forceinline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline int MONSTERS_GetValidMonsterId(int nMonsterId)
{
    if (nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }

    return -1;
}

// 0x005E4D30
void __fastcall AITHINK_SelectHirelingAction(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nHirelingId, D2UnitStrc* pTarget, D2SeedStrc* pSeed)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    int nChance = pHirelingTxtRecord->dwDefaultChance;
    int nLevelDiff = nLevel - pHirelingTxtRecord->nHirelingLevel;
    if (nLevelDiff < 0)
    {
        nLevelDiff = 0;
    }

    int nSkillChances[6];
    for (int i = 0; i < 6; ++i)
    {
        if (pHirelingTxtRecord->dwSkill[i] <= 0 || pHirelingTxtRecord->dwSkill[i] >= sgptDataTables->nSkillsTxtRecordCount)
        {
            break;
        }

        const int nSkillId = pHirelingTxtRecord->dwSkill[i];

        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            continue;
        }

        nSkillChances[i] = 0;

        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
        if (!pSkill || SKILLS_GetSkillLevel(pUnit, pSkill, 1) <= 0)
        {
            continue;
        }

        if (pSkillsTxtRecord->nAiType == 1 && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount
            && STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
        {
            continue;
        }

        if (nSkillId == SKILL_INFERNO)
        {
            pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            if (pTarget && sub_006416D0_UnitEdgeDistance(pUnit, pTarget) > SKILLS_GetSkillLevel(pUnit, pSkill, 1) / 2 + 4)
            {
                continue;
            }
        }

        nChance += pHirelingTxtRecord->dwChance[i] + nLevelDiff * pHirelingTxtRecord->dwChancePerLvl[i] / 4;
        nSkillChances[i] = nChance;
    }

    const int nRoll = SEED_RollLimitedRandomNumber(pSeed, nChance + 1);

    if (nRoll >= pHirelingTxtRecord->dwDefaultChance)
    {
        int i = 0;
        while (nRoll > nSkillChances[i] && i < 6)
        {
            ++i;
        }

        if (i < 6)
        {
            const int nSkillId = pHirelingTxtRecord->dwSkill[i];
            if (nSkillId > 0)
            {
                D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
                if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
                {
                    D2GAME_AssignSkill_6FD13800(pUnit, 0, nSkillId, -1);
                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                    return;
                }

                AITACTICS_UseSkill(pGame, pUnit, pHirelingTxtRecord->nMode[i], nSkillId, pTarget, 0, 0);
                return;
            }
        }
    }

    switch (MONSTERS_GetValidMonsterId(nMonsterId))
    {
    case MONSTER_ROGUEHIRE:
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->nSkillMode[0], pMonStatsTxtRecord->nSkill[0], pTarget, 0, 0);
        return;

    case MONSTER_ACT2HIRE:
    case MONSTER_ACT3HIRE:
    case MONSTER_ACT5HIRE1:
    case MONSTER_ACT5HIRE2:
        if (UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
        break;

    default:
        break;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}
