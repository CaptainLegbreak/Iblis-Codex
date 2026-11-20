#include "D2DataTbls.h"
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


extern D2DataTablesStrc sgtDataTables;                                                              // 0x0096BC30

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
        { "itype1", 15, 0, 0x10, &sgtDataTables.pItemTypesLinker },
        { "itype2", 15, 0, 0x12, &sgtDataTables.pItemTypesLinker },
        { "itype3", 15, 0, 0x14, &sgtDataTables.pItemTypesLinker },
        { "itype4", 15, 0, 0x16, &sgtDataTables.pItemTypesLinker },
        { "itype5", 15, 0, 0x18, &sgtDataTables.pItemTypesLinker },
        { "itype6", 15, 0, 0x1A, &sgtDataTables.pItemTypesLinker },
        { "itype7", 15, 0, 0x1C, &sgtDataTables.pItemTypesLinker },
        { "etype1", 15, 0, 0x1E, &sgtDataTables.pItemTypesLinker },
        { "etype2", 15, 0, 0x20, &sgtDataTables.pItemTypesLinker },
        { "etype3", 15, 0, 0x22, &sgtDataTables.pItemTypesLinker },
        { "etype4", 15, 0, 0x24, &sgtDataTables.pItemTypesLinker },
        { "end", 0, 0, 0, 0 },
    };

    int nRareSuffixRecordCount;
    int nRarePrefixRecordCount;
    D2RareAffixTxt* pRareSuffix = (D2RareAffixTxt*)DATATBLS_CompileTxt(hArchive, "raresuffix", pTbl, &nRareSuffixRecordCount, sizeof(D2RareAffixTxt));
    D2RareAffixTxt* pRarePrefix = (D2RareAffixTxt*)DATATBLS_CompileTxt(hArchive, "rareprefix", pTbl, &nRarePrefixRecordCount, sizeof(D2RareAffixTxt));

    sgtDataTables.nRareAffixTxtRecordCount = nRareSuffixRecordCount + nRarePrefixRecordCount;
    sgtDataTables.pRareAffixTxt = (D2RareAffixTxt*)FOG_AllocPool(0, sizeof(D2RareAffixTxt) * sgtDataTables.nRareAffixTxtRecordCount, ".\\DATATBLS\\ItemTbls.cpp", 0x2F4, 0);
    sgtDataTables.pRareSuffixTxt = sgtDataTables.pRareAffixTxt;
    memcpy(sgtDataTables.pRareSuffixTxt, pRareSuffix, sizeof(D2RareAffixTxt) * nRareSuffixRecordCount);
    sgtDataTables.pRarePrefixTxt = &sgtDataTables.pRareSuffixTxt[nRareSuffixRecordCount];
    memcpy(sgtDataTables.pRarePrefixTxt, pRarePrefix, sizeof(D2RareAffixTxt) * nRarePrefixRecordCount);
    DATATBLS_UnloadBin(pRareSuffix);
    DATATBLS_UnloadBin(pRarePrefix);

    void* pUnicode = 0;
    for (int i = 0; i < sgtDataTables.nRareAffixTxtRecordCount; ++i)
    {
        sgtDataTables.pRareAffixTxt[i].wStringId = D2LANG_GetTblIndex(sgtDataTables.pRareAffixTxt[i].szName, &pUnicode);
    }
}
