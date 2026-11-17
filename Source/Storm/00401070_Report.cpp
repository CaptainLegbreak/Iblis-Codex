struct _iobuf;

extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC
void __cdecl operator delete(void* pMemory);                                                                // 0x004053F0

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryW(const wchar_t* szFileName);                  // 0x006CC294
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);     // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134

extern "C" const char gszMiniDumpWriteDump_006FFB94[];                                                      // 0x006FFB94

extern void* ghDbgHelp_0098A680;                                                                            // 0x0098A680
extern void* gpfnEnumerateLoadedModules64_0098A6A4;                                                         // 0x0098A6A4
extern void* gpfnStackWalk64_0098A6A0;                                                                      // 0x0098A6A0
extern void* gpfnSymFunctionTableAccess64_0098A698;                                                         // 0x0098A698
extern void* gpfnSymGetLineFromAddr64_0098A6E8;                                                             // 0x0098A6E8
extern void* gpfnSymGetModuleBase64_0098A69C;                                                               // 0x0098A69C
extern void* gpfnSymGetModuleInfo64_0098A684;                                                               // 0x0098A684
extern void* gpfnSymGetOptions_0098A6AC;                                                                    // 0x0098A6AC
extern void* gpfnSymGetSymFromAddr64_0098A68C;                                                              // 0x0098A68C
extern void* gpfnSymInitialize_0098A6A8;                                                                    // 0x0098A6A8
extern void* gpfnSymCleanup_0098A6B8;                                                                       // 0x0098A6B8
extern void* gpfnSymSetOptions_0098A6B4;                                                                    // 0x0098A6B4
extern void* gpfnSymEnumerateModules64_0098A688;                                                            // 0x0098A688
extern void* gpfnSymSetSearchPath_0098A690;                                                                 // 0x0098A690
extern void* gpfnSymFindFileInPath_0098A6EC;                                                                // 0x0098A6EC
extern void* gpfnSymLoadModule64_0098A6DC;                                                                  // 0x0098A6DC
extern void* gpfnSymUnloadModule64_0098A694;                                                                // 0x0098A694
extern void* gpfnMiniDumpWriteDump_0098A6E0;                                                                // 0x0098A6E0

namespace crashy
{
class Report
{
public:
    Report();
    virtual ~Report();
    bool sub_004011F0_Close();
    bool sub_00401210_IsOpen();

    _iobuf* m_pFile;
    char m_szText08[0x400];
    char m_szText408[0x400];
    int m_nLineCount;
    char m_aszLines[1][0x400];
};
}

// build: symbol ??_7Report@crashy@@6B@ 0x006FF984
// 0x00401070
crashy::Report::Report()
{
    m_pFile = 0;
    m_nLineCount = 0;
    m_szText408[0] = 0;
    m_szText08[0] = 0;
}

// 0x004010D0
crashy::Report::~Report()
{
    if (m_pFile)
    {
        fclose(m_pFile);
        m_pFile = 0;
    }
}

// 0x004011F0
bool crashy::Report::sub_004011F0_Close()
{
    if (m_pFile)
    {
        fclose(m_pFile);
        m_pFile = 0;
    }
    return true;
}

// 0x00401210
bool crashy::Report::sub_00401210_IsOpen()
{
    return m_pFile != 0;
}

// build: context sub_00401B00_LoadDbgHelp
bool __cdecl sub_00401B00_LoadDbgHelp()
{
    if (ghDbgHelp_0098A680)
    {
        return true;
    }
    void* hModule = LoadLibraryW(L"DbgHelp.dll");
    if (!hModule)
    {
        return false;
    }
    if (!(gpfnEnumerateLoadedModules64_0098A6A4 = GetProcAddress(hModule, "EnumerateLoadedModules64"))
        || !(gpfnStackWalk64_0098A6A0 = GetProcAddress(hModule, "StackWalk64"))
        || !(gpfnSymFunctionTableAccess64_0098A698 = GetProcAddress(hModule, "SymFunctionTableAccess64"))
        || !(gpfnSymGetLineFromAddr64_0098A6E8 = GetProcAddress(hModule, "SymGetLineFromAddr64"))
        || !(gpfnSymGetModuleBase64_0098A69C = GetProcAddress(hModule, "SymGetModuleBase64"))
        || !(gpfnSymGetModuleInfo64_0098A684 = GetProcAddress(hModule, "SymGetModuleInfo64"))
        || !(gpfnSymGetOptions_0098A6AC = GetProcAddress(hModule, "SymGetOptions"))
        || !(gpfnSymGetSymFromAddr64_0098A68C = GetProcAddress(hModule, "SymGetSymFromAddr64"))
        || !(gpfnSymInitialize_0098A6A8 = GetProcAddress(hModule, "SymInitialize"))
        || !(gpfnSymCleanup_0098A6B8 = GetProcAddress(hModule, "SymCleanup"))
        || !(gpfnSymSetOptions_0098A6B4 = GetProcAddress(hModule, "SymSetOptions"))
        || !(gpfnSymEnumerateModules64_0098A688 = GetProcAddress(hModule, "SymEnumerateModules64"))
        || !(gpfnSymSetSearchPath_0098A690 = GetProcAddress(hModule, "SymSetSearchPath"))
        || !(gpfnSymFindFileInPath_0098A6EC = GetProcAddress(hModule, "SymFindFileInPath"))
        || !(gpfnSymLoadModule64_0098A6DC = GetProcAddress(hModule, "SymLoadModule64"))
        || !(gpfnSymUnloadModule64_0098A694 = GetProcAddress(hModule, "SymUnloadModule64")))
    {
        CloseHandle(hModule);
        return false;
    }
    gpfnMiniDumpWriteDump_0098A6E0 = GetProcAddress(hModule, gszMiniDumpWriteDump_006FFB94);
    ghDbgHelp_0098A680 = hModule;
    return true;
}
