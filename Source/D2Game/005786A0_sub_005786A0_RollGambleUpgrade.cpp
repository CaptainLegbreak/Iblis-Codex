struct D2SeedStrc;

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
};

struct D2ItemsTxt
{
    char unk0x00[0x88];
    unsigned int dwUberCode;
    unsigned int dwUltraCode;
    char unk0x90[0x6D];
    unsigned char nLevel;
};

D2SeedStrc* __fastcall SUNITPROXY_GetSeedFromNpcControl(D2GameStrc* pGame);                                                // 0x00536B40
int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                  // 0x0045C3E0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                           // 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                    // 0x00633640

// 0x005786A0
static int __stdcall sub_005786A0_RollGambleUpgrade(int nItemId, int nUberChance, int nUltraChance, D2GameStrc* pGame, int nItemLevel)
{
    if (!pGame->bExpansion)
    {
        return nItemId;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return nItemId;
    }

    D2SeedStrc* pSeed = SUNITPROXY_GetSeedFromNpcControl(pGame);
    const unsigned int dwUltraCode = pItemsTxtRecord->dwUltraCode;
    int nUltraItemId;
    if (pItemsTxtRecord->dwUberCode != 0x20202020 && pItemsTxtRecord->dwUberCode)
    {
        int nUberItemId;
        D2ItemsTxt* pUberItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(pItemsTxtRecord->dwUberCode, &nUberItemId);
        if (pUberItemsTxtRecord)
        {
            const int nUberItemChance = (nItemLevel - pUberItemsTxtRecord->nLevel) * nUberChance + 1;
            if (nUberItemChance > 0)
            {
                if (ITEMS_RollLimitedRandomNumber(pSeed, 10000) < nUberItemChance)
                {
                    return nUberItemId;
                }

                if (pItemsTxtRecord->dwUltraCode != 0x20202020 && pItemsTxtRecord->dwUltraCode)
                {
                    D2ItemsTxt* pUltraItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwUltraCode, &nUltraItemId);
                    if (pUltraItemsTxtRecord)
                    {
                        const int nUltraItemChance = (nItemLevel - pUltraItemsTxtRecord->nLevel) * nUltraChance + 1;
                        if (nUltraItemChance > 0 && ITEMS_RollLimitedRandomNumber(pSeed, 10000) < nUltraItemChance)
                        {
                            return nUltraItemId;
                        }
                    }
                }
            }
        }
    }

    return nItemId;
}

int __stdcall sub_J17_Emit_005786A0(D2GameStrc* pGame, int nItemLevel, int nItemId, int nUberChance, int nUltraChance)
{
    return sub_005786A0_RollGambleUpgrade(nItemId, nUberChance, nUltraChance, pGame, nItemLevel);
}
