struct Unicode
{
    unsigned short wChar;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
extern "C" char* __cdecl _itoa(int nValue, char* szOut, int nRadix);                                        // 0x00687605
extern "C" char* __cdecl _ultoa(unsigned long nValue, char* szOut, int nRadix);                             // 0x00687652
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0
Unicode* __fastcall sub_00526740(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526740
Unicode* __fastcall sub_00526940_FindSubstring(const Unicode* pString, const Unicode* pSubstring);           // 0x00526940

static __forceinline int Unicode_strlen_Inline(const Unicode* pString)
{
    int nLength = 0;
    if (pString)
    {
        while (pString->wChar)
        {
            ++pString;
            ++nLength;
        }
    }
    return nLength;
}

static __forceinline void Unicode_strcpy_Inline(Unicode* pDest, const Unicode* pSource)
{
    do
    {
        *pDest++ = *pSource;
    }
    while (pSource++->wChar);
}

// 0x005269D0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...)
{
    if (!pFormat)
    {
        return;
    }

    int nArg = *(const int*)(&pFormat + 1);
    pBuffer->wChar = 0;
    int nPos = 0;
    const Unicode* pFound = 0;
    if (!pFormat->wChar)
    {
        return;
    }

    Unicode szPercent[2];
    szPercent[0].wChar = '%';
    szPercent[1].wChar = 0;
    Unicode wSpec;
    const int* pArgs = (const int*)(&pFormat + 1);

    do
    {
        wSpec.wChar = 0;
        const Unicode* pNext = sub_00526940_FindSubstring(pFormat, szPercent);
        if (pNext)
        {
            pFound = pNext;
            wSpec = pNext[1];
        }

        while (pFormat != pFound && pFormat->wChar)
        {
            if (nPos >= nBufferSize)
            {
                pBuffer[-1].wChar = 0;
                return;
            }
            *pBuffer++ = *pFormat++;
            ++nPos;
        }

        if (nPos >= nBufferSize)
        {
            pBuffer[-1].wChar = 0;
            return;
        }

        if (!pFormat->wChar)
        {
            pBuffer->wChar = 0;
            return;
        }

        D2_ASSERT(pFound, 0x10D);

        switch (wSpec.wChar)
        {
        case 'd':
        case 'u':
        {
            Unicode wszNumber[15];
            char szNumber[16];
            memset(wszNumber, 0, sizeof(wszNumber));
            if (wSpec.wChar == 'd')
            {
                _itoa(nArg, szNumber, 10);
            }
            else
            {
                _ultoa(nArg, szNumber, 10);
            }
            sub_00526320_ToUnicode(wszNumber, szNumber, 15);
            const int nLength = Unicode_strlen_Inline(wszNumber);
            if (nLength + nPos + 1 >= nBufferSize)
            {
                return;
            }
            Unicode_strcpy_Inline(pBuffer, wszNumber);
            nPos += nLength;
            pBuffer += nLength;
            break;
        }

        case 's':
        {
            const Unicode* pString = (const Unicode*)nArg;
            const int nLength = Unicode_strlen_Inline(pString);
            if (!nLength || nLength + nPos + 1 >= nBufferSize)
            {
                sub_00526740(pBuffer, pString, nBufferSize - nPos - 1);
                return;
            }
            Unicode_strcpy_Inline(pBuffer, pString);
            pBuffer += nLength;
            nPos += nLength;
            break;
        }

        case '%':
            if (nPos + 1 >= nBufferSize)
            {
                return;
            }
            Unicode_strcpy_Inline(pBuffer, szPercent);
            ++pBuffer;
            ++nPos;
            break;

        case 0:
            sub_005267E0(pBuffer, szPercent);
            return;

        default:
            D2_ASSERT(0, 0x154);
            break;
        }

        pFormat += 2;
        ++pArgs;
        nArg = *pArgs;
    }
    while (pFormat->wChar);
}
