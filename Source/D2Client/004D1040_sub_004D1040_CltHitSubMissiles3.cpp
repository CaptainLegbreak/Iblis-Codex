struct D2DynamicPathStrc;
struct D2InventoryStrc;
struct D2SkillStrc;
struct D2ActiveRoomStrc;

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2CltUnitEventStrc
{
    int nType;
    int f_4;
    int f_8;
    int nParam1;
    int nParam2;
    int nParam3;
    D2CltUnitEventStrc* pPrevious;
    D2CltUnitEventStrc* pNext;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int unk0x10[7];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    int unk0x30[12];
    D2InventoryStrc* pInventory;
    int unk0x64[11];
    D2CltUnitEventStrc* pCltTimerList;
    int unk0x94[12];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[6];
    int nFrames;
    void* pfCallback;
    D2UnitStrc* pInitArgs;
};

struct D2MissilesTxt
{
    unsigned short wId;
    unsigned short pad0x02;
    unsigned int dwMissileFlags;
    unsigned short wCltDoFunc;
    unsigned short wCltHitFunc;
    unsigned short wSrvDoFunc;
    unsigned short wSrvHitFunc;
    unsigned short wSrvDmgFunc;
    unsigned short wTravelSound;
    unsigned short wHitSound;
    unsigned short wExplosionMissile;
    short wSubMissile[3];
    short wCltSubMissile[3];
    short wHitSubMissile[4];
    short wCltHitSubMissile[4];
    short wProgSound;
    unsigned short wProgOverlay;
    int dwParam[5];
    int dwHitPar[3];
    int dwCltParam[5];
    int dwCltHitPar[3];
    char unk0x78[0xBD];
    unsigned char nInitSteps;
    char unk0x136[0x6E];
};

struct D2CltRateStrc
{
    int nThreshold;
    int nRate;
    int nValue;
};

struct D2StatesTxt
{
    unsigned short wState;
    short wOverlay[4];
    char unk0x0A[0x2E];
    short wSkill;
    short wMissile;
};

struct D2SkillsTxt
{
    char unk0x00[0xEA];
    short wCltMissileA;
    short wCltMissileB;
    char unk0xEE[0x26];
    int dwCltCalc[3];
    char unk0x120[0x11C];
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2ItemsTxt
{
    char unk0x00[0x116];
    unsigned char nArmorComp[6];
};

struct D2DataTablesStrc
{
    char unk0x00[0xBC];
    D2StatesTxt* pStatesTxt;
    char f_C0[0x04];
    int nStatesTxtRecordCount;
    char unk0xC8[0xA9C];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const D2CltRateStrc gaCltRates_006DB848[6];                                                          // 0x006DB848
extern const int gaQuadOffsetY_006DB7D0[4];                                                                 // 0x006DB7D0
extern const int gaQuadOffsetX_006DB7E0[4];                                                                 // 0x006DB7E0
extern const int gaRingOffsetY_006DB5D0[64];                                                                // 0x006DB5D0
extern const int gaRingOffsetX_006DB6D0[64];                                                                // 0x006DB6D0

int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
void __fastcall sub_00476A80_StartTiming(int nArg1, int nArg2, int nArg3, int nArg4);                        // 0x00476A80
void __fastcall sub_004CC870_SubMissileCallback(D2UnitStrc* pMissile);                                     // 0x004CC870
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
void __fastcall sub_004CEF50_SpawnBurst(D2UnitStrc* pMissile, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult); // 0x004CEF50
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
void __fastcall sub_004D3630_CltDoCommon2(D2UnitStrc* pMissile);                                            // 0x004D3630
void __fastcall sub_004D37F0_CltDoCommon3(D2UnitStrc* pMissile);                                            // 0x004D37F0
void __fastcall sub_004D3070_CltDoOwnerStep(D2UnitStrc* pMissile);                                          // 0x004D3070
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile);                                       // 0x0064A380
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile);                                                     // 0x0064A780
void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue);                                     // 0x0046F0C0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem);                                                     // 0x0062A4E0
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
int __fastcall sub_0046D9F0_TestUnit(D2UnitStrc* pUnit);                                                    // 0x0046D9F0
void* __fastcall sub_004DC0B0_GetUnitMemoryPool(D2UnitStrc* pUnit);                                        // 0x004DC0B0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
unsigned int __stdcall ITEMS_GetAltGfx(D2UnitStrc* pItem);                                                // 0x006285F0
int __stdcall sub_0062C100(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned char* pShift, int nArg);  // 0x0062C100
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nState);                                             // 0x0063A7B0
D2UnitStrc* __stdcall sub_0063C050_GetBodyLocItem(D2InventoryStrc* pInventory, int nBodyLoc);               // 0x0063C050
int __stdcall sub_0064F420_HasBodyLocFallback(int nBodyLoc);                                               // 0x0064F420
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill);                                                        // 0x006444D0
int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill);                                                        // 0x00644500
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue);                                           // 0x006445E0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall sub_00624390_AnimInit(D2UnitStrc* pUnit);                                                   // 0x00624390
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
int __stdcall D2Common_10231(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650C20
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
int __stdcall sub_004DA320_GetMotionParam0(D2UnitStrc* pUnit);                                              // 0x004DA320
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);            // 0x004DA1D0
void __stdcall sub_00621780_SetMissileArg(D2UnitStrc* pMissile, int nArg);                                  // 0x00621780
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                        // 0x006487F0
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pPath, unsigned char nDirection);                       // 0x006488A0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                         // 0x0064A3B0
int __stdcall sub_0064A3E0_GetMissileClassId(D2UnitStrc* pMissile);                                       // 0x0064A3E0
int __stdcall sub_0064A510_GetSubMissile(D2UnitStrc* pMissile);                                            // 0x0064A510
int __stdcall sub_0064A570_GetSubMissileCount(D2UnitStrc* pMissile);                                       // 0x0064A570
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath);                                        // 0x006505C0
int __stdcall sub_004DA150_GetMotionAZ(D2UnitStrc* pUnit);                                                  // 0x004DA150
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit);                                                       // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit);                                                       // 0x00620410
void __stdcall PATH_SetPrecisionX(D2DynamicPathStrc* pDynamicPath, int nPrecisionX);                        // 0x006489A0
void __stdcall PATH_SetPrecisionY(D2DynamicPathStrc* pDynamicPath, int nPrecisionY);                        // 0x006489B0
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId < sgptDataTables->nSkillsTxtRecordCount && nSkillId >= 0)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline int STATES_IsUnitShapeShiftedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

inline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordStd(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

// 0x004D1040
int __fastcall sub_004D1040_CltHitSubMissiles3(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
        sub_004CD540_CreateMissile(&missileParams);
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[1];
        sub_004CD540_CreateMissile(&missileParams);
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[2] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[2];
        sub_004CD540_CreateMissile(&missileParams);
    }

    return 1;
}

// 0x004D1110
int __fastcall sub_004D1110_CltHitSubMissileDir(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;

    D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&missileParams);
    if (pSubMissile)
    {
        PATH_SetDirection(pSubMissile->pDynamicPath, PATH_GetDirection(pMissile->pDynamicPath));
    }

    return 1;
}

// 0x004D1240
int __fastcall sub_004D1240_CltHitSubMissiles2Motion(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
        sub_004CD540_CreateMissile(&missileParams);
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[1];
        D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&missileParams);
        if (pSubMissile)
        {
            sub_004DA1D0_SetMotionVectorA(pSubMissile, 0, 0, pMissilesTxtRecord->dwCltHitPar[0]);
        }
    }

    return 1;
}

// 0x004D14A0
int __fastcall sub_004D14A0_CltHitFollowUp(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    if (pHitUnit)
    {
        return 0;
    }

    int nFollowUp = -1;
    switch (sub_0064A3E0_GetMissileClassId(pMissile))
    {
    case 0x110:
        nFollowUp = 0x158;
        break;

    case 0x111:
    case 0x112:
    case 0x1A1:
        nFollowUp = 0x159;
        break;
    }

    D2UnitStrc* pNewMissile = sub_004CDB40_SubmitRequest(sub_004639D0_GetOwnerUnit(pMissile), nFollowUp, UNITS_GetUnitXPosition(pMissile), UNITS_GetUnitYPosition(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if (pNewMissile)
    {
        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        D2DynamicPathStrc* pNewPath = pNewMissile->pDynamicPath;
        PATH_SetDirection(pNewPath, PATH_GetDirection(pPath));
        sub_00621780_SetMissileArg(pNewMissile, 0x80);
    }

    return 1;
}

// 0x004D38D0
void __fastcall sub_004D38D0_CltDoTimedSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    if (pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    if (sub_0064A3B0_GetElapsedFrames(pMissile) >= pMissilesTxtRecord->nInitSteps && sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1;
        missileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        missileParams.nX = UNITS_GetXPosition(pMissile);
        missileParams.nY = CLIENTS_GetUnitY(pMissile);
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        int nLoops = pMissilesTxtRecord->dwCltParam[0];
        missileParams.nLoops = nLoops < 1 ? 1 : nLoops;
        missileParams.pfCallback = sub_004CC870_SubMissileCallback;
        missileParams.pInitArgs = pMissile;
        sub_004CD540_CreateMissile(&missileParams);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D3D30
void __fastcall sub_004D3D30_CltDoTiming(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->dwCltParam[0] <= 0 || pMissilesTxtRecord->dwCltParam[1] <= 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    if (!sub_0064A3B0_GetElapsedFrames(pMissile))
    {
        int nFrames = pMissilesTxtRecord->dwCltParam[1];
        int nThird = nFrames / 3;
        int nOuter = nThird * 25000 / 25;
        int nInner = (nFrames - 2 * nThird) * 25000 / 25;
        sub_00476A80_StartTiming(pMissilesTxtRecord->dwCltParam[0], nOuter, nInner, nOuter);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D4040
void __fastcall sub_004D4040_CltDoHoming(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pMissile);
    if (!pTarget)
    {
        pTarget = sub_004648F0_GetTargetUnit(pOwner);
        if (!pTarget)
        {
            sub_004D30C0_CltDoCommon(pMissile);
            return;
        }
    }

    int nRate = pMissilesTxtRecord->dwCltParam[2];
    if (nRate <= 0)
    {
        nRate = 5;
    }

    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nRate == 0 && sub_006416D0_UnitEdgeDistance(pMissile, pTarget) <= pMissilesTxtRecord->dwCltParam[3])
    {
        int nX = UNITS_GetXPosition(pMissile);
        int nY = CLIENTS_GetUnitY(pMissile);
        int nTargetX = UNITS_GetXPosition(pTarget);
        int nTargetY = CLIENTS_GetUnitY(pTarget);
        int nStep = pMissilesTxtRecord->dwCltParam[4];
        if (nStep < 1)
        {
            nStep = 1;
        }

        int nOffsetX = 0;
        int nOffsetY = 0;
        if (nTargetX > nX)
        {
            nOffsetX = nStep;
        }
        else if (nTargetX < nX)
        {
            nOffsetX = -nStep;
        }

        if (nTargetY > nY)
        {
            nOffsetY = nStep;
        }
        else if (nTargetY < nY)
        {
            nOffsetY = -nStep;
        }

        D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, UNITS_GetXPosition(pMissile) + nOffsetX, CLIENTS_GetUnitY(pMissile) + nOffsetY);
        D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D44B0
void __fastcall sub_004D44B0_CltDoBurst(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    int nSubMissile = sub_0064A510_GetSubMissile(pMissile);
    if (!nSubMissile)
    {
        nSubMissile = pMissilesTxtRecord->wCltSubMissile[0];
    }

    if (nSubMissile < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    int nCount = sub_0064A570_GetSubMissileCount(pMissile);
    if (nCount <= 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    if (sub_0064A3B0_GetElapsedFrames(pMissile) < pMissilesTxtRecord->dwCltParam[0] && sub_0064A3B0_GetElapsedFrames(pMissile) % 3 == 0)
    {
        int nPerStep = nCount > 4 ? nCount / 2 : nCount;
        int nMult = nCount > 4 ? 2 : 1;
        sub_004CEF50_SpawnBurst(pMissile, nCount, nSubMissile, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), nPerStep, nMult);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D4590
void __fastcall sub_004D4590_CltDoCopySubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0 && sub_0064A3B0_GetElapsedFrames(pMissile) >= pMissilesTxtRecord->nInitSteps && sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        int nX = UNITS_GetXPosition(pMissile);
        int nY = CLIENTS_GetUnitY(pMissile);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1;
        missileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        missileParams.nX = nX;
        missileParams.nY = nY;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        missileParams.nLoops = pMissilesTxtRecord->dwCltParam[0];

        D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&missileParams);
        if (pSubMissile)
        {
            PATH_SetDirection(pSubMissile->pDynamicPath, PATH_GetDirection(pMissile->pDynamicPath));
            PATH_SetPrecisionX(pSubMissile->pDynamicPath, UNITS_GetPrecisionX(pMissile));
            PATH_SetPrecisionY(pSubMissile->pDynamicPath, UNITS_GetPrecisionY(pMissile));
            sub_004DA1D0_SetMotionVectorA(pSubMissile, 0, 0, sub_004DA150_GetMotionAZ(pMissile));
        }

        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D46D0
void __fastcall sub_004D46D0_CltDoRing(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    int nRate = pMissilesTxtRecord->dwCltParam[0] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[0];
    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nRate <= 0)
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 2;
        missileParams.pOwner = pOwner;
        missileParams.pOrigin = pMissile;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];

        int nIndex = MISSILE_GetTargetX(pMissile) % 64;
        if (nIndex < 0)
        {
            nIndex = -nIndex;
        }

        missileParams.nTargetX = gaRingOffsetX_006DB6D0[nIndex];
        missileParams.nTargetY = gaRingOffsetY_006DB5D0[nIndex];
        MISSILE_SetTargetX(pMissile, (pMissilesTxtRecord->dwCltParam[1] + nIndex) % 64);
        sub_004CD540_CreateMissile(&missileParams);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D5200
void __fastcall sub_004D5200_CltDoOwnerQuad(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (pOwner && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwCltParam[0])
    {
        int nX = UNITS_GetXPosition(pOwner);
        int nY = CLIENTS_GetUnitY(pOwner);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 0x2001;
        missileParams.pOwner = pOwner;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];

        for (int i = 0; i < 4; ++i)
        {
            missileParams.nX = gaQuadOffsetX_006DB7E0[i] + nX;
            missileParams.nY = gaQuadOffsetY_006DB7D0[i] + nY;
            sub_004CD540_CreateMissile(&missileParams);
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D5880
void __fastcall sub_004D5880_CltDoPathSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || !pMissilesTxtRecord->wCltSubMissile[0])
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 9;
        missileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        missileParams.nX = UNITS_GetXPosition(pMissile);
        missileParams.nY = CLIENTS_GetUnitY(pMissile);
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        missileParams.nLoops = pMissilesTxtRecord->dwCltParam[0];
        sub_004CD540_CreateMissile(&missileParams);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D5950
void __fastcall sub_004D5950_CltDoProgSound(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    if (pMissilesTxtRecord->wProgSound > 0)
    {
        int nOldValue = MISSILE_GetTargetX(pMissile);
        int nNewValue = sub_004DA320_GetMotionParam0(pMissile);
        if (nOldValue && nOldValue != nNewValue)
        {
            sub_004B9A00(pMissilesTxtRecord->wProgSound, pMissile, 0, 0, 0);
        }

        MISSILE_SetTargetX(pMissile, nNewValue);
    }

    sub_004D3630_CltDoCommon2(pMissile);
}

// 0x004D5F80
void __fastcall sub_004D5F80_CltDoMirrorPair(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        int nTargetX = MISSILE_GetTargetX(pMissile);
        int nTargetY = MISSILE_GetTargetY(pMissile);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 2;
        missileParams.pOwner = pOwner;
        missileParams.pOrigin = pMissile;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        missileParams.nTargetX = nTargetX;
        missileParams.nTargetY = nTargetY;
        sub_004CD540_CreateMissile(&missileParams);
        missileParams.nTargetX = -nTargetX;
        missileParams.nTargetY = -nTargetY;
        sub_004CD540_CreateMissile(&missileParams);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D6080
void __fastcall sub_004D6080_CltDoOwnerSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        missileParams.pOrigin = pMissile;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        sub_004CD540_CreateMissile(&missileParams);
    }

    sub_004D37F0_CltDoCommon3(pMissile);
}

// 0x004D62B0
void __fastcall sub_004D62B0_CltDoOwnerTarget(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    sub_004D3070_CltDoOwnerStep(pMissile);

    int nX;
    int nY;
    if (sub_004C52E0_GetTargetPosition(pOwner, &nX, &nY))
    {
        int nCount = MISSILE_GetTargetY(pMissile);
        if (nCount < MISSILE_GetTargetX(pMissile))
        {
            MISSILE_SetTargetY(pMissile, nCount + 1);
        }

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 0x20;
        missileParams.pOwner = pOwner;
        missileParams.pOrigin = pOwner;
        missileParams.nTargetX = nX;
        missileParams.nTargetY = nY;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];

        D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&missileParams);
        if (pSubMissile)
        {
            PATH_SetType(pSubMissile->pDynamicPath, 0xE);
            D2Common_10142(pSubMissile->pDynamicPath, pSubMissile, 0);
        }

        MISSILE_SetTargetY(pMissile, 0);
        sub_004D30C0_CltDoCommon(pMissile);
    }
}

// 0x004D6C00
void __fastcall sub_004D6C00_CltDoRateTable(D2UnitStrc* pMissile)
{
    int nRemaining = sub_0064A380_GetRemainingFrames(pMissile);
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);

    int i = 0;
    for (i = 0; i < 5; ++i)
    {
        if (nRemaining > gaCltRates_006DB848[i].nThreshold)
        {
            break;
        }
    }

    if (nRemaining % gaCltRates_006DB848[i].nRate == 0)
    {
        int nY = UNITS_GetUnitYPosition(pMissile);
        int nX = UNITS_GetUnitXPosition(pMissile);
        int nLevel = MISSILE_GetLevel(pMissile);
        int nSkill = MISSILE_GetSkill(pMissile);
        if (pOwner)
        {
            D2MissileStrc missileParams;
            memset(&missileParams, 0, sizeof(missileParams));
            missileParams.dwFlags = 1;
            missileParams.pOwner = pOwner;
            missileParams.nX = nX;
            missileParams.nY = nY;
            missileParams.nSkill = nSkill;
            missileParams.nSkillLevel = nLevel;
            missileParams.nMissile = 0x15C;

            D2UnitStrc* pNewMissile = sub_004CD540_CreateMissile(&missileParams);
            if (pNewMissile)
            {
                MISSILE_SetTargetX(pNewMissile, gaCltRates_006DB848[i].nValue);
                MISSILE_SetTargetY(pNewMissile, nRemaining);
            }
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D9180
void __fastcall sub_004D9180_StateStartMissile(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord || pStatesTxtRecord->wSkill < 0)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(pStatesTxtRecord->wSkill);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->wCltMissileA < 0 || pSkillsTxtRecord->wCltMissileA >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nMissile = pSkillsTxtRecord->wCltMissileA;
    missileParams.nSkill = pStatesTxtRecord->wSkill;
    missileParams.nSkillLevel = 1;
    sub_004CD540_CreateMissile(&missileParams);

    if (pUnit)
    {
        pUnit->dwFlagEx |= 0x40000;
        pUnit->dwFlags |= 0x20;
    }
}

// 0x004D9630
void __fastcall sub_004D9630_StateOverlayRanges(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord)
    {
        return;
    }

    int nEnd = pStatesTxtRecord->wOverlay[1];
    int nStart = pStatesTxtRecord->wOverlay[0];
    if (nStart >= 0)
    {
        for (int i = nStart; i <= nEnd; ++i)
        {
            sub_0046F0C0(pUnit, 0, i);
        }
    }

    nStart = pStatesTxtRecord->wOverlay[2];
    nEnd = pStatesTxtRecord->wOverlay[3];
    if (nStart >= 0)
    {
        for (int i = nStart; i <= nEnd; ++i)
        {
            sub_0046F0C0(pUnit, 0, i);
        }
    }
}

// 0x004D96B0
void __fastcall sub_004D96B0_StateMissile(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord || pStatesTxtRecord->wMissile < 0 || pStatesTxtRecord->wMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nMissile = pStatesTxtRecord->wMissile;
    missileParams.nSkill = pStatesTxtRecord->wSkill >= 0 ? pStatesTxtRecord->wSkill : 0;
    missileParams.nSkillLevel = 1;
    sub_004CD540_CreateMissile(&missileParams);
}

// 0x004DAAB0
void __fastcall sub_004DAAB0_GetArmorComponents(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int bSkip, unsigned char* pComponents)
{
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 3);
    if (!bSkip && sub_0062A4E0_TestItem(pItem))
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(UNITS_GetClassIdInline(pItem));
        if (!pItemsTxtRecord)
        {
            return;
        }

        pComponents[0] = pItemsTxtRecord->nArmorComp[0];
        pComponents[1] = pItemsTxtRecord->nArmorComp[1];
        pComponents[2] = pItemsTxtRecord->nArmorComp[2];
        pComponents[3] = pItemsTxtRecord->nArmorComp[3];
        pComponents[4] = pItemsTxtRecord->nArmorComp[4];
        pComponents[5] = pItemsTxtRecord->nArmorComp[5];
        return;
    }

    memset(pComponents, 0, 6);
}

// 0x004DB570
int __fastcall sub_004DB570_GetBodyLocItemShift(D2UnitStrc* pUnit, int nBodyLoc, int nDefault)
{
    if (nBodyLoc >= 16)
    {
        return nDefault;
    }

    if (pUnit && !sub_0046D9F0_TestUnit(pUnit))
    {
        D2InventoryStrc* pInventory;
        D2UnitStrc* pOwner;
        if (STATES_IsUnitShapeShiftedInline(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
        {
            pInventory = pOwner->pInventory;
        }
        else
        {
            pInventory = pUnit->pInventory;
        }

        if (pInventory)
        {
            D2UnitStrc* pItem = sub_0063C050_GetBodyLocItem(pInventory, nBodyLoc);
            if (!pItem && nBodyLoc != 1 && sub_0064F420_HasBodyLocFallback(nBodyLoc))
            {
                pItem = sub_0063C050_GetBodyLocItem(pInventory, 1);
            }

            if (pItem && !ITEMS_CheckItemFlag(pItem, 0x100, 0x656, ".\\ENGINE\\GfxUtil.cpp") && !ITEMS_CheckItemFlag(pItem, 0x4000, 0x657, ".\\ENGINE\\GfxUtil.cpp"))
            {
                if (ITEMS_GetAltGfx(pItem) == 0x2074696C)
                {
                    return 0;
                }

                unsigned char nShift;
                const int nResult = sub_0062C100(pUnit, pItem, &nShift, 0);
                if (nResult)
                {
                    return nResult;
                }
            }
        }
    }

    return nDefault;
}

// 0x004DC190
void __fastcall sub_004DC190_RemoveCltUnitEvents(D2UnitStrc* pUnit, int nParam4, int nParam5)
{
    if (!pUnit)
    {
        return;
    }

    D2CltUnitEventStrc* pEvent = pUnit->pCltTimerList;
    while (pEvent)
    {
        D2CltUnitEventStrc* pNext = pEvent->pNext;
        if (pEvent->f_4 == nParam4 && pEvent->f_8 == nParam5)
        {
            if (pEvent->pPrevious)
            {
                pEvent->pPrevious->pNext = pEvent->pNext;
            }
            else
            {
                pUnit->pCltTimerList = pEvent->pNext;
            }

            if (pEvent->pNext)
            {
                pEvent->pNext->pPrevious = pEvent->pPrevious;
            }

            FOG_FreeServerMemory(sub_004DC0B0_GetUnitMemoryPool(pUnit), pEvent, ".\\UNIT\\CUnitEvent.cpp", 0x80, 0);
        }

        pEvent = pNext;
    }
}

// 0x004E1090
int __fastcall sub_004E1090_SkillDoClearTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nX = SKILLS_GetParam2(pSkill);
    int nY = SKILLS_GetParam3(pSkill);
    if (!nX || !nY)
    {
        return 0;
    }

    SKILLS_SetParam2(pSkill, 0);
    SKILLS_SetParam3(pSkill, 0);
    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    COLLISION_ResetMaskWithPattern(pRoom, nX, nY, 1, 0x100);
    return 1;
}

// 0x004E18F0
int __fastcall sub_004E18F0_SkillStartCltCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel));
    return 1;
}

// 0x004E0A40
int __fastcall sub_004E0A40_SkillStartPlace(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    sub_00624390_AnimInit(pUnit);
    if (pUnit)
    {
        pUnit->dwFlags |= 0xE;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile > 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
    {
        if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) == 1 && pSkillsTxtRecord->wCltMissileB > 0 && pSkillsTxtRecord->wCltMissileB < sgptDataTables->nMissilesTxtRecordCount)
        {
            nMissile = pSkillsTxtRecord->wCltMissileB;
        }

        sub_004CDBA0_SubmitOwnerRequest(pUnit, nMissile, UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit), nSkillId, nSkillLevel);
    }

    D2CoordStrc tCoord;
    tCoord.nX = UNITS_GetUnitXPosition(pUnit);
    tCoord.nY = UNITS_GetUnitYPosition(pUnit);
    D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &tCoord, UNITS_GetUnitSizeX(pUnit), 0x1C09, 1);
    if (!pRoom)
    {
        return 0;
    }

    if (!pUnit->pDynamicPath)
    {
        return 0;
    }

    if (!D2Common_10231(pUnit->pDynamicPath, pUnit, pRoom, tCoord.nX, tCoord.nY))
    {
        return 0;
    }

    COLLISION_SetMaskWithPattern(UNITS_GetRoom(pUnit), UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit), 1, 0x1000);
    return 1;
}

#include "gen/data/Source/D2Client/004D1040_sub_004D1040_CltHitSubMissiles3.inc"
