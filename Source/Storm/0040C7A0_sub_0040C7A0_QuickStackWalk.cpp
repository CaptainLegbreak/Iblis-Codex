struct D2ImageHlpLineStrc
{
    unsigned long dwSizeOfStruct;
    void* pKey;
    unsigned long dwLineNumber;
    char* szFileName;
    unsigned long dwAddress;
};

struct D2AddressStrc
{
    unsigned long dwOffset;
    unsigned short wSegment;
    int nMode;
};

struct D2StackFrameStrc
{
    D2AddressStrc tAddrPC;
    D2AddressStrc tAddrReturn;
    D2AddressStrc tAddrFrame;
    D2AddressStrc tAddrStack;
    void* pFuncTableEntry;
    unsigned long dwParams[4];
    int bFar;
    int bVirtual;
    unsigned long dwReserved[3];
    unsigned long dwKdHelp[19];
};

struct D2ImageHlpSymbolStrc
{
    unsigned long dwSizeOfStruct;
    unsigned long dwAddress;
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwMaxNameLength;
    char szName[1];
};

struct D2ImageHlpModuleStrc
{
    unsigned long dwSizeOfStruct;
    unsigned long dwBaseOfImage;
    unsigned long dwImageSize;
    unsigned long dwTimeDateStamp;
    unsigned long dwCheckSum;
    unsigned long dwNumSyms;
    int nSymType;
    char szModuleName[32];
    char szImageName[256];
    char szLoadedImageName[256];
};

struct D2ContextStrc
{
    char unk0x00[0xB4];
    unsigned long dwEbp;
    unsigned long dwEip;
    unsigned long dwSegCs;
    unsigned long dwEFlags;
    unsigned long dwEsp;
};

typedef int (__stdcall* StackWalkFn)(unsigned long dwMachine, void* hProcess, void* hThread, D2StackFrameStrc* pFrame, void* pContext, void* pfnReadMemory, void* pfnFunctionTableAccess, void* pfnGetModuleBase, void* pfnTranslateAddress);
typedef int (__stdcall* SymGetSymFromAddrFn)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpSymbolStrc* pSymbol);
typedef int (__stdcall* SymGetModuleInfoFn)(void* hProcess, unsigned long dwAddress, D2ImageHlpModuleStrc* pModuleInfo);
typedef int (__stdcall* SymGetLineFromAddrFn)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine);

extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();                                    // 0x006CC1B4
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess();                                       // 0x006CC13C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" const char gszEmptyString_006FFC44[];                                                            // 0x006FFC44
extern "C" const char gszUnknown_006CD5FC[];                                                                // 0x006CD5FC
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...);                // 0x00410660
const char* __fastcall sub_00408000_StripSourcePath(const char* szPath);                                    // 0x00408000
int __stdcall SStrLen(const char* szString);                                                                // 0x00413750
int __cdecl sub_0040C620_SymInitializeOnce();                                                               // 0x0040C620
int __fastcall sub_0040C720_SymCleanupOnce(int bAll);                                                       // 0x0040C720

extern SymGetLineFromAddrFn gpfnSymGetLineFromAddr_0075CFE4;                                                // 0x0075CFE4
extern void* gpfnSymFunctionTableAccess_0075CFE0;                                                           // 0x0075CFE0
extern void* gpfnSymGetModuleBase_0075CFE8;                                                                 // 0x0075CFE8
extern SymGetModuleInfoFn gpfnSymGetModuleInfo_0075CFEC;                                                    // 0x0075CFEC
extern SymGetSymFromAddrFn gpfnSymGetSymFromAddr_0075CFF4;                                                  // 0x0075CFF4
extern StackWalkFn gpfnStackWalk_0075D008;                                                                  // 0x0075D008
extern unsigned int gnStackWalkDepth_0075D018;                                                              // 0x0075D018

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

// 0x0040C7A0
int __fastcall sub_0040C7A0_QuickStackWalk(const char* szPrefix, void* hThread, D2ContextStrc* pContext)
{
    if (gnStackWalkDepth_0075D018 > 0)
    {
        return 0;
    }

    ++gnStackWalkDepth_0075D018;

    __int64 aTotals[4] = {};
    __int64 aStart[4] = {};
    __int64 aEnd[4] = {};

    void* hProcess = GetCurrentProcess();
    if (!sub_0040C620_SymInitializeOnce())
    {
        --gnStackWalkDepth_0075D018;
        return 0;
    }
    aTotals[3] += aEnd[3] - aStart[3];

    D2StackFrameStrc tFrame;
    memset(&tFrame, 0, sizeof(tFrame));
    tFrame.tAddrPC.dwOffset = pContext->dwEip;
    tFrame.tAddrPC.nMode = 3;
    tFrame.tAddrStack.dwOffset = pContext->dwEsp;
    tFrame.tAddrStack.nMode = 3;
    tFrame.tAddrFrame.dwOffset = pContext->dwEbp;
    tFrame.tAddrFrame.nMode = 3;

    char aSymbolBuffer[sizeof(D2ImageHlpSymbolStrc) + 0x100];
    D2ImageHlpSymbolStrc* pSymbol = (D2ImageHlpSymbolStrc*)aSymbolBuffer;
    pSymbol->dwSizeOfStruct = sizeof(D2ImageHlpSymbolStrc);
    pSymbol->dwMaxNameLength = 0x100;

    unsigned long aStack[64];
    int nFailures = 0;
    int nEntries;
    for (nEntries = 0; nEntries < 16; ++nEntries)
    {
        if (nFailures >= 3)
        {
            break;
        }

        if (!gpfnStackWalk_0075D008(0x14C, hProcess, hThread, &tFrame, pContext, 0, gpfnSymFunctionTableAccess_0075CFE0, gpfnSymGetModuleBase_0075CFE8, 0))
        {
            aTotals[0] += aEnd[0] - aStart[0];
            break;
        }
        aTotals[0] += aEnd[0] - aStart[0];

        if (nEntries >= 1)
        {
            aStack[nEntries] = tFrame.tAddrPC.dwOffset;
            const char* szSymbol;
            unsigned long dwDisplacement = 0;
            D2ImageHlpLineStrc tLine;
            memset(&tLine, 0, sizeof(tLine));
            tLine.dwSizeOfStruct = sizeof(tLine);
            if (gpfnSymGetSymFromAddr_0075CFF4(hProcess, tFrame.tAddrPC.dwOffset, &dwDisplacement, pSymbol))
            {
                szSymbol = pSymbol->szName;
                unsigned long dwLineDisplacement = dwDisplacement;
                if (!sub_0040B600_GetLineFromAddrRetry(hProcess, tFrame.tAddrPC.dwOffset, &dwLineDisplacement, &tLine))
                {
                    tLine.dwLineNumber = 0;
                }
            }
            else
            {
                ++nFailures;
                szSymbol = gszUnknown_006CD5FC;
            }
            aTotals[1] += aEnd[1] - aStart[1];

            D2ImageHlpModuleStrc tModule;
            memset(&tModule, 0, sizeof(tModule));
            tModule.dwSizeOfStruct = sizeof(tModule);
            if (!gpfnSymGetModuleInfo_0075CFEC(hProcess, tFrame.tAddrPC.dwOffset, &tModule))
            {
                GetLastError();
                tModule.szModuleName[0] = 0;
            }
            aTotals[2] += aEnd[2] - aStart[2];

            if (tLine.dwLineNumber)
            {
                const char* szFile = sub_00408000_StripSourcePath(tLine.szFileName);
                int nPad = 40 - SStrLen(tModule.szModuleName) - SStrLen(szSymbol);
                if (nPad < 1)
                {
                    nPad = 1;
                }
                sub_00410660_LogWritePrefixed(szPrefix, "    %08X  %s!%s+%04X  %*s%s,%d", tFrame.tAddrPC.dwOffset, tModule.szModuleName, szSymbol, dwDisplacement, nPad, gszEmptyString_006FFC44, szFile, tLine.dwLineNumber);
            }
            else
            {
                sub_00410660_LogWritePrefixed(szPrefix, "    %08X  %s!%s+%04X", tFrame.tAddrPC.dwOffset, tModule.szModuleName, szSymbol, dwDisplacement);
            }
        }
    }

    sub_0040C720_SymCleanupOnce(0);
    sub_00410660_LogWritePrefixed(szPrefix, "QuickStackWalk: %d entries, %I64d+%I64d+%I64d+%I64d cycles, %I64d avg", nEntries, aTotals[0], aTotals[1], aTotals[2], aTotals[3], (aTotals[0] + aTotals[1] + aTotals[2] + aTotals[3]) / nEntries);
    --gnStackWalkDepth_0075D018;
    return 1;
}
