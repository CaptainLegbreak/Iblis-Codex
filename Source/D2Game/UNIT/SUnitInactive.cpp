#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

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
struct D2SeedStrc;
struct D2ObjectDataStrc;
struct D2StaticPathStrc;
struct D2MonsterDataStrc;
struct D2AiCmdStrc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2UnitStrc;
struct D2GameStrc;
struct D2ItemSaveStrc;
struct D2ActiveRoomStrc;
struct D2MapAIStrc;
struct D2DataTablesStrc;

struct D2ItemDataStrc
{
    char pad0x00[0x24];
    int dwActionStamp;
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
    int nX;
    int nY;
    int nClassId;
    int nUnitId;
    unsigned int nUnitFlags;
    unsigned int nUnitFlagsEx;
    int nTypeFlags;
    int nOwnerId;
    D2MinionListStrc* pMinionList;
    D2MapAIStrc* pMapAI;
    int nAiSpecialState;
    int nLevelId;
    unsigned short nNameSeed;
    unsigned char nMonUMods[9];
    unsigned char unk0x3B;
    unsigned short nBossHcIdx;
    unsigned short unk0x3E;
    int nExperience;
    int nMaxHitpoints;
    int nHitpoints;
    int nCmdParam1;
    int nCmdParam2;
    int nGameFrame;
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
    unsigned char bMode;
    unsigned char nPad09;
    unsigned short nPad0A;
    unsigned int dwFlags;
    unsigned char nStorePage;
    unsigned char nBodyloc;
    unsigned short nPad12;
    int nItemFileIndex;
};


struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
    D2UnitStrc* pUnitFirst;
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
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2ObjectDataStrc
{
    char unk0x00[4];
    unsigned char InteractType;
};

struct D2MapAIStrc
{
    int nPathNodes;
};


struct D2MonsterDataStrc
{
    void* pMonstatsTxt;
    union
    {
        struct
        {
            unsigned char nComponent[16];
        };
        struct
        {
            unsigned char unk_04[0xA];
            unsigned char nComponent10;
        };
    };
    unsigned char unk_14[0x14];
    D2AiControlStrc* pAiControl;
};

struct D2AiCmdStrc
{
    int unk0x00[3];
    int nCmdParam1;
    int nCmdParam2;
    int nCmdParam3;
};




extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
extern "C" const char gszSUnitInactiveSourceFile_006E0BC8[]; // 0x006E0BC8
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall AITHINK_GetSpecialStateFromAiControl(D2AiControlStrc* pAiControl); // 0x005B0D60
int __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit); // 0x005A0140
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit); // 0x005A01E0
void __fastcall QUESTS_SetGoldenBirdSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00544F20
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit); // 0x005A0120
void __fastcall AIGENERAL_GetAiControlInfo(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType, int* pAiControlFlag1, int* pAiControlFlag2, D2MinionListStrc** ppMinionList); // 0x0058F440
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit); // 0x0058F000
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2); // 0x00666120
int __fastcall AIGENERAL_GetAiControlParam(D2UnitStrc* pUnit, int nIndex); // 0x0058EC50
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent); // 0x005415A0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall D2GAME_CheckIfSparklyChest_6FCBD7F0(D2UnitStrc* pUnit); // 0x005540D0
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
int __fastcall sub_6FC7D5F0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit); // 0x005752B0
void __fastcall sub_M402_EmitOther(D2GameStrc* pGame, D2UnitStrc* pUnit);
void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue); // 0x0058EC00
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomBySubtile(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2ActiveRoomStrc* __stdcall sub_00619DA0_ActLookup(D2DrlgActStrc* pAct, int nX, int nY); // 0x00619DA0
__declspec(noinline) static D2InactiveUnitListStrc* __stdcall sub_00541D20_GetListNodeFromActAndCoordinates(D2GameStrc* pGame, int nAct, int nX, int nY, int bAllocNewNode);

static int sub_00541970_IsItemNodeAlive(D2InactiveItemNodeStrc* pNode, D2GameStrc* pGame);

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

D2InactiveMonsterNodeStrc* __stdcall sub_C899_Emit_00541DE0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bAlloc)
{
    D2InactiveUnitListStrc* pList = sub_00541DE0_GetListNodeFromRoom(pGame, pRoom, bAlloc);
    return pList ? pList->pInactiveMonsters : 0;
}

// 0x00541D20
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
        D2InactiveUnitListStrc* pNew = (D2InactiveUnitListStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2InactiveUnitListStrc), gszSUnitInactiveSourceFile_006E0BC8, 0x424, 0);
        memset(&pNew->pInactiveItems, 0, 12);
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

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

inline int MONSTERS_GetBaseIdInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[nMonsterId];
        if (pMonStatsTxtRecord)
        {
            return pMonStatsTxtRecord->nBaseId;
        }
    }
    return nMonsterId;
}

inline unsigned char MONSTERS_GetComponent10Inl(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent10;
    }
    return 0;
}

inline int CLIENTS_GetUnitXInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInl(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }
    return 0;
}

static void __stdcall sub_00541FE0_SaveSpecialMonsterParameters(D2GameStrc* pGame, D2InactiveMonsterNodeStrc* pNode, D2UnitStrc* pUnit)
{
    const int nClassId = pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInl(nClassId);

    if (UNIT_HasFlag(pUnit, 0x04000000))
    {
        pNode->nCmdParam1 = gnInactiveCmdParam1_007314C0;
        pNode->nCmdParam2 |= gnInactiveNoXpParam2_007314C4;
    }

    if (UNIT_HasFlag(pUnit, 0x00020000))
    {
        pNode->nCmdParam1 = gnInactiveCmdParam1_007314C0;
        pNode->nCmdParam2 |= gnInactiveNoTcParam2_007314C8;
    }

    if (BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, 9)
        || BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, 8)
        || BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, 10))
    {
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 10, 0);
        if (pAiCmd && pAiCmd->nCmdParam1)
        {
            pNode->nCmdParam1 = pAiCmd->nCmdParam1;
            pNode->nCmdParam2 = pAiCmd->nCmdParam2;
        }

        D2MapAIStrc* pMapAI = AIGENERAL_GetMapAiFromUnit(pUnit);
        if (pMapAI->nPathNodes)
        {
            DRLGPRESET_ChangeMapAI((D2MapAIStrc**)pMapAI, (D2MapAIStrc*)&pNode->pMapAI);
        }
    }

    if (nClassId == 0x10B || nClassId == 0xF3 || (pNode->nTypeFlags & 0x800) && pNode->nBossHcIdx == 6)
    {
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 10, 0);
        if (pAiCmd)
        {
            pNode->nCmdParam1 = pAiCmd->nCmdParam1;
            pNode->nCmdParam2 = pAiCmd->nCmdParam2;
        }
    }

    if (pUnit->dwUnitType == 1)
    {
        const int nBaseId = MONSTERS_GetBaseIdInl(pUnit->dwClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            if (nBaseId == 0x44)
            {
                pNode->nCmdParam1 = AIGENERAL_GetAiControlParam(pUnit, 3);
            }
            else if (nBaseId == 0x21F)
            {
                pNode->nCmdParam1 = AIGENERAL_GetAiControlParam(pUnit, 1);
            }
        }
    }

    if (nClassId == 0x138)
    {
        pNode->nCmdParam1 = MONSTERS_GetComponent10Inl(pUnit);
    }
    else if (nClassId == 0x137)
    {
        pNode->nCmdParam1 = MONSTERS_GetComponent10Inl(pUnit);
    }
}

static void __stdcall sub_005421A0_CompressInactiveMonster(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pUnit || !pRoom)
    {
        return;
    }

    for (int i = 0; i < sgptDataTables->nCurseStates; ++i)
    {
        const int nState = sgptDataTables->pCurseStates[i];
        if (STATES_CheckState(pUnit, nState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
            }
        }
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);

    D2InactiveMonsterNodeStrc* pNode = (D2InactiveMonsterNodeStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2InactiveMonsterNodeStrc), gszSUnitInactiveSourceFile_006E0BC8, 0x528, 0);
    memset(pNode, 0, sizeof(D2InactiveMonsterNodeStrc));

    pNode->nOwnerId = -1;
    pNode->nX = CLIENTS_GetUnitXInl(pUnit);
    pNode->nY = CLIENTS_GetUnitYInl(pUnit);
    pNode->nClassId = pUnit->dwClassId;
    pNode->nGameFrame = pGame->dwGameFrame;
    pNode->nAiSpecialState = AITHINK_GetSpecialStateFromAiControl(AIGENERAL_GetAiControlFromUnitInl(pUnit));
    pNode->nNameSeed = MONSTERUNIQUE_GetNameSeed(pUnit);
    sub_00541FE0_SaveSpecialMonsterParameters(pGame, pNode, pUnit);

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 4))
    {
        pNode->nTypeFlags |= 2;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 2))
    {
        pNode->nTypeFlags |= 0x800;
        pNode->nBossHcIdx = MONSTERUNIQUE_GetBossHcIdx(pUnit);
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 1))
    {
        pNode->nTypeFlags |= 1;
        QUESTS_SetGoldenBirdSpawn(pGame, pUnit);
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 0x10))
    {
        pNode->nTypeFlags |= 0x20;
    }

    if (MONSTER_CheckSummonerFlag(pUnit, 2))
    {
        pNode->nTypeFlags |= 0x40;
    }

    const int nAlignment = STATLIST_GetUnitAlignment(pUnit);
    if (nAlignment == 2)
    {
        pNode->nTypeFlags |= 0x100;
    }
    else if (nAlignment == 0)
    {
        pNode->nTypeFlags |= 0x200;
    }
    else if (nAlignment == 1)
    {
        pNode->nTypeFlags |= 0x80;
    }

    D2_ASSERT(pUnit->dwNodeIndex >= 8, 0x56A);

    if (pUnit->dwNodeIndex != 11)
    {
        pNode->nTypeFlags |= 0x400;
    }

    pNode->nExperience = STATLIST_UnitGetStatValue(pUnit, 13, 0);
    pNode->nMaxHitpoints = STATLIST_GetMaxLifeFromUnit(pUnit);
    pNode->nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    pNode->nLevelId = MONSTER_GetLevelId(pUnit);

    const unsigned char* pMonUMods = MONSTERUNIQUE_GetUMods(pUnit);
    if (pMonUMods)
    {
        for (int i = 0; i < 9; ++i)
        {
            pNode->nMonUMods[i] = pMonUMods[i];
        }
    }

    if (pUnit->dwAnimMode == 12 || pUnit->dwAnimMode == 0)
    {
        pNode->nTypeFlags |= 4;
    }

    D2MinionListStrc* pMinionList;
    int nOwnerGUID;
    int nOwnerType;
    int nFlag1;
    int nFlag2;
    AIGENERAL_GetAiControlInfo(pUnit, &nOwnerGUID, &nOwnerType, &nFlag1, &nFlag2, &pMinionList);

    if (nOwnerGUID != -1 && nOwnerType == 1)
    {
        pNode->nOwnerId = nOwnerGUID;
        pNode->pMinionList = pMinionList;

        if (nFlag1)
        {
            pNode->nTypeFlags |= 8;
        }

        if (nFlag2)
        {
            pNode->nTypeFlags |= 0x10;
        }
    }

    pNode->nUnitId = pUnit->dwUnitId;
    pNode->nUnitFlags = pUnit->dwFlags;
    pNode->nUnitFlagsEx = pUnit->dwFlagEx;

    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    const int nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2InactiveUnitListStrc* pList = sub_00541D20_GetListNodeFromActAndCoordinates(pGame, nAct, tCoords.nSubtileX, tCoords.nSubtileY, 1);
    pNode->pNext = pList->pInactiveMonsters;
    pList->pInactiveMonsters = pNode;
}

void __stdcall sub_M402_Emit_00542E10(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 1)
    {
        sub_005421A0_CompressInactiveMonster(pGame, pUnit);
        return;
    }

    sub_M402_EmitOther(pGame, pUnit);
}

inline D2MonsterDataStrc* MONSTERUNIQUE_GetMonsterDataInl(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

inline void MONSTERS_SetComponentInl(D2UnitStrc* pUnit, int nComponent, unsigned char nValue)
{
    D2MonsterDataStrc* pMonsterData = MONSTERUNIQUE_GetMonsterDataInl(pUnit);
    if (pMonsterData)
    {
        pMonsterData->nComponent[nComponent] = nValue;
    }
}

// 0x00541E20
static void __stdcall sub_00541E20_RestoreSpecialMonsterParameters(D2GameStrc* pGame, D2InactiveMonsterNodeStrc* pNode, D2UnitStrc* pUnit)
{
    const int nClassId = pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInl(nClassId);

    if (BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, 9)
        || BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, 8)
        || BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, 10))
    {
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 10, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam1 = pNode->nCmdParam1;
            pAiCmd->nCmdParam2 = pNode->nCmdParam2;
            pAiCmd->nCmdParam3 = 0;
        }

        D2MapAIStrc** ppMapAI = &pNode->pMapAI;
        D2MapAIStrc* pMapAI = AIGENERAL_GetMapAiFromUnit(pUnit);
        if (*ppMapAI)
        {
            DRLGPRESET_ChangeMapAI(ppMapAI, pMapAI);
        }
    }

    if (nClassId == 0x10B || nClassId == 0xF3 || (pNode->nTypeFlags & 0x800) && pNode->nBossHcIdx == 6)
    {
        if (pNode->nCmdParam1 || pNode->nCmdParam2)
        {
            D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 10, 0);
            if (pAiCmd)
            {
                pAiCmd->nCmdParam1 = pNode->nCmdParam1;
                pAiCmd->nCmdParam2 = pNode->nCmdParam2;
            }
        }
    }

    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }
    if (nUnitType == 1)
    {
        const int nBaseId = MONSTERS_GetBaseIdInl(pUnit->dwClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            if (nBaseId == 0x44)
            {
                AIGENERAL_SetAiControlParam(pUnit, 3, pNode->nCmdParam1);
            }
            else if (nBaseId == 0x21F)
            {
                AIGENERAL_SetAiControlParam(pUnit, 1, pNode->nCmdParam1);
            }
        }
    }

    if (nClassId == 0x138)
    {
        const unsigned char nValue = (unsigned char)pNode->nCmdParam1;
        MONSTERS_SetComponentInl(pUnit, 10, nValue);
        MONSTERS_SetComponentInl(pUnit, 11, nValue);
    }
    else if (nClassId == 0x137)
    {
        const unsigned char nValue = (unsigned char)pNode->nCmdParam1;
        MONSTERS_SetComponentInl(pUnit, 10, nValue);
    }

    if (pNode->nCmdParam1 == gnInactiveCmdParam1_007314C0)
    {
        if (pNode->nCmdParam2 & gnInactiveNoXpParam2_007314C4)
        {
            pUnit->dwFlags |= 0x04000000;
        }

        if (pNode->nCmdParam2 & gnInactiveNoTcParam2_007314C8)
        {
            pUnit->dwFlags |= 0x00020000;
        }
    }
}

void __fastcall sub_EMIT_00542871(D2GameStrc* pGame, D2UnitStrc* pUnit, D2InactiveMonsterNodeStrc* pNode)
{
    STATLIST_SetUnitStat(pUnit, 6, pNode->nHitpoints, 0);
    sub_00541E20_RestoreSpecialMonsterParameters(pGame, pNode, pUnit);
    if (pNode->nTypeFlags & 0x400)
    {
        STATLIST_SetUnitStat(pUnit, 8, 0, 0);
    }
}

#include "gen/data/Source/D2Game/UNIT/SUnitInactive.inc"

// 0x005429B0
int __fastcall sub_005429B0_IsDeadMonsterAt(D2GameStrc* ptGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId)
{
    D2_ASSERT(ptGame, 0x6DA);
    D2_ASSERT(pRoom, 0x6DB);
    D2_ASSERT(nX && nY, 0x6DC);

    D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomBySubtile(pRoom, nX, nY);
    const int nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    if (!pTargetRoom)
    {
        pTargetRoom = sub_00619DA0_ActLookup(ptGame->pAct[nAct], nX, nY);
    }

    if (pTargetRoom)
    {
        for (D2UnitStrc* pUnit = pTargetRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        {
            if ((!pUnit ? 6 : pUnit->dwUnitType) == 1 && pUnit->dwClassId == nClassId && SUNIT_IsDead(pUnit))
            {
                return 1;
            }
        }
    }

    D2InactiveUnitListStrc* pList = sub_00541D20_GetListNodeFromActAndCoordinates(ptGame, nAct, nX, nY, 0);
    if (pList)
    {
        for (D2InactiveMonsterNodeStrc* pNode = pList->pInactiveMonsters; pNode; pNode = pNode->pNext)
        {
            if (pNode->nClassId == nClassId && (pNode->nTypeFlags & 4))
            {
                return 1;
            }
        }
    }

    return 0;
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
