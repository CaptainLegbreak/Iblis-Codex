enum D2C_Y10AiThinkConstants
{
    MONSTER_JERHYN = 201,
    MONSTER_ALKOR = 254,
    MONSTER_ORMUS = 255,
    MONSTER_CAIN5 = 265,
    MONSTER_DREHYA = 512,
    MONMODE_SKILL1 = 8,
};

struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

struct D2AiTickParamStrc;

bool __fastcall sub_005E6800_InitHomeCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E6800
bool __fastcall sub_005E68F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam);       // 0x005E68F0
bool __fastcall sub_6FCE69A0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam);       // 0x005E6AE0
bool __fastcall AITHINK_ExecuteMapAiAction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E7080
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY);    // 0x005DED90
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                // 0x005DC5C0
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall ACT3Q3_GetAltarCoordinates(D2GameStrc* pGame, D2CoordStrc* pCoord);                         // 0x005B9CA0
void __fastcall ACT3Q3_SetAltarMode(D2GameStrc* pGame);                                                     // 0x005B9CD0
int __fastcall ACT2Q4_IsJerhynPalaceActivated(D2GameStrc* pGame);                                           // 0x0059F570
void __fastcall ACT2Q4_GetAndUpdatePalaceNpcState(D2GameStrc* pGame, D2UnitStrc* pUnit, int* a3, int* pIdle); // 0x0059F580
int __fastcall ACT2Q4_IsGuardMoving(D2GameStrc* pGame, D2UnitStrc* pUnit);                                  // 0x0059B6E0
int __fastcall ACT3Q4_GoldenBirdBroughtToAlkor(D2GameStrc* pGame);                                          // 0x005BAD20
void __fastcall ACT3Q4_ResetAlkor(D2GameStrc* pGame);                                                       // 0x005BAD40
int __fastcall ACT1Q4_GetCainPortalInTownCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00594360
void __fastcall ACT1Q4_OnCainInTownActivated(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x005945F0
void __fastcall ACT5Q4_AnyaOpenPortal(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x0058BC80

// 0x005E7130
void __fastcall AITHINK_Fn032_Npc(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2CoordStrc coord;
    int a3;
    int a4;

    if (sub_005E6800_InitHomeCommand(pGame, pUnit, pAiTickParam))
    {
        return;
    }

    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    switch (nClassId)
    {
    case MONSTER_ORMUS:
    {
        if (ACT3Q3_GetAltarCoordinates(pGame, &coord))
        {
            if (AIUTIL_GetDistanceToCoordinates(pUnit, coord.nX, coord.nY) > 3)
            {
                AITACTICS_WalkToTargetCoordinates(pGame, pUnit, coord.nX, coord.nY);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_SKILL1, 0, 0);
                ACT3Q3_SetAltarMode(pGame);
            }
            return;
        }
        break;
    }
    case MONSTER_JERHYN:
    {
        if (!ACT2Q4_IsJerhynPalaceActivated(pGame))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 40);
            return;
        }

        ACT2Q4_GetAndUpdatePalaceNpcState(pGame, pUnit, &a3, &a4);
        if (a4)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        }

        if (!a3)
        {
            return;
        }

        if (ACT2Q4_IsGuardMoving(pGame, pUnit))
        {
            D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 10, 0);
            if (pAiCmd)
            {
                pAiCmd->nCmdParam[1] = CLIENTS_GetUnitX(pUnit) + 9;
                pAiCmd->nCmdParam[2] = CLIENTS_GetUnitY(pUnit);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
                return;
            }
        }
        break;
    }
    case MONSTER_ALKOR:
    {
        if (ACT3Q4_GoldenBirdBroughtToAlkor(pGame))
        {
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_SKILL1, 0, 0);
            ACT3Q4_ResetAlkor(pGame);
            return;
        }
        break;
    }
    case MONSTER_CAIN5:
    {
        if (ACT1Q4_GetCainPortalInTownCoordinates(pGame, pUnit, &coord))
        {
            if (AIUTIL_GetDistanceToCoordinates(pUnit, coord.nX, coord.nY) > 2)
            {
                AITACTICS_WalkToTargetCoordinates(pGame, pUnit, coord.nX, coord.nY);
                return;
            }

            ACT1Q4_OnCainInTownActivated(pGame, pUnit);
        }
        break;
    }
    case MONSTER_DREHYA:
    {
        ACT5Q4_AnyaOpenPortal(pGame, pUnit);
        break;
    }
    default:
        break;
    }

    if (!sub_005E68F0(pGame, pUnit, pAiTickParam) && !sub_6FCE69A0(pGame, pUnit, pAiTickParam) && !AITHINK_ExecuteMapAiAction(pGame, pUnit, pAiTickParam))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
    }
}
