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

extern "C" const char gszTxtField_code[];                                                                   // 0x006DCCE0
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern "C" const char gszGambleTxtName[];                                                                   // 0x006EA750
extern "C" const char gszItemsTblsSourceFile[];                                                             // 0x006E90E4
extern D2GambleDataTbl gGambleDataTables;                                                                   // 0x0096CAB0
extern D2TxtLinkStrc* gpItemsLinker;                                                                        // 0x0096BCC4
extern D2ItemsTxt* gpItemsTxt;                                                                              // 0x0096CA5C
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError);                 // 0x006BD130
extern "C" void __cdecl qsort(void* pBase, unsigned int nCount, unsigned int nSize, int (__cdecl* pfCompare)(const void*, const void*));// 0x00685B50
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define TBL_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00638AC0
int __cdecl DATATBLS_CompareGambleTxtRecords(const void* pRecord1, const void* pRecord2)
{
    unsigned int nLevel1 = ((const D2GambleTxt*)pRecord1)->nLevel;
    unsigned int nLevel2 = ((const D2GambleTxt*)pRecord2)->nLevel;

    if (nLevel1 > nLevel2)
    {
        return 1;
    }

    if (nLevel1 < nLevel2)
    {
        return -1;
    }

    return 0;
}
