#include "Storm.h"


extern int gnTextLeft; // 0x007BF278

#include "gen/data/Source/Storm/Unknown_006C9A68.inc"

const char* gpszCaption_007A0450; // 0x007A0450

// 0x006CAC10
void __cdecl sub_006CAC10_InitializeHorizontalPosition()
{
    gnTextLeft = (gnScreenWidth_0071146C - 325) / 2;
}
