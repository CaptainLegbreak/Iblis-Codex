#include "D2Direct3D.h"

int __stdcall D2CMPTileValidate(void*, int, int); // 0x005FDEA0
void __fastcall D3DCORE_SetAlphaBlendMode(int); // 0x006B1F40
void __fastcall D3DCORE_SetTextureFilterMode(int); // 0x006B2030
int __cdecl sub_006B77A0_GetBlendedShadows(); // 0x006B77A0
int __cdecl sub_006B9830_GetPerspective(); // 0x006B9830
int __fastcall sub_006B83A0_DrawPerspective(void*, int, int, int, unsigned char, int); // 0x006B83A0
int __fastcall sub_006B8220_DrawFlat(void*, int, int, int, unsigned char, int); // 0x006B8220

// 0x006B86F0
int __fastcall sub_006B86F0_DrawShadow(void* sprite, int x, int y, int mode, int extra)
{
    int nResult = 0;
    if (D2CMPTileValidate(sprite, 1, 0))
    {
        unsigned char alpha = 255;
        sub_006B1EA0_SetMode(1);
        if (sub_006B77A0_GetBlendedShadows())
        {
            D3DCORE_SetAlphaBlendMode(4);
            alpha = 192;
        }
        else
        {
            D3DCORE_SetAlphaBlendMode(1);
        }
        D3DCORE_SetTextureFilterMode(1);
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
