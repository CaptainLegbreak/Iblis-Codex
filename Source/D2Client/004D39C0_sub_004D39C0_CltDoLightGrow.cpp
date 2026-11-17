struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[23];
    void* pLight;
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
    char unk0x78[0x12C];
};

struct D2SkillsTxt
{
    char unk0x000[0x138];
    int dwCltCalc;
    char unk0x13C[0x100];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
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
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
void __fastcall sub_004742D0_ResetLightSize(void* pLight, int nSize);                                       // 0x004742D0
int __fastcall sub_00474350_GetLightSize(void* pLight);                                                     // 0x00474350
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __fastcall sub_004BA790_UpdateUnitHint(void* pHint, D2UnitStrc* pUnit, int nArg);                      // 0x004BA790
void* __fastcall sub_004CA990_GetLinkFirst(D2UnitStrc* pUnit);                                              // 0x004CA990
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pMissile, int nX, int nY, int nZ);                 // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pMissile, int nX, int nY, int nZ, int nArg);       // 0x004DA200
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, int nCalc, int nSkillId, int nSkillLevel);     // 0x00646CA0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                          // 0x0064A3B0

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecordChecked(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

static inline D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return SKILLS_GetMissilesTxtRecordChecked(pUnit->dwClassId);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pSkillsTxt[nSkillId];
}

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

// 0x004D39C0
void __fastcall sub_004D39C0_CltDoLightGrow(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
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

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    const int nParam0 = pMissilesTxtRecord->dwCltParam[0] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[0];
    const int nParam1 = pMissilesTxtRecord->dwCltParam[1] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[1];
    const int nVelocityZ = nParam1 * nParam0;
    const int nParam2 = pMissilesTxtRecord->dwCltParam[2] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[2];
    const int nVelocityX = nParam2 * nParam0;

    int nSteps = SKILLS_EvaluateSkillFormula(sub_004639D0_GetOwnerUnit(pMissile), pSkillsTxtRecord->dwCltCalc, nSkillId, MISSILE_GetLevel(pMissile));
    nSteps = D2_MIN(D2_MAX(nSteps, 1), 0x3C);

    const int nInterval = 0x3C / nSteps;
    void* pLight = pMissile->pLight;
    const int nLightSize = pLight ? sub_00474350_GetLightSize(pLight) : 0;
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (!((nFrames + 1) % nInterval) && nLightSize < nSteps && pLight)
        sub_004742D0_ResetLightSize(pLight, nLightSize + 1);

    if (!nFrames)
    {
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 1;
        tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        tParams.nX = CLIENTS_GetUnitX(pMissile);
        tParams.nY = CLIENTS_GetUnitY(pMissile);
        tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&tParams);
        if (pSubMissile)
        {
            sub_004DA1D0_SetMotionVectorA(pSubMissile, -nVelocityX, 0, nVelocityZ);
            sub_004DA200_SetMotionVectorB(pSubMissile, nParam2, 0, -nParam1, 1);
        }

        if (pMissilesTxtRecord->wCltSubMissile[1] > 0)
        {
            tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
            pSubMissile = sub_004CD540_CreateMissile(&tParams);
            if (pSubMissile)
            {
                sub_004DA1D0_SetMotionVectorA(pSubMissile, -nVelocityX, 0, nVelocityZ);
                sub_004DA200_SetMotionVectorB(pSubMissile, nParam2, 0, -nParam1, 1);
            }
        }
    }

    if (nFrames == nParam0 - 2)
    {
        void* pHint = sub_004CA990_GetLinkFirst(pMissile);
        if (pHint)
            sub_004BA790_UpdateUnitHint(pHint, pMissile, 1);

        if (pMissilesTxtRecord->wProgSound > 0)
            sub_004B9A00(pMissilesTxtRecord->wProgSound, pMissile, 0, 0, 0);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
