extern double gadPowTable_007788E0[20][10]; // 0x007788E0

// build: context PowIntT*
template <class T>
inline T PowIntT(T x, int nExp)
{
    unsigned int n;
    if (nExp >= 0)
        n = (unsigned int)nExp;
    else
        n = (unsigned int)(-nExp);
    for (T z = T(1); ; x *= x)
    {
        if ((n & 1) != 0)
            z *= x;
        if ((n >>= 1) == 0)
            return (nExp < 0 ? T(1) / z : z);
    }
}

// 0x00414260
inline double __cdecl sub_00414260_PowInt(double x, int nExp)
{
    return PowIntT(x, nExp);
}

// 0x004142A0
void __cdecl sub_004142A0_InitPowTable()
{
    for (int nExp = 0; nExp < 20; ++nExp)
    {
        for (int i = 0; i < 10; ++i)
        {
            gadPowTable_007788E0[nExp][i] = sub_00414260_PowInt(10.0, -(nExp + 1)) * i;
        }
    }
}
