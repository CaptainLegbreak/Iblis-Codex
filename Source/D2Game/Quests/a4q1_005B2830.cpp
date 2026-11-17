#include "D2Game.h"

#define MONSTER_TENTACLEHEAD1 261
#define MONSTATSFLAGINDEX_SETBOSS 4
#define MONSTATSFLAGINDEX_BOSSXFER 5
struct D2SeedStrc;
struct D2UnkMonCreateStrc;
struct D2MonStatsTxt;
struct D2UnkMonCreateStrc3;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x10];
    D2SeedStrc pSeed;
};

struct D2UnkMonCreateStrc
{
    D2GameStrc* pGame;
    D2ActiveRoomStrc* pRoom;
    D2RoomCoordListStrc* pRoomCoordList;
    int nMonsterId;
    int nAnimMode;
    int nUnitGUID;
    int nX;
    int nY;
    int field_20;
    short nFlags;
};

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    char pad0x04[0x08];
    unsigned char nMonStatsFlags;
    char pad0x0D[0x19];
    short wMinion[2];
    char pad0x2A[0x02];
    unsigned char nPartyMin;
    unsigned char nPartyMax;
    char pad0x2E[0x1A8 - 0x2E];
};

struct D2DataTablesStrc
{
    char pad0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char pad0xA7C[4];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50
int __fastcall sub_00463830_GetBaseIdFromMonsterId(int nMonsterId); // 0x00463830
int __fastcall sub_004CC790_RollRange(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004CC790
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion); // 0x0058F100
int __fastcall sub_005B2570_SpawnMinionsAround(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int nCount, int nOffset, short nFlags); // 0x005B2570
void __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pChainId, int* pMissileOffset); // 0x006510C0
static __declspec(noinline) void MONSTERSPAWN_SpawnMinionParty(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit);

struct D2UnkMonCreateStrc3
{
    int nXOffset;
    int nYOffset;
    int nSpawnType;
};

struct D2UnkMonCreateStrc2
{
    int nRecordCount;
    int unk0x04;
    unsigned char unk0x08;
    unsigned char pad0x09[3];
    D2UnkMonCreateStrc3 records[4];
};

D2UnitStrc* __fastcall D2GAME_SpawnNormalMonster_6FC68E30(D2UnkMonCreateStrc* pMonCreate); // 0x005B2A00
D2UnitStrc* __fastcall sub_005B3130_SpawnLeader(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId, int nAnimMode, int a7, int a8, unsigned short nFlags); // 0x005B3130
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId, int nAnimMode, int a7, short nFlags); // 0x005B2F20
int __fastcall sub_6FC6A230(D2GameStrc* pGame, D2UnitStrc* pOwner, int nX, int nY, int nMonsterId, int nAnimMode, int a5, int nCount, short nFlags); // 0x005B31B0
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

// 0x005B2830
static void MONSTERSPAWN_SpawnMinionParty(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit)
{
    const int nMonsterId = pMonCreate->nMonsterId;
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inline(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    int nChainId;
    DATATBLS_GetMonsterChainInfo(nMonsterId, 0, &nChainId);

    D2GameStrc* pGame = pMonCreate->pGame;
    const unsigned short nFlags = pMonCreate->nFlags;
    const short nMinion = pMonStatsTxtRecord->wMinion[0];
    if (nMinion < 0)
    {
        return;
    }
    const int nCount = *(volatile int*)&sgptDataTables->nMonStatsTxtRecordCount;
    if (nMinion >= nCount)
    {
        return;
    }

    const int nBaseId = sub_00463830_GetBaseIdFromMonsterId(nMonsterId);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount || nBaseId != MONSTER_TENTACLEHEAD1)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags & gdwBitMasks[MONSTATSFLAGINDEX_SETBOSS])
        {
            AIGENERAL_SetOwnerData(pGame, pUnit, !pUnit ? -1 : pUnit->dwUnitId, 1, 1, pMonStatsTxtRecord->nMonStatsFlags & gdwBitMasks[MONSTATSFLAGINDEX_BOSSXFER]);
        }

        int nMinionIndex = 0;
        int nThreshold = 0;
        if (pMonStatsTxtRecord->wMinion[1] >= 0 && pMonStatsTxtRecord->wMinion[1] < sgptDataTables->nMonStatsTxtRecordCount)
        {
            nThreshold = 1;
        }

        const int nMinions = sub_004CC790_RollRange(&pUnit->pSeed, pMonStatsTxtRecord->nPartyMin, pMonStatsTxtRecord->nPartyMax);
        for (int i = 0; i < nMinions; ++i)
        {
            D2UnitStrc* pMonster = MONSTERSPAWN_SpawnAtUnit(pGame, pUnit, pMonStatsTxtRecord->wMinion[nMinionIndex], 1, 4, 0x40);
            if (pMonster && (pMonStatsTxtRecord->nMonStatsFlags & gdwBitMasks[MONSTATSFLAGINDEX_SETBOSS]))
            {
                AIGENERAL_SetOwnerData(pGame, pMonster, sub_00451F50_GetUnitGUID(pUnit), 1, 0, 0);
                AIGENERAL_AllocMinionList(pGame, pUnit, pMonster);
            }

            ++nMinionIndex;
            if (nMinionIndex > nThreshold)
            {
                nMinionIndex = 0;
            }
        }
    }
    else
    {
        AIGENERAL_SetOwnerData(pGame, pUnit, !pUnit ? -1 : pUnit->dwUnitId, 1, 1, pMonStatsTxtRecord->nMonStatsFlags & gdwBitMasks[MONSTATSFLAGINDEX_BOSSXFER]);
        const int nMinions = sub_004CC790_RollRange(&pUnit->pSeed, pMonStatsTxtRecord->nPartyMin, pMonStatsTxtRecord->nPartyMax);
        const unsigned int bNonWaterSpawn = ~((unsigned int)nFlags >> 2) & 1;
        sub_005B2570_SpawnMinionsAround(pGame, pUnit, pMonStatsTxtRecord->wMinion[0], 1, nMinions, bNonWaterSpawn, 0x40);
    }
}

// build: context sub_005B2830_Shim
// calling-convention shim (not game code)
void __fastcall sub_005B2830_Shim(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit)
{
    MONSTERSPAWN_SpawnMinionParty(pMonCreate, pUnit);
}

// 0x005B3270
int __fastcall MONSTERSPAWN_SpawnFormation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pOwner, int nClassId, int nAnimMode, D2UnkMonCreateStrc2* pInfo, short nFlags)
{
    int nResult = 0;
    D2UnitStrc* pLeader = 0;
    int bForce = 0;
    int bIncrement = 0;
    if (pInfo->unk0x08 & 1) bIncrement = 1;
    if (nFlags & 1) bForce = 1;
    const int nCount = pInfo->nRecordCount;
    for (int i = 0; i < nCount; ++i)
    {
        pInfo = (D2UnkMonCreateStrc2*)pInfo->records;
        D2UnkMonCreateStrc3* pRecord = (D2UnkMonCreateStrc3*)pInfo;
        switch (bForce ? 4 : pRecord->nSpawnType)
        {
        case 1:
            pLeader = sub_005B3130_SpawnLeader(pGame, pRoom, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 0, 0);
            if (pLeader) nResult = 1;
            break;
        case 2:
            pLeader = sub_005B3130_SpawnLeader(pGame, pRoom, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 1, 0);
            if (pLeader) nResult = 1;
            break;
        case 5:
            if (pOwner)
            {
                D2UnitStrc* pMinion = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 0);
                if (pMinion)
                {
                    AIGENERAL_SetOwnerData(pGame, pMinion, sub_00451F50_GetUnitGUID(pOwner), sub_0044BE50_GetUnitTypeOrInvalid(pOwner), 0, 0);
                    nResult = 1;
                }
            }
            break;
        case 3:
            if (pLeader && sub_6FC6A230(pGame, pLeader, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 1, 0)) nResult = 1;
            break;
        case 0:
        {
            D2UnkMonCreateStrc monCreate;
            monCreate.nUnitGUID = 0;
            monCreate.nMonsterId = nClassId;
            monCreate.nAnimMode = nAnimMode;
            monCreate.field_20 = -1;
            monCreate.pGame = pGame;
            monCreate.pRoomCoordList = 0;
            monCreate.pRoom = pRoom;
            monCreate.nFlags = nFlags;
            monCreate.nX = nX + pRecord->nXOffset;
            monCreate.nY = nY + pRecord->nYOffset;
            if (D2GAME_SpawnNormalMonster_6FC68E30(&monCreate)) nResult = 1;
            break;
        }
        case 4:
        {
            nResult = 1;
            D2UnkMonCreateStrc monCreate;
            monCreate.nUnitGUID = 0;
            monCreate.nMonsterId = nClassId;
            monCreate.nAnimMode = nAnimMode;
            monCreate.field_20 = -1;
            monCreate.pGame = pGame;
            monCreate.pRoomCoordList = 0;
            monCreate.pRoom = pRoom;
            monCreate.nFlags = nFlags;
            monCreate.nX = nX + pRecord->nXOffset;
            monCreate.nY = nY + pRecord->nYOffset;
            if (!D2GAME_SpawnNormalMonster_6FC68E30(&monCreate)) return 0;
            break;
        }
        }
        if (bIncrement) ++nClassId;
    }
    return nResult;
}
