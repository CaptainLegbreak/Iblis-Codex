#include "D2Unicode.h"
// build: ob1
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern unsigned int gaFontCharValidBits_006DC9B8[8]; // 0x006DC9B8

// Returns whether the font can draw a character: 0 for the colour-code prefix 0xFF, else the character's bit in its
// row of gaFontCharValidBits_006DC9B8.
// 0x00502550
unsigned int __fastcall D2Win_10128(unsigned char nCharCode)
{
    if (Unicode(nCharCode).isPipe())
    {
        return 0;
    }

    // not original source: the identical arms, the identical-arm if below and the __assume only shape register use
    const unsigned int nRowChar = nCharCode ? nCharCode : nCharCode;
    const unsigned int dwOffset = (nRowChar >> 5) & 7;
    D2_ASSERT(dwOffset < 8, 0x4D8);
    const int nShift = nCharCode % 32;
    unsigned int dwWord = gaFontCharValidBits_006DC9B8[dwOffset];
    if (dwOffset)
    {
        dwWord >>= nShift;
    }
    else
    {
        dwWord >>= nShift;
    }
    const int nBits = (unsigned char)dwWord;
    __assume(nBits != 0x80000000);
    return nBits & 1;
}
