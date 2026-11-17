struct D2GameStrc;
struct D2SkillStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; };
struct D2SkillsTxt { char unk_000[0x48]; short nMissileA; short nMissileB; char unk_04C[0x18]; unsigned int dwRangeCalc; char unk_068[0xD4]; unsigned int dwDamageCalc; char unk_140[0xFC]; };
struct D2DataTablesStrc { char unk_000[0xB6C]; int nMissilesTxtRecordCount; char unk_B70[0x28]; D2SkillsTxt* pSkillsTxt; void* pSkillsLinker; int nSkillsTxtRecordCount; };
struct D2MissileStrc {
    unsigned int dwFlags; D2UnitStrc* pOwner; D2UnitStrc* pOrigin; int unk_0C;
    int nMissile; int nX; int nY; int nTargetX; int nTargetY; int unk_24; int unk_28;
    int nSkillId; int nSkillLevel; int unk_34; int unk_38; int unk_3C; int unk_40;
    int unk_44; int unk_48; int unk_4C; int unk_50;
    void (__fastcall* pInitFunc)(D2UnitStrc*, int); int nInitArg;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc*); // 0x00620250
int __stdcall SKILLS_GetParam1(D2SkillStrc*); // 0x006444A0
int __stdcall SKILLS_GetParam2(D2SkillStrc*); // 0x006444D0
int __stdcall SKILLS_GetParam3(D2SkillStrc*); // 0x00644500
void __stdcall SKILLS_SetParam1(D2SkillStrc*, int); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc*, int); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc*, int); // 0x006445E0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
D2UnitStrc* __fastcall sub_0056BD10_FindTarget(D2GameStrc*, D2UnitStrc*, int, int, int, unsigned int, int, int*); // 0x0056BD10
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc*, D2UnitStrc*); // 0x00620C10
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc*, D2UnitStrc*, int*, int*); // 0x0056D2C0
int __fastcall UNITS_GetWeaponClass(D2UnitStrc*); // 0x00623C60
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc*, D2MissileStrc*); // 0x0059FA30
void __fastcall SKILLS_AddDamagePercentBonus(D2UnitStrc*, int); // 0x005DB6A0
int __fastcall sub_004F4110_GetSkillParam5(int); // 0x004F4110
void __fastcall sub_0056E210_SetSkillDelay(D2UnitStrc*, int); // 0x0056E210
inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}
static __forceinline int GetTargetType(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

static __forceinline int GetTargetId(D2UnitStrc* pUnit)
{
    int nId = -1;
    if (pUnit)
    {
        nId = pUnit->dwUnitId;
    }
    return nId;
}

// 0x005DBA40
int __fastcall sub_005DBA40_CreateSkillMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt) return 0;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill) return 0;
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwRangeCalc, nSkillId, nSkillLevel);
    int nCount = SKILLS_GetParam1(pSkill);
    if (!nCount) return 0;
    const int nTargetId = SKILLS_GetParam3(pSkill);
    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam2(pSkill), nTargetId);
    if (!pTarget)
    {
        pTarget = sub_0056BD10_FindTarget(pGame, pUnit, 0, 0, nRange, 3, nTargetId, 0);
        if (!pTarget) return 1;
    }
    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    int nX = 0;
    int nY = 0;
    D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY);
    int nMissile = pSkillsTxt->nMissileA;
    if (UNITS_GetWeaponClass(pUnit) != 1 && pSkillsTxt->nMissileB >= 0)
        nMissile = pSkillsTxt->nMissileB;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount) return 0;
    const int nDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwDamageCalc, nSkillId, nSkillLevel);
    D2MissileStrc missile;
    memset(&missile, 0, sizeof(missile));
    missile.dwFlags = 0x21;
    missile.pOwner = pUnit;
    missile.nX = CLIENTS_GetUnitX(pUnit);
    missile.nY = CLIENTS_GetUnitY(pUnit);
    missile.nSkillId = nSkillId;
    missile.nSkillLevel = nSkillLevel;
    missile.nMissile = nMissile;
    missile.nTargetX = nX;
    missile.nTargetY = nY;
    missile.pInitFunc = SKILLS_AddDamagePercentBonus;
    missile.nInitArg = nDamage;
    MISSILES_CreateMissileFromParams(pGame, &missile);
    --nCount;
    SKILLS_SetParam1(pSkill, nCount);
    if (nCount <= 0) return 0;
    D2UnitStrc* pNextTarget = sub_0056BD10_FindTarget(pGame, pUnit, 0, 0, nRange, 3, !pTarget ? -1 : pTarget->dwUnitId, 0);
    if (pNextTarget)
    {
        SKILLS_SetParam2(pSkill, GetTargetType(pNextTarget));
        SKILLS_SetParam3(pSkill, GetTargetId(pNextTarget));
        sub_0056E210_SetSkillDelay(pUnit, sub_004F4110_GetSkillParam5(nSkillId));
    }
    return 1;
}
