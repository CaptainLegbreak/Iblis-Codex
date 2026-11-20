#include "D2Client.h"
#include "D2ClientGfx.h"

D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit);                                   // 0x0046F060

// 0x004DA620
void __fastcall sub_004DA620_SetMotionFlag10(D2UnitStrc* pUnit, int bSet)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bSet)
            pMotion->dwFlags |= 0x10;
        else
            pMotion->dwFlags &= ~0x10;
    }
}
