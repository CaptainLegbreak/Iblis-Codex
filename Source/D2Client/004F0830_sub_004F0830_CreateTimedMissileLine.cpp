struct D2DynamicPathStrc;
struct Unit0064A300;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x98];
    unsigned int dwFlagEx;
};

struct D2SkillsTxt
{
    char unk0x000[0xEA];
    short wCltMissileA;
    short wCltMissileB;
    char unk0x0EE[0x4A];
    unsigned int dwCalc[4];
    char unk0x148[0xF4];
};

struct D2MissilesTxt
{
    char unk0x000[0x38];
    int dwParam[5];
    char unk0x04C[0x158];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[4];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[4];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
D2UnitStrc* __fastcall sub_004C5470_CreateMissileToTarget(D2UnitStrc* pUnit, int nMissile, int nSkillId, int nSkillLevel); // 0x004C5470
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nSkillId, int nSkillLevel); // 0x004CDB40
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit); // 0x00620100
void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed); // 0x00621780
int __stdcall sub_006417F0_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
extern "C" int __stdcall sub_0064A300(Unit0064A300* pUnit); // 0x0064A300
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
void __stdcall MISSILE_SetActivateFrame(D2UnitStrc* pMissile, int nActivateFrame); // 0x0064A5F0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

// 0x004F0830
int __fastcall sub_004F0830_CreateTimedMissileLine(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    const int nMissileId = pSkillsTxtRecord->wCltMissileB;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
    if (!pMissilesTxtRecord)
        return 0;
    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
        return 0;
    int nDistance = sub_006417F0_GetDistanceToXY(pUnit, nTargetX, nTargetY);
    if (nDistance < 1)
        nDistance = 1;
    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    const int nDeltaX = 100 * (nTargetX - nX) / nDistance;
    const int nDeltaY = 100 * (nTargetY - nY) / nDistance;
    const int nStep = pMissilesTxtRecord->dwParam[0] < 1 ? 1 : pMissilesTxtRecord->dwParam[0];
    const int nFrameStep = pMissilesTxtRecord->dwParam[1] < 1 ? 1 : pMissilesTxtRecord->dwParam[1];
    int nPos = nStep;
    int nCount = 0;
    while (nPos < nDistance)
    {
        D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pUnit, nMissileId, nX + nPos * nDeltaX / 100, nY + nPos * nDeltaY / 100, nSkillId, nSkillLevel);
        if (pMissile)
        {
            D2COMMON_10160_PathUpdateDirection(pMissile->pDynamicPath, UNITS_GetDirection(pUnit));
            const int nFrames = sub_0064A300((Unit0064A300*)pMissile);
            MISSILE_SetTotalFrames(pMissile, nFrames + nCount * nFrameStep);
            MISSILE_SetCurrentFrame(pMissile, nFrames + nCount * nFrameStep);
            MISSILE_SetActivateFrame(pMissile, nFrames - nCount * nFrameStep);
            pMissile->dwFlagEx |= 0x40000;
        }
        nPos += nStep;
        ++nCount;
    }
    const int nTargetMissile = pSkillsTxtRecord->wCltMissileA;
    if (nTargetMissile >= 0 && nTargetMissile < sgptDataTables->nMissilesTxtRecordCount)
    {
        D2UnitStrc* pMissile = sub_004C5470_CreateMissileToTarget(pUnit, nTargetMissile, nSkillId, nSkillLevel);
        if (!pMissile)
            return 0;

        const int nSpeed = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (nSpeed > 0)
            UNITS_SetAnimationSpeed(pMissile, nSpeed);

        const int nFrames = sub_0064A300((Unit0064A300*)pMissile);
        MISSILE_SetTotalFrames(pMissile, nFrames + nCount * nFrameStep);
        MISSILE_SetCurrentFrame(pMissile, nFrames + nCount * nFrameStep);
        MISSILE_SetActivateFrame(pMissile, nFrames - nCount * nFrameStep);
        pMissile->dwFlagEx |= 0x40000;
    }
    return 1;
}
