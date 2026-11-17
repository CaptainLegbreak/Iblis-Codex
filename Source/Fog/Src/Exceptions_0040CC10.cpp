#include "Fog.h"

// build: context sub_H13_EmitLineRetry
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2ModuleInfoStrc
{
    char szPath[0x104];
    char szName[0x100];
    unsigned long dwBase;
    unsigned long dwSize;
    D2ModuleInfoStrc* pNext;
};

struct D2ImageHlpLineStrc
{
    unsigned long dwSizeOfStruct;
    void* pKey;
    unsigned long dwLineNumber;
    char* szFileName;
    unsigned long dwAddress;
};

struct D2MemoryBasicInfoStrc
{
    void* BaseAddress;
    void* AllocationBase;
    unsigned long AllocationProtect;
    unsigned long RegionSize;
    unsigned long State;
    unsigned long Protect;
    unsigned long Type;
};

struct D2PeDosHeaderStrc
{
    unsigned short f_0;
    char unk0x02[0x3A];
    long nNtHeadersOffset;
};

struct D2PeNtHeadersStrc
{
    unsigned long dwSignature;
    unsigned short wMachine;
    unsigned short wNumberOfSections;
    char unk0x08[0x0C];
    unsigned short wSizeOfOptionalHeader;
    unsigned short wCharacteristics;
    char aOptionalHeader[4];
};

struct D2PeSectionStrc
{
    char szName[0x08];
    unsigned long dwVirtualSize;
    unsigned long dwVirtualAddress;
    unsigned long dwSizeOfRawData;
    char unk0x14[0x14];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();                                    // 0x006CC1B4
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess();                                       // 0x006CC13C
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...);                // 0x00410660
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
int __fastcall sub_0040C220_GetAppPath(char* szPath, unsigned int nSize);                                   // 0x0040C220
D2ModuleInfoStrc* __stdcall sub_0040B690_GetModuleListToolhelp(unsigned long dwPid);                        // 0x0040B690

char gszSymSearchPath_0075BFB8[4096];                                                                       // 0x0075BFB8
int gbSymQuiet_0075CFB8;                                                                                    // 0x0075CFB8
D2CriticalSectionStrc gtImageHlpLock_0075CFBC;                                                              // 0x0075CFBC
int gnSymInitCount_0075CFD4;                                                                                // 0x0075CFD4
extern int (__stdcall* gpfnSymCleanup_0075CFDC)(void* hProcess);                                            // 0x0075CFDC
int (__stdcall* gpfnSymGetLineFromAddr_0075CFE4)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine);        // 0x0075CFE4
extern unsigned long (__stdcall* gpfnSymGetOptions_0075CFF0)();                                             // 0x0075CFF0
extern int (__stdcall* gpfnSymInitialize_0075CFF8)(void* hProcess, const char* szSearchPath, int bInvadeProcess); // 0x0075CFF8
extern unsigned long (__stdcall* gpfnSymLoadModule_0075CFFC)(void* hProcess, void* hFile, const char* szImageName, const char* szModuleName, unsigned long dwBase, unsigned long dwSize); // 0x0075CFFC
extern unsigned long (__stdcall* gpfnSymSetOptions_0075D004)(unsigned long dwOptions);                      // 0x0075D004
extern int gbImageHlpLoaded_0075D014;                                                                       // 0x0075D014

// 0x0040B600
static int __stdcall sub_0040B600_GetLineFromAddrRetry(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine)
{
    if (!gpfnSymGetLineFromAddr_0075CFE4)
    {
        return 0;
    }

    unsigned long nBack = 0;
    while (!gpfnSymGetLineFromAddr_0075CFE4(hProcess, dwAddress - nBack, pdwDisplacement, pLine))
    {
        if (++nBack == 100)
        {
            return 0;
        }
    }

    if (nBack)
    {
        *pdwDisplacement = nBack;
    }

    return 1;
}

// 0x0040BC50
static D2ModuleInfoStrc* __stdcall sub_0040BC50_GetModuleList(void* hProcess, unsigned long dwPid)
{
    D2ModuleInfoStrc* pList = sub_0040B690_GetModuleListToolhelp(dwPid);
    if (!pList)
    {
        pList = sub_0040B920_GetModuleListPsapi(hProcess);
    }

    for (D2ModuleInfoStrc* pModule = pList; pModule; pModule = pModule->pNext)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "    Base:%08lXh  Size:%7lXh  Name:%-15.15s  Path:%s", pModule->dwBase, pModule->dwSize, pModule->szName, pModule->szPath);
    }

    return pList;
}

// 0x0040C0F0
static D2ModuleInfoStrc* __stdcall sub_0040C0F0_EnumModuleSymbols(unsigned long dwPid, void* hProcess)
{
    char szImageName[0x104];
    char szModuleName[0x100];

    D2ModuleInfoStrc* pList = sub_0040BC50_GetModuleList(hProcess, dwPid);
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, &gszEmptyAssertText);
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Load symbols...");

    D2ModuleInfoStrc* pModule = pList;
    while (pModule)
    {
        D2ModuleInfoStrc* pNext = pModule->pNext;
        strcpy(szImageName, pModule->szPath);
        strcpy(szModuleName, pModule->szName);
        const unsigned long dwLoaded = gpfnSymLoadModule_0075CFFC(hProcess, 0, szImageName, szModuleName, pModule->dwBase, pModule->dwSize);
        if (!gbSymQuiet_0075CFB8)
        {
            if (!dwLoaded)
            {
                sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Error (%d) loading symbols for '%s'", GetLastError(), szModuleName);
            }
            else
            {
                sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Symbols Loaded for '%s'", szModuleName);
            }
        }

        pModule = pNext;
    }

    return pList;
}

// 0x0040C290
static char* sub_0040C290_ComposeSymbolPath(char* szPath)
{
    char szCurrentDir[0x200];
    char szBuffer[0x200];

    *szPath = 0;
    if (!sub_0040C220_GetAppPath(szBuffer, 0x200))
    {
        szBuffer[0] = 0;
    }
    else
    {
        strcat(szPath, szBuffer);
        strcat(szPath, ";");
    }

    if (GetCurrentDirectoryA(0x200, szCurrentDir))
    {
        if (!szBuffer[0] || _stricmp(szBuffer, szCurrentDir))
        {
            strcat(szPath, szCurrentDir);
            strcat(szPath, ";");
        }
    }

    if (GetEnvironmentVariableA("_NT_SYMBOL_PATH", szBuffer, 0x200))
    {
        strcat(szPath, szBuffer);
        strcat(szPath, ";");
    }

    if (GetEnvironmentVariableA("_NT_ALTERNATE_SYMBOL_PATH", szBuffer, 0x200))
    {
        strcat(szPath, szBuffer);
        strcat(szPath, ";");
    }

    if (GetEnvironmentVariableA("SYSTEMROOT", szBuffer, 0x200))
    {
        strcat(szPath, szBuffer);
        strcat(szPath, ";");
    }

    const size_t nLength = strlen(szPath);
    if (nLength)
    {
        szPath[nLength - 1] = 0;
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "User defined symbols path: %s", szPath);
    }
    else
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Unable to generate symbols search path");
    }

    return *szPath ? szPath : 0;
}

// 0x0040C520
static void __stdcall sub_0040C520_GetLogicalAddress(char* szModule, unsigned long* pnSection, unsigned long* pnOffset, void* pAddress, unsigned int nSize)
{
    D2MemoryBasicInfoStrc tInfo;

    SStrCopy(szModule, gszUnknown_006CD5FC, nSize);
    *pnSection = 0;
    *pnOffset = 0;
    if (!VirtualQuery(pAddress, &tInfo, sizeof(tInfo)))
    {
        return;
    }

    void* hModule = tInfo.AllocationBase;
    if (!hModule)
    {
        hModule = GetModuleHandleA(0);
    }

    if (!GetModuleFileNameA(hModule, szModule, nSize))
    {
        SStrCopy(szModule, gszUnknown_006CD5FC, nSize);
        return;
    }

    D2PeDosHeaderStrc* pDosHeader = (D2PeDosHeaderStrc*)hModule;
    if (!pDosHeader || pDosHeader->f_0 != 0x5A4D || !pDosHeader->nNtHeadersOffset)
    {
        return;
    }

    D2PeNtHeadersStrc* pNtHeaders = (D2PeNtHeadersStrc*)((char*)pDosHeader + pDosHeader->nNtHeadersOffset);
    if (pNtHeaders->dwSignature != 0x4550)
    {
        return;
    }

    D2PeSectionStrc* pSection = (D2PeSectionStrc*)(pNtHeaders->aOptionalHeader + pNtHeaders->wSizeOfOptionalHeader);
    const unsigned long dwRva = (char*)pAddress - (char*)hModule;
    for (unsigned int i = 0; i < pNtHeaders->wNumberOfSections; ++i, ++pSection)
    {
        const unsigned long dwStart = pSection->dwVirtualAddress;
        const unsigned long dwLength = pSection->dwSizeOfRawData > pSection->dwVirtualSize ? pSection->dwSizeOfRawData : pSection->dwVirtualSize;
        if (dwRva >= dwStart && dwRva <= dwStart + dwLength)
        {
            *pnSection = i + 1;
            *pnOffset = dwRva - dwStart;
            return;
        }
    }
}

// 0x0040C620
int __cdecl sub_0040C620_SymInitializeOnce()
{
    int bResult = 0;
    EnterCriticalSection(&gtImageHlpLock_0075CFBC);
    if (gbImageHlpLoaded_0075D014)
    {
        bResult = 1;
        if (gnSymInitCount_0075CFD4++ <= 0)
        {
            if (!gszSymSearchPath_0075BFB8[0])
            {
                sub_0040C290_ComposeSymbolPath(gszSymSearchPath_0075BFB8);
            }

            void* hProcess = GetCurrentProcess();
            if (!gpfnSymInitialize_0075CFF8(hProcess, gszSymSearchPath_0075BFB8, 0))
            {
                sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "s_DoSymInitialize(): err = %lu", GetLastError());
                gpfnSymCleanup_0075CFDC(hProcess);
                bResult = 0;
                gnSymInitCount_0075CFD4 = 0;
            }
            else
            {
                ++gnSymInitCount_0075CFD4;
                gpfnSymSetOptions_0075D004(gpfnSymGetOptions_0075CFF0() | 0x10);
                D2ModuleInfoStrc* pModule = sub_0040C0F0_EnumModuleSymbols(GetCurrentProcessId(), hProcess);
                if (pModule)
                {
                    do
                    {
                        D2ModuleInfoStrc* pNext = pModule->pNext;
                        FOG_Free(pModule, gszExceptionsCppFile_006CD628, 0x1F7, 0);
                        pModule = pNext;
                    }
                    while (pModule);
                }
            }
        }
    }

    LeaveCriticalSection(&gtImageHlpLock_0075CFBC);
    return bResult;
}
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
void __cdecl sub_004106B0_LogWritePrefixed0(const char* szPrefix, const char* szFormat, ...);               // 0x004106B0
void __cdecl sub_0040F960_CloseLogFiles();                                                                  // 0x0040F960
extern "C" void __fastcall sub_0040B660_FreeList(D2ModuleInfoStrc* pList);                                  // 0x0040B660

struct D2ThreadContextStrc
{
    unsigned long dwContextFlags;
    char unk0x04[0xB0];
    unsigned long Ebp;
    unsigned long Eip;
    unsigned long SegCs;
    unsigned long EFlags;
    unsigned long Esp;
};

void __fastcall sub_0040BCF0_DumpAnnotatedStack(void* hProcess, D2ThreadContextStrc* pContext, D2ModuleInfoStrc* pModules); // 0x0040BCF0

struct D2StackAddressStrc
{
    unsigned long dwOffset;
    unsigned short wSegment;
    unsigned long dwMode;
};

struct D2StackFrameStrc
{
    D2StackAddressStrc AddrPC;
    D2StackAddressStrc AddrReturn;
    D2StackAddressStrc AddrFrame;
    D2StackAddressStrc AddrStack;
    void* pFuncTableEntry;
    unsigned long dwParams[4];
    int bFar;
    int bVirtual;
    unsigned long dwReserved[3];
    unsigned long dwKdHelp[19];
};

struct D2FpoDataStrc
{
    unsigned long dwOffStart;
    unsigned long dwProcSize;
    unsigned long dwLocals;
    unsigned short wParams;
    unsigned short cbProlog : 8;
    unsigned short cbRegs : 3;
    unsigned short fHasSEH : 1;
    unsigned short fUseBP : 1;
    unsigned short reserved : 1;
    unsigned short cbFrame : 2;
};

struct D2ImageHlpSymbolStrc
{
    unsigned long dwSizeOfStruct;
    unsigned long dwAddress;
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwMaxNameLength;
    char szName[0x104];
};

struct D2ImageHlpModuleStrc
{
    unsigned long dwSizeOfStruct;
    unsigned long dwBaseOfImage;
    unsigned long dwImageSize;
    unsigned long dwTimeDateStamp;
    unsigned long dwCheckSum;
    unsigned long dwNumSyms;
    unsigned long dwSymType;
    char szModuleName[32];
    char szImageName[256];
    char szLoadedImageName[256];
};

extern void* (__stdcall* gpfnSymFunctionTableAccess_0075CFE0)(void* hProcess, unsigned long dwAddrBase);  // 0x0075CFE0
extern unsigned long (__stdcall* gpfnSymGetModuleBase_0075CFE8)(void* hProcess, unsigned long dwAddr);    // 0x0075CFE8
extern int (__stdcall* gpfnSymGetModuleInfo_0075CFEC)(void* hProcess, unsigned long dwAddr, D2ImageHlpModuleStrc* pModuleInfo); // 0x0075CFEC
extern int (__stdcall* gpfnSymGetSymFromAddr_0075CFF4)(void* hProcess, unsigned long dwAddr, unsigned long* pdwDisplacement, D2ImageHlpSymbolStrc* pSymbol); // 0x0075CFF4
extern int (__stdcall* gpfnStackWalk_0075D008)(unsigned long dwMachineType, void* hProcess, void* hThread, D2StackFrameStrc* pStackFrame, void* pContextRecord, void* pfnReadMemory, void* pfnFunctionTableAccess, void* pfnGetModuleBase, void* pfnTranslateAddress); // 0x0075D008

// 0x0040CC10
int __fastcall sub_0040CC10_WalkThreadStack(void* hThread, D2ThreadContextStrc* pContext)
{
    unsigned long dwNoStackDump = 0;
    SRegLoadValue("Diablo II", "NoStackDump", 0, &dwNoStackDump);
    if (dwNoStackDump)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "sShowStack: Stack dump turned off in registry");
        return 0;
    }

    if (!gbImageHlpLoaded_0075D014)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "sShowStack: imagehlp.dll not loaded");
        return 0;
    }

    void* hProcess = 0;
    DuplicateHandle(GetCurrentProcess(), GetCurrentProcess(), GetCurrentProcess(), &hProcess, 0, 0, 2);

    char szSearchPath[0x1000];
    const char* szPath = sub_0040C290_ComposeSymbolPath(szSearchPath);
    if (!gpfnSymInitialize_0075CFF8(hProcess, szPath, 0))
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "SymInitialize(): gle = %lu", GetLastError());
        gpfnSymCleanup_0075CFDC(hProcess);
        CloseHandle(hProcess);
        return 0;
    }

    gpfnSymSetOptions_0075D004(gpfnSymGetOptions_0075CFF0() | 0x10);
    const unsigned long dwProcessId = GetCurrentProcessId();
    D2ModuleInfoStrc* pModules = sub_0040C0F0_EnumModuleSymbols(dwProcessId, hProcess);
    sub_0040BCF0_DumpAnnotatedStack(hProcess, pContext, pModules);
    sub_0040B660_FreeList(pModules);
    sub_0040F960_CloseLogFiles();

    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, &gszEmptyAssertText);
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Stack Crawl:");
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Address  Frame    Module       Return    Stack");

    D2StackFrameStrc tFrame;
    memset(&tFrame, 0, sizeof(tFrame));
    tFrame.AddrPC.dwOffset = pContext->Eip;
    tFrame.AddrPC.dwMode = 3;
    tFrame.AddrStack.dwOffset = pContext->Esp;
    tFrame.AddrStack.dwMode = 3;
    tFrame.AddrFrame.dwOffset = pContext->Ebp;
    tFrame.AddrFrame.dwMode = 3;

    D2ImageHlpSymbolStrc tSymbol;
    D2ImageHlpSymbolStrc* pSymbol = &tSymbol;
    pSymbol->dwSizeOfStruct = 0x18;
    pSymbol->dwMaxNameLength = 0x100;

    D2ImageHlpModuleStrc tModule;
    char szModule[0x104];
    int nUnknown = 0;
    int nFrames;
    for (nFrames = 0; nFrames < 0x40; ++nFrames)
    {
        if (nUnknown >= 3)
        {
            break;
        }

        if (!gpfnStackWalk_0075D008(0x14C, hProcess, hThread, &tFrame, pContext, 0, gpfnSymFunctionTableAccess_0075CFE0, gpfnSymGetModuleBase_0075CFE8, 0))
        {
            sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Stack walk error: %d", GetLastError());
            break;
        }

        unsigned long dwSymDisplacement = 0;
        D2ImageHlpLineStrc tLine;
        memset(&tLine, 0, sizeof(tLine));
        const char* szSymbol;
        if (gpfnSymGetSymFromAddr_0075CFF4(hProcess, tFrame.AddrPC.dwOffset, &dwSymDisplacement, pSymbol))
        {
            szSymbol = pSymbol->szName;
            unsigned long dwLineDisplacement = dwSymDisplacement;
            tLine.dwSizeOfStruct = 0x14;
            if (!sub_0040B600_GetLineFromAddrRetry(hProcess, tFrame.AddrPC.dwOffset, &dwLineDisplacement, &tLine))
            {
                tLine.dwLineNumber = 0;
            }
        }
        else
        {
            ++nUnknown;
            szSymbol = gszUnknown_006CD5FC;
        }

        unsigned long nSection;
        unsigned long dwOffset;
        sub_0040C520_GetLogicalAddress(szModule, &nSection, &dwOffset, (void*)tFrame.AddrPC.dwOffset, sizeof(szModule));
        const char* szModuleName = strrchr(szModule, '\\');
        sub_004106B0_LogWritePrefixed0(&gszEmptyAssertText, "%08x %08x %-12s ", tFrame.AddrPC.dwOffset, tFrame.AddrFrame.dwOffset, szModuleName ? szModuleName + 1 : szModule);

        tModule.dwSizeOfStruct = 0x23C;
        if (gpfnSymGetModuleInfo_0075CFEC(hProcess, tFrame.AddrPC.dwOffset, &tModule))
        {
            sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "%s!", tModule.szModuleName);
        }

        sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "%s+%04X ", szSymbol, dwSymDisplacement);
        if (pSymbol->dwFlags & 3)
        {
            sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "[omap] ");
        }

        if (tFrame.pFuncTableEntry)
        {
            D2FpoDataStrc* pFpo = (D2FpoDataStrc*)tFrame.pFuncTableEntry;
            switch (pFpo->cbFrame)
            {
            case 0:
                if (pFpo->fHasSEH)
                {
                    sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "(FPO: [SEH])");
                }
                else
                {
                    sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, " (FPO:");
                    if (pFpo->fUseBP)
                    {
                        sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, " [EBP 0x%08x]", tFrame.dwReserved[0]);
                    }

                    sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, " [%d, %d, %d])", pFpo->wParams, pFpo->dwLocals, pFpo->cbRegs);
                }
                break;

            case 3:
                sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "(FPO: Non-FPO [%d, %d, %d])", pFpo->wParams, pFpo->dwLocals, pFpo->cbRegs);
                break;

            default:
                sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "(UNKNOWN FPO TYPE)");
                break;
            }
        }

        if (tLine.dwLineNumber)
        {
            const char* szFile = strrchr(tLine.szFileName, '\\');
            szFile = szFile ? szFile + 1 : tLine.szFileName;
            int nPad = 0x18 - SStrLen(szSymbol);
            if (nPad < 1)
            {
                nPad = 1;
            }

            sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "%*s %s, %d", nPad, gszSpace_006FFC44, szFile, tLine.dwLineNumber);
        }

        sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, gszNewline_006FFCB0);
    }

    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "%d frames dumped", nFrames);
    sub_0040F960_CloseLogFiles();
    gpfnSymCleanup_0075CFDC(hProcess);
    CloseHandle(hProcess);
    return 1;
}

void __stdcall sub_H13_EmitUse(const char* szText, unsigned long nValue1, unsigned long nValue2, unsigned long nValue3);

__declspec(noinline) int sub_H13_EmitLineRetry(void* hProcess, unsigned long dwAddress, unsigned long dwDisplacement)
{
    D2ImageHlpLineStrc tLine;
    unsigned long dwDisp = dwDisplacement;
    tLine.dwSizeOfStruct = 0x14;
    const int bResult = sub_0040B600_GetLineFromAddrRetry(hProcess, dwAddress, &dwDisp, &tLine);
    sub_H13_EmitUse(tLine.szFileName, dwDisp, tLine.dwLineNumber, bResult);
    return bResult;
}
