struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinkField;
};

struct D2CompItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
    char unk0x84[0x72];
    unsigned short wVersion;
    char unk0xF8[0xB0];
};

extern "C" const char gszD2CompSourceFile[];                                                                // 0x006DCC20
extern "C" const char szBinFieldEnd_006D9060[];                                                             // 0x006D9060
extern "C" const char szItemsTableMisc_006DCC70[];                                                          // 0x006DCC70
extern "C" const char szItemsTableArmor_006DCC78[];                                                         // 0x006DCC78
extern "C" const char szItemsFieldTransform_006DCC80[];                                                     // 0x006DCC80
extern "C" const char szItemsField1or2Handed_006DCC8C[];                                                    // 0x006DCC8C
extern "C" const char szItemsField2HandedWClass_006DCC98[];                                                 // 0x006DCC98
extern "C" const char szItemsFieldWClass_006DCCA8[];                                                        // 0x006DCCA8
extern "C" const char szItemsFieldComponent_006DCCB0[];                                                     // 0x006DCCB0
extern "C" const char szItemsFieldLevel_006DCCBC[];                                                         // 0x006DCCBC
extern "C" const char szItemsFieldSpawnable_006DCCC4[];                                                     // 0x006DCCC4
extern "C" const char szItemsFieldAlternateGfx_006DCCD0[];                                                  // 0x006DCCD0
extern "C" const char szItemTypesFieldCode_006DCCE0[];                                                      // 0x006DCCE0
extern "C" const char szItemsFieldType_006DCCE8[];                                                          // 0x006DCCE8
extern "C" const char szItemsFieldVersion_006DCCF0[];                                                       // 0x006DCCF0
extern "C" const char szItemsTableWeapons_006DCCF8[];                                                       // 0x006DCCF8

int gnItemsTotalCount_008426EC;                                                                             // 0x008426EC
D2CompItemsTxt* gpItemsTxt_008426F0;                                                                        // 0x008426F0
D2CompItemsTxt* gpWeaponsTxt_008426F4;                                                                      // 0x008426F4
int gnWeaponsTxtRecordCount_008426F8;                                                                       // 0x008426F8
D2CompItemsTxt* gpArmorTxt_008426FC;                                                                        // 0x008426FC
int gnArmorTxtRecordCount_00842700;                                                                         // 0x00842700
D2CompItemsTxt* gpMiscTxt_00842704;                                                                         // 0x00842704
int gnMiscTxtRecordCount_00842708;                                                                          // 0x00842708
unsigned short* gpItemsVersion0Index_0084270C;                                                              // 0x0084270C
D2TxtLinkStrc* gpItemsLinker_0087D824;                                                                      // 0x0087D824
extern D2TxtLinkStrc* gpItemTypesLinker_0087D828;                                                           // 0x0087D828

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
D2TxtLinkStrc* __stdcall sub_006BD040(const char* szFile, int nLine);                                   // 0x006BD040
void __stdcall sub_006BD230_AddLinkCode(D2TxtLinkStrc* pLinker, unsigned int dwCode);                       // 0x006BD230
void* __stdcall sub_00504430_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pBinField, int* pRecordCount, int nRecordSize); // 0x00504430

// 0x00504570
void __fastcall sub_00504570_LoadItems(void* hArchive)
{
    D2BinFieldStrc aItemsFields[] =
    {
        { szItemsFieldVersion_006DCCF0, 3, 0, 0xF6, 0 },
        { szItemsFieldType_006DCCE8, 0xF, 0, 0x11E, &gpItemTypesLinker_0087D828 },
        { szItemTypesFieldCode_006DCCE0, 9, 0, 0x80, 0 },
        { szItemsFieldAlternateGfx_006DCCD0, 9, 0, 0x90, 0 },
        { szItemsFieldSpawnable_006DCCC4, 4, 0, 0x133, 0 },
        { szItemsFieldLevel_006DCCBC, 4, 0, 0xFD, 0 },
        { szItemsFieldComponent_006DCCB0, 4, 0, 0x115, 0 },
        { szItemsFieldWClass_006DCCA8, 9, 0, 0xC0, 0 },
        { szItemsField2HandedWClass_006DCC98, 9, 0, 0xC4, 0 },
        { szItemsField1or2Handed_006DCC8C, 6, 0, 0x13D, 0 },
        { szItemsFieldTransform_006DCC80, 4, 0, 0x141, 0 },
        { szBinFieldEnd_006D9060, 0, 0, 0, 0 },
    };

    D2CompItemsTxt* pWeapons = (D2CompItemsTxt*)sub_00504430_CompileTxt(hArchive, szItemsTableWeapons_006DCCF8, aItemsFields, &gnWeaponsTxtRecordCount_008426F8, sizeof(D2CompItemsTxt));
    D2CompItemsTxt* pArmor = (D2CompItemsTxt*)sub_00504430_CompileTxt(hArchive, szItemsTableArmor_006DCC78, aItemsFields, &gnArmorTxtRecordCount_00842700, sizeof(D2CompItemsTxt));
    D2CompItemsTxt* pMisc = (D2CompItemsTxt*)sub_00504430_CompileTxt(hArchive, szItemsTableMisc_006DCC70, aItemsFields, &gnMiscTxtRecordCount_00842708, sizeof(D2CompItemsTxt));

    gnItemsTotalCount_008426EC = gnArmorTxtRecordCount_00842700 + gnMiscTxtRecordCount_00842708 + gnWeaponsTxtRecordCount_008426F8;

    gpItemsTxt_008426F0 = (D2CompItemsTxt*)FOG_AllocPool(0, gnItemsTotalCount_008426EC * sizeof(D2CompItemsTxt), gszD2CompSourceFile, 0xA34, 0);
    D2CompItemsTxt* pItems = gpItemsTxt_008426F0;
    gpWeaponsTxt_008426F4 = gpItemsTxt_008426F0;
    memcpy(gpItemsTxt_008426F0, pWeapons, gnWeaponsTxtRecordCount_008426F8 * sizeof(D2CompItemsTxt));
    pItems += gnWeaponsTxtRecordCount_008426F8;
    gpArmorTxt_008426FC = pItems;
    memcpy(pItems, pArmor, gnArmorTxtRecordCount_00842700 * sizeof(D2CompItemsTxt));
    pItems += gnArmorTxtRecordCount_00842700;
    gpMiscTxt_00842704 = pItems;
    memcpy(pItems, pMisc, gnMiscTxtRecordCount_00842708 * sizeof(D2CompItemsTxt));

    FOG_FreePool(0, (char*)pWeapons - 4, gszD2CompSourceFile, 0xA44, 0);
    FOG_FreePool(0, (char*)pArmor - 4, gszD2CompSourceFile, 0xA45, 0);
    FOG_FreePool(0, (char*)pMisc - 4, gszD2CompSourceFile, 0xA46, 0);

    gpItemsVersion0Index_0084270C = (unsigned short*)FOG_AllocPool(0, gnItemsTotalCount_008426EC * sizeof(unsigned short), gszD2CompSourceFile, 0xA4B, 0);
    memset(gpItemsVersion0Index_0084270C, 0, gnItemsTotalCount_008426EC * sizeof(unsigned short));

    int i = 0;
    if (i < gnItemsTotalCount_008426EC)
    {
        D2CompItemsTxt* pRecords = gpItemsTxt_008426F0;
        int nCount = 0;
        do
        {
            if (!pRecords[i].wVersion)
            {
                gpItemsVersion0Index_0084270C[nCount] = i;
                ++nCount;
            }
            ++i;
        }
        while (i < gnItemsTotalCount_008426EC);
    }

    gpItemsLinker_0087D824 = sub_006BD040(gszD2CompSourceFile, 0xA56);
    for (int i = 0; i < gnItemsTotalCount_008426EC; ++i)
    {
        sub_006BD230_AddLinkCode(gpItemsLinker_0087D824, gpItemsTxt_008426F0[i].dwCode);
    }
}
