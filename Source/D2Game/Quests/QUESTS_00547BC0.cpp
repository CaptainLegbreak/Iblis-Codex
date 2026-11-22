#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

#include "D2Txt.h"
#include "D2ItemsWorld.h"
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __stdcall MONSTERCHOOSE_GenerateComponentVariants(D2SeedStrc* pSeed, D2MonRegDataStrc* pMonRegData, int nCount); // 0x005BDB20

static inline int MONSTERREGION_SanitizeMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }

    return -1;
}

static __forceinline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }

    return 0;
}

static inline D2MonsterRegionStrc* MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId)
{
    return ppMonsterRegion[nLevelId];
}

static inline int sub_00623C60(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x00547BC0
D2MonRegDataStrc* __fastcall MONSTERREGION_GetMonsterComponentData(D2MonsterRegionStrc** ppMonsterRegion, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit)
{
    const short nClassId = sub_00623C60(pUnit);

    switch (MONSTERREGION_SanitizeMonsterId(nClassId))
    {
    case 195:
    case 196:
    case 294:
    case 296:
        return 0;
    default:
        break;
    }

    D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(ppMonsterRegion, DUNGEON_GetLevelIdFromRoom(pRoom));
    if (!pMonsterRegion)
    {
        return 0;
    }

    D2MonRegDataStrc* pMonsterRegionData = pMonsterRegion->pMonData;
    int nCounter = 0;
    while (nCounter < pMonsterRegion->nSpawnCount)
    {
        if ((unsigned short)pMonsterRegionData->nMonHcIdx == (unsigned short)nClassId)
        {
            return pMonsterRegionData;
        }

        ++pMonsterRegionData;
        ++nCounter;
    }

    if (nCounter >= 13)
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = MONSTERREGION_GetMonStats2TxtRecord(nClassId);
    if (pMonStats2TxtRecord && pMonStats2TxtRecord->unk0xEC > 2u)
    {
        pMonsterRegionData->nMonHcIdx = nClassId;
        ++pMonsterRegion->nSpawnCount;
        MONSTERCHOOSE_GenerateComponentVariants(&pUnit->pSeed, pMonsterRegionData, 3);
    }

    return pMonsterRegionData;
}
