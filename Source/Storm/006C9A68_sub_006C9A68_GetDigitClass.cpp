extern const unsigned char gCharacterClass_0074C5C8[]; // 0x0074C5C8
// 0x006C9A68
int __fastcall sub_006C9A68_GetDigitClass(signed char character)
{
    return gCharacterClass_0074C5C8[character] & 2;
}

#include "gen/data/Source/Storm/006C9A68_sub_006C9A68_GetDigitClass.inc"
