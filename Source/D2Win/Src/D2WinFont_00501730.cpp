#include "D2WinTypes.h"
#include "D2Unicode.h"
extern D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(int nChar);                                        // 0x00841DA0

inline int D2Win_IsColorCodePrefix(unsigned short wChar)
{
    if (wChar >= 0x100)
    {
        return 0;
    }

    return wChar == 0xFF;
}

// 0x00501730
int __fastcall D2Win_10123(const Unicode* wszText, int nTextLength)
{
    int nWidth = 0;
    int nCount = 0;
    const Unicode* pChar = wszText;
    while (pChar->wChar)
    {
        if (nCount >= nTextLength)
        {
            break;
        }

        const unsigned short wChar = pChar->wChar;
        if (wChar != '\n')
        {
            if (nCount + 3 < nTextLength && D2Win_IsColorCodePrefix(wChar) && pChar[1].wChar == 'c' && pChar[2].wChar >= '0' && pChar[2].wChar < '7')
            {
                pChar += 3;
                nCount += 3;
                continue;
            }

            nWidth += gpfGetCharInfo_00841DA0(wChar)->nWidth;
        }

        ++pChar;
        ++nCount;
    }

    return nWidth;
}
