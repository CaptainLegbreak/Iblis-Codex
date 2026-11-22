#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2LevelTxt.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"
#include "D2ClientGame.h"

struct D2RosterPetStrc;
struct D2ClientEntryStrc;

extern D2RosterPetStrc* gpRosterPets_007BB5BC; // 0x007BB5BC

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

