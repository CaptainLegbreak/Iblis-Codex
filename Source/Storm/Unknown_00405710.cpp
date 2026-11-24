#include "Storm.h"
#include "D2MultiTypes.h"

struct D2ConfigStrc;

extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


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

// build: symbol ?ERRORMANAGER_IsCmdSeparator@* 0x004055D0
static int ERRORMANAGER_IsCmdSeparator(char c)
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
        if (!ERRORMANAGER_IsCmdSeparator(s[i]))
        {
            break;
        }
    }
    int nOut = 0;
    for (; i < nLen; i++)
    {
        if (ERRORMANAGER_IsCmdSeparator(szBuf[i]))
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

#include "gen/data/Source/Storm/Unknown_00405710.inc"

void* ghCurrentProcess_0074C718; // 0x0074C718
