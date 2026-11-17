struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC0];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[2];
    unsigned char nFlags[8];
    char unk0x00C[0xDE];
    short wCltMissileA;
    char unk0x0EC[0x150];
};

struct D2MissilesTxt
{
    char unk0x000[0x1A4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    void* pMissilesLinker;
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnBitMasks_006CE268[8];                                                                          // 0x006CE268

D2MissilesTxt* __fastcall DATATBLS_GetMissilesTxtRecord(int nMissileId);                                    // 0x0046ACE0
D2UnitStrc* __fastcall sub_004C5420_CreateFirstMissile(D2UnitStrc* pUnit, int nArg0, int nArg3, int nArg4); // 0x004C5420
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30
int __stdcall D2COMMON_11039_CheckWeaponIsMissileBased(D2UnitStrc* pUnit, int* pValue);                    // 0x00645F00

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_J03(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline_J03(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004E2C20
int __fastcall sub_004E2C20_WeaponOrSkillMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_J03(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nMissile = D2COMMON_11039_CheckWeaponIsMissileBased(pUnit, &nSkillLevel);
    if (nMissile && nMissile != 0x1F)
    {
        if (DATATBLS_GetMissilesTxtRecordInline_J03(nMissile))
        {
            sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
            return 1;
        }

        return 0;
    }

    const int nCltMissile = pSkillsTxtRecord->wCltMissileA;
    if (nCltMissile < 0 || nCltMissile >= sgptDataTables->nMissilesTxtRecordCount || !DATATBLS_GetMissilesTxtRecord(nCltMissile))
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[0] & gnBitMasks_006CE268[1])
    {
        sub_004CDC30(pUnit, nCltMissile, 0, 0, 0, 0, nSkillId, nSkillLevel, 0);
    }
    else
    {
        sub_004C5420_CreateFirstMissile(pUnit, nCltMissile, nSkillId, nSkillLevel);
    }

    return 1;
}
