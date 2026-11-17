struct D2InventoryStrc;
struct D2UnitStrc { char pad00[0x60]; D2InventoryStrc* pInventory; };
struct D2InventoryGridInfoStrc { char pad00[0x14]; unsigned char nGridBoxWidth, nGridBoxHeight; };
struct D2CoordStrc { int x, y; };
struct D2CelContextStrc
{
    int frame;
    int pad04[12];
    void* cell;
    int pad38[2];
    int direction;
    int pad44;
};
extern const D2CoordStrc gSocketLayouts[][6]; // 0x006D91E8
extern void* gpCellFile_007BEF14; // 0x007BEF14
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*, unsigned int, int, const char*); // 0x006280A0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc*); // 0x0063B2C0
void __stdcall ITEMS_GetDimensions(D2UnitStrc*, unsigned char*, unsigned char*, const char*, int); // 0x006286C0
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc*); // 0x006299B0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc*); // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc*); // 0x0063DFA0
void __fastcall sub_0046EE80_DrawCursorItem(D2UnitStrc*, int, int); // 0x0046EE80
int __stdcall sub_004F6480(D2CelContextStrc*, int, int, int, int, int); // 0x004F6480
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0

// 0x00483E40
void __stdcall sub_00483E40_DrawItemSockets(D2UnitStrc* item, D2InventoryGridInfoStrc* grid, int x, int y)
{
    if (!ITEMS_CheckItemFlag(item, 0x10, 1120, ".\\UI\\inv.cpp"))
        return;
    unsigned char width, height;
    D2InventoryStrc* pInventory = item->pInventory;
    D2UnitStrc* socketItem = INVENTORY_GetFirstItem(pInventory);
    ITEMS_GetDimensions(item, &width, &height, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 1756);
    const unsigned char socketCount = ITEMS_GetSockets(item);
    const D2CoordStrc* offsets = gSocketLayouts[(2 * socketCount + width) * 4 + height - 13];
    for (unsigned int i = 0; i < ITEMS_GetSockets(item); ++i)
    {
        int drawX = (offsets[i].x - 1) * grid->nGridBoxWidth / 2 + x;
        int drawY = (offsets[i].y + 1) * grid->nGridBoxHeight / 2 + y;
        D2CelContextStrc context;
        memset(&context, 0, sizeof(context));
        context.cell = gpCellFile_007BEF14;
        context.direction = 0;
        context.frame = 0;
        sub_004F6480(&context, drawX - 1, drawY, -1, 0, 0);
        if (socketItem)
        {
            D2UnitStrc* checked = INVENTORY_UnitIsItem(socketItem);
            sub_0046EE80_DrawCursorItem(checked, drawX, drawY - grid->nGridBoxHeight);
            socketItem = INVENTORY_GetNextItem(socketItem);
        }
    }
}

#include "gen/data/Source/D2Client/00483E40_sub_00483E40_DrawItemSockets.inc"
