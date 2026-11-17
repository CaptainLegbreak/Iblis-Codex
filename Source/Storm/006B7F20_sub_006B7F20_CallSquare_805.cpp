struct D2Rect006B7F20Strc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};
struct D2Point006B7F20Strc
{
    int nX;
    int nY;
};
extern "C" __declspec(dllimport) int __stdcall SetRect(D2Rect006B7F20Strc* pRect, int nLeft, int nTop, int nRight, int nBottom);
int __fastcall sub_006B77B0_Call(int nLeft, int nTop, int nRight, int nBottom, int nValue, int nMode); // 0x006B77B0

// 0x006B7F20
void __fastcall sub_006B7F20_CallSquare(D2Point006B7F20Strc* pPoint, unsigned char nSize, int nValue)
{
    if (nSize)
    {
        --nSize;
        D2Rect006B7F20Strc tRect;
        SetRect(&tRect, pPoint->nX - nSize, pPoint->nY - nSize, pPoint->nX + nSize + 1, pPoint->nY + nSize + 1);
        sub_006B77B0_Call(tRect.nLeft, tRect.nTop, tRect.nRight, tRect.nBottom, nValue, 5);
    }
}
