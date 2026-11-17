struct D2DynamicPathStrc;
struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x1C];
    D2DynamicPathStrc* pDynamicPath;
};

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile);

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
    int unk0x38[7];
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

struct D2MissilesTxt
{
    char unk0x000[0x1E];
    short wCltSubMissile[3];
    char unk0x024[0x08];
    short wCltHitSubMissile[4];
    char unk0x034[0x38];
    int dwCltHitPar[3];
    char unk0x078[0x12C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int gaRingOffsetY_006DB140[64];                                                                // 0x006DB140
extern const int gaRingOffsetX_006DB240[64];                                                                // 0x006DB240
extern const int gaRingOffsetY_006DB340[64];                                                                // 0x006DB340
extern const int gaRingOffsetX_006DB440[64];                                                                // 0x006DB440
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                       // 0x004639D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760

extern "C" const char gszMissileSourceFile_006DAEF4[];                                                      // 0x006DAEF4
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath);                                         // 0x006505C0
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
void __stdcall D2Common_10235_PATH_UpdateRiderPath(D2UnitStrc* pRiderUnit, D2UnitStrc* pMountUnit);         // 0x006505E0
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
void __fastcall sub_00465F00_RemoveClientUnit(int nUnitId, int nUnitType);                                  // 0x00465F00

#define UNIT_INVALID 6

inline int UNITS_GetUnitIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

inline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    return !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D04D0
int __fastcall sub_004D04D0_HitRing64(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        if (!pOwner)
        {
            return 1;
        }

        {
            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 2;
            tMissileParams.pOwner = pOwner;
            tMissileParams.pOrigin = pMissile;
            tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
            tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];

            int nStep = pMissilesTxtRecord->dwCltHitPar[0];
            if (nStep < 1)
            {
                nStep = 1;
            }

            for (int i = 0; i < 64; i += nStep)
            {
                tMissileParams.nTargetX = gaRingOffsetX_006DB240[i];
                tMissileParams.nTargetY = gaRingOffsetY_006DB140[i];
                D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&tMissileParams);
                if (pSubMissile)
                {
                    MISSILE_SetTargetX(pSubMissile, gaRingOffsetX_006DB240[i]);
                    MISSILE_SetTargetY(pSubMissile, gaRingOffsetY_006DB140[i]);
                }
            }
        }

        return 1;
    }

    return 1;
}

// 0x004D05E0
int __fastcall sub_004D05E0_HitRing64(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        if (!pOwner)
        {
            return 1;
        }

        {
            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 2;
            tMissileParams.pOwner = pOwner;
            tMissileParams.pOrigin = pMissile;
            tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
            tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];

            int nStep = pMissilesTxtRecord->dwCltHitPar[0];
            if (nStep < 1)
            {
                nStep = 1;
            }

            for (int i = 0; i < 64; i += nStep)
            {
                tMissileParams.nTargetX = gaRingOffsetX_006DB440[i];
                tMissileParams.nTargetY = gaRingOffsetY_006DB340[i];
                D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&tMissileParams);
                if (pSubMissile)
                {
                    MISSILE_SetTargetX(pSubMissile, gaRingOffsetX_006DB440[i]);
                    MISSILE_SetTargetY(pSubMissile, gaRingOffsetY_006DB340[i]);
                }
            }
        }

        return 1;
    }

    return 1;
}

// 0x004D55C0
void __fastcall sub_004D55C0_CltDoOwnerSkill(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        if (pOwner)
        {
            D2SkillStrc* pSkill = UNITS_GetUsedSkill(pOwner);
            if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, gszMissileSourceFile_006DAEF4, 2285) == MISSILE_GetSkill(pMissile))
            {
                if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
                {
                    sub_004CDBA0_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltSubMissile[0], 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
                }

                D2Common_10235_PATH_UpdateRiderPath(pMissile, pOwner);
                sub_004D30C0_CltDoCommon(pMissile);
                return;
            }
        }
    }

    sub_00465F00_RemoveClientUnit(UNITS_GetUnitIdInline(pMissile), UNITS_GetUnitTypeInline(pMissile));
}

#include "gen/data/Source/D2Client/004D04D0_sub_004D04D0_HitRing64.inc"
