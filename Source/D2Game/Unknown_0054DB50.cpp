#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2GameActsViewStrc;
struct D2RoomWarpCoordsStrc;
struct D2LevelsTxt;
struct D2DrlgCoordsStrc;
struct D2SpawnAreaStrc;
struct D2SeedStrc;
struct D2MonStatsTxt;

struct D2GameActsViewStrc
{
    char unk0x00[0xBC];
    D2DrlgActStrc* pAct[5];
};

struct D2RoomWarpCoordsStrc
{
    int nX[9];
    int nY[9];
    int nCount;
};

struct D2LevelsTxt
{
    char unk0x00[0x0C];
    int nWarpDistSq;
};


struct D2ActiveRoomStrc { char pad[0x6c]; D2SeedStrc seed; };

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2RoomWarpCoordsStrc* __stdcall DUNGEON_GetWarpCoordinatesFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061AC10
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
void __stdcall sub_00643560_GameTileToSubtileCoords(int* pX, int* pY); // 0x00643560
static __declspec(noinline) int __stdcall sub_0054DB50_IsNearWarpOrSpawn(D2GameStrc* pGame, int nX, int nY, D2ActiveRoomStrc* pRoom);

struct D2DrlgCoordsStrc { int nSubtileX; int nSubtileY; int nSubtileWidth; int nSubtileHeight; int nTileXPos; int nTileYPos; int nTileWidth; int nTileHeight; };

struct D2SpawnAreaStrc { char unk0x00[0x10]; tagRECT tRect; char pad20[8]; int areaId; };
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
int __stdcall D2Common_10095(D2ActiveRoomStrc*,int,int); // 0x0061B130
D2UnitStrc* __fastcall sub_005B2F20_Spawn(D2GameStrc*,D2ActiveRoomStrc*,int,int,int,int,int,int); // 0x005B2F20
D2UnitStrc* __fastcall sub_005B3040_SpawnInCoordList(D2GameStrc*,D2ActiveRoomStrc*,D2SpawnAreaStrc*,int,int,int,int,int,int); // 0x005B3040

struct D2MonStatsTxt { short nId; short nBaseId; char unk_04[0x1A4]; };


extern D2DataTablesStrc* sgptDataTables; // 0x00744304

// 0x0054DB50
static int __stdcall sub_0054DB50_IsNearWarpOrSpawn(D2GameStrc* pGame, int nX, int nY, D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId)
    {
        return 0;
    }

    D2RoomWarpCoordsStrc* pWarps = DUNGEON_GetWarpCoordinatesFromRoom(pRoom);
    if (!pWarps)
    {
        return 0;
    }

    const int nDistSq = DATATBLS_GetLevelsTxtRecord(nLevelId)->nWarpDistSq;
    for (int i = 0; i < pWarps->nCount; ++i)
    {
        const int nDX = nX - pWarps->nX[i];
        const int nDY = nY - pWarps->nY[i];
        if (nDY * nDY + nDX * nDX < nDistSq)
        {
            return 1;
        }
    }

    int nSpawnX;
    int nSpawnY;
    DUNGEON_FindActSpawnLocation(((D2GameActsViewStrc*)pGame)->pAct[DRLG_GetActNoFromLevelId(nLevelId)], nLevelId, 11, &nSpawnX, &nSpawnY);
    if (nSpawnX > 0 && nSpawnY > 0)
    {
        sub_00643560_GameTileToSubtileCoords(&nSpawnX, &nSpawnY);
        const int nDX = nX - nSpawnX;
        const int nDY = nY - nSpawnY;
        if (nDY * nDY + nDX * nDX < nDistSq)
        {
            return 1;
        }
    }

    return 0;
}

int __fastcall sub_0054DB50_Emit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    return sub_0054DB50_IsNearWarpOrSpawn(pGame, nX, nY, pRoom);
}

// 0x0054DAC0
static void __stdcall sub_0054DAC0_GetSpawnBounds(D2ActiveRoomStrc* pRoom, int* pWidth, D2SpawnAreaStrc* pArea, int* pX, int* pY, int* pHeight)
{
    if (!pArea)
    {
        D2DrlgCoordsStrc coords;
        DUNGEON_GetRoomCoordinates(pRoom, &coords);
        *pX = coords.nSubtileX + 1;
        *pY = coords.nSubtileY + 1;
        *pWidth = coords.nSubtileWidth - 1;
        *pHeight = coords.nSubtileHeight - 1;
    }
    else
    {
        tagRECT rect;
        CopyRect(&rect, &pArea->tRect);
        DUNGEON_GameTileToSubtileCoords(&rect.left, &rect.top);
        DUNGEON_GameTileToSubtileCoords(&rect.right, &rect.bottom);
        *pX = rect.left + 1;
        *pY = rect.top + 1;
        *pWidth = rect.right - *pX;
        *pHeight = rect.bottom - *pY;
    }
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
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

// 0x0054DC40
int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2SpawnAreaStrc* pArea, int nClassId, int* pX, int* pY, int bAvoidWarps)
{
    int nX, nY, nWidth, nHeight;
    sub_0054DAC0_GetSpawnBounds(pRoom, &nWidth, pArea, &nX, &nY, &nHeight);

    int bHasArea = 0;
    int nAreaIndex = 0;
    if (pArea)
    {
        nAreaIndex = pArea->areaId;
        bHasArea = 1;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->seed : 0;
    for (int nTry = 0; nTry < 20; ++nTry)
    {
        const int nPosX = SEED_RollLimitedRandomNumber(pSeed, nWidth) + nX;
        const int nPosY = SEED_RollLimitedRandomNumber(pSeed, nHeight) + nY;

        if (bAvoidWarps && sub_0054DB50_IsNearWarpOrSpawn(pGame, nPosX, nPosY, pRoom))
        {
            continue;
        }

        D2UnitStrc* pMonster;
        if (bHasArea)
        {
            if (D2Common_10095(pRoom, nPosX, nPosY) != nAreaIndex)
            {
                continue;
            }

            pMonster = sub_005B3040_SpawnInCoordList(pGame, pRoom, pArea, nPosX, nPosY, nClassId, 1, -1, 1);
        }
        else
        {
            pMonster = sub_005B2F20_Spawn(pGame, pRoom, nPosX, nPosY, nClassId, 1, -1, 1);
        }

        if (pMonster)
        {
            *pX = nPosX;
            *pY = nPosY;
            return 1;
        }
    }

    return 0;
}

// build: context GetMonStatsRecord
static __forceinline D2MonStatsTxt* GetMonStatsRecord(D2DataTablesStrc* pDataTables, int nClassId)
{
    D2MonStatsTxt* pRecord = 0;
    if (nClassId >= 0 && nClassId < pDataTables->nMonStatsTxtRecordCount)
    {
        pRecord = &pDataTables->pMonStatsTxt[nClassId];
    }
    return pRecord;
}

// 0x0054EC40
int __fastcall sub_0054EC40_IsSpecialBaseMonster(int nClassId)
{
    D2DataTablesStrc* pDataTables = sgptDataTables;
    if (nClassId < 0)
    {
        goto fail;
    }

    D2MonStatsTxt* pRecord = GetMonStatsRecord(pDataTables, nClassId);
    if (pRecord)
    {
        nClassId = pRecord->nBaseId;
    }

    if (nClassId < 0)
    {
        goto fail;
    }
    if (nClassId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        goto fail;
    }
    if (nClassId == 19 || nClassId == 91)
    {
        return 1;
    }
fail:
    return 0;
}
