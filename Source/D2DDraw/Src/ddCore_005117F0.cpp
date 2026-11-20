#include "D2DDraw.h"

class D2DDrawSurfaceClass
{
public:
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall Slot0C(); virtual long __stdcall Slot10(); virtual long __stdcall Slot14();
    virtual long __stdcall Slot18(); virtual long __stdcall Slot1C(); virtual long __stdcall Slot20();
    virtual long __stdcall Slot24(); virtual long __stdcall Slot28(); virtual long __stdcall Slot2C();
    virtual long __stdcall Slot30(); virtual long __stdcall Slot34(); virtual long __stdcall Slot38();
    virtual long __stdcall Slot3C(); virtual long __stdcall Slot40(); virtual long __stdcall Slot44();
    virtual long __stdcall Slot48(); virtual long __stdcall Slot4C(); virtual long __stdcall Slot50();
    virtual long __stdcall Slot54(); virtual long __stdcall Slot58(); virtual long __stdcall Slot5C();
    virtual long __stdcall Slot60(); virtual long __stdcall Slot64(); virtual long __stdcall Slot68();
    virtual long __stdcall Slot6C(); virtual long __stdcall Slot70(); virtual long __stdcall Slot74();
    virtual long __stdcall Slot78(); virtual long __stdcall Slot7C();
    virtual long __stdcall Unlock(void* pRect);
};

class D2DirectDrawClass
{
public:
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

class D2DDrawPaletteClass
{
public:
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

class D2DDrawObjectClass
{
public:
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" long __stdcall DirectDrawCreate(void* pGuid, D2DirectDrawClass** ppDirectDraw, void* pUnkOuter); // 0x006B1350
extern "C" int __cdecl atexit(void (__cdecl* pfnExit)());                                                   // 0x00683824
int __cdecl sub_005114D0_SetDisplayMode();                                                                  // 0x005114D0
void __cdecl sub_00511A80_DDrawReleaseSurfaces();                                                           // 0x00511A80
void __cdecl sub_00511CD0_DDrawCloseAtExit();                                                               // 0x00511CD0
void __cdecl sub_00512430_DDrawCreateDebugFont();                                                           // 0x00512430
void __cdecl sub_005125B0_DDrawFreeDebugFont();                                                             // 0x005125B0

extern "C" const char szDirectDrawCreateFailed_006DE1B4[];                                                  // 0x006DE1B4
extern D2CriticalSectionStrc* gpRenderCriticalSection_007C9134;                                             // 0x007C9134
unsigned char gabDDrawDeviceGuid_00881144[16];                                                              // 0x00881144
int gbDDrawInitialized_00881260;                                                                            // 0x00881260
extern D2DirectDrawClass* gpDirectDraw_00881270;                                                            // 0x00881270
D2DDrawObjectClass* gpDDrawObject_00881274;                                                                 // 0x00881274
extern D2DDrawSurfaceClass* gpDDrawSurface_00881280;                                                        // 0x00881280
D2DDrawPaletteClass* gpDDrawObject_00881290;                                                                // 0x00881290

// 0x005117F0
int __fastcall sub_005117F0_DDrawEndDraw()
{
    long hResult = gpDDrawSurface_00881280->Unlock(0);
    if (hResult)
    {
        sub_005103B0("Unlock failed!", hResult);
        return 0;
    }

    gpScreenBuffer_007C9154 = 0;
    gpTileDrawFunctions_007C914C->pfFillYBufferTable(0, 0, 0, 0);
    D2_ASSERT(gpRenderCriticalSection_007C9134, 1036);
    LeaveCriticalSection(gpRenderCriticalSection_007C9134);
    return 1;
}

// 0x00511B10
int __fastcall sub_00511B10_DDrawPlayCutscene()
{
    if (gbRenderPaused_007C9144)
    {
        return 0;
    }

    sub_00511A80_DDrawReleaseSurfaces();
    return sub_005114D0_SetDisplayMode();
}

// 0x00511B30
int __fastcall sub_00511B30_DDrawCloseSurface()
{
    sub_00511A80_DDrawReleaseSurfaces();
    if (gpDDrawObject_00881290)
    {
        gpDDrawObject_00881290->Release();
        gpDDrawObject_00881290 = 0;
    }
    ghDDrawWindow_007C9140 = 0;
    return 1;
}

// 0x00511B80
int __fastcall sub_00511B80_DDrawClose()
{
    if (gbDDrawInitialized_00881260)
    {
        sub_00511A80_DDrawReleaseSurfaces();
        if (gpDDrawObject_00881290)
        {
            gpDDrawObject_00881290->Release();
            gpDDrawObject_00881290 = 0;
        }
        ghDDrawWindow_007C9140 = 0;
        if (gpDDrawObject_00881274)
        {
            gpDDrawObject_00881274->Release();
            gpDDrawObject_00881274 = 0;
        }
        if (gpDirectDraw_00881270)
        {
            gpDirectDraw_00881270->Release();
            gpDirectDraw_00881270 = 0;
        }
        if (gpRenderCriticalSection_007C9134)
        {
            DeleteCriticalSection(gpRenderCriticalSection_007C9134);
            FOG_Free(gpRenderCriticalSection_007C9134, ".\\Src\\ddCore.cpp", 293, 0);
            gpRenderCriticalSection_007C9134 = 0;
        }
        sub_005125B0_DDrawFreeDebugFont();
        gbDDrawInitialized_00881260 = 0;
    }
    return 1;
}

// 0x00511CE0
int __fastcall sub_00511CE0_DDrawInit(D2GfxSettingsStrc* pSettings, D2TileDrawFunctionsStrc* pHelpers)
{
    gpGfxSettings_007C9148 = pSettings;
    gpTileDrawFunctions_007C914C = pHelpers;
    sub_00512430_DDrawCreateDebugFont();
    long hResult;
    if (gdwVideoFlags_00881140 & gdwBitMasks[0])
    {
        hResult = DirectDrawCreate(0, &gpDirectDraw_00881270, 0);
    }
    else
    {
        hResult = DirectDrawCreate(gabDDrawDeviceGuid_00881144, &gpDirectDraw_00881270, 0);
    }

    if (hResult)
    {
        sub_005103B0(szDirectDrawCreateFailed_006DE1B4, hResult);
        return 0;
    }

    atexit(sub_00511CD0_DDrawCloseAtExit);
    gbDDrawInitialized_00881260 = 1;
    gpRenderCriticalSection_007C9134 = (D2CriticalSectionStrc*)FOG_Alloc(sizeof(D2CriticalSectionStrc), ".\\Src\\ddCore.cpp", 246, 0);
    InitializeCriticalSection(gpRenderCriticalSection_007C9134);
    return 1;
}
