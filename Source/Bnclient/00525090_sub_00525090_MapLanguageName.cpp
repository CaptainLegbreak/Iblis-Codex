struct D2LanguageInfoStrc
{
    const char* szName;
    const char* szCode;
    const char* szAltCode;
    const char* szRegion;
    int nFourCC;
    int f_14;
};

extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2);                              // 0x006841E9
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern D2LanguageInfoStrc gaLanguageInfo_007303D8[13];                                                      // 0x007303D8

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
