struct D2CacheLink00610840Strc
{
	char* pPrev;
	char* pNext;

	__forceinline char* Next()
	{
		char* const pResult = (int)pNext <= 0 ? 0 : pNext;
		return pResult;
	}
};

struct D2CacheList00610840Strc
{
	int nLinkOffset;
	D2CacheLink00610840Strc tTerminator;
};

struct D2Cache00610840Strc;
void __fastcall sub_006101B0_GrowListArray(D2Cache00610840Strc* pCache); // 0x006101B0

struct D2Cache00610840Strc
{
	char unk_00[0x10];
	unsigned int nCounter;
	char unk_14[0x08];
	D2CacheList00610840Strc* pLists;
	int unk_20;
	unsigned int nCount;

	int sub_00610840_Touch(int nIndex);
};

// 0x00610840
int D2Cache00610840Strc::sub_00610840_Touch(int nIndex)
{
	D2CacheList00610840Strc* const& pListArray = pLists;
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
			sub_006101B0_GrowListArray(this);
			return 1;
		}

		D2CacheList00610840Strc* pList = &pListArray[nIndex];
		D2CacheLink00610840Strc* pLink = pEntry ? (D2CacheLink00610840Strc*)(pEntry + pList->nLinkOffset) : &pList->tTerminator;
		pEntry = pLink->pNext;
	}

	return 0;
}
