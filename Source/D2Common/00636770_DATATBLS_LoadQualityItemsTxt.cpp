struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2QualityItemsTxt
{
    char unk0x00[0x2C];
    char szEffect1[32];
    char szEffect2[32];
    unsigned short wEffect1TblId;
    unsigned short wEffect2TblId;
};

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern D2TxtLinkStrc* gTxtLink_0096BCD8;                                                                    // 0x0096BCD8
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
D2QualityItemsTxt* gpQualityitemsTxt;                                                                       // 0x0096CC54
int gnQualityitemsTxtRecordCount;                                                                           // 0x0096CC50
unsigned short __stdcall D2LANG_GetTblIndex(const char* szReference, void** ppUnicode);                     // 0x00524D30

// 0x00636770
void __fastcall DATATBLS_LoadQualityItemsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "nummods", 4, 0, 10, 0 },
        { "mod1code", 19, 0, 12, &gTxtLink_0096BCD8 },
        { "mod2code", 19, 0, 28, &gTxtLink_0096BCD8 },
        { "mod1param", 2, 0, 16, 0 },
        { "mod1min", 2, 0, 20, 0 },
        { "mod1max", 2, 0, 24, 0 },
        { "mod2param", 2, 0, 32, 0 },
        { "mod2min", 2, 0, 36, 0 },
        { "mod2max", 2, 0, 40, 0 },
        { "effect1", 1, 31, 44, 0 },
        { "effect2", 1, 31, 76, 0 },
        { "armor", 4, 0, 0, 0 },
        { "weapon", 4, 0, 1, 0 },
        { "shield", 4, 0, 2, 0 },
        { "scepter", 4, 0, 3, 0 },
        { "wand", 4, 0, 4, 0 },
        { "staff", 4, 0, 5, 0 },
        { "bow", 4, 0, 6, 0 },
        { "boots", 4, 0, 7, 0 },
        { "gloves", 4, 0, 8, 0 },
        { "belt", 4, 0, 9, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpQualityitemsTxt = (D2QualityItemsTxt*)DATATBLS_CompileTxt(hArchive, "qualityitems", pTbl, &gnQualityitemsTxtRecordCount, 112);

    void* pUnicode = 0;
    for (int i = 0; i < gnQualityitemsTxtRecordCount; ++i)
    {
        if (gpQualityitemsTxt[i].szEffect1[0])
        {
            gpQualityitemsTxt[i].wEffect1TblId = D2LANG_GetTblIndex(gpQualityitemsTxt[i].szEffect1, &pUnicode);
        }

        if (gpQualityitemsTxt[i].szEffect2[0])
        {
            gpQualityitemsTxt[i].wEffect2TblId = D2LANG_GetTblIndex(gpQualityitemsTxt[i].szEffect2, &pUnicode);
        }
    }
}
