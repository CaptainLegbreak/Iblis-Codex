#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2InventoryStrc;
struct D2BitBufferStrc;

struct D2ItemDataStrc
{
    int dwQualityNo;
    unsigned int pSeed[2];
    int dwOwnerGUID;
    unsigned int dwInitSeed;
    unsigned int dwCommandFlags;
    unsigned int dwItemFlags;
};




struct D2ItemTypesTxt
{
    char unk0x00[0x1F];
    unsigned char nStaffMods;
    char unk0x20[0xE4 - 0x20];
};





struct D2BooksTxt
{
    char unk0x00[0x14];
    int dwCostPerCharge;
};

struct D2MagicAffixTxt
{
    char unk0x00[0x88];
    int dwMultiply;
    int dwAdd;
};

struct D2UniqueItemsTxt
{
    char unk0x00[0x7C];
    int dwCostMult;
    int dwCostAdd;
};

struct D2SetItemsTxt
{
    char unk0x00[0x38];
    int dwCostMult;
    int dwCostAdd;
};

struct D2NpcTxt
{
    int dwNpc;
    int dwSellMult;
    int dwBuyMult;
    int dwRepMult;
    int dwQuestFlag[3];
    int dwQuestSellMult[3];
    int dwQuestBuyMult[3];
    int dwQuestRepMult[3];
    int nMaxBuy[3];
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);                                         // 0x00625E00
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize);     // 0x006261D0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefixNo);                               // 0x00627EC0
unsigned short __stdcall ITEMS_GetAutoAffix(D2UnitStrc* pItem);                                             // 0x00627F20
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo);                               // 0x00627F80
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem);                                               // 0x00628110
unsigned char __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem);                                               // 0x006283A0
unsigned int __stdcall ITEMS_GetNormalCode(D2UnitStrc* pItem);                                              // 0x006287D0
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                    // 0x006289F0
int __fastcall sub_00628D30_GetChargedSkillsCost(D2UnitStrc* pItem, int nBaseCost);                         // 0x00628D30
void __fastcall sub_00628E70_AddBonusStatsCost(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost, unsigned int nDivisor); // 0x00628E70
int __stdcall STATLIST_GetFullStatsDataFromUnit(D2UnitStrc* pUnit, D2StatStrc* pStatBuffer, int nBufferSize); // 0x00625C30
int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625560
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);                                                       // 0x00629930
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
int __stdcall ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem);                                              // 0x0062A0F0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670
int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem);                                                          // 0x0062A8D0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
int __stdcall ITEMS_IsClassValid(D2UnitStrc* pItem);                                                        // 0x0062C060
int __stdcall ITEMS_IsRepairable(D2UnitStrc* pItem);                                                        // 0x0062E660
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem);                                                       // 0x0062E740
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode);                                          // 0x00633680
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex);                                     // 0x00633EE0
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex);                                               // 0x006374B0
D2NpcTxt* __stdcall DATATBLS_GetNpcTxtRecord(int nNpcId);                                                   // 0x00656900
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex);                                    // 0x00483440
D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int nIndex);                              // 0x00483470
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
static int __stdcall sub_00629370_GetGambleCost(D2UnitStrc* pItem, int nLevel);                             // 0x00629370
static void __stdcall sub_006292F0_AddSocketablesCost(int* pSellCost, int* pBuyCost, int* pRepCost, D2UnitStrc* pItem); // 0x006292F0
static void __stdcall sub_0062EDD0_AddItemSkillCost(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost, unsigned int nDivisor); // 0x0062EDD0


inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline int ITEMS_CheckItemFlagInl(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwItemFlags & dwFlag;
    }

    return 0;
}

// 0x00627E70
__declspec(noinline) int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return 2;
}

__declspec(noinline) static int __stdcall sub_00629370_GetGambleCost(D2UnitStrc*,int);
// 0x00629370
static int __stdcall sub_00629370_GetGambleCost(D2UnitStrc* pItem, int nLevel)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(DATATBLS_GetItemIdFromItemCode(ITEMS_GetNormalCode(pItem)));
    D2_ASSERT(pItemsTxtRecord, 2842);

    const unsigned int dwUberCode = pItemsTxtRecord->dwUberCode;
    const unsigned int dwUltraCode = pItemsTxtRecord->dwUltraCode;
    int nUberItemId = 0;
    int nUltraItemId = 0;
    int nUberChance = 0;
    int nUltraChance = 0;
    int nUberCost = 0;
    int nUltraCost = 0;

    if (pItemsTxtRecord->dwCode == ' nir' || pItemsTxtRecord->dwCode == ' uma')
    {
        return pItemsTxtRecord->dwGambleCost;
    }

    const int nStack = pItemsTxtRecord->dwMaxStack + pItemsTxtRecord->dwMinStack;
    int nCount = nStack / 2;
    if (nCount < 1)
    {
        nCount = 1;
    }

    const int nBaseCost = nCount * (unsigned int)pItemsTxtRecord->dwCost;
    const int nItemLevel = pItemsTxtRecord->nLevel;

    if (dwUberCode && pItemsTxtRecord->dwUberCode != '   0')
    {
        D2ItemsTxt* pUberItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwUberCode, &nUberItemId);
        if (pUberItemsTxtRecord)
        {
            nUberChance = 100 * (nLevel - pUberItemsTxtRecord->nLevel) / 2 + 1;
            if (nUberChance < 0)
            {
                nUberChance = 0;
            }
            nUberCost = (unsigned int)pUberItemsTxtRecord->dwCost;
        }
    }

    if (dwUltraCode && pItemsTxtRecord->dwUltraCode != '   0')
    {
        D2ItemsTxt* pUltraItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwUltraCode, &nUltraItemId);
        if (pUltraItemsTxtRecord)
        {
            nUltraChance = 100 * (nLevel - pUltraItemsTxtRecord->nLevel) / 4 + 1;
            if (nUltraChance < 0)
            {
                nUltraChance = 0;
            }
            nUltraCost = (unsigned int)pUltraItemsTxtRecord->dwCost;
        }
    }

    const int nBase = (nUberChance * nUberCost + nUltraChance * nUltraCost + nBaseCost * (10000 - nUltraChance - nUberChance)) / 10000;
    if (nLevel <= 5)
    {
        nLevel = 5;
    }

    return ((2 * nLevel + 1) / 3 + 20) * (nBase + (250 * (nLevel + ((nItemLevel - 45) < 0 ? 0 : (nItemLevel - 45)) - nItemLevel / 2)) / 3) / 15;
}

__declspec(noinline) static void __stdcall sub_006292F0_AddSocketablesCost(int*,int*,int*,D2UnitStrc*);

// build: context sub_006292F0_AddSocketablesCost
static void __stdcall sub_006292F0_AddSocketablesCost(int* pSellCost, int* pBuyCost, int* pRepCost, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pItem->pInventory;
    int nSell = 0;
    int nBuy = 0;
    int nRep = 0;

    if (pInventory)
    {
        D2UnitStrc* pSocketable = INVENTORY_GetFirstItem(pInventory);
        while (pSocketable)
        {
            D2UnitStrc* pCurrent = INVENTORY_UnitIsItem(pSocketable);
            pSocketable = INVENTORY_GetNextItem(pSocketable);
            if (pCurrent)
            {
                const int nCost = DATATBLS_GetItemsTxtRecord(pCurrent->dwClassId)->dwCost / 2;
                nSell += nCost;
                nBuy += nCost;
                nRep += nCost;
            }
        }

        *pSellCost += nSell;
        *pBuyCost += nBuy;
        *pRepCost += nRep;
    }
}

void __stdcall ITEMMODS_GetByTimeAdjustment(int,int,int,int*,int*,int*); // 0x0065CA30
__declspec(noinline) void __fastcall sub_00628E70_AddBonusStatsCost(D2UnitStrc*,int*,int*,int*,unsigned int);

// build: context sub_00628E70_AddBonusStatsCost
void __fastcall sub_00628E70_AddBonusStatsCost(D2UnitStrc* item,int* sell,int* buy,int* repair,unsigned int divisor)
{
    D2StatStrc stats[511];
    unsigned int saleAdd=0,buyAdd=0,repairAdd=0;
    int count=STATLIST_GetFullStatsDataFromUnit(item,stats,511);
    for(int index=0;index<count;++index)
    {
        int id=stats[index].nStat;
        int bonus=STATLIST_GetUnitStatBonus(item,id,stats[index].nLayer);
        if(!bonus || id<0 || id>=sgptDataTables->nItemStatCostTxtRecordCount) continue;
        D2ItemStatCostTxt* record=&sgptDataTables->pItemStatCostTxt[id];
        if(!record) continue;
        if(record->nValShift) bonus>>=record->nValShift;
        switch(record->nEncode)
        {
        case 1:
        {
            int skill=stats[index].nLayer;
            D2SkillsTxt* entry=0;
            if(skill>=0 && skill<sgptDataTables->nSkillsTxtRecordCount) entry=&sgptDataTables->pSkillsTxt[skill];
            if(!entry) break;
            if(bonus * *sell>65535 && entry->nCostMult)
            {
                saleAdd+=entry->nCostAdd+entry->nCostMult*(bonus * *sell/1024);
                buyAdd+=entry->nCostAdd+entry->nCostMult*(bonus * *buy/4096);
                repairAdd+=entry->nCostAdd+entry->nCostMult*(bonus * *repair/1024);
            }
            else
            {
                saleAdd+=entry->nCostAdd+bonus * *sell*entry->nCostMult/1024;
                buyAdd+=entry->nCostAdd+bonus*entry->nCostMult * *buy/4096;
                repairAdd+=entry->nCostAdd+bonus*entry->nCostMult * *repair/1024;
            }
            break;
        }
        case 2: case 3:
        {
            int skill=stats[index].nLayer>>sgptDataTables->nStuff;
            int value=stats[index].nLayer&sgptDataTables->nShiftedStuff;
            D2SkillsTxt* entry=0;
            if(skill>=0 && skill<sgptDataTables->nSkillsTxtRecordCount) entry=&sgptDataTables->pSkillsTxt[skill];
            if(value * *sell>65535 && entry->nCostMult)
            {
                saleAdd+=entry->nCostAdd+entry->nCostMult*(value * *sell/1024);
                buyAdd+=entry->nCostAdd+entry->nCostMult*(value * *buy/4096);
                repairAdd+=entry->nCostAdd+entry->nCostMult*(value * *repair/1024);
            }
            else
            {
                saleAdd+=entry->nCostAdd+value * *sell*entry->nCostMult/1024;
                buyAdd+=entry->nCostAdd+value*entry->nCostMult * *buy/4096;
                repairAdd+=entry->nCostAdd+value*entry->nCostMult * *repair/1024;
            }
            break;
        }
        case 4:
        {
            int period,min,max;
            ITEMMODS_GetByTimeAdjustment(bonus,0,0,&period,&min,&max);
            int value=(min+max)/2;
            if(value * *sell>65535 && record->dwMultiply)
            {
                saleAdd+=record->dwAdd+record->dwMultiply*(value * *sell/1024);
                buyAdd+=record->dwAdd+record->dwMultiply*(value * *buy/1024);
                repairAdd+=record->dwAdd+record->dwMultiply*(value * *repair/1024);
            }
            else
            {
                saleAdd+=record->dwAdd+value * *sell*record->dwMultiply/1024;
                buyAdd+=record->dwAdd+value*record->dwMultiply * *buy/1024;
                repairAdd+=record->dwAdd+value*record->dwMultiply * *repair/1024;
            }
            break;
        }
        default:
            if(bonus * *sell>65535 && record->dwMultiply)
            {
                saleAdd+=record->dwAdd+record->dwMultiply*(bonus * *sell/1024);
                buyAdd+=record->dwAdd+record->dwMultiply*(bonus * *buy/1024);
                repairAdd+=record->dwAdd+record->dwMultiply*(bonus * *repair/1024);
            }
            else
            {
                saleAdd+=record->dwAdd+bonus * *sell*record->dwMultiply/1024;
                buyAdd+=record->dwAdd+bonus*record->dwMultiply * *buy/1024;
                repairAdd+=record->dwAdd+bonus*record->dwMultiply * *repair/1024;
            }
            break;
        }
    }
    *sell+=saleAdd/divisor;*buy+=buyAdd/divisor;*repair+=repairAdd/divisor;
}

__declspec(noinline) static void __stdcall sub_0062EDD0_AddItemSkillCost(D2UnitStrc*,int*,int*,int*,unsigned int);
inline D2ItemTypesTxt* DATATBLS_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}

// 0x0062BBD0
int __stdcall ITEMS_GetStaffMods(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nStaffMods;
        }
    }

    return 7;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x0062EDD0
static void __stdcall sub_0062EDD0_AddItemSkillCost(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost, unsigned int nDivisor)
{
    D2StatStrc pStat[64];
    if (ITEMS_GetStaffMods(pItem) != 7)
    {
        unsigned int nSell = 0;
        unsigned int nBuy = 0;
        unsigned int nRep = 0;
        const int nStats = STATLIST_CopyStats(pItem, 107, pStat, 64);

        for (int i = 0; i < nStats; ++i)
        {
            const int nSkillId = pStat[i].nLayer;
            const int nValue = pStat[i].nValue;
            D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
            if (pSkillsTxtRecord)
            {
                    const int nFactor = 2 * nValue - 1;
                    if (*pSellCost > 65535 && pSkillsTxtRecord->nCostMult)
                    {
                        nSell += nFactor * (pSkillsTxtRecord->nCostAdd + *pSellCost * (pSkillsTxtRecord->nCostMult / 1024));
                        nBuy += nFactor * (pSkillsTxtRecord->nCostAdd + *pBuyCost * (pSkillsTxtRecord->nCostMult / 4096));
                        nRep += nFactor * (pSkillsTxtRecord->nCostAdd + *pRepCost * (pSkillsTxtRecord->nCostMult / 1024));
                    }
                    else
                    {
                        nSell += nFactor * (pSkillsTxtRecord->nCostAdd + pSkillsTxtRecord->nCostMult * *pSellCost / 1024);
                        nBuy += nFactor * (pSkillsTxtRecord->nCostAdd + pSkillsTxtRecord->nCostMult * *pBuyCost / 4096);
                        nRep += nFactor * (pSkillsTxtRecord->nCostAdd + pSkillsTxtRecord->nCostMult * *pRepCost / 1024);
                    }
            }
        }

        *pSellCost += nSell / nDivisor;
        *pBuyCost += nBuy / nDivisor;
        *pRepCost += nRep / nDivisor;
    }
}

// build: context sub_0062EFB0_CalculateTransactionCost
int __fastcall sub_0062EFB0_CalculateTransactionCost(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nVendorId, int nTransactionType)
{
    int nSellCost;
    int nBuyCost;
    int nRepCost;
    int nDivisor;

    if (!pPlayer || (pItem ? pItem->dwUnitType : 6) != UNIT_ITEM)
    {
        return 0x7FFFFFFF;
    }

    const int nLevel = STATLIST_UnitGetStatValue(pPlayer, 12, 0);

    if (nTransactionType == 3 && !ITEMS_IsRepairable(pItem))
    {
        return 0;
    }

    if (ITEMS_CheckItemFlagInl(pItem, 0x20000))
    {
        return 1;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);

    int nQuantity = STATLIST_UnitGetStatValue(pItem, 70, 0);
    if (nQuantity <= 0)
    {
        nQuantity = 1;
    }

    int nReducePricePct = STATLIST_UnitGetStatValue(pPlayer, 87, 0);
    if (nReducePricePct >= 99)
    {
        nReducePricePct = 99;
    }

    if (nTransactionType == 2)
    {
        if (ITEMS_GetItemFormat(pItem) >= 1)
        {
            int nCost = sub_00629370_GetGambleCost(pItem, nLevel);
            if (nReducePricePct)
            {
                nCost -= DATATBLS_ApplyRatio(nCost, nReducePricePct, 100);
            }
            return nCost;
        }

        return DATATBLS_GetItemsTxtRecord(DATATBLS_GetItemIdFromItemCode(ITEMS_GetNormalCode(pItem)))->dwGambleCost;
    }

    nRepCost = 0;
    nDivisor = 1;

    if (ITEMS_GetItemFlags(pItem) & 0x10000)
    {
        nSellCost = ITEMS_GetEarLevel(pItem) * pItemsTxtRecord->dwCost;
        nBuyCost = nSellCost;
    }
    else if (ITEMSIsA(pItem, 40))
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(ITEMS_GetFileIndex(pItem));
        nSellCost = pItemsTxtRecord->dwCost + (pMonStatsTxtRecord ? 8 * pMonStatsTxtRecord->nLevel[nDifficulty] : 0);
        nBuyCost = nSellCost;
    }
    else if (ITEMSIsA(pItem, 18))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2_ASSERT(pBooksTxtRecord, 3002);

        nSellCost = pBooksTxtRecord->dwCostPerCharge * nQuantity + pItemsTxtRecord->dwCost;
        nBuyCost = nSellCost;
    }
    else if (ITEMS_GetQuiverType(pItem))
    {
        nSellCost = pItemsTxtRecord->dwCost * nQuantity / 1024;
        nBuyCost = nSellCost;
        nRepCost = ITEMS_GetTotalMaxStack(pItem) * pItemsTxtRecord->dwCost / 1024;
    }
    else if (ITEMS_CheckIfStackable(pItem))
    {
        nSellCost = pItemsTxtRecord->dwCost;
        nBuyCost = nSellCost;
        nRepCost = nSellCost;

        nDivisor = ITEMS_GetTotalMaxStack(pItem) > 1 ? ITEMS_GetTotalMaxStack(pItem) : 1;
    }
    else
    {
        nSellCost = pItemsTxtRecord->dwCost;
        nRepCost = nSellCost;
        nBuyCost = nSellCost;
    }

    if (ITEMSIsA(pItem, 50))
    {
        const int nArmorClass = STATLIST_GetUnitBaseStat(pItem, 31, 0);
        if (pItemsTxtRecord->dwMaxAc - pItemsTxtRecord->dwMinAc + 1 != 0 && pItemsTxtRecord->dwMaxAc)
        {
            nSellCost = pItemsTxtRecord->dwCost * nArmorClass / pItemsTxtRecord->dwMaxAc;
            nBuyCost = pItemsTxtRecord->dwCost * nArmorClass / pItemsTxtRecord->dwMaxAc;
            nRepCost = pItemsTxtRecord->dwCost * nArmorClass / pItemsTxtRecord->dwMaxAc;
        }
    }

    const int bIdentified = ITEMS_CheckItemFlag(pItem, 0x10, 3044, ".\\ITEMS\\Items.cpp");
    const int bMagic = ITEMS_IsMagSetRarUniCrfOrTmp(pItem);
    const int nQuality = ITEMS_GetItemQuality(pItem);

    if (!bMagic)
    {
        sub_0062EDD0_AddItemSkillCost(pItem, &nSellCost, &nBuyCost, &nRepCost, nDivisor);
    }

    if (bIdentified)
    {
        int nSell = 0;
        int nBuy = 0;
        int nRep = 0;
        D2MagicAffixTxt* pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetAutoAffix(pItem));
        if (pMagicAffixTxtRecord)
        {
            int nRepAdd;
            if (nSellCost > 65535 && pMagicAffixTxtRecord->dwMultiply)
            {
                nSell = pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nSellCost / 1024);
                nBuy = pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nBuyCost / 1024);
                nRepAdd = pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nRepCost / 1024);
            }
            else
            {
                nSell = pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nSellCost / 1024;
                nBuy = pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nBuyCost / 1024;
                nRepAdd = pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nRepCost / 1024;
            }
            nRep = nRepAdd;
        }

        switch (nQuality)
        {
        case 6:
        case 8:
            for (int i = 0; i < 3; ++i)
            {
                pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, i));
                if (pMagicAffixTxtRecord)
                {
                    if (nSellCost > 65535 && pMagicAffixTxtRecord->dwMultiply)
                    {
                        nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nSellCost / 1024);
                        nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nBuyCost / 1024);
                        nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nRepCost / 1024);
                    }
                    else
                    {
                        nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nSellCost / 1024;
                        nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nBuyCost / 1024;
                        nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nRepCost / 1024;
                    }
                }

                pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, i));
                if (pMagicAffixTxtRecord)
                {
                    if (nSellCost > 65535 && pMagicAffixTxtRecord->dwMultiply)
                    {
                        nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nSellCost / 1024);
                        nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nBuyCost / 1024);
                        nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nRepCost / 1024);
                    }
                    else
                    {
                        nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nSellCost / 1024;
                        nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nBuyCost / 1024;
                        nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nRepCost / 1024;
                    }
                }
            }

            sub_00628E70_AddBonusStatsCost(pItem, &nSellCost, &nBuyCost, &nRepCost, nDivisor);
            break;

        case 7:
            if (ITEMS_GetFileIndex(pItem) >= 0)
            {
                D2UniqueItemsTxt* pUniqueItemsTxtRecord = sub_00483470_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (pUniqueItemsTxtRecord)
                {
                    if (nSellCost > 65535 && pUniqueItemsTxtRecord->dwCostMult)
                    {
                        nSell += pUniqueItemsTxtRecord->dwCostAdd + pUniqueItemsTxtRecord->dwCostMult * (nSellCost / 1024);
                        nBuy += pUniqueItemsTxtRecord->dwCostAdd + pUniqueItemsTxtRecord->dwCostMult * (nBuyCost / 1024);
                        nRep += pUniqueItemsTxtRecord->dwCostAdd + pUniqueItemsTxtRecord->dwCostMult * (nRepCost / 1024);
                    }
                    else
                    {
                        nSell += pUniqueItemsTxtRecord->dwCostAdd + pUniqueItemsTxtRecord->dwCostMult * nSellCost / 1024;
                        nBuy += pUniqueItemsTxtRecord->dwCostAdd + pUniqueItemsTxtRecord->dwCostMult * nBuyCost / 1024;
                        nRep += pUniqueItemsTxtRecord->dwCostAdd + pUniqueItemsTxtRecord->dwCostMult * nRepCost / 1024;
                    }
                    break;
                }
            }

        case 4:
            pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, 0));
            if (pMagicAffixTxtRecord)
            {
                if (nSellCost > 65535 && pMagicAffixTxtRecord->dwMultiply)
                {
                    nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nSellCost / 1024);
                    nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nBuyCost / 1024);
                    nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nRepCost / 1024);
                }
                else
                {
                    nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nSellCost / 1024;
                    nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nBuyCost / 1024;
                    nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nRepCost / 1024;
                }
            }

            pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, 0));
            if (pMagicAffixTxtRecord)
            {
                if (nSellCost > 65535 && pMagicAffixTxtRecord->dwMultiply)
                {
                    nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nSellCost / 1024);
                    nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nBuyCost / 1024);
                    nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nRepCost / 1024);
                }
                else
                {
                    nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nSellCost / 1024;
                    nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nBuyCost / 1024;
                    nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nRepCost / 1024;
                }
            }

        case 3:
        case 9:
            sub_00628E70_AddBonusStatsCost(pItem, &nSellCost, &nBuyCost, &nRepCost, nDivisor);
            break;

        case 5:
        {
            D2SetItemsTxt* pSetItemsTxtRecord = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (pSetItemsTxtRecord)
            {
                if (nSellCost > 65535 && pSetItemsTxtRecord->dwCostMult)
                {
                    nSell += pSetItemsTxtRecord->dwCostAdd + pSetItemsTxtRecord->dwCostMult * (nSellCost / 1024);
                    nBuy += pSetItemsTxtRecord->dwCostAdd + pSetItemsTxtRecord->dwCostMult * (nBuyCost / 1024);
                    nRep += pSetItemsTxtRecord->dwCostAdd + pSetItemsTxtRecord->dwCostMult * (nRepCost / 1024);
                }
                else
                {
                    nSell += pSetItemsTxtRecord->dwCostAdd + pSetItemsTxtRecord->dwCostMult * nSellCost / 1024;
                    nBuy += pSetItemsTxtRecord->dwCostAdd + pSetItemsTxtRecord->dwCostMult * nBuyCost / 1024;
                    nRep += pSetItemsTxtRecord->dwCostAdd + pSetItemsTxtRecord->dwCostMult * nRepCost / 1024;
                }
            }
            break;
        }

        case 1:
            nSell = nSellCost / -2;
            nBuy = nBuyCost / -2;
            nRep = nRepCost / -2;
            break;

        default:
            break;
        }

        nSellCost += nSell / nDivisor;
        nBuyCost += nBuy / nDivisor;
        nRepCost += nRep / nDivisor;

        if (bMagic)
        {
            sub_0062EDD0_AddItemSkillCost(pItem, &nSellCost, &nBuyCost, &nRepCost, nDivisor);
        }
    }

    sub_006292F0_AddSocketablesCost(&nSellCost, &nBuyCost, &nRepCost, pItem);

    if (ITEMS_CheckItemFlag(pItem, 0x400000, 3235, ".\\ITEMS\\Items.cpp"))
    {
        nBuyCost /= 4;
    }

    if (ITEMS_IsClassValid(pItem))
    {
        nBuyCost /= 4;
    }

    switch (nTransactionType)
    {
    case 1:
        if (ITEMS_IsEthereal(pItem) && ITEMS_HasDurability(pItem))
        {
            const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
            const int nDurability = STATLIST_UnitGetStatValue(pItem, 72, 0);
            if (nMaxDurability && nDurability <= 0)
            {
                nBuyCost = 0;
            }
        }
        break;

    case 3:
        if (!ITEMS_GetQuiverType(pItem) && !ITEMS_CheckIfThrowable(pItem) && ITEMS_HasDurability(pItem))
        {
            const int nDurability = STATLIST_UnitGetStatValue(pItem, 72, 0);
            const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
            if (nMaxDurability && nDurability < nMaxDurability)
            {
                if (STATLIST_UnitGetStatValue(pItem, 252, 0))
                {
                    if (nDurability >= nMaxDurability - 1)
                    {
                        nRepCost = 0;
                    }
                    else
                    {
                        nRepCost = (nMaxDurability - 1) * nRepCost / nMaxDurability;
                    }
                }
                else
                {
                    nRepCost = (nMaxDurability - nDurability) * nRepCost / nMaxDurability;
                }
            }
            else
            {
                nRepCost = 0;
            }
        }
        break;
    }

    D2NpcTxt* pNpcTxtRecord = DATATBLS_GetNpcTxtRecord(nVendorId);
    D2_ASSERT(pNpcTxtRecord, 3292);

    if (nSellCost > 65535 && pNpcTxtRecord->dwSellMult)
    {
        nSellCost = nSellCost / 1024 * pNpcTxtRecord->dwSellMult;
    }
    else
    {
        nSellCost = pNpcTxtRecord->dwSellMult * nSellCost / 1024;
    }

    if (nBuyCost > 65535 && pNpcTxtRecord->dwSellMult)
    {
        nBuyCost = nBuyCost / 1024 * pNpcTxtRecord->dwBuyMult;
    }
    else
    {
        nBuyCost = pNpcTxtRecord->dwBuyMult * nBuyCost / 1024;
    }

    if (nRepCost > 65535 && pNpcTxtRecord->dwRepMult)
    {
        nRepCost = nRepCost / 1024 * pNpcTxtRecord->dwRepMult;
    }
    else
    {
        nRepCost = pNpcTxtRecord->dwRepMult * nRepCost / 1024;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (pNpcTxtRecord->dwQuestFlag[i] && (QUESTRECORD_GetQuestState(pQuestFlags, pNpcTxtRecord->dwQuestFlag[i], 0) == 1
                                              || QUESTRECORD_GetQuestState(pQuestFlags, pNpcTxtRecord->dwQuestFlag[i], 1) == 1))
        {
            if (nSellCost > 65535 && pNpcTxtRecord->dwQuestSellMult[i])
            {
                nSellCost = nSellCost / 1024 * pNpcTxtRecord->dwQuestSellMult[i];
            }
            else
            {
                nSellCost = pNpcTxtRecord->dwQuestSellMult[i] * nSellCost / 1024;
            }

            if (nBuyCost > 65535 && pNpcTxtRecord->dwQuestBuyMult[i])
            {
                nBuyCost = nBuyCost / 1024 * pNpcTxtRecord->dwQuestBuyMult[i];
            }
            else
            {
                nBuyCost = pNpcTxtRecord->dwQuestBuyMult[i] * nBuyCost / 1024;
            }

            if (nRepCost > 65535 && pNpcTxtRecord->dwQuestRepMult[i])
            {
                nRepCost = nRepCost / 1024 * pNpcTxtRecord->dwQuestRepMult[i];
            }
            else
            {
                nRepCost = pNpcTxtRecord->dwQuestRepMult[i] * nRepCost / 1024;
            }
        }
    }

    if (!ITEMSIsA(pItem, 18) && !ITEMS_GetQuiverType(pItem))
    {
        nSellCost = nSellCost * nQuantity;

        if (ITEMS_CheckIfStackable(pItem) && ITEMS_IsRepairable(pItem))
        {
            const int nMaxStack = ITEMS_GetTotalMaxStack(pItem);
            if (nQuantity < nMaxStack && !STATLIST_UnitGetStatValue(pItem, 253, 0))
            {
                nRepCost *= nMaxStack - nQuantity;
            }
            else
            {
                nRepCost = 0;
            }

            nBuyCost = nMaxStack * nBuyCost - nRepCost;
        }
        else
        {
            nBuyCost = nBuyCost * nQuantity;
        }
    }

    if (nTransactionType == 3 && !ITEMS_IsEthereal(pItem))
    {
        nRepCost += sub_00628D30_GetChargedSkillsCost(pItem, 10000);
    }

    int nCost = nBuyCost;
    if (nCost > pNpcTxtRecord->nMaxBuy[nDifficulty])
    {
        nCost = pNpcTxtRecord->nMaxBuy[nDifficulty];
    }

    switch (nTransactionType)
    {
    case 1:
        return nCost < 1 ? 1 : nCost;

    case 3:
        if (nReducePricePct)
        {
            nRepCost -= DATATBLS_ApplyRatio(nRepCost, nReducePricePct, 100);
        }
        return nRepCost < 1 ? 1 : nRepCost;

    default:
        if (nReducePricePct)
        {
            nSellCost -= DATATBLS_ApplyRatio(nSellCost, nReducePricePct, 100);
        }
        return nSellCost < 1 ? 1 : nSellCost;
    }
}
