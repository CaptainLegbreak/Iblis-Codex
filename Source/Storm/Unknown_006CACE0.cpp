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

#include "gen/data/Source/Storm/Unknown_006CACE0.inc"

