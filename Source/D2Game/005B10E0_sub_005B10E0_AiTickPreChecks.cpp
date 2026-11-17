struct D2GameStrc;
struct D2UnitStrc;
struct D2AiTickParamStrc;

#define STATE_STUNNED 21

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall sub_005B0F50_AiOpenDoorCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B0F50
int __fastcall D2GAME_AICORE_MinionLeash_6FCF0D10(D2GameStrc* pGame, D2UnitStrc* pMonster, D2AiTickParamStrc* pAiTickParam); // 0x005B0FF0

// 0x005B10E0
int __fastcall sub_005B10E0_AiTickPreChecks(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (STATES_CheckState(pUnit, STATE_STUNNED))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 3);
        return 1;
    }

    if (sub_005B0F50_AiOpenDoorCheck(pGame, pUnit, pAiTickParam))
    {
        return 1;
    }

    return D2GAME_AICORE_MinionLeash_6FCF0D10(pGame, pUnit, pAiTickParam) != 0;
}
