#pragma function(memset)
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                 // 0x00681EF0

struct D2ActiveRoomStrc;
struct D2StatListStrc;
struct D2MinionListStrc;
struct D2AiControlStrc;
struct D2DynamicPathStrc;

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
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x94];
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
    void* pInactiveItems;
    D2InactiveMonsterNodeStrc* pInactiveMonsters;
    void* pInactiveUnits;
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
    char unk0x10[0x1A8 - 0x10];
};

struct D2DataTablesStrc
{
    char unk0x000[0x174];
    short* pCurseStates;
    short nCurseStates;
    char unk0x17A[0xA78 - 0x17A];
    D2MonStatsTxt* pMonStatsTxt;
    int unk0xA7C;
    int nMonStatsTxtRecordCount;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
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

extern "C" const char gszEmptyAssertText;                                                                    // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                       // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                    // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                                // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                   // 0x006CE268
#include "gen/data/Source/D2Game/UNIT/SUnitInactive_00541FE0/gnInactiveCmdParam1_007314C0.inc"
#include "gen/data/Source/D2Game/UNIT/SUnitInactive_00541FE0/gnInactiveNoXpParam2_007314C4.inc"
#include "gen/data/Source/D2Game/UNIT/SUnitInactive_00541FE0/gnInactiveNoTcParam2_007314C8.inc"
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                // 0x00620BB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                              // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);               // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList);                               // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                             // 0x00626CD0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                   // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                   // 0x00648900
int __fastcall AITHINK_GetSpecialStateFromAiControl(D2AiControlStrc* pAiControl);                            // 0x005B0D60
int __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit);                                                 // 0x005A0140
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                 // 0x005A0180
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit);                                              // 0x005A01E0
void __fastcall QUESTS_SetGoldenBirdSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit);                             // 0x00544F20
int __fastcall MONSTER_CheckSummonerFlag(D2UnitStrc* pUnit, int nFlag);                                      // 0x00573540
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                  // 0x006259B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                                // 0x00625D10
int __fastcall MONSTER_GetLevelId(D2UnitStrc* pUnit);                                                        // 0x00573520
unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit);                                         // 0x005A0120
void __fastcall AIGENERAL_GetAiControlInfo(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType, int* pAiControlFlag1, int* pAiControlFlag2, D2MinionListStrc** ppMinionList); // 0x0058F440
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);               // 0x00619730
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                           // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                              // 0x006427F0
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit);                                        // 0x0058F000
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2);                // 0x00666120
int __fastcall AIGENERAL_GetAiControlParam(D2UnitStrc* pUnit, int nIndex);                                   // 0x0058EC50
void __fastcall sub_R05_EmitOther(D2GameStrc* pGame, D2UnitStrc* pUnit);

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

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

static D2InactiveUnitListStrc* __stdcall sub_00541DE0_GetListNodeFromRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bAllocNewNode)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
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

// 0x00541FE0
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

    D2InactiveUnitListStrc* pList = sub_00541DE0_GetListNodeFromRoom(pGame, pRoom, 1);
    pNode->pNext = pList->pInactiveMonsters;
    pList->pInactiveMonsters = pNode;
}

void __stdcall sub_R05_Emit_00542E10(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 1)
    {
        sub_005421A0_CompressInactiveMonster(pGame, pUnit);
        return;
    }

    sub_R05_EmitOther(pGame, pUnit);
}
