#include "D2Client.h"
extern D2RosterPetNodeStrc* gpRosterPets;  // 0x007BB5BC
enum { NOT_FOUND = 0 };
// 0x004790F0
int __fastcall sub_004790F0(int key)
{
    for(D2RosterPetNodeStrc* node=gpRosterPets;node;node=node->pNext) {
        if(node->nKey==key) return node->unk0x10[0];
    }
    return NOT_FOUND;
}
