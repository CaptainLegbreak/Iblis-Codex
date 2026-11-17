struct D2GameStrc
{
    char unk0x00[0x78];
    unsigned short wItemFormat;
};

struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x60 - 0x10];
    D2InventoryStrc* pInventory;
};

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    int* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    void* pRoom;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int unk0x2C;
    int nQuality;
    char unk0x34[0x84 - 0x34];
};

#define UNIT_PLAYER 0
#define BODYLOC_RARM 4
#define BODYLOC_LARM 5
#define ITEMTYPE_WEAPON 0x2D

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem);                                     // 0x006289C0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode);                                          // 0x00633680
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int a2);                                     // 0x00558200
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3);  // 0x00558D90
int __fastcall sub_6FC45060(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0

// 0x0056D5F0
int __fastcall sub_0056D5F0_SpawnItemInFreeHand(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pRightArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
        D2UnitStrc* pLeftArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
        int nBodyLoc;
        int bEquip = 0;
        if (!pRightArmItem && !pLeftArmItem)
        {
            nBodyLoc = BODYLOC_RARM;
            bEquip = 1;
        }
        else if (!pRightArmItem && pLeftArmItem && !ITEMS_CheckWeaponIfTwoHanded(pLeftArmItem) && !ITEMS_CheckItemTypeId(pLeftArmItem, ITEMTYPE_WEAPON))
        {
            nBodyLoc = BODYLOC_RARM;
            bEquip = 1;
        }
        else if (!pLeftArmItem && pRightArmItem && !ITEMS_CheckWeaponIfTwoHanded(pRightArmItem) && !ITEMS_CheckItemTypeId(pRightArmItem, ITEMTYPE_WEAPON))
        {
            nBodyLoc = BODYLOC_LARM;
            bEquip = 1;
        }

        if (bEquip)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));
            itemDrop.pUnit = pUnit;
            itemDrop.pGame = pGame;
            itemDrop.wItemFormat = pGame->wItemFormat;
            itemDrop.nId = DATATBLS_GetItemIdFromItemCode(dwItemCode);
            D2_ASSERT(itemDrop.nId != -1, 0xF4C);

            itemDrop.nSpawnType = 4;
            itemDrop.nX = 0;
            itemDrop.nY = 0;
            itemDrop.pRoom = 0;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nQuality = 2;
            itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pUnit, 0);

            D2UnitStrc* pNewItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
            D2_ASSERT(pNewItem, 0xF55);

            {
                int nUnused;
                sub_6FC45060(pGame, pUnit, pNewItem->dwUnitId, nBodyLoc, 0, &nUnused);
            }
            return 1;
        }
    }

    return 0;
}
