#include "Storm.h"

struct D2LayoutRectStrc;

extern unsigned short gwszText_007A2D30[256]; // 0x007A2D30
extern unsigned short gwszText_007A2A78[256]; // 0x007A2A78
extern unsigned short gwszHoverName_007A2F38[256]; // 0x007A2F38
extern unsigned short gwChatHistory_007BB840[2056]; // 0x007BB840
extern unsigned short gwszName_007BCEA8[4096]; // 0x007BCEA8

struct D2LayoutRectStrc
{
    int nTop;
    int nBottom;
    int nMid;
    int nLeft;
    int nRight;
};
extern int gnScreenHeight_00711470; // 0x00711470
extern D2LayoutRectStrc gaLayoutRects_007241C8[4]; // 0x007241C8

// 0x006CAA30
void __cdecl sub_006CAA30_ClearText()
{
    for (int i = 0; i < 256; ++i)
    {
        gwszText_007A2D30[i] = 0;
    }
}

// 0x006CAA50
void __cdecl sub_006CAA50_ClearText()
{
    for (int i = 0; i < 256; ++i)
    {
        gwszText_007A2A78[i] = 0;
    }
}

// 0x006CAA70
void __cdecl sub_006CAA70_ClearText()
{
    for (int i = 0; i < 256; ++i)
    {
        gwszHoverName_007A2F38[i] = 0;
    }
}

// 0x006CAB10
void __cdecl sub_006CAB10_ClearText()
{
    for (int i = 0; i < 2056; ++i)
    {
        gwChatHistory_007BB840[i] = 0;
    }
}

// 0x006CABF0
void __cdecl sub_006CABF0_ClearText()
{
    for (int i = 0; i < 4096; ++i)
    {
        gwszName_007BCEA8[i] = 0;
    }
}

// 0x006CAC30
void __cdecl sub_006CAC30_InitLayout()
{
    gaLayoutRects_007241C8[0].nTop = gnScreenHeight_00711470 - 140;
    gaLayoutRects_007241C8[0].nBottom = gnScreenHeight_00711470 - 105;
    gaLayoutRects_007241C8[0].nMid = gnScreenHeight_00711470 - 143;
    gaLayoutRects_007241C8[0].nLeft = gnScreenWidth_0071146C / 2 + 40;
    gaLayoutRects_007241C8[0].nRight = gnScreenWidth_0071146C / 2 + 75;
    gaLayoutRects_007241C8[1].nTop = gnScreenHeight_00711470 - 140;
    gaLayoutRects_007241C8[1].nBottom = gnScreenHeight_00711470 - 105;
    gaLayoutRects_007241C8[1].nMid = gnScreenHeight_00711470 - 143;
    gaLayoutRects_007241C8[2].nTop = gnScreenHeight_00711470 - 195;
    gaLayoutRects_007241C8[2].nBottom = gnScreenHeight_00711470 - 160;
    gaLayoutRects_007241C8[2].nMid = gnScreenHeight_00711470 - 198;
    gaLayoutRects_007241C8[2].nLeft = gnScreenWidth_0071146C / 2 + 40;
    gaLayoutRects_007241C8[2].nRight = gnScreenWidth_0071146C / 2 + 75;
    gaLayoutRects_007241C8[3].nTop = gnScreenHeight_00711470 - 195;
    gaLayoutRects_007241C8[3].nBottom = gnScreenHeight_00711470 - 160;
    gaLayoutRects_007241C8[3].nMid = gnScreenHeight_00711470 - 198;
}

#include "gen/data/Source/Storm/Unknown_006CAA30.inc"
