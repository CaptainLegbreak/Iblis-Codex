#include "D2Win.h"

typedef unsigned short Unicode;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CelFileStrc* pCellFile;
    int unk0x38;
    D2CelStrc* f_3C;
    int unk0x40;
    int unk0x44;
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int unk0x14[3];
};

struct D2WinButtonStrc
{
    int nType;
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    char unk0x01C[0x24];
    unsigned int dwButtonFlags;
    int bIsPressed;
    int bIsCallbackPending;
    int nActivationCounter;
    int unk0x050;
    int nIsPressedFrameOffset;
    int field_58;
    int nBaseFrame;
    int eFont;
    Unicode wszText[256];
    int nTextColor;
    void (__stdcall* pfUpdateHoverState)(SMSGHANDLER_PARAMS* pMsg);
    int isButtonHovered;
    unsigned short nStringId;
};

struct tagPOINT
{
    int x;
    int y;
};

#define D2WIN_BUTTON 6
#define BUTTONFLAG_HAS_DISABLED_FRAMES 0x20
#define BUTTONFLAG_SUBTITLE 0x40
#define DRAWMODE_TRANS50 1
#define DRAWMODE_NORMAL 5
#define DRAWMODE_BURN 4
#define D2FONT_FONTEXOCET10 9
#define D2FONT_FONTRIDICULOUS 10
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern tagPOINT gMousePosition_6F8FE234;                                                                    // 0x007D55A4
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
int __stdcall D2Win_10125();                                                                                // 0x00501A40
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00502360(const Unicode* wszText, int nX, int nY, int nColor, int nArg5, int nDrawMode); // 0x00502360
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

static __declspec(noinline) int sub_00500C20_IsPointInButton(D2WinButtonStrc* pButton, int nX, int nY)
{
    const int nLeft = pButton->nImageX;
    const int nBottom = pButton->nImageY;
    return nX >= nLeft && nY >= nBottom - pButton->nHeight && nX < nLeft + pButton->nWidth && nY < nBottom;
}

static void __stdcall sub_00500C50_DrawButtonText(int nOffsetY, D2WinButtonStrc* pButton)
{
    sub_00502EF0(pButton->eFont);
    const int nTextHeight = D2Win_10125();
    int nOffsetX = (pButton->nWidth - sub_00501820(pButton->wszText)) / 2;
    if (nOffsetX < 0)
    {
        nOffsetX = 0;
    }

    int nX = pButton->nImageX + nOffsetX;
    int nY = pButton->nImageY - (pButton->nHeight - nTextHeight) / 2 + nOffsetY;
    if (pButton->bIsPressed && pButton->bIsCallbackPending || pButton->nActivationCounter)
    {
        nX -= 2;
        nY += 2;
    }

    if (pButton->dwButtonFlags & BUTTONFLAG_SUBTITLE)
    {
        nOffsetX = (pButton->nWidth - sub_00501820(pButton->wszText)) / 2;
        if (nOffsetX < 0)
        {
            nOffsetX = 0;
        }

        nX = pButton->nImageX + nOffsetX;
        nY = pButton->nImageY - 2 * ((pButton->nHeight - nTextHeight) / 3);
        int nTextOffsetX = (pButton->nWidth - sub_00501820(D2LANG_GetStringFromTblIndex(pButton->nStringId))) / 2;
        if (nTextOffsetX < 0)
        {
            nTextOffsetX = 0;
        }

        int nTextX = pButton->nImageX + nTextOffsetX;
        nY += nOffsetY;
        int nTextY = pButton->nImageY - (pButton->nHeight - nTextHeight) / 3 + nOffsetY;
        if (pButton->bIsPressed && pButton->bIsCallbackPending || pButton->nActivationCounter)
        {
            nTextX -= 2;
            nX -= 2;
            nY += 2;
            nTextY += 2;
        }

        sub_00502360(D2LANG_GetStringFromTblIndex(pButton->nStringId), nTextX, nTextY, pButton->nTextColor, 0, DRAWMODE_BURN);
    }

    sub_00502360(pButton->wszText, nX, nY, pButton->nTextColor, 0, DRAWMODE_BURN);
}

// 0x00500DB0
int __fastcall BUTTON_Draw(D2WinButtonStrc* pButton)
{
    D2_ASSERT(pButton->nType == D2WIN_BUTTON, 0x14D);

    int nBaseFrame = pButton->nBaseFrame;
    if (!(pButton->dwFlags & gdwBitMasks[2]) || !(pButton->dwFlags & gdwBitMasks[0]))
    {
        nBaseFrame += pButton->field_58;
    }
    else
    {
        if (pButton->bIsPressed)
        {
            if (pButton->dwButtonFlags & 3)
            {
                pButton->bIsCallbackPending = 1;
            }
            else
            {
                pButton->bIsCallbackPending = sub_00500C20_IsPointInButton(pButton, gMousePosition_6F8FE234.x, gMousePosition_6F8FE234.y);
            }
        }

        if (pButton->bIsPressed && pButton->bIsCallbackPending || pButton->nActivationCounter)
        {
            nBaseFrame += pButton->nIsPressedFrameOffset;
        }
    }

    if (pButton->pCellFile && pButton->dwFlags & gdwBitMasks[2])
    {
        int nDrawMode;
        if (pButton->dwFlags & gdwBitMasks[0] || pButton->dwButtonFlags & BUTTONFLAG_HAS_DISABLED_FRAMES)
        {
            nDrawMode = DRAWMODE_NORMAL;
        }
        else
        {
            nDrawMode = DRAWMODE_TRANS50;
        }

        const int nImageX = pButton->nImageX;
        const int nBaseY = pButton->nImageY - pButton->nHeight + 1;
        const int nRows = ((pButton->nHeight + 0xFF) >> 8) - 1;
        const int nColumns = (pButton->nWidth + 0xFF) >> 8;

        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.pCellFile = pButton->pCellFile;
        tContext.unk0x40 = 0;

        for (int i = 0; i < nRows; ++i)
        {
            for (int j = 0; j < nColumns; ++j)
            {
                tContext.nFrame = nBaseFrame + j + 4 * i;
                sub_004F6480(&tContext, nImageX + 256 * j, nBaseY + 256 * (i + 1), -1, nDrawMode, 0);
            }
        }

        if (nRows >= 0)
        {
            for (int i = 0; i < nColumns; ++i)
            {
                tContext.nFrame = nBaseFrame + i + 4 * nRows;
                sub_004F6480(&tContext, nImageX + 256 * i, pButton->nImageY, -1, nDrawMode, 0);
            }
        }

        pButton->eFont = D2FONT_FONTRIDICULOUS;
        int nOffsetY;
        if (pButton->nHeight >= 35)
        {
            pButton->eFont = D2FONT_FONTEXOCET10;
            nOffsetY = 4;
        }
        else if (pButton->nHeight == 32)
        {
            nOffsetY = 3;
        }
        else
        {
            nOffsetY = (pButton->nHeight > 20) + 1;
        }

        pButton->nTextColor = 0;
        if (pButton->wszText[0])
        {
            sub_00500C50_DrawButtonText(nOffsetY, pButton);
        }
    }

    if (pButton->nActivationCounter == 2)
    {
        pButton->nActivationCounter = 0;
        pButton->bIsCallbackPending = 1;
    }
    else if (pButton->nActivationCounter)
    {
        ++pButton->nActivationCounter;
    }

    if (pButton->pfUpdateHoverState)
    {
        if (sub_004FA4B0())
        {
            pButton->isButtonHovered = 0;
        }
        else
        {
            const int nImageX = pButton->nImageX;
            const int nImageY = pButton->nImageY;
            pButton->isButtonHovered = gMousePosition_6F8FE234.x >= nImageX && gMousePosition_6F8FE234.y >= nImageY - pButton->nHeight
                && gMousePosition_6F8FE234.x < nImageX + pButton->nWidth && gMousePosition_6F8FE234.y < nImageY;
        }

        SMSGHANDLER_PARAMS tMsg;
        tMsg.hWnd = pButton;
        tMsg.lParam = pButton->isButtonHovered;
        ++gnWinCallbackDepth_007D55C4;
        pButton->pfUpdateHoverState(&tMsg);
        --gnWinCallbackDepth_007D55C4;
    }

    return 1;
}
