// build: base-profile

#define NULL 0

struct D2TxtLinkStrc;
struct Unicode;
typedef void* HD2ARCHIVE;
typedef void* HSFILE;

enum D2C_TxtFieldTypes
{
    TXTFIELD_NONE = 0,
    TXTFIELD_ASCII = 1,
    TXTFIELD_DWORD = 2,
    TXTFIELD_BYTE = 4,
    TXTFIELD_UNKNOWN3 = 11,
    TXTFIELD_CODETOWORD = 15,
    TXTFIELD_NAMETODWORD = 19,
    TXTFIELD_CALCTODWORD = 25,
};

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinkField;
};

struct D2PropertyStrc
{
    int nProperty;
    int nLayer;
    int nMin;
    int nMax;
};

struct D2RunesTxt
{
    char szName[64];
    char szRuneName[64];
    unsigned char nComplete;
    unsigned char nServer;
    unsigned short wStringId;
    unsigned short pad0x84;
    unsigned short wIType[6];
    unsigned short wEType[3];
    int nRune[6];
    D2PropertyStrc pProperties[7];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" unsigned int __security_cookie;                                                                  // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie);                                   // 0x00681A48
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);           // 0x006CC468
int __fastcall ARCHIVE_OpenFile(HD2ARCHIVE hArchive, const char* szFilePath, HSFILE* phFile, int bQuiet);  // 0x00516E46
void __fastcall ARCHIVE_CloseFile(HD2ARCHIVE hArchive, HSFILE hFile);                                      // 0x00516E84
short __stdcall sub_00524D30_FindString(const char* szReference, const Unicode** ppUnicode);                // 0x00524D30
void* __stdcall DATATBLS_CompileTxt(HD2ARCHIVE hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int dwSize); // 0x006122F0
void __fastcall DATATBLS_ItemParamLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn); // 0x006336A0
D2TxtLinkStrc* __stdcall sub_006BD040_AllocBlock(const char* szFile, int nLine);                           // 0x006BD040

struct D2RuneDataTbl
{
    int nRunesTxtRecordCount;
    D2RunesTxt* pRunesTxt;
};

struct D2DataTablesStrc
{
    char pad0x000[0x94];
    D2TxtLinkStrc* pItemsLinker;
    char pad0x098[0x10];
    D2TxtLinkStrc* pPropertiesLinker;
    char pad0x0AC[0x04];
    D2TxtLinkStrc* pRunesLinker;
    char pad0x0B4[0xB40];
    D2TxtLinkStrc* pItemTypesLinker;
    char pad0xBF8[0x270];
    D2RuneDataTbl pRuneDataTables;
};

extern D2DataTablesStrc gD2DataTables;                                                                      // 0x0096BC30

// 0x00639420
static int __stdcall sub_00639420(HD2ARCHIVE hArchive, const char* szFileName, const char* szExtension)
{
    char szPath[260];
    HSFILE hFile;

    wsprintfA(szPath, "%s\\%s%s", "DATA\\GLOBAL\\EXCEL", szFileName, szExtension);
    if (!ARCHIVE_OpenFile(hArchive, szPath, &hFile, 1))
    {
        return 0;
    }

    ARCHIVE_CloseFile(hArchive, hFile);
    return 1;
}

// 0x006394A0
void __fastcall DATATBLS_LoadRunesTxt(HD2ARCHIVE hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "name", TXTFIELD_ASCII, 63, 0, NULL },
        { "rune name", TXTFIELD_ASCII, 63, 0x40, NULL },
        { "complete", TXTFIELD_BYTE, 0, 0x80, NULL },
        { "server", TXTFIELD_BYTE, 0, 0x81, NULL },
        { "itype1", TXTFIELD_CODETOWORD, 0, 0x86, &gD2DataTables.pItemTypesLinker },
        { "itype2", TXTFIELD_CODETOWORD, 0, 0x88, &gD2DataTables.pItemTypesLinker },
        { "itype3", TXTFIELD_CODETOWORD, 0, 0x8a, &gD2DataTables.pItemTypesLinker },
        { "itype4", TXTFIELD_CODETOWORD, 0, 0x8c, &gD2DataTables.pItemTypesLinker },
        { "itype5", TXTFIELD_CODETOWORD, 0, 0x8e, &gD2DataTables.pItemTypesLinker },
        { "itype6", TXTFIELD_CODETOWORD, 0, 0x90, &gD2DataTables.pItemTypesLinker },
        { "etype1", TXTFIELD_CODETOWORD, 0, 0x92, &gD2DataTables.pItemTypesLinker },
        { "etype2", TXTFIELD_CODETOWORD, 0, 0x94, &gD2DataTables.pItemTypesLinker },
        { "etype3", TXTFIELD_CODETOWORD, 0, 0x96, &gD2DataTables.pItemTypesLinker },
        { "rune1", TXTFIELD_UNKNOWN3, 0, 0x98, &gD2DataTables.pItemsLinker },
        { "rune2", TXTFIELD_UNKNOWN3, 0, 0x9c, &gD2DataTables.pItemsLinker },
        { "rune3", TXTFIELD_UNKNOWN3, 0, 0xa0, &gD2DataTables.pItemsLinker },
        { "rune4", TXTFIELD_UNKNOWN3, 0, 0xa4, &gD2DataTables.pItemsLinker },
        { "rune5", TXTFIELD_UNKNOWN3, 0, 0xa8, &gD2DataTables.pItemsLinker },
        { "rune6", TXTFIELD_UNKNOWN3, 0, 0xac, &gD2DataTables.pItemsLinker },
        { "t1code1", TXTFIELD_NAMETODWORD, 0, 0xb0, &gD2DataTables.pPropertiesLinker },
        { "t1param1", TXTFIELD_CALCTODWORD, 0, 0xb4, DATATBLS_ItemParamLinker },
        { "t1min1", TXTFIELD_DWORD, 0, 0xb8, NULL },
        { "t1max1", TXTFIELD_DWORD, 0, 0xbc, NULL },
        { "t1code2", TXTFIELD_NAMETODWORD, 0, 0xc0, &gD2DataTables.pPropertiesLinker },
        { "t1param2", TXTFIELD_CALCTODWORD, 0, 0xc4, DATATBLS_ItemParamLinker },
        { "t1min2", TXTFIELD_DWORD, 0, 0xc8, NULL },
        { "t1max2", TXTFIELD_DWORD, 0, 0xcc, NULL },
        { "t1code3", TXTFIELD_NAMETODWORD, 0, 0xd0, &gD2DataTables.pPropertiesLinker },
        { "t1param3", TXTFIELD_CALCTODWORD, 0, 0xd4, DATATBLS_ItemParamLinker },
        { "t1min3", TXTFIELD_DWORD, 0, 0xd8, NULL },
        { "t1max3", TXTFIELD_DWORD, 0, 0xdc, NULL },
        { "t1code4", TXTFIELD_NAMETODWORD, 0, 0xe0, &gD2DataTables.pPropertiesLinker },
        { "t1param4", TXTFIELD_CALCTODWORD, 0, 0xe4, DATATBLS_ItemParamLinker },
        { "t1min4", TXTFIELD_DWORD, 0, 0xe8, NULL },
        { "t1max4", TXTFIELD_DWORD, 0, 0xec, NULL },
        { "t1code5", TXTFIELD_NAMETODWORD, 0, 0xf0, &gD2DataTables.pPropertiesLinker },
        { "t1param5", TXTFIELD_CALCTODWORD, 0, 0xf4, DATATBLS_ItemParamLinker },
        { "t1min5", TXTFIELD_DWORD, 0, 0xf8, NULL },
        { "t1max5", TXTFIELD_DWORD, 0, 0xfc, NULL },
        { "t1code6", TXTFIELD_NAMETODWORD, 0, 0x100, &gD2DataTables.pPropertiesLinker },
        { "t1param6", TXTFIELD_CALCTODWORD, 0, 0x104, DATATBLS_ItemParamLinker },
        { "t1min6", TXTFIELD_DWORD, 0, 0x108, NULL },
        { "t1max6", TXTFIELD_DWORD, 0, 0x10c, NULL },
        { "t1code7", TXTFIELD_NAMETODWORD, 0, 0x110, &gD2DataTables.pPropertiesLinker },
        { "t1param7", TXTFIELD_CALCTODWORD, 0, 0x114, DATATBLS_ItemParamLinker },
        { "t1min7", TXTFIELD_DWORD, 0, 0x118, NULL },
        { "t1max7", TXTFIELD_DWORD, 0, 0x11c, NULL },
        { "end", TXTFIELD_NONE, 0, 0, NULL },
    };

    gD2DataTables.pRunesLinker = sub_006BD040_AllocBlock(".\\DATATBLS\\ItemTbls.cpp", 2303);

    D2_ASSERT(!sub_00639420(hArchive, "runessrv", ".txt"), 2308);
    D2_ASSERT(!sub_00639420(hArchive, "runessrv", ".bin"), 2312);
    D2_ASSERT(!sub_00639420(hArchive, "runessrv", ".xls"), 2316);

    gD2DataTables.pRuneDataTables.pRunesTxt = (D2RunesTxt*)DATATBLS_CompileTxt(hArchive, "runes", pTbl, &gD2DataTables.pRuneDataTables.nRunesTxtRecordCount, sizeof(D2RunesTxt));

    const Unicode* pUnicode = NULL;
    int i = 0;
    if (i < gD2DataTables.pRuneDataTables.nRunesTxtRecordCount)
    {
        hArchive = NULL;
        do
        {
            ((D2RunesTxt*)((char*)gD2DataTables.pRuneDataTables.pRunesTxt + (int)hArchive))->wStringId = sub_00524D30_FindString(((D2RunesTxt*)((char*)gD2DataTables.pRuneDataTables.pRunesTxt + (int)hArchive))->szName, &pUnicode);
            hArchive = (char*)hArchive + sizeof(D2RunesTxt);
            ++i;
        }
        while (i < gD2DataTables.pRuneDataTables.nRunesTxtRecordCount);
    }
}
