struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2AiTargetArgsStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    union
    {
        struct
        {
            int bCheckTargetCollision;
            int nMaxDistance;
            int unk0x10;
            D2UnitStrc* pAlternativeTarget;
            int nAlternativeDistance;
        } tSearch;
        struct
        {
            D2UnitStrc* pAlternativeTarget;
            int nAlternativeDistance;
        } tEligible;
        D2UnitStrc* pIgnoredTarget;
    };
    int unk0x1C[3];
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

int __stdcall sub_00648E30_GetPathValue(D2DynamicPathStrc* pPath);                                          // 0x00648E30
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath);                                  // 0x00648BF0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90
void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType);                                           // 0x00648CF0
void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3);                         // 0x00649970
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pPath);                                         // 0x00648780
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
int __fastcall MONSTERAI_GetTargetOverrideType(D2UnitStrc* pUnit);                                          // 0x005730E0
int __fastcall MONSTERAI_GetTargetOverrideGUID(D2UnitStrc* pUnit);                                          // 0x00573100
void __fastcall sub_00573120_ClearMonsterPair(D2UnitStrc* pUnit);                                           // 0x00573120
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource);      // 0x005DC380
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask);      // 0x00622AA0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax);                                    // 0x00472210
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3);                           // 0x005543B0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall sub_0061B130_GetCollision(D2ActiveRoomStrc* pRoom, int nX, int nY);                           // 0x0061B130
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40

// 0x005DD510
static int __stdcall AIUTIL_ShouldUseAlternativeTarget(D2UnitStrc** ppTarget, int* pTargetDistance, D2UnitStrc* pAlternativeTarget, int nAlternativeDistance, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0)
    {
        return 0;
    }

    if (!pAlternativeTarget)
    {
        return 0;
    }

    D2UnitStrc* pCurrentTarget = *ppTarget;
    if (!pCurrentTarget)
    {
        return 1;
    }

    if (nAlternativeDistance > 5)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    const int nPathType = sub_00648E30_GetPathValue(pPath);
    D2UnitStrc* pPathTarget = PATH_GetTargetUnit(pPath);
    const int nX = D2COMMON_10175_PathGetFirstPointX(pPath);
    const int nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    PATH_SetTargetUnit(pPath, pCurrentTarget);
    PATH_SetType(pPath, 2);
    D2Common_10142(pPath, pUnit, 0);
    PATH_SetTargetUnit(pPath, pPathTarget);
    D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
    PATH_SetType(pPath, nPathType);

    if (PATH_GetNumberOfPathPoints(pPath))
    {
        return 0;
    }

    D2AiTargetArgsStrc arg;
    arg.pTarget = 0;
    arg.nDistance = 0x7FFFFFFF;
    arg.pIgnoredTarget = pCurrentTarget;
    sub_6FCF1E80(SUNIT_GetGameFromUnit(pUnit), pUnit, &arg, 0, 7);

    if (!arg.pTarget || arg.nDistance >= 20)
    {
        return 1;
    }

    *ppTarget = arg.pTarget;
    *pTargetDistance = arg.nDistance;
    return 0;
}

static __forceinline int AIUTIL_IsOverrideTargetValid_Inline(D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return 0;
    }

    switch (pTarget->dwUnitType)
    {
    case 0:
    case 1:
        return !SUNIT_IsDead(pTarget);
    case 3:
        return 1;
    }
    return 0;
}

static int __stdcall AIUTIL_ResolveTargetOverride(int bCheckCollision, int bUseEligibilityCheck, D2UnitStrc** ppUnit, int* pDistance, D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005DD610

// build: context AIUTIL_ResolveTargetOverride
static int __stdcall AIUTIL_ResolveTargetOverride(int bCheckCollision, int bUseEligibilityCheck, D2UnitStrc** ppUnit, int* pDistance, D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = 0;
    int nDistance = 0;

    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
    {
        return 0;
    }

    const int nOverride = MONSTERAI_GetTargetOverrideType(pUnit);
    if (!nOverride)
    {
        return 0;
    }

    switch (nOverride)
    {
    case 1:
        pTarget = SUNIT_GetServerUnit(pGame, 0, MONSTERAI_GetTargetOverrideGUID(pUnit));
        if (!pTarget)
        {
            sub_00573120_ClearMonsterPair(pUnit);
            return 0;
        }
        nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
        if (bUseEligibilityCheck && UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
        {
            sub_00573120_ClearMonsterPair(pUnit);
            return 0;
        }
        break;

    case 2:
        pTarget = SUNIT_GetServerUnit(pGame, 1, MONSTERAI_GetTargetOverrideGUID(pUnit));
        if (!pTarget)
        {
            sub_00573120_ClearMonsterPair(pUnit);
            return 0;
        }
        nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
        if (bUseEligibilityCheck && UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
        {
            sub_00573120_ClearMonsterPair(pUnit);
            return 0;
        }
        break;

    case 4:
        pTarget = SUNIT_GetServerUnit(pGame, 3, MONSTERAI_GetTargetOverrideGUID(pUnit));
        if (!pTarget)
        {
            sub_00573120_ClearMonsterPair(pUnit);
            return 0;
        }
        nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
        if (bUseEligibilityCheck && UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
        {
            sub_00573120_ClearMonsterPair(pUnit);
            return 0;
        }
        break;

    case 3:
    {
        const int nAlignment = STATLIST_GetUnitAlignment(pUnit);
        const int nRoll = sub_00472210_SeedRollMasked(&pUnit->pSeed, 2);
        if (nAlignment == 1)
        {
            if (nRoll)
            {
                sub_6FCBDD30(pUnit, 2, 1);
            }
            else
            {
                sub_6FCBDD30(pUnit, 0, 1);
            }
        }
        else if (nRoll)
        {
            if (nAlignment == 0)
            {
                sub_6FCBDD30(pUnit, 2, 1);
            }
            else if (nAlignment == 2)
            {
                sub_6FCBDD30(pUnit, 0, 1);
            }
        }

        D2AiTargetArgsStrc arg;
        arg.pTarget = 0;
        arg.nDistance = 0x7FFFFFFF;
        if (!bUseEligibilityCheck)
        {
            const int nUnk = sub_0061B130_GetCollision(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
            arg.tSearch.bCheckTargetCollision = bCheckCollision;
            arg.tSearch.nMaxDistance = 35;
            arg.tSearch.unk0x10 = nUnk;
            arg.tSearch.pAlternativeTarget = 0;
            arg.tSearch.nAlternativeDistance = 0x7FFFFFFF;
            sub_6FCF1E80(pGame, pUnit, &arg, 0, 5);
        }
        else
        {
            arg.tEligible.pAlternativeTarget = 0;
            arg.tEligible.nAlternativeDistance = 0x7FFFFFFF;
            sub_6FCF1E80(pGame, pUnit, &arg, 0, 6);
        }

        pTarget = arg.pTarget;
        nDistance = arg.nDistance;
        sub_6FCBDD30(pUnit, nAlignment, 1);
        break;
    }

    default:
        sub_00573120_ClearMonsterPair(pUnit);
        return 0;
    }

    if (AIUTIL_IsOverrideTargetValid_Inline(pTarget))
    {
        *ppUnit = pTarget;
        *pDistance = nDistance;
        return 1;
    }

    sub_00573120_ClearMonsterPair(pUnit);
    return 0;
}

// 0x005DDC30
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange)
{
    D2UnitStrc* pTarget;
    int nDistance;

    if (!AIUTIL_ResolveTargetOverride(0, 1, &pTarget, &nDistance, pGame, pUnit))
    {
        D2AiTargetArgsStrc arg;
        arg.pTarget = 0;
        arg.nDistance = 0x7FFFFFFF;
        arg.tEligible.pAlternativeTarget = 0;
        arg.tEligible.nAlternativeDistance = 0x7FFFFFFF;
        sub_6FCF1E80(pGame, pUnit, &arg, 0, 6);

        if (AIUTIL_ShouldUseAlternativeTarget(&arg.pTarget, &arg.nDistance, arg.tEligible.pAlternativeTarget, arg.tEligible.nAlternativeDistance, pUnit))
        {
            pTarget = arg.tEligible.pAlternativeTarget;
            nDistance = arg.tEligible.nAlternativeDistance;
        }
        else
        {
            pTarget = arg.pTarget;
            nDistance = arg.nDistance;
        }
    }

    if (!pTarget)
    {
        if (pInMeleeRange)
        {
            *pInMeleeRange = 0;
        }

        if (pDistance)
        {
            *pDistance = 0x7FFFFFFF;
        }

        return 0;
    }

    if (pInMeleeRange)
    {
        *pInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    }

    if (pDistance)
    {
        *pDistance = nDistance;
    }

    return pTarget;
}
