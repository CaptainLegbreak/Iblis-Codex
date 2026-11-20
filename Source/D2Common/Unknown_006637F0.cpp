#include "D2Common.h"
#include "D2Path.h"
#include "D2Records.h"
#include "D2LevelTxt.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
union D2SeedStrc;
struct D2HirelingTxt;
struct D2HirelingInitStrc;
struct D2SetItemsTxt;



struct D2HirelingInitStrc
{
    int nId;
    int nLevel;
    int nHitpoints;
    int nStrength;
    int nDexterity;
    int nGold;
    int nExperience;
    int nDefense;
    int nMinDamage;
    int nMaxDamage;
    int nShare;
    int nResist;
    int nHireDesc;
    int field_34;
    short nFlags;
    short unk0x3A;
};

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed); // 0x00650E40
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromActAndDifficulty(int bExpansion, int nAct, int nDifficulty, D2HirelingTxt* pOldRecord); // 0x00656580


int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480


extern const int gnItemSetStates[]; // 0x006EE424
extern const int gnSetMaskToBonusMappingTable[]; // 0x006EE440
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
D2SetItemsTxt* __stdcall ITEMS_GetSetItemsTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062A490
int __stdcall ITEMS_GetNoOfSetItemsFromItem(D2UnitStrc* pItem); // 0x0062B3A0
int __stdcall D2Common_10574(D2UnitStrc* pUnit, int nStateId, int bSet); // 0x006279A0

static __forceinline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

// 0x006637F0
int __fastcall MONSTERS_HirelingInit(int bExpansion, D2UnitStrc* pMonster, int nLowSeed, int nAct, int nDifficulty, D2HirelingInitStrc* pHirelingInit)
{
    D2HirelingTxt* pRecords[16];
    D2SeedStrc tSeed;

    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, nLowSeed);

    int nEntries = 0;
    D2HirelingTxt* pRecord = 0;
    pRecords[0] = 0;
    while (1)
    {
        pRecord = DATATBLS_GetNextHirelingTxtRecordFromActAndDifficulty(bExpansion, nAct, nDifficulty, pRecord);
        if (!pRecord)
        {
            break;
        }
        pRecords[nEntries] = pRecord;
        ++nEntries;
    }

    if (!nEntries)
    {
        return 0;
    }

    D2HirelingTxt* pHirelingTxtRecord = pRecords[ITEMS_RollLimitedRandomNumber(&tSeed, nEntries)];
    pHirelingInit->nId = pHirelingTxtRecord->nId;

    const int nBaseLevel = STATLIST_UnitGetStatValue(pMonster, 12, 0) - 5;
    int nLevel = nBaseLevel + (unsigned int)SEED_RollRandomNumber(&tSeed) % 5;
    if (nLevel < 2)
    {
        nLevel = 2;
    }

    const int nLevelUps = nLevel - pHirelingTxtRecord->nHirelingLevel;
    nLevel = pHirelingTxtRecord->nHirelingLevel + nLevelUps;
    pHirelingInit->nLevel = nLevel;

    pHirelingInit->nHitpoints = pHirelingTxtRecord->dwHitpoints + nLevelUps * pHirelingTxtRecord->dwHitpointsPerLvl;
    pHirelingInit->nHitpoints = D2_MAX(pHirelingInit->nHitpoints, 40);

    pHirelingInit->nStrength = pHirelingTxtRecord->nStr + (nLevelUps * pHirelingTxtRecord->nStrPerLvl >> 3);
    pHirelingInit->nStrength = D2_MAX(pHirelingInit->nStrength, 10);

    pHirelingInit->nDexterity = pHirelingTxtRecord->nDex + (nLevelUps * pHirelingTxtRecord->nDexPerLvl >> 3);
    pHirelingInit->nDexterity = D2_MAX(pHirelingInit->nDexterity, 10);

    pHirelingInit->nGold = pHirelingTxtRecord->nGold * (15 * nLevelUps + 100) / 100;
    pHirelingInit->nGold = D2_MAX(pHirelingTxtRecord->nGold, pHirelingInit->nGold);

    pHirelingInit->nExperience = (nLevel + 1) * pHirelingTxtRecord->dwExpPerLvl * nLevel * nLevel;
    pHirelingInit->nExperience = D2_MAX(pHirelingInit->nExperience, 0);

    pHirelingInit->nDefense = pHirelingTxtRecord->dwDefense + nLevelUps * pHirelingTxtRecord->dwDefensePerLvl;
    pHirelingInit->nDefense = D2_MAX(pHirelingInit->nDefense, 0);

    pHirelingInit->nMinDamage = pHirelingTxtRecord->nDmgMin + (nLevelUps * pHirelingTxtRecord->nDmgPerLvl >> 3);
    pHirelingInit->nMinDamage = D2_MAX(pHirelingInit->nMinDamage, 0);

    pHirelingInit->nMaxDamage = pHirelingTxtRecord->nDmgMax + (nLevelUps * pHirelingTxtRecord->nDmgPerLvl >> 3);
    pHirelingInit->nMaxDamage = D2_MAX(pHirelingInit->nMaxDamage, 1);

    pHirelingInit->nShare = pHirelingTxtRecord->dwShare;
    pHirelingInit->nShare = D2_MAX(pHirelingInit->nShare, 0);

    pHirelingInit->nResist = pHirelingTxtRecord->dwResist;
    pHirelingInit->nResist = D2_MAX(pHirelingInit->nResist, 0);

    pHirelingInit->nHireDesc = pHirelingTxtRecord->nHireDesc;
    pHirelingInit->field_34 = 1;
    pHirelingInit->nFlags = 0;
    return 1;
}

// 0x00663A20
int __fastcall sub_00663A20_SetItemBonusStates(D2UnitStrc* pItem, unsigned int nSetItemMask)
{
    const int nType = pItem ? pItem->dwUnitType : 6;
    if (nType == 4 && ITEMS_GetItemQuality(pItem) == 5)
    {
        const D2SetItemsTxt* pSetItemsTxt = ITEMS_GetSetItemsTxtRecordFromItem(pItem);
        if (pSetItemsTxt)
        {
            switch (pSetItemsTxt->nAddFunc)
            {
            case 0:
                return 0;

            case 1:
            {
                const int nSetItems = ITEMS_GetNoOfSetItemsFromItem(pItem);
                for (int i = 0; i < 6; ++i)
                {
                    int nIndex = i;
                    if (i != nSetItems)
                    {
                        if (i > nSetItems)
                        {
                            nIndex -= 1;
                        }

                        if ((1 << i) & nSetItemMask)
                        {
                            D2Common_10574(pItem, gnItemSetStates[nIndex], 0);
                        }
                        else
                        {
                            D2Common_10574(pItem, gnItemSetStates[nIndex], 1);
                        }
                    }
                }
                break;
            }

            case 2:
            {
                const int nBonuses = (nSetItemMask >= 0x40 ? 0 : gnSetMaskToBonusMappingTable[nSetItemMask]) - 1;

                for (int i = 0; i < nBonuses; ++i)
                {
                    D2Common_10574(pItem, gnItemSetStates[i], 0);
                }

                if (nBonuses >= 5)
                {
                    return 1;
                }

                for (int i = nBonuses; i < 5; ++i)
                {
                    D2Common_10574(pItem, gnItemSetStates[i], 1);
                }
                break;
            }
            }

            return 1;
        }
    }

    return 0;
}

#include "gen/data/Source/D2Common/Unknown_006637F0.inc"
