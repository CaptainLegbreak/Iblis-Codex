const char* __fastcall sub_006C9AFF_FindLastCharacter(const char* text, char character); // 0x006C9AFF

// 0x006C9B17
char* __fastcall sub_006C9B17_StripFileName(char* szPath)
{
    char* pSlash = (char*)sub_006C9AFF_FindLastCharacter(szPath, '\\');
    if (!pSlash)
    {
        *szPath = 0;
    }
    else
    {
        *pSlash = 0;
    }
    return szPath;
}
