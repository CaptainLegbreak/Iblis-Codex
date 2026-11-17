struct D2GameStrc;
struct D2UnitStrc
{
    char unk0x00[0xC4];
    unsigned int dwFlags;
};
struct D2SkillsTxt
{
    char unk0x00[0x48];
    short wSrvMissileA;
    char unk0x4A[0x1F2];
};
struct D2DataTablesStrc
{
    char unk0x000[0xB6C];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
};
typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);
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
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2UnitStrc* __fastcall sub_0059FA30_CreateMissile(D2GameStrc* pGame, D2MissileStrc* pParams); // 0x0059FA30
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

// build: context GetSkillsTxtRecord
static __forceinline D2SkillsTxt* GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// build: context SKILLS_Abs
static int SKILLS_Abs(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

// 0x005CC050
int __fastcall sub_005CC050_PlaceSkillMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }
    const int nTargetX = CLIENTS_GetUnitX(pTarget);
    const int nTargetY = CLIENTS_GetUnitY(pTarget);
    const int nUnitX = CLIENTS_GetUnitX(pUnit);
    const int nUnitY = CLIENTS_GetUnitY(pUnit);

    int nY = nTargetY;
    int nX = nTargetX;
    int i = 4;
    if (SKILLS_Abs(nTargetX - nUnitX) < SKILLS_Abs(nTargetY - nUnitY))
    {
        nX = nUnitX;
        do
        {
            if (nX > nTargetX)
            {
                --nX;
            }
            else if (nX < nTargetX)
            {
                ++nX;
            }
        }
        while (--i > 0);
    }
    else
    {
        nY = nUnitY;
        do
        {
            if (nY > nTargetY)
            {
                --nY;
            }
            else if (nY < nTargetY)
            {
                ++nY;
            }
        }
        while (--i > 0);
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = pUnit;
    const int nDX = nX - nUnitX;
    const int nDY = nY - nUnitY;
    missileParams.nX = nUnitX + nDX / 6 - 1;
    missileParams.nY = nUnitY + nDY / 6 - 1;
    missileParams.nSkill = nSkillId;
    missileParams.dwFlags = 3;
    missileParams.nTargetX = nDX;
    missileParams.nTargetY = nDY;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    sub_0059FA30_CreateMissile(pGame, &missileParams);
    return 1;
}
