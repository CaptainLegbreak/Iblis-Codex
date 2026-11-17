struct D2PaletteEntry006C7FA0Strc
{
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};
struct D2RgbQuad006C7FA0Strc
{
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
};
extern "C" __declspec(dllimport) unsigned int __stdcall SetPaletteEntries(void* hPalette, unsigned int nStart, unsigned int nEntries, const D2PaletteEntry006C7FA0Strc* pEntries);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern D2RgbQuad006C7FA0Strc gaColors_00989C40[256]; // 0x00989C40
extern void* ghPalette_0098A160; // 0x0098A160
extern D2PaletteEntry006C7FA0Strc gaPalette_007C8CC8[256]; // 0x007C8CC8

// 0x006C7FA0
void __fastcall sub_006C7FA0_SetPalette(D2PaletteEntry006C7FA0Strc* pEntries)
{
    for (int i = 0; i < 256; ++i)
    {
        gaColors_00989C40[i].rgbRed = pEntries[i].peRed;
        gaColors_00989C40[i].rgbGreen = pEntries[i].peGreen;
        gaColors_00989C40[i].rgbBlue = pEntries[i].peBlue;
    }
    SetPaletteEntries(ghPalette_0098A160, 0, 256, pEntries);
    memcpy(gaPalette_007C8CC8, pEntries, sizeof(gaPalette_007C8CC8));
}
