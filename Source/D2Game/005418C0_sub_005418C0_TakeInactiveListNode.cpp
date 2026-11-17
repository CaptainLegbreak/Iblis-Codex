extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2InventoryStrc;
struct D2InactiveMonsterNodeStrc;
struct D2InactiveUnitNodeStrc;

struct D2ItemDataStrc
{
    char pad0x00[0x24];
    int dwActionStamp;
};

struct D2UnitStrc
{
    char pad0x00[0x14];
    D2ItemDataStrc* pItemData;
    char pad0x18[0x48];
    D2InventoryStrc* pInventory;
};

struct D2InactiveItemNodeStrc
{
    D2InactiveItemNodeStrc* pNext;
    int nFrame;
    char pad0x08[0x4];
    unsigned short nBitstreamSize;
    unsigned char pBitstream[1];
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
    char pad0x20[0x88];
    int dwGameFrame;
    char pad0xAC[0x2C];
    D2InactiveUnitListStrc* pInactiveUnitList[5];
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2ItemSaveStrc
{
    int nClassId;
    unsigned short nX;
    unsigned short nY;
    unsigned char nAnimMode;
    unsigned char nPad09;
    unsigned short nPad0A;
    unsigned int dwFlags;
    unsigned char nStorePage;
    unsigned char nBodyloc;
    unsigned short nPad12;
    int nItemFileIndex;
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
int __stdcall sub_0062E410(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave); // 0x0062E410
D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char* pBitstream, unsigned int nBufferSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, unsigned int* pSize, unsigned int dwVersion); // 0x00558CB0
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner);                    // 0x0063ABD0
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage);       // 0x0063B210
void __fastcall D2GAME_ITEMS_UpdateStatList_6FC4BC00(D2GameStrc* pGame, D2UnitStrc* pSocketable, D2UnitStrc* pItem); // 0x0055FE60

// 0x005418C0
static void __stdcall sub_005418C0_TakeInactiveListNode(D2InactiveUnitNodeStrc** ppUnitNode, D2InactiveItemNodeStrc** ppItemNode, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    *ppUnitNode = 0;
    *ppItemNode = 0;
    const int nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    D2InactiveUnitListStrc* pPrevious = 0;
    for (D2InactiveUnitListStrc* pList = pGame->pInactiveUnitList[nAct]; pList; pList = pList->pNext)
    {
        if (tCoords.nSubtileX > pList->nX)
        {
            return;
        }

        if (tCoords.nSubtileX == pList->nX && tCoords.nSubtileY == pList->nY)
        {
            if (pPrevious)
            {
                pPrevious->pNext = pList->pNext;
            }
            else
            {
                pGame->pInactiveUnitList[nAct] = pList->pNext;
            }

            *ppUnitNode = pList->pInactiveUnits;
            *ppItemNode = pList->pInactiveItems;
            FOG_FreeServerMemory(pGame->pMemoryPool, pList, ".\\UNIT\\SUnitInactive.cpp", 0xB6, 0);
            return;
        }

        pPrevious = pList;
    }
}

// 0x00541990
static D2UnitStrc* __stdcall sub_00541990_RestoreInactiveItem(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2InactiveItemNodeStrc* pItemNode)
{
    D2ItemSaveStrc tItemSave;
    unsigned int nSize;
    unsigned char* pBitstream = pItemNode->pBitstream;
    unsigned int nAvailableSize = pItemNode->nBitstreamSize;
    sub_0062E410(pBitstream, nAvailableSize, 1, &tItemSave);
    D2UnitStrc* pItem = ITEMS_CreateItemFromBitstream(pGame, pRoom, pBitstream, nAvailableSize, 1, &tItemSave, &nSize, 0x60);
    if (!pItem)
    {
        return 0;
    }

    pBitstream += nSize;
    nAvailableSize -= nSize;

    const int nFrame = pItemNode->nFrame;
    if (nFrame && nFrame < pGame->dwGameFrame + 15000)
    {
        pItem->pItemData->dwActionStamp = pGame->dwGameFrame + 15000;
    }
    else
    {
        pItem->pItemData->dwActionStamp = nFrame;
    }

    if (tItemSave.nItemFileIndex)
    {
        D2InventoryStrc* pInventory = pItem->pInventory;
        if (!pInventory)
        {
            pInventory = INVENTORY_AllocInventory(0, pItem);
        }

        const int nSockets = tItemSave.nItemFileIndex;
        for (int i = 0; i < nSockets; ++i)
        {
            sub_0062E410(pBitstream, nAvailableSize, 1, &tItemSave);
            D2UnitStrc* pSocketable = ITEMS_CreateItemFromBitstream(pGame, 0, pBitstream, nAvailableSize, 1, &tItemSave, &nSize, 0x60);
            D2_ASSERT(pSocketable, 0x10C);
            pBitstream += nSize;
            nAvailableSize -= nSize;
            INVENTORY_PlaceItemInSocket(pInventory, pSocketable, 1);
            D2GAME_ITEMS_UpdateStatList_6FC4BC00(pGame, pSocketable, pItem);
        }
    }

    return pItem;
}

// 0x00541AC0
static void __stdcall sub_00541AC0_RestoreInactiveItems(D2ActiveRoomStrc* pRoom, D2GameStrc* pGame, D2InactiveItemNodeStrc* pItemNode)
{
    while (pItemNode)
    {
        D2InactiveItemNodeStrc* pNext = pItemNode->pNext;
        if (!pItemNode->nFrame || pGame->dwGameFrame <= pItemNode->nFrame)
        {
            sub_00541990_RestoreInactiveItem(pGame, pRoom, pItemNode);
        }

        FOG_FreeServerMemory(pGame->pMemoryPool, pItemNode, ".\\UNIT\\SUnitInactive.cpp", 0x126, 0);
        pItemNode = pNext;
    }
}

// build: context sub_B08_Emit_00542B40
void __fastcall sub_B08_Emit_00542B40(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    D2InactiveUnitNodeStrc* pUnitNode = 0;
    D2InactiveItemNodeStrc* pItemNode = 0;
    sub_005418C0_TakeInactiveListNode(&pUnitNode, &pItemNode, pGame, pRoom);
    sub_00541AC0_RestoreInactiveItems(pRoom, pGame, pItemNode);
    if (pUnitNode)
    {
        FOG_FreeServerMemory(pGame->pMemoryPool, pUnitNode, ".\\UNIT\\SUnitInactive.cpp", 0x1C3, 0);
    }
}
