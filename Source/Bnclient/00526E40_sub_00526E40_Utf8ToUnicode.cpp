struct Unicode
{
    unsigned short wChar;
};

int __stdcall sub_006C7410_Utf8ToUtf16(unsigned short* pDst, unsigned int nDstMax, const unsigned char* pSrc, unsigned int nSrcMax, unsigned int* pnDstWritten, unsigned int* pnSrcRead); // 0x006C7410

extern "C" unsigned int __cdecl strlen(const char* szString);

// 0x00526E40
Unicode* __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength)
{
    unsigned int nWritten;
    unsigned short wszBuffer[0x400];

    if (sub_006C7410_Utf8ToUtf16(wszBuffer, 0x3FF, (const unsigned char*)szSrc, strlen(szSrc) + 1, &nWritten, 0))
    {
        nWritten = 0;
    }
    wszBuffer[nWritten] = 0;

    int i = 0;
    for (; i < nMaxLength; ++i)
    {
        if (!wszBuffer[i])
        {
            break;
        }
        pDst[i].wChar = wszBuffer[i];
    }

    if (wszBuffer[i])
    {
        pDst[i - 1].wChar = 0;
    }
    else
    {
        pDst[i].wChar = 0;
    }

    return pDst;
}
