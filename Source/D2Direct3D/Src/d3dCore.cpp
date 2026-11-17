#include "D2Direct3D.h"

#define DD_CHECK(expr,message) { error=(expr); if(error) { sub_006B20E0_LogDrawError(message,error); goto Fail; } }
#define D3D_CHECK(expr,message) { error=(expr); if(error) { msg=message; goto D3DFail; } }

struct Draw;
struct Surface;
struct Device;
struct D3D;
struct Gamma;
struct View;
struct D2ComObject006B58A0Strc;
struct SurfaceDesc;
struct Caps;
struct Viewport;
struct Guid;
struct WindowOptions;
struct D2DDPixelFormat006B58A0Strc;
struct D2DDSurfaceDesc006B58A0Strc;
struct D2ComObjectVtbl006B58A0Strc;
struct D2ComObjectStrc;
struct D2GuidStrc;
struct D2Device006B56C0Strc;
struct D2Direct3DDevice006B57D0Strc;
struct D2DeviceVtbl006B56C0Strc;
struct D2RenderConfig006B56C0Strc;
struct D2Direct3DDeviceVtbl006B57D0Strc;
struct D2CriticalSectionStrc;

struct SurfaceDesc { unsigned long size, flags, height, width; long pitch; unsigned long backBuffers; char unk18[80]; unsigned long caps; char unk6C[16]; };

struct Caps { unsigned long flags, flags2, flags3, flags4; };

struct Viewport { unsigned long size, x, y, width, height; float clipX, clipY, clipWidth, clipHeight, minZ, maxZ; };

struct Guid { unsigned long a; unsigned short b,c; unsigned char d[8]; };

struct Gamma
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual long __stdcall GetGammaRamp(unsigned long nFlags, void* pRamp) = 0;
};

struct Surface
{
    virtual long __stdcall QueryInterface(const Guid* riid, Gamma** ppGamma) = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual void __stdcall Unused18() = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual long __stdcall Flip(Surface* pOverride, unsigned long dwFlags) = 0;
    virtual long __stdcall GetAttachedSurface(Caps* pCaps, Surface** ppSurface) = 0;
};

struct Draw
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual long __stdcall CreateSurface(SurfaceDesc* pDesc, Surface** ppSurface, void* pOuter) = 0;
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
    virtual long __stdcall SetCooperativeLevel(void* hWnd, unsigned long dwFlags) = 0;
    virtual long __stdcall SetDisplayMode(unsigned long nWidth, unsigned long nHeight, unsigned long nBpp, unsigned long nRefresh, unsigned long dwFlags) = 0;
    virtual void __stdcall Unused58() = 0;
    virtual long __stdcall GetAvailableMemory(Caps* pCaps, unsigned long* pTotal, unsigned long* pFree) = 0;
};

struct View
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual void __stdcall Unused18() = 0;
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
    virtual long __stdcall SetViewport(Viewport* pViewport) = 0;
};

struct D3D
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual long __stdcall CreateViewport(View** ppView, void* pOuter) = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual long __stdcall CreateDevice(const Guid* rclsid, Surface* pSurface, Device** ppDevice, void* pOuter) = 0;
};

struct Device
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual long __stdcall AddViewport(View* pView) = 0;
    virtual void __stdcall Unused18() = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual void __stdcall Unused2C() = 0;
    virtual long __stdcall SetCurrentViewport(View* pView) = 0;
    virtual void __stdcall Unused34() = 0;
    virtual void __stdcall Unused38() = 0;
    virtual void __stdcall Unused3C() = 0;
    virtual void __stdcall Unused40() = 0;
    virtual void __stdcall Unused44() = 0;
    virtual void __stdcall Unused48() = 0;
    virtual void __stdcall Unused4C() = 0;
    virtual void __stdcall Unused50() = 0;
    virtual void __stdcall Unused54() = 0;
    virtual long __stdcall SetRenderState(unsigned long nState, unsigned long nValue) = 0;
    virtual void __stdcall Unused5C() = 0;
    virtual void __stdcall Unused60() = 0;
    virtual void __stdcall Unused64() = 0;
    virtual void __stdcall Unused68() = 0;
    virtual void __stdcall Unused6C() = 0;
    virtual void __stdcall Unused70() = 0;
    virtual void __stdcall Unused74() = 0;
    virtual void __stdcall Unused78() = 0;
    virtual void __stdcall Unused7C() = 0;
    virtual void __stdcall Unused80() = 0;
    virtual void __stdcall Unused84() = 0;
    virtual void __stdcall Unused88() = 0;
    virtual void __stdcall Unused8C() = 0;
    virtual void __stdcall Unused90() = 0;
    virtual void __stdcall Unused94() = 0;
    virtual void __stdcall Unused98() = 0;
    virtual void __stdcall Unused9C() = 0;
    virtual long __stdcall SetTextureStageState(unsigned long nStage, unsigned long nState, unsigned long nValue) = 0;
};

struct WindowOptions { char unk00[16]; int flag; };

extern int gnInitialized; // 0x00970E40
extern int gnState; // 0x00970E44
extern int gnModeFlag; // 0x00970E8C
extern int gnFlags; // 0x0096F3A8
extern const unsigned long gdwGammaMask; // 0x006CE278
extern const unsigned long gdwAgpMask; // 0x006CE26C
extern unsigned long gnWidth; // 0x007C9138
extern unsigned long gnHeight; // 0x007C913C
extern void* ghWindow; // 0x007C9140
extern int gnWindowed; // 0x007C9144
extern WindowOptions* gpOptions; // 0x007C9148
extern Draw* gpDraw; // 0x00970E60
extern D3D* gpD3D; // 0x00970E64
extern Surface* gpPrimary; // 0x00970E68
extern Surface* gpBack; // 0x00970E6C
extern Gamma* gpGamma; // 0x00970E74
extern Device* gpDevice; // 0x00970E78
extern View* gpView; // 0x00970E7C
extern unsigned char gGammaRamp[]; // 0x0096FCB8
extern const Guid gGammaGuid; // 0x006FF7C8
extern const Guid gDeviceGuid; // 0x006FF518
extern unsigned long gnTextureTotal; // 0x0096F4C4
extern unsigned long gnTextureFree; // 0x0096F4C8
extern unsigned long gnLocalTotal; // 0x0096F4CC
extern unsigned long gnLocalFree; // 0x0096F4D0
extern unsigned long gnAgpTotal; // 0x0096F4D4
extern unsigned long gnAgpFree; // 0x0096F4D8
extern const char gCoopError[]; // 0x006DE0A8
extern const char gDisplayError[]; // 0x006DE090
extern const char gSurfaceError[]; // 0x006FC108
extern const char gAttachedError[]; // 0x006FC0EC
extern const char gGammaInterfaceError[]; // 0x006FC0C4
extern const char gGammaError[]; // 0x006FC0A0
extern const char gDeviceError[]; // 0x006FC080
extern const char gCreateViewError[]; // 0x006FC064
extern const char gAddViewError[]; // 0x006FC040
extern const char gSetViewError[]; // 0x006FC02C
extern const char gCurrentViewError[]; // 0x006FC010
extern const char gTextureError[]; // 0x006FBAD8
extern const char gLocalError[]; // 0x006FBA74
extern const char gAgpError[]; // 0x006FBA1C
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0
extern "C" __declspec(dllimport) int __stdcall MoveWindow(void*,int,int,int,int,int); // 0x006CC444
void __fastcall sub_006B20E0_LogDrawError(const char*,long); // 0x006B20E0
void __fastcall sub_006B39B0_ShowD3DError(const char*,long); // 0x006B39B0
void __cdecl sub_006B3320_ReleaseSurfaces(); // 0x006B3320
void __cdecl sub_006B3800(); // 0x006B3800
void __cdecl sub_006B3080(); // 0x006B3080
void __cdecl sub_006BB5E0_CreateSurfaces(); // 0x006BB5E0
void __cdecl sub_006B8F10(); // 0x006B8F10
void __fastcall sub_006B2030_SetFilterMode(int); // 0x006B2030
__declspec(noinline) static int sub_006B4FD0_InitializeFullscreen(void*,int); // 0x006B4FD0

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
extern D2ComObject006B58A0Strc* gpDirectDraw_00970E60; // 0x00970E60
extern D2DDPixelFormat006B58A0Strc gtWantedFormat_0074C024; // 0x0074C024
extern const unsigned char gIidTexture_006FF478[16]; // 0x006FF478

struct D2ComObjectStrc
{
    void** lpVtbl;
};

typedef int (__stdcall* D2ComQueryInterfaceFn)(D2ComObjectStrc* pThis, const void* pIid, D2ComObjectStrc** ppOut);

typedef unsigned int (__stdcall* D2ComReleaseFn)(D2ComObjectStrc* pThis);

typedef int (__stdcall* D2DDGetDeviceIdentifierFn)(D2ComObjectStrc* pThis, void* pIdentifier, unsigned int dwFlags);

struct D2GuidStrc
{
    unsigned int dwData[4];
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* pCriticalSection);
extern "C" int __cdecl atexit(void (__cdecl* pfnExit)()); // 0x00683824
int __stdcall sub_006B1350_DirectDrawCreate(D2GuidStrc* pGuid, D2ComObjectStrc** ppDD, void* pUnkOuter); // 0x006B1350
void __fastcall sub_006B20E0_ReportError(const char* szMessage, int hResult); // 0x006B20E0
void __cdecl sub_006B5990_Shutdown(); // 0x006B5990
void __cdecl sub_006B80A0(); // 0x006B80A0
void __cdecl sub_006B96C0(); // 0x006B96C0
void __cdecl sub_006B97D0(); // 0x006B97D0
void __cdecl sub_006B9A10(); // 0x006B9A10
extern const unsigned int gnDeviceFlagMask_006CE268; // 0x006CE268
extern const D2GuidStrc gIID_IDirectDraw4_006FF8D8; // 0x006FF8D8
extern const D2GuidStrc gIID_IDirect3D3_006FF558; // 0x006FF558
extern "C" const char gszD3DCoreFile_006FC120[]; // 0x006FC120
extern void* gpCriticalSection_007C9134; // 0x007C9134
extern int gnD3DArg1_007C9148; // 0x007C9148
extern unsigned int gnDeviceFlags_0096F3A8; // 0x0096F3A8
extern D2GuidStrc gDeviceGuid_0096F3AC; // 0x0096F3AC
extern D2ComObjectStrc* gpDirect3D3_00970E64; // 0x00970E64

struct D2DeviceVtbl006B56C0Strc
{
    void* unk_00[11];
    long (__stdcall* SetState)(D2Device006B56C0Strc* pDevice, unsigned long nState, unsigned long nValue);
};

struct D2Device006B56C0Strc
{
    D2DeviceVtbl006B56C0Strc* lpVtbl;
};

struct D2RenderConfig006B56C0Strc
{
    unsigned char unk_00[0x10];
    int bFlag10;
};
extern D2RenderConfig006B56C0Strc* gpConfig_007C9148; // 0x007C9148
extern D2Device006B56C0Strc* gpDevice_00970E68; // 0x00970E68
void __fastcall sub_006BBCE0_Run(int a, int b, int c); // 0x006BBCE0

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);

struct D2Direct3DDeviceVtbl006B57D0Strc
{
    void* unk_00[10];
    long (__stdcall* EndScene)(D2Direct3DDevice006B57D0Strc* pDevice);
};

struct D2Direct3DDevice006B57D0Strc
{
    D2Direct3DDeviceVtbl006B57D0Strc* lpVtbl;
};

extern D2Direct3DDevice006B57D0Strc* gpDevice_00970E78; // 0x00970E78
void __cdecl sub_006B5550_ShutdownCore(); // 0x006B5550

// 0x006B4FD0
static int sub_006B4FD0_InitializeFullscreen(void* window,int mode)
{
    if(gnInitialized) { sub_00408A60(&gszEmptyAssertText,sub_00408090(),0x50F); exit(-1); }
    long error;
    const char* msg;
    ghWindow=window;
    if(mode==0) { gnWidth=640; gnHeight=480; } else { gnWidth=800; gnHeight=600; }
    switch(mode) { case 0: case 2: gnModeFlag=1; break; default: gnModeFlag=0; break; }
    DD_CHECK(gpDraw->SetCooperativeLevel(window,0x411),gCoopError);
    error=gpDraw->SetDisplayMode(gnWidth,gnHeight,32,0,0);
    if(error) { sub_006B20E0_LogDrawError(gDisplayError,error); return 0; }
    MoveWindow(window,0,0,gnWidth,gnHeight,1);
    gnInitialized=1; gnState=0;
    SurfaceDesc desc;
    desc.size=sizeof(desc);
    memset((char*)&desc+4,0,sizeof(desc)-4);
    desc.flags=0x21; desc.caps=0x6218; desc.backBuffers=1;
    DD_CHECK(gpDraw->CreateSurface(&desc,&gpPrimary,0),gSurfaceError);
    Caps caps;
    memset(&caps,0,sizeof(caps)); caps.flags=4;
    DD_CHECK(gpPrimary->GetAttachedSurface(&caps,&gpBack),gAttachedError);
    if(gnFlags & gdwGammaMask)
    {
        DD_CHECK(gpPrimary->QueryInterface(&gGammaGuid,&gpGamma),gGammaInterfaceError);
        DD_CHECK(gpGamma->GetGammaRamp(0,gGammaRamp),gGammaError);
    }
    D3D_CHECK(gpD3D->CreateDevice(&gDeviceGuid,gpBack,&gpDevice,0),gDeviceError);
    D3D_CHECK(gpD3D->CreateViewport(&gpView,0),gCreateViewError);
    D3D_CHECK(gpDevice->AddViewport(gpView),gAddViewError);
    Viewport viewport;
    memset(&viewport,0,sizeof(viewport));
    viewport.size=sizeof(viewport); viewport.x=0; viewport.y=0;
    viewport.width=gnWidth; viewport.height=gnHeight;
    viewport.clipX=0.0f; viewport.clipY=0.0f;
    viewport.clipWidth=(float)gnWidth; viewport.clipHeight=(float)gnHeight;
    viewport.minZ=0.0f; viewport.maxZ=1.0f;
    D3D_CHECK(gpView->SetViewport(&viewport),gSetViewError);
    D3D_CHECK(gpDevice->SetCurrentViewport(gpView),gCurrentViewError);
    memset(&caps,0,sizeof(caps)); caps.flags=0x5000;
    error=gpDraw->GetAvailableMemory(&caps,&gnTextureTotal,&gnTextureFree);
    if(error) sub_006B20E0_LogDrawError(gTextureError,error);
    memset(&caps,0,sizeof(caps)); caps.flags=0x10005000;
    error=gpDraw->GetAvailableMemory(&caps,&gnLocalTotal,&gnLocalFree);
    if(error) sub_006B20E0_LogDrawError(gLocalError,error);
    if(gnFlags & gdwAgpMask)
    {
        memset(&caps,0,sizeof(caps)); caps.flags=0x20005000;
        error=gpDraw->GetAvailableMemory(&caps,&gnAgpTotal,&gnAgpFree);
        if(error) sub_006B20E0_LogDrawError(gAgpError,error);
    }
    gpDevice->SetRenderState(29,0);
    gpDevice->SetRenderState(22,1);
    gpDevice->SetRenderState(4,0);
    gpDevice->SetRenderState(7,0);
    gpDevice->SetRenderState(14,0);
    gpDevice->SetRenderState(26,1);
    gpDevice->SetRenderState(25,6);
    gpDevice->SetRenderState(24,0);
    gpDevice->SetTextureStageState(0,12,3);
    sub_006B2030_SetFilterMode(1);
    gpDevice->SetTextureStageState(0,2,2);
    gpDevice->SetTextureStageState(0,3,0);
    gpDevice->SetTextureStageState(0,5,2);
    gpDevice->SetTextureStageState(0,6,0);
    sub_006B3080(); sub_006BB5E0_CreateSurfaces(); sub_006B8F10();
    return 1;
D3DFail:
    sub_006B39B0_ShowD3DError(msg,error);
Fail:
    sub_006B3320_ReleaseSurfaces(); ghWindow=0; return 0;
}

// 0x006B55E0
int __fastcall sub_006B55E0_InitWindow(void* window,int mode)
{
    if (gnInitialized)
        return 1;

    if (!sub_006B4FD0_InitializeFullscreen(window, mode))
        return 0;

    sub_006B3800();
    if (gpOptions->flag)
        gpPrimary->Flip(0, 1);
    else
        gpPrimary->Flip(0, 9);
    return 1;
}

int gbBusy_00970E50; // 0x00970E50

// 0x006B56C0
void __fastcall sub_006B56C0_RunWithState(int a, int b, int c)
{
    if (!gnWindowed)
    {
        gbBusy_00970E50 = 1;
        sub_006B3800_Flush();
        if (gpConfig_007C9148->bFlag10)
        {
            gpDevice_00970E68->lpVtbl->SetState(gpDevice_00970E68, 0, 1);
        }
        else
        {
            gpDevice_00970E68->lpVtbl->SetState(gpDevice_00970E68, 0, 9);
        }
        sub_006BBCE0_Run(a, b, c);
        gbBusy_00970E50 = 0;
    }
}

// 0x006B57D0
int __cdecl sub_006B57D0_EndScene()
{
    const long nResult = gpDevice_00970E78->lpVtbl->EndScene(gpDevice_00970E78);
    if (nResult)
    {
        sub_006B39B0_ShowD3DError("EndScene failed!", nResult);
    }
    D2_ASSERT(gpLock_007C9134, 0x8B3);
    LeaveCriticalSection(gpLock_007C9134);
    return 1;
}

// 0x006B5830
int __fastcall sub_006B5830_ResizeWindow(void* window,int mode)
{
    if (gnWindowed)
        return 1;

    sub_006B3320_ReleaseSurfaces();
    ghWindow = 0;
    if (!sub_006B4FD0_InitializeFullscreen(window, mode))
        return 0;

    sub_006B3800();
    if (gpOptions->flag)
        gpPrimary->Flip(0, 1);
    else
        gpPrimary->Flip(0, 9);
    return 1;
}

#include "gen/data/Source/D2Direct3D/Src/d3dCore.inc"

int gnDeviceTextureFlag_00970E4C; // 0x00970E4C

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

// 0x006B5990
void __cdecl sub_006B5990_Shutdown()
{
    sub_006B5550_ShutdownCore();
}

int gnD3DArg2_007C914C; // 0x007C914C

int gbD3DInitialized_00970E48; // 0x00970E48

D2ComObjectStrc* gpDirectDraw4_00970E60; // 0x00970E60

// 0x006B59A0
int __fastcall sub_006B59A0_D3DInit(int nArg1, int nArg2)
{
    D2ComObjectStrc* pDirectDraw = 0;
    char tIdentifier[0x850];

    D2_ASSERT(!gbD3DInitialized_00970E48, 0x687);

    gnD3DArg1_007C9148 = nArg1;
    gnD3DArg2_007C914C = nArg2;

    int hResult;
    if (gnDeviceFlags_0096F3A8 & gnDeviceFlagMask_006CE268)
    {
        hResult = sub_006B1350_DirectDrawCreate(0, &pDirectDraw, 0);
    }
    else
    {
        hResult = sub_006B1350_DirectDrawCreate(&gDeviceGuid_0096F3AC, &pDirectDraw, 0);
    }

    if (hResult)
    {
        sub_006B20E0_ReportError("DirectDrawCreate failed!", hResult);
        return 0;
    }

    hResult = ((D2ComQueryInterfaceFn)pDirectDraw->lpVtbl[0])(pDirectDraw, &gIID_IDirectDraw4_006FF8D8, &gpDirectDraw4_00970E60);
    if (hResult)
    {
        sub_006B20E0_ReportError("Failed to get DirectDraw4 interface!", hResult);
        return 0;
    }

    ((D2ComReleaseFn)pDirectDraw->lpVtbl[2])(pDirectDraw);
    pDirectDraw = 0;

    hResult = ((D2ComQueryInterfaceFn)gpDirectDraw4_00970E60->lpVtbl[0])(gpDirectDraw4_00970E60, &gIID_IDirect3D3_006FF558, &gpDirect3D3_00970E64);
    if (hResult)
    {
        sub_006B20E0_ReportError("Failed to get D3D interface!", hResult);
        return 0;
    }

    hResult = ((D2DDGetDeviceIdentifierFn)gpDirectDraw4_00970E60->lpVtbl[0x1B])(gpDirectDraw4_00970E60, tIdentifier, 0);
    if (hResult)
    {
        sub_006B20E0_ReportError("Failed to get device identifier interface!", hResult);
    }

    atexit(sub_006B5990_Shutdown);
    gbD3DInitialized_00970E48 = 1;
    sub_006B96C0();
    sub_006B97D0();
    sub_006B80A0();
    sub_006B9A10();
    gpCriticalSection_007C9134 = FOG_Alloc(0x18, gszD3DCoreFile_006FC120, 0x6EA, 0);
    InitializeCriticalSection(gpCriticalSection_007C9134);
    return 1;
}
