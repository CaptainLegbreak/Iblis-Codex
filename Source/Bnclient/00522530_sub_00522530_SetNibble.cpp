extern unsigned char gaSubstitutionBox_006DFF20[30][16];                                                    // 0x006DFF20
extern unsigned char gaCdKeyCharMap_006E0100[256];                                                          // 0x006E0100

inline unsigned int GetNibble(const unsigned int* pKey, unsigned int nIndex)
{
    const int nShift = (nIndex & 7) * 4;
    const unsigned int nWord = 3 - (nIndex >> 3);
    return (pKey[nWord] & (0xF << nShift)) >> nShift;
}

inline void SetNibble(unsigned int* pKey, unsigned int nIndex, unsigned char nValue)
{
    const int nShift = (nIndex & 7) * 4;
    const unsigned int nWord = 3 - (nIndex >> 3);
    pKey[nWord] = (pKey[nWord] & ~(0xF << nShift)) | ((nValue & 0xF) << nShift);
}

// 0x00522530
void __fastcall sub_00522530_SetNibble(unsigned int* pKey, unsigned int nIndex, unsigned char nValue)
{
    const int nShift = (nIndex & 7) * 4;
    const unsigned int nWord = 3 - (nIndex >> 3);
    pKey[nWord] = (pKey[nWord] & ~(0xF << nShift)) | ((nValue & 0xF) << nShift);
}

// 0x005225A0
void __fastcall sub_005225A0_SetBit(unsigned int* pKey, unsigned int nIndex, unsigned char nValue)
{
    const int nShift = nIndex & 0x1F;
    const unsigned int nWord = 3 - (nIndex >> 5);
    pKey[nWord] = (pKey[nWord] & ~(1 << nShift)) | ((nValue & 1) << nShift);
}

// 0x005225E0
unsigned int __fastcall sub_005225E0(unsigned int nWords, unsigned int nMultiplier, const unsigned int* pSource, unsigned int* pDest, unsigned int nCarry)
{
    pSource += nWords;
    pDest += nWords;
    while (nWords > 0)
    {
        --nWords;
        const unsigned __int64 nResult = (unsigned __int64)*--pSource * nMultiplier + nCarry;
        *--pDest = (unsigned int)nResult;
        nCarry = (unsigned int)(nResult >> 32);
    }
    return nCarry;
}

// 0x00522650
void __fastcall sub_00522650(const char* szKey, unsigned char* pOut)
{
    int nBase = 5;
    unsigned int nPosition = 0x21;
    for (unsigned int i = 0; i < 26; ++i)
    {
        const unsigned int nFirst = (nPosition + 0x7B5) % 0x34;
        nPosition = (nFirst + 0x7B5) % 0x34;
        const int nValue = gaCdKeyCharMap_006E0100[(unsigned char)szKey[i]];
        pOut[nFirst] = nValue / nBase;
        pOut[nPosition] = nValue % nBase;
    }
}

// 0x00522980
void __stdcall sub_00522980(unsigned int* pKey)
{
    for (int i = 29; i >= 0; --i)
    {
        unsigned char nValue = (unsigned char)GetNibble(pKey, i);
        for (int j = 29; j > i; --j)
            nValue = gaSubstitutionBox_006DFF20[i][(unsigned char)GetNibble(pKey, j) ^ gaSubstitutionBox_006DFF20[i][nValue]];
        for (int j = i - 1; j >= 0; --j)
            nValue = gaSubstitutionBox_006DFF20[i][(unsigned char)GetNibble(pKey, j) ^ gaSubstitutionBox_006DFF20[i][nValue]];
        SetNibble(pKey, i, gaSubstitutionBox_006DFF20[i][nValue]);
    }
}

#include "gen/data/Source/Bnclient/00522530_sub_00522530_SetNibble.inc"
