extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2Rect006B7C90Strc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};
extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C
void __fastcall sub_006B7B30_DrawLine(int nX1, int nY1, int nX2, int nY2, int nColor, int nAlpha); // 0x006B7B30

// 0x006B7C90
void __fastcall sub_006B7C90_DrawDiamond(D2Rect006B7C90Strc* pRect, int nColor)
{
    D2_ASSERT(pRect->nLeft <= pRect->nRight, 0xC5);
    D2_ASSERT(pRect->nTop <= pRect->nBottom, 0xC6);

    int nLeft = pRect->nLeft;
    int nTop = pRect->nTop;
    unsigned int nWidth = pRect->nRight - nLeft;
    unsigned int nHeight = pRect->nBottom - nTop;
    if (!nWidth)
    {
        return;
    }
    if (!nHeight)
    {
        return;
    }

    int nMidX = nLeft + (nWidth >> 1);
    int nMidY = nTop + (nHeight >> 1);
    int nRight = nLeft + nWidth;
    int nBottom = nTop + nHeight;
    if (nRight < 0 || nLeft > gnScreenWidth_007C9138 || nBottom < 0 || nTop > gnScreenHeight_007C913C)
    {
        return;
    }

    sub_006B7B30_DrawLine(nMidX, nTop, nRight, nMidY, nColor, 0xFF);
    sub_006B7B30_DrawLine(nRight, nMidY, nMidX, nBottom, nColor, 0xFF);
    sub_006B7B30_DrawLine(nMidX, nBottom, nLeft, nMidY, nColor, 0xFF);
    sub_006B7B30_DrawLine(nLeft, nMidY, nMidX, nTop, nColor, 0xFF);
}
