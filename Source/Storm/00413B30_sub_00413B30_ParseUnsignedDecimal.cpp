void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// 0x00413B30
int __stdcall sub_00413B30_ParseUnsignedDecimal(const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
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
    return nValid ? nResult : 0;
}
