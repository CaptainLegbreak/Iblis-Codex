struct D2UnitStrc;
struct D2InventoryNodeStrc;

struct D2CorpseStrc
{
    unsigned int unk0x00;
    unsigned int dwUnitId;
    unsigned int unk0x08;
    D2CorpseStrc* pNextCorpse;
};

struct D2InventoryStrc
{
    unsigned int dwSignature;
    void* pMemPool;
    D2UnitStrc* pOwner;
    D2UnitStrc* pFirstItem;
    D2UnitStrc* pLastItem;
    void* pGrids;
    int nGridCount;
    int dwLeftItemGUID;
    D2UnitStrc* pCursorItem;
    int dwOwnerGuid;
    int dwItemCount;
    D2InventoryNodeStrc* pFirstNode;
    D2InventoryNodeStrc* pLastNode;
    D2CorpseStrc* pFirstCorpse;
    D2CorpseStrc* pLastCorpse;
    int nCorpseCount;
};

#define INVENTORY_SIGNATURE 0x1020304

extern "C" const char gszInventorySourceFile_006EA918[];                                                    // 0x006EA918
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

// 0x0063BCF0
void __stdcall INVENTORY_Return(const char* szFile, int nLine, D2InventoryStrc* pInventory, int nX, int nY, int nInventoryRecordId, int bClient, unsigned char nPage)
{
}

// 0x0063D470
void __stdcall INVENTORY_CreateCorpseForPlayer(D2InventoryStrc* pInventory, int nUnitId, int a3, int a4)
{
    if (!pInventory)
        return;
    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
        return;

    D2CorpseStrc* pLastCorpse = pInventory->pLastCorpse;
    D2CorpseStrc* pCorpse = (D2CorpseStrc*)FOG_AllocPool(pInventory->pMemPool, sizeof(D2CorpseStrc), gszInventorySourceFile_006EA918, 0xFEA, 0);
    pCorpse->unk0x00 = a4;
    pCorpse->dwUnitId = nUnitId;
    pCorpse->unk0x08 = a3;
    pCorpse->pNextCorpse = 0;

    pInventory->pLastCorpse = pCorpse;
    if (!pInventory->pFirstCorpse)
        pInventory->pFirstCorpse = pCorpse;
    else
        pLastCorpse->pNextCorpse = pCorpse;

    if (pCorpse->unk0x00)
        ++pInventory->nCorpseCount;
}
