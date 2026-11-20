#include "D2LangTypes.h"
extern "C" unsigned int __cdecl strlen(const char* sz);

struct Unicode
{
    unsigned short wChar;
};

extern D2UtfConvertSpecStrc gaUtf8ConvertTable_007309B8[7];                                                 // 0x007309B8

// 0x00526100
static int __stdcall sub_00526100_Utf8ToUnicodeChar(Unicode* pDest, int nCount, const char* pSrc)
{
    int n = 0;
    if (nCount <= 0)
        return -1;

    const unsigned short c = (unsigned char)*pSrc;
    int nCode = (short)c;
    for (const D2UtfConvertSpecStrc* pSpec = gaUtf8ConvertTable_007309B8; pSpec->nMask; ++pSpec)
    {
        const short nLead = pSpec->nMask & c;
        ++n;
        if (nLead == pSpec->nLeading)
        {
            nCode &= pSpec->nLast;
            if (nCode < pSpec->nFirst)
                return -1;
            pDest->wChar = nCode;
            return n;
        }

        if (nCount <= n)
            return -1;

        const unsigned short t = (unsigned char)(*++pSrc ^ 0x80);
        if (t & 0xC0)
            return -1;
        nCode = (nCode << 6) | (short)t;
    }
    return -1;
}

// 0x00526320
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength)
{
    int nDest = 0;
    const int nSourceLength = strlen(szSource);
    int nSrc = 0;
    for (;;)
    {
        if (!(szSource[nSrc] && nDest < nLength - 1))
            break;
        const int nUnits = sub_00526100_Utf8ToUnicodeChar(&pDest[nDest], nSourceLength - nSrc, &szSource[nSrc]);
        ++nDest;
        if (nUnits == -1)
            break;
        nSrc += nUnits;
    }
    pDest[nDest].wChar = 0;
    return pDest;
}
