struct D2SkillsTxt
{
    char unk0x000[0x194];
    short wSkillDesc;
    char unk0x196[0xA6];
};

struct D2SkillDescTxt
{
    char unk0x00[0x0C];
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

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
const wchar_t* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
wchar_t* __fastcall sub_00526700(wchar_t* pDest, const wchar_t* pSource);                                 // 0x00526700

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

// 0x004E6DE0
static __declspec(noinline) unsigned short sub_004E6DE0_GetSkillDescStrLong(int nSkillId)
{
    D2SkillDescTxt* pSkillDescTxt = 0;
    D2SkillsTxt* pSkillsTxt = sub_H14_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
        pSkillDescTxt = sub_H14_GetSkillDescTxtRecord(pSkillsTxt->wSkillDesc);

    if (!pSkillDescTxt)
        return 0x1506;

    return pSkillDescTxt->wStrLong;
}

static int sub_004E83B0_AppendSkillDescStrLong(wchar_t* wszOut, int nSkillId)
{
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(sub_004E6DE0_GetSkillDescStrLong(nSkillId)));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

int sub_H14_Emit_004E83B0(wchar_t* wszOut, int nSkillId)
{
    return sub_004E83B0_AppendSkillDescStrLong(wszOut, nSkillId);
}
