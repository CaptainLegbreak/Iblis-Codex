#include "D2Game.h"
#include "D2Structs.h"

struct D2SeedStrc;
struct D2SkillsTxt;
struct D2ItemsTxt;
struct D2BooksTxt;
struct D2BookDataTbl;
struct D2SetItemsTxt;



D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc*); // 0x00627D90
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc*); // 0x00451F50
void* __fastcall sub_004DC0B0_GetUnitMemoryPool(D2UnitStrc*); // 0x004DC0B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc*, int, int); // 0x006257D0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void*, unsigned int, unsigned int, int, int); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc*, int, int, int); // 0x00627150

struct D2SkillsTxt { char pad0[0x18]; short nItemType; char pad1[0x23C-0x1A]; };

struct D2DataTablesStrc
{
    char pad0[0xB98];
    D2SkillsTxt* pSkills;
    void* pSkillsLinker;
    int nSkillsCount;
    unsigned char unk_BA4[0x74];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc*); // 0x0062A670
int __stdcall ITEMS_GetItemQuality(D2UnitStrc*); // 0x00627E70
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc*, int); // 0x00629BB0

struct D2ItemsTxt
{
    char unk0x00[0x80];
    int dwCode;
};

struct D2BooksTxt
{
    unsigned short wStr;
    unsigned char nSpellIcon;
    unsigned char pad0x03;
    unsigned int dwPSpell;
    int dwScrollSkillId;
    int dwBookSkillId;
    unsigned int dwBaseCost;
    unsigned int dwCostPerCharge;
    int dwScrollSpellCode;
    int dwBookSpellCode;
};

struct D2BookDataTbl
{
    int nBooksTxtRecordCount;
    D2BooksTxt* pBooksTxt;
};

D2BookDataTbl* __fastcall DATATBLS_GetBookDataTables(); // 0x006374A0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

struct D2ItemDropStrc
{
    char unk0x00[0x40];
    unsigned int nItemIndex;
    char unk0x44[0x3C];
    unsigned int dwFlags2;
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __stdcall sub_005C2740_RollLegacySetItem(D2UnitStrc* pItem); // 0x005C2740
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0
void __stdcall sub_0065FEC0_ItemApplyProps(int nPass, int nArg1, D2UnitStrc* pItem, void* pProperty, int nArg2, int nArg5); // 0x0065FEC0
static __declspec(noinline) int __stdcall sub_005C25C0_RollSetItemRecord(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem);

static __forceinline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return (unsigned int)nSeed;
}

static __forceinline D2SkillsTxt* GetSkillsRecord(int nSkill)
{
    if (nSkill >= 0 && nSkill < sgptDataTables->nSkillsCount)
        return &sgptDataTables->pSkills[nSkill];
    return 0;
}

// 0x005C0F90
void __stdcall ITEMS_AssignModernStaffMods(D2UnitStrc* pUnit, int nItemLvl, int nClassFirstSkillId, int nItemDropLvl)
{
    int skillIds[3] = { -1, -1, -1 };
    int nRand = nItemDropLvl + RollSeed(ITEMS_GetItemSeed(pUnit)) % 100;
    int nCount = 0;
    if (nRand > 90)
    {
        nCount = 3;
    }
    else if (nRand > 70)
    {
        nCount = 2;
    }
    else if (nRand > 30 || nItemDropLvl)
    {
        nCount = 1;
    }
    else
    {
        return;
    }

    int nBase = 1;
    if (nItemLvl > 36 && ITEMS_GetItemFormat(pUnit) >= 100u)
    {
        nBase = 5;
    }
    else if (nItemLvl > 24)
    {
        nBase = 4;
    }
    else if (nItemLvl > 18)
    {
        nBase = 3;
    }
    else if (nItemLvl > 11)
    {
        nBase = 2;
    }

    for (int j = 0; j < nCount; ++j)
    {
        nRand = RollSeed(ITEMS_GetItemSeed(pUnit)) % 100;
        int nBaseLayer = 0;
        if (nRand > 80)
        {
            nBaseLayer = nBase + 1;
        }
        else if (nRand > 30)
        {
            nBaseLayer = nBase;
        }
        else if (nRand > 10)
        {
            nBaseLayer = nBase - 1;
        }
        else
        {
            nBaseLayer = nBase - 2;
        }

        if (nBaseLayer < 1)
        {
            nBaseLayer = 1;
        }

        if (ITEMS_GetItemQuality(pUnit) == 1 && nBaseLayer >= 4)
        {
            nBaseLayer = 4;
        }

        int nSkillId;
        int nTries = 6;
        do
        {
            const int nRoll = RollSeed(ITEMS_GetItemSeed(pUnit)) % 5;
            nSkillId = nRoll + 5 * (nBaseLayer - 1) + nClassFirstSkillId;

            D2SkillsTxt* pSkillsTxtRecord = GetSkillsRecord(nSkillId);
            if (!pSkillsTxtRecord || pSkillsTxtRecord->nItemType <= 0 || ITEMS_CheckItemTypeId(pUnit, pSkillsTxtRecord->nItemType))
            {
                if (nSkillId != skillIds[0] && nSkillId != skillIds[1] && nSkillId != skillIds[2])
                {
                    skillIds[j] = nSkillId;
                    break;
                }
                --nTries;
            }
            else
            {
                --nTries;
            }
        }
        while (nTries > 0);

        int nValue = 1;
        if (ITEMS_GetItemFormat(pUnit) < 100u || ITEMS_GetItemQuality(pUnit) != 1)
        {
            nRand = nItemDropLvl / 2 + RollSeed(ITEMS_GetItemSeed(pUnit)) % 100;
            if (nRand >= 90)
            {
                nValue = 3;
            }
            else if (nRand >= 60)
            {
                nValue = 2;
            }
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, 0, 0x40u);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(sub_004DC0B0_GetUnitMemoryPool(pUnit), 0x40u, 0, 4, sub_00451F50_GetUnitGUID(pUnit));
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        }

        if (pStatList)
        {
            STATLIST_SetStatIfListIsValid(pStatList, 107, nValue, nSkillId);
        }
    }
}

// 0x005C2540
int __fastcall ITEMS_FindBookRecordIndex(D2UnitStrc* pItem, int bScroll)
{
    D2BookDataTbl* pBookDataTbl = DATATBLS_GetBookDataTables();
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pBookDataTbl)
    {
        return -1;
    }

    if (!pItemsTxtRecord)
    {
        return pBookDataTbl->nBooksTxtRecordCount;
    }

    if (!pBookDataTbl->pBooksTxt)
    {
        return pBookDataTbl->nBooksTxtRecordCount;
    }

    int nIndex = -1;
    for (int i = 0; i < pBookDataTbl->nBooksTxtRecordCount; ++i)
    {
        if (bScroll)
        {
            if (pItemsTxtRecord->dwCode == pBookDataTbl->pBooksTxt[i].dwScrollSpellCode)
            {
                nIndex = i;
                break;
            }
        }
        else if (pItemsTxtRecord->dwCode == pBookDataTbl->pBooksTxt[i].dwBookSpellCode)
        {
            nIndex = i;
            break;
        }
    }

    if (nIndex < 0)
    {
        nIndex = pBookDataTbl->nBooksTxtRecordCount;
    }
    return nIndex;
}

// 0x005C25C0
static int __stdcall sub_005C25C0_RollSetItemRecord(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    int nLegibleSets = 0;
    int nAccumulatedRarity = 0;
    int nIndex = -1;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem ? pItem->dwClassId : -1);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const unsigned short nItemFormat = ITEMS_GetItemFormat(pItem);
    const unsigned int dwCode = pItemsTxtRecord->dwCode;
    const int nItemLevel = ITEMS_GetItemLevel(pItem);
    int rarityData[512];

    D2SetItemsTxt* pSetItemsTxtRecord = sgptDataTables->pSetItemsTxt;
    const int nCount = sgptDataTables->nSetItemsTxtRecordCount;
    int i = 0;
    if (nCount <= 0)
    {
        return 0;
    }

    do
    {
        if ((pSetItemsTxtRecord->wVersion < 100 || nItemFormat >= 100) && pSetItemsTxtRecord->wLvl <= nItemLevel
            && dwCode == pSetItemsTxtRecord->szItemCode
            && (pSetItemsTxtRecord->nSetId != 29 || pItemDrop->dwFlags2 & 1))
        {
            if (pItemDrop->nItemIndex > 0 && pItemDrop->nItemIndex - 1 == i)
            {
                nIndex = i;
            }

            rarityData[2 * nLegibleSets] = i;
            rarityData[2 * nLegibleSets + 1] = pSetItemsTxtRecord->dwRarity;
            if (!pSetItemsTxtRecord->dwRarity)
            {
                rarityData[2 * nLegibleSets + 1] = 1;
            }

            nAccumulatedRarity += rarityData[2 * nLegibleSets + 1];
            ++nLegibleSets;
        }
        ++i;
        ++pSetItemsTxtRecord;
    }
    while (i < nCount);

    int nFileIndex = nIndex;
    if (nIndex < 0)
    {
        if (!nAccumulatedRarity)
        {
            return 0;
        }

        int nChance = ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nAccumulatedRarity);
        int nCounter = 0;
        while (nCounter < nLegibleSets)
        {
            if (nChance < rarityData[2 * nCounter + 1])
            {
                if (nCounter < 0)
                {
                    return 0;
                }

                nFileIndex = rarityData[2 * nCounter];
                goto LBL_SET;
            }

            nChance -= rarityData[2 * nCounter + 1];
            ++nCounter;
        }

        return 0;
    }

LBL_SET:
    ITEMS_SetFileIndex(pItem, nFileIndex);
    ITEMS_SetItemFlag(pItem, 0x10, 0);
    sub_0065FEC0_ItemApplyProps(4, 0, pItem, 0, 0, 0);
    return 1;
}

int __fastcall sub_005C2940_RollSetItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return sub_005C25C0_RollSetItemRecord(pItemDrop, pItem);
    }

    return sub_005C2740_RollLegacySetItem(pItem);
}
