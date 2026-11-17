struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2GameStrc
{
    char unk0x00[0x6A];
    unsigned char nGameType;
    char unk0x6B[2];
    unsigned char nDifficulty;
};

struct D2DifficultyLevelsTxt
{
    unsigned int dwResistPenalty;
    unsigned int dwDeathExpPenalty;
};

struct D2ClientStrc;

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define STAT_LEVEL 12
#define STAT_EXPERIENCE 13
#define STAT_GOLD 14
#define STAT_GOLDBANK 15
#define STAT_GOLDLOST 175

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall UNITS_GetStashGoldLimit(D2UnitStrc* pUnit);                                                   // 0x00623460
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
int __fastcall sub_6FC7C260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, unsigned int nValue);      // 0x00535510
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                   // 0x00611D30
int __stdcall DATATBLS_GetLevelThreshold(int nClass, int nLevel);                                           // 0x00611800
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall CLIENTS_SetExperienceLoss(D2ClientStrc* pClient, int nExpLoss);                             // 0x005391E0

static void D2GAME_SetStatOrResetGold_6FC7CA70(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }
    if (nValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        if (nStat == STAT_GOLD)
        {
            if (nValue > UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
                return;
            }
        }
        else if (nStat == STAT_GOLDBANK)
        {
            if (nValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, 0, 0);
                return;
            }
        }
    }
    STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

static void __stdcall sub_005357D0_ApplyDeathGoldPenalty(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    const int nDefenderLevel = STATLIST_UnitGetStatValue(pDefender, STAT_LEVEL, 0);
    const int nDefenderInventoryGold = STATLIST_UnitGetStatValue(pDefender, STAT_GOLD, 0);
    const int nDefenderBankGold = STATLIST_UnitGetStatValue(pDefender, STAT_GOLDBANK, 0);
    const int nDefenderTotalGold = nDefenderBankGold + nDefenderInventoryGold;
    const int nPenaltyPercentage = nDefenderLevel < 20 ? nDefenderLevel : 20;
    int nGoldPenalty = nDefenderTotalGold * nPenaltyPercentage / 100;
    int bAttackedByAnotherPlayer = 0;
    if (pAttacker && pAttacker != pDefender)
    {
        if (pAttacker->dwUnitType == UNIT_PLAYER)
        {
            bAttackedByAnotherPlayer = 1;
        }
        else if (pAttacker->dwUnitType == UNIT_MONSTER)
        {
            D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
            if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
            {
                bAttackedByAnotherPlayer = 1;
            }
        }
    }
    if (pGame->nGameType == 3)
    {
        if (nDefenderTotalGold - nGoldPenalty < 500 * nDefenderLevel)
        {
            nGoldPenalty = nDefenderTotalGold - 500 * nDefenderLevel;
            if (nGoldPenalty < 0)
            {
                nGoldPenalty = 0;
            }
        }
        if (nGoldPenalty > nDefenderInventoryGold)
        {
            nGoldPenalty = nDefenderInventoryGold;
        }
    }
    if (bAttackedByAnotherPlayer)
    {
        if (nGoldPenalty > nDefenderInventoryGold)
        {
            D2GAME_SetStatOrResetGold_6FC7CA70(pDefender, STAT_GOLDBANK, nDefenderInventoryGold + nDefenderBankGold - nGoldPenalty);
            D2GAME_SetStatOrResetGold_6FC7CA70(pDefender, STAT_GOLD, nGoldPenalty);
        }
        sub_6FC7C260(pGame, pDefender, !pDefender ? -1 : pDefender->dwUnitId, nGoldPenalty);
    }
    else
    {
        if (nGoldPenalty > nDefenderInventoryGold)
        {
            if (pGame->nGameType != 3)
            {
                D2GAME_SetStatOrResetGold_6FC7CA70(pDefender, STAT_GOLDBANK, nDefenderInventoryGold + nDefenderBankGold - nGoldPenalty);
            }
        }
        else
        {
            sub_6FC7C260(pGame, pDefender, !pDefender ? -1 : pDefender->dwUnitId, nDefenderInventoryGold - nGoldPenalty);
        }
        D2GAME_SetStatOrResetGold_6FC7CA70(pDefender, STAT_GOLD, 0);
    }
    D2GAME_SetStatOrResetGold_6FC7CA70(pDefender, STAT_GOLDLOST, nGoldPenalty);
}

// 0x005359F0
static void __stdcall sub_005359F0(D2GameStrc* pGame, D2UnitStrc* pDefender)
{
    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    const int nClassId = !pDefender ? -1 : pDefender->dwClassId;
    const int nDefenderLevel = STATLIST_UnitGetStatValue(pDefender, STAT_LEVEL, 0);
    if (nDefenderLevel > 1)
    {
        const unsigned int nPreviousExpThreshold = DATATBLS_GetLevelThreshold(nClassId, nDefenderLevel - 1);
        const unsigned int nCurrentExpThreshold = DATATBLS_GetLevelThreshold(nClassId, nDefenderLevel);
        const unsigned int nExpRange = nCurrentExpThreshold - nPreviousExpThreshold;
        int nNewExperienceValue = STATLIST_UnitGetStatValue(pDefender, STAT_EXPERIENCE, 0);
        int nExperiencePenalty = pDifficultyLevelsTxtRecord->dwDeathExpPenalty * nExpRange / 100;
        if (nExperiencePenalty)
        {
            nNewExperienceValue -= nExperiencePenalty;
            if (nNewExperienceValue <= nPreviousExpThreshold)
            {
                nExperiencePenalty += nNewExperienceValue - nPreviousExpThreshold;
                if (nExperiencePenalty < 0)
                {
                    nExperiencePenalty = 0;
                }
                nNewExperienceValue = nPreviousExpThreshold + 1;
            }
            CLIENTS_SetExperienceLoss(SUNIT_GetClientFromPlayer(pDefender, ".\\PLAYER\\Player.cpp", 0x3C4), nExperiencePenalty);
            STATLIST_SetUnitStat(pDefender, STAT_EXPERIENCE, nNewExperienceValue, 0);
        }
    }
}

// 0x00535AB0
void __fastcall PLAYER_ApplyDeathPenalty(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    sub_005357D0_ApplyDeathGoldPenalty(pGame, pDefender, pAttacker);
    if (pAttacker)
    {
        if (pAttacker->dwUnitType == UNIT_PLAYER)
        {
            return;
        }
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
        {
            return;
        }
    }
    sub_005359F0(pGame, pDefender);
}
