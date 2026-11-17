typedef unsigned int size_t;

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

extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strtok(char* szText, const char* szDelim);                                         // 0x0068264F
extern "C" int __cdecl strncmp(const char* szLeft, const char* szRight, size_t nCount);                     // 0x00682591
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);       // 0x00413A40
int __fastcall FOG_SetLogPrefix(const char* szLogPrefix);                                                   // 0x00407960
void __fastcall FOG_InitErrorMgr(const char* szProgramName, const char* szVersion, int bLogToFile);        // 0x00408CE0
void __fastcall SaveCmdLine(const char** argv);                                                             // 0x00405F00
void __cdecl MoveBetaSettingsToRelease();                                                                   // 0x00406040
void __fastcall ParseCmdLine(D2ConfigStrc* pCfg, const char* argv);                                         // 0x004059A0
int __fastcall GameStart(void* hInstance, D2ConfigStrc* pCfg, int nModType);                                // 0x00405C30
int __cdecl sub_00405EF0();                                                                                 // 0x00405EF0

extern "C" __declspec(dllimport) void* __stdcall OpenEventA(unsigned long dwDesiredAccess, int bInheritHandle, const char* szName); // 0x006CC12C
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char gszDash_006CCA2C[];                                                                   // 0x006CCA2C
extern const char* gaszModuleTypes_007065C4[6];                                                             // 0x007065C4
extern void* ghCurrentProcess_0074C718;                                                                     // 0x0074C718

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
    const char* szArgs = lpArgvCmd;
    int nChosenModule = 4;
    sub_00406340_SelectModule(szArgs, &nChosenModule);
    D2ConfigStrc tCfg;
    ParseCmdLine(&tCfg, szArgs);
    tCfg.pAllowExpansionCallback = sub_00405EF0;
    tCfg.bOpenGL = 0;
    if (!tCfg.b3DFX)
    {
        tCfg.bD3D = !tCfg.bWindow;
    }
    return GameStart(ghCurrentProcess_0074C718, &tCfg, nChosenModule);
}

#include "gen/data/Source/Storm/00406340_sub_00406340_SelectModule.inc"
