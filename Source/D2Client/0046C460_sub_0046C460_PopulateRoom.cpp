struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
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

struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
    D2SeedStrc tSeed;
};

struct D2MonStatsTxt
{
    char unk0x00[0x18];
    short nMonStatsEx;
    char unk0x1A[0x15];
    unsigned char nMinGrp;
    unsigned char nMaxGrp;
    char unk0x31[0x1A8 - 0x31];
};

struct D2MonStats2Txt
{
    char unk0x00[8];
    char nSizeX;
    char unk0x09[0x134 - 0x09];
};

struct D2LevelsTxt
{
    char unk0x00[0xCC];
    short wCMon[4];
    short wCPct[4];
    short wCAmt[4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x0C];
    D2MonStats2Txt* pMonStats2Txt;
    char unk0xA94[4];
    int nMonStats2TxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
void __fastcall sub_00466730_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode);         // 0x00466730
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask);// 0x0064D9B0

static __forceinline unsigned __int64 SEED_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;

    if ((nMax - 1) & nMax)
        return (unsigned int)SEED_RollRandomNumberForceInline(pSeed) % nMax;

    return SEED_RollRandomNumberForceInline(pSeed) & (nMax - 1);
}

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

    const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].nMonStatsEx;
    if (nMonStatsEx < 0 || nMonStatsEx >= sgptDataTables->nMonStats2TxtRecordCount)
        return;

    D2MonStats2Txt* pMonStats2 = &sgptDataTables->pMonStats2Txt[nMonStatsEx];
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
        sub_00466730_SpawnPresetUnit(nMonsterId, nPosX, nPosY, 1, 0);
}

// 0x0046C460
void __fastcall sub_0046C460_PopulateRoom(D2ActiveRoomStrc* pRoom)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId)
        return;

    D2LevelsTxt* pLevel = DATATBLS_GetLevelsTxtRecord(nLevelId);
    D2SeedStrc* pSeed = pRoom ? &pRoom->tSeed : 0;
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
