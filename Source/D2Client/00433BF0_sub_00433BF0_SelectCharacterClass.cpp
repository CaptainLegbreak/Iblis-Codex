struct D2WinControlStrc;
struct D2MenuCallbackArgStrc { D2WinControlStrc* pControl; unsigned int nMessage, nParam, nArg; };
#pragma pack(push, 1)
struct D2LaunchRecordStrc
{
    char unknown00[0x85];
    unsigned char nFlag085, nFlag086, nFlag087, nFlag088, nFlag089, nFlag08A, nFlag08B;
    char unknown08C[0x1EE-0x8C]; char nMode; unsigned short nFlags;
};
#pragma pack(pop)
extern int gnTextSentinel_0070CB80; // 0x0070CB80
extern D2WinControlStrc* gpClassImages_0077956C[7]; // 0x0077956C
extern D2LaunchRecordStrc* gpLaunchRecord_007795D4; // 0x007795D4
extern int gnLaunchMode_007795EC; // 0x007795EC
extern int gdwGlobal_00779DA4; // 0x00779DA4
extern D2WinControlStrc* gpControl_00779330; // 0x00779330
extern D2WinControlStrc* gpControl_0077933C; // 0x0077933C
D2WinControlStrc* gpControl_00779348;        // 0x00779348
extern D2WinControlStrc* gpControl_0077934C; // 0x0077934C
D2WinControlStrc* gpControl_00779568;        // 0x00779568
D2WinControlStrc* gpControl_00779598;        // 0x00779598
extern D2WinControlStrc* gpControl_007795B0; // 0x007795B0
D2WinControlStrc* gpControl_007795B4;        // 0x007795B4
extern D2WinControlStrc* gpControl_007795B8; // 0x007795B8
extern D2WinControlStrc* gpControl_007795C4; // 0x007795C4
D2WinControlStrc* gpControl_007795C8;        // 0x007795C8
extern D2WinControlStrc* gpControl_007795CC; // 0x007795CC

int __cdecl sub_00408F20_HasExpansionMpq(); // 0x00408F20
int __fastcall sub_004307A0(unsigned int, int, int, int); // 0x004307A0
int __stdcall sub_004308A0_ExpansionNotice6(D2MenuCallbackArgStrc*); // 0x004308A0
int __stdcall sub_004308E0_ExpansionNotice5(D2MenuCallbackArgStrc*); // 0x004308E0
void __stdcall sub_004F91C0(D2WinControlStrc*); // 0x004F91C0
void __fastcall sub_004F9740(D2WinControlStrc*, int); // 0x004F9740
extern "C" int __fastcall sub_00500310_GetAnimImageField50(D2WinControlStrc*); // 0x00500310
int __fastcall D2Win_10104(D2WinControlStrc*); // 0x00500340
extern "C" void __fastcall BUTTON_SetIsPressed(D2WinControlStrc*, int); // 0x005009A0
void __fastcall D2SOUND_10039(const char*); // 0x00514EC0
void __cdecl sub_00515020_FadeOutWaves(); // 0x00515020

// 0x00431E70
static __declspec(noinline) void sub_00431E70_SetModeFlags(char nMode)
{
    gpLaunchRecord_007795D4->nMode = nMode;
    gpLaunchRecord_007795D4->nFlag085 = 0;
    gpLaunchRecord_007795D4->nFlag089 = 0;
    gpLaunchRecord_007795D4->nFlag088 = 0;
    gpLaunchRecord_007795D4->nFlag086 = 0;
    gpLaunchRecord_007795D4->nFlag087 = 0;
    gpLaunchRecord_007795D4->nFlag08A = 0;
    gpLaunchRecord_007795D4->nFlag08B = 0;
    if (nMode == 0) gpLaunchRecord_007795D4->nFlag085 = 1;
    else if (nMode == 4) gpLaunchRecord_007795D4->nFlag089 = 1;
    else if (nMode == 2) gpLaunchRecord_007795D4->nFlag088 = 1;
    else if (nMode == 3) gpLaunchRecord_007795D4->nFlag086 = 1;
    else if (nMode == 1) gpLaunchRecord_007795D4->nFlag087 = 1;
    else if (nMode == 5) gpLaunchRecord_007795D4->nFlag08A = 1;
    else if (nMode == 6) gpLaunchRecord_007795D4->nFlag08B = 1;
}

// 0x00433BF0
int __stdcall sub_00433BF0_SelectCharacterClass(D2MenuCallbackArgStrc* pArg)
{
    int nImageState = sub_00500310_GetAnimImageField50(pArg->pControl);
    if (sub_00408F20_HasExpansionMpq())
    {
        for (int i = 0; i < 7; ++i)
            if (!D2Win_10104(gpClassImages_0077956C[i])) return 0;
    }
    else
    {
        for (int i = 0; i < 5; ++i)
            if (!D2Win_10104(gpClassImages_0077956C[i])) return 0;
    }
    int nPreviousClass = gnTextSentinel_0070CB80;
    int nClass = -1;
    gnTextSentinel_0070CB80 = -1;
    if (nPreviousClass != -1)
    {
        sub_00515020_FadeOutWaves();
        switch (nPreviousClass)
        {
        case 0: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\amazon deselect.wav"); break;
        case 4: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\barbarian deselect.wav"); break;
        case 3: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\paladin deselect.wav"); break;
        case 2: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\necromancer deselect.wav"); break;
        case 1: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\sorceress deselect.wav"); break;
        case 5: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\druid deselect.wav"); break;
        case 6: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\assassin deselect.wav"); break;
        }
    }
    if (pArg->pControl == gpClassImages_0077956C[0])
    {
        nClass = 4;
        sub_004307A0(pArg->nArg, 4, 0xFA7, 0x140A);
    }
    else if (pArg->pControl == gpClassImages_0077956C[1])
    {
        nClass = 2;
        sub_004307A0(pArg->nArg, 2, 0xFA9, 0x1409);
    }
    else if (pArg->pControl == gpClassImages_0077956C[2])
    {
        nClass = 0;
        sub_004307A0(pArg->nArg, 0, 0xFAB, 0x1408);
    }
    else if (pArg->pControl == gpClassImages_0077956C[3])
    {
        nClass = 1;
        sub_004307A0(pArg->nArg, 1, 0xFAA, 0x140B);
    }
    else if (pArg->pControl == gpClassImages_0077956C[4])
    {
        nClass = 3;
        sub_004307A0(pArg->nArg, 3, 0xFA8, 0x140C);
    }
    else if (pArg->pControl == gpClassImages_0077956C[5])
    {
        nClass = 5;
        sub_004308E0_ExpansionNotice5(pArg);
    }
    else if (pArg->pControl == gpClassImages_0077956C[6])
    {
        nClass = 6;
        sub_004308A0_ExpansionNotice6(pArg);
    }
    if (nClass != nPreviousClass && nImageState == 1)
    {
        switch (nClass)
        {
        case 0: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\amazon select.wav"); break;
        case 4: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\barbarian select.wav"); break;
        case 3: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\paladin select.wav"); break;
        case 2: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\necromancer select.wav"); break;
        case 1: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\sorceress select.wav"); break;
        case 6: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\assassin select.wav"); break;
        case 5: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\druid select.wav"); break;
        }
        gnTextSentinel_0070CB80 = nClass;
    }
    else if (nImageState != 2 && nImageState != 3 && nImageState != 4)
        gnTextSentinel_0070CB80 = nClass;
    sub_00431E70_SetModeFlags((char)gnTextSentinel_0070CB80);
    if (gnTextSentinel_0070CB80 == -1 && nImageState != 1)
    {
        sub_004F9740(gpControl_00779598, 0);
        sub_004F9740(gpControl_007795CC, 0);
        sub_004F9740(gpControl_007795B0, 0);
        sub_004F9740(gpControl_007795C4, 0);
        sub_004F9740(gpControl_0077934C, 0);
        sub_004F9740(gpControl_00779330, 0);
        if (gnLaunchMode_007795EC == 1)
        {
            sub_004F9740(gpControl_007795B8, 0);
            sub_004F9740(gpControl_00779348, 0);
        }
        if (sub_00408F20_HasExpansionMpq())
        {
            sub_004F9740(gpControl_00779568, 0);
            sub_004F9740(gpControl_007795C8, 0);
            sub_004F9740(gpControl_007795B4, 0);
        }
        sub_004F91C0(0);
        if (gnLaunchMode_007795EC == 1) sub_004F9740(gpControl_0077933C, 1);
    }
    else
    {
        sub_004F9740(gpControl_00779598, 1);
        sub_004F9740(gpControl_007795CC, 1);
        if (gdwGlobal_00779DA4)
        {
            sub_004F9740(gpControl_007795B0, 1);
            sub_004F9740(gpControl_007795C4, 1);
        }
        if (gnLaunchMode_007795EC == 1)
        {
            sub_004F9740(gpControl_007795B8, 1);
            sub_004F9740(gpControl_00779348, 1);
        }
        sub_004F9740(gpControl_0077934C, 1);
        sub_004F91C0(gpControl_0077934C);
        sub_004F9740(gpControl_00779330, 1);
        if (gnLaunchMode_007795EC == 1) sub_004F9740(gpControl_0077933C, 0);
    }
    if (sub_00408F20_HasExpansionMpq())
    {
        if (gnTextSentinel_0070CB80 == 6 || gnTextSentinel_0070CB80 == 5)
        {
            sub_004F9740(gpControl_00779568, 1);
            sub_004F9740(gpControl_007795C8, 0);
            sub_004F9740(gpControl_007795B4, 1);
            gpLaunchRecord_007795D4->nFlags |= 0x20;
        }
        else if (gnTextSentinel_0070CB80 != -1)
        {
            sub_004F9740(gpControl_00779568, 1);
            sub_004F9740(gpControl_007795C8, 1);
            sub_004F9740(gpControl_007795B4, 0);
            BUTTON_SetIsPressed(gpControl_007795C8, 1);
            gpLaunchRecord_007795D4->nFlags |= 0x20;
        }
    }
    if (gnLaunchMode_007795EC == 1)
    {
        BUTTON_SetIsPressed(gpControl_00779348, 1);
        gpLaunchRecord_007795D4->nFlags |= 0x40;
    }
    return 1;
}

#include "gen/data/Source/D2Client/00433BF0_sub_00433BF0_SelectCharacterClass.inc"
