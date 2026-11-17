extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2StatListStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x10];
    D2SeedStrc pSeed;
    char unk0x28[4];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    char unk0x04[0x10];
    int dwAiParam[3];
};

struct D2MonStatsTxt
{
    char unk0x00[0x56];
    short wAiParam[8][3];
};

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
};

typedef int(__fastcall* UNITFINDTEST)(D2UnitStrc* pUnit);

struct D2UnitFindArgStrc
{
    int nFlags; int unk0x04; D2UnitStrc* pUnit; int nX; int nY; int nSize; int nMaxArrayEntries; int nIndex;
    void* pField; void* pfnUnitTest; int unk0x28; int unk0x2C; int unk0x30; int unk0x34;
};

struct D2UnitFindDataStrc
{
    void* pMemPool; D2UnitStrc** pUnitsArray; D2ActiveRoomStrc* pRoom; void* pfnUnitTest; D2UnitFindArgStrc* pUnitFindArg;
    int nFlags; int nIndex; int nMaxArrayEntries; int nX; int nY; int nSize;
};

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C390
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam); // 0x005417D0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue);             // 0x0058EC00
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                         // 0x005B0BD0
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                 // 0x005DC5C0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMaxDistance);         // 0x005DE200
int __fastcall AITACTICS_ChangeModeAndTargetCoordinatesNoStep(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nMode); // 0x005DE490
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall sub_005F3960_IsMonster76Alive(D2UnitStrc* pUnit);                                            // 0x005F3960
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall sub_006260B0(D2StatListStrc* pStatList, int nExpireFrame);                                 // 0x006260B0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, UNITFINDTEST pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData);                               // 0x0065AA00
void __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData);          // 0x0065AC70

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline int UNITS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int UNITS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005F39B0
void __fastcall sub_005F39B0_Think(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    int nApproachOffsets[7][4][2] =
    {
        { { -10, -3 }, { 1, -5 }, { 6, 0 }, { 4, 10 } },
        { { -9, -2 }, { -6, -11 }, { -2, -5 }, { 6, 1 } },
        { { 0, 13 }, { -12, 0 }, { 7, 5 }, { -3, -11 } },
        { { -15, -3 }, { -6, -3 }, { -4, -5 }, { -6, -13 } },
        { { -12, -2 }, { -6, 2 }, { -5, 5 }, { 1, 11 } },
        { { -13, -6 }, { -8, -11 }, { -7, 0 }, { 1, 8 } },
        { { -5, -8 }, { -8, 1 }, { 1, -6 }, { 6, 9 } },
    };
    int nCastOffsets[7][4][2] =
    {
        { { 1, -5 }, { 6, 0 }, { 4, 10 }, { -10, -3 } },
        { { 1, 8 }, { -9, -2 }, { -5, 4 }, { 1, 8 } },
        { { -12, 0 }, { 7, 5 }, { -3, -11 }, { 11, -2 } },
        { { 7, 9 }, { -15, -3 }, { -6, -13 }, { 9, 7 } },
        { { -5, -7 }, { -5, -7 }, { 9, 0 }, { -12, -2 } },
        { { -8, -11 }, { -2, -6 }, { -2, -6 }, { -13, -6 } },
        { { -8, 1 }, { 1, -6 }, { 6, 9 }, { 0, 0 } },
    };
    int nCircleApproachOffsets[5][2] = { { -5, -5 }, { 3, -5 }, { 6, 3 }, { 3, 6 }, { -5, 3 } };
    int nCircleCastOffsets[5][2] = { { 6, 3 }, { 3, 6 }, { -5, 3 }, { -5, -5 }, { 3, -5 } };

    if (pTarget && pGame->dwGameFrame > pAiControl->dwAiParam[2] && AITHINK_GetSquaredDistance(pUnit, pTarget) < 1024
        && pAiControl->dwAiParam[0] < 4 && SEED_RollLimitedRandomNumber(pSeed, 1000) <= pGame->nDifficulty + 2)
    {
        pAiControl->dwAiParam[0] = 4;
    }

    if (pAiControl->dwAiParam[0] == 4)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        const int nX = UNITS_GetUnitXInline(pUnit);
        const int nY = UNITS_GetUnitYInline(pUnit);

        D2UnitFindArgStrc unitFindArg;
        memset(&unitFindArg, 0, sizeof(unitFindArg));
        unitFindArg.nX = nX;
        unitFindArg.nY = nY;
        unitFindArg.nFlags = 0x583;
        unitFindArg.nSize = 32;

        D2UnitFindDataStrc unitFindData;
        UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, pRoom, nX, nY, 32, sub_005F3960_IsMonster76Alive, &unitFindArg);
        UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

        if (unitFindData.nIndex == 4)
        {
            for (int i = 0; i < 4; ++i)
            {
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 1, 6);
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 2, 0);
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 3, i + 1);
                AITACTICS_IdleInNeutralMode(pGame, unitFindData.pUnitsArray[i], 337 - pGame->dwGameFrame % 337);
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);
            UNITFINDS_FreeUnitFindData(&unitFindData);
            return;
        }

        if (unitFindData.nIndex == 5)
        {
            for (int i = 0; i < 5; ++i)
            {
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 1, 5);
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 2, 0);
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 3, i + 1);
                AITACTICS_IdleInNeutralMode(pGame, unitFindData.pUnitsArray[i], 337 - pGame->dwGameFrame % 337);
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);
            UNITFINDS_FreeUnitFindData(&unitFindData);
            return;
        }

        pAiControl->dwAiParam[0] = 2;
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
        UNITFINDS_FreeUnitFindData(&unitFindData);
        return;
    }

    if (pAiControl->dwAiParam[0] >= 6)
    {
        if (pAiControl->dwAiParam[2] > 4)
        {
            pAiControl->dwAiParam[0] = 2;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
            return;
        }

        const int nX = CLIENTS_GetUnitX(pTarget) + nApproachOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][0];
        const int nY = CLIENTS_GetUnitY(pTarget) + nApproachOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][1];
        if (AIUTIL_GetDistanceToCoordinates(pUnit, nX, nY) > 3)
        {
            if (SEED_RollLimitedRandomNumber(pSeed, 100) < 34)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
                return;
            }

            AITACTICS_ChangeModeAndTargetCoordinatesNoStep(pGame, pUnit, nX, nY, 2);
            return;
        }

        if (pGame->dwGameFrame % 67)
        {
            goto lIdleS6Test;
        }

        if (pAiControl->dwAiParam[1] < 3)
        {
            if (!nCastOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][0] && !nCastOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][1])
            {
                ++pAiControl->dwAiParam[1];
                goto lIdleS6Zero;
            }

            const int nCastX = CLIENTS_GetUnitX(pTarget) + nCastOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][0];
            const int nCastY = CLIENTS_GetUnitY(pTarget) + nCastOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][1];
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 7, nCastX, nCastY);
            ++pAiControl->dwAiParam[1];
            return;
        }

        ++pAiControl->dwAiParam[0];
        pAiControl->dwAiParam[1] = 0;
        if (pAiControl->dwAiParam[0] - 6 > 6)
        {
            pAiControl->dwAiParam[0] = 2;
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + 1800;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);

        if (pTarget && pTarget->dwUnitType == 0 && !SUNIT_IsDead(pTarget))
        {
            const int nExpireFrame = pGame->dwGameFrame + 1728000;
            D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, !pTarget ? 6 : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId);
            if (pStatList)
            {
                STATLIST_SetStatIfListIsValid(pStatList, 80, 50 * (pGame->nDifficulty + 1), 0);
                sub_006260B0(pStatList, nExpireFrame);
                sub_005417D0_DirectDated(pGame, pTarget, 12, nExpireFrame, 0, 0);
                D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
            }
        }
        return;
    }

    if (pAiControl->dwAiParam[0] == 5)
    {
        if (pAiControl->dwAiParam[2] > 5)
        {
            pAiControl->dwAiParam[0] = 2;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
            return;
        }

        {
            const int nX = nCircleApproachOffsets[pAiControl->dwAiParam[2] - 1][0] + CLIENTS_GetUnitX(pTarget);
            const int nY = nCircleApproachOffsets[pAiControl->dwAiParam[2] - 1][1] + CLIENTS_GetUnitY(pTarget);
            if (AIUTIL_GetDistanceToCoordinates(pUnit, nX, nY) > 3)
            {
                if (SEED_RollLimitedRandomNumber(pSeed, 100) < 34)
                {
                    AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
                    return;
                }

                AITACTICS_ChangeModeAndTargetCoordinatesNoStep(pGame, pUnit, nX, nY, 2);
                return;
            }
        }

        if (pGame->dwGameFrame % 67)
        {
            goto lIdleS5Test;
        }

        if (pAiControl->dwAiParam[1] < 3)
        {
            if (!nCircleCastOffsets[pAiControl->dwAiParam[2] - 1][0] && !nCircleCastOffsets[pAiControl->dwAiParam[2] - 1][1])
            {
                ++pAiControl->dwAiParam[1];
                goto lIdleS5Zero;
            }

            {
                const int nCastX = CLIENTS_GetUnitX(pTarget) + nCircleCastOffsets[pAiControl->dwAiParam[2] - 1][0];
                const int nCastY = CLIENTS_GetUnitY(pTarget) + nCircleCastOffsets[pAiControl->dwAiParam[2] - 1][1];
                AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 7, nCastX, nCastY);
            }
            ++pAiControl->dwAiParam[1];
            return;
        }

        pAiControl->dwAiParam[0] = 2;
        pAiControl->dwAiParam[2] = pGame->dwGameFrame + 1800;
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);
        return;

lIdleS6Test:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 67 - pGame->dwGameFrame % 67);
        return;
lIdleS6Zero:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 67 - pGame->dwGameFrame % 67);
        return;
lIdleS5Test:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 67 - pGame->dwGameFrame % 67);
        return;
lIdleS5Zero:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);
        return;
    }

    if (pAiControl->dwAiParam[0] == 1)
    {
        if (pAiControl->dwAiParam[1] <= 0)
        {
            if (bCombat)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 8, 0);
                pAiControl->dwAiParam[0] = 3;
                return;
            }

            if (SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 8, 0);
                pAiControl->dwAiParam[0] = 2;
                return;
            }
        }

        --pAiControl->dwAiParam[1];
        if (SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
        {
            pAiControl->dwAiParam[0] = 1;
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }

        pAiControl->dwAiParam[0] = 1;
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 6);
        return;
    }

    if (!bCombat && (pAiControl->dwAiParam[0] == 2 || SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 0)))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 7, pTarget);
        pAiControl->dwAiParam[0] = 0;
        return;
    }

    if (bCombat && (pAiControl->dwAiParam[0] == 3 || SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 1)))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
        pAiControl->dwAiParam[0] = 0;
        return;
    }

    if (SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        pAiControl->dwAiParam[1] = 3;
        return;
    }

    pAiControl->dwAiParam[0] = 1;
    AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
    pAiControl->dwAiParam[1] = 3;
}
