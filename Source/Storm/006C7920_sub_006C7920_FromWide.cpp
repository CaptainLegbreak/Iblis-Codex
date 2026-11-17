extern const unsigned short gWideTable_006FCFC0[]; // 0x006FCFC0

static __declspec(noinline) int __stdcall sub_006C77F0_ConvertFromWide(const unsigned short* source, unsigned int count, const unsigned short* volatile table, char* destination);

// 0x006C77F0
static int __stdcall sub_006C77F0_ConvertFromWide(const unsigned short* source, unsigned int count, const unsigned short* volatile table, char* destination)
{
    if (!count)
    {
        return 0;
    }

    char* out = destination;
    unsigned short ch = *source;
    while (ch && count)
    {
        if (ch < 0x100 && ch == table[ch])
        {
            *out = (char)*source;
        }
        else
        {
            int i = 255;
            const unsigned short* p = &table[253];
            do
            {
                if (ch == p[2])
                {
                    break;
                }
                if (ch == p[1])
                {
                    i -= 1;
                    break;
                }
                if (ch == p[0])
                {
                    i -= 2;
                    break;
                }
                if (ch == p[-1])
                {
                    i -= 3;
                    break;
                }
                if (ch == p[-2])
                {
                    i -= 4;
                    break;
                }
                i -= 5;
                p -= 5;
            }
            while (i > 0);
            *out = (char)(i ? i : '?');
        }
        ch = *++source;
        ++out;
        --count;
    }

    if (count)
    {
        *out++ = 0;
    }

    return out - destination;
}

// 0x006C7920
int __stdcall sub_006C7920_FromWide(char* pDest, const unsigned short* pSource, unsigned int nCount)
{
    return sub_006C77F0_ConvertFromWide(pSource, nCount, gWideTable_006FCFC0, pDest);
}
