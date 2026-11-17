struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2SkillsTxt
{
    char unk0x000[0x148];
    int dwParam[8];
    char unk0x168[0xD4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

struct D2UnitFindArgStrc
{
    int nFlags; int unk0x04; D2UnitStrc* pUnit; int nX; int nY; int nSize; int nMaxArrayEntries; int nIndex;
    void* pField; void* pfnUnitTest; int unk0x28; int unk0x2C; int unk0x30; int unk0x34;
};

struct D2UnitFindDataStrc
{
    void* pMemPool; D2UnitStrc** pUnitsArray; D2ActiveRoomStrc* pRoom; void* pfnUnitTest; D2UnitFindArgStrc* pUnitFindArg;
    int nFlags; int nIndex; int nMaxArrayEntries; int nX; int nY; int nSize;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0
int __stdcall MISSILE_GetTotalFrames(D2UnitStrc* pMissile);                                                 // 0x0064A300
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData);                               // 0x0065AA00
void __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData);          // 0x0065AC70

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 nValue = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5u;
    pSeed->nHighSeed = (unsigned int)(nValue >> 32);
    pSeed->nLowSeed = (unsigned int)nValue;
    return (unsigned int)nValue;
}

// 0x004F1430
int __fastcall sub_004F1430_MissilesOnUnitsInRadius(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(285);
    int nSize;
    if (!pSkillsTxtRecord)
    {
        nSize = 0;
    }
    else if (nSkillLevel <= 0)
    {
        nSize = 0;
    }
    else
    {
        nSize = (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[5] + pSkillsTxtRecord->dwParam[4];
    }

    const int nX = UNITS_GetUnitXPosition(pUnit);
    const int nY = UNITS_GetUnitYPosition(pUnit);

    D2UnitFindArgStrc tUnitFindArg;
    memset(&tUnitFindArg, 0, sizeof(tUnitFindArg));
    tUnitFindArg.nFlags = 0x3002;
    tUnitFindArg.pUnit = pUnit;
    tUnitFindArg.nX = nX;
    tUnitFindArg.nY = nY;
    tUnitFindArg.nSize = nSize;

    D2UnitFindDataStrc tUnitFindData;
    UNITFINDS_InitializeUnitFindData(0, &tUnitFindData, UNITS_GetRoom(pUnit), nX, nY, nSize, 0, &tUnitFindArg);
    tUnitFindData.nFlags = tUnitFindArg.nFlags;
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&tUnitFindData);

    for (int i = 0; i < tUnitFindData.nIndex; ++i)
    {
        D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pUnit, 0x24B, UNITS_GetUnitXPosition(tUnitFindData.pUnitsArray[i]), UNITS_GetUnitYPosition(tUnitFindData.pUnitsArray[i]), nSkillId, nSkillLevel);
        if (pMissile)
        {
            int nFrames = MISSILE_GetTotalFrames(pMissile);
            nFrames += SEED_RollRandomNumber(&pUnit->pSeed) % 20 - 10;
            MISSILE_SetTotalFrames(pMissile, nFrames);
            MISSILE_SetCurrentFrame(pMissile, nFrames);
        }
    }

    UNITFINDS_FreeUnitFindData(&tUnitFindData);
    return 1;
}
