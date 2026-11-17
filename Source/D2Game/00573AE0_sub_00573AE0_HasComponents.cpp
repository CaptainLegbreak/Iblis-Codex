struct D2MonsterDataStrc
{
	void* pMonstatsTxt;
	unsigned char nComponent[16];
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

// build: context sub_00573AE0_GetComponents
static __forceinline unsigned char* sub_00573AE0_GetComponents(D2UnitStrc* pUnit)
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

	return pMonsterData->nComponent;
}

// 0x00573AE0
int __fastcall sub_00573AE0_HasComponents(D2UnitStrc* pUnit)
{
	const unsigned char* pComponents = sub_00573AE0_GetComponents(pUnit);
	int i = 0;
	do
	{
		if (*pComponents)
		{
			return 1;
		}
		++i;
		++pComponents;
	}
	while (i < 16);

	return 0;
}
