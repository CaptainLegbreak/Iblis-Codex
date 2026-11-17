struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct tagPOINT
{
    long x;
    long y;
};

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
void __fastcall sub_006C90E0_GdiUtilFilledRect(tagRECT* pRect, unsigned char nColor);                       // 0x006C90E0

// 0x006C91D0
void __fastcall sub_006C91D0_GdiUtilPoint(tagPOINT* pPoint, unsigned char nSize, unsigned char nPaletteIndex)
{
    if (nSize)
    {
        --nSize;
        tagRECT tRect;
        SetRect(&tRect, pPoint->x - nSize, pPoint->y - nSize, pPoint->x + nSize + 1, pPoint->y + nSize + 1);
        sub_006C90E0_GdiUtilFilledRect(&tRect, nPaletteIndex);
    }
}
