typedef int BOOL;

struct D2ComInterfaceStrc
{
    char unk0x00[0x10];
    void (__cdecl* pfnRelease)();
};

struct D2ConfigStrc
{
    int bIsExpansion;
    int nUnk0x04;
    unsigned char bWindow;
    unsigned char bNoFixedAspect;
    unsigned char b3DFX;
    unsigned char unk0x0B[2];
    unsigned char bD3D;
    unsigned char bPerspective;
    unsigned char bQuality;
    int nGamma;
    unsigned char bVSync;
    char unk0x15[0x1EF];
    unsigned char bDirect;
    unsigned char unk0x205;
    unsigned char bNoCompress;
    char unk0x207[0x19];
    unsigned char bNoSound;
    char unk0x221[3];
    unsigned char bSoundBackground;
    unsigned char pComInterface[4];
};

struct D2PoolSystemStrc;

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName);                   // 0x006CC144
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);     // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule);                                  // 0x006CC14C

int __stdcall sub_004059D0_RunModeInterface(D2ConfigStrc* pCfg);                                            // 0x004059D0
void __cdecl sub_00405A70();                                                                                // 0x00405A70
void __fastcall sub_00406870_InitStorm(int nDirectFlags, int nValue);                                       // 0x00406870
void __cdecl sub_00407970_ForceCrash();                                                                     // 0x00407970
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem);                                        // 0x00409C80
void __fastcall FOG_AsyncDataInitialize(int bEnable, int nUnused);                                          // 0x0040A390
void __cdecl FOG_AsyncDataDestroy();                                                                        // 0x0040A440
void __cdecl FOG_10218();                                                                                   // 0x0040B0C0
void __cdecl FOG_10082_Noop();                                                                              // 0x0040B320
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
void __cdecl D2MCPClientCloseMCP();                                                                         // 0x00449AD0
void __cdecl D2GFX_Release();                                                                               // 0x004F5050
void __stdcall D2GFX_SetPerspective(int bPerspective);                                                      // 0x004F51E0
int __stdcall D2GFX_SetGamma(int nGamma);                                                                   // 0x004F5230
void __cdecl D2GFX_EnableVSync();                                                                           // 0x004F5270
void __cdecl sub_004F5280();                                                                                 // 0x004F5280
void __cdecl D2GFX_ToggleLowQuality();                                                                      // 0x004F54F0
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
int __stdcall D2Win_InitializeSpriteCache(int bWindowed, int nResolution);                                  // 0x004F8F10
void __cdecl D2Win_CloseSpriteCache();                                                                      // 0x004F9030
int __stdcall D2Win_CreateWindow(void* hInstance, int nRenderMode, int bWindowed, int bCompress);           // 0x004FA520
int __cdecl ARCHIVE_ShowInsertExpansionDiscMessage();                                                       // 0x004FAB00
int __cdecl ARCHIVE_ShowInsertPlayDiscMessage();                                                            // 0x004FAB30
int __cdecl ARCHIVE_LoadArchives();                                                                         // 0x004FAB90
void __cdecl ARCHIVE_FreeArchives();                                                                        // 0x004FAE00
int __fastcall ARCHIVE_LoadExpansionArchives(int (__cdecl* pfnPlayDisc)(), int (__cdecl* pfnExpansionDisc)(), int nUnused, D2ConfigStrc* pCfg); // 0x004FAEC0
void __cdecl D2SOUND_CloseSoundSystem();                                                                    // 0x00514060
void __fastcall D2SOUND_OpenSoundSystem(int bExpansion, int bSoundBackground);                              // 0x00514530
int __cdecl sub_00525150();                                                                         // 0x00525150
void __cdecl sub_0060DDB0();                                                                                // 0x0060DDB0

int gnMode_0074C704;                                                                                        // 0x0074C704
int gbUseKeyhook_0074C708;                                                                                  // 0x0074C708
void* ghModKeyhook_0074C70C;                                                                                // 0x0074C70C

// 0x00405C30
int __fastcall GameStart(void* hInstance, D2ConfigStrc* pCfg, int nModType)
{
    if (pCfg->nUnk0x04 == 1)
    {
        sub_00407970_ForceCrash();
    }

    gnMode_0074C704 = nModType;

    BOOL bSoundStarted = 0;
    BOOL bGfxStarted = 0;

    sub_00406870_InitStorm(pCfg->bDirect, 0);
    FOG_AsyncDataInitialize(1, 0);
    FOG_10082_Noop();
    FOG_10218();

    if (gnMode_0074C704 != 2)
    {
        if (!ARCHIVE_LoadArchives() || !ARCHIVE_LoadExpansionArchives(ARCHIVE_ShowInsertPlayDiscMessage, ARCHIVE_ShowInsertExpansionDiscMessage, 0, pCfg))
        {
            ARCHIVE_FreeArchives();
            return 0;
        }
        pCfg->bIsExpansion = sub_00408F20_HasExpansionMpq();
        sub_00405A70();
    }

    sub_00525150();

    if (pCfg->b3DFX)
    {
        nModType = 4;
    }
    else if (pCfg->bWindow)
    {
        nModType = 1;
    }
    else
    {
        nModType = pCfg->bD3D ? 6 : 3;
    }

    const BOOL bWindowed = pCfg->bWindow != 0;
    const int nResolution = pCfg->bIsExpansion ? 2 : 0;

    if (gnMode_0074C704 != 2)
    {
        if (!D2Win_CreateWindow(hInstance, nModType, bWindowed, !pCfg->bNoCompress))
        {
            return 0;
        }

        if (pCfg->bPerspective && nModType >= 4)
        {
            D2GFX_SetPerspective(1);
        }

        if (!D2Win_InitializeSpriteCache(bWindowed, nResolution))
        {
            D2GFX_Release();
            return 0;
        }

        if (gbUseKeyhook_0074C708)
        {
            ghModKeyhook_0074C70C = LoadLibraryA("Keyhook.dll");
        }

        if (ghModKeyhook_0074C70C)
        {
            void (__stdcall* pfnInstall)(int) = (void (__stdcall*)(int))GetProcAddress(ghModKeyhook_0074C70C, "InstallKeyboardHook");
            if (pfnInstall)
            {
                pfnInstall(sub_004F59A0());
            }
        }

        bGfxStarted = 1;
    }

    if (pCfg->bQuality)
    {
        D2GFX_ToggleLowQuality();
    }

    if (pCfg->nGamma)
    {
        D2GFX_SetGamma(pCfg->nGamma);
    }

    if (pCfg->bVSync)
    {
        D2GFX_EnableVSync();
    }

    unsigned long bFixedAspect = 1;
    SRegLoadValue("Diablo II", "Fixed Aspect Ratio", 0, &bFixedAspect);
    if (pCfg->bNoFixedAspect || bFixedAspect != 1)
    {
        sub_004F5280();
    }

    if (!pCfg->bIsExpansion)
    {
        SRegSaveValue("Diablo II", "Resolution", 0, 0);
    }

    if (!pCfg->bNoSound && gnMode_0074C704 != 2)
    {
        D2SOUND_OpenSoundSystem(pCfg->bIsExpansion, pCfg->bSoundBackground);
        bSoundStarted = 1;
    }

    while (gnMode_0074C704 != 0)
    {
        if (gnMode_0074C704 == 2)
        {
            if (bSoundStarted)
            {
                D2SOUND_CloseSoundSystem();
                bSoundStarted = 0;
            }

            if (bGfxStarted)
            {
                D2Win_CloseSpriteCache();
                D2GFX_Release();
                bGfxStarted = 0;
            }
        }

        gnMode_0074C704 = sub_004059D0_RunModeInterface(pCfg);
    }

    if (bSoundStarted)
    {
        D2SOUND_CloseSoundSystem();
    }

    if (bGfxStarted)
    {
        D2Win_CloseSpriteCache();
        D2GFX_Release();
    }

    ARCHIVE_FreeArchives();

    if (ghModKeyhook_0074C70C)
    {
        void (__stdcall* pfnUninstall)() = (void (__stdcall*)())GetProcAddress(ghModKeyhook_0074C70C, "UninstallKeyboardHook");
        if (pfnUninstall)
        {
            pfnUninstall();
        }
        FreeLibrary(ghModKeyhook_0074C70C);
    }

    FOG_AsyncDataDestroy();
    D2MCPClientCloseMCP();

    D2ComInterfaceStrc* pComInterface = *(D2ComInterfaceStrc**)pCfg->pComInterface;
    if (pComInterface)
    {
        pComInterface->pfnRelease();
    }

    sub_0060DDB0();
    FOG_DestroyMemoryPoolSystem(0);
    return 0;
}
