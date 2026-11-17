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
int __fastcall sub_00502EF0_SetFont(int nFont); // 0x00502EF0
const wchar_t* __fastcall sub_00524A30_GetString(unsigned short wStringId); // 0x00524A30

extern int gnScreenWidth_0071146C; // 0x0071146C
extern D2SliderButtonStrc gaSliderButtons_007246D8[3]; // 0x007246D8
extern int gnScreenHeight_007A521C; // 0x007A521C
extern int gnSliderRows_007C0274; // 0x007C0274
extern int gnSliderOffset_007C0278; // 0x007C0278
extern int gnSliderScale_007C02AC; // 0x007C02AC
extern int gnSliderPos_007C02CC; // 0x007C02CC

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

#include "gen/data/Source/D2Client/004A5060_sub_004A5060_LayoutSlider.inc"
