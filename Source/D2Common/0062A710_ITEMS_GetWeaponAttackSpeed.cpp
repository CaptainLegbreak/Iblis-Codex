#define UNIT_ITEM 4

struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x60 - 0x08];
    D2InventoryStrc* pInventory;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
unsigned int __stdcall ITEMS_GetWeaponClassCode(D2UnitStrc* pItem);                                         // 0x00628500
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
void __stdcall D2Common_10884_COMPOSIT_unk(D2UnitStrc* pUnit, int nClassId, int nMode, int nUnitType, D2InventoryStrc* pInventory, char* szPath, int* pWeaponClassCode, int a8, int a9); // 0x0064F5B0
int __stdcall DATATBLS_GetAnimDataInfo(char* szPath, int* pOutLength, int* pOutAnimSpeed, int* pOutFirstFrameTagged); // 0x0066AA80

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0062A710
int __stdcall ITEMS_GetWeaponAttackSpeed(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT((pItem ? pItem->dwUnitType : 6) == UNIT_ITEM, 0x151D);
    D2_ASSERT(ITEMS_CheckItemTypeId(pItem, 0x2D), 0x151E);
    D2_ASSERT(pUnit, 0x151F);

    char szPath[8];
    int nLength = 0;
    int nAnimSpeed = 0;
    int nFirstFrame = 0;
    int nWeaponClassCode = ITEMS_GetWeaponClassCode(pItem);

    D2Common_10884_COMPOSIT_unk(pUnit, !pUnit ? -1 : pUnit->dwClassId, 7, !pUnit ? 6 : pUnit->dwUnitType, pUnit->pInventory, szPath, &nWeaponClassCode, 0, 0);
    if (!DATATBLS_GetAnimDataInfo(szPath, &nLength, &nAnimSpeed, &nFirstFrame))
    {
        return 0x2D;
    }

    D2_ASSERT(nLength, 0x1538);

    int nSpeed = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x5D, 0) + 100;
    nSpeed += STATLIST_UnitGetStatValue(pItem, 0x44, 0);
    return (nLength << 8) / (nAnimSpeed * nSpeed / 100);
}
