struct D2StoredUnitRecordStrc
{
    char unk0x00[0x20];
    unsigned short wValue;
};

struct D2RosterPetStrc
{
    int nClassId;
    int nType;
    int dwUnitId;
    int dwOwnerId;
    char unk0x10[0xC];
    int nLife;
    char unk0x20[0x10];
    D2RosterPetStrc* pNext;
};

struct D2RosterGroupStrc
{
    int unk0x00;
    D2StoredUnitRecordStrc* pFirst;
    D2RosterGroupStrc* pNext;
};

extern D2RosterPetStrc* gpRosterPets_007BB5BC;                                                              // 0x007BB5BC
D2RosterGroupStrc* gpRosterGroups_007BB5C8;                                                                 // 0x007BB5C8
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

// 0x00479080
int __fastcall sub_00479080_GetPetLife(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            return pPet->nLife;
        }
    }

    return 0;
}

// 0x00479180
int __fastcall sub_00479180_GetPetType(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            return pPet->nType;
        }
    }

    return 0;
}

// 0x004797C0
void __cdecl sub_004797C0_FreeRosterGroups()
{
    D2RosterGroupStrc* pGroup = gpRosterGroups_007BB5C8;
    while (pGroup)
    {
        D2RosterGroupStrc* pNext = pGroup->pNext;
        FOG_Free(pGroup, ".\\GAME\\Roster.cpp", 559, 0);
        pGroup = pNext;
    }

    gpRosterGroups_007BB5C8 = 0;
}

// 0x00479B90
int __fastcall sub_00479B90(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        return pEntry->wValue;
    }

    return 0;
}
