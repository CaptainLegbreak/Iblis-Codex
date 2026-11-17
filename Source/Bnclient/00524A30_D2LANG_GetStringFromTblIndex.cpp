extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode
{
    unsigned short ch;
};

struct D2LanguageInfoStrc
{
    const char* szName;
    const char* szCode;
    const char* szAltCode;
    const char* szRegion;
    int nFourCC;
    int f_14;
};

struct D2StringTableStrc;

extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2);                              // 0x006841E9
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
const Unicode* __fastcall sub_00524930(D2StringTableStrc* pTable, void* pIndex, unsigned short nIndex); // 0x00524930

extern D2LanguageInfoStrc gaLanguageInfo_007303D8[13];                                                      // 0x007303D8
extern D2StringTableStrc* gpStringTable_008829B4;                                                           // 0x008829B4
extern void* gpStringIndex_008829B8;                                                                        // 0x008829B8
extern void* gpPatchStringIndex_008829BC;                                                                   // 0x008829BC
extern void* gpExpansionStringIndex_008829C0;                                                               // 0x008829C0
extern D2StringTableStrc* gpPatchStringTable_008829D0;                                                      // 0x008829D0
extern D2StringTableStrc* gpExpansionStringTable_008829D4;                                                  // 0x008829D4
extern void* ghArchive_008829DC;                                                                            // 0x008829DC
int gnTableLanguage_008829EC;                                                                               // 0x008829EC
bool gbTableLanguageInitialized_008829F0;                                                                   // 0x008829F0

// 0x00524A30
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex)
{
    if (nIndex >= 0x4E20)
    {
        if (!gpExpansionStringTable_008829D4)
        {
            nIndex = 0x2B46;
        }
        else
        {
            const Unicode* pText = sub_00524930(gpExpansionStringTable_008829D4, gpExpansionStringIndex_008829C0, nIndex - 0x4E20);
            if (pText)
                return pText;
        }
    }
    if (gpPatchStringTable_008829D0 && nIndex >= 0x2710)
    {
        const Unicode* pText = sub_00524930(gpPatchStringTable_008829D0, gpPatchStringIndex_008829BC, nIndex - 0x2710);
        if (pText)
            return pText;
    }
    D2_ASSERT(gpStringTable_008829B4, 0x246);
    return sub_00524930(gpStringTable_008829B4, gpStringIndex_008829B8, nIndex);
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
        unsigned char* pBuffer = (unsigned char*)sub_00517079_LoadFile(ghArchive_008829DC, "data\\local\\use", 0, ".\\StrTable\\strtable.cpp", 0x44B);
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
