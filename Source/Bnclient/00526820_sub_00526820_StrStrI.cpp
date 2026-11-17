struct Unicode
{
    unsigned short ch;
};

extern unsigned short gwToUpperTable_00730578[0x100];                                                       // 0x00730578

// 0x00526820
Unicode* __fastcall sub_00526820_StrStrI(const Unicode* str, const Unicode* substr)
{
    if (!str || !substr)
    {
        return 0;
    }

    Unicode c = *str;
    for (;;)
    {
        const Unicode first = *substr;
        for (;;)
        {
            const unsigned short ch1 = c.ch < 0x100 ? gwToUpperTable_00730578[c.ch] : c.ch;
            const unsigned short ch2 = first.ch < 0x100 ? gwToUpperTable_00730578[first.ch] : first.ch;
            if (ch1 == ch2)
            {
                break;
            }

            c = *++str;
            if (!c.ch)
            {
                return 0;
            }
        }

        int n = 0;
        for (;;)
        {
            const unsigned short s1 = str->ch;
            const unsigned short s2 = substr->ch;
            const unsigned short ch1 = s1 < 0x100 ? gwToUpperTable_00730578[s1] : s1;
            const unsigned short ch2 = s2 < 0x100 ? gwToUpperTable_00730578[s2] : s2;
            if (ch1 != ch2 || !s1)
            {
                break;
            }

            if (!s2)
            {
                goto found;
            }

            ++str;
            ++substr;
            ++n;
        }

        if (!substr->ch)
        {
found:
            return (Unicode*)(str - n);
        }

        if (!str->ch)
        {
            return 0;
        }

        str = str - n + 1;
        substr -= n;
    }
}
