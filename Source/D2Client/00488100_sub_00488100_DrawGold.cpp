struct D2UnitStrc;
struct D2CelFileStrc;

struct Unicode
{
    unsigned short wChar;
};

struct D2GfxDataStrc
{
    int nFrame;
    char unk0x04[0x30];
    D2CelFileStrc* pCellFile;
    char unk0x38[0x08];
    int nDirection;
    char unk0x44[0x04];
};

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
int __cdecl sub_0044DCC0(); // 0x0044DCC0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740

extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern D2CelFileStrc* gpGoldButtonCel_007BCC34; // 0x007BCC34
extern int gbGoldButtonDown_007BCE30; // 0x007BCE30
extern int gbGoldButtonDown_007BCE34; // 0x007BCE34
extern "C" const char szFmtD_006D57BC[]; // 0x006D57BC

static int __stdcall sub_00486820_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight); // 0x00486820

// 0x00486820
static __declspec(noinline) int __stdcall sub_00486820_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nLeft && nMouseX <= nLeft + nWidth && nMouseY >= nBottom - nHeight && nMouseY <= nBottom)
        return 1;
    return 0;
}

// 0x00488100
void __fastcall sub_00488100_DrawGold(int nType)
{
    int nOldFont = sub_00502EF0(1);
    D2GfxDataStrc tData = {};
    tData.nDirection = 0;

    int nGold;
    int nTextX;
    int nTextY;
    int nIconX;
    int nIconY;
    int nFrame;
    switch (nType)
    {
    case 0:
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0(), 15, 0);
        nTextX = gnGlobal_007A2858 + 0xA5;
        if (sub_0044DCC0())
        {
            nTextY = gnGlobal_00711470 + gnGlobal_007A285C - 0x1B8;
            nIconY = gnGlobal_00711470 + gnGlobal_007A285C - 0x1B6;
        }
        else
        {
            nTextY = gnGlobal_00711470 + gnGlobal_007A285C - 0xF4;
            nIconY = gnGlobal_00711470 + gnGlobal_007A285C - 0xF2;
        }
        nIconX = gnGlobal_007A2858 + 0x49;
        nFrame = gbGoldButtonDown_007BCE34 != 0;
        if (sub_0044DCC0())
        {
            if (sub_00486820_IsMouseInBox(gnGlobal_007A2858 + 0x49, gnGlobal_00711470 + gnGlobal_007A285C - 0x1B6, 0x14, 0x12))
            {
                sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x101C), gnGlobal_007A2858 + 0x35, gnGlobal_00711470 + gnGlobal_007A285C - 0x1CA, 0, 0);
            }
        }
        else
        {
            if (sub_00486820_IsMouseInBox(gnGlobal_007A2858 + 0x49, gnGlobal_00711470 + gnGlobal_007A285C - 0xF2, 0x14, 0x12))
            {
                sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x101C), gnGlobal_007A2858 + 0x35, gnGlobal_00711470 + gnGlobal_007A285C - 0x106, 0, 0);
            }
        }
        break;

    case 1:
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0(), 14, 0);
        nTextX = gnGlobal_0071146C - gnGlobal_007A2858 - 0xD4;
        nTextY = gnGlobal_00711470 + gnGlobal_007A285C - 0x48;
        nIconY = gnGlobal_00711470 + gnGlobal_007A285C - 0x45;
        nIconX = gnGlobal_0071146C - gnGlobal_007A2858 - 0xED;
        nFrame = gbGoldButtonDown_007BCE30 != 0;
        break;

    default:
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0(), 15, 0);
        nTextX = sub_00501820(D2LANG_GetStringFromTblIndex(0xCF3)) + gnGlobal_007A2858 + 0x15;
        nTextY = gnGlobal_00711470 + gnGlobal_007A285C - 0x6A;
        nIconX = 0;
        nIconY = 0;
        nFrame = 0;
        break;
    }

    if (nType != 3)
    {
        Unicode wszGold[20] = {};
        char szGold[20];
        SStrPrintf(szGold, 20, szFmtD_006D57BC, nGold);
        sub_00526F20(wszGold, szGold, 19);
        if (nType == 2)
        {
            nTextX = gnGlobal_007A2858 - sub_00501820(wszGold) + 0xC6;
        }
        sub_00502320(wszGold, nTextX, nTextY, 0, 0);
    }

    switch (nType)
    {
    case 0:
        if (gbGoldButtonDown_007BCE34)
        {
            ++nIconY;
        }
        nIconX += 2;
        nIconY -= 2;
        tData.pCellFile = gpGoldButtonCel_007BCC34;
        tData.nFrame = nFrame;
        TEXTURE_CelDraw(&tData, nIconX, nIconY, -1, 5, 0);
        break;

    case 1:
        if (gbGoldButtonDown_007BCE30)
        {
            ++nIconY;
        }
        nIconX += 1;
        nIconY -= 2;
        tData.pCellFile = gpGoldButtonCel_007BCC34;
        tData.nFrame = nFrame;
        TEXTURE_CelDraw(&tData, nIconX, nIconY, -1, 5, 0);
        break;

    default:
        sub_00502320(D2LANG_GetStringFromTblIndex(0xCF3), gnGlobal_007A2858 + 0x15, nTextY, 0, 0);
        break;
    }

    sub_00502EF0(nOldFont);
}
