#include "D2DataTbls.h"
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" const char gszEmptyAssertText[]; // 0x006CC837
#define D2_ASSERT(x,line) do { if (!(x)) { sub_00408A60(gszEmptyAssertText,sub_00408090(),line); exit(-1); } } while(0)
struct D2DynamicPathStrc;
struct D2MinionListStrc;

struct D2MapAIStrc
{
    int nPathNodes;
};

struct D2InventoryStrc;
struct D2ActiveRoomStrc;
struct D2AiControlStrc;
struct D2MonsterDataStrc { void* pMonstatsTxt; unsigned char nComponent[16]; char pad14[0x14]; D2AiControlStrc* pAiControl; };
struct D2ItemDataStrc { char pad00[0x24]; int dwActionStamp; };
struct D2ObjectDataStrc { void* pObjectsTxt; unsigned char InteractType; };
struct D2UnitStrc
{
    int dwUnitType, dwClassId; void* pMemoryPool; int dwUnitId; unsigned int dwAnimMode;
    union { D2MonsterDataStrc* pMonsterData; D2ItemDataStrc* pItemData; D2ObjectDataStrc* pObjectData; };
    char pad18[0x48]; D2InventoryStrc* pInventory; char pad64[0x14]; unsigned char bSparkChest;
    char pad79[0x3F]; unsigned int dwDropItemCode; char padBC[8]; unsigned int dwFlags,dwFlagEx;
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

struct D2AiCmdStrc
{
    int unk0x00[3];
    int nCmdParam1;
    int nCmdParam2;
    int nCmdParam3;
};

struct D2MonStatsTxt
{
    char unk0x00[0x02];
    short nBaseId;
    char unk0x04[0x08];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x1A8 - 0x10];
};


struct D2InactiveUnitNodeStrc
{
    int nX,nY,nUnitType,nClassId,nAnimMode,nGameFrame; unsigned int nUnitFlags,nUnitFlagsEx;
    int nUnitId,nFrame; unsigned char nInteractType; char pad29[3]; unsigned int nDropItemCode;
    D2InactiveUnitNodeStrc* pNext;
};
struct D2InactiveItemNodeStrc { D2InactiveItemNodeStrc* pNext; int nFrame; char pad08[4]; unsigned short nBitstreamSize; unsigned char pBitstream[1]; };
struct D2InactiveUnitListStrc { int nX,nY; D2InactiveItemNodeStrc* pInactiveItems; D2InactiveMonsterNodeStrc* pInactiveMonsters; D2InactiveUnitNodeStrc* pInactiveUnits; D2InactiveUnitListStrc* pNext; };
struct D2GameStrc { char pad00[0x1C]; void* pMemoryPool; char pad20[0x88]; int dwGameFrame; char padAC[0x2C]; D2InactiveUnitListStrc* pInactiveUnitList[5]; int padEC; void* pMonReg[1]; };
struct D2DrlgCoordsStrc { int nSubtileX,nSubtileY,nSubtileWidth,nSubtileHeight,nTileXPos,nTileYPos,nTileWidth,nTileHeight; };
struct D2CoordStrc { int nX,nY; };
struct D2ItemSaveStrc { int nClassId; unsigned short nX,nY; unsigned char nAnimMode,nPad09; unsigned short nPad0A; unsigned int dwFlags; unsigned char nStorePage,nBodyloc; unsigned short nPad12; int nItemFileIndex; };
struct D2ObjectsTxt { char pad00[0x167]; unsigned char nSubClass; char pad168[0x10]; int dwParm[8]; };
extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                   // 0x006CE268
extern int gnInactiveCmdParam1_007314C0; // 0x007314C0
extern int gnInactiveNoXpParam2_007314C4; // 0x007314C4
extern int gnInactiveNoTcParam2_007314C8; // 0x007314C8

void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue);              // 0x0058EC00
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit);                                        // 0x0058F000
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2);                // 0x00666120
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);      // 0x00627260

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

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

inline void MONSTERS_SetComponentInl(D2UnitStrc* pUnit, int nComponent, unsigned char nValue)
{
    if (pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        pUnit->pMonsterData->nComponent[nComponent] = nValue;
    }
}

__declspec(noinline) static void __stdcall sub_00541E20_RestoreSpecialMonsterParameters(D2GameStrc* pGame, D2InactiveMonsterNodeStrc* pNode, D2UnitStrc* pUnit);
static void __stdcall sub_00541E20_RestoreSpecialMonsterParameters(D2GameStrc* pGame, D2InactiveMonsterNodeStrc* pNode, D2UnitStrc* pUnit); // 0x00541E20

// build: context sub_00541E20_RestoreSpecialMonsterParameters
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

    if (pUnit->dwUnitType == 1)
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
        const int nValue = pNode->nCmdParam1;
        MONSTERS_SetComponentInl(pUnit, 10, nValue);
        MONSTERS_SetComponentInl(pUnit, 11, nValue);
    }
    else if (nClassId == 0x137)
    {
        const int nValue = pNode->nCmdParam1;
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

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
int __stdcall sub_0062E410(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave); // 0x0062E410
D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char* pBitstream, unsigned int nBufferSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, unsigned int* pSize, unsigned int dwVersion); // 0x00558CB0
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner);                    // 0x0063ABD0
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage);       // 0x0063B210
void __fastcall D2GAME_ITEMS_UpdateStatList_6FC4BC00(D2GameStrc* pGame, D2UnitStrc* pSocketable, D2UnitStrc* pItem); // 0x0055FE60

__declspec(noinline) static void __stdcall sub_005418C0_TakeInactiveListNode(D2InactiveUnitNodeStrc** ppUnitNode, D2InactiveItemNodeStrc** ppItemNode, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);
static void __stdcall sub_005418C0_TakeInactiveListNode(D2InactiveUnitNodeStrc** ppUnitNode, D2InactiveItemNodeStrc** ppItemNode, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x005418C0
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

__declspec(noinline) static D2UnitStrc* __stdcall sub_00541990_RestoreInactiveItem(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2InactiveItemNodeStrc* pItemNode);
static D2UnitStrc* __stdcall sub_00541990_RestoreInactiveItem(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2InactiveItemNodeStrc* pItemNode); // 0x00541990
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

__declspec(noinline) static void __stdcall sub_00541AC0_RestoreInactiveItems(D2ActiveRoomStrc* pRoom, D2GameStrc* pGame, D2InactiveItemNodeStrc* pItemNode);
static void __stdcall sub_00541AC0_RestoreInactiveItems(D2ActiveRoomStrc* pRoom, D2GameStrc* pGame, D2InactiveItemNodeStrc* pItemNode); // 0x00541AC0
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

void* __fastcall sub_0040B430(void*,int,const char*,int,int); // 0x0040B430
int __fastcall ACT4Q2_IsChaosSanctumCleared(D2GameStrc*); // 0x005B5210
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*,int,int); // 0x00552F60
void __fastcall SUNIT_Restore(D2GameStrc*,D2UnitStrc*,D2ActiveRoomStrc*,int,int); // 0x00554A30
void __fastcall AIGENERAL_FreeAllMinionLists(D2GameStrc*,D2MinionListStrc*); // 0x0058F350
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnWithUnitId(D2GameStrc*,D2ActiveRoomStrc*,int,int,int,int,int,int,int); // 0x005B30E0
D2UnitStrc* __fastcall MONSTERUNIQUE_RestoreUniqueMonster(D2GameStrc*,D2ActiveRoomStrc*,int,int,int,int,unsigned short,int,int,unsigned short,unsigned char*); // 0x005A4440
D2UnitStrc* __fastcall MONSTERUNIQUE_RestoreMinion(D2GameStrc*,D2ActiveRoomStrc*,int,int,int,int,unsigned char*); // 0x005A46E0
int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc*,D2ActiveRoomStrc*,int,int,int*,int*,int); // 0x0054DC40
int __fastcall sub_0064E840_FindRoomCoordinates(D2ActiveRoomStrc*,D2CoordStrc*,int,int,D2ActiveRoomStrc**); // 0x0064E840
void __fastcall AIGENERAL_SetAiControlInfo(D2GameStrc*,D2UnitStrc*,int,int,int,int,D2MinionListStrc*); // 0x0058F4D0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc*,D2UnitStrc*,D2AiControlStrc*,int); // 0x005B0E00
void __fastcall TARGETS_InsertUnitNode(D2GameStrc*,D2UnitStrc*,int,int); // 0x005B1990
unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc*); // 0x005A0120
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc*,D2UnitStrc*,int,int); // 0x005A4850
void __fastcall SUNIT_SetAlignment(D2UnitStrc*,unsigned char,int); // 0x005543B0
void __fastcall MONSTERREGION_AdjustCountsForInactiveMonster(void**,int,int,int,int,int,D2UnitStrc*); // 0x00547ED0
void __fastcall DRLGPRESET_FreeMapAI(void*,D2MapAIStrc*); // 0x00666130
D2UnitStrc* __fastcall SUNIT_CreatePresetUnit(D2GameStrc*,D2ActiveRoomStrc*,int,int,int,int,int,int); // 0x005557D0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int); // 0x00640E90
int __stdcall UNITS_IsShrine(D2UnitStrc*); // 0x00621B00
void* __stdcall DATATBLS_GetShrinesTxtRecord(int); // 0x006414B0
void __stdcall UNITS_SetShrineTxtRecordInObjectData(D2UnitStrc*,void*); // 0x00621BB0
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc*,int); // 0x00624690
void __fastcall EVENT_SetEvent(D2GameStrc*,D2UnitStrc*,int,int,int,int); // 0x005417D0
unsigned char __fastcall sub_00552AA0_GetRegenerateMax(D2ObjectsTxt*); // 0x00552AA0
unsigned char __fastcall sub_00552AB0(); // 0x00552AB0
__declspec(noinline) static D2InactiveUnitListStrc* __stdcall sub_00541D20_GetListNodeFromActAndCoordinates(D2GameStrc* pGame, int nAct, int nX, int nY, int bAllocNewNode);
static D2InactiveUnitListStrc* __stdcall sub_00541D20_GetListNodeFromActAndCoordinates(D2GameStrc* pGame, int nAct, int nX, int nY, int bAllocNewNode); // 0x00541D20

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
inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* unit)
{
    if (unit && unit->dwUnitType == 1 && unit->pMonsterData) return unit->pMonsterData->pAiControl;
    return 0;
}
__declspec(noinline) static void __stdcall sub_005424F0_RestoreInactiveMonsters(D2GameStrc*,D2ActiveRoomStrc*);
static void __stdcall sub_005424F0_RestoreInactiveMonsters(D2GameStrc*,D2ActiveRoomStrc*); // 0x005424F0

// build: context sub_005424F0_RestoreInactiveMonsters
static void __stdcall sub_005424F0_RestoreInactiveMonsters(D2GameStrc* pGame,D2ActiveRoomStrc* pRoom)
{
    D2DrlgCoordsStrc coords;
    DUNGEON_GetRoomCoordinates(pRoom,&coords);
    const int act = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2InactiveUnitListStrc* list = sub_00541D20_GetListNodeFromActAndCoordinates(pGame,act,coords.nSubtileX,coords.nSubtileY,0);
    if (!list) return;
    D2InactiveMonsterNodeStrc* next = list->pInactiveMonsters;
    int chaos = 0;
    if (DUNGEON_GetLevelIdFromRoom(pRoom) == 108 && ACT4Q2_IsChaosSanctumCleared(pGame)) chaos = 1;
    while (next)
    {
        D2InactiveMonsterNodeStrc* node = next;
        next = ((D2InactiveMonsterNodeStrc*)node)->pNext;
        int mode = 1;
        const int id = node->nClassId;
        const int x = node->nX;
        const int y = node->nY;
        int typeFlags = node->nTypeFlags;
        if (typeFlags & 4) mode = 12;
        else if (chaos && id != 243) goto cleanup;
        {
            D2UnitStrc* unit = 0;
            if (node->nUnitFlagsEx & 0x100)
            {
                unit = SUNIT_GetServerUnit(pGame,1,node->nUnitId);
                if (unit) SUNIT_Restore(pGame,unit,pRoom,x,y);
                AIGENERAL_FreeAllMinionLists(pGame,node->pMinionList);
                goto cleanup;
            }
            int flags = 0x62;
            if (typeFlags & 0x40) flags = 0x6A;
            if ((typeFlags & 0x400) && ((typeFlags & 0x100) || (typeFlags & 0x80))) goto cleanup;
            if (BITARRAY_CHECK(DATATBLS_GetMonStatsTxtRecordInl(id)->nMonStatsFlags,14)) flags |= 0x80;
            int type = 0;
            if (typeFlags & 1) type = 1;
            if (typeFlags & 0x20) type = 2;
            switch (type)
            {
            case 2:
                unit = MONSTERUNIQUE_RestoreMinion(pGame,pRoom,x,y,id,node->nUnitId,node->nMonUMods);
                break;
            case 1:
                unit = MONSTERUNIQUE_RestoreUniqueMonster(pGame,pRoom,x,y,id,node->nUnitId,node->nNameSeed,node->nTypeFlags & 2,node->nTypeFlags & 0x800,node->nBossHcIdx,node->nMonUMods);
                break;
            case 0:
                unit = MONSTERSPAWN_SpawnWithUnitId(pGame,pRoom,x,y,id,mode,node->nUnitId,-1,flags);
                if (!unit)
                {
                    unit = MONSTERSPAWN_SpawnWithUnitId(pGame,pRoom,x,y,id,mode,node->nUnitId,5,flags);
                    if (!unit)
                    {
                        int sx,sy;
                        if (!MONSTERREGION_FindSpawnLocation(pGame,pRoom,0,id,&sx,&sy,0)) goto fallbackLocation;
                        unit = MONSTERSPAWN_SpawnWithUnitId(pGame,pRoom,sx,sy,id,mode,node->nUnitId,-1,flags);
                        if (!unit)
                        {
fallbackLocation:
                            D2CoordStrc alternate;
                            alternate.nX = x;
                            alternate.nY = y;
                            D2ActiveRoomStrc* otherRoom;
                            sub_0064E840_FindRoomCoordinates(pRoom,&alternate,1,0x3C01,&otherRoom);
                            if (otherRoom) unit = MONSTERSPAWN_SpawnWithUnitId(pGame,otherRoom,alternate.nX,alternate.nY,id,mode,node->nUnitId,-1,flags);
                        }
                    }
                }
                break;
            }
            int alignment = 0;
            if (node->nTypeFlags & 0x100) alignment = 2;
            if (node->nTypeFlags & 0x80) alignment = 1;
            if (unit)
            {
                AIGENERAL_SetAiControlInfo(pGame,unit,node->nOwnerId,1,node->nTypeFlags & 8,node->nTypeFlags & 0x10,node->pMinionList);
                STATLIST_SetUnitStat(unit,13,node->nExperience,0);
                if ((unsigned int)(pGame->dwGameFrame - node->nGameFrame) >= 7500)
                {
                    STATLIST_SetUnitStat(unit,7,node->nMaxHitpoints,0);
                    STATLIST_SetUnitStat(unit,6,node->nMaxHitpoints,0);
                }
                else
                {
                    STATLIST_SetUnitStat(unit,7,node->nMaxHitpoints,0);
                    STATLIST_SetUnitStat(unit,6,node->nHitpoints,0);
                }
                AITHINK_ExecuteAiFn(pGame,unit,AIGENERAL_GetAiControlFromUnitInline(unit),node->nAiSpecialState);
                sub_00541E20_RestoreSpecialMonsterParameters(pGame,node,unit);
                if (node->nTypeFlags & 0x400)
                {
                    if (alignment == 2) TARGETS_InsertUnitNode(pGame,unit,0,8);
                    else { D2_ASSERT(alignment == 1,0x691); TARGETS_InsertUnitNode(pGame,unit,0,9); }
                }
                unsigned char* saved = node->nMonUMods;
                unsigned char* mods = MONSTERUNIQUE_GetUMods(unit);
                if (mods)
                {
                    int n = 9;
                    do
                    {
                        if (*mods != *saved) D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame,unit,*saved,0);
                        ++saved;
                        ++mods;
                        --n;
                    } while (n);
                }
                SUNIT_SetAlignment(unit,alignment,1);
                if (node->nUnitFlagsEx & 0x200) unit->dwFlagEx |= 0x200;
                unit->dwFlags |= (node->nUnitFlags & 0x20000) | 0x3000000;
            }
            else AIGENERAL_FreeAllMinionLists(pGame,node->pMinionList);
            const int levelId = node->nLevelId;
            const int currentLevel = DUNGEON_GetLevelIdFromRoom(pRoom);
            MONSTERREGION_AdjustCountsForInactiveMonster(pGame->pMonReg,levelId,currentLevel,alignment,mode == 12,node->nTypeFlags & 0x40,unit);
        }
cleanup:
        if (node->pMapAI) DRLGPRESET_FreeMapAI(pGame->pMemoryPool,node->pMapAI);
        FOG_FreeServerMemory(pGame->pMemoryPool,node,".\\UNIT\\SUnitInactive.cpp",0x8C,0);
    }
}

void __fastcall SUNITINACTIVE_RestoreInactiveUnits(D2GameStrc*,D2ActiveRoomStrc*); // 0x00542B40

// 0x00542B40
void __fastcall SUNITINACTIVE_RestoreInactiveUnits(D2GameStrc* pGame,D2ActiveRoomStrc* pRoom)
{
    sub_005424F0_RestoreInactiveMonsters(pGame,pRoom);
    D2InactiveUnitNodeStrc* next = 0;
    D2InactiveItemNodeStrc* items = 0;
    sub_005418C0_TakeInactiveListNode(&next,&items,pGame,pRoom);
    sub_00541AC0_RestoreInactiveItems(pRoom,pGame,items);
    while (next)
    {
        D2InactiveUnitNodeStrc* node = next;
        next = node->pNext;
        const int mode = node->nAnimMode;
        const int type = node->nUnitType;
        D2UnitStrc* unit = 0;
        if (node->nUnitFlagsEx & 0x100)
        {
            unit = SUNIT_GetServerUnit(pGame,type,node->nUnitId);
            if (unit)
            {
                SUNIT_Restore(pGame,unit,pRoom,node->nX,node->nY);
                unit->dwFlags |= 0x10;
                switch (type)
                {
                case 0:
                    D2_ASSERT(node->nAnimMode == 17,0x156);
                    UNITS_ChangeAnimMode(unit,17);
                    break;
                case 2:
                    unit->pObjectData->InteractType = node->nInteractType;
                    break;
                }
            }
            FOG_FreeServerMemory(pGame->pMemoryPool,node,".\\UNIT\\SUnitInactive.cpp",0x15C,0);
        }
        else
        {
            if (type != 1) unit = SUNIT_CreatePresetUnit(pGame,pRoom,type,node->nClassId,node->nX,node->nY,mode,node->nUnitFlags);
            switch (type)
            {
            case 2:
            {
                D2_ASSERT(unit,0x170);
                D2ObjectsTxt* obj = DATATBLS_GetObjectsTxtRecord(unit->dwClassId);
                if (UNITS_IsShrine(unit) && node->nGameFrame)
                {
                    int frame = (unsigned short)node->nFrame | ((unsigned short)node->nUnitId << 16);
                    if (frame > 0)
                    {
                        if (frame <= pGame->dwGameFrame) frame = pGame->dwGameFrame + 1;
                        EVENT_SetEvent(pGame,unit,5,frame,0,0);
                    }
                    unit->pObjectData->InteractType = node->nInteractType;
                    UNITS_SetShrineTxtRecordInObjectData(unit,DATATBLS_GetShrinesTxtRecord(node->nInteractType));
                }
                else if (obj->nSubClass & 0x20)
                {
                    const unsigned char maximum = sub_00552AA0_GetRegenerateMax(obj);
                    unsigned char charges;
                    if (node->nInteractType < maximum)
                    {
                        const int period = obj->dwParm[0];
                        D2_ASSERT(period,0x18B);
                        if (node->nGameFrame < pGame->dwGameFrame + period)
                        {
                            int steps = (pGame->dwGameFrame - node->nGameFrame) / period;
                            if (steps >= 1) steps = 1;
                            charges = (unsigned char)(steps + node->nInteractType);
                            if (charges > maximum) charges = maximum;
                            unit->dwAnimMode = sub_00552AB0() - charges / obj->dwParm[2];
                            if (unit->dwAnimMode > 2)
                            {
                                unit->dwAnimMode = 0;
                                unit->pObjectData->InteractType = maximum;
                                goto objectDone;
                            }
                        }
                        else charges = node->nInteractType;
                        unit->pObjectData->InteractType = charges;
                        if (charges < maximum && maximum - charges > 0)
                        {
                            int offset = period;
                            int remaining = maximum - charges;
                            do
                            {
                                EVENT_SetEvent(pGame,unit,2,offset + pGame->dwGameFrame,0,0);
                                offset += period;
                                --remaining;
                            } while (remaining);
                        }
                    }
                }
                else
                {
                    unit->pObjectData->InteractType = node->nInteractType;
                    unit->bSparkChest = (unsigned char)node->nFrame;
                    if (node->nDropItemCode) unit->dwDropItemCode = node->nDropItemCode;
                }
                break;
            }
            }
objectDone:
            FOG_FreeServerMemory(pGame->pMemoryPool,node,".\\UNIT\\SUnitInactive.cpp",0x1C3,0);
        }
    }
}
