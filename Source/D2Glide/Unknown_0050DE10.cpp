#include "D2Glide.h"

extern int gnProjectOriginX_00880B60;                                                                       // 0x00880B60
extern int gnGlideSpriteScale_00880B64;                                                                     // 0x00880B64
extern int gnProjectOriginY_00880B68;                                                                       // 0x00880B68
static int* gpnPerspectiveTable_00880B6C;                                                                   // 0x00880B6C

// 0x0050DE10
void __fastcall sub_0050DE10_ProjectToScreenScaled(int nX, int nY, int nZ, int* pScreenX, int* pScreenY, int bLarge)
{
    const int* pTable = gpnPerspectiveTable_00880B6C;
    const int nA = ((nX - gnProjectOriginX_00880B60) * 24) >> 16;
    const int nB = ((nY - gnProjectOriginY_00880B68) * 24) >> 16;
    const int nSum = (nB + nA) * 0x2D4;
    const int nHeight = (nSum * -512) >> 10;
    const int nAngle = (nSum * 0x376) >> 20;
    const int nPerspective = pTable[(nAngle - 0x1000) & 0x1FFF];
    const int nTop = (nHeight * nPerspective) >> 20;
    *pScreenX = (((nB - nA) * nPerspective * 0x2D4) >> 20) + gnRenderWidth_007C9138 / 2;
    *pScreenY = nTop + gnRenderHeight_007C913C / 2 - 0x10;
    const int nScale = nTop - (((nHeight + 0x37400) * gpnPerspectiveTable_00880B6C[(nAngle - 0xF80) & 0x1FFF]) >> 20);
    if (bLarge)
    {
        gnGlideSpriteScale_00880B64 = (nScale * 0x4CC) >> 10;
    }
    else
    {
        gnGlideSpriteScale_00880B64 = (nScale * 0x466) >> 10;
    }
}
