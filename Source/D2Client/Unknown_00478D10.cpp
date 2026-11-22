#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2LevelTxt.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"
#include "D2ClientGame.h"
struct D2UnitStrc;

#define PETTYPE_FLAG_PARTY 4
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2RosterPetStrc;
struct D2PetTypeTxt;
struct D2ClientEntryStrc;
struct D2InvRectStrc;
struct D2InventoryGridInfoStrc;
struct D2InvCompGridStrc;


D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2StoredUnitRecordStrc* __fastcall ROSTER_FindRosterUnitById(int nUnitId); // 0x00479BB0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry); // 0x00479BC0
extern D2RosterPetStrc* gpRosterPets_007BB5BC; // 0x007BB5BC

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
unsigned int __fastcall GFXUTIL_TestRelationFlags(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC440
int __fastcall ROSTER_IsHostileRelation(int nUnitId1, int nUnitId2); // 0x0047A070
int __cdecl GAME_IsExpansion(); // 0x0044DCC0

void __stdcall sub_0065C180_2(int nInventoryTxtId, int bHigherRes, D2InvRectStrc* pInvRect); // 0x0065C180
void __stdcall sub_0065C1F0_2(int nInventoryTxtId, int bHigherRes, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0065C1F0
void __stdcall sub_0065C270_2(int nInventoryTxtId, int bHigherRes, D2InvCompGridStrc* pInvCompGrid, int nComponent); // 0x0065C270
int __fastcall NPCMENU_GetInteractNpcId(int* pUnitId); // 0x004B3230
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
extern int gdwGlobal_007BCBF0; // 0x007BCBF0
extern D2InventoryGridInfoStrc gGrid_007BCA30; // 0x007BCA30
extern D2InventoryGridInfoStrc gGrid_007BCA78; // 0x007BCA78
extern D2InvRectStrc gInvRect_007BCAA0; // 0x007BCAA0
extern D2InventoryGridInfoStrc gGrid_007BCB18; // 0x007BCB18
extern D2InvRectStrc gInvRect_007BCB30; // 0x007BCB30
extern D2InventoryGridInfoStrc gGrid_007BCB40; // 0x007BCB40
extern D2InventoryGridInfoStrc gGrid_007BCB58; // 0x007BCB58
extern D2InventoryGridInfoStrc gGrid_007BCB70; // 0x007BCB70
extern D2InventoryGridInfoStrc gGrid_007BCB88; // 0x007BCB88
extern D2InvRectStrc gRect_007BCBB0; // 0x007BCBB0
extern D2InventoryGridInfoStrc gInventoryGrid_007BCBC0; // 0x007BCBC0
extern D2InvCompGridStrc gaCompGrids_007BCC58[11]; // 0x007BCC58
extern D2InvCompGridStrc gaBodyLocRects_007BCD38[11]; // 0x007BCD38

// 0x00478D10
int __fastcall sub_00478D10_GetPetOwnerRelation(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
            const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
            if (pPet->dwOwnerId == nPlayerId)
            {
                return 1;
            }

            const unsigned short nPartyId = sub_00479BC0_GetEntryIndex(ROSTER_FindRosterUnitById(nPlayerId));
            if (nPartyId == 0xFFFF || nPartyId != sub_00479BC0_GetEntryIndex(ROSTER_FindRosterUnitById(pPet->dwOwnerId)))
            {
                break;
            }
            return 2;
        }
    }
    return 0;
}

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

            if (!(pPetTypeTxtRecord->nPetFlags[PETTYPE_FLAG_PARTY >> 3] & gdwBitMasks[PETTYPE_FLAG_PARTY & 7]))
            {
                return 3;
            }

            D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
            const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
            if (pPet->dwOwnerId == nPlayerId)
            {
                return 1;
            }

            const unsigned short nPartyId = sub_00479BC0_GetEntryIndex(ROSTER_FindRosterUnitById(nPlayerId));
            if (nPartyId == 0xFFFF || nPartyId != sub_00479BC0_GetEntryIndex(ROSTER_FindRosterUnitById(pPet->dwOwnerId)))
            {
                break;
            }
            return 2;
        }
    }
    return 0;
}

D2RosterPetStrc* gpRosterPets_007BB5BC; // 0x007BB5BC

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
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nPlayerId = pPlayer ? pPlayer->dwUnitId : -1;
    D2_ASSERT(nPlayerId != -1, 0x225);
    if (nOwnerId != -1)
        return GFXUTIL_TestRelationFlags(nOwnerId, nPlayerId, 8);

    return 1;
}

static inline D2RosterPetStrc* PETS_FindRosterPetInl(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            return pPet;
        }
    }

    return 0;
}

// 0x00478E70
int __fastcall sub_00478E70_IsPetFriendly(D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
{
    D2RosterPetStrc* pPet = PETS_FindRosterPetInl(!pUnit ? -1 : pUnit->dwUnitId);
    if (!pUnit || !pPlayer)
    {
        return 1;
    }

    const int nPlayerId = pPlayer->dwUnitId;
    if (!pPet)
    {
        const int nType = pPlayer->dwUnitType;
        if (nType == 1 && pUnit->dwUnitType == nType && STATLIST_AreUnitsAligned(pPlayer, pUnit))
        {
            return 0;
        }

        return 1;
    }

    const int nOwnerId = pPet->dwOwnerId;
    if (nOwnerId == nPlayerId)
    {
        return 0;
    }

    return ROSTER_IsHostileRelation(nPlayerId, nOwnerId);
}














// 0x00478F20
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny)
{
    if (!pUnit)
        return -1;

    const int nUnitId = pUnit->dwUnitId;
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->nType == nType && pPet->dwOwnerId == nUnitId && (bAny || !pPet->bDead))
            return pPet->dwUnitId;
    }

    return -1;
}
