struct D2ActiveRoomStrc;
struct D2InventoryStrc;
struct D2InactiveMonsterNodeStrc;
struct D2InactiveUnitNodeStrc;

struct D2UnitStrc
{
    char pad0x00[0x60];
    D2InventoryStrc* pInventory;
};

struct D2InactiveItemNodeStrc
{
    D2InactiveItemNodeStrc* pNext;
    int nFrame;
    int nOwnerId;
    unsigned short nBitstreamSize;
    unsigned char pBitstream[1];
};

struct D2InactiveItemBufferStrc
{
    D2InactiveItemNodeStrc* pNext;
    int nFrame;
    int nOwnerId;
    unsigned short nBitstreamSize;
    unsigned char pBitstream[0x400];
};

struct D2InactiveUnitListStrc
{
    int nX;
    int nY;
    D2InactiveItemNodeStrc* pInactiveItems;
    D2InactiveMonsterNodeStrc* pInactiveMonsters;
    D2InactiveUnitNodeStrc* pInactiveUnits;
    D2InactiveUnitListStrc* pNext;
};

struct D2GameStrc
{
    char pad0x00[0x1C];
    void* pMemoryPool;
};

int __stdcall ITEMS_GetOwnerId(D2UnitStrc* pItem);                                                           // 0x00629F20
int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bServer, int bSaveItemInv, int bGamble); // 0x006313E0
int __fastcall ITEMS_GetGroundRemovalTime(D2GameStrc* pGame, D2UnitStrc* pUnit);                             // 0x00558A10
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                    // 0x00629900
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                   // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                              // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                               // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);     // 0x0063AD90
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                      // 0x00555600

// 0x00541B10
static void __stdcall sub_00541B10_CompressInactiveItem(D2InactiveUnitListStrc* pList, D2InactiveItemNodeStrc** ppItemNode, D2GameStrc* pGame, D2UnitStrc* pItem)
{
    D2InactiveItemBufferStrc tNode;
    tNode.nOwnerId = ITEMS_GetOwnerId(pItem);
    tNode.pNext = 0;
    tNode.nBitstreamSize = ITEMS_SerializeItemToBitstream(pItem, tNode.pBitstream, sizeof(tNode.pBitstream), 1, 1, 0);
    tNode.nFrame = ITEMS_GetGroundRemovalTime(pGame, pItem);

    const int nNodeSize = tNode.nBitstreamSize + 15;
    D2InactiveItemNodeStrc* pItemNode = (D2InactiveItemNodeStrc*)sub_0040B430(pGame->pMemoryPool, nNodeSize, ".\\UNIT\\SUnitInactive.cpp", 0x1E2, 0);
    memcpy(pItemNode, &tNode, nNodeSize);

    D2InventoryStrc* pInventory;
    if (ITEMS_CheckIfSocketable(pItem) && (pInventory = pItem->pInventory) != 0)
    {
        D2UnitStrc* pSocketable = INVENTORY_GetFirstItem(pInventory);
        while (pSocketable)
        {
            D2UnitStrc* pNext = INVENTORY_GetNextItem(pSocketable);
            D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(pSocketable);
            INVENTORY_RemoveItemFromInventory(pInventory, pSocketed);
            SUNIT_RemoveUnit(pGame, pSocketed);
            pSocketable = pNext;
        }
    }

    SUNIT_RemoveUnit(pGame, pItem);

    if (ppItemNode)
    {
        *ppItemNode = pItemNode;
    }
    else
    {
        pItemNode->pNext = pList->pInactiveItems;
        pList->pInactiveItems = pItemNode;
    }
}

void __stdcall sub_P07_Emit_00542E10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2InactiveUnitListStrc* pList)
{
    sub_00541B10_CompressInactiveItem(pList, 0, pGame, pUnit);
}
