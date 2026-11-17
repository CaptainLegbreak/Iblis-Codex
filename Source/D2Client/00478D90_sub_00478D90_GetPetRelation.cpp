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

struct D2PetTypeTxt
{
    char unk0x00[0x04];
    unsigned char nFlags[4];
    char unk0x08[0xE0 - 0x08];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBE8];
    D2PetTypeTxt* pPetTypeTxt;
    void* pPetTypeLinker;
    int nPetTypeTxtRecordCount;
};

struct D2StoredUnitRecordStrc;

#define PETTYPE_FLAG_PARTY 4

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2StoredUnitRecordStrc* __fastcall sub_00479BB0_FindRosterUnit(int nUnitId);                               // 0x00479BB0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);                       // 0x00479BC0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2RosterPetStrc* gpRosterPets_007BB5BC;                                                              // 0x007BB5BC

inline D2PetTypeTxt* PETTXT_GetRecordInl(int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &sgptDataTables->pPetTypeTxt[nPetType];
    }
    return 0;
}

// 0x00478D90
int __fastcall sub_00478D90_GetPetRelation(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            D2PetTypeTxt* pPetTypeTxtRecord = PETTXT_GetRecordInl(pPet->nType);
            if (!pPetTypeTxtRecord)
            {
                return 3;
            }

            if (!(pPetTypeTxtRecord->nFlags[PETTYPE_FLAG_PARTY >> 3] & gdwBitMasks[PETTYPE_FLAG_PARTY & 7]))
            {
                return 3;
            }

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
