struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
struct D2PlayerDataStrc;
struct D2AiCmdStrc;
struct D2SeedStrc { unsigned int nLow; unsigned int nHigh; };
struct D2UnitStrc { int dwUnitType; int dwClassId; int unk08; int dwUnitId; int dwAnimMode; char pad14[0xC]; D2SeedStrc pSeed; int unk28; D2DynamicPathStrc* pDynamicPath; };
struct D2GameStrc;
struct D2AiControlStrc { char pad00[0x14]; int dwAiParam[3]; };
struct D2AiTickParamStrc { D2AiControlStrc* pAiControl; };
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc*, int); // 0x00472210
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc*, D2UnitStrc*, int, int); // 0x00540E60
D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc*); // 0x0058EE80
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc*); // 0x0058F0D0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int); // 0x005B0E00
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*, D2UnitStrc*); // 0x005DC380
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc*, D2UnitStrc*, unsigned int*, int*); // 0x005DDC30
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*, D2UnitStrc*, int); // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc*, int, int, unsigned char); // 0x005DE190
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc*, D2UnitStrc*, unsigned char); // 0x005DE200
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc*, D2UnitStrc*, int, int); // 0x005DED90
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char, int); // 0x005DEFE0
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x005DF530
int __fastcall sub_005E3930_FollowOwner(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, int, int); // 0x005E3930
void __fastcall sub_005E5050_RunHirelingAction(D2GameStrc*, D2UnitStrc*, int, D2UnitStrc*, D2UnitStrc*, D2SeedStrc*, D2AiTickParamStrc*); // 0x005E5050
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc*); // 0x0061AB00
int __stdcall D2Common_10095(D2ActiveRoomStrc*, int, int); // 0x0061B130
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
int __stdcall sub_00648A20_GetTargetX(D2DynamicPathStrc*); // 0x00648A20
int __stdcall sub_00648A30_GetTargetY(D2DynamicPathStrc*); // 0x00648A30
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc*); // 0x00649180
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc*, int, int, int, int); // 0x0064D910
// build: context HIRELING_StepAside
static __forceinline void HIRELING_StepAside(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, unsigned char nSteps)
{
    D2DynamicPathStrc* pPath = pOwner->pDynamicPath;
    UNITS_GetPlayerData(pOwner);
    int nX = sub_00648A20_GetTargetX(pPath);
    int nY = sub_00648A30_GetTargetY(pPath);
    AITACTICS_SetVelocity(pUnit, 7, 0, 0);
    if (D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pOwner, nSteps)) return;
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    if (D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pOwner, nSteps, 1)) return;
    AITACTICS_SetVelocity(pUnit, 0, 0, 40);
    AITACTICS_WalkToTargetCoordinates(pGame, pUnit, nX, nY);
}

// 0x005E52D0
void __fastcall sub_005E52D0_HirelingThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    int nMonsterId;
    if (!pUnit) nMonsterId = -1;
    else nMonsterId = pUnit->dwClassId;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        if (nMonsterId == 271)
        {
            AITHINK_ExecuteAiFn(pGame, pUnit, pTick->pAiControl, 5);
        }
        else
        {
            AITHINK_ExecuteAiFn(pGame, pUnit, pTick->pAiControl, 6);
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (pOwner->dwUnitType != 0)
    {
        if (nMonsterId == 271)
        {
            D2AiControlStrc* pControl = pTick->pAiControl;
            AITHINK_ExecuteAiFn(pGame, pUnit, pControl, 5);
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        D2AiControlStrc* pControl = pTick->pAiControl;
        AITHINK_ExecuteAiFn(pGame, pUnit, pControl, 6);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (STATES_CheckState(pUnit, 12)) STATES_ToggleState(pUnit, 12, 0);
    int nMode;
    if (!pUnit) nMode = 0;
    else nMode = pUnit->dwAnimMode;
    if (nMode == 2 || nMode == 15) return;
    D2AiControlStrc* pAi = pTick->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    int nFar;
    unsigned int nNear;
    int nSteps;
    if (pAi->dwAiParam[0] > 16 && pAi->dwAiParam[0] < 20)
    {
        nFar = 2 * pAi->dwAiParam[0];
        nNear = pAi->dwAiParam[0];
        nSteps = pAi->dwAiParam[0] >> 1;
    }
    else { nFar = 24; nNear = 16; nSteps = 5; }
    unsigned int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    int nOwnerMode = pOwner->dwAnimMode;
    if (nDistance > 100)
    {
        sub_005E3930_FollowOwner(pGame, pOwner, pUnit, 3, 0, 0, 0);
        return;
    }
    if (nDistance > (unsigned int)nFar)
    {
        sub_005E3930_FollowOwner(pGame, pOwner, pUnit, 1, 1, 60, 0);
        return;
    }
    if (nDistance > nNear)
    {
        if (nOwnerMode == 2 || nOwnerMode == 6)
        {
            sub_005E3930_FollowOwner(pGame, pOwner, pUnit, 0, 0, 0, 0);
            return;
        }
        if (nOwnerMode == 3)
        {
            sub_005E3930_FollowOwner(pGame, pOwner, pUnit, 0, 1, 60, 0);
            return;
        }
    }
    if (nMode != 1)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;
    }
    int bRanged;
    switch (nMonsterId)
    {
    case 338: case 560: case 561: bRanged = 0; break;
    default: bRanged = 1; break;
    }
    int bBlocked = 0;
    int nPattern = PATH_GetUnitCollisionPattern(pUnit);
    if (COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nPattern, 0x40))
    {
        bBlocked = 1;
        int nChance = 6;
        if (bRanged) nChance = 12;
        if (sub_00472210_SeedRollMasked(pSeed, 128) < nChance)
        {
            AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
            return;
        }
    }
    if (!DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        int bCombat;
        D2UnitStrc* pTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, &bCombat);
        if (pTarget && nDistance < 25)
        {
            sub_005E5050_RunHirelingAction(pGame, pUnit, nMonsterId, pOwner, pTarget, pSeed, pTick);
            return;
        }
    }
    if (bBlocked)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        return;
    }
    int nRegion = D2Common_10095(UNITS_GetRoom(pOwner), CLIENTS_GetUnitX(pOwner), CLIENTS_GetUnitY(pOwner));
    if (D2Common_10095(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit)) != nRegion)
    {
        sub_005E3930_FollowOwner(pGame, pOwner, pUnit, 0, 1, 60, 0);
        return;
    }
    nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    if (nDistance <= 1)
    {
        HIRELING_StepAside(pGame, pOwner, pUnit, nSteps - 1);
        return;
    }
    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 5) D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pOwner, nNear);
    else AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
}
