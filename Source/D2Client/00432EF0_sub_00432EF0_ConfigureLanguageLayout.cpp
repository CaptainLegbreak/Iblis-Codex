typedef unsigned short U16;
struct U16Cell
{
    U16 value;

};
typedef char U16_is_two[(sizeof(U16)==2)?1:-1];
typedef char Cell_size[(sizeof(U16Cell)==2)?1:-1];
typedef char Cell_value_zero[((unsigned int)&((U16Cell*)0)->value==0)?1:-1];
struct UiControl;
extern "C" int __cdecl sub_00525150_Language();
extern "C" void __fastcall sub_004F9740_ControlFlag(UiControl* control,int value);
extern "C" int __fastcall sub_00526800_UnicodeLength(const U16* text);
extern "C" UiControl* gControl;
extern "C" const U16Cell gUpperTable[];
extern "C" int gLayout_00709C48; // 0x00709C48
extern "C" int gLayout_007091F8; // 0x007091F8
extern "C" int gLayout_00709228; // 0x00709228
extern "C" int gLayout_00709258; // 0x00709258
extern "C" int gLayout_007092E8; // 0x007092E8
extern "C" int gLayout_00709318; // 0x00709318
extern "C" int gLayout_00709EE8; // 0x00709EE8
extern "C" int gLayout_0070B2C8; // 0x0070B2C8
extern "C" int gLayout_0070B2F8; // 0x0070B2F8
extern "C" int gLayout_0070B088; // 0x0070B088
extern "C" int gLayout_0070B4A8; // 0x0070B4A8
extern "C" int gLayout_0070B0E8; // 0x0070B0E8
extern "C" int gLayout_0070B148; // 0x0070B148
extern "C" int gLayout_0070B1A8; // 0x0070B1A8
extern "C" int gLayout_0070BDA8; // 0x0070BDA8
extern "C" int gLayout_0070BF58; // 0x0070BF58

// 0x00432EF0
extern "C" void __cdecl sub_00432EF0_ConfigureLanguageLayout()
{
    if (sub_00525150_Language() == 9)
    {
        gLayout_00709C48 = 0x9B;
        gLayout_007091F8 = 0x14E;
        gLayout_00709228 = 0x184;
        gLayout_00709258 = 0x1BA;
        gLayout_007092E8 = 0xF0;
        gLayout_00709318 = 0x158;
        gLayout_00709EE8 = 0x9C;
        gLayout_0070B2C8 = 0x1FA;
        gLayout_0070B2F8 = 0x22B;
        gLayout_0070B088 = 0x23F;
        gLayout_0070B4A8 = 0x22B;
        gLayout_0070B0E8 = 0x22B;
        gLayout_0070B148 = 0x23F;
        gLayout_0070B1A8 = 0x253;
        gLayout_0070BDA8 = 0x46;
        gLayout_0070BF58 = 0xEE;
    }
}

extern "C" int __fastcall sub_0043DAD0_SetControlFlag(int value)
{
    sub_004F9740_ControlFlag(gControl, value);
    return 1;
}

#include "gen/data/Source/D2Client/00432EF0_sub_00432EF0_ConfigureLanguageLayout.inc"
