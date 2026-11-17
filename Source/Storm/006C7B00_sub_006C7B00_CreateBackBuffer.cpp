typedef unsigned int size_t;

struct D2BitmapInfoStrc
{
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
    unsigned int bmiColors[256];
};

struct D2GfxBufferFuncsStrc
{
    void (__fastcall* pfnSetBuffer)(void* pBits, int nWidth, int nHeight, int a4);
};

extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern const char gszEmptyAssertText; // 0x006CC837
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
extern "C" __declspec(dllimport) void* __stdcall GetDC(void* hWnd); // 0x006CC44C
extern "C" __declspec(dllimport) int __stdcall ReleaseDC(void* hWnd, void* hDC); // 0x006CC448
extern "C" __declspec(dllimport) void* __stdcall CreateDIBSection(void* hDC, const D2BitmapInfoStrc* pbmi, unsigned int usage, void** ppvBits, void* hSection, unsigned int offset); // 0x006CC0CC

extern int gnBufferWidth_007C9138; // 0x007C9138
extern int gnBufferHeight_007C913C; // 0x007C913C
extern D2GfxBufferFuncsStrc* gpBufferFuncs_007C914C; // 0x007C914C
void* gpBufferBits_007C9154;        // 0x007C9154
void* ghBufferBitmap_0098A164;        // 0x0098A164

static __declspec(noinline) void sub_006C7B00_CreateBackBuffer(int nResolution);

// 0x006C7B00
static void sub_006C7B00_CreateBackBuffer(int nResolution)
{
    D2_ASSERT(!gpBufferBits_007C9154, 111);

    int nWidth;
    int nHeight;
    switch (nResolution)
    {
    case 0:
        nWidth = 640;
        nHeight = 480;
        break;

    case 3:
        nWidth = 1344;
        nHeight = 700;
        break;

    default:
        nWidth = 800;
        nHeight = 600;
        break;
    }

    gnBufferWidth_007C9138 = nWidth;
    gnBufferHeight_007C913C = nHeight;

    D2BitmapInfoStrc tBitmapInfo;
    memset(&tBitmapInfo, 0, sizeof(tBitmapInfo));
    tBitmapInfo.biSize = 40;
    tBitmapInfo.biWidth = nWidth;
    tBitmapInfo.biHeight = -nHeight;
    tBitmapInfo.biPlanes = 1;
    tBitmapInfo.biBitCount = 8;
    tBitmapInfo.biCompression = 0;

    void* hDC = GetDC(0);
    ghBufferBitmap_0098A164 = CreateDIBSection(hDC, &tBitmapInfo, 0, &gpBufferBits_007C9154, 0, 0);
    ReleaseDC(0, hDC);

    gpBufferFuncs_007C914C->pfnSetBuffer(gpBufferBits_007C9154, gnBufferWidth_007C9138, gnBufferHeight_007C913C, 0);
}

void __cdecl sub_Emit_006C7B00(int nResolution)
{
    sub_006C7B00_CreateBackBuffer(nResolution);
}
