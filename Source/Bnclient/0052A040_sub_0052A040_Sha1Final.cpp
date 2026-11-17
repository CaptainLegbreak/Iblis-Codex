struct D2SrpSha1ContextStrc
{
    unsigned int aState[5];
    unsigned int aCount[2];
    unsigned char f_1C[64];
};

extern "C" const unsigned char gabSha1Pad80_006E03F0[];                                                     // 0x006E03F0
extern "C" const unsigned char gabSha1Pad00_006DEF80[];                                                     // 0x006DEF80

void __fastcall sub_00529F80_Sha1Update(D2SrpSha1ContextStrc* pContext, const unsigned char* pData, unsigned int nLength); // 0x00529F80

// 0x0052A040
void __fastcall sub_0052A040_Sha1Final(unsigned char* pDigest, D2SrpSha1ContextStrc* pContext)
{
    unsigned int i;
    unsigned char abFinalCount[8];

    for (i = 0; i < 8; i++)
    {
        abFinalCount[i] = (unsigned char)((pContext->aCount[(i >= 4 ? 0 : 1)] >> ((3 - (i & 3)) * 8)) & 255);
    }
    sub_00529F80_Sha1Update(pContext, gabSha1Pad80_006E03F0, 1);
    while ((pContext->aCount[0] & 504) != 448)
    {
        sub_00529F80_Sha1Update(pContext, gabSha1Pad00_006DEF80, 1);
    }
    sub_00529F80_Sha1Update(pContext, abFinalCount, 8);
    for (i = 0; i < 20; i++)
    {
        pDigest[i] = (unsigned char)((pContext->aState[i >> 2] >> ((3 - (i & 3)) * 8)) & 255);
    }
}

#include "gen/data/Source/Bnclient/0052A040_sub_0052A040_Sha1Final.inc"
