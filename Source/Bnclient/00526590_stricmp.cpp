struct Unicode
{
    unsigned short ch;

    static int __fastcall stricmp(const Unicode* str1, const Unicode* str2);
};

extern unsigned short gwToUpperTable_00730578[0x100];                                                       // 0x00730578

// 0x00526590
int __fastcall Unicode::stricmp(const Unicode* str1, const Unicode* str2)
{
    while (str1->ch && str2->ch)
    {
        const unsigned short ch1 = str1->ch < 0x100 ? gwToUpperTable_00730578[str1->ch] : str1->ch;
        const unsigned short ch2 = str2->ch < 0x100 ? gwToUpperTable_00730578[str2->ch] : str2->ch;
        if (ch1 != ch2)
            return ch1 < ch2 ? -1 : 1;
        ++str1;
        ++str2;
    }
    if (str1->ch)
        return 1;
    return str2->ch ? -1 : 0;
}
