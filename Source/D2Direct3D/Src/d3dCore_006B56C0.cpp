#include "D2Direct3D.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2Device006B56C0Strc;
struct D2Direct3DDevice006B57D0Strc;
struct D2DeviceVtbl006B56C0Strc;
struct D2RenderConfig006B56C0Strc;
struct D2Direct3DDeviceVtbl006B57D0Strc;

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

extern int gbSkip_007C9144; // 0x007C9144
extern D2RenderConfig006B56C0Strc* gpConfig_007C9148; // 0x007C9148
extern D2Device006B56C0Strc* gpDevice_00970E68; // 0x00970E68
void __fastcall sub_006BBCE0_Run(int a, int b, int c); // 0x006BBCE0

struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090

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
void __fastcall sub_006B39B0_ShowD3DError(const char* szText, long nResult); // 0x006B39B0

int gbBusy_00970E50; // 0x00970E50

// 0x006B56C0
void __fastcall sub_006B56C0_RunWithState(int a, int b, int c)
{
    if (!gbSkip_007C9144)
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
