#include "D2Client.h"
#include "D2Path.h"
#include "D2ClientGame.h"

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
int* __fastcall MONSTER_GetAiValuePtr(D2UnitStrc* pUnit);                                                 // 0x004AE170
void __fastcall MONSTER_HandleMonsterCommand(int nCommand, D2UnitStrc* pUnit, D2MonCommandStrc* pTarget);    // 0x004AFF60
int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490
D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB);// 0x004CDB40
void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
void __stdcall GFXUTIL_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA2A0
void __fastcall GFXUTIL_SetMotionFlagMask(D2UnitStrc* pUnit, int bSet);                                  // 0x004DA6E0
void __stdcall sub_004DA350_UpdateMotion(D2UnitStrc* pUnit);                                                // 0x004DA350
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance);            // 0x00648E70
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760

extern D2UnitStrc* gapAiTargets[];                                                                  // 0x007A7470

static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static inline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollRandomNumber64_Inline(D2SeedStrc* pSeed)
{
    pSeed->lSeed = (pSeed->lSeed >> 32) + 0x6AC690C5i64 * (unsigned int)pSeed->lSeed;
    return (unsigned int)pSeed->lSeed;
}

static inline int SEED_RollPercentage64_Inline(D2SeedStrc* pSeed)
{
    return SEED_RollRandomNumber64_Inline(pSeed) % 100;
}

static inline int SEED_RollPercentage_Inline(D2SeedStrc* pSeed)
{
    return SEED_RollRandomNumber_Inline(pSeed) % 100;
}

static inline int AI_GetUnitMode_Inline(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->dwAnimMode;
}

static inline void AI_SetTimer_Inline(D2UnitStrc* pUnit, int nTicks)
{
    int* pTimer = sub_004AE110_GetAiTimer(pUnit);
    if (pTimer)
    {
        *pTimer = nTicks;
    }
}

D2UnitStrc* __stdcall sub_0046C720_FindNearestTarget(D2UnitStrc* pUnit, int* pDistance); // 0x0046C720

static void __stdcall sub_0046C770_CommandOnUnit(int nCommand, int nArg, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int nTargetType = 6;
    if (pTarget)
    {
        nTargetType = pTarget->dwUnitType;
    }

    D2MonCommandStrc tCommand;
    tCommand.nX = nTargetType;
    tCommand.nY = !pTarget ? -1 : pTarget->dwUnitId;
    tCommand.nZero = 0;
    tCommand.nPathValue = sub_00648E30_GetPathValue(pPath);
    tCommand.nArg = nArg;
    tCommand.nPathByte = sub_00648EA0_GetPathByte(pPath);
    MONSTER_HandleMonsterCommand(nCommand, pUnit, &tCommand);
}

// 0x0046C7D0
static int __stdcall sub_0046C7D0_StepAwayFromUnit(D2UnitStrc* pUnit, unsigned char nScale, int nCommand, int nArg, D2UnitStrc* pTarget)
{
    const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
    const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
    const int nTargetX = CLIENTS_GetUnitXInline(pTarget);
    const int nTargetY = CLIENTS_GetUnitYInline(pTarget);

    int nDirY = 0;
    int nDirX = 0;
    if ((unsigned int)nTargetX > (unsigned int)nUnitX)
    {
        nDirX = -1;
    }
    if ((unsigned int)nTargetX < (unsigned int)nUnitX)
    {
        nDirX = 1;
    }
    if ((unsigned int)nTargetY > (unsigned int)nUnitY)
    {
        nDirY = -1;
    }
    if ((unsigned int)nTargetY < (unsigned int)nUnitY)
    {
        nDirY = 1;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (COLLISION_CheckMaskWithSize(UNITS_GetRoom(pUnit), nDirX + nUnitX, nDirY + nUnitY, 1, PATH_GetFootprintCollisionMask(pPath)))
    {
        return 0;
    }

    D2MonCommandStrc tCommand;
    tCommand.nX = nUnitX + nScale * nDirX;
    tCommand.nY = nUnitY + nScale * nDirY;
    tCommand.nZero = 0;
    tCommand.nPathValue = sub_00648E30_GetPathValue(pPath);
    tCommand.nArg = nArg;
    tCommand.nPathByte = sub_00648EA0_GetPathByte(pPath);
    MONSTER_HandleMonsterCommand(nCommand, pUnit, &tCommand);
    return 1;
}

static void __stdcall sub_0046C960_StepRandom(unsigned char nScale, int nCommand, int nArg, D2UnitStrc* pUnit)
{
    const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
    const int nUnitY = CLIENTS_GetUnitYInline(pUnit);

    int nOffsetX = nScale;
    if (SEED_RollRandomNumber64_Inline(&pUnit->pSeed) & 1)
    {
        nOffsetX = -nOffsetX;
    }

    int nOffsetY = nScale;
    if (SEED_RollRandomNumber64_Inline(&pUnit->pSeed) & 1)
    {
        nOffsetY = -nOffsetY;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2MonCommandStrc tCommand;
    tCommand.nX = nUnitX + nOffsetX;
    tCommand.nY = nUnitY + nOffsetY;
    tCommand.nZero = 0;
    tCommand.nPathValue = sub_00648E30_GetPathValue(pPath);
    tCommand.nArg = nArg;
    tCommand.nPathByte = sub_00648EA0_GetPathByte(pPath);
    MONSTER_HandleMonsterCommand(nCommand, pUnit, &tCommand);
}

// 0x0046CA60
static void __stdcall sub_0046CA60_CommandToXY(int nCommand, int nArg, D2UnitStrc* pUnit, int nY, int nX)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2MonCommandStrc tCommand;
    tCommand.nX = nX;
    tCommand.nY = nY;
    tCommand.nZero = 0;
    tCommand.nPathValue = sub_00648E30_GetPathValue(pPath);
    tCommand.nArg = nArg;
    tCommand.nPathByte = sub_00648EA0_GetPathByte(pPath);
    MONSTER_HandleMonsterCommand(nCommand, pUnit, &tCommand);
}

// 0x0046CAB0
static void sub_0046CAB0_CommandMode8(D2UnitStrc* pUnit)
{
    D2MonCommandStrc tCommand = {};
    tCommand.nX = CLIENTS_GetUnitXInline(pUnit);
    tCommand.nY = CLIENTS_GetUnitYInline(pUnit);
    MONSTER_HandleMonsterCommand(8, pUnit, &tCommand);
}

// 0x0046CB40
static void sub_0046CB40_CommandMode7(D2UnitStrc* pUnit)
{
    D2MonCommandStrc tCommand = {};
    tCommand.nX = CLIENTS_GetUnitXInline(pUnit);
    tCommand.nY = CLIENTS_GetUnitYInline(pUnit);
    MONSTER_HandleMonsterCommand(7, pUnit, &tCommand);
}

// 0x0046CBD0
static void sub_0046CBD0_SetAiTimerClamped(D2UnitStrc* pUnit, int nTicks)
{
    if (nTicks >= 200)
    {
        nTicks = 200;
    }

    int* pTimer = sub_004AE110_GetAiTimer(pUnit);
    if (pTimer)
    {
        *pTimer = nTicks;
    }
}

// 0x0046CBF0
static int sub_0046CBF0_IsSamePosition(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
    const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
    const int nTargetX = CLIENTS_GetUnitXInline(pTarget);
    const int nTargetY = CLIENTS_GetUnitYInline(pTarget);
    if (nUnitX == nTargetX && nUnitY == nTargetY)
    {
        return 1;
    }

    return 0;
}

// 0x0046CCD0
static void sub_0046CCD0_AiType1(D2UnitStrc* pUnit)
{
    if (AI_GetUnitMode_Inline(pUnit) == 1)
    {
        D2UnitStrc* pFound = 0;
        int nDistance = 0x7FFFFFFF;
        sub_0046C570_FindRoomUnit(pUnit, &pFound, &nDistance, sub_0046C600_CheckTarget);
        if (pFound)
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            PATH_SetFootprintCollisionMask(pPath, 0x3C01);
            if (nDistance < 4)
            {
                PATH_SetFootprintCollisionMask(pPath, 0xC01);
                if (!sub_0046C7D0_StepAwayFromUnit(pUnit, 4, 0xC, 0x78, pFound))
                {
                    sub_0046C960_StepRandom(4, 0xC, 0x78, pUnit);
                }
                return;
            }

            if (SEED_RollPercentage_Inline(&pUnit->pSeed) < 30)
            {
                sub_0046C960_StepRandom(2, 1, 0, pUnit);
                return;
            }

            AI_SetTimer_Inline(pUnit, 5);
        }
    }
}

// 0x0046CDC0
static void __stdcall sub_0046CDC0_AiType2(D2UnitStrc* pTarget, unsigned int nDistance, D2UnitStrc* pUnit)
{
    if (AI_GetUnitMode_Inline(pUnit) == 1)
    {
        if (nDistance < 5)
        {
            if (SEED_RollPercentage_Inline(&pUnit->pSeed) < 66)
            {
                sub_0046C7D0_StepAwayFromUnit(pUnit, 8, 1, 30, pTarget);
            }
            else
            {
                sub_0046C960_StepRandom(12, 1, 30, pUnit);
            }
        }
        else
        {
            sub_0046C960_StepRandom(9, 1, 0, pUnit);
        }
    }
}

static void sub_0046CE40_AiType3(D2UnitStrc* pUnit)
{
    if (AI_GetUnitMode_Inline(pUnit) == 1)
    {
        int* pState = MONSTER_GetAiValuePtr(pUnit);
        if (pState)
        {
            D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
            const int nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pPlayer);
            if (*pState && nDistance > 25)
            {
                sub_00465F00_RemoveClientUnit(pUnit->dwUnitId, 1);
                return;
            }

            *pState = 1;

            int nOffsetX;
            int nOffsetY;
            if (SEED_RollRandomNumber64_Inline(&pUnit->pSeed) & 1)
            {
                nOffsetY = SEED_RollRandomNumber64_Inline(&pUnit->pSeed) % 40;
                nOffsetX = 40;
            }
            else
            {
                nOffsetX = SEED_RollRandomNumber64_Inline(&pUnit->pSeed) % 40;
                nOffsetY = 40;
            }

            if (SEED_RollRandomNumber64_Inline(&pUnit->pSeed) & 1)
            {
                nOffsetX = -nOffsetX;
            }

            if (SEED_RollRandomNumber64_Inline(&pUnit->pSeed) & 1)
            {
                nOffsetY = -nOffsetY;
            }

            const int nTargetX = CLIENTS_GetUnitXInline(pPlayer) + nOffsetX;
            const int nTargetY = CLIENTS_GetUnitYInline(pPlayer) + nOffsetY;
            const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
            const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
            PATH_SetNewDistance(pUnit->pDynamicPath, 90);
            sub_0046CA60_CommandToXY(1, 0, pUnit, 3 * nTargetY - 2 * nUnitY, 3 * nTargetX - 2 * nUnitX);
        }
    }
}

// 0x0046D070
static void __stdcall sub_0046D070_AiType4(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    const int nMode = AI_GetUnitMode_Inline(pUnit);
    if (MONSTERS_IsDead(pUnit))
    {
        return;
    }

    if (sub_0046CBF0_IsSamePosition(pTarget, pUnit))
    {
        sub_0046CAB0_CommandMode8(pUnit);
        return;
    }

    if (nMode == 1)
    {
        if (SEED_RollPercentage_Inline(&pUnit->pSeed) < 40)
        {
            AI_SetTimer_Inline(pUnit, 20);
            sub_0046CB40_CommandMode7(pUnit);
            return;
        }

        sub_0046C960_StepRandom(4, 1, 0, pUnit);
    }
}

void __stdcall sub_0046D110_AiType5(unsigned int nDistance, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x0046D110

// 0x0046D280
static void __stdcall sub_0046D280_AiType6(unsigned int nDistance, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (MONSTERS_IsDead(pUnit))
    {
        return;
    }

    if (sub_0046CBF0_IsSamePosition(pTarget, pUnit))
    {
        sub_0046CAB0_CommandMode8(pUnit);
        return;
    }

    if (AI_GetUnitMode_Inline(pUnit) == 1)
    {
        if (nDistance <= 1)
        {
            sub_0046C7D0_StepAwayFromUnit(pUnit, 4, 1, 0, pTarget);
            return;
        }

        const int nRoll = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100);
        if (nRoll < 75)
        {
            AI_SetTimer_Inline(pUnit, 32);
            sub_0046CB40_CommandMode7(pUnit);
            return;
        }

        sub_0046C960_StepRandom(4, 1, 0, pUnit);
    }
}

// 0x0046D310
static void sub_0046D310_AiType7(D2UnitStrc* pUnit)
{
    if (AI_GetUnitMode_Inline(pUnit) == 1)
    {
        if (COLLISION_CheckMask(UNITS_GetRoom(pUnit), CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0x1C0))
        {
            sub_0046CAB0_CommandMode8(pUnit);
            return;
        }

        D2UnitStrc* pFound = 0;
        int nDistance = 0x7FFFFFFF;
        sub_0046C570_FindRoomUnit(pUnit, &pFound, &nDistance, sub_0046C600_CheckTarget);
        if (pFound)
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            PATH_SetFootprintCollisionMask(pPath, 0x3C01);
            if (nDistance < 6)
            {
                PATH_SetFootprintCollisionMask(pPath, 0xC01);
                if (!sub_0046C7D0_StepAwayFromUnit(pUnit, 6, 1, 0x78, pFound))
                {
                    sub_0046C960_StepRandom(6, 1, 0x78, pUnit);
                }
                return;
            }

            const int nRoll = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100);
            if (nRoll < 30)
            {
                sub_0046C960_StepRandom(2, 1, 0, pUnit);
                return;
            }

            AI_SetTimer_Inline(pUnit, 5);
        }
    }
}

static void sub_0046D450_AiType8(D2UnitStrc* pUnit)
{
    if (!sub_00463DE0_GetPlayerUnit())
    {
        AI_SetTimer_Inline(pUnit, 5);
        return;
    }

    if (SEED_RollPercentage64_Inline(&pUnit->pSeed) < 5)
    {
        const int nMissileId = (SEED_RollRandomNumber64_Inline(&pUnit->pSeed) & 3) + 0x23A;
        const int nX = CLIENTS_GetUnitXInline(pUnit) + SEED_RollRandomNumber64_Inline(&pUnit->pSeed) % 60 - 30;
        const int nY = CLIENTS_GetUnitYInline(pUnit) + SEED_RollRandomNumber64_Inline(&pUnit->pSeed) % 60 - 30;
        D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pUnit, nMissileId, nX, nY, 0, 1);
        if (pMissile)
        {
            int bFlag;
            if (SEED_RollRandomNumber64_Inline(&pUnit->pSeed) & 1)
            {
                GFXUTIL_SetMotionVectorA(pMissile, 0, 0, -100);
                GFXUTIL_SetMotionVectorB(pMissile, 0, 0, 6, 1);
                GFXUTIL_SetMotionVectorC(pMissile, 0, 0, 300, 1);
                bFlag = 1;
            }
            else
            {
                GFXUTIL_SetMotionVectorA(pMissile, 0, 0, 300);
                GFXUTIL_SetMotionVectorB(pMissile, 0, 0, -6, 1);
                GFXUTIL_SetMotionVectorC(pMissile, 0, 0, -100, 1);
                bFlag = 0;
            }

            GFXUTIL_SetMotionFlagMask(pMissile, bFlag);
            sub_004DA350_UpdateMotion(pMissile);
            MISSILE_SetTotalFrames(pMissile, 60);
            MISSILE_SetCurrentFrame(pMissile, 60);
            MISSILE_SetTargetX(pMissile, 100);
            MISSILE_SetTargetY(pMissile, 300);
        }
    }
}

// 0x0046D660
static void sub_0046D660_AiFlagged(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    const int nMode = AI_GetUnitMode_Inline(pUnit);
    if (MONSTERS_IsDead(pUnit) || nMode != 1)
    {
        return;
    }

    if (!sub_0046C140_CheckMonStats2ModeFlag(!pUnit ? -1 : pUnit->dwClassId, 2))
    {
        AI_SetTimer_Inline(pUnit, 20);
        sub_0046CB40_CommandMode7(pUnit);
        return;
    }

    const int nRoll = SEED_RollPercentage_Inline(&pUnit->pSeed);
    if (nRoll < 40)
    {
        AI_SetTimer_Inline(pUnit, 20);
        sub_0046CB40_CommandMode7(pUnit);
        return;
    }

    if (nRoll < 60 && pTarget)
    {
        sub_0046C770_CommandOnUnit(0, 6, pUnit, pTarget);
        return;
    }

    if (nRoll < 80 && pTarget)
    {
        sub_0046C7D0_StepAwayFromUnit(pUnit, 8, 1, 4, pTarget);
        return;
    }

    sub_0046C960_StepRandom(8, 1, 4, pUnit);
}

void __fastcall sub_0046D780(D2UnitStrc* pUnit)
{
    int* pTimer = sub_004AE110_GetAiTimer(pUnit);
    if (!pTimer)
    {
        return;
    }

    if (*pTimer > 0)
    {
        *pTimer += -1;
        return;
    }

    int nDistance = 0x7FFFFFFF;
    D2UnitStrc* pTarget = sub_0046C720_FindNearestTarget(pUnit, &nDistance);
    if (!pTarget)
    {
        pTarget = sub_00463DD0_GetPlayerUnit();
        if (!pTarget)
        {
            AI_SetTimer_Inline(pUnit, 25);
            sub_0046CB40_CommandMode7(pUnit);
            return;
        }
    }

    if (nDistance > 30)
    {
        sub_0046CBD0_SetAiTimerClamped(pUnit, nDistance - 15);
        sub_0046CB40_CommandMode7(pUnit);
        return;
    }

    if (MONSTERUNIQUE_CheckMonStatsFlag(pUnit->dwClassId, 22))
    {
        sub_0046D660_AiFlagged(pTarget, pUnit);
        return;
    }

    switch (pUnit->dwClassId)
    {
    case 0x95:
    case 0x10C:
        sub_0046CCD0_AiType1(pUnit);
        return;

    case 0x9F:
        sub_0046CDC0_AiType2(pTarget, nDistance, pUnit);
        return;

    case 0x9D:
    case 0x9E:
    case 0x13F:
        sub_0046CE40_AiType3(pUnit);
        return;

    case 0xE3:
        sub_0046D070_AiType4(pTarget, pUnit);
        return;

    case 0x97:
    case 0x10D:
    case 0x11B:
    case 0x153:
        sub_0046D110_AiType5(nDistance, pUnit, pTarget);
        return;

    case 0x13E:
        sub_0046D280_AiType6(nDistance, pUnit, pTarget);
        return;

    case 0x22C:
        sub_0046D310_AiType7(pUnit);
        return;

    case 0x23E:
        sub_0046D450_AiType8(pUnit);
        return;

    case 0x116:
    case 0x117:
    case 0x118:
    case 0x119:
    case 0x11A:
        return;

    case 0x140:
        sub_0046CB40_CommandMode7(pUnit);
        return;
    }

    sub_0046CB40_CommandMode7(pUnit);
}
