struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0xB0];
    unsigned int dwFlags;
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nFlags[4];
};

struct D2MissilesTxt
{
    char unk0x00[0x04];
    unsigned char nFlags[4];
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

extern unsigned int gdwBitMasks[]; // 0x006CE268

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0
int __fastcall sub_004C5910(D2UnitStrc* pUnitA, D2UnitStrc* pUnitB); // 0x004C5910
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster); // 0x0063E990
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
int __stdcall MONSTERS_IsPrimeEvil(D2UnitStrc* pMonster); // 0x0063EDC0
int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask); // 0x0064E260

static __forceinline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x004C5960
int __fastcall sub_004C5960_CanScanUnit(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nFlags)
{
    const int nType = pTarget ? pTarget->dwUnitType : 6;
    switch (nType)
    {
    case 0:
    {
        if (!(nFlags & 1))
        {
            return 0;
        }
        const int nMode = pTarget->dwAnimMode;
        if (nFlags & 0x1000)
        {
            if (nMode != 0x11)
            {
                return 0;
            }
        }
        else
        {
            if (nMode == 0x11 || nMode == 0)
            {
                return 0;
            }
        }
        break;
    }
    case 1:
    {
        if (!(nFlags & 2))
        {
            return 0;
        }
        const int nMode = pTarget->dwAnimMode;
        if (nFlags & 0x1000)
        {
            if (nMode != 0x0C)
            {
                return 0;
            }
        }
        else
        {
            if (nMode == 0x0C || nMode == 0)
            {
                return 0;
            }
        }

        if (nFlags & 4 && !MONSTERS_IsUndead(pTarget)
            || nFlags & 0x4000 && MONSTERS_IsBoss(0, pTarget)
            || nFlags & 0x40000 && MONSTERS_IsPrimeEvil(pTarget))
        {
            return 0;
        }
        break;
    }
    case 2:
    {
        if (!(nFlags & 0x10))
        {
            return 0;
        }
        break;
    }
    case 3:
    {
        if (!(nFlags & 8))
        {
            return 0;
        }
        D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pTarget->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->nFlags[0] & gdwBitMasks[1])
        {
            return 0;
        }
        break;
    }
    case 4:
    {
        if (!(nFlags & 0x20))
        {
            return 0;
        }
        break;
    }
    default:
        return 0;
    }

    if (nFlags & 0x80 && !UNIT_HasFlag(pTarget, 4))
    {
        return 0;
    }
    if (nFlags & 0x400 && !UNIT_HasFlag(pTarget, 8))
    {
        return 0;
    }
    if (nFlags & 0x100 && DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    if (nFlags & 0x10000)
    {
        if (!sub_004C5910(pUnit, pTarget))
        {
            return 0;
        }
        if (pTarget->dwUnitType == 1)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
            if (!pMonStatsTxtRecord || pMonStatsTxtRecord->nFlags[1] & gdwBitMasks[0])
            {
                return 0;
            }
        }
    }
    if (nFlags & 0x8000 && !sub_00465C60_CheckUnitPair(pUnit, pTarget))
    {
        return 0;
    }
    if (nFlags & 0x20000 && !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        return 0;
    }
    if (nFlags & 0x80000 && STATES_CheckState(pTarget, 0x56))
    {
        return 0;
    }

    if (nFlags & 0x200)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom || !UNITS_GetRoom(pTarget))
        {
            return 0;
        }
        D2CoordStrc coords;
        coords.nX = CLIENTS_GetUnitX(pUnit);
        coords.nY = CLIENTS_GetUnitY(pUnit);
        D2CoordStrc targetCoords;
        targetCoords.nX = CLIENTS_GetUnitX(pTarget);
        targetCoords.nY = CLIENTS_GetUnitY(pTarget);
        if (COLLISION_RayTrace(pRoom, &coords, &targetCoords, 4))
        {
            return 0;
        }
    }
    return 1;
}
