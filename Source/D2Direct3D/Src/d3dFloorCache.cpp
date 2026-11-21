#include "D2Direct3D.h"
#include "D2DrlgMaps.h"
#include "D2DDrawTypes.h"
#include "D2D3DTypes.h"
#include "D2GlideTypes.h"

struct D2SurfaceStrc;

struct D2SurfaceVtableStrc;

struct D2FloorEntryStrc;

struct D2FloorSetStrc;

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2SurfaceVtableStrc { void* unknown[31]; int (__stdcall* SetPalette)(D2SurfaceStrc*, void*); };

struct D2SurfaceStrc { D2SurfaceVtableStrc* vtable; };

struct D2FloorEntryStrc { char unknown[8]; D2SurfaceStrc* surface; char tail[12]; };

struct D2FloorSetStrc { int count; char unknown[20]; D2FloorEntryStrc* entries; };

void __fastcall sub_006B20E0_DDrawLogError(const char*, int); // 0x006B20E0

D2FloorPoolEntryStrc* __fastcall sub_006BB1F0_TakeNode(D2FloorPoolStrc* pList); // 0x006BB1F0

static __declspec(noinline) void sub_006BB150_AppendTail(D2FloorPoolStrc* pList, D2FloorPoolEntryStrc* pNode);

__declspec(noinline) D2FloorPoolEntryStrc* __fastcall sub_006BB1F0_Unlink(D2FloorPoolStrc* pList, int nIndex);

#define RELEASE(p) if (p) { p->lpVtbl->Release((D2ComObject006BB640Strc*)p); p = 0; }

struct D2ComObject006BB640Strc;

struct D2ComObjectVtbl006BB640Strc;

struct D2ComPtr006BB640Strc;

struct D2CacheBindingStrc;

struct D2CacheNodeStrc;

struct D2CacheListStrc;

struct D2ComObjectVtbl006BB640Strc
{
    long (__stdcall* QueryInterface)(D2ComObject006BB640Strc* pThis, const void* riid, void** ppv);
    unsigned long (__stdcall* AddRef)(D2ComObject006BB640Strc* pThis);
    unsigned long (__stdcall* Release)(D2ComObject006BB640Strc* pThis);
};

struct D2ComObject006BB640Strc
{
    D2ComObject006BB640Strc* unk;
};

struct D2ComPtr006BB640Strc
{
    D2ComObjectVtbl006BB640Strc* lpVtbl;
};

extern D2ComPtr006BB640Strc* gpSurface_00989C00; // 0x00989C00

struct D2CacheBindingStrc
{
    int unk_00;
    short wSlot;
    short unk_06;
    int f_8[2];
    const unsigned char* pData;
};

struct D2CacheNodeStrc
{
    int id;
    D2CacheBindingStrc* binding;
    D2DDSurfaceStrc* pSurface;
    D2D3DTextureStrc* pTexture;
    D2CacheNodeStrc* next;
    D2CacheNodeStrc* previous;
};

struct D2CacheListStrc
{
    int capacity;
    int count;
    D2CacheNodeStrc* firstUsed;
    D2CacheNodeStrc* lastUsed;
    D2CacheNodeStrc* firstFree;
    D2CacheNodeStrc* lastFree;
    D2CacheNodeStrc* pNodes;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

void __fastcall sub_006B1DC0_Blit8To16(const unsigned char* pSource, unsigned short* pDest, int nWidth, int nHeight, int nPitch, int nUnused); // 0x006B1DC0

void __fastcall sub_006B38A0_Copy(D2DDSurfaceStrc* pDst, D2DDSurfaceStrc* pSrc, unsigned int nRows); // 0x006B38A0

void __fastcall sub_006BACB0_TouchCacheNode(D2CacheListStrc* pList, int nSlot); // 0x006BACB0

int __fastcall sub_006BAF00_AllocateCacheNode(D2CacheListStrc* pList); // 0x006BAF00

static void sub_006BB6B0_DecodeTile(const unsigned char* source, unsigned char* destination); // 0x006BB6B0

extern "C" const char gszFailedToUnlockMemorySurface_006FC284[]; // 0x006FC284

extern "C" const char gszFailedToLockMemorySurface_006FC2A4[]; // 0x006FC2A4

extern const unsigned int gnRenderFlag_006CE290; // 0x006CE290

extern D2D3DDeviceStrc* gpD3DDevice_00970E78; // 0x00970E78

extern D2D3DTextureStrc* gpMemoryTexture_00989C04; // 0x00989C04

D2ComPtr006BB640Strc* gpSurface_00989BF8; // 0x00989BF8

D2ComPtr006BB640Strc* gpTexture_00989BFC; // 0x00989BFC

D2ComPtr006BB640Strc* gpTexture_00989C04; // 0x00989C04

extern D2CacheListStrc gBlockCache_0096FC80; // 0x0096FC80

extern D2CacheListStrc gTileCache_0096FC9C; // 0x0096FC9C

void __fastcall sub_006BB390_MoveNode(D2CacheListStrc* pCache, int nIndex); // 0x006BB390

void __fastcall sub_006BAD70_MoveNode(D2CacheListStrc* pCache, int nIndex); // 0x006BAD70

int __fastcall sub_006BAFC0_Init(D2FloorPoolStrc* pPool, unsigned int nBase, unsigned int nLimit, unsigned int nUnit);

static void sub_006BB150_AppendInUse(D2FloorPoolStrc* pPool, D2FloorPoolEntryStrc* pEntry);

static void sub_006BB170_AppendSpare(D2FloorPoolStrc* pPool, D2FloorPoolEntryStrc* pEntry);

static D2FloorPoolEntryStrc* sub_006BB190_PopInUse(D2FloorPoolStrc* pPool);

static D2FloorPoolEntryStrc* sub_006BB1C0_PopSpare(D2FloorPoolStrc* pPool);

void __fastcall sub_006BB330_ReleaseOldest(D2FloorPoolStrc* pPool);

void __fastcall sub_006BB3E0_Destroy(D2FloorPoolStrc* pPool, int bReleaseAll);

static int sub_006BB270_Alloc(D2FloorPoolStrc* pPool);

D2CacheListStrc gTexCache_0096FC80; // 0x0096FC80

unsigned char gabTileBuffer_009897F8[0x400]; // 0x009897F8

D2DDSurfaceStrc* gpMemorySurface_00989C00; // 0x00989C00

int __fastcall sub_006B3730_CreateSurface(void** ppSurface, void** ppTexture, int nWidth, int nHeight); // 0x006B3730
extern int gnWidth_0096F4DC; // 0x0096F4DC

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

// 0x006BB0E0
void __fastcall sub_006BB0E0_SetFloorPalette(D2FloorSetStrc* textures, void* palette)
{
    if (!palette) return;
    for (int i=0; i<textures->count-1; ++i) {
        D2FloorEntryStrc* entry=&textures->entries[i];
        if (entry->surface) {
            int result=entry->surface->vtable->SetPalette(entry->surface,palette);
            if (result) { sub_006B20E0_DDrawLogError("SetPalette (floor surface)",result); return; }
        }
    }
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

static void sub_006BB150_AppendTail(D2FloorPoolStrc* pList, D2FloorPoolEntryStrc* pNode)
{
    if (!pList->pInUseFirst)
    {
        pList->pInUseFirst = pNode;
        pList->pInUseLast = pNode;
        return;
    }
    pList->pInUseLast->pNext = pNode;
    pNode->pPrev = pList->pInUseLast;
    pList->pInUseLast = pNode;
}

// build: context sub_006BB1F0_Unlink
D2FloorPoolEntryStrc* __fastcall sub_006BB1F0_Unlink(D2FloorPoolStrc* pList, int nIndex)
{
    D2FloorPoolEntryStrc* pHead = pList->pInUseFirst;
    if (!pHead)
        return 0;

    D2FloorPoolEntryStrc* pNode = &pList->pEntries[nIndex];
    if (pNode == pHead)
    {
        pList->pInUseFirst = pHead->pNext;
        if (pHead->pNext)
            pHead->pNext->pPrev = 0;
        else
            pList->pInUseLast = 0;
        pHead->pNext = 0;
        pHead->pPrev = 0;
        return pHead;
    }

    if (pNode == pList->pInUseLast)
    {
        pList->pInUseLast = pNode->pPrev;
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

// 0x006BB2D0
void __fastcall sub_006BB2D0_MoveToTail(D2FloorPoolStrc* pList, int nIndex)
{
    if (pList->nInUse > 1)
    {
        LRU_ASSERT(nIndex, 199);
        LRU_ASSERT(nIndex <= pList->nCapacity, 200);
        LRU_ASSERT(nIndex >= 1, 201);
        sub_006BB150_AppendTail(pList, sub_006BB1F0_Unlink(pList, nIndex - 1));
    }
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

// 0x006BB390
void __fastcall sub_006BB390_MoveNode(D2FloorPoolStrc* pList)
{
    if (pList->nInUse)
    {
        D2FloorPoolEntryStrc* pNode = sub_006BB1F0_TakeNode(pList);
        if (pNode)
        {
            if (pNode->pOwner)
            {
                pNode->pOwner->nCacheIndex = 0;
                pNode->pOwner = 0;
            }
            if (!pList->pSpareFirst)
            {
                pList->pSpareFirst = pNode;
                pList->pSpareLast = pNode;
            }
            else
            {
                pList->pSpareLast->pNext = pNode;
                pNode->pPrev = pList->pSpareLast;
                pList->pSpareLast = pNode;
            }
        }
        --pList->nInUse;
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
			pEntry->pTexture->lpVtbl->Release(pEntry->pTexture);
			pEntry->pTexture = 0;
		}
		if (pEntry->pSurface)
		{
			pEntry->pSurface->lpVtbl->Release(pEntry->pSurface);
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

// 0x006BB5E0
void __cdecl sub_006BB5E0_CreateSurfaces()
{
    D2_ASSERT(sub_006B3730_CreateSurface((void**)&gpSurface_00989BF8, (void**)&gpTexture_00989BFC, gnWidth_0096F4DC, gnHeight_009702B8), 0x27);
    D2_ASSERT(sub_006B3730_CreateSurface((void**)&gpSurface_00989C00, (void**)&gpTexture_00989C04, 0x20, 0x20), 0x2A);
}

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

// 0x006BB640
void __cdecl sub_006BB640_ReleaseSurfaces()
{
    RELEASE(gpTexture_00989BFC);
    RELEASE(gpSurface_00989BF8);
    RELEASE(gpTexture_00989C04);
    RELEASE(gpSurface_00989C00);
}

// 0x006BB6B0
static __declspec(noinline) void sub_006BB6B0_DecodeTile(const unsigned char* source, unsigned char* destination)
{
    int rows = 32;
    unsigned char* row = destination;
    unsigned char* pixel = destination;
    const unsigned char* input = source;
    memset(destination, 0, 1024);
    do
    {
        unsigned char skip = *input++;
        unsigned char count = *input++;
        if (!skip && !count)
        {
            --rows;
            row += 32;
            pixel = row;
        }
        else
        {
            pixel += skip;
            while (count--)
                *pixel++ = *input++;
        }
    } while (rows);
}

// 0x006BBA00
void __fastcall sub_006BBA00_BindTileTexture(D2CacheBindingStrc* pTile)
{
    D2_ASSERT(pTile->wSlot >= 0, 0x1EF);

    if (!pTile->wSlot)
    {
        sub_006BB6B0_DecodeTile(pTile->pData, gabTileBuffer_009897F8);
        pTile->wSlot = sub_006BAF00_AllocateCacheNode(&gTexCache_0096FC80);
        const int nIndex = pTile->wSlot - 1;
        D2_ASSERT(nIndex >= 0, 0x1FC);
        D2_ASSERT(nIndex < gTexCache_0096FC80.capacity, 0x1FD);

        D2CacheNodeStrc* pNode = &gTexCache_0096FC80.pNodes[pTile->wSlot - 1];
        pNode->binding = pTile;

        D2DDSurfaceDesc2Strc tDesc = { sizeof(D2DDSurfaceDesc2Strc) };
        long hResult = gpMemorySurface_00989C00->lpVtbl->Lock(gpMemorySurface_00989C00, 0, &tDesc, 0x21, 0);
        if (hResult)
        {
            sub_006B20E0_DDrawLogError(gszFailedToLockMemorySurface_006FC2A4, hResult);
        }

        D2_ASSERT(tDesc.dwFlags & 8, 0x20B);

        sub_006B1DC0_Blit8To16(gabTileBuffer_009897F8, (unsigned short*)tDesc.lpSurface, 0x20, 0x20, tDesc.lPitch >> 1, 0x20);

        hResult = gpMemorySurface_00989C00->lpVtbl->Unlock(gpMemorySurface_00989C00, 0);
        if (hResult)
        {
            sub_006B20E0_DDrawLogError(gszFailedToUnlockMemorySurface_006FC284, hResult);
        }

        if (gnRenderFlags_0096F3A8 & gnRenderFlag_006CE290)
        {
            sub_006B38A0_Copy(pNode->pSurface, gpMemorySurface_00989C00, 0x20);
        }
        else
        {
            pNode->pTexture->lpVtbl->Load(pNode->pTexture, gpMemoryTexture_00989C04);
        }

        gpD3DDevice_00970E78->lpVtbl->SetTexture(gpD3DDevice_00970E78, 0, pNode->pTexture);
    }
    else
    {
        D2CacheNodeStrc* pNode = &gTexCache_0096FC80.pNodes[pTile->wSlot - 1];
        sub_006BACB0_TouchCacheNode(&gTexCache_0096FC80, pTile->wSlot);
        gpD3DDevice_00970E78->lpVtbl->SetTexture(gpD3DDevice_00970E78, 0, pNode->pTexture);
    }
}

// 0x006BBB90
void __fastcall sub_006BBB90_InvalidateTileCaches(D2TileLibraryEntryStrc* pTile)
{
    if (pTile->nCacheIndex > 0)
    {
        sub_006BB390_MoveNode(&gTileCache_0096FC9C, (short)(pTile->nCacheIndex - 1));
    }

    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        if (pTile->pBlocks[i].nCacheIndex > 0)
        {
            sub_006BAD70_MoveNode(&gBlockCache_0096FC80, (short)(pTile->pBlocks[i].nCacheIndex - 1));
        }
    }
}

#include "gen/data/Source/D2Direct3D/Src/d3dFloorCache.inc"
