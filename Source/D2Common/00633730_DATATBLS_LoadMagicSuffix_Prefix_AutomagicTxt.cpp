struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2MagicAffixTxt
{
    char szName[0x20];
    unsigned short wTblIndex;
    char unk0x22[0x6E];
};

struct D2MagicAffixDataTbl
{
    int nMagicAffixTxtRecordCount;
    D2MagicAffixTxt* pMagicAffixTxt;
    D2MagicAffixTxt* pMagicSuffix;
    D2MagicAffixTxt* pMagicPrefix;
    D2MagicAffixTxt* pAutoMagic;
};

struct D2DataTablesStrc
{
    char unk0x000[0x004];
    D2TxtLinkStrc* pPlayerClassLinker;
    char unk0x008[0x0A0];
    D2TxtLinkStrc* pPropertiesLinker;
    char unk0x0AC[0x908];
    D2TxtLinkStrc* pColorsLinker;
    char unk0x9B8[0x23C];
    D2TxtLinkStrc* pItemTypesLinker;
    char unk0xBF8[0x254];
    D2MagicAffixDataTbl pMagicAffixDataTables;
};

enum
{
    TXTFIELD_NONE = 0,
    TXTFIELD_ASCII = 1,
    TXTFIELD_DWORD = 2,
    TXTFIELD_WORD = 3,
    TXTFIELD_BYTE = 4,
    TXTFIELD_CODETOBYTE = 13,
    TXTFIELD_CODETOWORD = 15,
    TXTFIELD_NAMETODWORD = 19,
    TXTFIELD_CALCTODWORD = 25,
};

extern "C" const char gszTxtField_version[];                                                                // 0x006DCCF0
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern D2DataTablesStrc gD2DataTables;                                                                      // 0x0096BC30

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0
unsigned short __stdcall sub_00524D30_FindString(const char* szKey, const wchar_t** ppText);                // 0x00524D30
void __fastcall DATATBLS_ItemParamLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn);// 0x006336A0

// 0x00633730
void __fastcall DATATBLS_LoadMagicSuffix_Prefix_AutomagicTxt(void* hArchive)
{
    D2MagicAffixTxt* pMagicSuffix;
    D2MagicAffixTxt* pMagicPrefix;
    D2MagicAffixTxt* pAutoMagic;

    int nSuffixRecords;
    int nPrefixRecords;
    int nAutoMagicRecords;

    D2BinFieldStrc pTbl[] =
    {
        { "name", TXTFIELD_ASCII, 31, 0, 0 },
        { "spawnable", TXTFIELD_BYTE, 0, 84, 0 },
        { "level", TXTFIELD_DWORD, 0, 88, 0 },
        { "group", TXTFIELD_DWORD, 0, 92, 0 },
        { gszTxtField_version, TXTFIELD_WORD, 0, 34, 0 },
        { "divide", TXTFIELD_DWORD, 0, 132, 0 },
        { "multiply", TXTFIELD_DWORD, 0, 136, 0 },
        { "add", TXTFIELD_DWORD, 0, 140, 0 },
        { "rare", TXTFIELD_BYTE, 0, 100, 0 },
        { "maxlevel", TXTFIELD_DWORD, 0, 96, 0 },
        { "levelreq", TXTFIELD_BYTE, 0, 101, 0 },
        { "classspecific", TXTFIELD_CODETOBYTE, 0, 102, &gD2DataTables.pPlayerClassLinker },
        { "class", TXTFIELD_CODETOBYTE, 0, 103, &gD2DataTables.pPlayerClassLinker },
        { "classlevelreq", TXTFIELD_BYTE, 0, 104, 0 },
        { "itype1", TXTFIELD_CODETOWORD, 0, 106, &gD2DataTables.pItemTypesLinker },
        { "itype2", TXTFIELD_CODETOWORD, 0, 108, &gD2DataTables.pItemTypesLinker },
        { "itype3", TXTFIELD_CODETOWORD, 0, 110, &gD2DataTables.pItemTypesLinker },
        { "itype4", TXTFIELD_CODETOWORD, 0, 112, &gD2DataTables.pItemTypesLinker },
        { "itype5", TXTFIELD_CODETOWORD, 0, 114, &gD2DataTables.pItemTypesLinker },
        { "itype6", TXTFIELD_CODETOWORD, 0, 116, &gD2DataTables.pItemTypesLinker },
        { "itype7", TXTFIELD_CODETOWORD, 0, 118, &gD2DataTables.pItemTypesLinker },
        { "etype1", TXTFIELD_CODETOWORD, 0, 120, &gD2DataTables.pItemTypesLinker },
        { "etype2", TXTFIELD_CODETOWORD, 0, 122, &gD2DataTables.pItemTypesLinker },
        { "etype3", TXTFIELD_CODETOWORD, 0, 124, &gD2DataTables.pItemTypesLinker },
        { "etype4", TXTFIELD_CODETOWORD, 0, 126, &gD2DataTables.pItemTypesLinker },
        { "etype5", TXTFIELD_CODETOWORD, 0, 128, &gD2DataTables.pItemTypesLinker },
        { "transformcolor", TXTFIELD_CODETOBYTE, 0, 86, &gD2DataTables.pColorsLinker },
        { "frequency", TXTFIELD_BYTE, 0, 130, 0 },
        { "mod1code", TXTFIELD_NAMETODWORD, 0, 36, &gD2DataTables.pPropertiesLinker },
        { "mod1param", TXTFIELD_CALCTODWORD, 0, 40, (void*)DATATBLS_ItemParamLinker },
        { "mod1min", TXTFIELD_DWORD, 0, 44, 0 },
        { "mod1max", TXTFIELD_DWORD, 0, 48, 0 },
        { "mod2code", TXTFIELD_NAMETODWORD, 0, 52, &gD2DataTables.pPropertiesLinker },
        { "mod2param", TXTFIELD_CALCTODWORD, 0, 56, (void*)DATATBLS_ItemParamLinker },
        { "mod2min", TXTFIELD_DWORD, 0, 60, 0 },
        { "mod2max", TXTFIELD_DWORD, 0, 64, 0 },
        { "mod3code", TXTFIELD_NAMETODWORD, 0, 68, &gD2DataTables.pPropertiesLinker },
        { "mod3param", TXTFIELD_CALCTODWORD, 0, 72, (void*)DATATBLS_ItemParamLinker },
        { "mod3min", TXTFIELD_DWORD, 0, 76, 0 },
        { "mod3max", TXTFIELD_DWORD, 0, 80, 0 },
        { gszTxtField_end, TXTFIELD_NONE, 0, 0, 0 },
    };

    pMagicSuffix = (D2MagicAffixTxt*)DATATBLS_CompileTxt(hArchive, "magicsuffix", pTbl, &nSuffixRecords, sizeof(D2MagicAffixTxt));
    pMagicPrefix = (D2MagicAffixTxt*)DATATBLS_CompileTxt(hArchive, "magicprefix", pTbl, &nPrefixRecords, sizeof(D2MagicAffixTxt));
    pAutoMagic = (D2MagicAffixTxt*)DATATBLS_CompileTxt(hArchive, "automagic", pTbl, &nAutoMagicRecords, sizeof(D2MagicAffixTxt));

    gD2DataTables.pMagicAffixDataTables.nMagicAffixTxtRecordCount = nSuffixRecords + nPrefixRecords + nAutoMagicRecords;
    gD2DataTables.pMagicAffixDataTables.pMagicAffixTxt = (D2MagicAffixTxt*)FOG_AllocPool(0, sizeof(D2MagicAffixTxt) * gD2DataTables.pMagicAffixDataTables.nMagicAffixTxtRecordCount, ".\\DATATBLS\\ItemTbls.cpp", 663, 0);

    gD2DataTables.pMagicAffixDataTables.pMagicSuffix = gD2DataTables.pMagicAffixDataTables.pMagicAffixTxt;
    memcpy(gD2DataTables.pMagicAffixDataTables.pMagicAffixTxt, pMagicSuffix, sizeof(D2MagicAffixTxt) * nSuffixRecords);
    memcpy(gD2DataTables.pMagicAffixDataTables.pMagicPrefix = &gD2DataTables.pMagicAffixDataTables.pMagicSuffix[nSuffixRecords], pMagicPrefix, sizeof(D2MagicAffixTxt) * nPrefixRecords);
    memcpy(gD2DataTables.pMagicAffixDataTables.pAutoMagic = &gD2DataTables.pMagicAffixDataTables.pMagicPrefix[nPrefixRecords], pAutoMagic, sizeof(D2MagicAffixTxt) * nAutoMagicRecords);

    DATATBLS_UnloadBin(pMagicSuffix);
    DATATBLS_UnloadBin(pMagicPrefix);
    DATATBLS_UnloadBin(pAutoMagic);

    const wchar_t* pUnicode = 0;
    for (int i = 0; i < gD2DataTables.pMagicAffixDataTables.nMagicAffixTxtRecordCount; ++i)
    {
        gD2DataTables.pMagicAffixDataTables.pMagicAffixTxt[i].wTblIndex = sub_00524D30_FindString(gD2DataTables.pMagicAffixDataTables.pMagicAffixTxt[i].szName, &pUnicode);
    }
}
