struct D2SkillsTxt
{
    char unk0x000[0x194];
    short wSkillDesc;
    char unk0x196[0xA6];
};

struct D2SkillDescTxt
{
    char unk0x00[0x08];
    unsigned short wStrName;
    unsigned short wStrShort;
    unsigned short wStrLong;
    char unk0x0E[0x112];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB8C];
    D2SkillDescTxt* pSkillDescTxt;
    char unk0xB90[0x04];
    int nSkillDescTxtRecordCount;
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

typedef char chkSkillsTxt_M125[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];
typedef char chkSkillDescTxt_M125[sizeof(D2SkillDescTxt) == 0x120 ? 1 : -1];

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

static D2SkillsTxt* sub_H14_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static D2SkillDescTxt* sub_H14_GetSkillDescTxtRecord(int nSkillDesc)
{
    if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
        return &sgptDataTables->pSkillDescTxt[nSkillDesc];
    return 0;
}

// 0x004E6D40
static __declspec(noinline) unsigned short sub_004E6D40_GetSkillDescStrName(int nSkillId)
{
    D2SkillDescTxt* pSkillDescTxt = 0;
    D2SkillsTxt* pSkillsTxt = sub_H14_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
        pSkillDescTxt = sub_H14_GetSkillDescTxtRecord(pSkillsTxt->wSkillDesc);
    if (!pSkillDescTxt)
        return 0x1506;
    return pSkillDescTxt->wStrName;
}

// 0x004E6D90
static __declspec(noinline) unsigned short sub_004E6D90_GetSkillDescStrShort(int nSkillId)
{
    D2SkillDescTxt* pSkillDescTxt = 0;
    D2SkillsTxt* pSkillsTxt = sub_H14_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
        pSkillDescTxt = sub_H14_GetSkillDescTxtRecord(pSkillsTxt->wSkillDesc);
    if (!pSkillDescTxt)
        return 0x1506;
    return pSkillDescTxt->wStrShort;
}

unsigned short __stdcall sub_M125_Emit_004E6D40(int nUnused1, int nUnused2, int nUnused3, int nSkillId)
{
    return sub_004E6D40_GetSkillDescStrName(nSkillId);
}

unsigned short __stdcall sub_M125_Emit_004E6D90(int nUnused1, int nUnused2, int nUnused3, int nSkillId)
{
    return sub_004E6D90_GetSkillDescStrShort(nSkillId);
}
