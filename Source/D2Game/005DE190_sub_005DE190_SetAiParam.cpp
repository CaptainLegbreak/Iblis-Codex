struct D2AiParamStrc;

struct D2MonsterDataStrc
{
	char unk_00[0x2C];
	D2AiParamStrc* pAiParams;
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

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall sub_005A6260_SetAiParamFields(D2AiParamStrc* pAiParams, int nParam, int nValue, int nArg); // 0x005A6260

// 0x005DE190
void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg)
{
	D2_ASSERT(nValue >= -126 && nValue <= 126, 272);

	if (nParam == 1)
	{
		nParam = 7;
	}

	D2AiParamStrc* pAiParams = (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData) ? pUnit->pMonsterData->pAiParams : 0;
	sub_005A6260_SetAiParamFields(pAiParams, nParam, nValue, nArg);
}
