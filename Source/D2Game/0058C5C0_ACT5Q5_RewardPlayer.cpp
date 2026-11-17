struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

#define STAT_LEVEL 12
#define STAT_EXPERIENCE 13
#define STAT_LASTEXP 29
#define STAT_NEXTEXP 30

void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0
void __fastcall PLAYERSTATS_LevelUp(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00570880
int __stdcall DATATBLS_GetLevelThreshold(int nClass, int nLevel); // 0x00611800
int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

static __declspec(noinline)
// 0x0058C5C0
void __stdcall ACT5Q5_RewardPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    QUESTS_UpdatePlayerFlags(pGame, pUnit);

    int nRewardExp = 1400000;
    switch (pGame->nDifficulty)
    {
    case 1:
        nRewardExp = 20000000;
        break;
    case 2:
        nRewardExp = 40000000;
        break;
    }

    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    const int nMaxLevel = DATATBLS_GetMaxLevel(nClassId);
    int nCurrentLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (nCurrentLevel >= nMaxLevel)
    {
        return;
    }

    const unsigned int nNextThreshold = DATATBLS_GetLevelThreshold(nClassId, nCurrentLevel + 1);
    const int nDeltaExpThreshold = nNextThreshold - DATATBLS_GetLevelThreshold(nClassId, nCurrentLevel);
    if (nRewardExp > nDeltaExpThreshold)
    {
        nRewardExp = nDeltaExpThreshold;
    }

    do
    {
        if (!nRewardExp)
        {
            break;
        }

        const int nNextExp = STATLIST_GetUnitBaseStat(pUnit, STAT_NEXTEXP, 0);
        const unsigned int nDeltaExp = nNextExp - STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
        if ((unsigned int)nRewardExp >= nDeltaExp)
        {
            STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, nNextExp, 0);
            STATLIST_SetUnitStat(pUnit, STAT_LASTEXP, nDeltaExp, 0);
            PLAYERSTATS_LevelUp(pGame, pUnit);
            nRewardExp -= nDeltaExp;
            nCurrentLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
        }
        else
        {
            nRewardExp += STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
            STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, nRewardExp, 0);
            nRewardExp ^= nRewardExp;
        }
    }
    while (nCurrentLevel < nMaxLevel);
}

void __fastcall sub_Emit_0058C5C0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        ACT5Q5_RewardPlayer(pGame, pUnit);
    }
}
