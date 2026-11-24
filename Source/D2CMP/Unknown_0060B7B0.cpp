#include "D2CmpTypes.h"

struct D2CmpCellBufStrc
{
    unsigned char* pValues;
    unsigned char* pData;
    int nPitch;
    int nWidth;
    int nHeight;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
extern unsigned int gdwBitMasks_006E6030[];                                                                 // 0x006E6030

static unsigned int CodecReadBits(int nBits, D2CmpBitCursorStrc* pCursor); // 0x0060B200
static unsigned int CodecReadBits(int nBits, D2CmpBitCursorStrc* pCursor); // 0x0060B200
static void __fastcall sub_0060B7B0_DecodeCell(D2CmpBitCursorStrc* pPixelCodes, D2CmpBitCursorStrc* pEqualCells, D2CmpCellBufStrc* pPrev, unsigned char** ppValues, D2CmpCellBufStrc* pCell);

// build: symbol ?ganDccFieldWidths@* 0x006E5F70
extern const int ganDccFieldWidths[16];
// build: symbol ?gadwDccSignBits@* 0x006E5FB0
extern const unsigned int gadwDccSignBits[32];
// build: symbol ?gadwDccSignExtend@* 0x006E60B8
extern const unsigned int gadwDccSignExtend[33];

int __fastcall sub_Emit_0060B280(int nIndex, D2CmpBitCursorStrc* pCursor, int bSigned)
{
    const int nBits = ganDccFieldWidths[nIndex];
    unsigned int nValue = CodecReadBits(nBits, pCursor);
    if (nBits && bSigned && (nValue & gadwDccSignBits[nBits - 1]))
    {
        nValue |= gadwDccSignExtend[nBits];
    }
    return nValue;
}

// build: symbol ?CodecGetRunBits@* 0x0060B780
static inline int CodecGetRunBits(const unsigned char* pBytes)
{
    int nBits;
    for (nBits = 0; (1 << nBits) + 1 <= 4 && pBytes[1 << nBits] != pBytes[(1 << nBits) - 1]; ++nBits)
    {
    }
    return nBits;
}

// 0x0060B7B0
static void __fastcall sub_0060B7B0_DecodeCell(D2CmpBitCursorStrc* pPixelCodes, D2CmpBitCursorStrc* pEqualCells, D2CmpCellBufStrc* pPrev, unsigned char** ppValues, D2CmpCellBufStrc* pCell)
{
    if (pEqualCells && pPrev->pValues && CodecReadBits(1, pEqualCells))
    {
        if (pCell->nWidth == pPrev->nWidth && pCell->nHeight == pPrev->nHeight)
        {
            if (pCell->pData != pPrev->pData)
            {
                unsigned char abTemp[5][5];
                unsigned char* pSrc = pPrev->pData;
                unsigned char* pTempIn = abTemp[0];
                for (int y = 0; y < pCell->nHeight; ++y)
                {
                    memcpy(pTempIn, pSrc, pCell->nWidth);
                    pTempIn += 5;
                    pSrc += pPrev->nPitch;
                }

                unsigned char* pDst = pCell->pData;
                const unsigned char* pTempOut = abTemp[0];
                for (int y = 0; y < pCell->nHeight; ++y, pTempOut += 5)
                {
                    memcpy(pDst, pTempOut, pCell->nWidth);
                    pDst += pCell->nPitch;
                }
            }
        }
        else
        {
            unsigned char* pDst = pCell->pData;
            for (int y = 0; y < pCell->nHeight; ++y)
            {
                memset(pDst, 0, pCell->nWidth);
                pDst += pCell->nPitch;
            }
        }
        return;
    }

    unsigned char* pRow = pCell->pData;
    const int nBits = CodecGetRunBits(pCell->pValues);
    if (!nBits)
    {
        const int nColor = **ppValues;
        for (int y = 0; y < pCell->nHeight; ++y)
        {
            memset(pRow, nColor, pCell->nWidth);
            pRow += pCell->nPitch;
        }
    }
    else
    {
        for (int y = 0; y < pCell->nHeight; ++y)
        {
            for (int x = 0; x < pCell->nWidth; ++x)
            {
                pRow[x] = (*ppValues)[CodecReadBits(nBits, pPixelCodes)];
            }
            pRow += pCell->nPitch;
        }
    }
    *ppValues += 4;
}

static __forceinline unsigned int DccReadBits(D2CmpBitCursorStrc* pCursor, int nCount)
{
    unsigned int nValue;
    const int nLeft = 32 - pCursor->nBitPos;
    if (nLeft >= nCount)
    {
        nValue = (*pCursor->pData >> pCursor->nBitPos) & gdwBitMasks_006E6030[nCount];
        pCursor->nBitPos += nCount;
        if (pCursor->nBitPos == 32)
        {
            ++pCursor->pData;
            pCursor->nBitPos = 0;
        }
    }
    else
    {
        nValue = (*pCursor->pData >> pCursor->nBitPos) & gdwBitMasks_006E6030[nLeft];
        ++pCursor->pData;
        pCursor->nBitPos = nCount - nLeft;
        nValue |= (*pCursor->pData & gdwBitMasks_006E6030[pCursor->nBitPos]) << nLeft;
    }
    return nValue;
}

static unsigned int CodecReadBits(int nBits, D2CmpBitCursorStrc* pCursor)
{
    if (!nBits)
    {
        return 0;
    }
    return DccReadBits(pCursor, nBits);
}

void __fastcall sub_Emit_0060B7B0(D2CmpBitCursorStrc* pPixelCodes, D2CmpBitCursorStrc* pEqualCells, D2CmpCellBufStrc* pPrev, unsigned char** ppValues, D2CmpCellBufStrc* pCell)
{
    sub_0060B7B0_DecodeCell(pPixelCodes, pEqualCells, pPrev, ppValues, pCell);
}
