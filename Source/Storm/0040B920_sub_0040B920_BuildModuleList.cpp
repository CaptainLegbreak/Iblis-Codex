struct D2ModuleEntryStrc
{
    char szFileName[0x104];
    char szBaseName[0x100];
    unsigned int nBase;
    unsigned int nSize;
    D2ModuleEntryStrc* pNext;
};

struct D2ModuleInfoStrc
{
    unsigned int nBase;
    unsigned int nSize;
    void* pEntryPoint;
};

typedef int (__stdcall* EnumProcessModulesFn)(void* hProcess, void** phModules, unsigned long nSize, unsigned long* pnNeeded);
typedef unsigned long (__stdcall* GetModuleNameFn)(void* hProcess, void* hModule, char* szName, unsigned long nSize);
typedef int (__stdcall* GetModuleInformationFn)(void* hProcess, void* hModule, D2ModuleInfoStrc* pInfo, unsigned long nSize);

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName);                  // 0x006CC144
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);     // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule);                                  // 0x006CC14C
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();                                    // 0x006CC1B4
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...);                // 0x00410660
extern "C" void __fastcall sub_0040B660_FreeList(D2ModuleEntryStrc* pList);                                 // 0x0040B660

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char gszExceptionsCpp_006CD628[];                                                          // 0x006CD628

// 0x0040B920
D2ModuleEntryStrc* __stdcall sub_0040B920_BuildModuleList(void* hProcess)
{
    void* ahModules[0x100];
    char szFileName[0x104];
    char szBaseName[0x100];
    unsigned long nNeeded;
    D2ModuleInfoStrc tInfo;
    D2ModuleEntryStrc* pList = 0;
    void* hPsapi = LoadLibraryA("psapi.dll");
    if (!hPsapi)
    {
        return 0;
    }
    EnumProcessModulesFn pfnEnumProcessModules = (EnumProcessModulesFn)GetProcAddress(hPsapi, "EnumProcessModules");
    GetModuleNameFn pfnGetModuleFileNameEx = (GetModuleNameFn)GetProcAddress(hPsapi, "GetModuleFileNameExA");
    GetModuleNameFn pfnGetModuleBaseName = (GetModuleNameFn)GetProcAddress(hPsapi, "GetModuleBaseNameA");
    GetModuleInformationFn pfnGetModuleInformation = (GetModuleInformationFn)GetProcAddress(hPsapi, "GetModuleInformation");
    if (!pfnEnumProcessModules || !pfnGetModuleFileNameEx || !pfnGetModuleBaseName || !pfnGetModuleInformation)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Unable to load psapi library");
        goto failed;
    }
    if (!pfnEnumProcessModules(hProcess, ahModules, sizeof(ahModules), &nNeeded))
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Error enumerating modules using PSAPI:  error(%d)", GetLastError());
        goto failed;
    }
    {
        const int nModules = nNeeded / sizeof(void*);
        if (nModules > 0x100)
        {
            sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "PSAPI EnumProcessModules returned invalid number of modules");
            goto failed;
        }
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "\nEnumerate modules...");
        for (int i = 0; i < nModules; ++i)
        {
            if (!pfnGetModuleInformation(hProcess, ahModules[i], &tInfo, sizeof(tInfo)))
            {
                sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "ERROR: PSAPI GetModuleInformation (%d)", GetLastError());
                goto failed;
            }
            if (!pfnGetModuleFileNameEx(hProcess, ahModules[i], szFileName, sizeof(szFileName)))
            {
                sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "ERROR: PSAPI GetModuleFileNameExA (%d)", GetLastError());
                goto failed;
            }
            if (!pfnGetModuleBaseName(hProcess, ahModules[i], szBaseName, sizeof(szBaseName) - 1))
            {
                sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "ERROR: PSAPI GetModuleBaseNameA (%d)", GetLastError());
                goto failed;
            }
            D2ModuleEntryStrc* pEntry = (D2ModuleEntryStrc*)FOG_Alloc(sizeof(D2ModuleEntryStrc), gszExceptionsCpp_006CD628, 0x2D3, 0);
            memset(pEntry, 0, sizeof(D2ModuleEntryStrc));
            strcpy(pEntry->szFileName, szFileName);
            strcpy(pEntry->szBaseName, szBaseName);
            pEntry->nBase = tInfo.nBase;
            pEntry->nSize = tInfo.nSize;
            pEntry->pNext = pList;
            pList = pEntry;
            D2ModuleEntryStrc* pPrevious = 0;
            for (D2ModuleEntryStrc* pCurrent = pEntry; pCurrent; pCurrent = pPrevious->pNext)
            {
                D2ModuleEntryStrc* pNext = pCurrent->pNext;
                if (!pNext || pCurrent->nBase <= pNext->nBase)
                {
                    break;
                }
                if (pCurrent == pList)
                {
                    pList = pNext;
                }
                else
                {
                    pPrevious->pNext = pNext;
                }
                pCurrent->pNext = pNext->pNext;
                pNext->pNext = pCurrent;
                pPrevious = pNext;
            }
        }
    }
    FreeLibrary(hPsapi);
    return pList;

failed:
    FreeLibrary(hPsapi);
    sub_0040B660_FreeList(pList);
    return 0;
}
