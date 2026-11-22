#include "D2BNClient.h"

#include "D2Primitives.h"

unsigned int __fastcall sub_00522570_GetBit(const unsigned int* pKey, unsigned int nIndex)
{
    const int nShift = nIndex & 0x1F;
    return (pKey[3 - (nIndex >> 5)] & (1 << nShift)) >> nShift;
}

void __fastcall sub_005225A0_SetBit(unsigned int* pKey, unsigned int nIndex, unsigned char nValue)
{
    const unsigned int nShift = nIndex & 0x1F;
    const unsigned int nWord = 3 - (nIndex >> 5);
    pKey[nWord] = (pKey[nWord] & ~(1 << nShift)) | ((nValue & 1) << nShift);
}

// 0x005226D0
void __fastcall sub_005226D0_PermuteKeyBits(int nUnused, unsigned int* pKey)
{
    unsigned int aCopy[4];
    aCopy[0] = pKey[0];
    aCopy[1] = pKey[1];
    aCopy[2] = pKey[2];
    aCopy[3] = pKey[3];

    unsigned int nPos = 0;
    for (unsigned int i = 0; i < 120; ++i)
    {
        sub_005225A0_SetBit(pKey, i, (unsigned char)sub_00522570_GetBit(aCopy, nPos));
        nPos += 11;
        if (nPos >= 120)
        {
            nPos -= 120;
            if ((int)nPos < 0)
            {
                nPos += 11;
            }
        }
    }
}
