struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pCriticalSection);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
struct D2ComObject006B5550Strc;
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
D2ComObject006B5550Strc* gpObject_00970E64;        // 0x00970E64
extern D2ComObject006B5550Strc* gpObject_00970E60; // 0x00970E60
extern D2CriticalSectionStrc* gpLock_007C9134; // 0x007C9134
void __cdecl sub_006B9B00_FreeGlobal(); // 0x006B9B00
void __cdecl sub_006B3320_Free(); // 0x006B3320

#define RELEASE(p) if (p) { p->lpVtbl->Release(p); p = 0; }

// 0x006B5550
int __cdecl sub_006B5550_ShutdownCore()
{
    if (gbCoreUp_00970E48)
    {
        sub_006B9B00_FreeGlobal();
        sub_006B3320_Free();
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
