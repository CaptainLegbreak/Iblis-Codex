#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
#pragma intrinsic(memset)



struct D2MonsterDataStrc
{
    D2MonStatsTxt* pMonstatsTxt;
    unsigned char nComponent[16];
};



struct D2PlayerCountBonusStrc
{
    int nHp;
    int nExperience;
    int nMonsterSkillBonus;
    int nDifficulty;
    int nPlayerCount;
};

struct D2ActiveRoomStrc;

extern const int gnHpBonusTable[9];
extern const int gnExperienceBonusTable[9];
int __fastcall PLAYER_GetPlayerCount(D2GameStrc* pGame);                                                    // 0x00535790
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                    // 0x00611D30

#define UNIT_MONSTER 1
#define BONUS_TABLE_SIZE 9
#define HP_BONUS_STEP 50
#define HP_BONUS_BASE 2
#define XP_BONUS_BASE 130
#define MONALIGN_EVIL 0

__declspec(noinline) int __fastcall MONSTER_GetHpBonus(int nPlayerCount); // 0x005738F0

// build: context MONSTER_GetHpBonus
__declspec(noinline) int __fastcall MONSTER_GetHpBonus(int nPlayerCount)
{
    if (nPlayerCount < BONUS_TABLE_SIZE)
    {
        return gnHpBonusTable[nPlayerCount];
    }

    return (nPlayerCount - HP_BONUS_BASE) * HP_BONUS_STEP;
}

__declspec(noinline) int __fastcall MONSTER_GetExperienceBonus(int nPlayerCount); // 0x00573910

// build: context MONSTER_GetExperienceBonus
__declspec(noinline) int __fastcall MONSTER_GetExperienceBonus(int nPlayerCount)
{
    if (nPlayerCount < BONUS_TABLE_SIZE)
    {
        return gnExperienceBonusTable[nPlayerCount];
    }

    return 2 * (5 * nPlayerCount + XP_BONUS_BASE);
}

static inline D2MonsterDataStrc* MONSTER_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

// 0x00573930
void __fastcall MONSTER_GetPlayerCountBonus(D2GameStrc* pGame, D2PlayerCountBonusStrc* pPlayerCountBonus, D2ActiveRoomStrc* pRoom, D2UnitStrc* pMonster)
{
    if (!pPlayerCountBonus)
    {
        return;
    }

    memset(pPlayerCountBonus, 0x00, sizeof(*pPlayerCountBonus));
    D2MonsterDataStrc* pMonsterData = MONSTER_GetMonsterDataInline(pMonster);
    if (!pMonsterData)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxt = pMonsterData->pMonstatsTxt;
    if (!pMonStatsTxt)
    {
        return;
    }

    if (pMonStatsTxt->nAlign == MONALIGN_EVIL)
    {
        int nPlayerCount = PLAYER_GetPlayerCount(pGame);
        if (nPlayerCount < 1)
        {
            nPlayerCount = 1;
        }
        pPlayerCountBonus->nHp = MONSTER_GetHpBonus(nPlayerCount);
        pPlayerCountBonus->nExperience = MONSTER_GetExperienceBonus(nPlayerCount);
        pPlayerCountBonus->nPlayerCount = nPlayerCount;
    }
    else
    {
        pPlayerCountBonus->nPlayerCount = 1;
    }

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (pGame->nDifficulty >= 3)
    {
        pGame->nDifficulty = 2;
    }

    pPlayerCountBonus->nMonsterSkillBonus = pDifficultyLevelsTxtRecord->dwMonsterSkillBonus;
    pPlayerCountBonus->nDifficulty = pGame->nDifficulty;
}
