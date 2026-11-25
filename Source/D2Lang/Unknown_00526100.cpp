#include "D2Lang.h"
#include "D2LangTypes.h"
#include "D2Unicode.h"

struct D2UtfConvertSpecStrc;
struct D2LangByteRangeStrc;

extern "C" unsigned int __cdecl strlen(const char* sz);


extern D2UtfConvertSpecStrc gaUtf8ConvertTable[7]; // 0x007309B8

extern unsigned short gnCharMapCount; // 0x00882B20
extern D2LangByteRangeStrc* gpLeadByteRanges; // 0x00882B28
extern unsigned short* gpCharMapIndex; // 0x00882B2C
extern "C" void* __cdecl bsearch(const void* pKey, const void* pBase, unsigned int nCount, unsigned int nSize, int (__cdecl* pfCompare)(const void*, const void*)); // 0x006881B1
int __cdecl sub_00527AE0_CompareKey(const void* pLeft, const void* pRight); // 0x00527AE0
Unicode* __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

// 0x00526100
static int __stdcall sub_00526100_Utf8ToUnicodeChar(Unicode* pDest, int nCount, const char* pSrc)
{
    int n = 0;
    if (nCount <= 0)
        return -1;

    const unsigned short c = (unsigned char)*pSrc;
    int nCode = (short)c;
    for (const D2UtfConvertSpecStrc* pSpec = gaUtf8ConvertTable; pSpec->nMask; ++pSpec)
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

// 0x00526190
static int __stdcall sub_00526190_UnicodeCharToUtf8(char* pDest, Unicode ch)
{
    const int nCode = ch.wChar;
    int n = 0;
    for (const D2UtfConvertSpecStrc* pSpec = gaUtf8ConvertTable; pSpec->nMask; ++pSpec)
    {
        ++n;
        if (nCode <= pSpec->nLast)
        {
            int nBits = pSpec->nTrailingBits;
            *pDest = (nCode >> nBits) | (unsigned char)pSpec->nLeading;
            while (nBits > 0)
            {
                nBits -= 6;
                *++pDest = ((nCode >> nBits) & 0x3F) | 0x80;
            }
            return n;
        }
    }
    return -1;
}

// 0x00526200
static int __stdcall sub_00526200_Utf8CharLength(int nCount, const char* pSrc)
{
    int n = 0;
    if (nCount <= 0)
        return -1;

    const int c = (unsigned char)*pSrc;
    int nCode = c;
    for (const D2UtfConvertSpecStrc* pSpec = gaUtf8ConvertTable; pSpec->nMask; ++pSpec)
    {
        ++n;
        if (((short)pSpec->nMask & c) == pSpec->nLeading)
        {
            if ((pSpec->nLast & nCode) < pSpec->nFirst)
                return -1;
            return n;
        }

        if (nCount <= n)
            return -1;

        const int t = (unsigned char)*++pSrc ^ 0x80;
        if (t & 0xC0)
            return -1;
        nCode = (nCode << 6) | t;
    }
    return -1;
}

// 0x005262A0
int __fastcall sub_005262A0_Utf8CountChars(const char* pSrc, int nCount)
{
    int n = 0;
    while (nCount > 0)
    {
        if (!*pSrc)
            break;
        const int nUnits = sub_00526200_Utf8CharLength(nCount, pSrc);
        if (nUnits != -1)
        {
            for (int j = 0; j < nUnits; ++j)
            {
                if (!*pSrc++)
                    return n;
            }
            ++n;
            nCount -= nUnits;
        }
        else
        {
            ++pSrc;
            --nCount;
        }
    }
    return n;
}

int __fastcall sub_005262F0_UnicodeCharUtf8Length(const Unicode* pChar)
{
    char szBuffer[8];
    return sub_00526190_UnicodeCharToUtf8(szBuffer, *pChar);
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

// 0x005263E0
char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength)
{
    int nLength = 0;
    for (int i = 0; pSource[i].wChar; ++i)
    {
        if (nLength >= nMaxLength - 1)
            break;
        const int nUnits = sub_00526190_UnicodeCharToUtf8(&szDest[nLength], pSource[i]);
        if (nUnits == -1)
            break;
        nLength += nUnits;
    }
    szDest[nLength] = 0;
    return szDest;
}

// 0x00526430
int __fastcall sub_00526430_UnicodeUtf8Length(const Unicode* pSource, int nCount)
{
    char szBuffer[12];
    int nLength = 0;
    for (int i = 0; pSource[i].wChar; ++i)
    {
        if (i >= nCount)
            break;
        const int nUnits = sub_00526190_UnicodeCharToUtf8(szBuffer, pSource[i]);
        if (nUnits == -1)
            break;
        nLength += nUnits;
    }
    return nLength;
}

#include "gen/data/Source/D2Lang/Unknown_00526100.inc"

// 0x005267E0
extern "C" __declspec(dllexport) unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc) {
    unsigned short* p = pDst;
    do {
        *p++ = *pSrc;
    } while (*pSrc++);
    return pDst;
}

unsigned char gnLeadByteRangeCount; // 0x00882B22

// 0x005276E0
static int sub_005276E0_IsLeadByte(unsigned char nByte)
{
    if (nByte < 0x20)
    {
        return 0;
    }
    for (int i = 0; i < gnLeadByteRangeCount; ++i)
    {
        if (gpLeadByteRanges[i].nLow <= nByte && nByte <= gpLeadByteRanges[i].nHigh)
        {
            return 0;
        }
    }
    return 1;
}

static __forceinline int FindCharIndex(unsigned short wChar)
{
    int nLow = 0;
    int nHigh = gnCharMapCount - 1;
// build: symbol ?gpCharMap@* 0x00882B24
    if (wChar < gpCharMap[gpCharMapIndex[0]].wValue || wChar > gpCharMap[gpCharMapIndex[nHigh]].wValue)
    {
        return -1;
    }
    int nMid = nHigh;
    if (wChar != gpCharMap[gpCharMapIndex[nHigh]].wValue)
    {
        nMid = (nLow + nHigh) >> 1;
        do
        {
            if (wChar >= gpCharMap[gpCharMapIndex[nMid]].wValue)
            {
                nLow = nMid;
            }
            else
            {
                nHigh = nMid;
            }
            nMid = (nLow + nHigh) >> 1;
        }
        while (nHigh - nLow > 1);
        if (gpCharMap[gpCharMapIndex[nMid]].wValue != wChar)
        {
            return -1;
        }
    }
    return nMid;
}

// build: symbol ?UNISYS_MapCodePageChar@* 0x00527A50
static int UNISYS_MapCodePageChar(unsigned short wChar)
{
    if (wChar < 0x20)
    {
        return wChar;
    }
    const int nIndex = FindCharIndex(wChar);
    if (nIndex < 0)
    {
        return -1;
    }
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
        const int nUnicode = UNISYS_MapCodePageChar(wChar);
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

char* __fastcall sub_00527BE0_UnicodeToCodePage(char* szDest, const Unicode* pSrc, int nCount)
{
    if (!gpCharMap)
    {
        return sub_00526F70(szDest, pSrc, nCount);
    }
    int i = 0;
    for (; i < nCount; ++pSrc)
    {
        const Unicode tChar = *pSrc;
        if (!tChar.wChar)
        {
            break;
        }
        const int nCodePage = sub_00527B00_MapUnicodeChar(tChar.wChar);
        if (nCodePage < 0)
        {
            continue;
        }
        if ((nCodePage & 0xFF00) || sub_005276E0_IsLeadByte((unsigned char)nCodePage))
        {
            szDest[i++] = (char)((unsigned int)nCodePage >> 8);
        }
        szDest[i++] = (char)nCodePage;
    }
    if (!pSrc->wChar && i < nCount)
    {
        szDest[i] = 0;
    }
    return szDest;
}

int __fastcall sub_00527CA0_GetCodePageLength(const Unicode* pSrc, int nCount)
{
    if (!gpCharMap)
    {
        return sub_00526800(pSrc);
    }
    int nLength = 0;
    for (int i = 0; i < nCount; ++i)
    {
        const Unicode tChar = pSrc[i];
        if (!tChar.wChar)
        {
            break;
        }
        const int nCodePage = sub_00527B00_MapUnicodeChar(tChar.wChar);
        if (nCodePage < 0)
        {
            continue;
        }
        if ((nCodePage & 0xFF00) || sub_005276E0_IsLeadByte((unsigned char)nCodePage))
        {
            nLength += 2;
        }
        else
        {
            nLength += 1;
        }
    }
    return nLength;
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
