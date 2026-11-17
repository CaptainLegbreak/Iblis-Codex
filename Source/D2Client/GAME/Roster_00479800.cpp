#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2RosterInfoStrc;
struct D2RosterCorpseStrc;
struct D2RosterGroupStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

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

extern "C" const char szRosterCpp_006D7268[]; // 0x006D7268
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
static __declspec(noinline) void sub_00479800_MoveGroupMembers(D2RosterGroupStrc* pGroup);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

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

D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
void __fastcall sub_00478780_SendPartyCommand(int nCommand, int nUnitId); // 0x00478780
D2StoredUnitRecordStrc* __stdcall sub_004795F0_SortRosterByName(D2StoredUnitRecordStrc* pList); // 0x004795F0
void __cdecl sub_004797C0_FreeRosterGroups(); // 0x004797C0
void __cdecl sub_00479860_SortRosterGroups(); // 0x00479860
void __cdecl sub_00479940_BuildRosterGroups(); // 0x00479940
void __cdecl sub_00479A00_JoinRosterGroups(); // 0x00479A00
D2StoredUnitRecordStrc* __cdecl sub_00479F60_LeaveParty(); // 0x00479F60
int __cdecl sub_0047A980_IsNumberDisplayEnabled(); // 0x0047A980
void __cdecl sub_0049A640(); // 0x0049A640
D2RosterInfoStrc** __cdecl sub_004DC270_AllocRosterInfoList(); // 0x004DC270
void __cdecl sub_004799C0();

static D2StoredUnitRecordStrc* gpStoredUnits_007BB5C0; // 0x007BB5C0

static D2RosterGroupStrc* gpRosterGroups_007BB5C8; // 0x007BB5C8

// 0x00479800
static void sub_00479800_MoveGroupMembers(D2RosterGroupStrc* pGroup)
{
    D2StoredUnitRecordStrc* pPrev = 0;
    D2StoredUnitRecordStrc* pRecord = gpStoredUnits_007BB5C0;
    while (pRecord)
    {
        if (pRecord->wPartyId == pGroup->wPartyId)
        {
            D2StoredUnitRecordStrc* pMoved = pRecord;
            pRecord = pRecord->pNext;
            if (pPrev)
                pPrev->pNext = pRecord;
            else
                gpStoredUnits_007BB5C0 = pRecord;
            pMoved->pNext = pGroup->pFirst;
            pGroup->pFirst = pMoved;
        }
        else
        {
            pPrev = pRecord;
            pRecord = pRecord->pNext;
        }
    }
}

// 0x00479940
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
            pGroup = (D2RosterGroupStrc*)FOG_Alloc(sizeof(D2RosterGroupStrc), szRosterCpp_006D7268, 0x1FC, 0);
            memset(pGroup, 0, 8);
            pGroup->wPartyId = wPartyId;
            pGroup->pNext = gpRosterGroups_007BB5C8;
            gpRosterGroups_007BB5C8 = pGroup;
        }
        sub_00479800_MoveGroupMembers(pGroup);
    }
}

static D2StoredUnitRecordStrc* gpStoredUnits2_007BB5C4; // 0x007BB5C4

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

// 0x00479360
static D2StoredUnitRecordStrc* sub_00479360_FindRosterUnitByIdOrName(int nUnitId, const char* szName)
{
    for (D2StoredUnitRecordStrc* pRec = gpStoredUnits_007BB5C0; pRec; pRec = pRec->pNext)
    {
        if (pRec->dwUnitId == nUnitId)
            return pRec;
        if (!strcmp(pRec->szName, szName))
            return pRec;
    }
    return 0;
}

// 0x004793C0
static void __stdcall sub_004793C0_FillRosterUnit(int nUnitId, int nClassId, unsigned short wLevel, unsigned short wPartyId, int nPartyFlags, unsigned short wGuildFlags, const char* szGuildName, const char* szGuildTag, const char* szName, D2StoredUnitRecordStrc* pRec)
{
    strcpy(pRec->szName, szName);
    pRec->dwUnitId = nUnitId;
    pRec->dwClassId = nClassId;
    pRec->wLevel = wLevel;
    pRec->wPartyId = wPartyId;
    pRec->dwPartyFlags = nPartyFlags;
    pRec->wGuildFlags = wGuildFlags;
    strcpy(pRec->szGuildTag, szGuildTag);
    strcpy(pRec->szGuildName, szGuildName);
    if (szGuildTag[0])
        sprintf(pRec->szNameEx, "%s {%s}", szName, szGuildTag);
    else
        strcpy(pRec->szNameEx, szName);
}

// 0x004796D0
static D2StoredUnitRecordStrc* sub_004796D0_SortRosterByKills(D2StoredUnitRecordStrc* pList)
{
    D2StoredUnitRecordStrc* pSorted = 0;
    D2StoredUnitRecordStrc* pCurrent = pList;
    while (pCurrent)
    {
        pList = pCurrent->pNext;
        D2StoredUnitRecordStrc* pPrevious = 0;
        for (D2StoredUnitRecordStrc* pRoster = pSorted; pRoster; pRoster = pRoster->pNext)
        {
            if (pCurrent->dwKillCount > pRoster->dwKillCount)
            {
                break;
            }
            pPrevious = pRoster;
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
        pCurrent = pList;
    }
    return pSorted;
}

// 0x00479740
void __cdecl sub_00479740_SortMainListByKills()
{
    gpStoredUnits_007BB5C0 = sub_004796D0_SortRosterByKills(gpStoredUnits_007BB5C0);
}

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

// 0x004799C0
void __cdecl sub_004799C0()
{
    for (D2RosterGroupStrc* pGroup = gpRosterGroups_007BB5C8; pGroup; pGroup = pGroup->pNext)
    {
        if (sub_0047A980_IsNumberDisplayEnabled())
            pGroup->pFirst = sub_004796D0_SortRosterByKills(pGroup->pFirst);
        else
            pGroup->pFirst = sub_004795F0_SortRosterByName(pGroup->pFirst);
    }
    sub_00479860_SortRosterGroups();
}

// 0x00479A60
static void sub_00479A60_MovePlayerToFront(int nPlayerId)
{
    D2StoredUnitRecordStrc* pPrev = 0;
    for (D2StoredUnitRecordStrc* pRec = gpStoredUnits_007BB5C0; pRec; pRec = pRec->pNext)
    {
        if (pRec->dwUnitId == nPlayerId && pPrev)
        {
            pPrev->pNext = pRec->pNext;
            pRec->pNext = gpStoredUnits_007BB5C0;
            gpStoredUnits_007BB5C0 = pRec;
        }
        pPrev = pRec;
    }
}

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

// 0x00479FC0
void __cdecl sub_00479FC0()
{
    sub_00478780_SendPartyCommand(9, sub_00479F60_LeaveParty()->dwUnitId);
}

// 0x0047A6F0
void __fastcall sub_0047A6F0_AddRosterUnit(int nUnitId, int nClassId, const char* szName, unsigned short wLevel, unsigned short wPartyId, int nUnused, int nPartyFlags, unsigned short wGuildFlags, const char* szGuildTag, const char* szGuildName)
{
    D2StoredUnitRecordStrc* pPrev = 0;
    D2StoredUnitRecordStrc* pIter = gpStoredUnits2_007BB5C4;
    D2_ASSERT(nUnitId != -1, 0xB3);
    D2StoredUnitRecordStrc* pRec = sub_00479360_FindRosterUnitByIdOrName(nUnitId, szName);
    if (pRec)
    {
        sub_004793C0_FillRosterUnit(nUnitId, nClassId, wLevel, wPartyId, nPartyFlags, wGuildFlags, szGuildName, szGuildTag, szName, pRec);
        sub_00479AB0();
        sub_0049A640();
        return;
    }
    while (pIter)
    {
        if (pIter->dwUnitId == nUnitId)
        {
            pRec = pIter;
            pIter = 0;
        }
        else
        {
            pPrev = pIter;
            pIter = pIter->pNext;
        }
    }
    if (pRec)
    {
        if (pPrev)
            pPrev->pNext = pRec->pNext;
        else
            gpStoredUnits2_007BB5C4 = pRec->pNext;
        pRec->pNext = 0;
    }
    else
    {
        pRec = (D2StoredUnitRecordStrc*)FOG_Alloc(sizeof(D2StoredUnitRecordStrc), szRosterCpp_006D7268, 0xD8, 0);
        memset(pRec, 0, sizeof(D2StoredUnitRecordStrc));
    }
    pRec->pRosterInfo = sub_004DC270_AllocRosterInfoList();
    sub_004793C0_FillRosterUnit(nUnitId, nClassId, wLevel, wPartyId, nPartyFlags, wGuildFlags, szGuildName, szGuildTag, szName, pRec);
    pRec->pNext = gpStoredUnits_007BB5C0;
    gpStoredUnits_007BB5C0 = pRec;
    sub_00479AB0();
    sub_0049A640();
}
