struct T004F51E0
{
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

struct SmackStrc
{
    unsigned int Version;
    unsigned int Width;
    unsigned int Height;
};

struct D2GdiSmackStrc
{
    SmackStrc* f_0;
    unsigned char nType;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) SmackStrc* __stdcall SmackOpen(const char* szName, unsigned int nFlags, unsigned int nExtraBuf); // 0x006CC604
extern "C" __declspec(dllimport) void __stdcall SmackClose(SmackStrc* hSmack);                              // 0x006CC608
extern "C" __declspec(dllimport) void __stdcall SmackToBuffer(SmackStrc* hSmack, unsigned int nLeft, unsigned int nTop, unsigned int nPitch, unsigned int nHeight, void* pBuffer, unsigned int nFlags); // 0x006CC60C
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
int __stdcall SFileLoadFileEx(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped); // 0x0041B680
unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210
int __stdcall sub_006C6A80_DecodeImage(int nMode, void* pData, int nSize, T004F51E0* pPalette, unsigned char* pDest, int nDestSize, int* pWidth, int* pHeight, int* pDepth); // 0x006C6A80

extern unsigned char gaGamePalette_007C8CC8[];                                                              // 0x007C8CC8
unsigned char gaGdiSmackPaletteMap_0098A178[256];                                                           // 0x0098A178
static unsigned char* gpGdiSmackBuffer_0098A278;                                                            // 0x0098A278
extern int gnGdiSmackFrame_0098A27C;                                                                        // 0x0098A27C

// 0x006C9710
void __fastcall sub_006C9710_GdiDecodeSmacker(const char* szFile, D2GdiSmackStrc* pSmack, unsigned char nType)
{
    pSmack->nType = nType;
    switch (nType)
    {
    case 's':
    {
        if (pSmack->f_0)
        {
            return;
        }
        SmackStrc* hSmack = SmackOpen(szFile, 0xFE000, -1);
        pSmack->f_0 = hSmack;
        if (!hSmack)
        {
            break;
        }
        gpGdiSmackBuffer_0098A278 = (unsigned char*)FOG_Alloc(hSmack->Width * hSmack->Height, ".\\Src\\gdiSmack.cpp", 67, 0);
        memset(gpGdiSmackBuffer_0098A278, 0, hSmack->Width * hSmack->Height);
        SmackToBuffer(pSmack->f_0, 0, 0, hSmack->Width, hSmack->Height, gpGdiSmackBuffer_0098A278, 0);
        gnGdiSmackFrame_0098A27C = 0;
        return;
    }

    case 'p':
    {
        gpGdiSmackBuffer_0098A278 = (unsigned char*)FOG_Alloc(0x6DB0, ".\\Src\\gdiSmack.cpp", 81, 0);
        memset(gpGdiSmackBuffer_0098A278, 0, 0x6DB0);

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
        const int bDecoded = sub_006C6A80_DecodeImage(2, pBuffer, nSize, aPalette, gpGdiSmackBuffer_0098A278, 0x6DB0, &nWidth, &nHeight, &nDepth);
        SMemFree(pBuffer, ".\\Src\\gdiSmack.cpp", 120, 0);
        if (!bDecoded || nWidth != 468 || nHeight != 60 || nDepth != 8)
        {
            break;
        }

        for (int i = 0; i < 256; ++i)
        {
            gaGdiSmackPaletteMap_0098A178[i] = sub_00605210_FindNearestColor(gaGamePalette_007C8CC8, 0x100, aPalette[i].peRed, aPalette[i].peGreen, aPalette[i].peBlue);
        }
        return;
    }

    default:
        return;
    }

    if (gpGdiSmackBuffer_0098A278)
    {
        FOG_Free(gpGdiSmackBuffer_0098A278, ".\\Src\\gdiSmack.cpp", 240, 0);
        gpGdiSmackBuffer_0098A278 = 0;
    }

    if (pSmack->nType == 's' && pSmack->f_0)
    {
        SmackClose(pSmack->f_0);
        pSmack->f_0 = 0;
    }
    pSmack->nType = 0;
}
