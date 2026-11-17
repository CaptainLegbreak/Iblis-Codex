unsigned int __fastcall sub_005225E0(unsigned int nWords, unsigned int nMultiplier, const unsigned int* pSource, unsigned int* pDest, unsigned int nCarry); // 0x005225E0
void __fastcall sub_00522650(const char* szKey, unsigned char* pOut); // 0x00522650
void __stdcall sub_00522980(unsigned int* pKey); // 0x00522980

__declspec(noinline) static unsigned int __fastcall sub_005226D0_PermuteKeyBits(int nUnused, unsigned int* pKey);
static unsigned int __fastcall sub_005226D0_PermuteKeyBits(int nUnused, unsigned int* pKey)
{
    const unsigned int nResult = pKey[0] >> (pKey[1] & 0x1F);
    pKey[2] ^= nResult;
    return nResult;
}

// 0x00522AE0
void __fastcall sub_00522AE0_DecodeCdKey26(const char* szKey, unsigned int* pProduct, unsigned int* pPublic, unsigned char* pPrivate)
{
    if (!szKey || !pPrivate)
    {
        return;
    }

    unsigned char aDigits[52];
    sub_00522650(szKey, aDigits);

    unsigned int aKey[4] = { 0 };
    for (int i = 52; i > 0; --i)
    {
        sub_005225E0(4, 5, aKey, aKey, aDigits[i - 1]);
    }

    sub_00522980(aKey);
    sub_005226D0_PermuteKeyBits(0, aKey);

    *pProduct = aKey[0] >> 10;
    *pPublic = ((aKey[0] & 0x3FF) << 16) | (aKey[1] >> 16);
    *(unsigned short*)pPrivate = (unsigned short)aKey[1];
    *(unsigned int*)(pPrivate + 2) = aKey[2];
    *(unsigned int*)(pPrivate + 6) = aKey[3];
}
