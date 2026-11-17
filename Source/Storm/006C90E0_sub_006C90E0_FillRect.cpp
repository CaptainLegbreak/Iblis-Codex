extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* pText, const char* pFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C
extern unsigned char* gpScreenBuffer_007C9154; // 0x007C9154

struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

// 0x006C90E0
void __fastcall sub_006C90E0_FillRect(D2RectStrc* pRect, int nColor)
{
    D2_ASSERT(pRect->nLeft <= pRect->nRight, 0x15E);
    D2_ASSERT(pRect->nTop <= pRect->nBottom, 0x15F);

    if (pRect->nRight < 0)
    {
        return;
    }

    if (pRect->nLeft >= gnScreenWidth_007C9138)
    {
        return;
    }

    if (pRect->nBottom < 0)
    {
        return;
    }

    if (pRect->nTop >= gnScreenHeight_007C913C)
    {
        return;
    }

    if (pRect->nLeft < 0)
    {
        pRect->nLeft = 0;
    }

    if (pRect->nRight >= gnScreenWidth_007C9138)
    {
        pRect->nRight = gnScreenWidth_007C9138 - 1;
    }

    if (pRect->nTop < 0)
    {
        pRect->nTop = 0;
    }

    if (pRect->nBottom >= gnScreenHeight_007C913C)
    {
        pRect->nBottom = gnScreenHeight_007C913C - 1;
    }

    unsigned int nWidth = pRect->nRight - pRect->nLeft;
    int nHeight = pRect->nBottom - pRect->nTop;

    if (!nWidth)
    {
        return;
    }

    if (!nHeight)
    {
        return;
    }

    unsigned char* pDst = &gpScreenBuffer_007C9154[pRect->nTop * gnScreenWidth_007C9138 + pRect->nLeft];
    while (nHeight--)
    {
        if (nWidth > 0)
        {
            memset(pDst, nColor, nWidth);
        }

        pDst += gnScreenWidth_007C9138;
    }
}
