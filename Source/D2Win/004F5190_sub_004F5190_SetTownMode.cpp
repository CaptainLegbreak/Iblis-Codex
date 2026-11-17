extern int gdwGlobal_0072DA4C; // 0x0072DA4C
extern int gnDisplayType; // 0x007C8CB0

// 0x004F5190
void __stdcall sub_004F5190_SetTownMode(int bTown)
{
    if (gnDisplayType < 4)
        bTown = 0;
    gdwGlobal_0072DA4C = bTown;
}

#include "gen/data/Source/D2Win/004F5190_sub_004F5190_SetTownMode.inc"
