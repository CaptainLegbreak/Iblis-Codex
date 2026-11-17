void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490
extern "C" const unsigned int gdwSStrHashTable_006CEE30[16];                                                // 0x006CEE30

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }
#define VALIDATEENDVOID if (!nValid) { sub_0041C340_SetLastError(0x57); return; }

// 0x00413B80
void __stdcall SStrTokenize(const char** pszString, char* szBuffer, unsigned int nBufferChars, const char* szWhitespace, int* pQuoted)
{
    int nValid = ((__int64)pszString) ? -1 : 0;
    VALIDATE(*pszString);
    VALIDATE(szBuffer || !nBufferChars);
    VALIDATE(szWhitespace);
    VALIDATEENDVOID;

    const int bQuotesAllowed = SStrChr(szWhitespace, '"') != 0;
    const char* pCurr = *pszString;
    int bInQuotes = 0;
    int bUsedQuotes = 0;
    while (*pCurr && SStrChr(szWhitespace, *pCurr))
    {
        if (bQuotesAllowed && *pCurr == '"')
        {
            bUsedQuotes = 1;
            bInQuotes = 1;
            ++pCurr;
            break;
        }
        ++pCurr;
    }

    unsigned int nLength = 0;
    char nChar;
    while ((nChar = *pCurr) != 0)
    {
        if (bQuotesAllowed && nChar == '"')
        {
            if (nLength && !bInQuotes)
            {
                break;
            }
            bInQuotes = !bInQuotes;
            ++pCurr;
            bUsedQuotes = 1;
            if (!bInQuotes)
            {
                break;
            }
            continue;
        }
        if (!bInQuotes && SStrChr(szWhitespace, nChar))
        {
            ++pCurr;
            break;
        }
        if (nLength + 1 < nBufferChars)
        {
            szBuffer[nLength++] = nChar;
        }
        ++pCurr;
    }

    if (nLength < nBufferChars)
    {
        szBuffer[nLength] = 0;
    }
    *pszString = pCurr;
    if (nValid && pQuoted)
    {
        *pQuoted = bUsedQuotes;
    }
}

// 0x00413CE0
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    unsigned int nResult = nSeed ? nSeed : 0x7FED7FED;
    unsigned int nAdjust = 0xEEEEEEEE;
    unsigned int nChar;
    if (nFlags & 1)
    {
        while ((nChar = (unsigned char)*szString) != 0)
        {
            ++szString;
            nResult = (gdwSStrHashTable_006CEE30[nChar >> 4] - gdwSStrHashTable_006CEE30[nChar & 0xF]) ^ (nResult + nAdjust);
            nAdjust = (nAdjust << 5) + nChar + nAdjust + nResult + 3;
        }
    }
    else
    {
        while ((nChar = (unsigned char)*szString) != 0)
        {
            ++szString;
            if (nChar >= 'a' && nChar <= 'z')
            {
                nChar -= 0x20;
            }
            if (nChar == '/')
            {
                nChar = '\\';
            }
            nResult = (gdwSStrHashTable_006CEE30[nChar >> 4] - gdwSStrHashTable_006CEE30[nChar & 0xF]) ^ (nResult + nAdjust);
            nAdjust = (nAdjust << 5) + nChar + nAdjust + nResult + 3;
        }
    }
    if (!nResult)
    {
        nResult = 1;
    }
    return nValid ? nResult : 0;
}

#include "gen/data/Source/Storm/00413B80_SStrTokenize.inc"
