#include "D2GameTypes.h"
#include "D2CMP.h"
#include "D2CmpTypes.h"
#include "D2CmpCache.h"
#include "D2CmpTiles.h"

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
static inline unsigned int DccReadBits(D2CmpBitCursorStrc* pCursor, int nCount)
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
static unsigned int __stdcall sub_0060B200(int nNumBits, D2CmpBitCursorStrc* pBitState)
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
static inline int DccReadSigned(int nCount, D2CmpBitCursorStrc* pCursor)
{
    int nValue = sub_0060B200(nCount, pCursor);
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

struct D2DccDirIndexStrc
{
    int nDir;
};

// 0x0060B530
static void __stdcall sub_0060B530_DccInitDir(D2DccHeaderStrc* pHeader, D2DccFrameStrc* pFrames, D2DccDirStrc* pDir, D2DccDirIndexStrc tDirIndex)
{
    pDir->pHeader = pHeader;
    pDir->pFrames = pFrames;
    pDir->nFrames = pHeader->nFrames;
    pDir->nDir = tDirIndex.nDir;

    int nMinX = 0x7FFFFFFF;
    int nMaxX = (int)0x80000000;
    int nMinY = 0x7FFFFFFF;
    int nMaxY = (int)0x80000000;

    D2DccFrameStrc* pEnd = &pFrames[pDir->nFrames];
    for (D2DccFrameStrc* pFrame = pFrames; pFrame < pEnd; ++pFrame)
    {
        int nX = pFrame->nXOffset;
        int nY = pFrame->nYOffset - (pFrame->bBottomUp ? 0 : pFrame->nHeight);
        if (nX < nMinX)
        {
            nMinX = nX;
        }
        if (nX + pFrame->nWidth > nMaxX)
        {
            nMaxX = nX + pFrame->nWidth;
        }
        if (nY < nMinY)
        {
            nMinY = nY;
        }
        if (nY + pFrame->nHeight > nMaxY)
        {
            nMaxY = nY + pFrame->nHeight;
        }
    }

    pDir->nMinY = nMinY;
    pDir->nMinX = nMinX;
    pDir->nBoxWidth = nMaxX - nMinX;
    pDir->nBoxHeight = nMaxY - nMinY;
}

// 0x0060B780
static inline int sub_0060B780_GetRunBits(const unsigned char* pBytes)
{
    int nBits;
    for (nBits = 0; (1 << nBits) + 1 <= 4 && pBytes[1 << nBits] != pBytes[(1 << nBits) - 1]; ++nBits)
    {
    }
    return nBits;
}

void __stdcall sub_0060B7B0_DecodeCell(D2CmpBitCursorStrc* pCursor, D2CmpBitCursorStrc* pEqual, D2DccCellStrc* pCell, unsigned char** ppRun, D2DccCellStrc* pPrev); // 0x0060B7B0

extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268

void __stdcall sub_0060B5F0_BuildColorMaps(D2CmpByteMapStrc* pInverse, const unsigned char* pFlags, D2CmpByteMapStrc* pForward); // 0x0060B5F0

void __fastcall sub_0060B640_BuildColorMaps(D2CmpByteMapStrc* pForward, const unsigned int* pBits, D2CmpByteMapStrc* pInverse); // 0x0060B640

// build: context DccTestBit
static inline int DccTestBit(const unsigned int* pBits, int nBit)
{
    return pBits[nBit >> 5] & gdwBitMasks_006CE268[nBit & 0x1F];
}

void __stdcall sub_0060B9A0_DecodeStage1(D2DccDirStrc* pDir, D2DccCellStrc* pCells, D2CmpBitCursorStrc* pEqual, D2CmpBitCursorStrc* pMask, D2CmpBitCursorStrc* pEncoding, D2CmpBitCursorStrc* pRaw, D2CmpBitCursorStrc* pCode, D2CmpByteRunStrc* pRun, int* pnBitsUsed); // 0x0060B9A0


// build: context DccCopyHeader
static inline void DccCopyHeader(D2DccHeaderStrc* pHeader, const D2DccFileStrc* pFile)
{
    pHeader->n04 = pFile->n04;
    pHeader->n14 = pFile->n14;
    pHeader->nFrames = pFile->nFrames;
    pHeader->n08 = pFile->n08;
}

// 0x0060B140
static inline void __stdcall sub_0060B140_BitBufferInit(int nSize, unsigned int* pBuffer, D2CmpBitCursorStrc* pBitBuf)
{
    pBitBuf->pStart = pBuffer;
    pBitBuf->pData = pBuffer;
    pBitBuf->nBits = nSize * 8;
    pBitBuf->nBitPos = 0;
}


struct D2DccDecodeLocalsStrc
{
    D2DccIterStrc tIt;
    D2DccDirStrc tDir;
    D2DccHeaderStrc tHeader;
    D2CmpBitCursorStrc tEqual1;
    D2CmpBitCursorStrc tEncoding;
    D2CmpBitCursorStrc tMask;
    D2CmpBitCursorStrc tRaw;
    D2CmpBitCursorStrc tCode;
};

struct D2DccEqualRunStrc
{
    D2CmpBitCursorStrc tEqual;
    D2CmpByteRunStrc tRun;
};

// build: context sub_0060BFF0_LoadSpriteData
int __fastcall sub_0060BFF0_LoadSpriteData(unsigned int dwData, void* pMemPool, int nSize, const D2DccFileStrc* pFile, D2DccOutTableStrc* pTable, int nFirstDir, int nDirs, int* pnOutSize, const char* szFile)
{
    D2CmpBitCursorStrc tCursor;
    D2DccEqualRunStrc e;
    D2DccDecodeLocalsStrc l;
    D2CmpByteMapStrc tInverse;

    EnterCriticalSection(&gtCodecLock_008F03CC);

    DccCopyHeader(&l.tHeader, pFile);
    sub_0060B140_BitBufferInit(nSize, (unsigned int*)dwData, &tCursor);

    const int nEnd = nFirstDir + nDirs;
    *pnOutSize = 0;
    for (int i = nFirstDir; i < nEnd; ++i)
    {
        const int nDirSize = *(int*)((unsigned int)tCursor.pStart - pFile->dwDirOffsets[nFirstDir] + pFile->dwDirOffsets[i]);
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
        D2DccFrameStrc* pFramesEnd = &gtDccFrames_00969020[l.tHeader.nFrames];
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
            pFrame->nVar0 = sub_0060B200(gnDccFieldWidths_006E5F70[nVar0Bits], &tCursor);
            pFrame->nWidth = sub_0060B200(gnDccFieldWidths_006E5F70[nWidthBits], &tCursor);
            pFrame->nHeight = sub_0060B200(gnDccFieldWidths_006E5F70[nHeightBits], &tCursor);
            pFrame->nXOffset = DccReadSigned(gnDccFieldWidths_006E5F70[nXBits], &tCursor);
            pFrame->nYOffset = DccReadSigned(gnDccFieldWidths_006E5F70[nYBits], &tCursor);
            const int nOpt = sub_0060B200(gnDccFieldWidths_006E5F70[nOptBits], &tCursor);
            pFrame->nOptBytes = nOpt;
            pFrame->pOptData = 0;
            pFrame->nCodedBytes = sub_0060B200(gnDccFieldWidths_006E5F70[nCodedBits], &tCursor);
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

        {
            const D2DccDirIndexStrc tDirIndex = { nDir };
            sub_0060B530_DccInitDir(&l.tHeader, gtDccFrames_00969020, &l.tDir, tDirIndex);
        }
        sub_0060B4B0_DccCountCells(&l.tDir);
        memset(gtDccCells_0094D8A8, 0, l.tDir.nCellsTotal * sizeof(D2DccCellStrc));

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

        e.tEqual = tCursor;
        tCursor.AdvanceBits(nEqualSize);
        l.tMask = tCursor;
        tCursor.AdvanceBits(nMaskSize);
        l.tEncoding = tCursor;
        tCursor.AdvanceBits(nEncodingSize);
        l.tRaw = tCursor;
        tCursor.AdvanceBits(nRawSize);
        l.tCode = tCursor;

        {
            int nBitsUsed = 0;
            e.tRun.pData = gabDccRunBuffer_0090D8A8;
            e.tRun.nCount = 0;
            l.tEqual1 = e.tEqual;
            sub_0060B9A0_DecodeStage1(&l.tDir, gtDccCells_0094D8A8, nEqualSize ? &l.tEqual1 : 0, &l.tMask, nEncodingSize ? &l.tEncoding : 0, nRawSize ? &l.tRaw : 0, &l.tCode, &e.tRun, &nBitsUsed);
            tCursor.AdvanceBits(nBitsUsed);
        }

        for (int k = 0; k < e.tRun.nCount; ++k)
        {
            e.tRun.pData[k] = tInverse.ab[e.tRun.pData[k]];
        }

        for (D2DccFrameStrc* pPosFrame = gtDccFrames_00969020; pPosFrame < pFramesEnd; ++pPosFrame)
        {
            const int nX = pPosFrame->nXOffset - l.tDir.nMinX;
            const int nY = pPosFrame->nYOffset - (pPosFrame->bBottomUp ? 0 : pPosFrame->nHeight) - l.tDir.nMinY;
            pPosFrame->nCellsX = (int)&gabDccPixels_008F03E8[nY * l.tDir.nBoxWidth + nX];
            pPosFrame->nCellsY = l.tDir.nBoxWidth;
        }

        {
            unsigned char* pRun = e.tRun.pData;
            if (sub_0060B480_DccFirstCell(&l.tDir, &l.tIt))
            {
                int nPrevFrame = 0;
                memset(gtDccCells_0094D8A8, 0, sizeof(gtDccCells_0094D8A8));
                D2CmpBitCursorStrc* pEqual = nEqualSize ? &e.tEqual : 0;
                int bMore;
                int nFrame;
                do
                {
                    D2DccCellStrc tCell;
                    tCell.pColors = pRun;
                    tCell.pDst = (unsigned char*)(l.tIt.nCellsX + l.tIt.nPixel);
                    tCell.nPitch = l.tIt.nCellsY;
                    tCell.nWidth = l.tIt.nStepX;
                    tCell.nHeight = l.tIt.nStepY;
                    D2DccCellStrc* pPrev = &gtDccCells_0094D8A8[l.tIt.nCell];
                    sub_0060B7B0_DecodeCell(&tCursor, pEqual, &tCell, &pRun, pPrev);
                    *pPrev = tCell;

                    bMore = sub_0060B2B0_DccNextCell(&l.tDir, &l.tIt);
                    nFrame = l.tIt.nFrame;
                    if (nFrame != nPrevFrame)
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
                        nPrevFrame = nFrame;
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
