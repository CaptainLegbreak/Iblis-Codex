typedef unsigned int D2IdeaUInt16;
typedef unsigned short D2IdeaWord16;

D2IdeaWord16 __fastcall sub_005242F0_MulInv(D2IdeaUInt16 x);                                                // 0x005242F0

// build: context sub_005243E0_InvertKey
void __fastcall sub_005243E0_InvertKey(const D2IdeaWord16* pEK, D2IdeaWord16* pDK)
{
    D2IdeaWord16 aTemp[52];
    D2IdeaWord16* p = aTemp + 52;
    D2IdeaUInt16 t1 = *pEK++;
    D2IdeaUInt16 t2 = -*pEK++;
    D2IdeaUInt16 t3 = -*pEK++;
    *--p = sub_005242F0_MulInv(*pEK++);
    *--p = t3;
    *--p = t2;
    *--p = sub_005242F0_MulInv(t1);
    for (int j = 1; j < 8; j++)
    {
        t1 = *pEK++;
        *--p = *pEK++;
        *--p = t1;
        t1 = *pEK++;
        t2 = -*pEK++;
        t3 = -*pEK++;
        *--p = sub_005242F0_MulInv(*pEK++);
        *--p = t2;
        *--p = t3;
        *--p = sub_005242F0_MulInv(t1);
    }
    t1 = *pEK++;
    *--p = *pEK++;
    *--p = t1;
    t1 = *pEK++;
    t2 = -*pEK++;
    *--p = sub_005242F0_MulInv(pEK[1]);
    *--p = -*pEK;
    *--p = t2;
    *--p = sub_005242F0_MulInv(t1);
    int j;
    for (j = 0, p = aTemp; j < 52; j++)
    {
        *pDK++ = *p;
        *p++ = 0;
    }
}

static inline D2IdeaUInt16 IdeaMul(D2IdeaUInt16 a, D2IdeaUInt16 b)
{
    if (a)
    {
        if (b)
        {
            const unsigned int p = (unsigned int)a * b;
            b = p & 0xFFFF;
            a = p >> 16;
            return b - a + (b < a);
        }
        return 1 - a;
    }
    return 1 - b;
}

#define IDEA_MUL(x, y) (x = IdeaMul((x) & 0xFFFF, y))

// 0x00524540
void __fastcall sub_00524540_Cipher(const D2IdeaWord16* pIn, D2IdeaWord16* pOut, const D2IdeaWord16* pKey)
{
    D2IdeaUInt16 x1, x2, x3, x4, t1, t2;
    int r = 8;
    x1 = *pIn++;
    x2 = *pIn++;
    x3 = *pIn++;
    x4 = *pIn;
    do
    {
        IDEA_MUL(x1, *pKey++);
        x2 += *pKey++;
        x3 += *pKey++;
        IDEA_MUL(x4, *pKey++);
        t2 = x1 ^ x3;
        IDEA_MUL(t2, *pKey++);
        t1 = t2 + (x2 ^ x4);
        IDEA_MUL(t1, *pKey++);
        t2 = t1 + t2;
        x1 ^= t1;
        x4 ^= t2;
        t2 ^= x2;
        x2 = x3 ^ t1;
        x3 = t2;
    }
    while (--r);
    IDEA_MUL(x1, *pKey++);
    *pOut++ = x1;
    *pOut++ = x3 + *pKey++;
    *pOut++ = x2 + *pKey++;
    IDEA_MUL(x4, *pKey);
    *pOut = x4;
}
