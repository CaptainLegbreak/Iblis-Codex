struct Unicode
{
    unsigned short wChar;
};

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

#define UNIT_MONSTER 1

Unicode gwszText_007A2D30[256];                                                                             // 0x007A2D30
int gnHoverTextColor_007A2F30;                                                                              // 0x007A2F30
extern Unicode gwszText_007A2A78[];                                                                         // 0x007A2A78
extern int gnHoverTextState_007A2C78;                                                                       // 0x007A2C78
Unicode gwszHoverName_007A2F38[256];                                                                        // 0x007A2F38
int __fastcall sub_00454880_GetHoverRect(D2RectStrc* pRect);                                                // 0x00454880
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
D2UnitStrc* __cdecl sub_00467A10();                                                             // 0x00467A10
int __stdcall D2Win_10125();                                                                                // 0x00501A40
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __fastcall sub_004AE360_IsMonsterFlag8(D2UnitStrc* pUnit);                                              // 0x004AE360
int __fastcall sub_004AE320_IsMonsterFlag4(D2UnitStrc* pUnit);                                              // 0x004AE320

static void __stdcall sub_004549F0_DrawCenteredText(const Unicode* wszText, int nFont, int nY, int nColor)
{
    Unicode wszBuffer[0x100];
    for (int i = 0; i < 0x100; ++i)
    {
        wszBuffer[i].wChar = 0;
    }
    D2RectStrc tRect;
    if (!sub_00454880_GetHoverRect(&tRect) || !wszText)
    {
        return;
    }
    const int nOldFont = sub_00502EF0(nFont);
    sub_005267E0(wszBuffer, wszText);
    const int nWidth = sub_00501820(wszBuffer);
    const int nX = ((tRect.nLeft + tRect.nRight) >> 1) - (nWidth >> 1);
    sub_00502320(wszBuffer, nX, nY, nColor, 1);
    sub_00502EF0(nOldFont);
}

// 0x00454A70
void __cdecl sub_00454A70_DrawHoverText()
{
    D2UnitStrc* pUnit = sub_00467A10();
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }
    int nY = D2Win_10125() + 0x27;
    sub_004549F0_DrawCenteredText(gwszText_007A2D30, 6, nY, gnHoverTextColor_007A2F30);
    if (gwszText_007A2D30[0].wChar || gwszHoverName_007A2F38[0].wChar)
    {
        nY += D2Win_10125();
    }
    sub_004549F0_DrawCenteredText(gwszText_007A2A78, 6, nY, gnHoverTextState_007A2C78);
}

// 0x004554B0
void __cdecl sub_004554B0_DrawHoverName()
{
    if (!sub_00526800(gwszHoverName_007A2F38))
    {
        return;
    }
    D2UnitStrc* pUnit = sub_00467A10();
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }
    int nColor = 0;
    if (sub_004AE360_IsMonsterFlag8(pUnit))
    {
        nColor = 4;
    }
    if (sub_004AE320_IsMonsterFlag4(pUnit))
    {
        nColor = 3;
    }
    const int nY = D2Win_10125() + 0x27;
    sub_004549F0_DrawCenteredText(gwszHoverName_007A2F38, 6, nY, nColor);
}
