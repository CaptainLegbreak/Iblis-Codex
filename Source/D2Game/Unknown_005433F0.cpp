#include "D2Game.h"
#include "D2DataTbls.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2InactiveUnitNodeStrc;
struct D2MinionListStrc;
struct D2SeedStrc;
struct D2InactiveItemNodeStrc;
struct D2InactiveItemBufferStrc;
struct D2ObjectDataStrc;
struct D2StaticPathStrc;
struct D2MonsterDataStrc;
struct D2InactiveMonsterNodeStrc;
struct D2InactiveUnitListStrc;
struct D2AiCmdStrc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2DrlgCoordsStrc;
struct D2PlayerDataStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
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

struct D2ObjectDataStrc
{
    char unk0x00[4];
    unsigned char InteractType;
};

struct D2MapAIStrc
{
    int nPathNodes;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x0E];
    unsigned char nComponent10;
    char unk0x0F[0x19];
    D2AiControlStrc* pAiControl;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    union
    {
        D2MonsterDataStrc* pMonsterData;
        D2ObjectDataStrc* pObjectData;
    };
    char unk0x18[0x14];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    char unk0x64[0x14];
    unsigned char bSparkChest;
    char unk0x79[0x3F];
    int dwDropItemCode;
    char unk0xBC[8];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
    int unk0xCC;
    int dwNodeIndex;
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

struct D2AiCmdStrc
{
    int unk0x00[3];
    int nCmdParam1;
    int nCmdParam2;
};

struct D2MonStatsTxt
{
    char unk0x00[0x02];
    short nBaseId;
    char unk0x04[0x08];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x08];
    short nMonStatsEx;
    char unk0x1A[0x1A8 - 0x1A];
};

struct D2MonStats2Txt
{
    char unk0x000[0x130];
    unsigned char nRestore;
    char unk0x131[3];
};


struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    unsigned char unk_20[0x4D];
    unsigned char nDifficulty;
    unsigned char unk_6E[0x3A];
    int dwGameFrame;
    char unk0xAC[0x2C];
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

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall AITHINK_GetSpecialStateFromAiControl(D2AiControlStrc* pAiControl); // 0x005B0D60
unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit); // 0x005A0140
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit); // 0x005A01E0
void __fastcall QUESTS_SetGoldenBirdSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00544F20
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit); // 0x005A0120
void __fastcall AIGENERAL_GetAiControlInfo(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType, int* pAiControlFlag1, int* pAiControlFlag2, D2MinionListStrc** ppMinionList); // 0x0058F440
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit); // 0x0058F000
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2); // 0x00666120
int __fastcall AIGENERAL_GetAiControlParam(D2UnitStrc* pUnit, int nIndex); // 0x0058EC50
int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bServer, int bSaveItemInv, int bGamble); // 0x006313E0
int __fastcall ITEMS_GetGroundRemovalTime(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558A10
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

struct D2ObjectsTxt
{
    char unk0x000[0x109];
    unsigned char nCycleAnim1;
    char unk0x10A[0x141 - 0x10A];
    unsigned char nMode2;
    char unk0x142[0x173 - 0x142];
    unsigned char nRestore;
    unsigned char nRestoreVirgins;
};

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent); // 0x005415A0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
unsigned char __fastcall D2GAME_CheckIfSparklyChest_6FCBD7F0(D2UnitStrc* pUnit); // 0x005540D0
void __fastcall sub_005543B0_AssignAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
int __fastcall sub_6FC7D5F0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit); // 0x005752B0

struct D2InactiveUnitNodeStrc
{
    int nX;
    int nY;
    int nUnitType;
    int nClassId;
    int nMode;
    int nGameFrame;
    unsigned int nUnitFlags;
    unsigned int nUnitFlagsEx;
    int nUnitId;
    int nFrame;
    unsigned char nInteractType;
    char unk0x29[3];
    int nDropItemCode;
    D2InactiveUnitNodeStrc* pNext;
};

struct D2PlayerDataStrc
{
    char unk0x00[16];
    D2BitBufferStrc* pQuestData[3];
    D2WaypointDataStrc* pWaypointData[3];
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

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

    if (bFound)
    {
        return pCurrent;
    }

    D2InactiveUnitListStrc* pNew = (D2InactiveUnitListStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2InactiveUnitListStrc), ".\\UNIT\\SUnitInactive.cpp", 0x424, 0);
    pNew->pInactiveItems = 0;
    pNew->pInactiveMonsters = 0;
    pNew->pInactiveUnits = 0;
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
    return pNew;
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

    D2InactiveMonsterNodeStrc* pNode = (D2InactiveMonsterNodeStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2InactiveMonsterNodeStrc), ".\\UNIT\\SUnitInactive.cpp", 0x528, 0);
    sub_00681EF0_memset(pNode, 0, sizeof(D2InactiveMonsterNodeStrc));

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
    const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2GameStrc* const pListGame = pGame;
    D2InactiveUnitListStrc* pList = sub_00541D20_GetListNodeFromActAndCoordinates(pListGame, nAct, tCoords.nSubtileX, tCoords.nSubtileY, 1);
    pNode->pNext = pList->pInactiveMonsters;
    pList->pInactiveMonsters = pNode;
}

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

    SUNIT_RemoveUnit(pGame, pItem);
    SUNIT_RemoveUnit(pGame, pItem);
    UNITROOM_UpdatePath(0);
    UNITROOM_UpdatePath(0);
}

inline unsigned __int64 SEED_RollRandomNumberInl(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline D2MonStats2Txt* DATATBLS_GetMonStats2TxtRecordFromMonsterIdInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStats2Id = sgptDataTables->pMonStatsTxt[nMonsterId].nMonStatsEx;
        if (nMonStats2Id >= 0 && nMonStats2Id < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStats2Id];
        }
    }
    return 0;
}

static void __stdcall sub_00542E10_CompressInactiveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit) // 0x00542E10
{
    if (pUnit->dwUnitType == 1)
    {
        sub_005421A0_CompressInactiveMonster(pGame, pUnit);
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    int nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    D2InactiveUnitListStrc* pList = pGame->pInactiveUnitList[nAct];
    D2InactiveUnitListStrc* pPrevious = 0;
    while (pList)
    {
        if (tCoords.nSubtileX == pList->nX && tCoords.nSubtileY == pList->nY)
        {
            break;
        }

        if (tCoords.nSubtileX > pList->nX)
        {
            break;
        }

        pPrevious = pList;
        pList = pList->pNext;
    }

    if (!pList || tCoords.nSubtileX > pList->nX)
    {
        D2InactiveUnitListStrc* pNew = (D2InactiveUnitListStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2InactiveUnitListStrc), ".\\UNIT\\SUnitInactive.cpp", 0x22E, 0);
        *pNew = D2InactiveUnitListStrc();
        pNew->nX = tCoords.nSubtileX;
        pNew->nY = tCoords.nSubtileY;
        pNew->pNext = pList;
        if (pPrevious)
        {
            pPrevious->pNext = pNew;
        }
        else
        {
            pGame->pInactiveUnitList[nAct] = pNew;
        }
        pList = pNew;
    }

    const int nUnitType = pUnit->dwUnitType;
    if (nUnitType == 4)
    {
        sub_00541B10_CompressInactiveItem(pList, 0, pGame, pUnit);
        return;
    }

    D2InactiveUnitNodeStrc* pNode = (D2InactiveUnitNodeStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2InactiveUnitNodeStrc), ".\\UNIT\\SUnitInactive.cpp", 0x244, 0);
    sub_00681EF0_memset(pNode, 0, sizeof(D2InactiveUnitNodeStrc));
    pNode->nX = CLIENTS_GetUnitXInl(pUnit);
    pNode->nY = CLIENTS_GetUnitYInl(pUnit);
    pNode->nUnitType = nUnitType;
    pNode->nClassId = pUnit->dwClassId;

    switch (nUnitType)
    {
    case 0:
        pNode->nUnitId = pUnit->dwUnitId;
        pNode->nMode = pUnit->dwAnimMode;
        break;

    case 2:
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
        if (pUnit->dwAnimMode == 1 && !pObjectsTxtRecord->nCycleAnim1 && pObjectsTxtRecord->nMode2)
        {
            pUnit->dwAnimMode = 2;
        }

        pNode->nMode = pUnit->dwAnimMode;

        if (sub_00621B00_IsShrine(pUnit))
        {
            pNode->nUnitId = (unsigned int)EVENT_GetEventFrame(pGame, pUnit, 5) >> 16;
            pNode->nFrame = (unsigned short)EVENT_GetEventFrame(pGame, pUnit, 5);
        }
        else
        {
            const int nClassId = pUnit->dwClassId;
            if (nClassId == 0x3B || nClassId == 0x3C || nClassId == 0x64)
            {
                pNode->nUnitId = pUnit->dwUnitId;
            }
            else
            {
                pNode->nFrame = pUnit->bSparkChest;
            }
        }

        pNode->nDropItemCode = pUnit->dwDropItemCode;
        pNode->nInteractType = pUnit->pObjectData->InteractType;
        break;
    }

    default:
        pNode->nMode = pUnit->dwAnimMode;
        break;
    }

    pNode->nGameFrame = pGame->dwGameFrame;
    pNode->nUnitFlags = pUnit->dwFlags;
    pNode->nUnitFlagsEx = pUnit->dwFlagEx;
    pNode->pNext = pList->pInactiveUnits;
    pList->pInactiveUnits = pNode;
}

static void __stdcall sub_005431F0_CompressMonsterIfNeeded(D2GameStrc* pGame, D2UnitStrc* pUnit) // 0x005431F0
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nAnimMode = pUnit->dwAnimMode;
    int bIsDead = 0;
    if (SUNIT_IsDead(pUnit))
    {
        bIsDead = 1;
    }

    int bCompress = 0;
    int bUnk = 0;
    if (DRLG_GetSaveMonstersFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)))
    {
        bCompress = 1;
    }

    if (pUnit->dwFlags & 0x02000000)
    {
        bCompress = 1;
    }

    if (nAnimMode == 0x0C)
    {
        D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
        if ((unsigned int)SEED_RollRandomNumberInl(pSeed) % 3)
        {
            bCompress = 0;
        }
    }

    if (bIsDead)
    {
        if (STATES_CheckStateMaskUdeadOnUnit(pUnit))
        {
            bCompress = 0;
        }

        if (STATLIST_GetUnitAlignment(pUnit) == 2)
        {
            bCompress = 0;
        }
    }

    if (pUnit->dwNodeIndex < 8)
    {
        if (!bIsDead)
        {
            bCompress = 1;
            sub_005543B0_AssignAlignment(pUnit, 0, 1);
            sub_005B1A90(pGame, pUnit);
        }
        else
        {
            bCompress = 0;
        }
    }

    if (bIsDead && (pUnit->dwClassId == 0x16B || pUnit->dwClassId == 0x16C))
    {
        bCompress = 0;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 0x18) && bIsDead)
    {
        bCompress = 0;
    }

    if (UNIT_HasFlag(pUnit, 0x80000000))
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner && pOwner->dwUnitType == 0)
        {
            bUnk = sub_6FC7D5F0(pGame, pOwner, pUnit);
        }
        bCompress = 0;
    }

    if (UNIT_HasFlag(pUnit, 0x00000200))
    {
        bCompress = 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = DATATBLS_GetMonStats2TxtRecordFromMonsterIdInl(pUnit->dwClassId);
    if (pMonStats2TxtRecord && pMonStats2TxtRecord->nRestore)
    {
        if (pMonStats2TxtRecord->nRestore == 2)
        {
            bCompress = 1;
        }
    }
    else
    {
        bCompress = 0;
    }

    if (bUnk)
    {
        pUnit->dwFlagEx |= 0x100;
        if (bCompress)
        {
            sub_00542E10_CompressInactiveUnit(pGame, pUnit);
        }
        UNITROOM_UpdatePath(pUnit);
    }
    else
    {
        if (bCompress)
        {
            sub_00542E10_CompressInactiveUnit(pGame, pUnit);
        }
        SUNIT_RemoveUnit(pGame, pUnit);
    }
}

// 0x005433F0
void __fastcall SUNITINACTIVE_CompressUnitIfNeeded(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nUnitType = pUnit->dwUnitType;
    const int nClassId = pUnit->dwClassId;
    int bCompress = 0;

    if (nUnitType == 1)
    {
        sub_005431F0_CompressMonsterIfNeeded(pGame, pUnit);
        return;
    }

    if (DRLG_GetSaveMonstersFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) || pUnit->dwFlags & 0x02000000)
    {
        bCompress = 1;
    }

    switch (nUnitType)
    {
    case 2:
    {
        if (nClassId == 0x3B || nClassId == 0x3C)
        {
            goto special;
        }

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
        if (!pObjectsTxtRecord->nRestore || D2GAME_CheckIfSparklyChest_6FCBD7F0(pUnit) & 2)
        {
            bCompress = 0;
        }

        if (pObjectsTxtRecord->nRestoreVirgins && pUnit->dwAnimMode)
        {
            bCompress = 0;
        }

        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
    }
    check:
        if (!bCompress)
        {
            break;
        }

    case 4:
    case 5:
        sub_00542E10_CompressInactiveUnit(pGame, pUnit);
        break;

    case 0:
        if (STATES_CheckState(pUnit, 7))
        {
        special:
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
            pUnit->dwFlagEx |= 0x100;
            sub_00542E10_CompressInactiveUnit(pGame, pUnit);
            UNITROOM_UpdatePath(pUnit);
            return;
        }
        goto check;
    }

    if (nUnitType != 4)
    {
        SUNIT_RemoveUnit(pGame, pUnit);
    }
}

// 0x00543520
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00547F50
D2WaypointDataStrc* __fastcall sub_00547F50(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pWaypointData[pGame->nDifficulty];
}
