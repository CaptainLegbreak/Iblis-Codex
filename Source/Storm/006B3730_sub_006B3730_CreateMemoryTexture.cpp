struct D2DDPixelFormat006B3730Strc
{
    unsigned int aData[8];
};

struct D2DDSurfaceDesc006B3730Strc
{
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int dwHeight;
    unsigned int dwWidth;
    unsigned int aUnk0x10[14];
    D2DDPixelFormat006B3730Strc tPixelFormat;
    unsigned int dwCaps;
    unsigned int aCaps2[3];
    unsigned int dwTextureStage;
};

struct D2ComObject006B3730Strc;
struct D2ComObjectVtbl006B3730Strc
{
    long (__stdcall* QueryInterface)(D2ComObject006B3730Strc* pThis, const void* pIid, void** ppOut);
    unsigned long (__stdcall* AddRef)(D2ComObject006B3730Strc* pThis);
    unsigned long (__stdcall* Release)(D2ComObject006B3730Strc* pThis);
    void* pfn0C;
    void* pfn10;
    void* pfn14;
    long (__stdcall* CreateSurface)(D2ComObject006B3730Strc* pThis, D2DDSurfaceDesc006B3730Strc* pDesc, D2ComObject006B3730Strc** ppSurface, void* pOuter);
};
struct D2ComObject006B3730Strc
{
    D2ComObjectVtbl006B3730Strc* lpVtbl;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __fastcall sub_006B20E0_ReportError(const char* szWhat, long hResult); // 0x006B20E0
extern D2ComObject006B3730Strc* gpDirectDraw_00970E60; // 0x00970E60
extern D2DDPixelFormat006B3730Strc gtWantedFormat_0074C024; // 0x0074C024
extern const unsigned char gIidTexture_006FF478[16]; // 0x006FF478

// 0x006B3730
int __fastcall sub_006B3730_CreateMemoryTexture(D2ComObject006B3730Strc** ppSurface, D2ComObject006B3730Strc** ppTexture, unsigned int nWidth, unsigned int nHeight)
{
    D2DDSurfaceDesc006B3730Strc tDesc = { sizeof(tDesc) };
    tDesc.dwFlags = 0x1007;
    tDesc.dwCaps = 0x840;
    tDesc.tPixelFormat = gtWantedFormat_0074C024;
    tDesc.dwWidth = nWidth;
    tDesc.dwHeight = nHeight;
    long hResult = gpDirectDraw_00970E60->lpVtbl->CreateSurface(gpDirectDraw_00970E60, &tDesc, ppSurface, 0);
    if (hResult)
    {
        sub_006B20E0_ReportError("CreateSurface (memory surface)", hResult);
        return 0;
    }
    hResult = (*ppSurface)->lpVtbl->QueryInterface(*ppSurface, gIidTexture_006FF478, (void**)ppTexture);
    if (hResult)
    {
        sub_006B20E0_ReportError("Failed to get texture interface for memory surface", hResult);
        (*ppSurface)->lpVtbl->Release(*ppSurface);
        return 0;
    }
    return 1;
}

#include "gen/data/Source/Storm/006B3730_sub_006B3730_CreateMemoryTexture.inc"
