void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                              // 0x0041D2A0
double __cdecl sub_00414260_PowInt(double x, int nExp);

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// 0x00414310
char* __stdcall SStrDup(const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    const unsigned int nSize = SStrLen(szString) + 1;
    char* szResult = (char*)SMemAlloc(nSize, ".\\SOURCE\\SSTR.CPP", 0x1F2, 0);
    SMemCopy(szResult, szString, nSize);
    return nValid ? szResult : 0;
}

// 0x00414370
__int64 __stdcall SStrToInt64(const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    const int bNegative = *szString == '-';
    if (bNegative)
    {
        ++szString;
    }
    unsigned int nAccum = *szString - '0';
    __int64 nResult = 0;
    const char* pStart = szString;
    if (nAccum < 10)
    {
        ++szString;
        unsigned int nDigit;
        while ((nDigit = *szString - '0') < 10)
        {
            nAccum = nAccum * 10 + nDigit;
            ++szString;
            if (nAccum >= 0x19999999)
            {
                double dPow;
                double x = 10.0;
                const int nExp = (int)(szString - pStart);
                unsigned int nBits;
                if (nExp >= 0)
                {
                    nBits = (unsigned int)nExp;
                }
                else
                {
                    nBits = (unsigned int)-nExp;
                }
                for (double z = 1.0; ; x *= x)
                {
                    if ((nBits & 1) != 0)
                    {
                        z *= x;
                    }
                    if ((nBits >>= 1) == 0)
                    {
                        dPow = nExp < 0 ? 1.0 / z : z;
                        break;
                    }
                }
                nResult = (__int64)(dPow + 0.5) * nResult + nAccum;
                nAccum = 0;
                pStart = szString;
            }
        }
    }
    else
    {
        nAccum = 0;
    }
    if (nResult)
    {
        nResult = (__int64)(sub_00414260_PowInt(10.0, (int)(szString - pStart)) + 0.5) * nResult + nAccum;
    }
    else
    {
        nResult = nAccum;
    }
    return nValid ? (bNegative ? -nResult : nResult) : 0;
}
