struct D2GameStrc;
struct D2UnitStrc;

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet);       // 0x0058EEF0
D2AiCmdStrc* __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40

// 0x0058EFA0
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet)
{
    if (!AIGENERAL_GetAiCommandFromParam(pUnit, nCmdParam, bSet))
    {
        D2AiCmdStrc tAiCmd;
        tAiCmd.nCmdParam[0] = nCmdParam;
        tAiCmd.nCmdParam[1] = 0;
        tAiCmd.nCmdParam[2] = 0;
        tAiCmd.nCmdParam[3] = 0;
        tAiCmd.nCmdParam[4] = 0;
        AIGENERAL_CopyAiCommand(pGame, pUnit, &tAiCmd);
    }

    return AIGENERAL_GetAiCommandFromParam(pUnit, nCmdParam, bSet);
}
