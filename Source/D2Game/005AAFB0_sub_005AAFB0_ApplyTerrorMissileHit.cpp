struct D2GameStrc;
struct D2UnitStrc { int dwUnitType; };
struct D2SkillsTxt { char unk_00[0x82]; short nState; char unk_84[0x1B8]; };
struct D2DataTablesStrc
{
    char unk_00[0xC4];
    int nStatesTxtRecordCount;
    char unk_C8[0xAD0];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall MISSILE_GetSkill(D2UnitStrc*); // 0x0064A280
int __stdcall MISSILE_GetLevel(D2UnitStrc*); // 0x0064A210
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc*, D2UnitStrc*); // 0x00552FD0
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, unsigned short); // 0x00625480
int __fastcall sub_004EFC20_GetSkillParam2(int); // 0x004EFC20
int __fastcall sub_004EFCB0_GetSummonLevel(int, int); // 0x004EFCB0
int __fastcall sub_004CC7C0_GetSkillMissileRange(int, int); // 0x004CC7C0
void __fastcall AIUTIL_ApplyTerrorCurseState(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, int); // 0x005DDD00
static __forceinline D2SkillsTxt* GetSkillsTxtRecord(int nSkillId)
{
    D2SkillsTxt* pResult = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        pResult = &sgptDataTables->pSkillsTxt[nSkillId];
    return pResult;
}

// 0x005AAFB0
int __fastcall sub_005AAFB0_ApplyTerrorMissileHit(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pTarget)
{
    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxt = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        pSkillsTxt = &sgptDataTables->pSkillsTxt[nSkillId];
    if (!pSkillsTxt)
        return 1;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
        return 1;
    if (pTarget && (!pTarget ? 6 : pTarget->dwUnitType) == 1)
    {
        const short nState = pSkillsTxt->nState;
        if (nState < 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
            return 1;
        if (!STATES_CheckState(pTarget, nState))
        {
            const int nMaxLevel = STATLIST_UnitGetStatValue(pOwner, 12, 0) + nSkillLevel + sub_004EFC20_GetSkillParam2(nSkillId);
            if (nMaxLevel > STATLIST_UnitGetStatValue(pTarget, 12, 0))
                AIUTIL_ApplyTerrorCurseState(pGame, pOwner, pTarget, nSkillId, sub_004CC7C0_GetSkillMissileRange(nSkillId, nSkillLevel), sub_004EFCB0_GetSummonLevel(nSkillId, nSkillLevel));
        }
    }
    return 0;
}
