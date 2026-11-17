#define NULL 0

extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix);                  // 0x006867B2
extern "C" int __cdecl tolower(int nChar);                                                                  // 0x0068523E
extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
extern const char gacCDKeyMap_006DF238[];                                                                   // 0x006DF238

static void sub_0051DD50_DecodeKeyPairs(char* szKey, unsigned int* pValue)
{
    unsigned int nBit = 1;
    *pValue = 0;
    for (int i = 0; i < 16; i += 2)
    {
        unsigned int nPair = gacCDKeyMap_006DF238[(unsigned char)szKey[i]] * 24 + gacCDKeyMap_006DF238[(unsigned char)szKey[i + 1]];
        if (nPair >= 0x100)
        {
            nPair -= 0x100;
            *pValue |= nBit;
        }

        unsigned int nHigh = (nPair >> 4) & 0xF;
        if (nHigh >= 10)
        {
            nHigh += 0x37;
        }
        else
        {
            nHigh += 0x30;
        }
        szKey[i] = nHigh;

        unsigned int nLow = nPair & 0xF;
        if (nLow >= 10)
        {
            nLow += 0x37;
        }
        else
        {
            nLow += 0x30;
        }
        szKey[i + 1] = nLow;
        nBit <<= 1;
    }
}

// 0x0051DDD0
int __fastcall sub_0051DDD0_DecodeCDKey16(int* pProduct, int* pValue1, const char* szKey, int* pValue2)
{
    *pProduct = 0;
    *pValue1 = 0;
    *pValue2 = 0;
    if (!szKey)
    {
        return 0;
    }

    char szBuffer[0x20];
    SStrCopy(szBuffer, szKey, 0x20);

    unsigned int nValue;
    sub_0051DD50_DecodeKeyPairs(szBuffer, &nValue);

    unsigned int nChecksum = 3;
    for (unsigned int i = 0; i < 0x10; ++i)
    {
        const char c = tolower(szBuffer[i]);
        const int nDigit = c >= 0x61 ? c - 0x57 : c - 0x30;
        nChecksum += (nChecksum * 2) ^ nDigit;
    }

    if ((unsigned char)nChecksum != nValue)
    {
        return 0;
    }

    for (int i = 15; i >= 0; --i)
    {
        const int j = (i + 7) & 15;
        const char c = szBuffer[i];
        szBuffer[i] = szBuffer[j];
        szBuffer[j] = c;
    }

    nValue = 0x13AC9741;
    for (int i = 15; i >= 0; --i)
    {
        const char c = toupper(szBuffer[i]);
        szBuffer[i] = c;
        if (c <= 0x37)
        {
            szBuffer[i] = (nValue & 7) ^ c;
            nValue >>= 3;
        }
        else if (c < 0x41)
        {
            szBuffer[i] = (i & 1) ^ c;
        }
    }

    char szPart2[7];
    char szPart3[9];
    SStrCopy((char*)&nValue, szBuffer, 3);
    SStrCopy(szPart2, &szBuffer[2], 7);
    SStrCopy(szPart3, &szBuffer[8], 9);
    *pProduct = strtoul((char*)&nValue, NULL, 0x10);
    *pValue1 = strtoul(szPart2, NULL, 0x10);
    *pValue2 = strtoul(szPart3, NULL, 0x10);
    return 1;
}
