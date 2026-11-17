void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// 0x00413AC0
int __stdcall SStrToInt(const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    const int bNegative = (*szString == '-');
    if (bNegative)
    {
        ++szString;
    }
    int nResult = *szString - '0';
    if ((unsigned int)nResult < 10)
    {
        unsigned int nDigit = *++szString - '0';
        while (nDigit < 10)
        {
            ++szString;
            nResult = nResult * 10 + nDigit;
            nDigit = *szString - '0';
        }
    }
    else
    {
        nResult = 0;
    }
    return nValid ? (bNegative ? -nResult : nResult) : 0;
}
