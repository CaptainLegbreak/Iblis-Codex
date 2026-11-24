#include "D2Direct3D.h"

#include "D2DDrawTypes.h"

#include "D2Win32Types.h"
#include "D2D3DTypes.h"

#define DD_CHECK(expr,message) { error=(expr); if(error) { sub_006B20E0_DDrawLogError(message,error); goto Fail; } }

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

void __fastcall sub_006B20E0_DDrawLogError(const char* szWhere, int hResult); // 0x006B20E0

void __fastcall sub_006B39B0_ShowD3DError(const char*,long); // 0x006B39B0

void __cdecl D3D_ReleaseResources(); // 0x006B3320

void __cdecl sub_006B3080(); // 0x006B3080

void __cdecl D3D_CreateTileSurfaces(); // 0x006BB5E0

void __cdecl sub_006B8F10(); // 0x006B8F10

void __fastcall D3D_SetTextureFilterMode(int); // 0x006B2030

static int D3D_InitFullscreen(void*,int); // 0x006B4FD0

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

extern D2ComObject006B58A0Strc* gpDirectDraw4; // 0x00970E60

extern D2DDPixelFormat006B58A0Strc gtWantedFormat_0074C024; // 0x0074C024

extern const unsigned char gabIidTexture[16]; // 0x006FF478

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

void __cdecl D3D_CloseAtExit(); // 0x006B5990

void __cdecl sub_006B80A0_InitializeDrawingGeometry(); // 0x006B80A0

void __cdecl sub_006B96C0_BuildScaleTable(); // 0x006B96C0

void __cdecl sub_006B97D0_BuildScaleTable(); // 0x006B97D0

void __cdecl D3D_SmackInit(); // 0x006B9A10

extern const unsigned int gnDeviceFlagMask_006CE268; // 0x006CE268

extern const D2GuidStrc gtIidDirectDraw4; // 0x006FF8D8

extern const D2GuidStrc gtIidDirect3D3; // 0x006FF558

extern "C" const char gszD3DCoreFile[]; // 0x006FC120

extern int gnD3DArg1_007C9148; // 0x007C9148

extern unsigned int gnDeviceFlags_0096F3A8; // 0x0096F3A8

extern D2GuidStrc gDeviceGuid_0096F3AC; // 0x0096F3AC

extern D2ComObjectStrc* gpDirect3D3; // 0x00970E64

extern D2GfxSettingsStrc* gpConfig_007C9148; // 0x007C9148

extern D2DDrawSurfaceStrc* gpDevice_00970E68; // 0x00970E68

void __fastcall sub_006BBCE0_Run(int a, int b, int c); // 0x006BBCE0

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);

D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78

int __cdecl D3D_Close(); // 0x006B5550

struct D2ComObject006B5550Strc;

struct D2ComObjectVtbl006B5550Strc;

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pCriticalSection);

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2ComObjectVtbl006B5550Strc
{
    long (__stdcall* QueryInterface)(D2ComObject006B5550Strc* pThis, const void* riid, void** ppv);
    unsigned long (__stdcall* AddRef)(D2ComObject006B5550Strc* pThis);
    unsigned long (__stdcall* Release)(D2ComObject006B5550Strc* pThis);
};

struct D2ComObject006B5550Strc
{
    D2ComObjectVtbl006B5550Strc* lpVtbl;
};

extern int gbD3DInitialized; // 0x00970E48

extern int gn_007C9140; // 0x007C9140

extern D2ComObject006B5550Strc* gpObject_00970E60; // 0x00970E60

extern "C" void __cdecl D3D_SmackFree(); // 0x006B9B00

extern D2CriticalSectionStrc* gpCriticalSection_007C9134; // 0x007C9134

extern int gnPaused_007C9144; // 0x007C9144

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);

void __fastcall sub_006B55E0_InitializeWindow(int, int); // 0x006B55E0

int gnState_00970E54; // 0x00970E54

int gnFilterMode; // 0x00970E5C

int gnState_00970E58; // 0x00970E58

void __fastcall sub_006B7F70_ClearTarget(int); // 0x006B7F70

void __fastcall sub_006B9710_SetColorComponents(int, int, int); // 0x006B9710

extern D2ComObjectStrc* gpInterface_00970E78; // 0x00970E78

void __cdecl sub_006B32B0_ReleaseRenderer(); // 0x006B32B0

void __cdecl sub_006B9150_ReleaseResource(); // 0x006B9150

void __cdecl D3D_ReleaseTileSurfaces(); // 0x006BB640

unsigned int gadwColors[256]; // 0x009702C0

unsigned short gawColors16[256]; // 0x0096FA80

extern D2DDSurfaceStrc* gpSurface_00970E6C; // 0x00970E6C

struct D2Device006B2030Strc;

struct D2DeviceVtbl006B2030Strc;

struct D2DeviceVtbl006B2030Strc
{
    void* unk_00[40];
    long (__stdcall* SetTextureStageState)(D2Device006B2030Strc* pDevice, unsigned long nStage, unsigned long nType, unsigned long nValue);
};

struct D2Device006B2030Strc
{
    D2DeviceVtbl006B2030Strc* lpVtbl;
};

extern int gbVideoUp; // 0x00970E40

extern int gnVideoState; // 0x00970E44

extern D2ComObjectStrc* gpPrimarySurface; // 0x00970E68

typedef long (__stdcall* D2DDFlipFn)(D2ComObjectStrc* pThis, D2ComObjectStrc* pTarget, unsigned long dwFlags);

extern int gdwGlobal_007B57E4; // 0x007B57E4

extern D2PaletteTableStrc* gpGfxPaletteView_007C9150; // 0x007C9150

D2PaletteTableStrc gPaletteView_0096F280; // 0x0096F280

extern D2ComObjectStrc* gpRenderSurface; // 0x00970E6C

extern D2ComObjectStrc* gpInterface; // 0x00970E70

extern D2ComObjectStrc* gpGammaControl; // 0x00970E74

extern D2ComObjectStrc* gpViewport; // 0x00970E7C

extern char gabGammaRamp[1536]; // 0x0096FCB8

typedef long (__stdcall* D2DDSetGammaRampFn)(D2ComObjectStrc* pThis, unsigned long dwFlags, void* pRamp);

extern unsigned int gnCapabilities_0096F3A8;                                                                // 0x0096F3A8

extern const unsigned int gdwBitMask7_006CE284;                                                             // 0x006CE284

extern const unsigned int gdwBitMask8;                                                             // 0x006CE288

void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...);                                          // 0x00410610

extern const unsigned int gnGammaMask_006CE278;                                                             // 0x006CE278

extern int gnGammaScale_0074C020;                                                                           // 0x0074C020

void __fastcall sub_006BE190_BuildGammaTable(int nGamma, void* pTable, double dScale, int nStride, int nEntries, int nMask); // 0x006BE190

extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, unsigned int nBytes);

D2ComObject006B5550Strc* gpObject_00970E64; // 0x00970E64

int gbD3DBusy; // 0x00970E50

int gnDeviceTextureFlag; // 0x00970E4C

int gpTileDrawFunctions; // 0x007C914C

int gbD3DInitialized_00970E48; // 0x00970E48

D2ComObjectStrc* gpDirectDraw4_00970E60; // 0x00970E60

int __cdecl D3D_InitCutsceneMode(); // 0x006B3420

extern unsigned int gnRenderFlags_0096F3A8; // 0x0096F3A8

extern const unsigned int gnRenderFlag_006CE284; // 0x006CE284

extern const unsigned int gnRenderFlag_006CE288; // 0x006CE288

extern "C" const char gszFailedToLockDest[];                                                       // 0x006FB130

extern "C" const char gszFailedToLockSource[];                                                     // 0x006FB14C

struct D2Object006BB3E0Strc;

struct D2Object006BADC0Strc;

struct D2DDrawDeviceStrc;

class CRegKeyInline;

struct D2Cache006BA830Strc;

struct D2DDCaps006B3420Strc;

struct D2DDSurfaceDesc006B3420Strc;

struct D2ComObject006B3420Strc;


extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(void* hKey, const char* szSubKey, unsigned long nReserved, char* szClass, unsigned long nOptions, unsigned long samDesired, void* pSecurity, void** phkResult, unsigned long* pDisposition); // 0x006CC004

extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey); // 0x006CC030

extern D2DDrawDeviceStrc gaDDrawDevices[]; // 0x0096F4E0

class CRegKeyInline
{
public:
    void* m_hKey;

    CRegKeyInline() : m_hKey(0) {}
    ~CRegKeyInline() { Close(); }

    long Close()
    {
        long lRes = 0;
        if (m_hKey != 0)
        {
            lRes = RegCloseKey(m_hKey);
            m_hKey = 0;
        }
        return lRes;
    }

    long Create(void* hKeyParent, const char* lpszKeyName, char* lpszClass = 0, unsigned long dwOptions = 0,
        unsigned long samDesired = 0x20006, void* lpSecAttr = 0, unsigned long* lpdwDisposition = 0)
    {
        unsigned long dw;
        void* hKey = 0;
        long lRes = RegCreateKeyExA(hKeyParent, lpszKeyName, 0, lpszClass, dwOptions, samDesired, lpSecAttr, &hKey, &dw);
        if (lpdwDisposition != 0)
            *lpdwDisposition = dw;
        if (lRes == 0)
        {
            lRes = Close();
            m_hKey = hKey;
        }
        return lRes;
    }

    long SetDWORDValue(const char* pszValueName, unsigned long dwValue)
    {
        return RegSetValueExA(m_hKey, pszValueName, 0, 4, (const unsigned char*)&dwValue, sizeof(unsigned long));
    }

    long SetStringValue(const char* pszValueName, const char* pszValue, unsigned long dwType = 1)
    {
        if (!pszValue)
            sub_006B1A30_ThrowAtlException(0x80004005);
        return RegSetValueExA(m_hKey, pszValueName, 0, dwType, (const unsigned char*)pszValue, (lstrlenA(pszValue) + 1) * sizeof(char));
    }

    long SetBinaryValue(const char* pszValueName, const void* pValue, unsigned long nBytes)
    {
        return RegSetValueExA(m_hKey, pszValueName, 0, 3, (const unsigned char*)pValue, nBytes);
    }
};

struct D2Cache006BA830Strc
{
    int unk0x00[7];
};

void __cdecl D3D_ReleaseSprites(); // 0x006B5B10

void __cdecl sub_006B7250_ReleaseAll(); // 0x006B7250

void __cdecl D3D_ReleaseSmackSurfaces(); // 0x006B9B30

void __fastcall sub_006BA830_FreeCache(D2Cache006BA830Strc* pCache, int bFree); // 0x006BA830

void __fastcall sub_006BADC0_Free(D2Object006BADC0Strc* pObject, int bFree); // 0x006BADC0

void __fastcall sub_006BB3E0_Free(D2Object006BB3E0Strc* pObject, int bFree); // 0x006BB3E0

extern int gdwGlobal_00970E8C; // 0x00970E8C

extern D2Object006BADC0Strc gObject_0096FC80; // 0x0096FC80

extern D2Object006BB3E0Strc gObject_0096FC9C; // 0x0096FC9C

extern D2Cache006BA830Strc gtTextureCache1; // 0x00970EC8

extern D2Cache006BA830Strc gtTextureCache2; // 0x00970EE4

extern D2Cache006BA830Strc gtTextureCache3; // 0x00970F00

extern void* ghDDrawWindow_007C9140; // 0x007C9140

struct D2DDCaps006B3420Strc
{
    unsigned int dwCaps;
    unsigned int dwCaps2;
    unsigned int dwCaps3;
    unsigned int dwCaps4;
};

struct D2DDSurfaceDesc006B3420Strc
{
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int aUnk0x08[24];
    D2DDCaps006B3420Strc tCaps;
    unsigned int dwTextureStage;
};

struct D2ComObject006B3420Strc
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual long __stdcall CreateSurface(D2DDSurfaceDesc006B3420Strc* pDesc, D2ComObject006B3420Strc** ppSurface, void* pOuter) = 0;
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
    virtual void __stdcall Unused50() = 0;
    virtual long __stdcall SetDisplayMode(unsigned int nWidth, unsigned int nHeight, unsigned int nBpp, unsigned int nRefresh, unsigned int dwFlags) = 0;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern D2ComObject006B3420Strc* gpPrimary_00970E68; // 0x00970E68

extern int gnRenderHeight; // 0x007C913C

void __fastcall sub_006B2F60_SaveVideoConfig(int nRender, int nDevice); // 0x006B2F60

// 0x006B1C10
void __fastcall sub_006B1C10_SetGlobal(int nValue)
{
    gdwGlobal_007B57E4 = nValue;
}

// 0x006B1C20
unsigned int __cdecl sub_006B1C20_GetMaskedFlags()
{
    return gnDeviceFlags_0096F3A8 & gnGammaMask_006CE278;
}

// 0x006B1C30
int __cdecl sub_006B1C30_SetMode()
{
    if (gpConfig_007C9148->bVSync)
        ((D2DDFlipFn)gpPrimarySurface->lpVtbl[11])(gpPrimarySurface, 0, 1);
    else
        ((D2DDFlipFn)gpPrimarySurface->lpVtbl[11])(gpPrimarySurface, 0, 9);
    return 1;
}

// 0x006B1C60
void __fastcall sub_006B1C60_GetScreenSize(int* pWidth, int* pHeight)
{
    *pWidth = gnRenderWidth;
    *pHeight = gnRenderHeight;
}

// 0x006B1C70
void __fastcall D3D_SetPalette(tagPALETTEENTRY* pPalette)
{
    for (int i = 0; i < 256; ++i)
    {
        gadwColors[i] = 0xFF000000 | (pPalette[i].peRed << 16) | (pPalette[i].peGreen << 8) | pPalette[i].peBlue;

        int nRed = pPalette[i].peRed >> 3;
        int nBlue = pPalette[i].peBlue >> 3;
        int nGreen = pPalette[i].peGreen >> 3;
        if (nRed < 31 && (pPalette[i].peRed & 7) >= 4)
            ++nRed;
        if (nBlue < 31 && (pPalette[i].peBlue & 7) >= 4)
            ++nBlue;
        if (nGreen < 31 && (pPalette[i].peGreen & 7) >= 4)
            ++nGreen;
        gawColors16[i] = (unsigned short)(0x8000 | (nRed << 10) | (nGreen << 5) | nBlue);

        if (!pPalette[i].peRed && !pPalette[i].peGreen && !pPalette[i].peBlue)
        {
            gadwColors[i] = 0;
            gawColors16[i] = 0;
        }
    }
}

// 0x006B1D50
unsigned int __fastcall sub_006B1D50_GetColor(unsigned int nIndex)
{
    return gadwColors[nIndex];
}

// 0x006B1D60
void __fastcall sub_006B1D60_SetPaletteView(const D2PaletteTableStrc* pSource)
{
    gPaletteView_0096F280 = *pSource;
    gpGfxPaletteView_007C9150 = &gPaletteView_0096F280;
}

// 0x006B1D80
void __fastcall sub_006B1D80_CopyRows(char* pSrc, char* pDst, int nBytes, int nRows, int nDstPitch, int nUnused)
{
    for (int i = 0; i < nRows; ++i)
    {
        memcpy(pDst, pSrc, nBytes);
        pSrc += nBytes;
        pDst += nDstPitch;
    }
}

// 0x006B1DC0
void __fastcall D3D_BlitIndexedToHighColor(const unsigned char* pSrc, unsigned short* pDst, int nWidth, int nHeight, int nDstPitch, int nUnused)
{
    unsigned short* pRowDst = pDst;
    const unsigned char* pRowSrc = pSrc;
    for (int y = 0; y < nHeight; ++y)
    {
        unsigned short* d = pRowDst;
        const unsigned char* s = pRowSrc;
        for (int x = 0; x < nWidth; ++x)
        {
            *d++ = gawColors16[*s++];
        }
        pRowSrc += nWidth;
        pRowDst += nDstPitch;
    }
}

// 0x006B1E30
void __fastcall sub_006B1E30_Blit8To32(const unsigned char* pSource, unsigned int* pDest, int nWidth, int nHeight, int nPitch, int nUnused)
{
    unsigned int* pDRow = pDest;
    const unsigned char* pRow = pSource;
    if (nHeight > 0)
    {
        nPitch *= 4;
        int y = nHeight;
        do
        {
            unsigned int* pDst = (unsigned int*)pDRow;
            const unsigned char* pSrc = pRow;
            if (nWidth > 0)
            {
                int x = nWidth;
                do
                {
                    *pDst++ = gadwColors[*pSrc++];
                    --x;
                } while (x);
            }
            pRow += nWidth;
            pDRow = (unsigned int*)((char*)pDRow + nPitch);
            --y;
        } while (y);
    }
}

// 0x006B1EA0
void __fastcall D3D_SetColorCombineMode(int nState)
{
    if (gnState_00970E54 && nState == gnState_00970E54)
        return;
    switch (nState)
    {
    case 1:
        gpDevice->SetTextureStageState(0, 1, 4);
        gpDevice->SetTextureStageState(0, 4, 4);
        gpDevice->SetRenderState(15, 1);
        break;
    case 2:
        gpDevice->SetTextureStageState(0, 1, 3);
        gpDevice->SetTextureStageState(0, 4, 3);
        gpDevice->SetRenderState(15, 0);
        break;
    }
    gnState_00970E54 = nState;
}

// 0x006B1F40
void __fastcall D3D_SetAlphaBlendMode(int nState)
{
    if (gnState_00970E58 && nState == gnState_00970E58)
        return;
    switch (nState)
    {
    case 1:
        gpDevice->SetRenderState(27, 0);
        gpDevice->SetRenderState(19, 2);
        gpDevice->SetRenderState(20, 1);
        break;
    case 2:
        gpDevice->SetRenderState(27, 1);
        gpDevice->SetRenderState(19, 2);
        gpDevice->SetRenderState(20, 2);
        break;
    case 3:
        gpDevice->SetRenderState(27, 1);
        gpDevice->SetRenderState(19, 1);
        gpDevice->SetRenderState(20, 3);
        break;
    case 4:
        gpDevice->SetRenderState(27, 1);
        gpDevice->SetRenderState(19, 5);
        gpDevice->SetRenderState(20, 6);
        break;
    }
    gnState_00970E58 = nState;
}

// 0x006B2030
void __fastcall D3D_SetTextureFilterMode(int nMode)
{
    if (gnFilterMode && nMode == gnFilterMode)
    {
        return;
    }
    switch (nMode)
    {
    case 1:
        gpDevice->SetTextureStageState(0, 16, 1);
        gpDevice->SetTextureStageState(0, 17, 1);
        break;
    case 2:
        gpDevice->SetTextureStageState(0, 16, 2);
        gpDevice->SetTextureStageState(0, 17, 2);
        break;
    }
    gnFilterMode = nMode;
}

// 0x006B3320
void __cdecl D3D_ReleaseResources()
{
    if (!gbVideoUp)
    {
        return;
    }

    sub_006B9150_ReleaseResource();
    D3D_ReleaseTileSurfaces();
    sub_006B32B0_ReleaseRenderer();

    if (gpViewport)
    {
        ((D2ComReleaseFn)gpViewport->lpVtbl[2])(gpViewport);
        gpViewport = 0;
    }

    if (gpInterface_00970E78)
    {
        ((D2ComReleaseFn)gpInterface_00970E78->lpVtbl[2])(gpInterface_00970E78);
        gpInterface_00970E78 = 0;
    }

    if (gpGammaControl)
    {
        const long hResult = ((D2DDSetGammaRampFn)gpGammaControl->lpVtbl[4])(gpGammaControl, 0, gabGammaRamp);
        if (hResult && hResult != (long)0x887601C2)
        {
            sub_006B20E0_DDrawLogError("Failed to restore original gamma ramp", hResult);
        }
        ((D2ComReleaseFn)gpGammaControl->lpVtbl[2])(gpGammaControl);
        gpGammaControl = 0;
    }

    if (gpInterface)
    {
        ((D2ComReleaseFn)gpInterface->lpVtbl[2])(gpInterface);
        gpInterface = 0;
    }

    if (gpRenderSurface)
    {
        ((D2ComReleaseFn)gpRenderSurface->lpVtbl[2])(gpRenderSurface);
        gpRenderSurface = 0;
    }

    if (gpPrimarySurface)
    {
        ((D2ComReleaseFn)gpPrimarySurface->lpVtbl[2])(gpPrimarySurface);
        gpPrimarySurface = 0;
    }

    gbVideoUp = 0;
    gnVideoState = 0;
}

// 0x006B3400
int __cdecl sub_006B3400_ReleaseWindow()
{
    D3D_ReleaseResources();
    ghDDrawWindow_007C9140 = 0;
    return 1;
}

// 0x006B3420
int __cdecl D3D_InitCutsceneMode()
{
    D2_ASSERT(!gbVideoUp, 0x7CB);

// build: symbol ?gnRenderWidth@* 0x007C9138
    gnRenderWidth = 640;
// build: symbol ?gnRenderHeight@* 0x007C913C
    gnRenderHeight = 480;

    unsigned int nBpp = 16;
    if (gdwBitMask7_006CE284 & gnCapabilities_0096F3A8)
    {
        nBpp = 32;
    }
    else if (gdwBitMask8 & gnCapabilities_0096F3A8)
    {
        nBpp = 24;
    }

    const char* szError;
    long hResult = gpDraw->SetDisplayMode(640, 480, nBpp, 0, 0);
    if (hResult)
    {
        szError = "SetDisplayMode failed!";
        goto fail;
    }

    {
        SurfaceDesc tDesc = { sizeof(tDesc) };
        tDesc.flags = 1;
        tDesc.caps = 0x4200;
        hResult = gpDraw->CreateSurface(&tDesc, &gpPrimary, 0);
    }
    if (hResult)
    {
        szError = "Failed to create primary surface for cutscenes";
fail:
        sub_006B20E0_DDrawLogError(szError, hResult);
        LOGMANAGER_WriteLogLine("Opening Direct3D window for cutscenes failed!");
        return 0;
    }

    gbVideoUp = 1;
    gnVideoState = 1;
    return 1;
}

// 0x006B3530
int __cdecl sub_006B3530_BeginCutScene()
{
// build: symbol ?gbRenderPaused@* 0x007C9144
    if (gbRenderPaused)
    {
        return 0;
    }

    if (!(gnRenderFlags_0096F3A8 & gnRenderFlag_006CE284) && !(gnRenderFlags_0096F3A8 & gnRenderFlag_006CE288))
    {
        return 1;
    }

    D3D_ReleaseResources();
    return D3D_InitCutsceneMode();
}

struct D2GammaRampStrc
{
    int red[128];
    int green[128];
    int blue[128];
};

// 0x006B3570
void __fastcall D3D_SetGamma(int nGamma)
{
    D2GammaRampStrc ramp;
    if (gnCapabilities_0096F3A8 & gnGammaMask_006CE278)
    {
        sub_006BE190_BuildGammaTable(nGamma, (unsigned short*)ramp.red, gnGammaScale_0074C020, 2, 256, 65535);
        memcpy(ramp.green, ramp.red, sizeof(ramp.red));
        memcpy(ramp.blue, ramp.red, sizeof(ramp.red));
        if (gpGammaControl)
        {
            int nResult = ((D2DDSetGammaRampFn)gpGammaControl->lpVtbl[4])(gpGammaControl, 0, &ramp);
            if (nResult)
                sub_006B20E0_DDrawLogError("Failed to set gamma ramp", nResult);
        }
    }
}

// 0x006B3610
int __fastcall D3D_GetBackBuffer(unsigned char* pDst)
{
    D2DDSurfaceDesc2Strc tDesc = { sizeof(D2DDSurfaceDesc2Strc) };
    if (!gpSurface_00970E6C)
    {
        return 0;
    }

    long hResult = gpSurface_00970E6C->lpVtbl->Lock(gpSurface_00970E6C, 0, &tDesc, 0x11, 0);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError("Lock failed!", hResult);
        return 0;
    }

    int nPitch = tDesc.lPitch / 4;
    unsigned char* pOutRow = pDst;
    unsigned int* pSrcRow = (unsigned int*)tDesc.lpSurface;
    for (int y = 0; y < gnRenderHeight; ++y)
    {
        unsigned char* pOut = pOutRow;
        unsigned int* pSrc = pSrcRow;
        for (int x = 0; x < gnRenderWidth; ++x)
        {
            unsigned int dwPixel = *pSrc++;
            *pOut++ = (unsigned char)(dwPixel >> 16);
            *pOut++ = (unsigned char)(dwPixel >> 8);
            *pOut++ = (unsigned char)dwPixel;
        }
        pOutRow += gnRenderWidth * 3;
        pSrcRow += nPitch;
    }

    hResult = gpSurface_00970E6C->lpVtbl->Unlock(gpSurface_00970E6C, 0);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError("Unlock failed!", hResult);
        return 0;
    }
    return 1;
}

// 0x006B3730
int __fastcall D3D_CreateMemoryTexture(D2ComObject006B58A0Strc** ppSurface, D2ComObject006B58A0Strc** ppTexture, unsigned int nWidth, unsigned int nHeight)
{
    D2DDSurfaceDesc006B58A0Strc tDesc = { sizeof(tDesc) };
    tDesc.dwFlags = 0x1007;
    tDesc.dwCaps = 0x840;
    tDesc.tPixelFormat = gtWantedFormat_0074C024;
    tDesc.dwWidth = nWidth;
    tDesc.dwHeight = nHeight;
    long hResult = gpDirectDraw4->lpVtbl->CreateSurface(gpDirectDraw4, &tDesc, ppSurface, 0);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError("CreateSurface (memory surface)", hResult);
        return 0;
    }
    hResult = (*ppSurface)->lpVtbl->QueryInterface(*ppSurface, gabIidTexture, (void**)ppTexture);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError("Failed to get texture interface for memory surface", hResult);
        (*ppSurface)->lpVtbl->Release(*ppSurface);
        return 0;
    }
    return 1;
}

// 0x006B38A0
void __fastcall sub_006B38A0_Copy(D2DDSurfaceStrc* pDst, D2DDSurfaceStrc* pSrc, unsigned int nRows)
{
    unsigned char* pSrcBits;
    unsigned char* pDstBits;
    unsigned int nDstPitch;
    unsigned int nWidth;
    D2DDSurfaceDesc2Strc tSrcDesc = { sizeof(D2DDSurfaceDesc2Strc) };
    long hResult = pSrc->lpVtbl->Lock(pSrc, 0, &tSrcDesc, 0x21, 0);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError(gszFailedToLockSource, hResult);
    }
    else
    {
        pSrcBits = (unsigned char*)tSrcDesc.lpSurface;
        D2DDSurfaceDesc2Strc tDstDesc = { sizeof(D2DDSurfaceDesc2Strc) };
        hResult = pDst->lpVtbl->Lock(pDst, 0, &tDstDesc, 0x21, 0);
        if (hResult)
        {
            sub_006B20E0_DDrawLogError(gszFailedToLockDest, hResult);
        }
        else
        {
            nDstPitch = tDstDesc.lPitch;
            nWidth = tSrcDesc.lPitch;
            pDstBits = (unsigned char*)tDstDesc.lpSurface;
            nWidth = nWidth < nDstPitch ? nWidth : nDstPitch;
            unsigned int nLeft = nRows;
            while (nLeft--)
            {
                memcpy(pDstBits, pSrcBits, nWidth);

                if (nLeft && (int)pDst < 0 && (int)pSrc < 0 && nWidth) pDstBits += nDstPitch; else pDstBits += nDstPitch;
                pSrcBits += tSrcDesc.lPitch;
            }
        }
    }
    pSrc->lpVtbl->Unlock(pSrc, 0);
    pDst->lpVtbl->Unlock(pDst, 0);
}

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
        LOGMANAGER_WriteLogLine(gszTooMany,context->count,32);
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

// 0x006B4FD0
static int D3D_InitFullscreen(void* window,int mode)
{
    if(gnInitialized) { sub_00408A60(&gszEmptyAssertText,sub_00408090(),0x50F); exit(-1); }
    long error;
    const char* msg;
    ghWindow=window;
    if(mode==0) { gnWidth=640; gnHeight=480; } else { gnWidth=800; gnHeight=600; }
    switch(mode) { case 0: case 2: gnModeFlag=1; break; default: gnModeFlag=0; break; }
    DD_CHECK(gpDraw->SetCooperativeLevel(window,0x411),gCoopError);
    error=gpDraw->SetDisplayMode(gnWidth,gnHeight,32,0,0);
    if(error) { sub_006B20E0_DDrawLogError(gDisplayError,error); return 0; }
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
    if(error) sub_006B20E0_DDrawLogError(gTextureError,error);
    memset(&caps,0,sizeof(caps)); caps.flags=0x10005000;
    error=gpDraw->GetAvailableMemory(&caps,&gnLocalTotal,&gnLocalFree);
    if(error) sub_006B20E0_DDrawLogError(gLocalError,error);
    if(gnFlags & gdwAgpMask)
    {
        memset(&caps,0,sizeof(caps)); caps.flags=0x20005000;
        error=gpDraw->GetAvailableMemory(&caps,&gnAgpTotal,&gnAgpFree);
        if(error) sub_006B20E0_DDrawLogError(gAgpError,error);
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
    D3D_SetTextureFilterMode(1);
    gpDevice->SetTextureStageState(0,2,2);
    gpDevice->SetTextureStageState(0,3,0);
    gpDevice->SetTextureStageState(0,5,2);
    gpDevice->SetTextureStageState(0,6,0);
    sub_006B3080(); D3D_CreateTileSurfaces(); sub_006B8F10();
    return 1;
D3DFail:
    sub_006B39B0_ShowD3DError(msg,error);
Fail:
    D3D_ReleaseResources(); ghWindow=0; return 0;
}

// 0x006B5520
void __cdecl D3D_FlushAndFlip()
{
    sub_006B3800_Flush();
    if (gpConfig_007C9148->bVSync)
    {
        gpDevice_00970E68->lpVtbl->Flip(gpDevice_00970E68, 0, 1);
    }
    else
    {
        gpDevice_00970E68->lpVtbl->Flip(gpDevice_00970E68, 0, 9);
    }
}

// 0x006B5550
int __cdecl D3D_Close()
{
    if (gbD3DInitialized)
    {
        D3D_SmackFree();
        D3D_ReleaseResources();
        gn_007C9140 = 0;
        RELEASE(gpObject_00970E64);
        RELEASE(gpObject_00970E60);
        if (gpLock_007C9134)
        {
            DeleteCriticalSection(gpLock_007C9134);
            FOG_Free(gpLock_007C9134, ".\\Src\\d3dCore.cpp", 0x71D, 0);
            gpLock_007C9134 = 0;
        }
        gbD3DInitialized = 0;
    }
    return 1;
}

// 0x006B55E0
int __fastcall D3D_CreateSurface(void* window,int mode)
{
    if (gnInitialized)
        return 1;

    if (!D3D_InitFullscreen(window, mode))
        return 0;

    sub_006B3800_Flush();
    if (gpOptions->flag)
        gpPrimary->Flip(0, 1);
    else
        gpPrimary->Flip(0, 9);
    return 1;
}

// 0x006B5630
void __fastcall D3D_PauseSurface(int window, int mode, int paused)
{
    if (!gpCriticalSection_007C9134) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x7b0); exit(-1); }
    EnterCriticalSection(gpCriticalSection_007C9134);
    if (paused) {
        gnPaused_007C9144 = 1;
        D3D_ReleaseResources();
        gn_007C9140 = 0;
    }
    else {
        gnPaused_007C9144 = 0;
        sub_006B55E0_InitializeWindow(window, mode);
    }
    LeaveCriticalSection(gpCriticalSection_007C9134);
}

// 0x006B56C0
void __fastcall D3D_OpenSmackCutscene(int a, int b, int c)
{
    if (!gnWindowed)
    {
        gbD3DBusy = 1;
        sub_006B3800_Flush();
        if (gpConfig_007C9148->bVSync)
        {
            gpDevice_00970E68->lpVtbl->Flip(gpDevice_00970E68, 0, 1);
        }
        else
        {
            gpDevice_00970E68->lpVtbl->Flip(gpDevice_00970E68, 0, 9);
        }
        sub_006BBCE0_Run(a, b, c);
        gbD3DBusy = 0;
    }
}

// 0x006B5720
int __fastcall D3D_StartDraw(int clear, int unused, int unusedA, int unusedB)
{
    if (gnPaused_007C9144) return 0;
    if (!gpCriticalSection_007C9134) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x842); exit(-1); }
    EnterCriticalSection(gpCriticalSection_007C9134);
    if (clear) sub_006B7F70_ClearTarget(0);
    gnState_00970E54 = 0;
    gnState_00970E58 = 0;
    gnFilterMode = 0;
    sub_006B9710_SetColorComponents(255, 255, 255);
    long result = gpDevice_00970E78->lpVtbl->BeginScene(gpDevice_00970E78);
    if (result) sub_006B39B0_ShowD3DError("BeginScene failed!", result);
    return 1;
}

// 0x006B57D0
int __cdecl D3D_EndDraw()
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
int __fastcall D3D_ChangeRes(void* window,int mode)
{
    if (gnWindowed)
        return 1;

    D3D_ReleaseResources();
    ghWindow = 0;
    if (!D3D_InitFullscreen(window, mode))
        return 0;

    sub_006B3800_Flush();
    if (gpOptions->flag)
        gpPrimary->Flip(0, 1);
    else
        gpPrimary->Flip(0, 9);
    return 1;
}

// 0x006B58A0
int __fastcall D3D_CreateDeviceTexture(D2ComObject006B58A0Strc** ppSurface, D2ComObject006B58A0Strc** ppTexture, unsigned int nWidth, unsigned int nHeight)
{
    D2DDSurfaceDesc006B58A0Strc tDesc = { sizeof(tDesc) };
    tDesc.dwFlags = 0x1007;
    tDesc.aCaps2[0] = 0x80;
    tDesc.tPixelFormat = gtWantedFormat_0074C024;
    tDesc.dwWidth = nWidth;
    tDesc.dwHeight = nHeight;
    tDesc.dwCaps = gnDeviceTextureFlag ? 0x5000 : 0x10005000;
    long hResult = gpDirectDraw4->lpVtbl->CreateSurface(gpDirectDraw4, &tDesc, ppSurface, 0);
    if (hResult)
    {
        if (hResult != (long)0x8876017C)
        {
            sub_006B20E0_DDrawLogError("CreateSurface (device surface)", hResult);
        }
        return 0;
    }
    hResult = (*ppSurface)->lpVtbl->QueryInterface(*ppSurface, gabIidTexture, (void**)ppTexture);
    if (hResult)
    {
        sub_006B39B0_ShowD3DError("Failed to get texture interface for device surface", hResult);
        (*ppSurface)->lpVtbl->Release(*ppSurface);
        return 0;
    }
    return 1;
}

// 0x006B5990
void __cdecl D3D_CloseAtExit()
{
    D3D_Close();
}

// 0x006B59A0
int __fastcall D3D_Init(int nArg1, int nArg2)
{
    D2ComObjectStrc* pDirectDraw = 0;
    char tIdentifier[0x850];

    D2_ASSERT(!gbD3DInitialized_00970E48, 0x687);

    gnD3DArg1_007C9148 = nArg1;
    gpTileDrawFunctions = nArg2;

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
        sub_006B20E0_DDrawLogError("DirectDrawCreate failed!", hResult);
        return 0;
    }

    hResult = ((D2ComQueryInterfaceFn)pDirectDraw->lpVtbl[0])(pDirectDraw, &gtIidDirectDraw4, &gpDirectDraw4_00970E60);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError("Failed to get DirectDraw4 interface!", hResult);
        return 0;
    }

    ((D2ComReleaseFn)pDirectDraw->lpVtbl[2])(pDirectDraw);
    pDirectDraw = 0;

    hResult = ((D2ComQueryInterfaceFn)gpDirectDraw4_00970E60->lpVtbl[0])(gpDirectDraw4_00970E60, &gtIidDirect3D3, &gpDirect3D3);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError("Failed to get D3D interface!", hResult);
        return 0;
    }

    hResult = ((D2DDGetDeviceIdentifierFn)gpDirectDraw4_00970E60->lpVtbl[0x1B])(gpDirectDraw4_00970E60, tIdentifier, 0);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError("Failed to get device identifier interface!", hResult);
    }

    atexit(D3D_CloseAtExit);
    gbD3DInitialized_00970E48 = 1;
    sub_006B96C0_BuildScaleTable();
    sub_006B97D0_BuildScaleTable();
    sub_006B80A0_InitializeDrawingGeometry();
    D3D_SmackInit();
    gpCriticalSection_007C9134 = (D2CriticalSectionStrc*)FOG_Alloc(0x18, gszD3DCoreFile, 0x6EA, 0);
    InitializeCriticalSection(gpCriticalSection_007C9134);
    return 1;
}

// 0x006B20C0
int __fastcall sub_006B20C0_SetOption(int nId, int nValue)
{
    if (nId != 11)
        return 0;
    gnGammaScale_0074C020 = nValue;
    return 1;
}

// 0x006B20E0
void __fastcall sub_006B20E0_DDrawLogError(const char* szWhere, int hResult)
{
    const char* szError;
    switch (hResult)
    {
    case (int)0x80004005: szError = "DDERR_GENERIC"; break;
    case (int)0x80004001: szError = "DDERR_UNSUPPORTED"; break;
    case (int)0x800401F0: szError = "DDERR_NOTINITIALIZED"; break;
    case (int)0x80070057: szError = "DDERR_INVALIDPARAMS"; break;
    case (int)0x8007000E: szError = "DDERR_OUTOFMEMORY"; break;
    case (int)0x88760005: szError = "DDERR_ALREADYINITIALIZED"; break;
    case (int)0x8876000A: szError = "DDERR_CANNOTATTACHSURFACE"; break;
    case (int)0x88760014: szError = "DDERR_CANNOTDETACHSURFACE"; break;
    case (int)0x88760028: szError = "DDERR_CURRENTLYNOTAVAIL"; break;
    case (int)0x88760037: szError = "DDERR_EXCEPTION"; break;
    case (int)0x8876005A: szError = "DDERR_HEIGHTALIGN"; break;
    case (int)0x8876005F: szError = "DDERR_INCOMPATIBLEPRIMARY"; break;
    case (int)0x88760064: szError = "DDERR_INVALIDCAPS"; break;
    case (int)0x8876006E: szError = "DDERR_INVALIDCLIPLIST"; break;
    case (int)0x88760078: szError = "DDERR_INVALIDMODE"; break;
    case (int)0x88760082: szError = "DDERR_INVALIDOBJECT"; break;
    case (int)0x88760091: szError = "DDERR_INVALIDPIXELFORMAT"; break;
    case (int)0x88760096: szError = "DDERR_INVALIDRECT"; break;
    case (int)0x887600A0: szError = "DDERR_LOCKEDSURFACES"; break;
    case (int)0x887600AA: szError = "DDERR_NO3D"; break;
    case (int)0x887600B4: szError = "DDERR_NOALPHAHW"; break;
    case (int)0x887600CD: szError = "DDERR_NOCLIPLIST"; break;
    case (int)0x887600D2: szError = "DDERR_NOCOLORCONVHW"; break;
    case (int)0x887600D4: szError = "DDERR_NOCOOPERATIVELEVELSET"; break;
    case (int)0x887600D7: szError = "DDERR_NOCOLORKEY"; break;
    case (int)0x887600DC: szError = "DDERR_NOCOLORKEYHW"; break;
    case (int)0x887600DE: szError = "DDERR_NODIRECTDRAWSUPPORT"; break;
    case (int)0x887600E1: szError = "DDERR_NOEXCLUSIVEMODE"; break;
    case (int)0x887600E6: szError = "DDERR_NOFLIPHW"; break;
    case (int)0x887600F0: szError = "DDERR_NOGDI"; break;
    case (int)0x887600FA: szError = "DDERR_NOMIRRORHW"; break;
    case (int)0x887600FF: szError = "DDERR_NOTFOUND"; break;
    case (int)0x88760104: szError = "DDERR_NOOVERLAYHW"; break;
    case (int)0x88760118: szError = "DDERR_NORASTEROPHW"; break;
    case (int)0x88760122: szError = "DDERR_NOROTATIONHW"; break;
    case (int)0x88760136: szError = "DDERR_NOSTRETCHHW"; break;
    case (int)0x8876013C: szError = "DDERR_NOT4BITCOLOR"; break;
    case (int)0x8876013D: szError = "DDERR_NOT4BITCOLORINDEX"; break;
    case (int)0x88760140: szError = "DDERR_NOT8BITCOLOR"; break;
    case (int)0x8876014A: szError = "DDERR_NOTEXTUREHW"; break;
    case (int)0x8876014F: szError = "DDERR_NOVSYNCHW"; break;
    case (int)0x88760154: szError = "DDERR_NOZBUFFERHW"; break;
    case (int)0x8876015E: szError = "DDERR_NOZOVERLAYHW"; break;
    case (int)0x88760168: szError = "DDERR_OUTOFCAPS"; break;
    case (int)0x8876017C: szError = "DDERR_OUTOFVIDEOMEMORY"; break;
    case (int)0x8876017E: szError = "DDERR_OVERLAYCANTCLIP"; break;
    case (int)0x88760180: szError = "DDERR_OVERLAYCOLORKEYONLYONEACTIVE"; break;
    case (int)0x88760183: szError = "DDERR_PALETTEBUSY"; break;
    case (int)0x88760190: szError = "DDERR_COLORKEYNOTSET"; break;
    case (int)0x8876019A: szError = "DDERR_SURFACEALREADYATTACHED"; break;
    case (int)0x887601A4: szError = "DDERR_SURFACEALREADYDEPENDENT"; break;
    case (int)0x887601AE: szError = "DDERR_SURFACEBUSY"; break;
    case (int)0x887601B3: szError = "DDERR_CANTLOCKSURFACE"; break;
    case (int)0x887601B8: szError = "DDERR_SURFACEISOBSCURED"; break;
    case (int)0x887601C2: szError = "DDERR_SURFACELOST"; break;
    case (int)0x887601CC: szError = "DDERR_SURFACENOTATTACHED"; break;
    case (int)0x887601D6: szError = "DDERR_TOOBIGHEIGHT"; break;
    case (int)0x887601E0: szError = "DDERR_TOOBIGSIZE"; break;
    case (int)0x887601EA: szError = "DDERR_TOOBIGWIDTH"; break;
    case (int)0x887601FE: szError = "DDERR_UNSUPPORTEDFORMAT"; break;
    case (int)0x88760208: szError = "DDERR_UNSUPPORTEDMASK"; break;
    case (int)0x88760219: szError = "DDERR_VERTICALBLANKINPROGRESS"; break;
    case (int)0x8876021C: szError = "DDERR_WASSTILLDRAWING"; break;
    case (int)0x88760230: szError = "DDERR_XALIGN"; break;
    case (int)0x88760231: szError = "DDERR_INVALIDDIRECTDRAWGUID"; break;
    case (int)0x88760232: szError = "DDERR_DIRECTDRAWALREADYCREATED"; break;
    case (int)0x88760233: szError = "DDERR_NODIRECTDRAWHW"; break;
    case (int)0x88760234: szError = "DDERR_PRIMARYSURFACEALREADYEXISTS"; break;
    case (int)0x88760235: szError = "DDERR_NOEMULATION"; break;
    case (int)0x88760236: szError = "DDERR_REGIONTOOSMALL"; break;
    case (int)0x88760237: szError = "DDERR_CLIPPERISUSINGHWND"; break;
    case (int)0x88760238: szError = "DDERR_NOCLIPPERATTACHED"; break;
    case (int)0x88760239: szError = "DDERR_NOHWND"; break;
    case (int)0x8876023A: szError = "DDERR_HWNDSUBCLASSED"; break;
    case (int)0x8876023B: szError = "DDERR_HWNDALREADYSET"; break;
    case (int)0x8876023C: szError = "DDERR_NOPALETTEATTACHED"; break;
    case (int)0x8876023D: szError = "DDERR_NOPALETTEHW"; break;
    case (int)0x8876023E: szError = "DDERR_BLTFASTCANTCLIP"; break;
    case (int)0x8876023F: szError = "DDERR_NOBLTHW"; break;
    case (int)0x88760240: szError = "DDERR_NODDROPSHW"; break;
    case (int)0x88760241: szError = "DDERR_OVERLAYNOTVISIBLE"; break;
    case (int)0x88760242: szError = "DDERR_NOOVERLAYDEST"; break;
    case (int)0x88760243: szError = "DDERR_INVALIDPOSITION"; break;
    case (int)0x88760244: szError = "DDERR_NOTAOVERLAYSURFACE"; break;
    case (int)0x88760245: szError = "DDERR_EXCLUSIVEMODEALREADYSET"; break;
    case (int)0x88760246: szError = "DDERR_NOTFLIPPABLE"; break;
    case (int)0x88760247: szError = "DDERR_CANTDUPLICATE"; break;
    case (int)0x88760248: szError = "DDERR_NOTLOCKED"; break;
    case (int)0x88760249: szError = "DDERR_CANTCREATEDC"; break;
    case (int)0x8876024A: szError = "DDERR_NODC"; break;
    case (int)0x8876024B: szError = "DDERR_WRONGMODE"; break;
    case (int)0x8876024C: szError = "DDERR_IMPLICITLYCREATED"; break;
    case (int)0x8876024D: szError = "DDERR_NOTPALETTIZED"; break;
    case (int)0x8876024E: szError = "DDERR_UNSUPPORTEDMODE"; break;
    case (int)0x8876024F: szError = "DDERR_NOMIPMAPHW"; break;
    case (int)0x88760250: szError = "DDERR_INVALIDSURFACETYPE"; break;
    case (int)0x88760258: szError = "DDERR_NOOPTIMIZEHW"; break;
    case (int)0x88760259: szError = "DDERR_NOTLOADED"; break;
    case (int)0x8876026C: szError = "DDERR_DCALREADYCREATED"; break;
    case (int)0x88760276: szError = "DDERR_NONONLOCALVIDMEM"; break;
    case (int)0x88760280: szError = "DDERR_CANTPAGELOCK"; break;
    case (int)0x88760294: szError = "DDERR_CANTPAGEUNLOCK"; break;
    case (int)0x887602A8: szError = "DDERR_NOTPAGELOCKED"; break;
    case (int)0x887602B2: szError = "DDERR_MOREDATA"; break;
    case (int)0x887602B7: szError = "DDERR_VIDEONOTACTIVE"; break;
    case (int)0x887602BB: szError = "DDERR_DEVICEDOESNTOWNSURFACE"; break;
    case (int)0x00000000: szError = "DD_OK"; break;
    default: szError = "< unknown >"; break;
    }

    LOGMANAGER_WriteLogLine("***** DirectDraw error: %s - %s (0x%x)", szWhere, szError, hResult);
}

#include "gen/data/Source/D2Direct3D/Src/d3dCore.inc"
