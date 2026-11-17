struct D2GameStrc;
struct D2UnitStrc;

struct D2AiControlStrc
{
	int nAiSpecialState;
	char unk_04[0x10];
	int dwAiParam[3];
};

struct D2MonStatsTxt
{
	char unk_000[0x170];
	short nSkill[8];
	unsigned char nSkillMode[8];
};

struct D2AiTickParamStrc
{
	D2AiControlStrc* pAiControl;
	int unk_04;
	D2UnitStrc* pTarget;
	char unk_0C[0x10];
	D2MonStatsTxt* pMonstatsTxt;
};

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE0F0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
void __fastcall sub_005F2EB0_RemoveGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005F2EB0

// 0x005F81D0
void __fastcall AITHINK_SpecialFn052_FrogDemon(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
	D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
	const int nAiSpecialState = pAiControl->nAiSpecialState;
	D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

	if (nAiSpecialState != 10 && nAiSpecialState != 11)
	{
		const short nSkillId = pMonStatsTxt->nSkill[0];
		if (nSkillId >= 0 && pAiControl->dwAiParam[2] >= 2)
		{
			AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], nSkillId, pAiTickParam->pTarget, 0, 0);
			pAiControl->dwAiParam[2] = 1;
			sub_005F2EB0_RemoveGroundCollision(pGame, pUnit);
			return;
		}

		AITHINK_ExecuteAiFn(pGame, pUnit, pAiControl, nAiSpecialState);
		AITACTICS_Idle(pGame, pUnit, 1);
		return;
	}

	AITHINK_ExecuteAiFn(pGame, pUnit, pAiControl, nAiSpecialState);
	AITACTICS_Idle(pGame, pUnit, 1);
}
