struct D2UnitStrc;
struct D2StatListStrc;
struct D2SkillsTxt
{
    char unk0x000[0x148];
    int dwParam[8];
    char unk0x168[0xD4];
};
struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall sub_006260E0(D2StatListStrc* pStatList); // 0x006260E0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005D2B60
int __fastcall D2GAME_SKILLS_BloodMana_6FD025E0(D2UnitStrc* pUnit, int nManaCost)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 114);
    const int nSkillId = sub_006260E0(pStatList);
    if (STATLIST_UnitGetStatValue(pUnit, 6, 0) >= nManaCost)
    {
        STATLIST_AddUnitStat(pUnit, 6, -nManaCost, 0);
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (STATLIST_UnitGetStatValue(pUnit, 6, 0) < (pSkillsTxtRecord->dwParam[4] << 8))
        {
            pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 114);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
            }
        }
        return 1;
    }
    pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 114);
    if (pStatList)
    {
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
    STATLIST_SetUnitStat(pUnit, 6, 256, 0);
    return 0;
}
