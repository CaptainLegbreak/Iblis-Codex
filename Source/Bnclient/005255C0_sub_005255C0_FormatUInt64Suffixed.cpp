extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" char* __cdecl _ui64toa(unsigned __int64 nValue, char* szOut, int nRadix);                        // 0x00687708

struct Unicode
{
    unsigned short wChar;
};

extern Unicode gawszUnitSuffix_00730510[4][2];                                                              // 0x00730510
extern "C" const char szStar_006D5830[];                                                                    // 0x006D5830
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0

// 0x005255C0
void __stdcall sub_005255C0_FormatUInt64Suffixed(Unicode* pOut, unsigned __int64 nValue, int nSize)
{
    char szBuffer[64];
    int nGroup = 0;
    int nUnit;
    D2_ASSERT(nSize > 2, 0x54B);
    _ui64toa(nValue, szBuffer, 10);
    int nLength = strlen(szBuffer);
    if (nLength)
    {
        nUnit = (nLength - 1) / 3 - 1;
        if (nUnit >= 4)
        {
            nUnit = 4;
        }
        else if (nUnit < 0)
        {
            nUnit = 0;
        }
        nLength += nUnit * -3;
        int nPos = nLength + (nLength - 1) / 3;
        if (nPos >= 1 && nPos < nSize - 2)
        {
            pOut[nPos + 1].wChar = 0;
            switch (nUnit)
            {
            case 0:
                pOut[nPos].wChar = 0;
                break;
            case 1:
                pOut[nPos].wChar = gawszUnitSuffix_00730510[0][0].wChar;
                break;
            case 2:
                pOut[nPos].wChar = gawszUnitSuffix_00730510[1][0].wChar;
                break;
            case 3:
                pOut[nPos].wChar = gawszUnitSuffix_00730510[2][0].wChar;
                break;
            case 4:
                pOut[nPos].wChar = gawszUnitSuffix_00730510[3][0].wChar;
                break;
            }
            while (nLength)
            {
                D2_ASSERT(nPos != 0, 0x580);
                --nLength;
                --nPos;
                pOut[nPos].wChar = szBuffer[nLength];
                ++nGroup;
                if (nGroup >= 3)
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
