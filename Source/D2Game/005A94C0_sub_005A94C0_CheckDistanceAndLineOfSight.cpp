struct D2ActiveRoomStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask); // 0x0064E260

// 0x005A94C0
static int __stdcall sub_005A94C0_CheckDistanceAndLineOfSight(int nMaxDistanceSq, int nX, int nY, D2ActiveRoomStrc* pRoom, int nOffsetX, int nOffsetY)
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

int __stdcall sub_K13_Emit_005A94C0(D2ActiveRoomStrc* pRoom, int nOffsetX, int nOffsetY, int nMaxDistanceSq, int nX, int nY)
{
    return sub_005A94C0_CheckDistanceAndLineOfSight(nMaxDistanceSq, nX, nY, pRoom, nOffsetX, nOffsetY);
}
