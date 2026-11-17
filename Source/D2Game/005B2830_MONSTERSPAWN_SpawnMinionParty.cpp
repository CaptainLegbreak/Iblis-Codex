struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2RoomCoordListStrc;

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

#define MONSTER_TENTACLEHEAD1 261
#define MONSTATSFLAGINDEX_SETBOSS 4
#define MONSTATSFLAGINDEX_BOSSXFER 5

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50
int __fastcall sub_00463830_GetBaseIdFromMonsterId(int nMonsterId);                                         // 0x00463830
int __fastcall sub_004CC790_RollRange(D2SeedStrc* pSeed, int nMin, int nMax);                              // 0x004CC790
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion);       // 0x0058F100
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0
int __fastcall sub_005B2570_SpawnMinionsAround(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int nCount, int nOffset, short nFlags); // 0x005B2570
void __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pChainId, int* pMissileOffset);            // 0x006510C0

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

static __declspec(noinline) void MONSTERSPAWN_SpawnMinionParty(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit);

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
