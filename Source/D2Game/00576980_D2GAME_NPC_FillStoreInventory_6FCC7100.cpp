struct D2UnitStrc;
struct D2SeedStrc;
struct Obj00536B40;

struct D2GameStrc
{
    char unk0x00[0x78];
    unsigned short wItemFormat;
};

struct D2ItemCacheStrc
{
    unsigned char nMin;
    unsigned char nMax;
    unsigned char nMagicMin;
    unsigned char nMagicMax;
    unsigned int dwCode;
    unsigned char nMagicLevel;
    char unk0x09[3];
};

struct D2UnitProxyStrc
{
    D2ItemCacheStrc* pItemCache;
    int nItems;
    unsigned int* pPermCache;
    int nPerms;
};

struct D2NpcTradeStrc
{
    char unk0x00[0x08];
    unsigned int dwTicks;
    D2UnitProxyStrc pProxy;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x20];
    D2NpcTradeStrc npcTrade;
};

struct D2ItemsTxt
{
    char unk0x000[0x80];
    unsigned int dwCode;
    char unk0x084[0x72];
    unsigned short wVersion;
    char unk0x0F8[0x05];
    unsigned char nLevel;
};

#define STAT_LEVEL 12
#define STAT_QUANTITY 70
#define ITEMQUAL_NORMAL 2
#define ITEMQUAL_MAGIC 4
#define STORE_LEVEL_BONUS 5
#define STORE_HIGH_LEVEL 25
#define ITEM_VERSION_EXPANSION 100
#define STORE_MAX_FAILED_ITEMS 32
#define ITEMCODE_CROSSBOW_BOLTS ' vqc'
#define ITEMCODE_ARROWS ' vqa'
#define FILLSTORE_ASSERT_LINE 713

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax);                                      // 0x004BC500
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
extern "C" unsigned int __fastcall sub_00536B40(Obj00536B40* pObj);                                     // 0x00536B40
int __fastcall sub_00576890(D2GameStrc* pGame, D2UnitStrc* pNpc, int nLevel);                         // 0x00576890
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);            // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);    // 0x00627260
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall ITEMS_CheckBitField1Flag1(int nItemId);                                                       // 0x00629C80
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);               // 0x00633640
D2UnitStrc* __fastcall D2GAME_NPC_GenerateStoreItem_6FCC6A60(D2UnitStrc* pNpc, unsigned int dwCode, D2GameStrc* pGame, int bVendorItem, int nQuality, int nItemLevel, int nPlayerLevel); // 0x00576330
int __fastcall sub_00576900_RollStoreItemQuality(D2SeedStrc* pSeed, unsigned int dwCode, int nItemLevel);

// 0x00576980
void __fastcall D2GAME_NPC_FillStoreInventory_6FCC7100(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2NpcTradeStrc* pTrade)
{
    D2SeedStrc* pSeed = (D2SeedStrc*)sub_00536B40((Obj00536B40*)pGame);

    pTrade->dwTicks = GetTickCount();

    int nNpcIndex;
    int nSpawnedItems = 0;
    int i;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nNpcIndex);
    if (pNpcRecord)
    {
    const int nLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    const int nItemLevel = sub_00576890(pGame, pNpc, nLevel + STORE_LEVEL_BONUS);

    for (i = 0; i < pNpcRecord->npcTrade.pProxy.nItems; ++i)
    {
        int nUnused;
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(pTrade->pProxy.pItemCache[i].dwCode, &nUnused);
        if (pItemsTxtRecord->nLevel <= nItemLevel)
        {
            unsigned int nNormalItems;
            if (nItemLevel >= STORE_HIGH_LEVEL)
            {
                nNormalItems = 0;
            }
            else
            {
                nNormalItems = OBJECTS_RollRandomNumber(pSeed, pNpcRecord->npcTrade.pProxy.pItemCache[i].nMin, pNpcRecord->npcTrade.pProxy.pItemCache[i].nMax + 1);
            }

            if (pItemsTxtRecord->wVersion < ITEM_VERSION_EXPANSION || pGame->wItemFormat >= ITEM_VERSION_EXPANSION)
            {
                for (unsigned int j = 0; j < nNormalItems; ++j)
                {
                    const int nQuality = sub_00576900_RollStoreItemQuality(pSeed, pNpcRecord->npcTrade.pProxy.pItemCache[i].dwCode, nItemLevel);
                    if (!D2GAME_NPC_GenerateStoreItem_6FCC6A60(pNpc, pNpcRecord->npcTrade.pProxy.pItemCache[i].dwCode, pGame, 1, nQuality, nItemLevel, nLevel))
                    {
                        ++nSpawnedItems;
                    }

                    if (nSpawnedItems > STORE_MAX_FAILED_ITEMS)
                    {
                        return;
                    }
                }

                int nItemId;
                DATATBLS_GetItemRecordFromItemCode(pTrade->pProxy.pItemCache[i].dwCode, &nItemId);
                if (ITEMS_CheckBitField1Flag1(nItemId) == 1 && pTrade->pProxy.pItemCache[i].nMagicLevel <= nItemLevel)
                {
                    int nMinItems = 1;
                    if (nItemLevel >= STORE_HIGH_LEVEL)
                    {
                        nMinItems = OBJECTS_RollRandomNumber(pSeed, 1, 3) + 1;
                    }

                    const unsigned int nMagicItems = OBJECTS_RollRandomNumber(pSeed, pNpcRecord->npcTrade.pProxy.pItemCache[i].nMagicMin, pNpcRecord->npcTrade.pProxy.pItemCache[i].nMagicMax + nMinItems);
                    for (unsigned int j = 0; j < nMagicItems; ++j)
                    {
                        if (!D2GAME_NPC_GenerateStoreItem_6FCC6A60(pNpc, pNpcRecord->npcTrade.pProxy.pItemCache[i].dwCode, pGame, 1, ITEMQUAL_MAGIC, nItemLevel, nLevel))
                        {
                            ++nSpawnedItems;
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < pNpcRecord->npcTrade.pProxy.nPerms; ++i)
    {
        D2UnitStrc* pStoreItem = D2GAME_NPC_GenerateStoreItem_6FCC6A60(pNpc, pNpcRecord->npcTrade.pProxy.pPermCache[i], pGame, 1, ITEMQUAL_NORMAL, nItemLevel, nLevel);
        if (pStoreItem)
        {
            int nUnused;
            const unsigned int nItemCode = DATATBLS_GetItemRecordFromItemCode(pTrade->pProxy.pPermCache[i], &nUnused)->dwCode;
            if (nItemCode == ITEMCODE_CROSSBOW_BOLTS || nItemCode == ITEMCODE_ARROWS)
            {
                STATLIST_SetUnitStat(pStoreItem, STAT_QUANTITY, ITEMS_GetTotalMaxStack(pStoreItem), 0);
            }
        }
        else
        {
            ++nSpawnedItems;
        }

        if (nSpawnedItems > STORE_MAX_FAILED_ITEMS)
        {
            break;
        }
    }
    }
    else
    {
        D2_ASSERT(0, FILLSTORE_ASSERT_LINE);
    }
}
