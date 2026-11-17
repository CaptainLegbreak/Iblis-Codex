extern "C" const unsigned char gaSha1Padding_00708890[];                                                    // 0x00708890

struct T0041D340
{
    unsigned __int64 nBitCount;
    unsigned int aState[5];
    unsigned char f_1C[64];

    void sub_00425DD0_Update(const unsigned char* pData, unsigned int nLen);
    void sub_00425F00_Final(unsigned char* pDigest);
};

static inline void sub_PutBE64(unsigned char* p, unsigned __int64 v)
{
    p[7] = (unsigned char)v; v >>= 8;
    p[6] = (unsigned char)v; v >>= 8;
    p[5] = (unsigned char)v; v >>= 8;
    p[4] = (unsigned char)v; v >>= 8;
    p[3] = (unsigned char)v; v >>= 8;
    p[2] = (unsigned char)v; v >>= 8;
    p[1] = (unsigned char)v; v >>= 8;
    p[0] = (unsigned char)v;
}

// 0x00425F00
void T0041D340::sub_00425F00_Final(unsigned char* pDigest)
{
    unsigned char aCount[8];
    sub_PutBE64(aCount, nBitCount);
    sub_00425DD0_Update(gaSha1Padding_00708890, ((0xFFFFFFF7 - ((unsigned int)nBitCount >> 3)) & 0x3F) + 1);
    sub_00425DD0_Update(aCount, 8);
    for (int i = 0; i < 5; i++)
    {
        unsigned int v = aState[i];
        for (int j = 3; j >= 0; j--)
        {
            pDigest[i * 4 + j] = (unsigned char)v;
            v >>= 8;
        }
    }
}

#include "gen/data/Source/Storm/00425F00_sub_00425F00_Final.inc"
