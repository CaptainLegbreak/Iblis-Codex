#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGfx.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit);                                   // 0x0046F060
void __fastcall sub_004706E0_GetUnitCelOffsets(D2UnitStrc* pUnit, int nComponent, int* pOffsetX, int* pOffsetY); // 0x004706E0
extern "C" int __stdcall sub_004DA0B0_GetGfxOffsetX(D2UnitStrc* pUnit);                                     // 0x004DA0B0
void __stdcall DUNGEON_GameToClientCoords(int* pX, int* pY);                                                // 0x00643290

// 0x004DA350
void __stdcall sub_004DA350_UpdateMotion(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (!pMotion || pMotion->dwFlags & 1)
    {
        return;
    }

    pMotion->tA.nX += pMotion->tB.nX;
    pMotion->tB.nX += pMotion->tD.nX;
    pMotion->tA.nY += pMotion->tB.nY;
    pMotion->tB.nY += pMotion->tD.nY;
    pMotion->tA.nZ += pMotion->tB.nZ;
    pMotion->tB.nZ += pMotion->tD.nZ;
    int* pX = &pMotion->tA.nX;
    int* pY = &pMotion->tA.nY;

    if (pMotion->dwFlags & 2)
    {
        if (pMotion->nFrames)
        {
            --pMotion->nFrames;
        }
        else
        {
            pMotion->dwFlags |= 1;
            pMotion->tA.nX = 0;
            pMotion->tA.nY = 0;
        }
    }

    unsigned int dwFlags = pMotion->dwFlags;
    if (dwFlags & 4)
    {
        if ((pMotion->tA.nZ >> 11) <= pMotion->tC.nZ)
        {
            pMotion->tB.nZ = pMotion->nParam1 * pMotion->tB.nZ / -100;
            pMotion->tA.nZ = pMotion->tC.nZ;
            if (pMotion->nParam0)
            {
                --pMotion->nParam0;
            }
            else
            {
                pMotion->dwFlags = dwFlags | 1;
            }
        }
    }
    else if (dwFlags & 0x10)
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
        if (pOwner)
        {
            int nOffsetX = 0;
            int nOffsetY = 0;
            int nComponent = 8;
            switch (!pUnit ? 6 : pUnit->dwUnitType)
            {
            case 3:
                D2_ASSERT(pOwner->dwUnitType == 1, 425);
                if (!pOwner->dwAnimMode || pOwner->dwAnimMode == 12)
                {
                    return;
                }
            case 1:
                nComponent = 14;
                break;
            }

            sub_004706E0_GetUnitCelOffsets(pOwner, nComponent, &nOffsetX, &nOffsetY);
            pMotion->nClientX = nOffsetX;
            pMotion->nClientZ = nOffsetY;
            if (pUnit && pUnit->dwUnitType == 3)
            {
                pMotion->nClientZ += 10;
            }
            pMotion->nClientX += sub_004DA0B0_GetGfxOffsetX(pOwner);
            pMotion->nClientZ += sub_004DA0F0_GetUnitGfxOffsetZ(pOwner);
            pMotion->tA.nX = pMotion->nClientX;
            pMotion->tA.nY = pMotion->nClientY;
            DUNGEON_ClientToGameSubtileCoords(pX, pY);
            pMotion->tA.nZ = -(pMotion->nClientZ << 11);
        }
    }
    else if (!(dwFlags & 0x20) && (pMotion->tA.nX >> 11) <= pMotion->tC.nX && (pMotion->tA.nY >> 11) <= pMotion->tC.nY && (pMotion->tA.nZ >> 11) <= pMotion->tC.nZ)
    {
        pMotion->tA.nX = pMotion->tC.nX << 11;
        pMotion->tA.nY = pMotion->tC.nY << 11;
        pMotion->tA.nZ = pMotion->tC.nZ << 11;
        pMotion->dwFlags = dwFlags | 1;
    }
    else if ((dwFlags & 0x20) && (pMotion->tA.nX >> 11) >= pMotion->tC.nX && (pMotion->tA.nY >> 11) >= pMotion->tC.nY && (pMotion->tA.nZ >> 11) >= pMotion->tC.nZ)
    {
        pMotion->tA.nX = pMotion->tC.nX << 11;
        pMotion->tA.nY = pMotion->tC.nY << 11;
        pMotion->tA.nZ = pMotion->tC.nZ << 11;
        pMotion->dwFlags = dwFlags | 1;
    }

    if (!(pMotion->dwFlags & 0x10))
    {
        pMotion->nClientX = pMotion->tA.nX >> 11;
        pMotion->nClientY = pMotion->tA.nY >> 11;
        DUNGEON_GameToClientCoords(&pMotion->nClientX, &pMotion->nClientY);
        pMotion->nClientZ = -(pMotion->tA.nZ >> 11);
    }
}
