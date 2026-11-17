struct D2UnitStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x2];
    int bExpansion;
    char f_74[0x34];
    unsigned int dwGameFrame;
    char unk0xAC[0x24];
    int pGameSeed;
};

enum D2C_ItemQualities
{
    ITEMQUAL_MAGIC = 4,
    ITEMQUAL_TEMPERED = 9,
};

enum
{
    ITEMTYPE_GOLD = 4,
    STAT_GOLD = 14,
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);              // 0x00625480
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                       // 0x00627E70
int __stdcall ITEMS_IsQuestItem(D2UnitStrc* pItem);                                                          // 0x00628CD0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                          // 0x0062B400
int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem);                                                       // 0x0062BEB0

// 0x00558A10
int __fastcall ITEMS_GetGroundRemovalTime(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (ITEMS_IsQuestItem(pUnit))
    {
        return 0;
    }

    const int nItemQuality = ITEMS_GetItemQuality(pUnit);
    if (nItemQuality != ITEMQUAL_MAGIC)
    {
        if (nItemQuality > ITEMQUAL_MAGIC && nItemQuality <= ITEMQUAL_TEMPERED)
        {
            return pGame->dwGameFrame + 45000;
        }

        if (ITEMS_GetItemType(pUnit) == ITEMTYPE_GOLD)
        {
            if (STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0) > 10000)
            {
                return pGame->dwGameFrame + 45000;
            }

            return pGame->dwGameFrame + 15000;
        }

        if (ITEMS_IsSocketFiller(pUnit))
        {
            return pGame->dwGameFrame + 30000;
        }

        return pGame->dwGameFrame + 15000;
    }

    return pGame->dwGameFrame + 30000;
}
