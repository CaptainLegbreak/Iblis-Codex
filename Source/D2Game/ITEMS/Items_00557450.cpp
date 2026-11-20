#include "D2Game.h"
#include "D2Structs.h"

struct D2SeedStrc;


struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2ItemsTxt
{
    char unk0x000[0xF8];
    unsigned short wAutoPrefix;
};

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    char unk0x04[0x2C];
    int nQuality;
    char unk0x34[0x0C];
    int nItemIndex;
    unsigned int dwFlags1;
    char unk0x48[0x20];
    int nPrefix[3];
    int nSuffix[3];
    unsigned int dwFlags2;
};

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __stdcall sub_005566B0_RollUniqueItem(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005566B0
int __stdcall ITEMS_RollItemQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);                          // 0x00556F60
unsigned short __fastcall sub_005C1BC0_RollTemperedAffix(D2UnitStrc* pItem, int bPrefix);                   // 0x005C1BC0
int __fastcall D2GAME_RollRareItem_6FC53360(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);                   // 0x005C21A0
int __fastcall sub_005C21D0_RollCraftedItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);                   // 0x005C21D0
int __fastcall ITEMS_FindBookRecordIndex(D2UnitStrc* pItem, int bScroll);                                   // 0x005C2540
int __fastcall sub_005C2940_RollSetItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);                       // 0x005C2940
int __fastcall ITEMS_RollSuperiorItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);                        // 0x005C2AD0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem);                                                 // 0x00627D90
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
void __stdcall ITEMS_SetItemQuality(D2UnitStrc* pItem, int nQuality);                                       // 0x00627EA0
void __stdcall ITEMS_AssignPrefix(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo);                // 0x00627EF0
void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix);                           // 0x00628010
void __stdcall ITEMS_AssignRareSuffix(D2UnitStrc* pItem, unsigned short nSuffix);                           // 0x00628070
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                         // 0x00628590
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                    // 0x006289F0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);                                                       // 0x00629930
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex);                             // 0x00629DF0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem);                                             // 0x0062BC20
void __stdcall ITEMS_AddSockets(D2UnitStrc* pItem, int nSockets);                                           // 0x0062BCB0
void* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex);                                                // 0x00633EE0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed);                                                 // 0x00650E50
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
void __stdcall sub_0065FEC0_ItemApplyProps(int nPass, int nArg1, D2UnitStrc* pItem, void* pProperty, int nArg2, int nArg5); // 0x0065FEC0

// build: symbol ?ITEMS_AssignDropMagicAffixes@@YGHPAUD2ItemDropStrc@@PAPAUD2UnitStrc@@@Z 0x005565E0
static int __stdcall ITEMS_AssignDropMagicAffixes(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem)
{
    const int nPrefixId = pItemDrop->nPrefix[0];
    int bForceSuffixRoll = 0;
    unsigned short nPrefix = 0;
    int bForcePrefixRoll = 0;
    unsigned short nSuffix = 0;
    if (nPrefixId < 0)
    {
        bForceSuffixRoll = 1;
    }
    else
    {
        if (nPrefixId > 0)
        {
            bForcePrefixRoll = 1;
        }

        nPrefix = ITEMS_RollMagicAffixes(*ppItem, 1, bForcePrefixRoll, 1, 1, nPrefixId);
        ITEMS_AssignPrefix(*ppItem, nPrefix, 0);
        if (!nPrefix)
        {
            bForceSuffixRoll = 1;
        }
    }

    if (bForceSuffixRoll || pItemDrop->nSuffix[0] >= 0)
    {
        if (pItemDrop->nSuffix[0] > 0)
        {
            bForceSuffixRoll = 1;
        }

        nSuffix = ITEMS_RollMagicAffixes(*ppItem, 1, bForceSuffixRoll, 1, 0, pItemDrop->nSuffix[0]);
        ITEMS_AssignSuffix(*ppItem, nSuffix, 0);
    }

    if (!nPrefix && !nSuffix)
    {
        return 0;
    }

    ITEMS_SetItemFlag(*ppItem, 0x10, 0);
    ITEMS_AssignStaffModsForFormat(*ppItem, pItemDrop);
    return 1;
}

// 0x00556A60
static int __stdcall ITEMS_AssignCharmAffixes(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    unsigned short nPrefix = 0;
    unsigned short nSuffix = 0;
    int nRand = 0;
    if (pItemDrop->nPrefix[0] > 0)
    {
        nPrefix = ITEMS_RollMagicAffixes(pItem, 1, 1, 1, 1, pItemDrop->nPrefix[0]);
        ITEMS_AssignPrefix(pItem, nPrefix, 0);
    }
    else if (pItemDrop->nSuffix[0] <= 0)
    {
        nSuffix = ITEMS_RollMagicAffixes(pItem, 1, 0, 1, 1, pItemDrop->nSuffix[0]);
        ITEMS_AssignPrefix(pItem, nSuffix, 0);
        if (!nSuffix)
        {
            nRand = 1;
        }
    }

    if (pItemDrop->nSuffix[0] > 0)
    {
        nSuffix = ITEMS_RollMagicAffixes(pItem, 1, 1, 1, 0, pItemDrop->nSuffix[0]);
        ITEMS_AssignSuffix(pItem, nSuffix, 0);
    }
    else if (pItemDrop->nPrefix[0] <= 0)
    {
        nPrefix = ITEMS_RollMagicAffixes(pItem, 1, nRand, 1, 0, pItemDrop->nPrefix[0]);
        ITEMS_AssignSuffix(pItem, nPrefix, 0);
    }

    if (!nPrefix && !nSuffix)
    {
        ITEMS_GetBaseCode(pItem);
        D2_ASSERT(0, 0x372);
    }

    ITEMS_SetItemFlag(pItem, 0x10, 0);
    return 1;
}

// 0x00556B60
static void __stdcall ITEMS_RollDropSockets(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMS_GetItemQuality(pItem) < 2)
    {
        return;
    }

    if (!ITEMS_CheckIfSocketable(pItem))
    {
        return;
    }

    if (ITEMS_CheckIfStackable(pItem))
    {
        return;
    }

    if (!ITEMS_GetMaxSockets(pItem))
    {
        return;
    }

    int nMaxSockets = ITEMS_GetMaxSockets(pItem);
    switch (pGame->nDifficulty)
    {
    case 0:
        if (nMaxSockets >= 3)
        {
            nMaxSockets = 3;
        }
        break;
    case 1:
        if (nMaxSockets >= 4)
        {
            nMaxSockets = 4;
        }
        break;
    case 2:
        if (nMaxSockets >= 6)
        {
            nMaxSockets = 6;
        }
        break;
    }

    if (nMaxSockets <= 0)
    {
        return;
    }

    if (ITEMS_GetItemFormat(pItem) >= 100 || !ITEMS_CheckItemTypeId(pItem, 3))
    {
        int nChance = SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), 100);
        if (pItemDrop->dwFlags2 & 8)
        {
            return;
        }

        if (pItemDrop->dwFlags2 & 0x10)
        {
            nChance = 0;
        }

        if ((pItemDrop->dwFlags1 & 0x800) || nChance < 33)
        {
            ITEMS_SetItemFlag(pItem, 0x800, 1);
            int nSockets;
            if (ITEMS_GetItemFormat(pItem) >= 1)
            {
                nSockets = ITEMS_GetItemStartSeed(pItem) % nMaxSockets + 1;
            }
            else
            {
                if (nMaxSockets > 3)
                {
                    nMaxSockets = 3;
                }

                if (ITEMS_CheckItemTypeId(pItem, 0x25) && nMaxSockets > 2)
                {
                    nMaxSockets = 2;
                }

                nSockets = nMaxSockets;
            }

            ITEMS_AddSockets(pItem, nSockets);
        }
    }
}

// 0x00556CA0
static void ITEMS_MakeEthereal(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (pItemDrop->dwFlags2 & 2)
    {
        return;
    }

    if (!ITEMS_CheckItemTypeId(pItem, 0x2D) && !ITEMS_CheckItemTypeId(pItem, 0x32))
    {
        return;
    }

    if (!ITEMS_HasDurability(pItem))
    {
        return;
    }

    switch (ITEMS_GetItemQuality(pItem))
    {
    case 1:
    case 5:
        return;
    }

    if (ITEMS_IsQuestItem(pItem))
    {
        return;
    }

    int bApplyEthereality = 0;
    const int nRoll = SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), 100);
    if (nRoll < 5)
    {
        bApplyEthereality = 1;
    }

    if (pItemDrop->dwFlags1 & 0x400000)
    {
        bApplyEthereality = 1;
    }

    if ((pItemDrop->dwFlags2 & 4) || bApplyEthereality)
    {
        ITEMMODS_ApplyEthereality(pItem);
        if (ITEMS_HasDurability(pItem))
        {
            const int nMaxDurability = STATLIST_GetUnitBaseStat(pItem, 0x49, 0) / 2 + 1;
            STATLIST_SetUnitStat(pItem, 0x49, nMaxDurability, 0);
            const int nDurability = STATLIST_UnitGetStatValue(pItem, 0x49, 0);
            STATLIST_SetUnitStat(pItem, 0x48, nDurability, 0);
        }
    }
}

// 0x00556D80
static void __stdcall ITEMS_AssignLegacySpecialProperties(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    switch (ITEMS_GetItemType(pItem))
    {
    case 13:
        ITEMS_AssignCharmAffixes(pItemDrop, pItem);
        break;
    case 40:
    {
        int nItemIndex = pItemDrop->nItemIndex;
        if (pItemDrop->pUnit)
        {
            nItemIndex = pItemDrop->pUnit->dwClassId;
        }

        ITEMS_SetFileIndex(pItem, nItemIndex);
        break;
    }
    case 7:
    {
        int nItemIndex = pItemDrop->nItemIndex;
        if (pItemDrop->pUnit)
        {
            nItemIndex = pItemDrop->pUnit->dwClassId;
        }

        ITEMS_SetFileIndex(pItem, nItemIndex);
        ITEMS_SetItemFlag(pItem, 0x10000, 1);
        break;
    }
    case 22:
        ITEMS_AssignSuffix(pItem, ITEMS_FindBookRecordIndex(pItem, 1), 0);
        break;
    case 18:
        ITEMS_AssignSuffix(pItem, ITEMS_FindBookRecordIndex(pItem, 0), 0);
        break;
    default:
        ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
        ITEMS_RollDropSockets(pGame, pItem, pItemDrop);
        break;
    }
}

// 0x00556E80
static void D2GAME_ITEMS_AssignSpecial_6FC4DB60(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMS_CheckItemTypeId(pItem, 13))
    {
        ITEMS_AssignCharmAffixes(pItemDrop, pItem);
    }

    if (ITEMS_CheckItemTypeId(pItem, 40))
    {
        int nItemIndex = pItemDrop->nItemIndex;
        if (pItemDrop->pUnit)
        {
            nItemIndex = pItemDrop->pUnit->dwClassId;
        }

        ITEMS_SetFileIndex(pItem, nItemIndex);
    }

    if (ITEMS_CheckItemTypeId(pItem, 7))
    {
        int nItemIndex = pItemDrop->nItemIndex;
        if (pItemDrop->pUnit)
        {
            nItemIndex = pItemDrop->pUnit->dwClassId;
        }

        ITEMS_SetFileIndex(pItem, nItemIndex);
        ITEMS_SetItemFlag(pItem, 0x10000, 1);
    }

    if (ITEMS_CheckItemTypeId(pItem, 22))
    {
        ITEMS_AssignSuffix(pItem, ITEMS_FindBookRecordIndex(pItem, 1), 0);
    }

    if (ITEMS_CheckItemTypeId(pItem, 18))
    {
        ITEMS_AssignSuffix(pItem, ITEMS_FindBookRecordIndex(pItem, 0), 0);
    }

    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
}

// build: symbol ?ITEMS_AssignSpecialPropertiesForFormat@@YGXPAUD2GameStrc@@PAUD2UnitStrc@@PAUD2ItemDropStrc@@@Z 0x00556F30
static void __stdcall ITEMS_AssignSpecialPropertiesForFormat(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (!ITEMS_GetItemFormat(pItem))
    {
        ITEMS_AssignLegacySpecialProperties(pGame, pItem, pItemDrop);
    }
    else
    {
        D2GAME_ITEMS_AssignSpecial_6FC4DB60(pItem, pItemDrop);
    }
}

// 0x00557250
static void ITEMS_ClearAffixesAndFileIndex(D2UnitStrc** ppItem)
{
    for (int i = 0; i < 3; i += 1)
    {
        ITEMS_AssignPrefix(*ppItem, 0, i);
        ITEMS_AssignSuffix(*ppItem, 0, i);
    }

    ITEMS_AssignRarePrefix(*ppItem, 0);
    ITEMS_AssignRareSuffix(*ppItem, 0);
    ITEMS_SetFileIndex(*ppItem, -1);
}

// 0x005572A0
static void __stdcall ITEMS_ResetToNormalQuality(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int nLowSeed)
{
    ITEMS_ClearAffixesAndFileIndex(ppItem);
    ITEMS_SetItemStartSeed(*ppItem, nLowSeed);
    SEED_InitLowSeed(ITEMS_GetItemSeed(*ppItem), nLowSeed);
    ITEMS_RollItemQuality(*ppItem, pItemDrop);
    ITEMS_SetItemQuality(*ppItem, 2);
    pItemDrop->nQuality = 2;
    ITEMS_AssignSpecialPropertiesForFormat(pGame, *ppItem, pItemDrop);
}

// 0x00557320
static int ITEMS_ResetToSuperiorQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed)
{
    ITEMS_ClearAffixesAndFileIndex(ppItem);
    ITEMS_SetItemStartSeed(*ppItem, *pLowSeed);
    SEED_InitLowSeed(ITEMS_GetItemSeed(*ppItem), *pLowSeed);
    ITEMS_RollItemQuality(*ppItem, pItemDrop);
    ITEMS_SetItemQuality(*ppItem, 3);
    pItemDrop->nQuality = 3;
    *pLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
    return ITEMS_RollSuperiorItem(*ppItem, pItemDrop);
}

// 0x00557380
static int __stdcall sub_00557380_ResetToMagicQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed)
{
    ITEMS_ClearAffixesAndFileIndex(ppItem);
    ITEMS_SetItemStartSeed(*ppItem, *pLowSeed);
    SEED_InitLowSeed(ITEMS_GetItemSeed(*ppItem), *pLowSeed);
    ITEMS_RollItemQuality(*ppItem, pItemDrop);
    ITEMS_SetItemQuality(*ppItem, 4);
    pItemDrop->nQuality = 4;
    *pLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
    return ITEMS_AssignDropMagicAffixes(pItemDrop, ppItem);
}

// 0x005573F0
static int sub_005573F0_ResetToRareQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed)
{
    ITEMS_ClearAffixesAndFileIndex(ppItem);
    ITEMS_SetItemStartSeed(*ppItem, *pLowSeed);
    SEED_InitLowSeed(ITEMS_GetItemSeed(*ppItem), *pLowSeed);
    ITEMS_RollItemQuality(*ppItem, pItemDrop);
    ITEMS_SetItemQuality(*ppItem, 6);
    pItemDrop->nQuality = 6;
    *pLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
    return D2GAME_RollRareItem_6FC53360(*ppItem, pItemDrop);
}

// 0x00557450
int __fastcall ITEMMODE_AssignItemQualityAndProperties(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop)
{
    D2UnitStrc* pItem = *ppItem;
    if (!pItem || (!pItem ? 6 : pItem->dwUnitType) != 4)
    {
        return 0;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    ITEMS_SetAutoAffix(*ppItem, 0);
    for (int i = 0; i < 3; ++i)
    {
        ITEMS_AssignPrefix(*ppItem, 0, i);
        ITEMS_AssignSuffix(*ppItem, 0, i);
    }

    ITEMS_AssignRarePrefix(*ppItem, 0);
    ITEMS_AssignRareSuffix(*ppItem, 0);

    int nQuality = ITEMS_RollItemQuality(*ppItem, pItemDrop);
    if (pItemDrop->nQuality)
    {
        nQuality = pItemDrop->nQuality;
    }
    ITEMS_SetItemQuality(*ppItem, nQuality);

    if (ITEMS_CanBeMagic(*ppItem))
    {
        if (ITEMS_IsQuestItem(*ppItem))
        {
            ITEMS_SetItemQuality(*ppItem, 7);
        }
        else if (!ITEMS_IsMagSetRarUniCrfOrTmp(*ppItem))
        {
            ITEMS_SetItemQuality(*ppItem, 4);
        }
    }

    if (!ITEMS_CanBeRare(*ppItem) && ITEMS_GetItemQuality(*ppItem) == 6)
    {
        ITEMS_SetItemQuality(*ppItem, 4);
    }

    if (sub_00628C70(*ppItem))
    {
        ITEMS_SetItemQuality(*ppItem, 7);
    }

    if (ITEMS_CanBeNormal(*ppItem))
    {
        ITEMS_SetItemQuality(*ppItem, 2);
    }

    unsigned int nSeed;
    switch (ITEMS_GetItemQuality(*ppItem))
    {
    case 1:
    {
        const unsigned int nLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!sub_005C2FB0_ApplyLowQuality(*ppItem, pItemDrop))
        {
            ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nLowSeed);
        }
        break;
    }
    case 2:
        ITEMS_AssignSpecialPropertiesForFormat(pGame, *ppItem, pItemDrop);
        break;

    case 3:
    {
        ITEMS_SetFileIndex(*ppItem, -1);
        const unsigned int nLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!ITEMS_RollSuperiorItem(*ppItem, pItemDrop))
        {
            ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nLowSeed);
        }
        break;
    }
    case 6:
        ITEMS_AssignRarePrefix(*ppItem, 0);
        ITEMS_AssignRareSuffix(*ppItem, 0);
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!D2GAME_RollRareItem_6FC53360(*ppItem, pItemDrop))
        {
            if (!sub_00557380_ResetToMagicQuality(pItemDrop, ppItem, &nSeed) && !ITEMS_ResetToSuperiorQuality(pItemDrop, ppItem, &nSeed))
            {
                ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
            }
        }
        break;

    case 4:
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!ITEMS_AssignDropMagicAffixes(pItemDrop, ppItem))
        {
            if (!ITEMS_ResetToSuperiorQuality(pItemDrop, ppItem, &nSeed))
            {
                ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
            }
        }
        break;

    case 7:
        ITEMS_SetFileIndex(*ppItem, -1);
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!sub_005566B0_RollUniqueItem(pGame, *ppItem, pItemDrop))
        {
            if (ITEMS_HasDurability(*ppItem) && ITEMS_GetItemFormat(*ppItem) >= 1)
            {
                const int nDurability = STATLIST_UnitGetStatValue(*ppItem, 0x48, 0);
                const int nMaxDurability = STATLIST_GetUnitBaseStat(*ppItem, 0x49, 0);
                STATLIST_SetUnitStat(*ppItem, 0x48, D2_MIN(3 * nDurability, 255), 0);
                STATLIST_SetUnitStat(*ppItem, 0x49, D2_MIN(3 * nMaxDurability, 255), 0);
            }

            if (!sub_005573F0_ResetToRareQuality(pItemDrop, ppItem, &nSeed) && !sub_00557380_ResetToMagicQuality(pItemDrop, ppItem, &nSeed) && !ITEMS_ResetToSuperiorQuality(pItemDrop, ppItem, &nSeed))
            {
                ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
            }
        }
        break;

    case 8:
    {
        ITEMS_AssignRarePrefix(*ppItem, 0);
        ITEMS_AssignRareSuffix(*ppItem, 0);
        const unsigned int nLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!sub_005C21D0_RollCraftedItem(*ppItem, pItemDrop))
        {
            ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nLowSeed);
        }
        break;
    }
    case 9:
    {
        ITEMS_AssignRarePrefix(*ppItem, 0);
        ITEMS_AssignRareSuffix(*ppItem, 0);
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        const unsigned short nPrefix = sub_005C1BC0_RollTemperedAffix(*ppItem, 1);
        const unsigned short nSuffix = sub_005C1BC0_RollTemperedAffix(*ppItem, 0);
        if (nPrefix && nSuffix)
        {
            ITEMS_AssignRarePrefix(*ppItem, nPrefix);
            ITEMS_AssignRareSuffix(*ppItem, nSuffix);
        }
        else
        {
            ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
        }
        break;
    }
    case 5:
        ITEMS_SetFileIndex(*ppItem, -1);
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!sub_005C2940_RollSetItem(*ppItem, pItemDrop))
        {
            if (ITEMS_HasDurability(*ppItem) && ITEMS_GetItemFormat(*ppItem) >= 1)
            {
                const int nDurability = STATLIST_UnitGetStatValue(*ppItem, 0x48, 0);
                const int nMaxDurability = STATLIST_GetUnitBaseStat(*ppItem, 0x49, 0);
                STATLIST_SetUnitStat(*ppItem, 0x48, D2_MIN(2 * nDurability, 255), 0);
                STATLIST_SetUnitStat(*ppItem, 0x49, D2_MIN(2 * nMaxDurability, 255), 0);
            }

            if (!sub_00557380_ResetToMagicQuality(pItemDrop, ppItem, &nSeed) && !ITEMS_ResetToSuperiorQuality(pItemDrop, ppItem, &nSeed))
            {
                ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
            }
        }
        break;

    default:
        return 0;
    }

    if (ITEMS_GetItemQuality(*ppItem) <= 0 || ITEMS_GetItemQuality(*ppItem) >= 10)
    {
        return 0;
    }

    if (ITEMS_GetItemFormat(*ppItem) >= 100)
    {
        ITEMS_MakeEthereal(*ppItem, pItemDrop);
    }

    switch (ITEMS_GetItemQuality(*ppItem))
    {
    case 1:
    case 2:
    case 3:
        ITEMS_RollDropSockets(pGame, *ppItem, pItemDrop);
        break;
    }

    if (ITEMS_GetItemFormat(*ppItem) >= 100)
    {
        switch (ITEMS_GetItemQuality(*ppItem))
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
        case 8:
        case 9:
        {
            const int nAutoPrefix = pItemsTxtRecord->wAutoPrefix;
            if (nAutoPrefix)
            {
                const unsigned short nAutoAffix = sub_005C1940_RollAutoAffix(*ppItem, 0, 1, 0, 1, 0, nAutoPrefix);
                if (nAutoAffix > 0)
                {
                    ITEMS_SetAutoAffix(*ppItem, nAutoAffix);
                    void* pAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(nAutoAffix);
                    sub_0065FEC0_ItemApplyProps(0, 0, *ppItem, pAffixTxtRecord, 0, 0);
                }
            }
        }
            break;
        }
    }

    return 1;
}
