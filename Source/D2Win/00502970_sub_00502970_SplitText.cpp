struct Unicode
{
    unsigned short wChar;

    static Unicode* __fastcall strncpy(Unicode* dest, const Unicode* src, int count);                       // 0x00526790
};

struct D2SplittedTextStrc
{
    Unicode* wszLine;
    D2SplittedTextStrc* pNextLine;
};

extern "C" int __cdecl isspace(int c);                                                                      // 0x00687006
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                                // 0x0040B380
extern "C" const char gszD2WinFontSourceFile[];                                                             // 0x006DC9FC
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __fastcall sub_00501730_GetTextWidthN(const Unicode* wszText, int nLength);                             // 0x00501730
int __fastcall sub_00526D30(const Unicode* pText, int nCount);                                              // 0x00526D30

D2SplittedTextStrc* __stdcall sub_005028E0_AllocSplitTextLine(const Unicode* wszText, int nLength, int bSkipSpace); // 0x005028E0

// build: context AllocSplitTextLine_Inline
static __forceinline D2SplittedTextStrc* AllocSplitTextLine_Inline(const Unicode* wszText, int nLength, int bSkipSpace)
{
    D2SplittedTextStrc* pSplitText = (D2SplittedTextStrc*)FOG_Alloc(sizeof(D2SplittedTextStrc), gszD2WinFontSourceFile, 0x588, 0);
    int nCount = nLength;
    const Unicode* pText = wszText;
    if (bSkipSpace && pText->wChar < 0x100 && isspace(pText->wChar))
    {
        nCount = nCount - 1;
        pText = pText + 1;
    }
    pSplitText->wszLine = (Unicode*)FOG_Alloc(sizeof(Unicode) * (nCount + 1), gszD2WinFontSourceFile, 0x591, 0);
    pSplitText->pNextLine = 0;
    Unicode::strncpy(pSplitText->wszLine, pText, nCount);
    pSplitText->wszLine[nCount].wChar = 0;
    return pSplitText;
}

// 0x00502970
D2SplittedTextStrc* __fastcall sub_00502970_SplitText(const Unicode* wszText, int* pLineCount, int nWidth)
{
    const int nLength = sub_00526800(wszText);
    D2SplittedTextStrc* pLast = 0;
    D2SplittedTextStrc* pFirst = 0;
    *pLineCount = 0;
    if (sub_00501730_GetTextWidthN(wszText, nLength) <= nWidth)
    {
        *pLineCount = 1;
        return AllocSplitTextLine_Inline(wszText, nLength + 1, 0);
    }

    int nStart = 0;
    int nEnd = nLength;
    for (;;)
    {
        int nTextWidth = 0;
        for (; nEnd > nStart; --nEnd)
        {
            nTextWidth = sub_00501730_GetTextWidthN(&wszText[nStart], nEnd - nStart + 1);
            if (nTextWidth <= nWidth)
            {
                break;
            }
        }
        for (; nEnd > nStart; --nEnd)
        {
            if (nEnd == nLength || sub_00526D30(&wszText[nStart], nEnd - nStart + 1))
            {
                break;
            }
        }

        if (nEnd == nStart)
        {
            for (nEnd = nLength; nEnd > nStart; --nEnd)
            {
                if (sub_00501730_GetTextWidthN(&wszText[nStart], nEnd - nStart + 1) <= nWidth)
                {
                    break;
                }
            }

            D2SplittedTextStrc* pLine = AllocSplitTextLine_Inline(&wszText[nStart], nEnd - nStart + 1, 1);
            ++*pLineCount;
            if (pLast)
            {
                pLast->pNextLine = pLine;
            }
            pLast = pLine;
            if (!pFirst)
            {
                pFirst = pLine;
            }
            nStart = nEnd + 1;
            nEnd = nLength;
            if (nStart > nLength)
            {
                break;
            }
        }
        else
        {
            if (nTextWidth > nWidth)
            {
                for (nEnd = nLength; nEnd > nStart; --nEnd)
                {
                    if (sub_00501730_GetTextWidthN(&wszText[nStart], nEnd - nStart + 1) <= nWidth)
                    {
                        break;
                    }
                }
                for (; nEnd > nStart; --nEnd)
                {
                    if (nEnd == nLength || sub_00526D30(&wszText[nStart], nEnd - nStart + 1))
                    {
                        break;
                    }
                }
                D2SplittedTextStrc* pLine;
                if (nEnd == nStart)
                {
                    for (nEnd = nLength; nEnd > nStart; --nEnd)
                    {
                        if (sub_00501730_GetTextWidthN(&wszText[nStart], nEnd - nStart + 1) <= nWidth)
                        {
                            break;
                        }
                    }
                    pLine = sub_005028E0_AllocSplitTextLine(&wszText[nStart], nEnd - nStart + 1, 1);
                }
                else
                {
                    pLine = sub_005028E0_AllocSplitTextLine(&wszText[nStart], nEnd - nStart + 1, 1);
                }
                ++*pLineCount;
                if (pLast)
                {
                    pLast->pNextLine = pLine;
                }
                pLast = pLine;
                if (!pFirst)
                {
                    pFirst = pLine;
                }
                nStart = nEnd + 1;
                nEnd = nLength;
                if (nStart > nLength)
                {
                    break;
                }
            }
            else
            {
                D2SplittedTextStrc* pLine = sub_005028E0_AllocSplitTextLine(&wszText[nStart], nEnd - nStart + 1, 1);
                ++*pLineCount;
                if (pLast)
                {
                    pLast->pNextLine = pLine;
                }
                pLast = pLine;
                if (!pFirst)
                {
                    pFirst = pLine;
                }
                nStart = nEnd + 1;
                nEnd = nLength;
                if (nStart > nLength)
                {
                    break;
                }
            }
        }
    }

    return pFirst;
}
