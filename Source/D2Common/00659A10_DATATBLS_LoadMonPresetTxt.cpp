struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinkField;
};

struct D2MonPresetTxt
{
    unsigned char nAct;
    unsigned char nType;
    unsigned short nPlace;
};

D2MonPresetTxt* gpMonPresetTxt;                                                                             // 0x0096C6D8
extern D2MonPresetTxt* gpMonPresetTxtActSections[5];                                                        // 0x0096C6DC
extern int gnMonPresetTxtActRecordCounts[5];                                                                // 0x0096C6F0
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
void __fastcall DATATBLS_MonPresetPlaceLinker(char* pSrc, void* pRecord, int nOffset, int nValue, int nTxtRow, int nTxtColumn); // 0x00659990

// 0x00659A10
void __fastcall DATATBLS_LoadMonPresetTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Act", 4, 0, 0, 0 },
        { "Place", 0x17, 0, 0, (void*)DATATBLS_MonPresetPlaceLinker },
        { gszTxtField_end, 0, 0, 0, 0 },
    };
    int nRecordCount = 0;

    D2MonPresetTxt* pMonPresetTxt = (D2MonPresetTxt*)DATATBLS_CompileTxt(hArchive, "monpreset", pTbl, &nRecordCount, sizeof(D2MonPresetTxt));

    gpMonPresetTxt = pMonPresetTxt;
    D2MonPresetTxt* pRecord = pMonPresetTxt;
    gpMonPresetTxtActSections[0] = pMonPresetTxt;

    int nAct = 0;
    int nActRecords = 0;
    for (int i = 0; i < nRecordCount; ++i, ++pRecord)
    {
        while (pRecord->nAct > nAct + 1)
        {
            gnMonPresetTxtActRecordCounts[nAct] = nActRecords;
            ++nAct;
            nActRecords = 0;
            gpMonPresetTxtActSections[nAct] = pRecord;
        }

        ++nActRecords;
    }

    gnMonPresetTxtActRecordCounts[nAct] = nActRecords;
}
