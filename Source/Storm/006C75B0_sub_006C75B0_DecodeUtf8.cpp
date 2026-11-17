// 0x006C75B0
int __stdcall sub_006C75B0_DecodeUtf8(const unsigned char* str, int* pLength)
{
    if (pLength)
        *pLength = 0;
    if (!str)
        return -1;

    unsigned int c = *str++;
    if (!c)
        return -1;
    if (pLength)
        ++*pLength;

    int nExtra;
    if ((c & 0xFE) == 0xFC)
    {
        c &= 1;
        nExtra = 5;
    }
    else if ((c & 0xFC) == 0xF8)
    {
        c &= 3;
        nExtra = 4;
    }
    else if ((c & 0xF8) == 0xF0)
    {
        c &= 7;
        nExtra = 3;
    }
    else if ((c & 0xF0) == 0xE0)
    {
        c &= 0xF;
        nExtra = 2;
    }
    else if ((c & 0xE0) == 0xC0)
    {
        c &= 0x1F;
        nExtra = 1;
    }
    else
    {
        if (c & 0x80)
            return 0x80000000;
        return c;
    }

    for (int i = 0; i < nExtra; ++i)
    {
        unsigned char b = *str++;
        if (!b)
            return -1;
        if (pLength)
            ++*pLength;
        if ((b & 0xC0) != 0x80)
            return 0x80000000;
        c = (c << 6) | (b & 0x3F);
    }
    return c;
}
