struct D2ModuleInfoStrc
{
    char szPath[0x104];
    char szName[0x100];
    unsigned long dwBase;
    unsigned long dwSize;
    D2ModuleInfoStrc* pNext;
};

struct D2ImageHlpSymbolStrc
{
    unsigned long dwSizeOfStruct;
    unsigned long dwAddress;
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwMaxNameLength;
    char szName[4];
};

struct D2SymbolBufferStrc
{
    D2ImageHlpSymbolStrc tSymbol;
    char szNameBuffer[0x100];
};

struct D2ContextStrc
{
    char unk0x00[0xB8];
    unsigned long Eip;
    unsigned long SegCs;
    unsigned long EFlags;
    unsigned long Esp;
};

typedef int (__stdcall* D2SymGetSymFromAddrFn)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpSymbolStrc* pSymbol);

extern "C" __declspec(dllimport) int __stdcall IsBadReadPtr(const void* lp, unsigned int ucb); // 0x006CC238
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9
extern "C" unsigned int __cdecl strlen(const char* szString);
#pragma intrinsic(strlen)
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410660
void __cdecl sub_00410740_LogWritePrefixed00(const char* szPrefix, const char* szFormat, ...); // 0x00410740
char* __fastcall sub_004113E0_EscapeString(char* szDst, const char* szSrc, int nSize, char cQuote); // 0x004113E0
D2ModuleInfoStrc* __fastcall sub_0040BCB0_FindModuleByAddress(unsigned long dwAddress, D2ModuleInfoStrc* pList); // 0x0040BCB0
extern D2SymGetSymFromAddrFn gpfnSymGetSymFromAddr_0075CFF4; // 0x0075CFF4
extern const char gszStackEipLine_006CD938[]; // 0x006CD938
extern const char gszStackRowEnd_006CD90C[]; // 0x006CD90C
extern const char gszStackStringLine_006CD8C8[]; // 0x006CD8C8
extern const char gszStackSymbolLine_006CD890[]; // 0x006CD890
extern const char gszStackPad_006FFC44[]; // 0x006FFC44

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0040BCB0
D2ModuleInfoStrc* __fastcall sub_0040BCB0_FindModuleByAddress(unsigned long dwAddress, D2ModuleInfoStrc* pList)
{
    for (D2ModuleInfoStrc* pModule = pList; pModule; pModule = pModule->pNext)
    {
        if (dwAddress >= pModule->dwBase && dwAddress < pModule->dwBase + pModule->dwSize)
            return pModule;
    }
    return 0;
}

// 0x0040BCF0
void __fastcall sub_0040BCF0_DumpAnnotatedStack(void* hProcess, D2ContextStrc* pContext, D2ModuleInfoStrc* pModules)
{
    D2SymbolBufferStrc tSymbol;
    char szEscaped[0x50];
    char szLine[0x100];

    unsigned char* pStack = (unsigned char*)pContext->Esp;
    tSymbol.tSymbol.dwSizeOfStruct = 0x18;
    tSymbol.tSymbol.dwMaxNameLength = 0x100;
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, &gszEmptyAssertText);
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Annotated stack dump");

    {
        unsigned long dwDisplacement;
        unsigned long dwEip = pContext->Eip;
        D2ModuleInfoStrc* pModule = sub_0040BCB0_FindModuleByAddress(dwEip, pModules);
        const char* szSymbol = gpfnSymGetSymFromAddr_0075CFF4(hProcess, dwEip, &dwDisplacement, &tSymbol.tSymbol) ? tSymbol.tSymbol.szName : "unknown";
        const char* szModule = pModule ? pModule->szName : "unknown";
        sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, gszStackEipLine_006CD938, dwEip, szModule, szSymbol, dwDisplacement);
    }

    int nLines = 0;
    unsigned int nRemaining = 0x1000;
    while (nRemaining > 0)
    {
        if (nLines >= 400)
            break;
        sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "              %08X:", pStack);
        int nCount = nRemaining < 16 ? nRemaining : 16;
        szLine[0] = 0;
        int bFound = 0;
        if (IsBadReadPtr(pStack, nCount))
        {
            SStrCopy(szLine, "<unreadable>", 0x7FFFFFFF);
            break;
        }

        int i;
        for (i = 0; i < nCount; i += 4)
        {
            int nLen = strlen(szLine);
            SStrPrintf(&szLine[nLen], 0x100 - nLen, " %02X%02X%02X%02X", pStack[i], pStack[i + 1], pStack[i + 2], pStack[i + 3]);
            if (sub_0040BCB0_FindModuleByAddress(*(unsigned long*)&pStack[i], pModules))
            {
                bFound = 1;
                i += 4;
                break;
            }
        }

        int nBytes = i;
        for (i = (unsigned int)((16 - i) * 9) / 4 + 2; i > 0; i--)
            sub_00413800(szLine, gszStackPad_006FFC44, 0x100);

        int nLen = strlen(szLine);
        int j = nLen;
        for (i = 0; i < nBytes; i++)
        {
            unsigned char c = pStack[i];
            szLine[j++] = (c & 0x7F) < 0x20 ? '.' : c;
        }
        szLine[nLen + i] = 0;
        sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, gszStackRowEnd_006CD90C, szLine);

        if (bFound)
        {
            unsigned long dwValue = *(unsigned long*)&pStack[nBytes - 4];
            D2ModuleInfoStrc* pValueModule = sub_0040BCB0_FindModuleByAddress(dwValue, pModules);
            D2_ASSERT(pValueModule, 0x3A5);
            unsigned long dwValueDisplacement;
            const char* szName = gpfnSymGetSymFromAddr_0075CFF4(hProcess, dwValue, &dwValueDisplacement, &tSymbol.tSymbol) ? tSymbol.tSymbol.szName : "unknown";
            if (!_stricmp(szName, "`string'") && !dwValueDisplacement)
                sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, gszStackStringLine_006CD8C8, dwValue, pValueModule->szName, szName, sub_004113E0_EscapeString(szEscaped, (const char*)dwValue, 0x50, 0));
            else
                sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, gszStackSymbolLine_006CD890, dwValue, pValueModule->szName, szName, dwValueDisplacement);
            nLines += 3;
        }

        nLines++;
        nRemaining -= nBytes;
        pStack += nBytes;
    }
}

#include "gen/data/Source/Fog/Src/Exceptions_0040BCF0.inc"
