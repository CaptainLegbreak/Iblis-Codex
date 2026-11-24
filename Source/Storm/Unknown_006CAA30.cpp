#include "Storm.h"

struct D2LayoutRectStrc;


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
