struct D2InventoryStrc
{
    int dwSignature;
};
struct D2UnitStrc
{
    int dwUnitType;
};

int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
extern unsigned char gaByteTable_00745600[256];                                                             // 0x00745600
extern const signed char gaDirectionDeltaX_006EA998[32];                                                    // 0x006EA998
extern const signed char gaDirectionDeltaY_006EA978[32];                                                    // 0x006EA978

#define INVENTORY_SIGNATURE 0x1020304
#define UNIT_ITEM 4
#define NUM_BODYLOC 11
inline D2InventoryStrc* INVENTORY_GetPtrIfValid(D2InventoryStrc* pInventory)
{
    return (pInventory && pInventory->dwSignature == INVENTORY_SIGNATURE) ? pInventory : 0;
}

inline D2UnitStrc* INVENTORY_UnitIsItem(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM) ? pItem : 0;
}

// 0x0063BD00
void __stdcall sub_0063BD00_Return(int nUnused)
{
}

// 0x0063BE30
void __stdcall sub_0063BE30_Return(int nUnused1, int nUnused2)
{
}

// 0x0063C110
int __stdcall INVENTORY_GetBodyLocFromEquippedItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (INVENTORY_GetPtrIfValid(pInventory) && INVENTORY_UnitIsItem(pItem))
    {
        const int nBodyLoc = UNITS_GetXPosition(pItem);
        return nBodyLoc < NUM_BODYLOC ? nBodyLoc : 0;
    }

    return 0;
}

// 0x0063C150
int __stdcall INVENTORY_GetItemsXPosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (INVENTORY_GetPtrIfValid(pInventory) && INVENTORY_UnitIsItem(pItem))
    {
        return UNITS_GetXPosition(pItem);
    }

    return 0;
}

// 0x0063C550
void __stdcall sub_0063C550_Return(int nUnused1, int nUnused2)
{
}

// 0x0063E7A0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex)
{
    return gaByteTable_00745600[nIndex];
}

// 0x0063E7E0
void __stdcall sub_0063E7E0_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY)
{
    *pX = gaDirectionDeltaX_006EA998[nDirection];
    *pY = gaDirectionDeltaY_006EA978[nDirection];
}

#include "gen/data/Source/D2Common/0063BD00_sub_0063BD00_Return.inc"
