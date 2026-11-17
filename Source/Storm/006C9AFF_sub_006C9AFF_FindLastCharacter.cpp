// 0x006C9AFF
const char* __fastcall sub_006C9AFF_FindLastCharacter(const char* text, char character)
{
    const char* result = 0;
    for (const char* p = text; *p; ++p)
    {
        if (*p == character)
            result = p;
    }
    return result;
}
