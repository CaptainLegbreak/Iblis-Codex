struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2CellFileStrc;
extern D2CellFileStrc* gpBoxPiecesCel_007A2798; // 0x007A2798
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

// 0x00452E50
void __fastcall sub_00452E50_DrawRectangleBorder(D2RectStrc* pRect)
{
    int nWidth = pRect->nRight - pRect->nLeft;
    int nLeft = pRect->nLeft;
    int nRight = nLeft + nWidth + 1;
    int nHeight = pRect->nBottom - pRect->nTop;
    int nTop = pRect->nTop;
    int nBottom = nTop + nHeight + 1;
    D2CelContextStrc context;
    int nPiece = 0;
    memset(&context, 0, sizeof(context));
    context.pCellFile = gpBoxPiecesCel_007A2798;
    context.unk0x40 = 0;

    const int nRightCorner = nRight - 12;
    const int nHorizontalStart = nLeft + 12;
    for (int nX = nHorizontalStart; nX < nRightCorner - 1; nX += 12)
    {
        context.nFrame = ++nPiece % 6 + 2;
        sub_004F6480(&context, nX, nTop + 12, -1, 5, 0);
    }
    for (int nX = nHorizontalStart + 1; nX < nRightCorner - 1; nX += 12)
    {
        context.nFrame = ++nPiece % 6 + 16;
        sub_004F6480(&context, nX, nBottom + 10, -1, 5, 0);
    }
    const int nVerticalStart = nTop + 12;
    for (int nY = nVerticalStart + 10; nY < nBottom - 1; nY += 12)
    {
        context.nFrame = ++nPiece % 3 + 10;
        sub_004F6480(&context, nLeft - 4, nY, -1, 5, 0);
    }
    for (int nY = nVerticalStart + 12; nY < nBottom - 1; nY += 12)
    {
        context.nFrame = ++nPiece % 3 + 13;
        sub_004F6480(&context, nRight - 7, nY, -1, 5, 0);
    }
    context.nFrame = 0;
    sub_004F6480(&context, nLeft, nVerticalStart, -1, 5, 0);
    context.nFrame = 1;
    sub_004F6480(&context, nRightCorner, nVerticalStart, -1, 5, 0);
    context.nFrame = 8;
    sub_004F6480(&context, nLeft, nBottom + 1, -1, 5, 0);
    context.nFrame = 9;
    sub_004F6480(&context, nRightCorner, nBottom + 1, -1, 5, 0);
}
