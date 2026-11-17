struct D2RgbTripleStrc { unsigned char nRed, nGreen, nBlue; };

struct D2RgbKeyStrc { unsigned char bytes[4]; };
typedef char D2RgbKeyMustBeFourBytes[(sizeof(D2RgbKeyStrc) == 4) ? 1 : -1];
typedef unsigned char (__stdcall* D2PaletteFn)(unsigned char, unsigned char, unsigned char);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void* __cdecl memset(void*, int, unsigned int);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int nZero); // 0x0040B380
extern const char gszSubTileFile_006E61F8[]; // 0x006E61F8
#define D2_ASSERT(expr,line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define GetRValue(rgb) ((unsigned char)(rgb))
#define GetGValue(rgb) ((unsigned char)(((unsigned short)(rgb)) >> 8))
#define GetBValue(rgb) ((unsigned char)((rgb) >> 16))

static __declspec(noinline) unsigned char* __stdcall sub_0060D6F0_ConvertPixels(unsigned char* pPixels, int nBytes, D2RgbKeyStrc tKey, D2PaletteFn pConvert);

// 0x0060D6F0
static unsigned char* __stdcall sub_0060D6F0_ConvertPixels(unsigned char* pPixels, int nBytes, D2RgbKeyStrc tKey, D2PaletteFn pConvert)
{
    const int nCount = nBytes / 3;
    unsigned char* pResult = (unsigned char*)FOG_Alloc(nCount, gszSubTileFile_006E61F8, 0xD8, 0);
    unsigned char* pBase = pResult;
    D2_ASSERT(pResult, 0xD9);
    memset(pResult, 0, nCount);
    int i = 0;
    if (nCount > 0)
    {
        do
        {
            unsigned char nColor;
            if (pPixels[i * 3] == tKey.bytes[0] && pPixels[i * 3 + 1] == tKey.bytes[1] && pPixels[i * 3 + 2] == tKey.bytes[2])
                nColor = 0;
            else
            {
                nColor = pConvert(pPixels[i * 3], pPixels[i * 3 + 1], pPixels[i * 3 + 2]);
                D2_ASSERT(nColor, 0xE4);
            }
            *pResult++ = nColor;
            ++i;
        } while (i < nCount);
        pResult = pBase;
    }
    return pResult;
}

// build: context sub_0060D6F0_Shim
// calling-convention shim (not game code)
unsigned char* __stdcall sub_0060D6F0_Shim(unsigned char* pPixels, int nBytes, unsigned int nKey, D2PaletteFn pConvert)
{
    D2RgbKeyStrc tKey = { { (unsigned char)nKey, (unsigned char)(nKey >> 8), (unsigned char)(nKey >> 16), (unsigned char)(nKey >> 24) } };
    return sub_0060D6F0_ConvertPixels(pPixels, nBytes, tKey, pConvert);
}
