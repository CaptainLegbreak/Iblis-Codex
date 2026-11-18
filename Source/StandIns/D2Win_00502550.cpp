// Functional replacement for the function at 0x00502550, not the original code: only the ordinary build (tools/link.py) uses it.

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl ASSERT_Report(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl ASSERT_GetSourceFile(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { ASSERT_Report(&gszEmptyAssertText, ASSERT_GetSourceFile(), line); exit(-1); }
extern unsigned int gaFontCharValidBits_006DC9B8[8]; // 0x006DC9B8

struct Unicode
{
    unsigned short ch;

    inline Unicode(unsigned short c) : ch(c) {}
    inline int isPipe() const
    {
        if (this->ch < 0x100)
        {
            return this->ch == 0xFF;
        }
        return 0;
    }
};

// 0x00502550
unsigned int __fastcall D2Win_10128(unsigned char nCharCode)
{
    if (Unicode(nCharCode).isPipe())
    {
        return 0;
    }

    const unsigned int nRowCode = nCharCode;
    const unsigned int dwOffset = (nRowCode >> 5) & 7;
    D2_ASSERT(dwOffset < 8, 0x4D8);
    const int nBits = (unsigned char)(gaFontCharValidBits_006DC9B8[dwOffset] >> ((unsigned char)nRowCode % 32));
    return nBits & 1;
}
