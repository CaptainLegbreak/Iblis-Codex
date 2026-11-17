extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* szFileName);                         // 0x006CC1A0
extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char* szPathName, void* pSecurityAttributes); // 0x006CC1B8
extern "C" __declspec(dllimport) long __stdcall SHGetFolderPathA(void* hWnd, int nFolder, void* hToken, unsigned long dwFlags, char* szPath); // 0x006CC43C
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
void __cdecl sub_00519300_FreeCache();                                                                      // 0x00519300
void __cdecl sub_005193E0_LoadCache();                                                                      // 0x005193E0

extern void* ghCacheFile_0072FB78;                                                                          // 0x0072FB78
extern int gnCacheValue_00881890;                                                                           // 0x00881890

// 0x00519220
static __declspec(noinline) void sub_00519220_GetCacheFilePath(char* szPath)
{
    D2_ASSERT(SHGetFolderPathA(0, 0x23, 0, 0, szPath) == 0, 0x112);
    sub_00413800(szPath, "\\Blizzard Entertainment", 0x104);
    CreateDirectoryA(szPath, 0);
    sub_00413800(szPath, "\\Diablo II", 0x104);
    CreateDirectoryA(szPath, 0);
    sub_00413800(szPath, "\\bncache.dat", 0x104);
}

// 0x005192A0
void __cdecl sub_005192A0_DeleteCacheFile()
{
    char szPath[260];

    if (ghCacheFile_0072FB78 != (void*)-1)
    {
        CloseHandle(ghCacheFile_0072FB78);
        ghCacheFile_0072FB78 = (void*)-1;
    }

    szPath[0] = 0;
    sub_00519220_GetCacheFilePath(szPath);
    DeleteFileA(szPath);
}

// 0x005198C0
void __cdecl sub_005198C0_ResetCache()
{
    char szPath[260];

    if (gnCacheValue_00881890)
    {
        sub_00519300_FreeCache();
        sub_005192A0_DeleteCacheFile();
    }

    szPath[0] = 0;
    sub_00519220_GetCacheFilePath(szPath);
    DeleteFileA(szPath);
    sub_005193E0_LoadCache();
}
