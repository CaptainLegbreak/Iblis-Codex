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

// 0x0060B4B0
static void sub_0060B4B0_DccCountCells(D2DccDirStrc* pDir)
{
    const int nCellsX = (pDir->nBoxWidth + 3) / 4;
    const int nCellsY = (pDir->f_14 + 3) / 4;
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

void sub_A22_Emit_0060B4B0(D2DccDirStrc* pDir)
{
    sub_0060B4B0_DccCountCells(pDir);
}
