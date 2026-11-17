#include "Bnclient.h"

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, char* pArgs);
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie); // 0x00681A48
void __fastcall sub_00517804_GetMessage(unsigned long dwError, char* szBuffer, unsigned int nSize); // 0x00517804
int __fastcall sub_0051740B_ErrorBox(const char* szText); // 0x0051740B

// 0x0051793E
void __cdecl sub_0051793E_FormatAndRaise(unsigned long dwError, ...)
{
    char szText[512];
    char szFormat[512];

    sub_00517804_GetMessage(dwError, szFormat, sizeof(szFormat));
    char* pArgs = (char*)&dwError + sizeof(dwError);
    wvsprintfA(szText, szFormat, pArgs);
    sub_0051740B_ErrorBox(szText);
}
