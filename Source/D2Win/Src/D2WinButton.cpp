#include "D2Win.h"
#include "D2CelContext.h"
#include "D2Win32Types.h"
#include "D2StormTypes.h"
#include "D2WinTypes.h"
#include "D2WinControls.h"

#define D2WIN_BUTTON 6

#define DRAWMODE_NORMAL 5

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

extern tagPOINT gMousePosition_6F8FE234;                                                                    // 0x007D55A4

int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0

int __stdcall D2Win_10125();                                                                                // 0x00501A40

int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall D2Win_10118_DrawBlendedText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered, int eDrawMode); // 0x00502360

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

static int sub_00500C20_IsPointInButton(D2WinButtonStrc* pButton, int nX, int nY);

static void __stdcall sub_00500C50_DrawButtonText(int nOffsetY, D2WinButtonStrc* pButton);

int __stdcall CONTROL_AppendToList(D2WinButtonStrc* pControl);                                              // 0x004F9210

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

int __fastcall BUTTON_Draw(D2WinButtonStrc* pButton);                                                       // 0x00500DB0

int __stdcall BUTTON_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg);                                             // 0x00501090

int __stdcall BUTTON_HandleMouseUp(SMSGHANDLER_PARAMS* pMsg);                                               // 0x00501150

int __stdcall BUTTON_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg);                                       // 0x005011F0

// 0x00500C20
static __declspec(noinline) int sub_00500C20_IsPointInButton(D2WinButtonStrc* pButton, int nX, int nY)
{
    const int nLeft = pButton->controlHeader.nImageX;
    const int nBottom = pButton->controlHeader.nImageY;
    return nX >= nLeft && nY >= nBottom - pButton->controlHeader.nHeight && nX < nLeft + pButton->controlHeader.nWidth && nY < nBottom;
}

// 0x00500C50
static void __stdcall sub_00500C50_DrawButtonText(int nOffsetY, D2WinButtonStrc* pButton)
{
    sub_00502EF0(pButton->eFont);
    const int nTextHeight = D2Win_10125();
    int nOffsetX = (pButton->controlHeader.nWidth - sub_00501820((const Unicode*)pButton->wszText)) / 2;
    if (nOffsetX < 0)
    {
        nOffsetX = 0;
    }

    int nX = pButton->controlHeader.nImageX + nOffsetX;
    int nY = pButton->controlHeader.nImageY - (pButton->controlHeader.nHeight - nTextHeight) / 2 + nOffsetY;
    if (pButton->bIsPressed && pButton->bIsCallbackPending || pButton->nActivationCounter)
    {
        nX -= 2;
        nY += 2;
    }

    if (pButton->dwButtonFlags & BUTTONFLAG_SUBTITLE)
    {
        nOffsetX = (pButton->controlHeader.nWidth - sub_00501820((const Unicode*)pButton->wszText)) / 2;
        if (nOffsetX < 0)
        {
            nOffsetX = 0;
        }

        nX = pButton->controlHeader.nImageX + nOffsetX;
        nY = pButton->controlHeader.nImageY - 2 * ((pButton->controlHeader.nHeight - nTextHeight) / 3);
        int nTextOffsetX = (pButton->controlHeader.nWidth - sub_00501820(D2LANG_GetStringFromTblIndex((unsigned short)pButton->nStringId))) / 2;
        if (nTextOffsetX < 0)
        {
            nTextOffsetX = 0;
        }

        int nTextX = pButton->controlHeader.nImageX + nTextOffsetX;
        nY += nOffsetY;
        int nTextY = pButton->controlHeader.nImageY - (pButton->controlHeader.nHeight - nTextHeight) / 3 + nOffsetY;
        if (pButton->bIsPressed && pButton->bIsCallbackPending || pButton->nActivationCounter)
        {
            nTextX -= 2;
            nX -= 2;
            nY += 2;
            nTextY += 2;
        }

        D2Win_10118_DrawBlendedText(D2LANG_GetStringFromTblIndex((unsigned short)pButton->nStringId), nTextX, nTextY, pButton->nTextColor, 0, DRAWMODE_BURN);
    }

    D2Win_10118_DrawBlendedText((const Unicode*)pButton->wszText, nX, nY, pButton->nTextColor, 0, DRAWMODE_BURN);
}

int __fastcall BUTTON_Draw(D2WinButtonStrc* pButton);

// 0x00500DB0
int __fastcall BUTTON_Draw(D2WinButtonStrc* pButton)
{
    D2_ASSERT(pButton->controlHeader.eType == D2WIN_BUTTON, 0x14D);

    int nBaseFrame = pButton->nBaseFrame;
    if (!(pButton->controlHeader.dwFlags & gdwBitMasks[2]) || !(pButton->controlHeader.dwFlags & gdwBitMasks[0]))
    {
        nBaseFrame += pButton->nDisabledFrameOffset;
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

    if (pButton->controlHeader.pCellFile && pButton->controlHeader.dwFlags & gdwBitMasks[2])
    {
        int nDrawMode;
        if (pButton->controlHeader.dwFlags & gdwBitMasks[0] || pButton->dwButtonFlags & BUTTONFLAG_HAS_DISABLED_FRAMES)
        {
            nDrawMode = DRAWMODE_NORMAL;
        }
        else
        {
            nDrawMode = DRAWMODE_TRANS50;
        }

        const int nImageX = pButton->controlHeader.nImageX;
        const int nBaseY = pButton->controlHeader.nImageY - pButton->controlHeader.nHeight + 1;
        const int nRows = ((pButton->controlHeader.nHeight + 0xFF) >> 8) - 1;
        const int nColumns = (pButton->controlHeader.nWidth + 0xFF) >> 8;

        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.pCellFile = pButton->controlHeader.pCellFile;
        tContext.nDirection = 0;

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
                sub_004F6480(&tContext, nImageX + 256 * i, pButton->controlHeader.nImageY, -1, nDrawMode, 0);
            }
        }

        pButton->eFont = D2FONT_FONTRIDICULOUS;
        int nOffsetY;
        if (pButton->controlHeader.nHeight >= 35)
        {
            pButton->eFont = D2FONT_FONTEXOCET10;
            nOffsetY = 4;
        }
        else if (pButton->controlHeader.nHeight == 32)
        {
            nOffsetY = 3;
        }
        else
        {
            nOffsetY = (pButton->controlHeader.nHeight > 20) + 1;
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
            const int nImageX = pButton->controlHeader.nImageX;
            const int nImageY = pButton->controlHeader.nImageY;
            pButton->isButtonHovered = gMousePosition_6F8FE234.x >= nImageX && gMousePosition_6F8FE234.y >= nImageY - pButton->controlHeader.nHeight
                && gMousePosition_6F8FE234.x < nImageX + pButton->controlHeader.nWidth && gMousePosition_6F8FE234.y < nImageY;
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

// 0x00501290
D2WinButtonStrc* __fastcall BUTTON_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, void* pCallback, int nVirtualKey, int nBaseFrame, unsigned int dwButtonFlags, int nStringId, void* pUpdateHoverState)
{
    D2WinButtonStrc* pButton = (D2WinButtonStrc*)FOG_Alloc(sizeof(D2WinButtonStrc), ".\\Src\\D2WinButton.cpp", 36, 0);
    memset(pButton, 0, sizeof(D2WinButtonStrc));

    pButton->controlHeader.eType = D2WIN_BUTTON;
    pButton->controlHeader.dwFlags |= gdwBitMasks[0];
    pButton->controlHeader.dwFlags |= gdwBitMasks[2];
    pButton->controlHeader.pCellFile = pCellFile;
    pButton->controlHeader.nImageX = nX;
    pButton->controlHeader.nImageY = nY;
    pButton->controlHeader.nWidth = nWidth;
    pButton->controlHeader.nHeight = nHeight;
    pButton->controlHeader.pfDraw = (D2WinControlFn)BUTTON_Draw;
    pButton->controlHeader.pfHandleMouseDown = BUTTON_HandleMouseDown;
    pButton->controlHeader.pfHandleMouseUp = BUTTON_HandleMouseUp;
    pButton->controlHeader.pfHandleCharInput = 0;
    pButton->controlHeader.pfHandleVirtualKeyInput = nVirtualKey ? BUTTON_HandleVirtualKeyInput : 0;
    pButton->controlHeader.field_34 = (D2WinMsgHandler)pCallback;
    pButton->controlHeader.pNext = 0;
    pButton->dwButtonFlags = dwButtonFlags;
    pButton->bIsPressed = 0;
    pButton->bIsCallbackPending = 0;
    pButton->nActivationVirtualKey = nVirtualKey;
    pButton->nBaseFrame = nBaseFrame;

    if (nStringId)
    {
        sub_005267E0((Unicode*)pButton->wszText, D2LANG_GetStringFromTblIndex(nStringId));
    }

    struct { int nColumns; int nRows; } tCels;
    tCels.nColumns = (nWidth + 0xFF) >> 8;
    tCels.nRows = (nHeight + 0xFF) >> 8;
    pButton->nIsPressedFrameOffset = tCels.nRows * tCels.nColumns;
    pButton->nDisabledFrameOffset = (pButton->dwButtonFlags & BUTTONFLAG_HAS_DISABLED_FRAMES) ? 2 * pButton->nIsPressedFrameOffset : 0;

    pButton->pfUpdateHoverState = (D2WinMsgHandler)pUpdateHoverState;
    pButton->isButtonHovered = 0;
    pButton->nStringId = 0;
    CONTROL_AppendToList(pButton);
    return pButton;
}
