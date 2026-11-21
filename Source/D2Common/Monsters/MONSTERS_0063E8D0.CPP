#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"





extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

#define MONSTER_SANDLEAPER1 78

__forceinline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

__forceinline D2SkillsTxt* __fastcall DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x0063E8D0
int __stdcall MONSTERS_IsSandLeaper(D2UnitStrc* pMonster, int bAlwaysReturnFalse)
{
    int nClassId;
    if (pMonster && pMonster->dwUnitType == UNIT_MONSTER)
    {
        nClassId = pMonster->dwClassId;
        if (D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId))
        {
            nClassId = pMonStatsTxtRecord->nBaseId;
        }
    }
    else
    {
        nClassId = -1;
    }

    if (nClassId == (sgptDataTables->nMonStatsTxtRecordCount <= MONSTER_SANDLEAPER1 ? -1 : MONSTER_SANDLEAPER1) && !bAlwaysReturnFalse)
    {
        return 1;
    }

    return 0;
}

// 0x0063E9F0
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster)
{
    if (pMonster && pMonster->dwUnitType == UNIT_MONSTER)
    {
        if (!pMonStatsTxtRecord)
        {
            pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pMonster->dwClassId);
        }

        if (pMonStatsTxtRecord)
        {
            return pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_BOSS >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_BOSS & 7];
        }
    }

    return 0;
}

// 0x0063EA40
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster)
{
    const int nUnitType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    return pMonster->dwAnimMode == MONMODE_DEATH || pMonster->dwAnimMode == MONMODE_DEAD;
}

// 0x0063EA70
int __stdcall MONSTERS_GetSpawnMode_XY(D2UnitStrc* pMonster, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY)
{
    if (bFromMonster && pMonster && pMonster->dwUnitType == UNIT_MONSTER)
    {
        if (D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pMonster->dwClassId))
        {
            const int nSpawn = pMonStatsTxtRecord->wSpawn;
            if (pX)
            {
                *pX = UNITS_GetXPosition(pMonster) + pMonStatsTxtRecord->nSpawnX;
            }

            if (pY)
            {
                *pY = CLIENTS_GetUnitY(pMonster) + pMonStatsTxtRecord->nSpawnY;
            }

            if (pSpawnMode)
            {
                *pSpawnMode = pMonStatsTxtRecord->nSpawnMode;
                if (*pSpawnMode < 0 || *pSpawnMode >= 16)
                {
                    *pSpawnMode = MONMODE_NEUTRAL;
                }
            }

            return nSpawn;
        }
    }
    else
    {
        D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord && pSkillsTxtRecord->wSummon >= 0 && pSkillsTxtRecord->wSummon < sgptDataTables->nMonStatsTxtRecordCount)
        {
            if (pX)
            {
                *pX = UNITS_GetXPosition(pMonster);
            }

            if (pY)
            {
                *pY = CLIENTS_GetUnitY(pMonster);
            }

            if (pSpawnMode)
            {
                *pSpawnMode = (signed char)pSkillsTxtRecord->nSumMode;
                if (*pSpawnMode < 0 || *pSpawnMode >= 16)
                {
                    *pSpawnMode = MONMODE_NEUTRAL;
                }
            }

            return pSkillsTxtRecord->wSummon;
        }
    }

    return -1;
}
