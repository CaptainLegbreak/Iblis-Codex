struct D2ActiveRoomStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask); // 0x0064E260
extern int gnValue_0072A348;                                                                                // 0x0072A348

// 0x004CC250
static __forceinline int sub_004CC250_HasSlotValue(int* pSlots, int nValue)
{
    for (int i = 0; i < 10; i++)
    {
        const int nSlot = pSlots[i];
        if (!nSlot)
        {
            return 0;
        }
        if (nSlot == nValue)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004CC800
static int __stdcall sub_004CC800_CheckDistanceAndLineOfSight(int nMaxDistanceSq, int nX, int nY, D2ActiveRoomStrc* pRoom, int nOffsetX, int nOffsetY)
{
    if (!pRoom)
    {
        return 0;
    }

    if (nOffsetX * nOffsetX + nOffsetY * nOffsetY > nMaxDistanceSq)
    {
        return 0;
    }

    D2CoordStrc begin;
    begin.nX = nX;
    begin.nY = nY;
    D2CoordStrc end;
    end.nX = nX + nOffsetX;
    end.nY = nY + nOffsetY;
    return !COLLISION_RayTrace(pRoom, &begin, &end, 4);
}

// 0x004CCF20
void __fastcall sub_004CCF20_SetValue(int nValue)
{
    gnValue_0072A348 = nValue;
}

int __fastcall sub_M119_Emit_004CC250(int* pSlots, int nValue)
{
    return sub_004CC250_HasSlotValue(pSlots, nValue + 1);
}

int __stdcall sub_M119_Emit_004CC800(D2ActiveRoomStrc* pRoom, int nOffsetX, int nOffsetY, int nMaxDistanceSq, int nX, int nY)
{
    return sub_004CC800_CheckDistanceAndLineOfSight(nMaxDistanceSq, nX, nY, pRoom, nOffsetX, nOffsetY);
}

#include "gen/data/Source/D2Client/004CC250_sub_004CC250_HasSlotValue.inc"
