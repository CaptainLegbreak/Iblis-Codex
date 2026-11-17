struct D2DynamicPathStrc;
struct D2MinionListStrc;

struct D2MapAIStrc
{
    int nPathNodes;
};

struct D2MonsterDataStrc
{
    void* pMonstatsTxt;
    unsigned char nComponent[16];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0xAC];
    unsigned int dwFlags;
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

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    int unk0xA7C;
    int nMonStatsTxtRecordCount;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

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

#include "gen/data/Source/D2Game/00541E20_sub_00541E20_RestoreSpecialMonsterParameters.inc"
