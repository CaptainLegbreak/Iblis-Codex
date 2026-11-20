#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2LevelTxt.h"
#include "D2ClientTypes.h"
struct D2UnitStrc;

#define PETTYPE_FLAG_PARTY 4
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2RosterPetStrc;
struct D2PetTypeTxt;
struct D2ClientEntryStrc;
struct D2InvRectStrc;
struct D2InventoryGridInfoStrc;
struct D2InvCompGridStrc;



struct D2RosterPetStrc
{
    int nClassId;
    int nType;
    int dwUnitId;
    int dwOwnerId;
    int nArg10;
    int unk0x14[2];
    int nLifePercent;
    union
    {
        struct
        {
            int unk0x20[4];
        };
        struct
        {
            unsigned char unk_20[0x4];
            D2ClientEntryStrc tEntry;
        };
    };
    D2RosterPetStrc* pNext;
};

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2StoredUnitRecordStrc* __fastcall sub_00479BB0_FindRosterUnit(int nUnitId); // 0x00479BB0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry); // 0x00479BC0
extern D2RosterPetStrc* gpRosterPets_007BB5BC; // 0x007BB5BC



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
unsigned int __fastcall sub_004DC440(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC440
int __fastcall sub_0047A070_TestPvpFlag8(int nUnitId1, int nUnitId2); // 0x0047A070
int __cdecl sub_0044DCC0(); // 0x0044DCC0



struct D2InvCompGridStrc
{
    D2InvRectStrc rect;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned short pad0x12;
};

void __stdcall sub_0065C180_2(int nInventoryTxtId, int bHigherRes, D2InvRectStrc* pInvRect); // 0x0065C180
void __stdcall sub_0065C1F0_2(int nInventoryTxtId, int bHigherRes, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0065C1F0
void __stdcall sub_0065C270_2(int nInventoryTxtId, int bHigherRes, D2InvCompGridStrc* pInvCompGrid, int nComponent); // 0x0065C270
int __fastcall sub_004B3230_GetTickPair(int* pUnitId); // 0x004B3230
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
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

D2RosterPetStrc* gpRosterPets_007BB5BC; // 0x007BB5BC

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
        return sub_004DC440(nOwnerId, nPlayerId, 8);

    return 1;
}

static __forceinline D2RosterPetStrc* PETS_FindRosterPetInl(int nUnitId)
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

    return sub_0047A070_TestPvpFlag8(nPlayerId, nOwnerId);
}

int gnUiRecordRow_007A5218; // 0x007A5218

int gnUiRecordRow_007BEEA8; // 0x007BEEA8

int gnGlobal_007BCBDC; // 0x007BCBDC

int gnGlobal_007BCBE0; // 0x007BCBE0

D2InventoryGridInfoStrc gGrid_007BCA50; // 0x007BCA50

D2InvRectStrc gInvRect_007BCA68; // 0x007BCA68

D2InvRectStrc gInvRect_007BCA90; // 0x007BCA90

D2InventoryGridInfoStrc gGrid_007BCAB0; // 0x007BCAB0

D2InvRectStrc gInvRect_007BCAC8; // 0x007BCAC8

D2InvRectStrc gInvRect_007BCAE0; // 0x007BCAE0

D2InvRectStrc gInvRect_007BCAF4; // 0x007BCAF4

D2InvRectStrc gInvRect_007BCB08; // 0x007BCB08

D2InvRectStrc gInvRect_007BCBA0; // 0x007BCBA0

// 0x00478F20
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny)
{
    if (!pUnit)
        return -1;

    const int nUnitId = pUnit->dwUnitId;
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->nType == nType && pPet->dwOwnerId == nUnitId && (bAny || !pPet->unk0x20[0]))
            return pPet->dwUnitId;
    }

    return -1;
}

// 0x004835B0
void __cdecl sub_004835B0_LoadUiRecords()
{
    if (gnUiRecordRow_007A5218 != gnUiRecordRow_007BEEA8)
    {
        gnUiRecordRow_007BEEA8 = gnUiRecordRow_007A5218;
        gnGlobal_007BCBDC = 0;
        gnGlobal_007BCBE0 = 0;
    }

    if (!gnGlobal_007BCBDC)
    {
        const int nClass = sub_00621050(sub_00463DD0_GetPlayerUnit(), 0, sub_0044DCC0());
        sub_0065C180_2(nClass, gnUiRecordRow_007A5218, &gInvRect_007BCAA0);
        sub_0065C1F0_2(nClass, gnUiRecordRow_007A5218, &gGrid_007BCB88);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[4], 0);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[3], 1);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[5], 2);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[1], 3);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[2], 4);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[6], 5);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[7], 6);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[8], 7);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[9], 8);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[10], 9);
        sub_0065C180_2(13, gnUiRecordRow_007A5218, &gInvRect_007BCB08);
        sub_0065C1F0_2(13, gnUiRecordRow_007A5218, &gInventoryGrid_007BCBC0);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[4], 0);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[3], 1);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[5], 2);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[1], 3);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[2], 4);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[6], 5);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[7], 6);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[8], 7);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[9], 8);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[10], 9);
        sub_0065C180_2(6, gnUiRecordRow_007A5218, &gInvRect_007BCAE0);
        sub_0065C1F0_2(6, gnUiRecordRow_007A5218, &gGrid_007BCB18);
        sub_0065C180_2(7, gnUiRecordRow_007A5218, &gInvRect_007BCA90);
        sub_0065C1F0_2(7, gnUiRecordRow_007A5218, &gGrid_007BCA30);
        sub_0065C180_2(8, gnUiRecordRow_007A5218, &gInvRect_007BCA68);
        sub_0065C1F0_2(8, gnUiRecordRow_007A5218, &gGrid_007BCB40);
        sub_0065C180_2(12, gnUiRecordRow_007A5218, &gInvRect_007BCAF4);
        sub_0065C1F0_2(12, gnUiRecordRow_007A5218, &gGrid_007BCA78);
        sub_0065C180_2(9, gnUiRecordRow_007A5218, &gInvRect_007BCB30);
        sub_0065C1F0_2(9, gnUiRecordRow_007A5218, &gGrid_007BCB70);
        sub_0065C180_2(10, gnUiRecordRow_007A5218, &gInvRect_007BCBA0);
        sub_0065C1F0_2(10, gnUiRecordRow_007A5218, &gGrid_007BCAB0);
        sub_0065C180_2(11, gnUiRecordRow_007A5218, &gInvRect_007BCAC8);
        sub_0065C1F0_2(11, gnUiRecordRow_007A5218, &gGrid_007BCA50);
        gnGlobal_007BCBDC = 1;
    }

    int nUnitId;
    if (!gnGlobal_007BCBE0 && gdwGlobal_007BCBF0 && sub_004B3230_GetTickPair(&nUnitId))
    {
        D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
        if (pUnit)
        {
            const int nClass = sub_00621050(pUnit, 0, sub_0044DCC0());
            sub_0065C180_2(nClass, gnUiRecordRow_007A5218, &gRect_007BCBB0);
            sub_0065C1F0_2(nClass, gnUiRecordRow_007A5218, &gGrid_007BCB58);
            gnGlobal_007BCBE0 = 1;
        }
    }
}
