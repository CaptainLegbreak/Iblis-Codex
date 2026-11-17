struct D2DynamicPathStrc;
struct D2SkillStrc;
struct D2ActiveRoomStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc tSeed;
    char unk0x28[0x04];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x94];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    char unk0x000[0x80];
    short nAuraState;
    char unk0x082[0xC6];
    int dwParam[8];
    char unk0x168[0xD4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xAD0];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther);                           // 0x00465C60
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall sub_004C76D0_ScaleFramePrecise(D2UnitStrc* pUnit, int nPercent);                            // 0x004C76D0
void __fastcall sub_004C7BE0_ApplyClientSkillCalc(D2UnitStrc* pUnit, int nValue);                           // 0x004C7BE0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill);                                                        // 0x006444A0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue);                                           // 0x006445E0
int __stdcall D2COMMON_11018(D2UnitStrc* pUnit);                                                            // 0x00645590
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance);            // 0x00648E70
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);               // 0x00649970
void __stdcall D2Common_10235_PATH_UpdateRiderPath(D2UnitStrc* pRiderUnit, D2UnitStrc* pMountUnit);         // 0x006505E0
int __stdcall MISSILE_GetTotalFrames(D2UnitStrc* pMissile);                                                 // 0x0064A300
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline int __fastcall UNITS_GetXPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int __fastcall UNITS_GetYPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int UNITS_GetClassIdInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x004F0C20
int __fastcall sub_004F0C20_StoreTargetPos(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, UNITS_GetXPositionInl(pTarget));
    SKILLS_SetParam2(pSkill, UNITS_GetYPositionInl(pTarget));
    return 1;
}

// 0x004F0DD0
int __fastcall sub_004F0DD0_StoreTargetInfo(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (pSkill)
    {
        D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
        if (pTarget && D2COMMON_11018(pTarget))
        {
            SKILLS_SetParam1(pSkill, CLIENTS_GetUnitX(pTarget));
            SKILLS_SetParam2(pSkill, CLIENTS_GetUnitY(pTarget));
            SKILLS_SetParam3(pSkill, UNITS_GetClassIdInl(pTarget));
            return 1;
        }
    }

    return 0;
}

// 0x004F0EF0
int __fastcall sub_004F0EF0_UpdateRiderPath(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
    if (!pOwner)
    {
        return 0;
    }

    D2Common_10235_PATH_UpdateRiderPath(pUnit, pOwner);
    return 1;
}

// 0x004F2010
int __fastcall sub_004F2010_CheckTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (pTarget && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)) && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget))
        && (unsigned int)pTarget->dwUnitType <= 1)
    {
        return sub_00465C60_CheckUnitPair(pUnit, pTarget) != 0;
    }

    return 0;
}

// 0x004F2160
int __fastcall sub_004F2160_DecrementParam(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (!sub_004648F0_GetTargetUnit(pUnit))
    {
        return 0;
    }

    const int nParam = SKILLS_GetParam1(pSkill) - 1;
    if (nParam > 0)
    {
        SKILLS_SetParam1(pSkill, nParam);
        sub_004C76D0_ScaleFramePrecise(pUnit, 100);
    }

    return 1;
}

// 0x004F23E0
int __fastcall sub_004F23E0_AuraStateOff(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        return !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState);
    }

    return 0;
}

// 0x004F2440
void __fastcall sub_004F2440_ClearState(D2UnitStrc* pUnit, int nState, int nSkillLevel)
{
    STATES_ToggleState(pUnit, nState, 0);
}

// 0x004F26D0
int __fastcall sub_004F26D0_ApplyCltCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    sub_004C7BE0_ApplyClientSkillCalc(pUnit, !pSkillsTxtRecord ? 0 : pSkillsTxtRecord->dwParam[3]);
    return 1;
}

// 0x004F2870
int __fastcall sub_004F2870_TargetIsPlayerOrMonster(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType == 1 || pTarget->dwUnitType == 0)
    {
        return 1;
    }

    return 0;
}

// 0x004F2AC0
void __fastcall sub_004F2AC0_MissileInit(D2UnitStrc* pMissile, int nSeed)
{
    if (!pMissile)
    {
        return;
    }

    int nFrames = MISSILE_GetTotalFrames(pMissile);
    if (nFrames >= 0x4E)
    {
        nFrames = 0x4D;
        MISSILE_SetTotalFrames(pMissile, nFrames);
        MISSILE_SetCurrentFrame(pMissile, nFrames);
    }

    D2DynamicPathStrc* pDynamicPath = pMissile->pDynamicPath;
    SEED_InitLowSeed(&pMissile->tSeed, nSeed);
    PATH_SetType(pDynamicPath, 10);
    PATH_SetNewDistance(pDynamicPath, nFrames);
    D2Common_10142(pDynamicPath, pMissile, 0);
}
