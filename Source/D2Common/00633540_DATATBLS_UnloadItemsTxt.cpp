struct D2TxtLinkStrc;
struct D2ItemsTxt { char unk[0x1A8]; };
struct D2MagicAffixTxt { char unk[0x90]; };
struct D2RareAffixTxt { char unk[0x48]; };
struct D2QualityItemsTxt { char unk[0x70]; };
struct D2GemsTxt { char unk[0xC0]; };
struct D2BooksTxt { char unk[0x20]; };
struct D2LowQualityItemsTxt { char unk[0x22]; };
struct D2ItemRatioTxt;
struct D2RunesTxt;
struct D2ItemStatCostDescStrc
{
    char unk0x00[0x2];
    short nDescPriority;
    char unk[0x8 - 0x2 - 2];
};

struct D2ItemDataTbl { int nItemsTxtRecordCount; D2ItemsTxt* pItemsTxt; };
struct D2MagicAffixDataTbl { int nMagicAffixTxtRecordCount; D2MagicAffixTxt* pMagicAffixTxt; };
struct D2RareAffixDataTbl { int nRareAffixTxtRecordCount; D2RareAffixTxt* pRareAffixTxt; };
struct D2QualityItemDataTbl { int nQualityItemsTxtRecordCount; D2QualityItemsTxt* pQualityItemsTxt; };
struct D2GemDataTbl { int nGemsTxtRecordCount; D2GemsTxt* pGemsTxt; };
struct D2BookDataTbl { int nBooksTxtRecordCount; D2BooksTxt* pBooksTxt; };
struct D2LowQualityItemDataTbl { int nLowQualityItemsTxtRecordCount; D2LowQualityItemsTxt* pLowQualityItemsTxt; };
struct D2ItemRatioDataTbl { int nItemRatioTxtRecordCount; D2ItemRatioTxt* pItemRatioTxt; };
struct D2GambleDataTbl { int nGambleTxtRecordCount; int* pGambleSelection; };
struct D2RuneDataTbl { int nRunesTxtRecordCount; D2RunesTxt* pRunesTxt; };

extern D2TxtLinkStrc* gpItemsLinker;                                                                        // 0x0096BCC4
void* gpPropertiesTxt;                                                                                      // 0x0096BCD4
extern D2TxtLinkStrc* gpPropertiesLinker;                                                                   // 0x0096BCD8
D2TxtLinkStrc* gpRunesLinker;                                                                               // 0x0096BCE0
extern void* gpItemStatCostTxt;                                                                             // 0x0096C7FC
extern D2TxtLinkStrc* gpItemStatCostLinker;                                                                 // 0x0096C800
extern int gnItemStatCostTxtRecordCount;                                                                    // 0x0096C804
extern void* gpStatsWithDescFunc;                                                                           // 0x0096C808
extern int gnStatsWithDescFunc;                                                                             // 0x0096C80C
extern D2TxtLinkStrc* gpItemTypesLinker;                                                                    // 0x0096C824
extern void* gp_0096C828;                                                                                // 0x0096C828
void* gpItemTypesEquivalenceLUTs;                                                                           // 0x0096C834
D2TxtLinkStrc* gpSetsLinker;                                                                                // 0x0096C838
void* gpSetsTxt;                                                                                            // 0x0096C83C
int gnSetsTxtRecordCount;                                                                                   // 0x0096C840
extern D2TxtLinkStrc* gpSetItemsLinker;                                                                     // 0x0096C844
extern void* gpSetItemsTxt;                                                                                 // 0x0096C848
int gnSetItemsTxtRecordCount;                                                                               // 0x0096C84C
extern D2TxtLinkStrc* gpUniqueItemsLinker;                                                                  // 0x0096C850
extern void* gpUniqueItemsTxt;                                                                              // 0x0096C854
extern int gnUniqueItemsTxtRecordCount;                                                                     // 0x0096C858
extern D2ItemDataTbl gItemDataTables;                                                                       // 0x0096CA58
extern unsigned short* gpIndexOldToCurrent;                                                                 // 0x0096CA78
D2MagicAffixDataTbl gMagicAffixDataTables;                                                                  // 0x0096CA7C
extern D2GemDataTbl gGemDataTables;                                                                         // 0x0096CA90
extern D2RuneDataTbl gRuneDataTables;                                                                       // 0x0096CA98
D2RareAffixDataTbl gRareAffixDataTables;                                                                    // 0x0096CAA0
D2GambleDataTbl gGambleDataTables;                                                                          // 0x0096CAB0
extern D2ItemRatioDataTbl gItemRatioDataTables;                                                             // 0x0096CC48
extern D2QualityItemDataTbl gQualityItemDataTables;                                                         // 0x0096CC50
extern D2LowQualityItemDataTbl gLowQualityItemDataTables;                                                   // 0x0096CC58
extern D2BookDataTbl gBookDataTables;                                                                       // 0x0096CC60
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0
void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker);                                                      // 0x006BD0B0
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError);                 // 0x006BD130
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define ITEM_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00633540
void __fastcall DATATBLS_UnloadItemsTxt()
{
    FOG_FreeLinker(gpItemsLinker);

    if (gItemDataTables.pItemsTxt)
    {
        sub_0040B480(0, gItemDataTables.pItemsTxt, ".\\DATATBLS\\ItemTbls.cpp", 456, 0);
    }

    if (gpIndexOldToCurrent)
    {
        sub_0040B480(0, gpIndexOldToCurrent, ".\\DATATBLS\\ItemTbls.cpp", 459, 0);
    }

    gItemDataTables.pItemsTxt = 0;
}

// 0x00633590
D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables()
{
    return &gItemDataTables;
}

// 0x006335A0
int __stdcall DATATBLS_MapOldItemIndexToCurrent(int nItemId)
{
    if (nItemId >= gItemDataTables.nItemsTxtRecordCount)
    {
        return -1;
    }

    if (nItemId < 0)
    {
        return -1;
    }

    ITEM_ASSERT(gpIndexOldToCurrent, 482);
    return gpIndexOldToCurrent[nItemId];
}

// 0x00633640
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId)
{
    int nItemId = FOG_GetLinkIndex(gpItemsLinker, dwCode, 0);
    if (nItemId < 0)
    {
        *pItemId = 0;
        return 0;
    }

    *pItemId = nItemId;
    return &gItemDataTables.pItemsTxt[nItemId];
}

// 0x00633680
int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode)
{
    return FOG_GetLinkIndex(gpItemsLinker, dwCode, 0);
}

// 0x00633EA0
void __fastcall DATATBLS_UnloadMagicSuffix_Prefix_AutomagicTxt()
{
    if (gMagicAffixDataTables.pMagicAffixTxt)
    {
        sub_0040B480(0, gMagicAffixDataTables.pMagicAffixTxt, ".\\DATATBLS\\ItemTbls.cpp", 695, 0);
    }
    gMagicAffixDataTables.pMagicAffixTxt = 0;
}

// 0x00633ED0
D2MagicAffixDataTbl* __stdcall DATATBLS_GetMagicAffixDataTables()
{
    return &gMagicAffixDataTables;
}

// 0x00633EE0
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex)
{
    ITEM_ASSERT(gMagicAffixDataTables.pMagicAffixTxt, 712);
    if (nIndex > gMagicAffixDataTables.nMagicAffixTxtRecordCount || nIndex <= 0)
    {
        return 0;
    }
    else
    {
        return &gMagicAffixDataTables.pMagicAffixTxt[nIndex - 1];
    }
}

// 0x00634220
void __fastcall DATATBLS_UnloadRareSuffix_PrefixTxt()
{
    if (gRareAffixDataTables.pRareAffixTxt)
    {
        sub_0040B480(0, gRareAffixDataTables.pRareAffixTxt, ".\\DATATBLS\\ItemTbls.cpp", 779, 0);
    }
    gRareAffixDataTables.pRareAffixTxt = 0;
}

// 0x00634250
D2RareAffixDataTbl* __fastcall DATATBLS_GetRareAffixDataTables()
{
    return &gRareAffixDataTables;
}

// 0x00634260
D2RareAffixTxt* __stdcall DATATBLS_GetRareAffixTxtRecord(int nId)
{
    if (nId > gRareAffixDataTables.nRareAffixTxtRecordCount || nId <= 0)
    {
        return 0;
    }
    else
    {
        ITEM_ASSERT(gRareAffixDataTables.pRareAffixTxt, 799);
        return &gRareAffixDataTables.pRareAffixTxt[nId - 1];
    }
}

// 0x00634D90
void __fastcall DATATBLS_UnloadUniqueItemsTxt()
{
    FOG_FreeLinker(gpUniqueItemsLinker);
    DATATBLS_UnloadBin(gpUniqueItemsTxt);
    gnUniqueItemsTxtRecordCount = 0;
}

// 0x00636730
void __fastcall DATATBLS_UnloadSets_SetItemsTxt()
{
    FOG_FreeLinker(gpSetsLinker);
    FOG_FreeLinker(gpSetItemsLinker);
    DATATBLS_UnloadBin(gpSetItemsTxt);
    DATATBLS_UnloadBin(gpSetsTxt);
    gnSetsTxtRecordCount = 0;
    gnSetItemsTxtRecordCount = 0;
}

// 0x00636B00
void __fastcall DATATBLS_UnloadQualityItemsTxt()
{
    DATATBLS_UnloadBin(gQualityItemDataTables.pQualityItemsTxt);
}

// 0x00636B10
D2QualityItemDataTbl* __fastcall DATATBLS_GetQualityItemDataTables()
{
    return &gQualityItemDataTables;
}

// 0x00636B20
D2QualityItemsTxt* __stdcall DATATBLS_GetQualityItemsTxtRecord(int nIndex)
{
    if (nIndex >= gQualityItemDataTables.nQualityItemsTxtRecordCount || nIndex == -1)
    {
        return 0;
    }
    else
    {
        ITEM_ASSERT(gQualityItemDataTables.pQualityItemsTxt, 1266);
        ITEM_ASSERT(&gQualityItemDataTables.pQualityItemsTxt[nIndex], 1266 + 1);
        return &gQualityItemDataTables.pQualityItemsTxt[nIndex];
    }
}

// 0x006372A0
void __fastcall DATATBLS_UnloadGemsTxt()
{
    DATATBLS_UnloadBin(gGemDataTables.pGemsTxt);
}

// 0x006372B0
D2GemDataTbl* __fastcall DATATBLS_GetGemDataTables()
{
    return &gGemDataTables;
}

// 0x006372C0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nIndex)
{
    if (nIndex >= gGemDataTables.nGemsTxtRecordCount || nIndex == -1)
    {
        return 0;
    }
    else
    {
        ITEM_ASSERT(gGemDataTables.pGemsTxt, 1379);
        ITEM_ASSERT(&gGemDataTables.pGemsTxt[nIndex], 1379 + 1);
        return &gGemDataTables.pGemsTxt[nIndex];
    }
}

// 0x00637490
void __fastcall DATATBLS_UnloadBooksTxt()
{
    DATATBLS_UnloadBin(gBookDataTables.pBooksTxt);
}

// 0x006374A0
D2BookDataTbl* __fastcall DATATBLS_GetBookDataTables()
{
    return &gBookDataTables;
}

// 0x006374B0
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex)
{
    if (nIndex >= gBookDataTables.nBooksTxtRecordCount || nIndex == -1)
    {
        return 0;
    }
    else
    {
        ITEM_ASSERT(gBookDataTables.pBooksTxt, 1436);
        ITEM_ASSERT(&gBookDataTables.pBooksTxt[nIndex], 1436 + 1);
        return &gBookDataTables.pBooksTxt[nIndex];
    }
}

// 0x006375A0
void __fastcall DATATBLS_UnloadLowQualityItemsTxt()
{
    DATATBLS_UnloadBin(gLowQualityItemDataTables.pLowQualityItemsTxt);
}

// 0x006375B0
D2LowQualityItemDataTbl* __fastcall DATATBLS_GetLowQualityItemDataTables()
{
    return &gLowQualityItemDataTables;
}

// 0x006375C0
D2LowQualityItemsTxt* __stdcall DATATBLS_GetLowQualityItemsTxtRecord(int nIndex)
{
    if (nIndex >= gLowQualityItemDataTables.nLowQualityItemsTxtRecordCount || nIndex == -1)
    {
        return 0;
    }
    else
    {
        ITEM_ASSERT(gLowQualityItemDataTables.pLowQualityItemsTxt, 1488);
        ITEM_ASSERT(&gLowQualityItemDataTables.pLowQualityItemsTxt[nIndex], 1488 + 1);
        return &gLowQualityItemDataTables.pLowQualityItemsTxt[nIndex];
    }
}

// 0x006378F0
void __fastcall DATATBLS_UnloadItemRatioTxt()
{
    DATATBLS_UnloadBin(gItemRatioDataTables.pItemRatioTxt);
}

// 0x00637900
D2ItemRatioDataTbl* __fastcall DATATBLS_GetItemRatioDataTables()
{
    return &gItemRatioDataTables;
}

// 0x006379D0
int __cdecl DATATBLS_CompareItemStatCostDescs(const void* pRecord1, const void* pRecord2)
{
    D2ItemStatCostDescStrc* pElem1 = (D2ItemStatCostDescStrc*)pRecord1;
    D2ItemStatCostDescStrc* pElem2 = (D2ItemStatCostDescStrc*)pRecord2;

    if (pElem1->nDescPriority < pElem2->nDescPriority)
    {
        return -1;
    }

    return pElem1->nDescPriority != pElem2->nDescPriority;
}

// 0x006385D0
void __fastcall DATATBLS_UnloadItemStatCostTxt()
{
    if (gpItemStatCostTxt)
    {
        DATATBLS_UnloadBin(gpItemStatCostTxt);
    }
    gpItemStatCostTxt = 0;

    if (gpItemStatCostLinker)
    {
        FOG_FreeLinker(gpItemStatCostLinker);
    }
    gpItemStatCostLinker = 0;
    gnItemStatCostTxtRecordCount = 0;

    if (gpStatsWithDescFunc)
    {
        sub_0040B480(0, gpStatsWithDescFunc, ".\\DATATBLS\\ItemTbls.cpp", 1891, 0);
    }
    gnStatsWithDescFunc = 0;
}

// 0x00638AA0
void __fastcall DATATBLS_UnloadPropertiesTxt()
{
    DATATBLS_UnloadBin(gpPropertiesTxt);
    FOG_FreeLinker(gpPropertiesLinker);
}

// 0x00638C80
void __fastcall DATATBLS_UnloadGambleTxt()
{
    if (gGambleDataTables.pGambleSelection)
    {
        sub_0040B480(0, gGambleDataTables.pGambleSelection, ".\\DATATBLS\\ItemTbls.cpp", 2061, 0);
        gGambleDataTables.pGambleSelection = 0;
        gGambleDataTables.nGambleTxtRecordCount = 0;
    }
}

// 0x00638CC0
D2GambleDataTbl* __fastcall DATATBLS_GetGambleDataTables()
{
    return &gGambleDataTables;
}

// 0x006393E0
void __fastcall DATATBLS_UnloadItemTypesTxt()
{
    sub_0040B480(0, gpItemTypesEquivalenceLUTs, ".\\DATATBLS\\ItemTbls.cpp", 2215, 0);
    DATATBLS_UnloadBin(gp_0096C828);
    FOG_FreeLinker(gpItemTypesLinker);
}

// 0x00639C90
void __fastcall DATATBLS_UnloadRunesTxt()
{
    DATATBLS_UnloadBin(gRuneDataTables.pRunesTxt);
    FOG_FreeLinker(gpRunesLinker);
}

// 0x00639CB0
D2RuneDataTbl* __fastcall DATATBLS_GetRuneDataTables()
{
    return &gRuneDataTables;
}
