#include "D2Lang.h"

extern unsigned short gwCrc16Table_007301D8[0x100];                                                         // 0x007301D8

struct Unicode
{
    unsigned short wChar;

    Unicode() {}
    Unicode(unsigned short wValue) : wChar(wValue) {}
    Unicode toUpper() const
    {
        return Unicode(wChar < 0x100 ? gwToUpperTable_00730578[wChar] : wChar);
    }
    static int __fastcall compare(Unicode lhs, Unicode rhs);
};

// 0x00524FD0
void __cdecl sub_00524FD0_Crc16Init(unsigned short* pCrc)
{
    *pCrc = 0xFFFF;
}

// 0x00524FE0
void __cdecl sub_00524FE0_Crc16Update(unsigned short* pCrc, unsigned char nByte)
{
    *pCrc = (*pCrc << 8) ^ gwCrc16Table_007301D8[(*pCrc >> 8) ^ nByte];
}

// 0x00526490
int __fastcall Unicode::compare(Unicode lhs, Unicode rhs)
{
    return lhs.toUpper().wChar == rhs.toUpper().wChar;
}

#include "gen/data/Source/D2Lang/StrTable/strtable_00524FD0.inc"
