#include "D2Game.h"

struct D2GameStrc
{
    char unk0x00[0x6A];
    unsigned char nGameType;
    char pad6B[2];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

int __fastcall sub_6FC7C260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, unsigned int nValue);      // 0x00535510
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);     // 0x00627260

// build: context D2GAME_SetStatOrResetGold_6FC7CA70
static __forceinline void D2GAME_SetStatOrResetGold_6FC7CA70(D2UnitStrc* pUnit, int nStat, int nValue)
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

    if (pUnit->dwUnitType == 0)
    {
        if (nStat == 14)
        {
            if (nValue > UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, 14, 0, 0);
                return;
            }
        }
        else if (nStat == 15)
        {
            if (nValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, 15, 0, 0);
                return;
            }
        }
    }

    STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

__declspec(noinline) static void __stdcall sub_005357D0_ApplyDeathGoldLoss(D2GameStrc* pGame, D2UnitStrc* pKiller, D2UnitStrc* pPlayer);
// 0x005357D0
static void __stdcall sub_005357D0_ApplyDeathGoldLoss(D2GameStrc* pGame, D2UnitStrc* pKiller, D2UnitStrc* pPlayer)
{
    const int nLevel = STATLIST_UnitGetStatValue(pPlayer, 12, 0);
    const int nGold = STATLIST_UnitGetStatValue(pPlayer, 14, 0);
    const int nStash = STATLIST_UnitGetStatValue(pPlayer, 15, 0);
    const int nTotal = nStash + nGold;
    const int nPercent = nLevel < 20 ? nLevel : 20;
    const int nMinimum = nLevel * 500;
    int nLoss = nPercent * nTotal / 100;
    const int nKeep = nTotal - nLoss;

    int bPlayerKill = 0;
    if (pKiller && pKiller != pPlayer)
    {
        if (pKiller->dwUnitType == 0)
        {
            bPlayerKill = 1;
        }
        else if (pKiller->dwUnitType == 1)
        {
            D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pKiller);
            if (pOwner && pOwner->dwUnitType == 0)
            {
                bPlayerKill = 1;
            }
        }
    }

    if (pGame->nGameType == 3)
    {
        if (nKeep < nMinimum)
        {
            nLoss = nTotal - nMinimum;
            if (nLoss < 0)
            {
                nLoss = 0;
            }
        }

        if (nLoss > nGold)
        {
            nLoss = nGold;
        }
    }

    if (bPlayerKill)
    {
        if (nLoss > nGold)
        {
            D2GAME_SetStatOrResetGold_6FC7CA70(pPlayer, 15, nStash - nLoss + nGold);
            D2GAME_SetStatOrResetGold_6FC7CA70(pPlayer, 14, nLoss);
        }

        sub_6FC7C260(pGame, pPlayer, !pPlayer ? -1 : pPlayer->dwUnitId, nLoss);
    }
    else
    {
        if (!(nLoss > nGold))
        {
            const int nDrop = nGold - nLoss;
            sub_6FC7C260(pGame, pPlayer, !pPlayer ? -1 : pPlayer->dwUnitId, nDrop);
        }
        else
        {
            if (pGame->nGameType != 3)
            {
                D2GAME_SetStatOrResetGold_6FC7CA70(pPlayer, 15, nStash - nLoss + nGold);
            }
        }

        D2GAME_SetStatOrResetGold_6FC7CA70(pPlayer, 14, 0);
    }

    D2GAME_SetStatOrResetGold_6FC7CA70(pPlayer, 0xAF, nLoss);
}

struct D2DifficultyLevelsTxt { unsigned int dwResistPenalty; unsigned int dwDeathExpPenalty; };
#define UNIT_PLAYER 0
#define STAT_LEVEL 12
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30
int __stdcall DATATBLS_GetLevelThreshold(int nClass, int nLevel); // 0x00611800
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall CLIENTS_SetExperienceLoss(D2ClientStrc* pClient, int nExpLoss); // 0x005391E0
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
            CLIENTS_SetExperienceLoss(SUNIT_GetClientFromPlayer(pDefender, szPlayerCppFile, 0x3C4), nExperiencePenalty);
            STATLIST_SetUnitStat(pDefender, STAT_EXPERIENCE, nNewExperienceValue, 0);
        }
    }
}

// 0x00535AB0
void __fastcall PLAYER_ApplyDeathPenalty(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    sub_005357D0_ApplyDeathGoldLoss(pGame, pAttacker, pDefender);
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
