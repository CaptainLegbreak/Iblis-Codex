extern const unsigned char gCharacterClass_0074C5C8[]; // 0x0074C5C8

// 0x006C9ADF
const char* __fastcall sub_006C9ADF_CopyWord(char* szDest, const char* szSource)
{
    while (*szSource && !(gCharacterClass_0074C5C8[*szSource] & 1))
    {
        *szDest = *szSource;
        ++szDest;
        ++szSource;
    }
    *szDest = 0;
    return szSource;
}
