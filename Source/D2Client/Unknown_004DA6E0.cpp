#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGfx.h"
#include "D2ClientTypes.h"

D2GfxMotionStrc* __fastcall GFX_GetGfxMotion(D2UnitStrc* pUnit); // 0x0046F060

// 0x004DA6E0
void __fastcall MISSILE_SetMotionFlagMask(D2UnitStrc* pUnit, int bSet)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bSet)
            pMotion->dwFlags |= 0x20;
        else
            pMotion->dwFlags &= ~0x20;
    }
}
