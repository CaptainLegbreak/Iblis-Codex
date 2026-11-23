#include "D2Glide.h"

extern int gnProjectOriginX;                                                                       // 0x00880B60
extern int gnGlideSpriteScale;                                                                     // 0x00880B64
extern int gnProjectOriginY;                                                                       // 0x00880B68
static int* gpnPerspectiveTable;                                                                   // 0x00880B6C

// 0x0050DE10
void __fastcall sub_0050DE10_ProjectToScreenScaled(int nX, int nY, int nZ, int* pScreenX, int* pScreenY, int bLarge)
{
    const int* pTable = gpnPerspectiveTable;
    const int nA = ((nX - gnProjectOriginX) * 24) >> 16;
    const int nB = ((nY - gnProjectOriginY) * 24) >> 16;
    const int nSum = (nB + nA) * 0x2D4;
    const int nHeight = (nSum * -512) >> 10;
    const int nAngle = (nSum * 0x376) >> 20;
    const int nPerspective = pTable[(nAngle - 0x1000) & 0x1FFF];
    const int nTop = (nHeight * nPerspective) >> 20;
    *pScreenX = (((nB - nA) * nPerspective * 0x2D4) >> 20) + gnRenderWidth_007C9138 / 2;
    *pScreenY = nTop + gnRenderHeight_007C913C / 2 - 0x10;
    const int nScale = nTop - (((nHeight + 0x37400) * gpnPerspectiveTable[(nAngle - 0xF80) & 0x1FFF]) >> 20);
    if (bLarge)
    {
        gnGlideSpriteScale = (nScale * 0x4CC) >> 10;
    }
    else
    {
        gnGlideSpriteScale = (nScale * 0x466) >> 10;
    }
}
