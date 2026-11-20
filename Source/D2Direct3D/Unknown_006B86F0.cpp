#include "D2Direct3D.h"

int __stdcall sub_005FDEA0(void*, int, int); // 0x005FDEA0
void __fastcall sub_006B1F40_SetBlendMode(int); // 0x006B1F40
void __fastcall sub_006B2030_SetFilterMode(int); // 0x006B2030
int __cdecl sub_006B77A0_GetBlendedShadows(); // 0x006B77A0
int __cdecl sub_006B9830_GetPerspective(); // 0x006B9830
int __fastcall sub_006B83A0_DrawPerspective(void*, int, int, int, unsigned char, int); // 0x006B83A0
int __fastcall sub_006B8220_DrawFlat(void*, int, int, int, unsigned char, int); // 0x006B8220

// 0x006B86F0
int __fastcall sub_006B86F0_DrawShadow(void* sprite, int x, int y, int mode, int extra)
{
    int nResult = 0;
    if (sub_005FDEA0(sprite, 1, 0))
    {
        unsigned char alpha = 255;
        sub_006B1EA0_SetMode(1);
        if (sub_006B77A0_GetBlendedShadows())
        {
            sub_006B1F40_SetBlendMode(4);
            alpha = 192;
        }
        else
        {
            sub_006B1F40_SetBlendMode(1);
        }
        sub_006B2030_SetFilterMode(1);
        if (sub_006B9830_GetPerspective())
        {
            nResult = sub_006B83A0_DrawPerspective(sprite, x, y, mode, alpha, extra);
        }
        else
        {
            nResult = sub_006B8220_DrawFlat(sprite, x, y, mode, alpha, extra);
        }
    }
    return nResult;
}
