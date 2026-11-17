struct D2RC4Strc
{
    unsigned char S[0x100];
    unsigned char i;
    unsigned char j;

    void sub_004E09B0_Init(const unsigned char* pKey, unsigned int nKeySize);
    void sub_0047F8C0_Crypt(unsigned char* pData, unsigned int nSize);       // 0x0047F8C0
};

// 0x004E09B0
void D2RC4Strc::sub_004E09B0_Init(const unsigned char* pKey, unsigned int nKeySize)
{
    for (unsigned int n = 0; n < 0x100; ++n)
    {
        S[n] = (unsigned char)n;
    }
    i = 0;
    j = 0;
    unsigned char k = 0;
    unsigned char b = 0;
    unsigned int n = 0;
    do
    {
        b += pKey[k] + S[n];
        unsigned char* pA = &S[n];
        unsigned char* pB = &S[b];
        unsigned char t = *pA;
        *pA = *pB;
        *pB = t;
        k = (unsigned char)((k + 1) % nKeySize);
        ++n;
    } while (n < 0x100);
}
