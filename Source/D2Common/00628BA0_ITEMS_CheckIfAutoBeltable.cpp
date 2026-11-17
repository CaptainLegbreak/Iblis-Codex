struct D2InventoryStrc;
struct D2ItemsTxt { char pad[0x131]; unsigned char nAutoBelt; };
struct D2UnitStrc { int dwUnitType; int dwClassId; };
typedef int BOOL;

extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
BOOL __stdcall INVENTORY_HasSimilarPotionInBelt(D2InventoryStrc* pInventory, D2UnitStrc* pPotion); // 0x0063C560
#define D2_NORETURN __declspec(noreturn)
extern "C" D2_NORETURN void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszEmptyAssertText; // 0x006CC837

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00628BA0
int __stdcall ITEMS_CheckIfAutoBeltable(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 0x9A6);
    D2_ASSERT(pItem->dwUnitType == 4, 0x9A7);
    int nClassId = pItem->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
    D2_ASSERT(pItemsTxtRecord, 0x9A9);
    if (pItemsTxtRecord->nAutoBelt || INVENTORY_HasSimilarPotionInBelt(pInventory, pItem) != -1) { return 1; }
    return 0;
}
