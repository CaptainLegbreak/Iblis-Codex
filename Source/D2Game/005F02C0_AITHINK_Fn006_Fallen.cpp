struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x0C];
    int dwAnimMode;
    char unk0x14[0x0C];
    D2SeedStrc pSeed;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x38];
    int nLastDeadGUIDs[4];
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

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

enum D2C_M230FallenAi
{
    UNIT_MONSTER = 1,
    EVENTTYPE_AITHINK = 2,
    MONMODE_DEATH = 0,
    MONMODE_NEUTRAL = 1,
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
    MONMODE_SKILL2 = 9,
    MONMODE_DEAD = 12,
    FALLEN_AI_PARAM_COMMAND_ATTACK_CHANCE_PCT = 0,
    FALLEN_AI_PARAM_APPROACH_DISTANCE = 1,
    FALLEN_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    FALLEN_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT = 3,
};

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int a4); // 0x00540E60
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);              // 0x00553380
void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit);                      // 0x0058ED10
extern "C" D2AiCmdStrc* __fastcall sub_0058EE80(D2UnitStrc* pUnit);                                      // 0x0058EE80
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730
int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY);               // 0x005DC530
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit);                                                             // 0x005DD2B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms); // 0x00619790
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd);         // 0x0058EF40
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollUnit(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F02C0
void __fastcall AITHINK_Fn006_Fallen(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pUnit)
    {
        return;
    }

    const int nAnimMode = pUnit->dwAnimMode;
    if (nAnimMode == MONMODE_DEATH || nAnimMode == MONMODE_DEAD)
    {
        return;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

    for (; nNumRooms; ++ppRoomList, --nNumRooms)
    {
        const int* pDeadGUID = (*ppRoomList)->nLastDeadGUIDs;
        for (int i = 0; i < 4; ++i, ++pDeadGUID)
        {
            D2UnitStrc* pCorpse = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, *pDeadGUID);
            if (pCorpse && pCorpse->dwAnimMode == MONMODE_DEATH && (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCorpse, nX, nY) < 15)
            {
                pAiControl->dwAiParam[0] = 1;
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                AITACTICS_SetVelocity(pUnit, 0, 50, 0);

                if (D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pAiTickParam->pTarget, 12, 1))
                {
                    if ((int)(AI_RollUnit(pUnit) % 20) < 1)
                    {
                        SUNIT_AttachSound(pUnit, 17, 0);
                    }

                    return;
                }

                nNumRooms = 1;
                break;
            }
        }
    }

    if (nAnimMode != MONMODE_NEUTRAL)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    D2AiCmdStrc* pCurrentAiCmd = sub_0058EE80(pUnit);
    if (!pCurrentAiCmd)
    {
        if (!bCombat && sub_6FCF2E70(pUnit))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }

        if (nDistance < 15 && AIGENERAL_GetMinionOwner(pUnit) == pUnit && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_COMMAND_ATTACK_CHANCE_PCT))
        {
            D2AiCmdStrc aiCmd;
            aiCmd.nCmdParam[0] = 1;
            AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
            AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, pTarget);
            return;
        }

        if (bCombat)
        {
            if (!pAiControl->dwAiParam[0])
            {
                if (!((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK_CHANCE_PCT)))
                {
                    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 30)
                    {
                        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, pTarget);
                        return;
                    }

                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                    return;
                }
            }

            pAiControl->dwAiParam[0] = 0;
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        if (nDistance > AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_APPROACH_DISTANCE))
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 30)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 3);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }

        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    if (pCurrentAiCmd->nCmdParam[0] == 1)
    {
        if (bCombat)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK_CHANCE_PCT))
            {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT))
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                    return;
                }

                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }

        if (!AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0))
        {
            AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
        }
    }
    else
    {
        AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}
