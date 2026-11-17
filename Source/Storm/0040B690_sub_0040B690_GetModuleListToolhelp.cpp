struct D2ModuleEntryStrc
{
    char szFileName[0x104];
    char szBaseName[0x100];
    unsigned int nBase;
    unsigned int nSize;
    D2ModuleEntryStrc* pNext;
};

struct D2ToolhelpModuleEntryStrc
{
    unsigned long dwSize;
    unsigned long th32ModuleID;
    unsigned long th32ProcessID;
    unsigned long GlblcntUsage;
    unsigned long ProccntUsage;
    unsigned int modBaseAddr;
    unsigned int modBaseSize;
    void* hModule;
    char szModule[0x100];
    char szExePath[0x104];
};

typedef void* (__stdcall* CreateToolhelp32SnapshotFn)(unsigned long dwFlags, unsigned long dwProcessId);
typedef int (__stdcall* Module32Fn)(void* hSnapshot, D2ToolhelpModuleEntryStrc* pEntry);

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName);                  // 0x006CC144
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);     // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule);                                  // 0x006CC14C
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...);                // 0x00410660

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

// 0x0040B690
D2ModuleEntryStrc* __stdcall sub_0040B690_GetModuleListToolhelp(unsigned long dwPid)
{
    D2ToolhelpModuleEntryStrc tModuleEntry;
    D2ModuleEntryStrc* pList = 0;
    CreateToolhelp32SnapshotFn pfnCreateToolhelp32Snapshot = 0;
    Module32Fn pfnModule32First = 0;
    Module32Fn pfnModule32Next = 0;
    void* hLibrary;
    const char* aszLibraries[2];
    aszLibraries[0] = "kernel32.dll";
    aszLibraries[1] = "tlhelp32.dll";

    for (int i = 0; i < 2; ++i)
    {
        hLibrary = LoadLibraryA(aszLibraries[i]);
        if (hLibrary)
        {
            pfnCreateToolhelp32Snapshot = (CreateToolhelp32SnapshotFn)GetProcAddress(hLibrary, "CreateToolhelp32Snapshot");
            pfnModule32First = (Module32Fn)GetProcAddress(hLibrary, "Module32First");
            pfnModule32Next = (Module32Fn)GetProcAddress(hLibrary, "Module32Next");
            if (pfnCreateToolhelp32Snapshot && pfnModule32First && pfnModule32Next)
            {
                break;
            }

            FreeLibrary(hLibrary);
            hLibrary = 0;
        }
    }

    if (!hLibrary)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Unable to load toolhelp library");
        return 0;
    }

    void* hSnapshot = pfnCreateToolhelp32Snapshot(8, dwPid);
    if (hSnapshot == (void*)-1)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Unable to get toolhelp snapshot");
        return 0;
    }

    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Enumerate modules...");
    for (int bFound = pfnModule32First(hSnapshot, &tModuleEntry); bFound; bFound = pfnModule32Next(hSnapshot, &tModuleEntry))
    {
        D2ModuleEntryStrc* pEntry = (D2ModuleEntryStrc*)FOG_Alloc(sizeof(D2ModuleEntryStrc), ".\\Src\\Exceptions.cpp", 0x253, 0);
        memset(pEntry, 0, sizeof(D2ModuleEntryStrc));
        strcpy(pEntry->szFileName, tModuleEntry.szExePath);
        strcpy(pEntry->szBaseName, tModuleEntry.szModule);
        pEntry->nBase = tModuleEntry.modBaseAddr;
        pEntry->nSize = tModuleEntry.modBaseSize;
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

    CloseHandle(hSnapshot);
    FreeLibrary(hLibrary);
    return pList;
}
