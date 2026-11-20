#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"


struct D2MonsterDataStrc
{
    char unk0x00[0x34];
    int nAiValue;
    int nAiState;
};


#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define MONSTATSFLAGINDEX_SWITCHAI 16

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline D2MonsterDataStrc* MONSTERS_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

// build: context sub_00573040_AiSwitchAllowed
static int __fastcall sub_00573040_AiSwitchAllowed(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_SWITCHAI >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_SWITCHAI & 7])
        {
            return 1;
        }
    }
    return 0;
}

// 0x00573090
int __fastcall sub_00573090_ApplyAiMode(D2UnitStrc* pUnit, int nState, int nValue)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && nState < 5 && sub_00573040_AiSwitchAllowed(pUnit))
    {
        D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterData(pUnit);
        if (pMonsterData)
        {
            pMonsterData->nAiState = nState;
            pMonsterData->nAiValue = nValue;
            return 1;
        }
    }
    return 0;
}
