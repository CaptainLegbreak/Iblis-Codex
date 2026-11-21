struct Unicode
{
    unsigned short w;
    operator unsigned short() const { return w; }
};

struct D2CharInfo
{
    unsigned char unk_00[3];
    unsigned char nWidth;
    char unk_04[4];
    unsigned short nImageIndex;
};

struct D2FontHeader
{
    char unk_00[0x0A];
    unsigned char nHeight;
};

struct D2FontSlot
{
    D2FontHeader* pFontInfo[5];
};

struct D2FontCache
{
    void* pCellFile;
};

struct D2GfxData
{
    int nFrame;
    char unk_04[0x30];
    void* pCellFile;
    char unk_38[8];
    int nDirection;
    char unk_44[4];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern const char gszAssertExpr_006CC837[]; // 0x006CC837

int __fastcall sub_00526800(const Unicode* wszText); // 0x00526800
int __fastcall sub_00526610(const Unicode* a, const Unicode* b, int n); // 0x00526610
int __fastcall sub_00526540(const Unicode* a, const Unicode* b, int n); // 0x00526540
void __stdcall TEXTURE_CelDrawColor(D2GfxData* pGfxData, int nX, int nY, unsigned int nGamma, int eDrawMode, int nColor); // 0x004F64B0

extern D2CharInfo* (__fastcall* gpfnFindCharInfo_00841DA0)(Unicode wChar); // 0x00841DA0
extern Unicode gwszMonsterIndicator_008426DC[]; // 0x008426DC
extern Unicode gwszColorCode_008426E0[]; // 0x008426E0
extern D2FontCache* gpFontCache_00841D88; // 0x00841D88
extern int gnFontSize_0072DFFC; // 0x0072DFFC
extern D2FontSlot gaFonts_00841DB0[]; // 0x00841DB0

static int FONT_GetMaxLineWidth(const Unicode* pStr); // 0x00501840

// build: context FONT_GetMaxLineWidth
static int FONT_GetMaxLineWidth(const Unicode* pStr)
{
    if (!pStr)
    {
        sub_00408A60(gszAssertExpr_006CC837, sub_00408090(), 525);
        exit(-1);
    }

    int nMax = 0;
    int nCur = 0;
    const int nLength = sub_00526800(pStr);
    if (nLength <= 0)
        return 0;

    for (int i = 0; *pStr && i < nLength; ++i)
    {
        if (*pStr == '\n')
        {
            if (nCur > nMax)
                nMax = nCur;
            nCur = 0;
            ++pStr;
        }
        else if (*pStr < 0x100u && *pStr == 0xFF)
        {
            if (!sub_00526610(pStr + 1, gwszMonsterIndicator_008426DC, 1))
                nCur += gpfnFindCharInfo_00841DA0(gwszMonsterIndicator_008426DC[0])->nWidth;
            pStr += 3;
            i += 2;
        }
        else
        {
            nCur += gpfnFindCharInfo_00841DA0(*pStr)->nWidth;
            ++pStr;
        }
    }

    if (nMax > nCur)
        nCur = nMax;
    return nCur;
}

static int FONT_GetFirstLineWidth(const Unicode* pStr); // 0x00501910

// build: context FONT_GetFirstLineWidth
static int FONT_GetFirstLineWidth(const Unicode* pStr)
{
    if (!pStr)
    {
        sub_00408A60(gszAssertExpr_006CC837, sub_00408090(), 560);
        exit(-1);
    }

    const int nLength = sub_00526800(pStr);
    int nWidth = 0;
    for (int i = 0; i < nLength; ++i)
    {
        if (*pStr == '\n')
            break;

        if (*pStr >= 0x100u || *pStr != 0xFF)
        {
            nWidth += gpfnFindCharInfo_00841DA0(*pStr)->nWidth;
            ++pStr;
        }
        else
        {
            if (!sub_00526610(pStr + 1, gwszMonsterIndicator_008426DC, 1))
                nWidth += gpfnFindCharInfo_00841DA0(gwszMonsterIndicator_008426DC[0])->nWidth;
            i += 2;
            pStr += 3;
        }
    }
    return nWidth;
}

static void __fastcall sub_00501C30(const Unicode* wszText, int nX, int nY, int nWidth, int nColor, int bCentered, int eDrawMode); // 0x00501C30

static inline int FONT_IsCodeChar(Unicode wChar)
{
    return wChar == 0xFF;
}

// build: context sub_00501C30
static void __fastcall sub_00501C30(const Unicode* wszText, int nX, int nY, int nWidth, int nColor, int bCentered, int eDrawMode)
{
    const int nLength = sub_00526800(wszText);
    int i = 0;
    const int nStartX = nX;
    if (bCentered)
        nX += (nWidth - FONT_GetFirstLineWidth(wszText)) >> 1;

    D2GfxData tGfxData;
    memset(&tGfxData, 0, sizeof(tGfxData));
    tGfxData.pCellFile = gpFontCache_00841D88->pCellFile;
    tGfxData.nDirection = 0;

    while (i < nLength)
    {
        const Unicode wChar = *wszText;
        ++i;
        ++wszText;

        if (wChar < 0x100u && FONT_IsCodeChar(wChar))
        {
            const Unicode wCode = *wszText;
            ++i;
            ++wszText;
            if (!sub_00526540(&wCode, gwszColorCode_008426E0, 1))
            {
                if (i < nLength)
                {
                    ++i;
                    nColor = *wszText++ - '0';
                    if (nColor >= 13)
                        nColor = 0;
                }
                else
                {
                    nColor = 0;
                }
            }
            else
            {
                --i;
                --wszText;
                D2CharInfo* pChar = gpfnFindCharInfo_00841DA0(wChar);
                tGfxData.nFrame = pChar->nImageIndex;
                TEXTURE_CelDrawColor(&tGfxData, nX, nY, (unsigned int)-1, eDrawMode, nColor);
                nX += pChar->nWidth;
            }
        }
        else if (wChar != '\n')
        {
            D2CharInfo* pChar = gpfnFindCharInfo_00841DA0(wChar);
            tGfxData.nFrame = pChar->nImageIndex;
            TEXTURE_CelDrawColor(&tGfxData, nX, nY, (unsigned int)-1, eDrawMode, nColor);
            nX += pChar->nWidth;
        }
        else
        {
            nX = nStartX;
            if (bCentered)
                nX += (nWidth - FONT_GetFirstLineWidth(wszText)) >> 1;
            nY += -16 * gaFonts_00841DB0[gnFontSize_0072DFFC].pFontInfo[0]->nHeight / 10;
        }
    }
}

// 0x00502360
void __fastcall D2Win_10118_DrawBlendedText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered, int eDrawMode)
{
    int nWidth = 0;
    if (bCentered)
        nWidth = FONT_GetMaxLineWidth(wszText) + 8;
    sub_00501C30(wszText, nX, nY, nWidth, nColor, bCentered, eDrawMode);
}
