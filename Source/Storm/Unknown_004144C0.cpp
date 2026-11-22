#include "SValidate.h"
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
double __cdecl sub_00414260_PowInt(double x, int nExp);                                                     // 0x00414260
int __stdcall SStrToInt(const char* szString);                                                              // 0x00413AC0
extern "C" { int gnFlag_007788DC; }                                                                         // 0x007788DC
extern "C" void __cdecl sub_00414360_CallThenSetFlag();                                                     // 0x00414360
double gadDigitScale_007788E0[20][10];                                                                      // 0x007788E0


template <class T>
inline T StormPowInt(T x, int nExp)
{
    unsigned int nBits;
    if (nExp >= 0)
        nBits = (unsigned int)nExp;
    else
        nBits = (unsigned int)-nExp;
    for (T z = T(1); ; x *= x)
    {
        if ((nBits & 1) != 0)
            z *= x;
        if ((nBits >>= 1) == 0)
            return nExp < 0 ? T(1) / z : z;
    }
}

static inline void sub_004144B0_EnsureInit()
{
    if (!gnFlag_007788DC)
        sub_00414360_CallThenSetFlag();
}

// 0x004144C0
double __stdcall SStrToDouble(const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    sub_004144B0_EnsureInit();
    const int bNegative = *szString == '-';
    if (bNegative)
    {
        ++szString;
    }
    double dResult = 0.0;
    unsigned int nAccum = *szString - '0';
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
                dResult = StormPowInt(10.0, (int)(szString - pStart)) * dResult + nAccum;
                nAccum = 0;
                pStart = szString;
            }
        }
    }
    else
    {
        nAccum = 0;
    }
    if (dResult != 0.0)
    {
        dResult = sub_00414260_PowInt(10.0, (int)(szString - pStart)) * dResult + nAccum;
    }
    else
    {
        dResult = nAccum;
    }
    if (*szString == '.')
    {
        ++szString;
        unsigned int nDigit;
        for (int i = 0; (nDigit = *szString - '0') < 10; ++i)
        {
            ++szString;
            if (i >= 20)
                dResult += StormPowInt(10.0, -1 - i) * nDigit;
            else
                dResult += gadDigitScale_007788E0[i][nDigit];
        }
    }
    if (*szString == 'e' || *szString == 'E')
    {
        ++szString;
        if (*szString == '+')
        {
            ++szString;
        }
        dResult *= StormPowInt(10.0, SStrToInt(szString));
    }
    return nValid ? (bNegative ? -dResult : dResult) : 0;
}
