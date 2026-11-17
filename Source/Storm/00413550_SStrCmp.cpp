extern "C" int __cdecl strncmp(const char* szLeft, const char* szRight, unsigned int nCount);
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0

// 0x00413550
int __stdcall SStrCmp(const char* szString1, const char* szString2, int nMaxChars)
{
    VALIDATEBEGIN;
    VALIDATE(szString1);
    VALIDATE(szString2);
    if (!nValid)
    {
        sub_0041C340_SetLastError(0x57);
        return (int)(szString1 - szString2);
    }
    return nValid ? strncmp(szString1, szString2, nMaxChars) : 0;
}
