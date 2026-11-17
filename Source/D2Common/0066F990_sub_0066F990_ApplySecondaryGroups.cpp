struct D2SeedStrc
{
    unsigned int dwLow;
    unsigned int dwHigh;
};
struct D2DrlgSubstGroupStrc
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int field_10;
    int field_14;
};
struct D2DrlgFileStrc
{
    char pad_00[76];
    int nSubstGroups;
    D2DrlgSubstGroupStrc* pSubstGroups;
};
struct D2LvlSubTxt
{
    int dwType;
    char pad_04[64];
    int dwBordType;
    char pad_after_border[8];
    D2DrlgFileStrc* pDrlgFile;
    char tail[264];
};
struct D2DrlgDrlgStrc
{
    char pad_00[1124];
    void* hArchive;
};
struct D2DrlgLevelStrc
{
    char pad_00[436];
    D2DrlgDrlgStrc* pDrlg;
    char pad_after_drlg[12];
    D2SeedStrc tSeed;
};
struct D2UnkOutdoorStrc
{
    D2DrlgLevelStrc* pLevel;
    char pad_04[16];
    int field_14;
    int nLvlSubId;
};

extern int __fastcall sub_0045C3E0_RollLimited(D2SeedStrc* pSeed, int nLimit); // 0x0045C3E0
extern D2LvlSubTxt* __fastcall DATATBLS_GetLvlSubTxtRecord(int nId); // 0x0061FA90
extern int __stdcall sub_0066F690_ApplySubstGroup(D2UnkOutdoorStrc* pOutdoor, D2LvlSubTxt* pRecord, D2DrlgSubstGroupStrc* pGroup); // 0x0066F690
extern void __fastcall DRLGTILESUB_InitializeDrlgFile(void* hArchive, D2LvlSubTxt* pRecord); // 0x006704E0

// 0x0066F990
static __declspec(noinline) void __stdcall sub_0066F990_ApplySecondaryGroups(D2UnkOutdoorStrc* pOutdoor, D2LvlSubTxt* pRecord)
{
    D2DrlgFileStrc* pFile = pRecord->pDrlgFile;
    D2DrlgLevelStrc* pLevel = pOutdoor->pLevel;
    const int nGroups = pFile->nSubstGroups;
    int nStart = 0;
    if (nGroups)
    {
        if (pOutdoor->field_14 == -1)
            pOutdoor->field_14 = 62;
        if (!pRecord->dwBordType)
            nStart = sub_0045C3E0_RollLimited(&pLevel->tSeed, nGroups);
        for (int i = 0; i < nGroups; ++i)
        {
            if (sub_0066F690_ApplySubstGroup(pOutdoor, pRecord, &pFile->pSubstGroups[(nStart + i) % nGroups])
                && !pRecord->dwBordType)
                break;
        }
    }
}

// 0x00670750
void __fastcall sub_00670750_ApplySubstitutionBorder(D2UnkOutdoorStrc* pOutdoor)
{
    D2LvlSubTxt* pRecord = DATATBLS_GetLvlSubTxtRecord(pOutdoor->nLvlSubId);
    void* hArchive = pOutdoor->pLevel->pDrlg->hArchive;
    while (pRecord->dwType == pOutdoor->nLvlSubId)
    {
        DRLGTILESUB_InitializeDrlgFile(hArchive, pRecord);
        sub_0066F990_ApplySecondaryGroups(pOutdoor, pRecord);
        ++pRecord;
    }
}
