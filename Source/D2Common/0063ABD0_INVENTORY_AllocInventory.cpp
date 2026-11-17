void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
struct D2InventoryStrc;
struct D2UnitStrc
{
    unsigned char unk_00[8];
    void* pMemoryPool;
    unsigned int dwUnitId;
    unsigned char unk_10[0x50];
    D2InventoryStrc* pInventory;
};
struct D2InventoryStrc
{
    unsigned int dwSignature;
    void* pMemPool;
    D2UnitStrc* pOwner;
    unsigned char unk_0C[0x18];
    unsigned int dwOwnerId;
    unsigned char unk_28[0x18];
};

// 0x0063ABD0
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner)
{
    if (!pMemPool && pOwner)
    {
        pMemPool = pOwner->pMemoryPool;
    }
    D2InventoryStrc* pInventory = (D2InventoryStrc*)FOG_AllocPool(pMemPool, sizeof(D2InventoryStrc), ".\\INVENTORY\\Inventory.cpp", 0x22D, 0);
    if (!pInventory)
    {
        return 0;
    }
    memset(pInventory, 0, sizeof(D2InventoryStrc));
    pInventory->dwSignature = 0x1020304;
    pInventory->pMemPool = pMemPool;
    pInventory->pOwner = pOwner;
    if (pOwner)
    {
        pOwner->pInventory = pInventory;
        pInventory->dwOwnerId = !pOwner ? -1 : pOwner->dwUnitId;
    }
    return pInventory;
}
