struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

extern "C" const char gszTxtField_code[];                                                                   // 0x006DCCE0
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
D2TxtLinkStrc* gTxtLink_0096BCD8;                                                                           // 0x0096BCD8
extern D2TxtLinkStrc* gTxtLink_0096C800;                                                                    // 0x0096C800
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
extern void* gpPropertiesTxt;                                                                               // 0x0096BCD4
int gnPropertiesTxtRecordCount;                                                                             // 0x0096BCDC
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                                    // 0x006BD040
extern D2TxtLinkStrc* gpPropertiesLinker;                                                                   // 0x0096BCD8

// 0x00638630
void __fastcall DATATBLS_LoadPropertiesTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_code, 17, 0, 0, &gTxtLink_0096BCD8 },
        { "set1", 4, 0, 2, 0 },
        { "val1", 3, 0, 10, 0 },
        { "func1", 4, 0, 24, 0 },
        { "stat1", 20, 0, 32, &gTxtLink_0096C800 },
        { "set2", 4, 0, 3, 0 },
        { "val2", 3, 0, 12, 0 },
        { "func2", 4, 0, 25, 0 },
        { "stat2", 20, 0, 34, &gTxtLink_0096C800 },
        { "set3", 4, 0, 4, 0 },
        { "val3", 3, 0, 14, 0 },
        { "func3", 4, 0, 26, 0 },
        { "stat3", 20, 0, 36, &gTxtLink_0096C800 },
        { "set4", 4, 0, 5, 0 },
        { "val4", 3, 0, 16, 0 },
        { "func4", 4, 0, 27, 0 },
        { "stat4", 20, 0, 38, &gTxtLink_0096C800 },
        { "set5", 4, 0, 6, 0 },
        { "val5", 3, 0, 18, 0 },
        { "func5", 4, 0, 28, 0 },
        { "stat5", 20, 0, 40, &gTxtLink_0096C800 },
        { "set6", 4, 0, 7, 0 },
        { "val6", 3, 0, 20, 0 },
        { "func6", 4, 0, 29, 0 },
        { "stat6", 20, 0, 42, &gTxtLink_0096C800 },
        { "set7", 4, 0, 8, 0 },
        { "val7", 3, 0, 22, 0 },
        { "func7", 4, 0, 30, 0 },
        { "stat7", 20, 0, 44, &gTxtLink_0096C800 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096BCD8 = FOG_AllocLinker(".\\DATATBLS\\ItemTbls.cpp", 1942);
    gpPropertiesTxt = DATATBLS_CompileTxt(hArchive, "properties", pTbl, &gnPropertiesTxtRecordCount, 46);
}
