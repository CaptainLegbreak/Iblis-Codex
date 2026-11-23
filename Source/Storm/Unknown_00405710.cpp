#include "Storm.h"

struct D2ConfigStrc;

extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

#pragma pack(push, 1)
struct D2ConfigStrc
{
    int bIsExpansion;
    int nUnk0x04;
    unsigned char bWindow;
    unsigned char bNoFixedAspect;
    unsigned char b3DFX;
    unsigned char bOpenGL;
    unsigned char bRave;
    unsigned char bD3D;
    char unk0x0E[0x203];
    int (__cdecl* pAllowExpansionCallback)();
    char unk0x215[0x1B8];
};

#pragma pack(pop)

extern "C" char* __cdecl strtok(char* szText, const char* szDelim); // 0x0068264F
extern "C" int __cdecl strncmp(const char* szLeft, const char* szRight, size_t nCount); // 0x00682591
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
void __fastcall FOG_SetLogPrefix(const char* szLogPrefix); // 0x00407960
void __fastcall FOG_InitErrorMgr(const char* szProgramName, const char* szVersion, int bLogToFile); // 0x00408CE0
void __fastcall SaveCmdLine(const char** argv); // 0x00405F00
void __cdecl MoveBetaSettingsToRelease(); // 0x00406040
void __fastcall ParseCmdLine(D2ConfigStrc* pCfg, const char* argv); // 0x004059A0
int __fastcall GameStart(void* hInstance, D2ConfigStrc* pCfg, int nModType); // 0x00405C30
int __cdecl sub_00405EF0(); // 0x00405EF0
extern "C" __declspec(dllimport) void* __stdcall OpenEventA(unsigned long dwDesiredAccess, int bInheritHandle, const char* szName); // 0x006CC12C
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent); // 0x006CC130
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" const char gszDash_006CCA2C[]; // 0x006CCA2C
extern const char* gaszModuleTypes_007065C4[6]; // 0x007065C4
extern void* ghCurrentProcess_0074C718; // 0x0074C718
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned long nBufferSize); // 0x00414E50
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
extern int gbRunningAsService; // 0x0074C720
extern char szSRegReadBuf[]; // 0x0074C728

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
    for (int i = 0; s[i]; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 'a' - 'A';
        }
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

// 0x00405710
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
    int nCommandLength = strlen(szCommandNameTestBuf);
    int bContinue = 1;
    sub_00405550_stoLower_Inl(szCommandNameTestBuf);
    for (; nCommandLength != 0 && bContinue; nCommandLength--)
    {
        szCommandNameTestBuf[nCommandLength] = '\0';
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

// 0x00406340
static int __stdcall sub_00406340_SelectModule(const char* szArgvCmd, int* pChosenModule)
{
    const size_t nArgvLength = strlen(szArgvCmd) + 1;
    char* szArgvDupe = (char*)FOG_Alloc(nArgvLength, ".\\Main.cpp", 442, 0);
    SStrCopy(szArgvDupe, szArgvCmd, nArgvLength);
    for (char* pCurrentParam = strtok(szArgvDupe, gszDash_006CCA2C); pCurrentParam; pCurrentParam = strtok(0, gszDash_006CCA2C))
    {
        for (int i = 0; i < 6; i++)
        {
            if (0 == strncmp(pCurrentParam, gaszModuleTypes_007065C4[i], strlen(gaszModuleTypes_007065C4[i])) && i != 1)
            {
                *pChosenModule = i;
            }
        }
    }
    FOG_Free(szArgvDupe, ".\\Main.cpp", 480, 0);
    return 1;
}

#include "gen/data/Source/Storm/Unknown_00405710.inc"

void* ghCurrentProcess_0074C718; // 0x0074C718

// 0x00405F00
void __fastcall SaveCmdLine(const char** argv)
{
    char szSRegWriteBuf[0x800];
    unsigned long bUseCmdLine = 0;
    if (*argv && strlen(*argv))
    {
        sprintf(szSRegWriteBuf, "%s -skiptobnet", *argv);
        SRegSaveString("Diablo II", "CmdLine", 0, szSRegWriteBuf);
    }
    else
    {
        SRegLoadValue("Diablo II", "UseCmdLine", 0, &bUseCmdLine);
        if (bUseCmdLine)
        {
            SRegLoadString("Diablo II", "CmdLine", 0, szSRegReadBuf, 0x400);
            *argv = szSRegReadBuf;
        }
        else
        {
            memcpy(szSRegWriteBuf, "-skiptobnet", sizeof("-skiptobnet"));
            SRegSaveString("Diablo II", "CmdLine", 0, szSRegWriteBuf);
        }
    }
    bUseCmdLine = 0;
    SRegSaveValue("Diablo II", "UseCmdLine", 0, 0);
    if (gbRunningAsService)
    {
        SRegLoadString("Diablo II", "SvcCmdLine", 0, szSRegReadBuf, 0x400);
        *argv = szSRegReadBuf;
    }
}

// 0x004064C0
int __fastcall GameInit(int argc, const char** argv)
{
    const char* lpArgvCmd = &gszEmptyAssertText;
    if (argc > 1)
    {
        lpArgvCmd = argv[argc - 1];
    }
    char szVersion[0x104];
    SStrPrintf(szVersion, 0x104, "v%d.%02d", 1, 14);
    FOG_SetLogPrefix("D2");
    FOG_InitErrorMgr("Diablo II", szVersion, 1);
    if (void* hEvent = OpenEventA(2, 1, "DIABLO_II_OK"))
    {
        SetEvent(hEvent);
        CloseHandle(hEvent);
    }
    SaveCmdLine(&lpArgvCmd);
    MoveBetaSettingsToRelease();
    int nChosenModule = 4;
    sub_00406340_SelectModule(lpArgvCmd, &nChosenModule);
    D2ConfigStrc tCfg;
    ParseCmdLine(&tCfg, lpArgvCmd);
    tCfg.pAllowExpansionCallback = sub_00405EF0;
    tCfg.bOpenGL = 0;
    if (!tCfg.b3DFX)
    {
        tCfg.bD3D = !tCfg.bWindow;
    }
    return GameStart(ghCurrentProcess_0074C718, &tCfg, nChosenModule);
}
