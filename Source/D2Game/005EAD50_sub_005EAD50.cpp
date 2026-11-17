#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2SkillStrc;

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
    D2SeedStrc tSeed;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2Unk005EAD50CounterStrc
{
    char unk0x00[0x14];
    int nFrame;
    int nValue;
    int nBase;
};

struct D2Unk005EAD50LimitsStrc
{
    char unk0x00[0x82];
    short nMin;
    short nMax;
};

struct D2Unk005EAD50ArgStrc
{
    D2Unk005EAD50CounterStrc* pCounter;
    char unk0x04[0x18];
    D2Unk005EAD50LimitsStrc* pLimits;
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall sub_005EABF0(D2GameStrc* pGame, D2UnitStrc* pTarget, D2UnitStrc* pUnit, int nSkillId, D2Unk005EAD50ArgStrc* pArg); // 0x005EABF0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_GetClassIdFromSkillId(int nSkillId);                                                   // 0x00645040
int __stdcall sub_006459F0(int nSkillId, int nSkillLevel);                                    // 0x006459F0

// 0x005EAD50
int __fastcall sub_005EAD50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillStrc* pSkill, int nSkillId, int nUnused, D2Unk005EAD50ArgStrc* pArg)
{
    if (pSkill && pTarget && pArg)
    {
        D2Unk005EAD50CounterStrc* pCounter = pArg->pCounter;
        if (pCounter)
        {
            const int nClassId = pTarget->dwClassId;
            if (SKILLS_GetClassIdFromSkillId(nSkillId) != nClassId)
            {
                return 0;
            }

            if (!sub_005EABF0(pGame, pTarget, pUnit, nSkillId, pArg))
            {
                return 0;
            }

            const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            if (!nSkillId)
            {
                return 1;
            }

            const int nValue = sub_006459F0(nSkillId, nSkillLevel);
            D2SeedStrc* pSeed = &pUnit->tSeed;
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) > 100 - nValue * 160 / 100)
            {
                return 0;
            }

            if (pCounter->nFrame > pGame->dwGameFrame)
            {
                return 0;
            }

            D2Unk005EAD50LimitsStrc* pLimits = pArg->pLimits;
            const int nMin = D2_MIN(D2_MAX(pLimits->nMin, 1), 128);
            const int nMax = D2_MIN(D2_MAX(pLimits->nMax, 1), 256);
            if (pCounter->nValue < nMin || pCounter->nValue > 32 * nMax)
            {
                pCounter->nValue = nMin;
            }

            if ((int)SEED_RollLimitedRandomNumber(pSeed, pCounter->nValue) > (int)SEED_RollLimitedRandomNumber(pSeed, 100))
            {
                return 0;
            }

            pCounter->nValue += (320 - pCounter->nBase) * nValue / (pCounter->nBase + 100);
            return 1;
        }
    }

    return 0;
}
