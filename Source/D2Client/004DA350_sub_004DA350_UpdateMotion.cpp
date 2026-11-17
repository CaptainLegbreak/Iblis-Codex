struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
};

struct D2GfxMotionStrc
{
    unsigned int dwFlags;
    int nX;
    int nY;
    int nZ;
    int nVelX;
    int nVelY;
    int nVelZ;
    int nAccX;
    int nAccY;
    int nAccZ;
    int nTargetX;
    int nTargetY;
    int nTargetZ;
    int nClientX;
    int nClientY;
    int nClientZ;
    int nBounces;
    int nBouncePercent;
    int nFrames;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit);                                   // 0x0046F060
void __fastcall sub_004706E0_GetUnitCelOffsets(D2UnitStrc* pUnit, int nComponent, int* pOffsetX, int* pOffsetY); // 0x004706E0
extern "C" int __stdcall sub_004DA0B0_GetGfxOffsetX(D2UnitStrc* pUnit);                                     // 0x004DA0B0
int __stdcall sub_004DA0F0_GetUnitGfxOffsetZ(D2UnitStrc* pUnit);                                            // 0x004DA0F0
void __stdcall DUNGEON_GameToClientCoords(int* pX, int* pY);                                                // 0x00643290
void __stdcall DUNGEON_ClientToGameSubtileCoords(int* pX, int* pY);                                         // 0x00643510

// 0x004DA350
void __stdcall sub_004DA350_UpdateMotion(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (!pMotion || pMotion->dwFlags & 1)
    {
        return;
    }

    pMotion->nX += pMotion->nVelX;
    pMotion->nVelX += pMotion->nAccX;
    pMotion->nY += pMotion->nVelY;
    pMotion->nVelY += pMotion->nAccY;
    pMotion->nZ += pMotion->nVelZ;
    pMotion->nVelZ += pMotion->nAccZ;
    int* pX = &pMotion->nX;
    int* pY = &pMotion->nY;

    if (pMotion->dwFlags & 2)
    {
        if (pMotion->nFrames)
        {
            --pMotion->nFrames;
        }
        else
        {
            pMotion->dwFlags |= 1;
            pMotion->nX = 0;
            pMotion->nY = 0;
        }
    }

    unsigned int dwFlags = pMotion->dwFlags;
    if (dwFlags & 4)
    {
        if ((pMotion->nZ >> 11) <= pMotion->nTargetZ)
        {
            pMotion->nVelZ = pMotion->nBouncePercent * pMotion->nVelZ / -100;
            pMotion->nZ = pMotion->nTargetZ;
            if (pMotion->nBounces)
            {
                --pMotion->nBounces;
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
            pMotion->nX = pMotion->nClientX;
            pMotion->nY = pMotion->nClientY;
            DUNGEON_ClientToGameSubtileCoords(pX, pY);
            pMotion->nZ = -(pMotion->nClientZ << 11);
        }
    }
    else if (!(dwFlags & 0x20) && (pMotion->nX >> 11) <= pMotion->nTargetX && (pMotion->nY >> 11) <= pMotion->nTargetY && (pMotion->nZ >> 11) <= pMotion->nTargetZ)
    {
        pMotion->nX = pMotion->nTargetX << 11;
        pMotion->nY = pMotion->nTargetY << 11;
        pMotion->nZ = pMotion->nTargetZ << 11;
        pMotion->dwFlags = dwFlags | 1;
    }
    else if ((dwFlags & 0x20) && (pMotion->nX >> 11) >= pMotion->nTargetX && (pMotion->nY >> 11) >= pMotion->nTargetY && (pMotion->nZ >> 11) >= pMotion->nTargetZ)
    {
        pMotion->nX = pMotion->nTargetX << 11;
        pMotion->nY = pMotion->nTargetY << 11;
        pMotion->nZ = pMotion->nTargetZ << 11;
        pMotion->dwFlags = dwFlags | 1;
    }

    if (!(pMotion->dwFlags & 0x10))
    {
        pMotion->nClientX = pMotion->nX >> 11;
        pMotion->nClientY = pMotion->nY >> 11;
        DUNGEON_GameToClientCoords(&pMotion->nClientX, &pMotion->nClientY);
        pMotion->nClientZ = -(pMotion->nZ >> 11);
    }
}
