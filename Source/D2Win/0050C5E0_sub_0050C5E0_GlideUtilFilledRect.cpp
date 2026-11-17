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

void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x0050BF50

// 0x0050C5E0
void __fastcall sub_0050C5E0_GlideUtilFilledRect(tagRECT* pRect, int nPaletteIndex)
{
    D2_ASSERT(pRect->left <= pRect->right, 0x100);
    D2_ASSERT(pRect->top <= pRect->bottom, 0x101);
    sub_0050BF50_GlideDrawBox(pRect->left, pRect->top, pRect->right, pRect->bottom, nPaletteIndex, 5);
}
