struct D2CacheLink006045B0Strc
{
	char* pPrev;
	char* pNext;

	inline char* Next()
	{
		char* const pResult = (int)pNext <= 0 ? 0 : pNext;
		return pResult;
	}
};

struct D2CacheList006045B0Strc
{
	int nLinkOffset;
	D2CacheLink006045B0Strc tTerminator;
};

struct D2Cache006045B0Strc;
void __fastcall sub_00603C80_GrowListArray(D2Cache006045B0Strc* pCache); // 0x00603C80

struct D2Cache006045B0Strc
{
	char unk_00[0x10];
	unsigned int nCounter;
	char unk_14[0x08];
	D2CacheList006045B0Strc* pLists;
	int unk_20;
	unsigned int nCount;

	int sub_006045B0_Touch(int nIndex);
};

// 0x006045B0
int D2Cache006045B0Strc::sub_006045B0_Touch(int nIndex)
{
	D2CacheList006045B0Strc* const& pListArray = pLists;
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
			sub_00603C80_GrowListArray(this);
			return 1;
		}

		D2CacheList006045B0Strc* pList = &pListArray[nIndex];
		D2CacheLink006045B0Strc* pLink = pEntry ? (D2CacheLink006045B0Strc*)(pEntry + pList->nLinkOffset) : &pList->tTerminator;
		pEntry = pLink->pNext;
	}

	return 0;
}
