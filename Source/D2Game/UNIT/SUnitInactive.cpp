#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_MONSTER 1
struct D2MinionListStrc;
struct D2InactiveMonsterNodeStrc;
struct D2InactiveUnitNodeStrc;
struct D2InactiveItemNodeStrc;
struct D2ItemDataStrc;
struct D2InactiveUnitListStrc;
struct D2DrlgCoordsStrc;
struct D2InactiveItemBufferStrc;

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
    int nOwnerId;
    unsigned short nBitstreamSize;
    unsigned char pBitstream[1];
    unsigned char unk_0F[0x1];
};

struct D2InactiveMonsterNodeStrc
{
    char unk0x00[0x08];
    int nClassId;
    char unk0x0C[0x14];
    D2MinionListStrc* pMinionList;
    D2MapAIStrc* pMapAI;
    char unk0x28[0x30];
    D2InactiveMonsterNodeStrc* pNext;
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
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    int dwGameFrame;
    char pad0xAC[0x2C];
    D2InactiveUnitListStrc* pInactiveUnitList[5];
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall AIGENERAL_FreeAllMinionLists(D2GameStrc* pGame, D2MinionListStrc* pMinionList); // 0x0058F350
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

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

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
int __stdcall sub_0062E410(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave); // 0x0062E410
D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char* pBitstream, unsigned int nBufferSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, unsigned int* pSize, unsigned int dwVersion); // 0x00558CB0
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210
void __fastcall D2GAME_ITEMS_UpdateStatList_6FC4BC00(D2GameStrc* pGame, D2UnitStrc* pSocketable, D2UnitStrc* pItem); // 0x0055FE60

struct D2InactiveItemBufferStrc
{
    D2InactiveItemNodeStrc* pNext;
    int nFrame;
    int nOwnerId;
    unsigned short nBitstreamSize;
    unsigned char pBitstream[0x400];
};
int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bServer, int bSaveItemInv, int bGamble); // 0x006313E0
int __fastcall ITEMS_GetGroundRemovalTime(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558A10
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

struct D2InactiveUnitNodeStrc
{
    char unk0x00[0x08];
    int nUnitType;
    int nClassId;
    char unk0x10[0x20];
    D2InactiveUnitNodeStrc* pNext;
};

static __declspec(noinline) D2InactiveUnitListStrc* __stdcall sub_00541DE0_GetListNodeFromRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bAllocNewNode);

// 0x00541880
void __fastcall sub_00541880_SetItemActionStamp(D2UnitStrc* pItem, int nStamp)
{
    pItem->pItemData->dwActionStamp = nStamp;
}

// 0x00541890
static void SUNITINACTIVE_FreeInactiveMonsterNode(D2GameStrc* pGame, D2InactiveMonsterNodeStrc* pInactiveMonsterNode)
{
    if (pInactiveMonsterNode->pMapAI)
    {
        DRLGPRESET_FreeMapAI(pGame->pMemoryPool, pInactiveMonsterNode->pMapAI);
    }
    FOG_FreeServerMemory(pGame->pMemoryPool, pInactiveMonsterNode, ".\\UNIT\\SUnitInactive.cpp", 140, 0);
}

void __fastcall sub_M105_Emit_00541890(D2GameStrc* pGame, D2InactiveUnitListStrc* pList)
{
    D2InactiveMonsterNodeStrc* pCurrent = pList->pInactiveMonsters;
    while (pCurrent)
    {
        D2InactiveMonsterNodeStrc* pNode = pCurrent;
        pCurrent = pCurrent->pNext;
        AIGENERAL_FreeAllMinionLists(pGame, pNode->pMinionList);
        SUNITINACTIVE_FreeInactiveMonsterNode(pGame, pNode);
    }
}

// 0x00541970
static int sub_00541970_IsItemNodeAlive(D2InactiveItemNodeStrc* pNode, D2GameStrc* pGame)
{
    const int nFrame = pNode->nFrame;
    if (!nFrame)
        return 1;
    return pGame->dwGameFrame <= nFrame;
}

void __fastcall sub_M105_Emit_00541970(D2GameStrc* pGame, D2InactiveUnitListStrc* pList)
{
    D2InactiveItemNodeStrc* pPrevious = 0;
    D2InactiveItemNodeStrc* pCurrent = pList->pInactiveItems;
    while (pCurrent)
    {
        D2InactiveItemNodeStrc* pNext = pCurrent->pNext;
        if (!sub_00541970_IsItemNodeAlive(pCurrent, pGame))
        {
            if (pPrevious)
                pPrevious->pNext = pNext;
            else
                pList->pInactiveItems = pNext;
            FOG_FreeServerMemory(pGame->pMemoryPool, pCurrent, ".\\UNIT\\SUnitInactive.cpp", 0x723, 0);
        }
        else
        {
            pPrevious = pCurrent;
        }
        pCurrent = pNext;
    }
}

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

// 0x00541C50
static void sub_00541C50_DeleteInactiveMonsterNode(D2GameStrc* pGame, unsigned short nClassId, unsigned char nAct)
{
    D2InactiveUnitListStrc* pInactiveUnitList = pGame->pInactiveUnitList[nAct];
    while (pInactiveUnitList)
    {
        D2InactiveMonsterNodeStrc* pInactiveMonsterNode = pInactiveUnitList->pInactiveMonsters;
        D2InactiveMonsterNodeStrc* pPreviousMonsterNode = 0;
        while (pInactiveMonsterNode)
        {
            if (pInactiveMonsterNode->nClassId == nClassId)
            {
                if (pInactiveMonsterNode == pInactiveUnitList->pInactiveMonsters)
                {
                    pInactiveUnitList->pInactiveMonsters = pInactiveMonsterNode->pNext;
                }
                else
                {
                    pPreviousMonsterNode->pNext = pInactiveMonsterNode->pNext;
                }
                AIGENERAL_FreeAllMinionLists(pGame, pInactiveMonsterNode->pMinionList);
                SUNITINACTIVE_FreeInactiveMonsterNode(pGame, pInactiveMonsterNode);
                return;
            }
            pPreviousMonsterNode = pInactiveMonsterNode;
            pInactiveMonsterNode = pInactiveMonsterNode->pNext;
        }
        pInactiveUnitList = pInactiveUnitList->pNext;
    }
}

// 0x00543140
void __fastcall SUNITINACTIVE_DeleteSingleListNode(D2GameStrc* pGame, unsigned short nUnitType, unsigned short nClassId, unsigned char nAct)
{
    if (nUnitType == UNIT_MONSTER)
    {
        sub_00541C50_DeleteInactiveMonsterNode(pGame, nClassId, nAct);
        return;
    }
    D2InactiveUnitListStrc* pInactiveUnitList = pGame->pInactiveUnitList[nAct];
    while (pInactiveUnitList)
    {
        D2InactiveUnitNodeStrc* pInactiveUnitNode = pInactiveUnitList->pInactiveUnits;
        D2InactiveUnitNodeStrc* pPreviousUnitNode = 0;
        while (pInactiveUnitNode)
        {
            if (pInactiveUnitNode->nUnitType == nUnitType && pInactiveUnitNode->nClassId == nClassId)
            {
                if (pInactiveUnitNode == pInactiveUnitList->pInactiveUnits)
                {
                    pInactiveUnitList->pInactiveUnits = pInactiveUnitNode->pNext;
                }
                else
                {
                    pPreviousUnitNode->pNext = pInactiveUnitNode->pNext;
                }
                FOG_FreeServerMemory(pGame->pMemoryPool, pInactiveUnitNode, ".\\UNIT\\SUnitInactive.cpp", 804, 0);
                return;
            }
            pPreviousUnitNode = pInactiveUnitNode;
            pInactiveUnitNode = pInactiveUnitNode->pNext;
        }
        pInactiveUnitList = pInactiveUnitList->pNext;
    }
}

// 0x00541CD0
static void sub_00541CD0_FreeInactiveMonsters(D2GameStrc* pGame, D2InactiveUnitListStrc* pList)
{
    D2InactiveMonsterNodeStrc* pCurrent = pList->pInactiveMonsters;
    while (pCurrent)
    {
        D2InactiveMonsterNodeStrc* pNode = pCurrent;
        pCurrent = pCurrent->pNext;
        AIGENERAL_FreeAllMinionLists(pGame, pNode->pMinionList);
        SUNITINACTIVE_FreeInactiveMonsterNode(pGame, pNode);
    }
}

// 0x00543080
void __fastcall SUNITINACTIVE_FreeInactiveUnitLists(D2GameStrc* pGame)
{
    for (int i = 0; i < 5; ++i)
    {
        D2InactiveUnitListStrc* pNextList = pGame->pInactiveUnitList[i];
        while (pNextList)
        {
            D2InactiveUnitListStrc* pCurrentList = pNextList;
            pNextList = pCurrentList->pNext;
            D2InactiveUnitNodeStrc* pNextUnit = pCurrentList->pInactiveUnits;
            while (pNextUnit)
            {
                D2InactiveUnitNodeStrc* pUnit = pNextUnit;
                pNextUnit = pNextUnit->pNext;
                FOG_FreeServerMemory(pGame->pMemoryPool, pUnit, ".\\UNIT\\SUnitInactive.cpp", 666, 0);
            }
            D2InactiveItemNodeStrc* pItem = pCurrentList->pInactiveItems;
            while (pItem)
            {
                D2InactiveItemNodeStrc* pNextItem = pItem->pNext;
                FOG_FreeServerMemory(pGame->pMemoryPool, pItem, ".\\UNIT\\SUnitInactive.cpp", 676, 0);
                pItem = pNextItem;
            }
            sub_00541CD0_FreeInactiveMonsters(pGame, pCurrentList);
            FOG_FreeServerMemory(pGame->pMemoryPool, pCurrentList, ".\\UNIT\\SUnitInactive.cpp", 683, 0);
        }
    }
}

// build: context sub_00541D20_GetListNodeFromActAndCoordinates
static D2InactiveUnitListStrc* __stdcall sub_00541D20_GetListNodeFromActAndCoordinates(D2GameStrc* pGame, int nAct, int nX, int nY, int bAllocNewNode)
{
    int bFound = 0;
    D2InactiveUnitListStrc* pCurrent = pGame->pInactiveUnitList[nAct];
    D2InactiveUnitListStrc* pPrevious = 0;
    while (pCurrent)
    {
        if (nX == pCurrent->nX && nY == pCurrent->nY)
        {
            bFound = 1;
            break;
        }

        if (nX > pCurrent->nX)
        {
            break;
        }

        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }

    if (!bAllocNewNode)
    {
        return bFound ? pCurrent : 0;
    }

    if (!bFound)
    {
        D2InactiveUnitListStrc* pNew = (D2InactiveUnitListStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2InactiveUnitListStrc), ".\\UNIT\\SUnitInactive.cpp", 0x424, 0);
        *(int*)&pNew->pInactiveItems = 0;
        *(int*)&pNew->pInactiveMonsters = 0;
        *(int*)&pNew->pInactiveUnits = 0;
        pNew->nX = nX;
        pNew->nY = nY;
        pNew->pNext = pCurrent;
        if (pPrevious)
        {
            pPrevious->pNext = pNew;
        }
        else
        {
            pGame->pInactiveUnitList[nAct] = pNew;
        }
        pCurrent = pNew;
    }

    return pCurrent;
}

// 0x00541DE0
static D2InactiveUnitListStrc* __stdcall sub_00541DE0_GetListNodeFromRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bAllocNewNode)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    const int nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    return sub_00541D20_GetListNodeFromActAndCoordinates(pGame, nAct, tCoords.nSubtileX, tCoords.nSubtileY, bAllocNewNode);
}

D2InactiveMonsterNodeStrc* __stdcall sub_C899_Emit_00541DE0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bAlloc)
{
    D2InactiveUnitListStrc* pList = sub_00541DE0_GetListNodeFromRoom(pGame, pRoom, bAlloc);
    return pList ? pList->pInactiveMonsters : 0;
}
