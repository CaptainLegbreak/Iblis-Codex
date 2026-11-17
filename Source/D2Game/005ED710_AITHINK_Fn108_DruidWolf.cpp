struct D2GameStrc;
struct D2AiTickParamStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

void __fastcall AITHINK_Fn108_SpiritWolf(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005ECEE0
void __fastcall AITHINK_Fn108_Fenris(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam);     // 0x005ED2A0

// 0x005ED710
void __fastcall AITHINK_Fn108_DruidWolf(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (pUnit && pUnit->dwClassId == 420)
    {
        AITHINK_Fn108_SpiritWolf(pGame, pUnit, pAiTickParam);
        return;
    }
    AITHINK_Fn108_Fenris(pGame, pUnit, pAiTickParam);
}
