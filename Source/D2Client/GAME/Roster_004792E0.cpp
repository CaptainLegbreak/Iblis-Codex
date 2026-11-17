#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2RosterInfoStrc;
struct D2RosterCorpseStrc;
struct D2RosterGroupStrc;
struct D2PlayerDataStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2RosterCorpseStrc
{
    int dwCorpseId;
    D2RosterCorpseStrc* pNext;
};

struct D2StoredUnitRecordStrc
{
    char szName[16];
    int dwUnitId;
    int dwPartyLife;
    int dwKillCount;
    int dwClassId;
    unsigned short wLevel;
    unsigned short wPartyId;
    int dwLevelId;
    int dwPosX;
    int dwPosY;
    int dwPartyFlags;
    D2RosterInfoStrc** pRosterInfo;
    D2RosterCorpseStrc* pCorpse;
    int dwPortalA;
    int dwPortalB;
    unsigned short wGuildFlags;
    char szGuildTag[4];
    char szGuildName[28];
    char szNameEx[26];
    D2StoredUnitRecordStrc* pNext;
};

struct D2RosterGroupStrc
{
    unsigned short wPartyId;
    unsigned short unk0x02;
    D2StoredUnitRecordStrc* pFirst;
    D2RosterGroupStrc* pNext;
};

struct D2PlayerDataStrc
{
    char szName[16];
};

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
void __fastcall sub_00478740_SendPvpCommand(int nCommand, int nUnitId, int bSet); // 0x00478740
void __cdecl sub_00478FA0_UpdatePetFlags(); // 0x00478FA0
void __fastcall sub_00479230_UpdateOwnerPetFlags(int nOwnerId); // 0x00479230
void __cdecl sub_004797C0_FreeRosterGroups(); // 0x004797C0
void __cdecl sub_004799C0(); // 0x004799C0
void __cdecl sub_00479A00_JoinRosterGroups(); // 0x00479A00
void __cdecl sub_0049A640(); // 0x0049A640
void __fastcall sub_004DC320_AddRosterInfo(int nUnitId1, int nUnitId2); // 0x004DC320
void __fastcall sub_004DC3E0_TogglePvpFlag(int nUnitId1, int nUnitId2, unsigned int nFlags, int bSet); // 0x004DC3E0
unsigned int __fastcall sub_004DC440(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC440
void __fastcall sub_004DC4C0_SetPvpFlagsLow(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC4C0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

static D2StoredUnitRecordStrc* gpStoredUnits_007BB5C0; // 0x007BB5C0

static D2StoredUnitRecordStrc* gpStoredUnits2_007BB5C4; // 0x007BB5C4

static D2RosterGroupStrc* gpRosterGroups_007BB5C8; // 0x007BB5C8

// 0x004792E0
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

// 0x00479320
D2StoredUnitRecordStrc* __cdecl sub_00479320_GetPlayerRosterUnit()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(!pPlayer ? -1 : pPlayer->dwUnitId);
    D2_ASSERT(pRec, 0x75);
    return pRec;
}

// build: context sub_00479800_MoveGroupMembers
static void sub_00479800_MoveGroupMembers(D2RosterGroupStrc* pGroup)
{
    D2StoredUnitRecordStrc* pRec = gpStoredUnits_007BB5C0;
    D2StoredUnitRecordStrc* pPrev = 0;
    while (pRec)
    {
        if (pRec->wPartyId == pGroup->wPartyId)
        {
            D2StoredUnitRecordStrc** ppNext = &pRec->pNext;
            D2StoredUnitRecordStrc* pMove = pRec;
            pRec = *ppNext;
            if (pPrev)
            {
                pPrev->pNext = pRec;
                *ppNext = pGroup->pFirst;
                pGroup->pFirst = pMove;
            }
            else
            {
                *ppNext = pGroup->pFirst;
                gpStoredUnits_007BB5C0 = pRec;
                pGroup->pFirst = pMove;
            }
        }
        else
        {
            pPrev = pRec;
            pRec = pRec->pNext;
        }
    }
}

// build: context sub_004798C0_MovePlayerGroupToFront
static void sub_004798C0_MovePlayerGroupToFront(int nPlayerId, unsigned short wPartyId)
{
    D2RosterGroupStrc* pHead = gpRosterGroups_007BB5C8;
    D2RosterGroupStrc* pGroup = pHead;
    D2RosterGroupStrc* pPrevGroup = 0;
    D2StoredUnitRecordStrc* pPrev = 0;
    if (wPartyId == 0xFFFF)
        return;
    while (pGroup && pGroup->wPartyId != wPartyId)
    {
        pPrevGroup = pGroup;
        pGroup = pGroup->pNext;
    }
    if (!pGroup)
        return;
    if (pPrevGroup)
    {
        pPrevGroup->pNext = pGroup->pNext;
        pGroup->pNext = pHead;
        gpRosterGroups_007BB5C8 = pGroup;
    }
    D2StoredUnitRecordStrc* pRec = pGroup->pFirst;
    while (pRec && pRec->dwUnitId != nPlayerId)
    {
        pPrev = pRec;
        pRec = pRec->pNext;
    }
    if (!pRec)
        return;
    if (pPrev)
    {
        pPrev->pNext = pRec->pNext;
        pRec->pNext = pGroup->pFirst;
        pGroup->pFirst = pRec;
    }
}

void __cdecl sub_00479940_BuildRosterGroups()
{
    while (gpStoredUnits_007BB5C0)
    {
        const unsigned short wPartyId = gpStoredUnits_007BB5C0->wPartyId;
        D2RosterGroupStrc* pGroup = gpRosterGroups_007BB5C8;
        while (pGroup)
        {
            if (pGroup->wPartyId == wPartyId)
                break;
            pGroup = pGroup->pNext;
        }
        if (!pGroup)
        {
            pGroup = (D2RosterGroupStrc*)FOG_Alloc(sizeof(D2RosterGroupStrc), ".\\GAME\\Roster.cpp", 0x1FC, 0);
            memset(pGroup, 0, sizeof(D2RosterGroupStrc));
            pGroup->wPartyId = wPartyId;
            pGroup->pNext = gpRosterGroups_007BB5C8;
            gpRosterGroups_007BB5C8 = pGroup;
        }
        sub_00479800_MoveGroupMembers(pGroup);
    }
}

// build: context sub_00479A60_MovePlayerToFront
static void sub_00479A60_MovePlayerToFront(int nPlayerId)
{
    D2StoredUnitRecordStrc* pHead = gpStoredUnits_007BB5C0;
    D2StoredUnitRecordStrc* pPrev = 0;
    if (!pHead)
        return;
    D2StoredUnitRecordStrc* pRec = pHead;
    do
    {
        if (pRec->dwUnitId == nPlayerId && pPrev)
        {
            pPrev->pNext = pRec->pNext;
            pRec->pNext = pHead;
            pHead = pRec;
        }
        pPrev = pRec;
        pRec = pRec->pNext;
    }
    while (pRec);
    gpStoredUnits_007BB5C0 = pHead;
}

// 0x00479AB0
__declspec(noinline) void __cdecl sub_00479AB0()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nPlayerId);
    const unsigned short wPartyId = pRec ? pRec->wPartyId : 0xFFFF;
    sub_00479940_BuildRosterGroups();
    sub_004799C0();
    sub_004798C0_MovePlayerGroupToFront(nPlayerId, wPartyId);
    sub_00479A00_JoinRosterGroups();
    sub_004797C0_FreeRosterGroups();
    if (wPartyId == 0xFFFF)
        sub_00479A60_MovePlayerToFront(nPlayerId);
}

// 0x00479B10
void __fastcall sub_00479B10_SetKillCount(int nUnitId, unsigned short nValue)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (!pRec)
        return;
    if (nValue & 0x8000)
        pRec->dwKillCount = nValue - 0x10000;
    else
        pRec->dwKillCount = nValue;
    sub_00479AB0();
    sub_0049A640();
}

// 0x00479BB0
D2StoredUnitRecordStrc* __fastcall sub_00479BB0_FindRosterUnit(int nUnitId)
{
    return sub_004792E0_FindRosterUnit(nUnitId);
}

// 0x00479C00
unsigned short __fastcall sub_00479C00_LookupPartyNumber(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(pUnit->dwUnitId);
        if (pRec)
            return pRec->wPartyId;
    }
    return 0xFFFF;
}

// 0x00479D30
static void sub_00479D30_TogglePvpFlag(D2StoredUnitRecordStrc* pEntry, unsigned short nFlag)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
    D2_ASSERT(pEntry, 0x463);
    sub_004DC320_AddRosterInfo(nPlayerId, pEntry->dwUnitId);
    sub_004DC3E0_TogglePvpFlag(nPlayerId, pEntry->dwUnitId, nFlag, !sub_004DC440(nPlayerId, pEntry->dwUnitId, nFlag));
}

// 0x00479DA0
void __fastcall sub_00479DA0_TogglePvpFlag1(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        sub_00479D30_TogglePvpFlag(pEntry, 1);
        D2UnitStrc* pPlayer = sub_00463DD0();
        sub_00478740_SendPvpCommand(1, pEntry->dwUnitId, sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 1));
    }
}

// 0x00479DE0
void __fastcall sub_00479DE0_TogglePvpFlag2(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        sub_00479D30_TogglePvpFlag(pEntry, 2);
        D2UnitStrc* pPlayer = sub_00463DD0();
        sub_00478740_SendPvpCommand(2, pEntry->dwUnitId, sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 2));
    }
}

// 0x00479E20
void __fastcall sub_00479E20_ToggleSquelch(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        sub_00479D30_TogglePvpFlag(pEntry, 4);
        D2UnitStrc* pPlayer = sub_00463DD0();
        sub_00478740_SendPvpCommand(3, pEntry->dwUnitId, sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 4));
        pPlayer = sub_00463DD0();
        if (sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 4))
            sub_00611560_GetSquelchList()->Squelch(pEntry->szNameEx);
        else
            sub_00611560_GetSquelchList()->Unsquelch(pEntry->szNameEx);
    }
}

// 0x00479F60
D2StoredUnitRecordStrc* __cdecl sub_00479F60_LeaveParty()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(!pPlayer ? -1 : pPlayer->dwUnitId);
    D2_ASSERT(pRec, 0x4ED);
    pRec->wPartyId = 0xFFFF;
    pRec->dwPartyFlags = 1;
    sub_00479AB0();
    sub_0049A640();
    return pRec;
}

// 0x00479FE0
void __fastcall sub_00479FE0_TogglePvpFlag8(D2StoredUnitRecordStrc* pEntry)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
    if (!pEntry)
        return;
    if (!sub_004DC440(nPlayerId, pEntry->dwUnitId, 8) && pEntry->wLevel < 9)
        return;
    sub_00479D30_TogglePvpFlag(pEntry, 8);
    sub_00478740_SendPvpCommand(4, pEntry->dwUnitId, sub_004DC440(nPlayerId, pEntry->dwUnitId, 8));
    if (sub_004DC440(nPlayerId, pEntry->dwUnitId, 8) && pEntry->wPartyId != 0xFFFF
        && sub_00479320_GetPlayerRosterUnit()->wPartyId == pEntry->wPartyId)
        sub_00479F60_LeaveParty();
}

// 0x0047A070
int __fastcall sub_0047A070_TestPvpFlag8(int nUnitId1, int nUnitId2)
{
    D2StoredUnitRecordStrc* pRec1 = sub_004792E0_FindRosterUnit(nUnitId1);
    D2StoredUnitRecordStrc* pRec2 = sub_004792E0_FindRosterUnit(nUnitId2);
    if (pRec1 && pRec2)
    {
        if (pRec1->wPartyId == pRec2->wPartyId && pRec1->wPartyId != 0xFFFF)
            return 0;
        return sub_004DC440(pRec1->dwUnitId, pRec2->dwUnitId, 8) != 0;
    }
    return 1;
}

// 0x0047A0D0
void __fastcall sub_0047A0D0_SetLifeAndLevel(int nUnitId, int nLife, unsigned short wLevelId)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (pRec)
    {
        pRec->dwPartyLife = nLife;
        pRec->dwLevelId = wLevelId;
        sub_00479AB0();
        sub_0049A640();
    }
}

// 0x0047A100
void __fastcall sub_0047A100_SetPosition(int nUnitId, int nX, int nY)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (pRec)
    {
        pRec->dwPosX = nX;
        pRec->dwPosY = nY;
    }
}

// 0x0047A150
int __fastcall sub_0047A150_GetPartyLife(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (pRec)
        return pRec->dwPartyLife;
    return 0;
}

// build: context sub_0047A170_TestNotFlag4
int __fastcall sub_0047A170_TestNotFlag4(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (pRec)
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        int nPlayerId;
        if (!pPlayer)
            nPlayerId = -1;
        else
            nPlayerId = pPlayer->dwUnitId;
        return sub_004DC440(nPlayerId, pRec->dwUnitId, 4) == 0;
    }
    return 1;
}

// 0x0047A1F0
char* __fastcall sub_0047A1F0_GetNameEx(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (pRec)
        return pRec->szNameEx;
    return 0;
}

// 0x0047A210
char* __fastcall sub_0047A210_GetUnitName(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x5DB);
    D2_ASSERT(pUnit->dwUnitType == 0, 0x5DC);
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(pUnit->dwUnitId);
    if (!pRec)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x5E5);
        return pPlayerData->szName;
    }
    return pRec->szNameEx;
}

// 0x0047A270
void __fastcall sub_0047A270_SetPortalIds(int nUnitId, int nA, int nB)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (pRec)
    {
        pRec->dwPortalA = nA;
        pRec->dwPortalB = nB;
    }
}

// 0x0047A310
D2RosterInfoStrc** __fastcall sub_0047A310_GetRosterInfoList(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (pRec)
        return pRec->pRosterInfo;
    return 0;
}

// 0x0047A330
void __fastcall sub_0047A330_SetPartyId(int nUnitId, unsigned short wPartyId)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (pRec)
    {
        pRec->wPartyId = wPartyId;
        sub_00479AB0();
        sub_0049A640();
    }
}

// 0x0047A350
void __fastcall sub_0047A350_SetPartyFlags(int nUnitId, unsigned char nFlags)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (pRec)
    {
        pRec->dwPartyFlags = nFlags;
        sub_0049A640();
    }
}

// 0x0047A370
void __fastcall sub_0047A370_SetPvpFlags(int nUnitId1, int nUnitId2, unsigned short wFlags)
{
    if (!sub_004792E0_FindRosterUnit(nUnitId1))
        return;
    sub_004DC320_AddRosterInfo(nUnitId1, nUnitId2);
    sub_004DC4C0_SetPvpFlagsLow(nUnitId1, nUnitId2, wFlags);
    sub_0049A640();
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (nUnitId2 == (!pPlayer ? -1 : pPlayer->dwUnitId))
        sub_00479230_UpdateOwnerPetFlags(nUnitId1);
}

// 0x0047A3D0
void __fastcall sub_0047A3D0_AddCorpse(int nUnitId, int nCorpseId)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (!pRec)
    {
        pRec = (D2StoredUnitRecordStrc*)FOG_Alloc(sizeof(D2StoredUnitRecordStrc), ".\\GAME\\Roster.cpp", 0x686, 0);
        D2_ASSERT(pRec, 0x687);
        memset(pRec, 0, sizeof(D2StoredUnitRecordStrc));
        pRec->dwUnitId = nUnitId;
        pRec->pNext = gpStoredUnits2_007BB5C4;
        gpStoredUnits2_007BB5C4 = pRec;
    }
    for (D2RosterCorpseStrc* pCorpse = pRec->pCorpse; pCorpse; pCorpse = pCorpse->pNext)
    {
        if (pCorpse->dwCorpseId == nCorpseId)
            return;
    }
    D2RosterCorpseStrc* pNew = (D2RosterCorpseStrc*)FOG_Alloc(sizeof(D2RosterCorpseStrc), ".\\GAME\\Roster.cpp", 0x697, 0);
    D2_ASSERT(pNew, 0x698);
    memset(pNew, 0, sizeof(D2RosterCorpseStrc));
    pNew->dwCorpseId = nCorpseId;
    pNew->pNext = pRec->pCorpse;
    pRec->pCorpse = pNew;
}

// 0x0047A490
void __fastcall sub_0047A490_DropCorpseEntry(int nUnitId, int nCorpseId)
{
    D2RosterCorpseStrc* pPrev = 0;
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (!pRec)
        return;
    for (D2RosterCorpseStrc* pCorpse = pRec->pCorpse; pCorpse; pCorpse = pCorpse->pNext)
    {
        if (pCorpse->dwCorpseId == nCorpseId)
        {
            if (pPrev)
                pPrev->pNext = pCorpse->pNext;
            else
                pRec->pCorpse = pCorpse->pNext;
            FOG_Free(pCorpse, ".\\GAME\\Roster.cpp", 0x6BD, 0);
            return;
        }
        pPrev = pCorpse;
    }
}

// 0x0047A520
int __fastcall sub_0047A520_IsSameParty(int nUnitId1, int nUnitId2)
{
    D2StoredUnitRecordStrc* pRec1 = sub_004792E0_FindRosterUnit(nUnitId1);
    D2StoredUnitRecordStrc* pRec2 = sub_004792E0_FindRosterUnit(nUnitId2);
    if (pRec1 && pRec2 && pRec1->wPartyId == pRec2->wPartyId && pRec1->wPartyId != 0xFFFF)
        return 1;
    return 0;
}

// 0x0047A6B0
int __fastcall sub_0047A6B0_GetOtherPartyLife(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (nUnitId != (!pPlayer ? -1 : pPlayer->dwUnitId) && pRec)
        return pRec->dwPartyLife;
    return 0;
}

// 0x0047A850
void __fastcall sub_0047A850_UpdateRosterUnit(int nUnitId, unsigned short wPartyId, unsigned short wLevel, int nUnused, int nPartyFlags)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (!pRec)
        return;
    for (D2RosterCorpseStrc* pCorpse = pRec->pCorpse; pCorpse; pCorpse = pCorpse->pNext)
    {
        if (pCorpse->dwCorpseId == nUnitId)
            return;
    }
    pRec->wPartyId = wPartyId;
    pRec->wLevel = wLevel;
    pRec->dwPartyFlags = nPartyFlags;
    sub_00478FA0_UpdatePetFlags();
    sub_00479AB0();
    sub_0049A640();
}

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

// 0x0047A4F0
int __fastcall sub_0047A4F0_TestFlag1(int nUnitId1, int nUnitId2)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId2);
    if (pRec)
    {
        const int nRecId = pRec->dwUnitId;
        if (nUnitId1 == nRecId)
            return 1;
        if (sub_004DC440(nRecId, nUnitId1, 1))
            return 1;
    }
    return 0;
}
