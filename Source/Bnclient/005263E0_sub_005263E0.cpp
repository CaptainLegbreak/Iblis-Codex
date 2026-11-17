struct Unicode
{
    unsigned short wChar;
};

struct D2UtfConvertSpecStrc
{
    unsigned short nMask;
    short nLeading;
    short nTrailingBits;
    short unk0x06;
    int nLast;
    int nFirst;
};

extern D2UtfConvertSpecStrc gaUtf8ConvertTable_007309B8[7];                                                 // 0x007309B8

// 0x00526190
static int __stdcall sub_00526190_UnicodeCharToUtf8(char* pDest, Unicode ch)
{
    const int nCode = ch.wChar;
    int n = 0;
    for (const D2UtfConvertSpecStrc* pSpec = gaUtf8ConvertTable_007309B8; pSpec->nMask; ++pSpec)
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

int __fastcall sub_005262F0_UnicodeCharUtf8Length(const Unicode* pChar)
{
    char szBuffer[8];
    return sub_00526190_UnicodeCharToUtf8(szBuffer, *pChar);
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
