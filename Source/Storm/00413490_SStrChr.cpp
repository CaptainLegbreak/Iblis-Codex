void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// 0x00413490
__declspec(noinline) const char* __stdcall SStrChr(const char* szString, char nChar)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    for (; *szString; ++szString)
    {
        if (*szString == nChar)
            return nValid ? szString : 0;
    }
    return 0;
}

// 0x004134D0
__declspec(noinline) const char* __stdcall SStrChrR(const char* szString, char nChar)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    const char* pLast = 0;
    for (const char* pString = szString; *pString; ++pString)
    {
        if (*pString == nChar)
            pLast = pString;
    }
    return nValid ? pLast : 0;
}

// 0x00413510
const char* __stdcall sub_00413510_SStrChrDir(const char* szString, char nChar, int bReverse)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    if (bReverse)
        return SStrChrR(szString, nChar);
    return nValid ? SStrChr(szString, nChar) : 0;
}
