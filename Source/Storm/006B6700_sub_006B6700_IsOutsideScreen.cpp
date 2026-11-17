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

// 0x006B6700
static __forceinline int sub_006B6700_IsOutsideScreen(int nX, int nY, D2GlideRectViewStrc* pRect)
{
    nX += pRect->nOffsetX;
    if (nX > gnScreenWidth_007C9138 || pRect->nLeft + nX < 0 || (nY += pRect->nOffsetY) < 0 || nY - pRect->nTop >= gnScreenHeight_007C913C)
        return 1;
    return 0;
}

// calling-convention shim (not game code)
int __fastcall sub_006B6700_Shim(D2GlideRectViewStrc* pRect, int nA, int nB)
{
    int n = nA * 3;
    n += sub_006B6700_IsOutsideScreen(nA, nB, pRect);
    return n;
}
