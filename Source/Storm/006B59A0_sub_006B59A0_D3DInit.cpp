extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
extern "C" int __cdecl atexit(void (__cdecl* pfnExit)());                                                   // 0x00683824
int __stdcall sub_006B1350_DirectDrawCreate(D2GuidStrc* pGuid, D2ComObjectStrc** ppDD, void* pUnkOuter);   // 0x006B1350
void __fastcall sub_006B20E0_ReportError(const char* szMessage, int hResult);                              // 0x006B20E0
void __cdecl sub_006B5990_Shutdown();                                                                       // 0x006B5990
void __cdecl sub_006B80A0();                                                                                // 0x006B80A0
void __cdecl sub_006B96C0();                                                                                // 0x006B96C0
void __cdecl sub_006B97D0();                                                                                // 0x006B97D0
void __cdecl sub_006B9A10();                                                                                // 0x006B9A10

extern const unsigned int gnDeviceFlagMask_006CE268;                                                        // 0x006CE268
extern const D2GuidStrc gIID_IDirectDraw4_006FF8D8;                                                         // 0x006FF8D8
extern const D2GuidStrc gIID_IDirect3D3_006FF558;                                                           // 0x006FF558
extern "C" const char gszD3DCoreFile_006FC120[];                                                            // 0x006FC120
extern void* gpCriticalSection_007C9134;                                                                    // 0x007C9134
extern int gnD3DArg1_007C9148;                                                                              // 0x007C9148
int gnD3DArg2_007C914C;                                                                                     // 0x007C914C
extern unsigned int gnDeviceFlags_0096F3A8;                                                                 // 0x0096F3A8
extern D2GuidStrc gDeviceGuid_0096F3AC;                                                                     // 0x0096F3AC
int gbD3DInitialized_00970E48;                                                                              // 0x00970E48
D2ComObjectStrc* gpDirectDraw4_00970E60;                                                                    // 0x00970E60
extern D2ComObjectStrc* gpDirect3D3_00970E64;                                                               // 0x00970E64

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

#include "gen/data/Source/Storm/006B59A0_sub_006B59A0_D3DInit.inc"
