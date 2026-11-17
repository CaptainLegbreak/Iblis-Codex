extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define NULL 0

struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x58];
    D2InventoryStrc* pInventory;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
    char unk0x84[0x6C];
    int dwGemOffset;
};

struct D2GemsTxt;

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                  // 0x00627910
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall sub_00629A40(D2UnitStrc* pItem);                                                              // 0x00629A40
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId);                                                 // 0x006372C0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);                                                        // 0x006235A0
void __stdcall sub_0065FEC0_ItemApplyProps(int nPass, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pProperty, int nArg2, int nArg5); // 0x0065FEC0
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4);                       // 0x00663CC0

static __forceinline int GetUnitType(D2UnitStrc* p)
{
    if (p)
    {
        return p->dwUnitType;
    }
    return 6;
}

static __forceinline D2InventoryStrc* GetInventory(D2UnitStrc* p)
{
    if (p)
    {
        return p->pInventory;
    }
    return 0;
}

static __declspec(noinline) void __stdcall sub_004C0D20_ApplyItemStats(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce);

// 0x004C0D20
static void __stdcall sub_004C0D20_ApplyItemStats(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce)
{
    D2ItemsTxt* pItemsTxtRecord;
    D2GemsTxt* pGemsTxtRecord;

    if (!pUnit)
    {
        return;
    }

    if (ITEMS_CheckItemTypeId(pItem, 0x14))
    {
        D2_ASSERT(GetUnitType(pUnit) == 4, 0x30);
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 0x32);
        pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pItemsTxtRecord->dwGemOffset);
        D2_ASSERT(pGemsTxtRecord, 0x34);
        sub_0065FEC0_ItemApplyProps(2, NULL, pItem, pGemsTxtRecord, sub_00629A40(pUnit), 0);
    }
    else if (ITEMS_CheckItemTypeId(pItem, 0x4A))
    {
        D2_ASSERT(GetUnitType(pUnit) == 4, 0x3A);
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 0x3C);
        pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pItemsTxtRecord->dwGemOffset);
        D2_ASSERT(pGemsTxtRecord, 0x3E);
        sub_0065FEC0_ItemApplyProps(5, pUnit, pItem, pGemsTxtRecord, sub_00629A40(pUnit), 0);
    }
    else
    {
        ITEMS_UpdateSets(pUnit, pItem, 0, 0);
    }

    if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x48, ".\\UNIT\\Item.cpp"))
    {
        return;
    }

    if (GetUnitType(pUnit) == 0)
    {
        D2UnitStrc* pLeftHand = INVENTORY_GetLeftHandWeapon(GetInventory(pUnit));
        if (UNITS_CanDualWield(pUnit))
        {
            int bType = 1;
            if (pLeftHand && pItem != pLeftHand && ITEMS_CheckItemTypeId(pItem, 0x2D))
            {
                bType = 0;
            }

            if (ITEMS_CheckItemFlag(pItem, 0x100, 0x64, ".\\UNIT\\Item.cpp") && !bForce)
            {
                return;
            }

            STATLIST_MergeStatLists(pUnit, pItem, bType);
            return;
        }
    }

    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x70, ".\\UNIT\\Item.cpp") && !bForce)
    {
        return;
    }

    STATLIST_MergeStatLists(pUnit, pItem, 1);
}

void __stdcall sub_004C0D20_CallerA(int nArg, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    sub_004C0D20_ApplyItemStats(pItem, pUnit, 0);
    ITEMS_UpdateSets(pUnit, pItem, nArg, nArg);
    sub_004C0D20_ApplyItemStats(pItem, pUnit, nArg);
    ITEMS_UpdateSets(pUnit, pItem, nArg, 0);
}
