struct D2UnitStrc;

struct D2MonsterDataStrc
{
    void* pMonstatsTxt;
    unsigned char nComponent[16];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0xAC];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x02];
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
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnBitMasks_006CE268[8];                                                                          // 0x006CE268

D2MissilesTxt* __fastcall DATATBLS_GetMissilesTxtRecord(int nMissileId);                                    // 0x0046ACE0
D2UnitStrc* __fastcall sub_004C5420_CreateFirstMissile(D2UnitStrc* pUnit, int nArg0, int nArg3, int nArg4); // 0x004C5420
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline unsigned char MONSTER_GetComponent10(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent[10];
    }

    return 0;
}

inline unsigned char MONSTER_GetComponent11(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent[11];
    }

    return 0;
}

// 0x004E2A40
int __fastcall sub_004E2A40_ComponentMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    nMissile += MONSTER_GetComponent10(pUnit);
    if (nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (DATATBLS_GetMissilesTxtRecord(nMissile))
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x40;
        }

        if (pSkillsTxtRecord->nFlags[0] & gnBitMasks_006CE268[1])
        {
            sub_004CDC30(pUnit, nMissile, 0, 0, 0, 0, nSkillId, nSkillLevel, 0);
        }
        else
        {
            sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
        }

        return 1;
    }

    return 0;
}

// 0x004E2B30
int __fastcall sub_004E2B30_ComponentMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    nMissile += MONSTER_GetComponent11(pUnit);
    if (nMissile < sgptDataTables->nMissilesTxtRecordCount && DATATBLS_GetMissilesTxtRecord(nMissile))
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x40;
        }

        if (pSkillsTxtRecord->nFlags[0] & gnBitMasks_006CE268[1])
        {
            sub_004CDC30(pUnit, nMissile, 0, 0, 0, 0, nSkillId, nSkillLevel, 0);
        }
        else
        {
            sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
        }

        return 1;
    }

    return 0;
}
