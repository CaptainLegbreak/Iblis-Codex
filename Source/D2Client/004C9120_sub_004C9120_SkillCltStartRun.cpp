struct D2SkillStrc;
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2CharStatsTxt
{
    char unk0x00[0x40];
    unsigned char nRunSpeed;
};

struct D2MonStatsTxt
{
    char unk0x00[0x32];
    short nRun;
};

extern "C" const char gszSkillsBarSourceFile_006DAE58[];                                                    // 0x006DAE58

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40
int __fastcall sub_004C7630(D2UnitStrc* pUnit, D2UnitStrc* pTarget);                                        // 0x004C7630
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClassId);                                // 0x004833E0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
int __stdcall PATH_GetPathPoints(D2DynamicPathStrc* pPath, D2PathPointStrc** ppPathPoints);                 // 0x006487D0
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0
void __fastcall sub_004C7950(D2UnitStrc* pUnit);                                                            // 0x004C7950

static inline int UNITS_GetUnitType_C9120(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }

    return pUnit->dwUnitType;
}

// 0x004C9120
int __fastcall sub_004C9120_SkillCltStartRun(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != 0 && nUnitType != 1)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pSkill || !pPath)
    {
        return 0;
    }

    if (pUnit == sub_00463DD0())
    {
        if (SKILLS_GetSkillIdFromSkill(pSkill, gszSkillsBarSourceFile_006DAE58, 1129) == nSkillId && (SKILLS_GetFlags(pSkill) & 1))
        {
            return 0;
        }

        if (STATES_CheckState(pUnit, 0x36))
        {
            return 0;
        }
    }

    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (pTarget && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        return sub_004C7630(pUnit, pTarget);
    }

    const int bPlayer = UNITS_GetUnitType_C9120(pUnit) == 0;
    const int nRestoreMask = bPlayer ? 0x1C09 : 0x3C01;
    const int nUnitMask = bPlayer ? 0x80 : 0x100;

    PATH_SetMoveTestCollisionMask(pPath, 0xC01);
    PATH_SetType(pPath, 7);
    if (!D2Common_10142(pPath, pUnit, 0))
    {
        PATH_SetMoveTestCollisionMask(pPath, nRestoreMask);
        return 0;
    }

    if (bPlayer)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = sub_004833E0_GetCharStatsTxtRecord(pUnit->dwClassId);
        if (pCharStatsTxtRecord)
        {
            PATH_SetVelocity(pPath, pCharStatsTxtRecord->nRunSpeed << 8, gszSkillsBarSourceFile_006DAE58, 1177);
        }
    }
    else
    {
        PATH_SetVelocity(pPath, DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId)->nRun << 8, gszSkillsBarSourceFile_006DAE58, 1183);
    }

    PATH_SetMoveTestCollisionMask(pPath, 0x401);

    D2PathPointStrc* pPathPoints;
    const int nPoints = PATH_GetPathPoints(pPath, &pPathPoints);
    if (!nPoints)
    {
        PATH_SetMoveTestCollisionMask(pPath, nRestoreMask);
        return 0;
    }

    nX = pPathPoints[nPoints - 1].X;
    nY = pPathPoints[nPoints - 1].Y;
    COLLISION_SetMaskWithPattern(UNITS_GetRoom(pUnit), nX, nY, PATH_GetUnitCollisionPattern(pUnit), nUnitMask);
    SKILLS_SetFlags(pSkill, 1);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);
    sub_004C7950(pUnit);
    return 1;
}
