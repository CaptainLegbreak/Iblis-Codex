struct D2RosterPetNodeStrc
{
    int nValue;
    int nType;
    int nKey;
    int nArg;
    int unk0x10[3];
    int nInit;
    int nClear;
    int unk0x24[3];
    D2RosterPetNodeStrc* pNext;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
extern D2RosterPetNodeStrc* gpRosterPets_007BB5BC;                                                          // 0x007BB5BC

// 0x00478A90
D2RosterPetNodeStrc* __fastcall sub_00478A90_FindRosterPet(int nKey)
{
    for (D2RosterPetNodeStrc* pNode = gpRosterPets_007BB5BC; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            return pNode;
        }
    }
    return 0;
}

// 0x00478C90
void __fastcall sub_00478C90_DropPetEntry(int nKey)
{
    D2RosterPetNodeStrc* pPrev = 0;
    for (D2RosterPetNodeStrc* pNode = gpRosterPets_007BB5BC; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            if (pNode->nType == 7)
            {
                D2UnitStrc* pPlayer = sub_00463DD0();
                if (pNode->nArg == (!pPlayer ? -1 : pPlayer->dwUnitId))
                {
                    pNode->nClear = 1;
                    return;
                }
            }
            if (pPrev)
                pPrev->pNext = pNode->pNext;
            else
                gpRosterPets_007BB5BC = pNode->pNext;
            FOG_Free(pNode, ".\\GAME\\RosterPets.cpp", 0xD1, 0);
            return;
        }
        pPrev = pNode;
    }
}
