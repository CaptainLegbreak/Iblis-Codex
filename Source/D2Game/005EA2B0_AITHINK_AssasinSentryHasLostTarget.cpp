struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
struct D2SkillStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
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

struct D2MonStatsTxt
{
    char unk0x000[0x170];
    short nSkill[8];
    unsigned char nSkillMode[8];
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

struct D2SkillsTxt
{
    char unk0x000[0x048];
    short wSrvMissileA;
    char unk0x04A[0x138 - 0x04A];
    unsigned int dwCalc[4];
    char unk0x148[0x23C - 0x148];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB6C];
    int nMissilesTxtRecordCount;
    char unk0xB70[0xB98 - 0xB70];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit);                                                     // 0x00535BC0
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc* pUnit);                          // 0x0058EE80
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);         // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DEE50
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMaxDistance); // 0x005DF530
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                                     // 0x00621CE0
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker);                                                   // 0x00622560
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                       // 0x00625480
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);               // 0x006272B0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps);                      // 0x00649070

enum D2C_Y11AiConstants
{
    MONMODE_WALK = 2,
    STAT_TOHIT = 0x13,
    STAT_ITEM_TOHIT_PERCENT = 0x77,
};

__forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005EA2B0
int __fastcall AITHINK_AssasinSentryHasLostTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, int bDecreaseParam)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return 1;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOwner);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return 1;
    }

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[1] < 0)
    {
        const int nSkillId = pAiTickParam->pMonstatsTxt->nSkill[0];
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
            return 1;
        }

        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
        if (!pSkill)
        {
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
            return 1;
        }

        const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
        D2AiControlStrc* pAiControlSet = pAiTickParam->pAiControl;
        pAiControlSet->dwAiParam[1] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
    }

    if (pAiControl->dwAiParam[1] > 0)
    {
        if (bDecreaseParam)
        {
            pAiControl->dwAiParam[1] -= 1;
        }
        return 0;
    }

    AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
    return 1;
}

// 0x005EA540
void __fastcall AITHINK_Fn102_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nSkillId = pAiTickParam->pMonstatsTxt->nSkill[0];
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    if (pAiControl->dwAiParam[0] < 0)
    {
        pAiControl->dwAiParam[0] = pGame->dwGameFrame + SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
    }

    if (pAiControl->dwAiParam[0] < pGame->dwGameFrame)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    if (!pAiControl->dwAiParam[2])
    {
        if (pSkillsTxtRecord->wSrvMissileA >= 0 && pSkillsTxtRecord->wSrvMissileA < sgptDataTables->nMissilesTxtRecordCount)
        {
            D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
            if (!pOwner)
            {
                pOwner = pUnit;
            }

            D2UnitStrc* pMissile = D2GAME_CreateMissile_6FD115E0(pGame, pOwner, nSkillId, nSkillLevel, pSkillsTxtRecord->wSrvMissileA, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
            if (pMissile)
            {
                UNITS_StoreOwner(pMissile, pUnit);
                const int nAttackRate = UNITS_GetAttackRate(pOwner);
                STATLIST_AddUnitStat(pUnit, STAT_TOHIT, nAttackRate, 0);

                int nToHitPercent = STATLIST_UnitGetStatValue(pOwner, STAT_ITEM_TOHIT_PERCENT, 0);
                D2UnitStrc* pWeapon = sub_6FC7C7B0(pOwner);
                if (pWeapon)
                {
                    nToHitPercent += SKILLS_GetWeaponMasteryBonus(pOwner, pWeapon, 0, 0);
                }

                STATLIST_AddUnitStat(pUnit, STAT_ITEM_TOHIT_PERCENT, nToHitPercent, 0);
            }

            pAiControl->dwAiParam[2] = 1;
        }
    }

    D2AiCmdStrc* pAiCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (!pAiCmd)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 3);
        return;
    }

    AITACTICS_SetVelocity(pUnit, 15, 0, 20);

    if (pAiControl->dwAiParam[1])
    {
        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[3], pAiCmd->nCmdParam[4]))
        {
            return;
        }

        pAiControl->dwAiParam[1] = (pAiControl->dwAiParam[1] == 0);

        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]))
        {
            return;
        }
    }
    else
    {
        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]))
        {
            return;
        }

        pAiControl->dwAiParam[1] = (pAiControl->dwAiParam[1] == 0);

        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[3], pAiCmd->nCmdParam[4]))
        {
            return;
        }
    }

    D2UnitStrc* pWalkOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pWalkOwner, 5))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
    }
}

// 0x005ECBC0
void __fastcall sub_005ECBC0_RavenWalkToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char a4, int a2)
{
    AITACTICS_SetVelocity(pUnit, a2, 0, a4);
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_WALK, &modeChange);
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    modeChange.pTargetUnit = pTarget;
    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}
