extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2ClientEntryStrc
{
    char unk0x00[0x08];
    int nState;
};

struct D2RosterPetStrc
{
    int nClassId;
    int nType;
    int dwUnitId;
    int dwOwnerId;
    int unk0x10[5];
    D2ClientEntryStrc tEntry;
    D2RosterPetStrc* pNext;
};

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
unsigned int __fastcall sub_004DC440(int nUnitId1, int nUnitId2, unsigned int nFlags);              // 0x004DC440

D2RosterPetStrc* gpRosterPets_007BB5BC;                                                                     // 0x007BB5BC

// 0x00478E40
D2ClientEntryStrc* __fastcall sub_00478E40_FindEntry(int nKey)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nKey)
            return &pPet->tEntry;
    }
    return 0;
}

// 0x00478EE0
int __fastcall sub_00478EE0_CountPets(D2UnitStrc* pOwner, int nType)
{
    D2RosterPetStrc* pPet = gpRosterPets_007BB5BC;
    const int nOwnerId = !pOwner ? -1 : pOwner->dwUnitId;
    int nCount = 0;
    for (; pPet; pPet = pPet->pNext)
    {
        if (pPet->nType == nType && pPet->dwOwnerId == nOwnerId)
            ++nCount;
    }
    return nCount;
}

// 0x00478F70
int __fastcall sub_00478F70_HasPets(D2UnitStrc* pOwner)
{
    D2RosterPetStrc* pPet = gpRosterPets_007BB5BC;
    const int nOwnerId = !pOwner ? -1 : pOwner->dwUnitId;
    for (; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwOwnerId == nOwnerId)
            return 1;
    }
    return 0;
}

// 0x00479120
int __fastcall sub_00479120_GetHirelingClassId(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
            return pPet->nClassId;
    }
    return 0;
}

// 0x00479150
int __fastcall sub_00479150_FindRosterIndex(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
            return pPet->dwOwnerId;
    }
    return -1;
}

// 0x004791B0
int __fastcall sub_004791B0_IsOwnedByPlayer(D2UnitStrc* pUnit)
{
    const int nOwnerId = sub_00479150_FindRosterIndex(!pUnit ? -1 : pUnit->dwUnitId);
    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nPlayerId = pPlayer ? pPlayer->dwUnitId : -1;
    D2_ASSERT(nPlayerId != -1, 0x225);
    if (nOwnerId != -1)
        return sub_004DC440(nOwnerId, nPlayerId, 8);

    return 1;
}
