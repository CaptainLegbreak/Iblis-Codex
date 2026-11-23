#include "D2Direct3D.h"

struct D2SurfaceDescStrc { unsigned int size, flags, height, width, pitch, backBuffers, refresh; unsigned int reserved1[14]; unsigned int bits; unsigned int reserved2[4]; unsigned int caps; unsigned int reserved3[4]; };
struct D2CapsStrc { unsigned int caps, caps2, caps3, caps4; };
struct D2DeviceStrc;
struct D2SurfaceStrc;
struct D2DeviceStrc
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
struct D2SurfaceStrc
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual void __stdcall Unused18() = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual void __stdcall Unused2C() = 0;
    virtual long __stdcall GetAttachedSurface(D2CapsStrc* pCaps, D2SurfaceStrc** ppSurface) = 0;
};
struct D2DrawStrc
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual long __stdcall CreateSurface(D2SurfaceDescStrc* pDesc, D2SurfaceStrc** ppSurface, void* pOuter) = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual void __stdcall Unused2C() = 0;
    virtual void __stdcall Unused30() = 0;
    virtual void __stdcall Unused34() = 0;
    virtual void __stdcall Unused38() = 0;
    virtual void __stdcall Unused3C() = 0;
    virtual void __stdcall Unused40() = 0;
    virtual void __stdcall Unused44() = 0;
    virtual void __stdcall Unused48() = 0;
    virtual void __stdcall Unused4C() = 0;
    virtual long __stdcall SetCooperativeLevel(void* hWnd, unsigned int dwFlags) = 0;
    virtual long __stdcall SetDisplayMode(unsigned int nWidth, unsigned int nHeight, unsigned int nBpp, unsigned int nRefresh, unsigned int dwFlags) = 0;
};
struct D2D3DStrc
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual void __stdcall Unused18() = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual long __stdcall CreateDevice(const void* rclsid, D2SurfaceStrc* pSurface, D2DeviceStrc** ppDevice, void* pOuter) = 0;
};
struct D2DisplayModeStrc { unsigned int flags,bits,width,height,refresh; };
struct D2DisplayContextStrc { unsigned int reserved[0x13c/4]; D2DisplayModeStrc modes[32]; int count; };
extern D2DrawStrc* gpDraw_00970E60; // 0x00970E60
extern D2D3DStrc* gpD3D_00970E64; // 0x00970E64
extern void* ghWindow_00970E84; // 0x00970E84
extern unsigned int ganWidths[2]; // 0x0074C000
extern unsigned int ganHeights[2]; // 0x0074C010
extern const unsigned int gadwHalGuid[4]; // 0x006FF518
extern const char gszTooMany[]; // 0x006FB86C
extern const char gszCoop[]; // 0x006FB83C
extern const char gszSetDisplayModeFailed[]; // 0x006FB810
extern const char gszPrimary[]; // 0x006FB7DC
extern const char gszAttached[]; // 0x006FB7AC
extern const char gszCreateHalDeviceFailed[]; // 0x006FB77C
extern const char gszCutscene[]; // 0x006DE0F4
void __cdecl sub_00410610_WriteLogLine(const char*,...); // 0x00410610
void __fastcall sub_006B39B0_ShowD3DError(const char*,long); // 0x006B39B0
extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0
// 0x006B3FD0
int __stdcall sub_006B3FD0_EnumerateDisplayMode(D2SurfaceDescStrc* mode,D2DisplayContextStrc* context)
{
    D2SurfaceStrc* primary=0;
    D2SurfaceStrc* attached=0;
    D2DeviceStrc* device=0;
    D2CapsStrc caps;
    D2SurfaceDescStrc desc;
    unsigned int flags=0;
    long result;
    if(!context) goto done;
    if(!mode || mode->size!=0x7c) return 0;
    if(context->count>=32) {
        sub_00410610_WriteLogLine(gszTooMany,context->count,32);
        if(device) { device->Release(); device=0; }
        if(attached) attached=0;
        if(primary) primary->Release();
        return 0;
    }
    if(mode->bits==32 && mode->width==640 && mode->height==480) flags=gdwBitMasks_006CE268[2];
    else if(mode->bits==24 && mode->width==640 && mode->height==480) flags=gdwBitMasks_006CE268[3];
    if(mode->bits==32 && mode->width==ganWidths[0] && mode->height==ganHeights[0]) flags|=gdwBitMasks_006CE268[1];
    if(mode->bits==32 && mode->width==ganWidths[1] && mode->height==ganHeights[1]) flags|=gdwBitMasks_006CE268[0];
    if(!flags) goto done;
    result=gpDraw_00970E60->SetCooperativeLevel(ghWindow_00970E84,0x11);
    if(result && result!=(long)0x88760245) { sub_006B20E0(gszCoop,result); goto cleanup; }
    result=gpDraw_00970E60->SetDisplayMode(mode->width,mode->height,mode->bits,mode->refresh,0);
    if(result) { sub_006B20E0(gszSetDisplayModeFailed,result); goto cleanup; }
    if(!(flags&gdwBitMasks_006CE268[0]) && !(flags&gdwBitMasks_006CE268[1])) {
        desc.size=sizeof(desc); memset(&desc.flags,0,sizeof(desc)-4); desc.flags=1; desc.caps=0x4200;
        result=gpDraw_00970E60->CreateSurface(&desc,&primary,0);
        if(result) { sub_006B20E0(gszCutscene,result); goto cleanup; }
    }
    else {
        desc.size=sizeof(desc); memset(&desc.flags,0,sizeof(desc)-4); desc.flags=0x21; desc.caps=0x6218; desc.backBuffers=1;
        result=gpDraw_00970E60->CreateSurface(&desc,&primary,0);
        if(result) { sub_006B20E0(gszPrimary,result); goto cleanup; }
        memset(&caps,0,sizeof(caps)); caps.caps=4;
        result=primary->GetAttachedSurface(&caps,&attached);
        if(result) { sub_006B20E0(gszAttached,result); goto cleanup; }
        gpD3D_00970E64->CreateDevice(gadwHalGuid,attached,&device,0);
        if(!device) { sub_006B39B0_ShowD3DError(gszCreateHalDeviceFailed,0); goto cleanup; }
    }
    {
        D2DisplayModeStrc* out=&context->modes[context->count];
        out->flags=flags; out->width=mode->width; out->height=mode->height; out->bits=mode->bits; out->refresh=mode->refresh;
        ++context->count;
    }
cleanup:
    if(device) { device->Release(); device=0; }
    if(attached) attached=0;
    if(primary) primary->Release();
done:

    return 1;
}

#include "gen/data/Source/D2Direct3D/Unknown_006B3FD0.inc"
