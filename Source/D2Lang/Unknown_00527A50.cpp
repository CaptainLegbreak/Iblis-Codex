#include "D2Unicode.h"
#include "D2Lang.h"


extern unsigned short gnCharMapCount;                                                              // 0x00882B20
unsigned char gnLeadByteRangeCount;                                                                // 0x00882B22
extern D2LangCharMapEntryStrc* gpCharMap;                                                          // 0x00882B24
extern "C" unsigned int __cdecl strlen(const char* szString);

int sub_005276E0_IsLeadByte(unsigned char nByte); // 0x005276E0

static __forceinline int sub_00527A50_FindIndex(const D2LangCharMapEntryStrc* pMap, unsigned short wChar)
{
    int nLow = 0;
    int nHigh = gnCharMapCount - 1;
// build: symbol ?gpCharMapIndex@* 0x00882B2C
    if (wChar < pMap[gpCharMapIndex[0]].wValue)
        return -1;
    if (wChar > pMap[gpCharMapIndex[nHigh]].wValue)
        return -1;
    if (wChar == pMap[gpCharMapIndex[nHigh]].wValue)
        return nHigh;
    int nMid = nHigh >> 1;
    do
    {
        if (wChar < pMap[gpCharMapIndex[nMid]].wValue)
            nHigh = nMid;
        else
            nLow = nMid;
        nMid = (nHigh + nLow) >> 1;
    } while (nHigh - nLow > 1);
    if (pMap[gpCharMapIndex[nMid]].wValue != wChar)
        return -1;
    return nMid;
}

// 0x00527A50
static int sub_00527A50_MapCodePageChar(unsigned short wChar)
{
    if (wChar < 0x20)
        return wChar;
    const int nIndex = sub_00527A50_FindIndex(gpCharMap, wChar);
    if (nIndex < 0)
        return -1;
    return gpCharMap[gpCharMapIndex[nIndex]].f_2;
}

// 0x00527B50
Unicode* __fastcall sub_00527B50_CodePageToUnicode(Unicode* pDest, const char* szSrc, int nCount)
{
    if (!gpCharMapIndex)
    {
        return sub_00526F20_ToUnicode(pDest, szSrc, nCount);
    }
    int i = 0;
    for (; i < nCount; ++i)
    {
        const unsigned char nByte = *szSrc;
        if (!nByte)
        {
            goto terminate;
        }
        unsigned short wChar;
        if (sub_005276E0_IsLeadByte(nByte))
        {
            wChar = (unsigned short)((nByte << 8) | (unsigned char)szSrc[1]);
            szSrc += 2;
        }
        else
        {
            wChar = nByte;
            ++szSrc;
        }
        const int nUnicode = sub_00527A50_MapCodePageChar(wChar);
        if (nUnicode < 0)
        {
            --i;
        }
        else
        {
            pDest[i].wChar = nUnicode;
        }
    }
    if (*szSrc)
    {
        return pDest;
    }
terminate:
    if (i < nCount)
    {
        pDest[i].wChar = 0;
    }
    return pDest;
}

