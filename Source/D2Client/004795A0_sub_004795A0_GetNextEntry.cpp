extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
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
    char unk0x34[0x4C];
    D2StoredUnitRecordStrc* pNext;
};

struct D2RosterGroupStrc
{
    int unk0x00;
    D2StoredUnitRecordStrc* pFirst;
    D2RosterGroupStrc* pNext;
};

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
short __fastcall sub_00465400_GetPlayerRosterField22(D2UnitStrc* pUnit);                                    // 0x00465400
void __fastcall sub_00478780_SendPartyCommand(unsigned char nCommand, int nUnitId);                          // 0x00478780
void __cdecl sub_00479AB0();                                                                                // 0x00479AB0
void __cdecl sub_0049A640();                                                                                // 0x0049A640
unsigned int __fastcall sub_004DC440(int nUnitId1, int nUnitId2, unsigned int nFlags);              // 0x004DC440

D2StoredUnitRecordStrc* gpStoredUnits_007BB5C0;                                                             // 0x007BB5C0
extern D2RosterGroupStrc* gpRosterGroups_007BB5C8;                                                          // 0x007BB5C8

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
        D2UnitStrc* pPlayer = sub_00463DD0();
        return sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 1);
    }
    return 0;
}

// 0x00479C60
int __fastcall sub_00479C60(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        return sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 2);
    }
    return 0;
}

// 0x00479CA0
int __fastcall sub_00479CA0(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        return sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 4);
    }
    return 0;
}

// 0x00479CE0
int __fastcall sub_00479CE0(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
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
    D2UnitStrc* pPlayer = sub_00463DD0();
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
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pEntry && pPlayer && sub_004DC440(pEntry->dwUnitId, !pPlayer ? -1 : pPlayer->dwUnitId, 8))
        return 1;
    return 0;
}

// 0x0047A5E0
int __fastcall sub_0047A5E0(D2StoredUnitRecordStrc* pEntry)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pEntry && pPlayer && sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 8))
        return 1;
    return 0;
}

// 0x0047A610
int __fastcall sub_0047A610(D2StoredUnitRecordStrc* pEntry)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pEntry && pPlayer && sub_004DC440(pEntry->dwUnitId, !pPlayer ? -1 : pPlayer->dwUnitId, 1))
        return 1;
    return 0;
}

// 0x0047A640
int __fastcall sub_0047A640(D2StoredUnitRecordStrc* pEntry)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pEntry && pPlayer && sub_004DC440(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 1))
        return 1;
    return 0;
}
