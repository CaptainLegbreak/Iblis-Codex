#include "D2Glide.h"

extern int* gpnPerspectiveTable_00880B6C; // 0x00880B6C

// 0x0050DC80
void __cdecl sub_0050DC80_AllocPerspectiveTable()
{
    gpnPerspectiveTable_00880B6C = (int*)FOG_Alloc(0x8000, ".\\Src\\glPerspective.cpp", 0x38, 0);
}

// 0x0050DCA0
void __cdecl sub_0050DCA0_FreePerspectiveTable()
{
    if (gpnPerspectiveTable_00880B6C)
    {
        FOG_Free(gpnPerspectiveTable_00880B6C, ".\\Src\\glPerspective.cpp", 63, 0);
        gpnPerspectiveTable_00880B6C = 0;
    }
}
