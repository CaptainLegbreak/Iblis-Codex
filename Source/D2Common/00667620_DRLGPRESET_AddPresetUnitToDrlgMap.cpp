struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2PresetUnitStrc
{
    int nMode;
    int nIndex;
    int nXpos;
    D2PresetUnitStrc* pNext;
    void* pMapAI;
    int nUnitType;
    int nYpos;
    int bSpawned;
};

struct D2DrlgFileStrc
{
    char unk0x00[0x54];
    D2PresetUnitStrc* pPresetUnit;
};

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgMapStrc
{
    int nLevelPrest;
    int nPickedFile;
    void* pLvlPrestTxtRecord;
    D2DrlgFileStrc* pFile;
    D2DrlgCoordStrc pDrlgCoord;
    void* pVertices;
    char pMapGrid[0x14];
    D2PresetUnitStrc* pPresetUnit;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

void __stdcall DUNGEON_GameTileToSubtileCoords(int* pX, int* pY); // 0x00643560
int __stdcall DATATBLS_GetSuperUniquesTxtRecordCount(); // 0x00655710
D2PresetUnitStrc* __fastcall DRLGPRESET_CopyPresetUnit(void* pMemPool, D2PresetUnitStrc* pPresetUnit, int nX, int nY); // 0x00667510

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int DRLGPRESET_GetMonsterId(int nMonsterId, int nMonStatsCount)
{
    if (nMonsterId >= 0 && nMonsterId < nMonStatsCount)
    {
        return nMonsterId;
    }

    return -1;
}

// 0x00667620
void __fastcall DRLGPRESET_AddPresetUnitToDrlgMap(void* pMemPool, D2DrlgMapStrc* pDrlgMap, D2SeedStrc* pSeed)
{
    D2PresetUnitStrc* pPresetUnit = pDrlgMap->pFile->pPresetUnit;
    int nX = pDrlgMap->pDrlgCoord.nPosX;
    int nY = pDrlgMap->pDrlgCoord.nPosY;
    DUNGEON_GameTileToSubtileCoords(&nX, &nY);

    for (; pPresetUnit; pPresetUnit = pPresetUnit->pNext)
    {
        switch (pPresetUnit->nUnitType)
        {
        case 1:
        {
            const int nMonStatsCount = sgptDataTables->nMonStatsTxtRecordCount;
            if (pPresetUnit->nIndex < nMonStatsCount)
            {
                switch (DRLGPRESET_GetMonsterId(pPresetUnit->nIndex, nMonStatsCount))
                {
                case 204:
                case 205:
                case 371:
                case 372:
                    if (SEED_RollRandomNumber(pSeed) % 3)
                    {
                        continue;
                    }
                    break;
                }
            }
            else if (pPresetUnit->nIndex - nMonStatsCount >= DATATBLS_GetSuperUniquesTxtRecordCount())
            {
                const int nCount = sgptDataTables->nMonStatsTxtRecordCount;
                switch (pPresetUnit->nIndex - nCount - DATATBLS_GetSuperUniquesTxtRecordCount())
                {
                case 33:
                    if (!(SEED_RollRandomNumber(pSeed) & 3))
                    {
                        continue;
                    }
                    break;

                case 34:
                    if (!(SEED_RollRandomNumber(pSeed) & 1))
                    {
                        continue;
                    }
                    break;

                case 35:
                    if (SEED_RollRandomNumber(pSeed) & 3)
                    {
                        continue;
                    }
                    break;
                }
            }
            break;
        }

        case 2:
            switch (pPresetUnit->nIndex)
            {
            case 196:
            case 261:
                if (SEED_RollRandomNumber(pSeed) & 1)
                {
                    continue;
                }
                break;

            case 581:
                if (!(SEED_RollRandomNumber(pSeed) & 3))
                {
                    continue;
                }
                break;
            }
            break;
        }

        D2PresetUnitStrc* pNew = DRLGPRESET_CopyPresetUnit(pMemPool, pPresetUnit, nX, nY);
        pNew->pNext = pDrlgMap->pPresetUnit;
        pDrlgMap->pPresetUnit = pNew;
    }
}
