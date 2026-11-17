#include "D2Win.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2RgbQuadStrc;

struct D2RgbQuadStrc
{
    unsigned char nBlue;
    unsigned char nGreen;
    unsigned char nRed;
    unsigned char nReserved;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern void* ghPalette_0098A160; // 0x0098A160
extern D2RgbQuadStrc gPaletteEntries_00989C40[256]; // 0x00989C40
extern int gnValue_007C913C; // 0x007C913C
extern int gnValue_007C9138; // 0x007C9138

// 0x006C81A0
void __fastcall sub_006C81A0_RENDERER_WINDOWED_GetPalette(void** phPalette, D2RgbQuadStrc** ppEntries)
{
    D2_ASSERT(phPalette, 546);
    D2_ASSERT(ppEntries, 547);
    *phPalette = ghPalette_0098A160;
    *ppEntries = gPaletteEntries_00989C40;
}

// 0x006C81E0
void __fastcall sub_006C81E0_GetValues(int* pA, int* pB, int* pC)
{
    D2_ASSERT(pA, 0x230);
    D2_ASSERT(pB, 0x231);
    D2_ASSERT(pC, 0x232);
    *pA = gnValue_007C9154;
    *pB = gnValue_007C913C;
    *pC = gnValue_007C9138;
}
