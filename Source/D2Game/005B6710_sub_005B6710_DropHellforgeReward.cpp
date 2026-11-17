struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2GameStrc { char unk_00[0x6D]; unsigned char nDifficulty; char unk_6E[2]; int bExpansion; char unk_74[0x34]; int dwGameFrame; };
struct D2UnitStrc { char unk_00[0xB8]; unsigned int dwDropItemCode; };
struct D2Act4Quest3Strc { char unk_00[3]; unsigned char bDropActive; unsigned char bChangeMode; char unk_05[3]; int nDropStage; char unk_0C[8]; int nDropCount; };
struct D2QuestDataStrc { int nQuestNo; D2GameStrc* pGame; char f_8[0x10]; D2Act4Quest3Strc* pQuestDataEx; };
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc*); // 0x005438B0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc*, D2UnitStrc*, int, int*, void*, int, int); // 0x00559A30
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0
extern unsigned int gnHellforgeRunesNormal_0073E114[]; // 0x0073E114
extern unsigned int gnHellforgeRunesNightmare_0073E514[]; // 0x0073E514
extern unsigned int gnHellforgeRunesHell_0073E540[]; // 0x0073E540
extern unsigned int gnHellforgeGemsFirst_0073E56C[]; // 0x0073E56C
extern unsigned int gnHellforgeGemsMiddle_0073E588[]; // 0x0073E588
extern unsigned int gnHellforgeGemsLast_0073E5A4[]; // 0x0073E5A4
static __forceinline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 seed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(seed >> 32);
    pSeed->nLowSeed = (unsigned int)seed;
    return (unsigned int)seed;
}
// 0x005B6710
void __fastcall sub_005B6710_DropHellforgeReward(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act4Quest3Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (pQuestDataEx->bChangeMode) UNITS_ChangeAnimMode(pUnit, 4);
    if (pQuestDataEx->bDropActive)
    {
        int nItemLevel = 50;
        int nDropped = 0;
        for (int i = 0; i < pQuestDataEx->nDropCount; ++i)
        {
            switch (pQuestDataEx->nDropStage)
            {
            case 4: pUnit->dwDropItemCode = gnHellforgeGemsFirst_0073E56C[RollSeed(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7]; break;
            case 2:
            case 3: pUnit->dwDropItemCode = gnHellforgeGemsMiddle_0073E588[RollSeed(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7]; break;
            case 1: pUnit->dwDropItemCode = gnHellforgeGemsLast_0073E5A4[RollSeed(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7]; break;
            default: return;
            }
            if (D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pUnit, 2, &nItemLevel, 0, -1, 0)) ++nDropped;
        }
        if (!nDropped) return;
        --pQuestDataEx->nDropStage;
        if (pQuestDataEx->nDropStage <= 0)
        {
            pQuestDataEx->bDropActive = 0;
            if (pQuestData->pGame->bExpansion)
            {
                unsigned int* pCodes = gnHellforgeRunesNormal_0073E114;
                switch (pQuestData->pGame->nDifficulty)
                {
                case 1: pCodes = gnHellforgeRunesNightmare_0073E514; break;
                case 2: pCodes = gnHellforgeRunesHell_0073E540; break;
                }
                pUnit->dwDropItemCode = pCodes[SEED_RollLimitedRandomNumber(QUESTS_GetGlobalSeed(pQuestData->pGame), 11)];
                D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pUnit, 2, &nItemLevel, 0, -1, 0);
            }
        }
        else
            EVENT_SetEvent(pQuestData->pGame, pUnit, 7, pQuestData->pGame->dwGameFrame + 20, 0, 0);
    }
}

#include "gen/data/Source/D2Game/005B6710_sub_005B6710_DropHellforgeReward.inc"
