struct Unicode
{
    unsigned short wChar;

    static int __fastcall strncmp(const Unicode* str1, const Unicode* str2, unsigned int count);
};

// 0x00526540
int __fastcall Unicode::strncmp(const Unicode* str1, const Unicode* str2, unsigned int count)
{
    while (str1->wChar && str2->wChar && count--)
    {
        const Unicode tChar1 = *str1++;
        const Unicode tChar2 = *str2++;
        if (tChar1.wChar != tChar2.wChar)
            return tChar1.wChar < tChar2.wChar ? -1 : 1;
    }
    return 0;
}
