typedef unsigned int size_t;

struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinkField;
};

struct D2CompItemStrc
{
    unsigned int dwCode;
    int nWeaponClass;
    int nItemType;
};

struct D2CompPairStrc
{
    unsigned int nKey;
    int nValue;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
    char unk0x84[0x0C];
    unsigned int dwAlternateGfx;
    char unk0x94[0x2C];
    unsigned int dwWeapClass;
    unsigned int dwWeapClass2Hand;
    char unk0xC8[0x56];
    short wType[2];
    char unk0x122[0x86];
};

typedef char check_size_itemstxt[(sizeof(D2ItemsTxt) == 0x1A8) ? 1 : -1];

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0

D2TxtLinkStrc* __stdcall sub_006BD040(const char* szFile, int nLine);                                   // 0x006BD040
void* __stdcall sub_004FAC80();                                                                             // 0x004FAC80
void* __stdcall sub_00504430_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pBinField, int* pRecordCount,
    int nRecordSize);                                                                                       // 0x00504430
void __fastcall sub_00504570(void* hArchive);                                                               // 0x00504570
int __stdcall sub_00504A20_CheckItemType(int nItemType, int nCheckType);                                    // 0x00504A20

extern D2CompItemStrc gaCompItems_0072E1E0[];                                                               // 0x0072E1E0
extern int gaWClassTokens_0072EF30[];                                                                       // 0x0072EF30
extern D2CompPairStrc gaCompPairs_0072EF68[];                                                               // 0x0072EF68
extern unsigned int gnCompPairs_0072EFD0;                                                                   // 0x0072EFD0
extern int gnItemsTxtRecordCount_008426EC;                                                                  // 0x008426EC
extern D2ItemsTxt* gpItemsTxt_008426F0;                                                                     // 0x008426F0
void* gpHitClassTxt_0087D81C;                                                                               // 0x0087D81C
D2TxtLinkStrc* gpHitClassLinker_0087D820;                                                                   // 0x0087D820
D2TxtLinkStrc* gpItemTypesLinker_0087D828;                                                                  // 0x0087D828
void* gpItemTypesTxt_0087D82C;                                                                              // 0x0087D82C
int gnItemTypesTxtRecordCount_0087D830;                                                                     // 0x0087D830
extern int gnItems_0087D834;                                                                                // 0x0087D834
D2CompItemStrc gaItems_0087D838[255];                                                                       // 0x0087D838
int gaItemWeaponClass_0087E430[254];                                                                        // 0x0087E430
int gbCompItemsInit_0087E85C;                                                                               // 0x0087E85C

static __forceinline int sub_GetCompPairValue(unsigned int nKey)
{
    for (unsigned int i = 0; i < gnCompPairs_0072EFD0; ++i)
    {
        if (nKey == gaCompPairs_0072EF68[i].nKey)
        {
            return gaCompPairs_0072EF68[i].nValue;
        }
    }

    return 0;
}

// 0x00506000
void __stdcall sub_00506000_InitCompItems()
{
    if (gbCompItemsInit_0087E85C)
    {
        return;
    }

    gbCompItemsInit_0087E85C = 1;
    memset(gaItems_0087D838, 0, sizeof(gaItems_0087D838));

    D2BinFieldStrc aItemTypesFields[] =
    {
        { "code", 0xA, 0, 0x00, &gpItemTypesLinker_0087D828 },
        { "equiv1", 0xF, 0, 0x04, &gpItemTypesLinker_0087D828 },
        { "equiv2", 0xF, 0, 0x06, &gpItemTypesLinker_0087D828 },
        { "repair", 4, 0, 0x08, 0 },
        { "body", 4, 0, 0x09, 0 },
        { "shoots", 0xF, 0, 0x0C, &gpItemTypesLinker_0087D828 },
        { "quiver", 0xF, 0, 0x0E, &gpItemTypesLinker_0087D828 },
        { "throwable", 4, 0, 0x10, 0 },
        { "reload", 4, 0, 0x11, 0 },
        { "reequip", 4, 0, 0x12, 0 },
        { "autostack", 4, 0, 0x13, 0 },
        { "magic", 4, 0, 0x14, 0 },
        { "normal", 4, 0, 0x16, 0 },
        { "charm", 4, 0, 0x17, 0 },
        { "gem", 4, 0, 0x18, 0 },
        { "beltable", 4, 0, 0x19, 0 },
        { "costformula", 4, 0, 0x20, 0 },
        { "varinvgfx", 4, 0, 0x23, 0 },
        { "invgfx1", 1, 0x1F, 0x24, 0 },
        { "invgfx2", 1, 0x1F, 0x44, 0 },
        { "invgfx3", 1, 0x1F, 0x64, 0 },
        { "invgfx4", 1, 0x1F, 0x84, 0 },
        { "invgfx5", 1, 0x1F, 0xA4, 0 },
        { "end", 0, 0, 0, 0 },
    };

    gpItemTypesLinker_0087D828 = sub_006BD040(".\\Src\\D2Comp.cpp", 0xACB);
    gpItemTypesTxt_0087D82C = sub_00504430_CompileTxt(sub_004FAC80(), "itemtypes", aItemTypesFields,
        &gnItemTypesTxtRecordCount_0087D830, 0xE4);

    D2BinFieldStrc aHitClassFields[] =
    {
        { "code", 0xA, 0, 0, &gpHitClassLinker_0087D820 },
        { "end", 0, 0, 0, 0 },
    };

    gpHitClassLinker_0087D820 = sub_006BD040(".\\Src\\D2Comp.cpp", 0xAD7);
    gpHitClassTxt_0087D81C = sub_00504430_CompileTxt(sub_004FAC80(), "hitclass", aHitClassFields, 0, 4);

    sub_00504570(sub_004FAC80());

    gaItems_0087D838[1].dwCode = ' til';
    gaItems_0087D838[1].nItemType = 3;
    gaItems_0087D838[1].nWeaponClass = gaWClassTokens_0072EF30[0];
    gaItems_0087D838[2].dwCode = ' dem';
    gaItems_0087D838[2].nItemType = 3;
    gaItems_0087D838[2].nWeaponClass = gaWClassTokens_0072EF30[0];
    gaItems_0087D838[3].dwCode = ' yvh';
    gaItems_0087D838[3].nItemType = 3;
    gaItems_0087D838[3].nWeaponClass = gaWClassTokens_0072EF30[0];

    int nNext = 4;
    for (int i = 0; i < gnItemsTxtRecordCount_008426EC; ++i)
    {
        D2ItemsTxt* pRecord = &gpItemsTxt_008426F0[i];

        unsigned int dwCode;
        if (pRecord->dwAlternateGfx)
        {
            dwCode = pRecord->dwAlternateGfx;
        }
        else
        {
            dwCode = pRecord->dwCode;
        }

        int bArmor = 1;
        if (!(sub_00504A20_CheckItemType(pRecord->wType[0], 0x2D) || sub_00504A20_CheckItemType(pRecord->wType[0], 3)
            || sub_00504A20_CheckItemType(pRecord->wType[0], 0x33) || sub_00504A20_CheckItemType(pRecord->wType[0], 0x25))
            || sub_00504A20_CheckItemType(pRecord->wType[0], 0x4B))
        {
            bArmor = 0;
        }

        int j;
        for (j = 0; j < nNext; ++j)
        {
            if (gaItems_0087D838[j].dwCode == dwCode)
            {
                goto next;
            }
        }

        if (bArmor == 1)
        {
            int nSlot = nNext;
            while ((sub_00504A20_CheckItemType(gaCompItems_0072E1E0[nSlot].nItemType, 0x2D)
                       && sub_00504A20_CheckItemType(pRecord->wType[0], 0x2D))
                || (sub_00504A20_CheckItemType(gaCompItems_0072E1E0[nSlot].nItemType, 0x32)
                       && sub_00504A20_CheckItemType(pRecord->wType[0], 0x32))
                || gaItems_0087D838[nSlot].dwCode)
            {
                ++nSlot;
            }

            if (nSlot >= 0xFF)
            {
                nSlot = nNext;
            }

            gaItems_0087D838[nSlot].dwCode = dwCode;
            gaItems_0087D838[nSlot].nItemType = pRecord->wType[0];
            gaItems_0087D838[nSlot].nWeaponClass = gaWClassTokens_0072EF30[sub_GetCompPairValue(pRecord->dwWeapClass)];
            gaItemWeaponClass_0087E430[nSlot] = gaWClassTokens_0072EF30[sub_GetCompPairValue(pRecord->dwWeapClass2Hand)];

            if (nNext == nSlot)
            {
                ++nNext;
            }
        }
next:
        ;
    }

    gnItems_0087D834 = 0xFF;
}

#include "gen/data/Source/D2Win/00506000_sub_00506000_InitCompItems.inc"
