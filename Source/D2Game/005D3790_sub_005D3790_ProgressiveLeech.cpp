struct D2UnitStrc;
struct D2StatListStrc;
struct D2SkillStrc;
struct D2SkillsTxt
{
    char unk_000[0x44];
    unsigned char nPrgDamage;
    char unk_045[0x54 - 0x45];
    short wAuraStat[6];
    char unk_060[0x1DC];
};
struct D2DataTablesStrc
{
    char unk_000[0x16C];
    short* pProgressiveStates;
    short nProgressiveStates;
    char unk_172[0xB98 - 0x172];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk_BA4[0x30];
    int nItemStatCostTxtRecordCount;
};
struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int unk_0C[9];
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall STATLIST_GetStatValue(D2StatListStrc*, int, unsigned short); // 0x00625D00
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc*, int); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0
int __fastcall sub_004E6CA0_GetSkillParamByLevel(int, int); // 0x004E6CA0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __stdcall sub_005D3880_ProgressiveElemental(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage); // 0x005D3880

// calling-convention shim (not game code)
void __stdcall sub_005D3970_ProgressiveElementalConversion(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage); // 0x005D3970

static __forceinline D2SkillsTxt* GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static __declspec(noinline) void __stdcall sub_005D3790_ProgressiveLeech(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage);

// 0x005D3790
static void __stdcall sub_005D3790_ProgressiveLeech(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage)
{
    const int nSkillId = STATLIST_GetStatValue(pStatList, 350, 0);
    D2SkillsTxt* pSkillsTxt = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
        return;
    const int nItemLevel = STATLIST_GetStatValue(pStatList, 351, 0);
    const int nCurrentLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId), 1);
    const int nSkillLevel = nCurrentLevel > nItemLevel ? nCurrentLevel : nItemLevel;
    if (nSkillLevel <= 0)
        return;
    if (pSkillsTxt->wAuraStat[0] < 0 || pSkillsTxt->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
        return;
    const int nCharges = STATLIST_GetStatValue(pStatList, pSkillsTxt->wAuraStat[0], 0);
    if (nCharges <= 0)
        return;
    int nLeech = sub_004E6CA0_GetSkillParamByLevel(nSkillId, nSkillLevel);
    switch (nCharges)
    {
    case 1:
        pDamage->dwLifeLeech += nLeech;
        break;
    case 2:
        pDamage->dwLifeLeech += nLeech;
        pDamage->dwManaLeech += nLeech;
        break;
    case 3:
        nLeech *= 2;
        pDamage->dwLifeLeech += nLeech;
        pDamage->dwManaLeech += nLeech;
        break;
    default:
        break;
    }
}

void __fastcall SKILLS_ApplyProgressiveLeechAndElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D3BA0
// build: context SKILLS_ApplyProgressiveLeechAndElementalDamage
void __fastcall SKILLS_ApplyProgressiveLeechAndElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pDamage || !(pDamage->wResultFlags & 1))
    {
        return;
    }

    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (STATES_CheckState(pUnit, sgptDataTables->pProgressiveStates[i]))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, sgptDataTables->pProgressiveStates[i]);
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, 350, 0);
                D2SkillsTxt* pSkillsTxtRecord = nSkillId > 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount ? sub_0045C4B0_GetSkillsTxtRecord(nSkillId) : 0;
                if (pSkillsTxtRecord)
                {
                    switch (pSkillsTxtRecord->nPrgDamage)
                    {
                    case 2:
                        sub_005D3790_ProgressiveLeech(pUnit, pStatList, pDamage);
                        break;

                    case 3:
                        sub_005D3880_ProgressiveElemental(pUnit, pStatList, pDamage);
                        break;

                    case 4:
                        sub_005D3970_ProgressiveElementalConversion(pUnit, pStatList, pDamage);
                        break;

                    default:
                        break;
                    }
                }
            }
        }
    }
}
