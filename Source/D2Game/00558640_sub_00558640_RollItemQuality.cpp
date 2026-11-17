struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
};

struct D2QualityModsStrc
{
    unsigned short f_0;
    unsigned short wRare;
    unsigned short wSet;
    unsigned short wUnique;
};

struct D2ItemsTxt
{
    char unk0x000[0xFD];
    unsigned char nLevel;
    char unk0x0FE[0x2B];
    unsigned char nUnique;
    unsigned char nQuest;
};

struct D2ItemTypesTxt
{
    char unk0x00[0x14];
    unsigned char nMagic;
    unsigned char nRare;
    unsigned char nNormal;
    char unk0x17[0xCD];
};

struct D2ItemRatioTxt
{
    int dwUnique;
    int dwUniqueDivisor;
    int dwUniqueMin;
    int dwRare;
    int dwRareDivisor;
    int dwRareMin;
    int dwSet;
    int dwSetDivisor;
    int dwSetMin;
    int dwMagic;
    int dwMagicDivisor;
    int dwMagicMin;
    int dwHiQuality;
    int dwHiQualityDivisor;
    int dwNormal;
    int dwNormalDivisor;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBF8];
    D2ItemTypesTxt* pItemTypesTxt;
    int nItemTypesTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                             // 0x006335F0
unsigned int __stdcall ITEMS_GetItemTypeFromItemId(unsigned int dwItemId);                                 // 0x00628700
D2ItemRatioTxt* __stdcall DATATBLS_GetItemRatioTxtRecord(int nItemId, unsigned char nDifficulty, unsigned short nVersion); // 0x00637910
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
int __fastcall sub_00558610_GetDiminishedMagicFind(int nMagicFind, int nFactor, int nFactor2);              // 0x00558610
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0

static __forceinline D2ItemTypesTxt* sub_C03_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}

static int sub_005585D0_GetMagicFindBonus(D2UnitStrc* pPlayer)
{
    if (pPlayer && (unsigned int)pPlayer->dwUnitType <= 1)
    {
        int nMagicBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pPlayer, 0x50, 0);
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pPlayer);
        if (pOwner)
        {
            nMagicBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, 0x50, 0);
        }
        return nMagicBonus;
    }
    return 0;
}

// 0x00558640
static int __stdcall sub_00558640_RollItemQuality(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer, D2QualityModsStrc* pMods, int nItemLevel, int nItemId)
{
    int bMagicFind = 0;
    int nChance;

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    D2ItemTypesTxt* pItemTypesTxtRecord = sub_C03_GetItemTypesTxtRecord(ITEMS_GetItemTypeFromItemId(nItemId));
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    if (pItemTypesTxtRecord->nNormal)
    {
        return 2;
    }

    if (pItemsTxtRecord->nUnique)
    {
        return 7;
    }

    if (pItemTypesTxtRecord->nMagic && pItemsTxtRecord->nQuest)
    {
        return 7;
    }

    D2ItemRatioTxt* pItemRatioTxtRecord = DATATBLS_GetItemRatioTxtRecord(nItemId, pGame->nDifficulty, 100);
    D2_ASSERT(pItemRatioTxtRecord, 0xE8D);

    const int nLevel = nItemLevel - pItemsTxtRecord->nLevel;
    int nMagicFind = sub_005585D0_GetMagicFindBonus(pPlayer);
    if (nMagicFind)
    {
        if (nMagicFind <= -100)
        {
            goto LABEL_SUPERIOR;
        }

        bMagicFind = 1;
    }

    nMagicFind += 100;

    nChance = (pItemRatioTxtRecord->dwUnique - nLevel / pItemRatioTxtRecord->dwUniqueDivisor) * 128;
    if (bMagicFind)
    {
        const int nDiminished = sub_00558610_GetDiminishedMagicFind(nMagicFind, 250, 250);
        if (nDiminished)
        {
            nChance = nChance * 100 / nDiminished;
        }
    }

    if (nChance <= pItemRatioTxtRecord->dwUniqueMin)
    {
        nChance = pItemRatioTxtRecord->dwUniqueMin;
    }

    nChance -= nChance * pMods->wUnique / 1024;
    if (nChance <= 0)
    {
        return 7;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 7;
    }

    nChance = (pItemRatioTxtRecord->dwSet - nLevel / pItemRatioTxtRecord->dwSetDivisor) * 128;
    if (bMagicFind)
    {
        const int nDiminished = sub_00558610_GetDiminishedMagicFind(nMagicFind, 500, 500);
        if (nDiminished)
        {
            nChance = nChance * 100 / nDiminished;
        }
    }

    if (nChance <= pItemRatioTxtRecord->dwSetMin)
    {
        nChance = pItemRatioTxtRecord->dwSetMin;
    }

    nChance -= nChance * pMods->wSet / 1024;
    if (nChance <= 0)
    {
        return 5;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 5;
    }

    if (pItemTypesTxtRecord->nRare)
    {
        nChance = (pItemRatioTxtRecord->dwRare - nLevel / pItemRatioTxtRecord->dwRareDivisor) * 128;
        if (bMagicFind)
        {
            const int nDiminished = sub_00558610_GetDiminishedMagicFind(nMagicFind, 600, 600);
            if (nDiminished)
            {
                nChance = nChance * 100 / nDiminished;
            }
        }

        if (nChance <= pItemRatioTxtRecord->dwRareMin)
        {
            nChance = pItemRatioTxtRecord->dwRareMin;
        }

        nChance -= nChance * pMods->wRare / 1024;
        if (nChance <= 0)
        {
            return 6;
        }

        if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
        {
            return 6;
        }
    }

    if (pItemTypesTxtRecord->nMagic)
    {
        return 4;
    }

    nChance = (pItemRatioTxtRecord->dwMagic - nLevel / pItemRatioTxtRecord->dwMagicDivisor) * 128;
    if (bMagicFind)
    {
        nChance = nChance * 100 / nMagicFind;
    }

    if (nChance <= pItemRatioTxtRecord->dwMagicMin)
    {
        nChance = pItemRatioTxtRecord->dwMagicMin;
    }

    nChance -= nChance * pMods->f_0 / 1024;
    if (nChance <= 0)
    {
        return 4;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 4;
    }

LABEL_SUPERIOR:
    nChance = (pItemRatioTxtRecord->dwHiQuality - nLevel / pItemRatioTxtRecord->dwHiQualityDivisor) * 128;
    if (nChance <= 0)
    {
        return 3;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 3;
    }

    nChance = (pItemRatioTxtRecord->dwNormal - nLevel / pItemRatioTxtRecord->dwNormalDivisor) * 128;
    if (nChance <= 0)
    {
        return 2;
    }

    return ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128 ? 2 : 1;
}

int __stdcall sub_C03_Emit_00558640(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer, D2QualityModsStrc* pMods, int nItemLevel, unsigned short nItemId)
{
    return sub_00558640_RollItemQuality(pGame, pItem, pPlayer, pMods, nItemLevel, nItemId);
}
