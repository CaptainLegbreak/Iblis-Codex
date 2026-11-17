extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2BnHashCtxStrc
{
    unsigned int aState[5];
    int nBitCountLo;
    int nBitCountHi;
    unsigned int f_1C[16];
};

struct D2IdeaUserKeyStrc
{
    unsigned int aKey[4];
};

struct D2IdeaKeyScheduleStrc
{
    unsigned short aKey[52];
};

extern D2BnHashCtxStrc gaBnHashCtx_00882760[];                                                              // 0x00882760
extern D2IdeaKeyScheduleStrc gaIdeaKeySchedules_00882878[];                                                 // 0x00882878

// 0x00523020
char* __fastcall sub_00523020_GetAlignedData(char* pBuffer)
{
    D2_ASSERT(pBuffer, 0xF2);
    const unsigned int nMisalign = (unsigned int)pBuffer & 0x3F;
    if (nMisalign)
        pBuffer += 0x40 - nMisalign;
    return pBuffer + 8;
}

// 0x005241C0
void __fastcall sub_005241C0_GetDigest(int nIndex, unsigned int* pDigest)
{
    if (pDigest)
    {
        for (int i = 0; i < 5; ++i)
            pDigest[i] = gaBnHashCtx_00882760[nIndex].aState[i];
    }
}

// 0x005242F0
unsigned int __fastcall sub_005242F0_MulInv(unsigned int x)
{
    if (x <= 1)
        return x;
    unsigned int t1 = 0x10001 / x;
    unsigned int y = 0x10001 % x;
    if (y == 1)
        return (1 - t1) & 0xFFFF;
    unsigned int t0 = 1;
    do
    {
        unsigned int q = x / y;
        x = x % y;
        t0 += q * t1;
        if (x == 1)
            return t0;
        q = y / x;
        y = y % x;
        t1 += q * t0;
    }
    while (y != 1);
    return (1 - t1) & 0xFFFF;
}

// 0x00524360
void __fastcall sub_00524360_ExpandKey(const D2IdeaUserKeyStrc* pUserKey, D2IdeaKeyScheduleStrc* pSchedule)
{
    const unsigned short* pKey = (const unsigned short*)pUserKey->aKey;
    unsigned short* pEK = pSchedule->aKey;
    int i, j;
    for (j = 0; j < 8; ++j)
        pEK[j] = pKey[j];
    for (i = 0; j < 52; ++j)
    {
        i += 1;
        pEK[i + 7] = (unsigned short)((pEK[i & 7] << 9) | (pEK[(i + 1) & 7] >> 7));
        pEK += i & 8;
        i &= 7;
    }
}

// 0x00524740
void __cdecl sub_00524740_ClearKeySchedules()
{
    memset(gaIdeaKeySchedules_00882878, 0, sizeof(D2IdeaKeyScheduleStrc) * 3);
}
