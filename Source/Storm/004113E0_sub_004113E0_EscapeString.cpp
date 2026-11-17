extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);       // 0x00413A40

// 0x004113E0
char* __fastcall sub_004113E0_EscapeString(char* szDst, const char* szSrc, int nSize, char cQuote)
{
    const char* pSrc = szSrc;

    D2_ASSERT(szDst, 0xC0);

    if (!szSrc)
    {
        SStrPrintf(szDst, nSize, "<NULL>");
        return szDst;
    }

    int nLeft = nSize - 1;
    if (nSize)
    {
        char* p = szDst;
        if (cQuote && nLeft > 0)
        {
            *p++ = cQuote;
            --nLeft;
        }

        while (nLeft > 0)
        {
            const char c = *pSrc;
            if (!c)
            {
                break;
            }
            ++pSrc;
            --nLeft;

            if (c >= 0x20)
            {
                *p++ = c;
                continue;
            }

            *p++ = '\\';
            if (!nLeft)
            {
                break;
            }
            --nLeft;

            if (c == '\r')
            {
                *p++ = 'r';
            }
            else if (c == '\n')
            {
                *p++ = 'n';
            }
            else if (c == '\t')
            {
                *p++ = 't';
            }
            else
            {
                if (nLeft < 2)
                {
                    break;
                }
                *p++ = 'x';
                *p++ = ((c & 0xF0) < 0xA0) ? ((unsigned char)c >> 4) + '0' : ((unsigned char)c >> 4) + ('A' - 10);
                *p++ = ((c & 0x0F) < 0x0A) ? (c & 0x0F) + '0' : (c & 0x0F) + ('A' - 10);
                nLeft -= 2;
            }
        }

        if (cQuote && nLeft > 0)
        {
            *p++ = cQuote;
            --nLeft;
        }

        *p = 0;
        D2_ASSERT(nLeft >= 0, 0x100);
        D2_ASSERT(p - szDst + 1 <= nSize, 0x101);
    }

    return szDst;
}
