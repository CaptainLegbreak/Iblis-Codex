struct D2DynamicPathStrc;
struct D2InventoryStrc;
struct D2SkillListStrc;
struct D2LightStrc;

struct D2MonsterDataStrc
{
    char unk0x00[0x2C];
    void* pUnk2C;
};

struct D2MonStatsTxt
{
    char unk0x000[0x0C];
    unsigned char nFlags[4];
    char unk0x010[0x08];
    short wMonStatsEx;
    char unk0x01A[0x18];
    short wVelocity;
    char unk0x034[0x19];
    unsigned char nMode4D;
    char unk0x04E[0xF6];
    short wResDm[3];
    short wResMa[3];
    short wResFi[3];
    short wResLi[3];
    short wResCo[3];
    short wResPo[3];
    char unk0x168[0x08];
    short wSkill[8];
    char unk0x180[0x18];
    char nSkLvl[8];
    char unk0x1A0[0x08];
};

struct D2MonStats2Txt
{
    char unk0x000[0x04];
    unsigned char nFlags[4];
    char unk0x008[0x12C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x0C];
    D2MonStats2Txt* pMonStats2Txt;
    char unk0xA94[0x04];
    int nMonStats2TxtRecordCount;
};

struct D2SeedStrc
{
    union
    {
        struct
        {
            unsigned int nLowSeed;
            unsigned int nHighSeed;
        };
        unsigned __int64 lSeed;
    };
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x08];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x14];
    int nUnk44;
    int nUnk48;
    char unk0x4C[0x14];
    D2InventoryStrc* pInventory;
    char unk0x64[0x08];
    int nUnk6C;
    char f_70[0x38];
    D2SkillListStrc* pSkills;
    char unk0xAC[0x18];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2DirectionArgStrc
{
    unsigned char nDirection;
};

#define I07_OFFSET(s, m) ((unsigned int)&((s*)0)->m)
typedef char I07_check_unit_a[(I07_OFFSET(D2UnitStrc, pSeed) == 0x20 && I07_OFFSET(D2UnitStrc, pDynamicPath) == 0x2C) ? 1 : -1];
typedef char I07_check_unit_b[(I07_OFFSET(D2UnitStrc, dwFlagEx) == 0xC8 && I07_OFFSET(D2StaticPathStrc, nYPos) == 0x10) ? 1 : -1];

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern const int gaRandomCurseSkills_006DA5DC[];                                                            // 0x006DA5DC
extern D2UnitStrc* gpEventUnit_007C0C5C;                                                                    // 0x007C0C5C
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_00465BF0(D2UnitStrc* pUnit, int nArg);                                                  // 0x00465BF0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit);                                              // 0x004DA000
void __fastcall sub_004DA620(D2UnitStrc* pUnit, int nArg);                                                  // 0x004DA620
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                                     // 0x00621CE0
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, D2DirectionArgStrc tDirection);          // 0x006488A0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0
void __stdcall sub_00649030_SetPathFlag40(D2DynamicPathStrc* pPath, int bClear);                            // 0x00649030
void __stdcall sub_00649190_SetPathMode(D2UnitStrc* pUnit, int nMode);                                      // 0x00649190

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
unsigned char __cdecl sub_0044DCD0_GetDifficulty();                                                         // 0x0044DCD0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
void __fastcall sub_00463E20_SetUnitFlagA(D2UnitStrc* pUnit, int bSet);                                     // 0x00463E20
void __fastcall sub_00463E80_SetUnitFlagB(D2UnitStrc* pUnit, int bSet);                                     // 0x00463E80
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit);                                                  // 0x00464930
void __fastcall sub_00466CB0_RemoveInventoryUnits(D2UnitStrc* pUnit, int nArg);                             // 0x00466CB0
void __fastcall sub_0046EC10_FreeGfxData(D2UnitStrc* pUnit);                                                // 0x0046EC10
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall sub_004743D0_ReleaseOverlayResource(D2LightStrc* pLight);                                   // 0x004743D0
void __fastcall sub_004AD020_RefreshMonster(D2UnitStrc* pUnit);                                             // 0x004AD020
void __fastcall sub_004AE0A0_SetClientFlags(D2UnitStrc* pUnit, unsigned short wFlags);                      // 0x004AE0A0
void __fastcall sub_004AE210_SetMonsterLight(D2UnitStrc* pUnit);                                            // 0x004AE210
void __fastcall sub_004DC510_InitGfxData(D2UnitStrc* pUnit);                                                // 0x004DC510
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, void* pGame);       // 0x00626D40
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner);                    // 0x0063ABD0
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory);                                        // 0x0063AC40
D2SkillListStrc* __stdcall SKILLS_AllocSkillList(void* pMemPool);                                           // 0x006438B0
D2LightStrc* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2);                                         // 0x00643A00
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
void __stdcall sub_00649FF0(D2UnitStrc* pUnit, int nArg);                                                   // 0x00649FF0
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection);                // 0x006488A0

static __forceinline unsigned int sub_H12_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned __int64 sub_I07_SeedRoll(D2SeedStrc* pSeed)
{
    const unsigned int nLowSeed = pSeed->nLowSeed;
    const unsigned int nHighSeed = pSeed->nHighSeed;
    unsigned __int64 lSeed = nHighSeed + 0x6AC690C5i64 * nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static __forceinline int sub_H12_UnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int sub_H12_UnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __declspec(noinline) void sub_004AE400_CastRandomCurse(D2UnitStrc* pUnit)
{
    const int nIndex = sub_H12_SeedStep(&pUnit->pSeed) % 5;
    D2_ASSERT(nIndex < 5, 0x174);

    const int nSkill = gaRandomCurseSkills_006DA5DC[nIndex];
    D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pUnit, nSkill, sub_H12_UnitX(pUnit), sub_H12_UnitY(pUnit), 0, 1);
    if (pMissile)
    {
        UNITS_StoreOwner(pMissile, pUnit);
        UNITS_StoreOwner(pUnit, pMissile);
        sub_004DA000_ResetGfxMotion(pMissile);
        sub_004DA620(pMissile, 1);
        pMissile->dwFlagEx |= 0x40000;
    }
}

static void sub_004AE4F0_MonsterEvent(D2UnitStrc* pUnit, int nEvent); // 0x004AE4F0

static __declspec(noinline) void sub_004AE4F0_MonsterEvent(D2UnitStrc* pUnit, int nEvent)
{
    switch (nEvent)
    {
    case 0x14B:
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        if (pPlayer)
        {
            UNITS_SetTargetUnitForDynamicUnit(pUnit, pPlayer);
            sub_00465BF0(pUnit, 0);
        }
        break;
    }
    case 0x9D:
    case 0x9E:
    case 0x13F:
        sub_00649190_SetPathMode(pUnit, 5);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0);
        break;
    case 0x96:
        gpEventUnit_007C0C5C = pUnit;
        break;
    case 0x158:
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        D2DirectionArgStrc tDirection;
        tDirection.nDirection = sub_I07_SeedRoll(&pPlayer->pSeed) & 0x3F;
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        sub_00649030_SetPathFlag40(pPath, 1);
        sub_006488A0_SetDirection(pPath, tDirection);
        sub_00649030_SetPathFlag40(pPath, 0);
        break;
    }
    case 0x1F1:
    case 0x1F2:
    case 0x1F3:
    case 0x1F4:
        sub_004AE400_CastRandomCurse(pUnit);
        break;
    case 0x19D:
    {
        D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pUnit, 0x188, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
        if (pMissile)
        {
            UNITS_StoreOwner(pMissile, pUnit);
        }
        break;
    }
    case 0x23A:
        sub_004CDB40_SubmitRequest(pUnit, 0x265, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
        break;
    }
}

static __forceinline D2MonStatsTxt* sub_F4B0_GetMonStatsTxt(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nId];
    }

    return 0;
}

static __forceinline D2MonStats2Txt* sub_F4B0_GetMonStats2TxtFromMonsterId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = sub_F4B0_GetMonStatsTxt(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        const int nId = pMonStatsTxtRecord->wMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }

    return 0;
}

// 0x004AEDD0
void __fastcall sub_004AEDD0_ChangeMonsterClass(D2UnitStrc* pUnit, int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = sub_F4B0_GetMonStatsTxt(nClassId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = sub_F4B0_GetMonStats2TxtFromMonsterId(nClassId);
    if (!pMonStats2TxtRecord)
    {
        return;
    }

    sub_0046EC10_FreeGfxData(pUnit);
    sub_00466CB0_RemoveInventoryUnits(pUnit, 0);
    INVENTORY_FreeInventory(pUnit->pInventory);
    pUnit->pInventory = 0;
    sub_00464930_FreeLight(pUnit);
    D2LightStrc* pLight = D2Common_10958(pUnit, 0);
    if (pLight)
    {
        sub_004743D0_ReleaseOverlayResource(pLight);
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData && pMonsterData->pUnk2C)
        {
            FOG_Free(pMonsterData->pUnk2C, ".\\UNIT\\Monster.cpp", 0x66, 0);
            pMonsterData->pUnk2C = 0;
        }
    }

    pUnit->nUnk6C = 0;
    pUnit->dwClassId = nClassId;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return;
    }

    PATH_SetVelocity(pPath, pMonStatsTxtRecord->wVelocity << 8, ".\\UNIT\\Monster.cpp", 0x2B8);
    sub_00649FF0(pUnit, 0);
    if ((pMonStatsTxtRecord->nFlags[9 >> 3] & gdwBitMasks[9 & 7]) && !pUnit->pInventory)
    {
        pUnit->pInventory = INVENTORY_AllocInventory(0, pUnit);
    }

    STATLIST_AllocStatListEx(pUnit, 0, 0, 0);
    STATLIST_SetUnitStat(pUnit, 0x44, 100, 0);
    STATLIST_SetUnitStat(pUnit, 0x43, 100, 0);
    STATLIST_SetUnitStat(pUnit, 0x45, 100, 0);
    const int nDifficulty = sub_0044DCD0_GetDifficulty();
    STATLIST_SetUnitStat(pUnit, 0x24, pMonStatsTxtRecord->wResDm[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, 0x25, pMonStatsTxtRecord->wResMa[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, 0x27, pMonStatsTxtRecord->wResFi[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, 0x29, pMonStatsTxtRecord->wResLi[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, 0x2B, pMonStatsTxtRecord->wResCo[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, 0x2D, pMonStatsTxtRecord->wResPo[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, 7, 0x8000, 0);
    STATLIST_SetUnitStat(pUnit, 6, 0x8000, 0);
    UNITS_ChangeAnimMode(pUnit, 1);
    pUnit->nUnk44 = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, pUnit->nUnk48);

    if (pMonStats2TxtRecord->nFlags[3 >> 3] & gdwBitMasks[3 & 7])
    {
        pUnit->dwFlags |= 2;
    }
    else
    {
        pUnit->dwFlags &= ~2;
    }

    pUnit->dwFlagEx &= ~0x40000;
    if (!(pMonStats2TxtRecord->nFlags[14 >> 3] & gdwBitMasks[14 & 7]))
    {
        pUnit->dwFlags |= 0x20;
    }
    else
    {
        pUnit->dwFlags &= ~0x20;
    }

    pUnit->dwFlags |= 8;
    if (pMonStats2TxtRecord->nFlags[9 >> 3] & gdwBitMasks[9 & 7])
    {
        pUnit->dwFlags |= 4;
    }
    else
    {
        pUnit->dwFlags &= ~4;
    }

    sub_004AE0A0_SetClientFlags(pUnit, 0);
    sub_004AE4F0_MonsterEvent(pUnit, nClassId);
    sub_004AE210_SetMonsterLight(pUnit);
    sub_004AD020_RefreshMonster(pUnit);
    pUnit->pSkills = SKILLS_AllocSkillList(0);
    for (int i = 0; i < 8; ++i)
    {
        if (pMonStatsTxtRecord->wSkill[i] >= 0)
        {
            SKILLS_AssignSkill(pUnit, pMonStatsTxtRecord->wSkill[i], pMonStatsTxtRecord->nSkLvl[i], 0, ".\\UNIT\\Monster.cpp", 0x2EA);
        }
    }

    if (!(pMonStatsTxtRecord->nFlags[8 >> 3] & gdwBitMasks[8 & 7]))
    {
        PATH_SetDirection(pPath, (unsigned int)sub_I07_SeedRoll(&pUnit->pSeed) & 0x3F);
    }

    sub_004DC510_InitGfxData(pUnit);
    int nMode = 2;
    if (pMonStatsTxtRecord->nMode4D < 8)
    {
        nMode = pMonStatsTxtRecord->nMode4D + 2;
    }

    const int nId = (pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount) ? pUnit->dwClassId : -1;
    switch (nId)
    {
    case 0x9C:
    case 0xD3:
    case 0xF2:
    case 0xF3:
        switch (sub_0044DCD0_GetDifficulty())
        {
        case 0:
            nMode = 2;
            break;

        case 1:
            nMode = 3;
            break;

        case 2:
            nMode = 4;
            break;
        }
        break;

    case 0x14D:
        nMode = 5;
        break;

    case 0x20F:
        sub_00470390(pUnit, 0xE3, 5, 0, 0, 0, 0, 0);
        break;
    }

    if (nMode >= 8)
    {
        nMode = 2;
    }

    sub_00463E20_SetUnitFlagA(pUnit, nMode);
    sub_00463E80_SetUnitFlagB(pUnit, nMode);
}
