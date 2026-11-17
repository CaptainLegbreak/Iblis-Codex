extern "C" unsigned int __cdecl strlen(const char* sz);
#pragma intrinsic(strlen)

struct D2FileTimeStrc
{
    unsigned int dwLowDateTime;
    unsigned int dwHighDateTime;
};

struct D2FindDataStrc
{
    unsigned int dwFileAttributes;
    D2FileTimeStrc ftCreationTime;
    D2FileTimeStrc ftLastAccessTime;
    D2FileTimeStrc ftLastWriteTime;
    unsigned int nFileSizeHigh;
    unsigned int nFileSizeLow;
    unsigned int dwReserved0;
    unsigned int dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
    char pad0x13E[2];
};

extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* szFileName, D2FindDataStrc* pFindData);
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData);
extern "C" __declspec(dllimport) int __stdcall FindClose(void* hFindFile);

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
int __fastcall sub_00407050_GetSavePath(char* szPath, int nSize);                                           // 0x00407050
int __fastcall sub_0043C8A0(const char* szName, char* szPath);                                              // 0x0043C8A0
char gszCharName_00779B68[256];                                                                             // 0x00779B68
int gnCharCount_00779DE0;                                                                                   // 0x00779DE0

static __declspec(noinline) void __stdcall sub_00438AD0_AddCharEntry(const char* szName, char* szPath, int nArg3, unsigned int nTimeLow, unsigned int nTimeHigh, int nMode);

// calling-convention shim (not game code)
static void __stdcall sub_00438AD0_AddCharEntry(const char* szName, char* szPath, int nArg3, unsigned int nTimeLow, unsigned int nTimeHigh, int nMode)
{
    FindClose((void*)nMode);
    FindClose((void*)((int)szName + (int)szPath + (int)nArg3 + (int)nTimeLow + (int)nTimeHigh));
}

static __forceinline int CharSel_IsValidCharName(const char* szName)
{
    const int nLen = strlen(szName);
    if (nLen < 2 || nLen > 15 || szName[nLen - 1] == '-' || szName[0] == '_')
        return 0;
    return 1;
}

// 0x00438F70
int __cdecl sub_00438F70_ScanCharFiles()
{
    D2FindDataStrc tFindData;
    char szPath[0x100];
    char szDir[0x400];
    char szPattern[0x400];

    gnCharCount_00779DE0 = 0;
    sub_00407050_GetSavePath(szDir, 0x400);
    sprintf(szPattern, "%s*.d2s", szDir);
    void* hFind = FindFirstFileA(szPattern, &tFindData);
    if (hFind == (void*)-1)
    {
        return 1;
    }

    do
    {
        const char* pSrc = tFindData.cFileName;
        char* pDst = gszCharName_00779B68;
        while (*pSrc && *pSrc != '.')
        {
            *pDst++ = *pSrc++;
        }
        *pDst = 0;

        if (CharSel_IsValidCharName(gszCharName_00779B68) && sub_0043C8A0(gszCharName_00779B68, szPath))
        {
            sub_00438AD0_AddCharEntry(gszCharName_00779B68, szPath, 0, tFindData.ftLastWriteTime.dwLowDateTime, tFindData.ftLastWriteTime.dwHighDateTime, 0);
            ++gnCharCount_00779DE0;
        }
    }
    while (FindNextFileA(hFind, &tFindData));

    FindClose(hFind);
    return 1;
}

void __cdecl sub_LEG_Emit_00438F70()
{
    sub_00438F70_ScanCharFiles();
}

void __stdcall sub_LEG_Emit_00438AD0(const char* szName, char* szPath, int nArg3, unsigned int nTimeLow, unsigned int nTimeHigh, int nMode)
{
    sub_00438AD0_AddCharEntry(szName, szPath, nArg3, nTimeLow, nTimeHigh, nMode);
}
