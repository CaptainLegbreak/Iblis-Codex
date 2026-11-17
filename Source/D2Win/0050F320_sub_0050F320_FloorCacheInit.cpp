struct D2TileLibraryEntryStrc;

struct D2GlideFloorCacheEntryStrc
{
    int unk0x00;
    unsigned int f_4;
    D2TileLibraryEntryStrc* pTile;
    D2GlideFloorCacheEntryStrc* pNext;
    D2GlideFloorCacheEntryStrc* pPrev;
};

struct D2GlideFloorCacheStrc
{
    unsigned int unk0x00;
    int nCount;
    int nUsed;
    D2GlideFloorCacheEntryStrc* pHead;
    D2GlideFloorCacheEntryStrc* pTail;
    D2GlideFloorCacheEntryStrc* f_14;
    D2GlideFloorCacheEntryStrc* f_18;
    D2GlideFloorCacheEntryStrc* pEntries;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
extern int gdwGlobal_0087EFB8;                                                                              // 0x0087EFB8

// 0x0050F320
int __fastcall sub_0050F320_FloorCacheInit(D2GlideFloorCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nBlockSize)
{
    const int nCount = (nEnd - nStart) / nBlockSize;
    pCache->unk0x00 = nBlockSize;
    pCache->nCount = nCount;
    pCache->pEntries = (D2GlideFloorCacheEntryStrc*)FOG_Alloc(nCount * sizeof(D2GlideFloorCacheEntryStrc), ".\\Src\\glFloorCache.cpp", 0x29, 0);
    D2_ASSERT(pCache->pEntries, 0x2A);
    memset(pCache->pEntries, 0, nCount * sizeof(D2GlideFloorCacheEntryStrc));

    for (int i = 0; i <= pCache->nCount - 1; ++i)
    {
        D2GlideFloorCacheEntryStrc* pEntry = &pCache->pEntries[i];
        pEntry->unk0x00 = i;
        if (i < pCache->nCount - 1)
        {
            pEntry->pNext = &pCache->pEntries[i + 1];
        }
        if (i > 0)
        {
            pEntry->pPrev = &pCache->pEntries[i - 1];
        }
        pEntry->f_4 = nStart + i * nBlockSize;
    }

    pCache->nUsed = 0;
    pCache->pHead = 0;
    pCache->pTail = 0;
    pCache->f_14 = pCache->pEntries;
    pCache->f_18 = &pCache->pEntries[pCache->nCount - 1];

    if (!gdwGlobal_0087EFB8)
    {
        for (int i = 1; i < pCache->nCount - 1; ++i)
        {
            const unsigned int nEntryAddress = pCache->pEntries[i].f_4;
            if (nEntryAddress < 0x200000 && pCache->unk0x00 + nEntryAddress > 0x200000)
            {
                pCache->pEntries[i - 1].pNext = &pCache->pEntries[i + 1];
                pCache->pEntries[i + 1].pPrev = &pCache->pEntries[i - 1];
                pCache->pEntries[i].pPrev = 0;
                pCache->pEntries[i].pNext = 0;
                ++pCache->nUsed;
                break;
            }
        }

        if (pCache->pEntries[pCache->nCount - 1].f_4 < 0x200000 && pCache->unk0x00 + pCache->pEntries[pCache->nCount - 1].f_4 > 0x200000)
        {
            pCache->pEntries[pCache->nCount - 1].pPrev = 0;
            pCache->pEntries[pCache->nCount - 2].pNext = 0;
            pCache->f_18 = &pCache->pEntries[pCache->nCount - 2];
            --pCache->nCount;
        }
    }

    return pCache->nCount * nBlockSize + nStart;
}
