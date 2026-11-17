struct D2InventoryGridInfoStrc
{
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short pad0x02;
    int nGridLeft;
    int nGridRight;
    int nGridTop;
    int nGridBottom;
    unsigned char nGridBoxWidth;
    unsigned char nGridBoxHeight;
    unsigned short pad0x16;
};

void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, unsigned char nColor, int nFlags); // 0x0046EFD0
extern int gnScreenHeight_007A521C;                                                                         // 0x007A521C
extern int gnScreenWidth_007A5220;                                                                          // 0x007A5220
extern unsigned char gabGridColors_007BCAD8[];                                                             // 0x007BCAD8

static __declspec(noinline) void __stdcall sub_004839D0_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nColor, unsigned char nWidth, unsigned char nHeight, int nY);

// 0x004839D0
static void __stdcall sub_004839D0_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nColor, unsigned char nWidth, unsigned char nHeight, int nY)
{
    for (int nRow = nY; nRow < nY + nHeight; ++nRow)
    {
        for (int nColumn = nX; nColumn < nX + nWidth; ++nColumn)
        {
            const int nLeft = pGrid->nGridBoxWidth * nColumn + pGrid->nGridLeft;
            const int nTop = pGrid->nGridBoxHeight * nRow + pGrid->nGridTop;
            if (nLeft >= 0 && nLeft < gnScreenWidth_007A5220 && nTop >= 0 && nTop < gnScreenHeight_007A521C)
            {
                sub_0046EFD0_DrawFramedBox(nLeft, nTop, pGrid->nGridBoxWidth, pGrid->nGridBoxHeight, gabGridColors_007BCAD8[nColor], 0);
            }
        }
    }
}

// build: context sub_004839D0_Shim
// calling-convention shim (not game code)
void __fastcall sub_004839D0_Shim(D2InventoryGridInfoStrc* pGrid, int nX, int nY, unsigned char nWidth, unsigned char nHeight)
{
    sub_004839D0_DrawGridCells(pGrid, nX, 1, nWidth, nHeight, nY);
    sub_004839D0_DrawGridCells(pGrid, nY, 0, nHeight, nWidth, nX);
}
