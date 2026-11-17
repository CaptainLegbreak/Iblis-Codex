void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
extern "C" const unsigned __int64 gqwSStrHash64Table_006CEE70[16];                                          // 0x006CEE70

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// 0x00413DC0
unsigned __int64 __stdcall SStrHash64(const char* szString, unsigned int nFlags, unsigned __int64 nSeed)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    unsigned __int64 nResult = nSeed ? nSeed : 0x7FED7FED7FED7FEDui64;
    unsigned __int64 nAdjust = 0xEEEEEEEEEEEEEEEEui64;
    unsigned int nChar;
    if (nFlags & 1)
    {
        while ((nChar = (unsigned char)*szString) != 0)
        {
            ++szString;
            nResult = (gqwSStrHash64Table_006CEE70[nChar >> 4] - gqwSStrHash64Table_006CEE70[nChar & 0xF]) ^ (nAdjust + nResult);
            nAdjust = nAdjust * 0x21 + nChar + nResult + 3;
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
            nResult = (gqwSStrHash64Table_006CEE70[nChar >> 4] - gqwSStrHash64Table_006CEE70[nChar & 0xF]) ^ (nAdjust + nResult);
            nAdjust = nAdjust * 0x21 + nChar + nResult + 3;
        }
    }
    if (!nResult)
    {
        nResult = 1;
    }
    return nValid ? nResult : 0;
}

#include "gen/data/Source/Storm/00413DC0_SStrHash64.inc"
