#include "D2Glide.h"

extern D2GfxSettingsStrc* gpGfxSettings; // 0x007C9148

// 0x0050BF40
int __cdecl sub_0050BF40_GlideGetBlendedShadows()
{
    return gpGfxSettings->bBlendedShadows;
}
