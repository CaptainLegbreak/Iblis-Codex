struct Unicode
{
    unsigned short ch;

    static int __fastcall strcmp(const Unicode* str1, const Unicode* str2);
    static Unicode* __fastcall strcat(Unicode* dest, const Unicode* src);
};

// 0x005264F0
int __fastcall Unicode::strcmp(const Unicode* str1, const Unicode* str2)
{
    while (str1->ch && str2->ch && str1->ch == str2->ch)
    {
        ++str1;
        ++str2;
    }
    if (str1->ch < str2->ch)
        return -1;
    return str1->ch > str2->ch;
}

// 0x00526700
Unicode* __fastcall Unicode::strcat(Unicode* dest, const Unicode* src)
{
    Unicode* pEnd = dest;
    while (pEnd->ch)
        ++pEnd;
    do
    {
        pEnd->ch = src->ch;
        ++pEnd;
    }
    while ((src++)->ch);
    return dest;
}
