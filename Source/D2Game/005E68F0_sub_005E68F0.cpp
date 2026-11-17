struct D2GameStrc;
struct D2DynamicPathStrc;
struct D2MonsterInteractStrc;

enum
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
};

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    void* pAiParamFn;
    unsigned short nAiFlags;
    unsigned char unk0x0A[2];
    int dwOwnerGUID;
    unsigned int dwOwnerType;
    int dwAiParam[3];
};

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
};

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                            // 0x00535060
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract);                              // 0x00572DC0
int __fastcall MONSTERAI_IsInteractingWith(D2MonsterInteractStrc* pMonInteract, D2UnitStrc* pUnit);         // 0x00572DE0
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource);      // 0x005DC380
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                 // 0x005DC5C0
D2UnitStrc* __fastcall sub_6FCCFD70(D2GameStrc* pGame, D2UnitStrc* pUnit, int* bCloseToTarget);             // 0x005DDF20
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback); // 0x005DE6D0
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY);    // 0x005DED90
bool __fastcall sub_005E6860_HomeCommandStep(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, unsigned int nMaxDistance); // 0x005E6860
void __stdcall sub_00648730(D2DynamicPathStrc* pDynamicPath);                                // 0x00648730

// 0x005E68F0
bool __fastcall sub_005E68F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCloseToTarget = 0;
    D2UnitStrc* pTarget = sub_6FCCFD70(pGame, pUnit, &bCloseToTarget);
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);

    const int nType = pUnit ? pUnit->dwUnitType : 6;
    D2MonsterInteractStrc* pMonInteract = nType == UNIT_MONSTER && pUnit->pMonsterData ? pUnit->pMonsterData->pMonInteract : 0;
    if (!pMonInteract)
    {
        return false;
    }

    int bInteracting = MONSTERAI_IsInteractingWith(pMonInteract, pTarget);
    if (pTarget && pTarget->dwUnitType == UNIT_PLAYER && PLAYER_IsBusy(pTarget) == 1)
    {
        bInteracting = 1;
    }

    const int bHasInteractUnit = MONSTERAI_HasInteractUnit(pMonInteract);
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (bHasInteractUnit || bInteracting || pAiControl->dwAiParam[0] > 0)
    {
        if (AIUTIL_GetDistanceToCoordinates(pUnit, pAiControl->dwAiParam[1], pAiControl->dwAiParam[2]) > 2 && pAiControl->dwAiParam[0] > 36)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pAiControl->dwAiParam[1], pAiControl->dwAiParam[2]);
        }
        else if (pAiControl->dwAiParam[0] > 0)
        {
            if (pUnit->pDynamicPath)
            {
                sub_00648730(pUnit->pDynamicPath);
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
        }

        if (pAiControl->dwAiParam[0] < 0)
        {
            pAiControl->dwAiParam[0] = 0;
        }
        else
        {
            --pAiControl->dwAiParam[0];
        }

        return true;
    }

    if (!pTarget || pTarget == pUnit)
    {
        return false;
    }

    if (nDistance >= 3 && nDistance <= 23)
    {
        if (sub_005E6860_HomeCommandStep(pGame, pUnit, pAiTickParam, 16))
        {
            return true;
        }

        AITACTICS_SetVelocity(pUnit, 1, 0, 0);
        if (nDistance >= 5)
        {
            D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 3, 2);
        }
        else
        {
            D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, nDistance - 2, 2);
        }

        return true;
    }

    sub_00648730(pUnit->pDynamicPath);
    if (!pAiControl->dwAiParam[1])
    {
        pAiControl->dwAiParam[1] = 60;
        if (pTarget->dwUnitType == UNIT_PLAYER)
        {
            SUNIT_AttachSound(pUnit, 18, pTarget);
        }
    }
    else
    {
        if (pAiControl->dwAiParam[1] < 0)
        {
            pAiControl->dwAiParam[1] = 0;
        }

        if (pAiControl->dwAiParam[1] > 0)
        {
            --pAiControl->dwAiParam[1];
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
    return true;
}
