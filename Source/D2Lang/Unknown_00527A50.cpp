#include "D2Unicode.h"
#include "D2Lang.h"


extern unsigned short gnCharMapCount;                                                              // 0x00882B20
unsigned char gnLeadByteRangeCount;                                                                // 0x00882B22
extern D2LangCharMapEntryStrc* gpCharMap;                                                          // 0x00882B24
extern "C" unsigned int __cdecl strlen(const char* szString);

// 0x005276E0
static int sub_005276E0_IsLeadByte(unsigned char nByte)
{
    if (nByte < 0x20)
    {
        return 0;
    }
    for (int i = 0; i < gnLeadByteRangeCount; ++i)
    {
// build: symbol ?gpLeadByteRanges@* 0x00882B28
        if (gpLeadByteRanges[i].nLow <= nByte && nByte <= gpLeadByteRanges[i].nHigh)
        {
            return 0;
        }
    }
    return 1;
}

// build: context - inferred inline helper of 0x00527A50 (no address of its own): the index search with the map

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

// 0x00527B00
static int sub_00527B00_MapUnicodeChar(unsigned short wChar)
{
    if (wChar < 0x20)
    {
        return wChar;
    }
    D2LangCharMapEntryStrc tKey;
    tKey.f_2 = wChar;
    const D2LangCharMapEntryStrc* pEntry = (const D2LangCharMapEntryStrc*)bsearch(&tKey, gpCharMap, gnCharMapCount, sizeof(D2LangCharMapEntryStrc), sub_00527AE0_CompareKey);
    if (!pEntry)
    {
        return -1;
    }
    return pEntry->wValue;
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

// 0x00527D50
int __fastcall sub_00527D50_GetCodePageCharCount(const char* szSrc, int nCount)
{
    if (!gpCharMapIndex)
    {
        return strlen(szSrc);
    }
    int nLength = 0;
    for (int i = 0; i < nCount; ++nLength)
    {
        const unsigned char nByte = szSrc[i];
        if (!nByte)
        {
            break;
        }
        if (sub_005276E0_IsLeadByte(nByte))
        {
            i += 2;
        }
        else
        {
            i += 1;
        }
    }
    return nLength;
}
