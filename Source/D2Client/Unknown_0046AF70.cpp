#include "D2MissileIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2LevelTxt.h"
struct D2UnitStrc;

union D2SeedStrc;
struct D2DrlgCoordsStrc;
struct D2MissileStrc;
struct D2StaticPathStrc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;





D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540


void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
D2UnitStrc* __stdcall UNITFINDS_FindUnitInNeighboredRooms(D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId); // 0x0065A620





extern D2DataTablesStrc* sgptDataTables; // 0x00744304
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg); // 0x00466730
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }
    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }
    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x0046AF70
void __stdcall sub_0046AF70(D2ActiveRoomStrc* pRoom)
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (pPlayer)
    {
        D2MissileStrc tMissile;
        D2DrlgCoordsStrc tCoords;
        memset(&tMissile, 0, sizeof(tMissile));
        tMissile.dwFlags = 0x2003;
        tMissile.pOwner = pPlayer;
        tMissile.nSkill = 0;
        tMissile.nSkillLevel = 1;
        tMissile.nMissile = MISSILE_DENOFEVILLIGHT;
        DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
        int nCount = 0;
        int i = 0;
        for (; nCount < 3; ++i)
        {
            if (i >= 25) break;
            int nX = tCoords.nSubtileX + SEED_RollLimitedRandomNumber(&pPlayer->pSeed, tCoords.nSubtileWidth);
            int nY = tCoords.nSubtileY + SEED_RollLimitedRandomNumber(&pPlayer->pSeed, tCoords.nSubtileHeight);
            tMissile.nX = nX;
            if (!COLLISION_CheckMask(pRoom, nX, tMissile.nY = nY, 5)) { MISSILE_CreateClientMissile(&tMissile); } else { --nCount; }
            ++nCount;
        }
    }
}

static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->nXPos;
        break;
    default:
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nX;
}

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->nYPos;
        break;
    default:
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nY;
}

// 0x0046B710
void __fastcall sub_0046B710_SpawnMissileAtObject173(D2UnitStrc* pUnit)
{
    D2UnitStrc* pObject = UNITFINDS_FindUnitInNeighboredRooms(UNITS_GetRoom(pUnit), 2, 0x173);
    int nX;
    int nY;
    if (pObject)
    {
        nX = CLIENTS_GetUnitXInline(pObject);
        nY = CLIENTS_GetUnitYInline(pObject);
    }
    else
    {
        nX = CLIENTS_GetUnitXInline(pUnit) - 15;
        nY = CLIENTS_GetUnitYInline(pUnit) - 15;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x420;
    tMissileParams.nMissile = MISSILE_TOWERMIST;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nTargetX = nX;
    tMissileParams.nTargetY = nY;
    tMissileParams.nSkillLevel = 1;
    MISSILE_CreateClientMissile(&tMissileParams);

    D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pUnit, 0x14C, nX, nY, 0, 1);
    if (pMissile)
    {
        MISSILE_SetTargetY(pMissile, 0);
    }
}

static inline unsigned __int64 SEED_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;

    if (((unsigned int)nMax - 1) & (unsigned int)nMax)
        return (unsigned int)SEED_RollRandomNumberForceInline(pSeed) % nMax;

    return SEED_RollRandomNumberForceInline(pSeed) & (nMax - 1);
}

static inline D2MonStats2Txt* MONSTATS2_GetRecordInline(int nMonStatsEx)
{
    return (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount) ? &sgptDataTables->pMonStats2Txt[nMonStatsEx] : 0;
}

// 0x0046C1A0
static void __stdcall sub_0046C1A0_SpawnMonsterInRoom(D2ActiveRoomStrc* pRoom, int nMonsterId, D2SeedStrc* pSeed)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    const int nX = tCoords.nSubtileX;
    const int nY = tCoords.nSubtileY;
    const int nWidth = tCoords.nSubtileWidth - 1;
    const int nHeight = tCoords.nSubtileHeight - 1;

    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
        return;

    const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
    D2MonStats2Txt* pMonStats2 = MONSTATS2_GetRecordInline(nMonStatsEx);
    if (!pMonStats2)
        return;

    const int nSize = pMonStats2->nSizeX;
    int nTry;
    int nPosX;
    int nPosY;
    for (nTry = 0; nTry < 10; ++nTry)
    {
        nPosX = nX + SEED_RollLimitedRandomNumberInline(pSeed, nWidth);
        nPosY = nY + SEED_RollLimitedRandomNumberInline(pSeed, nHeight);
        if (!COLLISION_CheckMaskWithSize(pRoom, nPosX, nPosY, nSize, 0x3F11))
            break;
    }

    if (nTry < 10)
        CUNIT_SpawnPresetUnit(nMonsterId, nPosX, nPosY, 1, 0);
}

// 0x0046C460
void __fastcall sub_0046C460_PopulateRoom(D2ActiveRoomStrc* pRoom)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId)
        return;

    D2LevelsTxt* pLevel = DATATBLS_GetLevelsTxtRecord(nLevelId);
    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    for (int i = 0; i < 4; ++i)
    {
        if (pLevel->wCMon[i] < 0)
            break;

        if ((unsigned int)SEED_RollRandomNumberForceInline(pSeed) % 100 < (unsigned int)pLevel->wCPct[i])
        {
            const int nMonsterId = pLevel->wCMon[i];
            D2MonStatsTxt* pMonStats = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
            int nCount = ITEMS_RollLimitedRandomNumber(pSeed, pMonStats->nMaxGrp - pMonStats->nMinGrp) + pMonStats->nMinGrp;
            if (pLevel->wCAmt[i])
                nCount *= pLevel->wCAmt[i];

            while (nCount > 0)
            {
                sub_0046C1A0_SpawnMonsterInRoom(pRoom, pLevel->wCMon[i], pSeed);
                --nCount;
            }
        }
    }
}
