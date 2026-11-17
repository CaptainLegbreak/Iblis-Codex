struct D2StoredUnitRecordStrc
{
    char szName[16];
    int dwUnitId;
    char unk0x14[0x28];
    int dwPortalA;
    int dwPortalB;
    char unk0x44[0x22];
    char szNameEx[26];
    D2StoredUnitRecordStrc* pNext;
};

extern D2StoredUnitRecordStrc* gpStoredUnits_007BB5C0;                                                      // 0x007BB5C0

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
