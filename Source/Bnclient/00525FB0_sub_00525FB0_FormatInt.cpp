extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" char* __cdecl _itoa(int nValue, char* szOut, int nRadix);                                        // 0x00687605

struct Unicode
{
    unsigned short wChar;

    static Unicode* __fastcall strncat(Unicode* dest, const Unicode* src, int count);
};

extern "C" const char szStar_006D5830[];                                                                    // 0x006D5830
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0

// 0x00525FB0
void __stdcall sub_00525FB0_FormatInt(Unicode* pOut, int nValue, int nSize)
{
    char szBuffer[64];
    int nGroup = 0;
    D2_ASSERT(nSize > 2, 0x4B9);
    if (nValue < 0)
    {
        pOut->wChar = '-';
        ++pOut;
        --nSize;
        nValue = -nValue;
    }
    _itoa(nValue, szBuffer, 10);
    int nLength = strlen(szBuffer);
    if (nLength)
    {
        int nPos = nLength + (nLength - 1) / 3;
        if (nPos >= 1 && nPos < nSize - 1)
        {
            pOut[nPos].wChar = 0;
            while (nLength)
            {
                D2_ASSERT(nPos != 0, 0x4D3);
                --nLength;
                --nPos;
                pOut[nPos].wChar = szBuffer[nLength];
                ++nGroup;
                if (nGroup >= 3 && strlen(szBuffer) > 3)
                {
                    nGroup = 0;
                    if (nPos > 0)
                    {
                        --nPos;
                        pOut[nPos].wChar = ',';
                    }
                }
            }
            return;
        }
    }
    {
        Unicode wszStar[2];
        wszStar[0].wChar = 0;
        wszStar[1].wChar = 0;
        sub_00526320_ToUnicode(wszStar, szStar_006D5830, 2);
        sub_005267E0(pOut, wszStar);
    }
}

// 0x00526740
Unicode* __fastcall Unicode::strncat(Unicode* dest, const Unicode* src, int count)
{
    Unicode* pEnd = dest;
    while (pEnd->wChar)
    {
        ++pEnd;
    }

    unsigned short wChar;
    while (count-- && (wChar = src->wChar) != 0)
    {
        pEnd->wChar = wChar;
        ++pEnd;
        ++src;
    }

    pEnd->wChar = 0;
    return dest;
}
