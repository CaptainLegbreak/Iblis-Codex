typedef char* va_list;
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))
#define va_arg(ap, t) (*(t*)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short wValue = 0) : wChar(wValue) {}

    static Unicode* __fastcall strchr(const Unicode* str, Unicode ch);                                      // 0x005266C0
    static Unicode* __fastcall strncpy(Unicode* dest, const Unicode* src, int count);                       // 0x00526790
};

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
void __fastcall sub_0048BE00_CutBracketToken(Unicode* pString, const Unicode* pToken);                      // 0x0048BE00
void __fastcall sub_004834E0_ReplaceToken(Unicode* pString, int nIndex, const Unicode* pInsert);            // 0x004834E0

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048BE80
void __cdecl sub_0048BE80_FormatArgs(Unicode* pDest, const Unicode* pFormat, ...)
{
    if (pFormat)
    {
        int nCount;
        Unicode aArgs[10][200];
        nCount = 0;
        va_list args;
        va_start(args, pFormat);
        const Unicode* pArg = va_arg(args, const Unicode*);
        while (pArg)
        {
            sub_005267E0(aArgs[nCount], pArg);
            ++nCount;
            pArg = va_arg(args, const Unicode*);
        }

        const Unicode* pSource;
        Unicode* pColon = Unicode::strchr(pFormat, Unicode(':'));
        if (pColon)
        {
            Unicode wszMs[5] = { '[', 'm', 's', ']', 0 };
            int nA = -1;
            const Unicode* pMark = Unicode::strchr(pFormat, Unicode('a'));
            if (pMark && pMark < pColon)
            {
                nA = pMark[1].wChar - '0';
            }
            int nN = -1;
            pMark = Unicode::strchr(pFormat, Unicode('n'));
            if (pMark && pMark < pColon)
            {
                nN = pMark[1].wChar - '0';
            }

            if (nA != -1)
            {
                if (nN != -1)
                {
                    Unicode wszTemp[5];
                    if (aArgs[nN][0].wChar == '[')
                    {
                        Unicode::strncpy(wszTemp, aArgs[nN], 4);
                        sub_005267E0(aArgs[nN], &aArgs[nN][4]);
                    }
                    else
                    {
                        sub_005267E0(wszTemp, wszMs);
                    }
                    if (aArgs[nA][0].wChar == '[')
                    {
                        sub_0048BE00_CutBracketToken(aArgs[nA], wszTemp);
                    }
                }
                else
                {
                    sub_0048BE00_CutBracketToken(aArgs[nA], wszMs);
                }
            }
            else if (nN != -1)
            {
                sub_005267E0(aArgs[nN], &aArgs[nN][4]);
            }
            pSource = pColon + 1;
        }
        else
        {
            pSource = pFormat;
        }
        sub_005267E0(pDest, pSource);

        for (int i = 0; i < nCount; ++i)
        {
            sub_004834E0_ReplaceToken(pDest, i, aArgs[i]);
        }
    }
}
