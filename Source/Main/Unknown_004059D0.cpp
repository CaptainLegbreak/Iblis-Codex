#include "D2MultiTypes.h"
#include "D2FogTypes.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2LangApi.h"
#include "FogApi.h"
#include "D2CommonApi2.h"
#include "FogApi2.h"

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
struct _iobuf;
typedef int BOOL;
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144
extern "C" int __cdecl fclose(_iobuf* pFile); // 0x00681FDC
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode); // 0x0068239A
extern "C" int __cdecl fputc(int nChar, _iobuf* pFile); // 0x00682058
bool __fastcall sub_00516DE1_Verify(void* pContext); // 0x00516DE1
bool __fastcall sub_00516D8B_RunSurvey(const char* szExePath); // 0x00516D8B
void __fastcall MAINMENUS_InitStorm(int nDirectFlags, int nValue); // 0x00406870
void __cdecl D2MCPClientCloseMCP(); // 0x00449AD0
int __stdcall D2GFX_Release(); // 0x004F5050
void __stdcall D2GFX_SetPerspective(int bPerspective); // 0x004F51E0
int __stdcall D2GFX_SetGamma(int nGamma); // 0x004F5230
void __cdecl D2GFX_EnableVSync(); // 0x004F5270
void __cdecl D2GFX_DisableFixedAspectRatio(); // 0x004F5280
int __stdcall D2GFX_ToggleLowQuality(); // 0x004F54F0
int __cdecl WINDOW_GetWindow(); // 0x004F59A0
int __stdcall D2Win_InitializeSpriteCache(int bWindowed, int nResolution); // 0x004F8F10
int __stdcall D2Win_CloseSpriteCache(); // 0x004F9030
int __stdcall D2Win_CreateWindow(void* hInstance, int nRenderMode, int bWindowed, int bCompress); // 0x004FA520
int __cdecl ARCHIVE_ShowInsertExpansionDiscMessage(); // 0x004FAB00
int __cdecl ARCHIVE_ShowInsertPlayDiscMessage(); // 0x004FAB30
int __cdecl ARCHIVE_LoadArchives(); // 0x004FAB90
void __cdecl ARCHIVE_FreeArchives(); // 0x004FAE00
int __fastcall ARCHIVE_LoadExpansionArchives(int (__cdecl* pfnPlayDisc)(), int (__cdecl* pfnExpansionDisc)(), int nUnused, D2ConfigStrc* pCfg); // 0x004FAEC0
void __cdecl D2SOUND_CloseSoundSystem(); // 0x00514060
void __fastcall sub_00514530_InitSound(int bExpansion, int bSoundBackground); // 0x00514530

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2ModeEntryStrc gaModeTable[6]; // 0x00706554
extern void* gpModeContext_0074C718; // 0x0074C718
D2ModeIfaceStrc* gpModeIface; // 0x0074C700
int gnMode; // 0x0074C704
int gbUseKeyhook; // 0x0074C708
void* ghModKeyhook; // 0x0074C70C

// 0x004059D0
int __stdcall ERRORMANAGER_RunModeInterface(D2ConfigStrc* pCfg)
{
    if (gnMode < 1 || gnMode > 5)
    {
        return 0;
    }
    D2_ASSERT(gaModeTable[gnMode].pfnCreate, 307);
    D2_ASSERT(gaModeTable[gnMode].pfnRelease, 308);
    gpModeIface = gaModeTable[gnMode].pfnCreate(gpModeContext_0074C718);
    const int nResult = gpModeIface->pfnRun(pCfg);
    gaModeTable[gnMode].pfnRelease();
    return nResult;
}

// 0x00405A50
void __cdecl sub_00405A50_Nop()
{
}

// 0x00405A60
void __cdecl sub_00405A60_Nop()
{
}

// 0x00405A70
void __stdcall sub_00405A70_WriteSurveyLocale()
{
    unsigned int nLanguage;
    char szPath[0x104];
    char szExe[0x400];
    STRTABLE_GetLanguageInfoField(&nLanguage, 3);
    if (ERRORMANAGER_GetBlizzardDataPath(szPath, 0x104))
    {
        SStrPack(szPath, "System Survey\\ProductData\\", 0x104);
        char* pEnd = szPath + SStrLen(szPath);
        unsigned int nRemain = szPath + sizeof(szPath) - pEnd;
        SStrCopy(pEnd, "D2DV\\locale", nRemain);
// build: symbol ?FOG_CreatePathHierarchy@* 0x00406A10
        FOG_CreatePathHierarchy(szPath);
        _iobuf* pFile = fopen(szPath, "w");
        if (pFile)
        {
            fputc(nLanguage >> 24, pFile);
            fputc((nLanguage >> 16) & 0xFF, pFile);
            fputc((nLanguage >> 8) & 0xFF, pFile);
            fputc(nLanguage & 0xFF, pFile);
            fclose(pFile);
        }
        if (FOG_IsExpansion())
        {
            SStrCopy(pEnd, "D2XP\\locale", nRemain);
            FOG_CreatePathHierarchy(szPath);
            pFile = fopen(szPath, "w");
            if (pFile)
            {
                fputc(nLanguage >> 24, pFile);
                fputc((nLanguage >> 16) & 0xFF, pFile);
                fputc((nLanguage >> 8) & 0xFF, pFile);
                fputc(nLanguage & 0xFF, pFile);
                fclose(pFile);
            }
        }
    }
    ERRORMANAGER_GetModuleDirectory(szExe, 0x400);
    SStrPack(szExe, "SystemSurvey.exe", 0x400);
    if (sub_00516DE1_Verify(szExe))
        sub_00516D8B_RunSurvey(szExe);
}


#include "gen/data/Source/Main/Unknown_004059D0.inc"
