struct D2RgbQuadStrc
{
    unsigned char nBlue;
    unsigned char nGreen;
    unsigned char nRed;
    unsigned char nReserved;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern void* ghPalette_0098A160; // 0x0098A160
extern D2RgbQuadStrc gPaletteEntries_00989C40[256]; // 0x00989C40

// 0x006C81A0
void __fastcall sub_006C81A0_RENDERER_WINDOWED_GetPalette(void** phPalette, D2RgbQuadStrc** ppEntries)
{
    D2_ASSERT(phPalette, 546);
    D2_ASSERT(ppEntries, 547);
    *phPalette = ghPalette_0098A160;
    *ppEntries = gPaletteEntries_00989C40;
}
