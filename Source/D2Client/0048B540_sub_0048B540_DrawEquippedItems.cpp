struct D2InventoryStrc;

struct D2UnitStrc
{
    char unk0x00[0x60];
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

struct D2InventoryGridInfoStrc
{
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short pad0x02;
    int nGridLeft;
    int nGridRight;
    int nGridTop;
    int nGridBottom;
    unsigned char nGridBoxWidth;
    unsigned char nGridBoxHeight;
    unsigned short pad0x16;
};

void __fastcall sub_0046EE80_DrawCursorItem(D2UnitStrc* pItem, int nX, int nY);                             // 0x0046EE80
void __stdcall sub_00483E40(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, int nX, int nY);            // 0x00483E40
void __stdcall sub_0048B0A0(D2UnitStrc* pUnit);                                                             // 0x0048B0A0
void __fastcall sub_0048B3F0_DrawMercEquipHighlights(D2UnitStrc* pUnit);                                    // 0x0048B3F0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem);                                             // 0x0062BC20
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
D2InventoryGridInfoStrc gInventoryGrid_007BCBC0;                                                            // 0x007BCBC0
extern D2UnitStrc* gdwGlobal_007BCBF4;                                                                      // 0x007BCBF4
extern D2BodyLocRectStrc gaBodyLocRects_007BCD38[11];                                                       // 0x007BCD38

// 0x0048B540
static void sub_0048B540_DrawEquippedItems(D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    for (int i = 0; i < 11; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (pItem)
        {
            unsigned char nWidth;
            unsigned char nHeight;
            ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
            const int nX = gaBodyLocRects_007BCD38[i].nLeft
                + (gaBodyLocRects_007BCD38[i].nWidth - nWidth * gInventoryGrid_007BCBC0.nGridBoxWidth) / 2;
            const int nY = gaBodyLocRects_007BCD38[i].nTop
                + (gaBodyLocRects_007BCD38[i].nHeight - nHeight * gInventoryGrid_007BCBC0.nGridBoxWidth) / 2;
            sub_0046EE80_DrawCursorItem(pItem, nX, nY);
            if (gdwGlobal_007BCBF4 == pItem && ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem) > 0
                && ITEMS_CheckItemFlag(pItem, 0x800, 0x30C8, ".\\UI\\inv.cpp"))
            {
                sub_00483E40(pItem, &gInventoryGrid_007BCBC0, nX, nY);
            }
        }
    }
}

void __cdecl sub_J08_Emit_0048B540(D2UnitStrc* pUnit)
{
    sub_0048B0A0(pUnit);
    sub_0048B540_DrawEquippedItems(pUnit);
    sub_0048B3F0_DrawMercEquipHighlights(pUnit);
}
