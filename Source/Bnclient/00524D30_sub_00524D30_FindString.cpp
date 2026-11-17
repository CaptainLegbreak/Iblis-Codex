extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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

extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);
unsigned int __stdcall sub_005249E0(const char* szKey, unsigned int nTableSize);                           // 0x005249E0
wchar_t* __fastcall sub_00524AC0_GetUntranslatedString(const char* szKey);                                  // 0x00524AC0

extern D2StringTableStrc* gpStringTable_008829B4;                                                           // 0x008829B4
extern void* gpStringIndex_008829B8;                                                                        // 0x008829B8
extern void* gpPatchStringIndex_008829BC;                                                                   // 0x008829BC
extern void* gpExpansionStringIndex_008829C0;                                                               // 0x008829C0
extern D2StringTableStrc* gpPatchStringTable_008829D0;                                                      // 0x008829D0
extern D2StringTableStrc* gpExpansionStringTable_008829D4;                                                  // 0x008829D4
wchar_t gwszEmptyString_008829E8[2];                                                                        // 0x008829E8

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
    D2_ASSERT(gpStringTable_008829B4, 0x2BA);
    D2_ASSERT(gpPatchStringTable_008829D0, 0x2BB);
    D2_ASSERT(szKey, 0x2C0);
    if (!*szKey)
    {
        *ppText = gwszEmptyString_008829E8;
        return 0;
    }
    unsigned short nIndex = sub_00524C60_FindInTable(gpPatchStringTable_008829D0, (const wchar_t**)gpPatchStringIndex_008829BC, szKey, ppText);
    if (nIndex != 0xFFFF)
        return nIndex + 10000;
    if (gpExpansionStringTable_008829D4)
    {
        nIndex = sub_00524C60_FindInTable(gpExpansionStringTable_008829D4, (const wchar_t**)gpExpansionStringIndex_008829C0, szKey, ppText);
        if (nIndex != 0xFFFF)
            return nIndex + 20000;
    }
    nIndex = sub_00524C60_FindInTable(gpStringTable_008829B4, (const wchar_t**)gpStringIndex_008829B8, szKey, ppText);
    if (nIndex == 0xFFFF)
    {
        *ppText = sub_00524AC0_GetUntranslatedString(szKey);
        return 0;
    }
    return nIndex;
}
