extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2StrCacheNodeStrc
{
    wchar_t* pText;
    char* szKey;
    D2StrCacheNodeStrc* pNext;
};

extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(void* hKey, const char* szValueName, unsigned long* pReserved, unsigned long* pType, unsigned char* pData, unsigned long* pcbData); // 0x006CC00C
extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(void* hKey, const char* szSubKey, unsigned long nOptions, unsigned long nSamDesired, void** phResult); // 0x006CC010
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey);                                    // 0x006CC030
extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);
extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
unsigned short __stdcall sub_00524D30_FindString(const char* szKey, const wchar_t** ppText);               // 0x00524D30
int __fastcall sub_00525100_LookupLanguage(const char* szLanguage);                                         // 0x00525100
void __fastcall sub_00526320_ToUnicode(wchar_t* pDest, const char* szSource, int nLength);                  // 0x00526320
int __fastcall sub_00527D50_GetUnicodeLength(const char* szSource, int nLength);                            // 0x00527D50

extern const unsigned short gaCrc16Table_007301D8[256];                                                     // 0x007301D8
extern "C" const char szNotTranslated_00730520[];                                                           // 0x00730520
char gszLanguage_008829F8[256];                                                                             // 0x008829F8

static D2StrCacheNodeStrc* s_pStringCache_008829B0;                                                         // 0x008829B0

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
    const int nChars = sub_00527D50_GetUnicodeLength(szText, nLength);
    pNode->pText = (wchar_t*)FOG_Alloc(nChars * 2 + 2, ".\\StrTable\\strtable.cpp", 0x271, 0);
    sub_00526320_ToUnicode(pNode->pText, szText, nChars);
    FOG_Free(szText, ".\\StrTable\\strtable.cpp", 0x277, 0);
    return pNode->pText;
}

// 0x00524E20
const wchar_t* __fastcall D2LANG_GetStringByReferenceString(const char* szKey)
{
    const wchar_t* pText = 0;
    sub_00524D30_FindString(szKey, &pText);
    return pText;
}

// 0x00525020
void __stdcall CRC16_CalculateChecksum(unsigned short* crc16_checksum_out, const unsigned char* data, unsigned int start_index, unsigned int end_index)
{
    D2_ASSERT(start_index < end_index, 0x3EA);
    *crc16_checksum_out = 0xFFFF;
    for (unsigned int i = start_index; i < end_index; ++i)
        *crc16_checksum_out = (*crc16_checksum_out << 8) ^ gaCrc16Table_007301D8[(*crc16_checksum_out >> 8) ^ data[i]];
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

#include "gen/data/Source/Bnclient/005249E0_sub_005249E0.inc"
