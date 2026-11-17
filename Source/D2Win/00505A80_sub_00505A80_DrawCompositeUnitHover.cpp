struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2HoverLineStrc
{
    Unicode wszText[256];
    int nWidth;
    int nHeight;

    D2HoverLineStrc() {} // 0x00504020
};

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct D2CompositeUnitStrc
{
    unsigned int dwFlags;
    unsigned char unk0x04[0x10];
    int nX;
    int nY;
    int nUnitIndex;
    unsigned char unk0x20[0xAC];
    Unicode wszAccountName[64];
    Unicode wszCharName[64];
    Unicode wszGuildTag[16];
    Unicode wszRealmName[32];
    int nCharLevel;
    unsigned int dwProductCode;
};

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern unsigned int gdwBitMasks[]; // 0x006CE268

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, int eDrawMode); // 0x004F6300
int __stdcall CONTROL_MouseInsideRect(const tagRECT* pRect); // 0x004F97B0
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

__declspec(noinline) void __stdcall sub_00503FA0_AddHoverLine(const Unicode* wszText, D2HoverLineStrc* pLines, int* pCount, int* pMaxWidth, int* pTotalHeight);

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00503FA0
void __stdcall sub_00503FA0_AddHoverLine(const Unicode* wszText, D2HoverLineStrc* pLines, int* pCount, int* pMaxWidth, int* pTotalHeight)
{
    D2HoverLineStrc* pLine = &pLines[*pCount];
    D2_ASSERT(*pCount < 7, 0x738);

    sub_005267E0(pLine->wszText, wszText);
    D2Win_10131_GetTextDimensions(pLine->wszText, &pLine->nWidth, &pLine->nHeight);
    *pMaxWidth = *pMaxWidth > pLine->nWidth + 6 ? *pMaxWidth : pLine->nWidth + 6;
    *pTotalHeight += pLine->nHeight;
    ++*pCount;
}

// 0x00505A80
int __fastcall sub_00505A80_DrawCompositeUnitHover(D2CompositeUnitStrc* pCompositeUnit)
{
    D2_ASSERT(pCompositeUnit, 1864);

    Unicode wszText[256];
    if (!(pCompositeUnit->dwFlags & gdwBitMasks[3]))
    {
        return 0;
    }

    tagRECT rect;
    SetRect(&rect, pCompositeUnit->nX - 30, pCompositeUnit->nY - 80, pCompositeUnit->nX + 30, pCompositeUnit->nY + 20);
    if (!CONTROL_MouseInsideRect(&rect))
    {
        return 0;
    }

    int nX = pCompositeUnit->nX;
    int nYEnd = pCompositeUnit->nY - 80;
    int nWidth = 0;
    int nHeight = 0;
    D2HoverLineStrc lines[7];
    int nCount = 0;
    int nColor = 0;
    sub_00502EF0(1);

    if (pCompositeUnit->dwProductCode == 'D2XP')
    {
        sub_00526320_ToUnicode(wszText, "Expansion", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }

    const int nType = pCompositeUnit->nUnitIndex;
    if (nType == 19)
    {
        sub_00526320_ToUnicode(wszText, "Moderator", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
ShowLevel:
        {
            const int nLevel = pCompositeUnit->nCharLevel;
            if (nLevel > 0)
            {
                memset(wszText, 0, sizeof(wszText));
                sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(5017), nLevel);
                sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);

                if (pCompositeUnit->dwFlags & gdwBitMasks[5])
                {
                    sub_00503FA0_AddHoverLine(D2LANG_GetStringFromTblIndex(5016), lines, &nCount, &nWidth, &nHeight);
                }

                sub_00526320_ToUnicode(wszText, "Realm: ", 256);
                sub_00526700(wszText, pCompositeUnit->wszRealmName);
                sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
            }
        }
    }
    else if (nType == 20)
    {
        sub_00526320_ToUnicode(wszText, "Sysop", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
        nColor = 3;
    }
    else if (nType == 18)
    {
        sub_00526320_ToUnicode(wszText, "Blizzard Rep", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
        nColor = 3;
    }
    else if (nType == 23)
    {
        sub_00526320_ToUnicode(wszText, "Speaker", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }
    else if (nType == 21)
    {
        sub_00526320_ToUnicode(wszText, "Referee", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }
    else if (nType == 22)
    {
        sub_00526320_ToUnicode(wszText, "Chat", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }
    else if (nType == 24)
    {
        sub_00526320_ToUnicode(wszText, "Open Character", 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }
    else
    {
        const unsigned int dwProductCode = pCompositeUnit->dwProductCode;
        if (dwProductCode == 'D2DV' || dwProductCode == 'D2XP' || dwProductCode == 'D2ST')
        {
            goto ShowLevel;
        }

        const char* szProduct;
        switch (dwProductCode)
        {
        case 'DRTL':
        case 'DTST':
            szProduct = "Diablo";
            break;
        case 'DSHR':
            szProduct = "Diablo Shareware";
            break;
        case 'SSHR':
            szProduct = "Starcraft Shareware";
            break;
        case 'STAR':
        case 'JSTR':
            szProduct = "Starcraft";
            break;
        case 'SEXP':
            szProduct = "Brood War";
            break;
        case 'W2BN':
            szProduct = "Warcraft II";
            break;
        case 'WAR3':
            szProduct = "Warcraft III";
            break;
        case 'W3XP':
            szProduct = "Frozen Throne";
            break;
        default:
            szProduct = "Unknown";
            break;
        }

        sub_00526320_ToUnicode(wszText, szProduct, 256);
        sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }

    sub_00526320_ToUnicode(wszText, "Account Name: ", 256);
    sub_00526700(wszText, pCompositeUnit->wszAccountName);
    sub_00503FA0_AddHoverLine(wszText, lines, &nCount, &nWidth, &nHeight);

    const int nBoxHeight = nHeight + 6;
    int nLeft = nX - (nWidth >> 1);
    int nOffset = 0;
    if (nLeft < 0)
    {
        nOffset = -nLeft;
        nLeft = 0;
    }
    else if (nLeft + nWidth > 800)
    {
        nOffset = 800 - nLeft - nWidth;
        nLeft = 800 - nWidth;
    }

    const int nTop = nYEnd - nBoxHeight;
    D2GFX_DrawBox(nLeft, nTop, nLeft + nWidth, nYEnd, 0, 2);
    nX += nOffset;

    int nY = nTop + 3;
    D2_ASSERT(nCount <= 7, 2052);
    const int nValidStrings = nCount;
    for (int i = 0; i < nValidStrings; ++i)
    {
        nY += lines[i].nHeight;
        D2HoverLineStrc* pLine = &lines[i];
        int nLineColor = 0;
        if (!i)
        {
            nLineColor = nColor;
        }
        sub_00502320(pLine->wszText, nX - (pLine->nWidth >> 1), nY, nLineColor, 0);
    }

    return 1;
}
