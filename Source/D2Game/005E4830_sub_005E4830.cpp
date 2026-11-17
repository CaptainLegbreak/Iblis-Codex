struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk_10[0x10];
    D2SeedStrc pSeed;
    char unk_28[0x9C];
    union
    {
        unsigned int dwFlags;
        struct { unsigned int unkBits:30; unsigned int bIgnoreTarget:1; unsigned int lastBit:1; };
    };
};
struct D2AiControlStrc { char unk_00[0x14]; int dwAiParam[3]; };
struct D2MonStatsTxt { char unk_00[0x32]; short nVelocity; short nRun; };
struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    int unk_04;
    D2UnitStrc* pTarget;
    int unk_0C[2];
    int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
};
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc*); // 0x0058F0D0
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*, D2UnitStrc*); // 0x005DC380
int __fastcall sub_6FCF14D0(D2UnitStrc*, D2UnitStrc*); // 0x005DC640
D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*); // 0x005DD7F0
D2UnitStrc* __fastcall sub_6FCCFD40(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*, int); // 0x005DDE50
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc*, D2UnitStrc*, int, D2UnitStrc*); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*, D2UnitStrc*, int); // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc*, int, int, unsigned char); // 0x005DE190
int __fastcall sub_6FCD0410(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x005DED40
void __fastcall sub_005DF400_FollowOwner(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x005DF400
int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, int, int); // 0x005E3EA0
int __fastcall sub_005E45D0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2UnitStrc*, int, D2AiTickParamStrc*, int, int); // 0x005E45D0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc*); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
static __forceinline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}
static __forceinline int UNITS_TestIgnoreTargetFlag(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlags >> 30) & 1;
    return bResult;
}
// 0x005E4830
void __fastcall sub_005E4830(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        if (pAiControl->dwAiParam[2])
        {
            D2UnitStrc* pOldOwner = SUNIT_GetServerUnit(pGame, 0, pAiControl->dwAiParam[2]);
            if (pOldOwner)
            {
                D2GAME_AI_PetMove_6FCE2BA0(pGame, pOldOwner, pUnit, 3, 0, 0, 0);
                return;
            }
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    pAiControl->dwAiParam[2] = pOwner->dwUnitId;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nOwnerDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    if (nOwnerDistance > 50)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 3, 0, 0, 0);
        return;
    }
    int nVelocity;
    if (pMonStatsTxt->nVelocity > 0)
    {
        nVelocity = 100 * pMonStatsTxt->nRun / pMonStatsTxt->nVelocity - 100;
        if (nVelocity >= 100)
            nVelocity = 100;
    }
    else
        nVelocity = 100;
    if (nOwnerDistance > 28)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, nVelocity, 0);
        return;
    }
    int nOwnerTargetDistance;
    int bOwnerCombat;
    D2UnitStrc* pOwnerTarget = sub_6FCF2110(pGame, pOwner, pAiControl, &nOwnerTargetDistance, &bOwnerCombat);
    if (pOwnerTarget && UNITS_TestIgnoreTargetFlag(pOwnerTarget))
        pOwnerTarget = 0;
    int nTargetDistance;
    int bCombat;
    D2UnitStrc* pTarget = sub_6FCCFD40(pGame, pUnit, pAiControl, &nTargetDistance, &bCombat, 24);
    if (!pTarget || nTargetDistance > 6)
    {
        pTarget = 0;
        if (pOwnerTarget)
        {
            nTargetDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwnerTarget);
            if (nTargetDistance < 36)
                pTarget = pOwnerTarget;
        }
    }
    if (!sub_6FCF14D0(pUnit, pTarget))
        pTarget = 0;
    int nResult;
    if ((int)(AI_RollUnitSeed(pUnit) % 100) < 15)
        nResult = sub_005E45D0(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 1, 8);
    else
        nResult = sub_005E45D0(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 0, 7);
    if (nResult)
        return;
    if (pTarget && DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        sub_005DF400_FollowOwner(pGame, pUnit, pOwner, 4);
        return;
    }
    if (!pTarget)
    {
        sub_005DF400_FollowOwner(pGame, pUnit, pOwner, 4);
        return;
    }
    if (!DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (bCombat)
        {
            if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 80)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        AITACTICS_SetVelocity(pUnit, 0, 0, 12);
        sub_6FCD0410(pGame, pUnit, pTarget, 7);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
}
