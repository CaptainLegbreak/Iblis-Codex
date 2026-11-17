typedef unsigned int size_t;

extern unsigned short gwToUpperTable_00730578[0x100];                                                       // 0x00730578

struct Unicode
{
    unsigned short wChar;

    Unicode() {}
    Unicode(unsigned short wValue) : wChar(wValue) {}
    Unicode toUpper() const
    {
        return Unicode(wChar < 0x100 ? gwToUpperTable_00730578[wChar] : wChar);
    }
    static int __fastcall strnicmp(const Unicode* str1, const Unicode* str2, size_t count);
};

// 0x00526610
int __fastcall Unicode::strnicmp(const Unicode* str1, const Unicode* str2, size_t count)
{
    Unicode ch1 = str1->toUpper();
    Unicode ch2 = str2->toUpper();
    while (str1->wChar && str2->wChar && count-- && ch1.wChar == ch2.wChar)
    {
        ch1 = (str1++)->toUpper();
        ch2 = (str2++)->toUpper();
    }
    if (ch1.wChar < ch2.wChar)
    {
        return -1;
    }
    return ch1.wChar > ch2.wChar;
}

#include "gen/data/Source/Bnclient/00526610_strnicmp.inc"
