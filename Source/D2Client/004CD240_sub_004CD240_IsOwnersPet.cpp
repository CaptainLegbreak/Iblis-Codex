struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemPool;
    int dwUnitId;
};

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                       // 0x004639D0
int __fastcall sub_00479150_FindRosterIndex(int nUnitId);                                                   // 0x00479150

// 0x004CD240
int __fastcall sub_004CD240_IsOwnersPet(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (pOwner->dwUnitType != 0)
    {
        return 0;
    }

    if (pUnit->dwUnitType != 1)
    {
        return 0;
    }

    const int nRosterId = sub_00479150_FindRosterIndex(pUnit->dwUnitId);
    const int nOwnerId = !pOwner ? -1 : pOwner->dwUnitId;
    return nRosterId == nOwnerId;
}
