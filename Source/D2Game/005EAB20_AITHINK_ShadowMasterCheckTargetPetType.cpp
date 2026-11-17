struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
};

struct D2SkillsTxt
{
    char unk0x000[0xBC];
    unsigned short wSummon;
    signed char nPetType;
    char unk0x0BF[0x23C - 0xBF];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0xBF0 - 0xBA4];
    int nPetTypeTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* pPlayer, int nPetGUID);                         // 0x00574A20

__forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005EAB20
int __fastcall AITHINK_ShadowMasterCheckTargetPetType(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const short nSummonId = pSkillsTxtRecord->wSummon;
    if (!nSummonId)
    {
        return 1;
    }

    const int nTargetClassId = !pTarget ? -1 : pTarget->dwClassId;
    if ((short)pSkillsTxtRecord->wSummon == (unsigned short)nTargetClassId)
    {
        return 0;
    }

    const int nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType < 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount || !pUnit)
    {
        return 1;
    }

    return PLAYERPETS_GetPetTypeFromPetGUID(pUnit, !pTarget ? -1 : pTarget->dwUnitId) != nPetType;
}
