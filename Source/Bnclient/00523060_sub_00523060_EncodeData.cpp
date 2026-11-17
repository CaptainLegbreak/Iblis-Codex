extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __fastcall sub_00408090();                                                    // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0

struct D2CipherKeyStringView
{
    void __thiscall sub_00522C30_InitCipherKeys(int bEncrypt); // 0x00522C30
};

struct D2EncodedTrailerStrc
{
    unsigned int nDigest;
    unsigned char nReserved;
    unsigned char nLastBlockSize;
    unsigned short wReserved;
};

unsigned int __fastcall sub_00523020_GetAlignedData(unsigned int nSize);                                   // 0x00523020
void __fastcall sub_005241C0_GetDigest(int nIndex, unsigned int* pDigest);                                  // 0x005241C0
void __fastcall sub_00524200_HashBlock(int nIndex, const void* pBlock, unsigned int* pDigest);              // 0x00524200
void __fastcall sub_00524760_CipherBlock(int nIndex, const unsigned short* pIn, unsigned short* pOut);      // 0x00524760
void __cdecl sub_00524740_ClearKeySchedules();                                                              // 0x00524740
void __cdecl sub_005241A0_ClearHashContexts();                                                              // 0x005241A0

// 0x00523060
void __fastcall sub_00523060_EncodeData(unsigned char* pData, unsigned int nSize, unsigned int nBufferSize, unsigned int nKey)
{
    unsigned char abDigest[20];
    unsigned char aaBlocks[2][64];
    unsigned char abFinalDigest[20];

    D2_ASSERT(pData, 0x105);
    const unsigned int& nKeyValue = nKey;
    const char* szKey = (const char*)nKeyValue;
    D2_ASSERT(szKey, 0x106);
    D2_ASSERT(nBufferSize == sub_00523020_GetAlignedData(nSize), 0x108);

    ((D2CipherKeyStringView*)szKey)->sub_00522C30_InitCipherKeys(1);

    unsigned int nBlock = 0;
    unsigned int nChunk = 0;
    while (nSize)
    {
        nChunk = nSize;
        if (nChunk >= 0x40)
            nChunk = 0x40;

        memcpy(aaBlocks[0], pData, nChunk);
        if (nChunk < 0x40)
            memset(&aaBlocks[0][nChunk], 0, 0x40 - nChunk);

        sub_005241C0_GetDigest(0, (unsigned int*)abDigest);
        if (!(nBlock & 0xF))
            sub_00524200_HashBlock(0, aaBlocks[0], 0);

        for (int i = 0; i < 0x40; ++i)
            aaBlocks[1][i] = abDigest[(unsigned int)(0x3F - i) % 20] + aaBlocks[0][i];

        if (!(nBlock & 7))
        {
            for (int i = 0; i < 0x40; i += 8)
                sub_00524760_CipherBlock(0, (unsigned short*)&aaBlocks[1][i], (unsigned short*)&aaBlocks[0][i]);
        }
        else
        {
            memcpy(aaBlocks[0], aaBlocks[1], 0x40);
        }

        memcpy(pData, aaBlocks[0], 0x40);
        nSize -= nChunk;
        pData += 0x40;
        ++nBlock;
    }

    sub_005241C0_GetDigest(0, (unsigned int*)abFinalDigest);
    D2EncodedTrailerStrc* pTrailer = (D2EncodedTrailerStrc*)pData;
    pTrailer->nDigest = *(unsigned int*)abFinalDigest;
    pTrailer->nReserved = 0;
    pTrailer->nLastBlockSize = (unsigned char)nChunk;
    pTrailer->wReserved = 0;

    sub_00524740_ClearKeySchedules();
    sub_005241A0_ClearHashContexts();
}
