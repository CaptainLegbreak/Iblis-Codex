extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef unsigned int size_t;

struct D2CelFileStrc;

struct Unicode
{
    unsigned short wChar;

    static int __fastcall strnicmp(const Unicode* str1, const Unicode* str2, size_t count);                 // 0x00526610
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
    unsigned short unk0x08;
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
extern int gnFontMetric1_0072E000;                                                                          // 0x0072E000
extern D2FontCacheStrc* gpFontCache_00841D88;                                                               // 0x00841D88
extern D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(int nChar);                                        // 0x00841DA0
extern D2FontCacheStrc gFontCache_00841DA8[14];                                                             // 0x00841DA8
extern wchar_t gwszMonsterCode_008426DC[2];                                                                 // 0x008426DC
extern wchar_t gwszColorCode_008426E0[2];                                                                   // 0x008426E0

// 0x00501910
static __declspec(noinline) int sub_00501910_GetTextLineWidth(const Unicode* pText)
{
    D2_ASSERT(pText, 572);
    int nWidth = 0;
    const int nLength = sub_00526800(pText);
    for (int nCount = 0; nCount < nLength; ++nCount)
    {
        const unsigned short wChar = pText->wChar;
        if (wChar == '\n')
            break;
        const int bColor = (wChar < 0x100) ? (wChar == 0xFF) : 0;
        if (bColor)
        {
            ++pText;
            if (!Unicode::strnicmp(pText, (const Unicode*)gwszMonsterCode_008426DC, 1))
                nWidth += gpfGetCharInfo_00841DA0(*(const int*)gwszMonsterCode_008426DC)->nWidth;
            nCount += 2;
            pText += 2;
            continue;
        }
        nWidth += gpfGetCharInfo_00841DA0(wChar)->nWidth;
        ++pText;
    }
    return nWidth;
}

static __declspec(noinline) void __stdcall FONT_DrawString(const Unicode* wszText, int nX, int nY, int nWidth, int nGlobalPaletteShift, int bCentered);

// 0x00501A80
static void __stdcall FONT_DrawString(const Unicode* wszText, int nX, int nY, int nWidth, int nGlobalPaletteShift, int bCentered)
{
    const int nLength = sub_00526800(wszText);
    int nCount = 0;
    const int nStartX = nX;
    if (bCentered)
    {
        nX += (nWidth - sub_00501910_GetTextLineWidth(wszText)) >> 1;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpFontCache_00841D88->pCellFile;
    tContext.nDirection = 0;

    const Unicode* wszTextCur = wszText;
    while (nCount < nLength)
    {
        const Unicode tChar = *wszTextCur;
        ++wszTextCur;
        ++nCount;
        const unsigned short wChar = wszTextCur[-1].wChar;

        const int bColor = (wChar < 0x100) ? (wChar == 0xFF) : 0;
        if (bColor)
        {
            const Unicode tNext = *wszTextCur;
            ++nCount;
            ++wszTextCur;

            if (!Unicode::strncmp(&tNext, (const Unicode*)gwszColorCode_008426E0, 1))
            {
                if (nCount >= nLength)
                {
                    nGlobalPaletteShift = 0;
                }
                else
                {
                    const Unicode* pDigit = wszTextCur;
                    ++nCount;
                    ++wszTextCur;
                    nGlobalPaletteShift = pDigit->wChar - '0';
                    if (nGlobalPaletteShift >= '\r')
                    {
                        nGlobalPaletteShift = 0;
                    }
                }
            }
            else
            {
                --nCount;
                --wszTextCur;

                D2CharStrc* pCharInfo = gpfGetCharInfo_00841DA0(*(const int*)&tChar);
                tContext.nFrame = pCharInfo->nImageIndex;
                TEXTURE_CelDrawColor(&tContext, nX, nY, (unsigned int)-1, 5, nGlobalPaletteShift);

                nX += pCharInfo->nWidth;
            }
        }
        else if (tChar.wChar != '\n')
        {
            D2CharStrc* pCharInfo = gpfGetCharInfo_00841DA0(*(const int*)&tChar);
            tContext.nFrame = pCharInfo->nImageIndex;
            TEXTURE_CelDrawColor(&tContext, nX, nY, (unsigned int)-1, 5, nGlobalPaletteShift);

            nX += pCharInfo->nWidth;
        }
        else
        {
            if (bCentered)
            {
                nX = ((nWidth - sub_00501910_GetTextLineWidth(wszTextCur)) >> 1) + nStartX;
            }
            else
            {
                nX = nStartX;
            }

            nY += gnFontMetric1_0072E000 * gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight / -10;
        }
    }
}

// build: context sub_00501A80_Shim
// calling-convention shim (not game code)
void __stdcall sub_00501A80_Shim(const Unicode* wszText, int nX, int nY, int nWidth, int nShift, int bCentered)
{
    FONT_DrawString(wszText, nX, nY - 2, nWidth, nShift, bCentered);
}
