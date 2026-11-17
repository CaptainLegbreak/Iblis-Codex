struct D2DynamicPathStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc tSeed;
    char unk0x28[0x04];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2SkillsTxt
{
    char unk0x000[0xEA];
    short wCltMissileA;
    short wCltMissileB;
    char unk0x0EE[0x26];
    int dwCltCalc[3];
    char unk0x120[0x11C];
};

struct D2MissilesTxt
{
    char unk0x00[0x3C];
    int nParam3C;
    char unk0x40[0x5A];
    unsigned char nParam9A;
    char unk0x9B[0xDD];
    unsigned char nParam178;
    char unk0x179[0x2B];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
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

void* __cdecl sub_00681EF0_Memset(void* pDst, int nValue, unsigned int nSize);                             // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int gnVelocityBonus_006DBF38[5];                                                               // 0x006DBF38

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit);                                   // 0x004648F0
void __fastcall sub_00465BF0_SetPathTargetToTargetUnit(D2UnitStrc* pUnit, int nArg);                        // 0x00465BF0
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
int __stdcall sub_004DA150_GetMotionAZ(D2UnitStrc* pUnit);                                                  // 0x004DA150
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
void __stdcall sub_004DA350_UpdateMotion(D2UnitStrc* pUnit);                                                // 0x004DA350
void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed);                                      // 0x00621780
void __stdcall UNITS_UpdateDirectionAndSpeed(D2UnitStrc* pUnit, int nX, int nY);                            // 0x00621C00
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
void __stdcall sub_00648E70_SetDistance(D2DynamicPathStrc* pPath, int nDistance);                           // 0x00648E70
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004EFDF0
int __fastcall sub_004EFDF0_LobMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2MissileStrc tMissileParams;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        const int nMissile = pSkillsTxtRecord->wCltMissileA;
        D2MissilesTxt* pMissilesTxtRecord;
        int nMissilesCount;
        if (nMissile >= 0 && nMissile < (nMissilesCount = sgptDataTables->nMissilesTxtRecordCount)
            && (pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissile]) != 0)
        {
            int nAltMissile = pSkillsTxtRecord->wCltMissileB;
            if (nAltMissile < 0 || nAltMissile >= nMissilesCount)
            {
                nAltMissile = -1;
            }

            D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
            if (pTarget)
            {
                D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget));
                sub_00465BF0_SetPathTargetToTargetUnit(pUnit, 1);
            }

            int nTargetX;
            int nTargetY;
            if (sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
            {
                if (!pTarget)
                {
                    UNITS_UpdateDirectionAndSpeed(pUnit, nTargetX, nTargetY);
                }

                sub_00681EF0_Memset(&tMissileParams, 0, sizeof(tMissileParams));
                tMissileParams.dwFlags = 0x25;
                tMissileParams.pOwner = pUnit;
                tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
                tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
                tMissileParams.nSkill = nSkillId;
                tMissileParams.nSkillLevel = nSkillLevel;
                tMissileParams.nTargetX = nTargetX;
                tMissileParams.nTargetY = nTargetY;

                const int nHeight = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel) + sub_004DA150_GetMotionAZ(pUnit);
                const int nFrames = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkillId, nSkillLevel) + pMissilesTxtRecord->nParam3C;
                int nSpeed = pMissilesTxtRecord->nParam178 << 8;
                int nFall = -2 * nHeight;
                if (nFrames)
                {
                    nSpeed /= nFrames;
                    nFall /= nFrames;
                }

                D2SeedStrc* pSeed = &pUnit->tSeed;
                tMissileParams.nMissile = nMissile;
                if (nAltMissile > 0 && SEED_RollLimitedRandomNumber(pSeed, 2))
                {
                    tMissileParams.nMissile = nAltMissile;
                }

                tMissileParams.nVelocity = pMissilesTxtRecord->nParam9A + gnVelocityBonus_006DBF38[SEED_RollRandomNumber(pSeed) % 5];

                D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
                if (pMissile)
                {
                    sub_00648E70_SetDistance(pMissile->pDynamicPath, nFrames);
                    UNITS_SetAnimationSpeed(pMissile, nSpeed);
                    MISSILE_SetTotalFrames(pMissile, nFrames);
                    MISSILE_SetCurrentFrame(pMissile, nFrames);
                    sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, nHeight);
                    sub_004DA350_UpdateMotion(pMissile);
                    sub_004DA200_SetMotionVectorB(pMissile, 0, 0, nFall, 1);
                }

                return 1;
            }
        }
    }

    return 0;
}

#include "gen/data/Source/D2Client/004EFDF0_sub_004EFDF0_LobMissile.inc"
