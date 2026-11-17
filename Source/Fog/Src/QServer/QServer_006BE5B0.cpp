typedef struct _RTL_CRITICAL_SECTION_006BE5B0
{
	void* DebugInfo;
	long LockCount;
	long RecursionCount;
	void* OwningThread;
	void* LockSemaphore;
	unsigned long SpinCount;
} CRITICAL_SECTION_006BE5B0;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION_006BE5B0* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION_006BE5B0* lpCriticalSection);

struct D2HashNode006BE5B0Strc
{
	void* pPrev;
	D2HashNode006BE5B0Strc* pNext;
	int unk_08;
	int unk_0C;
	int nKey;
};

struct D2HashTable006BE5B0Strc
{
	int unk_00;
	int unk_04;
	unsigned int nBuckets;
	int unk_0C;
	int unk_10;
	D2HashNode006BE5B0Strc** ppBuckets;
	int unk_18;
	CRITICAL_SECTION_006BE5B0* pLocks;
};

// 0x006BE5B0
D2HashNode006BE5B0Strc* __fastcall sub_006BE5B0_FindNode(D2HashTable006BE5B0Strc* pTable, int nKey)
{
	D2HashNode006BE5B0Strc * pResult;
	D2HashNode006BE5B0Strc* pNode = 0;
	for (unsigned int i = 0; i < pTable->nBuckets; ++i)
	{
		EnterCriticalSection(&pTable->pLocks[i]);
		for (pNode = pTable->ppBuckets[i]; pNode; pNode = pNode->pNext)
		{
			if (pNode->nKey == nKey)
			{
				LeaveCriticalSection(&pTable->pLocks[i]);
				pResult = pNode;
				goto Done;
			}
		}
		LeaveCriticalSection(&pTable->pLocks[i]);
	}

	pResult = pNode;
Done:
	return pResult;
}
