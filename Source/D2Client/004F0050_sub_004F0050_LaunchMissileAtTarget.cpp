struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    char unk0x10[0x38];
    int dwFrameCountPrecise;
    char unk0x4C[0x78];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    char unk0x000[0x114];
    int dwCltCalc[3];
    char unk0x120[0x11C];
};

struct D2MissilesTxt
{
    char unk0x00[0x1A4];
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

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
D2UnitStrc* __fastcall sub_004CDD10_CreateMissileAtTarget(D2UnitStrc* pUnit, int nMissile, int nSkillId, int nSkillLevel); // 0x004CDD10
int __stdcall sub_004DA150_GetMotionAZ(D2UnitStrc* pUnit); // 0x004DA150
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200
void __stdcall sub_004DA350_UpdateMotion(D2UnitStrc* pUnit); // 0x004DA350
int __fastcall sub_004F21B0_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall MISSILE_GetTotalFrames(D2UnitStrc* pMissile); // 0x0064A300

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline void sub_004F0050_LaunchMotion(D2UnitStrc* pMissile, int nHeight, int nVelocity)
{
    sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, nHeight);
    sub_004DA200_SetMotionVectorB(pMissile, 0, 0, nVelocity, 1);
    sub_004DA350_UpdateMotion(pMissile);
}

// 0x004F0050
int __fastcall sub_004F0050_LaunchMissileAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pMissile = sub_004CDD10_CreateMissileAtTarget(pUnit, nMissile, nSkillId, nSkillLevel);
    if (!pMissile)
    {
        return 0;
    }

    const int nFrames = MISSILE_GetTotalFrames(pMissile);
    const int nHeight = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkillId, nSkillLevel) + sub_004DA150_GetMotionAZ(pUnit);
    sub_004F0050_LaunchMotion(pMissile, nHeight, nFrames ? -(nHeight / nFrames) : -(nHeight / 2));
    return 1;
}
