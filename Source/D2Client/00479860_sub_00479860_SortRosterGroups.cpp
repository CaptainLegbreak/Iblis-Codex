struct D2StoredUnitRecordStrc;

struct D2RosterGroupStrc
{
    unsigned short wPartyId;
    unsigned short unk0x02;
    D2StoredUnitRecordStrc* pFirst;
    D2RosterGroupStrc* pNext;
};

static D2RosterGroupStrc* gpRosterGroups_007BB5C8;                                                          // 0x007BB5C8

// 0x00479860
void __cdecl sub_00479860_SortRosterGroups()
{
    D2RosterGroupStrc* pList = gpRosterGroups_007BB5C8;
    D2RosterGroupStrc* pSorted = 0;
    D2RosterGroupStrc* pCurrent;
    while ((pCurrent = pList) != 0)
    {
        pList = pList->pNext;
        D2RosterGroupStrc* pPrevious = 0;
        for (D2RosterGroupStrc* pGroup = pSorted; pGroup; pGroup = pGroup->pNext)
        {
            if (pCurrent->wPartyId < pGroup->wPartyId)
            {
                break;
            }
            pPrevious = pGroup;
        }
        if (pPrevious)
        {
            pCurrent->pNext = pPrevious->pNext;
            pPrevious->pNext = pCurrent;
        }
        else
        {
            pCurrent->pNext = pSorted;
            pSorted = pCurrent;
        }
    }
    gpRosterGroups_007BB5C8 = pSorted;
}
