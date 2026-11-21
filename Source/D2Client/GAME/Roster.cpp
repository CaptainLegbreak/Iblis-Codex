#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGame.h"
#include "D2UnitData.h"
#include "D2GameClient.h"

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

extern D2RosterPetStrc* gpRosterPets_007BB5BC; // 0x007BB5BC

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2RosterUnitStrc
{
    char unk0x00[0x38];
    D2RosterCorpseStrc* pCorpse;
    char unk0x3C[0x08];
    unsigned short wUnk0x44;
    unsigned char unk0x46[4];
    unsigned char unk0x4A[4];
};



D2StoredUnitRecordStrc* __stdcall sub_004795F0_SortRosterByName(D2StoredUnitRecordStrc* pList); // 0x004795F0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0


void __fastcall sub_00478780_SendPartyCommand(int nCommand, int nUnitId); // 0x00478780

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

struct D2PlayerDataStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

void __fastcall sub_00478740_SendPvpCommand(int nCommand, int nUnitId, int bSet); // 0x00478740

void __cdecl sub_00478FA0_UpdatePetFlags(); // 0x00478FA0

void __fastcall sub_00479230_UpdateOwnerPetFlags(int nOwnerId); // 0x00479230

void __cdecl sub_004797C0_FreeRosterGroups(); // 0x004797C0

void __cdecl sub_004799C0(); // 0x004799C0

void __cdecl sub_00479A00_JoinRosterGroups(); // 0x00479A00

void __fastcall sub_004DC320_AddRosterInfo(int nUnitId1, int nUnitId2); // 0x004DC320

void __fastcall sub_004DC3E0_TogglePvpFlag(int nUnitId1, int nUnitId2, unsigned int nFlags, int bSet); // 0x004DC3E0

void __fastcall sub_004DC4C0_SetPvpFlagsLow(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC4C0

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

static D2StoredUnitRecordStrc* gpStoredUnits_007BB5C0; // 0x007BB5C0

static D2StoredUnitRecordStrc* gpStoredUnits2_007BB5C4; // 0x007BB5C4

static D2RosterGroupStrc* gpRosterGroups_007BB5C8; // 0x007BB5C8

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

void __cdecl sub_00479860_SortRosterGroups();                                                               // 0x00479860

void __cdecl sub_00479940_BuildRosterGroups();                                                              // 0x00479940

D2StoredUnitRecordStrc* __cdecl sub_00479F60_LeaveParty();                                                  // 0x00479F60

int __cdecl sub_0047A980_IsNumberDisplayEnabled();                                                          // 0x0047A980

D2RosterInfoStrc** __cdecl sub_004DC270_AllocRosterInfoList();                                              // 0x004DC270

struct D2PanelCtrlStrc_004B8370
{
    char unk0x00[0x5C];
    int nState;
};

struct D2SoundObjStrc_00515A30
{
    char unk0x00[0x40];
    int nValue40;
    int nValue44;
};

struct D2LinkStrc_004CA990
{
    void* pFirst;
};

struct D2OwnerStrc_004CA990
{
    char unk0x00[0x78];
    D2LinkStrc_004CA990* pLink;
};

typedef char check_ptr_width[(sizeof(void*) == 4) ? 1 : -1];

typedef char check_size_ctrl[(sizeof(D2PanelCtrlStrc_004B8370) == 0x60) ? 1 : -1];

typedef char check_size_sound[(sizeof(D2SoundObjStrc_00515A30) == 0x48) ? 1 : -1];

typedef char check_size_owner[(sizeof(D2OwnerStrc_004CA990) == 0x7C) ? 1 : -1];

#pragma intrinsic(memset)

struct D2StoredUnitRecordStrc;

static __declspec(noinline) D2RosterGroupStrc* sub_00479770_GetOrAddGroup(unsigned short wId);

extern "C" const char szRosterCpp_006D7268[]; // 0x006D7268

static __declspec(noinline) void sub_00479800_MoveGroupMembers(D2RosterGroupStrc* pGroup);

D2StoredUnitRecordStrc* __cdecl sub_00479320_GetPlayerRosterUnit();

struct Unicode
{
    unsigned short wChar;

    int isWhitespace() const;
};

void __fastcall sub_004DC2B0_FreeRosterInfoList(D2RosterInfoStrc** pList);                                  // 0x004DC2B0

unsigned short __fastcall sub_00465400_GetPlayerRosterField22(D2UnitStrc* pUnit);                           // 0x00465400

void __fastcall sub_00479B10_SetKillCount(int nUnitId, unsigned short nValue);

D2StoredUnitRecordStrc* __fastcall sub_00479BB0_FindRosterUnit(int nUnitId);

unsigned short __fastcall sub_00479C00_LookupPartyNumber(D2UnitStrc* pUnit);

static void sub_00479D30_TogglePvpFlag(D2StoredUnitRecordStrc* pEntry, unsigned short nFlag);

void __fastcall sub_00479DA0_TogglePvpFlag1(D2StoredUnitRecordStrc* pEntry);

void __fastcall sub_00479DE0_TogglePvpFlag2(D2StoredUnitRecordStrc* pEntry);

void __fastcall sub_00479E20_ToggleSquelch(D2StoredUnitRecordStrc* pEntry);

void __fastcall sub_00479FE0_TogglePvpFlag8(D2StoredUnitRecordStrc* pEntry);

int __fastcall sub_0047A070_TestPvpFlag8(int nUnitId1, int nUnitId2);

void __fastcall sub_0047A0D0_SetLifeAndLevel(int nUnitId, int nLife, unsigned short wLevelId);

void __fastcall sub_0047A100_SetPosition(int nUnitId, int nX, int nY);

int __fastcall sub_0047A150_GetPartyLife(int nUnitId);

char* __fastcall sub_0047A1F0_GetNameEx(int nUnitId);

char* __fastcall sub_0047A210_GetUnitName(D2UnitStrc* pUnit);

void __fastcall sub_0047A270_SetPortalIds(int nUnitId, int nA, int nB);

D2RosterInfoStrc** __fastcall sub_0047A310_GetRosterInfoList(int nUnitId);

void __fastcall sub_0047A330_SetPartyId(int nUnitId, unsigned short wPartyId);

void __fastcall sub_0047A350_SetPartyFlags(int nUnitId, unsigned char nFlags);

void __fastcall sub_0047A370_SetPvpFlags(int nUnitId1, int nUnitId2, unsigned short wFlags);

void __fastcall sub_0047A3D0_AddCorpse(int nUnitId, int nCorpseId);

void __fastcall sub_0047A490_DropCorpseEntry(int nUnitId, int nCorpseId);

int __fastcall sub_0047A4F0_TestFlag1(int nUnitId1, int nUnitId2);

int __fastcall sub_0047A520_IsSameParty(int nUnitId1, int nUnitId2);

int __fastcall sub_0047A6B0_GetOtherPartyLife(int nUnitId);

void __fastcall sub_0047A850_UpdateRosterUnit(int nUnitId, unsigned short wPartyId, unsigned short wLevel, int nUnused, int nPartyFlags);

static void sub_00479800_MoveGroupMembers(D2RosterGroupStrc* pGroup);

static void sub_004798C0_MovePlayerGroupToFront(int nPlayerId, unsigned short wPartyId);

void __cdecl sub_00479940_BuildRosterGroups();

static void sub_00479A60_MovePlayerToFront(int nPlayerId);

void __fastcall sub_0047A6F0_AddRosterUnit(int nUnitId, int nClassId, const char* szName, unsigned short wLevel, unsigned short wPartyId, int nUnused, int nPartyFlags, unsigned short wGuildFlags, const char* szGuildTag, const char* szGuildName);

static D2StoredUnitRecordStrc* sub_004792E0_FindRosterUnit(int nUnitId);

int __fastcall sub_0047A170_TestNotFlag4(int nUnitId);

static D2StoredUnitRecordStrc* sub_00479360_FindRosterUnitByIdOrName(int nUnitId, const char* szName);

static void __stdcall sub_004793C0_FillRosterUnit(int nUnitId, int nClassId, unsigned short wLevel, unsigned short wPartyId, int nPartyFlags, unsigned short wGuildFlags, const char* szGuildName, const char* szGuildTag, const char* szName, D2StoredUnitRecordStrc* pRec);

static D2StoredUnitRecordStrc* sub_004796D0_SortRosterByKills(D2StoredUnitRecordStrc* pList);

void __cdecl sub_00479740_SortMainListByKills();

void __cdecl sub_00479FC0();



// 0x00479080
int __fastcall sub_00479080_GetPetLife(int nUnitId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            return pPet->nLifePercent;
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

// 0x004792C0
static __forceinline int sub_004792C0_HasCorpse(D2RosterUnitStrc* pRosterUnit, unsigned int dwCorpseId)
{
    for (D2RosterCorpseStrc* pCorpse = pRosterUnit->pCorpse; pCorpse; pCorpse = pCorpse->pNext)
    {
        if (pCorpse->dwCorpseId == dwCorpseId)
        {
            return 1;
        }
    }
    return 0;
}

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
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(!pPlayer ? -1 : pPlayer->dwUnitId);
    D2_ASSERT(pRec, 0x75);
    return pRec;
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

// 0x00479470
static __forceinline void sub_00479470_FreeCorpses(D2RosterUnitStrc* pRosterUnit)
{
    D2RosterCorpseStrc* pCorpse = pRosterUnit->pCorpse;
    while (pCorpse)
    {
        D2RosterCorpseStrc* pPrev = pCorpse->pNext;
        FOG_Free(pCorpse, ".\\GAME\\Roster.cpp", 0x110, 0);
        pCorpse = pPrev;
    }
    pRosterUnit->pCorpse = 0;
}

int __fastcall sub_M119_Emit_004792C0(D2RosterUnitStrc* pRosterUnit, unsigned int dwCorpseId)
{
    if (sub_004792C0_HasCorpse(pRosterUnit, dwCorpseId + 1))
    {
        sub_00479470_FreeCorpses(pRosterUnit);
    }
    return 1;
}


// 0x004794B0
void __cdecl sub_004794B0_FreeRosterLists()
{
    D2StoredUnitRecordStrc* pEntry = gpStoredUnits_007BB5C0;
    while (pEntry)
    {
        D2StoredUnitRecordStrc* pNext = pEntry->pNext;
        sub_004DC2B0_FreeRosterInfoList(pEntry->pRosterInfo);
        pEntry->pRosterInfo = 0;
        D2RosterCorpseStrc* pSub = pEntry->pCorpse;
        while (pSub)
        {
            D2RosterCorpseStrc* pSubNext = pSub->pNext;
            FOG_Free(pSub, ".\\GAME\\Roster.cpp", 0x110, 0);
            pSub = pSubNext;
        }
        pEntry->pCorpse = 0;
        FOG_Free(pEntry, ".\\GAME\\Roster.cpp", 0x14D, 0);
        pEntry = pNext;
    }
    gpStoredUnits_007BB5C0 = 0;

    pEntry = gpStoredUnits2_007BB5C4;
    while (pEntry)
    {
        D2StoredUnitRecordStrc* pNext = pEntry->pNext;
        sub_004DC2B0_FreeRosterInfoList(pEntry->pRosterInfo);
        pEntry->pRosterInfo = 0;
        D2RosterCorpseStrc* pSub = pEntry->pCorpse;
        while (pSub)
        {
            D2RosterCorpseStrc* pSubNext = pSub->pNext;
            FOG_Free(pSub, ".\\GAME\\Roster.cpp", 0x110, 0);
            pSub = pSubNext;
        }
        pEntry->pCorpse = 0;
        FOG_Free(pEntry, ".\\GAME\\Roster.cpp", 0x159, 0);
        pEntry = pNext;
    }
    gpStoredUnits2_007BB5C4 = 0;
}

// 0x004795A0
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
        return pEntry->pNext;
    return gpStoredUnits_007BB5C0;
}

// 0x004795C0
extern "C" const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry)
{
    D2_ASSERT(pEntry, 372);
    return pEntry->szNameEx;
}

// 0x004796B0
void __cdecl sub_004796B0_SortMainListByName()
{
    gpStoredUnits_007BB5C0 = sub_004795F0_SortRosterByName(gpStoredUnits_007BB5C0);
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

// 0x00479750
D2RosterGroupStrc* __fastcall sub_00479750_FindGroup(unsigned short wId)
{
    for (D2RosterGroupStrc* pGroup = gpRosterGroups_007BB5C8; pGroup; pGroup = pGroup->pNext)
    {
        if (pGroup->wPartyId == wId)
        {
            return pGroup;
        }
    }
    return 0;
}

static __forceinline D2RosterGroupStrc* ROSTER_FindGroup(unsigned short wId)
{
    for (D2RosterGroupStrc* pGroup = gpRosterGroups_007BB5C8; pGroup; pGroup = pGroup->pNext)
    {
        if (pGroup->wPartyId == wId)
        {
            return pGroup;
        }
    }
    return 0;
}

// 0x00479770
static D2RosterGroupStrc* sub_00479770_GetOrAddGroup(unsigned short wId)
{
    D2RosterGroupStrc* pGroup = ROSTER_FindGroup(wId);
    if (pGroup)
    {
        return pGroup;
    }
    pGroup = (D2RosterGroupStrc*)FOG_Alloc(sizeof(D2RosterGroupStrc), ".\\GAME\\Roster.cpp", 0x1FC, 0);
    memset(pGroup, 0, 8);
    pGroup->wPartyId = wId;
    pGroup->pNext = gpRosterGroups_007BB5C8;
    gpRosterGroups_007BB5C8 = pGroup;
    return pGroup;
}

// calling-convention shim (not game code)
void __fastcall sub_00479770_Shim(unsigned short* pIds, int nCount)
{
    for (int i = 0; i < nCount; ++i)
    {
        sub_00479770_GetOrAddGroup(pIds[i])->unk0x02 = 1;
    }
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

// 0x004798C0
static void sub_004798C0_MovePlayerGroupToFront(int nPlayerId, unsigned short wPartyId)
{
    D2RosterGroupStrc* pHead = gpRosterGroups_007BB5C8;
    D2RosterGroupStrc* pGroup = pHead;
    D2RosterGroupStrc* pPrevGroup = 0;
    D2StoredUnitRecordStrc* pPrev = 0;
    if (wPartyId == 0xFFFF)
        return;
    while (pGroup ? pGroup->wPartyId != wPartyId : false)
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
    while (pRec ? pRec->dwUnitId != nPlayerId : false)
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

// 0x00479AB0
__declspec(noinline) void __cdecl sub_00479AB0()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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

// 0x00479B80
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00479B80(Obj00479B80* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue18;
}

// 0x00479B90
int __fastcall sub_00479B90(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        return pEntry->wLevel;
    }

    return 0;
}

// 0x00479BA0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00479BA0(Obj00479BA0* pObj) {
    if (pObj) {
        return pObj->dwValue1C;
    }
    return 0;
}

// 0x00479BB0
D2StoredUnitRecordStrc* __fastcall sub_00479BB0_FindRosterUnit(int nUnitId)
{
    return sub_004792E0_FindRosterUnit(nUnitId);
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

// 0x00479D20
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00479D20(Obj00479D20* pObj) {
    if (pObj) {
        return pObj->dwValue30;
    }
    return 1;
}

// 0x00479D30
static void sub_00479D30_TogglePvpFlag(D2StoredUnitRecordStrc* pEntry, unsigned short nFlag)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        sub_00478740_SendPvpCommand(1, pEntry->dwUnitId, sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 1));
    }
}

// 0x00479DE0
void __fastcall sub_00479DE0_TogglePvpFlag2(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        sub_00479D30_TogglePvpFlag(pEntry, 2);
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        sub_00478740_SendPvpCommand(2, pEntry->dwUnitId, sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 2));
    }
}

// 0x00479E20
void __fastcall sub_00479E20_ToggleSquelch(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        sub_00479D30_TogglePvpFlag(pEntry, 4);
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        sub_00478740_SendPvpCommand(3, pEntry->dwUnitId, sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 4));
        pPlayer = sub_00463DD0_GetPlayerUnit();
        if (sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 4))
            sub_00611560_GetSquelchList()->Squelch(pEntry->szNameEx);
        else
            sub_00611560_GetSquelchList()->Unsquelch(pEntry->szNameEx);
    }
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

// 0x00479F60
D2StoredUnitRecordStrc* __cdecl sub_00479F60_LeaveParty()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(!pPlayer ? -1 : pPlayer->dwUnitId);
    D2_ASSERT(pRec, 0x4ED);
    pRec->wPartyId = 0xFFFF;
    pRec->dwPartyFlags = 1;
    sub_00479AB0();
    sub_0049A640();
    return pRec;
}

// 0x00479FC0
void __cdecl sub_00479FC0()
{
    sub_00478780_SendPartyCommand(9, sub_00479F60_LeaveParty()->dwUnitId);
}

// 0x00479FE0
void __fastcall sub_00479FE0_TogglePvpFlag8(D2StoredUnitRecordStrc* pEntry)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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

// 0x0047A0C0
int __fastcall sub_0047A0C0_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord)
{
    if (pRecord)
    {
        return pRecord->dwUnitId;
    }
    return -1;
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

// 0x0047A120
int __fastcall sub_0047A120_IsInPlayerParty(D2StoredUnitRecordStrc* pRecord)
{
    if (pRecord && pRecord->wPartyId != 0xFFFF && sub_00465400_GetPlayerRosterField22(sub_00463DD0_GetPlayerUnit()) == pRecord->wPartyId)
    {
        return 1;
    }
    return 0;
}

// 0x0047A150
int __fastcall sub_0047A150_GetPartyLife(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    if (pRec)
        return pRec->dwPartyLife;
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
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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

// 0x0047A520
int __fastcall sub_0047A520_IsSameParty(int nUnitId1, int nUnitId2)
{
    D2StoredUnitRecordStrc* pRec1 = sub_004792E0_FindRosterUnit(nUnitId1);
    D2StoredUnitRecordStrc* pRec2 = sub_004792E0_FindRosterUnit(nUnitId2);
    if (pRec1 && pRec2 && pRec1->wPartyId == pRec2->wPartyId && pRec1->wPartyId != 0xFFFF)
        return 1;
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

// 0x0047A6B0
int __fastcall sub_0047A6B0_GetOtherPartyLife(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitId);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (nUnitId != (!pPlayer ? -1 : pPlayer->dwUnitId) && pRec)
        return pRec->dwPartyLife;
    return 0;
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

// 0x0047A8B0
void __fastcall sub_0047A8B0_RemoveRosterUnit(int nUnitId)
{
    D2StoredUnitRecordStrc* pPrev = 0;
    D2StoredUnitRecordStrc* pRec = gpStoredUnits_007BB5C0;
    D2_ASSERT(nUnitId != -1, 0x121);
    for (; pRec; pRec = pRec->pNext)
    {
        if (pRec->dwUnitId == nUnitId)
        {
            if (pPrev)
            {
                pPrev->pNext = pRec->pNext;
            }
            else
            {
                gpStoredUnits_007BB5C0 = pRec->pNext;
            }
            sub_004DC2B0_FreeRosterInfoList(pRec->pRosterInfo);
            pRec->pRosterInfo = 0;
            D2RosterCorpseStrc* pCorpse = pRec->pCorpse;
            while (pCorpse)
            {
                D2RosterCorpseStrc* pNext = pCorpse->pNext;
                FOG_Free(pCorpse, ".\\GAME\\Roster.cpp", 0x110, 0);
                pCorpse = pNext;
            }
            pRec->pCorpse = 0;
            FOG_Free(pRec, ".\\GAME\\Roster.cpp", 0x131, 0);
            break;
        }
        pPrev = pRec;
    }
    sub_00479AB0();
    sub_0049A640();
}

// 0x0047A9B0
void __fastcall sub_0047A9B0_SetClientFlag1(int bClear)
{
    if (bClear)
    {
        gdwGlobal_00712EFC &= ~1;
    }
    else
    {
        gdwGlobal_00712EFC |= 1;
    }
}

// 0x0047A9E0
int __cdecl sub_0047A9E0_GetClientFlag40()
{
    return gdwGlobal_00712EFC & 0x40;
}

// 0x0047A9F0
int __cdecl sub_0047A9F0_GetClientFlag80()
{
    return gdwGlobal_00712EFC & 0x80;
}

// 0x0047AA00
int __cdecl sub_0047AA00_GetClientFlag200()
{
    return gdwGlobal_00712EFC & 0x200;
}

// 0x0047AA10
void __fastcall sub_0047AA10_SetGlobal(int nValue)
{
    gdwGlobal_00712F00 = nValue;
}

// 0x0047AA40
int Unicode::isWhitespace() const
{
    if (this->wChar < 0x100)
    {
        return ::isspace(this->wChar);
    }
    return 0;
}

// 0x004B8370
extern "C" void __fastcall sub_004B8370_SetCtrlState(D2PanelCtrlStrc_004B8370* pCtrl, int nState)
{
    D2_ASSERT(pCtrl, 1310);
    pCtrl->nState = nState;
}

// 0x004CA990
extern "C" void* __fastcall sub_004CA990_GetLinkFirst(D2OwnerStrc_004CA990* pOwner)
{
    D2_ASSERT(pOwner, 3171);
    D2LinkStrc_004CA990* pLink = pOwner->pLink;
    if (pLink)
    {
        return pLink->pFirst;
    }

    return 0;
}

extern "C" void __fastcall sub_00515A30_SetValue40(D2SoundObjStrc_00515A30* pSound, int nValue)
{
    D2_ASSERT(pSound, 815);
    pSound->nValue40 = nValue;
}

extern "C" void __fastcall sub_00515A60_SetValue44(D2SoundObjStrc_00515A30* pSound, int nValue)
{
    D2_ASSERT(pSound, 826);
    pSound->nValue44 = nValue;
}

extern "C" void __fastcall sub_00537970_SetClientFlag1(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 518);
    pClient->dwFlags |= 1;
}

#include "gen/data/Source/D2Client/GAME/Roster.inc"
