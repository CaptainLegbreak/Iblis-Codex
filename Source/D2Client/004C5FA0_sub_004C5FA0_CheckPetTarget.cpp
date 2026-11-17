struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2PetTypeTxt
{
    unsigned int dwPetType;
    unsigned char nFlags[4];
    char unk0x08[0xD8];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBE8];
    D2PetTypeTxt* pPetTypeTxt;
    void* pPetTypeLink;
    int nPetTypeTxtRecordCount;
};

enum
{
    UNIT_MONSTER = 1,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
int __fastcall sub_00479150_GetOwnerId(int nUnitId);                                                        // 0x00479150
int __fastcall sub_00479180_GetPetType(int nUnitId);                                                        // 0x00479180

static __forceinline D2PetTypeTxt* DATATBLS_GetPetTypeTxtRecord(int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &sgptDataTables->pPetTypeTxt[nPetType];
    }
    return 0;
}

// 0x004C5FA0
int __fastcall sub_004C5FA0_CheckPetTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if ((!pTarget ? 6 : pTarget->dwUnitType) != UNIT_MONSTER)
    {
        return 0;
    }

    const int nOwnerId = sub_00479150_GetOwnerId(!pTarget ? -1 : pTarget->dwUnitId);
    if (nOwnerId != (!pUnit ? -1 : pUnit->dwUnitId))
    {
        return 0;
    }

    D2PetTypeTxt* pPetTypeTxtRecord = DATATBLS_GetPetTypeTxtRecord(sub_00479180_GetPetType(!pTarget ? -1 : pTarget->dwUnitId));
    if (!pPetTypeTxtRecord)
    {
        return 0;
    }

    return (pPetTypeTxtRecord->nFlags[3 >> 3] & gdwBitMasks[3 & 7]) != 0;
}
