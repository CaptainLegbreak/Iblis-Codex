struct D2CacheLink00610CA0Strc
{
	char* pPrev;
	char* pNext;

	__forceinline char* Next()
	{
		char* const pResult = (int)pNext <= 0 ? 0 : pNext;
		return pResult;
	}
};

struct D2CacheList00610CA0Strc
{
	int nLinkOffset;
	D2CacheLink00610CA0Strc tTerminator;
};

struct D2Cache00610CA0Strc;
void __fastcall sub_006108D0_GrowListArray(D2Cache00610CA0Strc* pCache); // 0x006108D0

struct D2Cache00610CA0Strc
{
	char unk_00[0x10];
	unsigned int nCounter;
	char unk_14[0x08];
	D2CacheList00610CA0Strc* pLists;
	int unk_20;
	unsigned int nCount;

	int sub_00610CA0_Touch(int nIndex);
};

// 0x00610CA0
int D2Cache00610CA0Strc::sub_00610CA0_Touch(int nIndex)
{
	D2CacheList00610CA0Strc* const& pListArray = pLists;
	if (nCount >= 0x3FF)
	{
		return 0;
	}

	if (nCounter > 3)
	{
		nCounter -= 3;
	}
	else
	{
		nCounter = 0;
	}

	for (char* pEntry = pListArray[nIndex].tTerminator.Next(); (int)pEntry > 0; )
	{
		++nCounter;
		if (nCounter > 13)
		{
			nCounter = 0;
			sub_006108D0_GrowListArray(this);
			return 1;
		}

		D2CacheList00610CA0Strc* pList = &pListArray[nIndex];
		D2CacheLink00610CA0Strc* pLink = pEntry ? (D2CacheLink00610CA0Strc*)(pEntry + pList->nLinkOffset) : &pList->tTerminator;
		pEntry = pLink->pNext;
	}

	return 0;
}
