extern "C" int gnModeValue_00712CCC; // 0x00712CCC
extern "C" { int gnFlag_007BCE28; } // 0x007BCE28
extern "C" { int gnFlag_007C02EC; } // 0x007C02EC
extern "C" int gnValue_007C0C3C; // 0x007C0C3C
extern "C" unsigned char gbFlag_007BC9D4; // 0x007BC9D4
extern "C" unsigned char gbFlag_007BC9D8; // 0x007BC9D8
extern "C" int gnScreenHeight_00711470; // 0x00711470

// 0x004776F0
extern "C" void __cdecl sub_004776F0_SetModeValue4()
{
    gnModeValue_00712CCC = 4;
}

// 0x00477700
extern "C" void __cdecl sub_00477700_SetModeValue5()
{
    gnModeValue_00712CCC = 5;
}

// 0x00477710
extern "C" void __cdecl sub_00477710_SetModeValue6()
{
    gnModeValue_00712CCC = 6;
}

// 0x00477720
extern "C" void __cdecl sub_00477720_SetModeValue7()
{
    gnModeValue_00712CCC = 7;
}

// 0x0048A6E0
extern "C" void __cdecl sub_0048A6E0_SetFlag7BCE28()
{
    gnFlag_007BCE28 = 1;
}

// 0x004A7A80
extern "C" void __cdecl sub_004A7A80_ClearFlag7C02EC()
{
    gnFlag_007C02EC = 0;
}

// 0x004AA8F0
extern "C" void __cdecl sub_004AA8F0_ClearValue7C0C3C()
{
    gnValue_007C0C3C = 0;
}

// 0x00483300
extern "C" void __cdecl sub_00483300_SetByteFlag7BC9D4()
{
    gbFlag_007BC9D4 = 1;
}

// 0x00483340
extern "C" void __cdecl sub_00483340_SetByteFlag7BC9D8()
{
    gbFlag_007BC9D8 = 1;
}

// 0x00454970
extern "C" int __cdecl sub_00454970_GetScreenHeightMinus49()
{
    return gnScreenHeight_00711470 - 49;
}

#include "gen/data/Source/D2Client/004776F0_sub_004776F0_SetModeValue4.inc"
