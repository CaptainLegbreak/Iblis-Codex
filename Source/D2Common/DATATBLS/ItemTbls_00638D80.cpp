#include "D2Common.h"
#include "D2Records.h"
#include "D2TxtTables.h"



enum
{
    TXTFIELD_NONE = 0,
    TXTFIELD_ASCII = 1,
    TXTFIELD_BYTE = 4,
    TXTFIELD_ASCIITOCODE = 10,
    TXTFIELD_CODETOBYTE = 13,
    TXTFIELD_CODETOWORD = 15,
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __stdcall FOG_10215(D2TxtLinkStrc* pLink, int nCode);                                                  // 0x006BD230
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0

extern D2TxtLinkStrc* gpPlayerClassLinker_0096BC34;                                                         // 0x0096BC34
extern D2TxtLinkStrc* gpBodyLocsLinker_0096BC3C;                                                            // 0x0096BC3C
extern D2TxtLinkStrc* gpStorePageLinker_0096BC44;                                                           // 0x0096BC44
extern D2TxtLinkStrc* gpItemTypesLinker_0096C824;                                                           // 0x0096C824
D2ItemTypesTxt* gpItemTypesTxt_0096C828;                                                                    // 0x0096C828
int gnItemTypesTxtRecordCount_0096C82C;                                                                     // 0x0096C82C
extern int gnItemTypesIndex_0096C830;                                                                       // 0x0096C830
extern unsigned int* gpItemTypesEquivalenceLUTs_0096C834;                                                   // 0x0096C834
extern int gbCompileTxt_0096C8B4;                                                                           // 0x0096C8B4
extern int gbLoadFromBin_00744308;                                                                          // 0x00744308
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

// 0x00638CD0
int __fastcall DATATBLS_CheckItemTypesEquivalenceNested(int nItemType1, int nItemType2)
{
    if (nItemType2 <= 0)
        return 1;
    if (nItemType1 <= 0 || nItemType1 >= gnItemTypesTxtRecordCount_0096C82C)
        return 0;
    int nParentItemTypes[128];
    nParentItemTypes[0] = nItemType1;
    int nIndex = 1;
    do
    {
        int nItemType = nParentItemTypes[--nIndex];
        if (nItemType2 == nItemType)
            return 1;
        if (nItemType >= gnItemTypesTxtRecordCount_0096C82C)
            return 0;
        if (nIndex > 124)
            return 0;
        D2ItemTypesTxt* pItemTypesTxtRecord = &gpItemTypesTxt_0096C828[nItemType];
        if (pItemTypesTxtRecord->nEquiv1 > 0)
        {
            nParentItemTypes[nIndex++] = pItemTypesTxtRecord->nEquiv1;
            if (pItemTypesTxtRecord->nEquiv2)
                nParentItemTypes[nIndex++] = pItemTypesTxtRecord->nEquiv2;
        }
    }
    while (nIndex);
    return 0;
}

// 0x00638D80
void __fastcall DATATBLS_LoadItemTypesTxt(void* hArchive)
{
    unsigned int* pItemTypesNest = 0;

    D2BinFieldStrc pTbl[] =
    {
        { "code", TXTFIELD_ASCIITOCODE, 0, 0, &gpItemTypesLinker_0096C824 },
        { "equiv1", TXTFIELD_CODETOWORD, 0, 4, &gpItemTypesLinker_0096C824 },
        { "equiv2", TXTFIELD_CODETOWORD, 0, 6, &gpItemTypesLinker_0096C824 },
        { "repair", TXTFIELD_BYTE, 0, 8, 0 },
        { "body", TXTFIELD_BYTE, 0, 9, 0 },
        { "bodyloc1", TXTFIELD_CODETOBYTE, 0, 10, &gpBodyLocsLinker_0096BC3C },
        { "bodyloc2", TXTFIELD_CODETOBYTE, 0, 11, &gpBodyLocsLinker_0096BC3C },
        { "shoots", TXTFIELD_CODETOWORD, 0, 12, &gpItemTypesLinker_0096C824 },
        { "quiver", TXTFIELD_CODETOWORD, 0, 14, &gpItemTypesLinker_0096C824 },
        { "throwable", TXTFIELD_BYTE, 0, 16, 0 },
        { "reload", TXTFIELD_BYTE, 0, 17, 0 },
        { "reequip", TXTFIELD_BYTE, 0, 18, 0 },
        { "autostack", TXTFIELD_BYTE, 0, 19, 0 },
        { "magic", TXTFIELD_BYTE, 0, 20, 0 },
        { "rare", TXTFIELD_BYTE, 0, 21, 0 },
        { "normal", TXTFIELD_BYTE, 0, 22, 0 },
        { "charm", TXTFIELD_BYTE, 0, 23, 0 },
        { "gem", TXTFIELD_BYTE, 0, 24, 0 },
        { "beltable", TXTFIELD_BYTE, 0, 25, 0 },
        { "maxsock1", TXTFIELD_BYTE, 0, 26, 0 },
        { "maxsock25", TXTFIELD_BYTE, 0, 27, 0 },
        { "maxsock40", TXTFIELD_BYTE, 0, 28, 0 },
        { "treasureclass", TXTFIELD_BYTE, 0, 29, 0 },
        { "rarity", TXTFIELD_BYTE, 0, 30, 0 },
        { "staffmods", TXTFIELD_CODETOBYTE, 0, 31, &gpPlayerClassLinker_0096BC34 },
        { "costformula", TXTFIELD_BYTE, 0, 32, 0 },
        { "class", TXTFIELD_CODETOBYTE, 0, 33, &gpPlayerClassLinker_0096BC34 },
        { "storepage", TXTFIELD_CODETOBYTE, 0, 34, &gpStorePageLinker_0096BC44 },
        { "varinvgfx", TXTFIELD_BYTE, 0, 35, 0 },
        { "invgfx1", TXTFIELD_ASCII, 31, 36, 0 },
        { "invgfx2", TXTFIELD_ASCII, 31, 68, 0 },
        { "invgfx3", TXTFIELD_ASCII, 31, 100, 0 },
        { "invgfx4", TXTFIELD_ASCII, 31, 132, 0 },
        { "invgfx5", TXTFIELD_ASCII, 31, 164, 0 },
        { "invgfx6", TXTFIELD_ASCII, 31, 196, 0 },
        { "end", TXTFIELD_NONE, 0, 0, 0 },
    };

    gpItemTypesLinker_0096C824 = FOG_AllocLinker(".\\DATATBLS\\ItemTbls.cpp", 0x884);
    gpItemTypesTxt_0096C828 = (D2ItemTypesTxt*)DATATBLS_CompileTxt(hArchive, "itemtypes", pTbl, &gnItemTypesTxtRecordCount_0096C82C, sizeof(D2ItemTypesTxt));

    if (!gbCompileTxt_0096C8B4 && gbLoadFromBin_00744308)
    {
        for (int i = 0; i < gnItemTypesTxtRecordCount_0096C82C; ++i)
        {
            FOG_10215(gpItemTypesLinker_0096C824, *(int*)&gpItemTypesTxt_0096C828[i].szCode[0]);
        }
    }

    gnItemTypesIndex_0096C830 = (gnItemTypesTxtRecordCount_0096C82C + 31) / 32;
    const int nCount = gnItemTypesTxtRecordCount_0096C82C * gnItemTypesIndex_0096C830;
    gpItemTypesEquivalenceLUTs_0096C834 = (unsigned int*)FOG_AllocPool(0, sizeof(unsigned int) * nCount, ".\\DATATBLS\\ItemTbls.cpp", 0x893, 0);
    memset(gpItemTypesEquivalenceLUTs_0096C834, 0, sizeof(unsigned int) * nCount);

    for (int i = 0; i < gnItemTypesTxtRecordCount_0096C82C; ++i)
    {
        pItemTypesNest = &gpItemTypesEquivalenceLUTs_0096C834[gnItemTypesIndex_0096C830 * i];

        for (int j = 0; j < gnItemTypesTxtRecordCount_0096C82C; ++j)
        {
            if (DATATBLS_CheckItemTypesEquivalenceNested(i, j))
            {
                pItemTypesNest[j >> 5] |= gdwBitMasks[j & 31];
            }
        }
    }
}
