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

// build: context DccReadBits
static __forceinline unsigned int DccReadBits(D2CmpBitCursorStrc* pCursor, int nCount)
{
    unsigned int nValue;
    const int nLeft = 32 - pCursor->nBitPos;
    if (nLeft >= nCount)
    {
        nValue = (*pCursor->pData >> pCursor->nBitPos) & gData_006E6030[nCount];
        pCursor->nBitPos += nCount;
        if (pCursor->nBitPos == 32)
        {
            ++pCursor->pData;
            pCursor->nBitPos = 0;
        }
    }
    else
    {
        nValue = (*pCursor->pData >> pCursor->nBitPos) & gData_006E6030[nLeft];
        ++pCursor->pData;
        pCursor->nBitPos = nCount - nLeft;
        nValue |= (*pCursor->pData & gData_006E6030[pCursor->nBitPos]) << nLeft;
    }
    return nValue;
}

// 0x0060B200
static unsigned int __stdcall sub_0060B200_ReadBits(int nNumBits, D2CmpBitCursorStrc* pBitState)
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

// build: context DccReadSigned
static __forceinline int DccReadSigned(int nCount, D2CmpBitCursorStrc* pCursor)
{
    int nValue = sub_0060B200_ReadBits(nCount, pCursor);
    if (nCount && (nValue & gdwDccSignBits_006E5FB0[nCount - 1]))
    {
        nValue |= gdwDccSignExtend_006E60B8[nCount];
    }
    return nValue;
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
static __forceinline int sub_0060B480_DccFirstCell(D2DccDirStrc* pDir, D2DccIterStrc* pIt)
{
    if (!pDir->nFrames)
    {
        return 0;
    }
    memset(pIt, 0, sizeof(*pIt));
    pIt->nFrame = -1;
    return sub_0060B2B0_DccNextCell(pDir, pIt);
}

// 0x0060B4B0
static void sub_0060B4B0_DccCountCells(D2DccDirStrc* pDir)
{
    const int nCellsX = (pDir->nBoxWidth + 3) / 4;
    const int nCellsY = (pDir->nBoxHeight + 3) / 4;
    pDir->nCellsPerRow = nCellsX;
    pDir->nCellsTotal = nCellsY * nCellsX;
    pDir->nCells = 0;
    if (pDir->nFrames)
    {
        D2DccIterStrc iter;
        memset(&iter, 0, sizeof(iter));
        iter.nFrame = -1;
        if (sub_0060B2B0_DccNextCell(pDir, &iter))
        {
            do
            {
                ++pDir->nCells;
            }
            while (sub_0060B2B0_DccNextCell(pDir, &iter));
        }
    }
}

// build: context sub_0060B530_DccInitDir
static void __stdcall sub_0060B530_DccInitDir(D2DccHeaderStrc* pHeader, D2DccFrameStrc* pFrames, D2DccDirStrc* pDir, int nDir)
{
    pDir->pHeader = pHeader;
    pDir->pFrames = pFrames;
    pDir->nFrames = pHeader->nFrames;
    pDir->nDir = nDir;

    int nMinX = 0x7FFFFFFF;
    int nMaxX = (int)0x80000000;
    int nMinY = 0x7FFFFFFF;
    int nMaxY = (int)0x80000000;
    for (D2DccFrameStrc* pFrame = pFrames; pFrame < &pFrames[pHeader->nFrames]; ++pFrame)
    {
        int nX = pFrame->nXOffset;
        int nY = pFrame->nYOffset - (pFrame->bBottomUp ? 0 : pFrame->nHeight);
        if (nX < nMinX)
        {
            nMinX = nX;
        }
        nX += pFrame->nWidth;
        if (nX > nMaxX)
        {
            nMaxX = nX;
        }
        if (nY < nMinY)
        {
            nMinY = nY;
        }
        nY += pFrame->nHeight;
        if (nY > nMaxY)
        {
            nMaxY = nY;
        }
    }

    pDir->nMinY = nMinY;
    pDir->nBoxHeight = nMaxY - nMinY;
    pDir->nMinX = nMinX;
    pDir->nBoxWidth = nMaxX - nMinX;
}

// 0x0060B780
static __forceinline int sub_0060B780_GetRunBits(const unsigned char* pBytes)
{
    int nBits;
    for (nBits = 0; (1 << nBits) + 1 <= 4 && pBytes[1 << nBits] != pBytes[(1 << nBits) - 1]; ++nBits)
    {
    }
    return nBits;
}

// build: context sub_0060B7B0_DecodeCell
static void __stdcall sub_0060B7B0_DecodeCell(D2CmpBitCursorStrc* pCursor, D2CmpBitCursorStrc* pEqual, D2DccCellStrc* pCell, unsigned char** ppRun, D2DccCellStrc* pPrev)
{
    unsigned char abBuffer[25];
    if (pEqual && pPrev->pColors && sub_0060B200_ReadBits(1, pEqual))
    {
        if (pCell->nWidth == pPrev->nWidth && pCell->nHeight == pPrev->nHeight)
        {
            if (pCell->pDst != pPrev->pDst)
            {
                unsigned char* pSrc = pPrev->pDst;
                unsigned char* pBuf = abBuffer;
                for (int y = 0; y < pCell->nHeight; ++y)
                {
                    memcpy(pBuf, pSrc, pCell->nWidth);
                    pSrc += pPrev->nPitch;
                    pBuf += 5;
                }
                unsigned char* pDst = pCell->pDst;
                pBuf = abBuffer;
                for (int y = 0; y < pCell->nHeight; ++y)
                {
                    memcpy(pDst, pBuf, pCell->nWidth);
                    pDst += pCell->nPitch;
                    pBuf += 5;
                }
            }
        }
        else
        {
            unsigned char* pDst = pCell->pDst;
            for (int y = 0; y < pCell->nHeight; ++y)
            {
                memset(pDst, 0, pCell->nWidth);
                pDst += pCell->nPitch;
            }
        }
        return;
    }

    unsigned char* pDst = pCell->pDst;
    const int nBits = sub_0060B780_GetRunBits(pCell->pColors);
    if (!nBits)
    {
        const int nColor = **ppRun;
        for (int y = 0; y < pCell->nHeight; ++y)
        {
            memset(pDst, nColor, pCell->nWidth);
            pDst += pCell->nPitch;
        }
    }
    else
    {
        for (int y = 0; y < pCell->nHeight; ++y)
        {
            for (int x = 0; x < pCell->nWidth; ++x)
            {
                pDst[x] = (*ppRun)[sub_0060B200_ReadBits(nBits, pCursor)];
            }
            pDst += pCell->nPitch;
        }
    }
    *ppRun += 4;
}

extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268

// build: context sub_0060B5F0_BuildColorMaps
static __forceinline void __stdcall sub_0060B5F0_BuildColorMaps(D2CmpByteMapStrc* pInverse, const unsigned char* pFlags, D2CmpByteMapStrc* pForward)
{
    int i;
    int n;
    for (i = 0, n = 0; i < 0x100; ++i)
    {
        if (pFlags[i])
        {
            pForward->ab[i] = (unsigned char)n;
            pInverse->ab[n] = (unsigned char)i;
            ++n;
        }
    }
    pForward->nCount = 0x100;
    pInverse->nCount = n;
}

// 0x0060B640
static void __fastcall sub_0060B640_BuildColorMaps(D2CmpByteMapStrc* pForward, const unsigned int* pBits, D2CmpByteMapStrc* pInverse)
{
    unsigned char abFlags[0x100];
    for (int i = 0; i < 0x100; ++i)
    {
        abFlags[i] = (pBits[i >> 5] & gdwBitMasks_006CE268[i & 0x1F]) != 0;
    }
    sub_0060B5F0_BuildColorMaps(pInverse, abFlags, pForward);
}

// build: context DccTestBit
static __forceinline int DccTestBit(const unsigned int* pBits, int nBit)
{
    return pBits[nBit >> 5] & gdwBitMasks_006CE268[nBit & 0x1F];
}

void __stdcall sub_0060B9A0_DecodeStage1(D2DccDirStrc* pDir, D2DccCellStrc* pCells, D2CmpBitCursorStrc* pEqual, D2CmpBitCursorStrc* pMask, D2CmpBitCursorStrc* pEncoding, D2CmpBitCursorStrc* pRaw, D2CmpBitCursorStrc* pCode, D2CmpByteRunStrc* pRun, int* pnBitsUsed); // 0x0060B9A0

// build: context sub_0060B9A0_DecodeStage1
void __stdcall sub_0060B9A0_DecodeStage1(D2DccDirStrc* pDir, D2DccCellStrc* pCells, D2CmpBitCursorStrc* pEqual, D2CmpBitCursorStrc* pMask, D2CmpBitCursorStrc* pEncoding, D2CmpBitCursorStrc* pRaw, D2CmpBitCursorStrc* pCode, D2CmpByteRunStrc* pRun, int* pnBitsUsed)
{
    D2DccIterStrc tIt;
    const int nStart = (int)(pCode->pData - pCode->pStart) * 32 + pCode->nBitPos;
    unsigned char* pData = pRun->pData;
    if (sub_0060B480_DccFirstCell(pDir, &tIt))
    {
        do
        {
            D2DccCellStrc* pCell = &pCells[tIt.nCell];
            unsigned char* pPrev = pCell->pColors;
            unsigned int nPixelMask = 0xF;
            if (pPrev)
            {
                if (pEqual && sub_0060B200_ReadBits(1, pEqual))
                {
                    continue;
                }
                nPixelMask = DccReadBits(pMask, 4);
            }

            int bRaw = 0;
            if (nPixelMask && pEncoding)
            {
                bRaw = sub_0060B200_ReadBits(1, pEncoding);
            }

            unsigned int dwMask = nPixelMask | 0xFFFFFFF0;
            unsigned char nLast = 0;
            int i = 4;
            int bDone = 0;
            do
            {
                --i;
                if (DccTestBit(&dwMask, i))
                {
                    unsigned char nColor;
                    if (bRaw)
                    {
                        nColor = (unsigned char)DccReadBits(pRaw, 8);
                    }
                    else
                    {
                        unsigned int nStep;
                        nColor = nLast;
                        do
                        {
                            nStep = DccReadBits(pCode, 4);
                            nColor += (unsigned char)nStep;
                        }
                        while (nStep == 0xF);
                    }
                    pData[i] = nColor;
                    if (nLast == nColor)
                    {
                        bDone = 1;
                        break;
                    }
                    nLast = nColor;
                }
                else
                {
                    pData[i] = pPrev[i];
                }
            }
            while (i);

            if (bDone)
            {
                int nSrc = i;
                int nDst = -1;
                for (;;)
                {
                    do
                    {
                        ++nSrc;
                    }
                    while (!DccTestBit(&dwMask, nSrc));
                    if (nSrc >= 4)
                    {
                        break;
                    }
                    do
                    {
                        ++nDst;
                    }
                    while (!DccTestBit(&dwMask, nDst));
                    pData[nDst] = pData[nSrc];
                }
                for (;;)
                {
                    do
                    {
                        ++nDst;
                    }
                    while (!DccTestBit(&dwMask, nDst));
                    if (nDst >= 4)
                    {
                        break;
                    }
                    pData[nDst] = 0;
                }
                while (i)
                {
                    --i;
                    if (!DccTestBit(&dwMask, i))
                    {
                        pData[i] = pPrev[i];
                    }
                }
            }

            pCell->pColors = pData;
            pData += 4;
        }
        while (sub_0060B2B0_DccNextCell(pDir, &tIt));
    }
    *pnBitsUsed = (int)(pCode->pData - pCode->pStart) * 32 - nStart + pCode->nBitPos;
    pRun->nCount = (int)(pData - pRun->pData);
}

// build: context DccGetFile
static __forceinline const D2DccFileStrc* DccGetFile(unsigned int dwFile)
{
    return (const D2DccFileStrc*)dwFile;
}

// build: context DccCopyHeader
static __forceinline void DccCopyHeader(D2DccHeaderStrc* pHeader, const D2DccFileStrc* pFile)
{
    pHeader->n04 = pFile->n04;
    pHeader->n14 = pFile->n14;
    pHeader->nFrames = pFile->nFrames;
    pHeader->n08 = pFile->n08;
}

// 0x0060B140
static __forceinline void __stdcall sub_0060B140_BitBufferInit(int nSize, unsigned int* pBuffer, D2CmpBitCursorStrc* pBitBuf)
{
    pBitBuf->pStart = pBuffer;
    pBitBuf->pData = pBuffer;
    pBitBuf->nBits = nSize * 8;
    pBitBuf->nBitPos = 0;
}


// 0x0060BFF0
int __fastcall sub_0060BFF0_LoadSpriteData(unsigned char* pData, void* pMemPool, int nSize, unsigned int dwFile, D2DccOutTableStrc* pTable, int nFirstDir, int nDirs, int* pnOutSize, const char* szFile)
{
    D2CmpBitCursorStrc tCursor;
    D2CmpBitCursorStrc tEqual;
    D2CmpByteRunStrc tRun;
    D2DccDirStrc tDir;
    D2DccHeaderStrc tHeader;
    D2CmpBitCursorStrc tEqual1;
    D2CmpBitCursorStrc tEncoding;
    D2CmpBitCursorStrc tMask;
    D2CmpBitCursorStrc tRaw;
    D2CmpBitCursorStrc tCode;
    D2DccIterStrc tIt;
    D2CmpByteMapStrc tInverse;

    EnterCriticalSection(&gtCodecLock_008F03CC);

    DccCopyHeader(&tHeader, DccGetFile(dwFile));
    sub_0060B140_BitBufferInit(nSize, (unsigned int*)pData, &tCursor);

    *pnOutSize = 0;
    const int nEnd = nFirstDir + nDirs;
    for (int i = nFirstDir; i < nEnd; ++i)
    {
        const int nDirSize = *(int*)(pData - DccGetFile(dwFile)->dwDirOffsets[nFirstDir] + DccGetFile(dwFile)->dwDirOffsets[i]);
        pTable->dwDirOffsets[i] = *pnOutSize;
        *pnOutSize += nDirSize;
    }

    unsigned char* pResult = (unsigned char*)FOG_AllocPool(pMemPool, *pnOutSize, ".\\SRC\\Codec.cpp", 0x561, 0);
    unsigned char* pOut = pResult;
    for (int nDir = nFirstDir; nDir < nEnd; ++nDir)
    {
        DccReadBits(&tCursor, 32);
        const int nFlags = DccReadBits(&tCursor, 2);
        const unsigned int nWidths = DccReadBits(&tCursor, 28);
        D2DccFrameStrc* pFramesEnd = &gtDccFrames_00969020[tHeader.nFrames];
        const int nVar0Bits = nWidths & 0xF;
        const int nWidthBits = (nWidths >> 4) & 0xF;
        const int nHeightBits = (nWidths >> 8) & 0xF;
        const int nXBits = (nWidths >> 12) & 0xF;
        const int nYBits = (nWidths >> 16) & 0xF;
        const int nOptBits = (nWidths >> 20) & 0xF;
        const int nCodedBits = (nWidths >> 24) & 0xF;

        int nOptSum = 0;
        D2DccFrameStrc* pFrame;
        for (pFrame = gtDccFrames_00969020; pFrame < pFramesEnd; ++pFrame)
        {
            pFrame->nVar0 = sub_0060B200_ReadBits(gnDccFieldWidths_006E5F70[nVar0Bits], &tCursor);
            pFrame->nWidth = sub_0060B200_ReadBits(gnDccFieldWidths_006E5F70[nWidthBits], &tCursor);
            pFrame->nHeight = sub_0060B200_ReadBits(gnDccFieldWidths_006E5F70[nHeightBits], &tCursor);
            pFrame->nXOffset = DccReadSigned(gnDccFieldWidths_006E5F70[nXBits], &tCursor);
            pFrame->nYOffset = DccReadSigned(gnDccFieldWidths_006E5F70[nYBits], &tCursor);
            const int nOpt = sub_0060B200_ReadBits(gnDccFieldWidths_006E5F70[nOptBits], &tCursor);
            pFrame->nOptBytes = nOpt;
            pFrame->pOptData = 0;
            pFrame->nCodedBytes = sub_0060B200_ReadBits(gnDccFieldWidths_006E5F70[nCodedBits], &tCursor);
            pFrame->nCellsX = 0;
            pFrame->nCellsY = 0;
            pFrame->bBottomUp = DccReadBits(&tCursor, 1);
            nOptSum += nOpt;
        }

        if (nOptSum)
        {
            tCursor.AlignToByte();
            unsigned char* pOpt = tCursor.GetBytePtr();
            for (D2DccFrameStrc* pOptFrame = gtDccFrames_00969020; pOptFrame < pFramesEnd; ++pOptFrame)
            {
                if (pOptFrame->nOptBytes)
                {
                    pOptFrame->pOptData = pOpt;
                    pOpt += pOptFrame->nOptBytes;
                }
            }
            tCursor.AdvanceBits(nOptSum * 8);
        }

        sub_0060B530_DccInitDir(&tHeader, gtDccFrames_00969020, &tDir, nDir);
        sub_0060B4B0_DccCountCells(&tDir);
        memset(gtDccCells_0094D8A8, 0, tDir.nCellsTotal * sizeof(D2DccCellStrc));

        int nEqualSize = 0;
        int nEncodingSize = 0;
        int nRawSize = 0;
        if (nFlags & 2)
        {
            nEqualSize = DccReadBits(&tCursor, 20);
        }
        const int nMaskSize = DccReadBits(&tCursor, 20);
        if (nFlags & 1)
        {
            nEncodingSize = DccReadBits(&tCursor, 20);
            nRawSize = DccReadBits(&tCursor, 20);
        }

        {
            unsigned int adwColors[8];
            for (int j = 0; j < 8; ++j)
            {
                adwColors[j] = DccReadBits(&tCursor, 32);
            }
            D2CmpByteMapStrc tForward;
            sub_0060B640_BuildColorMaps(&tForward, adwColors, &tInverse);
        }

        tEqual = tCursor;
        tCursor.AdvanceBits(nEqualSize);
        tMask = tCursor;
        tCursor.AdvanceBits(nMaskSize);
        tEncoding = tCursor;
        tCursor.AdvanceBits(nEncodingSize);
        tRaw = tCursor;
        tCursor.AdvanceBits(nRawSize);
        tCode = tCursor;

        {
            int nBitsUsed = 0;
            tRun.pData = gabDccRunBuffer_0090D8A8;
            tRun.nCount = 0;
            tEqual1 = tEqual;
            sub_0060B9A0_DecodeStage1(&tDir, gtDccCells_0094D8A8, nEqualSize ? &tEqual1 : 0, &tMask, nEncodingSize ? &tEncoding : 0, nRawSize ? &tRaw : 0, &tCode, &tRun, &nBitsUsed);
            tCursor.AdvanceBits(nBitsUsed);
        }

        for (int k = 0; k < tRun.nCount; ++k)
        {
            tRun.pData[k] = tInverse.ab[tRun.pData[k]];
        }

        for (D2DccFrameStrc* pPosFrame = gtDccFrames_00969020; pPosFrame < pFramesEnd; ++pPosFrame)
        {
            const int nX = pPosFrame->nXOffset - tDir.nMinX;
            const int nY = pPosFrame->nYOffset - (pPosFrame->bBottomUp ? 0 : pPosFrame->nHeight) - tDir.nMinY;
            pPosFrame->nCellsX = (int)&gabDccPixels_008F03E8[nY * tDir.nBoxWidth + nX];
            pPosFrame->nCellsY = tDir.nBoxWidth;
        }

        {
            unsigned char* pRun = tRun.pData;
            if (sub_0060B480_DccFirstCell(&tDir, &tIt))
            {
                int nPrevFrame = 0;
                memset(gtDccCells_0094D8A8, 0, sizeof(gtDccCells_0094D8A8));
                D2CmpBitCursorStrc* pEqual = nEqualSize ? &tEqual : 0;
                int bMore;
                do
                {
                    D2DccCellStrc tCell;
                    tCell.pColors = pRun;
                    tCell.pDst = (unsigned char*)(tIt.nCellsX + tIt.nPixel);
                    tCell.nPitch = tIt.nCellsY;
                    tCell.nWidth = tIt.nStepX;
                    tCell.nHeight = tIt.nStepY;
                    sub_0060B7B0_DecodeCell(&tCursor, pEqual, &tCell, &pRun, &gtDccCells_0094D8A8[tIt.nCell]);
                    gtDccCells_0094D8A8[tIt.nCell] = tCell;

                    bMore = sub_0060B2B0_DccNextCell(&tDir, &tIt);
                    if (tIt.nFrame != nPrevFrame)
                    {
                        D2DccFrameStrc* pDone = &gtDccFrames_00969020[nPrevFrame];
                        D2Dc6FrameStrc* pHeader = (D2Dc6FrameStrc*)pOut;
                        pHeader->nFlip = pDone->nVar0;
                        pHeader->nWidth = pDone->nWidth;
                        pHeader->nHeight = pDone->nHeight;
                        pHeader->nXOffset = pDone->nXOffset;
                        pHeader->nYOffset = pDone->nYOffset;
                        pHeader->nLength = pDone->nCodedBytes;
                        pHeader->unk0x14 = 0;
                        pHeader->nNextBlock = 0;
                        if (!sub_0060BDB0_EncodeFrame(pDone, pHeader, pHeader->abData))
                        {
                            char szError[0x200];
                            sub_00410610_WriteLogLine("Sprite Decompression Error -- File:%s", szFile);
                            sprintf(szError, "Error decompressing sprite - Possible corruption in data file: %s", szFile);
                            sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x660);
                            exit(-1);
                        }
                        pOut += pHeader->nLength + pHeader->unk0x14 + 0x23;
                        nPrevFrame = tIt.nFrame;
                    }
                }
                while (bMore);
            }
        }

        tCursor.AlignToByte();
    }

    LeaveCriticalSection(&gtCodecLock_008F03CC);
    return (int)pResult;
}

#include "gen/data/Source/D2CMP/Unknown_0060B200.inc"

#include "gen/data/Source/D2CMP/SRC/Codec.inc"
