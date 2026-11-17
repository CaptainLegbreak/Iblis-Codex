int __stdcall sub_005FDEA0_CheckSurface(void*, int, int); // 0x005FDEA0
void __fastcall sub_006B1EA0_SetMode(int); // 0x006B1EA0
void __fastcall sub_006B1F40_SetBlend(int); // 0x006B1F40
void __fastcall sub_006B2030_SetEnabled(int); // 0x006B2030
int __cdecl sub_006B9830_UseAlternate(); // 0x006B9830
int __stdcall sub_006B8950_DrawAlternate(void*, void*, int, int, int, unsigned char); // 0x006B8950
int __stdcall sub_006B87A0_DrawNormal(void*, void*, int, int, int, unsigned char); // 0x006B87A0
static __declspec(noinline) int __stdcall sub_006B8DF0_DrawConfigured(void*, int, int, int, void*, unsigned char);

// build: context sub_006B8DF0_DrawConfigured
// calling-convention shim (not game code)
static int __stdcall sub_006B8DF0_DrawConfigured(void* pSurface, int nA, int nB, int nC, void* pImage, unsigned char nAlpha)
{
    if (!sub_005FDEA0_CheckSurface(pSurface, 1, 0)) return 0;
    sub_006B1EA0_SetMode(1);
    sub_006B1F40_SetBlend(nAlpha == 255 ? 1 : 4);
    sub_006B2030_SetEnabled(1);
    if (sub_006B9830_UseAlternate())
        return sub_006B8950_DrawAlternate(pImage, pSurface, nA, nB, nC, nAlpha);
    return sub_006B87A0_DrawNormal(pImage, pSurface, nA, nB, nC, nAlpha);
}

// 0x006B8E60
int __fastcall sub_006B8E60_DrawRelay(void* pSurface, int nA, int nB, int nC, void* pImage, unsigned char nAlpha)
{
    return sub_006B8DF0_DrawConfigured(pSurface, nA, nB, nC, pImage, nAlpha);
}
