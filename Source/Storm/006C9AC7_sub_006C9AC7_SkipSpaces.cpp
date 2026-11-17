extern const unsigned char gCharacterClass_0074C5C8[]; // 0x0074C5C8

// 0x006C9AC7
const char* __fastcall sub_006C9AC7_SkipSpaces(const char* szText)
{
    while (*szText && (gCharacterClass_0074C5C8[*szText] & 1))
    {
        ++szText;
    }
    return szText;
}
