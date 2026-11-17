extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" int __cdecl _stricmp(const char* szLeft, const char* szRight);                                   // 0x006841E9
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

#pragma pack(push, 1)
struct D2TblHeaderStrc
{
    unsigned short nCRC;
    unsigned short nNumElements;
    int nHashTableSize;
    unsigned char nVersion;
    unsigned int dwIndexStart;
    unsigned int dwNumLoops;
    unsigned int dwFileSize;
};

struct D2TblNodeStrc
{
    unsigned char bUsed;
    unsigned short nIndexNo;
    unsigned int dwHashValue;
    unsigned int dwStringOffset;
    unsigned int dwKeyOffset;
    unsigned short nNameLen;
};
#pragma pack(pop)

struct Unicode
{
    unsigned short wChar;
};

void* __fastcall sub_00517079(void* hArchive, const char* szPath, int* pSize, const char* szFile, int nLine); // 0x00517079
void __stdcall CRC16_CalculateChecksum(unsigned short* crc16_checksum_out, const unsigned char* data, unsigned int start_index, unsigned int end_index); // 0x00525020
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __stdcall sub_00525260(void* pOut, int nField);                                                 // 0x00525260
void __cdecl sub_00525770_InitUnitSuffixes();                                                               // 0x00525770
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
int __fastcall sub_00527790_LoadCodePageMap(void* hArchive, const char* szPath);                            // 0x00527790
int __fastcall sub_00527D50_GetCodePageCharCount(const char* szText, int nLength);                          // 0x00527D50

static D2TblHeaderStrc* gpStringTable_008829B4;                                                             // 0x008829B4
static Unicode** gpStringIndex_008829B8;                                                                    // 0x008829B8
static Unicode** gpPatchStringIndex_008829BC;                                                               // 0x008829BC
static Unicode** gpExpansionStringIndex_008829C0;                                                           // 0x008829C0
static Unicode* gpStringData_008829C4;                                                                      // 0x008829C4
static Unicode* gpPatchStringData_008829C8;                                                                 // 0x008829C8
static Unicode* gpExpansionStringData_008829CC;                                                             // 0x008829CC
static D2TblHeaderStrc* gpPatchStringTable_008829D0;                                                        // 0x008829D0
static D2TblHeaderStrc* gpExpansionStringTable_008829D4;                                                    // 0x008829D4
static int gnStringTableRefs_008829D8;                                                                      // 0x008829D8
extern void* ghArchive_008829DC;                                                                            // 0x008829DC

// 0x00525920
static D2TblHeaderStrc* sub_00525920_LoadTblFile(const char* szPath)
{
    D2TblHeaderStrc* pTbl = (D2TblHeaderStrc*)sub_00517079(ghArchive_008829DC, szPath, 0, ".\\StrTable\\strtable.cpp", 0xC0);

    unsigned short nCRC;
    CRC16_CalculateChecksum(&nCRC, (const unsigned char*)pTbl, pTbl->dwIndexStart, pTbl->dwFileSize);
    D2_ASSERT(nCRC == pTbl->nCRC, 0xCE);

    D2TblNodeStrc* pNodes = (D2TblNodeStrc*)((char*)pTbl + sizeof(D2TblHeaderStrc) + pTbl->nNumElements * sizeof(unsigned short));
    for (int i = 0; i < pTbl->nHashTableSize; ++i)
    {
        D2_ASSERT(pNodes[i].dwStringOffset < pTbl->dwFileSize, 0xE0);
        D2_ASSERT(pNodes[i].dwKeyOffset < pTbl->dwFileSize, 0xE1);
    }

    return pTbl;
}

// 0x005259C0
int __fastcall sub_005259C0_LoadStringTables(void* pMemPool, const char* szLanguage, int bExpansion)
{
    char szLang[4];
    char szMapPath[0x104];
    char szPath[0x104];
    char szFormat[0x104];
    char szCodePage[0x20];
    D2TblNodeStrc* pNodes;
    Unicode* pText;
    Unicode** pIndex;
    int nTotal;
    int i;

    if (gpStringTable_008829B4)
    {
        ++gnStringTableRefs_008829D8;
        return 1;
    }

    if (szLanguage)
        strcpy(szLang, szLanguage);
    else
        sub_00525260(szLang, 0);

    if (!_stricmp(szLang, "JPN"))
        strcpy(szCodePage, "JPN");
    else if (!_stricmp(szLang, "KOR"))
        strcpy(szCodePage, "KOR");
    else if (!_stricmp(szLang, "POL"))
        strcpy(szCodePage, "LATIN2");
    else if (!_stricmp(szLang, "RUS"))
        strcpy(szCodePage, "CYR");
    else
        strcpy(szCodePage, "LATIN");

    sprintf(szMapPath, "data\\local\\font\\%s\\default.map", szCodePage);
    sub_00527790_LoadCodePageMap(ghArchive_008829DC, szMapPath);

    strncpy(szFormat, "data\\local\\lng\\%s\\string.tbl", 0x103);
    sprintf(szPath, szFormat, szLang);
    gpStringTable_008829B4 = sub_00525920_LoadTblFile(szPath);
    if (!gpStringTable_008829B4)
        return 0;

    D2TblHeaderStrc* pTbl = gpStringTable_008829B4;
    D2TblHeaderStrc* pLoaded = gpStringTable_008829B4;

    pIndex = (Unicode**)FOG_Alloc(pTbl->nHashTableSize * sizeof(Unicode*), ".\\StrTable\\strtable.cpp", 0x18F, 0);
    gpStringIndex_008829B8 = pIndex;
    memset(pIndex, 0, pTbl->nHashTableSize * sizeof(Unicode*));
    ++gnStringTableRefs_008829D8;

    pNodes = (D2TblNodeStrc*)((char*)gpStringTable_008829B4 + sizeof(D2TblHeaderStrc) + pLoaded->nNumElements * sizeof(unsigned short));
    nTotal = 0;
    for (i = 0; i < pTbl->nHashTableSize; i++)
    {
        const char* szText = (char*)gpStringTable_008829B4 + pNodes[i].dwKeyOffset;
        nTotal += sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
    }

    gpStringData_008829C4 = (Unicode*)FOG_Alloc(nTotal * sizeof(Unicode), ".\\StrTable\\strtable.cpp", 0x1A9, 0);
    pText = gpStringData_008829C4;
    for (i = 0; i < pTbl->nHashTableSize; i++)
    {
        gpStringIndex_008829B8[i] = pText;
        const char* szText = (char*)gpStringTable_008829B4 + pNodes[i].dwKeyOffset;
        const int nCount = sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
        sub_00526320_ToUnicode(gpStringIndex_008829B8[i], szText, nCount);
        pText += nCount;
    }

    strncpy(szFormat, "data\\local\\lng\\%s\\patchstring.tbl", 0x103);
    sprintf(szPath, szFormat, szLang);
    gpPatchStringTable_008829D0 = sub_00525920_LoadTblFile(szPath);
    D2_ASSERT(gpPatchStringTable_008829D0, 0x1C3);

    pTbl = gpPatchStringTable_008829D0;

    pIndex = (Unicode**)FOG_Alloc(pTbl->nHashTableSize * sizeof(Unicode*), ".\\StrTable\\strtable.cpp", 0x1C5, 0);
    gpPatchStringIndex_008829BC = pIndex;
    memset(pIndex, 0, pTbl->nHashTableSize * sizeof(Unicode*));

    pTbl = gpPatchStringTable_008829D0;
    pNodes = (D2TblNodeStrc*)((char*)pTbl + sizeof(D2TblHeaderStrc) + pTbl->nNumElements * sizeof(unsigned short));
    nTotal = 0;
    for (i = 0; i < pTbl->nHashTableSize; i++)
    {
        const char* szText = (char*)gpPatchStringTable_008829D0 + pNodes[i].dwKeyOffset;
        nTotal += sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
    }

    gpPatchStringData_008829C8 = (Unicode*)FOG_Alloc(nTotal * sizeof(Unicode), ".\\StrTable\\strtable.cpp", 0x1DC, 0);
    pText = gpPatchStringData_008829C8;
    for (i = 0; i < pTbl->nHashTableSize; i++)
    {
        gpPatchStringIndex_008829BC[i] = pText;
        const char* szText = (char*)gpPatchStringTable_008829D0 + pNodes[i].dwKeyOffset;
        const int nCount = sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
        sub_00526320_ToUnicode(gpPatchStringIndex_008829BC[i], szText, nCount);
        pText += nCount;
    }

    if (bExpansion)
    {
        strncpy(szFormat, "data\\local\\lng\\%s\\expansionstring.tbl", 0x103);
        sprintf(szPath, szFormat, szLang);
        gpExpansionStringTable_008829D4 = sub_00525920_LoadTblFile(szPath);
        D2_ASSERT(gpExpansionStringTable_008829D4, 0x1F6);

        pTbl = gpExpansionStringTable_008829D4;

        pIndex = (Unicode**)FOG_Alloc(pTbl->nHashTableSize * sizeof(Unicode*), ".\\StrTable\\strtable.cpp", 0x1F8, 0);
        gpExpansionStringIndex_008829C0 = pIndex;
        memset(pIndex, 0, pTbl->nHashTableSize * sizeof(Unicode*));

        pTbl = gpExpansionStringTable_008829D4;
        pNodes = (D2TblNodeStrc*)((char*)pTbl + sizeof(D2TblHeaderStrc) + pTbl->nNumElements * sizeof(unsigned short));
        nTotal = 0;
        for (i = 0; i < pTbl->nHashTableSize; i++)
        {
            const char* szText = (char*)gpExpansionStringTable_008829D4 + pNodes[i].dwKeyOffset;
            nTotal += sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
        }

        gpExpansionStringData_008829CC = (Unicode*)FOG_Alloc(nTotal * sizeof(Unicode), ".\\StrTable\\strtable.cpp", 0x20F, 0);
        pText = gpExpansionStringData_008829CC;
        for (i = 0; i < pTbl->nHashTableSize; i++)
        {
            gpExpansionStringIndex_008829C0[i] = pText;
            const char* szText = (char*)gpExpansionStringTable_008829D4 + pNodes[i].dwKeyOffset;
            const int nCount = sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
            sub_00526320_ToUnicode(gpExpansionStringIndex_008829C0[i], szText, nCount);
            pText += nCount;
        }
    }

    sub_00525770_InitUnitSuffixes();
    return 1;
}
