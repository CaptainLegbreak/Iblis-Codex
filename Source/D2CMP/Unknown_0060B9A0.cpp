#include "D2GameTypes.h"
#include "D2CmpTypes.h"
#include "D2CmpCache.h"
#include "D2CmpTiles.h"

struct D2CmpByteMapStrc
{
    unsigned char ab[0x100];
    int nCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610
int __fastcall sub_0060BDB0_EncodeFrame(D2DccFrameStrc* pFrame, D2Dc6FrameStrc* pHeader, unsigned char* pDst); // 0x0060BDB0

extern D2CriticalSectionStrc gtCodecLock_008F03CC;                                                          // 0x008F03CC
extern unsigned char gabDccPixels_008F03E8[];                                                               // 0x008F03E8
extern unsigned char gabDccRunBuffer_0090D8A8[];                                                            // 0x0090D8A8
extern D2DccCellStrc gtDccCells_0094D8A8[5625];                                                             // 0x0094D8A8
extern D2DccFrameStrc gtDccFrames_00969020[];                                                               // 0x00969020
extern const int gnDccFieldWidths_006E5F70[16];                                                             // 0x006E5F70
extern const unsigned int gdwDccSignBits_006E5FB0[32];                                                      // 0x006E5FB0
extern const unsigned int gdwDccSignExtend_006E60B8[33];                                                    // 0x006E60B8
extern "C" const unsigned int gData_006E6030[33]; // 0x006E6030

// 0x0060B200
static unsigned int sub_0060B200_ReadBits(int nNumBits, D2CmpBitCursorStrc* pBitState)
{
    if (!nNumBits)
        return 0;

    const int nRemain = 32 - pBitState->nBitPos;
    unsigned int nBits;
    if (nNumBits <= nRemain)
    {
        nBits = gData_006E6030[nNumBits] & (*pBitState->pData >> pBitState->nBitPos);
        pBitState->nBitPos += nNumBits;
        if (pBitState->nBitPos == 32)
        {
            ++pBitState->pData;
            pBitState->nBitPos = 0;
        }
    }
    else
    {
        nBits = gData_006E6030[nRemain] & (*pBitState->pData++ >> pBitState->nBitPos);
        pBitState->nBitPos = nNumBits - nRemain;
        nBits |= (gData_006E6030[pBitState->nBitPos] & *pBitState->pData) << nRemain;
    }
    return nBits;
}

// 0x0060B2B0
static int sub_0060B2B0_DccNextCell(D2DccDirStrc* pDir, D2DccIterStrc* pIt)
{
    pIt->nX += pIt->nStepX;
    if (pIt->nX < pIt->nWidth)
    {
        pIt->nPixel += pIt->nStepX;
        ++pIt->nCell;
        pIt->nStepX = pIt->nX + 5 < pIt->nWidth ? 4 : pIt->nWidth - pIt->nX;
        return 1;
    }

    pIt->nY += pIt->nStepY;
    if (pIt->nY < pIt->nHeight)
    {
        const int nRemX = -(pIt->nX0 % 4);
        pIt->nX = 0;
        pIt->nStepX = nRemX + 5 < pIt->nWidth ? nRemX + 4 : pIt->nWidth;
        pIt->nPixelRow += pIt->nCellsY * pIt->nStepY;
        pIt->nPixel = pIt->nPixelRow;
        pIt->nCellRow += pDir->nCellsPerRow;
        pIt->nCell = pIt->nCellRow;
        pIt->nStepY = pIt->nY + 5 < pIt->nHeight ? 4 : pIt->nHeight - pIt->nY;
        return 1;
    }

    ++pIt->nFrame;
    D2DccFrameStrc* pFrame = &pDir->pFrames[pIt->nFrame];
    for (; pIt->nFrame < pDir->nFrames; ++pIt->nFrame, ++pFrame)
    {
        if (pFrame->nWidth && pFrame->nHeight)
        {
            pIt->nWidth = pFrame->nWidth;
            pIt->nHeight = pFrame->nHeight;
            pIt->nX0 = pFrame->nXOffset - pDir->nMinX;
            pIt->nY0 = pFrame->nYOffset - pDir->nMinY - (pFrame->bBottomUp ? 0 : pFrame->nHeight);
            pIt->nCellsX = pFrame->nCellsX;
            pIt->nCellsY = pFrame->nCellsY;
            pIt->nCellRow = pIt->nY0 / 4 * pDir->nCellsPerRow + pIt->nX0 / 4;
            pIt->nCell = pIt->nCellRow;
            pIt->nX = 0;
            pIt->nY = 0;
            pIt->nPixelRow = 0;
            pIt->nPixel = 0;
            const int nRemX = -(pIt->nX0 % 4);
            const int nRemY = -(pIt->nY0 % 4);
            pIt->nStepX = nRemX + 5 < pIt->nWidth ? nRemX + 4 : pIt->nWidth;
            pIt->nStepY = nRemY + 5 < pIt->nHeight ? nRemY + 4 : pIt->nHeight;
            return 1;
        }
    }

    return 0;
}

// 0x0060B480
static inline int sub_0060B480_DccFirstCell(D2DccDirStrc* pDir, D2DccIterStrc* pIt)
{
    if (!pDir->nFrames)
    {
        return 0;
    }
    memset(pIt, 0, sizeof(*pIt));
    pIt->nFrame = -1;
    return sub_0060B2B0_DccNextCell(pDir, pIt);
}

extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268

// build: context DccTestBit
static inline int DccTestBit(const unsigned int* pBits, int nBit)
{
    return pBits[nBit >> 5] & gdwBitMasks_006CE268[nBit & 0x1F];
}

// build: context DccGetBitPos
static inline int DccGetBitPos(D2CmpBitCursorStrc* pCursor)
{
    return (int)(pCursor->pData - pCursor->pStart) * 32 + pCursor->nBitPos;
}

// 0x0060B9A0
void __stdcall sub_0060B9A0_DecodeStage1(D2DccDirStrc* pDir, D2DccCellStrc* pCells, D2CmpBitCursorStrc* pEqual, D2CmpBitCursorStrc* pMask, D2CmpBitCursorStrc* pEncoding, D2CmpBitCursorStrc* pRaw, D2CmpBitCursorStrc* pCode, D2CmpByteRunStrc* pRun, int* pnBitsUsed)
{
    D2DccIterStrc tIt;
    unsigned char* pData = pRun->pData;
    const int nStart = DccGetBitPos(pCode);
    if (sub_0060B480_DccFirstCell(pDir, &tIt))
    {
        do
        {
            unsigned int dwMask = 0xF;
            unsigned char* pPrev = pCells[tIt.nCell].pColors;
            if (pPrev)
            {
                if (pEqual && sub_0060B200_ReadBits(1, pEqual))
                {
                    continue;
                }
                dwMask = sub_0060B200_ReadBits(4, pMask);
            }

            int bRaw = 0;
            if (dwMask && pEncoding)
            {
                bRaw = sub_0060B200_ReadBits(1, pEncoding);
            }

            dwMask |= 0xFFFFFFF0;
            int i = 4;
            unsigned char nLast = 0;
            while (i--)
            {
                if (DccTestBit(&dwMask, i))
                {
                    unsigned char nColor;
                    if (bRaw)
                    {
                        nColor = (unsigned char)sub_0060B200_ReadBits(8, pRaw);
                        pData[i] = nColor;
                    }
                    else
                    {
                        nColor = nLast;
                        unsigned int nStep = 0xF;
                        while (nStep == 0xF)
                        {
                            nStep = sub_0060B200_ReadBits(4, pCode);
                            nColor += nStep;
                        }
                        pData[i] = nColor;
                    }

                    if (nLast == nColor)
                    {
                        int nSrc = i;
                        int nDst = -1;
                        for (;;)
                        {
                            ++nSrc;
                            while (!DccTestBit(&dwMask, nSrc))
                            {
                                ++nSrc;
                            }
                            if (nSrc >= 4)
                            {
                                break;
                            }
                            ++nDst;
                            while (!DccTestBit(&dwMask, nDst))
                            {
                                ++nDst;
                            }
                            pData[nDst] = pData[nSrc];
                        }
                        for (;;)
                        {
                            ++nDst;
                            while (!DccTestBit(&dwMask, nDst))
                            {
                                ++nDst;
                            }
                            if (nDst >= 4)
                            {
                                break;
                            }
                            pData[nDst] = 0;
                        }
                        while (i--)
                        {
                            if (!DccTestBit(&dwMask, i))
                            {
                                pData[i] = pPrev[i];
                            }
                        }
                        break;
                    }
                    nLast = nColor;
                }
                else
                {
                    pData[i] = pPrev[i];
                }
            }

            pCells[tIt.nCell].pColors = pData;
            pData += 4;
        }
        while (sub_0060B2B0_DccNextCell(pDir, &tIt));
    }
    *pnBitsUsed = DccGetBitPos(pCode) - nStart;
    pRun->nCount = (int)(pData - pRun->pData);
}

#include "gen/data/Source/D2CMP/Unknown_0060B200.inc"
