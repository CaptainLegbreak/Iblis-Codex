struct D2CelFileStrc;

struct Unicode
{
    unsigned short wChar;

    int IsColorCodePrefix() const
    {
        if (wChar >= 0x100)
            return 0;

        return wChar == 0xFF;
    }

    int ToDigit() const
    {
        return wChar - '0';
    }

    static int __fastcall strncmp(const Unicode* str1, const Unicode* str2, unsigned int count);            // 0x00526540
};

struct D2CharStrc
{
    unsigned short wChar;
    unsigned char unk0x02;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned char unk0x05;
    unsigned short unk0x06;
    unsigned short nImageIndex;
    unsigned short unk0x0A[2];
};

struct D2FontStrc
{
    unsigned int dwHeader;
    unsigned short unk0x04;
    unsigned short unk0x06;
    unsigned short nCharCount;
    unsigned char nHeight;
    unsigned char unk0x0B;
};

struct D2FontCacheStrc
{
    D2CelFileStrc* pCellFile;
    D2FontStrc* pFontInfo[2];
    D2CharStrc* pCharInfo;
    unsigned int dwShiftedTickCount;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CelFileStrc* pCellFile;
    int unk0x38[2];
    int nDirection;
    int unk0x44;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __stdcall TEXTURE_CelDrawColor(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift); // 0x004F64B0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern int gnCurrentFont_0072DFFC;                                                                          // 0x0072DFFC
extern D2FontCacheStrc* gpFontCache_00841D88;                                                               // 0x00841D88
typedef D2CharStrc* (__fastcall* D2GetCharInfoFn)(unsigned short wChar);
extern D2GetCharInfoFn gpfGetCharInfo_00841DA0;                                                             // 0x00841DA0
extern D2FontCacheStrc gFontCache_00841DA8[];                                                               // 0x00841DA8
extern wchar_t gwszColorCode_008426E0[2];                                                                   // 0x008426E0

// 0x00501FE0
void __fastcall sub_00501FE0_DrawTickerText(const Unicode* wszText, int nX, int nY, int nColor, int nScroll, int nWidth)
{
    const int nLength = sub_00526800(wszText);
    int nCount = 0;
    const int nStartX = nX;
    nX += nScroll;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpFontCache_00841D88->pCellFile;
    tContext.nDirection = 0;

    if (nLength <= 0)
    {
        return;
    }

    const int nRight = nStartX + nWidth;
    int nShift = nColor;
    const Unicode* pText = wszText;
    do
    {
        if (nX > nRight)
        {
            break;
        }

        Unicode c2;
        const Unicode c = *pText;
        ++nCount;
        ++pText;
        const int bColorPrefix = pText[-1].IsColorCodePrefix();
        if (bColorPrefix)
        {
            c2 = *pText;
            ++nCount;
            ++pText;
            if (!Unicode::strncmp(&c2, (const Unicode*)gwszColorCode_008426E0, 1))
            {
                if (nCount >= nLength)
                {
                    nShift = 0;
                }
                else
                {
                    ++nCount;
                    nShift = (pText++)->ToDigit();
                    if (nShift >= 13)
                    {
                        nShift = 0;
                    }
                }
            }
            else
            {
                --nCount;
                --pText;
                D2CharStrc* pChar = gpfGetCharInfo_00841DA0(c.wChar);
                tContext.nFrame = pChar->nImageIndex;
                if (nX > nStartX)
                {
                    TEXTURE_CelDrawColor(&tContext, nX, nY, -1, 5, nShift);
                }
                nX += pChar->nWidth;
            }
        }
        else if (c.wChar != '\n')
        {
            D2CharStrc* pChar = gpfGetCharInfo_00841DA0(c.wChar);
            tContext.nFrame = pChar->nImageIndex;
            if (nX > nStartX)
            {
                TEXTURE_CelDrawColor(&tContext, nX, nY, -1, 5, nShift);
            }
            nX += pChar->nWidth;
        }
        else
        {
            nX = nStartX;
            nY += -16 * gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight / 10;
        }
    }
    while (nCount < nLength);
}
