struct D2DynamicPathStrc;

struct D2MonsterDataStrc
{
    char unk0[0x16];
    unsigned short wFlags;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0[0x4];
    int dwUnitId;
    char f_10[0x4];
    D2MonsterDataStrc* pMonsterData;
    char nAct[0x14];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2MissilesTxt
{
    char unk0[0x4];
    unsigned char nMissileFlags[4];
    char wCltDoFunc[0x19C];
};

struct D2DataTablesStrc
{
    char unk0[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char f_B68[0x4];
    int nMissilesTxtRecordCount;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit);                                   // 0x004648F0
extern "C" int __fastcall sub_004AC7E0(D2UnitStrc* pUnit, unsigned short wMask);                          // 0x004AC7E0
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pPath);                                  // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pPath);                                  // 0x00648A10
extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile);                                              // 0x0064A210
extern "C" int __stdcall sub_0064A280(D2UnitStrc* pMissile);                                              // 0x0064A280
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

__forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004AD970
void __fastcall sub_004AD970_StateMissileSplit(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag || !pUnit || pUnit->dwUnitType != 3)
    {
        return;
    }

    const int nMissileId = pUnit->dwClassId;
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
    if (!pOwner)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[12 >> 3] & gdwBitMasks[12 & 7])
    {
        return;
    }

    if (sub_004AC7E0(pOwner, 0x80))
    {
        return;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pOwner);
    int nX;

    if (!pTarget)
    {
        nX = D2COMMON_10175_PathGetFirstPointX(pPath);
        bFlag = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        nX = CLIENTS_GetUnitX(pTarget);
        bFlag = CLIENTS_GetUnitY(pTarget);
    }

    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, 'SEIS');
    tSeed.nHighSeed = pOwner->dwUnitId;

    int nDX = CLIENTS_GetUnitX(pOwner) - nX;
    int nDY = CLIENTS_GetUnitY(pOwner) - bFlag;

    if (nDX < 0)
    {
        nDX = -1;
    }
    else if (nDX > 0)
    {
        nDX = 1;
    }

    if (nDY < 0)
    {
        nDY = -1;
    }
    else if (nDY > 0)
    {
        nDY = 1;
    }

    switch (nMissileId)
    {
    case 63:
    case 63 + 1:
    case 63 + 2:
    case 66:
        nDY = 0;
        nDX = 0;
        break;
    }

    if (pOwner->dwUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->wFlags |= 0x80;
        }
    }

    sub_004CDBA0_SubmitOwnerRequest(pOwner, nMissileId, nX - nDY, bFlag + nDX, sub_0064A280(pUnit), sub_0064A210(pUnit));
    sub_004CDBA0_SubmitOwnerRequest(pOwner, nMissileId, nX + nDY, bFlag - nDX, sub_0064A280(pUnit), sub_0064A210(pUnit));

    if (pOwner->dwUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->wFlags &= ~0x80;
        }
    }
}
