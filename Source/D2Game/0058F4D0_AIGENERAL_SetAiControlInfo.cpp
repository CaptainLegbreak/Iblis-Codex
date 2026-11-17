struct D2GameStrc;
struct D2MinionListStrc;

struct D2AiControlStrc
{
	char unk_00[0x34];
	D2MinionListStrc* pMinionList;
};

struct D2MonsterDataStrc
{
	char unk_00[0x28];
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
};

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
void __fastcall AIGENERAL_FreeAllMinionLists(D2GameStrc* pGame, D2MinionListStrc* pMinionList); // 0x0058F350

// build: context AIGENERAL_GetAiControlFromUnit
static __forceinline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
	if (!pUnit || pUnit->dwUnitType != 1)
	{
		return 0;
	}

	D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
	if (!pMonsterData)
	{
		return 0;
	}

	return pMonsterData->pAiControl;
}

// 0x0058F4D0
void __fastcall AIGENERAL_SetAiControlInfo(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nOwnerGUID, unsigned int nOwnerType, int bSetFlag1, int bSetFlag2, D2MinionListStrc* pMinionList)
{
	const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
	if (nUnitType != 1)
	{
		return;
	}

	D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
	AIGENERAL_FreeAllMinionLists(pGame, pAiControl->pMinionList);
	AIGENERAL_SetOwnerData(pGame, pUnit, nOwnerGUID, nOwnerType, bSetFlag1, bSetFlag2);
	pAiControl->pMinionList = pMinionList;
}
