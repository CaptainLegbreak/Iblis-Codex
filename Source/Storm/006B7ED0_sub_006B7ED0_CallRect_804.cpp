extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2Rect006B7ED0Strc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};
int __fastcall sub_006B77B0_Call(int nLeft, int nTop, int nRight, int nBottom, int nValue, int nMode); // 0x006B77B0

// 0x006B7ED0
int __fastcall sub_006B7ED0_CallRect(D2Rect006B7ED0Strc* pRect, int nValue)
{
    D2_ASSERT(pRect->nLeft <= pRect->nRight, 0x10C);
    D2_ASSERT(pRect->nTop <= pRect->nBottom, 0x10D);
    return sub_006B77B0_Call(pRect->nLeft, pRect->nTop, pRect->nRight, pRect->nBottom, nValue, 5);
}
