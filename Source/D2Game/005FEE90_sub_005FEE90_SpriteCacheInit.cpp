extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* lpCriticalSection);        // 0x006CC210
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

struct D2SpriteCacheNodeStrc
{
    void* pData;
    unsigned int nSize;
    unsigned int nKey;
    unsigned int dwFlags;
    int unk0x10;
    D2SpriteCacheNodeStrc* pNext;
    D2SpriteCacheNodeStrc* pPrev;
};

struct D2SpriteCacheLockStrc
{
    char data[0x18];
};

struct D2SpriteCacheStrc
{
    void* pMemPool;
    unsigned int nMaxSize;
    unsigned int nTotalSize;
    unsigned int nCount;
    D2SpriteCacheNodeStrc* pNodes;
    D2SpriteCacheNodeStrc* pHeadA;
    D2SpriteCacheNodeStrc* pTailA;
    D2SpriteCacheNodeStrc* pHeadB;
    D2SpriteCacheNodeStrc* pTailB;
    D2SpriteCacheNodeStrc* f_24;
    D2SpriteCacheNodeStrc* f_28;
    int nArg;
    D2SpriteCacheLockStrc tLock;
    unsigned int nHits;
    unsigned int f_4C;
};

// 0x005FEE90
void __fastcall sub_005FEE90_SpriteCacheInit(D2SpriteCacheStrc* pCache, void* pMemPool, unsigned int nMaxSize, int nArg)
{
    pCache->nMaxSize = nMaxSize;
    pCache->nArg = nArg;
    pCache->pMemPool = pMemPool;
    pCache->nTotalSize = 0;
    pCache->pNodes = (D2SpriteCacheNodeStrc*)sub_0040B430(pMemPool, sizeof(D2SpriteCacheNodeStrc) * 0x1400, ".\\SRC\\SpriteCache.cpp", 2273, 0);
    memset(pCache->pNodes, 0, sizeof(D2SpriteCacheNodeStrc) * 0x1400);

    for (int i = 0; i < 0x1400; ++i)
    {
        D2SpriteCacheNodeStrc* pNode = &pCache->pNodes[i];
        if (i < 0x1400 - 1)
        {
            pNode->pNext = &pCache->pNodes[i + 1];
        }

        if (i > 0)
        {
            pNode->pPrev = &pCache->pNodes[i - 1];
        }

        pNode->pData = 0;
        pNode->nSize = 0;
        pNode->nKey = 0;
    }

    pCache->f_24 = pCache->pNodes;
    pCache->nCount = 0;
    pCache->pHeadA = 0;
    pCache->pTailA = 0;
    pCache->pHeadB = 0;
    pCache->pTailB = 0;
    pCache->f_28 = &pCache->pNodes[0x1400 - 1];
    pCache->nHits = 0;
    pCache->f_4C = 0;
    InitializeCriticalSection(&pCache->tLock);
}

struct D2CmpCelFileViewStrc
{
    int nVersion;
    char unk0x04[0x10];
    unsigned int nFrames;
};

struct D2CmpCelContextStrc
{
    unsigned int nFrame;
    char unk0x04[0x30];
    D2CmpCelFileViewStrc* pCelFile;
    char unk0x38[0x08];
    unsigned int nDirection;
};

// 0x00601810
int __stdcall sub_00601810_IsGfxFrameValid(D2CmpCelContextStrc* pContext)
{
    D2CmpCelFileViewStrc* pCelFile = pContext->pCelFile;
    if (!pCelFile)
    {
        return 0;
    }

    if (pCelFile->nVersion != 6)
    {
        return 0;
    }

    if (pContext->nDirection >= 0x40)
    {
        return 0;
    }

    return pContext->nFrame <= pCelFile->nFrames;
}
