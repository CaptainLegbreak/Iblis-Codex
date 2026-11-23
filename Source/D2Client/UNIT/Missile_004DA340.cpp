#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGfx.h"
#include "D2ClientTypes.h"

D2GfxMotionStrc* __fastcall GFX_GetGfxMotion(D2UnitStrc* pUnit); // 0x0046F060

// 0x004DA340
void __fastcall MISSILE_ClearMotionFlagTwo(D2UnitStrc* pMissile)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pMissile);
    if (pMotion)
        pMotion->dwFlags &= ~2;
}
