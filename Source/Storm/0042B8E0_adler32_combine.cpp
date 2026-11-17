// Altered from the original zlib source.
typedef long z_off_t;
typedef long long z_off64_t;

#define BASE 65521

// 0x0042B8E0
static unsigned long __stdcall adler32_combine_(unsigned long adler1, unsigned long adler2, z_off64_t len2)
{
    unsigned long sum1;
    unsigned long sum2;
    unsigned rem;

    if (len2 < 0)
        return 0xffffffffUL;
    len2 %= BASE;
    rem = (unsigned)len2;
    sum1 = adler1 & 0xffff;
    sum2 = rem * sum1;
    sum2 %= BASE;
    sum1 += (adler2 & 0xffff) + BASE - 1;
    sum2 += ((adler1 >> 16) & 0xffff) + ((adler2 >> 16) & 0xffff) + BASE - rem;
    if (sum1 >= BASE) sum1 -= BASE;
    if (sum1 >= BASE) sum1 -= BASE;
    if (sum2 >= (BASE << 1)) sum2 -= (BASE << 1);
    if (sum2 >= BASE) sum2 -= BASE;
    return sum1 | (sum2 << 16);
}

// 0x0042B990
unsigned long __fastcall adler32_combine(unsigned long adler1, unsigned long adler2, z_off_t len2)
{
    return adler32_combine_(adler1, adler2, len2);
}

// 0x0042B9B0
unsigned long __fastcall adler32_combine64(unsigned long adler1, unsigned long adler2, z_off64_t len2)
{
    return adler32_combine_(adler1, adler2, len2);
}
