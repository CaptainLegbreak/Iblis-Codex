struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2LowQualityItemsTxt
{
    char szName[32];
    unsigned short wTblId;
};

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
D2LowQualityItemsTxt* gpLowqualityitemsTxt;                                                                 // 0x0096CC5C
int gnLowqualityitemsTxtRecordCount;                                                                        // 0x0096CC58
unsigned short __stdcall D2LANG_GetTblIndex(const char* szReference, void** ppUnicode);                     // 0x00524D30

// 0x00637500
void __fastcall DATATBLS_LoadLowQualityItemsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Name", 1, 31, 0, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpLowqualityitemsTxt = (D2LowQualityItemsTxt*)DATATBLS_CompileTxt(hArchive, "lowqualityitems", pTbl, &gnLowqualityitemsTxtRecordCount, 34);

    void* pUnicode = 0;
    for (int i = 0; i < gnLowqualityitemsTxtRecordCount; ++i)
    {
        gpLowqualityitemsTxt[i].wTblId = D2LANG_GetTblIndex(gpLowqualityitemsTxt[i].szName, &pUnicode);
    }
}
