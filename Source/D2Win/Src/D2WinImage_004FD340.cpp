#include "D2Win.h"

struct D2WinControlStrc;
struct Unicode;

typedef int (__stdcall* D2WinMsgHandler)(struct SMSGHANDLER_PARAMS* pMsg);
typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

struct D2WinControlStrc
{
    int nType;
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    D2WinControlFn pfDraw;
    D2WinControlFn pfInitialize;
    D2WinMsgHandler pfHandleMouseDown;
    D2WinMsgHandler pfHandleMouseUp;
    D2WinMsgHandler pfHandleCharInput;
    D2WinMsgHandler pfHandleVirtualKeyInput;
    D2WinMsgHandler field_34;
    D2WinControlFn pfShouldMouseInputBeHandled;
    D2WinControlStrc* pNext;
};

struct D2WinImageClickRectStrc;

struct D2WinImageStrc
{
    D2WinControlStrc controlHeader;
    int nFrame;
    int eDrawMode;
    D2WinImageClickRectStrc* pClickRect;
    int field_4C;
    int field_50;
};

struct D2GfxDataStrc
{
    int nFrame;
    int unk0x04[12];
    D2CelFileStrc* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2CropRectStrc
{
    int nX0;
    int nX1;
    int nY0;
    int nY1;
};

enum D2ControlTypes
{
    D2WIN_IMAGE = 2,
};

enum DrawMode
{
    DRAWMODE_NORMAL = 5,
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __stdcall TEXTURE_CelDrawClipped(D2GfxDataStrc* pData, int nXPos, int nYPos, void* pCropRect, int eDrawMode); // 0x004F6510
int __fastcall D2Win_10058_0(D2WinControlStrc* pControl, const Unicode* pText, int a3, int nColumn);         // 0x004FB790

// 0x004FCD90
int __fastcall sub_004FCD90_D2Win_10058(D2WinControlStrc* pControl, const Unicode* pText, int a3, int nColumn)
{
    return D2Win_10058_0(pControl, pText, a3, nColumn);
}

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

// 0x004FD340
static void __stdcall sub_004FD340_ImageDrawTiled(const D2CropRectStrc* pDst, const D2CropRectStrc* pSrc, D2GfxDataStrc* pGfxData)
{
    const int nSrcWidth = pSrc->nX1 - pSrc->nX0;
    const int nDstWidth = pDst->nX1 - pDst->nX0;
    const int nSrcHeight = pSrc->nY1 - pSrc->nY0;
    const int nDstHeight = pDst->nY1 - pDst->nY0;
    if (nSrcWidth == nDstWidth && nSrcHeight == nDstHeight)
    {
        TEXTURE_CelDrawClipped(pGfxData, pDst->nX0 - pSrc->nX0, pDst->nY1 - pSrc->nY1 + 256, (void*)pDst, DRAWMODE_NORMAL);
        return;
    }

    const int nColumns = (nDstWidth + nSrcWidth - 1) / nSrcWidth;
    const int nRows = (nDstHeight + nSrcHeight - 1) / nSrcHeight;
    int nY = pDst->nY0 - pSrc->nY0 + 256;
    D2CropRectStrc tRect;
    for (int j = 0; j < nRows; ++j)
    {
        int nX = pDst->nX0 - pSrc->nX0;
        for (int i = 0; i < nColumns; ++i)
        {
            tRect.nX0 = D2_MAX(pDst->nX0, pSrc->nX0 + nX);
            tRect.nX1 = D2_MIN(pDst->nX1, tRect.nX0 + nSrcWidth);
            tRect.nY0 = D2_MAX(pDst->nY0, pSrc->nY0 + nY - 256);
            tRect.nY1 = D2_MIN(pDst->nY1, tRect.nY0 + nSrcHeight);
            TEXTURE_CelDrawClipped(pGfxData, nX, nY, &tRect, DRAWMODE_NORMAL);
            nX += nSrcWidth;
        }
        nY += nSrcHeight;
    }
}

// 0x004FD470
int __fastcall IMAGE_Draw(D2WinControlStrc* pControl)
{
    D2WinImageStrc* pImage = (D2WinImageStrc*)pControl;

    D2_ASSERT(pImage->controlHeader.nType == D2WIN_IMAGE, 0x10F);

    const int nBorderX = pImage->field_4C;
    const int nBorderY = pImage->field_50;
    D2GfxDataStrc tGfxData;
    memset(&tGfxData, 0, sizeof(tGfxData));
    tGfxData.pCellFile = pImage->controlHeader.pCellFile;
    tGfxData.unk0x40 = 0;
    tGfxData.nFrame = 0;

    int nX[4];
    int nY[4];
    int nSrcY[4];
    int nSrcX[4];
    nSrcX[0] = 0;
    nSrcX[1] = nBorderX;
    nSrcX[2] = 256 - nBorderX;
    nSrcX[3] = 256;
    nSrcY[0] = 0;
    nSrcY[1] = nBorderY;
    nSrcY[2] = 256 - nBorderY;
    nSrcY[3] = 256;
    nX[0] = pImage->controlHeader.nImageX;
    nX[1] = pImage->controlHeader.nImageX + nBorderX;
    nX[2] = pImage->controlHeader.nImageX + pImage->controlHeader.nWidth - nBorderX;
    nX[3] = pImage->controlHeader.nImageX + pImage->controlHeader.nWidth;
    nY[0] = pImage->controlHeader.nImageY - pImage->controlHeader.nHeight;
    nY[1] = pImage->controlHeader.nImageY - pImage->controlHeader.nHeight + nBorderY;
    nY[2] = pImage->controlHeader.nImageY - nBorderY;
    nY[3] = pImage->controlHeader.nImageY;
    D2CropRectStrc tDst;
    D2CropRectStrc tSrc;
    for (int j = 0; j < 3; ++j)
    {
        tSrc.nY0 = nSrcY[j];
        tSrc.nY1 = nSrcY[j + 1];
        for (int i = 0; i < 3; ++i)
        {
            tDst.nX0 = nX[i];
            tDst.nX1 = nX[i + 1];
            tDst.nY0 = nY[j];
            tDst.nY1 = nY[j + 1];
            tSrc.nX0 = nSrcX[i];
            tSrc.nX1 = nSrcX[i + 1];
            sub_004FD340_ImageDrawTiled(&tDst, &tSrc, &tGfxData);
        }
    }

    return 1;
}
