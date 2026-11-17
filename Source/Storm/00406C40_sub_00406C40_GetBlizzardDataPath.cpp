struct D2SystemTimeStrc
{
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
};

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2FindDataStrc
{
    unsigned long dwFileAttributes;
    D2FileTimeStrc ftCreationTime;
    D2FileTimeStrc ftLastAccessTime;
    D2FileTimeStrc ftLastWriteTime;
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                          // 0x00682990
extern "C" __declspec(dllimport) long __stdcall SHGetFolderPathA(void* hWnd, int nFolder, void* hToken, unsigned long dwFlags, char* szPath); // 0x006CC43C
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName);        // 0x006CC1B0
extern "C" __declspec(dllimport) int __stdcall MoveFileA(const char* szExisting, const char* szNew);        // 0x006CC1D0
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();                                    // 0x006CC1B4
extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* szFileName, D2FindDataStrc* pFindData); // 0x006CC1CC
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData);  // 0x006CC1C8
extern "C" __declspec(dllimport) int __stdcall FindClose(void* hFindFile);                                  // 0x006CC1C4
extern "C" __declspec(dllimport) int __stdcall RemoveDirectoryA(const char* szPathName);                    // 0x006CC1C0
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime);                // 0x006CC1D4
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName);                         // 0x006CC1A0
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);         // 0x00413A40
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
int __fastcall sub_00406A10_CreateDirectoryTree(const char* szPath);                                        // 0x00406A10
int __fastcall sub_00407370_JulianDay(int nYear, int nMonth, int nDay);                                     // 0x00407370
void __fastcall sub_00407440_FromJulianDay(int nJulianDay, int* pnYear, int* pnMonth, int* pnDay);          // 0x00407440
int __fastcall sub_0040C220_GetAppPath(char* szPath, unsigned int nSize);                                   // 0x0040C220

static int __fastcall FOG_AppendBackslash(char* szPath, int nSize)
{
    if (!szPath || !nSize)
        return 0;
    unsigned int nLen = SStrLen(szPath);
    if (nLen <= 0 || szPath[nLen - 1] != '\\')
    {
        if (nLen + 1 == nSize)
            return 0;
        szPath[nLen] = '\\';
        szPath[nLen + 1] = 0;
    }
    return 1;
}

// 0x00406C40
int __fastcall sub_00406C40_GetBlizzardDataPath(char* szOutPath, int nSize)
{
    char szPath[0x104];
    if (SHGetFolderPathA(0, 0x1C, 0, 0, szPath) < 0)
        return 0;
    sub_00413800(szPath, "\\Blizzard Entertainment", 0x7FFFFFFF);
    if (!FOG_AppendBackslash(szPath, nSize))
        return 0;
    if (!sub_00406A10_CreateDirectoryTree(szPath))
        return 0;
    SStrCopy(szOutPath, szPath, nSize);
    return SStrLen(szOutPath) == SStrLen(szPath);
}

// 0x00406DE0
int __fastcall sub_00406DE0_MoveDirectoryTree(const char* szSrc, const char* szDst)
{
    char szDir[0x104];
    SStrCopy(szDir, szDst, 0x7FFFFFFF);
    char* pCut = strrchr(szDir, '\\') + 1;
    char cSaved = *pCut;
    *pCut = 0;
    sub_00406A10_CreateDirectoryTree(szDir);
    *pCut = cSaved;
    if (MoveFileA(szSrc, szDst))
        return 2;
    unsigned long dwAttr = GetFileAttributesA(szSrc);
    if (dwAttr == (unsigned long)-1)
        return GetLastError() == 2 ? 2 : 1;
    if (!(dwAttr & 0x10))
        return 1;
    dwAttr = GetFileAttributesA(szDst);
    if (!(dwAttr & 0x10))
        return 1;
    if (dwAttr == (unsigned long)-1)
    {
        if (GetLastError() != 2)
            return 1;
        FOG_AppendBackslash(szDir, sizeof(szDir));
        sub_00406A10_CreateDirectoryTree(szDir);
    }
    char szSrcFind[0x104];
    char szDstFind[0x104];
    int nResult = 0;
    int nSrcLen = SStrPrintf(szSrcFind, 0x104, "%s\\*", szSrc) - 1;
    int nDstLen = SStrPrintf(szDstFind, 0x104, "%s\\", szDst);
    D2FindDataStrc tData;
    void* hFind = FindFirstFileA(szSrcFind, &tData);
    if (hFind != (void*)-1)
    {
        do
        {
            if (strcmp(tData.cFileName, ".") && strcmp(tData.cFileName, ".."))
            {
                SStrCopy(szSrcFind + nSrcLen, tData.cFileName, 0x104 - nSrcLen);
                SStrCopy(szDstFind + nDstLen, tData.cFileName, 0x104 - nDstLen);
                nResult |= sub_00406DE0_MoveDirectoryTree(szSrcFind, szDstFind);
            }
        } while (FindNextFileA(hFind, &tData));
    }
    FindClose(hFind);
    RemoveDirectoryA(szSrc);
    return nResult;
}

// 0x00407570
void __fastcall sub_00407570_DeleteOldDatedLogs(const char* szPrefix)
{
    D2SystemTimeStrc tTime;
    char szDir[0x1000];
    char szFile[0x1000];
    GetLocalTime(&tTime);
    szDir[0] = 0;
    if (sub_0040C220_GetAppPath(szDir, 0x1000))
    {
        sub_00413800(szDir, "\\", 0x1000);
        sub_00406A10_CreateDirectoryTree(szDir);
    }
    int nYear = tTime.wYear;
    int nMonth = tTime.wMonth;
    int nDay = tTime.wDay;
    int nJulianDay = sub_00407370_JulianDay(nYear, nMonth, nDay) - 5;
    for (int i = 0; i < 10; i++)
    {
        sub_00407440_FromJulianDay(nJulianDay, &nYear, &nMonth, &nDay);
        SStrPrintf(szFile, 0x1000, "%s%s%02d%02d%02d.txt", szDir, szPrefix, nYear % 100, nMonth, nDay);
        DeleteFileA(szFile);
        nJulianDay--;
    }
}
