struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short wValue = 0) : wChar(wValue) {}

    static Unicode* __fastcall strchr(const Unicode* str, Unicode ch);
};

// 0x005266C0
Unicode* __fastcall Unicode::strchr(const Unicode* str, Unicode ch)
{
    while (str->wChar && str->wChar != ch.wChar)
        ++str;
    if (str->wChar)
        return (Unicode*)str;
    return 0;
}
