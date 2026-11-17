struct D2GameStrc;
struct D2DamageStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x10];
    D2SeedStrc pSeed;
};

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);        // 0x00625500
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C390
void __fastcall SKILLS_ApplyDimVisionToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel); // 0x005C39C0

#define UNIT_MONSTER 1
#define STAT_LEVEL 12

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

// 0x005BFAA0
int __fastcall SKILLITEM_EventFunc09_Stupidity(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        goto ReturnZero;
    }

    if (!pUnit)
    {
        goto ReturnZero;
    }

    if ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_MONSTER)
    {
ReturnZero:
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
    {
        return 0;
    }

    const int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, STAT_LEVEL, 0);
    int nChance = 5 * (nAttackerLevel + 4 * nValue - STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) + 6);
    if (nEvent == 6 && nChance > 0)
    {
        nChance /= 3;
    }

    nChance = D2_MIN(D2_MAX(nChance, 1), 99);

    const int nRoll = SEED_RollLimitedRandomNumber(&pAttacker->pSeed, 100);
    if (nRoll >= nChance)
    {
        return 0;
    }

    int nLevel = (nChance - nRoll) / 5 + 1;
    nLevel = D2_MIN(D2_MAX(nLevel, 1), 20);

    SKILLS_ApplyDimVisionToTarget(pGame, pAttacker, pUnit, nLevel);
    return 1;
}
