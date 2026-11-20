#include "D2Client.h"

#define gbUpPressed_007C028C (gaPressed_007C0288[1])
#define gbDownPressed_007C0290 (gaPressed_007C0288[2])
#define KEYCFG_X ((gnScreenWidth_0071146C - 620) / 2)
#define KEYCFG_Y ((gnScreenHeight_007A521C - 420) / 2)

struct D2SliderButtonStrc;
struct Unicode;
struct D2RectStrc;
struct D2KeyConfigButtonStrc;

#pragma pack(push, 1)
struct D2SliderButtonStrc
{
    unsigned short wStringId;
    unsigned char unk_02[8];
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

#pragma pack(pop)

int __fastcall sub_00501820_GetTextWidth(const wchar_t* wszText); // 0x00501820
const wchar_t* __fastcall sub_00524A30_GetString(unsigned short wStringId); // 0x00524A30
extern D2SliderButtonStrc gaSliderButtons_007246D8[3]; // 0x007246D8
extern int gnScreenHeight_007A521C; // 0x007A521C
extern int gnSliderRows_007C0274; // 0x007C0274
extern int gnSliderOffset_007C0278; // 0x007C0278
extern int gnSliderScale_007C02AC; // 0x007C02AC
extern int gnSliderPos_007C02CC; // 0x007C02CC

struct Unicode
{
    unsigned short wChar;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

#pragma pack(push, 2)
struct D2ClientListEntryStrc
{
    int nKey;
    unsigned short nString;
    unsigned char unk0x06[4];
};

struct D2KeyConfigButtonStrc
{
    unsigned short nString;
    unsigned char unk0x02[4];
    int nColor;
    int nX;
    unsigned char unk0x0E[0x0C];
};

#pragma pack(pop)

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
void __fastcall sub_00452E50_DrawRectangleBorder(D2RectStrc* pRect); // 0x00452E50
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __fastcall sub_00469D90(int nA, int nB); // 0x00469D90
const Unicode* __fastcall sub_00469DE0_GetKeyText(int nKey, int nArg2); // 0x00469DE0
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
void __cdecl sub_004A43E0(); // 0x004A43E0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
extern D2KeyConfigButtonStrc gaButtons_007246D8[3]; // 0x007246D8
extern int gaPressed_007C0288[7]; // 0x007C0288
extern int gnGlobal_007C02B0; // 0x007C02B0
extern int gnGlobal_007C02B8; // 0x007C02B8
extern void* gpCelFile_007C02BC; // 0x007C02BC
extern unsigned int gdwMessageTick_007C02C8; // 0x007C02C8

static __forceinline int sub_F08_ListTop()
{
    return (gnScreenHeight_007A521C - 0x1A4) / 2;
}

static __forceinline int sub_F08_PanelLeft()
{
    return (gnScreenWidth_0071146C - 0x26C) / 2;
}

static __forceinline int sub_F08_PanelRight()
{
    return sub_F08_PanelLeft() + (gnScreenWidth_0071146C - sub_F08_PanelLeft() * 2);
}

static __forceinline int sub_F08_TrackTop()
{
    return sub_F08_ListTop() + 0x2F;
}

static __forceinline int sub_F08_ThumbHeight()
{
    return gnSliderOffset_007C0278 * 12;
}

static __forceinline int sub_KEYCFG_Rows()
{
    return ((sub_F08_ListTop() + 0x16C) - (sub_F08_ListTop() + 0x28)) / 0x12;
}

static __forceinline int sub_F08_VisibleLines()
{
    return sub_KEYCFG_Rows() - 3;
}

static __forceinline int sub_F08_TrackSpan()
{
    return sub_KEYCFG_Rows() * 0x12 - sub_F08_ThumbHeight() - 0x4E;
}

static __forceinline int sub_004A44C0_GetMaxFirstEntry()
{
    int nCount = gnSliderRows_007C0274;
    for (int i = 0; i < sub_F08_VisibleLines(); ++i)
    {
        if (--nCount <= 0)
            return 0;
    }
    return nCount;
}

// 0x004A5060
void __cdecl sub_004A5060_LayoutSlider()
{
    const int nOldFont = sub_00502EF0_SetFont(13);
    for (unsigned int i = 0; i < 3; ++i)
    {
        const int nWidth = sub_00501820_GetTextWidth(sub_00524A30_GetString(gaSliderButtons_007246D8[i].wStringId));
        const int nThird = (sub_F08_PanelRight() - sub_F08_PanelLeft()) / (sizeof(gaSliderButtons_007246D8) / sizeof(gaSliderButtons_007246D8[0]));
        gaSliderButtons_007246D8[i].nLeft = nThird * i + sub_F08_PanelLeft() + nThird / 2 - nWidth / 2 - 10;
        gaSliderButtons_007246D8[i].nRight = nThird * i + sub_F08_PanelLeft() + nThird / 2 + nWidth / 2 + 10;
        gaSliderButtons_007246D8[i].nTop = sub_F08_ListTop() + 0x149;
        gaSliderButtons_007246D8[i].nBottom = sub_F08_ListTop() + 0x16F;
    }
    sub_00502EF0_SetFont(nOldFont);

    gnSliderPos_007C02CC = sub_F08_TrackSpan() * gnSliderScale_007C02AC / sub_004A44C0_GetMaxFirstEntry() + sub_F08_TrackTop();
}

#include "gen/data/Source/D2Client/Unknown_004A5060.inc"

int gnScreenHeight_007A521C; // 0x007A521C

int gbRedraw_007C0280; // 0x007C0280

int gnHoverButton_007C02B4; // 0x007C02B4

int gnMessage_007C02C4; // 0x007C02C4

unsigned int gnBlink_007C02D0; // 0x007C02D0

int gnLastMouseY_007C02D4; // 0x007C02D4

int gnLastMouseX_007C02D8; // 0x007C02D8

// 0x004A4FA0
static int sub_004A4FA0_GetEntryState(int nIndex, int nFlag)
{
    if (nIndex == gnGlobal_007C02B0 && (gnGlobal_007C02B8 || nFlag == gnGlobal_007246D4))
    {
        return 3;
    }

    if (!sub_00469D90(gpListEntries_00724264[nIndex].nKey, 1) && !sub_00469D90(gpListEntries_00724264[nIndex].nKey, 0))
    {
        return 1;
    }

    return sub_00469D90(gpListEntries_00724264[nIndex].nKey, nFlag) ? 4 : 5;
}

static __forceinline int sub_KEYCFG_VisibleLines()
{
    return ((KEYCFG_Y + 0x136) - (KEYCFG_Y + 0x28)) / 0x12;
}

static __forceinline int sub_KEYCFG_ListTop()
{
    return (gnScreenHeight_007A521C - 0x1A4) / 2;
}

static __forceinline int sub_KEYCFG_PanelRight()
{
    return KEYCFG_X + (gnScreenWidth_0071146C - KEYCFG_X * 2);
}

static __forceinline int sub_KEYCFG_IsOnUpArrow(int nX, int nY)
{
    if (nX >= sub_KEYCFG_PanelRight() - 0x1F && nX <= sub_KEYCFG_PanelRight() - 0x12)
    {
        const int nTop = sub_KEYCFG_ListTop();
        if (nY >= nTop + 0x23 && nY <= nTop + 0x2F)
            return 1;
    }
    return 0;
}

static __forceinline int sub_KEYCFG_IsOnDownArrow(int nX, int nY)
{
    if (nX >= sub_KEYCFG_PanelRight() - 0x1F && nX <= sub_KEYCFG_PanelRight() - 0x12)
    {
        const int nTop = sub_KEYCFG_ListTop();
        if (nY >= nTop + 0x125 && nY <= nTop + 0x131)
            return 1;
    }
    return 0;
}

static __forceinline int sub_KEYCFG_TrackCels()
{
    return ((KEYCFG_Y + 0x131) - (KEYCFG_Y + 0x2F)) / 0x0C;
}

// 0x004A5270
void __cdecl sub_004A5270()
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    sub_004A43E0();
    if (gnLastMouseX_007C02D8 != nMouseX || gnLastMouseY_007C02D4 != nMouseY || gbRedraw_007C0280)
    {
        gnLastMouseX_007C02D8 = nMouseX;
        gnLastMouseY_007C02D4 = nMouseY;
        sub_004A4AD0_Press(nMouseX, nMouseY);
    }

    const int nOldFont = sub_00502EF0_SetFont(13);
    sub_0046EFD0_DrawFramedBox(KEYCFG_X, KEYCFG_Y, gnScreenWidth_0071146C - 2 * KEYCFG_X, (KEYCFG_Y + 0x171) - KEYCFG_Y, 0, 1);

    D2RectStrc tRect;
    tRect.nLeft = KEYCFG_X;
    tRect.nTop = KEYCFG_Y + 3;
    tRect.nRight = gnScreenWidth_0071146C - KEYCFG_X - 3;
    tRect.nBottom = KEYCFG_Y + 0x170;
    sub_00452E50_DrawRectangleBorder(&tRect);
    tRect.nTop = KEYCFG_Y + 0x143;
    sub_00452E50_DrawRectangleBorder(&tRect);

    sub_00502320(D2LANG_GetStringFromTblIndex(0xF51), KEYCFG_X + 0x12, KEYCFG_Y + 0x1E, 4, 0);
    sub_00502320(D2LANG_GetStringFromTblIndex(0xF52), KEYCFG_X + 0x12 + (gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3, KEYCFG_Y + 0x1E, 4, 0);
    sub_00502320(D2LANG_GetStringFromTblIndex(0xF53), KEYCFG_X + 0x12 + 2 * ((gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3), KEYCFG_Y + 0x1E, 4, 0);

    int i = 0;
    while (i < sub_KEYCFG_VisibleLines() && i < gnSliderRows_007C0274)
    {
        int nY = i * 0x12 + KEYCFG_Y + 0x22;
        int nIndex = gnSliderScale_007C02AC + i;
        int bVisible;
        if (gnGlobal_007C02B8 && nIndex == gnGlobal_007C02B0 && (gnBlink_007C02D0 & 0xF) <= 4)
            bVisible = 0;
        else
            bVisible = 1;

        ++i;

        if (gpListEntries_00724264[nIndex].nKey == 0x39)
            continue;

        if (nIndex == gnGlobal_007C02B0)
        {
            sub_0046EFD0_DrawFramedBox(KEYCFG_X + 0x12, nY + 1, 3 * ((gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3), 0x12, 0, 1);
            sub_00502320(D2LANG_GetStringFromTblIndex(gpListEntries_00724264[nIndex].nString), KEYCFG_X + 0x1E, nY + 0x12, gnGlobal_007C02B8 ? 3 : 0, 0);
        }
        else
        {
            sub_00502320(D2LANG_GetStringFromTblIndex(gpListEntries_00724264[nIndex].nString), KEYCFG_X + 0x1E, nY + 0x12, 0, 0);
        }

        if (bVisible || !gnGlobal_007246D4)
        {
            sub_00502320(sub_00469DE0_GetKeyText(gpListEntries_00724264[nIndex].nKey, 1), KEYCFG_X + 0x1E + (gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3, nY + 0x12, sub_004A4FA0_GetEntryState(nIndex, 1), 0);
        }

        if (bVisible || gnGlobal_007246D4)
        {
            sub_00502320(sub_00469DE0_GetKeyText(gpListEntries_00724264[nIndex].nKey, 0), KEYCFG_X + 0x1E + 2 * ((gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3), nY + 0x12, sub_004A4FA0_GetEntryState(nIndex, 0), 0);
        }
    }

    D2CelContextStrc tCel;
    memset(&tCel, 0, sizeof(tCel));
    tCel.pCellFile = gpCelFile_007C02BC;
    tCel.nFrame = 13;
    for (int j = 0; j < sub_KEYCFG_TrackCels(); ++j)
        sub_004F6480(&tCel, sub_KEYCFG_PanelRight() - 0x1F, KEYCFG_Y + 0x3B + j * 0x0C, -1, 5, 0);

    tCel.nFrame = 14;
    for (int k = 0; k < gnSliderOffset_007C0278; ++k)
        sub_004F6480(&tCel, sub_KEYCFG_PanelRight() - 0x20, gnSliderPos_007C02CC + 0x0C + k * 0x0C, -1, 5, 0);

    if (gbUpPressed_007C028C && sub_KEYCFG_IsOnUpArrow(nMouseX, nMouseY))
        tCel.nFrame = 9;
    else
        tCel.nFrame = 11;
    sub_004F6480(&tCel, sub_KEYCFG_PanelRight() - 0x1F, KEYCFG_Y + 0x2F, -1, 5, 0);

    if (gbDownPressed_007C0290 && sub_KEYCFG_IsOnDownArrow(nMouseX, nMouseY))
        tCel.nFrame = 8;
    else
        tCel.nFrame = 10;
    sub_004F6480(&tCel, sub_KEYCFG_PanelRight() - 0x1F, KEYCFG_Y + ((KEYCFG_Y + 0x171) - KEYCFG_Y) - 0x40, -1, 5, 0);

    for (unsigned int m = 0; m < 3; ++m)
    {
        int nColor;
        if (m == gnHoverButton_007C02B4)
            nColor = gaButtons_007246D8[m].nColor;
        else
            nColor = 4;
        sub_00502320(D2LANG_GetStringFromTblIndex(gaButtons_007246D8[m].nString), gaButtons_007246D8[m].nX + 10, KEYCFG_Y + ((KEYCFG_Y + 0x171) - KEYCFG_Y) - 0x12, nColor, 0);
    }

    if (GetTickCount() < gdwMessageTick_007C02C8 + 2000)
    {
        const int nCenterX = gnScreenWidth_0071146C / 2;
        const int nTextY = KEYCFG_Y + ((KEYCFG_Y + 0x171) - KEYCFG_Y) + 0x1E;
        const int nTextX = nCenterX - sub_00501820(D2LANG_GetStringFromTblIndex(gnMessage_007C02C4)) / 2;
        sub_00502320(D2LANG_GetStringFromTblIndex(gnMessage_007C02C4), nTextX, nTextY, 1, 1);
    }

    sub_00502EF0_SetFont(nOldFont);
    ++gnBlink_007C02D0;
}
