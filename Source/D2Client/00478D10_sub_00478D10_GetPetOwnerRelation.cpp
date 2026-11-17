struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2RosterPetStrc
{
    int nClassId;
    int nType;
    int dwUnitId;
    int dwOwnerId;
    char unk0x10[0x30 - 0x10];
    D2RosterPetStrc* pNext;
};

struct D2StoredUnitRecordStrc;

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2StoredUnitRecordStrc* __fastcall sub_00479BB0_FindRosterUnit(int nUnitId);                               // 0x00479BB0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);                       // 0x00479BC0

extern D2RosterPetStrc* gpRosterPets_007BB5BC;                                                              // 0x007BB5BC

// 0x00478D10
int __fastcall sub_00478D10_GetPetOwnerRelation(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            D2UnitStrc* pPlayer = sub_00463DD0();
            const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
            if (pPet->dwOwnerId == nPlayerId)
            {
                return 1;
            }

            const unsigned short nPartyId = sub_00479BC0_GetEntryIndex(sub_00479BB0_FindRosterUnit(nPlayerId));
            if (nPartyId == 0xFFFF || nPartyId != sub_00479BC0_GetEntryIndex(sub_00479BB0_FindRosterUnit(pPet->dwOwnerId)))
            {
                break;
            }
            return 2;
        }
    }
    return 0;
}
