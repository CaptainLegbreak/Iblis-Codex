struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2GambleTxt
{
    unsigned int dwItemCode;
    int nLevel;
    int nItemId;
};

struct D2ItemsTxt
{
    char unk0x000[0xFD];
    unsigned char nLevel;
    char unk0x0FE[0xAA];
};

struct D2GambleDataTbl
{
    int nGambleTxtRecordCount;
    unsigned int* pGambleSelection;
    int pGambleChooseLimit[100];
};

struct D2DataTablesStrc
{
    char unk0x000[0x94];
    D2TxtLinkStrc* pItemsLinker;
    char unk0x098[0xD94];
    D2ItemsTxt* pItemsTxt;
    char unk0xE30[0x50];
    D2GambleDataTbl pGambleDataTables;
};

extern "C" const char gszTxtField_code[];                                                                   // 0x006DCCE0
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern D2DataTablesStrc gD2DataTables;                                                                      // 0x0096BC30
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError);                 // 0x006BD130
extern "C" void __cdecl qsort(void* pBase, unsigned int nCount, unsigned int nSize, int (__cdecl* pfCompare)(const void*, const void*));// 0x00685B50
int __cdecl DATATBLS_CompareGambleTxtRecords(const void* pRecord1, const void* pRecord2);                   // 0x00638AC0
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00638AE0
void __fastcall DATATBLS_LoadGambleTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_code, 9, 0, 0, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    D2GambleTxt* pGambleTxt = (D2GambleTxt*)DATATBLS_CompileTxt(hArchive, "gamble", pTbl, &gD2DataTables.pGambleDataTables.nGambleTxtRecordCount, sizeof(D2GambleTxt));

    if (gD2DataTables.pGambleDataTables.nGambleTxtRecordCount)
    {
        gD2DataTables.pGambleDataTables.pGambleSelection = (unsigned int*)FOG_AllocPool(0, sizeof(unsigned int) * gD2DataTables.pGambleDataTables.nGambleTxtRecordCount, ".\\DATATBLS\\ItemTbls.cpp", 0x7DB, 0);
        for (int i = 0; i < gD2DataTables.pGambleDataTables.nGambleTxtRecordCount; ++i)
        {
            const unsigned int dwItemCode = pGambleTxt[i].dwItemCode;
            const int nItemId = FOG_GetLinkIndex(gD2DataTables.pItemsLinker, dwItemCode, 0);
            D2ItemsTxt* pItemsTxtRecord;
            D2_ASSERT(nItemId >= 0 && (pItemsTxtRecord = &gD2DataTables.pItemsTxt[nItemId]) != 0, 0x7E0);
            pGambleTxt[i].nLevel = pItemsTxtRecord->nLevel;
            pGambleTxt[i].nItemId = nItemId;
        }
        qsort(pGambleTxt, gD2DataTables.pGambleDataTables.nGambleTxtRecordCount, sizeof(D2GambleTxt), DATATBLS_CompareGambleTxtRecords);
    }
    else
    {
        gD2DataTables.pGambleDataTables.pGambleSelection = 0;
    }

    for (int i = 0; i < gD2DataTables.pGambleDataTables.nGambleTxtRecordCount; ++i)
    {
        gD2DataTables.pGambleDataTables.pGambleSelection[i] = pGambleTxt[i].nItemId;
    }

    gD2DataTables.pGambleDataTables.pGambleChooseLimit[0] = 2;

    for (int i = 1; i < 100; ++i)
    {
        gD2DataTables.pGambleDataTables.pGambleChooseLimit[i] = gD2DataTables.pGambleDataTables.nGambleTxtRecordCount;

        for (int nCounter = 0; nCounter < gD2DataTables.pGambleDataTables.nGambleTxtRecordCount; ++nCounter)
        {
            if (i < pGambleTxt[nCounter].nLevel)
            {
                gD2DataTables.pGambleDataTables.pGambleChooseLimit[i] = nCounter;
                break;
            }
        }
    }

    DATATBLS_UnloadBin(pGambleTxt);
}
