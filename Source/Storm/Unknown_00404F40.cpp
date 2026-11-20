#include "Storm.h"
#include "D2CrashTypes.h"
#define CMD_BOOLEAN 0
#define CMD_INTEGER 1
#define CMD_STRING 2
struct D2ConfigStrc;
struct D2PoolSystemStrc;
struct D2ImageDataDirStrc;
struct D2ImageOptionalHeader64Strc;
struct D2ImageOptionalHeader32Strc;
struct D2FloatSaveStrc;
struct D2StackFrameStrc;
struct D2IniEntryStrc;
struct Character;
struct D2CmdArgStrc;
struct D2ComInterfaceStrc;

struct D2ImageOptionalHeader32Strc
{
    unsigned short Magic;
    unsigned char unk0x02[0x5A];
    unsigned long NumberOfRvaAndSizes;
    D2ImageDataDirStrc DataDirectory[16];
};

static __declspec(noinline) void __stdcall sub_00404F60_GetDebugDirectory32(unsigned long* pSize, unsigned long* pRva, const D2ImageOptionalHeader32Strc* pHeader);

struct D2StackFrameStrc
{
    unsigned long dwPc;
    unsigned long dwFrame;
    unsigned long dwStack;
    unsigned long dwReturn;
    unsigned char bHasArgs;
    void* apArgs[4];
};

struct D2ThreadContextStrc
{
    unsigned long ContextFlags;
    unsigned long Dr0;
    unsigned long Dr1;
    unsigned long Dr2;
    unsigned long Dr3;
    unsigned long Dr6;
    unsigned long Dr7;
    D2FloatSaveStrc FloatSave;
    unsigned long SegGs;
    unsigned long SegFs;
    unsigned long SegEs;
    unsigned long SegDs;
    unsigned long Edi;
    unsigned long Esi;
    unsigned long Ebx;
    unsigned long Edx;
    unsigned long Ecx;
    unsigned long Eax;
    unsigned long Ebp;
    unsigned long Eip;
    unsigned long SegCs;
    unsigned long EFlags;
    unsigned long Esp;
    unsigned long SegSs;
    unsigned char ExtendedRegisters[512];

    int sub_00405060_CaptureFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, int nSkipFrames);
};

extern "C" __declspec(dllimport) unsigned long __stdcall VirtualQuery(const void* pAddress, D2MemoryBasicInfoStrc* pBuffer, unsigned long nLength); // 0x006CC244
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650
void* __stdcall SMemAlloc(size_t nSize, const char* szFile, int nLine, int nFlags); // 0x00413020
extern "C" const char gszNew_006CC82C[]; // 0x006CC82C
int __fastcall sub_00406B60_GetModuleDirectory(char* szPath, unsigned int nSize); // 0x00406B60
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800

struct D2IniEntryStrc
{
    char szSection[0x1B];
    char szKey[0x36];
    unsigned char nType;
    char pad0x52[2];
    int nOffset;
    int nDefault;
};

extern D2IniEntryStrc gaIniEntries_00705040[58]; // 0x00705040
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(dllimport) unsigned int __stdcall GetPrivateProfileIntA(const char* szAppName, const char* szKeyName, int nDefault, const char* szFileName); // 0x006CC150
extern "C" __declspec(dllimport) unsigned long __stdcall GetPrivateProfileStringA(const char* szAppName, const char* szKeyName, const char* szDefault, char* szReturned, unsigned long nSize, const char* szFileName); // 0x006CC420
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode); // 0x0068239A
extern "C" int __cdecl fputc(int nChar, _iobuf* pFile); // 0x00682058
void __stdcall sub_00525260(void* pOut, int nField); // 0x00525260
int __cdecl sub_00408F20_HasExpansionMpq(); // 0x00408F20
int __fastcall sub_00406C40_GetBlizzardDataPath(char* szOutPath, int nSize); // 0x00406C40
bool __fastcall sub_00516DE1_Verify(void* pContext); // 0x00516DE1
bool __fastcall sub_00516D8B_RunSurvey(const char* szExePath); // 0x00516D8B
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

struct Character { signed char value; };

enum { UPPER_FIRST = 65, UPPER_LAST = 90, CASE_DELTA = 32 };

extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2CmdArgStrc
{
    char szSection[0x1B];
    char szKey[0x1B];
    char szCommand[0x1B];
    unsigned char nType;
    int nIndex;
    int nDefault;
};

extern D2CmdArgStrc gaCmdArguments[58]; // 0x00705040
void __stdcall sub_00405450_LoadIniSettings(char* pSettings); // 0x00405450
void __cdecl sub_006114E0_CreateIgnoreList(); // 0x006114E0
int __fastcall sub_00405710_ParseCmdArgument(char* szCommandNameTestBuf, const char* pszCommand, char* szCommandValueBuf); // 0x00405710

typedef int BOOL;

struct D2ComInterfaceStrc
{
    char unk0x00[0x10];
    void (__cdecl* pfnRelease)();
};

struct D2ConfigStrc
{
    int bIsExpansion;
    int nUnk0x04;
    unsigned char bWindow;
    unsigned char bNoFixedAspect;
    unsigned char b3DFX;
    unsigned char unk0x0B[2];
    unsigned char bD3D;
    unsigned char bPerspective;
    unsigned char bQuality;
    int nGamma;
    unsigned char bVSync;
    char unk0x15[0x1EF];
    unsigned char bDirect;
    unsigned char unk0x205;
    unsigned char bNoCompress;
    char unk0x207[0x19];
    unsigned char bNoSound;
    char unk0x221[3];
    unsigned char bSoundBackground;
    unsigned char pComInterface[4];
};
int __stdcall sub_004059D0_RunModeInterface(D2ConfigStrc* pCfg); // 0x004059D0
void __stdcall sub_00405A70_WriteSurveyLocale(); // 0x00405A70
void __fastcall sub_00406870_InitStorm(int nDirectFlags, int nValue); // 0x00406870
void __cdecl sub_00407970_ForceCrash(); // 0x00407970
void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem); // 0x00409C80
void __fastcall FOG_AsyncDataInitialize(int bEnable, int nUnused); // 0x0040A390
void __cdecl FOG_AsyncDataDestroy(); // 0x0040A440
void __cdecl FOG_10218(); // 0x0040B0C0
void __cdecl FOG_10082_Noop(); // 0x0040B320
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
void __cdecl D2MCPClientCloseMCP(); // 0x00449AD0
int __stdcall D2GFX_Release(); // 0x004F5050
void __stdcall D2GFX_SetPerspective(int bPerspective); // 0x004F51E0
int __stdcall D2GFX_SetGamma(int nGamma); // 0x004F5230
void __cdecl D2GFX_EnableVSync(); // 0x004F5270
void __cdecl sub_004F5280(); // 0x004F5280
int __stdcall D2GFX_ToggleLowQuality(); // 0x004F54F0
int __cdecl sub_004F59A0(); // 0x004F59A0
int __stdcall D2Win_InitializeSpriteCache(int bWindowed, int nResolution); // 0x004F8F10
int __stdcall D2Win_CloseSpriteCache(); // 0x004F9030
int __stdcall D2Win_CreateWindow(void* hInstance, int nRenderMode, int bWindowed, int bCompress); // 0x004FA520
int __cdecl sub_004FAB00_ShowInsertExpansionDisc(); // 0x004FAB00
int __cdecl sub_004FAB30_ShowInsertPlayDisc(); // 0x004FAB30
int __cdecl ARCHIVE_LoadArchives(); // 0x004FAB90
void __cdecl ARCHIVE_FreeArchives(); // 0x004FAE00
int __fastcall ARCHIVE_LoadExpansionArchives(int (__cdecl* pfnPlayDisc)(), int (__cdecl* pfnExpansionDisc)(), int nUnused, D2ConfigStrc* pCfg); // 0x004FAEC0
void __cdecl sub_00514060_ShutdownSound(); // 0x00514060
void __fastcall sub_00514530_InitSound(int bExpansion, int bSoundBackground); // 0x00514530
int __cdecl STRTABLE_GetLanguage(); // 0x00525150
void __cdecl sub_0060DDB0(); // 0x0060DDB0
extern "C" __declspec(dllimport) unsigned long __stdcall GetVersion(); // 0x006CC138
extern "C" __declspec(dllimport) void* __stdcall OpenSCManagerA(const char* szMachineName, const char* szDatabaseName, unsigned long dwDesiredAccess); // 0x006CC028
extern "C" __declspec(dllimport) void* __stdcall OpenServiceA(void* hSCManager, const char* szServiceName, unsigned long dwDesiredAccess); // 0x006CC04C
extern char gszServiceName_007065DC[]; // 0x007065DC

void __cdecl operator delete(void* pMemory);
void* __cdecl operator new(size_t nSize);

// 0x00404F40
static __declspec(noinline) void __stdcall sub_00404F40_GetDebugDirectory64(unsigned long* pSize, unsigned long* pRva, const D2ImageOptionalHeader64Strc* pHeader)
{
    if (pHeader->NumberOfRvaAndSizes > 6)
    {
        const D2ImageDataDirStrc tDir = pHeader->DataDirectory[6];
        *pRva = tDir.VirtualAddress;
        *pSize = tDir.Size;
    }
}

void __fastcall sub_G02_Emit_00404F40(const D2ImageOptionalHeader64Strc* pHeader, unsigned long* pOut)
{
    sub_00404F40_GetDebugDirectory64(&pOut[1], &pOut[0], pHeader);
    sub_00404F40_GetDebugDirectory64(&pOut[3], &pOut[2], pHeader + 1);
}

// 0x00404F60
static void __stdcall sub_00404F60_GetDebugDirectory32(unsigned long* pSize, unsigned long* pRva, const D2ImageOptionalHeader32Strc* pHeader)
{
    if (pHeader->NumberOfRvaAndSizes > 6)
    {
        const D2ImageDataDirStrc tDir = pHeader->DataDirectory[6];
        *pRva = tDir.VirtualAddress;
        *pSize = tDir.Size;
    }
}

void __fastcall DebugDirectory32Context(const D2ImageOptionalHeader32Strc* pHeader, unsigned long* pOut)
{
    sub_00404F60_GetDebugDirectory32(&pOut[1], &pOut[0], pHeader);
    sub_00404F60_GetDebugDirectory32(&pOut[3], &pOut[2], pHeader + 1);
}

// 0x00401480
static unsigned char __stdcall sub_00401480_GetStackRange(void** ppBase, unsigned long* pEnd, const void* pAddress)
{
    D2MemoryBasicInfoStrc tInfo;
    if (!VirtualQuery(pAddress, &tInfo, sizeof(tInfo)))
        return 0;
    if (tInfo.State != 0x1000)
        return 0;
    if (tInfo.Type != 0x20000)
        return 0;
    if (tInfo.Protect != 4)
        return 0;
    *pEnd = (unsigned long)tInfo.BaseAddress + tInfo.RegionSize;
    if (*pEnd <= (unsigned long)pAddress)
        return 0;
    *ppBase = tInfo.AllocationBase;
    if (!VirtualQuery(tInfo.AllocationBase, &tInfo, sizeof(tInfo)))
        return 0;
    if (tInfo.Type != 0x20000)
        return 0;
    if (tInfo.BaseAddress != *ppBase)
        return 0;
    unsigned long dwEnd = (unsigned long)*ppBase + tInfo.RegionSize;
    if (tInfo.State == 0x1000)
    {
        if (dwEnd != *pEnd)
            return 0;
        *ppBase = tInfo.AllocationBase;
        return 1;
    }
    if (tInfo.State == 0x2000)
    {
        if (dwEnd >= *pEnd)
            return 0;
        *ppBase = tInfo.AllocationBase;
        return 1;
    }
    return 0;
}

// 0x00401540
static unsigned char __stdcall sub_00401540_GetThreadStack(unsigned long* pStackSize, unsigned long dwThreadId, unsigned long* pStackTop, unsigned long* pStackPointer)
{
    D2ThreadContextStrc tContext;
    void* hThread = 0;
    tContext.ContextFlags = 0x10001;
    if (GetCurrentThreadId() == dwThreadId)
    {
        RtlCaptureContext(&tContext);
    }
    else
    {
        hThread = OpenThread(0x4A, 0, dwThreadId);
        if (!hThread)
            return 0;
        if (SuspendThread(hThread) == -1)
            return 0;
        if (!GetThreadContext(hThread, &tContext))
        {
            ResumeThread(hThread);
            CloseHandle(hThread);
            return 0;
        }
    }
    *pStackPointer = tContext.Esp;
    void* pBase;
    unsigned long dwEnd;
    unsigned char bResult = sub_00401480_GetStackRange(&pBase, &dwEnd, (const void*)tContext.Esp);
    if (bResult)
    {
        *pStackTop = dwEnd;
        *pStackSize = dwEnd - (unsigned long)pBase;
    }
    if (hThread)
    {
        ResumeThread(hThread);
        CloseHandle(hThread);
    }
    return bResult;
}

// 0x00405060
int D2ThreadContextStrc::sub_00405060_CaptureFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, int nSkipFrames)
{
    D2StackFrameStrc* pOut = pFrames;
    unsigned int nMaxFrames = 0x80;
    D2ThreadContextStrc tContext;
    void* hThread = 0;
    if (this)
    {
        tContext = *this;
    }
    else
    {
        if (GetCurrentThreadId() == dwThreadId)
        {
            tContext.ContextFlags = 0x10001;
            RtlCaptureContext(&tContext);
        }
        else
        {
            tContext.ContextFlags = 0x10001;
            hThread = OpenThread(0x4A, 0, dwThreadId);
            if (!hThread)
                return 0;
            if (SuspendThread(hThread) == -1)
                return 0;
            if (!GetThreadContext(hThread, &tContext))
            {
                ResumeThread(hThread);
                CloseHandle(hThread);
                return 0;
            }
        }
    }
    unsigned int nCount = 0;
    unsigned long dwPc = tContext.Eip;
    unsigned long dwFrame = tContext.Ebp;
    unsigned long dwStack = tContext.Esp;
    unsigned long dwStackTop;
    unsigned long dwStackSize;
    unsigned long dwStackPointer;
    if (!sub_00401540_GetThreadStack(&dwStackSize, dwThreadId, &dwStackTop, &dwStackPointer))
    {
        if (hThread)
        {
            ResumeThread(hThread);
            CloseHandle(hThread);
        }
        return 0;
    }
    __try
    {
        for (unsigned int i = 0; i < nMaxFrames; i++)
        {
            if (i >= (unsigned int)nSkipFrames)
            {
                pOut[nCount].dwPc = dwPc;
                pOut[nCount].dwStack = dwStack;
                pOut[nCount].dwFrame = dwFrame;
                nCount++;
                if (nCount >= nMaxFrames)
                    break;
            }
            if (dwFrame <= dwStack)
                break;
            if (dwFrame + 8 > dwStackTop)
                break;
            unsigned long dwNext = *(unsigned long*)dwFrame;
            if (dwNext & 3)
                break;
            if (dwNext <= dwFrame)
                break;
            dwPc = *(unsigned long*)(dwFrame + 4);
            dwStack = dwFrame + 4;
            dwFrame = dwNext;
        }
    }
    __except (1)
    {
    }
    if (hThread)
    {
        ResumeThread(hThread);
        CloseHandle(hThread);
    }
    return nCount;
}

// build: symbol ??3@YAXPAX@Z 0x004053F0
void __cdecl operator delete(void* pMemory)
{
    if (pMemory)
    {
        SMemFree(pMemory, "delete", -1, 0);
    }
}

// build: symbol ??2@YAPAXI@Z 0x00405410
void* __cdecl operator new(size_t nSize)
{
    return SMemAlloc(nSize, gszNew_006CC82C, -1, 0);
}

// 0x00405430
static __forceinline void sub_00405430_GetIniPath(char* szPath)
{
    sub_00406B60_GetModuleDirectory(szPath, 0x104);
    sub_00413800(szPath, "D2.ini", 0x104);
}

void __stdcall sub_M114_Emit_00405430(char* szPath)
{
    sub_00405430_GetIniPath(szPath);
}

// 0x00405450
void __stdcall sub_00405450_LoadIniSettings(char* pSettings)
{
    char szIni[0x104];
    sub_00406B60_GetModuleDirectory(szIni, 0x104);
    sub_00413800(szIni, "D2.ini", 0x104);
    for (int i = 0; i < sizeof(gaIniEntries_00705040) / sizeof(gaIniEntries_00705040[0]); i++)
    {
        char* pDest = pSettings + gaIniEntries_00705040[i].nOffset;
        switch (gaIniEntries_00705040[i].nType)
        {
        case 0:
            *pDest = GetPrivateProfileIntA(gaIniEntries_00705040[i].szSection, gaIniEntries_00705040[i].szKey, gaIniEntries_00705040[i].nDefault, szIni) != 0;
            break;
        case 1:
            *(int*)pDest = GetPrivateProfileIntA(gaIniEntries_00705040[i].szSection, gaIniEntries_00705040[i].szKey, gaIniEntries_00705040[i].nDefault, szIni);
            break;
        case 2:
            GetPrivateProfileStringA(gaIniEntries_00705040[i].szSection, gaIniEntries_00705040[i].szKey, &gszEmptyAssertText, pDest, 0x1B, szIni);
            break;
        }
    }
}

// 0x00405A70
void __stdcall sub_00405A70_WriteSurveyLocale()
{
    unsigned int nLanguage;
    char szPath[0x104];
    char szExe[0x400];
    sub_00525260(&nLanguage, 3);
    if (sub_00406C40_GetBlizzardDataPath(szPath, 0x104))
    {
        sub_00413800(szPath, "System Survey\\ProductData\\", 0x104);
        char* pEnd = szPath + SStrLen(szPath);
        unsigned int nRemain = szPath + sizeof(szPath) - pEnd;
        SStrCopy(pEnd, "D2DV\\locale", nRemain);
        sub_00406A10_CreateDirectoryTree(szPath);
        _iobuf* pFile = fopen(szPath, "w");
        if (pFile)
        {
            fputc(nLanguage >> 24, pFile);
            fputc((nLanguage >> 16) & 0xFF, pFile);
            fputc((nLanguage >> 8) & 0xFF, pFile);
            fputc(nLanguage & 0xFF, pFile);
            fclose(pFile);
        }
        if (sub_00408F20_HasExpansionMpq())
        {
            SStrCopy(pEnd, "D2XP\\locale", nRemain);
            sub_00406A10_CreateDirectoryTree(szPath);
            pFile = fopen(szPath, "w");
            if (pFile)
            {
                fputc(nLanguage >> 24, pFile);
                fputc((nLanguage >> 16) & 0xFF, pFile);
                fputc((nLanguage >> 8) & 0xFF, pFile);
                fputc(nLanguage & 0xFF, pFile);
                fclose(pFile);
            }
        }
    }
    sub_00406B60_GetModuleDirectory(szExe, 0x400);
    sub_00413800(szExe, "SystemSurvey.exe", 0x400);
    if (sub_00516DE1_Verify(szExe))
        sub_00516D8B_RunSurvey(szExe);
}

#include "gen/data/Source/Storm/Unknown_00404F40.inc"

// 0x00405550
void __fastcall sub_00405550(Character* text)
{
    while(text->value) {
        if(text->value>=UPPER_FIRST && text->value<=UPPER_LAST)
            text->value+=CASE_DELTA;
        ++text;
    }
}

static int sub_004055D0_IsCmdSeparator_Inl(char c)
{
    const char aSeparators[4] = { ' ', '\t', '\n', ':' };
    for (int i = 0; i < 4; i++)
    {
        if (aSeparators[i] == c)
        {
            return 1;
        }
    }
    return 0;
}

static void __fastcall sub_00405550_stoLower_Inl(char* s)
{
    while (*s)
    {
        if (*s >= 'A' && *s <= 'Z')
        {
            *s += 'a' - 'A';
        }
        s++;
    }
}

// 0x00405610
static void ParseCmdValue(char* s)
{
    char szBuf[0x100];
    strcpy(szBuf, s);
    const int nLen = strlen(s);
    int i = 0;
    for (; i < nLen; i++)
    {
        if (!sub_004055D0_IsCmdSeparator_Inl(s[i]))
        {
            break;
        }
    }
    int nOut = 0;
    for (; i < nLen; i++)
    {
        if (sub_004055D0_IsCmdSeparator_Inl(szBuf[i]))
        {
            break;
        }
        s[nOut++] = szBuf[i];
    }
    s[nOut] = 0;
}

int __fastcall sub_00405710_ParseCmdArgument(char* szCommandNameTestBuf, const char* pszCommand, char* szCommandValueBuf)
{
    char szCommand[0x100];
    const int nRemainingLen = strlen(pszCommand);
    int nCommandIndex = -1;
    int i = 0;
    D2_ASSERT(nRemainingLen < 0x100, 259);
    while (i < nRemainingLen && pszCommand[i] != '-' && pszCommand[i] != '\0')
    {
        szCommand[i] = pszCommand[i];
        i++;
    }
    szCommand[i] = '\0';
    szCommand[i + 1] = '\0';
    strcpy(szCommandNameTestBuf, szCommand);
    const int nCommandLength = strlen(szCommandNameTestBuf);
    int bContinue = 1;
    sub_00405550_stoLower_Inl(szCommandNameTestBuf);
    for (int n = nCommandLength; n != 0 && bContinue; n--)
    {
        szCommandNameTestBuf[n] = '\0';
        nCommandIndex = GetCmdIndex(szCommandNameTestBuf);
        if (nCommandIndex != -1)
        {
            bContinue = 0;
        }
    }
    const int nCommandValueOffset = strlen(szCommandNameTestBuf);
    int nValueIdx = 0;
    for (; szCommand[nValueIdx]; nValueIdx++)
    {
        szCommandValueBuf[nValueIdx] = szCommand[nCommandValueOffset + nValueIdx];
    }
    szCommandValueBuf[nValueIdx] = '\0';
    ParseCmdValue(szCommandValueBuf);
    return nCommandIndex;
}

// 0x004058A0
static void __stdcall sub_004058A0_ParseCmdArgs(D2ConfigStrc* pCfg, const char* argv)
{
    char szCommandNameTestBuf[0x100];
    char szCommandValueBuf[0x100];

    const int nArgvLength = strlen(argv);
    for (int nCharIndex = 0; nCharIndex < nArgvLength; nCharIndex++)
    {
        if (argv[nCharIndex] != '-')
        {
            continue;
        }
        nCharIndex++;

        if (nCharIndex < nArgvLength)
        {
            const int nCommandIndex = sub_00405710_ParseCmdArgument(szCommandNameTestBuf, &argv[nCharIndex], szCommandValueBuf);
            if (nCommandIndex != -1)
            {
                void* pCfgMember = (char*)pCfg + gaCmdArguments[nCommandIndex].nIndex;

                switch (gaCmdArguments[nCommandIndex].nType)
                {
                case CMD_INTEGER:
                    *(int*)pCfgMember = atoi(szCommandValueBuf);
                    break;
                case CMD_STRING:
                    strcpy((char*)pCfgMember, szCommandValueBuf);
                    break;
                case CMD_BOOLEAN:
                    *(unsigned char*)pCfgMember = 1;
                    break;
                }
            }
        }
    }
}

// 0x004059A0
void __fastcall ParseCmdLine(D2ConfigStrc* pCfg, const char* argv)
{
    memset(pCfg, 0, 0x3CD);
    sub_00405450_LoadIniSettings((char*)pCfg);
    sub_006114E0_CreateIgnoreList();
    sub_004058A0_ParseCmdArgs(pCfg, argv);
}

// 0x00405A50
void __cdecl sub_00405A50_Nop()
{
}

// 0x00405A60
void __cdecl sub_00405A60_Nop()
{
}

// 0x0063A800
void __cdecl sub_0063A800_Nop()
{
}

// 0x004DF920
void __cdecl sub_004DF920_Nop()
{
}

// 0x004DF930
void __cdecl sub_004DF930_Nop()
{
}

// 0x00587830
void __cdecl sub_00587830_Nop()
{
}

int gnMode_0074C704; // 0x0074C704

int gbUseKeyhook_0074C708; // 0x0074C708

void* ghModKeyhook_0074C70C; // 0x0074C70C

// 0x00405C30
int __fastcall GameStart(void* hInstance, D2ConfigStrc* pCfg, int nModType)
{
    if (pCfg->nUnk0x04 == 1)
    {
        sub_00407970_ForceCrash();
    }

    gnMode_0074C704 = nModType;

    BOOL bSoundStarted = 0;
    BOOL bGfxStarted = 0;

    sub_00406870_InitStorm(pCfg->bDirect, 0);
    FOG_AsyncDataInitialize(1, 0);
    FOG_10082_Noop();
    FOG_10218();

    if (gnMode_0074C704 != 2)
    {
        if (!ARCHIVE_LoadArchives() || !ARCHIVE_LoadExpansionArchives(sub_004FAB30_ShowInsertPlayDisc, sub_004FAB00_ShowInsertExpansionDisc, 0, pCfg))
        {
            ARCHIVE_FreeArchives();
            return 0;
        }
        pCfg->bIsExpansion = sub_00408F20_HasExpansionMpq();
        sub_00405A70_WriteSurveyLocale();
    }

    STRTABLE_GetLanguage();

    if (pCfg->b3DFX)
    {
        nModType = 4;
    }
    else if (pCfg->bWindow)
    {
        nModType = 1;
    }
    else
    {
        nModType = pCfg->bD3D ? 6 : 3;
    }

    const BOOL bWindowed = pCfg->bWindow != 0;
    const int nResolution = pCfg->bIsExpansion ? 2 : 0;

    if (gnMode_0074C704 != 2)
    {
        if (!D2Win_CreateWindow(hInstance, nModType, bWindowed, !pCfg->bNoCompress))
        {
            return 0;
        }

        if (pCfg->bPerspective && nModType >= 4)
        {
            D2GFX_SetPerspective(1);
        }

        if (!D2Win_InitializeSpriteCache(bWindowed, nResolution))
        {
            D2GFX_Release();
            return 0;
        }

        if (gbUseKeyhook_0074C708)
        {
            ghModKeyhook_0074C70C = LoadLibraryA("Keyhook.dll");
        }

        if (ghModKeyhook_0074C70C)
        {
            void (__stdcall* pfnInstall)(int) = (void (__stdcall*)(int))GetProcAddress(ghModKeyhook_0074C70C, "InstallKeyboardHook");
            if (pfnInstall)
            {
                pfnInstall(sub_004F59A0());
            }
        }

        bGfxStarted = 1;
    }

    if (pCfg->bQuality)
    {
        D2GFX_ToggleLowQuality();
    }

    if (pCfg->nGamma)
    {
        D2GFX_SetGamma(pCfg->nGamma);
    }

    if (pCfg->bVSync)
    {
        D2GFX_EnableVSync();
    }

    unsigned long bFixedAspect = 1;
    SRegLoadValue("Diablo II", "Fixed Aspect Ratio", 0, &bFixedAspect);
    if (pCfg->bNoFixedAspect || bFixedAspect != 1)
    {
        sub_004F5280();
    }

    if (!pCfg->bIsExpansion)
    {
        SRegSaveValue("Diablo II", "Resolution", 0, 0);
    }

    if (!pCfg->bNoSound && gnMode_0074C704 != 2)
    {
        sub_00514530_InitSound(pCfg->bIsExpansion, pCfg->bSoundBackground);
        bSoundStarted = 1;
    }

    while (gnMode_0074C704 != 0)
    {
        if (gnMode_0074C704 == 2)
        {
            if (bSoundStarted)
            {
                sub_00514060_ShutdownSound();
                bSoundStarted = 0;
            }

            if (bGfxStarted)
            {
                D2Win_CloseSpriteCache();
                D2GFX_Release();
                bGfxStarted = 0;
            }
        }

        gnMode_0074C704 = sub_004059D0_RunModeInterface(pCfg);
    }

    if (bSoundStarted)
    {
        sub_00514060_ShutdownSound();
    }

    if (bGfxStarted)
    {
        D2Win_CloseSpriteCache();
        D2GFX_Release();
    }

    ARCHIVE_FreeArchives();

    if (ghModKeyhook_0074C70C)
    {
        void (__stdcall* pfnUninstall)() = (void (__stdcall*)())GetProcAddress(ghModKeyhook_0074C70C, "UninstallKeyboardHook");
        if (pfnUninstall)
        {
            pfnUninstall();
        }
        FreeLibrary(ghModKeyhook_0074C70C);
    }

    FOG_AsyncDataDestroy();
    D2MCPClientCloseMCP();

    D2ComInterfaceStrc* pComInterface = *(D2ComInterfaceStrc**)pCfg->pComInterface;
    if (pComInterface)
    {
        pComInterface->pfnRelease();
    }

    sub_0060DDB0();
    FOG_DestroyMemoryPoolSystem(0);
    return 0;
}

// 0x00406190
static int __stdcall sub_00406190_GetProc(void* hModule, const char* szName, void** ppProc)
{
    void* pProc = GetProcAddress(hModule, szName);
    if (!pProc)
    {
        return 0;
    }
    *ppProc = pProc;
    return 1;
}

int __stdcall sub_K01_Emit_00406190(void* hModule, const char* szName, void** ppProc)
{
    return sub_00406190_GetProc(hModule, szName, ppProc);
}

// 0x00406470
static __declspec(noinline) int sub_00406470_OpenServiceHandles(void** phService, void** phManager)
{
    *phService = 0;
    *phManager = 0;
    if (GetVersion() & 0x80000000)
    {
        return 0;
    }
    void* hManager = OpenSCManagerA(0, 0, 0xF003F);
    *phManager = hManager;
    if (!hManager)
    {
        return 0;
    }
    *phService = OpenServiceA(hManager, gszServiceName_007065DC, 0xF01FF);
    return 1;
}

int sub_M371_Emit_00406470(int nAdd)
{
    void* hService;
    void* hManager;
    return sub_00406470_OpenServiceHandles(&hService, &hManager) + nAdd;
}
