struct D2RosterInfoStrc;

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

// 0x0047A690
void __fastcall sub_0047A690(int nUnitGUID, unsigned char nLifePct)
{
    D2StoredUnitRecordStrc* pRec = sub_004792E0_FindRosterUnit(nUnitGUID);
    if (pRec)
        pRec->dwPartyLife = nLifePct;
}
