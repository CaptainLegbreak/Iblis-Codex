enum D2C_F41AiThinkConstants
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_ALIGNMENT_EVIL = 0,
    MONMODE_ATTACK1 = 4,
    MONMODE_SKILL1 = 8,
    MONMODE_SKILL2 = 9,
    MONMODE_NEUTRAL = 1,
    STATE_INFERNO = 12,
    EVENTTYPE_AITHINK = 2,
    UNITFLAG_NOTC = 0x20000,
    MONSTER_EVILHUT = 528,
    SKILL_NEST = 167,
};

struct D2ActiveRoomStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    char unk0x04[0x10];
    int dwAiParam[3];
    char unk0x20[0x1C];
    int nMinionSpawnClassId;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    D2AiControlStrc* pAiControl;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0xAC];
    unsigned int dwFlags;
};

struct D2MonStatsTxt
{
    char unk0x000[0x56];
    short wAiParam[8][3];
    char unk0x086[0xEA];
    short nSkill[8];
    unsigned char nSkillMode[8];
    char unk0x188[0x20];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

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

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

struct D2MapAIPathPositionStrc
{
    int nMapAIAction;
    int nX;
    int nY;
};

struct D2HighPriestAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nLifePercentage;
    int nMaxDistance;
};

struct D2SiegeBeastTowerAiCallbackArgStrc
{
    int nMaxDistance;
    int unk0x04;
    int unk0x08[8];
};

struct D2MinionSpawnerAiCallbackArgStrc
{
    int nMinions;
    int unk0x04[10];
};

struct D2PetMoveStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nCounter;
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

int __stdcall MONSTERS_IsDead(D2UnitStrc* pUnit);                                                           // 0x0063EA40
int __stdcall STATLIST_AreUnitsAligned(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                             // 0x00650D70
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                         // 0x005B0BD0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                           // 0x00621F20
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
int __fastcall AITACTICS_UseSequenceSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTargetUnit, int nX, int nY); // 0x005DE000
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
D2UnitStrc* __fastcall AITHINK_TargetCallback_SiegeBeast(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E1720
void __fastcall sub_005E17E0_SiegeBeastSetTower(D2UnitStrc* pUnit, D2UnitStrc* pTower);                     // 0x005E17E0
D2UnitStrc* __fastcall AITHINK_TargetCallback_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E2B70
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource);      // 0x005DC380
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall sub_005E4830(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam);       // 0x005E4830
void __fastcall sub_005E4AC0_NecroPetFollowOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E4AC0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
bool __fastcall sub_005E6020_SelectGenericSpawnClass(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pClassId);  // 0x005E6020
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                        // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall sub_6FC68350(int nMonsterId, D2ActiveRoomStrc* pRoom, int nX, int nY, int a5);              // 0x005FD350
bool __fastcall sub_6FCE61E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition); // 0x005E6DE0
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int nMonsterId, int nMode);                              // 0x0046C140

// 0x005E0430
D2UnitStrc* __fastcall AITHINK_TargetCallback_HighPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2HighPriestAiCallbackArgStrc* pArg = (D2HighPriestAiCallbackArgStrc*)pCallbackArg;
    if (!pTarget || pTarget->dwUnitType != UNIT_MONSTER || MONSTERS_IsDead(pTarget) || !STATLIST_AreUnitsAligned(pUnit, pTarget) || STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL)
    {
        return 0;
    }

    if (AITHINK_GetSquaredDistance(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pTarget);
    if (nLifePercentage > 75 || nLifePercentage >= pArg->nLifePercentage)
    {
        return 0;
    }

    pArg->nLifePercentage = nLifePercentage;
    pArg->pTarget = pTarget;
    return 0;
}

// 0x005E0F60
void __fastcall AITHINK_Fn093_ArcaneTower(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[1])
    {
        pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[0][pGame->nDifficulty];
    }

    if (pGame->dwGameFrame < pAiControl->dwAiParam[2])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[0])
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        --pAiControl->dwAiParam[1];
        if (pAiControl->dwAiParam[1] <= 0)
        {
            pAiControl->dwAiParam[0] = 1;
            pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[3][pGame->nDifficulty];
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[2][pGame->nDifficulty];
        }
        else
        {
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[1][pGame->nDifficulty];
        }
    }
    else
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        --pAiControl->dwAiParam[1];
        if (pAiControl->dwAiParam[1] <= 0)
        {
            pAiControl->dwAiParam[0] = 0;
            pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[0][pGame->nDifficulty];
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[4][pGame->nDifficulty];
        }
        else
        {
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[5][pGame->nDifficulty];
        }
    }
}

// 0x005E1860
void __fastcall AITHINK_Fn113_SiegeTower(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        if (pTarget)
        {
            D2SiegeBeastTowerAiCallbackArgStrc arg;
            arg.nMaxDistance = 400;
            arg.unk0x04 = 0;
            D2UnitStrc* pBeast = sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_SiegeBeast, 1);
            if (pBeast)
            {
                sub_005E17E0_SiegeBeastSetTower(pBeast, pUnit);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[0][pGame->nDifficulty]);
            }
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[0][pGame->nDifficulty]);
}

// build: context AITHINK_Fn121_MinionSpawner
void __fastcall AITHINK_Fn121_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiControl->dwAiParam[1] >= pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        return;
    }

    if (pAiTickParam->nTargetDistance > pMonStatsTxt->wAiParam[3][pGame->nDifficulty])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
        return;
    }

    if (pGame->dwGameFrame < pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
        return;
    }

    D2MinionSpawnerAiCallbackArgStrc arg;
    arg.nMinions = 0;
    sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_MinionSpawner, 1);
    if (pMonStatsTxt->nSkill[0] >= 0 && arg.nMinions < pMonStatsTxt->wAiParam[1][pGame->nDifficulty])
    {
        pAiControl->dwAiParam[0] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[2][pGame->nDifficulty];
        ++pAiControl->dwAiParam[1];
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
}

// 0x005E3900
void __fastcall sub_6FCE34B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2PetMoveStrc* pArg = (D2PetMoveStrc*)pCallbackArg;
    if (pArg->pUnit == pTarget)
    {
        return;
    }

    if (AIUTIL_GetDistanceToCoordinates_FullUnitSize(pArg->pUnit, pTarget) > 1)
    {
        return;
    }

    pArg->nCounter += 1;
    pArg->pTarget = pTarget;
}

// 0x005E4CF0
void __fastcall AITHINK_Fn067_NecroPet(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    if (pAiTickParam->pAiControl->dwAiParam[0] != 0)
    {
        sub_005E4AC0_NecroPetFollowOwner(pGame, pUnit, pAiTickParam);
    }
    else
    {
        sub_005E4830(pGame, pUnit, pAiTickParam);
    }
}

// 0x005E5280
void __fastcall D2GAME_AI_SpecialState04_6FCDC170(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, pAiControl->nAiSpecialState);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

// 0x005E61B0
void __fastcall AITHINK_Fn129_GenericSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        return;
    }

    if (pAiControl->nMinionSpawnClassId == -1 && !sub_005E6020_SelectGenericSpawnClass(pGame, pUnit, &pAiControl->nMinionSpawnClassId))
    {
        if (pUnit)
        {
            pUnit->dwFlags |= UNITFLAG_NOTC;
        }

        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    if (nTargetDistance > 20)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        return;
    }

    if (pAiControl->dwAiParam[1] >= pMonStatsTxt->wAiParam[2][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= UNITFLAG_NOTC;
        }

        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    int nDiff = pGame->dwGameFrame - pAiControl->dwAiParam[0];
    if (nDiff < 0)
    {
        nDiff = -nDiff;
    }

    if (nDiff >= pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        pAiControl->dwAiParam[0] = pGame->dwGameFrame;
        const int nMonsterId = MONSTER_EVILHUT >= sgptDataTables->nMonStatsTxtRecordCount ? -1 : MONSTER_EVILHUT;
        if (sub_6FC68350(nMonsterId, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0))
        {
            ++pAiControl->dwAiParam[1];
            AITACTICS_UseSequenceSkill(pGame, pUnit, SKILL_NEST, pTarget, 0, 0);
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
}

// 0x005E6EF0
bool __fastcall sub_005E6EF0_MapAiActionWalkToPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    return sub_6FCE61E0(pGame, pUnit, pAiTickParam, pPosition);
}

// 0x005E6F00
bool __fastcall sub_6FCE6340(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    bool bResult = false;
    if (pUnit && pPosition && pPosition->nX && pPosition->nY)
    {
        bResult = sub_6FCE61E0(pGame, pUnit, pAiTickParam, pPosition);
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 7, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = sub_0046C140_CheckMonStats2ModeFlag(pUnit->dwClassId, MONMODE_SKILL1) ? MONMODE_SKILL1 : MONMODE_NEUTRAL;
            pAiCmd->nCmdParam[2] = pPosition->nX;
            pAiCmd->nCmdParam[3] = pPosition->nY;
            pAiCmd->nCmdParam[4] = 4;
        }

        pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 4, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = pPosition->nX;
            pAiCmd->nCmdParam[2] = pPosition->nY;
            pAiCmd->nCmdParam[3] = 12;
            pAiCmd->nCmdParam[4] = 10;
        }
    }

    return bResult;
}

// 0x005E6FC0
bool __fastcall sub_6FCE64D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    bool bResult = false;
    if (pUnit && pPosition && pPosition->nX && pPosition->nY)
    {
        bResult = sub_6FCE61E0(pGame, pUnit, pAiTickParam, pPosition);
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 7, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = sub_0046C140_CheckMonStats2ModeFlag(pUnit->dwClassId, MONMODE_SKILL2) ? MONMODE_SKILL2 : MONMODE_NEUTRAL;
            pAiCmd->nCmdParam[2] = pPosition->nX;
            pAiCmd->nCmdParam[3] = pPosition->nY;
            pAiCmd->nCmdParam[4] = 4;
        }

        pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 4, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = pPosition->nX;
            pAiCmd->nCmdParam[2] = pPosition->nY;
            pAiCmd->nCmdParam[3] = 12;
            pAiCmd->nCmdParam[4] = 10;
        }
    }

    return bResult;
}
