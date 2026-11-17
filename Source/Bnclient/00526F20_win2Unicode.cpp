struct Unicode
{
    unsigned short wChar;

    static Unicode* __fastcall win2Unicode(Unicode* dest, const char* src, int count);
};

// 0x00526F20
Unicode* __fastcall Unicode::win2Unicode(Unicode* dest, const char* src, int count)
{
    int i;
    for (i = 0; i < count; ++i)
    {
        unsigned char src_ch = src[i];
        if (src_ch == '\0')
        {
            break;
        }
        dest[i].wChar = src_ch;
    }

    if (src[i] != '\0')
    {
        dest[i - 1].wChar = 0;
        return dest;
    }

    dest[i].wChar = 0;
    return dest;
}
