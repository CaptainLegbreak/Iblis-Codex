#include "D2CMP.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
struct D2CmpGfxHashStrc;
struct D2CmpBlockTableBStrc;
struct D2SpriteLoadRequestStrc;
struct D2SpriteCacheNodeStrc;
struct D2CmpGfxHashEntryStrc;

struct D2SpriteCacheStrc
{
    void* pMemPool;
};

struct D2CmpSpriteFileStrc
{
    unsigned int dwFlags;
    char unk0x04[0x10];
    int nDirections;
    int nFramesPerDirection;
    unsigned int aOffsets[1];
};

struct D2CmpSpriteContextStrc
{
    int nFrame;
    unsigned int dwFlags;
    int nType;
    int nArg0C;
    int nArg10;
    int unk0x14;
    int nArg18;
    int nArg1C;
    int nArg20;
    int nArg24;
    int nArg28;
};

struct D2CmpSpriteEntryStrc
{
    int unk0x00;
    int nArg04;
    int nArg08;
    int nArg0C;
    int nArg10;
    int nArg14;
    int nArg18;
    int nArg1C;
    unsigned char nFlags;
    unsigned char nFrames;
    unsigned char nFirstFrame;
    unsigned char nDirections;
    unsigned char nFramesPerDirection;
    char unk0x25[7];
    int aOffsets[0x21];
    T00481720* pAsync;
    D2SpriteCacheNodeStrc* pHolder;
};

struct D2SpriteCacheNodeStrc
{
    D2CmpSpriteEntryStrc* f_0;
    int unk0x04;
    D2CmpGfxHashEntryStrc* pRecord;
};

struct D2CmpGfxHashEntryStrc
{
    char unk0x00[0x24];
    D2SpriteCacheNodeStrc* pHolder;
};

struct D2CmpLoadDescStrc
{
    void* pfnCallback;
    D2CmpSpriteFileStrc* pFile;
    unsigned char* pFlags;
    int nFirstFrame;
    int nFrames;
    int unk0x14;
    int unk0x18;
};

extern D2SpriteCacheStrc gCmpTileCache;                                                                     // 0x0089DB60
extern D2CmpBlockTableBStrc gCmpBlockTableB;                                                                // 0x0088DB58
D2SpriteCacheNodeStrc* __fastcall sub_005FF4A0_SpriteCachePurge(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int bLocked); // 0x005FF4A0
void __fastcall sub_005FF630_ResizeCacheEntry(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int nDelta, int nArg); // 0x005FF630
int __stdcall sub_005FF6E0_SpriteLoadCallback(void* hArg, int nArg, D2SpriteLoadRequestStrc* pRequest);    // 0x005FF6E0
D2SpriteCacheNodeStrc* __fastcall sub_005FFC40_SpriteCacheAlloc(D2SpriteCacheStrc* pCache, unsigned int nSize, unsigned int nKey, int bLocked); // 0x005FFC40
D2CmpGfxHashEntryStrc* __fastcall sub_0060ADC0_GfxHashAdd(void* pMemPool, D2CmpBlockTableBStrc* pHash, D2CmpSpriteEntryStrc* pEntry, D2CmpSpriteContextStrc* pContext, D2CmpSpriteFileStrc* pFile); // 0x0060ADC0

// 0x005FFA20

static int __stdcall sub_005FFA20_LoadDC6Frames(D2CmpSpriteFileStrc* pFile, int nDirection, const char* szName, int nFrames, D2CmpSpriteEntryStrc* pEntry, D2CmpSpriteContextStrc* pContext)
{
    D2_ASSERT(pFile, 0x38F);
    D2_ASSERT(pEntry, 0x390);
    D2_ASSERT(pContext, 0x391);

    unsigned int nStart = 0;
    unsigned int nEnd = 0;
    if (pContext->nType == 1 || pContext->nType == 0)
    {
        if (pContext->nType == 1 && nFrames == 1 && pFile->nDirections != 1)
        {
            return -1;
        }

        nStart = nDirection * nFrames;
        nEnd = nStart + nFrames;
    }

    const int nSize = pFile->aOffsets[nEnd] - pFile->aOffsets[nStart];
    D2_ASSERT(nSize, 0x3A9);
    D2_ASSERT(!pEntry->pAsync, 0x3AA);

    pEntry->nFrames = (unsigned char)nFrames;
    pEntry->nFirstFrame = (unsigned char)(nDirection * nFrames);
    pEntry->nFramesPerDirection = (unsigned char)pFile->nFramesPerDirection;
    pEntry->nDirections = (unsigned char)pFile->nDirections + 1;

    const unsigned int nBase = pFile->aOffsets[nStart];
    for (unsigned int i = nStart; i <= nEnd; ++i)
    {
        D2_ASSERT(i < 0x21, 0x3C1);
        const int nOffset = pFile->aOffsets[i] - nBase;
        pEntry->aOffsets[i] = nOffset;
        D2_ASSERT(nOffset >= 0, 0x3C3);
    }

    if (pFile->dwFlags & 2)
    {
        D2CmpLoadDescStrc tDesc;
        memset(&tDesc, 0, sizeof(tDesc));
        tDesc.pfnCallback = (void*)sub_005FF6E0_SpriteLoadCallback;
        tDesc.pFile = pFile;
        tDesc.pFlags = &pEntry->nFlags;
        tDesc.nFirstFrame = nDirection * nFrames;
        tDesc.nFrames = nFrames;
        pEntry->nFlags |= 4;
        pEntry->pAsync = sub_0040A620(gCmpTileCache.pMemPool, szName, 1, pFile->aOffsets[nStart], nSize, 0, (int)&tDesc, -2, gszSpriteCacheSourceFile, 0x3DA);
    }
    else
    {
        pEntry->pAsync = sub_0040A620(gCmpTileCache.pMemPool, szName, 1, pFile->aOffsets[nStart], nSize, 0, 0, -2, gszSpriteCacheSourceFile, 0x3E6);
    }

    if (!pEntry->pAsync)
    {
        return -1;
    }

    return nSize;
}

static int __stdcall sub_005FFFA0_LoadDC6CacheEntry(D2CmpSpriteFileStrc* pFile, int nDirection, int nFrames, const char* szName, D2CmpSpriteContextStrc* pContext)
{
    D2SpriteCacheNodeStrc* pHolder = sub_005FFC40_SpriteCacheAlloc(&gCmpTileCache, sizeof(D2CmpSpriteEntryStrc), 0, 1);
    if (pHolder)
    {
        D2CmpSpriteEntryStrc* pEntry = pHolder->f_0;
        memset(pEntry, 0, sizeof(D2CmpSpriteEntryStrc));
        pEntry->nArg0C = pContext->nArg18;
        pEntry->nArg18 = pContext->nArg24;
        pEntry->nArg10 = pContext->nArg1C;
        pEntry->nArg14 = pContext->nArg20;
        pEntry->nArg1C = pContext->nArg28;
        pEntry->pHolder = pHolder;
        int nSize = 0;
        if (!(pFile->dwFlags & 1))
        {
            pEntry->nArg08 = pContext->nArg0C;
            pEntry->nArg04 = pContext->nArg10;
            nSize = sub_005FFA20_LoadDC6Frames(pFile, nDirection, szName, nFrames, pEntry, pContext);
            if (nSize != -1)
            {
                sub_005FF630_ResizeCacheEntry(&gCmpTileCache, pHolder, nSize, 1);
            }
        }

        if (nSize != -1)
        {
            D2CmpGfxHashEntryStrc* pRecord = sub_0060ADC0_GfxHashAdd(gCmpTileCache.pMemPool, &gCmpBlockTableB, pHolder->f_0, pContext, pFile);
            D2_ASSERT(pRecord, 0x630);
            pHolder->pRecord = pRecord;
            pRecord->pHolder = pHolder;
            if (pFile->dwFlags & 1)
            {
                pEntry->nFlags |= 1;
                return 0;
            }

            pEntry->nFlags |= 2;
            return 1;
        }

        sub_005FF4A0_SpriteCachePurge(&gCmpTileCache, pHolder, 1);
        return 0;
    }

    return 0;
}

int __stdcall sub_R04_Emit_005FFFA0(D2CmpSpriteFileStrc* pFile, int nDirection, int nFrames, const char* szName, D2CmpSpriteContextStrc* pContext)
{
    return sub_005FFFA0_LoadDC6CacheEntry(pFile, nDirection, nFrames, szName, pContext);
}
