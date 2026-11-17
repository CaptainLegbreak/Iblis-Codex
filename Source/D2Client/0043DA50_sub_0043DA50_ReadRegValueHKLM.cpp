typedef unsigned short Unicode;
typedef int (__stdcall* D2LaunchCallback)(int nArg);

struct D2LaunchFuncsStrc
{
    char unk0x00[0x6C];
    void (__fastcall* pfn0x6C)(void* pContext, int bFailed);
    char f_70[0x34];
    const char* (__fastcall* pfn0xA4)(void* pContext);
};

struct D2StartupInfoAStrc
{
    unsigned long cb;
    char* lpReserved;
    char* lpDesktop;
    char* lpTitle;
    unsigned long dwX;
    unsigned long dwY;
    unsigned long dwXSize;
    unsigned long dwYSize;
    unsigned long dwXCountChars;
    unsigned long dwYCountChars;
    unsigned long dwFillAttribute;
    unsigned long dwFlags;
    unsigned short wShowWindow;
    unsigned short cbReserved2;
    unsigned char* lpReserved2;
    void* hStdInput;
    void* hStdOutput;
    void* hStdError;
};

struct D2ProcessInformationStrc
{
    void* hProcess;
    void* hThread;
    unsigned long dwProcessId;
    unsigned long dwThreadId;
};

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(void* hKey, const char* szSubKey, unsigned long ulOptions, unsigned long samDesired, void** phkResult); // 0x006CC010
extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(void* hKey, const char* szValueName, unsigned long* lpReserved, unsigned long* lpType, unsigned char* lpData, unsigned long* lpcbData); // 0x006CC00C
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey);                                    // 0x006CC030
extern "C" __declspec(dllimport) void* __stdcall GetDesktopWindow();                                        // 0x006CC494
extern "C" __declspec(dllimport) int __stdcall SetForegroundWindow(void* hWnd);                             // 0x006CC490
extern "C" __declspec(dllimport) int __stdcall CreateProcessA(const char* szApplicationName, char* szCommandLine, void* pProcessAttributes, void* pThreadAttributes, int bInheritHandles, unsigned long dwCreationFlags, void* pEnvironment, const char* szCurrentDirectory, D2StartupInfoAStrc* pStartupInfo, D2ProcessInformationStrc* pProcessInformation); // 0x006CC33C
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone);                     // 0x00440140
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                           // 0x0077B09C
void* gpLaunchContext_0077B0A4;                                                                             // 0x0077B0A4

// 0x0043DA50
static int __stdcall sub_0043DA50_ReadRegValueHKLM(const char* szSubKey, const char* szValueName, unsigned char* pData, unsigned long nSize, unsigned long* pcbData)
{
    void* hKey;
    unsigned long dwType;
    *pcbData = 0;
    if (RegOpenKeyExA((void*)0x80000002, szSubKey, 0, 0x20019, &hKey))
    {
        return 0;
    }
    *pcbData = nSize;
    if (RegQueryValueExA(hKey, szValueName, 0, &dwType, pData, pcbData))
    {
        RegCloseKey(hKey);
        return 0;
    }
    return RegCloseKey(hKey) == 0;
}

// 0x00440DE0
int __stdcall sub_00440DE0(int nUnused)
{
    const char* szURL = gpLaunchFuncs_0077B09C->pfn0xA4(gpLaunchContext_0077B0A4);
    if (!szURL)
    {
        return 1;
    }
    char szCommand[0x800] = { 0 };
    int bOk = 0;
    SetForegroundWindow(GetDesktopWindow());
    char szKey[0x400];
    sprintf(szKey, "%s\\.html", "SOFTWARE\\Classes");
    unsigned long cbData;
    if (sub_0043DA50_ReadRegValueHKLM(szKey, 0, (unsigned char*)szCommand, 0x400, &cbData))
    {
        char szOpenKey[0x400];
        sprintf(szOpenKey, "%s\\%s\\shell\\open\\command", "SOFTWARE\\Classes", szCommand);
        char szPath[0x400] = { 0 };
        if (sub_0043DA50_ReadRegValueHKLM(szOpenKey, 0, (unsigned char*)szPath, 0x400, &cbData))
        {
            strcat(szPath, " ");
            strcat(szPath, szURL);
            D2StartupInfoAStrc si;
            D2ProcessInformationStrc pi;
            SMemZero(&si, sizeof(si));
            si.cb = sizeof(si);
            if (CreateProcessA(0, szPath, 0, 0, 0, 0x20, 0, 0, &si, &pi))
            {
                CloseHandle(pi.hThread);
                CloseHandle(pi.hProcess);
                bOk = 1;
            }
        }
    }
    if (!bOk)
    {
        sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14DC), 0);
    }
    gpLaunchFuncs_0077B09C->pfn0x6C(gpLaunchContext_0077B0A4, bOk == 0);
    return 1;
}
