typedef char* va_list;
typedef unsigned int size_t;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
int __fastcall FOG_SOCKET_WSACleanup();                                                                     // 0x0040D8D0
void __cdecl sub_00408900_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...); // 0x00408900
void __cdecl sub_0040F960_CloseLogFiles();                                                                  // 0x0040F960
#define FOG_ASSERT(expr, line) if (!(expr)) { const char* szAssertFile = sub_00408090(); FOG_SOCKET_WSACleanup(); sub_00408900_RaiseErrorReport(6, &gszEmptyAssertText, line, "Unrecoverable internal error %08x", szAssertFile); sub_0040F960_CloseLogFiles(); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464
extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args);         // 0x00682F22
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" int __cdecl SStrPrintf(char* szDest, size_t nSize, const char* szFormat, ...);                   // 0x00413A40
const char* __fastcall sub_00408000_StripSourcePath(const char* szFile);                                    // 0x00408000
void __cdecl sub_004106B0_LogWritePrefixed0(const char* szPrefix, const char* szFormat, ...);               // 0x004106B0
void __cdecl sub_00410740_LogWritePrefixed00(const char* szPrefix, const char* szFormat, ...);              // 0x00410740

extern "C" const char gszStringFormat_006FFC58[];                                                           // 0x006FFC58
extern const char* gaszErrorTypeNames_00706654[];                                                           // 0x00706654

// 0x00408B20
void __fastcall sub_00408B20_ShowErrorBox(int nType, const char* szFile, int nLine, const char* szFormat, va_list args)
{
    char szCaption[0x100];
    char szMessage[0x1000];
    char szText[0x1000];
    char szBoxText[0x1000];
    if (szFile)
    {
        SStrPrintf(szMessage, 0x1000, "--------  FILE: %s    LINE: %d  --------\n\n", sub_00408000_StripSourcePath(szFile), nLine);
        sub_004106B0_LogWritePrefixed0(&gszEmptyAssertText, gszStringFormat_006FFC58, szMessage);
    }
    FOG_ASSERT(szFormat, 0x8DE);
    _vsnprintf(szMessage, 0x1000, szFormat, args);
    szMessage[0xFFF] = 0;
    if (szFile)
    {
        SStrPrintf(szText, 0x1000, "%s\nLocation : %s, line #%d\nExpression : %s", gaszErrorTypeNames_00706654[nType], sub_00408000_StripSourcePath(szFile), nLine, szMessage);
    }
    else
    {
        strcpy(szText, szMessage);
    }
    SStrPrintf(szCaption, 0x100, "%s Error", "Diablo II");
    strcpy(szBoxText, szText);
    strcat(szText, "\n");
    sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, gszStringFormat_006FFC58, szText);
    sub_0040F960_CloseLogFiles();
    MessageBoxA(0, szBoxText, szCaption, 0x30);
}
