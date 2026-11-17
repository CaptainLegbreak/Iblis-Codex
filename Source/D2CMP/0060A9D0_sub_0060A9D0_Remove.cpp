extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char szGfxHashFile[];                                                                      // 0x006E5F44

struct D2AsyncLoadStrc;

typedef void(__fastcall* PixelDataFreeCallback)(void* pData);

void* __fastcall FOG_AsyncDataGetBuffer(D2AsyncLoadStrc* pAsync);                                           // 0x0040A9E0
void __fastcall sub_0040AB00_FreeAsyncData(D2AsyncLoadStrc* pAsync);                                        // 0x0040AB00
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
PixelDataFreeCallback __fastcall sub_00601A40(struct D2CmpGfxHashStrc* pHash);                                              // 0x00601A40

struct D2CmpGfxFrameStrc
{
    char unk0x00[0x14];
    int nSizeA;
    void* pPixelData;
    int nSizeB;
};

struct D2CmpGfxInfoStrc
{
    char unk0x00[0x21];
    unsigned char nCountB;
    char unk0x22[0x02];
    unsigned char nCountA;
    char unk0x25[0x03];
    int bHardware;
    char unk0x2C[0xB0 - 0x2C];
    D2AsyncLoadStrc* pAsync;
};

struct D2CmpGfxHashEntryStrc
{
    unsigned int nIndex;
    char unk0x04[0x1C];
    D2CmpGfxInfoStrc* pInfo;
    int unk0x24;
    D2CmpGfxHashEntryStrc* pPrev;
    D2CmpGfxHashEntryStrc* pNext;
};

struct D2CmpGfxHashStrc
{
    char unk0x0000[0x8000];
    D2CmpGfxHashEntryStrc* pBuckets[0x2000];
};

// 0x0060A9D0
void __fastcall sub_0060A9D0_Remove(D2CmpGfxHashStrc* pHash, int nUnused, void* pMemPool, D2CmpGfxHashEntryStrc* pEntry)
{
    void* pBlocks = 0;
    D2CmpGfxHashEntryStrc* pEntryCopy = pEntry;
    D2CmpGfxHashEntryStrc** ppBucket = &*(pEntryCopy->nIndex + pHash->pBuckets);
    if (*ppBucket == pEntry)
    {
        *ppBucket = pEntry->pNext;
    }

    D2CmpGfxInfoStrc* pInfo = pEntry->pInfo;
    D2AsyncLoadStrc* pAsync = pInfo->pAsync;
    if (pAsync)
    {
        if (pInfo->bHardware)
        {
            PixelDataFreeCallback pfnFree = sub_00601A40(pHash);
            char* pData = (char*)FOG_AsyncDataGetBuffer(pAsync);
            D2_ASSERT(pData, 0x5F);
            unsigned int nOffset = 0;
            pBlocks = ((D2CmpGfxFrameStrc*)pData)->pPixelData;
            for (unsigned int i = 0; i < pInfo->nCountA * (int)pInfo->nCountB;)
            {
                D2CmpGfxFrameStrc* pFrame = (D2CmpGfxFrameStrc*)(nOffset + pData);
                void* const tPPixelData = pFrame->pPixelData;
                if (tPPixelData)
                {
                    if (pfnFree)
                    {
                        pfnFree(tPPixelData);
                    }
                    pFrame->pPixelData = 0;
                }
                nOffset = nOffset + (pFrame->nSizeB + pFrame->nSizeA + 0x23);
                ++i;
            }

            if (pBlocks)
            {
                FOG_FreeServerMemory(pMemPool, pBlocks, szGfxHashFile, 0x82, 0);
            }
        }

        sub_0040AB00_FreeAsyncData(pAsync);
        pInfo->pAsync = 0;
    }

    FOG_FreeServerMemory(pMemPool, pEntry, szGfxHashFile, 0x8E, 0);
}
