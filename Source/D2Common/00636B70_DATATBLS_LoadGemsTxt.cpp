struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2GemsTxt
{
    char unk0x00[0x28];
    union
    {
        unsigned char szItemCode[4];
        int dwItemCode;
    };
    unsigned short wStringId;
    char unk0x2E[0x92];
};

struct D2ItemsTxt
{
    char unk0x000[0xF0];
    int dwGemOffset;
    char unk0x0F4[0xB4];
};

extern "C" const char gszTxtField_code[];                                                                   // 0x006DCCE0
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern D2TxtLinkStrc* gTxtLink_0096BCC4;                                                                    // 0x0096BCC4
extern D2TxtLinkStrc* gTxtLink_0096BCD8;                                                                    // 0x0096BCD8
void __fastcall sub_006336A0();                                                                 // 0x006336A0
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
D2GemsTxt* gpGemsTxt;                                                                                       // 0x0096CA94
int gnGemsTxtRecordCount;                                                                                   // 0x0096CA90
unsigned short __stdcall D2LANG_GetTblIndex(const char* szReference, void** ppUnicode);                     // 0x00524D30
extern D2ItemsTxt* gpItemsTxt;                                                                              // 0x0096CA5C

// 0x00636B70
void __fastcall DATATBLS_LoadGemsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "name", 1, 31, 0, 0 },
        { "letter", 1, 5, 32, 0 },
        { gszTxtField_code, 11, 0, 40, &gTxtLink_0096BCC4 },
        { "transform", 4, 0, 47, 0 },
        { "nummods", 4, 0, 46, 0 },
        { "weaponmod1code", 19, 0, 48, &gTxtLink_0096BCD8 },
        { "weaponmod1param", 25, 0, 52, (void*)sub_006336A0 },
        { "weaponmod1min", 2, 0, 56, 0 },
        { "weaponmod1max", 2, 0, 60, 0 },
        { "weaponmod2code", 19, 0, 64, &gTxtLink_0096BCD8 },
        { "weaponmod2param", 25, 0, 68, (void*)sub_006336A0 },
        { "weaponmod2min", 2, 0, 72, 0 },
        { "weaponmod2max", 2, 0, 76, 0 },
        { "weaponmod3code", 19, 0, 80, &gTxtLink_0096BCD8 },
        { "weaponmod3param", 25, 0, 84, (void*)sub_006336A0 },
        { "weaponmod3min", 2, 0, 88, 0 },
        { "weaponmod3max", 2, 0, 92, 0 },
        { "helmmod1code", 19, 0, 96, &gTxtLink_0096BCD8 },
        { "helmmod1param", 25, 0, 100, (void*)sub_006336A0 },
        { "helmmod1min", 2, 0, 104, 0 },
        { "helmmod1max", 2, 0, 108, 0 },
        { "helmmod2code", 19, 0, 112, &gTxtLink_0096BCD8 },
        { "helmmod2param", 25, 0, 116, (void*)sub_006336A0 },
        { "helmmod2min", 2, 0, 120, 0 },
        { "helmmod2max", 2, 0, 124, 0 },
        { "helmmod3code", 19, 0, 128, &gTxtLink_0096BCD8 },
        { "helmmod3param", 25, 0, 132, (void*)sub_006336A0 },
        { "helmmod3min", 2, 0, 136, 0 },
        { "helmmod3max", 2, 0, 140, 0 },
        { "shieldmod1code", 19, 0, 144, &gTxtLink_0096BCD8 },
        { "shieldmod1param", 25, 0, 148, (void*)sub_006336A0 },
        { "shieldmod1min", 2, 0, 152, 0 },
        { "shieldmod1max", 2, 0, 156, 0 },
        { "shieldmod2code", 19, 0, 160, &gTxtLink_0096BCD8 },
        { "shieldmod2param", 25, 0, 164, (void*)sub_006336A0 },
        { "shieldmod2min", 2, 0, 168, 0 },
        { "shieldmod2max", 2, 0, 172, 0 },
        { "shieldmod3code", 19, 0, 176, &gTxtLink_0096BCD8 },
        { "shieldmod3param", 25, 0, 180, (void*)sub_006336A0 },
        { "shieldmod3min", 2, 0, 184, 0 },
        { "shieldmod3max", 2, 0, 188, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpGemsTxt = (D2GemsTxt*)DATATBLS_CompileTxt(hArchive, "gems", pTbl, &gnGemsTxtRecordCount, 192);

    char szReference[4];
    void* pUnicode = 0;
    for (int i = 0; i < gnGemsTxtRecordCount; ++i)
    {
        szReference[0] = (gpGemsTxt[i].szItemCode[0] == ' ') ? 0 : gpGemsTxt[i].szItemCode[0];
        szReference[1] = (gpGemsTxt[i].szItemCode[1] == ' ') ? 0 : gpGemsTxt[i].szItemCode[1];
        szReference[2] = (gpGemsTxt[i].szItemCode[2] == ' ') ? 0 : gpGemsTxt[i].szItemCode[2];
        szReference[3] = 0;

        gpGemsTxt[i].wStringId = D2LANG_GetTblIndex(szReference, &pUnicode);
    }

    for (int i = 0; i < gnGemsTxtRecordCount; ++i)
    {
        gpItemsTxt[i].dwGemOffset = -1;
        int nItemCode = gpGemsTxt[i].dwItemCode;
        if (nItemCode >= 0)
        {
            gpItemsTxt[nItemCode].dwGemOffset = i;
        }
    }
}
