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
    int unk_00;
    unsigned int dwFlags;
    char f_8[0x4C];
    short nAuraStat;
    char unk_56[0x2A];
    short nAuraState;
    short nAuraTargetState;
    char unk_84[0x38];
    unsigned short wSummon;
    signed char nPetType;
    char unk_BF[0x171];
    unsigned char nAiType;
    char unk_231[0xB];
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

int __fastcall AITHINK_ShadowMasterCheckTargetPetType(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x005EAB20
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

struct D2StatListStrc;
struct D2AiTickParamStrc { int unk_00[2]; D2UnitStrc* pTarget; int unk_0C[3]; int bCombat; };
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc*, int); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc*, int, int); // 0x00625D00
// 0x005EABF0
int __fastcall sub_005EABF0_CheckShadowMasterSkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, D2AiTickParamStrc* pAiTick)
{
    int bCombat = pAiTick->bCombat;
    D2UnitStrc* pTarget = pAiTick->pTarget;
    D2SkillsTxt* pSkills = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkills || !AITHINK_ShadowMasterCheckTargetPetType(pGame, pOwner, pUnit, nSkillId)) return 0;
    if (bCombat)
    {
        if (pSkills->nAiType != 4 && pSkills->nAiType != 13) return 0;
    }
    else
    {
        if (pSkills->nAiType == 4 || pSkills->nAiType == 13) return 0;
    }
    if (pSkills->nAiType == 1 && pSkills->nAuraState > 0 && STATES_CheckState(pUnit, pSkills->nAuraState)) return 0;
    if (!pTarget)
    {
        switch (pSkills->nAiType)
        {
        case 2: case 4: case 5: case 11: case 12: case 13: return 0;
        }
    }
    if (pSkills->nAiType == 2)
    {
        if (pSkills->nAuraState > 0 && STATES_CheckState(pUnit, pSkills->nAuraState)) return 0;
        if (pSkills->nAuraTargetState > 0 && STATES_CheckState(pTarget, pSkills->nAuraTargetState)) return 0;
    }
    if ((unsigned char)pSkills->dwFlags & (unsigned char)gdwBitMasks[2])
    {
        if (pSkills->nAuraState > 0 && STATES_CheckState(pUnit, pSkills->nAuraState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkills->nAuraState);
            if (pStatList && STATLIST_GetStatValue(pStatList, pSkills->nAuraStat, 0) >= 3) return 0;
        }
    }
    return 1;
}
