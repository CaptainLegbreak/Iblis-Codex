struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154

// 0x00512D90
void __fastcall sub_00512D90_DDrawUtilFilledRect(tagRECT* pRect, unsigned char nColor)
{
    D2_ASSERT(pRect->left <= pRect->right, 0x165);
    D2_ASSERT(pRect->top <= pRect->bottom, 0x166);
    if (pRect->right < 0 || pRect->left >= gnScreenWidth_007C9138 || pRect->bottom < 0 || pRect->top >= gnScreenHeight_007C913C)
        return;
    if (pRect->left < 0)
        pRect->left = 0;
    if (pRect->right >= gnScreenWidth_007C9138)
        pRect->right = gnScreenWidth_007C9138 - 1;
    if (pRect->top < 0)
        pRect->top = 0;
    if (pRect->bottom >= gnScreenHeight_007C913C)
        pRect->bottom = gnScreenHeight_007C913C - 1;
    const unsigned int nWidth = pRect->right - pRect->left;
    int nHeight = pRect->bottom - pRect->top;
    if (!nWidth || !nHeight)
        return;
    unsigned char* pDst = &gpScreenBuffer_007C9154[pRect->top * gnScreenWidth_007C9138 + pRect->left];
    while (nHeight--)
    {
        for (unsigned int x = 0; x < nWidth; ++x)
            pDst[x] = nColor;
        pDst += gnScreenWidth_007C9138;
    }
}
