int __cdecl sub_00525150(); // 0x00525150
extern "C" int __cdecl isspace(int c); // 0x00687006
struct Unicode
{
    unsigned short wChar;

    int isWhitespace() const
    {
        return wChar < 0x100 && isspace(wChar);
    }
};

// 0x00526D30
int __fastcall sub_00526D30_IsLineBreak(const Unicode* pText, unsigned int nIndex)
{
    if (!nIndex)
    {
        return 1;
    }

    switch (sub_00525150())
    {
    case 6:
    case 8:
    case 9:
    {
#define wChar pText[nIndex].wChar
        if (wChar == 0x2026 || wChar == 0x3001 || wChar == 0x3002 || wChar == 0xFF01 || wChar == 0xFF0C
            || wChar == 0xFF0E || wChar == 0xFF1F || wChar == 0xFF61 || wChar == 0xFF64)
        {
            return 0;
        }
        if (wChar >= 'a' && wChar <= 'z')
        {
            return 0;
        }
        if (wChar >= 0xFF41 && wChar <= 0xFF5A)
        {
            return 0;
        }
        if (wChar >= 'A' && wChar <= 'Z')
        {
            return 0;
        }
        if (wChar >= 0xFF21 && wChar <= 0xFF3A)
        {
            return 0;
        }
        if (wChar >= '0' && wChar <= '9')
        {
            return 0;
        }
        if (wChar >= 0xFF10 && wChar <= 0xFF19)
        {
            return 0;
        }
        return 1;
#undef wChar
    }
    }

    if (pText[nIndex].isWhitespace())
    {
        return 0;
    }
    return pText[nIndex - 1].isWhitespace();
}
