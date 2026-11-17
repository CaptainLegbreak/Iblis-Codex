struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2RareAffixTxt
{
    char unk0x00[0x0C];
    unsigned short wStringId;
    unsigned short wVersion;
    unsigned short wIType[7];
    unsigned short wEType[4];
    char szName[32];
    char unk0x46[2];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBF4];
    D2TxtLinkStrc* pItemTypesLinker;
    char unk0xBF8[0xE70 - 0xBF8];
    int nRareAffixTxtRecordCount;
    D2RareAffixTxt* pRareAffixTxt;
    D2RareAffixTxt* pRareSuffixTxt;
    D2RareAffixTxt* pRarePrefixTxt;
};

extern D2DataTablesStrc gD2DataTables;                                                              // 0x0096BC30

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
unsigned short __stdcall D2LANG_GetTblIndex(const char* szReference, void** ppUnicode);                     // 0x00524D30
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0

// 0x00633F40
void __fastcall DATATBLS_LoadRareSuffix_PrefixTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "name", 1, 0x1F, 0x26, 0 },
        { "version", 3, 0, 0x0E, 0 },
        { "itype1", 15, 0, 0x10, &gD2DataTables.pItemTypesLinker },
        { "itype2", 15, 0, 0x12, &gD2DataTables.pItemTypesLinker },
        { "itype3", 15, 0, 0x14, &gD2DataTables.pItemTypesLinker },
        { "itype4", 15, 0, 0x16, &gD2DataTables.pItemTypesLinker },
        { "itype5", 15, 0, 0x18, &gD2DataTables.pItemTypesLinker },
        { "itype6", 15, 0, 0x1A, &gD2DataTables.pItemTypesLinker },
        { "itype7", 15, 0, 0x1C, &gD2DataTables.pItemTypesLinker },
        { "etype1", 15, 0, 0x1E, &gD2DataTables.pItemTypesLinker },
        { "etype2", 15, 0, 0x20, &gD2DataTables.pItemTypesLinker },
        { "etype3", 15, 0, 0x22, &gD2DataTables.pItemTypesLinker },
        { "etype4", 15, 0, 0x24, &gD2DataTables.pItemTypesLinker },
        { "end", 0, 0, 0, 0 },
    };

    int nRareSuffixRecordCount;
    int nRarePrefixRecordCount;
    D2RareAffixTxt* pRareSuffix = (D2RareAffixTxt*)DATATBLS_CompileTxt(hArchive, "raresuffix", pTbl, &nRareSuffixRecordCount, sizeof(D2RareAffixTxt));
    D2RareAffixTxt* pRarePrefix = (D2RareAffixTxt*)DATATBLS_CompileTxt(hArchive, "rareprefix", pTbl, &nRarePrefixRecordCount, sizeof(D2RareAffixTxt));

    gD2DataTables.nRareAffixTxtRecordCount = nRareSuffixRecordCount + nRarePrefixRecordCount;
    gD2DataTables.pRareAffixTxt = (D2RareAffixTxt*)FOG_AllocPool(0, sizeof(D2RareAffixTxt) * gD2DataTables.nRareAffixTxtRecordCount, ".\\DATATBLS\\ItemTbls.cpp", 0x2F4, 0);
    gD2DataTables.pRareSuffixTxt = gD2DataTables.pRareAffixTxt;
    memcpy(gD2DataTables.pRareSuffixTxt, pRareSuffix, sizeof(D2RareAffixTxt) * nRareSuffixRecordCount);
    gD2DataTables.pRarePrefixTxt = &gD2DataTables.pRareSuffixTxt[nRareSuffixRecordCount];
    memcpy(gD2DataTables.pRarePrefixTxt, pRarePrefix, sizeof(D2RareAffixTxt) * nRarePrefixRecordCount);
    DATATBLS_UnloadBin(pRareSuffix);
    DATATBLS_UnloadBin(pRarePrefix);

    void* pUnicode = 0;
    for (int i = 0; i < gD2DataTables.nRareAffixTxtRecordCount; ++i)
    {
        gD2DataTables.pRareAffixTxt[i].wStringId = D2LANG_GetTblIndex(gD2DataTables.pRareAffixTxt[i].szName, &pUnicode);
    }
}
