void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
extern unsigned int gdwSStrScanWord_007788D8;                                                               // 0x007788D8

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// 0x00413750
unsigned int __stdcall SStrLen(const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    unsigned int dwOnes = 0xFFFFFFFF;
    const char* p = szString;
    while ((unsigned int)p & 3)
    {
        if (!*p)
        {
            goto done;
        }
        ++p;
    }
    for (;;)
    {
        const unsigned int w = *(const unsigned int*)p;
        dwOnes -= w;
        unsigned int dwTest = (w + 0x7EFEFEFF) ^ dwOnes;
        p += 4;
        dwOnes |= w;
        dwTest &= 0x81010101;
        if (dwTest)
        {
            if (!(char)w)
            {
                p -= 4;
                break;
            }
            if (!(char)(w >> 8))
            {
                p -= 3;
                break;
            }
            if (!(w & 0xFF0000))
            {
                p -= 2;
                break;
            }
            if (!(w & 0xFF000000))
            {
                p -= 1;
                break;
            }
            gdwSStrScanWord_007788D8 = dwTest;
        }
    }
done:
    return nValid ? p - szString : 0;
}
