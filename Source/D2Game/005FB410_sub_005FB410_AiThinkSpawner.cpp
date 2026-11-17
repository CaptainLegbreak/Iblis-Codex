struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0xB0];
    unsigned int dwFlags;
};

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
};

struct D2MonStatsTxt
{
    char unk0x000[0x56];
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

D2ActiveRoomStrc* __fastcall sub_00463740_GetRoomAtPosition(D2ActiveRoomStrc* pRoom, int nX, int nY);      // 0x00463740
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                         // 0x005DE0F0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3);                                   // 0x00621E40
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __stdcall sub_0063EFA0_GetSpawnInfo(D2UnitStrc* pUnit, int* pMonsterId, int* pX, int* pY, int* pAnimMode, int a6, int a7); // 0x0063EFA0

#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static int UNITS_GetAnimMode_FB410(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->dwAnimMode;
}

// 0x005FB410
void __fastcall sub_005FB410_AiThinkSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nMode = UNITS_GetAnimMode_FB410(pUnit);

    if (pAiControl->dwAiParam[0] <= 0)
    {
        pAiControl->dwAiParam[0] = AI_GetParam(pGame, pMonStatsTxt, 1) + pGame->dwGameFrame;
        pAiControl->dwAiParam[1] = AI_GetParam(pGame, pMonStatsTxt, 0);
    }

    if (nMode == 1)
    {
        if (nDistance > 5)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }

        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 10, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 20);
        return;
    }

    if (nMode == 10)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 11, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 20);
        return;
    }

    if (nMode == 11 && pAiControl->dwAiParam[1] > 0)
    {
        if (pGame->dwGameFrame > pAiControl->dwAiParam[0])
        {
            pAiControl->dwAiParam[0] = AI_GetParam(pGame, pMonStatsTxt, 1) + pGame->dwGameFrame;

            int nMonsterId;
            int nX;
            int nY;
            int nAnimMode;
            sub_0063EFA0_GetSpawnInfo(pUnit, &nMonsterId, &nX, &nY, &nAnimMode, 0, 0);

            D2ActiveRoomStrc* pRoom = sub_00463740_GetRoomAtPosition(UNITS_GetRoom(pUnit), nX, nY);
            if (pRoom)
            {
                D2UnitStrc* pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, nAnimMode, 2, 0x42);
                if (pMonster)
                {
                    --pAiControl->dwAiParam[1];
                    pMonster->dwFlags |= 0x4020000;

                    if (pUnit && pUnit->dwClassId == 0x2C7)
                    {
                        STATES_ToggleState(pMonster, 0xB8, 1);
                        UNITS_SetOverlay(pMonster, 0xCA, 0);
                    }
                }
            }
        }

        AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 1));
        return;
    }

    AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
}
