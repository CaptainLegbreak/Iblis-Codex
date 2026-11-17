struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2UnitStrc;

void __fastcall sub_004E60A0_BuildItemPropertyText(D2UnitStrc* pItem, Unicode* wszBuffer, int nSize, int a4, int a5, int a6, int a7, int a8); // 0x004E60A0
int __fastcall sub_00526800(const Unicode* wszText); // 0x00526800
Unicode* __fastcall sub_00526700(Unicode* wszDest, const Unicode* wszSrc); // 0x00526700
const Unicode* __fastcall sub_00524A30(int nId); // 0x00524A30

// 0x004E6410
void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nUnused, int bFlag, const Unicode* wszExtra)
{
    Unicode wszBuffer[1024];
    wszBuffer[0] = 0;
    sub_004E60A0_BuildItemPropertyText(pItem, wszBuffer, 1024, 1, 0, 0xAB, 0x40, bFlag);
    if (!wszExtra)
    {
        sub_00526700(wszText, wszBuffer);
        return;
    }

    const int nLength = sub_00526800(wszBuffer);
    if (!nLength)
    {
        sub_00526700(wszText, wszBuffer);
        return;
    }

    int i = nLength - 2;
    while (i > 0)
    {
        if (wszBuffer[i].wChar == 10)
            break;
        --i;
    }

    if (i <= 0)
    {
        sub_00526700(wszText, wszExtra);
        sub_00526700(wszText, wszBuffer);
        return;
    }

    const Unicode* wszNewLine = sub_00524A30(0xF9E);
    const Unicode* wszSuffix = sub_00524A30(0xF0C);
    wszBuffer[i] = 0;
    sub_00526700(wszText, wszBuffer);
    sub_00526700(wszText, wszNewLine);
    sub_00526700(wszText, wszExtra);
    if (wszBuffer[nLength - 1].wChar == 10)
    {
        wszBuffer[nLength - 1] = 0;
    }
    sub_00526700(wszText, &wszBuffer[i + 1]);
    sub_00526700(wszText, wszSuffix);
    sub_00526700(wszText, wszNewLine);
}
