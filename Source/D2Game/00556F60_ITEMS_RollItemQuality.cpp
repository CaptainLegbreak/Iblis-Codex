struct D2SeedStrc;
struct D2UnitStrc { int dwUnitType, dwClassId; };
struct D2GameStrc { char pad0[0x6D]; unsigned char nDifficulty; };
struct D2ItemsTxt { char pad0[0xFD]; unsigned char nLevel; char padFE[0x12A-0xFE]; unsigned char nQuest; };
struct D2ItemDropStrc { char pad0[0xC]; int nItemLevel; char pad10[0x20]; int nQuality; char pad34[0x4C]; unsigned int dwFlags2; };
struct D2ItemRatioTxt
{
    int dwUnique, dwUniqueDivisor, dwUniqueMin;
    int dwRare, dwRareDivisor, dwRareMin;
    int dwSet, dwSetDivisor, dwSetMin;
    int dwMagic, dwMagicDivisor, dwMagicMin;
    int dwHiQuality, dwHiQualityDivisor, dwNormal, dwNormalDivisor;
};
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc*); // 0x0062A670
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc*); // 0x00554010
D2ItemRatioTxt* __stdcall DATATBLS_GetItemRatioTxtRecord(int, unsigned char, unsigned short); // 0x00637910
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int); // 0x006335F0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc*, int); // 0x00629BB0
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc*); // 0x00627D90
unsigned int __fastcall sub_0045C3E0(D2SeedStrc*, int); // 0x0045C3E0
extern const int gnQualityOrder_006E1138[6]; // 0x006E1138
// 0x00556F60
int __stdcall ITEMS_RollItemQuality(D2UnitStrc* pItem, D2ItemDropStrc* pDrop)
{
    if (ITEMS_GetItemFormat(pItem) >= 1 && pDrop->nQuality)
        return pDrop->nQuality;
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pItem);
    D2_ASSERT(pGame, 0x482);
    const unsigned short nVersion = ITEMS_GetItemFormat(pItem) >= 1 ? 100 : 0;
    D2ItemRatioTxt* pRatio = DATATBLS_GetItemRatioTxtRecord(!pItem ? -1 : pItem->dwClassId, pGame->nDifficulty, nVersion);
    D2_ASSERT(pRatio, 0x486);
    D2ItemsTxt* pRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pRecord, 0x489);
    if (pRecord->nQuest)
        return 2;
    int nItemLevel = pDrop->nItemLevel;
    int nChance = 0;
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        if (ITEMS_CheckItemTypeId(pItem, 0x34))
            nItemLevel = 1;
        else
        {
            nItemLevel -= pRecord->nLevel;
            if (nItemLevel < 1)
                nItemLevel = 1;
        }
    }
    int nQuality = 1;
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        for (unsigned int i = 0; i < 6; ++i)
        {
            switch (gnQualityOrder_006E1138[i])
            {
            case 7: nChance = pRatio->dwUnique - nItemLevel / pRatio->dwUniqueDivisor; nQuality = 7; break;
            case 6: nChance = pRatio->dwRare - nItemLevel / pRatio->dwRareDivisor; nQuality = 6; break;
            case 5: nChance = pRatio->dwSet - nItemLevel / pRatio->dwSetDivisor; nQuality = 5; break;
            case 4: nChance = pRatio->dwMagic - nItemLevel / pRatio->dwMagicDivisor; nQuality = 4; break;
            case 3: nChance = pRatio->dwHiQuality - nItemLevel / pRatio->dwHiQualityDivisor; nQuality = 3; break;
            case 2: nChance = pRatio->dwNormal - nItemLevel / pRatio->dwNormalDivisor; nQuality = 2; break;
            }
            if (nChance <= 0 || !sub_0045C3E0(ITEMS_GetItemSeed(pItem), nChance))
                return nQuality;
        }
    }
    else
    {
        for (unsigned int i = 0; i < 6; ++i)
        {
            switch (gnQualityOrder_006E1138[i])
            {
            case 7: nChance = pRatio->dwUnique - nItemLevel; nQuality = 7; break;
            case 6: nChance = pRatio->dwRare - nItemLevel; nQuality = 6; break;
            case 5: nChance = pRatio->dwSet - nItemLevel; nQuality = 5; break;
            case 4: nChance = pRatio->dwMagic - nItemLevel / pRatio->dwMagicDivisor; nQuality = 4; break;
            case 3: nChance = pRatio->dwHiQuality - nItemLevel / pRatio->dwHiQualityDivisor; nQuality = 3; break;
            case 2: nChance = pRatio->dwNormal - nItemLevel / pRatio->dwNormalDivisor; nQuality = 2; break;
            }
            if (nChance <= 0)
                nChance = 1;
            if (!sub_0045C3E0(ITEMS_GetItemSeed(pItem), nChance))
                return nQuality;
        }
    }
    return (((unsigned char)pDrop->dwFlags2 & 0x40) | 0x20) >> 5;
}

#include "gen/data/Source/D2Game/00556F60_ITEMS_RollItemQuality.inc"
