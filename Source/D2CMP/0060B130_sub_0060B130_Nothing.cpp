struct D2CmpBitCursorStrc
{
    int* pStart;
    int* pData;
    int unk0x08;
    int f_C;

    unsigned char* sub_0060B180_GetBytePtr();
    void sub_0060B1D0_AlignToByte();
    int sub_0060B1F0_GetBitPos();
};

struct D2CmpByteMapStrc
{
    unsigned char ab[0x100];
    int nCount;
};

struct D2CmpByteRunStrc
{
    unsigned char* pData;
    int nCount;
};

extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268

struct D2DccFrameStrc
{
    int nUnk0x00;
    int nWidth;
    int nHeight;
    int nXOffset;
    int nYOffset;
    int nUnk0x14[3];
    int nCellsX;
    int nCellsY;
    int bBottomUp;
};

struct D2DccDirStrc
{
    int nUnk0x00;
    D2DccFrameStrc* pFrames;
    int nMinX;
    int nMinY;
    int nBoxWidth;
    int f_14;
    int nUnk0x18;
    int nFrames;
    int nCells;
    int nCellsTotal;
    int nCellsPerRow;
};

struct D2DccIterStrc
{
    int nFrame;
    int nWidth;
    int nHeight;
    int nX0;
    int nY0;
    int nCellsX;
    int nCellsY;
    int nCellRow;
    int nCell;
    int nX;
    int nY;
    int f_2C;
    int nPixel;
    int nStepX;
    int nStepY;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0

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
        pIt->f_2C += pIt->nCellsY * pIt->nStepY;
        pIt->nPixel = pIt->f_2C;
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
            pIt->f_2C = 0;
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

// 0x0060B130
void __cdecl sub_0060B130_Nothing()
{
}

// 0x0060B180
unsigned char* D2CmpBitCursorStrc::sub_0060B180_GetBytePtr()
{
    return (unsigned char*)pData + (f_C + 7) / 8;
}

// 0x0060B1D0
void D2CmpBitCursorStrc::sub_0060B1D0_AlignToByte()
{
    const unsigned int nPos = (f_C + 7) & ~7u;
    f_C = nPos & 0x1F;
    pData += nPos / 32;
}

// 0x0060B1F0
int D2CmpBitCursorStrc::sub_0060B1F0_GetBitPos()
{
    return (pData - pStart) * 32 + f_C;
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
void __fastcall sub_0060B640_BuildColorMaps(D2CmpByteMapStrc* pInverse, const unsigned int* pBits, D2CmpByteMapStrc* pForward)
{
    unsigned char abFlags[0x100];
    for (int i = 0; i < 0x100; ++i)
    {
        abFlags[i] = (pBits[i >> 5] & gdwBitMasks_006CE268[i & 0x1F]) != 0;
    }
    sub_0060B5F0_BuildColorMaps(pInverse, abFlags, pForward);
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

// 0x0060BD90
static __forceinline void sub_0060BD90_RemapRun(D2CmpByteRunStrc* pRun, const unsigned char* pTable)
{
    for (int i = 0; i < pRun->nCount; ++i)
    {
        pRun->pData[i] = pTable[pRun->pData[i]];
    }
}

int sub_M123_Emit_0060B480(D2DccDirStrc* pDir)
{
    D2DccIterStrc tIt;
    int n = 0;
    if (sub_0060B480_DccFirstCell(pDir, &tIt))
    {
        do
        {
            ++n;
        } while (sub_0060B2B0_DccNextCell(pDir, &tIt));
    }
    return n;
}

int sub_M123_Emit_0060B780(const unsigned char* pBytes)
{
    return sub_0060B780_GetRunBits(pBytes + 0x10);
}

void sub_M123_Emit_0060BD90(D2CmpByteRunStrc* pRun, const unsigned char* pTable)
{
    sub_0060BD90_RemapRun(pRun, pTable);
}
