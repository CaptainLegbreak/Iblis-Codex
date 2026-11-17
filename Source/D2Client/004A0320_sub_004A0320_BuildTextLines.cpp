struct Unicode
{
    unsigned short wChar;

    Unicode() {}
    Unicode(unsigned short ch) : wChar(ch) {}
};

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall sub_00526800(const Unicode* pString);                                               // 0x00526800
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);            // 0x005267E0
void __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength);         // 0x005263E0
int __fastcall sub_00501820(const Unicode* wszText);                                      // 0x00501820

// build: context TEXT_ReadLine
static __forceinline const unsigned short* TEXT_ReadLine(Unicode* pLine, const unsigned short* pText)
{
    int i = 0;
    memset(pLine, 0, 100 * sizeof(Unicode));
    for (; i < 100 && *pText != '\n'; ++i)
    {
        pLine[i] = *pText++;
    }
    if (i < 100 && *pText == '\n')
    {
        ++pText;
    }
    return pText;
}

// 0x004A0320
T0044CB60* __stdcall sub_004A0320_BuildTextLines(const unsigned short* wszText, int* pLineCount, unsigned short* pMaxLines)
{
    Unicode szLine[100];
    const unsigned short* pText = wszText;

    *pLineCount = 0;
    T0044CB60* pLast = 0;
    T0044CB60* pFirst = 0;
    int bFirstLine = 1;
    while (*pText)
    {
        pText = TEXT_ReadLine(szLine, pText);

        T0044CB60* pLine = (T0044CB60*)FOG_Alloc(sizeof(T0044CB60), ".\\UI\\text.cpp", 0x5B8, 0);
        if (bFirstLine == 1)
        {
            const int nLength = sub_00526800(szLine);
            int bAscii = 1;
            for (int j = 0; j < nLength; ++j)
            {
                if (szLine[j].wChar >= 0x80)
                {
                    bAscii = 0;
                }
            }

            if (bAscii)
            {
                char szNumber[100];
                sub_005263E0(szNumber, szLine, 100);
                *pMaxLines = atoi(szNumber);
            }
            else
            {
                char szMessage[80];
                wsprintfA(szMessage, "line 0 of string does not contain scroll rate");
                *pMaxLines = 8;
            }

            bFirstLine = 0;
            pText = TEXT_ReadLine(szLine, pText);
        }

        const int nLength = sub_00526800(szLine);
        if (sub_00501820(szLine) >= 0x134)
        {
            char szMessage[80];
            wsprintfA(szMessage, "line %d of string is too long", *pLineCount);
        }

        pLine->pText = (Unicode*)FOG_Alloc(sizeof(Unicode) * (nLength + 1), ".\\UI\\text.cpp", 0x5EB, 0);
        sub_005267E0(pLine->pText, szLine);
        pLine->pNext = 0;
        if (pLast)
        {
            pLast->pNext = pLine;
        }
        else
        {
            pFirst = pLine;
        }
        ++*pLineCount;
        pLast = pLine;
    }
    return pFirst;
}
