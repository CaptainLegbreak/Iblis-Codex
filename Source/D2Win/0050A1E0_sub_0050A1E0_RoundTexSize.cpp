struct D2GlideRectViewStrc
{
    int unk0x00;
    int nLeft;
    int nTop;
    int nOffsetX;
    int nOffsetY;
};

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C

// 0x0050A1E0
static __forceinline int sub_0050A1E0_RoundTexSize(int nSize)
{
    if (nSize > 128)
        return 256;
    if (nSize > 64)
        return 128;
    if (nSize > 32)
        return 64;
    if (nSize > 16)
        return 32;
    return nSize > 8 ? 16 : 8;
}

// 0x0050A220
static __forceinline int sub_0050A220_GetTexSizeLog2(int nSize)
{
    if (nSize == 256)
        return 8;
    if (nSize == 128)
        return 7;
    if (nSize == 64)
        return 6;
    if (nSize == 32)
        return 5;
    return nSize == 16 ? 4 : 3;
}

// 0x0050AC90
static __forceinline int sub_0050AC90_IsOutsideScreen(int nX, int nY, D2GlideRectViewStrc* pRect)
{
    nX += pRect->nOffsetX;
    if (nX > gnScreenWidth_007C9138 || pRect->nLeft + nX < 0 || (nY += pRect->nOffsetY) < 0 || nY - pRect->nTop >= gnScreenHeight_007C913C)
        return 1;
    return 0;
}

int __fastcall sub_M120_Emit_0050A1E0(D2GlideRectViewStrc* pRect, int nA, int nB)
{
    int n = sub_0050A1E0_RoundTexSize(nA);
    n += sub_0050A220_GetTexSizeLog2(nB);
    n += sub_0050AC90_IsOutsideScreen(nA, nB, pRect);
    return n;
}
