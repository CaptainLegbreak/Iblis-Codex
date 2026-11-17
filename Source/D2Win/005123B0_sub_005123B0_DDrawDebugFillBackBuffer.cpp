extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __stdcall sub_00608C00_RemapRegion(unsigned char* pBuffer, int nPitch);                                // 0x00608C00
extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154

// 0x005123B0
void __fastcall sub_005123B0_DDrawDebugFillBackBuffer(int nX, int nY)
{
    D2_ASSERT(nX > 0 && nX < gnScreenWidth_007C9138 - 0x50, 0x186);
    D2_ASSERT(nY > 0 && nY < gnScreenHeight_007C913C - 0x50, 0x187);
    sub_00608C00_RemapRegion(gpScreenBuffer_007C9154 + gnScreenWidth_007C9138 * nY + nX, gnScreenWidth_007C9138);
}
