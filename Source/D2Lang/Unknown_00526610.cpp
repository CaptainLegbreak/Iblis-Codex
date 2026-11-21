#include "D2Lang.h"
#include "D2Unicode.h"

// 0x00526490
int __fastcall Unicode::compare(Unicode lhs, Unicode rhs)
{
    return lhs.toUpper().wChar == rhs.toUpper().wChar;
}

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

#include "gen/data/Source/D2Lang/Unknown_00526610.inc"
