struct D2DynamicPathStrc;
struct D2StaticPathStrc;
struct D2ActiveRoomStrc;
struct D2SkillStrc;
struct D2InventoryStrc;
struct D2StatListStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    void* f_14;
    char unk0x18[0x14];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x02];
    unsigned char nFlags[8];
    char unk0x00C[0x58];
    int dwAuraRangeCalc;
    char unk0x068[0x82];
    short wCltMissileA;
    short wCltMissileB;
    short wCltMissileC;
    short wCltMissileD;
    char unk0x0F2[0x1A];
    short wPrgOverlay;
    short wPrgSound;
    char unk0x110[0x04];
    int dwCltCalc[3];
    char unk0x120[0x18];
    int dwCalc[4];
    char unk0x148[0xF4];
};

struct D2MissilesTxt
{
    char unk0x000[0x1A4];
};

struct D2StatesTxt
{
    unsigned short wState;
    short wOverlay[4];
    char unk0x0A[0x2E];
    short wSkill;
    short wMissile;
};

struct D2MonStats2Txt
{
    char unk0x00[0x0C];
    unsigned char nOverlayHeight;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC];
    D2StatesTxt* pStatesTxt;
    char unk0x0C0[0x04];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xA9C];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

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
    int unk0x38;
    int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int nInitArg;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnBitMasks_006CE268[8];                                                                          // 0x006CE268
extern const unsigned char gnFrameDirections_006DBA08[8][9];                                                // 0x006DBA08
extern const unsigned char gnBaseDirections_006DBA50[8];                                                    // 0x006DBA50

int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                      // 0x004648F0
int __fastcall sub_0046E100(D2UnitStrc* pUnit, int nOverlay);                                               // 0x0046E100
void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue);                                     // 0x0046F0C0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall sub_00472C50(int nArg);                                                                     // 0x00472C50
int __fastcall sub_004B11F0(D2UnitStrc* pUnit);                                                             // 0x004B11F0
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* pUnit, int* pFrameNo, int* pFrameCount);           // 0x00621810
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY);                          // 0x00621DC0
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker);                                                   // 0x00622560
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                          // 0x00625820
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit);                         // 0x006277F0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                  // 0x00627910
int __stdcall STATES_CheckStateMaskAttBlueOnUnit(D2UnitStrc* pUnit);                                        // 0x0063A3C0
int __stdcall STATES_CheckStateMaskAttRedOnUnit(D2UnitStrc* pUnit);                                         // 0x0063A3E0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex);                               // 0x0063E7A0
void __stdcall sub_0063E7E0_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY);                  // 0x0063E7E0
int __stdcall sub_0063EA70_GetMonsterId(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int* pMode, int* pX, int* pY); // 0x0063EA70
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill);                                                        // 0x006444A0
int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill);                                                        // 0x006444D0
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue);                                           // 0x006445E0
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);                      // 0x006449F0
int __stdcall D2COMMON_11017_CheckUnitIfConsumeable(D2UnitStrc* pUnit, int a2);                             // 0x00645510
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4);                            // 0x00649EF0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
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

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

// 0x004D9480
void __fastcall sub_004D9480_StateOverlaySpread(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    int nSelect = STATLIST_GetStatValue(pStatList, 0xA9, 0);
    int nSkillId = STATLIST_GetStatValue(pStatList, 0x15E, 0);
    int nSkillLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return;
    }

    int nEnd = pStatesTxtRecord->wOverlay[1];
    int nStart = pStatesTxtRecord->wOverlay[0];
    nCount = D2_MIN(nCount, nEnd - nStart + 1);
    nSelect = D2_MIN(nSelect, nEnd - nStart + 1);
    if (nStart >= 0 && nEnd >= nStart)
    {
        int nIndex = (nSelect - 1) * (nEnd - nStart + 1) / nCount;
        for (int i = 0; i < nEnd - nStart + 1; ++i)
        {
            if (i != nIndex)
            {
                sub_0046F0C0(pUnit, 0, nStart + i);
            }
            else if (!sub_0046E100(pUnit, nStart + i))
            {
                sub_00470390(pUnit, nStart + i, 3, 0, 0, 0, 0, 0);
            }
        }
    }

    nStart = pStatesTxtRecord->wOverlay[2];
    nEnd = pStatesTxtRecord->wOverlay[3];
    if (nStart >= 0 && nEnd >= nStart)
    {
        int nRange = nEnd - nStart + 1;
        int nIndex = (nSelect - 1) * nRange / nCount;
        for (int i = 0; i < nRange; ++i, ++nStart)
        {
            if (i != nIndex)
            {
                sub_0046F0C0(pUnit, 0, nStart);
            }
            else if (!sub_0046E100(pUnit, nStart))
            {
                sub_00470390(pUnit, nStart, 3, 0, 0, 0, 0, 0);
            }
        }
    }
}

// 0x004E0D40
int __fastcall sub_004E0D40_SkillDoFrameOffset(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nX = SKILLS_GetParam1(pSkill);
    int nY = SKILLS_GetParam2(pSkill);
    if ((!nX || !nY) && !sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    unsigned char nDirection = (unsigned char)UNITS_GetDirectionToCoords(pUnit, nX, nY);
    unsigned char nIndex = sub_0063E7A0_GetByteTableEntry(nDirection) & 7;
    nX = UNITS_GetXPosition(pUnit);
    nY = CLIENTS_GetUnitY(pUnit);

    int nOffsetX;
    int nOffsetY;
    sub_0063E7E0_GetDirectionDelta(gnBaseDirections_006DBA50[nIndex], &nOffsetX, &nOffsetY);
    nX += nOffsetX;
    nY += nOffsetY;

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    nFrame -= 4;
    int nClamp = nFrame > 0 ? nFrame : 0;
    nFrame = nClamp < 8 ? nClamp : 8;

    unsigned char nDir = gnFrameDirections_006DBA08[nIndex][nFrame];
    if (nDir != 99)
    {
        sub_0063E7E0_GetDirectionDelta(nDir, &nOffsetX, &nOffsetY);
        nX += nOffsetX;
        nY += nOffsetY;
    }

    sub_004CDBA0_SubmitOwnerRequest(pUnit, nMissile, nX, nY, nSkillId, nSkillLevel);
    return 1;
}

// 0x004E0FD0
int __fastcall sub_004E0FD0_SkillStartMarkTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nMode;
    int nY;
    int nX;
    if (sub_0063EA70_GetMonsterId(pUnit, 1, nSkillId, nSkillLevel, &nMode, &nX, &nY) < 0)
    {
        return 0;
    }

    SKILLS_SetParam2(pSkill, nX);
    SKILLS_SetParam3(pSkill, nY);
    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
    COLLISION_SetMaskWithPattern(pRoom, nX, nY, 1, 0x100);
    return 1;
}

// 0x004E1B10
int __fastcall sub_004E1B10_FireAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissile];
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = nMissile;
    tMissileParams.dwFlags = 3;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nX = UNITS_GetXPosition(pUnit);
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nLoops = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (pTarget)
    {
        D2Common_10216(pUnit->pDynamicPath, UNITS_GetXPosition(pTarget), CLIENTS_GetUnitY(pTarget), 0);
        tMissileParams.nTargetX = UNITS_GetXPosition(pTarget) - UNITS_GetXPosition(pUnit);
        tMissileParams.nTargetY = CLIENTS_GetUnitY(pTarget) - CLIENTS_GetUnitY(pUnit);
    }
    else
    {
        tMissileParams.nTargetX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath) - UNITS_GetXPosition(pUnit);
        tMissileParams.nTargetY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath) - CLIENTS_GetUnitY(pUnit);
    }

    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, nSkillLevel);
    }

    return pMissilesTxtRecord ? 1 : 0;
}

// 0x004E3C50
int __fastcall sub_004E3C50_MissileAtTargetUnit(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (pTarget && pUnit)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.pOwner = pUnit;
        tMissileParams.dwFlags = 1;
        tMissileParams.nX = UNITS_GetXPosition(pTarget);
        tMissileParams.nY = CLIENTS_GetUnitY(pTarget);
        tMissileParams.nSkill = nSkillId;
        tMissileParams.nSkillLevel = nSkillLevel;
        tMissileParams.nMissile = nMissile;
        D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pMissile)
        {
            sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, 0x118);
            sub_004DA200_SetMotionVectorB(pMissile, 0, 0, -0x28, 1);
        }

        sub_00472C50(0);
        const short nOverlay = pSkillsTxtRecord->wPrgOverlay;
        if (nOverlay > 0)
        {
            sub_00470390(pTarget, nOverlay, 2, 0, 0, 0, 0, 0);
        }

        return 1;
    }

    return 0;
}

// 0x004E9040
void __fastcall sub_004E9040_AttackRating(D2UnitStrc* pUnit, void* pArg, D2SkillsTxt* pSkillsTxtRecord, int nSkillLevel, int* pValue, int* pColor, int nArg5, int nArg6)
{
    D2UnitStrc* pWeapon = 0;
    if (pUnit->pInventory)
    {
        pWeapon = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    *pValue = 0;
    *pColor = 0;
    if (!pArg)
    {
        return;
    }

    if (pWeapon)
    {
        int bStatNotDynamic = 0;
        D2UnitStrc* pOwner = STATLIST_GetOwner(pWeapon, &bStatNotDynamic);
        STATLIST_MergeStatLists(pUnit, pWeapon, 0);
        *pValue = UNITS_GetAttackRate(pUnit);
        if (pOwner)
        {
            STATLIST_MergeStatLists(pUnit, pWeapon, bStatNotDynamic);
        }
        else
        {
            STATLIST_ExpireUnitStatlist(pUnit, pWeapon);
        }
    }
    else
    {
        *pValue = UNITS_GetAttackRate(pUnit);
    }

    int nToHit = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0x77, 0);
    nToHit += SKILLS_GetToHitFactor(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->nFlags[0] & gnBitMasks_006CE268[3])
    {
        const int nBonus = STATLIST_UnitGetStatValue(pUnit, 0x145, 0);
        if (nBonus)
        {
            nToHit += nBonus;
            *pColor = 3;
        }
    }

    *pValue += *pValue * nToHit / 100;
    if (STATES_CheckStateMaskAttBlueOnUnit(pUnit))
    {
        *pColor = 3;
    }

    if (STATES_CheckStateMaskAttRedOnUnit(pUnit))
    {
        *pColor = 1;
    }
}

// 0x004F1D80
int __fastcall sub_004F1D80_MotionMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel) <= 0)
    {
        return 0;
    }

    const int nA = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
    if (nA <= 0)
    {
        return 0;
    }

    const int nB = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkillId, nSkillLevel);
    if (nB <= 0)
    {
        return 0;
    }

    const int nC = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[2], nSkillId, nSkillLevel);
    if (nC <= 0)
    {
        return 0;
    }

    const int nZ = nB * nA;
    const int nX = nC * nA;
    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.pOwner = pUnit;
    tMissileParams.dwFlags = 1;
    tMissileParams.nX = nTargetX;
    tMissileParams.nY = nTargetY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;

    const short nMissileA = pSkillsTxtRecord->wCltMissileA;
    if (nMissileA >= 0)
    {
        tMissileParams.nMissile = nMissileA;
        D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pMissile)
        {
            sub_004DA1D0_SetMotionVectorA(pMissile, nX, 0, nZ);
            sub_004DA200_SetMotionVectorB(pMissile, -nC, 0, -nB, 1);
        }
    }

    const short nMissileB = pSkillsTxtRecord->wCltMissileB;
    if (nMissileB >= 0)
    {
        tMissileParams.nMissile = nMissileB;
        D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pMissile)
        {
            sub_004DA1D0_SetMotionVectorA(pMissile, nX, 0, nZ);
            sub_004DA200_SetMotionVectorB(pMissile, -nC, 0, -nB, 1);
        }
    }

    return 1;
}

// 0x004F4000
int __fastcall sub_004F4000_MissileByOverlay(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : 6;
    if (nType != 1)
    {
        return 0;
    }

    if (!sub_004638A0_CheckMonStats2Flag(pTarget->dwClassId, 8))
    {
        return 0;
    }

    if (!D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
    {
        return 0;
    }

    if (!sub_004B11F0(pTarget))
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    switch (pMonStats2TxtRecord->nOverlayHeight)
    {
    case 1:
        nMissile = pSkillsTxtRecord->wCltMissileB;
        break;

    case 3:
        nMissile = pSkillsTxtRecord->wCltMissileC;
        break;
    }

    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x2000;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pTarget;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    return sub_004CD540_CreateMissile(&tMissileParams) != 0;
}

#include "gen/data/Source/D2Client/004D9480_sub_004D9480_StateOverlaySpread.inc"
