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
extern D2RosterPetNodeStrc* gpRosterPets_007BB5BC;  // 0x007BB5BC
enum { NOT_FOUND = 0 };
// 0x004790F0
int __fastcall sub_004790F0(int key)
{
    for(D2RosterPetNodeStrc* node=gpRosterPets_007BB5BC;node;node=node->pNext) {
        if(node->nKey==key) return node->unk0x10[0];
    }
    return NOT_FOUND;
}
