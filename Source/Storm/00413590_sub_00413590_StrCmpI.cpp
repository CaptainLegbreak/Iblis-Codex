void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
extern "C" int __cdecl _strnicmp(const char* szString1, const char* szString2, unsigned int nCount); // 0x00686040
#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0

// 0x00413590
int __stdcall sub_00413590_StrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars)
{
    VALIDATEBEGIN;
    VALIDATE(szString1);
    VALIDATE(szString2);
    if (!nValid)
    {
        sub_0041C340_SetLastError(0x57);
        return szString1 - szString2;
    }
    return nValid ? _strnicmp(szString1, szString2, nMaxChars) : 0;
}
