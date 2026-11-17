extern "C" unsigned int __cdecl _rotl(unsigned int nValue, int nShift);

struct T0041D340
{
    unsigned __int64 nBitCount;
    unsigned int aState[5];
    unsigned char f_1C[64];

    void sub_00425DD0_Update(const unsigned char* pData, unsigned int nLen);
};

// 0x00425720
unsigned int __fastcall sub_00425720_Rotl(unsigned int nValue, int nShift)
{
    return _rotl(nValue, nShift);
}

// 0x00425730
void __fastcall sub_00425730_Sha1Round0(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += sub_00425720_Rotl(a, 5) + ((*b & c) | (~*b & d)) + *w + 0x5A827999;
    *b = sub_00425720_Rotl(*b, 30);
    *w = 0;
}

// 0x00425770
void __fastcall sub_00425770_Sha1Round1(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += sub_00425720_Rotl(a, 5) + (*b ^ c ^ d) + *w + 0x6ED9EBA1;
    *b = sub_00425720_Rotl(*b, 30);
    *w = 0;
}

// 0x004257B0
void __fastcall sub_004257B0_Sha1Round2(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += sub_00425720_Rotl(a, 5) + ((*b & c) | (*b & d) | (c & d)) + *w + 0x8F1BBCDC;
    *b = sub_00425720_Rotl(*b, 30);
    *w = 0;
}

// 0x004257F0
void __fastcall sub_004257F0_Sha1Round3(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += sub_00425720_Rotl(a, 5) + (*b ^ c ^ d) + *w + 0xCA62C1D6;
    *b = sub_00425720_Rotl(*b, 30);
    *w = 0;
}

// 0x00425830
void __fastcall sub_00425830_LoadBE32(unsigned int* pOut, const unsigned char* pIn)
{
    *pOut = ((((pIn[0] << 8) | pIn[1]) << 8 | pIn[2]) << 8) | pIn[3];
}

// 0x00425850
void __fastcall sub_00425850_Sha1Transform(unsigned int* pState, const unsigned char* pBlock)
{
    unsigned int W[80];
    int i;

    for (i = 0; i < 16; i++)
    {
        sub_00425830_LoadBE32(&W[i], pBlock);
        pBlock += 4;
    }

    do
    {
        W[i] = sub_00425720_Rotl(W[i - 3] ^ W[i - 8] ^ W[i - 14] ^ W[i - 16], 1);
    } while (++i < 80);

    unsigned int a = pState[0];
    unsigned int b = pState[1];
    unsigned int c = pState[2];
    unsigned int d = pState[3];
    unsigned int e = pState[4];

    i = 0;
    do
    {
        sub_00425730_Sha1Round0(a, &b, c, d, &e, &W[i]);
        sub_00425730_Sha1Round0(e, &a, b, c, &d, &W[i + 1]);
        sub_00425730_Sha1Round0(d, &e, a, b, &c, &W[i + 2]);
        sub_00425730_Sha1Round0(c, &d, e, a, &b, &W[i + 3]);
        sub_00425730_Sha1Round0(b, &c, d, e, &a, &W[i + 4]);
        i += 5;
    } while (i < 20);

    do
    {
        sub_00425770_Sha1Round1(a, &b, c, d, &e, &W[i]);
        sub_00425770_Sha1Round1(e, &a, b, c, &d, &W[i + 1]);
        sub_00425770_Sha1Round1(d, &e, a, b, &c, &W[i + 2]);
        sub_00425770_Sha1Round1(c, &d, e, a, &b, &W[i + 3]);
        sub_00425770_Sha1Round1(b, &c, d, e, &a, &W[i + 4]);
        i += 5;
    } while (i < 40);

    do
    {
        sub_004257B0_Sha1Round2(a, &b, c, d, &e, &W[i]);
        sub_004257B0_Sha1Round2(e, &a, b, c, &d, &W[i + 1]);
        sub_004257B0_Sha1Round2(d, &e, a, b, &c, &W[i + 2]);
        sub_004257B0_Sha1Round2(c, &d, e, a, &b, &W[i + 3]);
        sub_004257B0_Sha1Round2(b, &c, d, e, &a, &W[i + 4]);
        i += 5;
    } while (i < 60);

    do
    {
        sub_004257F0_Sha1Round3(a, &b, c, d, &e, &W[i]);
        sub_004257F0_Sha1Round3(e, &a, b, c, &d, &W[i + 1]);
        sub_004257F0_Sha1Round3(d, &e, a, b, &c, &W[i + 2]);
        sub_004257F0_Sha1Round3(c, &d, e, a, &b, &W[i + 3]);
        sub_004257F0_Sha1Round3(b, &c, d, e, &a, &W[i + 4]);
        i += 5;
    } while (i < 80);

    pState[0] += a;
    pState[1] += b;
    pState[2] += c;
    pState[3] += d;
    pState[4] += e;
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
