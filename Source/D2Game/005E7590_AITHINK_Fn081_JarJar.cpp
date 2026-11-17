struct D2CoordStrc
{
    int nX;
    int nY;
};

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
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

struct D2AiTickParamStrc;

enum D2C_M76AiConstants
{
    UNIT_PLAYER = 0,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet);         // 0x0058EEF0
int __fastcall ACT2Q4_IsHaremBlockerObjectOpened(D2GameStrc* pGame);                                        // 0x0059AEC0
int __fastcall ACT2Q4_HasGuardMovedToEndPosition(D2GameStrc* pGame);                                        // 0x0059B8B0
int __fastcall ACT2Q4_GetGuardCoordinates(D2GameStrc* pGame, D2CoordStrc* pCoord);                          // 0x0059B8F0
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource);      // 0x005DC380
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                 // 0x005DC5C0
D2UnitStrc* __fastcall sub_6FCCFD70(D2GameStrc* pGame, D2UnitStrc* pUnit, int* bCloseToTarget);             // 0x005DDF20
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMaxDistance);         // 0x005DE200
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY);    // 0x005DED90
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMaxDistance); // 0x005DF530
bool __fastcall sub_005E6800_InitHomeCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E6800
bool __fastcall sub_005E68F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam);       // 0x005E68F0

// 0x005E7590
void __fastcall AITHINK_Fn081_JarJar(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (sub_005E6800_InitHomeCommand(pGame, pUnit, pAiTickParam))
    {
        return;
    }

    D2AiCmdStrc* pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!ACT2Q4_HasGuardMovedToEndPosition(pGame))
    {
        D2CoordStrc coords;
        coords.nX = pAiCmd->nCmdParam[1];
        coords.nY = pAiCmd->nCmdParam[2];

        int bFree = 1;
        if (ACT2Q4_GetGuardCoordinates(pGame, &coords))
        {
            bFree = 0;
        }

        if (pAiCmd->nCmdParam[4] < pGame->dwGameFrame && pGame->dwGameFrame - pAiCmd->nCmdParam[4] < 200)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            return;
        }

        if (AIUTIL_GetDistanceToCoordinates(pUnit, coords.nX, coords.nY) > 1)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, coords.nX, coords.nY);
            pAiCmd->nCmdParam[4] = pGame->dwGameFrame;
            return;
        }

        if (bFree)
        {
            if (sub_005E68F0(pGame, pUnit, pAiTickParam))
            {
                pAiCmd->nCmdParam[4] = pGame->dwGameFrame;
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            }
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        }
        return;
    }

    if (pAiCmd)
    {
        int bCloseToTarget;
        D2UnitStrc* pOwner = sub_6FCCFD70(pGame, pUnit, &bCloseToTarget);
        const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
        if (ACT2Q4_IsHaremBlockerObjectOpened(pGame) && AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3) > 2)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3);
            return;
        }

        if (AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3) > 7)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3);
            return;
        }

        if (!sub_005E68F0(pGame, pUnit, pAiTickParam) && pOwner && pOwner != pUnit)
        {
            if (pOwner->dwUnitType == UNIT_PLAYER)
            {
                if (nDistance < 12)
                {
                    if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 1000) < 100)
                    {
                        D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pOwner, 2);
                    }

                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 200);
                    return;
                }

                AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            }

            if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 1000) < 50)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 3);
            }
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 120);
}
