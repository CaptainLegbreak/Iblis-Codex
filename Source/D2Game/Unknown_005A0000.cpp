#include "D2Txt.h"
#include "D2Game.h"
#include "D2LevelTxt.h"
#include "D2TxtTables.h"
typedef char check_int_width[(sizeof(int) == 4) ? 1 : -1];
typedef char check_ptr_width[(sizeof(void*) == 4) ? 1 : -1];






struct D2DataTablesStrc
{
    char unk0x000[0xBC];
    D2StatesTxt* pStatesTxt;
    char unk0x0C0[0x04];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xAA8];
    D2MonLvlTxt* pMonLvlTxt;
    int nMonLvlTxtRecordCount;
    char unk0xB78[0x20];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x20];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
    char unk0xBCC[0x1C];
    D2PetTypeTxt* pPetTypeTxt;
    char unk0xBEC[0x04];
    int nPetTypeTxtRecordCount;
    char unk0xBF4[0x04];
    D2ItemTypesTxt* pItemTypesTxt;
    int nItemTypesTxtRecordCount;
};

typedef char check_states_size[(sizeof(D2StatesTxt) == 0x3C) ? 1 : -1];
typedef char check_monlvl_size[(sizeof(D2MonLvlTxt) == 0x78) ? 1 : -1];
typedef char check_skills_size[(sizeof(D2SkillsTxt) == 0x23C) ? 1 : -1];
typedef char check_charstats_size[(sizeof(D2CharStatsTxt) == 0xC4) ? 1 : -1];
typedef char check_pettype_size[(sizeof(D2PetTypeTxt) == 0xE0) ? 1 : -1];
typedef char check_itemtypes_size[(sizeof(D2ItemTypesTxt) == 0xE4) ? 1 : -1];
typedef char check_datatables_size[(sizeof(D2DataTablesStrc) == 0xC00) ? 1 : -1];

extern "C" D2DataTablesStrc* sgptDataTables; // 0x00744304

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2ItemTypesTxt* DATATBLS_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}

// 0x00452040
extern "C" D2StatesTxt* __fastcall sub_00452040_GetStatesTxtRecord(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

// 0x00478A20
extern "C" D2PetTypeTxt* __fastcall sub_00478A20_GetPetTypeTxtRecord(int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &sgptDataTables->pPetTypeTxt[nPetType];
    }

    return 0;
}

// 0x004833E0
extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x005A0000
extern "C" D2MonLvlTxt* __fastcall sub_005A0000_GetMonLvlTxtRecord(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
    {
        return &sgptDataTables->pMonLvlTxt[nLevel];
    }

    return 0;
}

// 0x005C8BC0
extern "C" int __fastcall sub_005C8BC0_GetSkillsTxtParam7(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[6];
}

// 0x00628440
extern "C" int __stdcall sub_00628440_GetShootsFromItemType(int nItemType)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(nItemType);
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    return pItemTypesTxtRecord->wShoots;
}
