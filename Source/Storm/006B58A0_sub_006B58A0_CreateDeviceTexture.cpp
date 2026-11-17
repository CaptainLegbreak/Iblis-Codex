struct D2DDPixelFormat006B58A0Strc
{
    unsigned int aData[8];
};

struct D2DDSurfaceDesc006B58A0Strc
{
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int dwHeight;
    unsigned int dwWidth;
    unsigned int aUnk0x10[14];
    D2DDPixelFormat006B58A0Strc tPixelFormat;
    unsigned int dwCaps;
    unsigned int aCaps2[3];
    unsigned int dwTextureStage;
};

struct D2ComObject006B58A0Strc;
struct D2ComObjectVtbl006B58A0Strc
{
    long (__stdcall* QueryInterface)(D2ComObject006B58A0Strc* pThis, const void* pIid, void** ppOut);
    unsigned long (__stdcall* AddRef)(D2ComObject006B58A0Strc* pThis);
    unsigned long (__stdcall* Release)(D2ComObject006B58A0Strc* pThis);
    void* pfn0C;
    void* pfn10;
    void* pfn14;
    long (__stdcall* CreateSurface)(D2ComObject006B58A0Strc* pThis, D2DDSurfaceDesc006B58A0Strc* pDesc, D2ComObject006B58A0Strc** ppSurface, void* pOuter);
};
struct D2ComObject006B58A0Strc
{
    D2ComObjectVtbl006B58A0Strc* lpVtbl;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __fastcall sub_006B20E0_ReportError(const char* szWhat, long hResult); // 0x006B20E0
void __fastcall sub_006B39B0_ShowD3DError(const char* szText, long nResult); // 0x006B39B0
extern D2ComObject006B58A0Strc* gpDirectDraw_00970E60; // 0x00970E60
int gnDeviceTextureFlag_00970E4C;        // 0x00970E4C
extern D2DDPixelFormat006B58A0Strc gtWantedFormat_0074C024; // 0x0074C024
extern const unsigned char gIidTexture_006FF478[16]; // 0x006FF478

// 0x006B58A0
int __fastcall sub_006B58A0_CreateDeviceTexture(D2ComObject006B58A0Strc** ppSurface, D2ComObject006B58A0Strc** ppTexture, unsigned int nWidth, unsigned int nHeight)
{
    D2DDSurfaceDesc006B58A0Strc tDesc = { sizeof(tDesc) };
    tDesc.dwFlags = 0x1007;
    tDesc.aCaps2[0] = 0x80;
    tDesc.tPixelFormat = gtWantedFormat_0074C024;
    tDesc.dwWidth = nWidth;
    tDesc.dwHeight = nHeight;
    tDesc.dwCaps = gnDeviceTextureFlag_00970E4C ? 0x5000 : 0x10005000;
    long hResult = gpDirectDraw_00970E60->lpVtbl->CreateSurface(gpDirectDraw_00970E60, &tDesc, ppSurface, 0);
    if (hResult)
    {
        if (hResult != (long)0x8876017C)
        {
            sub_006B20E0_ReportError("CreateSurface (device surface)", hResult);
        }
        return 0;
    }
    hResult = (*ppSurface)->lpVtbl->QueryInterface(*ppSurface, gIidTexture_006FF478, (void**)ppTexture);
    if (hResult)
    {
        sub_006B39B0_ShowD3DError("Failed to get texture interface for device surface", hResult);
        (*ppSurface)->lpVtbl->Release(*ppSurface);
        return 0;
    }
    return 1;
}
