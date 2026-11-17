#ifdef MOVED_TEST
#define CMD_ID 6
#define DURATION 22
#define INTERVAL 12
#else
#define CMD_ID 4
#define DURATION 20
#define INTERVAL 10
#endif
struct D2GameStrc;
struct D2UnitStrc;
struct D2AiTickParamStrc;
struct D2AiCmdStrc
{
#ifdef MOVED_TEST
    int movedPrefix;
#endif
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};
struct D2MapAIPathPositionStrc
{
#ifdef MOVED_TEST
    int movedPrefix;
#endif
    int nMapAIAction;
    int nX;
    int nY;
};
bool __fastcall sub_6FCE61E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition); // 0x005E6DE0
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
// 0x005E6E80
bool __fastcall sub_005E6E80(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    bool bResult = false;
    if (pUnit && pPosition && pPosition->nX && pPosition->nY)
    {
        bResult = sub_6FCE61E0(pGame, pUnit, pAiTickParam, pPosition);
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, CMD_ID, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = pPosition->nX;
            pAiCmd->nCmdParam[2] = pPosition->nY;
            pAiCmd->nCmdParam[3] = DURATION;
            pAiCmd->nCmdParam[4] = INTERVAL;
        }
    }
    return bResult;
}
