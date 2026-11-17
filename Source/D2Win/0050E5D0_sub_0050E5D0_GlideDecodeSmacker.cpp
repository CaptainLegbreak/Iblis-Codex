struct T004F51E0
{
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

struct D2RgbColorStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

struct D2GlideSmackStrc
{
    void* f_0;
    unsigned char nType;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x00683840
extern "C" __declspec(dllimport) void* __stdcall SmackOpen(const char* szName, unsigned int nFlags, unsigned int nExtraBuf); // 0x006CC604
extern "C" __declspec(dllimport) void __stdcall SmackClose(void* hSmack);                                   // 0x006CC608
extern "C" __declspec(dllimport) void __stdcall SmackToBuffer(void* hSmack, unsigned int nLeft, unsigned int nTop, unsigned int nPitch, unsigned int nHeight, void* pBuffer, unsigned int nFlags); // 0x006CC60C
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
int __stdcall SFileLoadFileEx(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped); // 0x0041B680
void __fastcall sub_0050E070_GlideSetSmackPalette(D2RgbColorStrc* pColors);                                 // 0x0050E070
void __cdecl sub_0050E330_GlideRefresh();                                                                    // 0x0050E330
int __stdcall sub_006C6A80_DecodeImage(int nMode, void* pData, int nSize, T004F51E0* pPalette, unsigned char* pDest, int nDestSize, int* pWidth, int* pHeight, int* pDepth); // 0x006C6A80

extern int gbRenderPaused_007C9144;                                                                         // 0x007C9144
extern unsigned char* gpGlideSmackBufferB_00880B70;                                                          // 0x00880B70
extern unsigned char* gpGlideSmackBufferC_00880B74;                                                          // 0x00880B74
unsigned char* gpGlideSmackBuffer_00880BF0;                                                                  // 0x00880BF0

// 0x0050E5D0
void __fastcall sub_0050E5D0_GlideDecodeSmacker(const char* szFile, D2GlideSmackStrc* pSmack, unsigned char nType)
{
    D2_ASSERT(gpGlideSmackBuffer_00880BF0, 142);
    memset(gpGlideSmackBuffer_00880BF0, 0, 0x8000);
    memset(gpGlideSmackBufferB_00880B70, 0, 0x8000);
    memset(gpGlideSmackBufferC_00880B74, 0, 0x8000);
    if (!gbRenderPaused_007C9144)
    {
        sub_0050E330_GlideRefresh();
    }

    pSmack->nType = nType;
    switch (nType)
    {
    case 's':
        if (pSmack->f_0)
        {
            return;
        }
        pSmack->f_0 = SmackOpen(szFile, 0xFE000, -1);
        if (!pSmack->f_0)
        {
            break;
        }
        SmackToBuffer(pSmack->f_0, 0, 0, 0x200, 0x40, gpGlideSmackBuffer_00880BF0, 0);
        return;

    case 'p':
    {
        void* pBuffer = 0;
        int nSize = 0;
        if (!SFileLoadFileEx(0, szFile, &pBuffer, &nSize, 0, 3, 0) || !pBuffer)
        {
            break;
        }

        T004F51E0 aPalette[256];
        int nWidth;
        int nHeight;
        int nDepth;
        const int bDecoded = sub_006C6A80_DecodeImage(2, pBuffer, nSize, aPalette, gpGlideSmackBuffer_00880BF0, 0x6DB0, &nWidth, &nHeight, &nDepth);
        SMemFree(pBuffer, ".\\Src\\glSmack.cpp", 219, 0);
        if (!bDecoded || nWidth != 468 || nHeight != 60 || nDepth != 8)
        {
            break;
        }

        D2RgbColorStrc aColors[256];
        for (int i = 0; i < 256; ++i)
        {
            aColors[i].nRed = aPalette[i].peRed;
            aColors[i].nGreen = aPalette[i].peGreen;
            aColors[i].nBlue = aPalette[i].peBlue;
        }

        for (int y = 59; y > 0; --y)
        {
            memmove(&gpGlideSmackBuffer_00880BF0[y * 0x200], &gpGlideSmackBuffer_00880BF0[y * nWidth], nWidth);
        }

        sub_0050E070_GlideSetSmackPalette(aColors);
        sub_0050E330_GlideRefresh();
        return;
    }

    default:
        return;
    }

    if (pSmack->nType == 's' && pSmack->f_0)
    {
        SmackClose(pSmack->f_0);
        pSmack->f_0 = 0;
    }
    pSmack->nType = 0;
}
