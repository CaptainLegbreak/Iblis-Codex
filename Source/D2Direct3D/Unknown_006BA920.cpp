#include "D2Direct3D.h"

struct D2D3DObjVtblStrc
{
	void* pQueryInterface;
	void* pAddRef;
	unsigned long (__stdcall* pRelease)(D2D3DObjStrc* pObj);
};

struct D2D3DObjStrc
{
	D2D3DObjVtblStrc* pVtbl;
};

struct D2TexOwnerSlotStrc
{
	void* pTexture;
	void* pInfo;
};

struct D2TexPoolEntryStrc
{
	int nIndex;
	D2TexOwnerSlotStrc* pOwnerSlots;
	int nOwnerSlot;
	int unk0x0C;
	D2D3DObjStrc* pTexture;
	D2D3DObjStrc* pSurface;
	D2TexPoolEntryStrc* pNext;
	D2TexPoolEntryStrc* pPrev;
};

struct D2TexPoolStrc
{
	int nCapacity;
	int nInUse;
	D2TexPoolEntryStrc* pInUseFirst;
	D2TexPoolEntryStrc* pInUseLast;
	D2TexPoolEntryStrc* pSpareFirst;
	D2TexPoolEntryStrc* pSpareLast;
	D2TexPoolEntryStrc* pEntries;
};
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

// 0x006BA420
int __fastcall sub_006BA420_Init(D2TexPoolStrc* pPool, int nBase, int nLimit, int nWidth, int nHeight)
{
	int nUnit = gnBytesPerPixel_00970E80 * nWidth * nHeight;

	pPool->nCapacity = (nLimit - nBase) / nUnit;
	pPool->nCapacity = pPool->nCapacity < 0x400 ? pPool->nCapacity : 0x400;

	int nSize = pPool->nCapacity * sizeof(D2TexPoolEntryStrc);
	pPool->pEntries = (D2TexPoolEntryStrc*)FOG_Alloc(nSize, gszTexPoolSourceFile_006FC36C, 55, 0);
	memset(pPool->pEntries, 0, nSize);

	for (int i = 0; i <= pPool->nCapacity - 1; ++i)
	{
		D2TexPoolEntryStrc* pEntry = &pPool->pEntries[i];
		pEntry->nIndex = i;
		if (i < pPool->nCapacity - 1)
		{
			pEntry->pNext = &pPool->pEntries[i + 1];
		}
		if (i > 0)
		{
			pEntry->pPrev = &pPool->pEntries[i - 1];
		}

		if (!sub_006B58A0_CreateTexture(&pEntry->pTexture, &pEntry->pSurface, nWidth, nHeight))
		{
			if (pEntry->pPrev)
			{
				pEntry->pPrev->pNext = 0;
			}
			pPool->nCapacity = i;
			D2_ASSERT(i, 90);
			break;
		}
	}

	pPool->nInUse = 0;
	pPool->pInUseFirst = 0;
	pPool->pInUseLast = 0;
	pPool->pSpareFirst = pPool->pEntries;
	pPool->pSpareLast = &pPool->pEntries[pPool->nCapacity - 1];
	return pPool->nCapacity * nUnit + nBase;
}

// 0x006BA5C0
static void sub_006BA5C0_AppendInUse(D2TexPoolStrc* pPool, D2TexPoolEntryStrc* pEntry)
{
	if (!pPool->pInUseFirst)
	{
		pPool->pInUseFirst = pEntry;
		pPool->pInUseLast = pEntry;
	}
	else
	{
		pPool->pInUseLast->pNext = pEntry;
		pEntry->pPrev = pPool->pInUseLast;
		pPool->pInUseLast = pEntry;
	}
}

// 0x006BA5E0
static void sub_006BA5E0_AppendSpare(D2TexPoolStrc* pPool, D2TexPoolEntryStrc* pEntry)
{
	if (!pPool->pSpareFirst)
	{
		pPool->pSpareFirst = pEntry;
		pPool->pSpareLast = pEntry;
	}
	else
	{
		pPool->pSpareLast->pNext = pEntry;
		pEntry->pPrev = pPool->pSpareLast;
		pPool->pSpareLast = pEntry;
	}
}

// 0x006BA600
static D2TexPoolEntryStrc* sub_006BA600_PopInUse(D2TexPoolStrc* pPool)
{
	D2TexPoolEntryStrc* pEntry = pPool->pInUseFirst;
	if (!pEntry)
	{
		return 0;
	}

	pPool->pInUseFirst = pEntry->pNext;
	if (pPool->pInUseFirst)
	{
		pPool->pInUseFirst->pPrev = 0;
	}
	else
	{
		pPool->pInUseLast = 0;
	}
	pEntry->pNext = 0;
	pEntry->pPrev = 0;
	return pEntry;
}

// 0x006BA630
static D2TexPoolEntryStrc* sub_006BA630_PopSpare(D2TexPoolStrc* pPool)
{
	D2TexPoolEntryStrc* pEntry = pPool->pSpareFirst;
	if (!pEntry)
	{
		return 0;
	}

	pPool->pSpareFirst = pEntry->pNext;
	if (pPool->pSpareFirst)
	{
		pPool->pSpareFirst->pPrev = 0;
	}
	else
	{
		pPool->pSpareLast = 0;
	}
	pEntry->pNext = 0;
	pEntry->pPrev = 0;
	return pEntry;
}

// 0x006BA6D0
static int sub_006BA6D0_Alloc(D2TexPoolStrc* pPool)
{
	if (pPool->nInUse == pPool->nCapacity)
	{
		return 0;
	}

	D2TexPoolEntryStrc* pEntry = sub_006BA630_PopSpare(pPool);
	D2_ASSERT(pEntry, 215);
	D2_ASSERT(pEntry->nIndex < pPool->nCapacity, 216);
	sub_006BA5C0_AppendInUse(pPool, pEntry);
	++pPool->nInUse;
	return pEntry->nIndex + 1;
}

// 0x006BA7C0
void __fastcall sub_006BA7C0_ReleaseOldest(D2TexPoolStrc* pPool)
{
	if (pPool->nInUse)
	{
		D2TexPoolEntryStrc* pEntry = sub_006BA600_PopInUse(pPool);
		if (pEntry)
		{
			if (pEntry->pOwnerSlots)
			{
				pEntry->pOwnerSlots[pEntry->nOwnerSlot].pTexture = 0;
				pEntry->pOwnerSlots[pEntry->nOwnerSlot].pInfo = 0;
				pEntry->pOwnerSlots = 0;
			}
			sub_006BA5E0_AppendSpare(pPool, pEntry);
		}
		--pPool->nInUse;
	}
}

// 0x006BA830
void __fastcall sub_006BA830_Destroy(D2TexPoolStrc* pPool, int bReleaseAll)
{
	D2_ASSERT(pPool, 113);

	if (!pPool->pEntries)
	{
		D2_ASSERT(!pPool->nInUse, 116);
		return;
	}

	for (int i = 0; i <= pPool->nCapacity - 1; ++i)
	{
		D2TexPoolEntryStrc* pEntry = &pPool->pEntries[i];
		if (pEntry->pSurface)
		{
			pEntry->pSurface->pVtbl->pRelease(pEntry->pSurface);
			pEntry->pSurface = 0;
		}
		if (pEntry->pTexture)
		{
			pEntry->pTexture->pVtbl->pRelease(pEntry->pTexture);
			pEntry->pTexture = 0;
		}
	}

	if (bReleaseAll)
	{
		while (pPool->nInUse)
		{
			sub_006BA7C0_ReleaseOldest(pPool);
		}
	}

	if (pPool->pEntries)
	{
		FOG_Free(pPool->pEntries, gszTexPoolSourceFile_006FC36C, 148, 0);
		pPool->pEntries = 0;
	}

	memset(pPool, 0, sizeof(D2TexPoolStrc));
}

// 0x006BA920
int __fastcall sub_006BA920_AllocOrEvict(D2TexPoolStrc* pPool)
{
	int nId = sub_006BA6D0_Alloc(pPool);
	while (!nId)
	{
		sub_006BA7C0_ReleaseOldest(pPool);
		nId = sub_006BA6D0_Alloc(pPool);
	}
	return nId;
}
