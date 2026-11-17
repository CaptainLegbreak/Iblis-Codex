extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern unsigned char* gpBuffer_007C9154; // 0x007C9154
extern int gnStride_007C9138; // 0x007C9138
extern int gnHeight_007C913C; // 0x007C913C
int __stdcall sub_00608C00_Draw(unsigned char* pPixel, int nStride); // 0x00608C00

// 0x006C88B0
int __fastcall sub_006C88B0_DrawAt(int nX, int nY)
{
    D2_ASSERT(nX > 0 && nX < gnStride_007C9138 - 80, 0x1AB);
    D2_ASSERT(nY > 0 && nY < gnHeight_007C913C - 80, 0x1AC);
    return sub_00608C00_Draw(gpBuffer_007C9154 + nY * gnStride_007C9138 + nX, gnStride_007C9138);
}
