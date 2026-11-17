struct D2InventoryStrc;

struct D2UnitStrc
{
    char unk0x00[0xC];
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct D2BodyLocRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned char unk0x12[2];
};

int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __fastcall sub_00479120_GetHirelingClassId(int nUnitId);                                                // 0x00479120
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem);                                     // 0x006289C0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc);                                     // 0x0062ED50
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
extern D2BodyLocRectStrc gaBodyLocRects_007BCD38[11];                                                       // 0x007BCD38
extern int gnAutomapWidth_007A5220;                                                                         // 0x007A5220
extern int gnAutomapHeight_007A521C;                                                                        // 0x007A521C
unsigned char gbGlobal_007BCAD8;                                                                            // 0x007BCAD8
unsigned char gbGlobal_007BCAD9;                                                                            // 0x007BCAD9

// build: symbol ?sub_0048B290@@YGHPAUD2UnitStrc@@0PAH@Z 0x0048B290
static int __stdcall sub_0048B290(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pbSlotMatch)
{
    *pbSlotMatch = 0;
    if (!sub_0044DCC0())
        return 0;
    int bResult = 0;
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x302C, ".\\UI\\inv.cpp"))
        return 0;
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x302F, ".\\UI\\inv.cpp"))
        return 0;
    if (ITEMS_CheckItemTypeId(pItem, 3) || ITEMS_CheckItemTypeId(pItem, 0x25))
    {
        bResult = 1;
        *pbSlotMatch = bResult;
    }
    switch (sub_00479120_GetHirelingClassId(!pUnit ? -1 : pUnit->dwUnitId))
    {
    case 0x10F:
        if (ITEMS_CheckItemTypeId(pItem, 0x1B))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x152:
        if (ITEMS_CheckItemTypeId(pItem, 0x21) || ITEMS_CheckItemTypeId(pItem, 0x22))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x167:
        if (ITEMS_CheckItemTypeId(pItem, 2))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMS_CheckItemTypeId(pItem, 0x1E) && !ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x230:
        if (ITEMS_CheckItemTypeId(pItem, 0x1C) && !ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMS_CheckItemTypeId(pItem, 0x47))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x231:
        if (ITEMS_CheckItemTypeId(pItem, 0x1E))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMS_CheckItemTypeId(pItem, 0x47))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    }
    if (bResult && !ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0))
        bResult = 0;
    return bResult;
}

static __forceinline int IsCursorInRectInline(int nLeft, int nTop, int nRight, int nBottom)
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom)
        return 1;
    return 0;
}

static __forceinline void DrawBodyLocRectInline(D2BodyLocRectStrc* pRect, int nColor)
{
    const int nX = pRect->nLeft;
    const int nY = pRect->nTop;
    if (nX >= 0 && nX < gnAutomapWidth_007A5220 && nY >= 0 && nY < gnAutomapHeight_007A521C)
        sub_0046EFD0_DrawFramedBox(nX, nY, pRect->nWidth, pRect->nHeight, nColor, 0);
}

// 0x0048B3F0
void __fastcall sub_0048B3F0_DrawMercEquipHighlights(D2UnitStrc* pUnit)
{
    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(sub_00463DD0()->pInventory);
    if (!pCursorItem)
        return;
    for (int i = 0; i < 11; ++i)
    {
        if (gaBodyLocRects_007BCD38[i].nLeft > 0 && IsCursorInRectInline(gaBodyLocRects_007BCD38[i].nLeft, gaBodyLocRects_007BCD38[i].nTop, gaBodyLocRects_007BCD38[i].nRight, gaBodyLocRects_007BCD38[i].nBottom))
        {
            unsigned char nWidth;
            unsigned char nHeight;
            ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
            int bMatch;
            if (ITEMS_CheckBodyLocation(pCursorItem, i) && sub_0048B290(pUnit, pCursorItem, &bMatch) && ITEMS_CheckRequirements(pCursorItem, pUnit, 0, 0, 0, 0))
                DrawBodyLocRectInline(&gaBodyLocRects_007BCD38[i], gbGlobal_007BCAD9);
            else
                DrawBodyLocRectInline(&gaBodyLocRects_007BCD38[i], gbGlobal_007BCAD8);
        }
    }
}
