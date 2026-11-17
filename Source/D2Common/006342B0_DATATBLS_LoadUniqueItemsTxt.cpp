struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2UniqueItemsTxt
{
    unsigned short wId;
    char szName[32];
    unsigned short wTblIndex;
    char unk0x24[296];
};

extern "C" const char gszTxtField_index[];                                                                  // 0x006E9CCC
extern "C" const char gszTxtField_version[];                                                                // 0x006DCCF0
extern "C" const char gszTxtField_code[];                                                                   // 0x006DCCE0
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern D2TxtLinkStrc* gTxtLink_0096C5E4;                                                                    // 0x0096C5E4
extern D2TxtLinkStrc* gTxtLink_0096BDC8;                                                                    // 0x0096BDC8
extern D2TxtLinkStrc* gTxtLink_0096BCD8;                                                                    // 0x0096BCD8
void __fastcall sub_006336A0();                                                                 // 0x006336A0
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
D2UniqueItemsTxt* gpUniqueitemsTxt;                                                                         // 0x0096C854
int gnUniqueitemsTxtRecordCount;                                                                            // 0x0096C858
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                                    // 0x006BD040
D2TxtLinkStrc* gpUniqueitemsLinker;                                                                         // 0x0096C850
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define TBL_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __stdcall FOG_10216_AddRecordToLinkingTable(D2TxtLinkStrc* pLinker, const char* szName);               // 0x006BD500
unsigned short __stdcall D2LANG_GetTblIndex(const char* szReference, void** ppUnicode);                     // 0x00524D30

// 0x006342B0
void __fastcall DATATBLS_LoadUniqueItemsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_index, 1, 31, 2, 0 },
        { gszTxtField_version, 3, 0, 36, 0 },
        { "enabled", 26, 0, 44, 0 },
        { "ladder", 26, 3, 44, 0 },
        { gszTxtField_code, 9, 0, 40, 0 },
        { "rarity", 3, 0, 48, 0 },
        { "lvl", 3, 0, 52, 0 },
        { "lvl req", 3, 0, 54, 0 },
        { "nolimit", 26, 1, 44, 0 },
        { "carry1", 26, 2, 44, 0 },
        { "chrtransform", 13, 0, 56, &gTxtLink_0096C5E4 },
        { "invtransform", 13, 0, 57, &gTxtLink_0096C5E4 },
        { "flippyfile", 1, 31, 58, 0 },
        { "invfile", 1, 31, 90, 0 },
        { "cost mult", 2, 0, 124, 0 },
        { "cost add", 2, 0, 128, 0 },
        { "dropsound", 20, 0, 132, &gTxtLink_0096BDC8 },
        { "dropsfxframe", 4, 0, 136, 0 },
        { "usesound", 20, 0, 134, &gTxtLink_0096BDC8 },
        { "prop1", 19, 0, 140, &gTxtLink_0096BCD8 },
        { "par1", 25, 0, 144, (void*)sub_006336A0 },
        { "min1", 2, 0, 148, 0 },
        { "max1", 2, 0, 152, 0 },
        { "prop2", 19, 0, 156, &gTxtLink_0096BCD8 },
        { "par2", 25, 0, 160, (void*)sub_006336A0 },
        { "min2", 2, 0, 164, 0 },
        { "max2", 2, 0, 168, 0 },
        { "prop3", 19, 0, 172, &gTxtLink_0096BCD8 },
        { "par3", 25, 0, 176, (void*)sub_006336A0 },
        { "min3", 2, 0, 180, 0 },
        { "max3", 2, 0, 184, 0 },
        { "prop4", 19, 0, 188, &gTxtLink_0096BCD8 },
        { "par4", 25, 0, 192, (void*)sub_006336A0 },
        { "min4", 2, 0, 196, 0 },
        { "max4", 2, 0, 200, 0 },
        { "prop5", 19, 0, 204, &gTxtLink_0096BCD8 },
        { "par5", 25, 0, 208, (void*)sub_006336A0 },
        { "min5", 2, 0, 212, 0 },
        { "max5", 2, 0, 216, 0 },
        { "prop6", 19, 0, 220, &gTxtLink_0096BCD8 },
        { "par6", 25, 0, 224, (void*)sub_006336A0 },
        { "min6", 2, 0, 228, 0 },
        { "max6", 2, 0, 232, 0 },
        { "prop7", 19, 0, 236, &gTxtLink_0096BCD8 },
        { "par7", 25, 0, 240, (void*)sub_006336A0 },
        { "min7", 2, 0, 244, 0 },
        { "max7", 2, 0, 248, 0 },
        { "prop8", 19, 0, 252, &gTxtLink_0096BCD8 },
        { "par8", 25, 0, 256, (void*)sub_006336A0 },
        { "min8", 2, 0, 260, 0 },
        { "max8", 2, 0, 264, 0 },
        { "prop9", 19, 0, 268, &gTxtLink_0096BCD8 },
        { "par9", 25, 0, 272, (void*)sub_006336A0 },
        { "min9", 2, 0, 276, 0 },
        { "max9", 2, 0, 280, 0 },
        { "prop10", 19, 0, 284, &gTxtLink_0096BCD8 },
        { "par10", 25, 0, 288, (void*)sub_006336A0 },
        { "min10", 2, 0, 292, 0 },
        { "max10", 2, 0, 296, 0 },
        { "prop11", 19, 0, 300, &gTxtLink_0096BCD8 },
        { "par11", 25, 0, 304, (void*)sub_006336A0 },
        { "min11", 2, 0, 308, 0 },
        { "max11", 2, 0, 312, 0 },
        { "prop12", 19, 0, 316, &gTxtLink_0096BCD8 },
        { "par12", 25, 0, 320, (void*)sub_006336A0 },
        { "min12", 2, 0, 324, 0 },
        { "max12", 2, 0, 328, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpUniqueitemsLinker = FOG_AllocLinker(".\\DATATBLS\\ItemTbls.cpp", 890);
    gpUniqueitemsTxt = (D2UniqueItemsTxt*)DATATBLS_CompileTxt(hArchive, "uniqueitems", pTbl, &gnUniqueitemsTxtRecordCount, 332);
    TBL_ASSERT(gnUniqueitemsTxtRecordCount < 32767, 892);

    for (int i = 0; i < gnUniqueitemsTxtRecordCount; ++i)
    {
        D2UniqueItemsTxt* pUniqueItemsTxtRecord = &gpUniqueitemsTxt[i];
        pUniqueItemsTxtRecord->wId = i;
        FOG_10216_AddRecordToLinkingTable(gpUniqueitemsLinker, pUniqueItemsTxtRecord->szName);
        void* pUnicode = 0;
        pUniqueItemsTxtRecord->wTblIndex = D2LANG_GetTblIndex(pUniqueItemsTxtRecord->szName, &pUnicode);
        if (!pUniqueItemsTxtRecord->wTblIndex)
        {
            pUniqueItemsTxtRecord->wTblIndex = 5383;
        }
    }
}
