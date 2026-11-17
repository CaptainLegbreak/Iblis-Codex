struct D2ComObject006BB640Strc;
struct D2ComObjectVtbl006BB640Strc
{
    long (__stdcall* QueryInterface)(D2ComObject006BB640Strc* pThis, const void* riid, void** ppv);
    unsigned long (__stdcall* AddRef)(D2ComObject006BB640Strc* pThis);
    unsigned long (__stdcall* Release)(D2ComObject006BB640Strc* pThis);
};
struct D2ComObject006BB640Strc
{
    D2ComObject006BB640Strc* unk;
};
struct D2ComPtr006BB640Strc
{
    D2ComObjectVtbl006BB640Strc* lpVtbl;
};
D2ComPtr006BB640Strc* gpSurface_00989BF8;        // 0x00989BF8
D2ComPtr006BB640Strc* gpTexture_00989BFC;        // 0x00989BFC
extern D2ComPtr006BB640Strc* gpSurface_00989C00; // 0x00989C00
D2ComPtr006BB640Strc* gpTexture_00989C04;        // 0x00989C04

#define RELEASE(p) if (p) { p->lpVtbl->Release((D2ComObject006BB640Strc*)p); p = 0; }

// 0x006BB640
void __cdecl sub_006BB640_ReleaseSurfaces()
{
    RELEASE(gpTexture_00989BFC);
    RELEASE(gpSurface_00989BF8);
    RELEASE(gpTexture_00989C04);
    RELEASE(gpSurface_00989C00);
}
