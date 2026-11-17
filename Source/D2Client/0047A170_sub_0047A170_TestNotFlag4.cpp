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

struct D2RosterInfoStrc;

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

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
unsigned int __fastcall sub_004DC440(int nUnitId1, int nUnitId2, unsigned int nFlags);              // 0x004DC440

extern D2StoredUnitRecordStrc* gpStoredUnits_007BB5C0;                                                      // 0x007BB5C0

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
        D2UnitStrc* pPlayer = sub_00463DD0();
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
