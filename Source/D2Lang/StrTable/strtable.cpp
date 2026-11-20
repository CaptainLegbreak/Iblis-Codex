#include "D2Lang.h"
#include "D2LangTypes.h"

#pragma intrinsic(strcmp)

struct D2ArchiveHandleStrc;
struct D2StrCacheNodeStrc;
struct D2LanguageInfoStrc;
struct D2StringHashNodeStrc;
struct D2GameStrc;
struct D2TblHeaderStrc;
struct D2TblNodeStrc;
struct Unicode;
struct D2StringTableStrc;
struct D2LangCharSetStrc;
struct D2StrTableHeader00524C60Strc;
struct D2StrHashEntry00524C60Strc;

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2ArchiveHandleStrc* __fastcall sub_00517332_LoadMpqFile(const char* szFileName, void* hFile, void* pfShowMessage, int nPriority); // 0x00517332
void __fastcall sub_005173AC_Unload(D2ArchiveHandleStrc* pMPQHandle); // 0x005173AC
extern "C" const char gszExpansionMpq_006CD3A0[]; // 0x006CD3A0
extern "C" const char szPatchD2Mpq_006DC728[]; // 0x006DC728
extern "C" const char szD2DataMpq_006DC770[]; // 0x006DC770

struct D2StrCacheNodeStrc
{
    wchar_t* pText;
    char* szKey;
    D2StrCacheNodeStrc* pNext;
};

extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(void* hKey, const char* szValueName, unsigned long* pReserved, unsigned long* pType, unsigned char* pData, unsigned long* pcbData); // 0x006CC00C
extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(void* hKey, const char* szSubKey, unsigned long nOptions, unsigned long nSamDesired, void** phResult); // 0x006CC010
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey); // 0x006CC030
extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);
extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);
unsigned short __stdcall sub_00524D30_FindString(const char* szKey, const wchar_t** ppText); // 0x00524D30
int __fastcall sub_00525100_LookupLanguage(const char* szLanguage); // 0x00525100

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

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
int __fastcall sub_00527D50_GetCodePageCharCount(const char* szSource, int nLength); // 0x00527D50
extern const unsigned short gaCrc16Table_007301D8[256]; // 0x007301D8
extern "C" const char szNotTranslated_00730520[]; // 0x00730520

struct D2LanguageInfoStrc
{
    const char* szName;
    const char* szCode;
    const char* szAltCode;
    const char* szRegion;
    int nFourCC;
    int f_14;
};

extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9
void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079

#pragma pack(push, 1)
struct D2StringTableStrc
{
    unsigned short nCrc;
    unsigned short nElements;
    int nHashTableSize;
    unsigned char nVersion;
    unsigned int dwIndexStart;
    unsigned int dwMaxTries;
    unsigned int dwIndexEnd;
};

#pragma pack(pop)

extern D2LanguageInfoStrc gaLanguageInfo_007303D8[13]; // 0x007303D8
extern D2StringTableStrc* sghStringTable; // 0x008829B4
extern void* gpStringIndex_008829B8; // 0x008829B8
extern void* gpPatchStringIndex_008829BC; // 0x008829BC
extern void* gpExpansionStringIndex_008829C0; // 0x008829C0
extern D2StringTableStrc* sghPatchStringTable; // 0x008829D0
extern D2StringTableStrc* sghExpansionStringTable; // 0x008829D4
extern void* ghArchive_008829DC; // 0x008829DC

#pragma pack(push, 1)
struct D2StringHashNodeStrc
{
    unsigned char bUsed;
    unsigned short nIndex;
    unsigned int dwHashValue;
    unsigned int dwKeyOffset;
    unsigned int dwStringOffset;
    unsigned short nStringLength;
};

#pragma pack(pop)

unsigned int __stdcall sub_005249E0(const char* szKey, unsigned int nTableSize); // 0x005249E0
wchar_t* __fastcall sub_00524AC0_GetUntranslatedString(const char* szKey); // 0x00524AC0
void __cdecl sub_00527720_FreeCodePageTables(); // 0x00527720

struct D2GameStrc
{
    char unk0x0000[0x1920];
    char unk0x1920[0x7A00];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

#pragma pack(push, 1)

#pragma pack(pop)

void __stdcall CRC16_CalculateChecksum(unsigned short* crc16_checksum_out, const unsigned char* data, unsigned int start_index, unsigned int end_index); // 0x00525020
extern D2TblHeaderStrc* gpM15EmitTbl;
extern "C" const char szM15EmitFormat[];

extern "C" char* __cdecl _i64toa(__int64 nValue, char* szOut, int nRadix); // 0x006876D7

extern Unicode gawszUnitSuffix_00730510[4][2]; // 0x00730510
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
static D2TblHeaderStrc* sub_00525920_LoadTblFile(const char* szPath);
extern "C" char* __cdecl _ui64toa(unsigned __int64 nValue, char* szOut, int nRadix); // 0x00687708

#pragma pack(push, 1)
struct D2StrTableHeader00524C60Strc
{
	unsigned short wCrc;
	unsigned short wNumElements;
	int nHashTableSize;
	unsigned char nVersion;
	unsigned int dwIndexStart;
	unsigned int nNumLoops;
	unsigned int dwFileSize;
};

struct D2StrHashEntry00524C60Strc
{
	unsigned char bUsed;
	unsigned short wIndex;
	unsigned int dwHash;
	unsigned int dwStrOffset;
	unsigned int dwNameOffset;
	unsigned short wNameLength;
};

#pragma pack(pop)
static __declspec(noinline) unsigned short __stdcall sub_00524C60_FindKey(void** ppSlots, const char* szKey, void** ppOut, D2StrTableHeader00524C60Strc* pTable);

void* ghArchive_008829DC; // 0x008829DC

void* ghArchive_008829E0; // 0x008829E0

void* ghArchive_008829E4; // 0x008829E4

// 0x00524810
int __cdecl sub_00524810_OpenArchives()
{
    D2_ASSERT(!ghArchive_008829DC, 0x8A);
    ghArchive_008829DC = sub_00517332_LoadMpqFile(szD2DataMpq_006DC770, 0, 0, 1000);
    if (!ghArchive_008829DC)
        return 0;
    ghArchive_008829E0 = sub_00517332_LoadMpqFile(szPatchD2Mpq_006DC728, 0, 0, 1000);
    if (!ghArchive_008829E0)
    {
        sub_005173AC_Unload((D2ArchiveHandleStrc*)ghArchive_008829DC);
        ghArchive_008829DC = 0;
        return 0;
    }
    ghArchive_008829E4 = sub_00517332_LoadMpqFile(gszExpansionMpq_006CD3A0, 0, 0, 1000);
    if (!ghArchive_008829E4)
    {
        sub_005173AC_Unload((D2ArchiveHandleStrc*)ghArchive_008829DC);
        ghArchive_008829DC = 0;
        sub_005173AC_Unload((D2ArchiveHandleStrc*)ghArchive_008829E0);
        ghArchive_008829E0 = 0;
        return 0;
    }
    return 1;
}

// 0x005248E0
void __cdecl sub_005248E0_CloseArchives()
{
    if (ghArchive_008829DC)
    {
        sub_005173AC_Unload((D2ArchiveHandleStrc*)ghArchive_008829DC);
        ghArchive_008829DC = 0;
    }
    if (ghArchive_008829E0)
    {
        sub_005173AC_Unload((D2ArchiveHandleStrc*)ghArchive_008829E0);
        ghArchive_008829E0 = 0;
    }
    if (ghArchive_008829E4)
    {
        sub_005173AC_Unload((D2ArchiveHandleStrc*)ghArchive_008829E4);
        ghArchive_008829E4 = 0;
    }
}

// 0x005249C0
static __forceinline void sub_005249C0_FreeTable(void* pTable)
{
    FOG_Free(pTable, ".\\StrTable\\strtable.cpp", 0x121, 0);
}

void __fastcall sub_M129_Emit_005249C0(void* pTable1, void* pTable2)
{
    sub_005249C0_FreeTable(pTable1);
    sub_005249C0_FreeTable(pTable2);
}

char gszLanguage_008829F8[256]; // 0x008829F8

static D2StrCacheNodeStrc* s_pStringCache_008829B0; // 0x008829B0

// 0x005249E0
unsigned int __stdcall sub_005249E0(const char* szKey, unsigned int nTableSize)
{
    unsigned int nHash = 0;
    while (*szKey)
    {
        nHash = (nHash << 4) + *szKey;
        unsigned int nHigh = nHash & 0xF0000000;
        if (nHigh)
            nHash = ((nHigh >> 0x18) ^ nHash) & 0x0FFFFFFF;
        ++szKey;
    }
    return nHash % nTableSize;
}

int gnTableLanguage_008829EC; // 0x008829EC

bool gbTableLanguageInitialized_008829F0; // 0x008829F0

// 0x00524A30
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex)
{
    if (nIndex >= 0x4E20)
    {
        if (!sghExpansionStringTable)
        {
            nIndex = 0x2B46;
        }
        else
        {
            const Unicode* pText = sub_00524930(sghExpansionStringTable, gpExpansionStringIndex_008829C0, nIndex - 0x4E20);
            if (pText)
                return pText;
        }
    }
    if (sghPatchStringTable && nIndex >= 0x2710)
    {
        const Unicode* pText = sub_00524930(sghPatchStringTable, gpPatchStringIndex_008829BC, nIndex - 0x2710);
        if (pText)
            return pText;
    }
    D2_ASSERT(sghStringTable, 0x246);
    return sub_00524930(sghStringTable, gpStringIndex_008829B8, nIndex);
}

// 0x00524AC0
wchar_t* __fastcall sub_00524AC0_GetUntranslatedString(const char* szKey)
{
    for (D2StrCacheNodeStrc* pNode = s_pStringCache_008829B0; pNode; pNode = pNode->pNext)
    {
        if (!strcmp(szKey, pNode->szKey))
            return pNode->pText;
    }
    D2StrCacheNodeStrc* pNode = (D2StrCacheNodeStrc*)FOG_Alloc(sizeof(D2StrCacheNodeStrc), ".\\StrTable\\strtable.cpp", 0x259, 0);
    pNode->pNext = s_pStringCache_008829B0;
    s_pStringCache_008829B0 = pNode;
    pNode->szKey = (char*)FOG_Alloc(strlen(szKey) + 1, ".\\StrTable\\strtable.cpp", 0x264, 0);
    strcpy(pNode->szKey, szKey);
    const int nLength = strlen(szKey) + strlen(szNotTranslated_00730520);
    char* szText = (char*)FOG_Alloc(nLength + 1, ".\\StrTable\\strtable.cpp", 0x26C, 0);
    strcpy(szText, szKey);
    strcat(szText, szNotTranslated_00730520);
    const int nChars = sub_00527D50_GetCodePageCharCount(szText, nLength);
    pNode->pText = (wchar_t*)FOG_Alloc(nChars * 2 + 2, ".\\StrTable\\strtable.cpp", 0x271, 0);
    sub_00526320_ToUnicode((Unicode*)pNode->pText, szText, nChars);
    FOG_Free(szText, ".\\StrTable\\strtable.cpp", 0x277, 0);
    return pNode->pText;
}

// 0x00524C60
static unsigned short __stdcall sub_00524C60_FindKey(void** ppSlots, const char* szKey, void** ppOut, D2StrTableHeader00524C60Strc* pTable)
{
	D2StrHashEntry00524C60Strc* pHashTable = (D2StrHashEntry00524C60Strc*)((char*)pTable + sizeof(D2StrTableHeader00524C60Strc) + pTable->wNumElements * sizeof(unsigned short));
	unsigned int nLoops = 0;
	int const tArg1 = pTable->nHashTableSize;
	int nHash = sub_005249E0(szKey, tArg1);
	while (nLoops < pTable->nNumLoops)
	{
		++nLoops;
		if ((&pHashTable[nHash])->bUsed == 1 && !strcmp((const char*)pTable + (&pHashTable[nHash])->dwStrOffset, szKey))
		{
			D2_ASSERT(ppSlots[nHash], 662);
			*ppOut = ppSlots[nHash];
			return pHashTable[nHash].wIndex;
		}
		nHash = (nHash + 1) % pTable->nHashTableSize;
	}

	return 0xFFFF;
}

wchar_t gwszEmptyString_008829E8[2]; // 0x008829E8

static unsigned short __stdcall sub_00524C60_FindInTable(D2StringTableStrc* pTable, const wchar_t** ppIndex, const char* szKey, const wchar_t** ppText)
{
    unsigned int i = 0;
    D2StringHashNodeStrc* pNodes = (D2StringHashNodeStrc*)((char*)pTable + sizeof(D2StringTableStrc) + pTable->nElements * 2);
    int nIndex = sub_005249E0(szKey, pTable->nHashTableSize);
    while (i < pTable->dwMaxTries)
    {
        D2StringHashNodeStrc* pNode = &pNodes[nIndex];
        ++i;
        if (pNode->bUsed == 1 && !strcmp((char*)pTable + pNode->dwKeyOffset, szKey))
        {
            D2_ASSERT(ppIndex[nIndex], 0x296);
            *ppText = ppIndex[nIndex];
            return pNodes[nIndex].nIndex;
        }
        nIndex = (nIndex + 1) % pTable->nHashTableSize;
    }
    return 0xFFFF;
}

// 0x00524D30
unsigned short __stdcall sub_00524D30_FindString(const char* szKey, const wchar_t** ppText)
{
    D2_ASSERT(sghStringTable, 0x2BA);
    D2_ASSERT(sghPatchStringTable, 0x2BB);
    D2_ASSERT(szKey, 0x2C0);
    if (!*szKey)
    {
        *ppText = gwszEmptyString_008829E8;
        return 0;
    }
    unsigned short nIndex = sub_00524C60_FindInTable(sghPatchStringTable, (const wchar_t**)gpPatchStringIndex_008829BC, szKey, ppText);
    if (nIndex != 0xFFFF)
        return nIndex + 10000;
    if (sghExpansionStringTable)
    {
        nIndex = sub_00524C60_FindInTable(sghExpansionStringTable, (const wchar_t**)gpExpansionStringIndex_008829C0, szKey, ppText);
        if (nIndex != 0xFFFF)
            return nIndex + 20000;
    }
    nIndex = sub_00524C60_FindInTable(sghStringTable, (const wchar_t**)gpStringIndex_008829B8, szKey, ppText);
    if (nIndex == 0xFFFF)
    {
        *ppText = sub_00524AC0_GetUntranslatedString(szKey);
        return 0;
    }
    return nIndex;
}

// 0x00524E20
const wchar_t* __fastcall D2LANG_GetStringByReferenceString(const char* szKey)
{
    const wchar_t* pText = 0;
    sub_00524D30_FindString(szKey, &pText);
    return pText;
}

D2StrCacheNodeStrc* gpStringCache_008829B0; // 0x008829B0

void* gpPatchStringIndex_008829BC; // 0x008829BC

void* gpExpansionStringIndex_008829C0; // 0x008829C0

void* gpStringData_008829C4; // 0x008829C4

void* gpPatchStringData_008829C8; // 0x008829C8

void* gpExpansionStringData_008829CC; // 0x008829CC

D2StringTableStrc* sghPatchStringTable; // 0x008829D0

D2StringTableStrc* sghExpansionStringTable; // 0x008829D4

int gnStringTableRefs_008829D8; // 0x008829D8

// 0x00524E40
void __cdecl sub_00524E40_UnloadStringTables()
{
    if (sghStringTable && --gnStringTableRefs_008829D8 == 0)
    {
        if (gpStringIndex_008829B8)
        {
            FOG_Free(gpStringData_008829C4, ".\\StrTable\\strtable.cpp", 0x329, 0);
            gpStringData_008829C4 = 0;
            FOG_Free(gpStringIndex_008829B8, ".\\StrTable\\strtable.cpp", 0x32E, 0);
            gpStringIndex_008829B8 = 0;
        }
        FOG_Free(sghStringTable, ".\\StrTable\\strtable.cpp", 0x121, 0);
        sghStringTable = 0;

        if (gpPatchStringIndex_008829BC)
        {
            FOG_Free(gpPatchStringIndex_008829BC, ".\\StrTable\\strtable.cpp", 0x33C, 0);
            gpPatchStringIndex_008829BC = 0;
        }
        if (gpPatchStringData_008829C8)
        {
            FOG_Free(gpPatchStringData_008829C8, ".\\StrTable\\strtable.cpp", 0x341, 0);
            gpPatchStringData_008829C8 = 0;
        }
        FOG_Free(sghPatchStringTable, ".\\StrTable\\strtable.cpp", 0x121, 0);
        sghPatchStringTable = 0;

        if (gpExpansionStringIndex_008829C0)
        {
            FOG_Free(gpExpansionStringIndex_008829C0, ".\\StrTable\\strtable.cpp", 0x34A, 0);
            gpExpansionStringIndex_008829C0 = 0;
        }
        if (gpExpansionStringData_008829CC)
        {
            FOG_Free(gpExpansionStringData_008829CC, ".\\StrTable\\strtable.cpp", 0x34F, 0);
            gpExpansionStringData_008829CC = 0;
        }
        if (sghExpansionStringTable)
        {
            FOG_Free(sghExpansionStringTable, ".\\StrTable\\strtable.cpp", 0x121, 0);
            sghExpansionStringTable = 0;
        }

        D2StrCacheNodeStrc* pNode = gpStringCache_008829B0;
        while (pNode)
        {
            D2StrCacheNodeStrc* pNext = pNode->pNext;
            FOG_Free(pNode->pText, ".\\StrTable\\strtable.cpp", 0x377, 0);
            FOG_Free(pNode->szKey, ".\\StrTable\\strtable.cpp", 0x378, 0);
            FOG_Free(pNode, ".\\StrTable\\strtable.cpp", 0x379, 0);
            pNode = pNext;
        }
        gpStringCache_008829B0 = 0;
        sub_00527720_FreeCodePageTables();
    }
}

void __fastcall sub_0059F820_ClearGameBlock(D2GameStrc* pGame)
{
    memset(pGame->unk0x1920, 0, sizeof(pGame->unk0x1920));
}

// 0x00525010
unsigned short __fastcall sub_0059FFF0_ToWord(unsigned short nValue)
{
    return nValue;
}

// 0x00525020
void __stdcall CRC16_CalculateChecksum(unsigned short* crc16_checksum_out, const unsigned char* data, unsigned int start_index, unsigned int end_index)
{
    D2_ASSERT(start_index < end_index, 0x3EA);
    *crc16_checksum_out = 0xFFFF;
    for (unsigned int i = start_index; i < end_index; ++i)
        *crc16_checksum_out = (*crc16_checksum_out << 8) ^ gaCrc16Table_007301D8[(*crc16_checksum_out >> 8) ^ data[i]];
}

// 0x00525090
void __fastcall sub_00525090_MapLanguageName(char* szLanguage)
{
    for (int i = 0; i < 13; ++i)
    {
        if (!_stricmp(szLanguage, gaLanguageInfo_007303D8[i].szName))
        {
            strcpy(szLanguage, gaLanguageInfo_007303D8[i].szCode);
            return;
        }
    }
    strcpy(szLanguage, gaLanguageInfo_007303D8[0].szCode);
}

// 0x00525100
int __fastcall sub_00525100_LookupLanguage(const char* szLanguage)
{
    for (int i = 0; i < 13; ++i)
    {
        if (!_stricmp(szLanguage, gaLanguageInfo_007303D8[i].szName))
            return gaLanguageInfo_007303D8[i].f_14;
    }
    return 0;
}

// 0x00525150
int __cdecl STRTABLE_GetLanguage()
{
    if (!gbTableLanguageInitialized_008829F0)
    {
        gbTableLanguageInitialized_008829F0 = true;
        unsigned char* pBuffer = (unsigned char*)ARCHIVE_AllocateBufferAndReadFile(ghArchive_008829DC, "data\\local\\use", 0, ".\\StrTable\\strtable.cpp", 0x44B);
        if (pBuffer)
        {
            gnTableLanguage_008829EC = *pBuffer;
            FOG_Free(pBuffer, ".\\StrTable\\strtable.cpp", 0x450, 0);
        }
        if (gnTableLanguage_008829EC >= 14)
            gnTableLanguage_008829EC = 0;
    }
    return gnTableLanguage_008829EC;
}

// 0x005251C0
int __cdecl sub_005251C0_GetLanguage()
{
    void* hKey;
    if (!RegOpenKeyExA((void*)0x80000001, "Control Panel\\International", 0, 0x20019, &hKey))
    {
        unsigned long nType;
        unsigned long nLength;
        if (!RegQueryValueExA(hKey, "sLanguage", 0, &nType, (unsigned char*)gszLanguage_008829F8, &nLength) && strlen(gszLanguage_008829F8) && strlen(gszLanguage_008829F8) < 4)
        {
            RegCloseKey(hKey);
            return sub_00525100_LookupLanguage(gszLanguage_008829F8);
        }
    }
    return 0;
}

int sub_M15_Emit_00525920(const char* szDir, const char* szLang)
{
    char szPath[0x104];
    sprintf(szPath, szM15EmitFormat, szDir, szLang);
    gpM15EmitTbl = sub_00525920_LoadTblFile(szPath);
    return gpM15EmitTbl != 0;
}

D2StringTableStrc* sghStringTable; // 0x008829B4

void* gpStringIndex_008829B8; // 0x008829B8

static inline const Unicode* D2LANG_GetStringFromTblIndex_Inline(unsigned short nIndex)
{
    if (nIndex >= 0x4E20)
    {
        if (!sghExpansionStringTable)
        {
            nIndex = 0x2B46;
        }
        else
        {
            const Unicode* pText = sub_00524930(sghExpansionStringTable, gpExpansionStringIndex_008829C0, nIndex - 0x4E20);
            if (pText)
            {
                return pText;
            }
        }
    }
    if (sghPatchStringTable && nIndex >= 0x2710)
    {
        const Unicode* pText = sub_00524930(sghPatchStringTable, gpPatchStringIndex_008829BC, nIndex - 0x2710);
        if (pText)
        {
            return pText;
        }
    }
    D2_ASSERT(sghStringTable, 0x246);
    return sub_00524930(sghStringTable, gpStringIndex_008829B8, nIndex);
}

// 0x00525260
void __stdcall sub_00525260(void* pOut, int nField)
{
    const int nLanguageId = sub_00525150();
    D2_ASSERT(gaLanguageInfo_007303D8[0].f_14 == 0, 0x490);

    int nIndex = 0;
    if (nLanguageId < 14)
    {
        for (nIndex = 0; nIndex < 13; ++nIndex)
        {
            if (gaLanguageInfo_007303D8[nIndex].f_14 == nLanguageId)
            {
                break;
            }
        }
        if (nIndex >= 14)
        {
            nIndex = 0;
        }
    }

    switch (nField)
    {
    case 1:
        strcpy((char*)pOut, gaLanguageInfo_007303D8[nIndex].szAltCode);
        break;
    case 2:
        strcpy((char*)pOut, gaLanguageInfo_007303D8[nIndex].szRegion);
        break;
    case 3:
        *(int*)pOut = gaLanguageInfo_007303D8[nIndex].nFourCC;
        break;
    default:
        strcpy((char*)pOut, gaLanguageInfo_007303D8[nIndex].szCode);
        break;
    }
}

// 0x00525350
void __stdcall sub_00525350_FormatUInt(Unicode* pOut, unsigned int nValue, int nSize)
{
    char szBuffer[64];
    int nGroup = 0;
    D2_ASSERT(nSize > 2, 0x4ED);
    _ultoa(nValue, szBuffer, 10);
    int nLength = strlen(szBuffer);
    if (nLength)
    {
        int nPos = nLength + (nLength - 1) / 3;
        if (nPos >= 1 && nPos < nSize - 1)
        {
            pOut[nPos].wChar = 0;
            while (nLength)
            {
                D2_ASSERT(nPos != 0, 0x500);
                --nLength;
                --nPos;
                pOut[nPos].wChar = szBuffer[nLength];
                ++nGroup;
                if (nGroup >= 3 && strlen(szBuffer) > 3)
                {
                    nGroup = 0;
                    if (nPos > 0)
                    {
                        --nPos;
                        pOut[nPos].wChar = ',';
                    }
                }
            }
            return;
        }
    }
    Unicode wszStar[2];
    wszStar[0].wChar = 0;
    wszStar[1].wChar = 0;
    sub_00526320_ToUnicode(wszStar, szStar_006D5830, 2);
    sub_005267E0(pOut, wszStar);
}

// 0x00525490
void __stdcall sub_00525490_FormatInt64(Unicode* pOut, __int64 nValue, int nSize)
{
    char szBuffer[64];
    int nGroup = 0;
    D2_ASSERT(nSize > 2, 0x519);
    if (nValue < 0)
    {
        pOut->wChar = '-';
        ++pOut;
        --nSize;
        nValue = -nValue;
    }
    _i64toa(nValue, szBuffer, 10);
    int nLength = strlen(szBuffer);
    if (nLength)
    {
        int nPos = nLength + (nLength - 1) / 3;
        if (nPos >= 1 && nPos < nSize - 1)
        {
            pOut[nPos].wChar = 0;
            while (nLength)
            {
                D2_ASSERT(nPos != 0, 0x533);
                --nLength;
                --nPos;
                pOut[nPos].wChar = szBuffer[nLength];
                ++nGroup;
                if (nGroup >= 3)
                {
                    nGroup = 0;
                    if (nPos > 0)
                    {
                        --nPos;
                        pOut[nPos].wChar = ',';
                    }
                }
            }
            return;
        }
    }
    Unicode wszStar[2];
    wszStar[0].wChar = 0;
    wszStar[1].wChar = 0;
    sub_00526320_ToUnicode(wszStar, szStar_006D5830, 2);
    sub_005267E0(pOut, wszStar);
}

#include "gen/data/Source/D2Lang/StrTable/strtable.inc"

// 0x005255C0
void __stdcall sub_005255C0_FormatUInt64Suffixed(Unicode* pOut, unsigned __int64 nValue, int nSize)
{
    char szBuffer[64];
    int nGroup = 0;
    int nUnit;
    D2_ASSERT(nSize > 2, 0x54B);
    _ui64toa(nValue, szBuffer, 10);
    int nLength = strlen(szBuffer);
    if (nLength)
    {
        nUnit = (nLength - 1) / 3 - 1;
        if (nUnit >= 4)
        {
            nUnit = 4;
        }
        else if (nUnit < 0)
        {
            nUnit = 0;
        }
        nLength += nUnit * -3;
        int nPos = nLength + (nLength - 1) / 3;
        if (nPos >= 1 && nPos < nSize - 2)
        {
            pOut[nPos + 1].wChar = 0;
            switch (nUnit)
            {
            case 0:
                pOut[nPos].wChar = 0;
                break;
            case 1:
                pOut[nPos].wChar = gawszUnitSuffix_00730510[0][0].wChar;
                break;
            case 2:
                pOut[nPos].wChar = gawszUnitSuffix_00730510[1][0].wChar;
                break;
            case 3:
                pOut[nPos].wChar = gawszUnitSuffix_00730510[2][0].wChar;
                break;
            case 4:
                pOut[nPos].wChar = gawszUnitSuffix_00730510[3][0].wChar;
                break;
            }
            while (nLength)
            {
                D2_ASSERT(nPos != 0, 0x580);
                --nLength;
                --nPos;
                pOut[nPos].wChar = szBuffer[nLength];
                ++nGroup;
                if (nGroup >= 3)
                {
                    nGroup = 0;
                    if (nPos > 0)
                    {
                        --nPos;
                        pOut[nPos].wChar = ',';
                    }
                }
            }
            return;
        }
    }
    {
        Unicode wszStar[2];
        wszStar[0].wChar = 0;
        wszStar[1].wChar = 0;
        sub_00526320_ToUnicode(wszStar, szStar_006D5830, 2);
        sub_005267E0(pOut, wszStar);
    }
}

// 0x00525770
void __cdecl sub_00525770_InitUnitSuffixes()
{
    char szBuffer[8];

    sub_00526F70(szBuffer, D2LANG_GetStringFromTblIndex_Inline(0x14D0), 5);
    if (strlen(szBuffer) > 1)
    {
        gawszUnitSuffix_00730510[0][0].wChar = 'K';
    }
    else
    {
        gawszUnitSuffix_00730510[0][0].wChar = szBuffer[0];
    }

    sub_00526F70(szBuffer, D2LANG_GetStringFromTblIndex_Inline(0x14D1), 5);
    if (strlen(szBuffer) > 1)
    {
        gawszUnitSuffix_00730510[1][0].wChar = 'M';
    }
    else
    {
        gawszUnitSuffix_00730510[1][0].wChar = szBuffer[0];
    }

    sub_00526F70(szBuffer, D2LANG_GetStringFromTblIndex_Inline(0x14D2), 5);
    if (strlen(szBuffer) > 1)
    {
        gawszUnitSuffix_00730510[2][0].wChar = 'B';
    }
    else
    {
        gawszUnitSuffix_00730510[2][0].wChar = szBuffer[0];
    }

    sub_00526F70(szBuffer, D2LANG_GetStringFromTblIndex_Inline(0x14D3), 5);
    if (strlen(szBuffer) > 1)
    {
        gawszUnitSuffix_00730510[3][0].wChar = 'T';
    }
    else
    {
        gawszUnitSuffix_00730510[3][0].wChar = szBuffer[0];
    }
}

// 0x00525920
static D2TblHeaderStrc* sub_00525920_LoadTblFile(const char* szPath)
{
    D2TblHeaderStrc* pHeader = (D2TblHeaderStrc*)sub_00517079(ghArchive_008829DC, szPath, 0, ".\\StrTable\\strtable.cpp", 0xC0);

    unsigned short nCRC;
    CRC16_CalculateChecksum(&nCRC, (const unsigned char*)pHeader, pHeader->dwIndexStart, pHeader->dwFileSize);
    D2_ASSERT(nCRC == pHeader->nCRC, 0xCE);

    D2TblNodeStrc* pNode = (D2TblNodeStrc*)((char*)pHeader + sizeof(D2TblHeaderStrc) + pHeader->nNumElements * sizeof(unsigned short));
    for (int i = 0; i < pHeader->nHashTableSize; ++i)
    {
        D2_ASSERT(pNode[i].dwStringOffset < pHeader->dwFileSize, 0xE0);
        D2_ASSERT(pNode[i].dwKeyOffset < pHeader->dwFileSize, 0xE1);
    }

    return pHeader;
}

// build: context Unicode::strncat
Unicode* __fastcall Unicode::strncat(Unicode* dest, const Unicode* src, int count)
{
    Unicode* pEnd = dest;
    while (pEnd->wChar)
    {
        ++pEnd;
    }

    while (count--)
    {
        if (!src->wChar)
        {
            break;
        }
        *pEnd++ = *src++;
    }

    pEnd->wChar = 0;
    return dest;
}

// 0x00527090
bool D2LangCharSetStrc::sub_00527090_ContainsChar(const Unicode* pChar) const
{
    Unicode wszChars[20] = {};
    int i;
    for (i = 0; i < 20 && szChars[i] != '\0'; ++i)
    {
        wszChars[i].wChar = (unsigned char)szChars[i];
    }
    if (szChars[i] != '\0')
    {
        wszChars[i - 1].wChar = 0;
    }
    else
    {
        wszChars[i].wChar = 0;
    }
    const int nLength = sub_00526800(wszChars);
    for (int j = 0; j < nLength; ++j)
    {
        if (pChar->wChar == wszChars[j].wChar)
        {
            return true;
        }
    }
    return false;
}

// build: context sub_00524C60_Shim
// calling-convention shim (not game code)
unsigned short __stdcall sub_00524C60_Shim(D2StrTableHeader00524C60Strc* pTable, void** ppSlots, const char* szKey, void** ppOut)
{
	return sub_00524C60_FindKey(ppSlots, szKey, ppOut, pTable);
}
