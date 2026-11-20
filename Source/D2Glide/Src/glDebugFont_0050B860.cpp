struct D2GlideFontVertexStrc
{
    float x;
    float y;
    int nColor;
    float oow;
    float sow;
    float tow;
    float unk0x18;
};

struct D2GrTexInfoStrc
{
    int nSmallLodLog2;
    int nLargeLodLog2;
    int nAspectRatioLog2;
    int nFormat;
    void* pData;
};

struct D2GlideDebugGlyphStrc
{
    unsigned char pixels[16][8];
};

typedef void (__stdcall* GlideTexDownloadMipMapFn)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo);

extern GlideTexDownloadMipMapFn gpfGlideTexDownloadMipMap_0087EAB8;                 // 0x0087EAB8
extern D2GrTexInfoStrc gGlideDebugFontTexInfo_0072F2B4;                             // 0x0072F2B4
int gaGlideDebugFontTexAddr_008800D8[96];                                           // 0x008800D8
D2GlideFontVertexStrc gaGlideDebugFontVertices_00880258[4];                         // 0x00880258
extern unsigned char* gpGlideDebugFontGlyphs_0088044C;                              // 0x0088044C
static int gnGlideDebugFontTmu_00880450;                                            // 0x00880450
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);       // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
#pragma intrinsic(memcpy)

static int __fastcall GlideAlignAddress(int nAddress, int nAlignment)
{
    if (nAddress & (nAlignment - 1))
        nAddress = (nAddress | (nAlignment - 1)) + 1;
    return nAddress;
}

// 0x0050B860
int __fastcall sub_0050B860_GlideDownloadDebugFont(int nStartAddress, int nAlignment)
{
    int nStride = GlideAlignAddress(0x80, nAlignment);
    int nTotal = nStride * 96;
    nStartAddress = GlideAlignAddress(nStartAddress, nAlignment);

    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(0x80, ".\\Src\\glDebugFont.cpp", 0x62, 0);
    gGlideDebugFontTexInfo_0072F2B4.pData = pBuffer;

    for (int nGlyph = 0; nGlyph < 96; ++nGlyph)
    {
        gaGlideDebugFontTexAddr_008800D8[nGlyph] = nStartAddress;
        memcpy(pBuffer, &gpGlideDebugFontGlyphs_0088044C[nGlyph * 0x80], 0x80);
        gpfGlideTexDownloadMipMap_0087EAB8(gnGlideDebugFontTmu_00880450, gaGlideDebugFontTexAddr_008800D8[nGlyph], 3, &gGlideDebugFontTexInfo_0072F2B4);
        nStartAddress += nStride;
    }

    FOG_Free(pBuffer, ".\\Src\\glDebugFont.cpp", 0x70, 0);

    gaGlideDebugFontVertices_00880258[0].x = 0.0f;
    gaGlideDebugFontVertices_00880258[0].y = 0.0f;
    gaGlideDebugFontVertices_00880258[0].nColor = -1;
    gaGlideDebugFontVertices_00880258[0].oow = 1.0f;
    gaGlideDebugFontVertices_00880258[1].oow = 1.0f;
    gaGlideDebugFontVertices_00880258[1].nColor = -1;
    gaGlideDebugFontVertices_00880258[0].sow = 0.0f;
    gaGlideDebugFontVertices_00880258[0].tow = 0.0f;
    gaGlideDebugFontVertices_00880258[1].x = 0.0f;
    gaGlideDebugFontVertices_00880258[1].y = 0.0f;
    gaGlideDebugFontVertices_00880258[1].sow = 0.0f;
    gaGlideDebugFontVertices_00880258[1].tow = 256.0f;
    gaGlideDebugFontVertices_00880258[2].x = 0.0f;
    gaGlideDebugFontVertices_00880258[2].y = 0.0f;
    gaGlideDebugFontVertices_00880258[2].nColor = -1;
    gaGlideDebugFontVertices_00880258[2].oow = 1.0f;
    gaGlideDebugFontVertices_00880258[2].sow = 128.0f;
    gaGlideDebugFontVertices_00880258[3].sow = 128.0f;
    gaGlideDebugFontVertices_00880258[2].tow = 256.0f;
    gaGlideDebugFontVertices_00880258[3].x = 0.0f;
    gaGlideDebugFontVertices_00880258[3].y = 0.0f;
    gaGlideDebugFontVertices_00880258[3].nColor = -1;
    gaGlideDebugFontVertices_00880258[3].tow = 0.0f;
    gaGlideDebugFontVertices_00880258[3].oow = 1.0f;

    return nTotal;
}

#include "gen/data/Source/D2Glide/Src/glDebugFont_0050B860.inc"
