struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short wValue = 0) : wChar(wValue) {}
};

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

// 0x004834E0
void __fastcall sub_004834E0_ReplaceToken(Unicode* pText, int nIndex, const Unicode* pInsert)
{
    Unicode wszBuffer[400];
    const int nDigit = nIndex + '0';
    const int nLength = sub_00526800(pText);
    for (int i = 0; i < nLength - 1; ++i)
    {
        if (pText[i].wChar == '%' && pText[i + 1].wChar == nDigit)
        {
            sub_00526700(wszBuffer, pInsert);
            const Unicode* pEnd = &wszBuffer[sub_00526800(wszBuffer) - 1];
            const int bSpace = pEnd->wChar == ' ';
            Unicode* pDest = pText;
            const Unicode* pRest;
            if (!(bSpace && pDest[i + 2].wChar == ' '))
            {
                pRest = &pDest[i + 2];
                sub_00526700(wszBuffer, pRest);
            }
            else
            {
                pRest = &pDest[i + 3];
                sub_00526700(wszBuffer, pRest);
            }
            sub_005267E0(pDest, wszBuffer);
            return;
        }
        wszBuffer[i] = pText[i];
    }
}
