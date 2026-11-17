struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2RosterPetStrc
{
    int nClassId;
    int nType;
    int dwUnitId;
    int dwOwnerId;
    char unk0x10[0x20];
    D2RosterPetStrc* pNext;
};

int __stdcall STATLIST_AreUnitsAligned(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                             // 0x00650D70
int __fastcall sub_0047A070_TestPvpFlag8(int nUnitId1, int nUnitId2);                                       // 0x0047A070

extern D2RosterPetStrc* gpRosterPets_007BB5BC;                                                              // 0x007BB5BC

static __forceinline D2RosterPetStrc* PETS_FindRosterPetInl(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            return pPet;
        }
    }

    return 0;
}

// 0x00478E70
int __fastcall sub_00478E70_IsPetFriendly(D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
{
    D2RosterPetStrc* pPet = PETS_FindRosterPetInl(!pUnit ? -1 : pUnit->dwUnitId);
    if (!pUnit || !pPlayer)
    {
        return 1;
    }

    const int nPlayerId = pPlayer->dwUnitId;
    if (!pPet)
    {
        const int nType = pPlayer->dwUnitType;
        if (nType == 1 && pUnit->dwUnitType == nType && STATLIST_AreUnitsAligned(pPlayer, pUnit))
        {
            return 0;
        }

        return 1;
    }

    const int nOwnerId = pPet->dwOwnerId;
    if (nOwnerId == nPlayerId)
    {
        return 0;
    }

    return sub_0047A070_TestPvpFlag8(nPlayerId, nOwnerId);
}
