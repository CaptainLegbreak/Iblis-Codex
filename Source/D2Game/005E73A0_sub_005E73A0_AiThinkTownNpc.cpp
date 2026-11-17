struct D2GameStrc;
struct D2MonsterInteractStrc;

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1

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
int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract);                             // 0x00572DC0
void __fastcall sub_0059C750_Fn(D2GameStrc* pGame);                                                         // 0x0059C750
int __fastcall sub_0059DF50_Check(D2GameStrc* pGame, D2UnitStrc* pUnit);                                    // 0x0059DF50
int __fastcall sub_005B43F0_Check(D2GameStrc* pGame, D2UnitStrc* pUnit);                                    // 0x005B43F0
void __fastcall sub_005B4440_Fn(D2GameStrc* pGame);                                                         // 0x005B4440
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pUnit, D2UnitStrc* pTarget);        // 0x005DC380
D2UnitStrc* __fastcall sub_6FCCFD70(D2GameStrc* pGame, D2UnitStrc* pUnit, int* bCloseToTarget);             // 0x005DDF20
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall sub_005E7350_Check(D2GameStrc* pGame, D2UnitStrc* pUnit);                                    // 0x005E7350

// 0x005E73A0
void __fastcall sub_005E73A0_AiThinkTownNpc(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCloseToTarget = 0;
    D2UnitStrc* pTarget = sub_6FCCFD70(pGame, pUnit, &bCloseToTarget);
    if (pTarget && pTarget != pUnit)
    {
        const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
        D2MonsterInteractStrc* pMonInteract = pUnit ? (pUnit->dwUnitType == UNIT_MONSTER ? (pUnit->pMonsterData ? pUnit->pMonsterData->pMonInteract : 0) : 0) : 0;
        if (pTarget->dwUnitType == UNIT_PLAYER && PLAYER_IsBusy(pTarget) == 1)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }

        if (MONSTERAI_HasInteractUnit(pMonInteract))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }

        D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
        if (nDistance < 24)
        {
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
                --pAiControl->dwAiParam[1];
            }
        }
        else
        {
            if (pAiControl->dwAiParam[1] <= 0)
            {
                pAiControl->dwAiParam[1] = 60;
            }
            --pAiControl->dwAiParam[1];
        }
    }
    else if (pUnit)
    {
        if (pUnit->dwClassId == 0xFB)
        {
            if (sub_0059DF50_Check(pGame, pUnit) && sub_005E7350_Check(pGame, pUnit))
            {
                AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
                sub_0059C750_Fn(pGame);
                return;
            }
        }
        else if (pUnit->dwClassId == 0x196)
        {
            if (sub_005B43F0_Check(pGame, pUnit) && sub_005E7350_Check(pGame, pUnit))
            {
                AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
                sub_005B4440_Fn(pGame);
                return;
            }
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
}
