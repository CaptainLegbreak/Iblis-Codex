struct _iobuf;

extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC
void __cdecl operator delete(void* pMemory);                                                                // 0x004053F0

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryW(const wchar_t* szFileName);                  // 0x006CC294
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);     // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134

extern "C" const char gszMiniDumpWriteDump[];                                                      // 0x006FFB94

extern void* ghDbgHelp;                                                                            // 0x0098A680
extern void* gpfnEnumerateLoadedModules64;                                                         // 0x0098A6A4
extern void* gpfnStackWalk64;                                                                      // 0x0098A6A0
extern void* gpfnSymFunctionTableAccess64;                                                         // 0x0098A698
extern void* gpfnSymGetLineFromAddr64;                                                             // 0x0098A6E8
extern void* gpfnSymGetModuleBase64;                                                               // 0x0098A69C
extern void* gpfnSymGetModuleInfo64;                                                               // 0x0098A684
extern void* gpfnSymGetOptions;                                                                    // 0x0098A6AC
extern void* gpfnSymGetSymFromAddr64;                                                              // 0x0098A68C
extern void* gpfnSymInitialize;                                                                    // 0x0098A6A8
extern void* gpfnSymCleanup;                                                                       // 0x0098A6B8
extern void* gpfnSymSetOptions;                                                                    // 0x0098A6B4
extern void* gpfnSymEnumerateModules64;                                                            // 0x0098A688
extern void* gpfnSymSetSearchPath;                                                                 // 0x0098A690
extern void* gpfnSymFindFileInPath;                                                                // 0x0098A6EC
extern void* gpfnSymLoadModule64;                                                                  // 0x0098A6DC
extern void* gpfnSymUnloadModule64;                                                                // 0x0098A694
extern void* gpfnMiniDumpWriteDump;                                                                // 0x0098A6E0

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

bool __cdecl sub_00401B00_LoadDbgHelp(); // 0x00401B00
