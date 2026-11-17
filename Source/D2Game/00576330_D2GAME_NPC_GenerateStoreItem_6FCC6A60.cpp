struct D2SeedStrc;
struct D2InventoryStrc;
struct D2UnitStrc { char unk_00[0x0C]; int dwUnitId; };
struct D2GameStrc { char unk_00[0x6D]; unsigned char nDifficulty; char unk_6E[2]; int bExpansion; };
struct D2ItemsTxt { char unk_00[0x88]; unsigned int dwUberCode; unsigned int dwUltraCode; char unk_90[0x10C]; unsigned int dwNightmareUpgrade; unsigned int dwHellUpgrade; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" int __cdecl _stricmp(const char*, const char*); // 0x006841E9
extern const char gszNpcSourceFile[]; // 0x006E15F0
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
D2SeedStrc* __fastcall SUNITPROXY_GetSeedFromNpcControl(D2GameStrc* pGame); // 0x00536B40
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc*, int, D2GameStrc*, int, int, int, int, int, int, int, int); // 0x00559CE0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
const char* __stdcall DATATBLS_GetLowQualityItemsTxtRecord(int nIndex); // 0x006375C0
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590
unsigned char __stdcall ITEMS_GetStorePage(D2UnitStrc* pItem); // 0x0062E880
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
void __fastcall D2GAME_NPC_RepairItem_6FCC6970(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x005761C0
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall UNITS_GetYPosition(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall D2GAME_PlaceItem_6FC44410(const char*, int, D2GameStrc*, D2UnitStrc*, int, int, int, int, int, D2InventoryStrc*); // 0x00560200
void __fastcall sub_00535F30(D2UnitStrc*, D2GameStrc*, D2UnitStrc*, int); // 0x00535F30
void __fastcall sub_005762C0_SetItemTradeFlags(D2UnitStrc*, D2UnitStrc*, D2GameStrc*, int, int); // 0x005762C0

// 0x00576330
D2UnitStrc* __fastcall D2GAME_NPC_GenerateStoreItem_6FCC6A60(D2UnitStrc* pNpc, unsigned int dwCode, D2GameStrc* pGame, int bVendorItem, int nQuality, int nItemLevel, int nPlayerLevel)
{
    D2_ASSERT(pGame, 0x102);
    D2_ASSERT(pNpc, 0x103);
    int nItemId;
    D2ItemsTxt* pRecord = DATATBLS_GetItemRecordFromItemCode(dwCode, &nItemId);
    unsigned int dwNewCode = dwCode;
    if (pGame->nDifficulty > 0 && nPlayerLevel > 25)
    {
        if (pGame->nDifficulty == 1)
        {
            unsigned int nChance = ITEMS_RollLimitedRandomNumber(SUNITPROXY_GetSeedFromNpcControl(pGame), 100000);
            if (nChance < (unsigned int)(64 * nItemLevel + 4000) && pRecord->dwUberCode && pRecord->dwUberCode != 0x20202020)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwUberCode, &nItemId);
                dwNewCode = pRecord->dwUberCode;
            }
            else if (pRecord->dwNightmareUpgrade != 0x20787878)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwNightmareUpgrade, &nItemId);
                dwNewCode = pRecord->dwNightmareUpgrade;
            }
        }
        else
        {
            unsigned int nChance = ITEMS_RollLimitedRandomNumber(SUNITPROXY_GetSeedFromNpcControl(pGame), 100000);
            if (pGame->bExpansion && nChance < (unsigned int)(16 * nItemLevel + 1000) && pRecord->dwUltraCode && pRecord->dwUltraCode != 0x20202020)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwUltraCode, &nItemId);
                dwNewCode = pRecord->dwUltraCode;
            }
            else if (nChance < (unsigned int)(128 * nItemLevel + 5000) && pRecord->dwUberCode != 0x20202020 && pRecord->dwUberCode)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwUberCode, &nItemId);
                dwNewCode = pRecord->dwUberCode;
            }
            if (pRecord->dwHellUpgrade != 0x20787878)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwHellUpgrade, &nItemId);
                dwNewCode = pRecord->dwHellUpgrade;
            }
        }
    }
    D2UnitStrc* pItem;
    for (int i = 0; i < 2; ++i)
    {
        int bValid;
        int j = 0;
        do
        {
            bValid = 1;
            pItem = D2GAME_CreateItemUnit_6FC501A0(pNpc, nItemId, pGame, 4, nQuality, 0, 1, nItemLevel, 0, 0, 0);
            if (ITEMS_GetItemQuality(pItem) == 1)
            {
                const char* szName = DATATBLS_GetLowQualityItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (!_stricmp(szName, "Cracked"))
            {
                ITEMS_RemoveFromAllPlayers(pGame, pItem);
                pItem = 0;
                bValid = 0;
                }
            }
            ++j;
        } while (!bValid && j < 5);
        if (!bValid) return 0;
        if (dwNewCode != ITEMS_GetBaseCode(pItem))
        {
            ITEMS_RemoveFromAllPlayers(pGame, pItem);
            nQuality = 2;
            pItem = 0;
        }
        else
        {
            i = 2;
        }
    }
    if (pItem)
    {
        unsigned char nPage = ITEMS_GetStorePage(pItem);
        if (nPage == 0xFF)
        {
            ITEMS_RemoveFromAllPlayers(pGame, pItem);
            return 0;
        }
        ITEMS_SetInvPage(pItem, nPage);
        D2GAME_NPC_RepairItem_6FCC6970(pGame, pItem, 0);
        int nUnitId = pItem->dwUnitId;
        if (!D2GAME_PlaceItem_6FC44410(gszNpcSourceFile, 0x16C, pGame, pNpc, nUnitId, UNITS_GetXPosition(pItem), UNITS_GetYPosition(pItem), 1, 1, 0))
        {
            if (nPage == 1)
            {
                ITEMS_SetInvPage(pItem, 2);
                int nRetryUnitId = pItem->dwUnitId;
                if (D2GAME_PlaceItem_6FC44410(gszNpcSourceFile, 0x172, pGame, pNpc, nRetryUnitId, UNITS_GetXPosition(pItem), UNITS_GetYPosition(pItem), 1, 1, 0))
                {
                    sub_005762C0_SetItemTradeFlags(pNpc, pItem, pGame, bVendorItem, 0);
                    return pItem;
                }
            }
            sub_00535F30(pNpc, pGame, pItem, 0);
            return 0;
        }
        sub_005762C0_SetItemTradeFlags(pNpc, pItem, pGame, bVendorItem, 0);
    }
    return pItem;
}
