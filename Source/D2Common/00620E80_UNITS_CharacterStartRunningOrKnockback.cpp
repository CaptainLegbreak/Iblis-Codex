struct D2StatListStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2CharStatsTxt
{
    char unk0x00[0x40];
    unsigned char nWalkSpeed;
    unsigned char nRunSpeed;
    char unk0x42[0x82];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);           // 0x006270B0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510

// 0x00620E80
static void UNITS_CharacterStartRunningOrKnockback(D2UnitStrc* pUnit, int nClassId)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 4, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    D2CharStatsTxt* pCharStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount) ? &sgptDataTables->pCharStatsTxt[nClassId] : 0;
    const int nWalkSpeed = pCharStatsTxtRecord->nWalkSpeed;
    if (nWalkSpeed)
    {
        sub_006270B0(pStatList, 0x43, 100 * pCharStatsTxtRecord->nRunSpeed / nWalkSpeed - 100, 0);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }
}

// calling-convention shim (not game code)
int __stdcall sub_K14_EmitCharacterStartRunning(D2UnitStrc* pUnit, int nClass)
{
    if (UNITS_GetUnitSizeX(pUnit) == 3)
        UNITS_CharacterStartRunningOrKnockback(pUnit, nClass);
    if (UNITS_GetUnitSizeX(pUnit) == 5)
        UNITS_CharacterStartRunningOrKnockback(pUnit, pUnit->dwClassId);
    return 1;
}
