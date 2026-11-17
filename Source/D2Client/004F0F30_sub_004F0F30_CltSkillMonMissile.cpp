struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
struct D2SkillStrc;

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
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x0C];
    D2SeedStrc pSeed;
    int dwInitSeed;
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
    char unk0x000[0xEA];
    short wCltMissileA;
    short wCltMissileB;
    short wCltMissileC;
    short wCltMissileD;
    char unk0x0F2[0x22];
    int dwCltCalc[3];
    char unk0x120[0x11C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB6C];
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

typedef int (__fastcall* D2UnitFindCallback)(D2UnitStrc* pUnit, void* pArg);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" const char szSkillsEMonCpp_006DBF90[];                                                           // 0x006DBF90
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnFanOffsetX_006DBF50[];                                                                         // 0x006DBF50
extern int gnFanOffsetY_006DBF70[];                                                                         // 0x006DBF70

void __fastcall sub_004E2ED0_VolleyCallback(D2UnitStrc* pMissile, int nArg);                                // 0x004E2ED0
int __fastcall sub_004F0F10_IsTargetObject(D2UnitStrc* pUnit, void* pArg);                                  // 0x004F0F10
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit);                                              // 0x00620100
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pPath, unsigned char nDirection);                       // 0x006488A0
void __stdcall sub_00649030_SetPathFlag40(D2DynamicPathStrc* pPath, int bClear);                            // 0x00649030
void __fastcall sub_00464810(D2UnitStrc* pUnit);                                                            // 0x00464810
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);          // 0x006439F0
D2SkillStrc* __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);              // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill);                                                        // 0x006444A0
int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill);                                                        // 0x006444D0
int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill);                                                        // 0x00644500
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue);                                           // 0x006445E0
int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                                           // 0x006417F0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitFindCallback pCallback, void* pArg, int nSize); // 0x00641CB0
void __fastcall sub_004D2D70_CltMissileHit(D2UnitStrc* pMissile, D2UnitStrc* pTarget, int bArg);            // 0x004D2D70

// build: context SKILLS_GetSkillsTxtRecordInline
static D2SkillsTxt* SKILLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// build: context UNITS_GetXPositionInline
static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 2 || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
    {
        return pUnit->pStaticPath->nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

// build: context UNITS_GetYPositionInline
static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 2 || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
    {
        return pUnit->pStaticPath->nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// build: context MISSILE_SetPathDirectionInline
static void MISSILE_SetPathDirectionInline(D2UnitStrc* pMissile, unsigned char nDirection)
{
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    PATH_SetDirection(pPath, nDirection);
    sub_00649030_SetPathFlag40(pPath, 0);
}

// 0x004F04F0
static int __stdcall sub_004F04F0_CreateMissileFan(int nMissile, int nSkillId, int nSkillLevel, int nCount, D2UnitStrc* pUnit)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.dwFlags = 3;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nMissile = nMissile;
    tMissileParams.pInitFunc = sub_004E2ED0_VolleyCallback;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &tMissileParams.nX, &tMissileParams.nY))
    {
        return 0;
    }

    for (int i = 0; i < nCount; ++i)
    {
        tMissileParams.nTargetX = gnFanOffsetX_006DBF50[i & 7];
        tMissileParams.nTargetY = gnFanOffsetY_006DBF70[i & 7];
        tMissileParams.nInitArg = i;
        sub_004CD540_CreateMissile(&tMissileParams);
    }
    return 1;
}

// 0x004F0590
static int __stdcall sub_004F0590_CreateCltMissileRequest(int nMissile, int nSkillId, int nSkillLevel, int bNotify, D2UnitStrc* pUnit)
{
    D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pUnit, nMissile, UNITS_GetXPositionInline(pUnit), UNITS_GetYPositionInline(pUnit), nSkillId, nSkillLevel);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetPathDirectionInline(pMissile, UNITS_GetDirection(pUnit));
    if (bNotify)
    {
        sub_00464810(pMissile);
    }
    return 1;
}

// build: context sub_004F0650_CltSkillMissileFan
int __fastcall sub_004F0650_CltSkillMissileFan(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordInline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nMissileA = pSkillsTxtRecord->wCltMissileA;
    if (nMissileA >= 0 && nMissileA < sgptDataTables->nMissilesTxtRecordCount)
    {
        sub_004F0590_CreateCltMissileRequest(nMissileA, nSkillId, nSkillLevel, 0, pUnit);
    }

    const int nMissileB = pSkillsTxtRecord->wCltMissileB;
    if (nMissileB >= 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
    {
        const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
        sub_004F04F0_CreateMissileFan(nMissileB, nSkillId, nSkillLevel, nCount, pUnit);
    }
    return 1;
}

// 0x004F0F30
int __fastcall sub_004F0F30_CltSkillMonMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, 0x126);
    if (!pSkill)
    {
        SKILLS_AssignSkill(pUnit, 0x126, 1, 0, szSkillsEMonCpp_006DBF90, 0x35C);
        pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, 0x126);
        if (!pSkill)
        {
            return 0;
        }
    }

    const int nSkill = SKILLS_GetSkillIdFromSkill(pSkill, szSkillsEMonCpp_006DBF90, 0x364);
    nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    struct { int nX; int nY; int nValue; } tLocals;
    tLocals.nValue = SKILLS_GetParam1(pSkill);
    SKILLS_SetParam1(pSkill, tLocals.nValue + 1);
    tLocals.nX = SKILLS_GetParam2(pSkill);
    tLocals.nY = SKILLS_GetParam3(pSkill);
    int bFire = 0;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordInline(nSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (tLocals.nValue >= SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkill, nSkillLevel))
    {
        bFire = 1;
    }

    tLocals.nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkill, nSkillLevel);
    if (UNITS_GetDistanceToCoordinates(pUnit, tLocals.nX, tLocals.nY) >= tLocals.nValue)
    {
        bFire = 1;
    }

    int nMissile;
    switch (pUnit->dwAnimMode)
    {
    case 1:
        if (bFire)
        {
            D2UnitStrc* pTarget = D2Common_10407(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), sub_004F0F10_IsTargetObject, 0, 1);
            if (pTarget)
            {
                sub_004D2D70_CltMissileHit(pTarget, 0, 0);
            }
        }
        nMissile = pSkillsTxtRecord->wCltMissileD;
        break;

    case 2:
    {
        const int nRoll = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2);
        nMissile = pSkillsTxtRecord->wCltMissileC + nRoll;
        break;
    }

    default:
        return 1;
    }

    if (bFire && nMissile > 0)
    {
        SKILLS_SetParam1(pSkill, 0);
        SKILLS_SetParam2(pSkill, CLIENTS_GetUnitX(pUnit));
        SKILLS_SetParam3(pSkill, CLIENTS_GetUnitY(pUnit));
        sub_004F0590_CreateCltMissileRequest(nMissile, nSkill, nSkillLevel, 1, pUnit);
    }
    return 1;
}
