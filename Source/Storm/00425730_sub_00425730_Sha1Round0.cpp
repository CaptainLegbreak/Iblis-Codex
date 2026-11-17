extern "C" unsigned int __cdecl _rotl(unsigned int nValue, int nShift);

void __fastcall sub_00425850_Sha1Transform(unsigned int* pState, const unsigned char* pBlock);              // 0x00425850

struct T0041D340
{
    unsigned __int64 nBitCount;
    unsigned int aState[5];
    unsigned char f_1C[64];

    void sub_00425DD0_Update(const unsigned char* pData, unsigned int nLen);
};

// 0x00425730
void __fastcall sub_00425730_Sha1Round0(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += _rotl(a, 5) + ((*b & c) | (~*b & d)) + *w + 0x5A827999;
    *b = _rotl(*b, 30);
    *w = 0;
}

// 0x00425770
void __fastcall sub_00425770_Sha1Round1(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += _rotl(a, 5) + (*b ^ c ^ d) + *w + 0x6ED9EBA1;
    *b = _rotl(*b, 30);
    *w = 0;
}

// 0x004257B0
void __fastcall sub_004257B0_Sha1Round2(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += _rotl(a, 5) + (((c | d) & *b) | (c & d)) + *w + 0x8F1BBCDC;
    *b = _rotl(*b, 30);
    *w = 0;
}

// 0x004257F0
void __fastcall sub_004257F0_Sha1Round3(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += _rotl(a, 5) + (*b ^ c ^ d) + *w + 0xCA62C1D6;
    *b = _rotl(*b, 30);
    *w = 0;
}

// 0x00425DD0
void T0041D340::sub_00425DD0_Update(const unsigned char* pData, unsigned int nLen)
{
    unsigned int nUsed = (unsigned int)nBitCount >> 3 & 0x3F;
    nBitCount += (unsigned __int64)nLen * 8;
    if (nUsed)
    {
        nLen += nUsed;
        pData -= nUsed;
        if (nLen >= 64)
        {
            for (; nUsed < 64; nUsed++)
                f_1C[nUsed] = pData[nUsed];
            sub_00425850_Sha1Transform(aState, f_1C);
            nLen -= 64;
            pData += 64;
            nUsed = 0;
        }
    }
    while (nLen >= 64)
    {
        sub_00425850_Sha1Transform(aState, pData);
        nLen -= 64;
        pData += 64;
    }
    for (; nUsed < nLen; nUsed++)
        f_1C[nUsed] = pData[nUsed];
}

// 0x00425E80
void __fastcall sub_00425E80_PutBE64(unsigned char* pOut, unsigned __int64 nValue)
{
    pOut[7] = (unsigned char)nValue; nValue >>= 8;
    pOut[6] = (unsigned char)nValue; nValue >>= 8;
    pOut[5] = (unsigned char)nValue; nValue >>= 8;
    pOut[4] = (unsigned char)nValue; nValue >>= 8;
    pOut[3] = (unsigned char)nValue; nValue >>= 8;
    pOut[2] = (unsigned char)nValue; nValue >>= 8;
    pOut[1] = (unsigned char)nValue; nValue >>= 8;
    pOut[0] = (unsigned char)nValue;
}
