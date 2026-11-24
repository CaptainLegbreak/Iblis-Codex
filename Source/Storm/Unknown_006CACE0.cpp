#include "Storm.h"

extern int gnKeyConfigThumbY; // 0x007C02CC

void __cdecl sub_006CB400_Nop(); // 0x006CB400
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824
extern const char* gszDefaultClass_0072DAA0; // 0x0072DAA0
extern const char* gszWindowClassName; // 0x007C9158
extern const char* gszDefaultWindow_0072DB3C; // 0x0072DB3C
extern const char* gszWindowClass; // 0x007C9344
extern const char* gszWindowTitle; // 0x007C9348
extern unsigned int gaTable_00841EC8[0x200]; // 0x00841EC8

// 0x006CADE0
void __cdecl sub_006CADE0_RegisterCleanup()
{
    sub_00683824_RegisterExit(sub_006CB400_Nop);
}

// 0x006CADF0
void __cdecl sub_006CADF0_InitializeWindowText()
{
    gszWindowClassName = gszDefaultClass_0072DAA0;
}

#include "gen/data/Source/Storm/Unknown_006CACE0.inc"

// 0x006CAE00
void __cdecl sub_006CAE00_InitializeWindowText()
{
    gszWindowClass = gszDefaultWindow_0072DB3C;
}

// 0x006CAE10
void __cdecl sub_006CAE10_InitializeWindowText()
{
    gszWindowTitle = gszDefaultWindow_0072DB3C;
}

// 0x006CAE20
void __cdecl sub_006CAE20_ClearTable()
{
    for (int i = 0; i < 0x200; ++i)
    {
        gaTable_00841EC8[i] = 0;
    }
}

unsigned short gwColorCodeFirst_008426E0; // 0x008426E0

unsigned short gwColorCodeSecond_008426E2; // 0x008426E2

// 0x006CAE40
void __cdecl sub_006CAE40_InitializeColorCode()
{
    gwColorCodeFirst_008426E0 = 0;
    gwColorCodeSecond_008426E2 = 0;
}

unsigned short gwMonsterCodeFirst_008426DC; // 0x008426DC

unsigned short gwMonsterCodeSecond_008426DE; // 0x008426DE

// 0x006CAE50
void __cdecl sub_006CAE50_InitializeMonsterCode()
{
    gwMonsterCodeFirst_008426DC = 0;
    gwMonsterCodeSecond_008426DE = 0;
}
