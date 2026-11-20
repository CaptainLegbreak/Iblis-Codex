#include "D2Game.h"
#include "D2Structs.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2SeedStrc;
struct D2SkillsTxt;



struct D2GameStrc
{
    char unk0x00[0xA8];
    unsigned int dwGameFrame;
};

struct D2SkillsTxt
{
    char unk0x000[0x64];
    unsigned int dwAuraRangeCalc;
    char unk0x068[0x23C - 0x64 - 4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0xBA0 - 0xB98 - 4];
    int nSkillsTxtRecordCount;
};

typedef void(__fastcall* CurseCallbackFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel);

enum
{
    MONMODE_DEATH = 0,
    MONMODE_GETHIT = 3,
    EVENTTYPE_MONUMOD = 7,
    STAT_LEVEL = 0x0C,
    STAT_MINDAMAGE = 0x15,
    STAT_MAXDAMAGE = 0x16,
    STAT_SECONDARY_MINDAMAGE = 0x17,
    STAT_SECONDARY_MAXDAMAGE = 0x18,
    MONSTER_ROGUEHIRE = 0x10F,
    SKILL_AMPLIFYDAMAGE = 0x42,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStat, int nLayer); // 0x00625480
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall sub_0056DBC0(D2GameStrc* pGame, int nFlags, D2UnitStrc* pUnit, int nSkillLevel, int nRange, CurseCallbackFunc pfCurse); // 0x0056DBC0
void __fastcall MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel); // 0x005A23D0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005A2530
void __fastcall MONSTERUNIQUE_CastAmplifyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
    {
        return;
    }

    if ((SEED_RollRandomNumber(&pUnit->pSeed) & 3) < 1)
    {
        return;
    }

    int nSkillLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) / 5 + 1;
    if (nSkillLevel < 1)
    {
        nSkillLevel = 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(SKILL_AMPLIFYDAMAGE);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, SKILL_AMPLIFYDAMAGE, nSkillLevel);
    sub_0056DBC0(pGame, 3, pUnit, nSkillLevel, D2_MIN(D2_MAX(nRange, 1), 40), MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage);
}

inline int D2Clamp(int v, int low, int high)
{
    return (v < low) ? low : (high < v) ? high : v;
}

// 0x005A2D80
void __fastcall sub_6FC6CF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    int nMinDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
    int nMaxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
    if (nMaxDamage > 0 && (!pUnit || pUnit->dwClassId != MONSTER_ROGUEHIRE))
    {
        nMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0) - 1;
        nMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MAXDAMAGE, 0) - 1;
        if (nMinDamage < 0)
        {
            nMinDamage = 0;
        }
        if (nMaxDamage < 0)
        {
            nMaxDamage = 0;
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
        STATLIST_SetStat(pStatList, STAT_MINDAMAGE, nMinDamage, 0);
        STATLIST_SetStat(pStatList, STAT_MAXDAMAGE, nMaxDamage, 0);
    }
}

// 0x005A2EB0
void __fastcall MONSTERUNIQUE_ScarabModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int nUMod, int bUnique)
{
    if (!pBoss || pBoss->dwAnimMode == MONMODE_GETHIT || pBoss->dwAnimMode == MONMODE_DEATH)
    {
        EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 2, 0, 0);
    }
}
