#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameTypes.h"

#include "D2GameStrc.h"
#include "D2QuestData.h"
#include "D2UnitData.h"
struct D2QuestStrc;
union D2SeedStrc;
struct D2Act4Quest3Strc;



int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc*); // 0x005438B0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int nItemType, int bIgnoreRarity); // 0x00559A30
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0
extern unsigned int gnHellforgeRunesNormal[]; // 0x0073E114
extern unsigned int gnHellforgeRunesNightmare[]; // 0x0073E514
extern unsigned int gnHellforgeRunesHell[]; // 0x0073E540
extern unsigned int gnHellforgeGemsFirst[]; // 0x0073E56C
extern unsigned int gnHellforgeGemsMiddle[]; // 0x0073E588
extern unsigned int gnHellforgeGemsLast[]; // 0x0073E5A4

void __fastcall PLRINTRO_SetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x00572360

static inline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 seed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(seed >> 32);
    pSeed->nLowSeed = (unsigned int)seed;
    return (unsigned int)seed;
}

// 0x005B6710
void __fastcall sub_005B6710_DropHellforgeReward(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bRewardPending) UNITS_ChangeAnimMode(pUnit, 4);
    if (pQuestDataEx->unk0x03)
    {
        int nItemLevel = 50;
        int nDropped = 0;
        for (int i = 0; i < pQuestDataEx->nPlayersInAct; ++i)
        {
            switch (pQuestDataEx->nRewardState)
            {
            case 4: pUnit->dwDropItemCode = gnHellforgeGemsFirst[RollSeed(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7]; break;
            case 2:
            case 3: pUnit->dwDropItemCode = gnHellforgeGemsMiddle[RollSeed(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7]; break;
            case 1: pUnit->dwDropItemCode = gnHellforgeGemsLast[RollSeed(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7]; break;
            default: return;
            }
            if (D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pUnit, 2, &nItemLevel, 0, -1, 0)) ++nDropped;
        }
        if (!nDropped) return;
        --pQuestDataEx->nRewardState;
        if (pQuestDataEx->nRewardState <= 0)
        {
            pQuestDataEx->unk0x03 = 0;
            if (pQuestData->pGame->bExpansion)
            {
                unsigned int* pCodes = gnHellforgeRunesNormal;
                switch (pQuestData->pGame->nDifficulty)
                {
                case 1: pCodes = gnHellforgeRunesNightmare; break;
                case 2: pCodes = gnHellforgeRunesHell; break;
                }
                pUnit->dwDropItemCode = pCodes[SEED_RollLimitedRandomNumber(QUESTS_GetGlobalSeed(pQuestData->pGame), 11)];
                D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pUnit, 2, &nItemLevel, 0, -1, 0);
            }
        }
        else
            EVENT_SetEvent(pQuestData->pGame, pUnit, 7, pQuestData->pGame->dwGameFrame + 20, 0, 0);
    }
}

#include "gen/data/Source/D2Game/Unknown_005B6710.inc"
struct D2ItemDropStrc;
struct D2UnitStrc;

// 0x005B6C60
void __fastcall sub_005B6C60_UpdateQuest(void* pUnused, D2QuestArgStrc* pArgs)
{
    const int nNpcId = pArgs->nOldLevel;
    const unsigned short nIndex = pArgs->nMessageIndex;
    switch (nNpcId)
    {
    case 254:
        if (nIndex == 502 || nIndex == 501)
            PLRINTRO_SetQuestIntroFlag(pArgs->pPlayer, pArgs->pGame, nNpcId);
        break;
    case 264:
        if (nIndex == 479 || nIndex == 478)
            PLRINTRO_SetQuestIntroFlag(pArgs->pPlayer, pArgs->pGame, nNpcId);
        break;
    case 252:
        if (nIndex == 491 || nIndex == 490)
            PLRINTRO_SetQuestIntroFlag(pArgs->pPlayer, pArgs->pGame, nNpcId);
        break;
    case 255:
        if (nIndex == 515 || nIndex == 514)
            PLRINTRO_SetQuestIntroFlag(pArgs->pPlayer, pArgs->pGame, nNpcId);
        break;
    case 297:
        if (nIndex == 453)
            PLRINTRO_SetQuestIntroFlag(pArgs->pPlayer, pArgs->pGame, nNpcId);
        break;
    case 245:
        if (nIndex == 458)
            PLRINTRO_SetQuestIntroFlag(pArgs->pPlayer, pArgs->pGame, nNpcId);
        break;
    }
}
