#include "D2Client.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2RosterInfoStrc;
struct D2RosterPetStrc;
struct D2RosterGroupStrc;
struct D2RosterCorpseStrc;
struct D2RosterUnitStrc;
struct Obj00479B80;
struct Obj00479BA0;
struct Obj00479D20;
struct Obj0047A1B0;
struct Obj0047A1E0;
struct Obj0047A670;

struct D2StoredUnitRecordStrc
{
    char szName[16];
    int dwUnitId;
    int dwPartyLife;
    int dwKillCount;
    int dwClassId;
    unsigned short wValue;
    unsigned short wPartyId;
    int dwLevelId;
    int dwPosX;
    int dwPosY;
    int dwPartyFlags;
    D2RosterInfoStrc** pRosterInfo;
    D2RosterCorpseStrc* pCorpse;
    int dwPortalA;
    int dwPortalB;
    char unk0x44[0x22];
    char szNameEx[26];
    D2StoredUnitRecordStrc* pNext;
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
    unsigned short wId;
    unsigned short wUnk0x02;
    D2StoredUnitRecordStrc* pFirst;
    D2RosterGroupStrc* pNext;
};

extern D2RosterPetStrc* gpRosterPets_007BB5BC; // 0x007BB5BC
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2RosterCorpseStrc
{
    int dwCorpseId;
    union
    {
        D2RosterCorpseStrc* pPrev;
        D2RosterCorpseStrc* pNext;
    };
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

extern D2StoredUnitRecordStrc* gpStoredUnits_007BB5C0; // 0x007BB5C0
extern D2RosterGroupStrc* gpRosterGroups_007BB5C8; // 0x007BB5C8
D2StoredUnitRecordStrc* __stdcall sub_004795F0_SortRosterByName(D2StoredUnitRecordStrc* pList); // 0x004795F0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
short __fastcall sub_00465400_GetPlayerRosterField22(D2UnitStrc* pUnit); // 0x00465400
void __fastcall sub_00478780_SendPartyCommand(unsigned char nCommand, int nUnitId); // 0x00478780
void __cdecl sub_00479AB0(); // 0x00479AB0
void __cdecl sub_0049A640(); // 0x0049A640
unsigned int __fastcall sub_004DC440(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC440

struct Obj00479B80 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwValue18;
};

struct Obj00479BA0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwValue1C;
};

struct Obj00479D20 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwValue30;
};

struct Obj0047A1B0 { unsigned char bUnknown00[0x28]; unsigned int dwValue28; unsigned int dwValue2C; };

struct Obj0047A1E0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwValue24;
};

struct Obj0047A670 { unsigned char bUnknown00[0x1C]; int nMode1C; };

D2RosterGroupStrc* gpRosterGroups_007BB5C8; // 0x007BB5C8

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

D2StoredUnitRecordStrc* gpStoredUnits_007BB5C0; // 0x007BB5C0

// 0x004795A0
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
        return pEntry->pNext;
    return gpStoredUnits_007BB5C0;
}

// 0x00479A00
void __cdecl sub_00479A00_JoinRosterGroups()
{
    D2StoredUnitRecordStrc* pTail = 0;
    for (D2RosterGroupStrc* pGroup = gpRosterGroups_007BB5C8; pGroup; pGroup = pGroup->pNext)
    {
        if (pTail)
        {
            pTail->pNext = pGroup->pFirst;
        }
        else
        {
            pTail = pGroup->pFirst;
            gpStoredUnits_007BB5C0 = pTail;
        }
        pGroup->pFirst = 0;
        if (pTail)
        {
            while (pTail->pNext)
                pTail = pTail->pNext;
        }
    }
}

// 0x00479BC0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry)
{
    D2StoredUnitRecordStrc* pRoster = gpStoredUnits_007BB5C0;
    int nCount = 0;
    if (pEntry && pRoster)
    {
        const unsigned short wPartyId = pEntry->wPartyId;
        for (; pRoster; pRoster = pRoster->pNext)
        {
            if (pRoster->wPartyId == wPartyId)
                ++nCount;
        }
        if (nCount > 1)
            return wPartyId;
    }
    return 0xFFFF;
}

// 0x00479C20
int __fastcall sub_00479C20(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        return sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 1);
    }
    return 0;
}

// 0x00479C60
int __fastcall sub_00479C60(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        return sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 2);
    }
    return 0;
}

// 0x00479CA0
int __fastcall sub_00479CA0(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        return sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 4);
    }
    return 0;
}

// 0x00479CE0
int __fastcall sub_00479CE0(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 8))
            return 1;
    }
    return 0;
}

// 0x00479EB0
void __fastcall sub_00479EB0(D2StoredUnitRecordStrc* pEntry)
{
    if (!pEntry)
        return;

    int nCommand = 0;
    switch (pEntry->dwPartyFlags)
    {
    case 0:
        pEntry->dwPartyFlags = 4;
        nCommand = 6;
        break;
    case 1:
        D2_ASSERT(0, 0x4C7);
    case 2:
        nCommand = 8;
        pEntry->dwPartyFlags = 1;
        break;
    case 4:
        pEntry->dwPartyFlags = 0;
        nCommand = 7;
        break;
    case 3:
        nCommand = 9;
        pEntry->dwPartyFlags = 1;
        break;
    }
    sub_00478780_SendPartyCommand(nCommand, pEntry->dwUnitId);
    sub_00479AB0();
    sub_0049A640();
}

// 0x0047A2C0
int __fastcall sub_0047A2C0_HasPartyMate(D2UnitStrc* pUnit)
{
    D2StoredUnitRecordStrc* pRoster = gpStoredUnits_007BB5C0;
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    const unsigned short wPartyId = sub_00465400_GetPlayerRosterField22(pUnit);
    if (wPartyId == 0xFFFF)
        return 0;

    for (; pRoster; pRoster = pRoster->pNext)
    {
        if (pRoster->wPartyId == wPartyId && pRoster->dwUnitId != nUnitId)
            return 1;
    }
    return 0;
}

// 0x0047A560
int __cdecl sub_0047A560()
{
    D2StoredUnitRecordStrc* pRoster = gpStoredUnits_007BB5C0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
    for (; pRoster; pRoster = pRoster->pNext)
    {
        if (sub_004DC440(pRoster->dwUnitId, nPlayerId, 8))
            return 1;
    }
    return 0;
}

// 0x0047A5B0
int __fastcall sub_0047A5B0(D2StoredUnitRecordStrc* pEntry)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pEntry && pPlayer && sub_004DC440(pEntry->dwUnitId, !pPlayer ? -1 : pPlayer->dwUnitId, 8))
        return 1;
    return 0;
}

// 0x0047A5E0
int __fastcall sub_0047A5E0(D2StoredUnitRecordStrc* pEntry)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pEntry && pPlayer && sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 8))
        return 1;
    return 0;
}

// 0x0047A610
int __fastcall sub_0047A610(D2StoredUnitRecordStrc* pEntry)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pEntry && pPlayer && sub_004DC440(pEntry->dwUnitId, !pPlayer ? -1 : pPlayer->dwUnitId, 1))
        return 1;
    return 0;
}

// 0x0047A640
int __fastcall sub_0047A640(D2StoredUnitRecordStrc* pEntry)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pEntry && pPlayer && sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 1))
        return 1;
    return 0;
}

// 0x00479B80
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00479B80(Obj00479B80* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue18;
}

// 0x00479BA0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00479BA0(Obj00479BA0* pObj) {
    if (pObj) {
        return pObj->dwValue1C;
    }
    return 0;
}

// 0x00479D20
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00479D20(Obj00479D20* pObj) {
    if (pObj) {
        return pObj->dwValue30;
    }
    return 1;
}

// 0x0047A0C0
int __fastcall sub_0047A0C0_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord)
{
    if (pRecord)
    {
        return pRecord->dwUnitId;
    }
    return -1;
}

// 0x0047A290
const char* __fastcall sub_0047A290_GetOwnerName(int nUnitId)
{
    for (D2StoredUnitRecordStrc* pRec = gpStoredUnits_007BB5C0; pRec; pRec = pRec->pNext)
    {
        if (pRec->dwPortalA == nUnitId || pRec->dwPortalB == nUnitId)
        {
            return pRec->szNameEx;
        }
    }
    return 0;
}

static D2StoredUnitRecordStrc* sub_004792E0_FindRosterUnit(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = gpStoredUnits_007BB5C0;
    if (nUnitId == -1)
        return 0;
    for (; pRec; pRec = pRec->pNext)
    {
        if (pRec->dwUnitId == nUnitId)
            return pRec;
        for (D2RosterCorpseStrc* pCorpse = pRec->pCorpse; pCorpse; pCorpse = pCorpse->pNext)
        {
            if (pCorpse->dwCorpseId == nUnitId)
                return pRec;
        }
    }
    return 0;
}

inline int ROSTER_TestPvpFlag4Inl(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        return sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 4);
    }
    return 0;
}

// 0x0047A170
int __fastcall sub_0047A170_TestNotFlag4(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (pRec)
    {
        return !ROSTER_TestPvpFlag4Inl(pRec);
    }
    return 1;
}

// 0x0047A1B0
extern "C" __declspec(dllexport) void __fastcall sub_0047A1B0(Obj0047A1B0* pObj, unsigned int* pFirst, unsigned int* pSecond) {
    if (pObj) {
        *pFirst = pObj->dwValue28;
        *pSecond = pObj->dwValue2C;
    } else {
        *pFirst = 0;
        *pSecond = 0;
    }
}

// 0x0047A1E0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_0047A1E0(Obj0047A1E0* pObj) {
    if (pObj) {
        return pObj->dwValue24;
    }
    return 0;
}

// 0x0047A670
extern "C" __declspec(dllexport) int __fastcall sub_0047A670(Obj0047A670* pObj) {
    if (pObj) {
        switch (pObj->nMode1C) {
        case 0:
        case 1:
        case 6:
            return 0;
        }
    }
    return 1;
}

// 0x0047A690
void __fastcall sub_0047A690(int nUnitGUID, unsigned char nLifePct)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitGUID);
    if (pRec)
        pRec->dwPartyLife = nLifePct;
}
