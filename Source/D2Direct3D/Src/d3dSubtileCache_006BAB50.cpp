#include "D2Direct3D.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2D3DObjVtblStrc;
struct D2SubtilePoolOwnerStrc;
struct D2SubtilePoolEntryStrc;
struct D2SubtilePoolStrc;

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

struct D2SubtilePoolOwnerStrc
{
	int unk0x00;
	short nPoolId;
};

struct D2SubtilePoolEntryStrc
{
	int nIndex;
	D2SubtilePoolOwnerStrc* pOwner;
	D2D3DObjStrc* pTexture;
	D2D3DObjStrc* pSurface;
	D2SubtilePoolEntryStrc* pNext;
	D2SubtilePoolEntryStrc* pPrev;
};

struct D2SubtilePoolStrc
{
	int nCapacity;
	int nInUse;
	D2SubtilePoolEntryStrc* pInUseFirst;
	D2SubtilePoolEntryStrc* pInUseLast;
	D2SubtilePoolEntryStrc* pSpareFirst;
	D2SubtilePoolEntryStrc* pSpareLast;
	D2SubtilePoolEntryStrc* pEntries;
};
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

// 0x006BA9A0
int __fastcall sub_006BA9A0_Init(D2SubtilePoolStrc* pPool, unsigned int nBase, unsigned int nLimit, unsigned int nUnit)
{
	pPool->nCapacity = (nLimit - nBase) / nUnit;
	pPool->nCapacity = pPool->nCapacity < 0x800 ? pPool->nCapacity : 0x800;

	int nSize = pPool->nCapacity * sizeof(D2SubtilePoolEntryStrc);
	pPool->pEntries = (D2SubtilePoolEntryStrc*)FOG_Alloc(nSize, gszSubtilePoolSourceFile_006FC3A8, 45, 0);
	D2_ASSERT(pPool->pEntries, 46);
	memset(pPool->pEntries, 0, nSize);

	for (int i = 0; i <= pPool->nCapacity - 1; ++i)
	{
		D2SubtilePoolEntryStrc* pEntry = &pPool->pEntries[i];
		pEntry->nIndex = i;
		if (i < pPool->nCapacity - 1)
		{
			pEntry->pNext = &pPool->pEntries[i + 1];
		}
		if (i > 0)
		{
			pEntry->pPrev = &pPool->pEntries[i - 1];
		}

		if (!sub_006B58A0_CreateTexture(&pEntry->pTexture, &pEntry->pSurface, 32, 32))
		{
			if (pEntry->pPrev)
			{
				pEntry->pPrev->pNext = 0;
			}
			pPool->nCapacity = i;
			D2_ASSERT(i, 73);
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

// 0x006BAB30
static void sub_006BAB30_AppendInUse(D2SubtilePoolStrc* pPool, D2SubtilePoolEntryStrc* pEntry)
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

// 0x006BAB50
static void sub_006BAB50_AppendSpare(D2SubtilePoolStrc* pPool, D2SubtilePoolEntryStrc* pEntry)
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

// 0x006BAB70
static D2SubtilePoolEntryStrc* sub_006BAB70_PopInUse(D2SubtilePoolStrc* pPool)
{
	D2SubtilePoolEntryStrc* pEntry = pPool->pInUseFirst;
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

// 0x006BABA0
static D2SubtilePoolEntryStrc* sub_006BABA0_PopSpare(D2SubtilePoolStrc* pPool)
{
	D2SubtilePoolEntryStrc* pEntry = pPool->pSpareFirst;
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

// 0x006BAC50
static int sub_006BAC50_Alloc(D2SubtilePoolStrc* pPool)
{
	if (pPool->nInUse == pPool->nCapacity)
	{
		return 0;
	}

	D2SubtilePoolEntryStrc* pEntry = sub_006BABA0_PopSpare(pPool);
	sub_006BAB30_AppendInUse(pPool, pEntry);
	++pPool->nInUse;
	return pEntry->nIndex + 1;
}

// 0x006BAD10
void __fastcall sub_006BAD10_ReleaseOldest(D2SubtilePoolStrc* pPool)
{
	if (pPool->nInUse)
	{
		D2SubtilePoolEntryStrc* pEntry = sub_006BAB70_PopInUse(pPool);
		if (pEntry)
		{
			if (pEntry->pOwner)
			{
				pEntry->pOwner->nPoolId = 0;
				pEntry->pOwner = 0;
			}
			sub_006BAB50_AppendSpare(pPool, pEntry);
		}
		--pPool->nInUse;
	}
}

// 0x006BADC0
void __fastcall sub_006BADC0_Destroy(D2SubtilePoolStrc* pPool, int bReleaseAll)
{
	D2_ASSERT(pPool, 96);

	if (!pPool->pEntries)
	{
		D2_ASSERT(!pPool->nInUse, 99);
		return;
	}

	for (int i = 0; i <= pPool->nCapacity - 1; ++i)
	{
		D2SubtilePoolEntryStrc* pEntry = &pPool->pEntries[i];
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
			sub_006BAD10_ReleaseOldest(pPool);
		}
	}

	if (pPool->pEntries)
	{
		FOG_Free(pPool->pEntries, gszSubtilePoolSourceFile_006FC3A8, 130, 0);
		pPool->pEntries = 0;
	}

	memset(pPool, 0, sizeof(D2SubtilePoolStrc));
}

// 0x006BAF00
int __fastcall sub_006BAF00_AllocOrEvict(D2SubtilePoolStrc* pPool)
{
	int nId = sub_006BAC50_Alloc(pPool);
	while (!nId)
	{
		sub_006BAD10_ReleaseOldest(pPool);
		nId = sub_006BAC50_Alloc(pPool);
	}
	return nId;
}
