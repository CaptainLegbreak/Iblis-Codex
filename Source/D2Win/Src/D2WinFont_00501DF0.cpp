struct D2CelFileStrc;
struct D2CelStrc;

struct Unicode
{
    unsigned short wChar;

    static int __fastcall strncmp(const Unicode* str1, const Unicode* str2, unsigned int count); // 0x00526540
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

int __cdecl sub_004F5140(); // 0x004F5140
extern "C" int __fastcall sub_00526800(const unsigned short* pText); // 0x00526800
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, unsigned int nGamma, int nDrawMode, unsigned char* pPalette); // 0x004F6480
void __stdcall TEXTURE_CelDrawEx(D2CelContextStrc* pContext, int nX, int nY, int nSkipLines, int nDrawLines, int nDrawMode); // 0x004F64E0
D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840
int __stdcall sub_006018F0(D2CelStrc* pCel); // 0x006018F0

extern int gnCurrentFont_0072DFFC; // 0x0072DFFC
extern D2FontCacheStrc* gpFontCache_00841D88; // 0x00841D88
extern D2CharStrc* (__fastcall* gpfGetCharInfo_00841DA0)(unsigned short wChar); // 0x00841DA0
extern D2CelFileStrc* ghMonsterIndicators_00841DA4; // 0x00841DA4
extern D2FontCacheStrc gFontCache_00841DA8[]; // 0x00841DA8
extern wchar_t gwszMonsterCode_008426DC[2]; // 0x008426DC
extern wchar_t gwszColorCode_008426E0[2]; // 0x008426E0

inline int sub_00501DF0_IsColorCodePrefix(unsigned short wChar)
{
    if (wChar >= 0x100)
        return 0;
    return wChar == 0xFF;
}

// 0x00501DF0
void __fastcall sub_00501DF0_DrawClippedFontText(const Unicode* pText, int nX, int nY, int nTextColor, int nSkipLines, int nDrawLines)
{
    if (nSkipLines < 0)
        return;

    const int nDisplayType = sub_004F5140();
    const int nLength = sub_00526800((const unsigned short*)pText);
    int nCount = 0;
    const int nStartX = nX;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;

    if (nLength > 0)
    {
        const Unicode* pScan = pText - 1;
        do
        {
            const Unicode c = pText[nCount++];
            Unicode c2;
            const unsigned short wScan = (++pScan)->wChar;
            if (sub_00501DF0_IsColorCodePrefix(wScan))
            {
                c2 = pText[nCount];
                ++nCount;
                ++pScan;
                if (!Unicode::strncmp(&c2, (const Unicode*)gwszColorCode_008426E0, 1))
                {
                    ++nCount;
                    ++pScan;
                    continue;
                }
                if (!Unicode::strncmp(&c2, (const Unicode*)gwszMonsterCode_008426DC, 1))
                {
                    const Unicode* pMarker = pScan;
                    ++nCount;
                    ++pScan;
                    const unsigned short wMarker = pMarker->wChar;
                    D2CharStrc* pChar = gpfGetCharInfo_00841DA0(wMarker);
                    tContext.pCellFile = ghMonsterIndicators_00841DA4;
                    tContext.nFrame = pChar->nImageIndex;
                    TEXTURE_CelDraw(&tContext, nX, nY, -1, 5, 0);
                    nY += 16 * gFontCache_00841DA8[gnCurrentFont_0072DFFC].pFontInfo[1]->nHeight / 10;
                }
            }
            else if (c.wChar != '\n')
            {
                D2CharStrc* pChar = gpfGetCharInfo_00841DA0(c.wChar);
                if (nDisplayType != 6)
                {
                    tContext.pCellFile = gpFontCache_00841D88->pCellFile;
                    tContext.nFrame = pChar->nImageIndex;
                    const int nHeight = sub_006018F0(CelGetHandle(&tContext));
                    if (nSkipLines + nDrawLines <= nHeight)
                        TEXTURE_CelDrawEx(&tContext, nX, nY, nSkipLines, nDrawLines, 5);
                    else
                        TEXTURE_CelDrawEx(&tContext, nX, nY, 0, nHeight, 5);
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
}
