#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"




struct D2ItemDataTbl
{
    int nItemsTxtRecordCount;
    D2ItemsTxt* pItemsTxt;
    D2ItemsTxt* pWeapons;
    int nWeaponsTxtRecordCount;
    D2ItemsTxt* pArmor;
    int nArmorTxtRecordCount;
    D2ItemsTxt* pMisc;
};

struct D2ItemUnkStrc
{
    int nIndex;
    D2ItemsTxt* pItemsTxtRecord;
};

#define ITEMTYPE_BODY_PART 0x28
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                              // 0x006427F0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x00555E00
static int __stdcall sub_00555E00_CanSelectItem(D2SeedStrc* pSeed, int bIgnoreRarity, D2ItemsTxt* pItemsTxtRecord, int nItemType, int nLevelId)
{
    if (nLevelId <= 0)
    {
        nLevelId = 1;
    }

    if (pItemsTxtRecord->nSpawnable > 0 && !pItemsTxtRecord->nQuest && pItemsTxtRecord->nLevel <= nLevelId)
    {
        if (!bIgnoreRarity)
        {
            const int nChance = pItemsTxtRecord->nRarity - DRLG_GetActNoFromLevelId(nLevelId);
            if (nChance > 0 && ITEMS_RollLimitedRandomNumber(pSeed, nChance))
            {
                return 0;
            }
        }

        if (nItemType == -1 || pItemsTxtRecord->wType[0] == nItemType)
        {
            return 1;
        }
    }

    return 0;
}

// 0x00555E70
int __fastcall ITEMMODE_SelectRandomArmorItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity)
{
    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    D2ItemsTxt* pItemsTxtRecord = pItemDataTbl->pArmor;
    const int nBase = pItemsTxtRecord - pItemDataTbl->pItemsTxt;
    const int nCount = pItemDataTbl->pMisc - pItemsTxtRecord;
    int nMax = 0;
    if (!pItemsTxtRecord)
    {
        return -1;
    }

    D2ItemUnkStrc data[1024];
    for (int i = 0; i < nCount; ++i)
    {
        if (sub_00555E00_CanSelectItem(pSeed, bIgnoreRarity, &pItemsTxtRecord[i], nItemType, nLevelId)
            && (pGame->bExpansion || pItemsTxtRecord[i].wVersion < 100) && nMax < 1023)
        {
            data[nMax].pItemsTxtRecord = &pItemsTxtRecord[i];
            data[nMax].nIndex = nBase + i;
            ++nMax;
        }
    }

    const int nIndex = SEED_RollLimitedRandomNumber(pSeed, nMax);
    if (nIndex > nMax)
    {
        return -1;
    }

    D2ItemUnkStrc* pData = &data[nIndex];
    if (!pData)
    {
        return -1;
    }

    return pData->nIndex;
}

// 0x00555FB0
int __fastcall ITEMMODE_SelectRandomWeaponItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity)
{
    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    D2ItemsTxt* pItemsTxtRecord = pItemDataTbl->pWeapons;
    const int nBase = pItemsTxtRecord - pItemDataTbl->pItemsTxt;
    const int nCount = pItemDataTbl->pArmor - pItemsTxtRecord;
    int nMax = 0;
    if (!pItemsTxtRecord)
    {
        return -1;
    }

    D2ItemUnkStrc data[1024];
    for (int i = 0; i < nCount; ++i)
    {
        if (sub_00555E00_CanSelectItem(pSeed, bIgnoreRarity, &pItemsTxtRecord[i], nItemType, nLevelId)
            && (pGame->bExpansion || pItemsTxtRecord[i].wVersion < 100) && nMax < 1023)
        {
            data[nMax].pItemsTxtRecord = &pItemsTxtRecord[i];
            data[nMax].nIndex = nBase + i;
            ++nMax;
        }
    }

    const int nIndex = SEED_RollLimitedRandomNumber(pSeed, nMax);
    if (nIndex > nMax)
    {
        return -1;
    }

    D2ItemUnkStrc* pData = &data[nIndex];
    if (!pData)
    {
        return -1;
    }

    return pData->nIndex;
}

// 0x005560F0
int __fastcall ITEMMODE_SelectRandomMiscItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts)
{
    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    const int nBase = pItemDataTbl->pMisc - pItemDataTbl->pItemsTxt;
    const int nCount = &pItemDataTbl->pItemsTxt[pItemDataTbl->nItemsTxtRecordCount] - pItemDataTbl->pMisc;

    D2ItemsTxt* pItemsTxtRecord = pItemDataTbl->pMisc;
    int nMax = 0;
    if (!pItemsTxtRecord)
    {
        return -1;
    }

    D2ItemUnkStrc data[1024];
    for (int i = 0; i < nCount; ++i)
    {
        if (bAllowBodyParts || pItemsTxtRecord[i].wType[0] != ITEMTYPE_BODY_PART)
        {
            if (sub_00555E00_CanSelectItem(pSeed, bIgnoreRarity, &pItemsTxtRecord[i], nItemType, nLevelId)
                && (pGame->bExpansion || pItemsTxtRecord[i].wVersion < 100) && nMax < 1023)
            {
                data[nMax].pItemsTxtRecord = &pItemsTxtRecord[i];
                data[nMax].nIndex = nBase + i;
                ++nMax;
            }
        }
    }

    const int nIndex = SEED_RollLimitedRandomNumber(pSeed, nMax);
    if (nIndex > nMax)
    {
        return -1;
    }

    D2ItemUnkStrc* pData = &data[nIndex];
    if (!pData)
    {
        return -1;
    }

    return pData->nIndex;
}
