const char* __fastcall sub_006C9AFF_FindLastCharacter(const char* text, char character); // 0x006C9AFF

// 0x006C9B30
const char* __fastcall sub_006C9B30_GetFileName(const char* szPath)
{
    const char* pSlash = sub_006C9AFF_FindLastCharacter(szPath, '\\');
    if (!pSlash)
    {
        return szPath;
    }
    return pSlash + 1;
}
