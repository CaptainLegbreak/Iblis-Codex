#include "D2BNClient.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* szFileName); // 0x006CC1A0
extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char* szPathName, void* pSecurityAttributes); // 0x006CC1B8
extern "C" __declspec(dllimport) long __stdcall SHGetFolderPathA(void* hWnd, int nFolder, void* hToken, unsigned long dwFlags, char* szPath); // 0x006CC43C
void __cdecl sub_00519300_FreeCache(); // 0x00519300
void __cdecl sub_005193E0_LoadCache(); // 0x005193E0
extern void* ghCacheFile_0072FB78; // 0x0072FB78

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
extern D2CriticalSectionStrc gCacheLock_00881894; // 0x00881894

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

void* gpCacheBuffer_00881880; // 0x00881880

void* gpCacheBuffer_00881884; // 0x00881884

unsigned int* gpCacheTable_00881888; // 0x00881888

void* gpCacheBuffer_0088188C; // 0x0088188C

// 0x00519300
void __cdecl sub_00519300_FreeCache()
{
    EnterCriticalSection(&gCacheLock_00881894);
    gnCacheValue_00881890 = 0;
    if (gpCacheBuffer_00881884)
    {
        SMemFree(gpCacheBuffer_00881884, ".\\CACHE.CPP", 0x155, 0);
        gpCacheBuffer_00881884 = 0;
    }
    if (gpCacheBuffer_0088188C)
    {
        SMemFree(gpCacheBuffer_0088188C, ".\\CACHE.CPP", 0x159, 0);
        gpCacheBuffer_0088188C = 0;
    }
    if (gpCacheBuffer_00881880)
    {
        SMemFree(gpCacheBuffer_00881880, ".\\CACHE.CPP", 0x15D, 0);
        gpCacheBuffer_00881880 = 0;
    }
    if (ghCacheFile_0072FB78 != (void*)-1)
    {
        CloseHandle(ghCacheFile_0072FB78);
        ghCacheFile_0072FB78 = (void*)-1;
    }
    if (gpCacheTable_00881888)
    {
        SMemFree(gpCacheTable_00881888, ".\\CACHE.CPP", 0x165, 0);
        gpCacheTable_00881888 = 0;
    }
    LeaveCriticalSection(&gCacheLock_00881894);
}

// 0x005193C0
int __fastcall sub_005193C0_FreeCachedFile(void* pData, unsigned int nSize)
{
    if (!pData)
        return 0;
    SMemFree(pData, ".\\CACHE.CPP", 0x16F, 0);
    return 1;
}
