#include "D2Direct3D.h"
#include "D2DrlgMaps.h"

extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

// 0x006BB1F0
D2FloorPoolEntryStrc* __fastcall sub_006BB1F0_TakeNode(D2FloorPoolStrc* pList, int nIndex)
{
    D2FloorPoolEntryStrc* pHead = pList->pInUseFirst;
    if (!pHead)
    {
        return 0;
    }
    D2FloorPoolEntryStrc* pNode = &pList->pEntries[nIndex];
    if (pNode == pHead)
    {
        pList->pInUseFirst = pHead->pNext;
        if (pList->pInUseFirst)
        {
            pList->pInUseFirst->pPrev = 0;
        }
        else
        {
            pList->pInUseLast = 0;
        }
        pHead->pNext = 0;
        pHead->pPrev = 0;
        return pHead;
    }
    if (pNode == pList->pInUseLast)
    {
        pList->pInUseLast = pList->pInUseLast->pPrev;
        pList->pInUseLast->pNext = 0;
    }
    else
    {
        pNode->pPrev->pNext = pNode->pNext;
        pNode->pNext->pPrev = pNode->pPrev;
    }
    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

// 0x006BAFC0
int __fastcall sub_006BAFC0_Init(D2FloorPoolStrc* pPool, unsigned int nBase, unsigned int nLimit, unsigned int nUnit)
{
	pPool->nCapacity = (nLimit - nBase) / nUnit;
	pPool->nCapacity = pPool->nCapacity < 0x400 ? pPool->nCapacity : 0x400;

	int nSize = pPool->nCapacity * sizeof(D2FloorPoolEntryStrc);
	pPool->pEntries = (D2FloorPoolEntryStrc*)FOG_Alloc(nSize, gszFloorPoolSourceFile_006FC3E4, 45, 0);
	D2_ASSERT(pPool->pEntries, 46);
	memset(pPool->pEntries, 0, nSize);

	for (int i = 0; i <= pPool->nCapacity - 1; ++i)
	{
		D2FloorPoolEntryStrc* pEntry = &pPool->pEntries[i];
		pEntry->nIndex = i;
		if (i < pPool->nCapacity - 1)
		{
			pEntry->pNext = &pPool->pEntries[i + 1];
		}
		if (i > 0)
		{
			pEntry->pPrev = &pPool->pEntries[i - 1];
		}

		if (!sub_006B58A0_CreateTexture(&pEntry->pTexture, &pEntry->pSurface, gnGlobal_0096F4DC, gnGlobal_009702B8))
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

// 0x006BB150
static void sub_006BB150_AppendInUse(D2FloorPoolStrc* pPool, D2FloorPoolEntryStrc* pEntry)
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

// 0x006BB170
static void sub_006BB170_AppendSpare(D2FloorPoolStrc* pPool, D2FloorPoolEntryStrc* pEntry)
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

// 0x006BB190
static D2FloorPoolEntryStrc* sub_006BB190_PopInUse(D2FloorPoolStrc* pPool)
{
	D2FloorPoolEntryStrc* pEntry = pPool->pInUseFirst;
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

// 0x006BB1C0
static D2FloorPoolEntryStrc* sub_006BB1C0_PopSpare(D2FloorPoolStrc* pPool)
{
	D2FloorPoolEntryStrc* pEntry = pPool->pSpareFirst;
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

// 0x006BB270
static int sub_006BB270_Alloc(D2FloorPoolStrc* pPool)
{
	if (pPool->nInUse == pPool->nCapacity)
	{
		return 0;
	}

	D2FloorPoolEntryStrc* pEntry = sub_006BB1C0_PopSpare(pPool);
	sub_006BB150_AppendInUse(pPool, pEntry);
	++pPool->nInUse;
	return pEntry->nIndex + 1;
}

// 0x006BB330
void __fastcall sub_006BB330_ReleaseOldest(D2FloorPoolStrc* pPool)
{
	if (pPool->nInUse)
	{
		D2FloorPoolEntryStrc* pEntry = sub_006BB190_PopInUse(pPool);
		if (pEntry)
		{
			if (pEntry->pOwner)
			{
				pEntry->pOwner->nCacheIndex = 0;
				pEntry->pOwner = 0;
			}
			sub_006BB170_AppendSpare(pPool, pEntry);
		}
		--pPool->nInUse;
	}
}

// 0x006BB3E0
void __fastcall sub_006BB3E0_Destroy(D2FloorPoolStrc* pPool, int bReleaseAll)
{
	D2_ASSERT(pPool, 96);

	if (!pPool->pEntries)
	{
		D2_ASSERT(!pPool->nInUse, 99);
		return;
	}

	for (int i = 0; i <= pPool->nCapacity - 1; ++i)
	{
		D2FloorPoolEntryStrc* pEntry = &pPool->pEntries[i];
		if (pEntry->pTexture)
		{
			pEntry->pTexture->pVtbl->pRelease(pEntry->pTexture);
			pEntry->pTexture = 0;
		}
		if (pEntry->pSurface)
		{
			pEntry->pSurface->pVtbl->pRelease(pEntry->pSurface);
			pEntry->pSurface = 0;
		}
	}

	if (bReleaseAll)
	{
		while (pPool->nInUse)
		{
			sub_006BB330_ReleaseOldest(pPool);
		}
	}

	if (pPool->pEntries)
	{
		FOG_Free(pPool->pEntries, gszFloorPoolSourceFile_006FC3E4, 131, 0);
		pPool->pEntries = 0;
	}

	memset(pPool, 0, sizeof(D2FloorPoolStrc));
}

// 0x006BB520
int __fastcall sub_006BB520_AllocOrEvict(D2FloorPoolStrc* pPool)
{
	int nId = sub_006BB270_Alloc(pPool);
	while (!nId)
	{
		sub_006BB330_ReleaseOldest(pPool);
		nId = sub_006BB270_Alloc(pPool);
	}
	return nId;
}
