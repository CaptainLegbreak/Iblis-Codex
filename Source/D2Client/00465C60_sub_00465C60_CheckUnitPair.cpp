struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x80];
    int unk0x94;
    int dwOwnerId;
    char unk0x9C[0x28];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __fastcall sub_00464EC0_CheckSkillOwner(D2UnitStrc* pUnit, D2UnitStrc* pTarget);                        // 0x00464EC0
int __fastcall sub_00479150_FindRosterIndex(int nUnitId);                                                   // 0x00479150
int __fastcall sub_0047A4F0_TestFlag1(int nUnitId1, int nUnitId2);                                          // 0x0047A4F0
unsigned int __fastcall sub_004DC440(int nUnitId1, int nUnitId2, unsigned int nFlags);              // 0x004DC440
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall STATLIST_AreUnitsAligned(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                             // 0x00650D70

static __forceinline int UNITS_IsDeadOrDying(D2UnitStrc* pUnit)
{
    if (pUnit->dwFlags & 0x10000)
    {
        return 1;
    }

    const int nMode = pUnit->dwAnimMode;
    switch (pUnit->dwUnitType)
    {
    case 0:
        if (nMode == 0 || nMode == 0x11)
        {
            return 1;
        }
        break;

    case 1:
        if (nMode == 0 || nMode == 0x0C)
        {
            return 1;
        }
        break;
    }

    return 0;
}

// 0x00465C60
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther)
{
    int nUnitType;
    int nUnitId;
    if (!pUnit)
    {
        nUnitType = 6;
        nUnitId = -1;
    }
    else
    {
        nUnitType = pUnit->dwUnitType;
        nUnitId = pUnit->dwUnitId;
    }

    int nOtherType = !pOther ? 6 : pOther->dwUnitType;
    int nOtherId = !pOther ? -1 : pOther->dwUnitId;

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if ((!pOther ? 6 : pOther->dwUnitType) == 0 && UNITS_IsDeadOrDying(pOther) && !sub_0047A4F0_TestFlag1(nUnitId, pOther->dwUnitId))
        {
            return 0;
        }

        if (pUnit && pUnit->dwUnitType == 0 && pOther && pOther->dwUnitType == 1
            && sub_00479150_FindRosterIndex(pOther->dwUnitId) != -1 && !sub_00464EC0_CheckSkillOwner(pUnit, pOther))
        {
            return 0;
        }

        return 1;
    }

    if (nUnitType == 1)
    {
        const int nOwnerId = sub_00479150_FindRosterIndex(nUnitId);
        if (nOwnerId != -1)
        {
            nUnitType = 0;
            nUnitId = nOwnerId;
        }

        int bUnitOwned = 0;
        if (pUnit)
        {
            bUnitOwned = (pUnit->dwFlagEx >> 10) & 1;
        }

        if (bUnitOwned && !pOther->unk0x94)
        {
            nUnitType = 0;
            nUnitId = pUnit->dwOwnerId;
        }
    }

    if (nOtherType == 1)
    {
        const int nOwnerId = sub_00479150_FindRosterIndex(nOtherId);
        if (nOwnerId != -1)
        {
            nOtherType = 0;
            nOtherId = nOwnerId;
        }

        int bOtherOwned = 0;
        if (pOther)
        {
            bOtherOwned = (pOther->dwFlagEx >> 10) & 1;
        }

        if (bOtherOwned && !pOther->unk0x94)
        {
            nOtherId = pOther->dwOwnerId;
            nOtherType = 0;
        }
    }

    if (nUnitType == nOtherType && nUnitId == nOtherId)
    {
        return 0;
    }

    if (nUnitType == 0 && nOtherType == 0)
    {
        if (pOther && pOther->dwUnitType == 0 && sub_00464820_IsDeadOrDying(pOther) && sub_0047A4F0_TestFlag1(nUnitId, pOther->dwUnitId))
        {
            return 1;
        }

        return sub_004DC440(nUnitId, nOtherId, 8);
    }

    if (nOtherType == 1)
    {
        if (sub_004638A0_CheckMonStats2Flag(!pOther ? -1 : pOther->dwClassId, 4))
        {
            return 1;
        }

        if (sub_004638A0_CheckMonStats2Flag(!pOther ? -1 : pOther->dwClassId, 5))
        {
            return 0;
        }
    }

    if (nUnitType == 0 && (nOtherType == 4 || nOtherType == 2))
    {
        return 1;
    }

    return !STATLIST_AreUnitsAligned(pUnit, pOther);
}
