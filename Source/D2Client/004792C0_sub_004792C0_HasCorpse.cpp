struct D2RosterCorpseStrc
{
    unsigned int dwCorpseId;
    D2RosterCorpseStrc* pPrev;
};

struct D2RosterUnitStrc
{
    char unk0x00[0x38];
    D2RosterCorpseStrc* pCorpse;
    char unk0x3C[0x08];
    unsigned short wUnk0x44;
    unsigned char unk0x46[4];
    unsigned char unk0x4A[4];
};

struct D2StoredUnitRecordStrc;

struct D2RosterGroupStrc
{
    unsigned short wId;
    unsigned short wUnk0x02;
    D2StoredUnitRecordStrc* pFirst;
    D2RosterGroupStrc* pNext;
};

extern D2StoredUnitRecordStrc* gpStoredUnits_007BB5C0;                                                      // 0x007BB5C0
extern D2RosterGroupStrc* gpRosterGroups_007BB5C8;                                                          // 0x007BB5C8
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
D2StoredUnitRecordStrc* __stdcall sub_004795F0_SortRosterByName(D2StoredUnitRecordStrc* pList);             // 0x004795F0

// 0x004792C0
static __forceinline int sub_004792C0_HasCorpse(D2RosterUnitStrc* pRosterUnit, unsigned int dwCorpseId)
{
    for (D2RosterCorpseStrc* pCorpse = pRosterUnit->pCorpse; pCorpse; pCorpse = pCorpse->pPrev)
    {
        if (pCorpse->dwCorpseId == dwCorpseId)
        {
            return 1;
        }
    }
    return 0;
}

// 0x00479470
static __forceinline void sub_00479470_FreeCorpses(D2RosterUnitStrc* pRosterUnit)
{
    D2RosterCorpseStrc* pCorpse = pRosterUnit->pCorpse;
    while (pCorpse)
    {
        D2RosterCorpseStrc* pPrev = pCorpse->pPrev;
        FOG_Free(pCorpse, ".\\GAME\\Roster.cpp", 0x110, 0);
        pCorpse = pPrev;
    }
    pRosterUnit->pCorpse = 0;
}

// 0x004796B0
void __cdecl sub_004796B0_SortMainListByName()
{
    gpStoredUnits_007BB5C0 = sub_004795F0_SortRosterByName(gpStoredUnits_007BB5C0);
}

// 0x00479750
D2RosterGroupStrc* __fastcall sub_00479750_FindGroup(unsigned short wId)
{
    for (D2RosterGroupStrc* pGroup = gpRosterGroups_007BB5C8; pGroup; pGroup = pGroup->pNext)
    {
        if (pGroup->wId == wId)
        {
            return pGroup;
        }
    }
    return 0;
}

// 0x00479B50
unsigned short __fastcall sub_00479B50_GetWord44(D2RosterUnitStrc* pRosterUnit)
{
    if (!pRosterUnit)
    {
        return 0;
    }
    return pRosterUnit->wUnk0x44;
}

// 0x00479B60
unsigned char* __fastcall sub_00479B60_GetField46(D2RosterUnitStrc* pRosterUnit)
{
    if (!pRosterUnit)
    {
        return 0;
    }
    return pRosterUnit->unk0x46;
}

// 0x00479B70
unsigned char* __fastcall sub_00479B70_GetField4A(D2RosterUnitStrc* pRosterUnit)
{
    if (!pRosterUnit)
    {
        return 0;
    }
    return pRosterUnit->unk0x4A;
}

int __fastcall sub_M119_Emit_004792C0(D2RosterUnitStrc* pRosterUnit, unsigned int dwCorpseId)
{
    if (sub_004792C0_HasCorpse(pRosterUnit, dwCorpseId + 1))
    {
        sub_00479470_FreeCorpses(pRosterUnit);
    }
    return 1;
}
