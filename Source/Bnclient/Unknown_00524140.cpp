#include "D2BnCryptTypes.h"

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern D2BnHashCtxStrc gaBnHashCtx_00882760[];                                                              // 0x00882760
void __stdcall sub_00523AF0_HashTransform(D2BnHashCtxStrc* pCtx);                                           // 0x00523AF0

static void __stdcall sub_00524140_UpdateHash(D2BnHashCtxStrc* pCtx, const void* pData, int nLength);

// 0x00524140
static void __stdcall sub_00524140_UpdateHash(D2BnHashCtxStrc* pCtx, const void* pData, int nLength)
{
    const int nOld = pCtx->nBitCountLo;
    const int nNew = nOld + nLength * 8;
    if (nNew < nOld)
        ++pCtx->nBitCountHi;
    pCtx->nBitCountHi += nLength >> 29;
    pCtx->nBitCountLo = nNew;
    if (nLength >= 64)
    {
        unsigned int nBlocks = (unsigned int)nLength >> 6;
        do
        {
            memcpy(pCtx->unk0x1C, pData, sizeof(pCtx->unk0x1C));
            sub_00523AF0_HashTransform(pCtx);
            pData = (const char*)pData + 64;
        } while (--nBlocks);
    }
}

// build: context sub_00524200_HashBlock
void __fastcall sub_00524200_HashBlock(int nIndex, const void* pBlock, unsigned int* pDigest)
{
    D2BnHashCtxStrc* pCtx = &gaBnHashCtx_00882760[(nIndex)];
    sub_00524140_UpdateHash(pCtx, pBlock, 64);
    if (pDigest)
    {
        for (int i = 0; i < 5; ++i)
            pDigest[i] = gaBnHashCtx_00882760[nIndex].aState[i];
    }
}
