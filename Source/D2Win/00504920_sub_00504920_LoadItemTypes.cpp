struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinkField;
};

extern "C" const char szItemTypesFieldCode_006DCCE0[];                                                      // 0x006DCCE0
extern "C" const char szItemTypesFieldEquiv1_006DCD14[];                                                    // 0x006DCD14
extern "C" const char szItemTypesFieldEquiv2_006DCD0C[];                                                    // 0x006DCD0C
extern "C" const char szBinFieldEnd_006D9060[];                                                             // 0x006D9060
extern "C" const char szItemTypesTable_006DCD00[];                                                          // 0x006DCD00
extern D2TxtLinkStrc* gpItemTypesLinker_0087D828;                                                           // 0x0087D828
extern void* gpItemTypesTxt_0087D82C;                                                                       // 0x0087D82C
extern int gnItemTypesTxtRecordCount_0087D830;                                                              // 0x0087D830

D2TxtLinkStrc* __stdcall sub_006BD040(const char* szFile, int nLine);                                   // 0x006BD040
void* __stdcall sub_00504430_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pBinField, int* pRecordCount, int nRecordSize); // 0x00504430

// 0x00504920
void __fastcall sub_00504920_LoadItemTypes(void* hArchive)
{
    D2BinFieldStrc aItemTypesFields[] =
    {
        { szItemTypesFieldCode_006DCCE0, 0xA, 0, 0, &gpItemTypesLinker_0087D828 },
        { szItemTypesFieldEquiv1_006DCD14, 0xF, 0, 4, &gpItemTypesLinker_0087D828 },
        { szItemTypesFieldEquiv2_006DCD0C, 0xF, 0, 6, &gpItemTypesLinker_0087D828 },
        { szBinFieldEnd_006D9060, 0, 0, 0, 0 },
    };

    gpItemTypesLinker_0087D828 = sub_006BD040(".\\Src\\D2Comp.cpp", 0xA97);
    gpItemTypesTxt_0087D82C = sub_00504430_CompileTxt(hArchive, szItemTypesTable_006DCD00, aItemTypesFields, &gnItemTypesTxtRecordCount_0087D830, 0xE4);
}
