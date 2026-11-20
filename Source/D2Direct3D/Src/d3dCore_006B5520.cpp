#include "D2Direct3D.h"

struct D2Device006B5520Strc;
struct D2ComObject006B5550Strc;
struct D2Direct3DDeviceStrc;
struct D2DeviceVtbl006B5520Strc;
struct D2RenderConfig006B5520Strc;
struct D2ComObjectVtbl006B5550Strc;
struct D2Direct3DDeviceVtblStrc;

struct D2DeviceVtbl006B5520Strc
{
    void* unk_00[11];
    long (__stdcall* SetState)(D2Device006B5520Strc* pDevice, unsigned long nState, unsigned long nValue);
};

struct D2Device006B5520Strc
{
    D2DeviceVtbl006B5520Strc* lpVtbl;
};

struct D2RenderConfig006B5520Strc
{
    unsigned char unk_00[0x10];
    int bFlag10;
};

extern D2RenderConfig006B5520Strc* gpConfig_007C9148; // 0x007C9148
extern D2Device006B5520Strc* gpDevice_00970E68; // 0x00970E68

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

extern int gbCoreUp_00970E48; // 0x00970E48
extern int gn_007C9140; // 0x007C9140
extern D2ComObject006B5550Strc* gpObject_00970E60; // 0x00970E60
extern "C" void __cdecl sub_006B9B00_FreeGlobal(); // 0x006B9B00
void __cdecl sub_006B3320_ReleaseResources(); // 0x006B3320
extern D2CriticalSectionStrc* gpCriticalSection_007C9134; // 0x007C9134
extern int gnPaused_007C9144; // 0x007C9144
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
void __fastcall sub_006B55E0_InitializeWindow(int, int); // 0x006B55E0

struct D2Direct3DDeviceVtblStrc {
    void* unknown0[9];
    long (__stdcall* BeginScene)(D2Direct3DDeviceStrc*);
};

struct D2Direct3DDeviceStrc { D2Direct3DDeviceVtblStrc* vtable; };

extern int gnState_00970E54; // 0x00970E54
extern int gnState_00970E58; // 0x00970E58
extern int gnState_00970E5C; // 0x00970E5C
extern D2Direct3DDeviceStrc* gpDevice_00970E78; // 0x00970E78
void __fastcall sub_006B7F70_ClearTarget(int); // 0x006B7F70
void __fastcall sub_006B9710_SetColorComponents(int, int, int); // 0x006B9710
void __fastcall sub_006B39B0_ShowD3DError(const char*, long); // 0x006B39B0

// 0x006B5520
void __cdecl sub_006B5520_FlushAndSetState()
{
    sub_006B3800_Flush();
    if (gpConfig_007C9148->bFlag10)
    {
        gpDevice_00970E68->lpVtbl->SetState(gpDevice_00970E68, 0, 1);
    }
    else
    {
        gpDevice_00970E68->lpVtbl->SetState(gpDevice_00970E68, 0, 9);
    }
}

D2ComObject006B5550Strc* gpObject_00970E64; // 0x00970E64

// 0x006B5550
int __cdecl sub_006B5550_ShutdownCore()
{
    if (gbCoreUp_00970E48)
    {
        sub_006B9B00_FreeGlobal();
        sub_006B3320_ReleaseResources();
        gn_007C9140 = 0;
        RELEASE(gpObject_00970E64);
        RELEASE(gpObject_00970E60);
        if (gpLock_007C9134)
        {
            DeleteCriticalSection(gpLock_007C9134);
            FOG_Free(gpLock_007C9134, ".\\Src\\d3dCore.cpp", 0x71D, 0);
            gpLock_007C9134 = 0;
        }
        gbCoreUp_00970E48 = 0;
    }
    return 1;
}

// 0x006B5630
void __fastcall sub_006B5630_SetPaused(int window, int mode, int paused)
{
    if (!gpCriticalSection_007C9134) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x7b0); exit(-1); }
    EnterCriticalSection(gpCriticalSection_007C9134);
    if (paused) {
        gnPaused_007C9144 = 1;
        sub_006B3320_ReleaseResources();
        gn_007C9140 = 0;
    }
    else {
        gnPaused_007C9144 = 0;
        sub_006B55E0_InitializeWindow(window, mode);
    }
    LeaveCriticalSection(gpCriticalSection_007C9134);
}

// 0x006B5720
int __fastcall sub_006B5720_BeginScene(int clear, int unused, int unusedA, int unusedB)
{
    if (gnPaused_007C9144) return 0;
    if (!gpCriticalSection_007C9134) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x842); exit(-1); }
    EnterCriticalSection(gpCriticalSection_007C9134);
    if (clear) sub_006B7F70_ClearTarget(0);
    gnState_00970E54 = 0;
    gnState_00970E58 = 0;
    gnState_00970E5C = 0;
    sub_006B9710_SetColorComponents(255, 255, 255);
    long result = gpDevice_00970E78->vtable->BeginScene(gpDevice_00970E78);
    if (result) sub_006B39B0_ShowD3DError("BeginScene failed!", result);
    return 1;
}
