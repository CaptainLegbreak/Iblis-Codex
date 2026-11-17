struct D2GameStrc;
struct D2DynamicPathStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x16];
    unsigned short nFlags;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2MissilesTxt
{
    char unk0x00[0x04];
    unsigned char nFlags[4];
    char unk0x08[0x1A4 - 0x08];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[];                                                                    // 0x006CE268
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pOwner, int nSkillId, int nSkillLevel, int a6, int a7, int nX, int nY, int a10); // 0x0056ECB0
int __fastcall sub_005A0180_CheckMonsterFlag(D2UnitStrc* pUnit, int nFlag);                                 // 0x005A0180
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pPath);                                  // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pPath);                                  // 0x00648A10
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed);                                          // 0x00650E40

static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static int sub_005A3610_IsWideMissile(int nMissileId)
{
    if (nMissileId < 0x3F)
    {
        return 0;
    }
    if (nMissileId > 0x42)
    {
        return 0;
    }
    return 1;
}

// 0x005A3610
void __fastcall sub_005A3610_SpawnSideMissiles(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnused, int nArg)
{
    if (!nArg || !pMissile || pMissile->dwUnitType != 3)
    {
        return;
    }

    const int nMissileId = pMissile->dwClassId;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(nMissileId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->nFlags[12 >> 3] & gdwBitMasks[12 & 7])
    {
        return;
    }

    if (sub_005A0180_CheckMonsterFlag(pOwner, 0x80))
    {
        return;
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pOwner);
    int nY;
    if (!pTarget)
    {
        nArg = D2COMMON_10175_PathGetFirstPointX(pPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        nArg = CLIENTS_GetUnitX(pTarget);
        nY = CLIENTS_GetUnitY(pTarget);
    }

    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, 0x53454953);
    tSeed.nHighSeed = pOwner->dwUnitId;

    int nDeltaX = CLIENTS_GetUnitX(pOwner) - nArg;
    int nDeltaY = CLIENTS_GetUnitY(pOwner) - nY;
    if (nDeltaX < 0)
    {
        nDeltaX = -1;
    }
    else if (nDeltaX > 0)
    {
        nDeltaX = 1;
    }

    if (nDeltaY < 0)
    {
        nDeltaY = -1;
    }
    else if (nDeltaY > 0)
    {
        nDeltaY = 1;
    }

    if (sub_005A3610_IsWideMissile(nMissileId))
    {
        nDeltaY = 0;
        nDeltaX = 0;
    }

    if (pOwner->dwUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nFlags |= 0x80;
        }
    }

    sub_6FD11420(pGame, nMissileId, pOwner, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), 0, 0, nArg - nDeltaY, nY + nDeltaX, 0);
    sub_6FD11420(pGame, nMissileId, pOwner, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), 0, 0, nArg + nDeltaY, nY - nDeltaX, 0);

    if (pOwner->dwUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nFlags &= ~0x80;
        }
    }
}
