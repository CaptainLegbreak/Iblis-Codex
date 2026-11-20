#include "D2Lang.h"
#include "D2LangTypes.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" int __cdecl _stricmp(const char* szLeft, const char* szRight);                                   // 0x006841E9
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

#pragma pack(push, 1)

#pragma pack(pop)

struct Unicode
{
    unsigned short wChar;

    Unicode toUpper() const
    {
        Unicode tResult;
        tResult.wChar = wChar < 0x100 ? gwToUpperTable_00730578[wChar] : wChar;
        return tResult;
    }
    static int __fastcall compare(Unicode lhs, Unicode rhs);
    static Unicode* __fastcall strncat(Unicode* dest, const Unicode* src, int count);
};
void __stdcall CRC16_CalculateChecksum(unsigned short* crc16_checksum_out, const unsigned char* data, unsigned int start_index, unsigned int end_index); // 0x00525020
void __stdcall sub_00525260(void* pOut, int nField);                                                 // 0x00525260
void __cdecl sub_00525770_InitUnitSuffixes();                                                               // 0x00525770
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
int __fastcall sub_00527790_LoadCodePageMap(void* hArchive, const char* szPath);                            // 0x00527790
int __fastcall sub_00527D50_GetCodePageCharCount(const char* szText, int nLength);                          // 0x00527D50

static D2TblHeaderStrc* sghStringTable;                                                             // 0x008829B4
static Unicode** gpStringIndex_008829B8;                                                                    // 0x008829B8
static Unicode** gpPatchStringIndex_008829BC;                                                               // 0x008829BC
static Unicode** gpExpansionStringIndex_008829C0;                                                           // 0x008829C0
static Unicode* gpStringData_008829C4;                                                                      // 0x008829C4
static Unicode* gpPatchStringData_008829C8;                                                                 // 0x008829C8
static Unicode* gpExpansionStringData_008829CC;                                                             // 0x008829CC
static D2TblHeaderStrc* sghPatchStringTable;                                                        // 0x008829D0
static D2TblHeaderStrc* sghExpansionStringTable;                                                    // 0x008829D4
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

    if (sghStringTable)
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
    sghStringTable = sub_00525920_LoadTblFile(szPath);
    if (!sghStringTable)
        return 0;

    D2TblHeaderStrc* pTbl = sghStringTable;
    D2TblHeaderStrc* pLoaded = sghStringTable;

    pIndex = (Unicode**)FOG_Alloc(pTbl->nHashTableSize * sizeof(Unicode*), ".\\StrTable\\strtable.cpp", 0x18F, 0);
    gpStringIndex_008829B8 = pIndex;
    memset(pIndex, 0, pTbl->nHashTableSize * sizeof(Unicode*));
    ++gnStringTableRefs_008829D8;

    pNodes = (D2TblNodeStrc*)((char*)sghStringTable + sizeof(D2TblHeaderStrc) + pLoaded->nNumElements * sizeof(unsigned short));
    nTotal = 0;
    for (i = 0; i < pTbl->nHashTableSize; i++)
    {
        const char* szText = (char*)sghStringTable + pNodes[i].dwKeyOffset;
        nTotal += sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
    }

    gpStringData_008829C4 = (Unicode*)FOG_Alloc(nTotal * sizeof(Unicode), ".\\StrTable\\strtable.cpp", 0x1A9, 0);
    pText = gpStringData_008829C4;
    for (i = 0; i < pTbl->nHashTableSize; i++)
    {
        gpStringIndex_008829B8[i] = pText;
        const char* szText = (char*)sghStringTable + pNodes[i].dwKeyOffset;
        const int nCount = sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
        sub_00526320_ToUnicode(gpStringIndex_008829B8[i], szText, nCount);
        pText += nCount;
    }

    strncpy(szFormat, "data\\local\\lng\\%s\\patchstring.tbl", 0x103);
    sprintf(szPath, szFormat, szLang);
    sghPatchStringTable = sub_00525920_LoadTblFile(szPath);
    D2_ASSERT(sghPatchStringTable, 0x1C3);

    pTbl = sghPatchStringTable;

    pIndex = (Unicode**)FOG_Alloc(pTbl->nHashTableSize * sizeof(Unicode*), ".\\StrTable\\strtable.cpp", 0x1C5, 0);
    gpPatchStringIndex_008829BC = pIndex;
    memset(pIndex, 0, pTbl->nHashTableSize * sizeof(Unicode*));

    pTbl = sghPatchStringTable;
    pNodes = (D2TblNodeStrc*)((char*)pTbl + sizeof(D2TblHeaderStrc) + pTbl->nNumElements * sizeof(unsigned short));
    nTotal = 0;
    for (i = 0; i < pTbl->nHashTableSize; i++)
    {
        const char* szText = (char*)sghPatchStringTable + pNodes[i].dwKeyOffset;
        nTotal += sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
    }

    gpPatchStringData_008829C8 = (Unicode*)FOG_Alloc(nTotal * sizeof(Unicode), ".\\StrTable\\strtable.cpp", 0x1DC, 0);
    pText = gpPatchStringData_008829C8;
    for (i = 0; i < pTbl->nHashTableSize; i++)
    {
        gpPatchStringIndex_008829BC[i] = pText;
        const char* szText = (char*)sghPatchStringTable + pNodes[i].dwKeyOffset;
        const int nCount = sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
        sub_00526320_ToUnicode(gpPatchStringIndex_008829BC[i], szText, nCount);
        pText += nCount;
    }

    if (bExpansion)
    {
        strncpy(szFormat, "data\\local\\lng\\%s\\expansionstring.tbl", 0x103);
        sprintf(szPath, szFormat, szLang);
        sghExpansionStringTable = sub_00525920_LoadTblFile(szPath);
        D2_ASSERT(sghExpansionStringTable, 0x1F6);

        pTbl = sghExpansionStringTable;

        pIndex = (Unicode**)FOG_Alloc(pTbl->nHashTableSize * sizeof(Unicode*), ".\\StrTable\\strtable.cpp", 0x1F8, 0);
        gpExpansionStringIndex_008829C0 = pIndex;
        memset(pIndex, 0, pTbl->nHashTableSize * sizeof(Unicode*));

        pTbl = sghExpansionStringTable;
        pNodes = (D2TblNodeStrc*)((char*)pTbl + sizeof(D2TblHeaderStrc) + pTbl->nNumElements * sizeof(unsigned short));
        nTotal = 0;
        for (i = 0; i < pTbl->nHashTableSize; i++)
        {
            const char* szText = (char*)sghExpansionStringTable + pNodes[i].dwKeyOffset;
            nTotal += sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
        }

        gpExpansionStringData_008829CC = (Unicode*)FOG_Alloc(nTotal * sizeof(Unicode), ".\\StrTable\\strtable.cpp", 0x20F, 0);
        pText = gpExpansionStringData_008829CC;
        for (i = 0; i < pTbl->nHashTableSize; i++)
        {
            gpExpansionStringIndex_008829C0[i] = pText;
            const char* szText = (char*)sghExpansionStringTable + pNodes[i].dwKeyOffset;
            const int nCount = sub_00527D50_GetCodePageCharCount(szText, pNodes[i].nNameLen) + 1;
            sub_00526320_ToUnicode(gpExpansionStringIndex_008829C0[i], szText, nCount);
            pText += nCount;
        }
    }

    sub_00525770_InitUnitSuffixes();
    return 1;
}
