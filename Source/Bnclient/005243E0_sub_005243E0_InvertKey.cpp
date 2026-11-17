typedef unsigned int D2IdeaUInt16;
typedef unsigned short D2IdeaWord16;

D2IdeaWord16 __fastcall sub_005242F0_MulInv(D2IdeaUInt16 x);                                                // 0x005242F0

// 0x005243E0
void __fastcall sub_005243E0_InvertKey(const D2IdeaWord16* pEK, D2IdeaWord16* pDK)
{
    D2IdeaUInt16 u1;
    D2IdeaUInt16 u2;
    D2IdeaUInt16 u3;
    D2IdeaWord16 aTemp[52];
    D2IdeaWord16* p = aTemp + 52;
    const D2IdeaUInt16 t1 = *pEK++;
    const D2IdeaUInt16 t2 = -*pEK++;
    const D2IdeaUInt16 t3 = -*pEK++;
    *--p = sub_005242F0_MulInv(*pEK++);
    *--p = t3;
    *--p = t2;
    *--p = sub_005242F0_MulInv(t1);
    for (int j = 1; j < 8; j++)
    {
        u1 = *pEK++;
        *--p = *pEK++;
        *--p = u1;
        u1 = *pEK++;
        u2 = -*pEK++;
        u3 = -*pEK++;
        *--p = sub_005242F0_MulInv(*pEK++);
        *--p = u2;
        *--p = u3;
        *--p = sub_005242F0_MulInv(u1);
    }
    u1 = *pEK++;
    *--p = *pEK++;
    *--p = u1;
    u1 = *pEK++;
    u2 = -*pEK++;
    *--p = sub_005242F0_MulInv(pEK[1]);
    *--p = -*pEK;
    *--p = u2;
    *--p = sub_005242F0_MulInv(u1);
    int j;
    for (j = 0, p = aTemp; j < 52; j++)
    {
        *pDK++ = *p;
        *p++ = 0;
    }
}
