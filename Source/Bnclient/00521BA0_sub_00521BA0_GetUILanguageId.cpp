extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName);                  // 0x006CC144
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);    // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule);                                 // 0x006CC14C
extern "C" __declspec(dllimport) unsigned short __stdcall GetSystemDefaultLangID(void);                    // 0x006CC354

extern "C" const char gszKernel32_006CD6E4[];                                                               // 0x006CD6E4

// 0x00521BA0
unsigned int __cdecl sub_00521BA0_GetUILanguageId()
{
    void* hKernel = LoadLibraryA(gszKernel32_006CD6E4);
    if (hKernel)
    {
        unsigned short (__stdcall* pfnGetUILanguage)() = (unsigned short (__stdcall*)())GetProcAddress(hKernel, "GetSystemDefaultUILanguage");
        if (pfnGetUILanguage)
        {
            unsigned short nLangId = pfnGetUILanguage();
            FreeLibrary(hKernel);
            return nLangId;
        }
        FreeLibrary(hKernel);
    }
    return GetSystemDefaultLangID();
}
