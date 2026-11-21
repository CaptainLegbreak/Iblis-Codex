#include "Fog.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

bool __stdcall sub_004067D0_GetKnownFolderPathA(char* szPath, int nSize);                                   // 0x004067D0
int __fastcall sub_00406B20_AppendBackslash(char* szPath, size_t nSize);                                // 0x00406B20
int __fastcall sub_00406DE0_MoveDirectoryTree(const char* szPathA, const char* szPathB);                         // 0x00406DE0
unsigned int __stdcall sub_00413800(char* dest, const char* source, unsigned int limit); // 0x00413800
size_t __stdcall SStrLen(const char* szString);                                                             // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070

extern "C" __declspec(dllimport) long __stdcall SHGetFolderPathA(void* hwnd, int csidl, void* hToken, unsigned long dwFlags, char* pszPath); // 0x006CC43C

static bool AppendPathSeparator_Inl(char* szPath, size_t nSize)
{
    if (!nSize)
    {
        return false;
    }
    const size_t nLength = SStrLen(szPath);
    if (nLength > 0 && szPath[nLength - 1] == '\\')
    {
        return true;
    }
    if (nLength + 1 == nSize)
    {
        return false;
    }
    szPath[nLength] = '\\';
    szPath[nLength + 1] = 0;
    return true;
}

// 0x00406D30
static bool sub_00406D30(char* szOutPath, unsigned int nMaxLen)
{
    char szPath[0x104];
    if (!nMaxLen)
    {
        return false;
    }
    D2_ASSERT(szOutPath, 68);
    if (sub_004067D0_GetKnownFolderPathA(szOutPath, nMaxLen))
    {
        sub_00406B20_AppendBackslash(szOutPath, nMaxLen);
        sub_00413800(szOutPath, "Diablo II", nMaxLen);
    }
    else
    {
        if (SHGetFolderPathA(0, 5, 0, 0, szPath))
        {
            return false;
        }
        sub_00406B20_AppendBackslash(szOutPath, nMaxLen);
        sub_00413800(szOutPath, "Diablo II\\Save", nMaxLen);
    }
    return true;
}

// 0x00407050
int __fastcall sub_00407050_GetSavePath(char* szPath, int nSize)
{
    char szSavePath[0x104];
    char szNewPath[0x104];
    szPath[0] = 0;
    if (!SRegLoadString("Diablo II", "NewSavePath", 1, szPath, nSize) && GetLastError() == 2
        && SRegLoadString("Diablo II", "Save Path", 0, szSavePath, 0x104))
    {
        const size_t nLength = strlen(szSavePath);
        if (szSavePath[nLength - 1] == '\\')
        {
            szSavePath[nLength - 1] = 0;
        }
        const unsigned long dwAttributes = GetFileAttributesA(szSavePath);
        if (dwAttributes != (unsigned long)-1 && (dwAttributes & 0x10))
        {
            if (sub_00406D30(szNewPath, 0x104))
            {
                if (sub_00406DE0_MoveDirectoryTree(szSavePath, szNewPath) == 1)
                {
                    SStrCopy(szPath, szSavePath, nSize);
                }
                else
                {
                    AppendPathSeparator_Inl(szNewPath, 0x104);
                    SRegSaveString("Diablo II", "NewSavePath", 1, szNewPath);
                    SStrCopy(szPath, szNewPath, nSize);
                }
            }
        }
    }
    if (GetFileAttributesA(szPath) == (unsigned long)-1)
    {
        szPath[0] = 0;
    }
    if (!szPath[0])
    {
        sub_00406D30(szPath, nSize);
        AppendPathSeparator_Inl(szPath, nSize);
        SRegSaveString("Diablo II", "NewSavePath", 1, szPath);
    }
    if (!AppendPathSeparator_Inl(szPath, nSize))
    {
        return 0;
    }
    return sub_00406A10_CreateDirectoryTree(szPath);
}
